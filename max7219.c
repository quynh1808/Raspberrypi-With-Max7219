/*
    + Connect to Max7219:
        - VCC   3.3V        17 phys
        - GND   0v          20
        - Din   MOSI        19
        - CS    CE0,CE1     24,26, using Pin 24
        - SCLK              23
*/

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdint.h>

/* Configuration Max7219 from datatsheet----------------------*/
#define Decode_Mode_Reg     0x09    //Decode-Mode Register Examples (Table 4 datasheet)
#define Digits              0xFF    //Decode for digits 7-0 
// #define Digits              0x00    //No Decode for digits 7-0 (using for "Covid19")
#define Intensity_Reg       0x0A    // Intensity Register Format(Table 7)
#define Intensity           0x09    // 19/32 Duty Cycle
#define Scan_Limit_Reg      0x0B    //Scan-Limit Register Format (Table 8)
#define Scan_Limit          0x07    //Display digits 7-0
#define Shutdown_Reg_Format 0x0C    // Shutdown Register Format (Table 3)
#define Shutdown_Format     0x01    // Normal Operation
#define Display_Test_Reg    0x0F    // Display-Test Register Format (Table 10) 
#define Display_Test        0x00    // Mode Normal Operation

uint8_t birth_day[8] = {2,2,10,0,4,10,0,2};
uint8_t covid19[8] = {0x4E,0x1D,0x1C,0x10,0x3D,0x30,0x7B};

void send_data(unsigned char address, unsigned char value)
{
    unsigned char data [2];
    data[0] = address;
    data[1] = value;
    wiringPiSPIDataRW(0,data,2);
}
void Init(void)
{
    send_data(Decode_Mode_Reg,Digits);
    send_data(Intensity_Reg,Intensity);
    send_data(Scan_Limit_Reg,Scan_Limit);
    send_data(Shutdown_Reg_Format,Shutdown_Format);
    send_data(Display_Test_Reg,Display_Test);
}

int main(void)
{
    wiringPiSPISetup(0,8000000); //Serial-Clock Input. 8Mhz ( 10MHz max)
    Init();
    while (1)
    {
    for (int i=0;i<8;i++)
        send_data(i+1,birth_day[7-i]);
        //send_data(i+1,covid19[7-i]);
    }
    
   
   return 0;
}
