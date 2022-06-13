################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../Testboard_HAL_drivers/source/sys_link.cmd 

ASM_SRCS += \
../Testboard_HAL_drivers/source/dabort.asm \
../Testboard_HAL_drivers/source/os_portasm.asm \
../Testboard_HAL_drivers/source/sys_core.asm \
../Testboard_HAL_drivers/source/sys_intvecs.asm \
../Testboard_HAL_drivers/source/sys_mpu.asm \
../Testboard_HAL_drivers/source/sys_pmu.asm 

C_SRCS += \
../Testboard_HAL_drivers/source/adc.c \
../Testboard_HAL_drivers/source/crc.c \
../Testboard_HAL_drivers/source/ecap.c \
../Testboard_HAL_drivers/source/eqep.c \
../Testboard_HAL_drivers/source/errata_SSWF021_45.c \
../Testboard_HAL_drivers/source/esm.c \
../Testboard_HAL_drivers/source/etpwm.c \
../Testboard_HAL_drivers/source/gio.c \
../Testboard_HAL_drivers/source/het.c \
../Testboard_HAL_drivers/source/mibspi.c \
../Testboard_HAL_drivers/source/notification.c \
../Testboard_HAL_drivers/source/os_croutine.c \
../Testboard_HAL_drivers/source/os_event_groups.c \
../Testboard_HAL_drivers/source/os_heap.c \
../Testboard_HAL_drivers/source/os_list.c \
../Testboard_HAL_drivers/source/os_mpu_wrappers.c \
../Testboard_HAL_drivers/source/os_port.c \
../Testboard_HAL_drivers/source/os_queue.c \
../Testboard_HAL_drivers/source/os_tasks.c \
../Testboard_HAL_drivers/source/os_timer.c \
../Testboard_HAL_drivers/source/pinmux.c \
../Testboard_HAL_drivers/source/rti.c \
../Testboard_HAL_drivers/source/sci.c \
../Testboard_HAL_drivers/source/sys_dma.c \
../Testboard_HAL_drivers/source/sys_pcr.c \
../Testboard_HAL_drivers/source/sys_phantom.c \
../Testboard_HAL_drivers/source/sys_pmm.c \
../Testboard_HAL_drivers/source/sys_selftest.c \
../Testboard_HAL_drivers/source/sys_startup.c \
../Testboard_HAL_drivers/source/sys_vim.c \
../Testboard_HAL_drivers/source/system.c 

C_DEPS += \
./Testboard_HAL_drivers/source/adc.d \
./Testboard_HAL_drivers/source/crc.d \
./Testboard_HAL_drivers/source/ecap.d \
./Testboard_HAL_drivers/source/eqep.d \
./Testboard_HAL_drivers/source/errata_SSWF021_45.d \
./Testboard_HAL_drivers/source/esm.d \
./Testboard_HAL_drivers/source/etpwm.d \
./Testboard_HAL_drivers/source/gio.d \
./Testboard_HAL_drivers/source/het.d \
./Testboard_HAL_drivers/source/mibspi.d \
./Testboard_HAL_drivers/source/notification.d \
./Testboard_HAL_drivers/source/os_croutine.d \
./Testboard_HAL_drivers/source/os_event_groups.d \
./Testboard_HAL_drivers/source/os_heap.d \
./Testboard_HAL_drivers/source/os_list.d \
./Testboard_HAL_drivers/source/os_mpu_wrappers.d \
./Testboard_HAL_drivers/source/os_port.d \
./Testboard_HAL_drivers/source/os_queue.d \
./Testboard_HAL_drivers/source/os_tasks.d \
./Testboard_HAL_drivers/source/os_timer.d \
./Testboard_HAL_drivers/source/pinmux.d \
./Testboard_HAL_drivers/source/rti.d \
./Testboard_HAL_drivers/source/sci.d \
./Testboard_HAL_drivers/source/sys_dma.d \
./Testboard_HAL_drivers/source/sys_pcr.d \
./Testboard_HAL_drivers/source/sys_phantom.d \
./Testboard_HAL_drivers/source/sys_pmm.d \
./Testboard_HAL_drivers/source/sys_selftest.d \
./Testboard_HAL_drivers/source/sys_startup.d \
./Testboard_HAL_drivers/source/sys_vim.d \
./Testboard_HAL_drivers/source/system.d 

OBJS += \
./Testboard_HAL_drivers/source/adc.obj \
./Testboard_HAL_drivers/source/crc.obj \
./Testboard_HAL_drivers/source/dabort.obj \
./Testboard_HAL_drivers/source/ecap.obj \
./Testboard_HAL_drivers/source/eqep.obj \
./Testboard_HAL_drivers/source/errata_SSWF021_45.obj \
./Testboard_HAL_drivers/source/esm.obj \
./Testboard_HAL_drivers/source/etpwm.obj \
./Testboard_HAL_drivers/source/gio.obj \
./Testboard_HAL_drivers/source/het.obj \
./Testboard_HAL_drivers/source/mibspi.obj \
./Testboard_HAL_drivers/source/notification.obj \
./Testboard_HAL_drivers/source/os_croutine.obj \
./Testboard_HAL_drivers/source/os_event_groups.obj \
./Testboard_HAL_drivers/source/os_heap.obj \
./Testboard_HAL_drivers/source/os_list.obj \
./Testboard_HAL_drivers/source/os_mpu_wrappers.obj \
./Testboard_HAL_drivers/source/os_port.obj \
./Testboard_HAL_drivers/source/os_portasm.obj \
./Testboard_HAL_drivers/source/os_queue.obj \
./Testboard_HAL_drivers/source/os_tasks.obj \
./Testboard_HAL_drivers/source/os_timer.obj \
./Testboard_HAL_drivers/source/pinmux.obj \
./Testboard_HAL_drivers/source/rti.obj \
./Testboard_HAL_drivers/source/sci.obj \
./Testboard_HAL_drivers/source/sys_core.obj \
./Testboard_HAL_drivers/source/sys_dma.obj \
./Testboard_HAL_drivers/source/sys_intvecs.obj \
./Testboard_HAL_drivers/source/sys_mpu.obj \
./Testboard_HAL_drivers/source/sys_pcr.obj \
./Testboard_HAL_drivers/source/sys_phantom.obj \
./Testboard_HAL_drivers/source/sys_pmm.obj \
./Testboard_HAL_drivers/source/sys_pmu.obj \
./Testboard_HAL_drivers/source/sys_selftest.obj \
./Testboard_HAL_drivers/source/sys_startup.obj \
./Testboard_HAL_drivers/source/sys_vim.obj \
./Testboard_HAL_drivers/source/system.obj 

ASM_DEPS += \
./Testboard_HAL_drivers/source/dabort.d \
./Testboard_HAL_drivers/source/os_portasm.d \
./Testboard_HAL_drivers/source/sys_core.d \
./Testboard_HAL_drivers/source/sys_intvecs.d \
./Testboard_HAL_drivers/source/sys_mpu.d \
./Testboard_HAL_drivers/source/sys_pmu.d 

OBJS__QUOTED += \
"Testboard_HAL_drivers\source\adc.obj" \
"Testboard_HAL_drivers\source\crc.obj" \
"Testboard_HAL_drivers\source\dabort.obj" \
"Testboard_HAL_drivers\source\ecap.obj" \
"Testboard_HAL_drivers\source\eqep.obj" \
"Testboard_HAL_drivers\source\errata_SSWF021_45.obj" \
"Testboard_HAL_drivers\source\esm.obj" \
"Testboard_HAL_drivers\source\etpwm.obj" \
"Testboard_HAL_drivers\source\gio.obj" \
"Testboard_HAL_drivers\source\het.obj" \
"Testboard_HAL_drivers\source\mibspi.obj" \
"Testboard_HAL_drivers\source\notification.obj" \
"Testboard_HAL_drivers\source\os_croutine.obj" \
"Testboard_HAL_drivers\source\os_event_groups.obj" \
"Testboard_HAL_drivers\source\os_heap.obj" \
"Testboard_HAL_drivers\source\os_list.obj" \
"Testboard_HAL_drivers\source\os_mpu_wrappers.obj" \
"Testboard_HAL_drivers\source\os_port.obj" \
"Testboard_HAL_drivers\source\os_portasm.obj" \
"Testboard_HAL_drivers\source\os_queue.obj" \
"Testboard_HAL_drivers\source\os_tasks.obj" \
"Testboard_HAL_drivers\source\os_timer.obj" \
"Testboard_HAL_drivers\source\pinmux.obj" \
"Testboard_HAL_drivers\source\rti.obj" \
"Testboard_HAL_drivers\source\sci.obj" \
"Testboard_HAL_drivers\source\sys_core.obj" \
"Testboard_HAL_drivers\source\sys_dma.obj" \
"Testboard_HAL_drivers\source\sys_intvecs.obj" \
"Testboard_HAL_drivers\source\sys_mpu.obj" \
"Testboard_HAL_drivers\source\sys_pcr.obj" \
"Testboard_HAL_drivers\source\sys_phantom.obj" \
"Testboard_HAL_drivers\source\sys_pmm.obj" \
"Testboard_HAL_drivers\source\sys_pmu.obj" \
"Testboard_HAL_drivers\source\sys_selftest.obj" \
"Testboard_HAL_drivers\source\sys_startup.obj" \
"Testboard_HAL_drivers\source\sys_vim.obj" \
"Testboard_HAL_drivers\source\system.obj" 

C_DEPS__QUOTED += \
"Testboard_HAL_drivers\source\adc.d" \
"Testboard_HAL_drivers\source\crc.d" \
"Testboard_HAL_drivers\source\ecap.d" \
"Testboard_HAL_drivers\source\eqep.d" \
"Testboard_HAL_drivers\source\errata_SSWF021_45.d" \
"Testboard_HAL_drivers\source\esm.d" \
"Testboard_HAL_drivers\source\etpwm.d" \
"Testboard_HAL_drivers\source\gio.d" \
"Testboard_HAL_drivers\source\het.d" \
"Testboard_HAL_drivers\source\mibspi.d" \
"Testboard_HAL_drivers\source\notification.d" \
"Testboard_HAL_drivers\source\os_croutine.d" \
"Testboard_HAL_drivers\source\os_event_groups.d" \
"Testboard_HAL_drivers\source\os_heap.d" \
"Testboard_HAL_drivers\source\os_list.d" \
"Testboard_HAL_drivers\source\os_mpu_wrappers.d" \
"Testboard_HAL_drivers\source\os_port.d" \
"Testboard_HAL_drivers\source\os_queue.d" \
"Testboard_HAL_drivers\source\os_tasks.d" \
"Testboard_HAL_drivers\source\os_timer.d" \
"Testboard_HAL_drivers\source\pinmux.d" \
"Testboard_HAL_drivers\source\rti.d" \
"Testboard_HAL_drivers\source\sci.d" \
"Testboard_HAL_drivers\source\sys_dma.d" \
"Testboard_HAL_drivers\source\sys_pcr.d" \
"Testboard_HAL_drivers\source\sys_phantom.d" \
"Testboard_HAL_drivers\source\sys_pmm.d" \
"Testboard_HAL_drivers\source\sys_selftest.d" \
"Testboard_HAL_drivers\source\sys_startup.d" \
"Testboard_HAL_drivers\source\sys_vim.d" \
"Testboard_HAL_drivers\source\system.d" 

ASM_DEPS__QUOTED += \
"Testboard_HAL_drivers\source\dabort.d" \
"Testboard_HAL_drivers\source\os_portasm.d" \
"Testboard_HAL_drivers\source\sys_core.d" \
"Testboard_HAL_drivers\source\sys_intvecs.d" \
"Testboard_HAL_drivers\source\sys_mpu.d" \
"Testboard_HAL_drivers\source\sys_pmu.d" 

C_SRCS__QUOTED += \
"../Testboard_HAL_drivers/source/adc.c" \
"../Testboard_HAL_drivers/source/crc.c" \
"../Testboard_HAL_drivers/source/ecap.c" \
"../Testboard_HAL_drivers/source/eqep.c" \
"../Testboard_HAL_drivers/source/errata_SSWF021_45.c" \
"../Testboard_HAL_drivers/source/esm.c" \
"../Testboard_HAL_drivers/source/etpwm.c" \
"../Testboard_HAL_drivers/source/gio.c" \
"../Testboard_HAL_drivers/source/het.c" \
"../Testboard_HAL_drivers/source/mibspi.c" \
"../Testboard_HAL_drivers/source/notification.c" \
"../Testboard_HAL_drivers/source/os_croutine.c" \
"../Testboard_HAL_drivers/source/os_event_groups.c" \
"../Testboard_HAL_drivers/source/os_heap.c" \
"../Testboard_HAL_drivers/source/os_list.c" \
"../Testboard_HAL_drivers/source/os_mpu_wrappers.c" \
"../Testboard_HAL_drivers/source/os_port.c" \
"../Testboard_HAL_drivers/source/os_queue.c" \
"../Testboard_HAL_drivers/source/os_tasks.c" \
"../Testboard_HAL_drivers/source/os_timer.c" \
"../Testboard_HAL_drivers/source/pinmux.c" \
"../Testboard_HAL_drivers/source/rti.c" \
"../Testboard_HAL_drivers/source/sci.c" \
"../Testboard_HAL_drivers/source/sys_dma.c" \
"../Testboard_HAL_drivers/source/sys_pcr.c" \
"../Testboard_HAL_drivers/source/sys_phantom.c" \
"../Testboard_HAL_drivers/source/sys_pmm.c" \
"../Testboard_HAL_drivers/source/sys_selftest.c" \
"../Testboard_HAL_drivers/source/sys_startup.c" \
"../Testboard_HAL_drivers/source/sys_vim.c" \
"../Testboard_HAL_drivers/source/system.c" 

ASM_SRCS__QUOTED += \
"../Testboard_HAL_drivers/source/dabort.asm" \
"../Testboard_HAL_drivers/source/os_portasm.asm" \
"../Testboard_HAL_drivers/source/sys_core.asm" \
"../Testboard_HAL_drivers/source/sys_intvecs.asm" \
"../Testboard_HAL_drivers/source/sys_mpu.asm" \
"../Testboard_HAL_drivers/source/sys_pmu.asm" 


