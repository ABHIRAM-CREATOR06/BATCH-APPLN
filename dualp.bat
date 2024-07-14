@echo off
:menu
cls
echo MY COLLECTION 
echo Choose options:
echo 1: INDIAN CURRENCY TO OTHER CURRENCY CONVERTOR
echo 2: INDIAN NUMERICAL SYSTEM TO WORDS
echo 3: MATRIX OPERATIONS
echo 4: exit the file 
set /p choice="ENTER YOUR CHOICE(1,2,3,4):"

if "%choice%"=="1" (
    start dollar.exe
    goto menu
) else if "%choice%"=="2" (
    start kk.exe
    goto menu
) else if "%choice%"=="3" (
    start matrix.exe
    goto menu
) else if "%choice%"=="4" (
    echo EXITING
) else (
    echo INVALID MENU OPTION RETURNING TO MENU 
    pause
    goto menu
)
