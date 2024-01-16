################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Sources/croutine.c \
../FreeRTOS/Sources/heap_1.c \
../FreeRTOS/Sources/list.c \
../FreeRTOS/Sources/port.c \
../FreeRTOS/Sources/queue.c \
../FreeRTOS/Sources/tasks.c \
../FreeRTOS/Sources/timers.c 

OBJS += \
./FreeRTOS/Sources/croutine.o \
./FreeRTOS/Sources/heap_1.o \
./FreeRTOS/Sources/list.o \
./FreeRTOS/Sources/port.o \
./FreeRTOS/Sources/queue.o \
./FreeRTOS/Sources/tasks.o \
./FreeRTOS/Sources/timers.o 

C_DEPS += \
./FreeRTOS/Sources/croutine.d \
./FreeRTOS/Sources/heap_1.d \
./FreeRTOS/Sources/list.d \
./FreeRTOS/Sources/port.d \
./FreeRTOS/Sources/queue.d \
./FreeRTOS/Sources/tasks.d \
./FreeRTOS/Sources/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Sources/%.o: ../FreeRTOS/Sources/%.c FreeRTOS/Sources/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\Common" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\FreeRTOS\Config" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\FreeRTOS\Include" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\FreeRTOS\Sources" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\HAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\MCAL" -I"H:\Embedded Diploma\Embedded Diploma\RTOS\Source Code-20231121T192222Z-001\Source Code\G2310_P03_FreeRTOS_Semaphore\G2310_P03_FreeRTOS_Semaphore\SERVICES" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


