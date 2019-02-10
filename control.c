#include <xc.h>
#include <p18cxxx.h>
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
        if (buff > 0) {
            buff--;
        }
    }
    PORTC = 0x0;
    for (int i = 0; i < buff; i++) {
    }
}

unsigned char Check_Sensor(void) {
    unsigned char sen_ll, sen_l, sen_c, sen_r, sen_rr;
    unsigned char weight;

    sen_ll = PORTBbits.RB0;
    sen_l = PORTBbits.RB1;
    sen_c = PORTBbits.RB2;
    sen_r = PORTBbits.RB3;
    sen_rr = PORTBbits.RB4;

    weight = sen_ll + sen_l + sen_c + sen_r + sen_rr;

    if (weight > 2) {
        sen_ll = sen_ll^0b1;
        sen_l = sen_l^0b1;
        sen_c = sen_c^0b1;
        sen_r = sen_r^0b1;
        sen_rr = sen_rr^0b1;
    }
    PORTAbits.RA0 = sen_ll;
    PORTAbits.RA1 = sen_l;
    PORTAbits.RA2 = sen_c;
    PORTAbits.RA3 = sen_r;
    PORTAbits.RA4 = sen_rr;
    //PORTAbits.RA0 = PORTBbits.RB0; /* Left sensor ¨Left LED */
    //PORTAbits.RA1 = PORTBbits.RB1; /* Left center sensor ¨Left center LED */
    //PORTAbits.RA2 = PORTBbits.RB2; /* Center sensor ¨Center LED */
    //PORTAbits.RA3 = PORTBbits.RB3; /* Right center sensor ¨Right center LED */
    //PORTAbits.RA4 = PORTBbits.RB4; /* Right sensor ¨Right LED */

    return sen_ll|sen_l|sen_c|sen_r|sen_rr;
}

int Control_Sensor(void) {
    int error;
    float buff;
    unsigned char sen_ll, sen_l, sen_c, sen_r, sen_rr;
    unsigned char weight;

    sen_ll = PORTBbits.RB0;
    sen_l = PORTBbits.RB1;
    sen_c = PORTBbits.RB2;
    sen_r = PORTBbits.RB3;
    sen_rr = PORTBbits.RB4;

    weight = sen_ll + sen_l + sen_c + sen_r + sen_rr;

    if (weight > 2) {
        sen_ll = sen_ll^0b1;
        sen_l = sen_l^0b1;
        sen_c = sen_c^0b1;
        sen_r = sen_r^0b1;
        sen_rr = sen_rr^0b1;
    }

    buff = sen_ll * (-2) + sen_l * (-1) + sen_r * 1 + sen_rr * 2;
    weight = sen_ll + sen_l + sen_c + sen_r + sen_rr;

    buff /= weight;
    buff *= 10;

    error = (int) buff;

    return error;
}