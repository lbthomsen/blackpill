################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../usb/Class/MSC/Src/usbd_msc.c \
../usb/Class/MSC/Src/usbd_msc_bot.c \
../usb/Class/MSC/Src/usbd_msc_data.c \
../usb/Class/MSC/Src/usbd_msc_scsi.c 

OBJS += \
./usb/Class/MSC/Src/usbd_msc.o \
./usb/Class/MSC/Src/usbd_msc_bot.o \
./usb/Class/MSC/Src/usbd_msc_data.o \
./usb/Class/MSC/Src/usbd_msc_scsi.o 

C_DEPS += \
./usb/Class/MSC/Src/usbd_msc.d \
./usb/Class/MSC/Src/usbd_msc_bot.d \
./usb/Class/MSC/Src/usbd_msc_data.d \
./usb/Class/MSC/Src/usbd_msc_scsi.d 


# Each subdirectory must supply rules for building sources it contributes
usb/Class/MSC/Src/usbd_msc.o: ../usb/Class/MSC/Src/usbd_msc.c usb/Class/MSC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usb/App -I../usb/Target -I../usb/Core/Inc -I../usb/Class/CDC/Inc -I../usb/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"usb/Class/MSC/Src/usbd_msc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
usb/Class/MSC/Src/usbd_msc_bot.o: ../usb/Class/MSC/Src/usbd_msc_bot.c usb/Class/MSC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usb/App -I../usb/Target -I../usb/Core/Inc -I../usb/Class/CDC/Inc -I../usb/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"usb/Class/MSC/Src/usbd_msc_bot.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
usb/Class/MSC/Src/usbd_msc_data.o: ../usb/Class/MSC/Src/usbd_msc_data.c usb/Class/MSC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usb/App -I../usb/Target -I../usb/Core/Inc -I../usb/Class/CDC/Inc -I../usb/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"usb/Class/MSC/Src/usbd_msc_data.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
usb/Class/MSC/Src/usbd_msc_scsi.o: ../usb/Class/MSC/Src/usbd_msc_scsi.c usb/Class/MSC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usb/App -I../usb/Target -I../usb/Core/Inc -I../usb/Class/CDC/Inc -I../usb/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"usb/Class/MSC/Src/usbd_msc_scsi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

