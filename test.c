#include <xc.h>
#include "config.h"
#include "interface.h"

void Test_LED(void) {
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

void Test_Sensor(void){
   if(PORTBbits.RB0){
       PORTA = PORTA | LED_LL;
   }else if(LED_LL == (PORTA & LED_LL)){
       PORTA -= LED_LL; 
   }
   if(PORTBbits.RB1){
       PORTA = PORTA | LED_L;
   }else if(LED_L == (PORTA & LED_L)){
       PORTA -= LED_L; 
   }
   if(PORTBbits.RB2){
       PORTA = PORTA | LED_C;
   }else if(LED_C == (PORTA & LED_C)){
       PORTA -= LED_C; 
   }
   if(PORTBbits.RB3){
       PORTA = PORTA | LED_R;
   }else if(LED_R == (PORTA & LED_R)){
       PORTA -= LED_R; 
   }
   if(PORTBbits.RB4){
       PORTA = PORTA | LED_RR;
   }else if(LED_RR == (PORTA & LED_RR)){
       PORTA -= LED_RR; 
   }
}