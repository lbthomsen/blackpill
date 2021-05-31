################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../usb/Core/Src/usbd_core.c \
../usb/Core/Src/usbd_ctlreq.c \
../usb/Core/Src/usbd_ioreq.c 

OBJS += \
./usb/Core/Src/usbd_core.o \
./usb/Core/Src/usbd_ctlreq.o \
./usb/Core/Src/usbd_ioreq.o 

C_DEPS += \
./usb/Core/Src/usbd_core.d \
./usb/Core/Src/usbd_ctlreq.d \
./usb/Core/Src/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
usb/Core/Src/usbd_core.o: ../usb/Core/Src/usbd_core.c usb/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usb/App -I../usb/Target -I../usb/Core/Inc -I../usb/Class/CDC/Inc -I../usb/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"usb/Core/Src/usbd_core.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
usb/Core/Src/usbd_ctlreq.o: ../usb/Core/Src/usbd_ctlreq.c usb/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usb/App -I../usb/Target -I../usb/Core/Inc -I../usb/Class/CDC/Inc -I../usb/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"usb/Core/Src/usbd_ctlreq.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
usb/Core/Src/usbd_ioreq.o: ../usb/Core/Src/usbd_ioreq.c usb/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usb/App -I../usb/Target -I../usb/Core/Inc -I../usb/Class/CDC/Inc -I../usb/Class/MSC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"usb/Core/Src/usbd_ioreq.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

