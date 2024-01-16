################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MyTasks.c \
../main.c 

OBJS += \
./MyTasks.o \
./main.o 

C_DEPS += \
./MyTasks.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\Common" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\FreeRTOS\Config" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\FreeRTOS\Include" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\FreeRTOS\Sources" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\HAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\MCAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\SERVICES" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


