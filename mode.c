/******************************************************
 *ファイル名：control.c
 * 概要：モードの選択とそのモードに関する関数の定義
 **********************************************************/

/************include*****************************************/
#include <xc.h>
#include "test.h"
#include "config.h"
#include "interface.h"
#include "control.h"

/************プロトタイプ宣言********************************/
void Mode_Trace(void);

/***********関数宣言**************************************/

/************************************************
 * 関数名：Mode_Serect
 * 概要：モードを実行
 * 引数：モード
 * 返り値：なし
 ***************************************************/
void Mode_Serect(unsigned char mode) {
    switch (mode) {
        case 1:
            Mode_Trace();//トレーサー
            break;
        case 2:
            while (1) {
                Check_Sensor();//センサーの確認
            }
            break;
        case 3:
            while (1) {
                Test_Sensor();//センサーのテスト
            }
            break;
        case 4:
            while (1) {
                Test_LED();//LEDのテスト
            }
            break;
        case 5:
            while (1) {
                Test_Motor();//モーターのテスト
            }
            break;
        case 6:
            while (1) {
                Test_Switch();//スイッチのテスト
            }
            break;
        case 7:
            break;
    }
}

/************************************************
 * 関数名：Mode_Switch
 * 概要：スイッチでモードを選択
 * 引数：なし
 * 返り値：モード
 ***************************************************/
unsigned char Mode_Switch(void) {
    unsigned char mode = 0;

    while (1) {
        if (Inter_Sw() == 1) {
            wait_ms(500);//長押しでモードの決定
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
 * 関数名：Mode_Trace
 * 概要：ラインの上を走る
 * 引数：なし
 * 返り値：なし
 ***************************************************/
void Mode_Trace(void) {
    int left = 0, right = 0;//左右のモーターの出力量
    while (1) {
        if (Check_Sensor()) {//ライン上にある時
            int error=Control_Sensor();//ラインがどれだけ真ん中からずれているか
            int buff = 100*error;

            left = 2000 + buff;
            right = 2000 - buff;
            
            //Control_Motorの引数(0?3000)に調整
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