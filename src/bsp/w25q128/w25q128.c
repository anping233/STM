#include"include.h"

#include "cmd.h"
#include "config.h"

static inline void cs_enable(void) {
    gpio_reset(SPI_CS_GPIO_PORT, SPI_CS_GPIO_PIN);
    return ;
}

static inline void cs_disable(void) {
    gpio_set(SPI_CS_GPIO_PORT, SPI_CS_GPIO_PIN);
    return ;
}

static void send_cmd(const uint8_t *psend, size_t send_sz, uint8_t *precv, size_t recv_sz)
 {
    assert(psend != NULL || precv != NULL);
    cs_enable();

    if (psend != NULL)
    {
        for (size_t i = 0; i < send_sz; i++)
            spi_write_read_byte(psend[i]);
    }

    if (precv != NULL)
    {
        for (size_t i = 0; i < recv_sz; i++)
            precv[i] = spi_write_read_byte(0);
    }

    cs_disable();
    return;
}

static bool w25q64_is_wel(void)
{
    uint8_t *status;
    uint8_t data[] = {WRITE_ENABLE, READ_STATUS_REGISTER1, 0};

    send_cmd(data, sizeof(data), status, 1);

    if(status[0] == IS_WEL)
        return true;
    else
        return false;
}


static bool w25q64_is_busy(void)
{
    uint8_t *status;
    uint8_t data[] = {WRITE_ENABLE, READ_STATUS_REGISTER1, 0};

    send_cmd(data, sizeof(data), status, 1);

    if(status[0] == IS_BUSY)
        return true;
    else
        return false;
}

static uint8_t w25q64_read_wp(void)
{
    uint8_t *status;
    uint8_t data[] = {WRITE_ENABLE, READ_STATUS_REGISTER1, 0};

    send_cmd(data, sizeof(data), status, 1);

    return status[0];
}


void w25q64_block_proctect(void)
{
    uint8_t data[] = {WRITE_ENABLE, WRITE_STATUS_REGISTER, BLOCK_PROTECT};

    send_cmd(data, sizeof(data), NULL, 0);
    return ;
}

void w25q64_top_bottom_protect(void)
{
    uint8_t data[] = {WRITE_ENABLE, WRITE_STATUS_REGISTER, TOP_BOTTOM_PROTECT};

    send_cmd(data, sizeof(data), NULL, 0);
    return ;
}

void w25q64_sector_protect(void)
{
    uint8_t data[] = {WRITE_ENABLE, WRITE_STATUS_REGISTER, SECTOR_PROTECT};

    send_cmd(data, sizeof(data), NULL, 0);
    return;
}

void w25q64_status_register_protect(void)
{
    uint8_t data[] = {WRITE_ENABLE, WRITE_STATUS_REGISTER, STATUS_REGISTER_PROTECT1, STATUS_REGISTER_PROTECT2};

    send_cmd(data, sizeof(data), NULL, 0);
    return;
}

int w25q64_read_data(uint32_t addr, uint8_t *buffer, size_t len)
{
    uint8_t data[] = {READ_DATA, addr >> 16, addr >> 8, addr};

    send_cmd(data, sizeof(data), buffer, len);
    return w25q128_read_success;
}

int w25q64_fast_read_data(uint32_t addr, uint8_t *buffer, size_t len)
{
    uint8_t data[] = {FAST_READ, addr >> 16, addr >> 8, addr, 0};

    send_cmd(data, sizeof(data), buffer, len);
    return w25q128_read_success;
}

int w25q64_sector_erase(uint32_t addr)
{
    if (w25q64_is_wel() != true)// 当WEL != 1时
        return w25q128_erase_false;

    if ((w25q64_read_wp() & SECTOR_ERASE_DISABLE) != 0) //当被写保护时，不允许擦除操作
        return w25q128_erase_false;

        uint8_t data[] = {SECTOR_ERASE, addr >> 16, addr >> 8, addr, 0};
        send_cmd(data, sizeof(data), NULL, 0);
        return w25q128_erase_success;
}

int w25q64_block_erase_32k(uint32_t addr)
{
    if (w25q64_is_wel() != true)// 当WEL != 1时
        return w25q128_erase_false;

    if ((w25q64_read_wp() & BLOCK_ERASE_32K_DISABLE) != 0) //当被写保护时，不允许擦除操作
        return w25q128_erase_false;

    uint8_t data[] =  {BLOCK_ERASE_32KB,(addr >> 16) & 0xff, (addr >> 8) & 0xff, addr & 0xff};
    send_cmd(data, sizeof(data), NULL, 0);
    return w25q128_erase_success;
}

int w25q64_block_erase_64k(uint32_t addr)
{
    if (w25q64_is_wel() != true)// 当WEL != 1时
        return w25q128_erase_false;

    if ((w25q64_read_wp() & BLOCK_ERASE_64K_DISABLE) != 0) //当被写保护时，不允许擦除操作
        return w25q128_erase_false;

    uint8_t data[] =  {BLOCK_ERASE_64KB,(addr >> 16) & 0xff, (addr >> 8) & 0xff, addr & 0xff};
    send_cmd(data, sizeof(data), NULL, 0);
    return w25q128_erase_success;
}

int w25q64_chip_erase(void)
{

    if (w25q64_is_wel() != true)// 当WEL != 1时
        return w25q128_erase_false;

    if ((w25q64_read_wp() & CHIP_ERASE_DISABLE) != 0) //当被写保护时，不允许擦除操作
        return w25q128_erase_false;

    uint8_t data[] =  {CHIP_ERASE};
    send_cmd(data, sizeof(data), NULL, 0);
    return w25q128_erase_success;
}

int w25q64_erase_suspend(void)
{
    uint8_t data[] =  {ERASE_SUSPEND};

    if ( w25q64_is_busy() == false)// 当BUSY = 1时
        return w25q128_suspend_false;

    send_cmd(data, sizeof(data), NULL, 0);
    delay_us(20);
    return w25q128_suspend_success;
}

int w25q64_erase_resume(void)
{
    uint8_t data[] = {ERASE_RESUME};

    if (w25q64_is_busy() == true)//当BUSY = 0时
        return w25q128_resume_false;

    delay_us(20);
    send_cmd(data, sizeof(data), NULL, 0);
    return w25q128_resume_success;
}


void w25q128_test(void)
{

#if 0
    uint8_t data;
    uint8_t *buffer;

    data[] = {0x90, 0x00, 0x00, 0x00, 0x00, 0x00};
    send_cmd(data, sizeof(data), buffer, 2);
    printf("0x%x\n",buffer[0]);
    printf("0x%x\n",buffer[1]);
#endif

    uint8_t *buffer;
    w25q64_read_data(0x40ff00, buffer, 3);
    printf("buffer[0] = %x\n",buffer[0]);
    printf("buffer[1] = %x\n",buffer[1]);
    printf("buffer[2] = %x\n",buffer[2]);
    w25q64_block_erase_32k(0x40ff00);
    uint8_t *buffer1;
    w25q64_read_data(0x40ff00, buffer1, 3);
    printf("buffer[0] = %x\n",buffer1[0]);
    printf("buffer[1] = %x\n",buffer1[1]);
    printf("buffer[2] = %x\n",buffer1[2]);

    return;
}
