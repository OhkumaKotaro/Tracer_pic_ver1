/* 
 * File:   config.h
 * Author: kotaro
 *
 * Created on 2019/01/02, 3:32
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define LED_LL 0b1
#define LED_L 0b10
#define LED_C 0b100
#define LED_R 0b1000
#define LED_RR 0b10000
    
#define SEN_LL 0b1
#define SEN_L 0b10
#define SEN_C 0b100
#define SEN_R 0b1000
#define SEN_RR 0b10000
    
    void wait_ms(int num);
    void Config_mode(void);




#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

