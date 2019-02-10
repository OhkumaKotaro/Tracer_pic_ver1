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
    int buff_l = 0, buff_r = 0;
    while (1) {
        if (Check_Sensor()) {
            int buff = 15 * Control_Sensor();

            buff_l = 100 + buff;
            buff_r = 100 - buff;

            if (buff_l < 0) {
                buff_l = 0;
            }
            if (buff_r < 0) {
                buff_r = 0;
            }
        }

        Control_Motor(buff_l, buff_r);
    }
}