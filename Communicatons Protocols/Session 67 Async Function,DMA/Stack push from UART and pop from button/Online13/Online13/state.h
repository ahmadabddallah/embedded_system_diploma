/*
 * state.h
 *
 * Created: 12/10/2023 2:01:28 AM
 *  Author: ahmed
 */ 


#ifndef STATE_H_
#define STATE_H_

typedef enum{
	IDLE_S,
	LEFT_S,
	RIGHT_S,
	W8_S
}state_type;


typedef enum{
	L_B,
	R_B,
	W_B	
	
}transitions_type;


void Idle(void);

void Left(void);

void Right(void);

void W8(void);


transitions_type Get_transition(void);


#endif /* STATE_H_ */