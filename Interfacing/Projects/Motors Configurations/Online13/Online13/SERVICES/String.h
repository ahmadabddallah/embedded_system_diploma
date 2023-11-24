/*
 * String.h
 *
 * Created: 10/31/2023 12:27:54 AM
 *  Author: ahmed
 */ 


#ifndef STRING_H_
#define STRING_H_

#include "DIO_Interface.h"
#include "StdTypes.h"
#include "Utils.h"

typedef enum{
	identical,
	Not_identical,
	first_is_bigger,
	second_is_bigger,
	
	
}string_error_t;


u16 string_length(u8 *str);

string_error_t check_string(u8 *str1,u8 *str2);




#endif /* STRING_H_ */