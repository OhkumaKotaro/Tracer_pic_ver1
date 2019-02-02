/* 
 * File:   control.h
 * Author: kotaro
 *
 * Created on 2019/01/07, 20:51
 */

#ifndef CONTROL_H
#define	CONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

    void Control_Motor(int left, int right);
    void Check_Sensor(void);
    int Control_Sensor(void);


#ifdef	__cplusplus
}
#endif

#endif	/* CONTROL_H */

