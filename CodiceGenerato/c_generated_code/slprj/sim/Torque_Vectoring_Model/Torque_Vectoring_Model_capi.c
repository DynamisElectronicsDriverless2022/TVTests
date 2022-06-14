#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Torque_Vectoring_Model_capi_host.h"
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
#include "Torque_Vectoring_Model.h"
#include "Torque_Vectoring_Model_capi.h"
#include "Torque_Vectoring_Model_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_SignalHierLoggingInfo rtSigHierLoggingInfo [ ] = { { ""
, 3 , 0 } , { "Torque_Distribution" , 2 , 3 } , { "MPC" , 8 , 5 } , {
"States" , 6 , 13 } , { "xhat" , 0 , - 1 } , { "EKF" , 0 , - 1 } , { "r_meas"
, 0 , - 1 } , { "vy_meas" , 0 , - 1 } , { "vx_meas" , 0 , - 1 } , { "x" , 3 ,
19 } , { "vx" , 0 , - 1 } , { "vy" , 0 , - 1 } , { "yaw_rate" , 0 , - 1 } , {
"Output_Vector_Reference" , 2 , 22 } , { "vx_ref" , 0 , - 1 } , { "vy_ref" ,
0 , - 1 } , { "Control_Constraints" , 4 , 24 } , {
"Load_Transfer_Calculation" , 4 , 28 } , { "fz_fl" , 0 , - 1 } , { "fz_fr" ,
0 , - 1 } , { "fz_rl" , 0 , - 1 } , { "fz_rr" , 0 , - 1 } , {
"Slip_Angle_Calculation" , 4 , 32 } , { "slip_angle_FL" , 0 , - 1 } , {
"slip_angle_FR" , 0 , - 1 } , { "slip_angle_RL" , 0 , - 1 } , {
"slip_angle_RR" , 0 , - 1 } , { "ubu" , 0 , - 1 } , { "lbu" , 0 , - 1 } , {
"Polytropic_Constraints" , 3 , 36 } , { "Accelerator_Mapping" , 1 , 39 } , {
"acc_map" , 0 , - 1 } , { "ug" , 0 , - 1 } , { "lg" , 0 , - 1 } , { "control"
, 0 , - 1 } , { "Solver" , 5 , 40 } , { "OCP_status" , 0 , - 1 } , {
"KKT_Residual" , 0 , - 1 } , { "X1" , 0 , - 1 } , { "CPU_time" , 0 , - 1 } ,
{ "SQP_iter" , 0 , - 1 } , { "Torque" , 4 , 45 } , { "t_rr" , 0 , - 1 } , {
"t_rl" , 0 , - 1 } , { "t_fr" , 0 , - 1 } , { "t_fl" , 0 , - 1 } , { "Power1"
, 0 , - 1 } , { "Reference" , 1 , 49 } , { "yaw_rate_desired" , 0 , - 1 } , {
"Input_Signals" , 4 , 50 } , { "hv" , 5 , 54 } , {
"display_overload_inverter" , 0 , - 1 } , { "display_overload_motor" , 0 , -
1 } , { "cooling" , 4 , 59 } , { "engine_temperature" , 0 , - 1 } , {
"t_igbt" , 0 , - 1 } , { "t_plate" , 0 , - 1 } , { "voltage" , 0 , - 1 } , {
"Pmax_regen" , 0 , - 1 } , { "Pmax_tractive" , 0 , - 1 } , { "car_settings" ,
3 , 63 } , { "rtd_flag" , 0 , - 1 } , { "torque_map" , 0 , - 1 } , {
"tc_flag" , 0 , - 1 } , { "dynamics_data" , 7 , 66 } , { "ax" , 0 , - 1 } , {
"ay" , 0 , - 1 } , { "brake_torque" , 0 , - 1 } , { "omega_wheels" , 0 , - 1
} , { "driver_inputs" , 3 , 73 } , { "throttle" , 0 , - 1 } , { "brake" , 0 ,
- 1 } , { "steering" , 0 , - 1 } , { "Slip_Control" , 1 , 76 } , {
"Slip_Ratios" , 4 , 77 } , { "slip_ratio_fl" , 0 , - 1 } , { "slip_ratio_fr"
, 0 , - 1 } , { "slip_ratio_rl" , 0 , - 1 } , { "slip_ratio_rr" , 0 , - 1 } }
; static const uint_T rtSigHierLoggingChildIdxs [ ] = { 1 , 49 , 73 , 2 , 47
, 3 , 13 , 16 , 29 , 34 , 35 , 41 , 46 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12
, 14 , 15 , 17 , 22 , 27 , 28 , 18 , 19 , 20 , 21 , 23 , 24 , 25 , 26 , 30 ,
32 , 33 , 31 , 36 , 37 , 38 , 39 , 40 , 42 , 43 , 44 , 45 , 48 , 50 , 60 , 64
, 69 , 51 , 52 , 53 , 58 , 59 , 54 , 55 , 56 , 57 , 61 , 62 , 63 , 10 , 11 ,
65 , 66 , 12 , 67 , 68 , 70 , 71 , 72 , 74 , 75 , 76 , 77 , 78 } ; static
rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0
, 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , 0 ,
TARGET_STRING ( "Torque_Vectoring_Model/Transfer Fcn1" ) , TARGET_STRING ( ""
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 1 , 2 ,
TARGET_STRING ( "Torque_Vectoring_Model/Transfer Fcn2" ) , TARGET_STRING ( ""
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 2 , 1 ,
TARGET_STRING ( "Torque_Vectoring_Model/Transfer Fcn4" ) , TARGET_STRING ( ""
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 3 , 4 ,
TARGET_STRING ( "Torque_Vectoring_Model/Transfer Fcn5" ) , TARGET_STRING ( ""
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 4 , 3 ,
TARGET_STRING ( "Torque_Vectoring_Model/Transfer Fcn6" ) , TARGET_STRING ( ""
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 , 1 , - 1 , 0 } , { 5 , - 1 ,
TARGET_STRING ( "Torque_Vectoring_Model/Unit Delay" ) , TARGET_STRING (
"DSTATE" ) , "" , 0 , 0 , 1 , 0 , 1 , 0 , - 1 , 0 } , { 6 , - 1 ,
TARGET_STRING (
 "Torque_Vectoring_Model/Torque_Vectoring/Torque Distribution/MPC/Control constraints/lbu_dot/Unit Delay1"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 2 , 0 , - 1 , 0 } , { 7
, - 1 , TARGET_STRING (
 "Torque_Vectoring_Model/Torque_Vectoring/Torque Distribution/MPC/Faults detection/Subsystem2/Discrete FIR Filter"
) , TARGET_STRING ( "states" ) , "" , 0 , 0 , 1 , 0 , 2 , 0 , - 1 , 0 } , { 8
, - 1 , TARGET_STRING (
 "Torque_Vectoring_Model/Torque_Vectoring/Torque Distribution/MPC/Faults detection/Subsystem2/Discrete FIR Filter"
) , TARGET_STRING ( "circBuf" ) , "" , 0 , 1 , 0 , 0 , 2 , 0 , - 1 , 0 } , {
9 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model/Torque_Vectoring/Torque Distribution/MPC/Control constraints/Low YRD/Mz = 0 Bound logic/Discrete FIR Filter"
) , TARGET_STRING ( "states" ) , "" , 0 , 2 , 2 , 0 , 2 , 0 , - 1 , 0 } , {
10 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model/Torque_Vectoring/Torque Distribution/MPC/Control constraints/Low YRD/Mz = 0 Bound logic/Discrete FIR Filter"
) , TARGET_STRING ( "circBuf" ) , "" , 0 , 1 , 0 , 0 , 2 , 0 , - 1 , 0 } , {
11 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model/Torque_Vectoring/Torque Distribution/MPC/Weights generation/Subsystem1/Steer Activation/Delay"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 3 , 3 , 0 , 2 , 0 , - 1 , 0 } , {
12 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model/Torque_Vectoring/Torque Distribution/MPC/Weights generation/Subsystem1/Steer Activation/First Activation/Unit Delay1"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 3 , 0 , 0 , 2 , 0 , - 1 , 0 } , {
13 , - 1 , TARGET_STRING (
 "Torque_Vectoring_Model/Torque_Vectoring/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter\n(Discrete or Continuous)/Integrator\n(Discrete or Continuous)/Discrete/Integrator"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 2 , 0 , - 1 , 0 } , { 0
, - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } }
; static int_T rt_LoggedStateIdxList [ ] = { 0 , 2 , 1 , 4 , 3 , 4 , 5 , 6 ,
48 , 49 , 47 , 51 , 50 , 3 } ;
#ifndef HOST_CAPI_BUILD
static void Torque_Vectoring_Model_InitializeDataAddr ( void * dataAddr [ ] ,
lm02cmjnzh * localDW , njcbhnzhxv * localX ) { dataAddr [ 0 ] = ( void * ) (
& localX -> dcitxr0qmt ) ; dataAddr [ 1 ] = ( void * ) ( & localX ->
kddiqlzre2 ) ; dataAddr [ 2 ] = ( void * ) ( & localX -> jylybj1aho ) ;
dataAddr [ 3 ] = ( void * ) ( & localX -> mpgtiyrp0l ) ; dataAddr [ 4 ] = (
void * ) ( & localX -> lan15trgft ) ; dataAddr [ 5 ] = ( void * ) ( & localDW
-> l54on5e34r [ 0 ] ) ; dataAddr [ 6 ] = ( void * ) ( & localDW -> l1hwxxcf3t
) ; dataAddr [ 7 ] = ( void * ) ( & localDW -> k3gnkpqipr [ 0 ] ) ; dataAddr
[ 8 ] = ( void * ) ( & localDW -> oltejywlb5 ) ; dataAddr [ 9 ] = ( void * )
( & localDW -> ayvrdlqgwy [ 0 ] ) ; dataAddr [ 10 ] = ( void * ) ( & localDW
-> ikp1er2ybh ) ; dataAddr [ 11 ] = ( void * ) ( & localDW -> p1qn01wqap [ 0
] ) ; dataAddr [ 12 ] = ( void * ) ( & localDW -> kjpqgomqpj ) ; dataAddr [
13 ] = ( void * ) ( & localDW -> hpgo02yjst [ 0 ] ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void Torque_Vectoring_Model_InitializeVarDimsAddr ( int32_T *
vardimsAddr [ ] ) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void Torque_Vectoring_Model_InitializeLoggingFunctions (
RTWLoggingFcnPtr loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ;
loggingPtrs [ 1 ] = ( NULL ) ; loggingPtrs [ 2 ] = ( NULL ) ; loggingPtrs [ 3
] = ( NULL ) ; loggingPtrs [ 4 ] = ( NULL ) ; loggingPtrs [ 5 ] = ( NULL ) ;
loggingPtrs [ 6 ] = ( NULL ) ; loggingPtrs [ 7 ] = ( NULL ) ; loggingPtrs [ 8
] = ( NULL ) ; loggingPtrs [ 9 ] = ( NULL ) ; loggingPtrs [ 10 ] = ( NULL ) ;
loggingPtrs [ 11 ] = ( NULL ) ; loggingPtrs [ 12 ] = ( NULL ) ; loggingPtrs [
13 ] = ( NULL ) ; }
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
rtContextSystems [ 37 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ]
= { { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo
mmiStaticInfoLogging = { 37 , rtContextSystems , loggingMetaInfo , 0 , ( NULL
) , { 79 , rtSigHierLoggingInfo , rtSigHierLoggingChildIdxs } , 0 , ( NULL )
} ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 0
, ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockStates , 14 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 851060625U
, 2273770208U , 2967087885U , 2168034103U } , & mmiStaticInfoLogging , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * Torque_Vectoring_Model_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void Torque_Vectoring_Model_InitializeSystemRan ( ezpkkyrudv * const
bl3qdbldo0 , sysRanDType * systemRan [ ] , lm02cmjnzh * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER (
bl3qdbldo0 ) ; UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType
* ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ] = ( NULL ) ;
systemRan [ 3 ] = ( NULL ) ; systemRan [ 4 ] = ( NULL ) ; systemRan [ 5 ] = (
NULL ) ; systemRan [ 6 ] = ( NULL ) ; systemRan [ 7 ] = ( NULL ) ; systemRan
[ 8 ] = ( NULL ) ; systemRan [ 9 ] = ( NULL ) ; systemRan [ 10 ] = ( NULL ) ;
systemRan [ 11 ] = ( NULL ) ; systemRan [ 12 ] = ( NULL ) ; systemRan [ 13 ]
= ( NULL ) ; systemRan [ 14 ] = ( NULL ) ; systemRan [ 15 ] = ( NULL ) ;
systemRan [ 16 ] = ( NULL ) ; systemRan [ 17 ] = ( sysRanDType * ) & localDW
-> eswfw4zt2l ; systemRan [ 18 ] = ( sysRanDType * ) & localDW -> cuj32ioisf
; systemRan [ 19 ] = ( NULL ) ; systemRan [ 20 ] = ( NULL ) ; systemRan [ 21
] = ( sysRanDType * ) & localDW -> cvp5xo4aw2 . cms2fen1zz ; systemRan [ 22 ]
= ( sysRanDType * ) & localDW -> cjp0ll3pd2 . fcirhlhinq ; systemRan [ 23 ] =
( sysRanDType * ) & localDW -> peozus1dnst . fcirhlhinq ; systemRan [ 24 ] =
( sysRanDType * ) & localDW -> pf5ohd3jye0 . cms2fen1zz ; systemRan [ 25 ] =
( sysRanDType * ) & localDW -> hfgcehfk2gx . cf0xinclcr ; systemRan [ 26 ] =
( sysRanDType * ) & localDW -> fsg3uy4quct . hxinfjq0k1 ; systemRan [ 27 ] =
( sysRanDType * ) & localDW -> c0dwlf5j11 . cf0xinclcr ; systemRan [ 28 ] = (
sysRanDType * ) & localDW -> l1plnz21yr . hxinfjq0k1 ; systemRan [ 29 ] = (
NULL ) ; systemRan [ 30 ] = ( NULL ) ; systemRan [ 31 ] = ( NULL ) ;
systemRan [ 32 ] = ( NULL ) ; systemRan [ 33 ] = ( NULL ) ; systemRan [ 34 ]
= ( NULL ) ; systemRan [ 35 ] = ( NULL ) ; systemRan [ 36 ] = ( NULL ) ;
systemTid [ 1 ] = bl3qdbldo0 -> Timing . mdlref_GlobalTID [ 2 ] ; systemTid [
2 ] = bl3qdbldo0 -> Timing . mdlref_GlobalTID [ 2 ] ; systemTid [ 3 ] =
bl3qdbldo0 -> Timing . mdlref_GlobalTID [ 2 ] ; systemTid [ 4 ] = bl3qdbldo0
-> Timing . mdlref_GlobalTID [ 2 ] ; systemTid [ 5 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 6 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 7 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 8 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 9 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 10 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 11 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 12 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 13 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 14 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 15 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 16 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 18 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 17 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 19 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 26 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 28 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 25 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 27 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 23 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 22 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 24 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 21 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 20 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 29 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 30 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 31 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 32 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 33 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 34 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 35 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 2 ] ; systemTid [ 36 ] = bl3qdbldo0 -> Timing .
mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] =
0 ; rtContextSystems [ 1 ] = 0 ; rtContextSystems [ 2 ] = 0 ;
rtContextSystems [ 3 ] = 0 ; rtContextSystems [ 4 ] = 0 ; rtContextSystems [
5 ] = 0 ; rtContextSystems [ 6 ] = 0 ; rtContextSystems [ 7 ] = 0 ;
rtContextSystems [ 8 ] = 0 ; rtContextSystems [ 9 ] = 0 ; rtContextSystems [
10 ] = 0 ; rtContextSystems [ 11 ] = 0 ; rtContextSystems [ 12 ] = 0 ;
rtContextSystems [ 13 ] = 0 ; rtContextSystems [ 14 ] = 0 ; rtContextSystems
[ 15 ] = 0 ; rtContextSystems [ 16 ] = 0 ; rtContextSystems [ 17 ] = 17 ;
rtContextSystems [ 18 ] = 18 ; rtContextSystems [ 19 ] = 0 ; rtContextSystems
[ 20 ] = 0 ; rtContextSystems [ 21 ] = 21 ; rtContextSystems [ 22 ] = 22 ;
rtContextSystems [ 23 ] = 23 ; rtContextSystems [ 24 ] = 24 ;
rtContextSystems [ 25 ] = 25 ; rtContextSystems [ 26 ] = 26 ;
rtContextSystems [ 27 ] = 27 ; rtContextSystems [ 28 ] = 28 ;
rtContextSystems [ 29 ] = 0 ; rtContextSystems [ 30 ] = 0 ; rtContextSystems
[ 31 ] = 0 ; rtContextSystems [ 32 ] = 0 ; rtContextSystems [ 33 ] = 0 ;
rtContextSystems [ 34 ] = 0 ; rtContextSystems [ 35 ] = 0 ; rtContextSystems
[ 36 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void Torque_Vectoring_Model_InitializeDataMapInfo ( ezpkkyrudv * const
bl3qdbldo0 , lm02cmjnzh * localDW , njcbhnzhxv * localX , void * sysRanPtr ,
int contextTid ) { rtwCAPI_SetVersion ( bl3qdbldo0 -> DataMapInfo . mmi , 1 )
; rtwCAPI_SetStaticMap ( bl3qdbldo0 -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( bl3qdbldo0 -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; Torque_Vectoring_Model_InitializeDataAddr (
bl3qdbldo0 -> DataMapInfo . dataAddress , localDW , localX ) ;
rtwCAPI_SetDataAddressMap ( bl3qdbldo0 -> DataMapInfo . mmi , bl3qdbldo0 ->
DataMapInfo . dataAddress ) ; Torque_Vectoring_Model_InitializeVarDimsAddr (
bl3qdbldo0 -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap (
bl3qdbldo0 -> DataMapInfo . mmi , bl3qdbldo0 -> DataMapInfo . vardimsAddress
) ; rtwCAPI_SetPath ( bl3qdbldo0 -> DataMapInfo . mmi , ( NULL ) ) ;
rtwCAPI_SetFullPath ( bl3qdbldo0 -> DataMapInfo . mmi , ( NULL ) ) ;
Torque_Vectoring_Model_InitializeLoggingFunctions ( bl3qdbldo0 -> DataMapInfo
. loggingPtrs ) ; rtwCAPI_SetLoggingPtrs ( bl3qdbldo0 -> DataMapInfo . mmi ,
bl3qdbldo0 -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetInstanceLoggingInfo (
bl3qdbldo0 -> DataMapInfo . mmi , & bl3qdbldo0 -> DataMapInfo .
mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( bl3qdbldo0 -> DataMapInfo .
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( bl3qdbldo0 -> DataMapInfo .
mmi , 0 ) ; Torque_Vectoring_Model_InitializeSystemRan ( bl3qdbldo0 ,
bl3qdbldo0 -> DataMapInfo . systemRan , localDW , bl3qdbldo0 -> DataMapInfo .
systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( bl3qdbldo0 ->
DataMapInfo . mmi , bl3qdbldo0 -> DataMapInfo . systemRan ) ;
rtwCAPI_SetSystemTid ( bl3qdbldo0 -> DataMapInfo . mmi , bl3qdbldo0 ->
DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( bl3qdbldo0 ->
DataMapInfo . mmi , & bl3qdbldo0 -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Torque_Vectoring_Model_host_InitializeDataMapInfo (
Torque_Vectoring_Model_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
