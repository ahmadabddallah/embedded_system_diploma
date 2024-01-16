

#ifndef MEMMAP32_H_
#define MEMMAP32_H_
/*
#  define __INTR_ATTRS used, externally_visible
#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)*/
//#define _VECTOR(N) __vector_ ## N*/

/* DIO_Registers */
#define DDRA_PR (*(volatile unsigned char*)0x3A)
#define DDRB_PR (*(volatile unsigned char*)0x37)
#define DDRC_PR (*(volatile unsigned char*)0x34)
#define DDRD_PR (*(volatile unsigned char*)0x31)

#define PINA_PR (*(volatile unsigned char*)0x39)
#define PINB_PR (*(volatile unsigned char*)0x36)
#define PINC_PR (*(volatile unsigned char*)0x33)
#define PIND_PR (*(volatile unsigned char*)0x30)

#define PORTA_PR (*(volatile unsigned char*)0x3B)
#define PORTB_PR (*(volatile unsigned char*)0x38)
#define PORTC_PR (*(volatile unsigned char*)0x35)
#define PORTD_PR (*(volatile unsigned char*)0x32)
/********************************************************************************************************/

/* ADC_Registers */
#define ADMUX_PR (*(volatile unsigned char*)0x27)
#define ADLAR_PR 5
#define REFS0_PR 6
#define REFS1_PR 7

#define ADCSRA_PR (*(volatile unsigned char*)0x26)
#define ADPS0_PR 0
#define ADPS1_PR 1
#define ADPS2_PR 2
#define ADIE_PR 3
#define ADIF_PR 4
#define ADATE_PR 5
#define ADSC_PR 6
#define ADEN_PR 7

#define ADCL_PR (*(volatile unsigned char*)0x24)
#define ADCH_PR (*(volatile unsigned char*)0x25)
#define ADC_PR (*(volatile unsigned short*)0x24)
/********************************************************************************************************/
/*External Interrupt */
#define MCUCSR_PR   (*(volatile unsigned char*)0x54)
#define ISC2_PR 6

#define MCUCR_PR   (*(volatile unsigned char*)0x55)
#define ISC00_PR 0
#define ISC01_PR 1
#define ISC10_PR 2
#define ISC11_PR 3

#define GICRv     (*(volatile unsigned char*)0x5B)
#define INT1v 7
#define INT0v 6
#define INT2v 5

#define GIFR_PR    (*(volatile unsigned char*)0x5A)
#define INTF1_PR 7
#define INTF0_PR 6
#define INTF2_PR 5
/************************************************************************************************/
/* Timer 0 */
#define TCNT0_PR   (*(volatile unsigned char*)0x52)
#define TCCR0_PR   (*(volatile unsigned char*)0x53)
/* TCCR0 */
#define FOC0_PR    7
#define WGM00_PR   6
#define COM01_PR   5
#define COM00_PR   4
#define WGM01_PR   3
#define CS02_PR    2
#define CS01_PR    1
#define CS00_PR    0

#define TWCR_PR    (*(volatile unsigned char*)0x56)
#define SPMCR_PR   (*(volatile unsigned char*)0x57)
#define TIFR_PR    (*(volatile unsigned char*)0x58)
#define TIMSK_PR   (*(volatile unsigned char*)0x59)
/* TIMSK */
#define OCIE2_PR   7
#define TOIE2_PR   6
#define TICIE1_PR  5
#define OCIE1A_PR  4
#define OCIE1B_PR  3
#define TOIE1_PR   2
#define OCIE0_PR   1
#define TOIE0_PR   0

#define OCR0_PR    (*(volatile unsigned char*)0x5C)
/****************************************************************************************************/

/*TIMER 1*/


#define ICR1_PR         (*(volatile unsigned short*)0x46)
#define ICR1L_PR     (*(volatile unsigned char*)0x46)
#define ICR1H_PR     (*(volatile unsigned char*)0x47)
#define OCR1B_PR     (*(volatile unsigned short*)0x48)
#define OCR1BL_PR    (*(volatile unsigned char*)0x48)
#define OCR1BH_PR       (*(volatile unsigned char*)0x49)
#define OCR1A_PR     (*(volatile unsigned short*)0x4A)
#define OCR1AL_PR    (*(volatile unsigned char*)0x4A)
#define OCR1AH_PR      (*(volatile unsigned char*)0x4B)
#define TCNT1_PR       (*(volatile unsigned short*)0x4C)
#define TCNT1L_PR    (*(volatile unsigned char*)0x4C)
#define TCNT1H_PR    (*(volatile unsigned char*)0x4D)
#define TCCR1B_PR       (*(volatile unsigned char*)0x4E)
#define TCCR1A_PR        (*(volatile unsigned char*)0x4F)

#define SFIOR_PR       (*(volatile unsigned char*)0x50)

#define OSCCAL_PR       (*(volatile unsigned char*)0x51)
/******************************************************************************/
/* Timer 2 */

#define OCR2_PR     (*(volatile unsigned char*)0x43)
#define TCNT2_PR    (*(volatile unsigned char*)0x44)
#define TCCR2_PR    (*(volatile unsigned char*)0x45)




/* TCCR2 */
#define FOC2_PR    7
#define WGM20_PR   6
#define COM21_PR   5
#define COM20_PR   4
#define WGM21_PR   3
#define CS22_PR    2
#define CS21_PR    1
#define CS20_PR    0

/* ASSR */
/* bits 7-4 reserved */
#define AS2_PR     3
#define TCN2UB_PR  2
#define OCR2UB_PR  1
#define TCR2UB_PR  0

/* TCCR1A */
#define COM1A1_PR  7
#define COM1A0_PR  6
#define COM1B1_PR  5
#define COM1B0_PR  4
#define FOC1A_PR   3
#define FOC1B_PR   2
#define WGM11_PR   1
#define WGM10_PR   0

/* TCCR1B */
#define ICNC1_PR   7
#define ICES1_PR   6
/* bit 5 reserved */
#define WGM13_PR   4
#define WGM12_PR   3
#define CS12_PR    2
#define CS11_PR    1
#define CS10_PR    0

/* WDTCR */
#define WDTCR_PR    (*(volatile unsigned char*)0x41)
/* bits 7-5 reserved */
#define WDTOE_PR   4
#define WDE_PR     3
#define WDP2_PR    2
#define WDP1_PR    1
#define WDP0_PR    0








/*****************************UART Registers*******************************/
/* USART Baud Rate Register Low */
#define UBRRL_PR    (*(volatile unsigned char*)0x29)

/* USART Control and Status Register B */
#define UCSRB_PR   (*(volatile unsigned char*)0x2A)

#define    RXCIE_PR        7
#define    TXCIE_PR        6
#define    UDRIE_PR        5
#define    RXEN_PR        4
#define    TXEN_PR        3
#define    UCSZ_PR        2
#define    UCSZ2_PR        2
#define    RXB8_PR        1
#define    TXB8_PR        0
/* USART Control and Status Register A */
#define UCSRA_PR    (*(volatile unsigned char*)0x2B)

#define    RXC_PR         7
#define    TXC_PR         6
#define    UDRE_PR         5
#define    FE_PR         4
#define    DOR_PR         3
#define    UPE_PR         2
#define    U2X_PR         1
#define    MPCM_PR         0
/* USART I/O Data Register */
#define UDR_PR       (*(volatile unsigned char*)0x2C)

/* USART Baud Rate Register High */
#define UBRRH_PR    (*(volatile unsigned char*)0x40)

/* USART Control and Status Register C */
#define UCSRC_PR     (*(volatile unsigned char*)0x40)

/* USART Register C */
#define    URSEL_PR        7
#define    UMSEL_PR        6
#define    UPM1_PR         5
#define    UPM0_PR         4
#define    USBS_PR         3
#define    UCSZ1_PR        2
#define    UCSZ0_PR        1
#define    UCPOL_PR        0



/******************************************************************************/
/* SPI */
/* SPI Control Register */
#define SPCR_PR       (*(volatile unsigned char*)0x2D)
/* SPI Status Register */
#define SPSR_PR       (*(volatile unsigned char*)0x2E)
/* SPI I/O Data Register */
#define SPDR_PR       (*(volatile unsigned char*)0x2F)

/* SPI Status Register - SPSR */
#define    SPIF_PR         7
#define    WCOL_PR         6
#define    SPI2X_PR        0

/* SPI Control Register - SPCR */
#define    SPIE_PR         7
#define    SPE_PR         6
#define    DORD_PR         5
#define    MSTR_PR         4
#define    CPOL_PR         3
#define    CPHA_PR         2
#define    SPR1_PR         1
#define    SPR0_PR         0

/****************************** EEPROM Control Register ****************************/
/* EEPROM Control Register */
#define EECR_PR	(*(volatile unsigned char*)0x3C)

#define    EERIE_PR        3
#define    EEMWE_PR        2
#define    EEWE_PR        1
#define    EERE_PR        0

/* EEPROM Data Register */
#define EEDR_PR	(*(volatile unsigned char*)0x3D)

/* EEPROM Address Register */
#define EEAR_PR	(*(volatile unsigned short*)0x3E)
#define EEARL_PR	(*(volatile unsigned char*)0x3E)
#define EEARH_PR	(*(volatile unsigned char*)0x3F)

/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */
#define TWBR_PR    (*(volatile unsigned char*)0x20)
#define TWSR_PR    (*(volatile unsigned char*)0x21)
#define TWAR_PR    (*(volatile unsigned char*)0x22)
#define TWDR_PR    (*(volatile unsigned char*)0x23)

/* TIMSK */
#define OCIE2_PR   7
#define TOIE2_PR   6
#define TICIE1_PR  5
#define OCIE1A_PR  4
#define OCIE1B_PR  3
#define TOIE1_PR   2
#define OCIE0_PR   1
#define TOIE0_PR   0

/* TIFR */
#define OCF2_PR   7
#define TOV2_PR   6
#define ICF1_PR   5
#define OCF1A_PR   4
#define OCF1B_PR   3
#define TOV1_PR   2
#define OCF0_PR   1
#define TOV0_PR   0

/* SPMCR */
#define SPMIE_PR   7
#define RWWSB_PR   6
/* bit 5 reserved */
#define RWWSRE_PR  4
#define BLBSET_PR  3
#define PGWRT_PR   2
#define PGERS_PR   1
#define SPMEN_PR   0

/* TWCR */
#define TWINT_PR   7
#define TWEA_PR   6
#define TWSTA_PR   5
#define TWSTO_PR   4
#define TWWC_PR   3
#define TWEN_PR   2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6_PR    7
#define TWA5_PR    6
#define TWA4_PR    5
#define TWA3_PR    4
#define TWA2_PR    3
#define TWA1_PR    2
#define TWA0_PR    1
#define TWGCE_PR   0

/* TWSR */
#define TWS7_PR    7
#define TWS6_PR    6
#define TWS5_PR    5
#define TWS4_PR    4
#define TWS3_PR    3
/* bit 2 reserved */
#define TWPS1_PR   1
#define TWPS0_PR   0
/*********************************************************************************/
/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect_PR			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect_PR			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect_PR			__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect_PR		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect_PR			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect_PR		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect_PR		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_OCB_vect_PR		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect_PR			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect_PR		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect_PR			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect_PR			__vector_12
/* USART, Rx Complete */
#define UART_RX_vect_PR			__vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect_PR			__vector_14
/* USART, Tx Complete */
#define UART_TX_vect_PR			__vector_15
/* ADC Conversion Complete */
#define ADC_vect_PR			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect_PR			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect_PR			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect_PR			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect_PR			__vector_20

#  define BAD_vect_PR __vector_default

/*interrupt functions*/

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)
# define ret()  __asm__ __volatile__ ("ret" ::)

#  define ISR_NOBLOCK_PR    __attribute__((interrupt))
#  define ISR_NAKED_PR      __attribute__((naked))


#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)






#endif /* MEMMAPPED32_H_ */
