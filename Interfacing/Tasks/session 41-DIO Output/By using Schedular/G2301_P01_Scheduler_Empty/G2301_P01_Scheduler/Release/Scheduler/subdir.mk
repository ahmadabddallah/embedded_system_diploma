################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Scheduler/OS.c \
../Scheduler/Tasks.c 

OBJS += \
./Scheduler/OS.o \
./Scheduler/Tasks.o 

C_DEPS += \
./Scheduler/OS.d \
./Scheduler/Tasks.d 


# Each subdirectory must supply rules for building sources it contributes
Scheduler/%.o: ../Scheduler/%.c Scheduler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\HAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\MCAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\Scheduler" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler\SERVICES" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2301_P01_Scheduler_Empty\G2301_P01_Scheduler" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


