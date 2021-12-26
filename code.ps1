echo "Make Sure Correct VS Path Is Set"

$VS_PATH = "C:\Program Files\Microsoft Visual Studio\2022\Professional"
Import-Module "$VS_PATH\Common7\Tools\Microsoft.VisualStudio.DevShell.dll"
Enter-VsDevShell -VsInstallPath "$VS_PATH" -SkipAutomaticLocation -DevCmdArguments "-arch=x64"

echo "Enviorment Configured"

cd $PSScriptRoot

code .
