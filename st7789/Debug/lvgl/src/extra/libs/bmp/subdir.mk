################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/libs/bmp/lv_bmp.c 

OBJS += \
./lvgl/src/extra/libs/bmp/lv_bmp.o 

C_DEPS += \
./lvgl/src/extra/libs/bmp/lv_bmp.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/libs/bmp/%.o lvgl/src/extra/libs/bmp/%.su lvgl/src/extra/libs/bmp/%.cyclo: ../lvgl/src/extra/libs/bmp/%.c lvgl/src/extra/libs/bmp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/lth/src/blackpill/st7789/lvgl/src" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-libs-2f-bmp

clean-lvgl-2f-src-2f-extra-2f-libs-2f-bmp:
	-$(RM) ./lvgl/src/extra/libs/bmp/lv_bmp.cyclo ./lvgl/src/extra/libs/bmp/lv_bmp.d ./lvgl/src/extra/libs/bmp/lv_bmp.o ./lvgl/src/extra/libs/bmp/lv_bmp.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-libs-2f-bmp

