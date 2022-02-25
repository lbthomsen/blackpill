################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp.c \
../lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp_osa.c 

OBJS += \
./lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp.o \
./lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp_osa.o 

C_DEPS += \
./lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp.d \
./lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp_osa.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/nxp_pxp/%.o: ../lvgl/src/draw/nxp_pxp/%.c lvgl/src/draw/nxp_pxp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/lth/src/blackpill/st7789/lvgl/src" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-nxp_pxp

clean-lvgl-2f-src-2f-draw-2f-nxp_pxp:
	-$(RM) ./lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp.d ./lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp.o ./lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp_osa.d ./lvgl/src/draw/nxp_pxp/lv_gpu_nxp_pxp_osa.o

.PHONY: clean-lvgl-2f-src-2f-draw-2f-nxp_pxp

