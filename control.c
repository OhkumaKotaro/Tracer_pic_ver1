/******************************************************
 *ファイル名：control.c
 * 概要：制御関連を書いたつもり
 **********************************************************/


/************include*****************************************/
#include <xc.h>
#include <p18cxxx.h>
#include "config.h"

/***********define*****************************************/
#define LEFT 1
#define RIGHT -1

/**********変数宣言****************************************/
int mode=0;//ラインが右か左にあるかの判断用

/***********関数宣言**************************************/

/************************************************
 * 関数名：Control_Motor
 * 概要：モーターの出力
 * 引数：左モーターの出力量,右モーターの出力量 (0?3000)
 * 返り値：なし
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
 * 関数名：Check_Sensor
 * 概要：ラインがどこにあるのかLEDに表示、ラインがどこにあるかの判断
 * 引数：なし
 * 返り値：機体が ライン上 -> 1以上 , ライン外 -> 0 
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
 * 関数名：Control_Sensor
 * 概要：ラインが中心からどれだけ離れているかを判断
 * 引数：なし
 * 返り値：-20左 ? 0真ん中 ? 20右
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

    //ラインが黒の時は反転させる
    if (weight > 2) {
        sen_ll = sen_ll^0b1;
        sen_l = sen_l^0b1;
        sen_c = sen_c^0b1;
        sen_r = sen_r^0b1;
        sen_rr = sen_rr^0b1;
    }
    
    //重心計算
    buff = sen_ll * (-2) + sen_l * (-1) + sen_r * 1 + sen_rr * 2;
    weight = sen_ll + sen_l + sen_c + sen_r + sen_rr;

    buff /= weight;
    buff *= 10;

    error = (int) buff;

    return error;
}