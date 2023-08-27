#pragma once

#define  WRITE_ENABLE    (0X06)
#define  WRITE_DISABLE    (0X04)
#define  READ_STATUS_REGISTER1    (0X05)
#define  READ_STATUS_REGISTER2    (0X35)
#define  WRITE_STATUS_REGISTER     (0X01)
#define  READ_DATA      (0X03)
#define  FAST_READ      (0X0B)
#define  PAGE_PROGRAM    (0X02)
#define  SECTOR_ERASE    (0X20)
#define  BLOCK_ERASE_32KB    (0X52)
#define  BLOCK_ERASE_64KB    (0XD8)
#define  CHIP_ERASE      (0XC7)
#define  ERASE_SUSPEND   (0X75)
#define  ERASE_RESUME    (0X7A)
#define  POWER_DOWN      (0XB9)
#define  HIGH_PERFOR     (0XA3)
#define  RESLSE_POWER_DOWN (0XAB)
#define  REALSE_HIGH_PERFOR      (0XAB)
#define  READ_MANUFACTURER_ID       (0X90)
#define  READ_DEVICE_ID          (0X90)
#define  READ_UNIGUE_ID      (0X4B)
#define  READ_JEDEC_ID       (0x9F)



