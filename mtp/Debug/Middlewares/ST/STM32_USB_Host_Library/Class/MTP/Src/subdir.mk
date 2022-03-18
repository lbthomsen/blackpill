################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp.c \
../Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp_ptp.c 

OBJS += \
./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp.o \
./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp_ptp.o 

C_DEPS += \
./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp.d \
./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp_ptp.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/%.o Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/%.su: ../Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/%.c Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_HOST/App -I../USB_HOST/Target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Inc -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-MTP-2f-Src

clean-Middlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-MTP-2f-Src:
	-$(RM) ./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp.d ./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp.o ./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp.su ./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp_ptp.d ./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp_ptp.o ./Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp_ptp.su

.PHONY: clean-Middlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-MTP-2f-Src

