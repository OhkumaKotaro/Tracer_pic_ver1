#include <xc.h>

unsigned char Inter_Sw(void){
    unsigned char sw=PORTAbits.RA5 ^ 0b1;
    return sw;
}
