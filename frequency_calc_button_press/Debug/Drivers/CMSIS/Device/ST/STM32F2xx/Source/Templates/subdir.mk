################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.c 

OBJS += \
./Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.o 

C_DEPS += \
./Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/%.o Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/%.su Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/%.cyclo: ../Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/%.c Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F207xx -c -I../Core/Inc -I../Drivers/STM32F2xx_HAL_Driver/Inc -I../Drivers/STM32F2xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F2xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32F2xx-2f-Source-2f-Templates

clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32F2xx-2f-Source-2f-Templates:
	-$(RM) ./Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.cyclo ./Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.d ./Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.o ./Drivers/CMSIS/Device/ST/STM32F2xx/Source/Templates/system_stm32f2xx.su

.PHONY: clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32F2xx-2f-Source-2f-Templates

