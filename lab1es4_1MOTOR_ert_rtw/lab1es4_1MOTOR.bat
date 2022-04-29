
cd .

chcp 1252

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2021b\bin\win64\gmake"  -B DEPRULES=0 -j5  -f lab1es4_1MOTOR.mk all) else ("C:\PROGRA~1\MATLAB\R2021b\bin\win64\gmake"  -B DEPRULES=0 -j5  -f lab1es4_1MOTOR.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1