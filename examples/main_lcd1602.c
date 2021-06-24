#include <mcs51/8052.h> 
#include "hd44780.h"

void main() {
    int i = 7124;
    disp_start_stable(2,16);
    disp_printf("Hello world!");
    disp_put_cur(1,0);
    disp_printf("Int test: %d", i);
    disp_cur_on();
    while(1);
}