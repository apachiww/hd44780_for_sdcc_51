#include <mcs51/8052.h> 
#include "hd44780.h"

void main() {
    int i = 32767;
    uint8_t r,c;
    uint8_t cgdata1[] = {0x04, 0x0A, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04};
    char kana[] = {KN_KA, KN_TA, KN_KA, KN_NA};

    disp_start_stable(4,20);

    lcd_put_cg_addr(0x00);
    lcd_cpy_cgram(cgdata1, 8);

    disp_put_cur(0,0);
    disp_printf("Hello world! ");
    disp_print(0x00);
    disp_put_cur(1,0);
    disp_printf("Int test: %d", i);
    disp_put_cur(2,0);
    disp_println(kana, 4);
    disp_put_cur(3,0);
    disp_get_cur(&r,&c);
    disp_printf("Current cursor: %d,%d", r,c);
    disp_cur_on();
    while(1);
}