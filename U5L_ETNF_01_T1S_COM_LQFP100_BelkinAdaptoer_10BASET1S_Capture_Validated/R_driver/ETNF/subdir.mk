################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/R_driver/ETNF/R_driver_ETNF.c 

C_DEPS += \
./R_driver/ETNF/R_driver_ETNF.d 

OBJS += \
./R_driver/ETNF/R_driver_ETNF.o 

SREC += \
U5L_ETNF_01_T1S_COM.srec 

MAP += \
U5L_ETNF_01_T1S_COM.map 


# Each subdirectory must supply rules for building sources it contributes
R_driver/ETNF/R_driver_ETNF.o: C:/R_driver/ETNF/R_driver_ETNF.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -I"C:/R_driver/ETNF" -I"C:/U5L_ETNF_01_T1S_COM/src/config" -I"C:/R_device_U5L/flash" -I"C:/R_device_U5L/standby" -I"C:/R_driver/COM" -I"C:/R_driver/general" -I"C:/R_device_U5L" -I"C:/R_driver" -I"C:/U5L_ETNF_01_T1S_COM/src" -I"C:/R_device_U5L/ETNF" -I"C:/R_device_U5L/clock" -I"C:/R_device_U5L/RLIN3" -I"C:/R_device_U5L/cmsis" -I"C:/R_driver/CLMA" -I"C:/R_device_U5L/reset" -I"C:/R_device_U5L/CLMA" -I"C:/R_device_U5L/port" -I"C:/R_device_U5L/RSCFD" -I"C:/U5L_ETNF_01_T1S_COM/src/App" -I"C:/R_driver/RSCFD" -I"C:/U5L_ETNF_01_T1S_COM/src/PE0" -I"C:/R_driver/RLIN3" -I"C:/R_device_U5L/INTC" -I"C:/R_device_U5L/ECM" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

