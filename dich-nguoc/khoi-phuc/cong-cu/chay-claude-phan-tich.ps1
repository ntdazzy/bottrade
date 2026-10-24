# Chạy một phần phân tích độc lập, chỉ đọc; không sửa nguồn hoặc gọi lệnh shell.
param(
    [Parameter(Mandatory)][string]$Prompt,
    [Parameter(Mandatory)][ValidatePattern('\A[a-z0-9-]{1,64}\z')][string]$Run,
    [ValidatePattern('\A[0-9a-f-]{36}\z')][string]$Resume,
    [switch]$WaitForExit
)
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$workspace=Split-Path (Split-Path $root -Parent) -Parent
$promptPath=(Resolve-Path -LiteralPath $Prompt).Path
if (-not $promptPath.StartsWith($workspace+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'PROMPT_OUTSIDE_WORKSPACE' }
$claudeExe='C:\Users\NTD\.vscode\extensions\anthropic.claude-code-2.1.308-win32-x64\resources\native-binary\claude.exe'
if (-not (Test-Path -LiteralPath $claudeExe)) { throw 'CLAUDE_EXECUTABLE_MISSING' }
$jobs=Join-Path (Split-Path $root -Parent) ('.local\claude-parallel-'+(Get-Date -Format yyyyMMdd))
$out=Join-Path $jobs $Run
if (Test-Path -LiteralPath $out) { throw 'CLAUDE_RUN_EXISTS' }
New-Item -ItemType Directory -Path $out | Out-Null
$utf8=[Text.UTF8Encoding]::new($false)
[IO.File]::WriteAllText((Join-Path $out 'prompt.txt'),[IO.File]::ReadAllText($promptPath),$utf8)
[IO.File]::WriteAllText((Join-Path $out 'settings.json'),'{"ultracode":true}',$utf8)
$promptHash=(Get-FileHash -LiteralPath (Join-Path $out 'prompt.txt') -Algorithm SHA256).Hash.ToLowerInvariant()
$arguments=@('-p','--model','claude-opus-5-5','--effort','max','--settings',
    ('"'+(Join-Path $out 'settings.json')+'"'),'--output-format','json',
    '--disable-slash-commands','--allowedTools','Read,Grep,Glob','--disallowedTools','Bash,Edit,Write',
    '--debug-file',('"'+(Join-Path $out 'debug.txt')+'"'))
if ($Resume) { $arguments+=@('--resume',$Resume) }
$process=Start-Process -FilePath $claudeExe -ArgumentList $arguments -WorkingDirectory $workspace `
    -RedirectStandardInput (Join-Path $out 'prompt.txt') -RedirectStandardOutput (Join-Path $out 'response.json') `
    -RedirectStandardError (Join-Path $out 'stderr.txt') -WindowStyle Hidden -PassThru
$job=[ordered]@{pid=$process.Id;started=(Get-Date).ToUniversalTime().ToString('o');
    model='claude-opus-5-5';effort='max';ultracode_requested=$true;
    scope='Independent read-only analysis';prompt_sha256=$promptHash;resume=$Resume}
$job | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $out 'job.json') -Encoding utf8
$job | ConvertTo-Json
if ($WaitForExit) { $process.WaitForExit(); Write-Output ('CLAUDE_EXIT='+$process.ExitCode) }
