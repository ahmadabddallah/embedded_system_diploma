################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICES/TimerServices.c \
../SERVICES/UART_Services.c 

OBJS += \
./SERVICES/TimerServices.o \
./SERVICES/UART_Services.o 

C_DEPS += \
./SERVICES/TimerServices.d \
./SERVICES/UART_Services.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICES/%.o: ../SERVICES/%.c SERVICES/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\HAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\MCAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\Scheduler" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\SERVICES" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

