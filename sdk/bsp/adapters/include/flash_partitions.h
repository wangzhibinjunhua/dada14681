/**
 *****************************************************************************************
 *
 * @file flash_partitions.h
 *
 * @brief Default partition table
 *
 * Copyright (C) 2015. Dialog Semiconductor, unpublished work. This computer
 * program includes Confidential, Proprietary Information and is a Trade Secret of
 * Dialog Semiconductor. All use, disclosure, and/or reproduction is prohibited
 * unless authorized in writing. All Rights Reserved.
 *
 * <black.orca.support@diasemi.com> and contributors.
 *
 *****************************************************************************************
 */

#ifndef FLASH_PARTITIONS_H_
#define FLASH_PARTITIONS_H_

#ifndef PARTITION_TABLE_BEGIN
#define PARTITION_TABLE_BEGIN
#endif

#ifndef PARTITION_TABLE_ENTRY
/*
 * This to create partition entry in partition table.
 */
#define PARTITION_TABLE_ENTRY(start, size, id)
#endif

#ifndef PARTITION
/*
 * This macro can be used to define partition without specifying size. Size of partition created
 * with this macro will be computed using next partition starting address.
 * When this macro is used partition entries must be put in partition table in ascending starting
 * offset order.
 * Last entry in partition table can't be created with this macro.
 */
#define PARTITION(start, id, flags)
#endif

#ifndef PARTITION2
/*
 * This macro creates partition entry in similar way as PARTITION_TABLE_ENTRY but adds flags field.
 */
#define PARTITION2(start, size, id, flags)
#endif

#ifndef PARTITION_TABLE_END
#define PARTITION_TABLE_END
#endif

#define FLASH_SECTOR_SIZE 0x1000

#if defined(CUSTOM_CONFIG_SUOTA_1M_DEFINE)
#define PARTITION_TABLE_ADDR (0x060000 - (FLASH_SECTOR_SIZE))
#else
#define PARTITION_TABLE_ADDR (0x080000 - (FLASH_SECTOR_SIZE))
#endif

PARTITION_TABLE_BEGIN
#include <partition_table.h>
PARTITION_TABLE_END

#endif /* FLASH_PARTITIONS_H_ */

