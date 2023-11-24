/*
 * GPS_Services.c
 *
 * Created: 10/28/2023 6:49:34 PM
 *  Author: ahmed
 */ 
#include "GPS_Services.h"

void GPS_get_lant_lag(u8 *lat,u8 *lng){
	
	u16 idx_a=0;
	u16 idx_n=0;
	for(u16 k=0;k<495;k++){
		if(filtered_data[k]=='G'&&filtered_data[k+1]=='P'&&filtered_data[k+2]=='R'&&filtered_data[k+3]=='M'&&filtered_data[k+4]=='C'){
			idx_a=k+19;
			idx_n=k+31;
			break;
		}
		
	}
	u16 i=0;
	for(u16 j=idx_a;i<9;i++,j++){
		lat[i]=filtered_data[j];
	}
	lat[i]=0;
	i=0;
	for(u16 j=idx_n;i<9;i++,j++){
		lng[i]=filtered_data[j];
	}
	lng[i]=0;
}