/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LowVoltageInverter.h
 *
 * Code generated for Simulink model 'LowVoltageInverter'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Dec 10 15:26:04 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LowVoltageInverter_h_
#define RTW_HEADER_LowVoltageInverter_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef LowVoltageInverter_COMMON_INCLUDES_
#define LowVoltageInverter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LowVoltageInverter_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* user code (top of header file) */
#include "constant_defines.h"
#include "id_can.h"
#include "adcFcnLib.h"
//#include "canFcnLib.h"
#include "gpioFcnLib.h"
//#include "i2cFcnLib.h"
//#include "i2sFcnLib.h"
#include "pwmFcnLib.h"
#include "spiFcnLib.h"
#include "usartFcnLib.h"
#include "BusDefinition.h"
#ifndef struct_tag_4B5c9t1JtSUztS9hrJrCFG
#define struct_tag_4B5c9t1JtSUztS9hrJrCFG

struct tag_4B5c9t1JtSUztS9hrJrCFG
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[9];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_4B5c9t1JtSUztS9hrJrCFG */

#ifndef typedef_g_dsp_internal_SlidingWindowAve
#define typedef_g_dsp_internal_SlidingWindowAve

typedef struct tag_4B5c9t1JtSUztS9hrJrCFG g_dsp_internal_SlidingWindowAve;

#endif                             /* typedef_g_dsp_internal_SlidingWindowAve */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap;

#endif                                 /* typedef_cell_wrap */

#ifndef struct_tag_fvggScuiyshoksoPP6S2aF
#define struct_tag_fvggScuiyshoksoPP6S2aF

struct tag_fvggScuiyshoksoPP6S2aF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  g_dsp_internal_SlidingWindowAve *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowAve _pobj0;
};

#endif                                 /* struct_tag_fvggScuiyshoksoPP6S2aF */

#ifndef typedef_dsp_simulink_MovingAverage
#define typedef_dsp_simulink_MovingAverage

typedef struct tag_fvggScuiyshoksoPP6S2aF dsp_simulink_MovingAverage;

#endif                                 /* typedef_dsp_simulink_MovingAverage */

#ifndef struct_tag_UeG7yjL5UU0cwdA60Vt2WE
#define struct_tag_UeG7yjL5UU0cwdA60Vt2WE

struct tag_UeG7yjL5UU0cwdA60Vt2WE
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pWinLen;
  real_T pBuf[10];
  real_T pHeap[10];
  real_T pMidHeap;
  real_T pIdx;
  real_T pPos[10];
  real_T pMinHeapLength;
  real_T pMaxHeapLength;
};

#endif                                 /* struct_tag_UeG7yjL5UU0cwdA60Vt2WE */

#ifndef typedef_c_dsp_internal_MedianFilterCG
#define typedef_c_dsp_internal_MedianFilterCG

typedef struct tag_UeG7yjL5UU0cwdA60Vt2WE c_dsp_internal_MedianFilterCG;

#endif                               /* typedef_c_dsp_internal_MedianFilterCG */

#ifndef struct_tag_efPzRkKwjmFe5pvHGi5ekB
#define struct_tag_efPzRkKwjmFe5pvHGi5ekB

struct tag_efPzRkKwjmFe5pvHGi5ekB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap inputVarSize;
  int32_T NumChannels;
  c_dsp_internal_MedianFilterCG pMID;
};

#endif                                 /* struct_tag_efPzRkKwjmFe5pvHGi5ekB */

#ifndef typedef_dsp_MedianFilter
#define typedef_dsp_MedianFilter

typedef struct tag_efPzRkKwjmFe5pvHGi5ekB dsp_MedianFilter;

#endif                                 /* typedef_dsp_MedianFilter */

/* Block signals and states (default storage) for system '<S9>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage obj;      /* '<S9>/Moving Average' */
  real_T MovingAverage_h;              /* '<S9>/Moving Average' */
  boolean_T objisempty;                /* '<S9>/Moving Average' */
} DW_MovingAverage;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_MovingAverage MovingAverage1;     /* '<S9>/Moving Average' */
  DW_MovingAverage MovingAverage_b;    /* '<S9>/Moving Average' */
  dsp_MedianFilter obj;                /* '<S17>/Median Filter2' */
  real_T Divide[2];                    /* '<S18>/Divide' */
  real_T DiscreteTransferFcn2_states[3];/* '<S17>/Discrete Transfer Fcn2' */
  real_T TmpRTBAtClarkInport1_Buffer[3];/* synthesized block */
  real_T TmpRTBAtOn_Off_LogicOutport1; /* '<Root>/On_Off_Logic' */
  real_T A;                            /* '<S5>/Gain3' */
  real_T A_b;                          /* '<S5>/Gain4' */
  real_T A_c;                          /* '<S5>/Gain5' */
  real_T Saturation;                   /* '<S69>/Saturation' */
  real_T ActualTorque;
      /* '<S1>/BusConversion_InsertedFor_MotorFeedback_Outport_1_at_inport_0' */
  real_T Add1;                         /* '<S27>/Add1' */
  real_T U;                            /* '<S14>/Chart' */
  real_T V;                            /* '<S14>/Chart' */
  real_T W;                            /* '<S14>/Chart' */
  real_T Integrator_DSTATE;            /* '<S62>/Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S27>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S12>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S13>/Discrete-Time Integrator' */
  real_T TmpRTBAtOn_Off_LogicOutport1_Bu;/* synthesized block */
  real_T TmpRTBAtAdd2Inport2_Buffer;   /* synthesized block */
  real_T T;                            /* '<S14>/Chart' */
  real_T Pi;                           /* '<S14>/Chart' */
  real_T Base_speed;                   /* '<S11>/Chart1' */
  int32_T chartGlobalTickCounter;      /* '<S3>/On_Off_Chart' */
  int32_T countReferenceTick_1;        /* '<S3>/On_Off_Chart' */
  uint16_T Width;                      /* '<S82>/Width' */
  uint16_T On;                         /* '<S6>/Chart' */
  uint16_T Vel_Target;                 /* '<S6>/Chart' */
  uint8_T USART[17];                   /* '<Root>/Data Store Memory' */
  uint8_T is_active_c2_LowVoltageInverter;/* '<S3>/On_Off_Chart' */
  uint8_T is_c2_LowVoltageInverter;    /* '<S3>/On_Off_Chart' */
  boolean_T countCondWasTrueAtLastTimeStep_;/* '<S3>/On_Off_Chart' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [2/3 -1/3 -1/3;0 1/sqrt(3) -1/sqrt(3)]
   * Referenced by: '<S8>/Clark'
   */
  real_T Clark_Gain[6];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T IuLSB;                        /* '<Root>/IuLSB' */
  real_T IvLSB;                        /* '<Root>/IvLSB' */
  real_T IwLSB;                        /* '<Root>/IwLSB' */
  uint8_T Msg[4];                      /* '<Root>/Msg' */
  real_T Theta;                        /* '<Root>/Theta' */
} ExtU;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID0_1;
      uint16_T TID2_4;
      uint16_T TID3_5;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void LowVoltageInverter_initialize(void);
extern void Isensing(void);
extern void FOC(void);
extern void LowVoltageInverter_step2(void);
extern void PWMSet(void);
extern void LoopVel(void);
extern void OnOffLogic(void);
extern void UsartTx(void);
extern void UsartRx(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Cast' : Eliminate redundant data type conversion
 * Block '<S2>/Cast' : Eliminate redundant data type conversion
 * Block '<S59>/Integral Gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LowVoltageInverter'
 * '<S1>'   : 'LowVoltageInverter/FOC'
 * '<S2>'   : 'LowVoltageInverter/Loop_Vel'
 * '<S3>'   : 'LowVoltageInverter/On_Off_Logic'
 * '<S4>'   : 'LowVoltageInverter/PWMSet'
 * '<S5>'   : 'LowVoltageInverter/Subsystem'
 * '<S6>'   : 'LowVoltageInverter/UsartRx'
 * '<S7>'   : 'LowVoltageInverter/UsartTx'
 * '<S8>'   : 'LowVoltageInverter/FOC/Clark_Park'
 * '<S9>'   : 'LowVoltageInverter/FOC/FeedForward1'
 * '<S10>'  : 'LowVoltageInverter/FOC/Inverse_Park'
 * '<S11>'  : 'LowVoltageInverter/FOC/MTPA'
 * '<S12>'  : 'LowVoltageInverter/FOC/PI_d'
 * '<S13>'  : 'LowVoltageInverter/FOC/PI_q'
 * '<S14>'  : 'LowVoltageInverter/FOC/SVM'
 * '<S15>'  : 'LowVoltageInverter/FOC/Saturation Dynamic1'
 * '<S16>'  : 'LowVoltageInverter/FOC/Saturation Dynamic2'
 * '<S17>'  : 'LowVoltageInverter/FOC/Tracker'
 * '<S18>'  : 'LowVoltageInverter/FOC/Clark_Park/Park'
 * '<S19>'  : 'LowVoltageInverter/FOC/Inverse_Park/Inverse_Park'
 * '<S20>'  : 'LowVoltageInverter/FOC/MTPA/Chart1'
 * '<S21>'  : 'LowVoltageInverter/FOC/MTPA/Saturation Dynamic2'
 * '<S22>'  : 'LowVoltageInverter/FOC/MTPA/iq_mtpa_calc2'
 * '<S23>'  : 'LowVoltageInverter/FOC/SVM/Chart'
 * '<S24>'  : 'LowVoltageInverter/FOC/Tracker/IIR Filter2'
 * '<S25>'  : 'LowVoltageInverter/FOC/Tracker/IIR Filter2/IIR Filter'
 * '<S26>'  : 'LowVoltageInverter/FOC/Tracker/IIR Filter2/IIR Filter/Low-pass'
 * '<S27>'  : 'LowVoltageInverter/FOC/Tracker/IIR Filter2/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S28>'  : 'LowVoltageInverter/Loop_Vel/PID Controller'
 * '<S29>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Anti-windup'
 * '<S30>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/D Gain'
 * '<S31>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Filter'
 * '<S32>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Filter ICs'
 * '<S33>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/I Gain'
 * '<S34>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Ideal P Gain'
 * '<S35>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Ideal P Gain Fdbk'
 * '<S36>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Integrator'
 * '<S37>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Integrator ICs'
 * '<S38>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/N Copy'
 * '<S39>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/N Gain'
 * '<S40>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/P Copy'
 * '<S41>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Parallel P Gain'
 * '<S42>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Reset Signal'
 * '<S43>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Saturation'
 * '<S44>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Saturation Fdbk'
 * '<S45>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Sum'
 * '<S46>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Sum Fdbk'
 * '<S47>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Tracking Mode'
 * '<S48>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Tracking Mode Sum'
 * '<S49>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Tsamp - Integral'
 * '<S50>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Tsamp - Ngain'
 * '<S51>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/postSat Signal'
 * '<S52>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/preSat Signal'
 * '<S53>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S54>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S55>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S56>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/D Gain/Disabled'
 * '<S57>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Filter/Disabled'
 * '<S58>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Filter ICs/Disabled'
 * '<S59>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/I Gain/Internal Parameters'
 * '<S60>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Ideal P Gain/Passthrough'
 * '<S61>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S62>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Integrator/Discrete'
 * '<S63>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Integrator ICs/Internal IC'
 * '<S64>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S65>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/N Gain/Disabled'
 * '<S66>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/P Copy/Disabled'
 * '<S67>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S68>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Reset Signal/Disabled'
 * '<S69>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Saturation/Enabled'
 * '<S70>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Saturation Fdbk/Disabled'
 * '<S71>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Sum/Sum_PI'
 * '<S72>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Sum Fdbk/Disabled'
 * '<S73>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Tracking Mode/Disabled'
 * '<S74>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S75>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Tsamp - Integral/Passthrough'
 * '<S76>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S77>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/postSat Signal/Forward_Path'
 * '<S78>'  : 'LowVoltageInverter/Loop_Vel/PID Controller/preSat Signal/Forward_Path'
 * '<S79>'  : 'LowVoltageInverter/On_Off_Logic/On_Off_Chart'
 * '<S80>'  : 'LowVoltageInverter/PWMSet/Chart'
 * '<S81>'  : 'LowVoltageInverter/UsartRx/Chart'
 * '<S82>'  : 'LowVoltageInverter/UsartTx/Subsystem'
 * '<S83>'  : 'LowVoltageInverter/UsartTx/Subsystem/Bit Shift'
 * '<S84>'  : 'LowVoltageInverter/UsartTx/Subsystem/Bit Shift/bit_shift'
 */
#endif                                 /* RTW_HEADER_LowVoltageInverter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
