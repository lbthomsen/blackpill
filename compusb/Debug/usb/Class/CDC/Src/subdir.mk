################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../usb/Class/CDC/Src/usbd_cdc.c 

OBJS += \
./usb/Class/CDC/Src/usbd_cdc.o 

C_DEPS += \
./usb/Class/CDC/Src/usbd_cdc.d 


# Each subdirectory must supply rules for building sources it contributes
usb/Class/CDC/Src/usbd_cdc.o: ../usb/Class/CDC/Src/usbd_cdc.c usb/Class/CDC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usb/App -I../usb/Target -I../usb/Core/Inc -I../usb/Class/CDC/Inc -I../usb/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"usb/Class/CDC/Src/usbd_cdc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

