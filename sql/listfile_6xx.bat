@echo off
title MySql Server
REM COLOR 0A
color 4f
mode con:lines=16 cols=55


:start
cls
echo.
echo  #####################################################
echo  #                                                   #
echo  #   Listfile Creator V1.0                           #
echo  #                                                   #
echo  #####################################################
echo.
echo.
echo.
echo  Creating listfile ......
echo.
echo  Please Wait ......
echo.
echo.
cd 6.x.x_updates
echo.
echo.
for /r %%a in (*) do echo %%a >> listfile_6xx.txt
echo.
echo.
move listfile_6xx.txt ../
echo.
echo.
echo  Done !!! 
echo.
echo.
pause
exit
