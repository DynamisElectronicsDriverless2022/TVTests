#ifndef RTW_HEADER_Torque_Vectoring_Model_Cooling_private_h_
#define RTW_HEADER_Torque_Vectoring_Model_Cooling_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Torque_Vectoring_Model_Cooling.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "simtarget/slMdlrefSimTargetCoreHeaders.h"
#include "simtarget/slMdlrefSimTargetInstrumentationHeaders.h"
#include "messages/slMessagesSfcnBridge.h"
#include "dynamic_matrix/dynamicMatrixSFcnAPI.h"
#include "sl_fileio_rtw.h"
extern const char * rt_GetMatSignalLoggingFileName ( void ) ; extern const
char * rt_GetMatSigLogSelectorFileName ( void ) ; extern void *
rt_GetOSigstreamManager ( void ) ; extern void * *
rt_GetOSigstreamManagerAddr ( void ) ; extern void * rt_slioCatalogue ( void
) ; extern void * * rt_slioCatalogueAddr ( void ) ; extern void
rt_ssSet_slErrMsg ( void * S , void * diag ) ; extern void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) ; extern void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) ; extern const char *
rt_CreateFullPathToTop ( const char * toppath , const char * subpath ) ;
extern boolean_T slIsRapidAcceleratorSimulating ( void ) ; extern void
rt_RAccelReplaceFromFilename ( const char * blockpath , char * fileNam ) ;
extern void rt_RAccelReplaceToFilename ( const char * blockpath , char *
fileNam ) ; extern void slsaCacheDWorkPointerForSimTargetOP ( void * ss ,
void * * ptr ) ; extern void slsaCacheDWorkDataForSimTargetOP ( void * ss ,
void * ptr , unsigned int sizeInBytes ) ; extern void
slsaSaveRawMemoryForSimTargetOP ( void * ss , const char * key , void * * ptr
, unsigned int sizeInBytes , void * ( * customOPSaveFcn ) ( void * dworkPtr ,
unsigned int * sizeInBytes ) , void ( * customOPRestoreFcn ) ( void *
dworkPtr , const void * data , unsigned int sizeInBytes ) ) ; extern void *
gblLoggingInterval ;
#ifndef rtmDisableTaskUsingRateIndex
#define rtmDisableTaskUsingRateIndex(rtm, sti) simTgtDisableTaskUsingRateIndex(ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[sti])
#endif
#ifndef rtmEnableTaskUsingRateIndex
#define rtmEnableTaskUsingRateIndex(rtm, sti) simTgtEnableTaskUsingRateIndex(ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[sti])
#endif
#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm) ssIsFirstInitCond((rtm)->_mdlRefSfcnS)
#endif
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm) ssIsMajorTimeStep((rtm)->_mdlRefSfcnS)
#endif
#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm) ssIsMinorTimeStep((rtm)->_mdlRefSfcnS)
#endif
#ifndef rtmRaiseEvent
#define rtmRaiseEvent(rtm, runtimeEventIndex) simTgtRaiseEvent(ssGetRootSS((rtm)->_mdlRefSfcnS), [runtimeEventIndex])
#endif
#ifndef rtmRaiseEventWithEnqueue
#define rtmRaiseEventWithEnqueue(rtm, runtimeEventIndex) simTgtRaiseEventWithEnqueue(ssGetRootSS((rtm)->_mdlRefSfcnS), [runtimeEventIndex])
#endif
#ifndef rtmIsSpecialSampleHit
#define rtmIsSpecialSampleHit(rtm, sti, prom_sti, tid) ssIsSpecialSampleHit( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[sti], (rtm)->Timing.mdlref_GlobalTID[prom_sti], tid)
#endif
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val) ((rtm)->Timing.tFinal = (val))
#endif
#ifndef UCHAR_MAX
#include <limits.h>
#endif
#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif
#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) ((rtm)->DataMapInfo)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) ((rtm)->DataMapInfo = (val))
#endif
#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif
#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm) ((rtm)->Timing.tFinal)
#endif
#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm) ((rtm)->Timing.sampleHitArray)
#endif
#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm) ((rtm)->Timing.stepSize)
#endif
#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm) ((rtm)->zCCacheNeedsReset)
#endif
#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif
#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm) ((rtm)->Timing.timeOfLastOutput)
#endif
#ifndef rtmGetClockTick0
#define rtmGetClockTick0(rtm) ssGetClockTick( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[0])
#endif
#ifndef rtmGetClockTick1
#define rtmGetClockTick1(rtm) ssGetClockTick( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[1])
#endif
#ifndef rtmGetClockTick2
#define rtmGetClockTick2(rtm) ssGetClockTick( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[2])
#endif
#ifndef rtmGetClockTick3
#define rtmGetClockTick3(rtm) ssGetClockTick( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[3])
#endif
#ifndef rtmGetClockTickH0
#define rtmGetClockTickH0(rtm) ssGetClockTickH( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[0])
#endif
#ifndef rtmGetClockTickH1
#define rtmGetClockTickH1(rtm) ssGetClockTickH( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[1])
#endif
#ifndef rtmGetClockTickH2
#define rtmGetClockTickH2(rtm) ssGetClockTickH( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[2])
#endif
#ifndef rtmGetClockTickH3
#define rtmGetClockTickH3(rtm) ssGetClockTickH( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[3])
#endif
#ifndef rtmGetLogOutput
#define rtmGetLogOutput(rtm) ssGetLogOutput((rtm)->_mdlRefSfcnS)
#endif
#ifndef rtmSetSampleHit
#define rtmSetSampleHit(rtm, sti, tid, val) _ssSetSampleHit(ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[sti], val)
#endif
#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid) ssIsSampleHit( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[sti], tid)
#endif
#ifndef rtmGetT
#define rtmGetT(rtm) (ssGetT((rtm)->_mdlRefSfcnS))
#endif
#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm) (ssGetTFinal((rtm)->_mdlRefSfcnS))
#endif
#ifndef rtmGetTNextWasAdjusted
#define rtmGetTNextWasAdjusted(rtm, sti) (ssGetTNextWasAdjusted((rtm)->_mdlRefSfcnS,  (rtm)->Timing.mdlref_GlobalTID[sti]))
#endif
#ifndef rtmGetTStart
#define rtmGetTStart(rtm) (ssGetTStart((rtm)->_mdlRefSfcnS))
#endif
#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti) ssGetTaskTime( ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[sti])
#endif
#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val) _ssSetTaskTime(ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[sti], val)
#endif
#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm) (ssGetTimeOfLastOutput((rtm)->_mdlRefSfcnS))
#endif
#ifndef rtmGetVarNextHitTime
#define rtmGetVarNextHitTime(rtm, sti) (_ssGetVarNextHitTime((rtm)->_mdlRefSfcnS,  (int)(ssGetOffsetTime(ssGetRootSS((rtm)->_mdlRefSfcnS), (rtm)->Timing.mdlref_GlobalTID[sti+3]))))
#endif
#ifndef rtmSetVarNextHitTime
#define rtmSetVarNextHitTime(rtm, sti, val) ssSetTimeOfNextVarHit((rtm)->_mdlRefSfcnS,  (rtm)->Timing.mdlref_GlobalTID[sti], val)
#endif
extern ms4e4ssiy0o ms4e4ssiy0 ; extern void acados_solver_sfunction_dt_model
( SimStruct * rts ) ;
#endif
