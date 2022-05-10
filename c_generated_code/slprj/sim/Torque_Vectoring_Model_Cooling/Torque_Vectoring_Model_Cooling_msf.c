#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME Torque_Vectoring_Model_Cooling_msf
#endif
#define S_FUNCTION_LEVEL 2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif
#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#include "mwstringutil.h"
#define rt_logging_h
#include "Torque_Vectoring_Model_Cooling_types.h"
#include "Torque_Vectoring_Model_Cooling.h"
#include "Torque_Vectoring_Model_Cooling_private.h"
struct_VErj1hGlw6L5R7K3AuDTiC rtP_TV ; const char *
rt_GetMatSignalLoggingFileName ( void ) { return NULL ; } const char *
rt_GetMatSigLogSelectorFileName ( void ) { return NULL ; } void *
rt_GetOSigstreamManager ( void ) { return NULL ; } void * rt_slioCatalogue (
void ) { return NULL ; } void * rtwGetPointerFromUniquePtr ( void * uniquePtr
) { return NULL ; } void * CreateDiagnosticAsVoidPtr ( const char * id , int
nargs , ... ) { void * voidPtrDiagnostic = NULL ; va_list args ; va_start (
args , nargs ) ; slmrCreateDiagnostic ( id , nargs , args , &
voidPtrDiagnostic ) ; va_end ( args ) ; return voidPtrDiagnostic ; } void
rt_ssSet_slErrMsg ( void * S , void * diag ) { SimStruct * simStrcut = (
SimStruct * ) S ; if ( ! _ssIsErrorStatusAslErrMsg ( simStrcut ) ) {
_ssSet_slLocalErrMsg ( simStrcut , diag ) ; } else { _ssDiscardDiagnostic (
simStrcut , diag ) ; } } void rt_ssReportDiagnosticAsWarning ( void * S ,
void * diag ) { _ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; }
void rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } const char *
rt_CreateFullPathToTop ( const char * toppath , const char * subpath ) { char
* fullpath = NULL ; slmrCreateFullPathToTop ( toppath , subpath , & fullpath
) ; return fullpath ; } boolean_T slIsRapidAcceleratorSimulating ( void ) {
return false ; } void rt_RAccelReplaceFromFilename ( const char * blockpath ,
char * fileName ) { ( void ) blockpath ; ( void ) fileName ; } void
rt_RAccelReplaceToFilename ( const char * blockpath , char * fileName ) { (
void ) blockpath ; ( void ) fileName ; } void
slsaCacheDWorkPointerForSimTargetOP ( void * ss , void * * ptr ) { ( void )
ss ; ( void ) ptr ; } void slsaCacheDWorkDataForSimTargetOP ( void * ss ,
void * ptr , unsigned int sizeInBytes ) { ( void ) ss ; ( void ) ptr ; ( void
) sizeInBytes ; } void slsaSaveRawMemoryForSimTargetOP ( void * ss , const
char * key , void * * ptr , unsigned int sizeInBytes , void * ( *
customOPSaveFcn ) ( void * dworkPtr , unsigned int * sizeInBytes ) , void ( *
customOPRestoreFcn ) ( void * dworkPtr , const void * data , unsigned int
sizeInBytes ) ) { ( void ) ss ; ( void ) key ; ( void ) ptr ; ( void )
sizeInBytes ; ( void ) customOPSaveFcn ; ( void ) customOPRestoreFcn ; } void
acados_solver_sfunction_dt_model ( SimStruct * S ) { ( void ) S ; }
#define MDL_PROCESS_PARAMETERS
#if defined(MATLAB_MEX_FILE)
static void mdlProcessParameters ( SimStruct * S ) {
struct_VErj1hGlw6L5R7K3AuDTiC * GlobalPrm_0 = ( struct_VErj1hGlw6L5R7K3AuDTiC
* ) NULL ; if ( ! ssGetModelRefGlobalParamData ( S , 0 , ( void * * ) ( &
GlobalPrm_0 ) ) ) return ; if ( GlobalPrm_0 != NULL ) { ( void ) memcpy ( & (
rtP_TV ) , GlobalPrm_0 , sizeof ( struct_VErj1hGlw6L5R7K3AuDTiC ) ) ; } }
#endif
static void mdlInitializeConditions ( SimStruct * S ) { djynksnhd4a * dw = (
djynksnhd4a * ) ssGetDWork ( S , 0 ) ; lietroj0em * localX = ( lietroj0em * )
ssGetContStates ( S ) ; njtux15dzh ( & ( dw -> rtm ) , & ( dw -> rtb ) , & (
dw -> rtdw ) , localX ) ; } static void mdlReset ( SimStruct * S ) {
djynksnhd4a * dw = ( djynksnhd4a * ) ssGetDWork ( S , 0 ) ; lietroj0em *
localX = ( lietroj0em * ) ssGetContStates ( S ) ; cc2mloeum2 ( & ( dw -> rtm
) , & ( dw -> rtdw ) , localX ) ; } static void mdlPeriodicOutputUpdate (
SimStruct * S , int_T tid ) { djynksnhd4a * dw = ( djynksnhd4a * ) ssGetDWork
( S , 0 ) ; real_T const * i_hslookaa2r = ( real_T * ) ssGetInputPortSignal (
S , 0 ) ; real_T const * i_ixstttuxj5 = ( real_T * ) ssGetInputPortSignal ( S
, 1 ) ; real_T const * i_bbhxqbcec1 = ( real_T * ) ssGetInputPortSignal ( S ,
8 ) ; real_T const * i_h3br443frc = ( real_T * ) ssGetInputPortSignal ( S , 9
) ; real_T const * i_fupllqef0r = ( real_T * ) ssGetInputPortSignal ( S , 10
) ; real_T const * i_olrdiqcc2q = ( real_T * ) ssGetInputPortSignal ( S , 11
) ; lietroj0em * localX = ( lietroj0em * ) ssGetContStates ( S ) ; real_T *
o_B_30_1 = ( real_T * ) ssGetOutputPortSignal ( S , 0 ) ; real_T * o_B_30_2 =
( real_T * ) ssGetOutputPortSignal ( S , 1 ) ; real_T * o_B_30_3 = ( real_T *
) ssGetOutputPortSignal ( S , 2 ) ; real_T * o_B_30_4 = ( real_T * )
ssGetOutputPortSignal ( S , 3 ) ; real_T const * i_kvyqmtegef = ( real_T * )
ssGetInputPortSignal ( S , 12 ) ; real_T const * i_n4oyk2n2pb = ( real_T * )
ssGetInputPortSignal ( S , 13 ) ; real_T const * i_nqp2kxupmr = ( real_T * )
ssGetInputPortSignal ( S , 14 ) ; real_T const * i_ebr32ao12z = ( real_T * )
ssGetInputPortSignal ( S , 15 ) ; real_T const * i_jt5aam3ekr = ( real_T * )
ssGetInputPortSignal ( S , 16 ) ; real_T const * i_i3xskpae5z = ( real_T * )
ssGetInputPortSignal ( S , 17 ) ; real_T const * i_fitchxcadd = ( real_T * )
ssGetInputPortSignal ( S , 18 ) ; real_T const * i_jep4vwjut0 = ( real_T * )
ssGetInputPortSignal ( S , 19 ) ; real_T const * i_i2azpvjwnq = ( real_T * )
ssGetInputPortSignal ( S , 20 ) ; real_T const * i_ausnbtx2ku = ( real_T * )
ssGetInputPortSignal ( S , 21 ) ; real_T const * i_dslb2pf2ju = ( real_T * )
ssGetInputPortSignal ( S , 22 ) ; if ( tid == 0 ) {
Torque_Vectoring_Model_CoolingTID0 ( & ( dw -> rtm ) , i_hslookaa2r ,
i_ixstttuxj5 , i_bbhxqbcec1 , i_h3br443frc , i_fupllqef0r , i_olrdiqcc2q , &
( dw -> rtb ) , & ( dw -> rtdw ) , localX ) ; icxn3b14hxTID0 ( & ( dw -> rtm
) , i_kvyqmtegef , i_n4oyk2n2pb , i_nqp2kxupmr , i_ebr32ao12z , i_jt5aam3ekr
, i_i3xskpae5z , i_fitchxcadd , i_jep4vwjut0 , i_i2azpvjwnq , i_ausnbtx2ku ,
i_dslb2pf2ju , & ( dw -> rtdw ) ) ; } if ( tid == 1 ) {
Torque_Vectoring_Model_CoolingTID1 ( ) ; icxn3b14hxTID1 ( ) ; } if ( tid == 2
) { Torque_Vectoring_Model_CoolingTID2 ( & ( dw -> rtm ) , o_B_30_1 ,
o_B_30_2 , o_B_30_3 , o_B_30_4 , & ( dw -> rtb ) , & ( dw -> rtdw ) ) ;
icxn3b14hxTID2 ( & ( dw -> rtb ) , & ( dw -> rtdw ) ) ; } } static void
mdlInitializeSizes ( SimStruct * S ) { if ( ( S -> mdlInfo -> genericFcn != (
NULL ) ) && ( ! ( S -> mdlInfo -> genericFcn ) ( S ,
GEN_FCN_CHK_MODELREF_SFUN_HAS_MODEL_BLOCK , - 1 , ( NULL ) ) ) ) { return ; }
ssSetNumSFcnParams ( S , 0 ) ; ssFxpSetU32BitRegionCompliant ( S , 1 ) ;
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; if ( S -> mdlInfo -> genericFcn != (
NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ; }
ssSetRTWGeneratedSFcn ( S , 2 ) ; ssSetNumContStates ( S , 6 ) ;
ssSetNumDiscStates ( S , 0 ) ; ssSetNumPeriodicContStates ( S , 0 ) ;
ssSetSymbolicDimsSupport ( S , true ) ; slmrInitializeIOPortDataVectors ( S ,
23 , 4 ) ; if ( ! ssSetNumInputPorts ( S , 23 ) ) return ; if ( !
ssSetInputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 0 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 0 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 0 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 0 , 1 ) ; ssSetInputPortOptimOpts ( S
, 0 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 0 ,
false ) ; ssSetInputPortSampleTime ( S , 0 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 0 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 1 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 1 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 1 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 1 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 1 , 1 ) ; ssSetInputPortOptimOpts ( S
, 1 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 1 ,
false ) ; ssSetInputPortSampleTime ( S , 1 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 1 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 2 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 2 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 2 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 2 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 2 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 2 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 2 , 1 ) ; ssSetInputPortOptimOpts ( S
, 2 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 2 ,
false ) ; ssSetInputPortSampleTime ( S , 2 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 2 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 3 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 3 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 3 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 3 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 3 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 3 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 3 , 1 ) ; ssSetInputPortOptimOpts ( S
, 3 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 3 ,
false ) ; ssSetInputPortSampleTime ( S , 3 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 3 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 4 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 4 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 4 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 4 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 4 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 4 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 4 , 1 ) ; ssSetInputPortOptimOpts ( S
, 4 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 4 ,
false ) ; ssSetInputPortSampleTime ( S , 4 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 4 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 5 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 5 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 5 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 5 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 5 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 5 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 5 , 1 ) ; ssSetInputPortOptimOpts ( S
, 5 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 5 ,
false ) ; ssSetInputPortSampleTime ( S , 5 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 5 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 6 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 6 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 6 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 6 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 6 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 6 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 6 , 1 ) ; ssSetInputPortOptimOpts ( S
, 6 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 6 ,
false ) ; ssSetInputPortSampleTime ( S , 6 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 6 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 7 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 7 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 7 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 7 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 7 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 7 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 7 , 1 ) ; ssSetInputPortOptimOpts ( S
, 7 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 7 ,
false ) ; ssSetInputPortSampleTime ( S , 7 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 7 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 8 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 8 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 8 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 8 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 8 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 8 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 8 , 1 ) ; ssSetInputPortOptimOpts ( S
, 8 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 8 ,
false ) ; ssSetInputPortSampleTime ( S , 8 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 8 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 9 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 9 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 9 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 9 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 9 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 9 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 9 , 1 ) ; ssSetInputPortOptimOpts ( S
, 9 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 9 ,
false ) ; ssSetInputPortSampleTime ( S , 9 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 9 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 10 , 1 ) )
return ; ssSetInputPortDimensionsMode ( S , 10 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 10 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 10 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 10 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 10 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 10 , 1 ) ; ssSetInputPortOptimOpts ( S
, 10 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 10 ,
false ) ; ssSetInputPortSampleTime ( S , 10 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 10 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 11 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 11 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 11 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 11 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 11 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 11 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 11 , 1 ) ; ssSetInputPortOptimOpts ( S
, 11 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 11 ,
false ) ; ssSetInputPortSampleTime ( S , 11 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 11 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 12 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 12 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 12 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 12 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 12 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 12 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 12 , 1 ) ; ssSetInputPortOptimOpts ( S
, 12 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 12 ,
false ) ; ssSetInputPortSampleTime ( S , 12 , 0.001 ) ;
ssSetInputPortOffsetTime ( S , 12 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 13 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 13 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 13 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 13 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 13 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 13 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 13 , 1 ) ; ssSetInputPortOptimOpts ( S
, 13 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 13 ,
false ) ; ssSetInputPortSampleTime ( S , 13 , 0.001 ) ;
ssSetInputPortOffsetTime ( S , 13 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 14 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 14 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 14 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 14 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 14 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 14 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 14 , 1 ) ; ssSetInputPortOptimOpts ( S
, 14 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 14 ,
false ) ; ssSetInputPortSampleTime ( S , 14 , 0.001 ) ;
ssSetInputPortOffsetTime ( S , 14 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 15 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 15 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 15 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 15 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 15 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 15 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 15 , 1 ) ; ssSetInputPortOptimOpts ( S
, 15 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 15 ,
false ) ; ssSetInputPortSampleTime ( S , 15 , 0.001 ) ;
ssSetInputPortOffsetTime ( S , 15 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 16 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 16 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 16 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 16 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 16 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 16 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 16 , 1 ) ; ssSetInputPortOptimOpts ( S
, 16 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 16 ,
false ) ; ssSetInputPortSampleTime ( S , 16 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 16 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 17 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 17 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 17 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 17 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 17 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 17 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 17 , 1 ) ; ssSetInputPortOptimOpts ( S
, 17 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 17 ,
false ) ; ssSetInputPortSampleTime ( S , 17 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 17 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 18 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 18 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 18 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 18 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 18 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 18 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 18 , 1 ) ; ssSetInputPortOptimOpts ( S
, 18 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 18 ,
false ) ; ssSetInputPortSampleTime ( S , 18 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 18 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 19 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 19 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 19 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 19 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 19 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 19 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 19 , 1 ) ; ssSetInputPortOptimOpts ( S
, 19 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 19 ,
false ) ; ssSetInputPortSampleTime ( S , 19 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 19 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 20 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 20 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 20 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 20 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 20 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 20 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 20 , 1 ) ; ssSetInputPortOptimOpts ( S
, 20 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 20 ,
false ) ; ssSetInputPortSampleTime ( S , 20 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 20 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 21 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 21 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 21 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 21 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 21 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 21 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 21 , 1 ) ; ssSetInputPortOptimOpts ( S
, 21 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 21 ,
false ) ; ssSetInputPortSampleTime ( S , 21 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 21 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 22 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 22 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 22 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 22 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 22 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 22 , 0 ) ;
ssSetInputPortRequiredContiguous ( S , 22 , 1 ) ; ssSetInputPortOptimOpts ( S
, 22 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 22 ,
false ) ; ssSetInputPortSampleTime ( S , 22 , 0.0 ) ;
ssSetInputPortOffsetTime ( S , 22 , 0.0 ) ; if ( ! ssSetNumOutputPorts ( S ,
4 ) ) return ; if ( ! ssSetOutputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 0 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 0 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 0 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 0 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 0 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 0 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 0 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 0 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 1 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 1 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 1 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 1 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 1 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 1 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 1 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 1 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 1 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 2 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 2 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 2 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 2 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 2 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 2 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 2 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 2 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 2 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 2 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 2 , SS_NOT_REUSABLE_AND_LOCAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 3 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 3 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 3 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 3 , SS_DOUBLE )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 3 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 3 , 0.02 ) ; ssSetOutputPortOffsetTime ( S
, 3 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 3 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 3 , SS_OK_TO_MERGE_CONDITIONAL ) ;
ssSetOutputPortICAttributes ( S , 3 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 3 , SS_NOT_REUSABLE_AND_LOCAL ) ;
ssSetSimStateCompliance ( S , USE_CUSTOM_SIM_STATE ) ;
mr_Torque_Vectoring_Model_Cooling_RegisterSimStateChecksum ( S ) ;
ssSetNumSampleTimes ( S , 4 ) ; ssSetParameterTuningCompliance ( S , true ) ;
ssSetNumRWork ( S , 0 ) ; ssSetNumIWork ( S , 0 ) ; ssSetNumPWork ( S , 0 ) ;
ssSetNumModes ( S , 0 ) ; { int_T zcsIdx = 0 ; }
ssSetOutputPortIsNonContinuous ( S , 0 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 0 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 1 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 1 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 2 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 2 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 3 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 3 , 0 ) ;
ssSetInputPortIsNotDerivPort ( S , 0 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 1 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 2 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 3 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 4 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 5 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 6 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 7 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 8 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 9 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 10 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 11 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 12 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 13 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 14 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 15 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 16 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 17 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 18 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 19 , 1 ) ; ssSetInputPortIsNotDerivPort ( S , 20 , 1 ) ;
ssSetInputPortIsNotDerivPort ( S , 21 , 1 ) ; ssSetInputPortIsNotDerivPort (
S , 22 , 1 ) ; ssSetModelReferenceSampleTimeInheritanceRule ( S ,
DISALLOW_SAMPLE_TIME_INHERITANCE ) ; ssSetAcceptsFcnCallInputs ( S ) ;
ssSetModelReferenceNormalModeSupport ( S ,
MDL_START_AND_MDL_PROCESS_PARAMS_OK ) ; ssSupportsMultipleExecInstances ( S ,
false ) ; ssRegisterMsgForNotSupportingMultiExecInst ( S ,
 "<diag_root><diag id=\"Simulink:blocks:UserSFcnBlockDoesNotSupportMultiExecInstances\" pr=\"d\"><arguments><arg type=\"encoded\">VABvAHIAcQB1AGUAXwBWAGUAYwB0AG8AcgBpAG4AZwBfAE0AbwBkAGUAbABfAEMAbwBvAGwAaQBuAGcALwBUAG8AcgBxAHUAZQBfAFYAZQBjAHQAbwByAGkAbgBnAC8AVABvAHIAcQB1AGUAIABEAGkAcwB0AHIAaQBiAHUAdABpAG8AbgAvAE0AUABDAC8AUwAtAEYAdQBuAGMAdABpAG8AbgAAAA==</arg><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg></arguments><hs><h>AAAARIDT30CL</h></hs></diag></diag_root>"
) ; ssHasStateInsideForEachSS ( S , false ) ; ssSetOptions ( S ,
SS_OPTION_ALLOW_CONSTANT_PORT_SAMPLE_TIME |
SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED | SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES |
SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_EXCEPTION_FREE_CODE |
SS_OPTION_WORKS_WITH_CODE_REUSE ) ;
#if SS_SFCN_FOR_SIM
if ( S -> mdlInfo -> genericFcn != ( NULL ) && ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { int_T retVal = 1 ;
mr_Torque_Vectoring_Model_Cooling_MdlInfoRegFcn ( S ,
"Torque_Vectoring_Model_Cooling" , & retVal ) ; if ( ! retVal ) return ; }
#endif
#if SS_SFCN_FOR_SIM
if ( ssSetNumDWork ( S , 1 ) ) { int mdlrefDWTypeId ; ssRegMdlRefDWorkType (
S , & mdlrefDWTypeId ) ; if ( mdlrefDWTypeId == INVALID_DTYPE_ID ) return ;
if ( ! ssSetDataTypeSize ( S , mdlrefDWTypeId , sizeof ( djynksnhd4a ) ) )
return ; ssSetDWorkDataType ( S , 0 , mdlrefDWTypeId ) ; ssSetDWorkWidth ( S
, 0 , 1 ) ; }
#else
if ( ! ssSetNumDWork ( S , 1 ) ) { return ; }
#endif
slmrRegisterSystemInitializeMethod ( S , mdlInitializeConditions ) ;
slmrRegisterSystemResetMethod ( S , mdlReset ) ;
slmrRegisterPeriodicOutputUpdateMethod ( S , mdlPeriodicOutputUpdate ) ;
ssSetSimulinkVersionGeneratedIn ( S , "10.5" ) ; ssSetNeedAbsoluteTime ( S ,
1 ) ; } static void mdlInitializeSampleTimes ( SimStruct * S ) {
ssSetSampleTime ( S , 0 , 0 ) ; ssSetOffsetTime ( S , 0 , 0 ) ;
ssSetSampleTime ( S , 1 , 0.001 ) ; ssSetOffsetTime ( S , 1 , 0 ) ;
ssSetSampleTime ( S , 2 , 0.02 ) ; ssSetOffsetTime ( S , 2 , 0 ) ;
ssSetSampleTime ( S , 3 , mxGetInf ( ) ) ; ssSetOffsetTime ( S , 3 , 0 ) ;
return ; }
#define MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths ( SimStruct * S ) { if ( S -> mdlInfo ->
genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ;
ssSetSignalSizesComputeType ( S , SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE
) ; } { static const char * toFileNames [ ] = { "" } ; static const char *
fromFileNames [ ] = { "" } ; if ( ! ssSetModelRefFromFiles ( S , 0 ,
fromFileNames ) ) return ; if ( ! ssSetModelRefToFiles ( S , 0 , toFileNames
) ) return ; } }
#define MDL_SETUP_RUNTIME_RESOURCES
static void mdlSetupRuntimeResources ( SimStruct * S ) { djynksnhd4a * dw = (
djynksnhd4a * ) ssGetDWork ( S , 0 ) ; lietroj0em * localX = ( lietroj0em * )
ssGetContStates ( S ) ; void * sysRanPtr = ( NULL ) ; int sysTid = 0 ;
ssGetContextSysRanBCPtr ( S , & sysRanPtr ) ; ssGetContextSysTid ( S , &
sysTid ) ; if ( sysTid == CONSTANT_TID ) { sysTid = 0 ; } krzmzwaah3 ( S ,
slmrGetTopTidFromMdlRefChildTid ( S , 0 , false ) ,
slmrGetTopTidFromMdlRefChildTid ( S , 1 , false ) ,
slmrGetTopTidFromMdlRefChildTid ( S , 2 , false ) ,
slmrGetTopTidFromMdlRefChildTid ( S , 3 , true ) , & ( dw -> rtm ) , & ( dw
-> rtb ) , & ( dw -> rtdw ) , localX , sysRanPtr , sysTid , ( ( NULL ) ) , (
( NULL ) ) , 0 , - 1 ) ; ssSetModelMappingInfoPtr ( S , & ( dw -> rtm .
DataMapInfo . mmi ) ) ; if ( S -> mdlInfo -> genericFcn != ( NULL ) ) {
_GenericFcn fcn = S -> mdlInfo -> genericFcn ; } mw22bjqtbb ( & ( dw -> rtm )
, & ( dw -> rtdw ) ) ; }
#define MDL_START
static void mdlStart ( SimStruct * S ) { djynksnhd4a * dw = ( djynksnhd4a * )
ssGetDWork ( S , 0 ) ; mdlProcessParameters ( S ) ; o2joeltd34 ( & ( dw ->
rtm ) , & ( dw -> rtb ) , & ( dw -> rtdw ) ) ; } static void mdlOutputs (
SimStruct * S , int_T tid ) { djynksnhd4a * dw = ( djynksnhd4a * ) ssGetDWork
( S , 0 ) ; real_T const * i_hslookaa2r = ( real_T * ) ssGetInputPortSignal (
S , 0 ) ; real_T const * i_ixstttuxj5 = ( real_T * ) ssGetInputPortSignal ( S
, 1 ) ; real_T const * i_bbhxqbcec1 = ( real_T * ) ssGetInputPortSignal ( S ,
8 ) ; real_T const * i_h3br443frc = ( real_T * ) ssGetInputPortSignal ( S , 9
) ; real_T const * i_fupllqef0r = ( real_T * ) ssGetInputPortSignal ( S , 10
) ; real_T const * i_olrdiqcc2q = ( real_T * ) ssGetInputPortSignal ( S , 11
) ; lietroj0em * localX = ( lietroj0em * ) ssGetContStates ( S ) ; real_T *
o_B_30_1 = ( real_T * ) ssGetOutputPortSignal ( S , 0 ) ; real_T * o_B_30_2 =
( real_T * ) ssGetOutputPortSignal ( S , 1 ) ; real_T * o_B_30_3 = ( real_T *
) ssGetOutputPortSignal ( S , 2 ) ; real_T * o_B_30_4 = ( real_T * )
ssGetOutputPortSignal ( S , 3 ) ; if ( tid == PARAMETER_TUNING_TID ) {
Torque_Vectoring_Model_CoolingTID3 ( & ( dw -> rtm ) , & ( dw -> rtb ) , & (
dw -> rtdw ) ) ; } if ( tid != CONSTANT_TID && tid != PARAMETER_TUNING_TID )
{ if ( ssIsSampleHit ( S , 0 , tid ) || ssIsMinorTimeStep ( S ) ) {
Torque_Vectoring_Model_CoolingTID0 ( & ( dw -> rtm ) , i_hslookaa2r ,
i_ixstttuxj5 , i_bbhxqbcec1 , i_h3br443frc , i_fupllqef0r , i_olrdiqcc2q , &
( dw -> rtb ) , & ( dw -> rtdw ) , localX ) ; } if ( ssIsSampleHit ( S , 1 ,
tid ) ) { Torque_Vectoring_Model_CoolingTID1 ( ) ; } if ( ssIsSampleHit ( S ,
2 , tid ) ) { Torque_Vectoring_Model_CoolingTID2 ( & ( dw -> rtm ) , o_B_30_1
, o_B_30_2 , o_B_30_3 , o_B_30_4 , & ( dw -> rtb ) , & ( dw -> rtdw ) ) ; } }
}
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { djynksnhd4a * dw = (
djynksnhd4a * ) ssGetDWork ( S , 0 ) ; real_T const * i_kvyqmtegef = ( real_T
* ) ssGetInputPortSignal ( S , 12 ) ; real_T const * i_n4oyk2n2pb = ( real_T
* ) ssGetInputPortSignal ( S , 13 ) ; real_T const * i_nqp2kxupmr = ( real_T
* ) ssGetInputPortSignal ( S , 14 ) ; real_T const * i_ebr32ao12z = ( real_T
* ) ssGetInputPortSignal ( S , 15 ) ; real_T const * i_jt5aam3ekr = ( real_T
* ) ssGetInputPortSignal ( S , 16 ) ; real_T const * i_i3xskpae5z = ( real_T
* ) ssGetInputPortSignal ( S , 17 ) ; real_T const * i_fitchxcadd = ( real_T
* ) ssGetInputPortSignal ( S , 18 ) ; real_T const * i_jep4vwjut0 = ( real_T
* ) ssGetInputPortSignal ( S , 19 ) ; real_T const * i_i2azpvjwnq = ( real_T
* ) ssGetInputPortSignal ( S , 20 ) ; real_T const * i_ausnbtx2ku = ( real_T
* ) ssGetInputPortSignal ( S , 21 ) ; real_T const * i_dslb2pf2ju = ( real_T
* ) ssGetInputPortSignal ( S , 22 ) ; if ( ssIsSampleHit ( S , 0 , tid ) ) {
icxn3b14hxTID0 ( & ( dw -> rtm ) , i_kvyqmtegef , i_n4oyk2n2pb , i_nqp2kxupmr
, i_ebr32ao12z , i_jt5aam3ekr , i_i3xskpae5z , i_fitchxcadd , i_jep4vwjut0 ,
i_i2azpvjwnq , i_ausnbtx2ku , i_dslb2pf2ju , & ( dw -> rtdw ) ) ; } if (
ssIsSampleHit ( S , 1 , tid ) ) { icxn3b14hxTID1 ( ) ; } if ( ssIsSampleHit (
S , 2 , tid ) ) { icxn3b14hxTID2 ( & ( dw -> rtb ) , & ( dw -> rtdw ) ) ; }
return ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { djynksnhd4a * dw = (
djynksnhd4a * ) ssGetDWork ( S , 0 ) ; real_T const * i_jadgnwuby2 = ( real_T
* ) ssGetInputPortSignal ( S , 2 ) ; real_T const * i_l3imfnqvf4 = ( real_T *
) ssGetInputPortSignal ( S , 3 ) ; real_T const * i_fu32yu3a2y = ( real_T * )
ssGetInputPortSignal ( S , 4 ) ; real_T const * i_ijjnas2qpp = ( real_T * )
ssGetInputPortSignal ( S , 5 ) ; real_T const * i_em0e3ce0ei = ( real_T * )
ssGetInputPortSignal ( S , 6 ) ; real_T const * i_edcvnu11ku = ( real_T * )
ssGetInputPortSignal ( S , 7 ) ; lietroj0em * localX = ( lietroj0em * )
ssGetContStates ( S ) ; j4t221w5my * localXdot = ( j4t221w5my * ) ssGetdX ( S
) ; pi0v2qwoey ( i_jadgnwuby2 , i_l3imfnqvf4 , i_fu32yu3a2y , i_ijjnas2qpp ,
i_em0e3ce0ei , i_edcvnu11ku , localX , localXdot ) ; } static void
mdlTerminate ( SimStruct * S ) { djynksnhd4a * dw = ( djynksnhd4a * )
ssGetDWork ( S , 0 ) ; dcficcp3zq ( & ( dw -> rtm ) , & ( dw -> rtdw ) ) ;
return ; }
#define MDL_CLEANUP_RUNTIME_RESOURCES
static void mdlCleanupRuntimeResources ( SimStruct * S ) { djynksnhd4a * dw =
( djynksnhd4a * ) ssGetDWork ( S , 0 ) ; dgkz1olqma ( & ( dw -> rtm ) , & (
dw -> rtdw ) ) ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static mxArray * mdlGetSimState ( SimStruct * S ) { static const char *
simStateFieldNames [ 6 ] = { "localX" , "mdlrefDW" , "disallowedStateData" ,
"tNext" , "tNextTid" , "nonContDerivSigInfoPrevVal" , } ; mxArray * ss =
mxCreateStructMatrix ( 1 , 1 , 6 , simStateFieldNames ) ; { const lietroj0em
* localX = ( const lietroj0em * ) ssGetContStates ( S ) ; const size_t
numBytes = sizeof ( lietroj0em ) ; mxArray * storedX = mxCreateNumericMatrix
( 1 , numBytes , mxUINT8_CLASS , mxREAL ) ; UINT8_T * rawData = ( UINT8_T * )
mxGetData ( storedX ) ; memcpy ( & rawData [ 0 ] , localX , numBytes ) ;
mxSetFieldByNumber ( ss , 0 , 0 , storedX ) ; } { mxArray * mdlrefDW =
mr_Torque_Vectoring_Model_Cooling_GetDWork ( ssGetDWork ( S , 0 ) ) ;
mxSetFieldByNumber ( ss , 0 , 1 , mdlrefDW ) ; } { mxArray * data =
mr_Torque_Vectoring_Model_Cooling_GetSimStateDisallowedBlocks ( ) ;
mxSetFieldByNumber ( ss , 0 , 2 , data ) ; } ; mxSetFieldByNumber ( ss , 0 ,
3 , mxCreateDoubleScalar ( ( double ) ssGetTNext ( S ) ) ) ;
mxSetFieldByNumber ( ss , 0 , 4 , mxCreateDoubleScalar ( ( double )
ssGetTNextTid ( S ) ) ) ; return ss ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static void mdlSetSimState ( SimStruct * S , const mxArray * ss ) { {
lietroj0em * localX = ( lietroj0em * ) ssGetContStates ( S ) ; const size_t
numBytes = sizeof ( lietroj0em ) ; const mxArray * storedX =
mxGetFieldByNumber ( ss , 0 , 0 ) ; const UINT8_T * rawData = ( const UINT8_T
* ) mxGetData ( storedX ) ; memcpy ( localX , & rawData [ 0 ] , numBytes ) ;
} mr_Torque_Vectoring_Model_Cooling_SetDWork ( ssGetDWork ( S , 0 ) ,
mxGetFieldByNumber ( ss , 0 , 1 ) ) ; ssSetTNext ( S , ( time_T ) mxGetScalar
( mxGetFieldByNumber ( ss , 0 , 3 ) ) ) ; ssSetTNextTid ( S , ( int_T )
mxGetScalar ( mxGetFieldByNumber ( ss , 0 , 4 ) ) ) ; }
#ifdef MATLAB_MEX_FILE 
#include "simulink.c"
#include "fixedpoint.c"
#else
#error Assertion failed: file must be compiled as a MEX-file
#endif
