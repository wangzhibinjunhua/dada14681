@SETLOCAL
@set on_off=OFF
@echo %on_off%
SETLOCAL ENABLEEXTENSIONS
SETLOCAL ENABLEDELAYEDEXPANSION

@rem store this script name for help
set thisfile=%~0
set nobootloader=
set this_folder=%~dp0

set config_file=program_qspi_ini.cmd
set user_config_file=program_qspi_config.bat

set version=sw_version.h
:more_options
shift
if "%~0"=="" goto :no_more_options
if /i "%~0"=="-v" (set verbose=-v
    set verbose_on=on
    goto :more_options)
if /i "%~0"=="-q" (set quiet=1
    goto :more_options)
if /i "%~0"=="--nobootloader" (set nobootloader=1
    goto :more_options)
if /i "%~0"=="--id" (set device_sn=%1
    shift
    goto :more_options)
if /i "%~0"=="--bootloader" (set bootloader=%1
    shift
    goto :more_options)
if /i "%~0"=="-b" (set bootloader=%1
    shift
    goto :more_options)
if /i "%~0"=="/?" goto :help
if /i "%~0"=="--help" goto :help
if /i "%~0"=="-h" goto :help

:no_more_options
if "" == "%verbose%" set verbose_on=%on_off%

@rem Setup SDK root
if DEFINED SDKROOT goto :sdk_set

pushd %this_folder%\..\..\..\..
set SDKROOT=%CD%
popd

:sdk_set
set SUOTA_LOADER_PATH=%SDKROOT%\sdk\bsp\system\loaders\ble_suota_loader
set UARTBOOT_PATH=%SDKROOT%\sdk\bsp\system\loaders\uartboot

if not exist "%SDKROOT%\utilities\scripts\qspi\%config_file%" (
   pushd %this_folder%\..\..\..\..\utilities\scripts\qspi
   call %user_config_file%
   popd
)

call "%SDKROOT%\utilities\scripts\qspi\%config_file%"

set build_config=DA14681-01-Release_QSPI

set CLI=%SDKROOT%\binaries\cli_programmer
set QSCR=%SDKROOT%\utilities\scripts\qspi
if not defined quiet echo Using SDK from %SDKROOT%
if not defined quiet echo cli_programmer from %CLI%

if defined %bootloader (
  set boot_loader_bin=%bootloader%
) else (
  set boot_loader_bin=%SUOTA_LOADER_PATH%\%build_config%\ble_suota_loader.bin
)

if "%~0" == "" (
  echo No binary file specified
  exit /b 1
)

set bin_file=%~f0
shift

if exist "%~0" (
  @rem Jlink path given by user: %jlink_path%
  @REM Remove quotes if any
  for /F "tokens=*" %%i in (%0) do set jlink_path=%%~i
)

if not defined quiet echo image file %bin_file%
if not defined quiet echo boot loader %boot_loader_bin%

call :banner "Preparing image file"
set image_file=application_image.img

@rem Create application image with known name that will be used by cli_programmer
@echo %verbose_on%
call "%sdkroot%\utilities\scripts\suota\v11\mkimage.bat" %verbose% "%bin_file%" "%image_file%"
@echo %on_off%

set TMPCFG=%TEMP%\cfg_%RANDOM%.ini

if "%jlink_path%"=="" if "%device_sn%"=="" (
%windir%\system32\CScript /Nologo "%sdkroot%\utilities\scripts\qspi\prepare_local_ini_file.vbs" --cfg "%TMPCFG%"
goto exec_cli
)

if "%jlink_path%"=="" (
%windir%\system32\CScript /Nologo "%sdkroot%\utilities\scripts\qspi\prepare_local_ini_file.vbs" --id %device_sn% --cfg "%TMPCFG%"
goto exec_cli
)

if "%device_sn%"=="" (
%windir%\system32\CScript /Nologo "%sdkroot%\utilities\scripts\qspi\prepare_local_ini_file.vbs" --cfg "%TMPCFG%" --jlink_path "%jlink_path%"
goto exec_cli
)

%windir%\system32\CScript /Nologo "%sdkroot%\utilities\scripts\qspi\prepare_local_ini_file.vbs" --id %device_sn% --cfg "%TMPCFG%" --jlink_path "%jlink_path%"

:exec_cli
if defined nobootloader goto skip_erase_bl
@rem Erase bootloader and partition table
call :banner "Erasing bootloader area"
@echo %verbose_on%
"%CLI%" --cfg "%TMPCFG%" gdbserver erase_qspi 0 4096
@echo %on_off%
:skip_erase_bl

call :banner "Erasing partition table"
@echo %verbose_on%
"%CLI%" --cfg "%TMPCFG%" gdbserver erase_qspi 0x5F000 4096
@echo %on_off%

@rem Flash application image to update partition. It will be moved to image partition by bootloader
call :banner "Writing application image"
@echo %verbose_on%
"%CLI%" --cfg "%TMPCFG%" gdbserver write_qspi 0x20000 "%bin_file%"
call :banner "Writing image header"
@echo %verbose_on%
"%CLI%" --cfg "%TMPCFG%" gdbserver write_qspi 0x1F000 "%image_file%" 36
del "%image_file%"
@echo %on_off%

if defined nobootloader goto skip_bl
@rem Flash bootloader
call :banner "Writing bootloader"
pushd %QSCR%
@echo %verbose_on%
call program_qspi_jtag.bat --cfg "%TMPCFG%" "%boot_loader_bin%"
@echo %on_off%
popd
:skip_bl

if "%jlink_path%"=="" (
%windir%\system32\CScript /Nologo "%sdkroot%\utilities\scripts\qspi\reboot_device.vbs" %id%
goto clean_up
)
%windir%\system32\CScript /Nologo "%sdkroot%\utilities\scripts\qspi\reboot_device.vbs" --jlink_path "%jlink_path%" %id%

:clean_up
del "%TMPCFG%"

exit /b 0

:help
echo Usage:
echo %thisfile% [-h] [-q] [--nobootloader] [--id serial_number] [-b bootloader] bin_file [jlink_path]
echo    where:
echo      -h - prints this help
echo      -q - reduce number of prints
echo      --nobootloader - do not flash bootloader
echo      --id serial_number - serial number of jlink to connect to
echo      -b or --bootloader - bootloader to flash, if not specified default will be used
echo.
echo      bin_file - application binary file to flash
echo      jlink_path - path to Jlink, if not specified default will be used
exit /b 0

:banner
@if defined quiet goto :eof
@echo .......................................................................................................................
@echo ..
@echo .. %~1
@echo ..
@echo .......................................................................................................................
@goto:eof
