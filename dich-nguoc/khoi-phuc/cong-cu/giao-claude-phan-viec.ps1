# Giao Claude viet ket qua trong mot thu muc rieng; Codex kiem truoc khi ghep.
param(
    [Parameter(Mandatory)][string]$Prompt,
    [Parameter(Mandatory)][ValidatePattern('\A[a-z0-9-]{1,64}\z')][string]$Run,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [ValidatePattern('\A[0-9a-f-]{36}\z')][string]$Resume
)
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$workspace=Split-Path (Split-Path $root -Parent) -Parent
$promptPath=(Resolve-Path -LiteralPath $Prompt).Path
$outputPath=(Resolve-Path -LiteralPath $OutputDirectory).Path
$proposalRoot=Join-Path $root 'claude-thuc-hien'
if (-not $promptPath.StartsWith($workspace+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'PROMPT_OUTSIDE_WORKSPACE' }
if (-not $outputPath.StartsWith($proposalRoot+'\',[StringComparison]::OrdinalIgnoreCase)) { throw 'OUTPUT_OUTSIDE_CLAUDE_DELIVERABLES' }
$ancestor=$outputPath
while ($ancestor.StartsWith($workspace,[StringComparison]::OrdinalIgnoreCase)) {
    if ((Get-Item -LiteralPath $ancestor -Force).Attributes -band [IO.FileAttributes]::ReparsePoint) { throw 'REPARSE_POINT_IN_OUTPUT' }
    $ancestor=Split-Path $ancestor -Parent
}
$claudeExe='C:\Users\NTD\.vscode\extensions\anthropic.claude-code-2.1.308-win32-x64\resources\native-binary\claude.exe'
if (-not (Test-Path -LiteralPath $claudeExe)) { throw 'CLAUDE_EXECUTABLE_MISSING' }
$jobs=Join-Path (Split-Path $root -Parent) ('.local\claude-parallel-'+(Get-Date -Format yyyyMMdd))
$out=Join-Path $jobs $Run
if (Test-Path -LiteralPath $out) { throw 'CLAUDE_RUN_EXISTS' }
[IO.Directory]::CreateDirectory($out) | Out-Null
$utf8=[Text.UTF8Encoding]::new($false)
[IO.File]::WriteAllText((Join-Path $out 'prompt.txt'),[IO.File]::ReadAllText($promptPath),$utf8)
$promptHash=(Get-FileHash -LiteralPath (Join-Path $out 'prompt.txt') -Algorithm SHA256).Hash.ToLowerInvariant()
$relative=$outputPath.Substring($workspace.Length+1).Replace('\','/')
$editRule='Edit(./'+$relative+'/**)'
$settings=[ordered]@{ultracode=$true;autoMemoryEnabled=$false;permissions=@{allow=@('Read','Grep','Glob',$editRule);deny=@('Bash','PowerShell')}}
[IO.File]::WriteAllText((Join-Path $out 'settings.json'),($settings | ConvertTo-Json -Depth 5),$utf8)
$arguments=@('-p','--model','claude-opus-5-5','--effort','max','--settings',
    ('"'+(Join-Path $out 'settings.json')+'"'),'--output-format','json','--disable-slash-commands',
    '--tools','Read,Grep,Glob,Edit,Write','--allowedTools',('Read,Grep,Glob,'+$editRule),
    '--permission-mode','dontAsk','--disallowedTools','Bash,PowerShell',
    '--debug-file',('"'+(Join-Path $out 'debug.txt')+'"'))
if ($Resume) { $arguments+=@('--resume',$Resume) }
$process=Start-Process -FilePath $claudeExe -ArgumentList $arguments -WorkingDirectory $workspace `
    -RedirectStandardInput (Join-Path $out 'prompt.txt') -RedirectStandardOutput (Join-Path $out 'response.json') `
    -RedirectStandardError (Join-Path $out 'stderr.txt') -WindowStyle Hidden -PassThru
$job=[ordered]@{pid=$process.Id;started=(Get-Date).ToUniversalTime().ToString('o');model='claude-opus-5-5';effort='max';
    ultracode_requested=$true;scope='Write proposed analysis/code only within an explicitly assigned deliverable directory';
    output_directory=$relative;edit_rule=$editRule;permission_mode='dontAsk';
    prompt_sha256=$promptHash;resume=$Resume}
$job | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $out 'job.json') -Encoding utf8
$job | ConvertTo-Json
