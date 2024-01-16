


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "StdTypes.h"
#include "DIO_Interface.h"

#define   FIRST_OUT    PINB4
#define   FIRST_IN     PIND0
#define   DEAULT_KEY    '.'
#define   ROWS      4
#define   COL       4



u8 KEYPAD_GetEntry(void);







#endif /* KEYPAD_H_ */