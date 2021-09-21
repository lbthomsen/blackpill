################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usb_device.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_audio_mic_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_audio_spkr_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_acm_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_ecm_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_rndis_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_desc.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_dfu_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_hid_custom_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_msc_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_printer_if.c \
../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_video_if.c 

OBJS += \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usb_device.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_audio_mic_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_audio_spkr_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_acm_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_ecm_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_rndis_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_desc.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_dfu_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_hid_custom_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_msc_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_printer_if.o \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_video_if.o 

C_DEPS += \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usb_device.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_audio_mic_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_audio_spkr_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_acm_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_ecm_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_cdc_rndis_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_desc.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_dfu_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_hid_custom_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_msc_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_printer_if.d \
./Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/usbd_video_if.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/%.o: ../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/%.c Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Composite -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/MSC/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/App -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/HID_KEYBOARD/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/HID_CUSTOM/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Core/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Target -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/DFU/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/PRINTER/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/HID_MOUSE/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/AUDIO_MIC/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/COMPOSITE/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/AUDIO_SPKR/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/CDC_ACM/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/VIDEO/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/CDC_RNDIS/Inc -I../Middlewares/Third_Party/AL94_USB_Composite/COMPOSITE/Class/CDC_ECM/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

