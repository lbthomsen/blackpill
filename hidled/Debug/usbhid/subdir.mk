################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../usbhid/usb_device.c \
../usbhid/usbd_conf.c \
../usbhid/usbd_core.c \
../usbhid/usbd_ctlreq.c \
../usbhid/usbd_custom_hid_if.c \
../usbhid/usbd_customhid.c \
../usbhid/usbd_desc.c \
../usbhid/usbd_ioreq.c 

OBJS += \
./usbhid/usb_device.o \
./usbhid/usbd_conf.o \
./usbhid/usbd_core.o \
./usbhid/usbd_ctlreq.o \
./usbhid/usbd_custom_hid_if.o \
./usbhid/usbd_customhid.o \
./usbhid/usbd_desc.o \
./usbhid/usbd_ioreq.o 

C_DEPS += \
./usbhid/usb_device.d \
./usbhid/usbd_conf.d \
./usbhid/usbd_core.d \
./usbhid/usbd_ctlreq.d \
./usbhid/usbd_custom_hid_if.d \
./usbhid/usbd_customhid.d \
./usbhid/usbd_desc.d \
./usbhid/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
usbhid/%.o usbhid/%.su usbhid/%.cyclo: ../usbhid/%.c usbhid/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../usbhid/ -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-usbhid

clean-usbhid:
	-$(RM) ./usbhid/usb_device.cyclo ./usbhid/usb_device.d ./usbhid/usb_device.o ./usbhid/usb_device.su ./usbhid/usbd_conf.cyclo ./usbhid/usbd_conf.d ./usbhid/usbd_conf.o ./usbhid/usbd_conf.su ./usbhid/usbd_core.cyclo ./usbhid/usbd_core.d ./usbhid/usbd_core.o ./usbhid/usbd_core.su ./usbhid/usbd_ctlreq.cyclo ./usbhid/usbd_ctlreq.d ./usbhid/usbd_ctlreq.o ./usbhid/usbd_ctlreq.su ./usbhid/usbd_custom_hid_if.cyclo ./usbhid/usbd_custom_hid_if.d ./usbhid/usbd_custom_hid_if.o ./usbhid/usbd_custom_hid_if.su ./usbhid/usbd_customhid.cyclo ./usbhid/usbd_customhid.d ./usbhid/usbd_customhid.o ./usbhid/usbd_customhid.su ./usbhid/usbd_desc.cyclo ./usbhid/usbd_desc.d ./usbhid/usbd_desc.o ./usbhid/usbd_desc.su ./usbhid/usbd_ioreq.cyclo ./usbhid/usbd_ioreq.d ./usbhid/usbd_ioreq.o ./usbhid/usbd_ioreq.su

.PHONY: clean-usbhid

