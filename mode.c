#include <xc.h>
#include "test.h"
#include "config.h"
#include "interface.h"
#include "control.h"

void Mode_Trace(void);

void Mode_Serect(unsigned char mode) {
    switch (mode) {
        case 1:
            Mode_Trace();
            break;
        case 2:
            while (1) {
                Check_Sensor();
            }
            break;
        case 3:
            while (1) {
                Test_Sensor();
            }
            break;
        case 4:
            while (1) {
                Test_LED();
            }
            break;
        case 5:
            while (1) {
                Test_Motor();
            }
            break;
        case 6:
            break;
        case 7:
            break;
    }
}

unsigned char Mode_Switch(void) {
    unsigned char mode = 0;

    while (1) {
        if (Inter_Sw() == 1) {
            wait_ms(500);
            if (Inter_Sw() == 1) {
                break;
            } else {
                mode++;
                PORTA = mode;
            }
        }
    }
    return mode;
}

void Mode_Trace(void) {
    int left = 0, right = 0;
    //float sum=0;
    int before=0;
    while (1) {
        if (Check_Sensor()) {
            int error=Control_Sensor();
            int p = 15 * error;
            //int i=0.1*sum;
            int d = before-error;
            int buff=p+1.5*d;

            left = 100 + buff;
            right = 100 - buff;

            if (left < 0) {
                left = 0;
            }else if(left>400){
                left=400;
            }
                
            if (right < 0) {
                right = 0;
            }else if(right>400){
                right=400;
            }
        }

        Control_Motor(left, right);
    }
}