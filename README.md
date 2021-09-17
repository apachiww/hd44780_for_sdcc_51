# HD44780 library for sdcc 51

This library provides support for HITACHI HD44780 based character LCDs (0801, 0802, 1601, 1602, 2004) and some compatible VFD variants like Noritake itron CU20045 (Light adjust available), with fast IO operation

+ Suitable for 8051 based MCUs with various crystals and instruction cycles (1T, 6T, 12T) as AUTOMATIC delay calculation is available

+ Both 4-bit and 8-bit bus modes are supported

+ カタカナ display and CGRAM operations also available

+ Easy-to-use formattable print function `disp_printf(format, ...)` similar to normal `printf(format, ...)`

This library is designed for SDCC only, IO definitions should be modified accordingly if you are to apply it to Keil C51

See test [examples](examples/)

## Test: LCD1602

4bit M68 bus with R/#W

![](images/test1602.jpg)

## Test: LCD2004

4bit M68 bus with R/#W

![](images/test2004.jpg)

## 3: Noritake CU20045-UW VFD

8bit M68 bus with R/#W

![](images/vfd2004.jpg)

## 4: PT6314 based VFM202MDAR2 VFD 

8bit i80 bus with #RD

![](images/vfd2002.jpg)