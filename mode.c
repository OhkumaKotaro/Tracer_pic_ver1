/******************************************************
 *�t�@�C�����Fcontrol.c
 * �T�v�F���[�h�̑I���Ƃ��̃��[�h�Ɋւ���֐��̒�`
 **********************************************************/

/************include*****************************************/
#include <xc.h>
#include "test.h"
#include "config.h"
#include "interface.h"
#include "control.h"

/************�v���g�^�C�v�錾********************************/
void Mode_Trace(void);

/***********�֐��錾**************************************/

/************************************************
 * �֐����FMode_Serect
 * �T�v�F���[�h�����s
 * �����F���[�h
 * �Ԃ�l�F�Ȃ�
 ***************************************************/
void Mode_Serect(unsigned char mode) {
    switch (mode) {
        case 1:
            Mode_Trace();//�g���[�T�[
            break;
        case 2:
            while (1) {
                Check_Sensor();//�Z���T�[�̊m�F
            }
            break;
        case 3:
            while (1) {
                Test_Sensor();//�Z���T�[�̃e�X�g
            }
            break;
        case 4:
            while (1) {
                Test_LED();//LED�̃e�X�g
            }
            break;
        case 5:
            while (1) {
                Test_Motor();//���[�^�[�̃e�X�g
            }
            break;
        case 6:
            while (1) {
                Test_Switch();//�X�C�b�`�̃e�X�g
            }
            break;
        case 7:
            break;
    }
}

/************************************************
 * �֐����FMode_Switch
 * �T�v�F�X�C�b�`�Ń��[�h��I��
 * �����F�Ȃ�
 * �Ԃ�l�F���[�h
 ***************************************************/
unsigned char Mode_Switch(void) {
    unsigned char mode = 0;

    while (1) {
        if (Inter_Sw() == 1) {
            wait_ms(500);//�������Ń��[�h�̌���
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

/************************************************
 * �֐����FMode_Trace
 * �T�v�F���C���̏�𑖂�
 * �����F�Ȃ�
 * �Ԃ�l�F�Ȃ�
 ***************************************************/
void Mode_Trace(void) {
    int left = 0, right = 0;//���E�̃��[�^�[�̏o�͗�
    while (1) {
        if (Check_Sensor()) {//���C����ɂ��鎞
            int error=Control_Sensor();//���C�����ǂꂾ���^�񒆂��炸��Ă��邩
            int buff = 100*error;

            left = 2000 + buff;
            right = 2000 - buff;
            
            //Control_Motor�̈���(0?3000)�ɒ���
            if (left < 0) {
                left = 0;
            }else if(left>3000){
                left=3000;
            }
                
            if (right < 0) {
                right = 0;
            }else if(right>3000){
                right=3000;
            }
        }

        Control_Motor(left, right);
    }
}