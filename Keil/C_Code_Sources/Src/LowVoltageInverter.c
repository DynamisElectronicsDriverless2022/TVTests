/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LowVoltageInverter.c
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

#include "LowVoltageInverter.h"

/* Named constants for Chart: '<S3>/On_Off_Chart' */
#define IN_Off                         ((uint8_T)1U)
#define IN_On                          ((uint8_T)2U)
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
static void MovingAverage_Init(DW_MovingAverage *localDW);
static void MovingAverage(real_T rtu_0, DW_MovingAverage *localDW);

/* Forward declaration for local functions */
static void MedianFilterCG_resetImpl(c_dsp_internal_MedianFilterCG *obj);
static void MedianFilterCG_trickleDownMax(c_dsp_internal_MedianFilterCG *obj,
  real_T i);
static void MedianFilterCG_trickleDownMin(c_dsp_internal_MedianFilterCG *obj,
  real_T i);
static void CalculateTs(real_T Alfa, real_T *T0, real_T *T1, real_T *T2, const
  real_T *NormalizedAmplitude);
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/* System initialize for atomic system: */
static void MovingAverage_Init(DW_MovingAverage *localDW)
{
  g_dsp_internal_SlidingWindowAve *iobj_0;
  int32_T i;

  /* Start for MATLABSystem: '<S9>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S9>/Moving Average' */
  iobj_0 = localDW->obj.pStatistic;
  if (iobj_0->isInitialized == 1) {
    iobj_0->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      iobj_0->pCumSumRev[i] = 0.0;
    }

    iobj_0->pCumRevIndex = 1.0;
    iobj_0->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S9>/Moving Average' */
}

/* Output and update for atomic system: */
static void MovingAverage(real_T rtu_0, DW_MovingAverage *localDW)
{
  g_dsp_internal_SlidingWindowAve *obj;
  real_T csumrev[9];
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<S9>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 9; i++) {
    csumrev[i] = obj->pCumSumRev[i];
  }

  modValueRev = obj->pModValueRev;
  z = 0.0;

  /* MATLABSystem: '<S9>/Moving Average' */
  localDW->MovingAverage_h = 0.0;

  /* MATLABSystem: '<S9>/Moving Average' */
  csum += rtu_0;
  if (modValueRev == 0.0) {
    z = csumrev[(int32_T)cumRevIndex - 1] + csum;
  }

  csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 9.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (i = 7; i >= 0; i--) {
      csumrev[i] += csumrev[i + 1];
    }
  }

  if (modValueRev == 0.0) {
    /* MATLABSystem: '<S9>/Moving Average' */
    localDW->MovingAverage_h = z / 10.0;
  }

  obj->pCumSum = csum;
  for (i = 0; i < 9; i++) {
    obj->pCumSumRev[i] = csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }
}

static void MedianFilterCG_resetImpl(c_dsp_internal_MedianFilterCG *obj)
{
  real_T cnt1;
  real_T cnt2;
  int32_T i;
  memset(&obj->pBuf[0], 0, 10U * sizeof(real_T));
  memset(&obj->pPos[0], 0, 10U * sizeof(real_T));
  memset(&obj->pHeap[0], 0, 10U * sizeof(real_T));
  obj->pWinLen = 10.0;
  obj->pIdx = obj->pWinLen;
  obj->pMidHeap = ceil((obj->pWinLen + 1.0) / 2.0);
  obj->pMinHeapLength = trunc((obj->pWinLen - 1.0) / 2.0);
  obj->pMaxHeapLength = trunc(obj->pWinLen / 2.0);
  cnt1 = 1.0;
  cnt2 = obj->pWinLen;
  for (i = 0; i < 10; i++) {
    if (fmod(-(real_T)i + 10.0, 2.0) == 0.0) {
      obj->pPos[9 - i] = cnt1;
      cnt1++;
    } else {
      obj->pPos[9 - i] = cnt2;
      cnt2--;
    }

    obj->pHeap[(int32_T)obj->pPos[9 - i] - 1] = -(real_T)i + 10.0;
  }
}

static void MedianFilterCG_trickleDownMax(c_dsp_internal_MedianFilterCG *obj,
  real_T i)
{
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i >= -obj->pMaxHeapLength)) {
    real_T ind1;
    real_T ind2;
    real_T tmp;
    real_T tmp_0;
    if ((i < -1.0) && (i > -obj->pMaxHeapLength) && (obj->pBuf[(int32_T)
         obj->pHeap[(int32_T)(i + obj->pMidHeap) - 1] - 1] < obj->pBuf[(int32_T)
         obj->pHeap[(int32_T)((i - 1.0) + obj->pMidHeap) - 1] - 1])) {
      i--;
    }

    ind1 = trunc(i / 2.0) + obj->pMidHeap;
    ind2 = i + obj->pMidHeap;
    tmp = obj->pHeap[(int32_T)ind1 - 1];
    tmp_0 = obj->pHeap[(int32_T)ind2 - 1];
    if (!(obj->pBuf[(int32_T)tmp - 1] < obj->pBuf[(int32_T)tmp_0 - 1])) {
      exitg1 = true;
    } else {
      obj->pHeap[(int32_T)ind1 - 1] = tmp_0;
      obj->pHeap[(int32_T)ind2 - 1] = tmp;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)ind1 - 1] - 1] = ind1;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)ind2 - 1] - 1] = ind2;
      i *= 2.0;
    }
  }
}

static void MedianFilterCG_trickleDownMin(c_dsp_internal_MedianFilterCG *obj,
  real_T i)
{
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i <= obj->pMinHeapLength)) {
    real_T ind1;
    real_T ind2;
    real_T tmp;
    real_T tmp_0;
    if ((i > 1.0) && (i < obj->pMinHeapLength) && (obj->pBuf[(int32_T)obj->
         pHeap[(int32_T)((i + 1.0) + obj->pMidHeap) - 1] - 1] < obj->pBuf
         [(int32_T)obj->pHeap[(int32_T)(i + obj->pMidHeap) - 1] - 1])) {
      i++;
    }

    ind1 = i + obj->pMidHeap;
    ind2 = trunc(i / 2.0) + obj->pMidHeap;
    tmp = obj->pHeap[(int32_T)ind1 - 1];
    tmp_0 = obj->pHeap[(int32_T)ind2 - 1];
    if (!(obj->pBuf[(int32_T)tmp - 1] < obj->pBuf[(int32_T)tmp_0 - 1])) {
      exitg1 = true;
    } else {
      obj->pHeap[(int32_T)ind1 - 1] = tmp_0;
      obj->pHeap[(int32_T)ind2 - 1] = tmp;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)ind1 - 1] - 1] = ind1;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)ind2 - 1] - 1] = ind2;
      i *= 2.0;
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T u0_0;
    int32_T u1_0;
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for Chart: '<S14>/Chart' */
static void CalculateTs(real_T Alfa, real_T *T0, real_T *T1, real_T *T2, const
  real_T *NormalizedAmplitude)
{
  *T1 = sin(rtDW.Pi / 3.0 - Alfa) * (rtDW.T * *NormalizedAmplitude);
  *T2 = rtDW.T * *NormalizedAmplitude * sin(Alfa);
  *T0 = (rtDW.T - *T1) - *T2;
}

/* Model step function for TID0 */
void Isensing(void)                    /* Explicit Task: Subsystem */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [1.0E-5s, 0.0s] to Sample time: [0.0001s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 9) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* Outputs for Atomic SubSystem: '<Root>/FOC' */
  /* RateTransition generated from: '<S8>/Clark' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    rtDW.TmpRTBAtClarkInport1_Buffer[0] = rtDW.A_c;
    rtDW.TmpRTBAtClarkInport1_Buffer[1] = rtDW.A;
    rtDW.TmpRTBAtClarkInport1_Buffer[2] = rtDW.A_b;
  }

  /* End of RateTransition generated from: '<S8>/Clark' */
  /* End of Outputs for SubSystem: '<Root>/FOC' */

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Gain: '<S5>/Gain3' incorporates:
   *  Bias: '<S5>/Add Constant1'
   *  Gain: '<S5>/Gain1'
   *  Inport: '<Root>/IvLSB'
   */
  rtDW.A = (0.001220703125 * rtU.IvLSB + -2.5) * 15.15151515151515;

  /* Gain: '<S5>/Gain4' incorporates:
   *  Bias: '<S5>/Add Constant2'
   *  Gain: '<S5>/Gain2'
   *  Inport: '<Root>/IwLSB'
   */
  rtDW.A_b = (0.001220703125 * rtU.IwLSB + -2.5) * 15.15151515151515;

  /* Gain: '<S5>/Gain5' incorporates:
   *  Bias: '<S5>/Add Constant'
   *  Gain: '<S5>/Gain'
   *  Inport: '<Root>/IuLSB'
   */
  rtDW.A_c = (0.001220703125 * rtU.IuLSB + -2.5) * 15.15151515151515;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model step function for TID1 */
void FOC(void)                         /* Explicit Task: FOC */
{
  /* local block i/o variables */
  real_T rtb_Add;
  c_dsp_internal_MedianFilterCG *obj;
  real_T tmp[2];
  real_T CFunction3;
  real_T Divide_tmp;
  real_T NormalizedAmplitude;
  real_T T0;
  real_T Theta;
  real_T p;
  real_T rtb_Saturation3;
  real_T temp;
  real_T vprev;
  int32_T i;

  /* Outputs for Atomic SubSystem: '<Root>/FOC' */
  /* SignalConversion generated from: '<S1>/MotorFeedback_Outport_1' incorporates:
   *  Inport: '<Root>/Theta'
   */
  rtDW.ActualTorque = rtU.Theta;

  /* CFunction: '<S1>/C Function3' incorporates:
   *  Inport: '<Root>/Theta'
   */
  CFunction3 = rtU.Theta * 4.0;

  /* Trigonometry: '<S18>/Cos' incorporates:
   *  Trigonometry: '<S19>/Cos'
   */
  Theta = cos(CFunction3);

  /* Trigonometry: '<S18>/Cos1' incorporates:
   *  Trigonometry: '<S19>/Sin'
   */
  T0 = sin(CFunction3);

  /* Gain: '<S8>/Clark' incorporates:
   *  RateTransition generated from: '<S8>/Clark'
   */
  for (i = 0; i < 2; i++) {
    tmp[i] = (rtConstP.Clark_Gain[i + 2] * rtDW.TmpRTBAtClarkInport1_Buffer[1] +
              rtConstP.Clark_Gain[i] * rtDW.TmpRTBAtClarkInport1_Buffer[0]) +
      rtConstP.Clark_Gain[i + 4] * rtDW.TmpRTBAtClarkInport1_Buffer[2];
  }

  /* End of Gain: '<S8>/Clark' */

  /* Product: '<S18>/Divide' */
  rtDW.Divide[0] = 0.0;

  /* Sum: '<S18>/Add' incorporates:
   *  Gain: '<S18>/Gain1'
   *  Sum: '<S19>/Add'
   *  Trigonometry: '<S18>/Cos'
   *  Trigonometry: '<S18>/Cos1'
   */
  NormalizedAmplitude = 0.0 * T0 + Theta;

  /* Product: '<S18>/Divide' incorporates:
   *  Sum: '<S18>/Add'
   */
  rtDW.Divide[0] += NormalizedAmplitude * tmp[0];

  /* Sum: '<S18>/Add' incorporates:
   *  Gain: '<S18>/Gain'
   *  Sum: '<S19>/Add'
   *  Trigonometry: '<S18>/Cos'
   *  Trigonometry: '<S18>/Cos1'
   */
  Divide_tmp = 0.0 * Theta + T0;

  /* Product: '<S18>/Divide' incorporates:
   *  Sum: '<S18>/Add'
   */
  rtDW.Divide[0] += Divide_tmp * tmp[1];
  rtDW.Divide[1] = 0.0;

  /* Sum: '<S18>/Add' incorporates:
   *  Gain: '<S18>/Gain'
   *  Gain: '<S18>/Gain1'
   *  Sum: '<S19>/Add'
   *  Trigonometry: '<S18>/Cos'
   *  Trigonometry: '<S18>/Cos1'
   */
  Theta = 0.0 * Theta + -T0;

  /* Product: '<S18>/Divide' incorporates:
   *  Sum: '<S18>/Add'
   */
  rtDW.Divide[1] += Theta * tmp[0];
  rtDW.Divide[1] += NormalizedAmplitude * tmp[1];

  /* DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn2' incorporates:
   *  Inport: '<Root>/Theta'
   */
  CFunction3 = ((rtU.Theta - 0.0 * rtDW.DiscreteTransferFcn2_states[0]) - 0.0 *
                rtDW.DiscreteTransferFcn2_states[1]) - 0.0 *
    rtDW.DiscreteTransferFcn2_states[2];
  rtb_Saturation3 = ((18333.333333333332 * CFunction3 + -30000.0 *
                      rtDW.DiscreteTransferFcn2_states[0]) + 15000.0 *
                     rtDW.DiscreteTransferFcn2_states[1]) + -3333.333333333333 *
    rtDW.DiscreteTransferFcn2_states[2];

  /* Saturate: '<S17>/Saturation3' */
  if (rtb_Saturation3 <= -10000.0) {
    rtb_Saturation3 = -10000.0;
  }

  /* End of Saturate: '<S17>/Saturation3' */

  /* MATLABSystem: '<S17>/Median Filter2' */
  obj = &rtDW.obj.pMID;
  if (rtDW.obj.pMID.isInitialized != 1) {
    rtDW.obj.pMID.isSetupComplete = false;
    rtDW.obj.pMID.isInitialized = 1;
    rtDW.obj.pMID.isSetupComplete = true;
    MedianFilterCG_resetImpl(&rtDW.obj.pMID);
  }

  vprev = rtDW.obj.pMID.pBuf[(int32_T)rtDW.obj.pMID.pIdx - 1];
  rtDW.obj.pMID.pBuf[(int32_T)rtDW.obj.pMID.pIdx - 1] = rtb_Saturation3;
  p = rtDW.obj.pMID.pPos[(int32_T)rtDW.obj.pMID.pIdx - 1];
  rtDW.obj.pMID.pIdx++;
  if (rtDW.obj.pMID.pWinLen + 1.0 == rtDW.obj.pMID.pIdx) {
    rtDW.obj.pMID.pIdx = 1.0;
  }

  if (p > rtDW.obj.pMID.pMidHeap) {
    if (vprev < rtb_Saturation3) {
      MedianFilterCG_trickleDownMin(&rtDW.obj.pMID, (p - rtDW.obj.pMID.pMidHeap)
        * 2.0);
    } else {
      boolean_T exitg1;
      rtb_Saturation3 = p - rtDW.obj.pMID.pMidHeap;
      exitg1 = false;
      while ((!exitg1) && (rtb_Saturation3 > 0.0)) {
        boolean_T flag;
        flag = (obj->pBuf[(int32_T)obj->pHeap[(int32_T)(rtb_Saturation3 +
                 obj->pMidHeap) - 1] - 1] < obj->pBuf[(int32_T)obj->pHeap
                [(int32_T)(trunc(rtb_Saturation3 / 2.0) + obj->pMidHeap) - 1] -
                1]);
        if (!flag) {
          exitg1 = true;
        } else {
          vprev = rtb_Saturation3 + obj->pMidHeap;
          p = trunc(rtb_Saturation3 / 2.0) + obj->pMidHeap;
          temp = obj->pHeap[(int32_T)vprev - 1];
          obj->pHeap[(int32_T)vprev - 1] = obj->pHeap[(int32_T)p - 1];
          obj->pHeap[(int32_T)p - 1] = temp;
          obj->pPos[(int32_T)obj->pHeap[(int32_T)vprev - 1] - 1] = vprev;
          obj->pPos[(int32_T)obj->pHeap[(int32_T)p - 1] - 1] = p;
          rtb_Saturation3 = trunc(rtb_Saturation3 / 2.0);
        }
      }

      if (rtb_Saturation3 == 0.0) {
        MedianFilterCG_trickleDownMax(&rtDW.obj.pMID, -1.0);
      }
    }
  } else if (p < rtDW.obj.pMID.pMidHeap) {
    if (rtb_Saturation3 < vprev) {
      MedianFilterCG_trickleDownMax(&rtDW.obj.pMID, (p - rtDW.obj.pMID.pMidHeap)
        * 2.0);
    } else {
      boolean_T exitg1;
      rtb_Saturation3 = p - rtDW.obj.pMID.pMidHeap;
      exitg1 = false;
      while ((!exitg1) && (rtb_Saturation3 < 0.0)) {
        boolean_T flag;
        flag = (obj->pBuf[(int32_T)obj->pHeap[(int32_T)(trunc(rtb_Saturation3 /
                  2.0) + obj->pMidHeap) - 1] - 1] < obj->pBuf[(int32_T)
                obj->pHeap[(int32_T)(rtb_Saturation3 + obj->pMidHeap) - 1] - 1]);
        if (!flag) {
          exitg1 = true;
        } else {
          vprev = trunc(rtb_Saturation3 / 2.0) + obj->pMidHeap;
          p = rtb_Saturation3 + obj->pMidHeap;
          temp = obj->pHeap[(int32_T)vprev - 1];
          obj->pHeap[(int32_T)vprev - 1] = obj->pHeap[(int32_T)p - 1];
          obj->pHeap[(int32_T)p - 1] = temp;
          obj->pPos[(int32_T)obj->pHeap[(int32_T)vprev - 1] - 1] = vprev;
          obj->pPos[(int32_T)obj->pHeap[(int32_T)p - 1] - 1] = p;
          rtb_Saturation3 = trunc(rtb_Saturation3 / 2.0);
        }
      }

      if (rtb_Saturation3 == 0.0) {
        MedianFilterCG_trickleDownMin(&rtDW.obj.pMID, 1.0);
      }
    }
  } else {
    if (rtDW.obj.pMID.pMaxHeapLength != 0.0) {
      MedianFilterCG_trickleDownMax(&rtDW.obj.pMID, -1.0);
    }

    if (rtDW.obj.pMID.pMinHeapLength > 0.0) {
      MedianFilterCG_trickleDownMin(&rtDW.obj.pMID, 1.0);
    }
  }

  rtb_Saturation3 = rtDW.obj.pMID.pBuf[(int32_T)rtDW.obj.pMID.pHeap[(int32_T)
    rtDW.obj.pMID.pMidHeap - 1] - 1];
  rtb_Saturation3 = (rtDW.obj.pMID.pBuf[(int32_T)rtDW.obj.pMID.pHeap[(int32_T)
                     (rtDW.obj.pMID.pMidHeap - 1.0) - 1] - 1] + rtb_Saturation3)
    / 2.0;

  /* Sum: '<S27>/Add1' incorporates:
   *  Constant: '<S27>/Filter_Constant'
   *  Constant: '<S27>/One'
   *  MATLABSystem: '<S17>/Median Filter2'
   *  Product: '<S27>/Product'
   *  Product: '<S27>/Product1'
   *  UnitDelay: '<S27>/Unit Delay'
   */
  rtDW.Add1 = rtb_Saturation3 * 0.01 + 0.99 * rtDW.UnitDelay_DSTATE;

  /* CFunction: '<S9>/C Function3' */
  rtb_Saturation3 = rtDW.Add1 * 4.0;

  /* Sum: '<S9>/Add' incorporates:
   *  CFunction: '<S9>/C Function'
   *  CFunction: '<S9>/C Function1'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product2'
   */
  rtb_Add = rtb_Saturation3 * rtDW.Divide[0] * 0.0029 + 0.075 * rtb_Saturation3;
  MovingAverage(rtb_Add, &rtDW.MovingAverage_b);

  /* CFunction: '<S9>/C Function2' incorporates:
   *  Product: '<S9>/Product1'
   */
  MovingAverage(rtb_Saturation3 * rtDW.Divide[1] * 0.003, &rtDW.MovingAverage1);

  /* Chart: '<S11>/Chart1' */
  if (rtDW.Add1 <= rtDW.Base_speed) {
    rtb_Saturation3 = 0.0;
    p = (real_T)MAX_CURR;
  } else {
    rtb_Saturation3 = (real_T)((BASE_SPEED - rtDW.Add1) * FLUX_LINKAGE /
      (rtDW.Add1 * LD));
    rtb_Saturation3 = (real_T)(rtb_Saturation3 >= (real_T)-MAX_CURR ?
      rtb_Saturation3 : -MAX_CURR);
    p = sqrt(rt_powd_snf((real_T)MAX_CURR, 2.0) - rt_powd_snf(rtb_Saturation3,
              2.0));
  }

  /* End of Chart: '<S11>/Chart1' */

  /* CFunction: '<S12>/C Function1' incorporates:
   *  Sum: '<S1>/Sum'
   */
  rtb_Saturation3 = (rtb_Saturation3 - rtDW.Divide[0]) * 0.0029 * 100.0;

  /* Sum: '<S1>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Sum: '<S12>/Sum'
   */
  vprev = (rtDW.DiscreteTimeIntegrator_DSTATE + rtb_Saturation3) -
    rtDW.MovingAverage1.MovingAverage_h;

  /* Switch: '<S16>/Switch2' incorporates:
   *  CFunction: '<S1>/C Function'
   *  RelationalOperator: '<S16>/LowerRelop1'
   *  RelationalOperator: '<S16>/UpperRelop'
   *  Switch: '<S16>/Switch'
   */
  if (vprev > 12.0) {
    temp = 12.0;
  } else if (vprev < -12.0) {
    /* Switch: '<S16>/Switch' */
    temp = -12.0;
  } else {
    temp = vprev;
  }

  /* End of Switch: '<S16>/Switch2' */

  /* CFunction: '<S22>/C Function3' incorporates:
   *  CFunction: '<S22>/C Function2'
   *  Gain: '<S22>/Gain'
   *  RateTransition: '<Root>/RT1'
   */
  vprev = 0.66666666666666663 * rtDW.Saturation / 0.075 / 4.0;

  /* Switch: '<S21>/Switch2' incorporates:
   *  RelationalOperator: '<S21>/LowerRelop1'
   */
  if (!(vprev > p)) {
    /* Gain: '<S11>/Gain1' */
    p = -p;

    /* Switch: '<S21>/Switch' incorporates:
     *  RelationalOperator: '<S21>/UpperRelop'
     */
    if (!(vprev < p)) {
      p = vprev;
    }

    /* End of Switch: '<S21>/Switch' */
  }

  /* End of Switch: '<S21>/Switch2' */

  /* CFunction: '<S13>/C Function1' incorporates:
   *  Sum: '<S1>/Sum1'
   */
  vprev = (p - rtDW.Divide[1]) * 0.003 * 100.0;

  /* Sum: '<S1>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
   *  Sum: '<S13>/Sum'
   */
  p = (rtDW.DiscreteTimeIntegrator_DSTATE_e + vprev) +
    rtDW.MovingAverage_b.MovingAverage_h;

  /* Switch: '<S15>/Switch2' incorporates:
   *  CFunction: '<S1>/C Function1'
   *  RelationalOperator: '<S15>/LowerRelop1'
   *  RelationalOperator: '<S15>/UpperRelop'
   *  Switch: '<S15>/Switch'
   */
  if (p > 12.0) {
    p = 12.0;
  } else if (p < -12.0) {
    /* Switch: '<S15>/Switch' */
    p = -12.0;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Product: '<S19>/Matrix Multiply' incorporates:
   *  SignalConversion generated from: '<S19>/Matrix Multiply'
   */
  T0 = NormalizedAmplitude * temp + Theta * p;
  p = Divide_tmp * temp + NormalizedAmplitude * p;

  /* Trigonometry: '<S14>/Atan2' */
  Theta = rt_atan2d_snf(T0, p);

  /* CFunction: '<S14>/C Function3' incorporates:
   *  Math: '<S14>/Square'
   *  Math: '<S14>/Square1'
   *  Sqrt: '<S14>/Square Root'
   *  Sum: '<S14>/Add'
   */
  NormalizedAmplitude = sqrt(T0 * T0 + p * p) / 12.0;

  /* Chart: '<S14>/Chart' */
  if ((Theta > 0.0) && (Theta < rtDW.Pi / 3.0)) {
    CalculateTs(Theta, &T0, &p, &temp, &NormalizedAmplitude);
    rtDW.U = (p + temp) + 0.5 * T0;
    rtDW.V = 0.5 * T0 + temp;
    rtDW.W = 0.5 * T0;
  } else {
    p = 2.0 * rtDW.Pi / 3.0;
    if ((Theta > rtDW.Pi / 3.0) && (Theta < p)) {
      CalculateTs(Theta - rtDW.Pi / 3.0, &T0, &p, &temp, &NormalizedAmplitude);
      rtDW.U = 0.5 * T0 + p;
      rtDW.V = (p + temp) + 0.5 * T0;
      rtDW.W = 0.5 * T0;
    } else if ((Theta > p) && (Theta < rtDW.Pi)) {
      CalculateTs(Theta - 2.0 * rtDW.Pi / 3.0, &T0, &p, &temp,
                  &NormalizedAmplitude);
      rtDW.U = 0.5 * T0;
      rtDW.V = (p + temp) + 0.5 * T0;
      rtDW.W = 0.5 * T0 + temp;
    } else {
      p = -2.0 * rtDW.Pi / 3.0;
      if ((Theta > -rtDW.Pi) && (Theta < p)) {
        CalculateTs(Theta + rtDW.Pi, &T0, &p, &temp, &NormalizedAmplitude);
        rtDW.U = 0.5 * T0;
        rtDW.V = 0.5 * T0 + p;
        rtDW.W = (p + temp) + 0.5 * T0;
      } else {
        temp = -rtDW.Pi / 3.0;
        if ((Theta > p) && (Theta < temp)) {
          CalculateTs(Theta + 2.0 * rtDW.Pi / 3.0, &T0, &p, &temp,
                      &NormalizedAmplitude);
          rtDW.U = 0.5 * T0 + temp;
          rtDW.V = 0.5 * T0;
          rtDW.W = (p + temp) + 0.5 * T0;
        } else if ((Theta > temp) && (Theta < 0.0)) {
          CalculateTs(Theta + rtDW.Pi / 3.0, &T0, &p, &temp,
                      &NormalizedAmplitude);
          rtDW.U = (p + temp) + 0.5 * T0;
          rtDW.V = 0.5 * T0;
          rtDW.W = 0.5 * T0 + p;
        }
      }
    }
  }

  /* End of Chart: '<S14>/Chart' */
  /* End of Outputs for SubSystem: '<Root>/FOC' */

  /* Update for Atomic SubSystem: '<Root>/FOC' */
  /* Update for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn2' */
  rtDW.DiscreteTransferFcn2_states[2] = rtDW.DiscreteTransferFcn2_states[1];
  rtDW.DiscreteTransferFcn2_states[1] = rtDW.DiscreteTransferFcn2_states[0];
  rtDW.DiscreteTransferFcn2_states[0] = CFunction3;

  /* Update for UnitDelay: '<S27>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtDW.Add1;

  /* Outputs for Atomic SubSystem: '<Root>/FOC' */
  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  CFunction: '<S12>/C Function2'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += rtb_Saturation3 * 0.982 / 0.0029 *
    0.0001;

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
   *  CFunction: '<S13>/C Function2'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_e += vprev * 0.982 / 0.003 * 0.0001;

  /* End of Outputs for SubSystem: '<Root>/FOC' */
  /* End of Update for SubSystem: '<Root>/FOC' */
}

/* Model step function for TID2 */
void LowVoltageInverter_step2(void)    /* Sample time: [0.0001s, 0.0s] */
{
  real_T rtb_ActualSpeed;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0001s, 0.0s] to Sample time: [0.005s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID2_4)++;
  if ((rtM->Timing.RateInteraction.TID2_4) > 49) {
    rtM->Timing.RateInteraction.TID2_4 = 0;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Loop_Vel' */
  /* RateTransition generated from: '<S2>/Add2' */
  if (rtM->Timing.RateInteraction.TID2_4 == 1) {
    rtDW.TmpRTBAtAdd2Inport2_Buffer = rtb_ActualSpeed;
  }

  /* End of RateTransition generated from: '<S2>/Add2' */
  /* End of Outputs for SubSystem: '<Root>/Loop_Vel' */
}

/* Model step function for TID3 */
void PWMSet(void)                      /* Explicit Task: PWMSet */
{
  real_T rtb_RT3;
  real_T rtb_RT4;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0001s, 0.0s] to Sample time: [0.01s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID3_5)++;
  if ((rtM->Timing.RateInteraction.TID3_5) > 99) {
    rtM->Timing.RateInteraction.TID3_5 = 0;
  }

  /* RateTransition generated from: '<Root>/On_Off_Logic' */
  if (rtM->Timing.RateInteraction.TID3_5 == 1) {
    /* RateTransition generated from: '<Root>/On_Off_Logic' */
    rtDW.TmpRTBAtOn_Off_LogicOutport1 = rtDW.TmpRTBAtOn_Off_LogicOutport1_Bu;
  }

  /* End of RateTransition generated from: '<Root>/On_Off_Logic' */

  /* RateTransition: '<Root>/RT3' */
  rtb_RT3 = rtDW.V;

  /* RateTransition: '<Root>/RT4' */
  rtb_RT4 = rtDW.W;

  /* Outputs for Atomic SubSystem: '<Root>/PWMSet' */
  /* Chart: '<S4>/Chart' incorporates:
   *  RateTransition: '<Root>/RT2'
   */
  if (rtDW.TmpRTBAtOn_Off_LogicOutport1 == 1.0) {
    uint8_T rtb_RT3_0;
    if (rtDW.U < 256.0) {
      if (rtDW.U >= 0.0) {
        rtb_RT3_0 = (uint8_T)rtDW.U;
      } else {
        rtb_RT3_0 = 0U;
      }
    } else {
      rtb_RT3_0 = MAX_uint8_T;
    }

    pwm_setDutyCycle_wrapper((uint8_T)IuTIM, (uint8_T)IuCh, rtb_RT3_0);
    if (rtb_RT3 < 256.0) {
      if (rtb_RT3 >= 0.0) {
        rtb_RT3_0 = (uint8_T)rtb_RT3;
      } else {
        rtb_RT3_0 = 0U;
      }
    } else {
      rtb_RT3_0 = MAX_uint8_T;
    }

    pwm_setDutyCycle_wrapper((uint8_T)IvTIM, (uint8_T)IvCh, rtb_RT3_0);
    if (rtb_RT4 < 256.0) {
      if (rtb_RT4 >= 0.0) {
        rtb_RT3_0 = (uint8_T)rtb_RT4;
      } else {
        rtb_RT3_0 = 0U;
      }
    } else {
      rtb_RT3_0 = MAX_uint8_T;
    }

    pwm_setDutyCycle_wrapper((uint8_T)IwTIM, (uint8_T)IwCh, rtb_RT3_0);
  } else {
    pwm_setDutyCycle_wrapper((uint8_T)IuTIM, (uint8_T)IuCh, 0U);
    pwm_setDutyCycle_wrapper((uint8_T)IvTIM, (uint8_T)IvCh, 0U);
    pwm_setDutyCycle_wrapper((uint8_T)IwTIM, (uint8_T)IwCh, 0U);
  }

  /* End of Chart: '<S4>/Chart' */
  /* End of Outputs for SubSystem: '<Root>/PWMSet' */
}

/* Model step function for TID4 */
void LoopVel(void)                     /* Explicit Task: Loop_Vel */
{
  real_T rtb_Add2;
  real_T rtb_Add2_0;
  real_T rtb_SignPreIntegrator;
  real_T rtb_SignPreIntegrator_0;
  real_T rtb_Sum_g;

  /* Outputs for Atomic SubSystem: '<Root>/Loop_Vel' */
  /* Sum: '<S2>/Add2' incorporates:
   *  RateTransition: '<Root>/RT'
   *  RateTransition generated from: '<S2>/Add2'
   */
  rtb_Add2 = (real_T)rtDW.Vel_Target - rtDW.TmpRTBAtAdd2Inport2_Buffer;

  /* Sum: '<S71>/Sum' incorporates:
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Gain: '<S67>/Proportional Gain'
   */
  rtb_Sum_g = 0.5 * rtb_Add2 + rtDW.Integrator_DSTATE;

  /* DeadZone: '<S55>/DeadZone' incorporates:
   *  Saturate: '<S69>/Saturation'
   */
  if (rtb_Sum_g > 3.19) {
    rtb_SignPreIntegrator = rtb_Sum_g - 3.19;

    /* Saturate: '<S69>/Saturation' */
    rtDW.Saturation = 3.19;
  } else {
    if (rtb_Sum_g >= -3.19) {
      rtb_SignPreIntegrator = 0.0;
    } else {
      rtb_SignPreIntegrator = rtb_Sum_g - -3.19;
    }

    if (rtb_Sum_g < -3.19) {
      /* Saturate: '<S69>/Saturation' */
      rtDW.Saturation = -3.19;
    } else {
      /* Saturate: '<S69>/Saturation' */
      rtDW.Saturation = rtb_Sum_g;
    }
  }

  /* End of DeadZone: '<S55>/DeadZone' */

  /* Signum: '<S53>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_SignPreIntegrator_0 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_SignPreIntegrator_0 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_SignPreIntegrator_0 = 0.0;
  } else {
    rtb_SignPreIntegrator_0 = (rtNaN);
  }

  /* End of Signum: '<S53>/SignPreSat' */

  /* Signum: '<S53>/SignPreIntegrator' */
  if (rtb_Add2 < 0.0) {
    rtb_Add2_0 = -1.0;
  } else if (rtb_Add2 > 0.0) {
    rtb_Add2_0 = 1.0;
  } else if (rtb_Add2 == 0.0) {
    rtb_Add2_0 = 0.0;
  } else {
    rtb_Add2_0 = (rtNaN);
  }

  /* End of Signum: '<S53>/SignPreIntegrator' */

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S53>/Constant1'
   *  DataTypeConversion: '<S53>/DataTypeConv1'
   *  DataTypeConversion: '<S53>/DataTypeConv2'
   *  Gain: '<S53>/ZeroGain'
   *  Logic: '<S53>/AND3'
   *  RelationalOperator: '<S53>/Equal1'
   *  RelationalOperator: '<S53>/NotEqual'
   */
  if ((0.0 * rtb_Sum_g != rtb_SignPreIntegrator) && ((int8_T)
       rtb_SignPreIntegrator_0 == (int8_T)rtb_Add2_0)) {
    rtb_Add2 = 0.0;
  }

  /* End of Switch: '<S53>/Switch' */
  /* End of Outputs for SubSystem: '<Root>/Loop_Vel' */

  /* Update for Atomic SubSystem: '<Root>/Loop_Vel' */
  /* Update for DiscreteIntegrator: '<S62>/Integrator' */
  rtDW.Integrator_DSTATE += 0.005 * rtb_Add2;

  /* End of Update for SubSystem: '<Root>/Loop_Vel' */
}

/* Model step function for TID5 */
void OnOffLogic(void)                  /* Explicit Task: On_Off_Logic */
{
  int32_T rtb_Start;
  uint16_T rtb_TmpRTBAtUsartRxOutport1;
  boolean_T countCondIsTrue;

  /* RateTransition generated from: '<Root>/UsartRx' */
  rtb_TmpRTBAtUsartRxOutport1 = rtDW.On;

  /* Outputs for Atomic SubSystem: '<Root>/On_Off_Logic' */
  /* Chart: '<S3>/On_Off_Chart' */
  rtDW.chartGlobalTickCounter++;
  countCondIsTrue = (rtDW.is_c2_LowVoltageInverter == 1);
  if ((!countCondIsTrue) || (!rtDW.countCondWasTrueAtLastTimeStep_)) {
    rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
  }

  rtDW.countCondWasTrueAtLastTimeStep_ = countCondIsTrue;
  if (rtDW.is_active_c2_LowVoltageInverter == 0U) {
    rtDW.chartGlobalTickCounter = 0;
    rtDW.is_active_c2_LowVoltageInverter = 1U;
    rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
    rtDW.is_c2_LowVoltageInverter = IN_Off;
    rtb_Start = 0;
    rtDW.countCondWasTrueAtLastTimeStep_ = (rtDW.is_c2_LowVoltageInverter == 1);
  } else if (rtDW.is_c2_LowVoltageInverter == IN_Off) {
    rtb_Start = 0;
    countCondIsTrue = (rtDW.is_c2_LowVoltageInverter == 1);
    if ((!countCondIsTrue) || (!rtDW.countCondWasTrueAtLastTimeStep_)) {
      rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
    }

    rtDW.countCondWasTrueAtLastTimeStep_ = countCondIsTrue;
    if ((rtb_TmpRTBAtUsartRxOutport1 == 1) && ((real_T)
         (rtDW.chartGlobalTickCounter - rtDW.countReferenceTick_1) / 100.0 >=
         5.0)) {
      rtDW.is_c2_LowVoltageInverter = IN_On;
      rtb_Start = 1;
    }
  } else {
    /* case IN_On: */
    rtb_Start = 1;
    if (rtb_TmpRTBAtUsartRxOutport1 == 0) {
      rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
      rtDW.is_c2_LowVoltageInverter = IN_Off;
      rtb_Start = 0;
      rtDW.countCondWasTrueAtLastTimeStep_ = (rtDW.is_c2_LowVoltageInverter == 1);
    }
  }

  /* End of Chart: '<S3>/On_Off_Chart' */
  /* End of Outputs for SubSystem: '<Root>/On_Off_Logic' */

  /* RateTransition generated from: '<Root>/On_Off_Logic' */
  rtDW.TmpRTBAtOn_Off_LogicOutport1_Bu = rtb_Start;
}

/* Model step function for TID6 */
void UsartTx(void)                     /* Explicit Task: UsartTx */
{
  int32_T i;
  uint16_T rtb_Cast[7];
  uint8_T rtb_Assignment1[14];
  uint8_T rtb_y[7];

  /* Outputs for Atomic SubSystem: '<Root>/UsartTx' */
  /* DataTypeConversion: '<S82>/Cast' incorporates:
   *  Bias: '<S7>/Add Constant'
   *  Gain: '<S7>/Gain'
   *  RateTransition generated from: '<Root>/RT5'
   *  RateTransition generated from: '<Root>/RT6'
   */
  rtb_Cast[0] = (uint16_T)(100.0 * rtDW.Divide[1] + 32768.0);
  rtb_Cast[1] = (uint16_T)(100.0 * rtDW.Divide[0] + 32768.0);
  rtb_Cast[2] = (uint16_T)(100.0 * rtDW.Add1 + 32768.0);
  rtb_Cast[3] = (uint16_T)(100.0 * rtDW.ActualTorque + 32768.0);
  rtb_Cast[4] = (uint16_T)(100.0 * rtDW.A_c + 32768.0);
  rtb_Cast[5] = (uint16_T)(100.0 * rtDW.A + 32768.0);
  rtb_Cast[6] = (uint16_T)(100.0 * rtDW.A_b + 32768.0);

  /* Outputs for Atomic SubSystem: '<S82>/Bit Shift' */
  for (i = 0; i < 7; i++) {
    int32_T rtb_Assignment1_tmp;

    /* MATLAB Function: '<S83>/bit_shift' incorporates:
     *  DataTypeConversion: '<S82>/Cast'
     */
    rtb_y[i] = (uint8_T)((uint32_T)rtb_Cast[i] >> 8);

    /* Assignment: '<S82>/Assignment' incorporates:
     *  Assignment: '<S82>/Assignment1'
     *  DataTypeConversion: '<S82>/Cast1'
     */
    rtb_Assignment1_tmp = i << 1;
    rtb_Assignment1[rtb_Assignment1_tmp] = rtb_y[i];

    /* Assignment: '<S82>/Assignment1' incorporates:
     *  DataTypeConversion: '<S82>/Cast2'
     */
    rtb_Assignment1[rtb_Assignment1_tmp + 1] = (uint8_T)rtb_Cast[i];
  }

  /* End of Outputs for SubSystem: '<S82>/Bit Shift' */

  /* DataStoreWrite: '<S82>/Data Store Write' incorporates:
   *  Constant: '<S82>/Constant'
   */
  rtDW.USART[0] = 104U;
  rtDW.USART[1] = 100U;
  rtDW.USART[2] = 114U;
  for (i = 0; i < 14; i++) {
    rtDW.USART[i + 3] = rtb_Assignment1[i];
  }

  /* End of DataStoreWrite: '<S82>/Data Store Write' */

  /* CCaller: '<S82>/C Caller' incorporates:
   *  DataStoreRead: '<S82>/Data Store Read'
   */
  usartTransmit_DMA_wrapper(3U, &rtDW.USART[0], rtDW.Width);

  /* End of Outputs for SubSystem: '<Root>/UsartTx' */
}

/* Model step function for TID7 */
void UsartRx(void)                     /* Explicit Task: UsartRx */
{
  /* Outputs for Atomic SubSystem: '<Root>/UsartRx' */
  /* Chart: '<S6>/Chart' incorporates:
   *  Inport: '<Root>/Msg'
   */
  rtDW.On = (uint16_T)(rtU.Msg[0] << 8 | rtU.Msg[1]);
  rtDW.Vel_Target = (uint16_T)(rtU.Msg[2] << 8 | rtU.Msg[3]);

  /* End of Outputs for SubSystem: '<Root>/UsartRx' */
}

/* Model initialize function */
void LowVoltageInverter_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/UsartTx' */
  /* Start for Width: '<S82>/Width' */
  rtDW.Width = 17U;

  /* End of SystemInitialize for SubSystem: '<Root>/UsartTx' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/FOC' */
  /* SystemInitialize for Chart: '<S11>/Chart1' */
  rtDW.Base_speed = 4107.0;

  /* SystemInitialize for Chart: '<S14>/Chart' */
  rtDW.T = 100.0;
  rtDW.Pi = 3.1415926535897931;

  /* Start for MATLABSystem: '<S17>/Median Filter2' */
  rtDW.obj.matlabCodegenIsDeleted = false;
  rtDW.obj.isInitialized = 1;
  rtDW.obj.NumChannels = 1;
  rtDW.obj.pMID.isInitialized = 0;
  rtDW.obj.isSetupComplete = true;

  /* InitializeConditions for MATLABSystem: '<S17>/Median Filter2' */
  if (rtDW.obj.pMID.isInitialized == 1) {
    MedianFilterCG_resetImpl(&rtDW.obj.pMID);
  }

  /* End of InitializeConditions for MATLABSystem: '<S17>/Median Filter2' */
  MovingAverage_Init(&rtDW.MovingAverage_b);

  /* Start for CFunction: '<S9>/C Function2' */
  MovingAverage_Init(&rtDW.MovingAverage1);

  /* End of SystemInitialize for SubSystem: '<Root>/FOC' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
