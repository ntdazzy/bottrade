# Build only the selected bot/test in this project's isolated MT5.
param(
    [ValidatePattern('\A[a-z0-9-]+\z')][string]$Bot='twisterpro-scalper',
    [string]$Source,
    [string]$MetaEditor
)
$ErrorActionPreference='Stop'
$work=Split-Path $PSScriptRoot -Parent
$project=Split-Path $work -Parent
$terminal=Join-Path $work '.local\terminal'
$mql=Join-Path $terminal 'MQL5'
$botRoot=Join-Path $work ('bots\'+$Bot)
if (-not $Source) { $Source=Join-Path $botRoot 'source\TwisterProRecovered.mq5' }
$sourcePath=(Resolve-Path -LiteralPath $Source).Path
if (-not $sourcePath.StartsWith($botRoot+'\',[StringComparison]::OrdinalIgnoreCase) -or [IO.Path]::GetExtension($sourcePath) -ne '.mq5') { throw 'SOURCE_MUST_BE_MQ5_INSIDE_SELECTED_BOT' }
if (-not $MetaEditor) { $MetaEditor=Join-Path $terminal 'metaeditor64.exe' }
if (-not (Test-Path -LiteralPath $MetaEditor) -or -not (Test-Path -LiteralPath (Join-Path $mql 'Include'))) { throw 'MISSING_ISOLATED_MT5: see dich-nguoc/tools/README.md' }
if (Get-Process terminal64,metatester64 -ErrorAction SilentlyContinue | Where-Object { $_.Path -and $_.Path.StartsWith($terminal+'\',[StringComparison]::OrdinalIgnoreCase) }) { throw 'ISOLATED_MT5_IS_BUSY' }
$destination=Join-Path $mql 'Experts\Market'
[IO.Directory]::CreateDirectory($destination) | Out-Null
$sources=@(Get-ChildItem -LiteralPath (Join-Path $botRoot 'source') -File | Where-Object { $_.Extension -in '.mq5','.mqh' })
foreach ($file in $sources) {
    [IO.File]::WriteAllText((Join-Path $destination $file.Name),[IO.File]::ReadAllText($file.FullName),[Text.Encoding]::Unicode)
}
$target=Join-Path $destination ([IO.Path]::GetFileName($sourcePath))
[IO.File]::WriteAllText($target,[IO.File]::ReadAllText($sourcePath),[Text.Encoding]::Unicode)
$inputs=@{}
function Find-BuildInputs([string]$Path) {
    $full=(Resolve-Path -LiteralPath $Path).Path
    if (-not $full.StartsWith($mql+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'INCLUDE_OUTSIDE_ISOLATED_MQL5' }
    if ($inputs.ContainsKey($full)) { return }
    $inputs[$full]=(Get-FileHash -LiteralPath $full).Hash.ToLowerInvariant()
    $content=[IO.File]::ReadAllText($full)
    foreach ($include in [regex]::Matches($content,'(?m)^\s*#include\s*([<"])([^>"]+)[>"]')) {
        $base=if ($include.Groups[1].Value -eq '<') { Join-Path $mql 'Include' } else { Split-Path $full }
        Find-BuildInputs (Join-Path $base $include.Groups[2].Value)
    }
}
Find-BuildInputs $target
$log=[IO.Path]::ChangeExtension($target,'.log')
if (Test-Path -LiteralPath $log) { Remove-Item -LiteralPath $log }
$arguments=@('/compile:"'+$target+'"','/log:"'+$log+'"','/inc:"'+$mql+'"')
Start-Process -FilePath $MetaEditor -ArgumentList $arguments -WindowStyle Hidden -Wait
if (-not (Test-Path -LiteralPath $log)) { throw 'COMPILER_DID_NOT_CREATE_LOG' }
$lines=[IO.File]::ReadAllLines($log,[Text.Encoding]::Unicode)
$lines | Where-Object { $_ -match ': (error|warning) ' } | Write-Output
$result=$lines | Where-Object { $_ -match '^Result: (\d+) errors?' } | Select-Object -Last 1
Write-Output $result
if (-not $result -or [int]([regex]::Match($result,'\d+').Value) -ne 0) { throw 'COMPILE_FAILED' }
foreach ($path in $inputs.Keys) {
    if ((Get-FileHash -LiteralPath $path).Hash.ToLowerInvariant() -ne $inputs[$path]) { throw 'BUILD_INPUT_CHANGED' }
}
$binary=[IO.Path]::ChangeExtension($target,'.ex5')
$relativeInputs=@{}
foreach ($path in $inputs.Keys) { $relativeInputs[$path.Substring($project.Length+1).Replace('\','/') ]=$inputs[$path] }
[ordered]@{version=1;target=('Experts/Market/'+[IO.Path]::GetFileName($target));binary_sha256=(Get-FileHash -LiteralPath $binary).Hash.ToLowerInvariant();log_sha256=(Get-FileHash -LiteralPath $log).Hash.ToLowerInvariant();sources=@{};compiled_inputs=$relativeInputs} |
    ConvertTo-Json -Depth 5 | Set-Content -LiteralPath ([IO.Path]::ChangeExtension($target,'.build.json')) -Encoding utf8
