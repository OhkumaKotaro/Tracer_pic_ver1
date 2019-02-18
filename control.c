/******************************************************
 *�t�@�C�����Fcontrol.c
 * �T�v�F����֘A������������
 **********************************************************/


/************include*****************************************/
#include <xc.h>
#include <p18cxxx.h>
#include "config.h"

/***********define*****************************************/
#define LEFT 1
#define RIGHT -1

/**********�ϐ��錾****************************************/
int mode=0;//���C�����E�����ɂ��邩�̔��f�p

/***********�֐��錾**************************************/

/************************************************
 * �֐����FControl_Motor
 * �T�v�F���[�^�[�̏o��
 * �����F�����[�^�[�̏o�͗�,�E���[�^�[�̏o�͗� (0?3000)
 * �Ԃ�l�F�Ȃ�
 ***************************************************/
void Control_Motor(int left, int right) {
    volatile unsigned short buff = 3000;
    volatile unsigned short buff_l = left;
    volatile unsigned short buff_r = right;
    PORTC = 0x03;
    while (buff_l + buff_r) {
        //left
        if (buff_l > 0) {
            buff_l--;
        } else {
            PORTCbits.RC0 = 0;
        }
        //right
        if (buff_r > 0) {
            buff_r--;
        } else {
            PORTCbits.RC1 = 0;
        }
        //
        if (buff > 0) {
            buff--;
        }
    }
    PORTC = 0x0;
    for (int i = 0; i < buff; i++) {
    }
}

/************************************************
 * �֐����FCheck_Sensor
 * �T�v�F���C�����ǂ��ɂ���̂�LED�ɕ\���A���C�����ǂ��ɂ��邩�̔��f
 * �����F�Ȃ�
 * �Ԃ�l�F�@�̂� ���C���� -> 1�ȏ� , ���C���O -> 0 
 ***************************************************/
unsigned char Check_Sensor(void) {
    unsigned char sen_ll, sen_l, sen_c, sen_r, sen_rr;
    unsigned char weight;

    sen_ll = PORTBbits.RB0;
    sen_l = PORTBbits.RB1;
    sen_c = PORTBbits.RB2;
    sen_r = PORTBbits.RB3;
    sen_rr = PORTBbits.RB4;

    weight = sen_ll + sen_l + sen_c + sen_r + sen_rr;

    if (weight > 2) {
        sen_ll = sen_ll^0b1;
        sen_l = sen_l^0b1;
        sen_c = sen_c^0b1;
        sen_r = sen_r^0b1;
        sen_rr = sen_rr^0b1;
    }
    PORTAbits.RA0 = sen_ll;
    PORTAbits.RA1 = sen_l;
    PORTAbits.RA2 = sen_c;
    PORTAbits.RA3 = sen_r;
    PORTAbits.RA4 = sen_rr;
    
    if(mode==LEFT){
        sen_r=0;
        sen_rr=0;
    }else if(mode==RIGHT){
        sen_l=0;
        sen_ll=0;
    }

    return sen_ll|sen_l|sen_c|sen_r|sen_rr;
}

/************************************************
 * �֐����FControl_Sensor
 * �T�v�F���C�������S����ǂꂾ������Ă��邩�𔻒f
 * �����F�Ȃ�
 * �Ԃ�l�F-20�� ? 0�^�� ? 20�E
 ***************************************************/
int Control_Sensor(void) {
    int error;
    float buff;
    unsigned char sen_ll, sen_l, sen_c, sen_r, sen_rr;
    unsigned char weight;

    sen_ll = PORTBbits.RB0;
    sen_l = PORTBbits.RB1;
    sen_c = PORTBbits.RB2;
    sen_r = PORTBbits.RB3;
    sen_rr = PORTBbits.RB4;

    weight = sen_ll + sen_l + sen_c + sen_r + sen_rr;

    //���C�������̎��͔��]������
    if (weight > 2) {
        sen_ll = sen_ll^0b1;
        sen_l = sen_l^0b1;
        sen_c = sen_c^0b1;
        sen_r = sen_r^0b1;
        sen_rr = sen_rr^0b1;
    }
    
    //�d�S�v�Z
    buff = sen_ll * (-2) + sen_l * (-1) + sen_r * 1 + sen_rr * 2;
    weight = sen_ll + sen_l + sen_c + sen_r + sen_rr;

    buff /= weight;
    buff *= 10;

    error = (int) buff;

    return error;
}