/*
 * StdTypes.h
 *
 * Created: 18/06/2023 11:16:44 م
 *  Author: ahmed
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned long u32;
typedef signed long s32;
typedef float f32;
typedef double f64;

typedef enum {
	FALSE,
	TRUE
}Bool_t;  

typedef enum{
	OK,
	NOK,
	NULLPTR,
	OUTOFRANGE
}Error_t;

#define NULL_PTR ((void*)0)
#define NULL ((char)0)

#define MAX_U8  ((u8)255)
#define MIN_U8  ((u8)0) 
#define MIN_S8  ((s8)-128)
#define MAX_S8  ((s8)127)
#define ZERO_S8 ((s8)0)










#endif /* STDTYPES_H_ */ 