#include <xc.h>
#include <p18cxxx.h>

#include "config.h"
#include "mode.h"


void main(void) {
    Config_mode();//�����ݒ�
    
    //infinit roop
    while(1){
        Mode_Serect(Mode_Switch());//���[�h��I�������s
    }

}