################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include FreeRTOS/Sources/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := G2309_P03_FreeRTOS_Semaphore
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
G2309_P03_FreeRTOS_Semaphore.lss \

FLASH_IMAGE += \
G2309_P03_FreeRTOS_Semaphore.hex \

EEPROM_IMAGE += \
G2309_P03_FreeRTOS_Semaphore.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: G2309_P03_FreeRTOS_Semaphore.elf secondary-outputs

# Tool invocations
G2309_P03_FreeRTOS_Semaphore.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,G2309_P03_FreeRTOS_Semaphore.map -mmcu=atmega32 -o "G2309_P03_FreeRTOS_Semaphore.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

G2309_P03_FreeRTOS_Semaphore.lss: G2309_P03_FreeRTOS_Semaphore.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S G2309_P03_FreeRTOS_Semaphore.elf  >"G2309_P03_FreeRTOS_Semaphore.lss"
	@echo 'Finished building: $@'
	@echo ' '

G2309_P03_FreeRTOS_Semaphore.hex: G2309_P03_FreeRTOS_Semaphore.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex G2309_P03_FreeRTOS_Semaphore.elf  "G2309_P03_FreeRTOS_Semaphore.hex"
	@echo 'Finished building: $@'
	@echo ' '

G2309_P03_FreeRTOS_Semaphore.eep: G2309_P03_FreeRTOS_Semaphore.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex G2309_P03_FreeRTOS_Semaphore.elf  "G2309_P03_FreeRTOS_Semaphore.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: G2309_P03_FreeRTOS_Semaphore.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 G2309_P03_FreeRTOS_Semaphore.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) G2309_P03_FreeRTOS_Semaphore.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
