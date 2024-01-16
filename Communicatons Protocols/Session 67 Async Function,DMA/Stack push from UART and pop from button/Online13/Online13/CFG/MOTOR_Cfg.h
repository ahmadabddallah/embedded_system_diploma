/*
 * MOTOR_Cfg.h
 *
 * Created: 21/06/2023 09:06:47 م
 *  Author: ahmed
 */ 


#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_
/**************************************PIN CONFIG****************************/
/*MA1 */
#define M1_IN1 PIND0
#define M1_IN2 PIND1
#define M1_EN  OCR0

#define M2_IN1 PIND3
#define M2_IN2 PIND4
#define M2_EN  OCR1A

 
#define INIT_STATE 



#define MOTOR_MAX_SPEED 90




#endif /* MOTOR_CFG_H_ */