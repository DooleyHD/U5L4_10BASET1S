################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/PE0/cstart_pe0.s \
../src/PE0/vecttable_pe0.s 

C_SRCS += \
../src/PE0/exception_handler_pe0.c \
../src/PE0/main_pe0.c \
../src/PE0/sub_pe0.c 

S_DEPS += \
./src/PE0/cstart_pe0.d \
./src/PE0/vecttable_pe0.d 

C_DEPS += \
./src/PE0/exception_handler_pe0.d \
./src/PE0/main_pe0.d \
./src/PE0/sub_pe0.d 

OBJS += \
./src/PE0/cstart_pe0.o \
./src/PE0/exception_handler_pe0.o \
./src/PE0/main_pe0.o \
./src/PE0/sub_pe0.o \
./src/PE0/vecttable_pe0.o 

SREC += \
U5L_ETNF_01_T1S_COM.srec 

MAP += \
U5L_ETNF_01_T1S_COM.map 


# Each subdirectory must supply rules for building sources it contributes
src/PE0/%.o: ../src/PE0/%.s
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"
src/PE0/%.o: ../src/PE0/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/ETNF" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/src/config" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/flash" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/standby" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/COM" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/general" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/src" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/ETNF" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/clock" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/RLIN3" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/cmsis" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/CLMA" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/reset" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/CLMA" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/port" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/RSCFD" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/src/App" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/RSCFD" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/src/PE0" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_driver/RLIN3" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/INTC" -I"D:/Workspace_U5L/U5L_ETNF_01_T1S_COM/R_device_U5L/ECM" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

