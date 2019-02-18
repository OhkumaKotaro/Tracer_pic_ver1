/* 
 * File:   control.h
 * Author: kotaro
 * 概要：control.c内の関数のプロトタイプ宣言
 * Created on 2019/01/07, 20:51
 */

#ifndef CONTROL_H
#define	CONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

    void Control_Motor(int left, int right);
    unsigned char Check_Sensor(void);
    int Control_Sensor(void);


#ifdef	__cplusplus
}
#endif

#endif	/* CONTROL_H */

