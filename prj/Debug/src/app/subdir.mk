################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/app/dbgbrd_ctl.c \
../src/app/pccom_anly.c 

OBJS += \
./src/app/dbgbrd_ctl.o \
./src/app/pccom_anly.o 

C_DEPS += \
./src/app/dbgbrd_ctl.d \
./src/app/pccom_anly.d 


# Each subdirectory must supply rules for building sources it contributes
src/app/%.o: ../src/app/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401RETx -DNUCLEO_F401RE -DDEBUG -I"D:/MyDocuments/MyWork/prj/stm32/io_test/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


