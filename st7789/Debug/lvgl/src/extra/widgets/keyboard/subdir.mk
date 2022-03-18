################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/widgets/keyboard/lv_keyboard.c 

OBJS += \
./lvgl/src/extra/widgets/keyboard/lv_keyboard.o 

C_DEPS += \
./lvgl/src/extra/widgets/keyboard/lv_keyboard.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/widgets/keyboard/%.o lvgl/src/extra/widgets/keyboard/%.su: ../lvgl/src/extra/widgets/keyboard/%.c lvgl/src/extra/widgets/keyboard/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/lth/src/blackpill/st7789/lvgl/src" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-keyboard

clean-lvgl-2f-src-2f-extra-2f-widgets-2f-keyboard:
	-$(RM) ./lvgl/src/extra/widgets/keyboard/lv_keyboard.d ./lvgl/src/extra/widgets/keyboard/lv_keyboard.o ./lvgl/src/extra/widgets/keyboard/lv_keyboard.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-keyboard

