################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

-include makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include rcarmcuu5x_gen/subdir.mk
-include rcarmcu/fsp/src/r_ioport/subdir.mk
-include rcarmcu/fsp/src/bsp/mcu/rcarmcuu5l/subdir.mk
-include rcarmcu/fsp/src/bsp/mcu/all/subdir.mk
-include rcarmcu/fsp/src/bsp/cmsis/Device/RENESAS/Source/subdir.mk
-include rcarmcu/board/u5l4_176_pb/subdir.mk
-include rcarmcu/arm/CMSIS_6/subdir.mk
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
$(C_DEPS):$(SMS_ASM)
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
OBJCOPY += \
RCarU5L4176_10BASET1S_FSP130.srec \

SECONDARY_SIZE += \
RCarU5L4176_10BASET1S_FSP130.siz \


# All Target
all: RCarU5L4176_10BASET1S_FSP130.elf secondary-outputs

# Tool invocations
RCarU5L4176_10BASET1S_FSP130.elf: $(OBJS) $(USER_OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(LINKER_SCRIPT)
	$(file > RCarU5L4176_10BASET1S_FSP130.elf.in,-mcpu=cortex-m33 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -o "RCarU5L4176_10BASET1S_FSP130.elf" $(OBJS) $(USER_OBJS) -T "fsp.lld" -L"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130/script" -L"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\Debug" -Wl,-Map=RCarU5L4176_10BASET1S_FSP130.map -Wl,--start-group -lcrt0 -lc++abi  -Wl,--end-group -Wl,--gc-sections -Wl,--cref -Wl,--icf=none -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcuu5x_cfg\\fsp_cfg\\bsp" -I"." -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcuu5x_gen" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcuu5x_cfg\\fsp_cfg" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\src\\bsp\\mcu\\rcarmcuu5l\\rcarmcuu5l4" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\inc" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\src\\bsp\\mcu\\rcarmcuu5l" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\src" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\inc\\api" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\inc\\instances" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\src\\bsp\\mcu\\all")
	@echo Building target: $@ && clang  --target=arm-none-eabi @"RCarU5L4176_10BASET1S_FSP130.elf.in"> RCarU5L4176_10BASET1S_FSP130.cref
RCarU5L4176_10BASET1S_FSP130.srec: RCarU5L4176_10BASET1S_FSP130.elf
	llvm-objcopy "RCarU5L4176_10BASET1S_FSP130.elf" -O srec  "RCarU5L4176_10BASET1S_FSP130.srec"
RCarU5L4176_10BASET1S_FSP130.siz: RCarU5L4176_10BASET1S_FSP130.elf
	llvm-size --format=berkeley "RCarU5L4176_10BASET1S_FSP130.elf"
# Other Targets
clean:
	-$(file > clean_file.tmp,  $(JMP_DEPS)  $(FSY_DEPS)  $(C_UPPER_DEPS)  $(SECONDARY_SIZE)  $(SRC_UPPER_DEPS)  $(P_UPPER_DEPS)  $(S_DEPS)  $(PP_UPPER_DEPS)  $(P_DEPS)  $(FSY_UPPER_DEPS)  $(C_DEPS)  $(CREF)  $(SRC_DEPS)  $(OBJCOPY)  $(JMP_UPPER_DEPS)  $(PP_DEPS)  $(SX_DEPS)  $(ASM_UPPER_DEPS)  $(OBJS)  $(SX_UPPER_DEPS)  $(ASM_DEPS)  $(MAP)  $(S_UPPER_DEPS) )
	-@ xargs -P 2 -s 32000 -t -a clean_file.tmp $(RM)
	-@$(RM) clean_file.tmp
	-$(RM)  RCarU5L4176_10BASET1S_FSP130.elf
	-@echo ' '

secondary-outputs: $(OBJCOPY) $(SECONDARY_SIZE)

.PHONY: all clean dependents 

-include ../makefile.targets
