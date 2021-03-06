SUOTA in Proximity Reporter {#pxp_suota}
======================

## Overview

This application, besides its main functionality described [here](@ref pxp), can be built with Software Update over the Air (SUOTA) support.

Features:

- Advertising starts automatically once the application starts, advertising contains:
 - Proximity Reporter Profile information.
 - SUOTA service information.
 - DIS information
- Standard applications for Proximity Reporter profile can be used to connect to device.
- The Dialog dedicated applications for `Android` and `iOS` `Dialog SUOTA` can connect to device to perform software update.
Those applications can be found in _Play Store_ or _Apple App Store_.

## Installation procedure

To install the project follow the [General Installation and Debugging Procedure](@ref install_and_debug_procedure).

Import the project `ble_suota_loader` from `sdk/bsp/system/loaders/ble_suota_loader` and
build it in the `Release_QSPI` configuration.

### Prepare SUOTA image

SUOTA image is a binary file with a proper header that can be sent to a target device from Android or iOS device.
To create an image, open command prompt, navigate to a `projects/dk_apps/demos/ble_peripheral` folder
and run script to create the image file.

To build an image in Windows run:

> `mkimage.bat <build_configuration>`

Where build_configuration may be DA14681-01-Release_QSPI_SUOTA, DA14681-01-Debug_QSPI_SUOTA, etc.


To build an image in Linux run:

> `./mkimage.sh <build_configuration>`

Where build_configuration may be DA14681-01-Release_QSPI_SUOTA, DA14681-01-Debug_QSPI_SUOTA, etc

It prepares a `ble_peripheral.1.0.0.1.img` image file. The file name contains
a version number taken from a `sw_version.h`.

### Copy Image to Android or iOS device

The image file should be copied to Android phone or tablet or to iOS device inside the SUOTA folder of the device.
For iOS devices use iTunes.
For Android a USB cable can be used to connect the Android device with pc in order to copy the img file or the following command can be used to send the image:

> `adb push Debug_QSPI_SUOTA/ble_peripheral.1.0.0.1.img /sdcard/suota`

### Install bootloader and initial image

The bootloader and ble peripheral demo require a partition table that contains partitions for image storage.
If such partitions were not present on the target device the easiest way to fix this is to erase the existing
partition table sector. The bootloader will recreate it with correct values.
The following command writes the bootloader image and  the PXP image to the target device.

To program flash in Windows run:

> `initial_flash.bat <build_configuration>`

Where build_configuration may be DA14681-01-Release_QSPI_SUOTA, DA14681-01-Debug_QSPI_SUOTA, etc

To program flash in Linux run:

> `./initial_flash.sh <build_configuration>`

Where build_configuration may be DA14681-01-Release_QSPI_SUOTA, DA14681-01-Debug_QSPI_SUOTA, etc

When the initial flash is finished a device reboots and the application starts from the executable partition.

### Install bootloader only through Eclipse and download the image through SUOTA
If only the bootloader needs to be programmed, this can be done through Eclipse by the following steps:
- Click on `ble_suota_loader` in Project Explorer of Eclipse so that it becomes the active project.
- Press program_qspi_jtag_win, program_qspi_jtag_linux (when J-Link debugger will be used to
  programming) or program_qspi_serial_win, program _qspi_serial_linux (when UART will be used to
  programming) button (it is under Run > External Tools > External Tool Configurations) to download
  the `ble_suota_loader` to QSPI. If something goes wrong, reconnect the platform and repeat.

Then download the image through SUOTA by the following steps:

- Run the `./mkimage.sh` or the `mkimage.bat` to create a new image.
- Transfer the image to Android or iOS device.
- Find the device using SUOTA Application. The name of device shall be **Dialog PX Reporter**.
- Proceed with a software update in SUOTA Application.
- When programming is finished, the device reboots automatically and advertising starts again.

## Manual testing

- Build `ble_peripheral` `(Release_QSPI_SUOTA)` and `ble_suota_loader` using eclipse.
- Program flash with the suota image using the `inital_flash.bat` or the `./initial_flash.sh` script.
- Change vesion number in the `sw_version.h` file and rebuild the `ble_peripheral` project.
- Run the `./mkimage.sh` or the `mkimage.bat` to create a new image.
- Transfer the image to Android or iOS device.
- Find the device using SUOTA Application. The name of device shall be **Dialog PX Reporter**.
- Proceed with a software update in SUOTA Application.
- When programming is finished, the device reboots automatically and advertising starts again.
- The device should be visible as **Dialog PX Reporter** with the new version number.
- When the application is running verify that Proximity Reporter profile is available and working.
- When there are other active connections, SUOTA should fail.


##UserManual
- Import the project `ble_suota_loader` from `sdk/bsp/system/loaders/ble_suota_loader` and build it in the `Release_QSPI` configuration.
- build the project `ble_peripheral` in the `DA14681-01-Release_QSPI_SUOTA or DA14681-01-Debug_QSPI_SUOTA,` configuration.
- use External Tools with option 'suota_initial_flash_jtag_win' download to device 
- To create a SUOTA image binary file ,open command prompt and run the `./mkimage.sh` or the `mkimage.bat` to create a new image. eg:
  mkimage.bat <DA14681-01-Debug_QSPI_SUOTA> or mkimage.bat <DA14681-01-Release_QSPI_SUOTA>
- Transfer the image to Android or iOS device under the Suota folder.
- MISO GPIO : P0_2	MOSI GPIO : P0_1	CS GPIO : P0_5	CSK GPIO : P0_0   Image bank : 0  Block size : 240 	 

##PLT
-use plt in option Memory Functions:QSPI Flah,Write1:start address:0x00000000 ble_suota_loader.bin.cached  Write2:Start address :0x01F000  HB01_20170515_Release.bin
-HB01_20170515_Release.bin is maded with SmartSnippets Toolbox in option ASPI Programmer 
-bin2image qspi_cached ble_suota_loader.bin ble_suota_loader.bin.cached AD enable_uart
D:\Project\BLE\DA1458x_DA1468x_PLT_v_4.0\executables\binaries>bin2image qspi_cached ble_suota_loader.bin ble_suota_loader.bin.cached AD enable_uart

-0x095000 for sensor id