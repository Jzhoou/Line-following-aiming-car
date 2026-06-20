################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/18709/workspace_ccstheia/pid2/BSP/MPU6050" -I"C:/Users/18709/workspace_ccstheia/pid2/BSP/MPU6050/DMP" -I"C:/Users/18709/workspace_ccstheia/pid2/CONTROL" -I"C:/Users/18709/workspace_ccstheia/pid2/HARDWARE" -I"C:/Users/18709/workspace_ccstheia/pid2" -I"C:/Users/18709/workspace_ccstheia/pid2/Debug" -I"D:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1314856383: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/ti/ccs2020/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "C:/Users/18709/workspace_ccstheia/pid2/empty.syscfg" -o "." -s "D:/ti/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1314856383 ../empty.syscfg
device.opt: build-1314856383
device.cmd.genlibs: build-1314856383
ti_msp_dl_config.c: build-1314856383
ti_msp_dl_config.h: build-1314856383
Event.dot: build-1314856383

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/18709/workspace_ccstheia/pid2/BSP/MPU6050" -I"C:/Users/18709/workspace_ccstheia/pid2/BSP/MPU6050/DMP" -I"C:/Users/18709/workspace_ccstheia/pid2/CONTROL" -I"C:/Users/18709/workspace_ccstheia/pid2/HARDWARE" -I"C:/Users/18709/workspace_ccstheia/pid2" -I"C:/Users/18709/workspace_ccstheia/pid2/Debug" -I"D:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: D:/ti/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/18709/workspace_ccstheia/pid2/BSP/MPU6050" -I"C:/Users/18709/workspace_ccstheia/pid2/BSP/MPU6050/DMP" -I"C:/Users/18709/workspace_ccstheia/pid2/CONTROL" -I"C:/Users/18709/workspace_ccstheia/pid2/HARDWARE" -I"C:/Users/18709/workspace_ccstheia/pid2" -I"C:/Users/18709/workspace_ccstheia/pid2/Debug" -I"D:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


