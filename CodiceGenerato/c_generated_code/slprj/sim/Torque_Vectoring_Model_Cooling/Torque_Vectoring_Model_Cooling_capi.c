#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Torque_Vectoring_Model_Cooling_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 48
#endif
#ifndef SS_INT64
#define SS_INT64 49
#endif
#else
#include "builtin_typeid_types.h"
#include "Torque_Vectoring_Model_Cooling.h"
#include "Torque_Vectoring_Model_Cooling_capi.h"
#include "Torque_Vectoring_Model_Cooling_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_SignalHierLoggingInfo rtSigHierLoggingInfo [ ] = { { ""
, 7 , 0 } , { "t_engine_fl" , 0 , - 1 } , { "t_engine_fr" , 0 , - 1 } , {
"t_engine_rl" , 0 , - 1 } , { "t_engine_rr" , 0 , - 1 } , { "t_igbt" , 0 , -
1 } , { "t_plate" , 0 , - 1 } , { "voltage" , 0 , - 1 } , { "" , 3 , 7 } , {
"Torque_Distribution" , 2 , 10 } , { "MPC" , 8 , 12 } , { "States" , 6 , 20 }
, { "xhat" , 0 , - 1 } , { "EKF" , 0 , - 1 } , { "r_meas" , 0 , - 1 } , {
"vy_meas" , 0 , - 1 } , { "vx_meas" , 0 , - 1 } , { "x" , 3 , 26 } , { "vx" ,
0 , - 1 } , { "vy" , 0 , - 1 } , { "yaw_rate" , 0 , - 1 } , {
"Output_Vector_Reference" , 2 , 29 } , { "vx_ref" , 0 , - 1 } , { "vy_ref" ,
0 , - 1 } , { "Control_Constraints" , 4 , 31 } , {
"Load_Transfer_Calculation" , 4 , 35 } , { "fz_fl" , 0 , - 1 } , { "fz_fr" ,
0 , - 1 } , { "fz_rl" , 0 , - 1 } , { "fz_rr" , 0 , - 1 } , {
"Slip_Angle_Calculation" , 4 , 39 } , { "slip_angle_FL" , 0 , - 1 } , {
"slip_angle_FR" , 0 , - 1 } , { "slip_angle_RL" , 0 , - 1 } , {
"slip_angle_RR" , 0 , - 1 } , { "ubu" , 0 , - 1 } , { "lbu" , 0 , - 1 } , {
"Polytropic_Constraints" , 3 , 43 } , { "Accelerator_Mapping" , 1 , 46 } , {
"acc_map" , 0 , - 1 } , { "ug" , 0 , - 1 } , { "lg" , 0 , - 1 } , { "control"
, 0 , - 1 } , { "Solver" , 5 , 47 } , { "OCP_status" , 0 , - 1 } , {
"KKT_Residual" , 0 , - 1 } , { "X1" , 0 , - 1 } , { "CPU_time" , 0 , - 1 } ,
{ "SQP_iter" , 0 , - 1 } , { "Torque" , 4 , 52 } , { "t_rr" , 0 , - 1 } , {
"t_rl" , 0 , - 1 } , { "t_fr" , 0 , - 1 } , { "t_fl" , 0 , - 1 } , { "Faults"
, 1 , 56 } , { "g" , 0 , - 1 } , { "Reference" , 1 , 57 } , {
"yaw_rate_desired" , 0 , - 1 } , { "Input_Signals" , 4 , 58 } , { "hv" , 5 ,
62 } , { "display_overload_inverter" , 0 , - 1 } , { "display_overload_motor"
, 0 , - 1 } , { "cooling" , 7 , 67 } , { "Pmax_regen" , 0 , - 1 } , {
"Pmax_tractive" , 0 , - 1 } , { "car_settings" , 2 , 74 } , { "rtd" , 0 , - 1
} , { "torque_map" , 0 , - 1 } , { "dynamics_data" , 7 , 76 } , { "ax" , 0 ,
- 1 } , { "ay" , 0 , - 1 } , { "brake_torque" , 0 , - 1 } , { "omega_wheels"
, 0 , - 1 } , { "driver_inputs" , 3 , 83 } , { "throttle" , 0 , - 1 } , {
"brake" , 0 , - 1 } , { "steering" , 0 , - 1 } , { "Slip_Control" , 1 , 86 }
, { "Slip_Ratios" , 4 , 87 } , { "slip_ratio_fl" , 0 , - 1 } , {
"slip_ratio_fr" , 0 , - 1 } , { "slip_ratio_rl" , 0 , - 1 } , {
"slip_ratio_rr" , 0 , - 1 } } ; static const uint_T rtSigHierLoggingChildIdxs
[ ] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 9 , 58 , 77 , 10 , 56 , 11 , 21 , 24 , 37
, 42 , 43 , 49 , 54 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 22 , 23 ,
25 , 30 , 35 , 36 , 26 , 27 , 28 , 29 , 31 , 32 , 33 , 34 , 38 , 40 , 41 , 39
, 44 , 45 , 46 , 47 , 48 , 50 , 51 , 52 , 53 , 55 , 57 , 59 , 65 , 68 , 73 ,
60 , 61 , 62 , 63 , 64 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 66 , 67 , 18 , 19 , 69 ,
70 , 20 , 71 , 72 , 74 , 75 , 76 , 78 , 79 , 80 , 81 , 82 } ; static
rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0
, 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , 0 ,
TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Transfer Fcn" ) ,
TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0
} , { 1 , 1 , TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Transfer Fcn1"
) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1
, 0 } , { 2 , 5 , TARGET_STRING (
"Torque_Vectoring_Model_Cooling/Transfer Fcn2" ) , TARGET_STRING ( "" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 3 , 2 ,
TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Transfer Fcn4" ) ,
TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0
} , { 4 , 3 , TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Transfer Fcn5"
) , TARGET_STRING ( "" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1
, 0 } , { 5 , 4 , TARGET_STRING (
"Torque_Vectoring_Model_Cooling/Transfer Fcn6" ) , TARGET_STRING ( "" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 6 , - 1 ,
TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Unit Delay" ) , TARGET_STRING
( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 1 , 0 , - 1 , 0 } , { 7 , - 1 ,
TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Unit Delay1" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 } , { 8 , - 1
, TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Unit Delay1" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 } , { 9 , - 1
, TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Unit Delay1" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 2 } , { 10 , -
1 , TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Unit Delay1" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 3 } , { 11 , -
1 , TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Unit Delay1" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 4 } , { 12 , -
1 , TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Unit Delay1" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 5 } , { 13 , -
1 , TARGET_STRING ( "Torque_Vectoring_Model_Cooling/Unit Delay1" ) ,
TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 6 } , { 14 , -
1 , TARGET_STRING (
 "Torque_Vectoring_Model_Cooling/Torque_Vectoring/Torque Distribution/MPC/Control constraints/lbu_dot/Unit Delay1"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 2 , 0 , - 1 , 0 } , {
15 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model_Cooling/Torque_Vectoring/Torque Distribution/MPC/Faults detection/Subsystem2/Discrete FIR Filter"
) , TARGET_STRING ( "states" ) , "" , 0 , 0 , 1 , 0 , 2 , 0 , - 1 , 0 } , {
16 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model_Cooling/Torque_Vectoring/Torque Distribution/MPC/Faults detection/Subsystem2/Discrete FIR Filter"
) , TARGET_STRING ( "circBuf" ) , "" , 0 , 1 , 0 , 0 , 2 , 0 , - 1 , 0 } , {
17 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model_Cooling/Torque_Vectoring/Torque Distribution/MPC/Control constraints/Low YRD/Mz = 0 Bound logic/Discrete FIR Filter"
) , TARGET_STRING ( "states" ) , "" , 0 , 2 , 2 , 0 , 2 , 0 , - 1 , 0 } , {
18 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model_Cooling/Torque_Vectoring/Torque Distribution/MPC/Control constraints/Low YRD/Mz = 0 Bound logic/Discrete FIR Filter"
) , TARGET_STRING ( "circBuf" ) , "" , 0 , 1 , 0 , 0 , 2 , 0 , - 1 , 0 } , {
19 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model_Cooling/Torque_Vectoring/Torque Distribution/MPC/Weights generation/Subsystem1/Steer Activation/Delay"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 3 , 3 , 0 , 2 , 0 , - 1 , 0 } , {
20 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model_Cooling/Torque_Vectoring/Torque Distribution/MPC/Weights generation/Subsystem1/Steer Activation/First Activation/Unit Delay1"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 3 , 0 , 0 , 2 , 0 , - 1 , 0 } , {
21 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model_Cooling/Torque_Vectoring/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter\n(Discrete or Continuous)/Integrator\n(Discrete or Continuous)/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 2 , 0 , - 1 , 0 } , { 0
, - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } }
; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 5 , 2 , 3 , 4 , 3 , 4 ,
5 , 6 , 7 , 8 , 9 , 10 , 12 , 13 , 57 , 58 , 56 , 60 , 59 , 11 } ;
#ifndef HOST_CAPI_BUILD
static void Torque_Vectoring_Model_Cooling_InitializeDataAddr ( void *
dataAddr [ ] , mgp55fs13f * localDW , lietroj0em * localX ) { dataAddr [ 0 ]
= ( void * ) ( & localX -> inywxj3phd ) ; dataAddr [ 1 ] = ( void * ) ( &
localX -> o0bszejbom ) ; dataAddr [ 2 ] = ( void * ) ( & localX -> dfm0kp31sv
) ; dataAddr [ 3 ] = ( void * ) ( & localX -> e4b4ty00oh ) ; dataAddr [ 4 ] =
( void * ) ( & localX -> izf2sqtdun ) ; dataAddr [ 5 ] = ( void * ) ( &
localX -> czus4khhe5 ) ; dataAddr [ 6 ] = ( void * ) ( & localDW ->
cekljt2ymr [ 0 ] ) ; dataAddr [ 7 ] = ( void * ) ( & localDW -> pdxgxplqmn )
; dataAddr [ 8 ] = ( void * ) ( & localDW -> n1da0wcaf3 ) ; dataAddr [ 9 ] =
( void * ) ( & localDW -> gwxz5m5c00 ) ; dataAddr [ 10 ] = ( void * ) ( &
localDW -> nx2hykgwlx ) ; dataAddr [ 11 ] = ( void * ) ( & localDW ->
krjzmknqx5 ) ; dataAddr [ 12 ] = ( void * ) ( & localDW -> gvyx1brndr ) ;
dataAddr [ 13 ] = ( void * ) ( & localDW -> bgdtgcb4oy ) ; dataAddr [ 14 ] =
( void * ) ( & localDW -> hajatyzjx5 ) ; dataAddr [ 15 ] = ( void * ) ( &
localDW -> ejjut2mdfk [ 0 ] ) ; dataAddr [ 16 ] = ( void * ) ( & localDW ->
i1l0bqw5lx ) ; dataAddr [ 17 ] = ( void * ) ( & localDW -> dgsobaf5wq [ 0 ] )
; dataAddr [ 18 ] = ( void * ) ( & localDW -> eivhquhkdw ) ; dataAddr [ 19 ]
= ( void * ) ( & localDW -> o4w5h0xslh [ 0 ] ) ; dataAddr [ 20 ] = ( void * )
( & localDW -> gfjyfh03up ) ; dataAddr [ 21 ] = ( void * ) ( & localDW ->
ae3zmggup2 [ 0 ] ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void Torque_Vectoring_Model_Cooling_InitializeVarDimsAddr ( int32_T *
vardimsAddr [ ] ) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void Torque_Vectoring_Model_Cooling_InitializeLoggingFunctions (
RTWLoggingFcnPtr loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ;
loggingPtrs [ 1 ] = ( NULL ) ; loggingPtrs [ 2 ] = ( NULL ) ; loggingPtrs [ 3
] = ( NULL ) ; loggingPtrs [ 4 ] = ( NULL ) ; loggingPtrs [ 5 ] = ( NULL ) ;
loggingPtrs [ 6 ] = ( NULL ) ; loggingPtrs [ 7 ] = ( NULL ) ; loggingPtrs [ 8
] = ( NULL ) ; loggingPtrs [ 9 ] = ( NULL ) ; loggingPtrs [ 10 ] = ( NULL ) ;
loggingPtrs [ 11 ] = ( NULL ) ; loggingPtrs [ 12 ] = ( NULL ) ; loggingPtrs [
13 ] = ( NULL ) ; loggingPtrs [ 14 ] = ( NULL ) ; loggingPtrs [ 15 ] = ( NULL
) ; loggingPtrs [ 16 ] = ( NULL ) ; loggingPtrs [ 17 ] = ( NULL ) ;
loggingPtrs [ 18 ] = ( NULL ) ; loggingPtrs [ 19 ] = ( NULL ) ; loggingPtrs [
20 ] = ( NULL ) ; loggingPtrs [ 21 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "int" , "int32_T" , 0 , 0 , sizeof ( int32_T ) , ( uint8_T ) SS_INT32 , 0 ,
0 , 0 } , { "short" , "int16_T" , 0 , 0 , sizeof ( int16_T ) , ( uint8_T )
SS_INT16 , 0 , 0 , 0 } , { "unsigned char" , "boolean_T" , 0 , 0 , sizeof (
boolean_T ) , ( uint8_T ) SS_BOOLEAN , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } } ; static
uint_T rtDimensionArray [ ] = { 1 , 1 , 4 , 1 , 9 , 1 , 5 , 1 } ; static
const real_T rtcapiStoredFloats [ ] = { 0.0 , 0.001 , 0.02 } ; static
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 1 , ( uint8_T ) 0
} , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 2 , ( uint8_T ) 0 } } ; static int_T
rtContextSystems [ 35 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ]
= { { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo
mmiStaticInfoLogging = { 35 , rtContextSystems , loggingMetaInfo , 0 , ( NULL
) , { 83 , rtSigHierLoggingInfo , rtSigHierLoggingChildIdxs } , 0 , ( NULL )
} ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 0
, ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockStates , 22 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 2906543427U
, 3431695052U , 150190706U , 4209866224U } , & mmiStaticInfoLogging , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo *
Torque_Vectoring_Model_Cooling_GetCAPIStaticMap ( void ) { return & mmiStatic
; }
#ifndef HOST_CAPI_BUILD
static void Torque_Vectoring_Model_Cooling_InitializeSystemRan ( lmmo4anm52 *
const m0dkyunhwk , sysRanDType * systemRan [ ] , mgp55fs13f * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER (
m0dkyunhwk ) ; UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType
* ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ] = ( NULL ) ;
systemRan [ 3 ] = ( NULL ) ; systemRan [ 4 ] = ( NULL ) ; systemRan [ 5 ] = (
NULL ) ; systemRan [ 6 ] = ( NULL ) ; systemRan [ 7 ] = ( NULL ) ; systemRan
[ 8 ] = ( NULL ) ; systemRan [ 9 ] = ( NULL ) ; systemRan [ 10 ] = ( NULL ) ;
systemRan [ 11 ] = ( NULL ) ; systemRan [ 12 ] = ( NULL ) ; systemRan [ 13 ]
= ( NULL ) ; systemRan [ 14 ] = ( NULL ) ; systemRan [ 15 ] = ( sysRanDType *
) & localDW -> ikwgolg1up ; systemRan [ 16 ] = ( sysRanDType * ) & localDW ->
oqcd3cplaf ; systemRan [ 17 ] = ( NULL ) ; systemRan [ 18 ] = ( NULL ) ;
systemRan [ 19 ] = ( sysRanDType * ) & localDW -> k2qa4dutqw . m3ocyz4afo ;
systemRan [ 20 ] = ( sysRanDType * ) & localDW -> jtklenszl2 . df54wvvk40 ;
systemRan [ 21 ] = ( sysRanDType * ) & localDW -> i54nxukymky . df54wvvk40 ;
systemRan [ 22 ] = ( sysRanDType * ) & localDW -> olrlhhrjjg0 . m3ocyz4afo ;
systemRan [ 23 ] = ( sysRanDType * ) & localDW -> pwa0sx1vmmq . p2o4a4dw11 ;
systemRan [ 24 ] = ( sysRanDType * ) & localDW -> kymnflaougc . fpjiixhyl5 ;
systemRan [ 25 ] = ( sysRanDType * ) & localDW -> il54uu1pjc . p2o4a4dw11 ;
systemRan [ 26 ] = ( sysRanDType * ) & localDW -> dl4mqb4pfs . fpjiixhyl5 ;
systemRan [ 27 ] = ( NULL ) ; systemRan [ 28 ] = ( NULL ) ; systemRan [ 29 ]
= ( NULL ) ; systemRan [ 30 ] = ( NULL ) ; systemRan [ 31 ] = ( NULL ) ;
systemRan [ 32 ] = ( NULL ) ; systemRan [ 33 ] = ( NULL ) ; systemRan [ 34 ]
= ( NULL ) ; systemTid [ 1 ] = m0dkyunhwk -> Timing . mdlref_GlobalTID [ 2 ]
; systemTid [ 2 ] = m0dkyunhwk -> Timing . mdlref_GlobalTID [ 2 ] ; systemTid
[ 3 ] = m0dkyunhwk -> Timing . mdlref_GlobalTID [ 2 ] ; systemTid [ 4 ] =
m0dkyunhwk -> Timing . mdlref_GlobalTID [ 2 ] ; systemTid [ 5 ] = m0dkyunhwk
-> Timing . mdlref_GlobalTID [ 2 ] ; systemTid [ 6 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 7 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 8 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 9 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 10 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 11 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 12 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 13 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 14 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 16 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 15 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 17 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 24 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 26 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 23 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 25 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 21 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 20 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 22 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 19 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 18 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 27 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 28 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 29 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 30 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 31 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 32 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 33 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 34 ] = m0dkyunhwk -> Timing .
mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] =
0 ; rtContextSystems [ 1 ] = 0 ; rtContextSystems [ 2 ] = 0 ;
rtContextSystems [ 3 ] = 0 ; rtContextSystems [ 4 ] = 0 ; rtContextSystems [
5 ] = 0 ; rtContextSystems [ 6 ] = 0 ; rtContextSystems [ 7 ] = 0 ;
rtContextSystems [ 8 ] = 0 ; rtContextSystems [ 9 ] = 0 ; rtContextSystems [
10 ] = 0 ; rtContextSystems [ 11 ] = 0 ; rtContextSystems [ 12 ] = 0 ;
rtContextSystems [ 13 ] = 0 ; rtContextSystems [ 14 ] = 0 ; rtContextSystems
[ 15 ] = 15 ; rtContextSystems [ 16 ] = 16 ; rtContextSystems [ 17 ] = 0 ;
rtContextSystems [ 18 ] = 0 ; rtContextSystems [ 19 ] = 19 ; rtContextSystems
[ 20 ] = 20 ; rtContextSystems [ 21 ] = 21 ; rtContextSystems [ 22 ] = 22 ;
rtContextSystems [ 23 ] = 23 ; rtContextSystems [ 24 ] = 24 ;
rtContextSystems [ 25 ] = 25 ; rtContextSystems [ 26 ] = 26 ;
rtContextSystems [ 27 ] = 0 ; rtContextSystems [ 28 ] = 0 ; rtContextSystems
[ 29 ] = 0 ; rtContextSystems [ 30 ] = 0 ; rtContextSystems [ 31 ] = 0 ;
rtContextSystems [ 32 ] = 0 ; rtContextSystems [ 33 ] = 0 ; rtContextSystems
[ 34 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void Torque_Vectoring_Model_Cooling_InitializeDataMapInfo ( lmmo4anm52 *
const m0dkyunhwk , mgp55fs13f * localDW , lietroj0em * localX , void *
sysRanPtr , int contextTid ) { rtwCAPI_SetVersion ( m0dkyunhwk -> DataMapInfo
. mmi , 1 ) ; rtwCAPI_SetStaticMap ( m0dkyunhwk -> DataMapInfo . mmi , &
mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( m0dkyunhwk -> DataMapInfo . mmi ,
& mmiStaticInfoLogging ) ; Torque_Vectoring_Model_Cooling_InitializeDataAddr
( m0dkyunhwk -> DataMapInfo . dataAddress , localDW , localX ) ;
rtwCAPI_SetDataAddressMap ( m0dkyunhwk -> DataMapInfo . mmi , m0dkyunhwk ->
DataMapInfo . dataAddress ) ;
Torque_Vectoring_Model_Cooling_InitializeVarDimsAddr ( m0dkyunhwk ->
DataMapInfo . vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( m0dkyunhwk ->
DataMapInfo . mmi , m0dkyunhwk -> DataMapInfo . vardimsAddress ) ;
rtwCAPI_SetPath ( m0dkyunhwk -> DataMapInfo . mmi , ( NULL ) ) ;
rtwCAPI_SetFullPath ( m0dkyunhwk -> DataMapInfo . mmi , ( NULL ) ) ;
Torque_Vectoring_Model_Cooling_InitializeLoggingFunctions ( m0dkyunhwk ->
DataMapInfo . loggingPtrs ) ; rtwCAPI_SetLoggingPtrs ( m0dkyunhwk ->
DataMapInfo . mmi , m0dkyunhwk -> DataMapInfo . loggingPtrs ) ;
rtwCAPI_SetInstanceLoggingInfo ( m0dkyunhwk -> DataMapInfo . mmi , &
m0dkyunhwk -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray (
m0dkyunhwk -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen (
m0dkyunhwk -> DataMapInfo . mmi , 0 ) ;
Torque_Vectoring_Model_Cooling_InitializeSystemRan ( m0dkyunhwk , m0dkyunhwk
-> DataMapInfo . systemRan , localDW , m0dkyunhwk -> DataMapInfo . systemTid
, sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( m0dkyunhwk -> DataMapInfo
. mmi , m0dkyunhwk -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid (
m0dkyunhwk -> DataMapInfo . mmi , m0dkyunhwk -> DataMapInfo . systemTid ) ;
rtwCAPI_SetGlobalTIDMap ( m0dkyunhwk -> DataMapInfo . mmi , & m0dkyunhwk ->
Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Torque_Vectoring_Model_Cooling_host_InitializeDataMapInfo (
Torque_Vectoring_Model_Cooling_host_DataMapInfo_T * dataMap , const char *
path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap (
dataMap -> mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi ,
( NULL ) ) ; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
