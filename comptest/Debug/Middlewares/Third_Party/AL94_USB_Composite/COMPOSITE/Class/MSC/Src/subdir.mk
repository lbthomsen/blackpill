################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_bot.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_data.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_scsi.c 

OBJS += \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_bot.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_data.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_scsi.o 

C_DEPS += \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_bot.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_data.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_scsi.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/%.o Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/%.su Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/%.cyclo: ../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/%.c Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Composite -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/COMPOSITE/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/HID_CUSTOM/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Core/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Target -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/CDC_ACM/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-AL94_USB_Composite-2f-COMPOSITE-2f-Class-2f-MSC-2f-Src

clean-Middlewares-2f-Third_Party-2f-AL94_USB_Composite-2f-COMPOSITE-2f-Class-2f-MSC-2f-Src:
	-$(RM) ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc.cyclo ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc.d ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc.o ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc.su ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_bot.cyclo ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_bot.d ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_bot.o ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_bot.su ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_data.cyclo ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_data.d ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_data.o ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_data.su ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_scsi.cyclo ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_scsi.d ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_scsi.o ./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/usbd_msc_scsi.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-AL94_USB_Composite-2f-COMPOSITE-2f-Class-2f-MSC-2f-Src

