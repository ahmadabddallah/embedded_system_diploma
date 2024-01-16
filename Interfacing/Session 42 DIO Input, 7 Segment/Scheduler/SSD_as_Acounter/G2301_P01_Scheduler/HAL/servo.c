
#include "servo.h"


void SERVO_Init(void)
{
	ICR1=19999;
	SERVO_PIN=599;
}
void SERVO_SetAngle(u8  angle)
{
	SERVO_PIN=((u32)angle*2000)/180+599;
}