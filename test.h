/* 
 * File:   test.h
 * Author: kotaro
 * 概要：test.c内の関数をプロトタイプ宣言
 * Created on 2019/01/02, 3:31
 */

#ifndef TEST_H
#define	TEST_H

#ifdef	__cplusplus
extern "C" {
#endif

    void Test_LED(void);
    void Test_Switch(void);
    void Test_Sensor(void);
    void Test_Motor(void);



#ifdef	__cplusplus
}
#endif

#endif	/* TEST_H */

