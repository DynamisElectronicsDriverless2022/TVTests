/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
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

#include "TVModel.h"
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;
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
  real_T *Amplitude);
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

  /* Start for MATLABSystem: '<S3>/Moving Average' */
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

  /* InitializeConditions for MATLABSystem: '<S3>/Moving Average' */
  iobj_0 = localDW->obj.pStatistic;
  if (iobj_0->isInitialized == 1) {
    iobj_0->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      iobj_0->pCumSumRev[i] = 0.0;
    }

    iobj_0->pCumRevIndex = 1.0;
    iobj_0->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S3>/Moving Average' */
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

  /* MATLABSystem: '<S3>/Moving Average' */
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

  /* MATLABSystem: '<S3>/Moving Average' */
  localDW->MovingAverage_g = 0.0;

  /* MATLABSystem: '<S3>/Moving Average' */
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
    /* MATLABSystem: '<S3>/Moving Average' */
    localDW->MovingAverage_g = z / 10.0;
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

/* Function for Chart: '<S8>/Chart' */
static void CalculateTs(real_T Alfa, real_T *T0, real_T *T1, real_T *T2, const
  real_T *Amplitude)
{
  *T1 = sin(rtDW.Pi / 3.0 - Alfa) * (rtDW.T * *Amplitude);
  *T2 = rtDW.T * *Amplitude * sin(Alfa);
  *T0 = (rtDW.T - *T1) - *T2;
}

/* Model step function */
void TV(void)
{
  /* local block i/o variables */
  real_T rtb_Product1_l;
  real_T rtb_Add;
  c_dsp_internal_MedianFilterCG *obj;
  real_T Amplitude;
  real_T DiscreteTransferFcn2_tmp;
  real_T T1;
  real_T T2;
  real_T p;
  real_T rtb_Saturation3;
  real_T rtb_Square1;
  real_T temp;
  real_T vprev;

  /* Outputs for Atomic SubSystem: '<Root>/TV' */
  /* DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn2' */
  DiscreteTransferFcn2_tmp = ((0.0 - 0.0 * rtDW.DiscreteTransferFcn2_states[0])
    - 0.0 * rtDW.DiscreteTransferFcn2_states[1]) - 0.0 *
    rtDW.DiscreteTransferFcn2_states[2];
  rtb_Saturation3 = ((18333.333333333332 * DiscreteTransferFcn2_tmp + -30000.0 *
                      rtDW.DiscreteTransferFcn2_states[0]) + 15000.0 *
                     rtDW.DiscreteTransferFcn2_states[1]) + -3333.333333333333 *
    rtDW.DiscreteTransferFcn2_states[2];

  /* Saturate: '<S11>/Saturation3' */
  if (rtb_Saturation3 <= -10000.0) {
    rtb_Saturation3 = -10000.0;
  }

  /* End of Saturate: '<S11>/Saturation3' */

  /* MATLABSystem: '<S11>/Median Filter2' */
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

  /* Sum: '<S21>/Add1' incorporates:
   *  Constant: '<S21>/Filter_Constant'
   *  Constant: '<S21>/One'
   *  MATLABSystem: '<S11>/Median Filter2'
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product1'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  rtb_Saturation3 = rtb_Saturation3 * 0.01 + 0.99 * rtDW.UnitDelay_DSTATE;

  /* Product: '<S3>/Product1' */
  rtb_Product1_l = rtb_Saturation3 * 0.0;
  MovingAverage(rtb_Product1_l, &rtDW.MovingAverage1);

  /* Chart: '<S5>/Chart1' */
  if (rtb_Saturation3 <= rtDW.Base_speed) {
    vprev = 0.0;
    temp = 7.1;
  } else {
    vprev = fmax((10000.0 - rtb_Saturation3) * 0.071 / (rtb_Saturation3 * 0.071),
                 -7.1);
    temp = sqrt(50.41 - rt_powd_snf(vprev, 2.0));
  }

  /* End of Chart: '<S5>/Chart1' */

  /* Sum: '<S1>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Sum: '<S6>/Sum'
   */
  p = (rtDW.DiscreteTimeIntegrator_DSTATE + vprev) -
    rtDW.MovingAverage1.MovingAverage_g;

  /* Switch: '<S10>/Switch2' incorporates:
   *  RelationalOperator: '<S10>/LowerRelop1'
   *  RelationalOperator: '<S10>/UpperRelop'
   *  Switch: '<S10>/Switch'
   */
  if (p > 0.0) {
    rtb_Square1 = 0.0;
  } else if (p < -0.0) {
    /* Switch: '<S10>/Switch' */
    rtb_Square1 = -0.0;
  } else {
    rtb_Square1 = p;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Sum: '<S3>/Add' incorporates:
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product2'
   */
  rtb_Add = 0.0 * rtb_Saturation3 + rtb_Saturation3 * 0.0;
  MovingAverage(rtb_Add, &rtDW.MovingAverage_p);

  /* Switch: '<S15>/Switch2' incorporates:
   *  RelationalOperator: '<S15>/LowerRelop1'
   *  Switch: '<S15>/Switch'
   */
  if (!(0.0 > temp)) {
    temp = 0.0;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Sum: '<S1>/Sum1' */
  p = temp;

  /* Sum: '<S1>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S7>/Sum'
   */
  temp = (rtDW.DiscreteTimeIntegrator_DSTATE_a + temp) +
    rtDW.MovingAverage_p.MovingAverage_g;

  /* Switch: '<S9>/Switch2' incorporates:
   *  RelationalOperator: '<S9>/LowerRelop1'
   *  RelationalOperator: '<S9>/UpperRelop'
   *  Switch: '<S9>/Switch'
   */
  if (temp > 0.0) {
    temp = 0.0;
  } else if (temp < -0.0) {
    /* Switch: '<S9>/Switch' */
    temp = -0.0;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Product: '<S13>/Matrix Multiply' incorporates:
   *  SignalConversion generated from: '<S13>/Matrix Multiply'
   *  Sum: '<S13>/Add'
   */
  T1 = 0.0 * temp + rtb_Square1;
  temp += 0.0 * rtb_Square1;

  /* Sqrt: '<S8>/Square Root' incorporates:
   *  Math: '<S8>/Square'
   *  Math: '<S8>/Square1'
   *  Sum: '<S8>/Add'
   */
  Amplitude = sqrt(T1 * T1 + temp * temp);

  /* Trigonometry: '<S8>/Atan2' */
  temp = rt_atan2d_snf(T1, temp);

  /* Chart: '<S8>/Chart' */
  if ((temp > 0.0) && (temp < rtDW.Pi / 3.0)) {
    CalculateTs(temp, &rtb_Square1, &T1, &T2, &Amplitude);
  } else {
    rtb_Square1 = 2.0 * rtDW.Pi / 3.0;
    if ((temp > rtDW.Pi / 3.0) && (temp < rtb_Square1)) {
      CalculateTs(temp - rtDW.Pi / 3.0, &rtb_Square1, &T1, &T2, &Amplitude);
    } else if ((temp > rtb_Square1) && (temp < rtDW.Pi)) {
      CalculateTs(temp - 2.0 * rtDW.Pi / 3.0, &rtb_Square1, &T1, &T2, &Amplitude);
    } else {
      rtb_Square1 = -2.0 * rtDW.Pi / 3.0;
      if ((temp > -rtDW.Pi) && (temp < rtb_Square1)) {
        CalculateTs(temp + rtDW.Pi, &rtb_Square1, &T1, &T2, &Amplitude);
      } else {
        T1 = -rtDW.Pi / 3.0;
        if ((temp > rtb_Square1) && (temp < T1)) {
          CalculateTs(temp + 2.0 * rtDW.Pi / 3.0, &rtb_Square1, &T1, &T2,
                      &Amplitude);
        } else if ((temp > T1) && (temp < 0.0)) {
          CalculateTs(temp + rtDW.Pi / 3.0, &rtb_Square1, &T1, &T2, &Amplitude);
        }
      }
    }
  }

  /* End of Chart: '<S8>/Chart' */

  /* Update for DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn2' */
  rtDW.DiscreteTransferFcn2_states[2] = rtDW.DiscreteTransferFcn2_states[1];
  rtDW.DiscreteTransferFcn2_states[1] = rtDW.DiscreteTransferFcn2_states[0];
  rtDW.DiscreteTransferFcn2_states[0] = DiscreteTransferFcn2_tmp;

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Saturation3;

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.01 * vprev;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += 0.01 * p;

  /* End of Outputs for SubSystem: '<Root>/TV' */
}

/* Model initialize function */
void TVModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/TV' */
  /* SystemInitialize for Chart: '<S5>/Chart1' */
  rtDW.Base_speed = 1000.0;

  /* SystemInitialize for Chart: '<S8>/Chart' */
  rtDW.T = 100.0;
  rtDW.Pi = 3.1415926535897931;

  /* Start for MATLABSystem: '<S11>/Median Filter2' */
  rtDW.obj.matlabCodegenIsDeleted = false;
  rtDW.obj.isInitialized = 1;
  rtDW.obj.NumChannels = 1;
  rtDW.obj.pMID.isInitialized = 0;
  rtDW.obj.isSetupComplete = true;

  /* InitializeConditions for MATLABSystem: '<S11>/Median Filter2' */
  if (rtDW.obj.pMID.isInitialized == 1) {
    MedianFilterCG_resetImpl(&rtDW.obj.pMID);
  }

  /* End of InitializeConditions for MATLABSystem: '<S11>/Median Filter2' */
  MovingAverage_Init(&rtDW.MovingAverage1);
  MovingAverage_Init(&rtDW.MovingAverage_p);

  /* End of SystemInitialize for SubSystem: '<Root>/TV' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
