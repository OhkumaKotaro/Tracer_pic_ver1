#include <xc.h>
#include <p18cxxx.h>

#include "config.h"
#include "mode.h"


void main(void) {
    Config_mode();//初期設定
    
    //infinit roop
    while(1){
        Mode_Serect(Mode_Switch());//モードを選択し実行
    }

}