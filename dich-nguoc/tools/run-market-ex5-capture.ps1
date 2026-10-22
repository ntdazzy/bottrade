param(
    [Parameter(Mandatory=$true)][ValidateRange(1,17)][int[]]$Indices,
    [Parameter(Mandatory=$true)][ValidatePattern('\A[a-z0-9_]{1,24}\z')][string]$Run,
    [switch]$IncludeProgramData,
    [string]$InputsPath,
    [string]$StringChecksPath,
    [string]$ReadyByteRva
)
$ErrorActionPreference = 'Stop'
$work = Split-Path $PSScriptRoot -Parent
$project = Split-Path $work -Parent
$root = Join-Path $work 'bots\twisterpro-scalper\verification'
$terminal = Join-Path $work '.local\terminal'
$python = (Get-Command python).Source
$jobs = Get-Content -LiteralPath (Join-Path $work 'catalog.json') -Raw | ConvertFrom-Json
$captureScript = Join-Path $PSScriptRoot 'inspect-ex5-running-code.py'
if (-not (Test-Path -LiteralPath (Join-Path $terminal 'metatester64.exe'))) {
    throw 'MISSING_ISOLATED_MT5: see dich-nguoc/tools/README.md'
}
function Get-OwnedProcesses {
    @(Get-Process terminal64,metatester64 -ErrorAction SilentlyContinue |
        Where-Object { $_.Path -and $_.Path.StartsWith($terminal+'\',[StringComparison]::OrdinalIgnoreCase) })
}
foreach ($index in $Indices) {
    if (Get-OwnedProcesses) { throw 'OWNED_TERMINAL_IS_ALREADY_RUNNING' }
    $job = $jobs | Where-Object { $_.index -eq $index }
    if (-not $job) { throw 'UNKNOWN_JOB_INDEX' }
    $root = Join-Path $work ('bots\'+$job.bot_id+'\verification')
    if ($job.bot_id -ne 'twisterpro-scalper') { throw 'COMPLETE_TWISTER_BEFORE_RESUMING_OTHER_BOTS' }
    if ($InputsPath) {
        $inputFile = (Resolve-Path -LiteralPath $InputsPath).Path
        if (-not $inputFile.StartsWith($root+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'INPUTS_FILE_OUTSIDE_RESEARCH_ROOT' }
        $overrides = Get-Content -LiteralPath $inputFile -Raw | ConvertFrom-Json
        foreach ($property in $overrides.PSObject.Properties) {
            if ($property.Name -notmatch '\A[A-Za-z_][A-Za-z0-9_]*\z' -or [string]$property.Value -match "[`r`n]") { throw 'INVALID_INPUT_OVERRIDE' }
        }
        $job.test | Add-Member -NotePropertyName inputs -NotePropertyValue $overrides -Force
    }
    $label = ('{0}_{1:d2}' -f $Run,$index)
    $captureDir = Join-Path $root ('captures\'+$label)
    $jobFile = Join-Path $root ($label+'-job.json')
    if ((Test-Path -LiteralPath $captureDir) -or (Test-Path -LiteralPath $jobFile)) { throw 'RUN_ALREADY_EXISTS' }
    $source = Join-Path $project $job.source
    if ((Get-FileHash -LiteralPath $source).Hash -ne $job.sha256) { throw 'SOURCE_HASH_CHANGED' }
    $copy = Join-Path $terminal ('MQL5\Experts\Market\'+$job.test.ex5)
    Copy-Item -LiteralPath $source -Destination $copy -Force
    if ((Get-FileHash -LiteralPath $copy).Hash -ne $job.sha256) { throw 'COPY_HASH_MISMATCH' }
    $job.test.id = $label
    ConvertTo-Json -InputObject @($job.test) -Depth 5 | Set-Content -LiteralPath $jobFile -Encoding utf8
    $stdout = Join-Path $root ($label+'-stdout.txt')
    $stderr = Join-Path $root ($label+'-stderr.txt')
    $runnerArgs = @('-I','-B','-X','utf8',('"{0}"' -f (Join-Path $PSScriptRoot 'run_market.py')),('"{0}"' -f $terminal),('"{0}"' -f $jobFile))
    $runner = Start-Process -FilePath $python -ArgumentList $runnerArgs `
        -WorkingDirectory $root -WindowStyle Hidden -RedirectStandardOutput $stdout -RedirectStandardError $stderr -PassThru
    $record = [ordered]@{run=$label;source=$job.source;source_sha256=$job.sha256;capture_exit=$null;tester_pid=$null}
    if ($InputsPath) { $record.inputs_file = $inputFile; $record.inputs_sha256 = (Get-FileHash -LiteralPath $inputFile).Hash }
    try {
        $deadline = [DateTime]::UtcNow.AddSeconds(55)
        $tester = $null
        while ([DateTime]::UtcNow -lt $deadline) {
            $tester = Get-OwnedProcesses | Where-Object { $_.ProcessName -eq 'metatester64' } | Select-Object -First 1
            if ($tester) { break }
            if ($runner.HasExited) { break }
            Start-Sleep -Milliseconds 100
        }
        if ($tester) {
            $record.tester_pid = $tester.Id
            $record.engine_base = ('0x{0:x}' -f $tester.MainModule.BaseAddress.ToInt64())
            $record.engine_sha256 = (Get-FileHash -LiteralPath (Join-Path $terminal 'metatester64.exe')).Hash
            $captureArgs = @('-I','-B','-X','utf8',$captureScript,'--pid',$tester.Id,'--out',$captureDir,'--min-code-bytes',8192,'--wait-seconds',15,'--include-readonly')
            if ($IncludeProgramData) { $captureArgs += '--include-program-data' }
            if ($ReadyByteRva) { $captureArgs += @('--ready-byte-rva',$ReadyByteRva) }
            if ($StringChecksPath) { $captureArgs += @('--verify-input-strings',$StringChecksPath) }
            & $python @captureArgs `
                1> (Join-Path $root ($label+'-capture.txt')) 2> (Join-Path $root ($label+'-capture-error.txt'))
            $record.capture_exit = $LASTEXITCODE
        } else { $record.error = 'OWNED_TESTER_NOT_STARTED' }
    } finally {
        # These processes belong to this run; no other terminal is stopped.
        $cleanupErrors = @()
        foreach ($owned in (Get-OwnedProcesses)) {
            try { Stop-Process -Id $owned.Id -Force -ErrorAction Stop }
            catch {
                # A process that exited by itself needs no further action.
                if (Get-Process -Id $owned.Id -ErrorAction SilentlyContinue) {
                    $cleanupErrors += [pscustomobject]@{event='stop_failed';module='run-market-ex5-capture';pid=$owned.Id;detail=$_.Exception.Message}
                }
            }
        }
        if (-not $runner.WaitForExit(10000)) { $runner.Kill(); $runner.WaitForExit() }
        $record.cleanup_errors = $cleanupErrors
        $record.runner_exit = $runner.ExitCode
        $record.test_interrupted_after_capture = $true
        $record | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $root ($label+'-result.json')) -Encoding utf8
    }
    $record | ConvertTo-Json -Compress
    if ($record.capture_exit -ne 0 -or $null -eq $record.capture_exit -or $record.cleanup_errors.Count -gt 0) {
        throw "CAPTURE_FAILED: $label (see saved result and capture-error files)"
    }
}
