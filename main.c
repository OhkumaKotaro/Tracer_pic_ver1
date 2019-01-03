#include <xc.h>
#include <p18cxxx.h>

#include "config.h"
#include "test.h"

main(void)
{
    Config_mode();
    
    //infinit roop
    while(1){
        Test_Sw();
    }
             
 }