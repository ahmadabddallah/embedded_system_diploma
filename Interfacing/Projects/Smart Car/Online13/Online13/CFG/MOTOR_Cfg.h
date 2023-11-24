/*
 * MOTOR_Cfg.h
 *
 * Created: 21/06/2023 09:06:47 م
 *  Author: ahmed
 */ 


#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_
/**************************************PIN CONFIG****************************/
/*Motor 1 */
#define M1_IN1 PINC0
#define M1_IN2 PINC1
#define M1_EN  OCR0

/*Motor 2 */
#define M2_IN1 PINC2
#define M2_IN2 PINC3
#define M2_EN  OCR0

/*Motor 3 */
#define M3_IN1 PINC4
#define M3_IN2 PINC5
#define M3_EN  OCR1A

/*Motor 4 */
#define M4_IN1 PINC6
#define M4_IN2 PINC7
#define M4_EN  OCR1A

 
#define INIT_STATE 



#define MOTOR_MAX_SPEED 90




#endif /* MOTOR_CFG_H_ */