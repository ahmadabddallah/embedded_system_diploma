


#ifndef SERVO_H_
#define SERVO_H_

#include "Timers.h"


void SERVO_Init(void);
void SERVO_SetAngle(u8  angle);


#define  SERVO_PIN   OCR1A



#endif /* SERVO_H_ */