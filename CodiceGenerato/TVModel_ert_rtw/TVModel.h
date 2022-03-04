/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Jan 14 15:10:40 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TVModel_h_
#define RTW_HEADER_TVModel_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef TVModel_COMMON_INCLUDES_
#define TVModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TVModel_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
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

/* Block signals and states (default storage) for system '<S3>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage obj;      /* '<S3>/Moving Average' */
  real_T MovingAverage_g;              /* '<S3>/Moving Average' */
  boolean_T objisempty;                /* '<S3>/Moving Average' */
} DW_MovingAverage;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_MovingAverage MovingAverage1;     /* '<S3>/Moving Average' */
  DW_MovingAverage MovingAverage_p;    /* '<S3>/Moving Average' */
  dsp_MedianFilter obj;                /* '<S11>/Median Filter2' */
  real_T DiscreteTransferFcn2_states[3];/* '<S11>/Discrete Transfer Fcn2' */
  real_T UnitDelay_DSTATE;             /* '<S21>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S6>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S7>/Discrete-Time Integrator' */
  real_T T;                            /* '<S8>/Chart' */
  real_T Pi;                           /* '<S8>/Chart' */
  real_T Base_speed;                   /* '<S5>/Chart1' */
} DW;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void TVModel_initialize(void);
extern void TV(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Cast' : Eliminate redundant data type conversion
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
 * '<Root>' : 'TVModel'
 * '<S1>'   : 'TVModel/TV'
 * '<S2>'   : 'TVModel/TV/Clark_Park'
 * '<S3>'   : 'TVModel/TV/FeedForward1'
 * '<S4>'   : 'TVModel/TV/Inverse_Park'
 * '<S5>'   : 'TVModel/TV/MTPA'
 * '<S6>'   : 'TVModel/TV/PI_d'
 * '<S7>'   : 'TVModel/TV/PI_q'
 * '<S8>'   : 'TVModel/TV/SVM'
 * '<S9>'   : 'TVModel/TV/Saturation Dynamic1'
 * '<S10>'  : 'TVModel/TV/Saturation Dynamic2'
 * '<S11>'  : 'TVModel/TV/Tracker'
 * '<S12>'  : 'TVModel/TV/Clark_Park/Park'
 * '<S13>'  : 'TVModel/TV/Inverse_Park/Inverse_Park'
 * '<S14>'  : 'TVModel/TV/MTPA/Chart1'
 * '<S15>'  : 'TVModel/TV/MTPA/Saturation Dynamic2'
 * '<S16>'  : 'TVModel/TV/MTPA/iq_mtpa_calc2'
 * '<S17>'  : 'TVModel/TV/SVM/Chart'
 * '<S18>'  : 'TVModel/TV/Tracker/IIR Filter2'
 * '<S19>'  : 'TVModel/TV/Tracker/IIR Filter2/IIR Filter'
 * '<S20>'  : 'TVModel/TV/Tracker/IIR Filter2/IIR Filter/Low-pass'
 * '<S21>'  : 'TVModel/TV/Tracker/IIR Filter2/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
