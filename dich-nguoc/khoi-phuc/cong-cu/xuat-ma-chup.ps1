# Export C-like code from an existing verified capture; does not recreate MQL5.
param(
    [Parameter(Mandatory)][ValidateSet(1,3)][int]$Bot,
    [Parameter(Mandatory)][string]$Ghidra,
    [Parameter(Mandatory)][string]$Java,
    [Parameter(Mandatory)][ValidatePattern('^[a-z0-9-]+$')][string]$Run
)
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$index=if ($Bot -eq 1) { '05' } else { '16' }
$source=Join-Path $root "bot-cua-toi-$Bot\phan-tich\ban-ex5-$index"
$capture=Get-Content -LiteralPath (Join-Path $source 'capture\capture.json') -Raw | ConvertFrom-Json
$region=$capture.regions | Sort-Object bytes -Descending | Select-Object -First 1
$binary=Join-Path $source ('capture\'+$region.file)
if ((Get-FileHash -LiteralPath $binary -Algorithm SHA256).Hash.ToLowerInvariant() -ne $region.sha256) { throw 'CAPTURE_HASH_MISMATCH' }
$out=Join-Path $root "bot-cua-toi-$Bot\phan-tich\$Run"
if (Test-Path -LiteralPath $out) { throw 'RUN_EXISTS' }
$temp=Join-Path $root "tam-bot1-3-20261023\$Run"
[IO.Directory]::CreateDirectory($out) | Out-Null
[IO.Directory]::CreateDirectory($temp) | Out-Null
[IO.Directory]::CreateDirectory((Join-Path $temp 'metadata')) | Out-Null
Copy-Item -LiteralPath (Join-Path $source 'dia-chi-nen.txt') -Destination (Join-Path $temp ('metadata\'+$region.file+'.base.txt'))
$env:JAVA_HOME=(Resolve-Path -LiteralPath $Java).Path
$argsG=@($temp,"bot-$Bot",'-import',$binary,'-loader','BinaryLoader','-processor','x86:LE:64:default','-cspec','windows',
    '-scriptPath',(Join-Path $root 'cong-cu-cu\ghidra'),'-preScript','SetEx5CaptureBase.java',(Join-Path $temp 'metadata'),
    '-postScript','ExportEx5Code.java',(Join-Path $source 'diem-bat-dau-ham.txt'),(Join-Path $out 'ma-trung-gian.c'),
    '-analysisTimeoutPerFile','180','-max-cpu','2','-log',(Join-Path $out 'ghidra.log'),'-scriptlog',(Join-Path $out 'scripts.log'))
@{bot=$Bot;binary=$binary;sha256=$region.sha256;arguments=$argsG;java=$env:JAVA_HOME;ghidra=$Ghidra} | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $out 'lenh-chay.json') -Encoding utf8
& (Join-Path $Ghidra 'support\analyzeHeadless.bat') @argsG
if ($LASTEXITCODE -ne 0) { throw 'GHIDRA_FAILED' }
if (-not (Test-Path -LiteralPath (Join-Path $out 'ma-trung-gian.c.summary.json'))) { throw 'EXPORT_RESULT_MISSING' }
Get-Content -LiteralPath (Join-Path $out 'ma-trung-gian.c.summary.json')
