#pragma once

#define W25Q128_TEST        0
#define READ_STATUS_REGISTER        0
#define BLOCK_PROCTECT_TEST         0

typedef enum {
    w25q128_read_success,
    w25q128_erase_success = 1,
    w25q128_suspend_success ,
    w25q128_resume_success ,
    w25q128_erase_false ,
    w25q128_suspend_false ,
    w25q128_resume_false ,

}w25q128_err_t;


void w25q128_test(void);
void w25q64_block_proctect(void);
void w25q64_top_bottom_protect(void);
void w25q64_sector_protect(void);
void w25q64_status_register_protect(void);
int w25q64_read_data(uint32_t addr, uint8_t *buffer, size_t len);
int w25q64_fast_read_data(uint32_t addr, uint8_t *buffer, size_t len);
int w25q64_sector_erase(uint32_t addr);
int w25q64_block_erase_32k(uint32_t addr);
int w25q64_block_erase_64k(uint32_t addr);
int w25q64_chip_erase(void);
int w25q64_erase_suspend(void);
int w25q64_erase_resume(void);


