#include <xc.h>
#include "test.h"
#include "config.h"
#include "interface.h"

void Mode_Serect(unsigned char mode) {
    switch (mode) {
        case 1:
            while (1) {
                Test_LED();
            }
            break;
        case 2:
            while (1) {
                Test_Switch();
            }
            break;
        case 3:
            while (1) {
                Test_Sensor();
            }
            break;
        case 4:
            break;
        case 5:
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
