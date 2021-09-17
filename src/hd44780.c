#include "hd44780.h"

// Basic level IO functions

# ifdef IO_MODE_M68
void write_cmd(uint8_t cmd)
{
    IO_E_WR = 0;
#ifndef LCD_NO_READ
    IO_RW_RD = 0;
#endif  
    IO_RS = 0;

#ifdef LCD_BUS_4BIT
    IO_D7 = cmd&0x80;
    IO_D6 = cmd&0x40;
    IO_D5 = cmd&0x20;
    IO_D4 = cmd&0x10;
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
    IO_D7 = cmd&0x08;
    IO_D6 = cmd&0x04;
    IO_D5 = cmd&0x02;
    IO_D4 = cmd&0x01;
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif

#ifdef LCD_BUS_8BIT
    IO_D7 = cmd&0x80;
    IO_D6 = cmd&0x40;
    IO_D5 = cmd&0x20;
    IO_D4 = cmd&0x10;
    IO_D3 = cmd&0x08;
    IO_D2 = cmd&0x04;
    IO_D1 = cmd&0x02;
    IO_D0 = cmd&0x01;
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif

#ifdef LCD_BUS_8P
    IO_D = cmd;
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif
    return;
}

void write_4bit(uint8_t cmd)
{
    IO_E_WR = 0;
#ifndef LCD_NO_READ
    IO_RW_RD = 0;
#endif
    IO_RS = 0;

#ifdef LCD_BUS_8P
    IO_D = cmd;
#else
    IO_D7 = cmd&0x80;
    IO_D6 = cmd&0x40;
    IO_D5 = cmd&0x20;
    IO_D4 = cmd&0x10;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
}

void write_data(uint8_t data)
{
    IO_E_WR = 0;
#ifndef LCD_NO_READ
    IO_RW_RD = 0;
#endif  
    IO_RS = 1;

#ifdef LCD_BUS_4BIT
    IO_D7 = data&0x80;
    IO_D6 = data&0x40;
    IO_D5 = data&0x20;
    IO_D4 = data&0x10;
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
    IO_D7 = data&0x08;
    IO_D6 = data&0x04;
    IO_D5 = data&0x02;
    IO_D4 = data&0x01;
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif

#ifdef LCD_BUS_8BIT
    IO_D7 = data&0x80;
    IO_D6 = data&0x40;
    IO_D5 = data&0x20;
    IO_D4 = data&0x10;
    IO_D3 = data&0x08;
    IO_D2 = data&0x04;
    IO_D1 = data&0x02;
    IO_D0 = data&0x01;
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif

#ifdef LCD_BUS_8P
    IO_D = data;
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif
    return;
}
#endif

#ifdef IO_MODE_I80
void write_cmd(uint8_t cmd)
{
    IO_E_WR = 1;
#ifndef LCD_NO_READ
    IO_RW_RD = 1;
#endif  
    IO_RS = 0;

#ifdef LCD_BUS_4BIT
    IO_D7 = cmd&0x80;
    IO_D6 = cmd&0x40;
    IO_D5 = cmd&0x20;
    IO_D4 = cmd&0x10;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
    IO_D7 = cmd&0x08;
    IO_D6 = cmd&0x04;
    IO_D5 = cmd&0x02;
    IO_D4 = cmd&0x01;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif

#ifdef LCD_BUS_8BIT
    IO_D7 = cmd&0x80;
    IO_D6 = cmd&0x40;
    IO_D5 = cmd&0x20;
    IO_D4 = cmd&0x10;
    IO_D3 = cmd&0x08;
    IO_D2 = cmd&0x04;
    IO_D1 = cmd&0x02;
    IO_D0 = cmd&0x01;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif

#ifdef LCD_BUS_8P
    IO_D = cmd;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif
    return;
}

void write_4bit(uint8_t cmd)
{
    IO_E_WR = 1;
#ifndef LCD_NO_READ
    IO_RW_RD = 1;
#endif
    IO_RS = 0;

#ifdef LCD_BUS_8P
    IO_D = cmd;
#else
    IO_D7 = cmd&0x80;
    IO_D6 = cmd&0x40;
    IO_D5 = cmd&0x20;
    IO_D4 = cmd&0x10;
#endif
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
}

void write_data(uint8_t data)
{
    IO_E_WR = 1;
#ifndef LCD_NO_READ
    IO_RW_RD = 1;
#endif  
    IO_RS = 1;

#ifdef LCD_BUS_4BIT
    IO_D7 = data&0x80;
    IO_D6 = data&0x40;
    IO_D5 = data&0x20;
    IO_D4 = data&0x10;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
    IO_D7 = data&0x08;
    IO_D6 = data&0x04;
    IO_D5 = data&0x02;
    IO_D4 = data&0x01;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif

#ifdef LCD_BUS_8BIT
    IO_D7 = data&0x80;
    IO_D6 = data&0x40;
    IO_D5 = data&0x20;
    IO_D4 = data&0x10;
    IO_D3 = data&0x08;
    IO_D2 = data&0x04;
    IO_D1 = data&0x02;
    IO_D0 = data&0x01;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif

#ifdef LCD_BUS_8P
    IO_D = data;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_W_EH;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_W_END;
#endif
#endif
    return;
}
#endif

// If RW is available, then read functions are available

#ifndef LCD_NO_READ

#ifdef IO_MODE_M68

// Read address and busy flag

uint8_t read_bf_addr()
{
    uint8_t addr = 0;

// Initialize

#ifdef LCD_BUS_4BIT
    IO_D7 = 1;
    IO_D6 = 1;
    IO_D5 = 1;
    IO_D4 = 1;
#endif

#ifdef LCD_BUS_8BIT
    IO_D7 = 1;
    IO_D6 = 1;
    IO_D5 = 1;
    IO_D4 = 1;
    IO_D3 = 1;
    IO_D2 = 1;
    IO_D1 = 1;
    IO_D0 = 1;
#endif

#ifdef LCD_BUS_8P
    IO_D = 0xFF;
#endif

    IO_E_WR = 0;
    IO_RW_RD = 1; 
    IO_RS = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_RS2E;
#endif

// Begin read

#ifdef LCD_BUS_4BIT
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    addr |= IO_D7?0x80:0x00;
    addr |= IO_D6?0x40:0x00;
    addr |= IO_D5?0x20:0x00;
    addr |= IO_D4?0x10:0x00;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif

    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    addr |= IO_D7?0x08:0x00;
    addr |= IO_D6?0x04:0x00;
    addr |= IO_D5?0x02:0x00;
    addr |= IO_D4?0x01:0x00;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif

#ifdef LCD_BUS_8BIT
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    addr |= IO_D7?0x80:0x00;
    addr |= IO_D6?0x40:0x00;
    addr |= IO_D5?0x20:0x00;
    addr |= IO_D4?0x10:0x00;
    addr |= IO_D3?0x08:0x00;
    addr |= IO_D2?0x04:0x00;
    addr |= IO_D1?0x02:0x00;
    addr |= IO_D0?0x01:0x00;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif

#ifdef LCD_BUS_8P
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    addr = IO_D;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif
    return addr;
}

// Read data, you have to set the address before using this function

uint8_t read_data()
{
    uint8_t data = 0;

// Initialize

#ifdef LCD_BUS_4BIT
    IO_D7 = 1;
    IO_D6 = 1;
    IO_D5 = 1;
    IO_D4 = 1;
#endif

#ifdef LCD_BUS_8BIT
    IO_D7 = 1;
    IO_D6 = 1;
    IO_D5 = 1;
    IO_D4 = 1;
    IO_D3 = 1;
    IO_D2 = 1;
    IO_D1 = 1;
    IO_D0 = 1;
#endif

#ifdef LCD_BUS_8P
    IO_D = 0xFF;
#endif

    IO_E_WR = 0;
    IO_RW_RD = 1; 
    IO_RS = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_RS2E;
#endif

// Begin read

#ifdef LCD_BUS_4BIT
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    data |= IO_D7?0x80:0x00;
    data |= IO_D6?0x40:0x00;
    data |= IO_D5?0x20:0x00;
    data |= IO_D4?0x10:0x00;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    data |= IO_D7?0x08:0x00;
    data |= IO_D6?0x04:0x00;
    data |= IO_D5?0x02:0x00;
    data |= IO_D4?0x01:0x00;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif

#ifdef LCD_BUS_8BIT
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    data |= IO_D7?0x80:0x00;
    data |= IO_D6?0x40:0x00;
    data |= IO_D5?0x20:0x00;
    data |= IO_D4?0x10:0x00;
    data |= IO_D3?0x08:0x00;
    data |= IO_D2?0x04:0x00;
    data |= IO_D1?0x02:0x00;
    data |= IO_D0?0x01:0x00;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif

#ifdef LCD_BUS_8P
    IO_E_WR = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    data = IO_D;
    IO_E_WR = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif
    return data;
}

#endif

#ifdef IO_MODE_I80

// Read address and busy flag

uint8_t read_bf_addr()
{
    uint8_t addr = 0;

// Initialize
    IO_E_WR = 1;
    IO_RW_RD = 1; 
    IO_RS = 0;

#ifdef LCD_BUS_4BIT
    IO_D7 = 1;
    IO_D6 = 1;
    IO_D5 = 1;
    IO_D4 = 1;
#endif

#ifdef LCD_BUS_8BIT
    IO_D7 = 1;
    IO_D6 = 1;
    IO_D5 = 1;
    IO_D4 = 1;
    IO_D3 = 1;
    IO_D2 = 1;
    IO_D1 = 1;
    IO_D0 = 1;
#endif

#ifdef LCD_BUS_8P
    IO_D = 0xFF;
#endif

#ifdef FAST_MCU
    FN_DELAYT_R_RS2E;
#endif

// Begin read

#ifdef LCD_BUS_4BIT
    IO_RW_RD = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    addr |= IO_D7?0x80:0x00;
    addr |= IO_D6?0x40:0x00;
    addr |= IO_D5?0x20:0x00;
    addr |= IO_D4?0x10:0x00;
    IO_RW_RD = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif

    IO_RW_RD = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    addr |= IO_D7?0x08:0x00;
    addr |= IO_D6?0x04:0x00;
    addr |= IO_D5?0x02:0x00;
    addr |= IO_D4?0x01:0x00;
    IO_RW_RD = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif

#ifdef LCD_BUS_8BIT
    IO_RW_RD = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    addr |= IO_D7?0x80:0x00;
    addr |= IO_D6?0x40:0x00;
    addr |= IO_D5?0x20:0x00;
    addr |= IO_D4?0x10:0x00;
    addr |= IO_D3?0x08:0x00;
    addr |= IO_D2?0x04:0x00;
    addr |= IO_D1?0x02:0x00;
    addr |= IO_D0?0x01:0x00;
    IO_RW_RD = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif

#ifdef LCD_BUS_8P
    IO_RW_RD = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    addr = IO_D;
    IO_RW_RD = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_END
#endif
#endif
    return addr;
}

// Read data, you have to set the address before using this function

uint8_t read_data()
{
    uint8_t data = 0;

// Initialize
    IO_E_WR = 1;
    IO_RW_RD = 1; 
    IO_RS = 1;

#ifdef LCD_BUS_4BIT
    IO_D7 = 1;
    IO_D6 = 1;
    IO_D5 = 1;
    IO_D4 = 1;
#endif

#ifdef LCD_BUS_8BIT
    IO_D7 = 1;
    IO_D6 = 1;
    IO_D5 = 1;
    IO_D4 = 1;
    IO_D3 = 1;
    IO_D2 = 1;
    IO_D1 = 1;
    IO_D0 = 1;
#endif

#ifdef LCD_BUS_8P
    IO_D = 0xFF;
#endif

#ifdef FAST_MCU
    FN_DELAYT_R_RS2E;
#endif

// Begin read

#ifdef LCD_BUS_4BIT
    IO_RW_RD = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    data |= IO_D7?0x80:0x00;
    data |= IO_D6?0x40:0x00;
    data |= IO_D5?0x20:0x00;
    data |= IO_D4?0x10:0x00;
    IO_RW_RD = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
    IO_RW_RD = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    data |= IO_D7?0x08:0x00;
    data |= IO_D6?0x04:0x00;
    data |= IO_D5?0x02:0x00;
    data |= IO_D4?0x01:0x00;
    IO_RW_RD = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif

#ifdef LCD_BUS_8BIT
    IO_RW_RD = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    data |= IO_D7?0x80:0x00;
    data |= IO_D6?0x40:0x00;
    data |= IO_D5?0x20:0x00;
    data |= IO_D4?0x10:0x00;
    data |= IO_D3?0x08:0x00;
    data |= IO_D2?0x04:0x00;
    data |= IO_D1?0x02:0x00;
    data |= IO_D0?0x01:0x00;
    IO_RW_RD = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif

#ifdef LCD_BUS_8P
    IO_RW_RD = 0;
#ifdef FAST_MCU
    FN_DELAYT_R_E2D;
#endif
    data = IO_D;
    IO_RW_RD = 1;
#ifdef FAST_MCU
    FN_DELAYT_R_END;
#endif
#endif
    return data;
}

#endif

// Wait when the busy flag is on

void lcd_wait()
{
    while(read_bf_addr()&0x80);
    return;
}
#endif

// Soft delay functions

void lcd_wait_2t(uint8_t t)
{
    while(--t);
    return;
}

void lcd_wait_512t(uint8_t t)
{
    uint8_t i;
    while(--t) {
        i = 255;
        while(--i);
    }
    return;
}

#ifdef FAST_MCU
void lcd_wait_65kt(uint8_t t)
{
    uint8_t i;
    uint8_t j;
    while(--t) {
        i = 255;
        while(--i) {
            j = 255;
            while(--j);
        }
    }
    return;
}
#endif


// Medium level functions

// Clear and home functions

void lcd_clear()
{
    write_cmd(CMD_CLEAR);
    DELAY_CLR;
    return;
}

void lcd_home()
{
    write_cmd(CMD_HOME);
    DELAY_CLR;
    return;
}

// Initialzing, THE FIRST FUNCTION TO BE EXECUTED AFTER POWERON

void lcd_init(uint8_t cmd)
{
    write_cmd(CMD_INIT | (cmd & 0x1F));
    DELAY_CMD;
    return;
}

// Settings

void lcd_set_entry(uint8_t cmd)
{
    write_cmd(CMD_ENTRY | (cmd & 0x03));
    DELAY_CMD;
    return;
}

void lcd_set_disp(uint8_t cmd)
{
    write_cmd(CMD_SET_DISP | (cmd & 0x07));
    DELAY_CMD;
    return;
}

// Move or shift

void lcd_mov(uint8_t cmd)
{
    write_cmd(CMD_MOVE | (cmd & 0x0C));
    DELAY_CMD;
    return;
}

// Data transfer

void lcd_cpy_ddram(const char *data, uint8_t count)
{
    for(uint8_t i = 0; i < count; i++) {
        write_data(*(data + i));
        DELAY_CMD;    
    }
    return;
}

void lcd_put_cur_addr(uint8_t addr)
{
    write_cmd(CMD_SET_ADD | addr);
    DELAY_CMD;
    return;
}

void lcd_cpy_cgram(const uint8_t *data, uint8_t count)
{
    for(uint8_t i = 0; i < count; i++) {
        write_data(*(data + i));
        DELAY_CMD;
    }
    return;
}

void lcd_put_cg_addr(uint8_t addr)
{
    write_cmd(CMD_SET_ACG | (addr & 0x3F));
    DELAY_CMD;
    return;
}

#ifndef LCD_NO_READ
uint8_t lcd_get_cur_addr()
{
    return (read_bf_addr() & 0x7F);
}

#endif

#ifdef DISP_TYPE_NORITAKE_CU20045
void vfd_set_light(uint8_t light)
{
#ifdef LCD_BUS_4BIT
    write_cmd(CMD_INIT | CMD_INIT_4_BIT);
#endif

#if defined (LCD_BUS_8BIT) || defined (LCD_BUS_8P)
    write_cmd(CMD_INIT | CMD_INIT_8_BIT);
#endif
    // Light setting requires data writing command
    DELAY_CMD;
    write_data(light & 0x03);
    DELAY_CMD;
    return;
}

#endif


// High level functions

void disp_start_stable(uint8_t row, uint8_t col)
{
    IO_RS = 0;
#ifdef IO_MODE_M68
    IO_E_WR = 0;
#ifndef LCD_NO_READ
    IO_RW_RD = 0;
#endif
#endif

#ifdef IO_MODE_I80
    IO_E_WR = 1;
#ifndef LCD_NO_READ
    IO_RW_RD = 1;
#endif
#endif

    size_row = col;
    num_row = row;

    FN_DELAY_PWRON;

    // The additional 3 resets
    write_4bit(0x30);
    FN_DELAY_INIT_PHASE1;
    write_4bit(0x30);
    FN_DELAY_INIT_PHASE2;
    write_4bit(0x30);
    DELAY_CMD;

#ifdef LCD_BUS_4BIT
    // 4bit BUS mode requires row setting twice 
    write_4bit(0x20);
    if(row == 1)
    lcd_init(CMD_INIT_4_BIT | CMD_INIT_8_FONT | CMD_INIT_1_LINE);
    else
    lcd_init(CMD_INIT_4_BIT | CMD_INIT_8_FONT | CMD_INIT_2_LINE);
#endif

#if defined(LCD_BUS_8BIT) || defined(LCD_BUS_8P)
    if(row == 1)
    lcd_init(CMD_INIT_8_BIT | CMD_INIT_8_FONT | CMD_INIT_1_LINE);
    else
    lcd_init(CMD_INIT_8_BIT | CMD_INIT_8_FONT | CMD_INIT_2_LINE);
#endif

    // Requires extra settings
    lcd_set_disp(CMD_SET_DISP_OFF | CMD_SET_CUR_OFF | CMD_SET_BLINK_OFF);
    lcd_clear();
    lcd_set_entry(CMD_ENTRY_INC | CMD_ENTRY_CURSOR);

    // Turn on display
    lcd_set_disp(CMD_SET_DISP_ON | CMD_SET_CUR_OFF | CMD_SET_BLINK_OFF);
    return;
}

void disp_clear()
{
    lcd_clear();
    return;
}

void disp_home()
{
    lcd_home();
    return;
}

void disp_on()
{
    lcd_set_disp(CMD_SET_DISP_ON);
    return;
}

void disp_off()
{
    lcd_set_disp(CMD_SET_DISP_OFF);
    return;
}

void disp_cur_on()
{
    lcd_set_disp(CMD_SET_DISP_ON | CMD_SET_CUR_ON | CMD_SET_BLINK_ON);
    return;
}

void disp_cur_off()
{
    lcd_set_disp(CMD_SET_DISP_ON | CMD_SET_CUR_OFF | CMD_SET_BLINK_OFF);
    return;
}


void disp_put_cur(uint8_t row, uint8_t col)
{
    // The number of row and column begin at 0
    uint8_t addr;

    if(num_row == 2) {
        switch(row) {
            case 1:
                addr = 0x40 + col;
                break;
            default:
                addr = 0x00 + col;
        }
    }
    else if(num_row == 4) {
        switch(row) {
            case 3:
                addr = 0x54 + col;
                break;
            case 2:
                addr = 0x14 + col;
                break;
            case 1:
                addr = 0x40 + col;
                break;
            default:
                addr = 0x00 + col;
        }
    }
    // Default 1 line
    else {
        addr = 0x00 + col;
    }
    lcd_put_cur_addr(addr);
    return;
}

#ifndef LCD_NO_READ
void disp_get_cur(uint8_t *row, uint8_t *col)
{
    uint8_t addr = lcd_get_cur_addr();
    if(num_row == 4) {
        if(addr <= 0x13) {
            *row = 0;
            *col = addr - 0x00;
        }
        else if((addr >= 0x14) && (addr <= 0x27)) {
            *row = 2;
            *col = addr - 0x14;
        }
        else if((addr >= 0x40) && (addr <= 0x53)) {
            *row = 1;
            *col = addr - 0x40;
        }
        else if((addr >= 0x54) && (addr <= 0x67)) {
            *row = 3;
            *col = addr - 0x54;
        }
    }
    else if(num_row == 2) {
        if(addr <= 0x27) {
            *row = 0;
            *col = addr - 0x00;
        }
        else if((addr >= 0x40) && (addr <= 0x67)) {
            *row = 1;
            *col = addr - 0x40;
        }
    }
    else {
        *row = 0;
        *col = addr;
    }
    return;
}

#endif

void disp_shift(uint8_t orient)
{
    if(!orient) {
        lcd_mov(CMD_MOVE_DISP | CMD_MOVE_LEFT);
    }
    else {
        lcd_mov(CMD_MOVE_DISP | CMD_MOVE_RIGHT);
    }
    return;
}

void disp_curmov(uint8_t orient)
{
    if(!orient) {
        lcd_mov(CMD_MOVE_CURSOR | CMD_MOVE_LEFT);
    }
    else {
        lcd_mov(CMD_MOVE_CURSOR | CMD_MOVE_RIGHT);
    }
    return;
}

void disp_print(char c)
{
    write_data(c);
    DELAY_CMD;
    return;
}

void disp_println(const char *data, uint8_t count)
{
    lcd_cpy_ddram(data, count);
    return;
}

// Formattable printf() function
static
void put_char_to_lcd(char c, void *p) _REENTRANT
{
    p;
    write_data(c);
    DELAY_CMD;
}

int disp_printf(const char *format, ...)
{
    va_list arg;
    int i;

    va_start (arg, format);
    i = _print_format (put_char_to_lcd, NULL, format, arg);
    va_end (arg);

    return i;
}
