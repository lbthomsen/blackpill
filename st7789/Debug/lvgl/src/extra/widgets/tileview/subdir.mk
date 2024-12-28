################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/widgets/tileview/lv_tileview.c 

OBJS += \
./lvgl/src/extra/widgets/tileview/lv_tileview.o 

C_DEPS += \
./lvgl/src/extra/widgets/tileview/lv_tileview.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/widgets/tileview/%.o lvgl/src/extra/widgets/tileview/%.su lvgl/src/extra/widgets/tileview/%.cyclo: ../lvgl/src/extra/widgets/tileview/%.c lvgl/src/extra/widgets/tileview/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/lth/src/blackpill/st7789/lvgl/src" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-tileview

clean-lvgl-2f-src-2f-extra-2f-widgets-2f-tileview:
	-$(RM) ./lvgl/src/extra/widgets/tileview/lv_tileview.cyclo ./lvgl/src/extra/widgets/tileview/lv_tileview.d ./lvgl/src/extra/widgets/tileview/lv_tileview.o ./lvgl/src/extra/widgets/tileview/lv_tileview.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-tileview

