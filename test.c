/****************************************************
 * �t�@�C�����Ftest.c
 * �T�v�F���Ӌ@��̊m�F�p�̊֐����`
 ******************************************************/

/************include*****************************************/
#include <xc.h>
#include "config.h"
#include "interface.h"
#include "control.h"

/***********�֐��錾**************************************/

/************************************************
 * �֐����FTest_LED
 * �T�v�FLED�̃e�X�g�p�֐�
 * �����F�Ȃ�
 * �Ԃ�l�F�Ȃ�
 ***************************************************/
void Test_LED(void) {
    volatile unsigned long i;//�œK����i�̃J�E���g�������Ȃ�Ȃ��悤�ɐ錾
    PORTA = 0xff; //LED �S�ē_��
    for (i = 0; i < 800000; i++) {//�����炩�҂�
    }
    PORTA = 0x00; //LED �S�ď���
    for (i = 0; i < 800000; i++) {//�����炩�҂�
    }
}


/************************************************
 * �֐����FTest_Switch
 * �T�v�F�X�C�b�`�̃e�X�g�p�֐�
 * �����F�Ȃ�
 * �Ԃ�l�F�Ȃ�
 ***************************************************/
void Test_Switch(void) {
    if (Inter_Sw() == 0) {//�X�C�b�`��������ĂȂ��Ȃ�
        PORTA = 0xff; //LED �S�ē_��
        wait_ms(1000);
        PORTA -= 0b1;//1�ԍ���LED������
        wait_ms(1000);
        PORTA -= 0b10;//����LED������
        wait_ms(1000);
        PORTA -= 0b100;//�^�񒆂�LED������
        wait_ms(1000);
        PORTA -= 0b1000;//�E��LED������
        wait_ms(1000);
        PORTA -= 0b10000;//1�ԉE��LED������
        wait_ms(1000);
    } else if (Inter_Sw() == 1) {//�X�C�b�`�������ꂽ��
        PORTA = 0xff;//LED �S�ē_��
        wait_ms(1000);
        PORTA = 0; //LED �S�ď���
        wait_ms(1000);
    }
}


/************************************************
 * �֐����FTest_Sensor
 * �T�v�F�Z���T�[�̃e�X�g�p�֐�
 * �����F�Ȃ�
 * �Ԃ�l�F�Ȃ�
 ***************************************************/
void Test_Sensor(void) {
    PORTAbits.RA0 = PORTBbits.RB0; /* Left sensor ��Left LED */
    PORTAbits.RA1 = PORTBbits.RB1; /* Left center sensor ��Left center LED */
    PORTAbits.RA2 = PORTBbits.RB2; /* Center sensor ��Center LED */
    PORTAbits.RA3 = PORTBbits.RB3; /* Right center sensor ��Right center LED */
    PORTAbits.RA4 = PORTBbits.RB4; /* Right sensor ��Right LED */
}


/************************************************
 * �֐����FTest_Motor
 * �T�v�F���[�^�[�̃e�X�g�p�֐�
 * �����F�Ȃ�
 * �Ԃ�l�F�Ȃ�
 ***************************************************/
void Test_Motor(void) {
    Control_Motor(50, 299);
}