#include <xc.h>
#include "config.h"

#define dt 0.0001

void Control_Motor(int left, int right) {
    unsigned short buff = 400;
    unsigned short buff_l = left;
    unsigned short buff_r = right;
    PORTC = 0x03;
    while (buff_l + buff_r) {
        if (buff_l > 0) {
            buff_l--;
        } else {
            PORTCbits.RC0 = 0;
        }
        if (buff_r > 0) {
            buff_r--;
        } else {
            PORTCbits.RC1 = 0;
        }
        buff--;
    }
    PORTC = 0x0;
    for (int i = 0; i < buff; i++) {
    }
}

void Check_Sensor(void) {
    PORTAbits.RA0 = PORTBbits.RB0; /* Left sensor ¨Left LED */
    PORTAbits.RA1 = PORTBbits.RB1; /* Left center sensor ¨Left center LED */
    PORTAbits.RA2 = PORTBbits.RB2; /* Center sensor ¨Center LED */
    PORTAbits.RA3 = PORTBbits.RB3; /* Right center sensor ¨Right center LED */
    PORTAbits.RA4 = PORTBbits.RB4; /* Right sensor ¨Right LED */
}

int Control_Sensor(void) {
    int error = 0;
    float buff;

    buff = PORTBbits.RB0 * (-2) + PORTBbits.RB1 * (-1) + PORTBbits.RB3 * 1 + PORTBbits.RB4 * 2;
    buff /= PORTBbits.RB0 + PORTBbits.RB1 + PORTBbits.RB2 + PORTBbits.RB3 + PORTBbits.RB4;
    buff *= 10;
    
    error =(int)buff;

    return error;
}