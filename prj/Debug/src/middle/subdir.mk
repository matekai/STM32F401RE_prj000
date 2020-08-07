################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/middle/pccom_getline.c \
../src/middle/pccom_rcv.c \
../src/middle/pccom_send.c 

OBJS += \
./src/middle/pccom_getline.o \
./src/middle/pccom_rcv.o \
./src/middle/pccom_send.o 

C_DEPS += \
./src/middle/pccom_getline.d \
./src/middle/pccom_rcv.d \
./src/middle/pccom_send.d 


# Each subdirectory must supply rules for building sources it contributes
src/middle/%.o: ../src/middle/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401RETx -DNUCLEO_F401RE -DDEBUG -I"D:/MyDocuments/MyWork/prj/stm32/io_test/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


