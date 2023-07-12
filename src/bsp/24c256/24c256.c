#include"include.h"

#include"config.h"


void byte_write(uint8_t *data, uint16_t addr)
{

    i2c_start();
    i2c_send_byte(SLAVE_ADDR_w);
    i2c_send_byte((addr & 0xff00) >> 8);
    i2c_send_byte(addr & 0x00ff);
    i2c_send_data(data, sizeof(uint8_t));
    i2c_stop();

    return;
}

void page_write(uint8_t *data, size_t len)
{
    i2c_start();
    i2c_send_byte(SLAVE_ADDR_w);
    i2c_send_byte(WORD0_ADDR);
    i2c_send_byte(WORD1_ADDR);
    i2c_send_data(data, len);
    i2c_stop();

    return;
}

uint8_t current_addr_read(void)
{
    uint8_t temp = 0;

    i2c_start();
    i2c_send_byte(SLAVE_ADDR_r);
    temp = i2c_read_byte(0);
    i2c_stop();

    return temp;
}

uint8_t randow_read(uint16_t addr)
{
    uint8_t temp;
    i2c_start();
    i2c_send_byte(SLAVE_ADDR_w);
    i2c_send_byte((addr & 0xff00) >> 8);
    i2c_send_byte(addr & 0x00ff);
    i2c_start();
    i2c_send_byte(SLAVE_ADDR_r);
    temp = i2c_read_byte(0);
    i2c_stop();

    return temp;
}

void seq_read(void)
{
    i2c_start();
    i2c_send_byte(SLAVE_ADDR_r);
    i2c_send_data(x,DATA_NUM);
    i2c_stop();

    return;
}

void init_24c256(void)
{
    gpio_init_24c256();
    sda_h();
    sck_h();

    return;
}

#if TEST_24C256
    uint8_t test_24c256(void)
    {
        uint8_t temp = 0;
        byte_write(0x12, 0x1234);
        temp = randow_read(0x1234);

        if(temp == 0x12)
        return 1
        else
        return 0;
    }
#endif

