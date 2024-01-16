/*
 * GPS_Services.h
 *
 * Created: 10/28/2023 6:49:50 PM
 *  Author: ahmed
 */ 


#ifndef GPS_SERVICES_H_
#define GPS_SERVICES_H_

#include "GPS.h"
#include "StdTypes.h"
#include "DIO_Interface.h"

extern u8 filtered_data[500];

void GPS_get_lant_lag(u8 *lat,u8 *lng);


#endif /* GPS_SERVICES_H_ */