################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.c \
../lvgl/src/extra/libs/fsdrv/lv_fs_posix.c \
../lvgl/src/extra/libs/fsdrv/lv_fs_stdio.c \
../lvgl/src/extra/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.o \
./lvgl/src/extra/libs/fsdrv/lv_fs_posix.o \
./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.o \
./lvgl/src/extra/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.d \
./lvgl/src/extra/libs/fsdrv/lv_fs_posix.d \
./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.d \
./lvgl/src/extra/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/libs/fsdrv/%.o: ../lvgl/src/extra/libs/fsdrv/%.c lvgl/src/extra/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/lth/src/blackpill/st7789/lvgl/src" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv

clean-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv:
	-$(RM) ./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.d ./lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.o ./lvgl/src/extra/libs/fsdrv/lv_fs_posix.d ./lvgl/src/extra/libs/fsdrv/lv_fs_posix.o ./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.d ./lvgl/src/extra/libs/fsdrv/lv_fs_stdio.o ./lvgl/src/extra/libs/fsdrv/lv_fs_win32.d ./lvgl/src/extra/libs/fsdrv/lv_fs_win32.o

.PHONY: clean-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv

