################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

-include makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/config/subdir.mk
-include src/PE0/subdir.mk
-include src/App/subdir.mk
-include R_driver/general/subdir.mk
-include R_driver/RSCFD/subdir.mk
-include R_driver/RLIN3/subdir.mk
-include R_driver/ETNF/subdir.mk
-include R_driver/COM/subdir.mk
-include R_driver/CLMA/subdir.mk
-include R_device_U5L/standby/subdir.mk
-include R_device_U5L/reset/subdir.mk
-include R_device_U5L/port/subdir.mk
-include R_device_U5L/flash/subdir.mk
-include R_device_U5L/clock/subdir.mk
-include R_device_U5L/RSCFD/subdir.mk
-include R_device_U5L/RLIN3/subdir.mk
-include R_device_U5L/INTC/subdir.mk
-include R_device_U5L/ETNF/subdir.mk
-include R_device_U5L/ECM/subdir.mk
-include R_device_U5L/CLMA/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(P_UPPER_DEPS)),)
-include $(P_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(PP_UPPER_DEPS)),)
-include $(PP_UPPER_DEPS)
endif
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif
ifneq ($(strip $(FSY_UPPER_DEPS)),)
-include $(FSY_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(JMP_UPPER_DEPS)),)
-include $(JMP_UPPER_DEPS)
endif
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_UPPER_DEPS)),)
-include $(SX_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
U5L_ETNF_01_T1S_COM.srec \

SECONDARY_SIZE += \
U5L_ETNF_01_T1S_COM.siz \


# All Target
all: U5L_ETNF_01_T1S_COM.elf secondary-outputs

# Tool invocations
U5L_ETNF_01_T1S_COM.elf: $(OBJS) $(USER_OBJS) $(LINKER_SCRIPT)
	$(file > U5L_ETNF_01_T1S_COM.elf.in,-mcpu=cortex-m33 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -T "D:\\Workspace_U5L\\U5L_ETNF_01_T1S_COM\\src\\config\\section.ld" -Xlinker --gc-sections -Wl,-Map,"U5L_ETNF_01_T1S_COM.map" -o "U5L_ETNF_01_T1S_COM.elf" $(OBJS) $(USER_OBJS) $(LIBS))
	@echo Building target: $@ && arm-none-eabi-gcc @"U5L_ETNF_01_T1S_COM.elf.in"
U5L_ETNF_01_T1S_COM.srec: U5L_ETNF_01_T1S_COM.elf
	arm-none-eabi-objcopy -O srec "U5L_ETNF_01_T1S_COM.elf"  "U5L_ETNF_01_T1S_COM.srec"
U5L_ETNF_01_T1S_COM.siz: U5L_ETNF_01_T1S_COM.elf
	arm-none-eabi-size --format=berkeley "U5L_ETNF_01_T1S_COM.elf"
# Other Targets
clean:
	-$(file > clean_file.tmp,  $(JMP_DEPS)  $(FSY_DEPS)  $(C_UPPER_DEPS)  $(SECONDARY_SIZE)  $(SRC_UPPER_DEPS)  $(P_UPPER_DEPS)  $(S_DEPS)  $(PP_UPPER_DEPS)  $(P_DEPS)  $(FSY_UPPER_DEPS)  $(C_DEPS)  $(SRC_DEPS)  $(JMP_UPPER_DEPS)  $(PP_DEPS)  $(SX_DEPS)  $(ASM_UPPER_DEPS)  $(SX_UPPER_DEPS)  $(OBJS)  $(SECONDARY_FLASH)  $(ASM_DEPS)  $(SREC)  $(S_UPPER_DEPS)  $(MAP) )
	-@ xargs -P 2 -s 32000 -t -a clean_file.tmp $(RM)
	-@$(RM) clean_file.tmp
	-$(RM)  U5L_ETNF_01_T1S_COM.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
