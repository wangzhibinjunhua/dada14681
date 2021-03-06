/*
 *****************************************************************************************
 *
 * Copyright (C) 2016. Dialog Semiconductor, unpublished work. This computer
 * program includes Confidential, Proprietary Information and is a Trade Secret of
 * Dialog Semiconductor. All use, disclosure, and/or reproduction is prohibited
 * unless authorized in writing. All Rights Reserved.
 *
 * <black.orca.support@diasemi.com> and contributors.
 *
 *****************************************************************************************
 */
#if defined(CUSTOM_CONFIG_SUOTA_1M_DEFINE)
//custom defined   1
PARTITION2( 0x000000 , 0x01E000 , NVMS_FIRMWARE_PART        , 0 )
PARTITION2( 0x01E000 , 0x001000 , NVMS_PRODUCT_HEADER_PART  , 0 )
PARTITION2( 0x01F000 , 0x001000 , NVMS_IMAGE_HEADER_PART    , 0 )
PARTITION2( 0x020000 , 0x030000 , NVMS_FW_EXEC_PART         , 0 )
PARTITION2( 0x050000 , 0x00D000 , NVMS_LOG_PART             , 0 )
PARTITION2( 0x05D000 , 0x002000 , NVMS_PLATFORM_PARAMS_PART , PARTITION_FLAG_READ_ONLY )
PARTITION2( 0x05F000 , 0x001000 , NVMS_PARTITION_TABLE      , PARTITION_FLAG_READ_ONLY )
PARTITION2( 0x060000 , 0x002000 , NVMS_PARAM_PART           , 0 )
PARTITION2( 0x062000 , 0x031000 , NVMS_FW_UPDATE_PART       , 0 )
PARTITION2( 0x093000 , 0x002000 , NVMS_GENERIC_PART         , PARTITION_FLAG_VES )
PARTITION2( 0x095000 , 0x001000 , NVMS_IMAGE_CUSTOM_CONFIG_PART                  , 0 )
PARTITION2( 0x096000 , 0x00f000 , NVMS_IMAGE_DATA_STORAGE_PART			, 0 )
PARTITION2( 0x0A5000 , 0x05B000 , NVMS_IMAGE_RESULT_DATA_STORAGE_PART		   , 0 )


#else
//custom defined   1
PARTITION2( 0x000000 , 0x01E000 , NVMS_FIRMWARE_PART        , 0 )
PARTITION2( 0x01E000 , 0x001000 , NVMS_PRODUCT_HEADER_PART  , 0 )
PARTITION2( 0x01F000 , 0x001000 , NVMS_IMAGE_HEADER_PART    , 0 )
PARTITION2( 0x020000 , 0x030000 , NVMS_FW_EXEC_PART         , 0 )
PARTITION2( 0x050000 , 0x00D000 , NVMS_LOG_PART             , 0 )
PARTITION2( 0x05D000 , 0x002000 , NVMS_PLATFORM_PARAMS_PART , PARTITION_FLAG_READ_ONLY )
PARTITION2( 0x05F000 , 0x001000 , NVMS_PARTITION_TABLE      , PARTITION_FLAG_READ_ONLY )
PARTITION2( 0x060000 , 0x002000 , NVMS_PARAM_PART           , 0 )
PARTITION2( 0x062000 , 0x031000 , NVMS_FW_UPDATE_PART       , 0 )
PARTITION2( 0x093000 , 0x002000 , NVMS_GENERIC_PART         , PARTITION_FLAG_VES )
PARTITION2( 0x095000 , 0x066000 , NVMS_IMAGE_DATA_STORAGE_PART			, 0 )
PARTITION2( 0x0FB000 , 0x005000 , NVMS_IMAGE_RESULT_DATA_STORAGE_PART		   , 0 )

//custom defined   2
PARTITION2( 0x000000 , 0x01E000 , NVMS_FIRMWARE_PART        , 0 )
PARTITION2( 0x01E000 , 0x001000 , NVMS_PRODUCT_HEADER_PART  , 0 )
PARTITION2( 0x01F000 , 0x001000 , NVMS_IMAGE_HEADER_PART    , 0 )
PARTITION2( 0x020000 , 0x030000 , NVMS_FW_EXEC_PART         , 0 )
PARTITION2( 0x050000 , 0x00D000 , NVMS_LOG_PART             , 0 )
PARTITION2( 0x05D000 , 0x002000 , NVMS_PLATFORM_PARAMS_PART , PARTITION_FLAG_READ_ONLY )
PARTITION2( 0x05F000 , 0x001000 , NVMS_PARTITION_TABLE      , PARTITION_FLAG_READ_ONLY )
PARTITION2( 0x060000 , 0x002000 , NVMS_PARAM_PART           , 0 )
PARTITION2( 0x062000 , 0x031000 , NVMS_FW_UPDATE_PART       , 0 )
PARTITION2( 0x093000 , 0x00F000 , NVMS_GENERIC_PART         , PARTITION_FLAG_VES )
PARTITION2( 0x0A2000 , 0x059000 , NVMS_IMAGE_DATA_STORAGE_PART			, 0 )
PARTITION2( 0x0FB000 , 0x005000 , NVMS_IMAGE_RESULT_DATA_STORAGE_PART		   , 0 )

//default
PARTITION2( 0x000000 , 0x01E000 , NVMS_FIRMWARE_PART        , 0 )
PARTITION2( 0x01E000 , 0x001000 , NVMS_PRODUCT_HEADER_PART  , 0 )
PARTITION2( 0x01F000 , 0x001000 , NVMS_IMAGE_HEADER_PART    , 0 )
PARTITION2( 0x020000 , 0x050000 , NVMS_FW_EXEC_PART         , 0 )
PARTITION2( 0x070000 , 0x00D000 , NVMS_LOG_PART             , 0 )
PARTITION2( 0x07D000 , 0x002000 , NVMS_PLATFORM_PARAMS_PART , PARTITION_FLAG_READ_ONLY )
PARTITION2( 0x07F000 , 0x001000 , NVMS_PARTITION_TABLE      , PARTITION_FLAG_READ_ONLY )
PARTITION2( 0x080000 , 0x010000 , NVMS_PARAM_PART           , 0 )
PARTITION2( 0x090000 , 0x051000 , NVMS_FW_UPDATE_PART       , 0 )
PARTITION2( 0x0E1000 , 0x01F000 , NVMS_GENERIC_PART         , PARTITION_FLAG_VES )
#endif
