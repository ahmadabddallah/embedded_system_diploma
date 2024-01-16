/*
 * MemMap.h
 *
 * Created: 18/06/2023 11:11:46 م
 *  Author: ahmed
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

/*********************************DIO Registers********************************************/
#define DDRA	(*(volatile unsigned char *)0x3A)
#define PORTA	(*(volatile unsigned char *)0x3B)
#define PINA	(*( volatile unsigned char *)0x39)

#define DDRB	(*(volatile unsigned char *)0x37)
#define PORTB	(*(volatile unsigned char *)0x38)
#define PINB	(*(volatile unsigned char *)0x36)

#define DDRC	(*(volatile unsigned char*)0x34)
#define PORTC	(*(volatile unsigned char *)0x35) 
#define PINC	(*(volatile unsigned char*)0x33)


#define DDRD	(*(volatile unsigned char *)0x31)
#define PORTD	(*(volatile unsigned char *)0x32)
#define PIND	(*(volatile unsigned char *)0x30)

/******************************ADC Registers************************************************/
#define ADMUX (*(volatile unsigned char*)0x27)

#define ADLAR 5
#define REFS0 6
#define REFS1 7


#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7

#define ADCL (*(volatile unsigned char*)0x24)
#define ADCH (*(volatile unsigned char*)0x25)


/*********************************UART REGISTERS****************************/

/* USART Control and Status Register A */
#define UCSRA    (*(volatile unsigned char*)0x2B)

#define    RXC          7
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3
#define    UPE          2
#define    U2X          1
#define    MPCM         0


/* USART Control and Status Register B */
#define UCSRB   (*(volatile unsigned char*)0x2A)

#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2
#define    RXB8         1
#define    TXB8         0



/* USART Control and Status Register C */
#define UCSRC     (*(volatile unsigned char*)0x40)

/* USART Register C */
#define    URSEL        7
#define    UMSEL        6
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0


/* USART Baud Rate Register High */
#define UBRRH    (*(volatile unsigned char*)0x40)


/* USART Baud Rate Register Low */
#define UBRRL    (*(volatile unsigned char*)0x29)



/* USART I/O Data Register */ 
#define UDR		(*(volatile unsigned char*)0x2C)



#endif /* MEMMAP_H_ */