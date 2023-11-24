/*
 * Check_Password.c
 *
 * Created: 10/11/2023 4:52:58 PM
 *  Author: ahmed
 */ 


#include "Check_Password.h"




check_password_t check_password(u8 *str1,u8 *str2){
	
	for(u8 i=0;i<4;i++){
		if(str1[i]!=str2[i]){
			return NOT_CORRECT;
		}
	}
	return CORRECT;
}