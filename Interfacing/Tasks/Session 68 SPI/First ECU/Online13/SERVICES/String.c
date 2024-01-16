/*
 * String.c
 *
 * Created: 10/31/2023 12:28:09 AM
 *  Author: ahmed
 */ 

#include "String.h"



u16 string_length(u8 *str){
	
	u16 length=0;
	for(;str[length]!=0;length++);
	return length;
		
}

string_error_t check_string(u8 *str1,u8 *str2){
	u16 string_length1=string_length(str1);
	u16 string_length2=string_length(str2);
	
	if(string_length1!=string_length2){
		return Not_identical;
	}
	for(u16 i=0;str1[i];i++){
		if(str1[i]>str2[i]){
			return first_is_bigger;
		}
		else if(str1[i]<str2[i]){
			return second_is_bigger;
		}
		
		
	}
	return identical;
	
	
	
}