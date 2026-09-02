param(
    [Parameter(Mandatory = $true)]
    [string]$Source
)

$ErrorActionPreference = "Stop"

$sourcePath = (Resolve-Path -LiteralPath $Source).Path
$projectRoot = Split-Path -Parent $PSScriptRoot
$buildDir = Join-Path $projectRoot ".build"
$sourceName = [System.IO.Path]::GetFileNameWithoutExtension($sourcePath)
$outputPath = Join-Path $buildDir ($sourceName + ".exe")

New-Item -ItemType Directory -Force -Path $buildDir | Out-Null

& gcc -std=c17 -Wall -Wextra -Wpedantic -g $sourcePath -o $outputPath
if ($LASTEXITCODE -ne 0) {
    throw "编译失败，请先处理上面的警告或错误。"
}

& $outputPath
if ($LASTEXITCODE -ne 0) {
    throw "程序运行失败，退出码：$LASTEXITCODE"
}
