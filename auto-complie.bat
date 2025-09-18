@echo off
:: Auto compile and run a C file

:: Change this to your C source file name
set filename=index.c
set output=index.exe
------------------------------------------
echo Compiling %filename%...
------------------------------------------
gcc %filename% -o %output%

if errorlevel 1 (
    echo Compilation failed!
    pause
    exit /b
)
------------------------------------------
echo Running %output%...
------------------------------------------
%output%

pause
