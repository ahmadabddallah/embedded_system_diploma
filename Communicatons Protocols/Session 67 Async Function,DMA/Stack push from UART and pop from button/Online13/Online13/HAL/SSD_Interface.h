/*
 * SSD_Interface.h
 *
 * Created: 11/27/2023 2:29:21 AM
 *  Author: ahmed
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "DIO_Interface.h"
#include "Utils.h"
#include "SSD_Cfg.h"

#if POLRAITY== CATHODE
	
	void SSD_SetNum(u8 num);

#elif

	
	void SSD_Num_Anode(u8 num);
	
#endif









#endif /* SSD_INTERFACE_H_ */