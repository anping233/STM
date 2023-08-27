#include"include.h"

#include"config.h"


void byte_write(uint8_t *data, uint16_t addr)
{

    i2c_start();
    i2c_send_byte(SLAVE_ADDR_W);
    sck_h();
    sck_l();
    i2c_send_byte(addr >> BITS_PER_BYTE);
    sck_h();
    sck_l();
    i2c_send_byte(addr & (nbits(BITS_PER_BYTE)));
    sck_h();
    sck_l();
    i2c_send_data(data, sizeof(uint8_t));
    sck_h();
    sck_l();
    i2c_stop();

    delay_ms(20);

    return;
}

void page_write(uint16_t addr, uint8_t *data, size_t len)
{
    i2c_start();
    i2c_send_byte(SLAVE_ADDR_W);
    sck_h();
    sck_l();
    i2c_send_byte(addr >> BITS_PER_BYTE);
    sck_h();
    sck_l();
    i2c_send_byte(addr & (nbits(BITS_PER_BYTE)));
    sck_h();
    sck_l();
    i2c_send_data(data, len);
    sck_h();
    sck_l();
    i2c_stop();

    return;
}

uint8_t current_addr_read(void)
{
    uint8_t temp = 0;

    i2c_start();
    i2c_send_byte(SLAVE_ADDR_R);
    sck_h();
    sck_l();
    temp = i2c_read_byte(0);
    sck_h();
    sck_l();
    i2c_stop();

    return temp;
}

uint8_t randow_read(uint16_t addr)
{
    uint8_t temp = 0;
    i2c_start();
    i2c_send_byte(SLAVE_ADDR_W);
    sck_h();
    sck_l();
    i2c_send_byte(addr >> BITS_PER_BYTE);
    sck_h();
    sck_l();
    i2c_send_byte(addr & (nbits(BITS_PER_BYTE)));
    sck_h();
    sck_l();
    i2c_start();
    i2c_send_byte(SLAVE_ADDR_R);
    sck_h();
    sck_l();
    temp = i2c_read_byte(0);
    i2c_stop();

    return temp;
}

void seq_read(uint8_t *buffer, uint8_t len)
{
    uint8_t i = 0;

    i2c_start();
    i2c_send_byte(SLAVE_ADDR_R);

    while (len--)
    {
        if(len == 1)
        {
            buffer[i++] = i2c_read_byte(0);
        }
        else
        {
            buffer[i++] = i2c_read_byte(1);
        }
    }

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

#if E2_24C256_TEST_EN
    uint8_t test_24c256(void)
    {
        uint8_t temp0 = 0;
        byte_write(0x12, 0x1234);
        temp0 = randow_read(0x1234);

        if(temp0 == 0x12)
            return 1;
        else
            return 0;
    }
#endif

