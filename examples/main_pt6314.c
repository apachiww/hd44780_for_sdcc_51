#include <mcs51/8052.h> 
#include "hd44780.h"

void main() {
    int i = 32767;
    uint8_t cgdata1[] = {0x04, 0x0A, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04};

    disp_start(2,20);

    vfd_set_light_pt6314(0x03); // Adjustable from 0x03 to 0x00

    lcd_put_cg_addr(0x00);
    lcd_cpy_cgram(cgdata1, 8);

    disp_put_cur(0,0);
    disp_printf("Hello world!");
    disp_put_cur(1,0);
    disp_printf("Int test: %d", i);
    disp_cur_on();
    while(1);
}