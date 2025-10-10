@echo off

set filename=index.c
set output=index.exe

echo ----------------------------------------
echo Compiling %filename%...
echo ----------------------------------------
gcc %filename% -o %output%


if errorlevel 1 (
    echo Compilation failed!
    pause
    exit /b
)

echo ----------------------------------------
echo Running %output%...
echo ----------------------------------------
%output%

pause
