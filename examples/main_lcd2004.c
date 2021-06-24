#include <mcs51/8052.h> 
#include "hd44780.h"

void main() {
    int i = 7124;
    char kana[] = {KN_KA, KN_TA, KN_KA, KN_NA};
    disp_start_stable(4,20);
    disp_printf("Hello world!");
    disp_put_cur(1,0);
    disp_printf("apachiww@github.com");
    disp_put_cur(2,0);
    disp_println(kana, 4);
    disp_put_cur(3,0);
    disp_printf("Int test: %d", i);
    disp_cur_on();
    while(1);
}