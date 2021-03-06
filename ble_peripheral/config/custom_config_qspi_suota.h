/**
\addtogroup BSP
\{
\addtogroup CONFIG
\{
\addtogroup CUSTOM
\{
*/

/**
****************************************************************************************
*
* @file custom_config_qspi.h
*
* @brief Board Support Package. User Configuration file for cached QSPI mode.
*
* Copyright (C) 2015. Dialog Semiconductor, unpublished work. This computer
* program includes Confidential, Proprietary Information and is a Trade Secret of
* Dialog Semiconductor. All use, disclosure, and/or reproduction is prohibited
* unless authorized in writing. All Rights Reserved.
*
* <black.orca.support@diasemi.com> and contributors.
*
****************************************************************************************
*/

#ifndef CUSTOM_CONFIG_QSPI_SUOTA_H_
#define CUSTOM_CONFIG_QSPI_SUOTA_H_

#include "bsp_definitions.h"

#define CONFIG_RETARGET
#define CONFIG_RETARGET_UART    HW_UART1
#define CONFIG_RETARGET_UART_BAUDRATE    HW_UART_BAUDRATE_1000000

#define dg_configUSE_BOD                (1)

#define RBLE_SENSOR_CTRL_BY_APP

#define RBLE_SENOR_TEST_CUSTOM
#define RBLE_DMA_I2C_INTERFACE
#define RBLE_V18P_GPIO_CTRL

#define MEMS_20648
////#define RBLE_UART_DEBUG

//#define dg_configPOWER_EXT_1V8_PERIPHERALS      (1)

#define CUSTOM_CONNECTION

#define dg_configPOWER_1V8P			(1)

#define RBLE_PCB_B01_CUSTOM

#define BLE_USE_DATA_V5

#define MEMS_SECONDARY_DEVICE

#define MEMS_AUGMENTED_SENSORS

#define RBLE_FLOAT_MATH_QFBLIB

#define CUSTOM_CONFIG_SUOTA_1M_DEFINE

#define RBLE_DATA_STORAGE_IN_FLASH

#define CUSTOM_CONFIG_SERIAL_NUMBER_DEFINE
#define CUSTOM_REBOOT_VOL_RECORD


#define RBLE_DMP_REPEAT_WRITE
#define RBLE_SAMPLE_TIMER_SWITCH
  
#define CONFIG_USE_BLE

#define dg_configTESTMODE_MEASURE_SLEEP_CURRENT (0)

#define dg_configUSE_LP_CLK                     LP_CLK_32768
#define dg_configEXEC_MODE                      MODE_IS_CACHED
#define dg_configCODE_LOCATION                  NON_VOLATILE_IS_FLASH
#define dg_configEXT_CRYSTAL_FREQ               EXT_CRYSTAL_IS_16M

#define dg_configIMAGE_SETUP                    PRODUCTION_MODE	//DEVELOPMENT_MODE
#define dg_configEMULATE_OTP_COPY               (0)

#define dg_configIMAGE_FLASH_OFFSET             (0x20000)
#define dg_configSUOTA_SUPPORT                  (1)

#define dg_configUSER_CAN_USE_TIMER1            (0)

/*
 * Controls the retRAM size used by the project.
 * 0: all RAM is retained
 * 1: retention memory size is optimal
 */
#define proj_configOPTIMAL_RETRAM                (0)

#if !defined(RELEASE_BUILD) && (proj_configOPTIMAL_RETRAM == 1)
        /* WARNING: retRAM optimizations are disabled in DEBUG builds! */
        #undef proj_configOPTIMAL_RETRAM
        #define proj_configOPTIMAL_RETRAM       (0)
#elif (dg_configEXEC_MODE != MODE_IS_CACHED)
        /* WARNING: retRAM optimizations are not applicable in MIRRORED mode! */
        #undef proj_configOPTIMAL_RETRAM
        #define proj_configOPTIMAL_RETRAM       (0)
#endif

#if (proj_configOPTIMAL_RETRAM == 0)
        #define dg_configMEM_RETENTION_MODE     (0x1F)
        #define dg_configSHUFFLING_MODE         (0x3)
#else
                #define dg_configMEM_RETENTION_MODE             (0x14)
                #define dg_configSHUFFLING_MODE                 (0x2)
#endif

#define dg_configUSE_WDOG                       (1)
//#define dg_configUSE_WDOG                       (0)




#define dg_configFLASH_CONNECTED_TO             (FLASH_CONNECTED_TO_1V8)
#define dg_configFLASH_POWER_DOWN               (1)
#define dg_configPOWER_1V8_ACTIVE               (1)
#define dg_configPOWER_1V8_SLEEP                (1)

#define dg_configBATTERY_TYPE                   (BATTERY_TYPE_LIMN2O4)
#define dg_configBATTERY_CHARGE_CURRENT         2       // 30mA
#define dg_configBATTERY_PRECHARGE_CURRENT      20      // 2.1mA
#define dg_configBATTERY_CHARGE_NTC             1       // disabled


#define STOP_SENSOR_AFTER_THREE_HOUR
#define THREE_HOUR (3*3600*1000)
//test
#define RBLE_BAT_MEASURE
#define dg_configBATTERY_ADAPTER 	1
#define dg_configUSE_USB                        0
#define dg_configUSE_USB_CHARGER                0
#define dg_configALLOW_CHARGING_NOT_ENUM        1

#define dg_configUSE_ProDK                      (1)

#define dg_configUSE_SW_CURSOR                  (1)

#define dg_configCACHEABLE_QSPI_AREA_LEN        (NVMS_PARAM_PART_start - MEMORY_QSPIF_BASE)

/*
 * Specifies the heap overhead while SUOTA is ongoing.
 */
#define SUOTA_HEAP_OVERHEAD                     (2048)

/*************************************************************************************************\
 * FreeRTOS specific config
 */
#define OS_FREERTOS                              /* Define this to use FreeRTOS */
#define configTOTAL_HEAP_SIZE                    16384   /* This is the FreeRTOS Total Heap Size */

/*************************************************************************************************\
 * Peripheral specific config
 */
#define dg_configFLASH_ADAPTER                  1
#define dg_configNVMS_ADAPTER                   1
#define dg_configNVMS_VES                       1
#define dg_configGPADC_ADAPTER                  1

/*
 * SUOTA loader configuration:
 * - To enable SUOTA over GATT only, set SUOTA_VERSION to any version >= SUOTA_VERSION_1_1
 *      and leave SUOTA_PSM undefined.
 * - To enable SUOTA over GATT and L2CAP CoC, set SUOTA_VERSION to any version >= SUOTA_VERSION_1_2
 *      and also define SUOTA_PSM to match the desired PSM. In this case the central device
 *      can use either of both according to its preference.
 */
#define SUOTA_VERSION   SUOTA_VERSION_1_3
#define SUOTA_PSM       0x81

#define USE_PARTITION_TABLE_1MB_WITH_SUOTA

/*************************************************************************************************\
 * BLE device config
 */
#define dg_configBLE_CENTRAL                    (0)
#define dg_configBLE_GATT_CLIENT                (0)
#define dg_configBLE_OBSERVER                   (0)
#define dg_configBLE_BROADCASTER                (0)
#ifndef SUOTA_PSM
#define dg_configBLE_L2CAP_COC                  (0)
#endif
/*************************************************************************************************\
 * Peripheral specific config
 */
/////#define dg_configUSE_HW_TRNG                    (1)
#define dg_configUSE_HW_I2C                     (1)
////#define dg_configUSE_HW_SPI                     (1)
////#define dg_configUSE_HW_KEYBOARD_SCANNER        (1)

#define dg_configI2C_ADAPTER                    (1)
////#define dg_configSPI_ADAPTER                    (1)
////#define dg_configUART_ADAPTER                   (1)

/* Include bsp default values */
#include "bsp_defaults.h"

/*************************************************************************************************\
 * Memory layout configuration
 */
#if (dg_configCODE_LOCATION == NON_VOLATILE_IS_OTP)
        // CODE_SIZE cannot be more than 58K
        #define CODE_SIZE     ( 58 * 1024)

        #if (dg_configEXEC_MODE == MODE_IS_CACHED)
                        /* DA14681-01
                         * RAM goes first, RetRAM0 follows. RetRAM1 is added at the beginning when
                         * optimized RetRAM configuration is used (so that the IVT is preserved).
                         * RAM size should be defined such that it covers the whole empty space
                         * between RetRAM1, if it exists, and RetRAM0.
                         */
                        #define RETRAM_FIRST    0

                        #define RAM_SIZE        ( 64 * 1024)

                        #if (proj_configOPTIMAL_RETRAM == 0)
                                #define RETRAM_0_SIZE   ( 64 * 1024)
                                #define RETRAM_1_SIZE   (  0 * 1024)
                        #else
                                #define RETRAM_0_SIZE   ( 32 * 1024)
                                #define RETRAM_1_SIZE   ( 32 * 1024)
                        #endif
        #else // MIRRORED
                        /* DA14681-01
                         * CODE is first, RetRAM follows. RAM is last, always 16K.
                         *
                         * RetRAM uses all RAM5 block. RAM uses CACHE.
                         */
                        #define RETRAM_FIRST    1

                        #define RAM_SIZE        ( 16 * 1024)
                        #define RETRAM_0_SIZE   (128 * 1024 - CODE_SIZE)
                        #define RETRAM_1_SIZE   (  0 * 1024)
        #endif

        #if (CODE_SIZE > (58 * 1024))
                #error "maximum CODE size when OTP is used is 58K!"
        #endif

#elif (dg_configCODE_LOCATION == NON_VOLATILE_IS_FLASH)
        #define CODE_SIZE     (172 * 1024)
        //#define CODE_SIZE     (256 * 1024)
	#if 1
			//test_r
		/* DA14681-01
		 * RAM goes first, RetRAM0 follows. RetRAM1 is added at the beginning when
		 * optimized RetRAM configuration is used (so that the IVT is preserved).
		 */
                        #define RETRAM_FIRST    0
		
                        #define RAM_SIZE        ( 64 * 1024)		
                       
                        #define RETRAM_0_SIZE   ( 64 * 1024)
                        #define RETRAM_1_SIZE   (  0 * 1024)                        

        #elif  0 
		//(dg_configEXEC_MODE == MODE_IS_CACHED)
                        /* DA14681-01
                         * RAM goes first, RetRAM0 follows. RetRAM1 is added at the beginning when
                         * optimized RetRAM configuration is used (so that the IVT is preserved).
                         */
                        #define RETRAM_FIRST    0

                        #define RAM_SIZE        ( 64 * 1024)

                        #if (proj_configOPTIMAL_RETRAM == 0)
                                #define RETRAM_0_SIZE   ( 64 * 1024)
                                #define RETRAM_1_SIZE   (  0 * 1024)
                        #else
                                #define RETRAM_0_SIZE   ( 32 * 1024)
                                #define RETRAM_1_SIZE   ( 32 * 1024)
                        #endif
        #else // MIRRORED
                #error "QSPI mirrored mode is not supported!"
        #endif

#elif (dg_configCODE_LOCATION == NON_VOLATILE_IS_NONE)
                #define CODE_SIZE       ( 79 * 1024)

        #if (dg_configEXEC_MODE == MODE_IS_CACHED)
                #warning "RAM cached mode is not supported! Reset to RAM (mirrored) mode!"
                #undef dg_configEXEC_MODE
                #define dg_configEXEC_MODE      MODE_IS_RAM
        #endif

                /* DA14681-01
                 * CODE is first, RetRAM follows. RAM is last, always 16K.
                 *
                 * RetRAM uses all RAM5 block. RAM uses CACHE.
                 */
                #define RETRAM_FIRST    1

                #define RAM_SIZE        ( 16 * 1024)
                #define RETRAM_0_SIZE   (128 * 1024 - CODE_SIZE)
                #define RETRAM_1_SIZE   (  0 * 1024)

#else
        #error "Unknown configuration..."
#endif

#endif /* CUSTOM_CONFIG_QSPI_SUOTA_H_ */

/**
\}
\}
\}
*/
