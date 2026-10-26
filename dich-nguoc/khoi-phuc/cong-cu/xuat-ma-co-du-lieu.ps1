# Export an already captured program with the existing verified metadata and data loader.
param(
    [Parameter(Mandatory)][ValidateSet(1,2,3)][int]$Bot,
    [Parameter(Mandatory)][string]$Metadata,
    [Parameter(Mandatory)][string]$Ghidra,
    [Parameter(Mandatory)][string]$Java,
    [Parameter(Mandatory)][ValidatePattern('^[a-z0-9-]{1,50}$')][string]$Run
)
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$metadataPath=(Resolve-Path -LiteralPath $Metadata).Path
$analysisRoot=(Resolve-Path -LiteralPath (Join-Path $root "bot-cua-toi-$Bot\phan-tich")).Path
if (-not $metadataPath.StartsWith($analysisRoot+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'METADATA_OUTSIDE_BOT_ANALYSIS' }
$out=Split-Path $metadataPath -Parent
$record=Get-Content -LiteralPath (Join-Path $metadataPath 'import.json') -Raw | ConvertFrom-Json
if ($record.bot -ne $Bot) { throw 'METADATA_BOT_DIFFERS' }
$binary=(Resolve-Path -LiteralPath $record.code_file).Path
if ((Get-FileHash -LiteralPath $binary -Algorithm SHA256).Hash.ToLowerInvariant() -ne $record.code_sha256) { throw 'CAPTURE_CODE_HASH_DIFFERS' }
$target=Join-Path $out 'ma-trung-gian.c'
if ((Test-Path -LiteralPath $target) -or (Test-Path -LiteralPath (Join-Path $out 'lenh-chay.json'))) { throw 'EXPORT_OUTPUT_EXISTS' }
$projectRoot=Join-Path $root "tam-bot1-3-20261023\ghidra-$Run"
if (Test-Path -LiteralPath $projectRoot) { throw 'GHIDRA_PROJECT_EXISTS' }
[IO.Directory]::CreateDirectory($projectRoot) | Out-Null
$env:JAVA_HOME=(Resolve-Path -LiteralPath $Java).Path
$ghidraPath=(Resolve-Path -LiteralPath $Ghidra).Path
$exportArgs=@($projectRoot,'capture','-import',$binary,'-loader','BinaryLoader','-processor','x86:LE:64:default','-cspec','windows','-noanalysis',
    '-scriptPath',(Join-Path $root 'cong-cu-cu\ghidra'),
    '-preScript','SetEx5CaptureBase.java',$metadataPath,
    '-preScript','LoadEx5ProgramData.java',$metadataPath,
    '-preScript','AnnotateTwister.java',$metadataPath,
    '-postScript','ExportEx5Code.java',(Join-Path $metadataPath 'seeds.txt'),$target,'captured_program_data','120',
    '-analysisTimeoutPerFile','300','-max-cpu','2','-log',(Join-Path $out 'ghidra.log'),'-scriptlog',(Join-Path $out 'scripts.log'))
@{bot=$Bot;source_sha256=$record.code_sha256;metadata_sha256=(Get-FileHash -LiteralPath (Join-Path $metadataPath 'import.json') -Algorithm SHA256).Hash.ToLowerInvariant();arguments=$exportArgs;ghidra=$ghidraPath;java=$env:JAVA_HOME} | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $out 'lenh-chay.json') -Encoding utf8
& (Join-Path $ghidraPath 'support\analyzeHeadless.bat') @exportArgs
if ($LASTEXITCODE -ne 0) { throw 'GHIDRA_EXPORT_FAILED' }
if (-not (Test-Path -LiteralPath ($target+'.summary.json'))) { throw 'EXPORT_SUMMARY_MISSING' }
Get-Content -LiteralPath ($target+'.summary.json')
