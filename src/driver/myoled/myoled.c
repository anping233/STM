#include"include.h"

#include"font.h"

uint8_t oled_pow(uint8_t x, uint8_t y)
{
    uint8_t result = 1;

    while (y--)
    {
        result *= x;
    }

    return result;
}

void send_commend(uint8_t commend)
{
    sda_out();
    i2c_start();
    i2c_send_byte(0x78);
    sck_h();
    sck_l();
    i2c_send_byte(0x00);
    sck_h();
    sck_l();
    i2c_send_byte(commend);
    sck_h();
    sck_l();
    i2c_stop();

    return;
}

void send_data(uint8_t data)
{
    sda_out();
    i2c_start();
    i2c_send_byte(0x78);
    sck_h();
    sck_l();
    i2c_send_byte(0x40);
    sck_h();
    sck_l();
    i2c_send_byte(data);
    sck_h();
    sck_l();
    i2c_stop();
    return;
}

void set_cursor(uint8_t seg,uint8_t col)
{
    send_commend(0xB0 | seg);
    send_commend(0x10 | ((col & 0xf0) >> 4));
    send_commend(0x00 | (col & 0x0f));
    return;
}

void oled_clear(void)
{
    uint8_t i;
    for(i = 0; i < 8; i++)
    {
        set_cursor(i,0);
        for( uint8_t j = 0; j < 128; j++)
        {
            send_data(0x00);
        }
    }

    return;
}

void oled_show_char(uint8_t seg, uint8_t col,char character)
{
    uint8_t i;

    set_cursor((seg - 1) * 2, (col - 1) * 8);

    for(i = 0; i < 8; i++)
    {
        send_data(oled_arry[character - ' '][i]);
    }

    set_cursor(((seg - 1) * 2 ) + 1, (col - 1) * 8);

    for(i = 0; i < 8; i++)
    {
        send_data(oled_arry[character - ' '][i + 8]);
    }

    return;
}

void oled_show_string(uint8_t seg, uint8_t col,char *string)
{
    uint8_t i;

    for(i = 0; string[i] != '\0'; i++)
    {
        oled_show_char(seg, col + i, string[i]);
    }

    return;
}

void oled_show_num(uint8_t seg, uint8_t col, uint32_t num, uint8_t len)
{
    uint8_t i;

    for(i = 0; i < len; i++)
    {
        oled_show_char(seg, col + 1, num /oled_pow(10,(len - i - 1)) % 10 + '0');
    }
    return;
}

void oled_show_sign_num(uint8_t seg, uint8_t col, uint32_t num, uint8_t len)
{
    uint8_t i;
    uint32_t num1;

    if(num >= 0)
    {
        oled_show_char(seg, col, '+');
        num1 = num;
    }
    else
    {
        oled_show_char(seg, col, '-');
        num1 = -num;
    }

    for(i = 0; i < len; i++)
    {
        oled_show_char(seg, col + 1 + i, num1/oled_pow(10,(len - i -1)) % 10 + '0');
    }
    return;
}

void oled_show_hex_num(uint8_t seg, uint8_t col, uint32_t num, uint8_t len)
{
    uint8_t i;
    uint8_t hex_num;

    hex_num = num / oled_pow(16, (len - i - 1)) % 16;

    if(num < 10)
    {
        for(i = 0; i < len; i++)
        {
            oled_show_char(seg, col + i, hex_num + '0');
        }
    }
    else
    {
        for(i = 0; i < len; i++)
        {
            oled_show_char(seg, col + i, hex_num - 10 + 'A');
        }
    }

    return;
}

void oled_show_bin_num(uint8_t seg, uint8_t col, uint8_t num, uint8_t len)
{
    uint8_t i;

    for(i = 0; i < len; i++)
    {
        oled_show_char(seg, col + i, num / oled_pow(2, (len - i - 1)) % 2 + '0');
    }

    return;
}

void oled_init(void)
{
    delay_ms(300);
    i2c_init();

    send_commend(0xAE);    //关闭显示

    send_commend(0xD5);    //设置显示时钟分频比/振荡器频率
    send_commend(0x80);

    send_commend(0xA8);    //设置多路复用率
    send_commend(0x3F);

    send_commend(0xD3);    //设置显示偏移
    send_commend(0x00);

    send_commend(0x40);    //设置显示开始行

    send_commend(0xA1);    //设置左右方向，0xA1正常 0xA0左右反置

    send_commend(0xC8);    //设置上下方向，0xC8正常 0xC0上下反置

    send_commend(0xDA);    //设置COM引脚硬件配置
    send_commend(0x12);

    send_commend(0x81);    //设置对比度控制
    send_commend(0xCF);

    send_commend(0xD9);    //设置预充电周期
    send_commend(0xF1);

    send_commend(0xDB);    //设置VCOMH取消选择级别
    send_commend(0x30);

    send_commend(0xA4);    //设置整个显示打开/关闭

    send_commend(0xA6);    //设置正常/倒转显示

    send_commend(0x8D);    //设置充电泵
    send_commend(0x14);

    send_commend(0xAF);    //开启显示

    oled_clear();
    return;
}

#if OLED_TEST
void oled_test(void)
{
    oled_show_char(2,8,'a');
    oled_show_bin_num(3,5,1010,4);

    return;
}
#endif