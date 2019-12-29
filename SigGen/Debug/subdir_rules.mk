################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/Include" --include_path="D:/WorkSpace_CCSV62/SigGen/inc/csl" --include_path="D:/WorkSpace_CCSV62/SigGen/inc/dsp" --include_path="D:/WorkSpace_CCSV62/SigGen/BSL/inc" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sine.obj: ../sine.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/Include" --include_path="D:/WorkSpace_CCSV62/SigGen/inc/csl" --include_path="D:/WorkSpace_CCSV62/SigGen/inc/dsp" --include_path="D:/WorkSpace_CCSV62/SigGen/BSL/inc" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="sine.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

switch.obj: ../switch.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/Include" --include_path="D:/WorkSpace_CCSV62/SigGen/inc/csl" --include_path="D:/WorkSpace_CCSV62/SigGen/inc/dsp" --include_path="D:/WorkSpace_CCSV62/SigGen/BSL/inc" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="switch.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

wavecom.obj: ../wavecom.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/Include" --include_path="D:/WorkSpace_CCSV62/SigGen/inc/csl" --include_path="D:/WorkSpace_CCSV62/SigGen/inc/dsp" --include_path="D:/WorkSpace_CCSV62/SigGen/BSL/inc" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="wavecom.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


