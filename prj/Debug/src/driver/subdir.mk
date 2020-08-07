################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/driver/gpio.c \
../src/driver/nvic.c \
../src/driver/rcc.c \
../src/driver/timer.c \
../src/driver/uart.c 

OBJS += \
./src/driver/gpio.o \
./src/driver/nvic.o \
./src/driver/rcc.o \
./src/driver/timer.o \
./src/driver/uart.o 

C_DEPS += \
./src/driver/gpio.d \
./src/driver/nvic.d \
./src/driver/rcc.d \
./src/driver/timer.d \
./src/driver/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/driver/%.o: ../src/driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401RETx -DNUCLEO_F401RE -DDEBUG -I"D:/MyDocuments/MyWork/prj/stm32/io_test/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


