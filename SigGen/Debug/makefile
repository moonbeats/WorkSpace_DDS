################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/c5500_4.4.1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./sine.obj" \
"./switch.obj" \
"./wavecom.obj" \
"./BSL/src/aic3204_loop_linein.obj" \
"./BSL/src/aic3204_test.obj" \
"./BSL/src/ezdsp5535.obj" \
"./BSL/src/ezdsp5535_gpio.obj" \
"./BSL/src/ezdsp5535_i2c.obj" \
"./BSL/src/ezdsp5535_i2s.obj" \
"./BSL/src/ezdsp5535_lcd.obj" \
"./BSL/src/ezdsp5535_led.obj" \
"./BSL/src/ezdsp5535_sar.obj" \
"./BSL/src/ezdsp5535_sdcard.obj" \
"./BSL/src/ezdsp5535_spiflash.obj" \
"./BSL/src/ezdsp5535_uart.obj" \
"../lnkx.cmd" \
"../lib/55xdspx_r3.lib" \
"../lib/C55XXCSL_LP.lib" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"D:/WorkSpace_CCSV62/SigGen/lib/C55XXCSL_LP.lib" \
-l"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib/rts55x.lib" \
-l"D:/WorkSpace_CCSV62/SigGen/lib/55xdspx_r3.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include BSL/src/subdir_vars.mk
-include lib/subdir_vars.mk
-include subdir_rules.mk
-include BSL/src/subdir_rules.mk
-include lib/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
SigGen.out \

EXE_OUTPUTS__QUOTED += \
"SigGen.out" \

BIN_OUTPUTS += \
SigGen.hex \

BIN_OUTPUTS__QUOTED += \
"SigGen.hex" \


# All Target
all: SigGen.out

# Tool invocations
SigGen.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 -z -m"SigGen.map" --stack_size=0x200 --heap_size=0x400 -i"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --reread_libs --display_error_number --warn_sections --xml_link_info="SigGen_linkInfo.xml" --rom_model --sys_stacksize=0x200 -o "SigGen.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

SigGen.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C5500 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/hex55"  -o "SigGen.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "main.d" "switch.d" "wavecom.d" "BSL\src\aic3204_loop_linein.d" "BSL\src\aic3204_test.d" "BSL\src\ezdsp5535.d" "BSL\src\ezdsp5535_gpio.d" "BSL\src\ezdsp5535_i2c.d" "BSL\src\ezdsp5535_i2s.d" "BSL\src\ezdsp5535_lcd.d" "BSL\src\ezdsp5535_led.d" "BSL\src\ezdsp5535_sar.d" "BSL\src\ezdsp5535_sdcard.d" "BSL\src\ezdsp5535_spiflash.d" "BSL\src\ezdsp5535_uart.d" 
	-$(RM) "main.obj" "sine.obj" "switch.obj" "wavecom.obj" "BSL\src\aic3204_loop_linein.obj" "BSL\src\aic3204_test.obj" "BSL\src\ezdsp5535.obj" "BSL\src\ezdsp5535_gpio.obj" "BSL\src\ezdsp5535_i2c.obj" "BSL\src\ezdsp5535_i2s.obj" "BSL\src\ezdsp5535_lcd.obj" "BSL\src\ezdsp5535_led.obj" "BSL\src\ezdsp5535_sar.obj" "BSL\src\ezdsp5535_sdcard.obj" "BSL\src\ezdsp5535_spiflash.obj" "BSL\src\ezdsp5535_uart.obj" 
	-$(RM) "sine.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

