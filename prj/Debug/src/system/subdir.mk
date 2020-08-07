################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/system/main.c \
../src/system/systm.c 

OBJS += \
./src/system/main.o \
./src/system/systm.o 

C_DEPS += \
./src/system/main.d \
./src/system/systm.d 


# Each subdirectory must supply rules for building sources it contributes
src/system/%.o: ../src/system/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401RETx -DNUCLEO_F401RE -DDEBUG -I"D:/MyDocuments/MyWork/prj/stm32/io_test/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


