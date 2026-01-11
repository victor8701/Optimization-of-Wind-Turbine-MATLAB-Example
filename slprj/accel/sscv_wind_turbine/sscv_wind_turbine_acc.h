#ifndef sscv_wind_turbine_acc_h_
#define sscv_wind_turbine_acc_h_
#ifndef sscv_wind_turbine_acc_COMMON_INCLUDES_
#define sscv_wind_turbine_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif
#include "sscv_wind_turbine_acc_types.h"
#include <stddef.h>
#include <string.h>
#include <float.h>
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "simstruc_types.h"
typedef struct { creal_T B_6_0_0 ; creal_T B_6_1_16 ; creal_T B_6_2_32 ;
creal_T B_6_3_48 ; creal_T B_6_4_64 ; creal_T B_6_5_80 ; real_T B_6_6_96 ;
real_T B_6_7_104 ; real_T B_6_8_112 ; real_T B_6_9_120 ; real_T B_6_10_128 ;
real_T B_6_11_136 ; real_T B_6_12_144 ; real_T B_6_13_152 ; real_T B_6_14_160
; real_T B_6_15_168 ; real_T B_6_16_176 ; real_T B_6_17_184 ; real_T
B_6_18_192 ; real_T B_6_19_200 ; real_T B_6_20_208 ; real_T B_6_21_216 ;
real_T B_6_22_224 ; real_T B_6_23_232 ; real_T B_6_24_240 ; real_T B_6_25_248
; real_T B_6_26_256 ; real_T B_6_27_264 ; real_T B_6_28_272 ; real_T
B_6_29_280 ; real_T B_6_30_288 ; real_T B_6_31_296 ; real_T B_6_32_304 ;
real_T B_6_33_312 ; real_T B_6_34_320 ; real_T B_6_35_328 ; real_T B_6_36_336
; real_T B_6_37_344 ; real_T B_6_38_352 ; real_T B_6_39_360 [ 4 ] ; real_T
B_6_43_392 ; real_T B_6_44_400 ; real_T B_6_45_408 ; real_T B_6_46_416 ;
real_T B_6_47_424 ; real_T B_6_48_432 ; real_T B_6_49_440 ; real_T B_6_50_448
; real_T B_6_51_456 ; real_T B_6_52_464 ; real_T B_6_53_472 [ 3 ] ; real_T
B_6_56_496 [ 3 ] ; real_T B_6_59_520 [ 4 ] ; real_T B_6_63_552 [ 4 ] ; real_T
B_6_67_584 [ 4 ] ; real_T B_6_71_616 [ 25 ] ; real_T B_6_96_816 [ 4 ] ;
real_T B_6_100_848 [ 4 ] ; real_T B_6_104_880 [ 4 ] ; real_T B_6_108_912 ;
real_T B_6_109_920 [ 4 ] ; real_T B_6_113_952 ; real_T B_6_114_960 ; real_T
B_6_115_968 ; real_T B_6_116_976 ; real_T B_6_117_984 ; real_T B_6_118_992 ;
real_T B_6_119_1000 [ 4 ] ; real_T B_6_123_1032 [ 47 ] ; real_T B_6_170_1408
[ 3 ] ; real_T B_6_173_1432 ; real_T B_6_174_1440 ; real_T B_6_175_1448 ;
real_T B_6_176_1456 ; real_T B_6_177_1464 ; real_T B_6_178_1472 ; real_T
B_6_179_1480 ; real_T B_6_180_1488 ; real_T B_6_181_1496 ; real_T
B_6_182_1504 ; real_T B_6_183_1512 ; real_T B_6_184_1520 ; real_T
B_6_185_1528 ; real_T B_6_186_1536 ; real_T B_6_187_1544 ; real_T
B_6_188_1552 ; real_T B_6_189_1560 ; real_T B_6_190_1568 ; real_T
B_6_191_1576 ; real_T B_6_192_1584 ; real_T B_6_193_1592 ; real_T
B_6_194_1600 ; real_T B_6_195_1608 ; real_T B_6_196_1616 ; real_T
B_6_197_1624 ; real_T B_6_198_1632 ; real_T B_6_199_1640 ; real_T
B_6_200_1648 ; real_T B_6_201_1656 ; real_T B_6_202_1664 ; real_T
B_6_203_1672 ; real_T B_6_204_1680 ; real_T B_6_205_1688 ; real_T
B_6_206_1696 ; real_T B_6_207_1704 ; real_T B_6_208_1712 ; real_T
B_6_209_1720 ; real_T B_6_210_1728 ; real_T B_6_211_1736 ; real_T
B_6_212_1744 ; real_T B_5_213_1752 ; real_T B_5_214_1760 ; real_T
B_5_215_1768 ; real_T B_5_216_1776 ; real_T B_3_217_1784 ; real_T
B_3_218_1792 ; real_T B_2_219_1800 ; real_T B_2_220_1808 ; real_T
B_2_221_1816 ; real_T B_2_222_1824 ; real_T B_2_223_1832 ; real_T
B_2_224_1840 ; real_T B_2_225_1848 ; real_T B_2_226_1856 ; real_T
B_2_227_1864 ; real_T B_2_228_1872 ; real_T B_2_229_1880 ; real_T
B_1_230_1888 ; real_T B_1_231_1896 ; real_T B_0_232_1904 ; real_T
B_0_233_1912 ; real_T B_0_234_1920 ; real_T B_0_235_1928 ; boolean_T
B_6_236_1936 ; boolean_T B_6_237_1937 ; boolean_T B_6_238_1938 ; boolean_T
B_6_239_1939 ; boolean_T B_6_240_1940 ; boolean_T B_6_241_1941 ; char_T
pad_B_6_241_1941 [ 2 ] ; } B_sscv_wind_turbine_T ; typedef struct { real_T
INPUT_1_1_1_Discrete_1347933324 [ 2 ] ; real_T INPUT_2_1_1_Discrete_402107996
[ 2 ] ; real_T INPUT_2_1_2_Discrete_2399076326 [ 2 ] ; real_T
INPUT_2_1_3_Discrete_4193898352 [ 2 ] ; real_T
INPUT_2_1_1_Discrete_2123895232 ; real_T INPUT_2_1_1_FirstOutput_2123895232 ;
real_T INPUT_1_1_1_Discrete_959998736 ; real_T
INPUT_1_1_1_FirstOutput_959998736 ; real_T INPUT_3_1_1_Discrete_1140340848 [
2 ] ; real_T INPUT_4_1_1_Discrete_4057523296 [ 2 ] ; real_T
STATE_1_Discrete_3393353915 [ 30 ] ; real_T PrevY ; real_T LastMajorTime ;
real_T STATE_1_Discrete ; real_T STATE_1_ZcValueStore ; real_T
OUTPUT_1_0_Discrete ; real_T OUTPUT_1_0_ZcValueStore ; real_T
STATE_1_ZcValueStore_i [ 17 ] ; real_T OUTPUT_1_0_Discrete_e ; real_T
OUTPUT_1_0_ZcValueStore_k ; real_T IC_FirstOutputTime ; real_T
TransportDelay_RWORK ; void * Results_PWORK [ 4 ] ; struct { void * AQHandles
; } TAQSigLogging_InsertedFor_From10_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_From11_at_outport_0_PWORK ; struct {
void * AQHandles ; } TAQSigLogging_InsertedFor_From12_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_From13_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_From14_at_outport_0_PWORK ; struct {
void * AQHandles ; } TAQSigLogging_InsertedFor_From15_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_From8_at_outport_0_PWORK ; void * STATE_1_Simulator
; void * STATE_1_SimData ; void * STATE_1_DiagMgr ; void * STATE_1_ZcLogger ;
void * STATE_1_TsInfo ; void * SINK_1_RtwLogger ; void * SINK_1_RtwLogBuffer
; void * SINK_1_RtwLogFcnManager ; void * SINK_1_InstRtwLogger ; void *
SINK_1_InstRtwLogBuffer ; void * OUTPUT_1_0_Simulator ; void *
OUTPUT_1_0_SimData ; void * OUTPUT_1_0_DiagMgr ; void * OUTPUT_1_0_ZcLogger ;
void * OUTPUT_1_0_TsInfo ; void * STATE_1_Simulator_d ; void *
STATE_1_SimData_n ; void * STATE_1_DiagMgr_e ; void * STATE_1_ZcLogger_d ;
void * STATE_1_TsInfo_n ; void * SINK_1_RtwLogger_n ; void *
SINK_1_RtwLogBuffer_j ; void * SINK_1_RtwLogFcnManager_p ; void *
SINK_1_InstRtwLogger_k ; void * SINK_1_InstRtwLogBuffer_d ; void *
OUTPUT_1_0_Simulator_k ; void * OUTPUT_1_0_SimData_c ; void *
OUTPUT_1_0_DiagMgr_h ; void * OUTPUT_1_0_ZcLogger_i ; void *
OUTPUT_1_0_TsInfo_j ; void * TransportDelay_PWORK [ 2 ] ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_MeasurementFilter_at_outport_0_PWORK
; void * RTP_1_RtpManager ; struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Add_at_outport_0_PWORK ; struct { void * AQHandles
; } TAQSigLogging_InsertedFor_DeratingPitch_at_outport_0_PWORK ; struct {
void * AQHandles ; } TAQSigLogging_InsertedFor_Gain_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Integrator_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_Sum_at_outport_0_PWORK ; int32_T
TurbineStateMachine_sysIdxToRun ; int32_T MPPTControl_sysIdxToRun ; int32_T
DeratingControl_sysIdxToRun ; int32_T TurbineState2_sysIdxToRun ; int32_T
TurbineState1_sysIdxToRun ; int32_T TurbineState0an3_sysIdxToRun ; int_T
STATE_1_Modes ; int_T OUTPUT_1_0_Modes ; int_T STATE_1_Modes_j [ 17 ] ; int_T
OUTPUT_1_0_Modes_l ; int_T TransportDelay_IWORK [ 5 ] ; int_T Step_MODE ;
int_T Saturation_MODE ; int_T Step_MODE_f ; int_T Saturation1_MODE ; int_T
Step_MODE_l ; int_T Saturation2_MODE ; int_T Saturation_MODE_e ; int_T
Saturation_MODE_a ; int_T Abs_MODE ; int_T Integrator_MODE ; int_T
Saturation_MODE_c ; int_T Abs_MODE_p ; int_T Saturation_MODE_cb ; int_T
Saturation1_MODE_l ; int_T Saturation_MODE_h ; int32_T STATE_1_MASS_MATRIX_PR
; int32_T STATE_1_MASS_MATRIX_PR_h ; int8_T Sqrt_DWORK1 ; int8_T
MPPTControl_SubsysRanBC ; int8_T DeratingControl_SubsysRanBC ; int8_T
TurbineState2_SubsysRanBC ; int8_T TurbineState1_SubsysRanBC ; int8_T
TurbineState0an3_SubsysRanBC ; uint8_T STATE_1_ZcSignalDir ; uint8_T
STATE_1_ZcStateStore ; uint8_T OUTPUT_1_0_ZcSignalDir ; uint8_T
OUTPUT_1_0_ZcStateStore ; uint8_T STATE_1_ZcSignalDir_m [ 17 ] ; uint8_T
STATE_1_ZcStateStore_f [ 17 ] ; uint8_T OUTPUT_1_0_ZcSignalDir_l ; uint8_T
OUTPUT_1_0_ZcStateStore_l ; boolean_T PrevLimited ; boolean_T Compare_Mode ;
boolean_T Compare_Mode_a ; boolean_T Compare_Mode_b ; boolean_T
Integrator_DWORK1 ; boolean_T STATE_1_FirstOutput ; boolean_T
OUTPUT_1_0_FirstOutput ; boolean_T STATE_1_FirstOutput_g ; boolean_T
OUTPUT_1_0_FirstOutput_l ; boolean_T Integrator_DWORK1_n ; boolean_T
RTP_1_SetParametersNeeded ; boolean_T Switch_Mode ; boolean_T
MPPTControl_MODE ; boolean_T TurbineState2_MODE ; boolean_T
TurbineState1_MODE ; boolean_T TurbineState0an3_MODE ; char_T
pad_TurbineState0an3_MODE [ 2 ] ; } DW_sscv_wind_turbine_T ; typedef struct {
real_T MeasurementFilter_CSTATE ; real_T MeasurementFilter_CSTATE_f ; real_T
TransferFcn1_CSTATE ; real_T MeasurementFilter_CSTATE_a ; real_T
TransferFcn_CSTATE ; real_T TransferFcn_CSTATE_l ; real_T
TransferFcn_CSTATE_i ; real_T Sensordynamics2_CSTATE ; real_T
Sensordynamics1_CSTATE ; real_T Integrator_CSTATE ; real_T
sscv_wind_turbineGrid_and_TransformerTransformerTwoWindingTransfow1_aphiorg [
24 ] ; real_T
sscv_wind_turbineSimulink_PS_Converter1outputFiltered_2379984884_0 ; real_T
sscv_wind_turbineSimulink_PS_ConverteroutputFiltered_3397113124_0 ; real_T
TransferFcn_CSTATE_k ; real_T TransferFcn2_CSTATE ; real_T
sscv_wind_turbineWind_TurbineRotor_Hubinertiaw [ 28 ] ; real_T
TransferFcn1_CSTATE_c ; real_T Integrator_CSTATE_i ; real_T
MeasurementFilter_CSTATE_d ; real_T Integrator_CSTATE_g ; real_T
TransferFcn_CSTATE_b ; real_T TransferFcn_CSTATE_io ; real_T
Controller_CSTATE ; real_T Integrator_CSTATE_b ; } X_sscv_wind_turbine_T ;
typedef int_T PeriodicIndX_sscv_wind_turbine_T [ 1 ] ; typedef real_T
PeriodicRngX_sscv_wind_turbine_T [ 2 ] ; typedef struct { real_T
MeasurementFilter_CSTATE ; real_T MeasurementFilter_CSTATE_f ; real_T
TransferFcn1_CSTATE ; real_T MeasurementFilter_CSTATE_a ; real_T
TransferFcn_CSTATE ; real_T TransferFcn_CSTATE_l ; real_T
TransferFcn_CSTATE_i ; real_T Sensordynamics2_CSTATE ; real_T
Sensordynamics1_CSTATE ; real_T Integrator_CSTATE ; real_T
sscv_wind_turbineGrid_and_TransformerTransformerTwoWindingTransfow1_aphiorg [
24 ] ; real_T
sscv_wind_turbineSimulink_PS_Converter1outputFiltered_2379984884_0 ; real_T
sscv_wind_turbineSimulink_PS_ConverteroutputFiltered_3397113124_0 ; real_T
TransferFcn_CSTATE_k ; real_T TransferFcn2_CSTATE ; real_T
sscv_wind_turbineWind_TurbineRotor_Hubinertiaw [ 28 ] ; real_T
TransferFcn1_CSTATE_c ; real_T Integrator_CSTATE_i ; real_T
MeasurementFilter_CSTATE_d ; real_T Integrator_CSTATE_g ; real_T
TransferFcn_CSTATE_b ; real_T TransferFcn_CSTATE_io ; real_T
Controller_CSTATE ; real_T Integrator_CSTATE_b ; } XDot_sscv_wind_turbine_T ;
typedef struct { boolean_T MeasurementFilter_CSTATE ; boolean_T
MeasurementFilter_CSTATE_f ; boolean_T TransferFcn1_CSTATE ; boolean_T
MeasurementFilter_CSTATE_a ; boolean_T TransferFcn_CSTATE ; boolean_T
TransferFcn_CSTATE_l ; boolean_T TransferFcn_CSTATE_i ; boolean_T
Sensordynamics2_CSTATE ; boolean_T Sensordynamics1_CSTATE ; boolean_T
Integrator_CSTATE ; boolean_T
sscv_wind_turbineGrid_and_TransformerTransformerTwoWindingTransfow1_aphiorg [
24 ] ; boolean_T
sscv_wind_turbineSimulink_PS_Converter1outputFiltered_2379984884_0 ;
boolean_T sscv_wind_turbineSimulink_PS_ConverteroutputFiltered_3397113124_0 ;
boolean_T TransferFcn_CSTATE_k ; boolean_T TransferFcn2_CSTATE ; boolean_T
sscv_wind_turbineWind_TurbineRotor_Hubinertiaw [ 28 ] ; boolean_T
TransferFcn1_CSTATE_c ; boolean_T Integrator_CSTATE_i ; boolean_T
MeasurementFilter_CSTATE_d ; boolean_T Integrator_CSTATE_g ; boolean_T
TransferFcn_CSTATE_b ; boolean_T TransferFcn_CSTATE_io ; boolean_T
Controller_CSTATE ; boolean_T Integrator_CSTATE_b ; }
XDis_sscv_wind_turbine_T ; typedef struct { real_T MeasurementFilter_CSTATE ;
real_T MeasurementFilter_CSTATE_f ; real_T TransferFcn1_CSTATE ; real_T
MeasurementFilter_CSTATE_a ; real_T TransferFcn_CSTATE ; real_T
TransferFcn_CSTATE_l ; real_T TransferFcn_CSTATE_i ; real_T
Sensordynamics2_CSTATE ; real_T Sensordynamics1_CSTATE ; real_T
Integrator_CSTATE ; real_T
sscv_wind_turbineGrid_and_TransformerTransformerTwoWindingTransfow1_aphiorg [
24 ] ; real_T
sscv_wind_turbineSimulink_PS_Converter1outputFiltered_2379984884_0 ; real_T
sscv_wind_turbineSimulink_PS_ConverteroutputFiltered_3397113124_0 ; real_T
TransferFcn_CSTATE_k ; real_T TransferFcn2_CSTATE ; real_T
sscv_wind_turbineWind_TurbineRotor_Hubinertiaw [ 28 ] ; real_T
TransferFcn1_CSTATE_c ; real_T Integrator_CSTATE_i ; real_T
MeasurementFilter_CSTATE_d ; real_T Integrator_CSTATE_g ; real_T
TransferFcn_CSTATE_b ; real_T TransferFcn_CSTATE_io ; real_T
Controller_CSTATE ; real_T Integrator_CSTATE_b ; }
CStateAbsTol_sscv_wind_turbine_T ; typedef struct { real_T
MeasurementFilter_CSTATE ; real_T MeasurementFilter_CSTATE_f ; real_T
TransferFcn1_CSTATE ; real_T MeasurementFilter_CSTATE_a ; real_T
TransferFcn_CSTATE ; real_T TransferFcn_CSTATE_l ; real_T
TransferFcn_CSTATE_i ; real_T Sensordynamics2_CSTATE ; real_T
Sensordynamics1_CSTATE ; real_T Integrator_CSTATE ; real_T
sscv_wind_turbineGrid_and_TransformerTransformerTwoWindingTransfow1_aphiorg [
24 ] ; real_T
sscv_wind_turbineSimulink_PS_Converter1outputFiltered_2379984884_0 ; real_T
sscv_wind_turbineSimulink_PS_ConverteroutputFiltered_3397113124_0 ; real_T
TransferFcn_CSTATE_k ; real_T TransferFcn2_CSTATE ; real_T
sscv_wind_turbineWind_TurbineRotor_Hubinertiaw [ 28 ] ; real_T
TransferFcn1_CSTATE_c ; real_T Integrator_CSTATE_i ; real_T
MeasurementFilter_CSTATE_d ; real_T Integrator_CSTATE_g ; real_T
TransferFcn_CSTATE_b ; real_T TransferFcn_CSTATE_io ; real_T
Controller_CSTATE ; real_T Integrator_CSTATE_b ; }
CXPtMin_sscv_wind_turbine_T ; typedef struct { real_T
MeasurementFilter_CSTATE ; real_T MeasurementFilter_CSTATE_f ; real_T
TransferFcn1_CSTATE ; real_T MeasurementFilter_CSTATE_a ; real_T
TransferFcn_CSTATE ; real_T TransferFcn_CSTATE_l ; real_T
TransferFcn_CSTATE_i ; real_T Sensordynamics2_CSTATE ; real_T
Sensordynamics1_CSTATE ; real_T Integrator_CSTATE ; real_T
sscv_wind_turbineGrid_and_TransformerTransformerTwoWindingTransfow1_aphiorg [
24 ] ; real_T
sscv_wind_turbineSimulink_PS_Converter1outputFiltered_2379984884_0 ; real_T
sscv_wind_turbineSimulink_PS_ConverteroutputFiltered_3397113124_0 ; real_T
TransferFcn_CSTATE_k ; real_T TransferFcn2_CSTATE ; real_T
sscv_wind_turbineWind_TurbineRotor_Hubinertiaw [ 28 ] ; real_T
TransferFcn1_CSTATE_c ; real_T Integrator_CSTATE_i ; real_T
MeasurementFilter_CSTATE_d ; real_T Integrator_CSTATE_g ; real_T
TransferFcn_CSTATE_b ; real_T TransferFcn_CSTATE_io ; real_T
Controller_CSTATE ; real_T Integrator_CSTATE_b ; }
CXPtMax_sscv_wind_turbine_T ; typedef struct { real_T Compare_RelopInput_ZC ;
real_T Compare_RelopInput_ZC_b ; real_T Step_StepTime_ZC ; real_T
Saturation_UprLim_ZC ; real_T Saturation_LwrLim_ZC ; real_T
Step_StepTime_ZC_e ; real_T Saturation1_UprLim_ZC ; real_T
Saturation1_LwrLim_ZC ; real_T Step_StepTime_ZC_j ; real_T
Saturation2_UprLim_ZC ; real_T Saturation2_LwrLim_ZC ; real_T
Saturation_UprLim_ZC_n ; real_T Saturation_LwrLim_ZC_g ; real_T
Compare_RelopInput_ZC_a ; real_T Integrator_Reset_ZC ; real_T
STATE_1_Wind_TurbineNacelleLumped_GeneratorSPST_Switch_Three_Phasezc_1_ZC ;
real_T Saturation_UprLim_ZC_i ; real_T Saturation_LwrLim_ZC_j ; real_T
Abs_AbsZc_ZC ; real_T
STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchzc_1_ZC ; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_2_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_3_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_4_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_5_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_6_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_7_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_8_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_9_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_10_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_11_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_12_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_13_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_14_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_15_ZC
; real_T
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_16_ZC
; real_T
STATE_1_Wind_TurbineNacelleLumped_GeneratorVariable_Rotational_Damperzc_1_ZC
; real_T Integrator_Reset_ZC_a ; real_T Integrator_xUpperSaturation_ZC ;
real_T Integrator_xLowerSaturation_ZC ; real_T Integrator_InputPortSignal_ZC
; real_T Saturation_UprLim_ZC_l ; real_T Saturation_LwrLim_ZC_d ; real_T
Abs_AbsZc_ZC_c ; real_T Saturation_UprLim_ZC_iw ; real_T
Saturation_LwrLim_ZC_k ; real_T Saturation1_UprLim_ZC_d ; real_T
Saturation1_LwrLim_ZC_m ; real_T Saturation_UprLim_ZC_m ; real_T
Saturation_LwrLim_ZC_gi ; real_T Switch_SwitchCond_ZC ; }
ZCV_sscv_wind_turbine_T ; typedef struct { ZCSigState Compare_RelopInput_ZCE
; ZCSigState Compare_RelopInput_ZCE_n ; ZCSigState Step_StepTime_ZCE ;
ZCSigState Saturation_UprLim_ZCE ; ZCSigState Saturation_LwrLim_ZCE ;
ZCSigState Step_StepTime_ZCE_f ; ZCSigState Saturation1_UprLim_ZCE ;
ZCSigState Saturation1_LwrLim_ZCE ; ZCSigState Step_StepTime_ZCE_o ;
ZCSigState Saturation2_UprLim_ZCE ; ZCSigState Saturation2_LwrLim_ZCE ;
ZCSigState Saturation_UprLim_ZCE_g ; ZCSigState Saturation_LwrLim_ZCE_o ;
ZCSigState Compare_RelopInput_ZCE_g ; ZCSigState Integrator_Reset_ZCE ;
ZCSigState
STATE_1_Wind_TurbineNacelleLumped_GeneratorSPST_Switch_Three_Phasezc_1_ZCE ;
ZCSigState Saturation_UprLim_ZCE_e ; ZCSigState Saturation_LwrLim_ZCE_l ;
ZCSigState Abs_AbsZc_ZCE ; ZCSigState
STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchzc_1_ZCE ; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_2_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_3_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_4_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_5_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_6_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_7_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_8_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_9_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_10_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_11_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_12_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_13_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_14_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_15_ZCE
; ZCSigState
 STATE_1_Wind_TurbineNacelleBrakesDisk_Friction_Clutchfundamental_clutchclutchzc_16_ZCE
; ZCSigState
STATE_1_Wind_TurbineNacelleLumped_GeneratorVariable_Rotational_Damperzc_1_ZCE
; ZCSigState Integrator_Reset_ZCE_o ; ZCSigState
Integrator_xUpperSaturation_ZCE ; ZCSigState Integrator_xLowerSaturation_ZCE
; ZCSigState Integrator_InputPortSignal_ZCE ; ZCSigState
Saturation_UprLim_ZCE_j ; ZCSigState Saturation_LwrLim_ZCE_lr ; ZCSigState
Abs_AbsZc_ZCE_p ; ZCSigState Saturation_UprLim_ZCE_n ; ZCSigState
Saturation_LwrLim_ZCE_n ; ZCSigState Saturation1_UprLim_ZCE_l ; ZCSigState
Saturation1_LwrLim_ZCE_i ; ZCSigState Saturation_UprLim_ZCE_b ; ZCSigState
Saturation_LwrLim_ZCE_h ; ZCSigState Switch_SwitchCond_ZCE ; }
PrevZCX_sscv_wind_turbine_T ; typedef struct { int_T ir [ 57 ] ; int_T jc [
75 ] ; real_T pr [ 57 ] ; } MassMatrix_sscv_wind_turbine_T ; typedef struct {
const real_T B_6_262_2096 ; } ConstB_sscv_wind_turbine_T ;
#define sscv_wind_turbine_rtC(S) ((ConstB_sscv_wind_turbine_T *) _ssGetConstBlockIO(S))
struct P_sscv_wind_turbine_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T
P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T
P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ;
real_T P_15 [ 9 ] ; real_T P_16 [ 9 ] ; real_T P_17 ; real_T P_18 ; real_T
P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ;
real_T P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 [ 9 ] ;
real_T P_30 [ 9 ] ; real_T P_31 ; real_T P_32 [ 9 ] ; real_T P_33 [ 9 ] ;
real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T P_37 ; real_T P_38 ; real_T
P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ;
real_T P_45 ; real_T P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T
P_50 ; real_T P_51 ; real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 ;
real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T
P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ;
real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T
P_72 ; real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ;
real_T P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T
P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ;
real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ; real_T
P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T P_99 ;
real_T P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T P_104 ;
real_T P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T P_109 ;
real_T P_110 ; real_T P_111 ; real_T P_112 ; real_T P_113 ; real_T P_114 ;
real_T P_115 ; real_T P_116 ; real_T P_117 ; real_T P_118 ; real_T P_119 ;
real_T P_120 ; real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ;
real_T P_125 ; real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ;
real_T P_130 ; real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ;
real_T P_135 ; real_T P_136 ; } ; extern P_sscv_wind_turbine_T
sscv_wind_turbine_rtDefaultP ; extern const ConstB_sscv_wind_turbine_T
sscv_wind_turbine_rtInvariant ;
#endif
