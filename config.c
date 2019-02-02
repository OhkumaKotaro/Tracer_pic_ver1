#include <xc.h>

#define _XTAL_FREQ 16000000

void wait_ms(int num)   //wait time about (num*1ms)
{
    do{
        __delay_ms(1);
    }
    while(--num > 0);
}

void Config_mode(void){
    OSCCON = 0b01110000; //Oscillator Frequency Select as 16MHz
    OSCCON2 = 0x10; //Enable PLL, SOSC, PRI OSC drivers turned off
    OSCTUNE = 0x80; //3X PLL ratio mode selected

    //setting digital or analog pin
    ANSELA = 0x00;          //portA all digital pin
    ANSELB = 0x00;          //portB all digital pin
    ANSELC = 0x00;          //portc all digital pin    

    //set ports as input or output
    TRISA = 0x20;            //  portA : RA0,1,2,3,4:output, RA5:input   0010_0000(bin) = 20(hex)
    TRISB = 0xFF;            //  portB : all input 1111_1111 = FF
    TRISC = 0x00;            //  portC : are all input 1111_1111 = FF

    //set ports to 0
    PORTA = 0x00;            //  reset portA 
    PORTB = 0x00;            //  reset portB 
    PORTC = 0x00;            //  reset portC
}