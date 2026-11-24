[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$Source,
    [Parameter(Mandatory = $true)][string]$ProjectRoot,
    [switch]$Run,
    [switch]$StrictWarnings
)

$ErrorActionPreference = 'Stop'
$sourceFile = Get-Item -LiteralPath $Source
if ($sourceFile.PSIsContainer -or $sourceFile.Extension -notin '.c', '.cpp') {
    throw "请选择已保存的 .c 或 .cpp 源文件：$Source"
}

# 保留源码相对项目根目录的层级，避免不同目录的同名程序互相覆盖。
$root = [IO.Path]::GetFullPath($ProjectRoot).TrimEnd('\', '/') + '\'
if (!$sourceFile.FullName.StartsWith($root, [StringComparison]::OrdinalIgnoreCase)) {
    throw "源文件不在工作区目录内：$($sourceFile.FullName)"
}
$relativeSource = $sourceFile.FullName.Substring($root.Length)
$compiler = 'D:/DevTools/msys64/ucrt64/bin/g++.exe'
$standard = '-std=c++17'
$relativeExe = [IO.Path]::ChangeExtension($relativeSource, '.exe')
if ($sourceFile.Extension -eq '.c') {
    # C 产物保留源码后缀，避免 main.c 和同目录的 main.cpp 共用 main.exe。
    $relativeExe = "$relativeSource.exe"
    $compiler = 'D:/DevTools/msys64/ucrt64/bin/gcc.exe'
    $standard = '-std=c17'
}
$exe = Join-Path (Join-Path $root 'out') $relativeExe
[void][IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($exe))

$flags = @($standard, '-g', '-fdiagnostics-color=always')
if ($StrictWarnings) {
    $flags += @('-Wall', '-Wextra', '-Wpedantic', '-Werror=return-type', '-Werror=uninitialized',
        '-Wreturn-type', '-Wuninitialized', '-Wshadow', '-Wconversion', '-Wsign-conversion')
}

# 让程序能加载 MSYS2 的 DLL，并从源码目录读取相对路径输入。
$env:Path = "$(Split-Path -Parent $compiler);$env:Path"
Set-Location -LiteralPath $sourceFile.DirectoryName
& $compiler @flags $sourceFile.FullName -o $exe
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}
if ($Run) {
    & $exe
    exit $LASTEXITCODE
}
