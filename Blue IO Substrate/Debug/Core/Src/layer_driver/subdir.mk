################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/layer_driver/can.cpp 

OBJS += \
./Core/Src/layer_driver/can.o 

CPP_DEPS += \
./Core/Src/layer_driver/can.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/layer_driver/%.o Core/Src/layer_driver/%.su Core/Src/layer_driver/%.cyclo: ../Core/Src/layer_driver/%.cpp Core/Src/layer_driver/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-layer_driver

clean-Core-2f-Src-2f-layer_driver:
	-$(RM) ./Core/Src/layer_driver/can.cyclo ./Core/Src/layer_driver/can.d ./Core/Src/layer_driver/can.o ./Core/Src/layer_driver/can.su

.PHONY: clean-Core-2f-Src-2f-layer_driver

