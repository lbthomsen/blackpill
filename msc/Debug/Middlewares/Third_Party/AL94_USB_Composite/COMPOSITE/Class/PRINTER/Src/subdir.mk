################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/PRINTER/Src/usbd_printer.c 

OBJS += \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/PRINTER/Src/usbd_printer.o 

C_DEPS += \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/PRINTER/Src/usbd_printer.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/PRINTER/Src/%.o: ../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/PRINTER/Src/%.c Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/PRINTER/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Composite -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/HID_KEYBOARD/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/HID_CUSTOM/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Core/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Target -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/DFU/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/PRINTER/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/HID_MOUSE/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/AUDIO_MIC/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/COMPOSITE/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/AUDIO_SPKR/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/CDC_ACM/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/VIDEO/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/CDC_RNDIS/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/CDC_ECM/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

