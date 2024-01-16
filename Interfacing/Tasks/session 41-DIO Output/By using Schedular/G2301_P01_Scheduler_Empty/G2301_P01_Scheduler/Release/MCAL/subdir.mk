################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/DIO.c \
../MCAL/DIO_Lcfg.c \
../MCAL/EXInterrupt.c \
../MCAL/SPI.c \
../MCAL/Timers.c \
../MCAL/UART.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/DIO.o \
./MCAL/DIO_Lcfg.o \
./MCAL/EXInterrupt.o \
./MCAL/SPI.o \
./MCAL/Timers.o \
./MCAL/UART.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/DIO.d \
./MCAL/DIO_Lcfg.d \
./MCAL/EXInterrupt.d \
./MCAL/SPI.d \
./MCAL/Timers.d \
./MCAL/UART.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\HAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\MCAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\Scheduler" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\SERVICES" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


