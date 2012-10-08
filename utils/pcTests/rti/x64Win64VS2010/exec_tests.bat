:: This script runs all tests in this directory and checks their results.

setlocal EnableDelayedExpansion
@echo off

:: Initialize the returned value to 0 (all succesfully)
set errorstatus=0

:: Find all directories.
for /D %%D in ("*") do (
   :: Enter to the directory.
   cd %%D
   call :execTest %%D
   :: Go out to the parent directory.
   cd ..
   :: Detect error in call.
   if not !errorstatus!==0 goto :exit
)
goto :exit

:execTest
:: Backup of Client.cxx file.
copy Client.cxx Client.cxx.backup
:: Backup of the ServerImpl.cxx file
copy %*ServerImpl.cxx %*ServerImpl.cxx.backup
:: Delete all generated files.
del *.h *.cxx %*RequestReply.idl
:: Generates the file with DDSRPC script
call ..\..\..\..\..\scripts\ddsrpc_rti_pcTests.bat -ppDisable "%*.idl"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Copy backup to original files.
move Client.cxx.backup Client.cxx
move %*ServerImpl.cxx.backup %*ServerImpl.cxx
:: Clean the visual solution
msbuild "%*-vs2010.sln" /t:Clean
:: Build the visual solution
msbuild "%*-vs2010.sln" /t:Build /p:Configuration="Release DLL"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Execute the server in other cmd.exe
start objs\x64Win64VS2010\%*Server.exe
:: Wait 5 seconds
call :wait 5
:: Execute the client in this cmd.exe
"objs\x64Win64VS2010\%*Client.exe"
set errorstatus=%ERRORLEVEL%
:: Kill server
TaskKill /IM "%*Server.exe"
goto :EOF

:: Fuction wait ::
:wait
@ping 192.168.1.10 -n %~1 -w 1000
goto:EOF

:: Function exit ::
:exit
if %errorstatus%==0 (echo "TEST SUCCESFULLY") else (echo "TEST FAILED")
exit /B %errorstatus%
goto :EOF