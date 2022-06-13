################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
phantom_drivers/vcu/source/%.obj: ../phantom_drivers/vcu/source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 -me --include_path="C:/Users/Rafael/OneDrive - Simon Fraser University (1sfu)/Documents/TestBoardFirmware/TestBoardFirmware/Testboard_HAL_drivers/include" --include_path="C:/Users/Rafael/OneDrive - Simon Fraser University (1sfu)/Documents/TestBoardFirmware/TestBoardFirmware/phantom_drivers/bms/include" --include_path="C:/Users/Rafael/OneDrive - Simon Fraser University (1sfu)/Documents/TestBoardFirmware/TestBoardFirmware/phantom_drivers/common/include" --include_path="C:/Users/Rafael/OneDrive - Simon Fraser University (1sfu)/Documents/TestBoardFirmware/TestBoardFirmware/phantom_drivers/vcu/include" --include_path="C:/Users/Rafael/OneDrive - Simon Fraser University (1sfu)/Documents/TestBoardFirmware/TestBoardFirmware" --include_path="C:/Users/Rafael/OneDrive - Simon Fraser University (1sfu)/Documents/TestBoardFirmware/TestBoardFirmware/third_party/tiny-json" --include_path="C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" -g --diag_suppress=190 --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="phantom_drivers/vcu/source/$(basename $(<F)).d_raw" --obj_directory="phantom_drivers/vcu/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


