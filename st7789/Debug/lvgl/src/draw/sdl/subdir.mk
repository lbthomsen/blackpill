################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/sdl/lv_draw_sdl.c \
../lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./lvgl/src/draw/sdl/lv_draw_sdl.o \
./lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./lvgl/src/draw/sdl/lv_draw_sdl.d \
./lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sdl/%.o: ../lvgl/src/draw/sdl/%.c lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/lth/src/blackpill/st7789/lvgl/src" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-sdl

clean-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./lvgl/src/draw/sdl/lv_draw_sdl.d ./lvgl/src/draw/sdl/lv_draw_sdl.o ./lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./lvgl/src/draw/sdl/lv_draw_sdl_img.d ./lvgl/src/draw/sdl/lv_draw_sdl_img.o ./lvgl/src/draw/sdl/lv_draw_sdl_label.d ./lvgl/src/draw/sdl/lv_draw_sdl_label.o ./lvgl/src/draw/sdl/lv_draw_sdl_line.d ./lvgl/src/draw/sdl/lv_draw_sdl_line.o ./lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./lvgl/src/draw/sdl/lv_draw_sdl_utils.o

.PHONY: clean-lvgl-2f-src-2f-draw-2f-sdl

