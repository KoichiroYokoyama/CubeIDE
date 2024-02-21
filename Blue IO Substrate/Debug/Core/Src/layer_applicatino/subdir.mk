################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/layer_applicatino/Serial_Manager.cpp 

OBJS += \
./Core/Src/layer_applicatino/Serial_Manager.o 

CPP_DEPS += \
./Core/Src/layer_applicatino/Serial_Manager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/layer_applicatino/%.o Core/Src/layer_applicatino/%.su Core/Src/layer_applicatino/%.cyclo: ../Core/Src/layer_applicatino/%.cpp Core/Src/layer_applicatino/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-layer_applicatino

clean-Core-2f-Src-2f-layer_applicatino:
	-$(RM) ./Core/Src/layer_applicatino/Serial_Manager.cyclo ./Core/Src/layer_applicatino/Serial_Manager.d ./Core/Src/layer_applicatino/Serial_Manager.o ./Core/Src/layer_applicatino/Serial_Manager.su

.PHONY: clean-Core-2f-Src-2f-layer_applicatino

