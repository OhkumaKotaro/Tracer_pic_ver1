/* 
 * File:   mode.h
 * Author: kotaro
 *
 * Created on 2019/01/05, 22:32
 */

#ifndef MODE_H
#define	MODE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    void Mode_Serect(unsigned char mode);
    unsigned char Mode_Switch(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MODE_H */

