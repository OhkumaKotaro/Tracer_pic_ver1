#include <xc.h>
#include "config.h"
#include "interface.h"
#include "control.h"

void Test_LED(void) {
    volatile unsigned long i;
    PORTA = LED_LL | LED_L | LED_C | LED_R | LED_RR; //turn on LEDs
    for (i = 0; i < 800000; i++) {
    }
    PORTA = 0x00; //turn off LEDs
    for (i = 0; i < 800000; i++) {
    }
}

void Test_Switch(void) {
    if (Inter_Sw() == 0) {
        PORTA = LED_LL | LED_L | LED_C | LED_R | LED_RR; //turn on LEDs
        wait_ms(1000);
        PORTA -= LED_RR; //turn on LEDs
        wait_ms(1000);
        PORTA -= LED_R; //turn on LEDs
        wait_ms(1000);
        PORTA -= LED_C; //turn on LEDs
        wait_ms(1000);
        PORTA -= LED_L; //turn on LEDs
        wait_ms(1000);
        PORTA -= LED_LL; //turn off LEDs
        wait_ms(1000);
    } else if (Inter_Sw() == 1) {
        PORTA = LED_LL | LED_L | LED_C | LED_R | LED_RR; //turn on LEDs
        wait_ms(1000);
        PORTA = 0; //turn on LEDs
        wait_ms(1000);
    }
}

void Test_Sensor(void) {
    PORTAbits.RA0 = PORTBbits.RB0; /* Left sensor ¨Left LED */
    PORTAbits.RA1 = PORTBbits.RB1; /* Left center sensor ¨Left center LED */
    PORTAbits.RA2 = PORTBbits.RB2; /* Center sensor ¨Center LED */
    PORTAbits.RA3 = PORTBbits.RB3; /* Right center sensor ¨Right center LED */
    PORTAbits.RA4 = PORTBbits.RB4; /* Right sensor ¨Right LED */
}

void Test_Motor(void) {
    Control_Motor(50, 299);
}