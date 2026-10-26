################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../R_device_U5L/clock/R_driver_clock.o 

C_SRCS += \
../R_device_U5L/clock/R_driver_clock.c 

C_DEPS += \
./R_device_U5L/clock/R_driver_clock.d 

OBJS += \
./R_device_U5L/clock/R_driver_clock.o 

SREC += \
U5L_ETNF_01_T1S_COM.srec 

MAP += \
U5L_ETNF_01_T1S_COM.map 


# Each subdirectory must supply rules for building sources it contributes
R_device_U5L/clock/%.o: ../R_device_U5L/clock/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/ETNF" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/src/config" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/flash" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/standby" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/COM" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/general" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/src" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/ETNF" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/clock" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/RLIN3" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/cmsis" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/CLMA" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/reset" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/CLMA" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/port" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/RSCFD" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/src/App" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/RSCFD" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/src/PE0" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/RLIN3" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/INTC" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/ECM" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

