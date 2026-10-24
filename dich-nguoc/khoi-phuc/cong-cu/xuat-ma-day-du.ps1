# Read a newly prepared capture with exact function ranges and measured native signatures.
param(
    [Parameter(Mandatory)][string]$Metadata,
    [Parameter(Mandatory)][string]$Ghidra,
    [Parameter(Mandatory)][string]$Java
)
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$metadata=(Resolve-Path -LiteralPath $Metadata).Path
if (-not $metadata.StartsWith($root+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'METADATA_OUTSIDE_RECOVERY' }
$info=Get-Content -LiteralPath (Join-Path $metadata 'import.json') -Raw | ConvertFrom-Json
$out=Split-Path $metadata -Parent
$code=Join-Path $out 'ma-trung-gian.c'
if (Test-Path -LiteralPath $code) { throw 'OUTPUT_EXISTS' }
$temp=Join-Path $root ('tam-bot1-3-20261023\bot'+$info.bot+'-'+(Split-Path $out -Leaf))
[IO.Directory]::CreateDirectory($temp) | Out-Null
$env:JAVA_HOME=(Resolve-Path -LiteralPath $Java).Path
$argsG=@($temp,'capture','-import',$info.code_file,'-loader','BinaryLoader','-processor','x86:LE:64:default','-cspec','windows',
 '-noanalysis','-scriptPath',(Join-Path $root 'cong-cu-cu\ghidra'),'-preScript','SetEx5CaptureBase.java',$metadata,
 '-preScript','LoadEx5ProgramData.java',$metadata,'-preScript','AnnotateTwister.java',$metadata,
 '-postScript','ExportEx5Code.java',(Join-Path $metadata 'seeds.txt'),$code,'captured_program_data','120',
 '-analysisTimeoutPerFile','300','-max-cpu','2','-log',(Join-Path $out 'ghidra.log'),'-scriptlog',(Join-Path $out 'scripts.log'))
@{arguments=$argsG;ghidra=$Ghidra;java=$env:JAVA_HOME;source_sha256=(Get-FileHash -LiteralPath $info.code_file -Algorithm SHA256).Hash} | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $out 'lenh-chay.json') -Encoding utf8
& (Join-Path $Ghidra 'support\analyzeHeadless.bat') @argsG
if ($LASTEXITCODE -ne 0) { throw 'GHIDRA_FAILED' }
if (-not (Test-Path -LiteralPath ($code+'.summary.json'))) { throw 'EXPORT_RESULT_MISSING' }
Get-Content -LiteralPath ($code+'.summary.json')
