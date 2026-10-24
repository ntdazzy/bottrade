# Biên dịch một EA của bot trong khoi-phuc bằng MetaEditor của máy thử riêng.
# Chép cây source/MQL5/{Experts,Include}/bot-cua-toi-N vào MQL5 của máy thử (giữ đường dẫn tương đối),
# chạy MetaEditor ẩn, đọc nhật ký và lưu biên nhận vào bang-chung/bien-dich/<Run>/.
# Ví dụ:
#   .\bien-dich.ps1 -Bot 13 -Terminal '<...\.local\claude-recovery-20261023\mt5>' -Run b13-build-01
param(
    [Parameter(Mandatory)][ValidateRange(1,15)][int]$Bot,
    [Parameter(Mandatory)][string]$Terminal,
    [Parameter(Mandatory)][ValidatePattern('\A[a-z0-9-]+\z')][string]$Run,
    [string]$Source
)
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$name="bot-cua-toi-$Bot"
$botRoot=Join-Path $root $name
$srcMql=Join-Path $botRoot 'source\MQL5'
if (-not $Source) { $Source=Join-Path $srcMql "Experts\$name\$name.mq5" }
$sourcePath=(Resolve-Path -LiteralPath $Source).Path
if (-not $sourcePath.StartsWith($srcMql+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'SOURCE_OUTSIDE_BOT_SOURCE' }
$terminal=(Resolve-Path -LiteralPath $Terminal).Path
$local=Join-Path (Split-Path $root -Parent) '.local'
if (-not $terminal.StartsWith($local+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'TERMINAL_MUST_BE_INSIDE_DICH_NGUOC_LOCAL' }
$editor=Join-Path $terminal 'metaeditor64.exe'
$mql=Join-Path $terminal 'MQL5'
if (-not (Test-Path -LiteralPath $editor) -or -not (Test-Path -LiteralPath (Join-Path $mql 'Include\Trade\Trade.mqh'))) { throw 'MISSING_ISOLATED_MT5' }
if (Get-Process terminal64,metatester64,metaeditor64 -ErrorAction SilentlyContinue | Where-Object { $_.Path -and $_.Path.StartsWith($terminal+'\',[StringComparison]::OrdinalIgnoreCase) }) { throw 'ISOLATED_MT5_IS_BUSY' }
$out=Join-Path $botRoot "bang-chung\bien-dich\$Run"
if (Test-Path -LiteralPath $out) { throw 'RUN_EXISTS' }

# Chép nguồn của bot (không xóa gì khác trong máy thử).
$copied=[ordered]@{}
foreach ($part in 'Experts','Include','Scripts') {
    $from=Join-Path $srcMql "$part\$name"
    if (-not (Test-Path -LiteralPath $from)) { continue }
    $to=Join-Path $mql "$part\$name"
    if (Test-Path -LiteralPath $to) { Remove-Item -LiteralPath $to -Recurse -Force }
    [IO.Directory]::CreateDirectory($to) | Out-Null
    foreach ($file in Get-ChildItem -LiteralPath $from -File -Recurse | Where-Object { $_.Extension -in '.mq5','.mqh' }) {
        $rel=$file.FullName.Substring($srcMql.Length+1)
        Copy-Item -LiteralPath $file.FullName -Destination (Join-Path $mql $rel)
        $copied[$rel.Replace('\','/')]=(Get-FileHash -LiteralPath $file.FullName -Algorithm SHA256).Hash.ToLowerInvariant()
    }
}
$target=Join-Path $mql $sourcePath.Substring($srcMql.Length+1)
$log=[IO.Path]::ChangeExtension($target,'.log')
$binary=[IO.Path]::ChangeExtension($target,'.ex5')
foreach ($p in $log,$binary) { if (Test-Path -LiteralPath $p) { Remove-Item -LiteralPath $p } }
# Không dùng /portable: với cờ này MetaEditor thoát mà không biên dịch, không tạo nhật ký (lần chạy 23/10/2026).
$arguments=@('/compile:"'+$target+'"','/log:"'+$log+'"','/inc:"'+$mql+'"')
$p=Start-Process -FilePath $editor -ArgumentList $arguments -WindowStyle Hidden -Wait -PassThru
if (-not (Test-Path -LiteralPath $log)) { throw 'COMPILER_DID_NOT_CREATE_LOG' }
$raw=[IO.File]::ReadAllBytes($log)
$text=if ($raw.Length -ge 2 -and $raw[0] -eq 0xFF -and $raw[1] -eq 0xFE) { [Text.Encoding]::Unicode.GetString($raw,2,$raw.Length-2) } else { [Text.Encoding]::UTF8.GetString($raw) }
$lines=$text -split "`r?`n"
$result=$lines | Where-Object { $_ -match 'Result: (\d+) errors?, (\d+) warnings?' } | Select-Object -Last 1
$m=[regex]::Match([string]$result,'(\d+) errors?, (\d+) warnings?')
[IO.Directory]::CreateDirectory($out) | Out-Null
Copy-Item -LiteralPath $log -Destination (Join-Path $out 'metaeditor.log')
$receipt=[ordered]@{
    run=$Run; target=$target.Substring($mql.Length+1).Replace('\','/')
    metaeditor_sha256=(Get-FileHash -LiteralPath $editor -Algorithm SHA256).Hash.ToLowerInvariant()
    exit_code=$p.ExitCode
    errors=if ($m.Success) { [int]$m.Groups[1].Value } else { $null }
    warnings=if ($m.Success) { [int]$m.Groups[2].Value } else { $null }
    result_line=[string]$result
    sources_sha256=$copied
    trade_mqh_sha256=(Get-FileHash -LiteralPath (Join-Path $mql 'Include\Trade\Trade.mqh') -Algorithm SHA256).Hash.ToLowerInvariant()
    binary_sha256=if (Test-Path -LiteralPath $binary) { (Get-FileHash -LiteralPath $binary -Algorithm SHA256).Hash.ToLowerInvariant() } else { $null }
}
if (Test-Path -LiteralPath $binary) { Copy-Item -LiteralPath $binary -Destination (Join-Path $out ([IO.Path]::GetFileName($binary))) }
$receipt | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $out 'bien-nhan.json') -Encoding utf8
$lines | Where-Object { $_ -match ': (error|warning) ' }
Write-Output ([string]$result)
if (-not $m.Success -or [int]$m.Groups[1].Value -ne 0) { throw 'COMPILE_FAILED' }
