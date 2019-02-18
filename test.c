/****************************************************
 * ファイル名：test.c
 * 概要：周辺機器の確認用の関数を定義
 ******************************************************/

/************include*****************************************/
#include <xc.h>
#include "config.h"
#include "interface.h"
#include "control.h"

/***********関数宣言**************************************/

/************************************************
 * 関数名：Test_LED
 * 概要：LEDのテスト用関数
 * 引数：なし
 * 返り値：なし
 ***************************************************/
void Test_LED(void) {
    volatile unsigned long i;//最適化でiのカウントが無くならないように宣言
    PORTA = 0xff; //LED 全て点灯
    for (i = 0; i < 800000; i++) {//いくらか待つ
    }
    PORTA = 0x00; //LED 全て消灯
    for (i = 0; i < 800000; i++) {//いくらか待つ
    }
}


/************************************************
 * 関数名：Test_Switch
 * 概要：スイッチのテスト用関数
 * 引数：なし
 * 返り値：なし
 ***************************************************/
void Test_Switch(void) {
    if (Inter_Sw() == 0) {//スイッチが押されてないなら
        PORTA = 0xff; //LED 全て点灯
        wait_ms(1000);
        PORTA -= 0b1;//1番左のLEDを消灯
        wait_ms(1000);
        PORTA -= 0b10;//左のLEDを消灯
        wait_ms(1000);
        PORTA -= 0b100;//真ん中のLEDを消灯
        wait_ms(1000);
        PORTA -= 0b1000;//右のLEDを消灯
        wait_ms(1000);
        PORTA -= 0b10000;//1番右のLEDを消灯
        wait_ms(1000);
    } else if (Inter_Sw() == 1) {//スイッチが押されたら
        PORTA = 0xff;//LED 全て点灯
        wait_ms(1000);
        PORTA = 0; //LED 全て消灯
        wait_ms(1000);
    }
}


/************************************************
 * 関数名：Test_Sensor
 * 概要：センサーのテスト用関数
 * 引数：なし
 * 返り値：なし
 ***************************************************/
void Test_Sensor(void) {
    PORTAbits.RA0 = PORTBbits.RB0; /* Left sensor →Left LED */
    PORTAbits.RA1 = PORTBbits.RB1; /* Left center sensor →Left center LED */
    PORTAbits.RA2 = PORTBbits.RB2; /* Center sensor →Center LED */
    PORTAbits.RA3 = PORTBbits.RB3; /* Right center sensor →Right center LED */
    PORTAbits.RA4 = PORTBbits.RB4; /* Right sensor →Right LED */
}


/************************************************
 * 関数名：Test_Motor
 * 概要：モーターのテスト用関数
 * 引数：なし
 * 返り値：なし
 ***************************************************/
void Test_Motor(void) {
    Control_Motor(50, 299);
}