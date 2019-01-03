#include <xc.h>
#include "config.h"
#include "interface.h"

void Test_Lchika(void) {
    PORTA = LED_LL | LED_L | LED_C | LED_R | LED_RR; //turn on LEDs
    wait_ms(1000);
    PORTA = LED_LL | LED_L | LED_C | LED_R; //turn on LEDs
    wait_ms(1000);
    PORTA = LED_LL | LED_L | LED_C; //turn on LEDs
    wait_ms(1000);
    PORTA = LED_LL | LED_L; //turn on LEDs
    wait_ms(1000);
    PORTA = LED_LL; //turn on LEDs
    wait_ms(1000);
    PORTA = 0x00; //turn off LEDs
    wait_ms(1000);
}

void Test_Sw(void) {
    if (Inter_Sw() == 0) {
        PORTA = LED_LL | LED_L | LED_C | LED_R | LED_RR; //turn on LEDs
        wait_ms(1000);
        PORTA = LED_LL | LED_L | LED_C | LED_R; //turn on LEDs
        wait_ms(1000);
        PORTA = LED_LL | LED_L | LED_C; //turn on LEDs
        wait_ms(1000);
        PORTA = LED_LL | LED_L; //turn on LEDs
        wait_ms(1000);
        PORTA = LED_LL; //turn on LEDs
        wait_ms(1000);
        PORTA = 0x00; //turn off LEDs
        wait_ms(1000);
    } else if (Inter_Sw() == 1) {
        PORTA = LED_LL | LED_L | LED_C | LED_R | LED_RR; //turn on LEDs
        wait_ms(1000);
        PORTA = 0; //turn on LEDs
        wait_ms(1000);
    }
}