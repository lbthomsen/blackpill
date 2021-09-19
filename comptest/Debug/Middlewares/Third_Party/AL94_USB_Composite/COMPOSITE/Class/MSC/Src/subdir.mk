################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
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
Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/%.o: ../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/%.c Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Composite -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/COMPOSITE/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/HID_CUSTOM/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Core/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Target -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/CDC_ACM/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

