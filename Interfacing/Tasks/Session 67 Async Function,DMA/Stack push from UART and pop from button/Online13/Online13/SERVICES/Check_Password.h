/*
 * Check_Password.h
 *
 * Created: 10/11/2023 4:52:44 PM
 *  Author: ahmed
 */ 


#ifndef CHECK_PASSWORD_H_
#define CHECK_PASSWORD_H_

#include "StdTypes.h"

typedef enum{
	CORRECT,
	NOT_CORRECT
	
	}check_password_t;


check_password_t check_password(u8 *str1,u8 *str2);




#endif /* CHECK_PASSWORD_H_ */