#pragma once

#define BLOCK_PROTECT       (0X1C)
#define TOP_BOTTOM_PROTECT      (0X20)
#define SECTOR_PROTECT     (0X40)
#define STATUS_REGISTER_PROTECT1     (0X80)
#define STATUS_REGISTER_PROTECT2     (0X01)

#define SECTOR_ERASE_DISABLE        (0X7C)
#define BLOCK_ERASE_32K_DISABLE     (0X7C)
#define BLOCK_ERASE_64K_DISABLE     (0X7C)
#define CHIP_ERASE_DISABLE          (0X1C)


#define IS_BUSY         (0X01)
#define IS_WEL          (0X02)