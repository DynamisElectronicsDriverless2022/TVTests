
call "setup_mingw.bat"

cd .

chcp 1252

if "%1"=="" ("D:\Matlab2021b\bin\win64\gmake"  -f TVModel.mk all) else ("D:\Matlab2021b\bin\win64\gmake"  -f TVModel.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1