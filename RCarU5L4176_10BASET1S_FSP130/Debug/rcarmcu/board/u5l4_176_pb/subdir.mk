################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rcarmcu/board/u5l4_176_pb/board_init.c \
../rcarmcu/board/u5l4_176_pb/board_leds.c 

C_DEPS += \
./rcarmcu/board/u5l4_176_pb/board_init.d \
./rcarmcu/board/u5l4_176_pb/board_leds.d 

CREF += \
RCarU5L4176_10BASET1S_FSP130.cref 

OBJS += \
./rcarmcu/board/u5l4_176_pb/board_init.o \
./rcarmcu/board/u5l4_176_pb/board_leds.o 

MAP += \
RCarU5L4176_10BASET1S_FSP130.map 


# Each subdirectory must supply rules for building sources it contributes
rcarmcu/board/u5l4_176_pb/%.o: ../rcarmcu/board/u5l4_176_pb/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -fshort-enums -fno-unroll-loops -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcuu5x_cfg\\fsp_cfg\\bsp" -I"." -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcuu5x_gen" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcuu5x_cfg\\fsp_cfg" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\src\\bsp\\mcu\\rcarmcuu5l\\rcarmcuu5l4" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\inc" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\src\\bsp\\mcu\\rcarmcuu5l" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\src" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\inc\\api" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\inc\\instances" -I"G:\\SW_Workspace\\workspaceRenesas_e2Studio_U5L\\RCarU5L4176_10BASET1S_FSP130\\rcarmcu\\fsp\\src\\bsp\\mcu\\all" -D_RENESAS_RCARMCUU5X_ -D_RCARMCUU5X_CORE=CM33 -D_RCARMCUU5X_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

