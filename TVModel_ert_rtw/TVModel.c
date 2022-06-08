/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jun  8 13:17:33 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TVModel.h"

/* Named constants for Chart: '<S17>/Activation logic' */
#define IN_ABS_ACTIVE                  ((uint8_T)1U)
#define IN_ABS_INACTIVE                ((uint8_T)2U)
#define IN_ABS_OFF                     ((uint8_T)1U)
#define IN_ABS_ON                      ((uint8_T)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_TS_OFF                      ((uint8_T)1U)
#define IN_TS_ON                       ((uint8_T)2U)

/* Named constants for Chart: '<S23>/Activation logic' */
#define IN_TC_ACTIVE                   ((uint8_T)1U)
#define IN_TC_INACTIVE                 ((uint8_T)2U)
#define IN_TC_OFF                      ((uint8_T)1U)
#define IN_TC_ON                       ((uint8_T)2U)

/* Named constants for Chart: '<S145>/Overlap Chart' */
#define IN_Go                          ((uint8_T)1U)
#define IN_Stop                        ((uint8_T)2U)

/* Named constants for Chart: '<S146>/Chart' */
#define IN_OFF                         ((uint8_T)1U)
#define IN_ON                          ((uint8_T)2U)
#define IN_SWITCHING_FILTER            ((uint8_T)3U)
#define mz_filter_tau                  (0.98019867330675525)

/* Named constants for Chart: '<S278>/T_Req_Chart' */
#define IN_Brake                       ((uint8_T)1U)
#define IN_Throttle                    ((uint8_T)2U)
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static real_T look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
static uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction);
static real_T intrp2d_l(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride);
static uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);

/* Forward declaration for local functions */
static real_T minimum(const real_T x[3]);
static void BaseDistribution(real_T T_req, const real_T T_max[4], const real_T
  T_min[4], real_T Mz_req, real_T T[4]);
static void sort(real_T x[4], int32_T idx[4]);
static void assignBrakeTorque(const real_T T_in[4], real_T Tbrake[4]);
static void exit_internal_ABS_ON(void);
static void exit_internal_TC_ON(void);
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

static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

static real_T look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

static uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0;
  }

  return bpIndex;
}

static real_T intrp2d_l(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride)
{
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T offset_1d;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  yL_0d0 = table[offset_1d];
  yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
  offset_1d += stride;
  yL_0d1 = table[offset_1d];
  return (((table[offset_1d + 1U] - yL_0d1) * frac[0U] + yL_0d1) - yL_0d0) *
    frac[1U] + yL_0d0;
}

static uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T bpIndex;
  uint32_T iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
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

/* Function for Chart: '<S239>/Distribution complete' */
static real_T minimum(const real_T x[3])
{
  real_T ex;
  int32_T idx;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    int32_T k;
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 3) {
      if (ex > x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

/* Function for Chart: '<S239>/Distribution complete' */
static void BaseDistribution(real_T T_req, const real_T T_max[4], const real_T
  T_min[4], real_T Mz_req, real_T T[4])
{
  real_T b_x[5];
  real_T x[4];
  real_T deltaTreq_0[3];
  real_T deltaTreq_1[3];
  real_T deltaTreq_2[3];
  real_T T_tmp;
  real_T dT;
  real_T deltaMzreq;
  real_T deltaTmax;
  real_T deltaTmax_idx_0;
  real_T deltaTmax_idx_1;
  real_T deltaTmax_idx_2;
  real_T deltaTmax_idx_3;
  real_T deltaTreq;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  if (!rtIsNaN(T_min[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!rtIsNaN(T_min[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    deltaMzreq = T_min[0];
  } else {
    deltaMzreq = T_min[idx - 1];
    while (idx + 1 <= 4) {
      if (deltaMzreq < T_min[idx]) {
        deltaMzreq = T_min[idx];
      }

      idx++;
    }
  }

  T[2] = deltaMzreq;
  T[3] = deltaMzreq;
  deltaTreq = T_req - (((deltaMzreq + deltaMzreq) + deltaMzreq) + deltaMzreq);
  deltaTmax_idx_0 = T_max[0] - deltaMzreq;
  deltaTmax_idx_1 = T_max[1] - deltaMzreq;
  deltaTmax_idx_2 = T_max[2] - deltaMzreq;
  deltaTmax_idx_3 = T_max[3] - deltaMzreq;
  x[0] = deltaTreq / 2.0;
  x[1] = deltaTmax_idx_0;
  x[2] = deltaTmax_idx_1;
  x[3] = Mz_req * rtDW.Rw / rtDW.tr;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    dT = x[0];
  } else {
    dT = x[idx - 1];
    while (idx + 1 <= 4) {
      if (dT > x[idx]) {
        dT = x[idx];
      }

      idx++;
    }
  }

  deltaTreq -= 2.0 * dT;
  T_tmp = deltaMzreq + dT;
  deltaTmax_idx_0 -= dT;
  deltaTmax = deltaTmax_idx_1 - dT;
  deltaMzreq = Mz_req - dT / rtDW.Rw * rtDW.tr;
  deltaTreq_0[0] = deltaTreq;
  deltaTreq_0[1] = deltaTmax_idx_0;
  deltaTreq_0[2] = deltaMzreq * 2.0 * rtDW.Rw / rtDW.tr;
  dT = minimum(deltaTreq_0);
  T[0] = T_tmp + dT;
  deltaTreq -= dT;
  deltaTmax_idx_0 -= dT;
  deltaTreq_0[0] = deltaTreq;
  deltaTreq_0[1] = deltaTmax;
  deltaTreq_0[2] = (deltaMzreq - dT / rtDW.Rw * rtDW.tr / 2.0) * 2.0 * rtDW.Rw /
    rtDW.tr;
  dT = minimum(deltaTreq_0);
  T[1] = T_tmp + dT;
  deltaTreq -= dT;
  deltaTmax_idx_1 = deltaTmax - dT;
  b_x[0] = deltaTreq / 4.0;
  b_x[1] = deltaTmax_idx_0;
  b_x[2] = deltaTmax_idx_1;
  b_x[3] = deltaTmax_idx_2;
  b_x[4] = deltaTmax_idx_3;
  if (!rtIsNaN(b_x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!rtIsNaN(b_x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    dT = b_x[0];
  } else {
    dT = b_x[idx - 1];
    while (idx + 1 <= 5) {
      if (dT > b_x[idx]) {
        dT = b_x[idx];
      }

      idx++;
    }
  }

  deltaTreq -= 4.0 * dT;
  deltaTmax = deltaTmax_idx_0 - dT;
  T[0] += dT;
  deltaMzreq = deltaTmax_idx_1 - dT;
  T[1] += dT;
  deltaTmax_idx_2 -= dT;
  T[2] += dT;
  deltaTmax_idx_3 -= dT;
  T[3] += dT;
  deltaTreq_0[0] = deltaTreq / 2.0;
  deltaTreq_0[1] = deltaTmax;
  deltaTreq_0[2] = deltaTmax_idx_2;
  dT = minimum(deltaTreq_0);
  deltaTreq -= 2.0 * dT;
  deltaTreq_0[0] = deltaTreq / 2.0;
  T[0] += dT;
  deltaTreq_1[1] = deltaTmax - dT;
  deltaTreq_0[1] = deltaMzreq;
  T[2] += dT;
  deltaTreq_2[2] = deltaTmax_idx_2 - dT;
  deltaTreq_0[2] = deltaTmax_idx_3;
  dT = minimum(deltaTreq_0);
  deltaTreq -= 2.0 * dT;
  deltaTreq_1[0] = deltaTreq / 2.0;
  T[1] += dT;
  deltaTreq_2[1] = deltaMzreq - dT;
  T[3] += dT;
  deltaTreq_1[2] = deltaTmax_idx_3 - dT;
  dT = minimum(deltaTreq_1);
  deltaTreq_2[0] = (deltaTreq - 2.0 * dT) / 2.0;
  T[0] += dT;
  T[3] += dT;
  dT = minimum(deltaTreq_2);
  T[1] += dT;
  T[2] += dT;
}

/* Function for Chart: '<S239>/Distribution complete' */
static void sort(real_T x[4], int32_T idx[4])
{
  real_T x4[4];
  real_T xwork[4];
  int32_T idx4[4];
  int32_T i1;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int32_T nNaNs;
  int8_T perm[4];
  idx[0] = 0;
  x4[0] = 0.0;
  idx4[0] = 0;
  xwork[0] = 0.0;
  idx[1] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  xwork[1] = 0.0;
  idx[2] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  xwork[2] = 0.0;
  idx[3] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  xwork[3] = 0.0;
  nNaNs = 0;
  ib = -1;
  if (rtIsNaN(x[0])) {
    idx[3] = 1;
    xwork[3] = x[0];
    nNaNs = 1;
  } else {
    ib = 0;
    idx4[0] = 1;
    x4[0] = x[0];
  }

  if (rtIsNaN(x[1])) {
    idx[3 - nNaNs] = 2;
    xwork[3 - nNaNs] = x[1];
    nNaNs++;
  } else {
    ib++;
    idx4[ib] = 2;
    x4[ib] = x[1];
  }

  if (rtIsNaN(x[2])) {
    idx[3 - nNaNs] = 3;
    xwork[3 - nNaNs] = x[2];
    nNaNs++;
  } else {
    ib++;
    idx4[ib] = 3;
    x4[ib] = x[2];
  }

  if (rtIsNaN(x[3])) {
    idx[3 - nNaNs] = 4;
    xwork[3 - nNaNs] = x[3];
    nNaNs++;
  } else {
    ib++;
    idx4[ib] = 4;
    x4[ib] = x[3];
    if (ib + 1 == 4) {
      real_T tmp;
      real_T tmp_0;
      if (x4[0] <= x4[1]) {
        i1 = 1;
        ib = 2;
      } else {
        i1 = 2;
        ib = 1;
      }

      if (x4[2] <= x4[3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      tmp = x4[i1 - 1];
      tmp_0 = x4[i3 - 1];
      if (tmp <= tmp_0) {
        tmp = x4[ib - 1];
        if (tmp <= tmp_0) {
          perm[0] = (int8_T)i1;
          perm[1] = (int8_T)ib;
          perm[2] = (int8_T)i3;
          perm[3] = (int8_T)i4;
        } else if (tmp <= x4[i4 - 1]) {
          perm[0] = (int8_T)i1;
          perm[1] = (int8_T)i3;
          perm[2] = (int8_T)ib;
          perm[3] = (int8_T)i4;
        } else {
          perm[0] = (int8_T)i1;
          perm[1] = (int8_T)i3;
          perm[2] = (int8_T)i4;
          perm[3] = (int8_T)ib;
        }
      } else {
        tmp_0 = x4[i4 - 1];
        if (tmp <= tmp_0) {
          if (x4[ib - 1] <= tmp_0) {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i1;
            perm[2] = (int8_T)ib;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i1;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)ib;
          }
        } else {
          perm[0] = (int8_T)i3;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)i1;
          perm[3] = (int8_T)ib;
        }
      }

      idx[-nNaNs] = idx4[perm[0] - 1];
      idx[1 - nNaNs] = idx4[perm[1] - 1];
      idx[2 - nNaNs] = idx4[perm[2] - 1];
      idx[3 - nNaNs] = idx4[perm[3] - 1];
      x[-nNaNs] = x4[perm[0] - 1];
      x[1 - nNaNs] = x4[perm[1] - 1];
      x[2 - nNaNs] = x4[perm[2] - 1];
      x[3 - nNaNs] = x4[perm[3] - 1];
      ib = -1;
    }
  }

  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1) {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      break;
    }

    for (i3 = 0; i3 <= ib; i3++) {
      i1 = perm[i3] - 1;
      i4 = ((i3 - nNaNs) - ib) + 3;
      idx[i4] = idx4[i1];
      x[i4] = x4[i1];
    }
  }

  i3 = (nNaNs >> 1) + 4;
  for (ib = 4; ib - 4 <= i3 - 5; ib++) {
    i4 = ib - nNaNs;
    i1 = idx[i4];
    idx[i4] = idx[7 - ib];
    idx[7 - ib] = i1;
    x[i4] = xwork[7 - ib];
    x[7 - ib] = xwork[i4];
  }

  if ((nNaNs & 1U) != 0U) {
    nNaNs = i3 - nNaNs;
    x[nNaNs] = xwork[nNaNs];
  }
}

/* Function for Chart: '<S239>/Distribution complete' */
static void assignBrakeTorque(const real_T T_in[4], real_T Tbrake[4])
{
  real_T idxArray[4];
  int32_T iidx[4];
  Tbrake[0] = 0.0;
  Tbrake[1] = 0.0;
  Tbrake[2] = 0.0;
  Tbrake[3] = 0.0;
  if (((T_in[0] + T_in[1]) + T_in[2]) + T_in[3] > 0.0) {
    idxArray[0] = T_in[0];
    idxArray[1] = T_in[1];
    idxArray[2] = T_in[2];
    idxArray[3] = T_in[3];
    sort(idxArray, iidx);
    Tbrake[iidx[3] - 1] = fmax(0.0, fabs(T_in[iidx[0] - 1]));
    Tbrake[iidx[2] - 1] = fmax(0.0, fabs(T_in[iidx[1] - 1]));
    Tbrake[iidx[1] - 1] = T_in[iidx[1] - 1];
    Tbrake[iidx[0] - 1] = T_in[iidx[0] - 1];
  } else {
    Tbrake[0] = T_in[0];
    Tbrake[1] = T_in[1];
    Tbrake[2] = T_in[2];
    Tbrake[3] = T_in[3];
  }
}

/* Function for Chart: '<S17>/Activation logic' */
static void exit_internal_ABS_ON(void)
{
  rtDW.is_RR_m = IN_NO_ACTIVE_CHILD;
  rtDW.is_RL_j = IN_NO_ACTIVE_CHILD;
  rtDW.is_FR_o = IN_NO_ACTIVE_CHILD;
  rtDW.is_FL_g = IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S23>/Activation logic' */
static void exit_internal_TC_ON(void)
{
  rtDW.is_RR = IN_NO_ACTIVE_CHILD;
  rtDW.is_RL = IN_NO_ACTIVE_CHILD;
  rtDW.is_FR = IN_NO_ACTIVE_CHILD;
  rtDW.is_FL = IN_NO_ACTIVE_CHILD;
}

/* Model step function */
void TV(void)
{
  g_dsp_internal_SlidingWindowA_l *obj_0;
  g_dsp_internal_SlidingWindowAve *obj;
  int64_T acc1;
  real_T rtb_y[64];
  real_T rtb_CCaller_o3[26];
  real_T csumrev[24];
  real_T rtb_CCaller_o12[20];
  real_T rtb_CCaller_o6[16];
  real_T varargin_2[16];
  real_T RateTransition3[13];
  real_T rtb_CCaller_o10[5];
  real_T rtb_CCaller_o9[5];
  real_T rtb_CCaller_o8[4];
  real_T rtb_Integrator_d[4];
  real_T rtb_Integrator_i[4];
  real_T rtb_Minus_i[4];
  real_T rtb_Product1[4];
  real_T rtb_SignPreIntegrator_e[4];
  real_T rtb_Switch2_i[4];
  real_T rtb_Tnew[4];
  real_T rtb_UnaryMinus_d0[4];
  real_T rtb_UnaryMinus_f[4];
  real_T rtb_CCaller_o13[3];
  real_T rtb_CCaller_o14[3];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T Faeroz_tmp;
  real_T Switch2_idx_0;
  real_T Switch2_idx_1;
  real_T Switch2_idx_2;
  real_T Switch2_idx_3;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T rtb_Abs_i_idx_0;
  real_T rtb_Abs_l;
  real_T rtb_Gain1;
  real_T rtb_Gain3;
  real_T rtb_Gain_idx_1;
  real_T rtb_Gain_idx_2;
  real_T rtb_Gain_idx_3;
  real_T rtb_Integrator_c_idx_0;
  real_T rtb_Integrator_c_idx_1;
  real_T rtb_Integrator_c_idx_2;
  real_T rtb_Integrator_c_idx_3;
  real_T rtb_Integrator_idx_0;
  real_T rtb_Integrator_idx_1;
  real_T rtb_Integrator_idx_2;
  real_T rtb_Integrator_idx_3;
  real_T rtb_Integrator_m;
  real_T rtb_NProdOut;
  real_T rtb_RL;
  real_T rtb_RL_tmp;
  real_T rtb_RL_tmp_0;
  real_T rtb_RL_tmp_tmp;
  real_T rtb_RL_tmp_tmp_0;
  real_T rtb_RR;
  real_T rtb_Saturation1;
  real_T rtb_Saturation_k_idx_0;
  real_T rtb_Saturation_k_idx_1;
  real_T rtb_Saturation_k_idx_2;
  real_T rtb_Saturation_k_idx_3;
  real_T rtb_Sign;
  real_T rtb_SumofElements1;
  real_T rtb_Switch;
  real_T rtb_Switch2_ae;
  real_T rtb_Switch_b_idx_0;
  real_T rtb_Switch_b_idx_1;
  real_T rtb_Switch_b_idx_2;
  real_T rtb_Switch_gx;
  real_T rtb_Switch_tmp;
  real_T rtb_Switch_tmp_0;
  real_T rtb_Switch_tmp_1;
  real_T rtb_Switch_tmp_2;
  real_T rtb_Switch_tmp_tmp;
  real_T rtb_Switch_tmp_tmp_0;
  real_T rtb_front_wheel_angle_single__d;
  real_T rtb_k_i;
  real_T rtb_k_l_idx_0;
  real_T rtb_k_l_idx_1;
  real_T rtb_k_l_idx_2;
  real_T rtb_k_l_idx_3;
  real_T rtb_ome_wheels;
  real_T rtb_ome_wheels_idx_0;
  real_T rtb_ome_wheels_idx_1;
  real_T rtb_ome_wheels_idx_2;
  real_T rtb_ome_wheels_idx_3;
  real_T rtb_vx;
  real_T u0;
  real_T u0_tmp;
  real_T u0_tmp_0;
  real_T z;
  int32_T tmp[2];
  int32_T b_exit;
  int32_T idx;
  int32_T rtb_y_tmp;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  boolean_T AND;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_p;
  boolean_T rtb_LessThan3;
  boolean_T rtb_Logic_d_idx_0;
  boolean_T rtb_Logic_d_idx_1;
  boolean_T rtb_Logic_ds_idx_0;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_idx_1;
  boolean_T rtb_Logic_o_idx_0;
  boolean_T rtb_Logic_o_idx_1;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (rtU.vx <= 0.0) {
    rtb_Integrator_m = 0.0;
  } else {
    rtb_Integrator_m = rtU.vx;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/yaw_rate'
   */
  rtb_Gain1 = 0.017453292519943295 * rtU.yaw_rate_deg;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Integrator_m <= 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = rtb_Integrator_m;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Signum: '<S9>/Sign' incorporates:
   *  Inport: '<Root>/steering'
   */
  if (rtU.steering < 0.0) {
    rtb_Sign = -1.0;
  } else if (rtU.steering > 0.0) {
    rtb_Sign = 1.0;
  } else if (rtU.steering == 0.0) {
    rtb_Sign = 0.0;
  } else {
    rtb_Sign = rtU.steering;
  }

  /* End of Signum: '<S9>/Sign' */

  /* Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Product: '<S9>/Divide1'
   */
  rtb_Abs_i_idx_0 = fabs(look1_binlx(rtU.steering, rtConstP.pooled38,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Abs_l = fabs(look1_binlx(-rtU.steering, rtConstP.pooled38,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Gain: '<S12>/Gain3'
   *  Gain: '<S13>/Gain3'
   *  Gain: '<S14>/Gain'
   *  Gain: '<S15>/Gain'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S12>/Divide4'
   *  Product: '<S13>/Divide4'
   *  Product: '<S14>/Divide'
   *  Product: '<S15>/Divide'
   *  Sum: '<S12>/Subtract3'
   *  Sum: '<S13>/Subtract3'
   *  Sum: '<S14>/Subtract'
   *  Sum: '<S15>/Subtract'
   *  Switch: '<S13>/Switch'
   *  Switch: '<S14>/Switch'
   *  Switch: '<S15>/Switch'
   */
  if (rtb_vx > 0.5) {
    /* Sum: '<S12>/Sum' incorporates:
     *  Inport: '<Root>/vy'
     *  Product: '<S12>/Divide5'
     *  Product: '<S12>/Divide6'
     *  Trigonometry: '<S12>/Cos1'
     *  Trigonometry: '<S12>/Cos2'
     */
    rtb_Sign = rtb_vx * cos(rtb_Abs_i_idx_0) + sin(rtb_Abs_i_idx_0) * rtU.vy;
    rtb_Switch = (0.235 * rtU.omega_wheels_FL - rtb_Sign) / rtb_Sign;

    /* Sum: '<S13>/Sum' incorporates:
     *  Gain: '<S12>/Gain3'
     *  Inport: '<Root>/omega_wheels_FL'
     *  Inport: '<Root>/vy'
     *  Product: '<S12>/Divide4'
     *  Product: '<S13>/Divide5'
     *  Product: '<S13>/Divide6'
     *  Sum: '<S12>/Subtract3'
     *  Trigonometry: '<S13>/Cos1'
     *  Trigonometry: '<S13>/Cos2'
     */
    rtb_Sign = rtb_vx * cos(rtb_Abs_l) + sin(rtb_Abs_l) * rtU.vy;
    rtb_Switch_gx = (0.235 * rtU.omega_wheels_FR - rtb_Sign) / rtb_Sign;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_vx) / rtb_vx;
    rtb_RL = (0.235 * rtU.omega_wheels_RL - rtb_vx) / rtb_vx;
  } else {
    rtb_Switch = 0.0;
    rtb_Switch_gx = 0.0;
    rtb_RR = 0.0;
    rtb_RL = 0.0;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_front_wheel_angle_single__d = look1_binlx(rtU.steering, rtConstP.pooled38,
    rtConstP.steering_to_wheel_angle_single_, 32U);

  /* MATLAB Function: '<S22>/MATLAB Function2' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/vy'
   */
  Faeroz_tmp = rtb_vx - 0.635 * rtb_Gain1;
  rtb_k_l_idx_0 = rtU.vy - 0.765 * rtb_Gain1;
  rtb_k_l_idx_1 = 0.635 * rtb_Gain1 + rtb_vx;

  /* Gain: '<S25>/Gain' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_ome_wheels_idx_0 = 0.235 * rtU.omega_wheels_FL;
  rtb_ome_wheels_idx_1 = 0.235 * rtU.omega_wheels_FR;
  rtb_ome_wheels_idx_2 = 0.235 * rtU.omega_wheels_RL;
  rtb_ome_wheels_idx_3 = 0.235 * rtU.omega_wheels_RR;

  /* MATLAB Function: '<S22>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function2'
   */
  rtb_NProdOut = cos(rtb_front_wheel_angle_single__d);
  rtb_Switch2_ae = sin(rtb_front_wheel_angle_single__d);

  /* SignalConversion generated from: '<S138>/ SFunction ' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Inport: '<Root>/vy'
   *  MATLAB Function: '<S22>/MATLAB Function2'
   *  MATLAB Function: '<S25>/MATLAB Function'
   */
  rtb_Integrator_d[0] = (0.765 * rtb_Gain1 + rtU.vy) * rtb_Switch2_ae +
    Faeroz_tmp * rtb_NProdOut;
  rtb_Integrator_d[1] = (0.765 * rtb_Gain1 + rtU.vy) * sin
    (rtb_front_wheel_angle_single__d) + rtb_k_l_idx_1 * rtb_NProdOut;

  /* MATLAB Function: '<S22>/MATLAB Function2' */
  rtb_Integrator_m = rtb_k_l_idx_0 * rtb_k_l_idx_0;

  /* SignalConversion generated from: '<S138>/ SFunction ' incorporates:
   *  MATLAB Function: '<S22>/MATLAB Function2'
   *  MATLAB Function: '<S25>/MATLAB Function'
   */
  rtb_Integrator_d[2] = sqrt(Faeroz_tmp * Faeroz_tmp + rtb_Integrator_m);
  rtb_Integrator_d[3] = sqrt(rtb_k_l_idx_1 * rtb_k_l_idx_1 + rtb_Integrator_m);

  /* MATLAB Function: '<S25>/MATLAB Function' incorporates:
   *  Constant: '<S25>/Constant'
   */
  rtb_CCaller_o13[0] = rtb_Integrator_d[0];
  rtb_CCaller_o13[1] = rtb_ome_wheels_idx_0;
  rtb_CCaller_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    b_exit = 2;
    exitg1 = false;
    while ((!exitg1) && (b_exit < 4)) {
      if (!rtIsNaN(rtb_CCaller_o13[b_exit - 1])) {
        idx = b_exit;
        exitg1 = true;
      } else {
        b_exit++;
      }
    }
  }

  if (idx == 0) {
    rtb_Sign = rtb_CCaller_o13[0];
  } else {
    rtb_Sign = rtb_CCaller_o13[idx - 1];
    while (idx + 1 <= 3) {
      if (rtb_Sign < rtb_CCaller_o13[idx]) {
        rtb_Sign = rtb_CCaller_o13[idx];
      }

      idx++;
    }
  }

  rtb_k_l_idx_0 = (rtb_ome_wheels_idx_0 - rtb_Integrator_d[0]) / rtb_Sign;
  rtb_CCaller_o13[0] = rtb_Integrator_d[1];
  rtb_CCaller_o13[1] = rtb_ome_wheels_idx_1;
  rtb_CCaller_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    b_exit = 2;
    exitg1 = false;
    while ((!exitg1) && (b_exit < 4)) {
      if (!rtIsNaN(rtb_CCaller_o13[b_exit - 1])) {
        idx = b_exit;
        exitg1 = true;
      } else {
        b_exit++;
      }
    }
  }

  if (idx == 0) {
    rtb_Sign = rtb_CCaller_o13[0];
  } else {
    rtb_Sign = rtb_CCaller_o13[idx - 1];
    while (idx + 1 <= 3) {
      if (rtb_Sign < rtb_CCaller_o13[idx]) {
        rtb_Sign = rtb_CCaller_o13[idx];
      }

      idx++;
    }
  }

  rtb_k_l_idx_1 = (rtb_ome_wheels_idx_1 - rtb_Integrator_d[1]) / rtb_Sign;
  rtb_CCaller_o13[0] = rtb_Integrator_d[2];
  rtb_CCaller_o13[1] = rtb_ome_wheels_idx_2;
  rtb_CCaller_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    b_exit = 2;
    exitg1 = false;
    while ((!exitg1) && (b_exit < 4)) {
      if (!rtIsNaN(rtb_CCaller_o13[b_exit - 1])) {
        idx = b_exit;
        exitg1 = true;
      } else {
        b_exit++;
      }
    }
  }

  if (idx == 0) {
    rtb_Sign = rtb_CCaller_o13[0];
  } else {
    rtb_Sign = rtb_CCaller_o13[idx - 1];
    while (idx + 1 <= 3) {
      if (rtb_Sign < rtb_CCaller_o13[idx]) {
        rtb_Sign = rtb_CCaller_o13[idx];
      }

      idx++;
    }
  }

  rtb_k_l_idx_2 = (rtb_ome_wheels_idx_2 - rtb_Integrator_d[2]) / rtb_Sign;
  rtb_CCaller_o13[0] = rtb_Integrator_d[3];
  rtb_CCaller_o13[1] = rtb_ome_wheels_idx_3;
  rtb_CCaller_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    b_exit = 2;
    exitg1 = false;
    while ((!exitg1) && (b_exit < 4)) {
      if (!rtIsNaN(rtb_CCaller_o13[b_exit - 1])) {
        idx = b_exit;
        exitg1 = true;
      } else {
        b_exit++;
      }
    }
  }

  if (idx == 0) {
    rtb_Sign = rtb_CCaller_o13[0];
  } else {
    rtb_Sign = rtb_CCaller_o13[idx - 1];
    while (idx + 1 <= 3) {
      if (rtb_Sign < rtb_CCaller_o13[idx]) {
        rtb_Sign = rtb_CCaller_o13[idx];
      }

      idx++;
    }
  }

  rtb_k_l_idx_3 = (rtb_ome_wheels_idx_3 - rtb_Integrator_d[3]) / rtb_Sign;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels = rtb_ome_wheels_idx_0 * 50.0;

  /* Sum: '<S16>/Plus' incorporates:
   *  Constant: '<S16>/Constant'
   *  Gain: '<S25>/Gain2'
   *  Product: '<S16>/Product4'
   *  Product: '<S16>/Product5'
   *  Sum: '<S137>/Diff'
   *  UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtb_k_i = (rtb_ome_wheels - rtDW.UD_DSTATE[0]) * 0.1019367991845056 *
    0.040000000000000036 + rtb_k_l_idx_0 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Minus_i[0] = -0.13600000000000004 - rtb_k_i;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_0 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_l_idx_0 = rtb_k_i;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels = rtb_ome_wheels_idx_1 * 50.0;

  /* Sum: '<S16>/Plus' incorporates:
   *  Constant: '<S16>/Constant'
   *  Gain: '<S25>/Gain2'
   *  Product: '<S16>/Product4'
   *  Product: '<S16>/Product5'
   *  Sum: '<S137>/Diff'
   *  UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtb_k_i = (rtb_ome_wheels - rtDW.UD_DSTATE[1]) * 0.1019367991845056 *
    0.040000000000000036 + rtb_k_l_idx_1 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Minus_i[1] = -0.13600000000000004 - rtb_k_i;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_1 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_l_idx_1 = rtb_k_i;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels = rtb_ome_wheels_idx_2 * 50.0;

  /* Sum: '<S16>/Plus' incorporates:
   *  Constant: '<S16>/Constant'
   *  Gain: '<S25>/Gain2'
   *  Product: '<S16>/Product4'
   *  Product: '<S16>/Product5'
   *  Sum: '<S137>/Diff'
   *  UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtb_k_i = (rtb_ome_wheels - rtDW.UD_DSTATE[2]) * 0.1019367991845056 *
    0.040000000000000036 + rtb_k_l_idx_2 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Minus_i[2] = -0.13600000000000004 - rtb_k_i;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_2 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_l_idx_2 = rtb_k_i;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels = rtb_ome_wheels_idx_3 * 50.0;

  /* Sum: '<S16>/Plus' incorporates:
   *  Constant: '<S16>/Constant'
   *  Gain: '<S25>/Gain2'
   *  Product: '<S16>/Product4'
   *  Product: '<S16>/Product5'
   *  Sum: '<S137>/Diff'
   *  UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtb_k_i = (rtb_ome_wheels - rtDW.UD_DSTATE[3]) * 0.1019367991845056 *
    0.040000000000000036 + rtb_k_l_idx_3 * 0.96;

  /* Logic: '<S18>/AND' incorporates:
   *  Constant: '<S18>/Constant2'
   *  RelationalOperator: '<S18>/Relational Operator'
   */
  AND = (rtb_vx > 3.0);

  /* DiscreteIntegrator: '<S62>/Integrator' */
  if (AND && (rtDW.Integrator_PrevResetState <= 0)) {
    rtDW.Integrator_DSTATE[0] = 0.0;
    rtDW.Integrator_DSTATE[1] = 0.0;
    rtDW.Integrator_DSTATE[2] = 0.0;
    rtDW.Integrator_DSTATE[3] = 0.0;
  }

  /* Sum: '<S72>/Sum' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Product: '<S67>/PProd Out'
   */
  rtb_k_l_idx_3 = rtb_Minus_i[0] * 57.0 + rtDW.Integrator_DSTATE[0];

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_k_l_idx_3 > -4.9) {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_0 = -4.9;
  } else if (rtb_k_l_idx_3 < -21.0) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Switch: '<S70>/Switch2'
     */
    Switch2_idx_0 = -21.0;
  } else {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_0 = rtb_k_l_idx_3;
  }

  /* Sum: '<S72>/Sum' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Product: '<S67>/PProd Out'
   */
  rtb_Switch_b_idx_0 = rtb_k_l_idx_3;
  rtb_k_l_idx_3 = rtb_Minus_i[1] * 57.0 + rtDW.Integrator_DSTATE[1];

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_k_l_idx_3 > -4.9) {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_1 = -4.9;
  } else if (rtb_k_l_idx_3 < -21.0) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Switch: '<S70>/Switch2'
     */
    Switch2_idx_1 = -21.0;
  } else {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_1 = rtb_k_l_idx_3;
  }

  /* Sum: '<S72>/Sum' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Product: '<S67>/PProd Out'
   */
  rtb_Switch_b_idx_1 = rtb_k_l_idx_3;
  rtb_k_l_idx_3 = rtb_Minus_i[2] * 57.0 + rtDW.Integrator_DSTATE[2];

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_k_l_idx_3 > -4.9) {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_2 = -4.9;
  } else if (rtb_k_l_idx_3 < -21.0) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Switch: '<S70>/Switch2'
     */
    Switch2_idx_2 = -21.0;
  } else {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_2 = rtb_k_l_idx_3;
  }

  /* Sum: '<S72>/Sum' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Product: '<S67>/PProd Out'
   *  Sum: '<S17>/Minus'
   */
  rtb_Switch_b_idx_2 = rtb_k_l_idx_3;
  rtb_k_l_idx_3 = (-0.13600000000000004 - rtb_k_i) * 57.0 +
    rtDW.Integrator_DSTATE[3];

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_k_l_idx_3 > -4.9) {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_3 = -4.9;
  } else if (rtb_k_l_idx_3 < -21.0) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Switch: '<S70>/Switch2'
     */
    Switch2_idx_3 = -21.0;
  } else {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_3 = rtb_k_l_idx_3;
  }

  /* Memory: '<S139>/Memory' incorporates:
   *  Switch: '<S21>/Switch2'
   */
  rtb_Switch2_i[0] = rtDW.Memory_PreviousInput[0];
  rtb_Switch2_i[1] = rtDW.Memory_PreviousInput[1];
  rtb_Switch2_i[2] = rtDW.Memory_PreviousInput[2];
  rtb_Switch2_i[3] = rtDW.Memory_PreviousInput[3];

  /* RateTransition: '<S152>/Rate Transition3' incorporates:
   *  Constant: '<S142>/Inertia Scaling'
   *  Constant: '<S142>/LMUy'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = rtb_front_wheel_angle_single__d;
  RateTransition3[1] = rtb_Switch;
  RateTransition3[2] = rtb_Switch_gx;
  RateTransition3[3] = rtb_RL;
  RateTransition3[4] = rtb_RR;
  RateTransition3[5] = rtDW.UnitDelay_DSTATE[0];
  RateTransition3[6] = rtDW.UnitDelay_DSTATE[1];
  RateTransition3[7] = rtDW.UnitDelay_DSTATE[2];
  RateTransition3[8] = rtDW.UnitDelay_DSTATE[3];
  RateTransition3[9] = rtU.ay;
  RateTransition3[10] = rtU.ax;
  RateTransition3[11] = 0.8;
  RateTransition3[12] = 1.0;

  /* CFunction: '<S152>/C Function' incorporates:
   *  Constant: '<S152>/Constant3'
   */
  for (idx = 0; idx < 2; idx++) {
    memcpy(&rtDW.CFunction[idx * 13], &RateTransition3[0], 13U * sizeof(real_T));
  }

  /* End of CFunction: '<S152>/C Function' */

  /* Lookup_n-D: '<S276>/Max_Torque_Overload_Motor_LUT' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Lookup_n-D: '<S276>/Max_Torque_Overload_Inverter_LUT'
   *  Lookup_n-D: '<S277>/Display Overload Inverter LUT'
   *  Lookup_n-D: '<S277>/Display Overload Motor LUT'
   */
  rtb_Integrator_c_idx_0 = look1_binlx(0.0, rtConstP.pooled43, rtConstP.pooled42,
    2U);
  rtb_SignPreIntegrator_e[0] = rtb_Integrator_c_idx_0;
  rtb_SignPreIntegrator_e[1] = rtb_Integrator_c_idx_0;
  rtb_SignPreIntegrator_e[2] = rtb_Integrator_c_idx_0;
  rtb_SignPreIntegrator_e[3] = rtb_Integrator_c_idx_0;

  /* Lookup_n-D: '<S276>/Max_Torque_Overload_Inverter_LUT' */
  rtb_Integrator_d[0] = rtb_Integrator_c_idx_0;
  rtb_Integrator_d[1] = rtb_Integrator_c_idx_0;
  rtb_Integrator_d[2] = rtb_Integrator_c_idx_0;
  rtb_Integrator_d[3] = rtb_Integrator_c_idx_0;

  /* RelationalOperator: '<S285>/Compare' incorporates:
   *  Constant: '<S282>/Time constant'
   *  Constant: '<S285>/Constant'
   *  Sum: '<S282>/Sum1'
   */
  rtb_Compare = (0.079577471545947673 - rtDW.Probe[0] <= 0.0);

  /* Gain: '<S279>/Gain4' incorporates:
   *  Gain: '<S288>/Gain4'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_Gain3 = 128.91550390443524 * rtU.omega_wheels_FL;

  /* Saturate: '<S279>/Saturation1' incorporates:
   *  Gain: '<S279>/Gain4'
   */
  if (rtb_Gain3 <= 0.0) {
    rtb_Tnew[0] = 0.0;
  } else {
    rtb_Tnew[0] = rtb_Gain3;
  }

  /* Gain: '<S279>/Gain4' incorporates:
   *  Gain: '<S288>/Gain4'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  rtb_SumofElements1 = 128.91550390443524 * rtU.omega_wheels_FR;

  /* Saturate: '<S279>/Saturation1' incorporates:
   *  Gain: '<S279>/Gain4'
   */
  if (rtb_SumofElements1 <= 0.0) {
    rtb_Tnew[1] = 0.0;
  } else {
    rtb_Tnew[1] = rtb_SumofElements1;
  }

  /* Gain: '<S279>/Gain4' incorporates:
   *  Gain: '<S288>/Gain4'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  u0_tmp = 128.91550390443524 * rtU.omega_wheels_RL;

  /* Saturate: '<S279>/Saturation1' incorporates:
   *  Gain: '<S279>/Gain4'
   */
  if (u0_tmp <= 0.0) {
    rtb_Tnew[2] = 0.0;
  } else {
    rtb_Tnew[2] = u0_tmp;
  }

  /* Gain: '<S279>/Gain4' incorporates:
   *  Gain: '<S288>/Gain4'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0_tmp_0 = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S279>/Saturation1' incorporates:
   *  Gain: '<S279>/Gain4'
   */
  if (u0_tmp_0 <= 0.0) {
    rtb_Tnew[3] = 0.0;
  } else {
    rtb_Tnew[3] = u0_tmp_0;
  }

  /* Lookup_n-D: '<S279>/2-D Lookup Table' incorporates:
   *  Constant: '<S276>/Constant7'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &cumRevIndex);
  fractions[1U] = cumRevIndex;
  bpIndices[0U] = plook_binc(rtb_Tnew[0], rtConstP.pooled14, 200U, &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_Tnew[0] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_Tnew[1], rtConstP.pooled14, 200U, &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_Tnew[1] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_Tnew[2], rtConstP.pooled14, 200U, &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_Tnew[2] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_Tnew[3], rtConstP.pooled14, 200U, &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_Tnew[3] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);

  /* Gain: '<S279>/Gain' */
  rtb_ome_wheels_idx_3 = 0.0098000000000000014 * rtb_Tnew[0];
  rtb_Gain_idx_1 = 0.0098000000000000014 * rtb_Tnew[1];
  rtb_Gain_idx_2 = 0.0098000000000000014 * rtb_Tnew[2];
  rtb_Gain_idx_3 = 0.0098000000000000014 * rtb_Tnew[3];

  /* DiscreteIntegrator: '<S287>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE_m[0] = rtb_ome_wheels_idx_3;
    rtDW.Integrator_DSTATE_m[1] = rtb_Gain_idx_1;
    rtDW.Integrator_DSTATE_m[2] = rtb_Gain_idx_2;
    rtDW.Integrator_DSTATE_m[3] = rtb_Gain_idx_3;
  }

  if (rtb_Compare || (rtDW.Integrator_PrevResetState_e != 0)) {
    rtDW.Integrator_DSTATE_m[0] = rtb_ome_wheels_idx_3;
    rtDW.Integrator_DSTATE_m[1] = rtb_Gain_idx_1;
    rtDW.Integrator_DSTATE_m[2] = rtb_Gain_idx_2;
    rtDW.Integrator_DSTATE_m[3] = rtb_Gain_idx_3;
  }

  rtb_Integrator_idx_0 = rtDW.Integrator_DSTATE_m[0];
  rtb_Integrator_idx_1 = rtDW.Integrator_DSTATE_m[1];
  rtb_Integrator_idx_2 = rtDW.Integrator_DSTATE_m[2];
  rtb_Integrator_idx_3 = rtDW.Integrator_DSTATE_m[3];

  /* MinMax: '<S276>/Min' incorporates:
   *  Constant: '<S279>/Constant'
   *  DiscreteIntegrator: '<S287>/Integrator'
   *  RelationalOperator: '<S281>/LowerRelop1'
   *  RelationalOperator: '<S281>/UpperRelop'
   *  Switch: '<S281>/Switch'
   *  Switch: '<S281>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_m[0] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE_m[0] < 0.0) {
    /* Switch: '<S281>/Switch' incorporates:
     *  Constant: '<S279>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE_m[0];
  }

  u0 = fmin(fmin(fmin(rtb_SignPreIntegrator_e[0], rtb_Integrator_d[0]), 20.972),
            rtb_Saturation1);

  /* Saturate: '<S276>/Saturation_Positive' incorporates:
   *  MinMax: '<S276>/Min'
   */
  if (u0 <= 0.0) {
    rtb_SignPreIntegrator_e[0] = 0.0;
  } else {
    rtb_SignPreIntegrator_e[0] = u0;
  }

  /* MinMax: '<S276>/Min' incorporates:
   *  Constant: '<S279>/Constant'
   *  DiscreteIntegrator: '<S287>/Integrator'
   *  RelationalOperator: '<S281>/LowerRelop1'
   *  RelationalOperator: '<S281>/UpperRelop'
   *  Switch: '<S281>/Switch'
   *  Switch: '<S281>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_m[1] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE_m[1] < 0.0) {
    /* Switch: '<S281>/Switch' incorporates:
     *  Constant: '<S279>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE_m[1];
  }

  u0 = fmin(fmin(fmin(rtb_SignPreIntegrator_e[1], rtb_Integrator_d[1]), 20.972),
            rtb_Saturation1);

  /* Saturate: '<S276>/Saturation_Positive' incorporates:
   *  MinMax: '<S276>/Min'
   */
  if (u0 <= 0.0) {
    rtb_SignPreIntegrator_e[1] = 0.0;
  } else {
    rtb_SignPreIntegrator_e[1] = u0;
  }

  /* MinMax: '<S276>/Min' incorporates:
   *  Constant: '<S279>/Constant'
   *  DiscreteIntegrator: '<S287>/Integrator'
   *  RelationalOperator: '<S281>/LowerRelop1'
   *  RelationalOperator: '<S281>/UpperRelop'
   *  Switch: '<S281>/Switch'
   *  Switch: '<S281>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_m[2] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE_m[2] < 0.0) {
    /* Switch: '<S281>/Switch' incorporates:
     *  Constant: '<S279>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE_m[2];
  }

  u0 = fmin(fmin(fmin(rtb_SignPreIntegrator_e[2], rtb_Integrator_d[2]), 20.972),
            rtb_Saturation1);

  /* Saturate: '<S276>/Saturation_Positive' incorporates:
   *  MinMax: '<S276>/Min'
   */
  if (u0 <= 0.0) {
    rtb_SignPreIntegrator_e[2] = 0.0;
  } else {
    rtb_SignPreIntegrator_e[2] = u0;
  }

  /* MinMax: '<S276>/Min' incorporates:
   *  Constant: '<S279>/Constant'
   *  DiscreteIntegrator: '<S287>/Integrator'
   *  RelationalOperator: '<S281>/LowerRelop1'
   *  RelationalOperator: '<S281>/UpperRelop'
   *  Switch: '<S281>/Switch'
   *  Switch: '<S281>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_m[3] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE_m[3] < 0.0) {
    /* Switch: '<S281>/Switch' incorporates:
     *  Constant: '<S279>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE_m[3];
  }

  u0 = fmin(fmin(fmin(rtb_SignPreIntegrator_e[3], rtb_Integrator_d[3]), 20.972),
            rtb_Saturation1);

  /* Saturate: '<S276>/Saturation_Positive' incorporates:
   *  MinMax: '<S276>/Min'
   */
  if (u0 <= 0.0) {
    rtb_SignPreIntegrator_e[3] = 0.0;
  } else {
    rtb_SignPreIntegrator_e[3] = u0;
  }

  /* UnitDelay: '<S11>/Unit Delay1' */
  rtb_Tnew[0] = rtDW.UnitDelay1_DSTATE[0];
  rtb_Tnew[1] = rtDW.UnitDelay1_DSTATE[1];
  rtb_Tnew[2] = rtDW.UnitDelay1_DSTATE[2];
  rtb_Tnew[3] = rtDW.UnitDelay1_DSTATE[3];

  /* Math: '<S262>/Square1' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function2'
   *  Math: '<S262>/Square2'
   *  Math: '<S264>/Square1'
   */
  Faeroz_tmp = rtb_vx * rtb_vx;

  /* Gain: '<S262>/Lateral Load Transfer' incorporates:
   *  Gain: '<S263>/Lateral Load Transfer'
   *  Gain: '<S264>/Lateral Load Transfer'
   *  Gain: '<S265>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S262>/Unary Minus'
   */
  rtb_Saturation_k_idx_0 = 30.826771653543307 * -rtU.ay;

  /* Gain: '<S262>/Lift Force' incorporates:
   *  Gain: '<S263>/Lift Force'
   *  Math: '<S262>/Square1'
   */
  rtb_Saturation_k_idx_1 = Faeroz_tmp * 0.92446666666666677;

  /* Gain: '<S262>/Drag moment' incorporates:
   *  Gain: '<S263>/Drag moment'
   *  Gain: '<S264>/Drag moment'
   *  Gain: '<S265>/Drag moment'
   */
  rtb_Saturation_k_idx_2 = Faeroz_tmp * 0.21998117647058821;

  /* Gain: '<S262>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S263>/Longitudinal Load Transfer'
   *  Gain: '<S264>/Longitudinal Load Transfer'
   *  Gain: '<S265>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S262>/Unary Minus1'
   */
  rtb_Saturation_k_idx_3 = 25.588235294117645 * -rtU.ax;

  /* SignalConversion generated from: '<S254>/2-D Lookup Table' incorporates:
   *  Constant: '<S262>/Static Load Front'
   *  Constant: '<S263>/Static Load Front'
   *  Gain: '<S262>/Drag moment'
   *  Gain: '<S262>/Lateral Load Transfer'
   *  Gain: '<S262>/Lift Force'
   *  Gain: '<S262>/Longitudinal Load Transfer'
   *  Sum: '<S262>/Subtract'
   *  Sum: '<S263>/Subtract'
   */
  rtb_Integrator_d[0] = (((rtb_Saturation_k_idx_0 + 635.688) +
    rtb_Saturation_k_idx_1) - rtb_Saturation_k_idx_2) + rtb_Saturation_k_idx_3;
  rtb_Integrator_d[1] = (((635.688 - rtb_Saturation_k_idx_0) +
    rtb_Saturation_k_idx_1) - rtb_Saturation_k_idx_2) + rtb_Saturation_k_idx_3;

  /* Gain: '<S264>/Lift Force' incorporates:
   *  Gain: '<S265>/Lift Force'
   */
  rtb_Saturation_k_idx_1 = Faeroz_tmp * 0.74153333333333349;

  /* SignalConversion generated from: '<S254>/2-D Lookup Table' incorporates:
   *  Constant: '<S264>/Static Load Front'
   *  Constant: '<S265>/Static Load Front'
   *  Gain: '<S264>/Lift Force'
   *  Sum: '<S264>/Subtract'
   *  Sum: '<S265>/Subtract'
   */
  rtb_Integrator_d[2] = (((rtb_Saturation_k_idx_0 + 688.66200000000015) +
    rtb_Saturation_k_idx_1) + rtb_Saturation_k_idx_2) - rtb_Saturation_k_idx_3;
  rtb_Integrator_d[3] = (((688.66200000000015 - rtb_Saturation_k_idx_0) +
    rtb_Saturation_k_idx_1) + rtb_Saturation_k_idx_2) - rtb_Saturation_k_idx_3;

  /* Switch: '<S261>/Switch' incorporates:
   *  Constant: '<S261>/Constant'
   *  Sum: '<S266>/Subtract'
   *  Sum: '<S266>/Subtract1'
   *  Sum: '<S266>/Subtract2'
   *  Sum: '<S267>/Subtract'
   *  Sum: '<S267>/Subtract2'
   *  Sum: '<S268>/Subtract1'
   *  Trigonometry: '<S266>/Atan'
   *  Trigonometry: '<S267>/Atan'
   *  Trigonometry: '<S268>/Atan'
   *  Trigonometry: '<S269>/Atan'
   */
  if (rtb_vx > 3.0) {
    /* Sum: '<S266>/Subtract1' incorporates:
     *  Gain: '<S266>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S267>/Subtract1'
     */
    rtb_Saturation_k_idx_0 = 0.73439999999999994 * rtb_Gain1 + rtU.vy;

    /* Sum: '<S266>/Subtract' incorporates:
     *  Gain: '<S266>/Gain1'
     *  Sum: '<S268>/Subtract'
     */
    rtb_Saturation_k_idx_1 = rtb_vx - 0.635 * rtb_Gain1;
    rtb_UnaryMinus_d0[0] = rt_atan2d_snf(rtb_Saturation_k_idx_0,
      rtb_Saturation_k_idx_1) - rtb_Abs_i_idx_0;

    /* Sum: '<S267>/Subtract' incorporates:
     *  Gain: '<S267>/Gain1'
     *  Sum: '<S266>/Subtract'
     *  Sum: '<S266>/Subtract1'
     *  Sum: '<S266>/Subtract2'
     *  Sum: '<S269>/Subtract'
     *  Trigonometry: '<S266>/Atan'
     */
    rtb_Saturation_k_idx_2 = 0.635 * rtb_Gain1 + rtb_vx;
    rtb_UnaryMinus_d0[1] = rt_atan2d_snf(rtb_Saturation_k_idx_0,
      rtb_Saturation_k_idx_2) - rtb_Abs_l;

    /* Sum: '<S268>/Subtract1' incorporates:
     *  Gain: '<S268>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S267>/Subtract'
     *  Sum: '<S267>/Subtract2'
     *  Sum: '<S269>/Subtract1'
     *  Trigonometry: '<S267>/Atan'
     */
    rtb_Saturation_k_idx_0 = rtU.vy - 0.79560000000000008 * rtb_Gain1;
    rtb_UnaryMinus_d0[2] = rt_atan2d_snf(rtb_Saturation_k_idx_0,
      rtb_Saturation_k_idx_1);
    rtb_UnaryMinus_d0[3] = rt_atan2d_snf(rtb_Saturation_k_idx_0,
      rtb_Saturation_k_idx_2);
  } else {
    rtb_UnaryMinus_d0[0] = 0.0;
    rtb_UnaryMinus_d0[1] = 0.0;
    rtb_UnaryMinus_d0[2] = 0.0;
    rtb_UnaryMinus_d0[3] = 0.0;
  }

  /* End of Switch: '<S261>/Switch' */

  /* Lookup_n-D: '<S254>/2-D Lookup Table' */
  rtb_Saturation_k_idx_0 = look2_binlx(rtb_Integrator_d[0], rtb_UnaryMinus_d0[0],
    rtConstP.pooled50, rtConstP.pooled51, rtConstP.uDLookupTable_tableData_h,
    rtConstP.pooled66, 30U);
  rtb_Saturation_k_idx_1 = look2_binlx(rtb_Integrator_d[1], rtb_UnaryMinus_d0[1],
    rtConstP.pooled50, rtConstP.pooled51, rtConstP.uDLookupTable_tableData_h,
    rtConstP.pooled66, 30U);
  rtb_Saturation_k_idx_2 = look2_binlx(rtb_Integrator_d[2], rtb_UnaryMinus_d0[2],
    rtConstP.pooled50, rtConstP.pooled51, rtConstP.uDLookupTable_tableData_h,
    rtConstP.pooled66, 30U);
  rtb_Saturation_k_idx_3 = look2_binlx(rtb_Integrator_d[3], rtb_UnaryMinus_d0[3],
    rtConstP.pooled50, rtConstP.pooled51, rtConstP.uDLookupTable_tableData_h,
    rtConstP.pooled66, 30U);

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_Sign = 3.5714285714285712 * rtU.brake;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Sign > 1.0) {
    rtb_Sign = 1.0;
  } else if (rtb_Sign < 0.0) {
    rtb_Sign = 0.0;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Switch: '<S248>/Switch' */
  rtb_Saturation1 = !(rtb_Sign > 0.95);

  /* Saturate: '<S254>/Saturation1' incorporates:
   *  Gain: '<S254>/Gain'
   *  Product: '<S254>/Product'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_k_idx_0 * 20.0;
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S248>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_SignPreIntegrator_e[0] = fmin(fmin(rtb_SignPreIntegrator_e[0],
    rtDW.UnitDelay1_DSTATE[0]), u0) * rtb_Saturation1;

  /* Saturate: '<S254>/Saturation1' incorporates:
   *  Gain: '<S254>/Gain'
   *  Product: '<S254>/Product'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_k_idx_1 * 20.0;
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S248>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_SignPreIntegrator_e[1] = fmin(fmin(rtb_SignPreIntegrator_e[1],
    rtDW.UnitDelay1_DSTATE[1]), u0) * rtb_Saturation1;

  /* Saturate: '<S254>/Saturation1' incorporates:
   *  Gain: '<S254>/Gain'
   *  Product: '<S254>/Product'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_k_idx_2 * 20.0;
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S248>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_SignPreIntegrator_e[2] = fmin(fmin(rtb_SignPreIntegrator_e[2],
    rtDW.UnitDelay1_DSTATE[2]), u0) * rtb_Saturation1;

  /* Saturate: '<S254>/Saturation1' incorporates:
   *  Gain: '<S254>/Gain'
   *  Product: '<S254>/Product'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_k_idx_3 * 20.0;
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S248>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_SignPreIntegrator_e[3] = fmin(fmin(rtb_SignPreIntegrator_e[3],
    rtDW.UnitDelay1_DSTATE[3]), u0) * rtb_Saturation1;

  /* Lookup_n-D: '<S254>/2-D Lookup Table1' */
  rtb_Integrator_d[0] = look2_binlx(rtb_Integrator_d[0], rtb_UnaryMinus_d0[0],
    rtConstP.pooled50, rtConstP.pooled51, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled66, 30U);
  rtb_Integrator_d[1] = look2_binlx(rtb_Integrator_d[1], rtb_UnaryMinus_d0[1],
    rtConstP.pooled50, rtConstP.pooled51, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled66, 30U);
  rtb_Integrator_d[2] = look2_binlx(rtb_Integrator_d[2], rtb_UnaryMinus_d0[2],
    rtConstP.pooled50, rtConstP.pooled51, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled66, 30U);
  rtb_Integrator_d[3] = look2_binlx(rtb_Integrator_d[3], rtb_UnaryMinus_d0[3],
    rtConstP.pooled50, rtConstP.pooled51, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled66, 30U);

  /* Product: '<S254>/Product1' incorporates:
   *  Gain: '<S254>/Gain1'
   */
  rtb_Product1[0] = 0.017407407407407406 * rtb_Integrator_d[0] * 20.0;
  rtb_Product1[1] = 0.017407407407407406 * rtb_Integrator_d[1] * 20.0;
  rtb_Product1[2] = 0.017407407407407406 * rtb_Integrator_d[2] * 20.0;
  rtb_Product1[3] = 0.017407407407407406 * rtb_Integrator_d[3] * 20.0;

  /* Lookup_n-D: '<S277>/Display Overload Motor LUT' */
  rtb_UnaryMinus_d0[0] = rtb_Integrator_c_idx_0;
  rtb_UnaryMinus_d0[1] = rtb_Integrator_c_idx_0;
  rtb_UnaryMinus_d0[2] = rtb_Integrator_c_idx_0;
  rtb_UnaryMinus_d0[3] = rtb_Integrator_c_idx_0;

  /* Lookup_n-D: '<S277>/Display Overload Inverter LUT' */
  rtb_Tnew[0] = rtb_Integrator_c_idx_0;
  rtb_Tnew[1] = rtb_Integrator_c_idx_0;
  rtb_Tnew[2] = rtb_Integrator_c_idx_0;
  rtb_Tnew[3] = rtb_Integrator_c_idx_0;

  /* RelationalOperator: '<S294>/Compare' incorporates:
   *  Constant: '<S291>/Time constant'
   *  Constant: '<S294>/Constant'
   *  Sum: '<S291>/Sum1'
   */
  rtb_Compare_p = (0.079577471545947673 - rtDW.Probe_k[0] <= 0.0);

  /* Saturate: '<S288>/Saturation1' */
  if (rtb_Gain3 <= 0.0) {
    rtb_Integrator_d[0] = 0.0;
  } else {
    rtb_Integrator_d[0] = rtb_Gain3;
  }

  if (rtb_SumofElements1 <= 0.0) {
    rtb_Integrator_d[1] = 0.0;
  } else {
    rtb_Integrator_d[1] = rtb_SumofElements1;
  }

  if (u0_tmp <= 0.0) {
    rtb_Integrator_d[2] = 0.0;
  } else {
    rtb_Integrator_d[2] = u0_tmp;
  }

  if (u0_tmp_0 <= 0.0) {
    rtb_Integrator_d[3] = 0.0;
  } else {
    rtb_Integrator_d[3] = u0_tmp_0;
  }

  /* End of Saturate: '<S288>/Saturation1' */

  /* Lookup_n-D: '<S288>/2-D Lookup Table' incorporates:
   *  Constant: '<S277>/Constant7'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &cumRevIndex);
  fractions_0[1U] = cumRevIndex;
  bpIndices_0[0U] = plook_binc(rtb_Integrator_d[0], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions_0[0U] = cumRevIndex;
  rtb_Integrator_d[0] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13,
    201U);
  bpIndices_0[0U] = plook_binc(rtb_Integrator_d[1], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions_0[0U] = cumRevIndex;
  rtb_Integrator_d[1] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13,
    201U);
  bpIndices_0[0U] = plook_binc(rtb_Integrator_d[2], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions_0[0U] = cumRevIndex;
  rtb_Integrator_d[2] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13,
    201U);
  bpIndices_0[0U] = plook_binc(rtb_Integrator_d[3], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions_0[0U] = cumRevIndex;
  rtb_Integrator_d[3] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13,
    201U);

  /* Gain: '<S288>/Gain' */
  rtb_Saturation_k_idx_0 = 0.0098000000000000014 * rtb_Integrator_d[0];
  rtb_Saturation_k_idx_1 = 0.0098000000000000014 * rtb_Integrator_d[1];
  rtb_Saturation_k_idx_2 = 0.0098000000000000014 * rtb_Integrator_d[2];
  rtb_Saturation_k_idx_3 = 0.0098000000000000014 * rtb_Integrator_d[3];

  /* DiscreteIntegrator: '<S296>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_j != 0) {
    rtDW.Integrator_DSTATE_f[0] = rtb_Saturation_k_idx_0;
    rtDW.Integrator_DSTATE_f[1] = rtb_Saturation_k_idx_1;
    rtDW.Integrator_DSTATE_f[2] = rtb_Saturation_k_idx_2;
    rtDW.Integrator_DSTATE_f[3] = rtb_Saturation_k_idx_3;
  }

  if (rtb_Compare_p || (rtDW.Integrator_PrevResetState_b != 0)) {
    rtDW.Integrator_DSTATE_f[0] = rtb_Saturation_k_idx_0;
    rtDW.Integrator_DSTATE_f[1] = rtb_Saturation_k_idx_1;
    rtDW.Integrator_DSTATE_f[2] = rtb_Saturation_k_idx_2;
    rtDW.Integrator_DSTATE_f[3] = rtb_Saturation_k_idx_3;
  }

  rtb_Integrator_c_idx_0 = rtDW.Integrator_DSTATE_f[0];
  rtb_Integrator_c_idx_1 = rtDW.Integrator_DSTATE_f[1];
  rtb_Integrator_c_idx_2 = rtDW.Integrator_DSTATE_f[2];
  rtb_Integrator_c_idx_3 = rtDW.Integrator_DSTATE_f[3];

  /* Sum: '<S270>/Subtract' incorporates:
   *  Gain: '<S270>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[0] + rtb_Product1[0];

  /* Switch: '<S290>/Switch2' incorporates:
   *  Constant: '<S288>/Constant'
   *  DiscreteIntegrator: '<S296>/Integrator'
   *  RelationalOperator: '<S290>/LowerRelop1'
   *  RelationalOperator: '<S290>/UpperRelop'
   *  Switch: '<S290>/Switch'
   */
  if (rtDW.Integrator_DSTATE_f[0] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE_f[0] < 0.0) {
    /* Switch: '<S290>/Switch' incorporates:
     *  Constant: '<S288>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE_f[0];
  }

  /* MinMax: '<S277>/Min1' */
  cumRevIndex = fmin(fmin(fmin(rtb_UnaryMinus_d0[0], rtb_Tnew[0]), 20.972),
                     rtb_Saturation1);

  /* Saturate: '<S254>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S277>/Saturation_Positive' */
  if (cumRevIndex <= 0.0) {
    cumRevIndex = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Integrator_d[0] = fmax(fmax(u0, -cumRevIndex), rtDW.UnitDelay2_DSTATE[0]);

  /* Sum: '<S270>/Subtract' incorporates:
   *  Gain: '<S270>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[1] + rtb_Product1[1];

  /* Switch: '<S290>/Switch2' incorporates:
   *  Constant: '<S288>/Constant'
   *  DiscreteIntegrator: '<S296>/Integrator'
   *  RelationalOperator: '<S290>/LowerRelop1'
   *  RelationalOperator: '<S290>/UpperRelop'
   *  Switch: '<S290>/Switch'
   */
  if (rtDW.Integrator_DSTATE_f[1] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE_f[1] < 0.0) {
    /* Switch: '<S290>/Switch' incorporates:
     *  Constant: '<S288>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE_f[1];
  }

  /* MinMax: '<S277>/Min1' */
  cumRevIndex = fmin(fmin(fmin(rtb_UnaryMinus_d0[1], rtb_Tnew[1]), 20.972),
                     rtb_Saturation1);

  /* Saturate: '<S254>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S277>/Saturation_Positive' */
  if (cumRevIndex <= 0.0) {
    cumRevIndex = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Integrator_d[1] = fmax(fmax(u0, -cumRevIndex), rtDW.UnitDelay2_DSTATE[1]);

  /* Sum: '<S270>/Subtract' incorporates:
   *  Gain: '<S270>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[2] + rtb_Product1[2];

  /* Switch: '<S290>/Switch2' incorporates:
   *  Constant: '<S288>/Constant'
   *  DiscreteIntegrator: '<S296>/Integrator'
   *  RelationalOperator: '<S290>/LowerRelop1'
   *  RelationalOperator: '<S290>/UpperRelop'
   *  Switch: '<S290>/Switch'
   */
  if (rtDW.Integrator_DSTATE_f[2] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE_f[2] < 0.0) {
    /* Switch: '<S290>/Switch' incorporates:
     *  Constant: '<S288>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE_f[2];
  }

  /* MinMax: '<S277>/Min1' */
  cumRevIndex = fmin(fmin(fmin(rtb_UnaryMinus_d0[2], rtb_Tnew[2]), 20.972),
                     rtb_Saturation1);

  /* Saturate: '<S254>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S277>/Saturation_Positive' */
  if (cumRevIndex <= 0.0) {
    cumRevIndex = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Integrator_d[2] = fmax(fmax(u0, -cumRevIndex), rtDW.UnitDelay2_DSTATE[2]);

  /* Sum: '<S270>/Subtract' incorporates:
   *  Gain: '<S270>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[3] + rtb_Product1[3];

  /* Switch: '<S290>/Switch2' incorporates:
   *  Constant: '<S288>/Constant'
   *  DiscreteIntegrator: '<S296>/Integrator'
   *  RelationalOperator: '<S290>/LowerRelop1'
   *  RelationalOperator: '<S290>/UpperRelop'
   *  Switch: '<S290>/Switch'
   */
  if (rtDW.Integrator_DSTATE_f[3] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE_f[3] < 0.0) {
    /* Switch: '<S290>/Switch' incorporates:
     *  Constant: '<S288>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE_f[3];
  }

  /* MinMax: '<S277>/Min1' */
  cumRevIndex = fmin(fmin(fmin(rtb_UnaryMinus_d0[3], rtb_Tnew[3]), 20.972),
                     rtb_Saturation1);

  /* Saturate: '<S254>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S277>/Saturation_Positive' */
  if (cumRevIndex <= 0.0) {
    cumRevIndex = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Integrator_d[3] = fmax(fmax(u0, -cumRevIndex), rtDW.UnitDelay2_DSTATE[3]);

  /* CombinatorialLogic: '<S256>/Logic' incorporates:
   *  Constant: '<S247>/Constant'
   *  Constant: '<S247>/Constant1'
   *  Memory: '<S256>/Memory'
   *  RelationalOperator: '<S247>/Less Than'
   *  RelationalOperator: '<S247>/Less Than1'
   */
  b_exit = (int32_T)(((((uint32_T)(rtb_Switch <= -0.6) << 1) + (rtb_Switch >=
    -0.5)) << 1) + rtDW.Memory_PreviousInput_f);
  rtb_Logic_idx_0 = rtConstP.pooled69[(uint32_T)b_exit];
  rtb_Logic_idx_1 = rtConstP.pooled69[b_exit + 8U];

  /* CombinatorialLogic: '<S257>/Logic' incorporates:
   *  Constant: '<S247>/Constant'
   *  Constant: '<S247>/Constant1'
   *  Memory: '<S257>/Memory'
   *  RelationalOperator: '<S247>/Less Than'
   *  RelationalOperator: '<S247>/Less Than1'
   */
  b_exit = (int32_T)(((((uint32_T)(rtb_Switch_gx <= -0.6) << 1) + (rtb_Switch_gx
    >= -0.5)) << 1) + rtDW.Memory_PreviousInput_j);
  rtb_Logic_d_idx_0 = rtConstP.pooled69[(uint32_T)b_exit];
  rtb_Logic_d_idx_1 = rtConstP.pooled69[b_exit + 8U];

  /* CombinatorialLogic: '<S258>/Logic' incorporates:
   *  Constant: '<S247>/Constant'
   *  Constant: '<S247>/Constant1'
   *  Memory: '<S258>/Memory'
   *  RelationalOperator: '<S247>/Less Than'
   *  RelationalOperator: '<S247>/Less Than1'
   */
  b_exit = (int32_T)(((((uint32_T)(rtb_RL <= -0.6) << 1) + (rtb_RL >= -0.5)) <<
                      1) + rtDW.Memory_PreviousInput_j4);
  rtb_Logic_o_idx_0 = rtConstP.pooled69[(uint32_T)b_exit];
  rtb_Logic_o_idx_1 = rtConstP.pooled69[b_exit + 8U];

  /* CombinatorialLogic: '<S259>/Logic' incorporates:
   *  Constant: '<S247>/Constant'
   *  Constant: '<S247>/Constant1'
   *  Memory: '<S259>/Memory'
   *  RelationalOperator: '<S247>/Less Than'
   *  RelationalOperator: '<S247>/Less Than1'
   */
  b_exit = (int32_T)(((((uint32_T)(rtb_RR <= -0.6) << 1) + (rtb_RR >= -0.5)) <<
                      1) + rtDW.Memory_PreviousInput_i);
  rtb_Logic_ds_idx_0 = rtConstP.pooled69[(uint32_T)b_exit];

  /* Product: '<S247>/Product' incorporates:
   *  CombinatorialLogic: '<S259>/Logic'
   */
  rtb_Tnew[0] = rtb_Integrator_d[0] * (real_T)rtb_Logic_idx_1;
  rtb_Tnew[1] = rtb_Integrator_d[1] * (real_T)rtb_Logic_d_idx_1;
  rtb_Tnew[2] = (real_T)rtb_Logic_o_idx_1 * rtb_Integrator_d[2];
  rtb_Tnew[3] = (real_T)rtConstP.pooled69[b_exit + 8U] * rtb_Integrator_d[3];

  /* Outputs for Atomic SubSystem: '<S140>/YRD_LUT_-2' */
  /* Abs: '<S172>/Abs' incorporates:
   *  Abs: '<S275>/Abs'
   */
  u0_tmp_0 = fabs(rtb_front_wheel_angle_single__d);

  /* End of Outputs for SubSystem: '<S140>/YRD_LUT_-2' */

  /* MATLABSystem: '<S172>/Moving Average' incorporates:
   *  Abs: '<S172>/Abs'
   */
  if (rtDW.obj.TunablePropsChanged) {
    rtDW.obj.TunablePropsChanged = false;
  }

  obj = rtDW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (b_exit = 0; b_exit < 24; b_exit++) {
      obj->pCumSumRev[b_exit] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (b_exit = 0; b_exit < 24; b_exit++) {
      obj->pCumSumRev[b_exit] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  rtb_Integrator_m = obj->pCumSum;
  for (b_exit = 0; b_exit < 24; b_exit++) {
    csumrev[b_exit] = obj->pCumSumRev[b_exit];
  }

  modValueRev = obj->pModValueRev;
  z = 0.0;
  rtb_Gain3 = 0.0;
  rtb_Integrator_m += u0_tmp_0;
  if (modValueRev == 0.0) {
    z = csumrev[(int32_T)cumRevIndex - 1] + rtb_Integrator_m;
  }

  csumrev[(int32_T)cumRevIndex - 1] = u0_tmp_0;
  if (cumRevIndex != 24.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    rtb_Integrator_m = 0.0;
    for (b_exit = 22; b_exit >= 0; b_exit--) {
      csumrev[b_exit] += csumrev[b_exit + 1];
    }
  }

  if (modValueRev == 0.0) {
    rtb_Gain3 = z / 25.0;
  }

  obj->pCumSum = rtb_Integrator_m;
  for (b_exit = 0; b_exit < 24; b_exit++) {
    obj->pCumSumRev[b_exit] = csumrev[b_exit];
  }

  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* CombinatorialLogic: '<S232>/Logic' incorporates:
   *  Abs: '<S172>/Abs'
   *  Constant: '<S172>/Constant1'
   *  Constant: '<S172>/Constant4'
   *  Delay: '<S172>/Delay'
   *  Logic: '<S172>/AND'
   *  MATLABSystem: '<S172>/Moving Average'
   *  Memory: '<S232>/Memory'
   *  RelationalOperator: '<S172>/Less Than'
   *  RelationalOperator: '<S172>/Less Than2'
   */
  rtb_Logic_idx_1 = rtConstP.pooled69[((((uint32_T)(0.017453292519943295 <=
    u0_tmp_0) << 1) + ((rtb_Gain3 < 0.0043633231299858239) && rtDW.Delay_DSTATE
                       [0])) << 1) + rtDW.Memory_PreviousInput_l];

  /* Outputs for IfAction SubSystem: '<S172>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S231>/Action Port'
   */
  /* If: '<S172>/If' incorporates:
   *  Constant: '<S172>/Constant'
   *  DataTypeConversion: '<S231>/Data Type Conversion'
   *  Logic: '<S172>/AND1'
   *  RelationalOperator: '<S172>/Less Than1'
   */
  rtb_Logic_d_idx_1 = (rtb_Logic_idx_1 && (rtb_vx >= 3.0));

  /* End of Outputs for SubSystem: '<S172>/If Action Subsystem1' */

  /* SignalConversion generated from: '<S251>/ SFunction ' incorporates:
   *  MATLAB Function: '<S150>/Cross Check'
   */
  cumRevIndex = rtb_Tnew[1];

  /* MATLAB Function: '<S150>/Cross Check' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/throttle'
   */
  rtb_Integrator_d[0] = rtb_Tnew[0];
  rtb_Integrator_d[1] = rtb_Tnew[1];
  rtb_Integrator_d[2] = rtb_Tnew[2];
  rtb_Integrator_d[3] = rtb_Tnew[3];
  if (rtb_Logic_d_idx_1) {
    b_exit = 0;
  } else {
    b_exit = 1;
  }

  if (b_exit == 0) {
    if (rtb_Tnew[0] > rtb_SignPreIntegrator_e[0]) {
      rtb_Integrator_d[0] = rtb_SignPreIntegrator_e[0] - cumRevIndex;
    }

    if (rtb_Tnew[1] > rtb_SignPreIntegrator_e[1]) {
      rtb_Integrator_d[1] = rtb_SignPreIntegrator_e[1] - cumRevIndex;
    }

    if (rtb_Tnew[2] > rtb_SignPreIntegrator_e[2]) {
      rtb_Integrator_d[2] = rtb_SignPreIntegrator_e[2] - cumRevIndex;
    }

    if (rtb_Tnew[3] > rtb_SignPreIntegrator_e[3]) {
      rtb_Integrator_d[3] = rtb_SignPreIntegrator_e[3] - cumRevIndex;
    }
  } else if (rtU.throttle > 0.05) {
    rtb_Integrator_d[0] = 0.0;
    rtb_Integrator_d[1] = 0.0;
    rtb_Integrator_d[2] = 0.0;
    rtb_Integrator_d[3] = 0.0;
  } else if (rtU.brake > 0.05) {
    rtb_SignPreIntegrator_e[0] = 0.0;
    rtb_SignPreIntegrator_e[1] = 0.0;
    rtb_SignPreIntegrator_e[2] = 0.0;
    rtb_SignPreIntegrator_e[3] = 0.0;
  }

  /* CFunction: '<S249>/C Function' incorporates:
   *  Constant: '<S249>/Constant3'
   */
  rtDW.CFunction_p[0] = rtb_Integrator_d[0];
  rtDW.CFunction_p[1] = rtb_Integrator_d[1];
  rtDW.CFunction_p[2] = rtb_Integrator_d[2];
  rtDW.CFunction_p[3] = rtb_Integrator_d[3];

  /* CFunction: '<S250>/C Function' incorporates:
   *  Constant: '<S250>/Constant3'
   */
  rtDW.CFunction_f[0] = rtb_SignPreIntegrator_e[0];
  rtDW.CFunction_f[1] = rtb_SignPreIntegrator_e[1];
  rtDW.CFunction_f[2] = rtb_SignPreIntegrator_e[2];
  rtDW.CFunction_f[3] = rtb_SignPreIntegrator_e[3];

  /* Sum: '<S233>/Sum of Elements' */
  rtb_Saturation1 = ((rtDW.CFunction_f[0] + rtDW.CFunction_f[1]) +
                     rtDW.CFunction_f[2]) + rtDW.CFunction_f[3];

  /* Product: '<S233>/Product' incorporates:
   *  Constant: '<S233>/Constant1'
   *  Constant: '<S233>/Constant2'
   *  Constant: '<S240>/Constant'
   *  Constant: '<S240>/Exponent < 0'
   *  Gain: '<S233>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S233>/ '
   *  Math: '<S240>/Power'
   *  Product: '<S233>/Product1'
   *  Product: '<S240>/Divide'
   *  Product: '<S240>/Divide1'
   *  RelationalOperator: '<S233>/Less Than'
   *  RelationalOperator: '<S233>/Less Than1'
   *  Sum: '<S233>/Subtract1'
   *  Sum: '<S240>/Subtract'
   *  Sum: '<S240>/Sum'
   */
  cumRevIndex = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle), -1.5) +
                        1.0) - rtb_Sign) * (real_T)(int8_T)((int8_T)(rtb_Sign >=
    0.05) ^ (int8_T)(rtU.throttle >= 0.05)) * 84.0;

  /* Switch: '<S241>/Switch2' incorporates:
   *  RelationalOperator: '<S241>/LowerRelop1'
   */
  if (!(cumRevIndex > rtb_Saturation1)) {
    /* Sum: '<S233>/Sum of Elements1' */
    rtb_SumofElements1 = ((rtDW.CFunction_p[0] + rtDW.CFunction_p[1]) +
                          rtDW.CFunction_p[2]) + rtDW.CFunction_p[3];

    /* Switch: '<S241>/Switch' incorporates:
     *  RelationalOperator: '<S241>/UpperRelop'
     */
    if (cumRevIndex < rtb_SumofElements1) {
      rtb_Saturation1 = rtb_SumofElements1;
    } else {
      rtb_Saturation1 = cumRevIndex;
    }

    /* End of Switch: '<S241>/Switch' */
  }

  /* End of Switch: '<S241>/Switch2' */

  /* Gain: '<S233>/Gain2' */
  z = 0.95 * rtb_Saturation1;

  /* Gain: '<S233>/Gain3' */
  rtb_Gain3 = 1.05 * rtb_Saturation1;

  /* Switch: '<S234>/Switch2' incorporates:
   *  Constant: '<S234>/Engine Brake'
   *  Constant: '<S242>/Constant1'
   *  Constant: '<S242>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S242>/AND'
   *  MinMax: '<S234>/Max1'
   *  RelationalOperator: '<S242>/Less Than'
   *  RelationalOperator: '<S242>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_Sign)) {
    cumRevIndex = -0.0;
  } else {
    cumRevIndex = fmin(z, rtb_Gain3);
  }

  /* End of Switch: '<S234>/Switch2' */

  /* UnaryMinus: '<S235>/Unary Minus1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Saturate: '<S235>/Max Regen'
   */
  rtb_Saturation1 = -0.0;

  /* InitialCondition: '<S235>/IC' */
  if (rtDW.IC_FirstOutputTime) {
    rtDW.IC_FirstOutputTime = false;
    rtb_Saturation1 = -35000.0;
  }

  /* End of InitialCondition: '<S235>/IC' */

  /* Product: '<S235>/Divide1' incorporates:
   *  Constant: '<S235>/Constant'
   */
  rtb_Integrator_m = 0.001 * rtb_Saturation1;

  /* MATLAB Function: '<S146>/MATLAB Function4' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function3'
   *  MATLAB Function: '<S148>/MATLAB Function'
   */
  rtb_Abs_i_idx_0 = 0.765 * sin(rtb_Abs_i_idx_0) - 0.635 * cos(rtb_Abs_i_idx_0);
  rtb_Abs_l = 0.765 * sin(rtb_Abs_l) + 0.635 * cos(rtb_Abs_l);
  modValueRev = ((rtb_Abs_i_idx_0 * rtDW.CFunction_p[0] + rtb_Abs_l *
                  rtDW.CFunction_f[1]) - 0.635 * rtDW.CFunction_p[2]) + 0.635 *
    rtDW.CFunction_f[3];

  /* Outputs for Atomic SubSystem: '<S140>/YRD_LUT_-2' */
  /* Saturate: '<S275>/Saturation' */
  if (rtb_vx <= 3.0) {
    rtb_Saturation1 = 3.0;
  } else {
    rtb_Saturation1 = rtb_vx;
  }

  /* End of Saturate: '<S275>/Saturation' */

  /* Product: '<S275>/Divide2' incorporates:
   *  Lookup_n-D: '<S275>/LUT_-3'
   *  Product: '<S275>/Divide'
   *  Product: '<S275>/Divide1'
   *  Signum: '<S199>/SignPreIntegrator'
   */
  rtb_SumofElements1 = rtb_front_wheel_angle_single__d / u0_tmp_0 * (look2_binlx
    (u0_tmp_0, rtb_Saturation1, rtConstP.LUT_3_bp01Data, rtConstP.LUT_3_bp02Data,
     rtConstP.LUT_3_tableData, rtConstP.LUT_3_maxIndex, 100U) / rtb_Saturation1);

  /* End of Outputs for SubSystem: '<S140>/YRD_LUT_-2' */

  /* SignalConversion generated from: '<S167>/ SFunction ' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function2'
   */
  rtb_Integrator_d[0] = rtb_Switch;
  rtb_Integrator_d[1] = rtb_Switch_gx;
  rtb_Integrator_d[2] = rtb_RL;
  rtb_Integrator_d[3] = rtb_RR;

  /* MATLAB Function: '<S146>/MATLAB Function2' incorporates:
   *  Constant: '<S146>/Constant'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/vy'
   *  Sum: '<S170>/Sum1'
   *  Sum: '<S170>/Sum2'
   */
  rtb_Switch_gx = Faeroz_tmp * 3.14825;
  rtb_RL_tmp = rtb_Gain1 * 1.27 / 2.0;
  rtb_RL_tmp_0 = rtb_Gain1 * 0.73439999999999994 + rtU.vy;
  u0 = rtb_vx - rtb_RL_tmp;
  rtb_RL = atan(rtb_RL_tmp_0 / u0) - rtb_front_wheel_angle_single__d;
  rtb_Sign = rtb_RL_tmp + rtb_vx;
  rtb_Saturation1 = atan(rtb_RL_tmp_0 / rtb_Sign) -
    rtb_front_wheel_angle_single__d;
  rtb_Switch = rtU.vy - rtb_Gain1 * 0.79560000000000008;
  rtb_front_wheel_angle_single__d = atan(rtb_Switch / u0);
  rtb_Switch = atan(rtb_Switch / rtb_Sign);
  u0_tmp = 0.5 * rtb_Switch_gx * 0.55490196078431375;
  rtb_RR = Faeroz_tmp * 1.0461500000000001 * 0.5 / 1.53 * 0.576;
  rtb_Sign = (((635.688 - 30.826771653543307 * rtU.ay) + u0_tmp) - rtb_RR) -
    25.588235294117645 * rtU.ax;
  u0_tmp_0 = (((30.826771653543307 * rtU.ay + 635.688) + u0_tmp) - rtb_RR) -
    25.588235294117645 * rtU.ax;
  Faeroz_tmp = 0.5 * rtb_Switch_gx * 0.4450980392156863;
  rtb_Switch_gx = (((688.66200000000015 - 30.826771653543307 * rtU.ay) +
                    Faeroz_tmp) + rtb_RR) + 25.588235294117645 * rtU.ax;
  rtb_RR = (((30.826771653543307 * rtU.ay + 688.66200000000015) + Faeroz_tmp) +
            rtb_RR) + 25.588235294117645 * rtU.ax;
  Faeroz_tmp = 12.4 * rtb_RL - 0.512;
  rtb_RL_tmp = (1.14E-6 * rtb_Sign - rtb_RL) + 0.00239;
  if (rtb_RL_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (rtb_RL_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (rtb_RL_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  rtb_RL_tmp_tmp = 0.000282 * rtb_Sign - 2.02;
  rtb_RL_tmp = sin(atan(0.000559 * rtb_Sign) * 2.0) * 34500.0 * rtb_RL_tmp /
    (1.34 * rtb_Sign * 0.8 * rtb_RL_tmp_tmp - 0.01);
  u0 = 0.0013 * rtb_Sign - 2.33;
  rtb_RL_tmp_tmp_0 = sqrt(Faeroz_tmp * Faeroz_tmp + 1.0);
  rtb_RL_tmp_0 = (3.86E-7 * rtb_Sign + 0.000205) * 13.9 / rtb_RL_tmp_tmp_0;
  rtb_RL = (sin(atan(rtb_RL_tmp - (0.26 * u0_tmp + 1.0) * (3.99E-5 * rtb_Sign -
    0.521) * (atan(rtb_RL_tmp) - rtb_RL_tmp)) * 1.34) * (rtb_Sign * 0.8) *
            rtb_RL_tmp_tmp + (7.1E-5 * rtb_Sign - 0.149) * (rtb_Sign * 0.8)) *
    cos(atan((atan(((3.86E-7 * rtb_Sign - rtb_Integrator_d[0]) + 0.000205) *
                   13.9 / rtb_RL_tmp_tmp_0) - ((3.86E-7 * rtb_Sign -
            rtb_Integrator_d[0]) + 0.000205) * 13.9 / sqrt(Faeroz_tmp *
           Faeroz_tmp + 1.0)) * u0 + ((3.86E-7 * rtb_Sign - rtb_Integrator_d[0])
          + 0.000205) * 13.9 / sqrt(Faeroz_tmp * Faeroz_tmp + 1.0)) * 0.958) /
    cos(atan((atan(rtb_RL_tmp_0) - rtb_RL_tmp_0) * u0 + rtb_RL_tmp_0) * 0.958) -
    sin(atan(16.1 * rtb_Integrator_d[0]) * 1.94) * (rtb_Sign * 0.8) *
    rtb_RL_tmp_tmp * (1.03E-5 * rtb_Sign - 0.000288) / sqrt(rtb_RL * rtb_RL *
    225.0 + 1.0);
  Faeroz_tmp = 12.4 * rtb_Saturation1 - 0.512;
  rtb_RL_tmp = (1.14E-6 * u0_tmp_0 - rtb_Saturation1) + 0.00239;
  if (rtb_RL_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (rtb_RL_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (rtb_RL_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  u0 = 0.000282 * u0_tmp_0 - 2.02;
  rtb_Sign = sin(atan(0.000559 * u0_tmp_0) * 2.0) * 34500.0 * rtb_RL_tmp / (1.34
    * u0_tmp_0 * 0.8 * u0 - 0.01);
  rtb_RL_tmp = 0.0013 * u0_tmp_0 - 2.33;
  rtb_RL_tmp_0 = sqrt(Faeroz_tmp * Faeroz_tmp + 1.0);
  rtb_RL_tmp_tmp = (3.86E-7 * u0_tmp_0 + 0.000205) * 13.9 / rtb_RL_tmp_0;
  rtb_Saturation1 = (sin(atan(rtb_Sign - (0.26 * u0_tmp + 1.0) * (3.99E-5 *
    u0_tmp_0 - 0.521) * (atan(rtb_Sign) - rtb_Sign)) * 1.34) * (u0_tmp_0 * 0.8) *
                     u0 + (7.1E-5 * u0_tmp_0 - 0.149) * (u0_tmp_0 * 0.8)) * cos
    (atan((atan(((3.86E-7 * u0_tmp_0 - rtb_Integrator_d[1]) + 0.000205) * 13.9 /
                rtb_RL_tmp_0) - ((3.86E-7 * u0_tmp_0 - rtb_Integrator_d[1]) +
        0.000205) * 13.9 / sqrt(Faeroz_tmp * Faeroz_tmp + 1.0)) * rtb_RL_tmp +
          ((3.86E-7 * u0_tmp_0 - rtb_Integrator_d[1]) + 0.000205) * 13.9 / sqrt
          (Faeroz_tmp * Faeroz_tmp + 1.0)) * 0.958) / cos(atan((atan
    (rtb_RL_tmp_tmp) - rtb_RL_tmp_tmp) * rtb_RL_tmp + rtb_RL_tmp_tmp) * 0.958) -
    sin(atan(16.1 * rtb_Integrator_d[1]) * 1.94) * (u0_tmp_0 * 0.8) * u0 *
    (1.03E-5 * u0_tmp_0 - 0.000288) / sqrt(rtb_Saturation1 * rtb_Saturation1 *
    225.0 + 1.0);
  rtb_Sign = 12.4 * rtb_front_wheel_angle_single__d - 0.512;
  u0 = 12.4 * rtb_Switch - 0.512;
  rtb_RL_tmp = (1.14E-6 * rtb_Switch_gx - rtb_front_wheel_angle_single__d) +
    0.00239;
  Faeroz_tmp = (1.14E-6 * rtb_RR - rtb_Switch) + 0.00239;
  if (rtb_RL_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (rtb_RL_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (rtb_RL_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  if (Faeroz_tmp < 0.0) {
    u0_tmp_0 = -1.0;
  } else if (Faeroz_tmp > 0.0) {
    u0_tmp_0 = 1.0;
  } else if (Faeroz_tmp == 0.0) {
    u0_tmp_0 = 0.0;
  } else {
    u0_tmp_0 = (rtNaN);
  }

  rtb_RL_tmp_0 = 0.000282 * rtb_Switch_gx - 2.02;
  rtb_RL_tmp = sin(atan(0.000559 * rtb_Switch_gx) * 2.0) * 34500.0 * rtb_RL_tmp /
    (1.34 * rtb_Switch_gx * 0.8 * rtb_RL_tmp_0 - 0.01);
  rtb_RL_tmp_tmp = 0.0013 * rtb_Switch_gx - 2.33;
  rtb_RL_tmp_tmp_0 = 0.000282 * rtb_RR - 2.02;
  rtb_Switch_tmp = sin(atan(0.000559 * rtb_RR) * 2.0) * 34500.0 * Faeroz_tmp /
    (1.34 * rtb_RR * 0.8 * rtb_RL_tmp_tmp_0 - 0.01);
  rtb_Switch_tmp_0 = 0.0013 * rtb_RR - 2.33;
  Faeroz_tmp = rtb_SumofElements1 - rtb_Gain1;
  rtb_Switch_tmp_tmp = sqrt(rtb_Sign * rtb_Sign + 1.0);
  rtb_Switch_tmp_1 = (3.86E-7 * rtb_Switch_gx + 0.000205) * 13.9 /
    rtb_Switch_tmp_tmp;
  rtb_Switch_tmp_tmp_0 = sqrt(u0 * u0 + 1.0);
  rtb_Switch_tmp_2 = (3.86E-7 * rtb_RR + 0.000205) * 13.9 / rtb_Switch_tmp_tmp_0;
  rtb_Switch = Faeroz_tmp / 0.08 * 180.0 - (((rtb_RL + rtb_Saturation1) *
    rtb_NProdOut * 0.73439999999999994 - (((sin(atan(rtb_RL_tmp - (0.26 * u0_tmp
    + 1.0) * (3.99E-5 * rtb_Switch_gx - 0.521) * (atan(rtb_RL_tmp) - rtb_RL_tmp))
    * 1.34) * (rtb_Switch_gx * 0.8) * rtb_RL_tmp_0 + (7.1E-5 * rtb_Switch_gx -
    0.149) * (rtb_Switch_gx * 0.8)) * cos(atan((atan(((3.86E-7 * rtb_Switch_gx -
    rtb_Integrator_d[2]) + 0.000205) * 13.9 / rtb_Switch_tmp_tmp) - ((3.86E-7 *
    rtb_Switch_gx - rtb_Integrator_d[2]) + 0.000205) * 13.9 / sqrt(rtb_Sign *
    rtb_Sign + 1.0)) * rtb_RL_tmp_tmp + ((3.86E-7 * rtb_Switch_gx -
    rtb_Integrator_d[2]) + 0.000205) * 13.9 / sqrt(rtb_Sign * rtb_Sign + 1.0)) *
    0.958) / cos(atan((atan(rtb_Switch_tmp_1) - rtb_Switch_tmp_1) *
                      rtb_RL_tmp_tmp + rtb_Switch_tmp_1) * 0.958) - sin(atan
    (16.1 * rtb_Integrator_d[2]) * 1.94) * (rtb_Switch_gx * 0.8) * rtb_RL_tmp_0 *
    (1.03E-5 * rtb_Switch_gx - 0.000288) / sqrt(rtb_front_wheel_angle_single__d *
    rtb_front_wheel_angle_single__d * 225.0 + 1.0)) + ((sin(atan(rtb_Switch_tmp
    - (0.26 * u0_tmp_0 + 1.0) * (3.99E-5 * rtb_RR - 0.521) * (atan
    (rtb_Switch_tmp) - rtb_Switch_tmp)) * 1.34) * (rtb_RR * 0.8) *
    rtb_RL_tmp_tmp_0 + (7.1E-5 * rtb_RR - 0.149) * (rtb_RR * 0.8)) * cos(atan
    ((atan(((3.86E-7 * rtb_RR - rtb_Integrator_d[3]) + 0.000205) * 13.9 /
           rtb_Switch_tmp_tmp_0) - ((3.86E-7 * rtb_RR - rtb_Integrator_d[3]) +
    0.000205) * 13.9 / sqrt(u0 * u0 + 1.0)) * rtb_Switch_tmp_0 + ((3.86E-7 *
    rtb_RR - rtb_Integrator_d[3]) + 0.000205) * 13.9 / sqrt(u0 * u0 + 1.0)) *
    0.958) / cos(atan((atan(rtb_Switch_tmp_2) - rtb_Switch_tmp_2) *
                      rtb_Switch_tmp_0 + rtb_Switch_tmp_2) * 0.958) - sin(atan
    (16.1 * rtb_Integrator_d[3]) * 1.94) * (rtb_RR * 0.8) * rtb_RL_tmp_tmp_0 *
    (1.03E-5 * rtb_RR - 0.000288) / sqrt(rtb_Switch * rtb_Switch * 225.0 + 1.0)))
    * 0.79560000000000008) + -(rtb_Saturation1 - rtb_RL) * rtb_Switch2_ae * 1.27
    / 2.0);
  if (rtIsNaN(rtb_Switch)) {
    rtb_Switch = 0.0;
  }

  /* Logic: '<S146>/NOT1' */
  rtb_Logic_o_idx_1 = !rtb_Logic_d_idx_1;

  /* DiscreteIntegrator: '<S209>/Integrator' */
  if (rtb_Logic_o_idx_1 || (rtDW.Integrator_PrevResetState_i != 0)) {
    rtDW.Integrator_DSTATE_n = 0.0;
  }

  /* DiscreteIntegrator: '<S204>/Filter' */
  if (rtb_Logic_o_idx_1 || (rtDW.Filter_PrevResetState != 0)) {
    rtDW.Filter_DSTATE = 0.0;
  }

  /* Product: '<S212>/NProd Out' incorporates:
   *  Constant: '<S146>/Constant11'
   *  Constant: '<S146>/Constant13'
   *  Constant: '<S146>/Constant14'
   *  DiscreteIntegrator: '<S204>/Filter'
   *  Product: '<S203>/DProd Out'
   *  Product: '<S226>/cProd Out'
   *  Sum: '<S170>/Sum3'
   *  Sum: '<S204>/SumD'
   */
  rtb_NProdOut = ((rtb_SumofElements1 * 0.0 - rtb_Gain1) * 0.0 -
                  rtDW.Filter_DSTATE) * 3.0;

  /* Sum: '<S219>/Sum' incorporates:
   *  Constant: '<S146>/Constant12'
   *  DiscreteIntegrator: '<S209>/Integrator'
   *  Product: '<S214>/PProd Out'
   */
  rtb_front_wheel_angle_single__d = (Faeroz_tmp * 0.0 + rtDW.Integrator_DSTATE_n)
    + rtb_NProdOut;

  /* Switch: '<S217>/Switch2' incorporates:
   *  Constant: '<S146>/Constant10'
   *  Constant: '<S146>/Constant9'
   *  RelationalOperator: '<S217>/LowerRelop1'
   *  RelationalOperator: '<S217>/UpperRelop'
   *  Switch: '<S217>/Switch'
   */
  if (rtb_front_wheel_angle_single__d > 50.0) {
    rtb_Switch2_ae = 50.0;
  } else if (rtb_front_wheel_angle_single__d < -50.0) {
    /* Switch: '<S217>/Switch' incorporates:
     *  Constant: '<S146>/Constant10'
     */
    rtb_Switch2_ae = -50.0;
  } else {
    rtb_Switch2_ae = rtb_front_wheel_angle_single__d;
  }

  /* End of Switch: '<S217>/Switch2' */

  /* Sum: '<S146>/Sum1' incorporates:
   *  Gain: '<S146>/Gain2'
   */
  u0 = 0.017407407407407406 * rtb_Switch + rtb_Switch2_ae;

  /* Saturate: '<S146>/Saturation' */
  if (u0 > 20.0) {
    u0 = 20.0;
  } else if (u0 < -20.0) {
    u0 = -20.0;
  }

  /* End of Saturate: '<S146>/Saturation' */

  /* Product: '<S146>/Product' */
  rtb_Switch = u0 * (real_T)rtb_Logic_d_idx_1;

  /* MATLAB Function: '<S146>/MATLAB Function3' */
  rtb_Switch_gx = ((rtb_Abs_i_idx_0 * rtDW.CFunction_f[0] + rtb_Abs_l *
                    rtDW.CFunction_p[1]) - 0.635 * rtDW.CFunction_f[2]) + 0.635 *
    rtDW.CFunction_p[3];

  /* Switch: '<S171>/Switch2' incorporates:
   *  RelationalOperator: '<S171>/LowerRelop1'
   */
  if (!(rtb_Switch > modValueRev)) {
    /* Switch: '<S171>/Switch' incorporates:
     *  RelationalOperator: '<S171>/UpperRelop'
     */
    if (rtb_Switch < rtb_Switch_gx) {
      modValueRev = rtb_Switch_gx;
    } else {
      modValueRev = rtb_Switch;
    }

    /* End of Switch: '<S171>/Switch' */
  }

  /* End of Switch: '<S171>/Switch2' */

  /* MATLAB Function: '<S146>/MATLAB Function1' incorporates:
   *  Constant: '<S146>/Constant15'
   *  Inport: '<Root>/throttle'
   *  RelationalOperator: '<S146>/Less Than'
   */
  guard1 = false;
  if (modValueRev < 0.0) {
    guard1 = true;
  } else if (modValueRev > 0.0) {
    /* SignalConversion generated from: '<S166>/ SFunction ' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant9'
     */
    tmp[0] = -35000;
    tmp[1] = 80000;
    if (tmp[rtU.throttle >= 0.05] < 10000) {
      rtb_Saturation1 = 0.0;
    } else {
      rtb_Saturation1 = 0.75;
    }

    rtb_Switch = modValueRev * rtb_Saturation1;
  } else {
    if (modValueRev == 0.0) {
    }

    guard1 = true;
  }

  if (guard1) {
    rtb_Switch = modValueRev;

    /* SignalConversion generated from: '<S166>/ SFunction ' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant9'
     */
    tmp[0] = -35000;
    tmp[1] = 80000;
    if (tmp[rtU.throttle >= 0.05] < 10000) {
      rtb_Saturation1 = 0.0;
    } else {
      rtb_Saturation1 = 0.75;
    }

    modValueRev *= rtb_Saturation1;
  }

  /* End of MATLAB Function: '<S146>/MATLAB Function1' */

  /* MinMax: '<S234>/Max' */
  z = fmax(z, rtb_Gain3);

  /* InitialCondition: '<S236>/IC1' */
  rtDW.IC1_FirstOutputTime = false;

  /* Gain: '<S272>/Gain2' incorporates:
   *  Gain: '<S244>/Gain2'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_Gain3 = 13.5 * rtU.omega_wheels_FL;

  /* Saturate: '<S272>/Saturation' incorporates:
   *  Gain: '<S272>/Gain2'
   */
  if (rtb_Gain3 > 2083.9231268812296) {
    rtb_Integrator_d[0] = 2083.9231268812296;
  } else if (rtb_Gain3 < 10.471975511965978) {
    rtb_Integrator_d[0] = 10.471975511965978;
  } else {
    rtb_Integrator_d[0] = rtb_Gain3;
  }

  /* Gain: '<S272>/Gain2' incorporates:
   *  Gain: '<S244>/Gain2'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  rtb_SumofElements1 = 13.5 * rtU.omega_wheels_FR;

  /* Saturate: '<S272>/Saturation' incorporates:
   *  Gain: '<S272>/Gain2'
   */
  if (rtb_SumofElements1 > 2083.9231268812296) {
    rtb_Integrator_d[1] = 2083.9231268812296;
  } else if (rtb_SumofElements1 < 10.471975511965978) {
    rtb_Integrator_d[1] = 10.471975511965978;
  } else {
    rtb_Integrator_d[1] = rtb_SumofElements1;
  }

  /* Gain: '<S272>/Gain2' incorporates:
   *  Gain: '<S244>/Gain2'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  u0_tmp = 13.5 * rtU.omega_wheels_RL;

  /* Saturate: '<S272>/Saturation' incorporates:
   *  Gain: '<S272>/Gain2'
   */
  if (u0_tmp > 2083.9231268812296) {
    rtb_Integrator_d[2] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Integrator_d[2] = 10.471975511965978;
  } else {
    rtb_Integrator_d[2] = u0_tmp;
  }

  /* Gain: '<S272>/Gain2' incorporates:
   *  Gain: '<S244>/Gain2'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0_tmp_0 = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S272>/Saturation' incorporates:
   *  Gain: '<S272>/Gain2'
   */
  if (u0_tmp_0 > 2083.9231268812296) {
    rtb_Integrator_d[3] = 2083.9231268812296;
  } else if (u0_tmp_0 < 10.471975511965978) {
    rtb_Integrator_d[3] = 10.471975511965978;
  } else {
    rtb_Integrator_d[3] = u0_tmp_0;
  }

  /* Abs: '<S274>/Abs' */
  rtb_SignPreIntegrator_e[0] = fabs(rtb_Switch2_i[0]);
  rtb_SignPreIntegrator_e[1] = fabs(rtb_Switch2_i[1]);
  rtb_SignPreIntegrator_e[2] = fabs(rtb_Switch2_i[2]);
  rtb_SignPreIntegrator_e[3] = fabs(rtb_Switch2_i[3]);

  /* Lookup_n-D: '<S274>/2-D Lookup Table' */
  rtb_Integrator_d[0] = look2_binlx(rtb_Integrator_d[0],
    rtb_SignPreIntegrator_e[0], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Integrator_d[1] = look2_binlx(rtb_Integrator_d[1],
    rtb_SignPreIntegrator_e[1], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Integrator_d[2] = look2_binlx(rtb_Integrator_d[2],
    rtb_SignPreIntegrator_e[2], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Integrator_d[3] = look2_binlx(rtb_Integrator_d[3],
    rtb_SignPreIntegrator_e[3], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled67, 200U);

  /* Saturate: '<S274>/Saturation' */
  u0 = rtb_Integrator_d[0];
  if (u0 > 1.0) {
    rtb_Integrator_d[0] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_d[0] = 0.3;
  } else {
    rtb_Integrator_d[0] = u0;
  }

  u0 = rtb_Integrator_d[1];
  if (u0 > 1.0) {
    rtb_Integrator_d[1] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_d[1] = 0.3;
  } else {
    rtb_Integrator_d[1] = u0;
  }

  u0 = rtb_Integrator_d[2];
  if (u0 > 1.0) {
    rtb_Integrator_d[2] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_d[2] = 0.3;
  } else {
    rtb_Integrator_d[2] = u0;
  }

  u0 = rtb_Integrator_d[3];
  if (u0 > 1.0) {
    rtb_Integrator_d[3] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_d[3] = 0.3;
  } else {
    rtb_Integrator_d[3] = u0;
  }

  /* End of Saturate: '<S274>/Saturation' */

  /* Switch: '<S272>/Switch3' incorporates:
   *  Gain: '<S272>/     '
   *  Gain: '<S272>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Integrator_d[0];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Integrator_d[0];
  }

  if (rtU.omega_wheels_FR > 0.0) {
    rtb_Switch_gx = 0.96 * rtb_Integrator_d[1];
  } else {
    rtb_Switch_gx = 1.0416666666666667 * rtb_Integrator_d[1];
  }

  if (rtU.omega_wheels_RL > 0.0) {
    rtb_RR = 0.96 * rtb_Integrator_d[2];
  } else {
    rtb_RR = 1.0416666666666667 * rtb_Integrator_d[2];
  }

  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Gain1 = 0.96 * rtb_Integrator_d[3];
  } else {
    rtb_Gain1 = 1.0416666666666667 * rtb_Integrator_d[3];
  }

  /* End of Switch: '<S272>/Switch3' */

  /* MATLAB Function: '<S151>/MATLAB Function' incorporates:
   *  Gain: '<S151>/Gain'
   *  Gain: '<S272>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S272>/Product'
   */
  rtb_Tnew[0] = 13.5 * rtU.omega_wheels_FL * rtb_Saturation1 * 0.0;
  rtb_Tnew[1] = 13.5 * rtU.omega_wheels_FR * rtb_Switch_gx * 0.0;
  rtb_Tnew[2] = 13.5 * rtU.omega_wheels_RL * rtb_RR * 0.0;
  rtb_Tnew[3] = 13.5 * rtU.omega_wheels_RR * rtb_Gain1 * 0.0;
  memset(&rtb_CCaller_o6[0], 0, sizeof(real_T) << 4U);
  rtb_CCaller_o6[0] = rtb_Tnew[0];
  rtb_CCaller_o6[5] = rtb_Tnew[1];
  rtb_CCaller_o6[10] = rtb_Tnew[2];
  rtb_CCaller_o6[15] = rtb_Tnew[3];
  rtb_Tnew[0] = 0.03;
  rtb_Tnew[1] = 0.03;
  rtb_Tnew[2] = 0.03;
  rtb_Tnew[3] = 0.03;
  memset(&varargin_2[0], 0, sizeof(real_T) << 4U);
  varargin_2[0] = rtb_Tnew[0];
  varargin_2[5] = rtb_Tnew[1];
  varargin_2[10] = rtb_Tnew[2];
  varargin_2[15] = rtb_Tnew[3];
  memset(&rtb_y[0], 0, sizeof(real_T) << 6U);
  for (b_exit = 0; b_exit < 4; b_exit++) {
    idx = b_exit << 2;
    rtb_y_tmp = b_exit << 3;
    rtb_y[rtb_y_tmp] = rtb_CCaller_o6[idx];
    rtb_y[rtb_y_tmp + 1] = rtb_CCaller_o6[idx + 1];
    rtb_y[rtb_y_tmp + 2] = rtb_CCaller_o6[idx + 2];
    rtb_y[rtb_y_tmp + 3] = rtb_CCaller_o6[idx + 3];
  }

  for (b_exit = 0; b_exit < 4; b_exit++) {
    idx = b_exit << 2;
    rtb_y_tmp = (b_exit + 4) << 3;
    rtb_y[rtb_y_tmp + 4] = varargin_2[idx];
    rtb_y[rtb_y_tmp + 5] = varargin_2[idx + 1];
    rtb_y[rtb_y_tmp + 6] = varargin_2[idx + 2];
    rtb_y[rtb_y_tmp + 7] = varargin_2[idx + 3];
  }

  for (b_exit = 0; b_exit < 64; b_exit++) {
    rtb_y[b_exit] *= 50.0;
  }

  /* End of MATLAB Function: '<S151>/MATLAB Function' */

  /* Saturate: '<S244>/Saturation' */
  if (rtb_Gain3 > 2083.9231268812296) {
    rtb_Integrator_d[0] = 2083.9231268812296;
  } else if (rtb_Gain3 < 10.471975511965978) {
    rtb_Integrator_d[0] = 10.471975511965978;
  } else {
    rtb_Integrator_d[0] = rtb_Gain3;
  }

  if (rtb_SumofElements1 > 2083.9231268812296) {
    rtb_Integrator_d[1] = 2083.9231268812296;
  } else if (rtb_SumofElements1 < 10.471975511965978) {
    rtb_Integrator_d[1] = 10.471975511965978;
  } else {
    rtb_Integrator_d[1] = rtb_SumofElements1;
  }

  if (u0_tmp > 2083.9231268812296) {
    rtb_Integrator_d[2] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Integrator_d[2] = 10.471975511965978;
  } else {
    rtb_Integrator_d[2] = u0_tmp;
  }

  if (u0_tmp_0 > 2083.9231268812296) {
    rtb_Integrator_d[3] = 2083.9231268812296;
  } else if (u0_tmp_0 < 10.471975511965978) {
    rtb_Integrator_d[3] = 10.471975511965978;
  } else {
    rtb_Integrator_d[3] = u0_tmp_0;
  }

  /* End of Saturate: '<S244>/Saturation' */

  /* Abs: '<S246>/Abs' */
  rtb_SignPreIntegrator_e[0] = fabs(rtb_Switch2_i[0]);
  rtb_SignPreIntegrator_e[1] = fabs(rtb_Switch2_i[1]);
  rtb_SignPreIntegrator_e[2] = fabs(rtb_Switch2_i[2]);
  rtb_SignPreIntegrator_e[3] = fabs(rtb_Switch2_i[3]);

  /* Lookup_n-D: '<S246>/2-D Lookup Table' */
  rtb_Integrator_d[0] = look2_binlx(rtb_Integrator_d[0],
    rtb_SignPreIntegrator_e[0], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Integrator_d[1] = look2_binlx(rtb_Integrator_d[1],
    rtb_SignPreIntegrator_e[1], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Integrator_d[2] = look2_binlx(rtb_Integrator_d[2],
    rtb_SignPreIntegrator_e[2], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Integrator_d[3] = look2_binlx(rtb_Integrator_d[3],
    rtb_SignPreIntegrator_e[3], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled67, 200U);

  /* Saturate: '<S246>/Saturation' */
  u0 = rtb_Integrator_d[0];
  if (u0 > 1.0) {
    rtb_Integrator_d[0] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_d[0] = 0.3;
  } else {
    rtb_Integrator_d[0] = u0;
  }

  u0 = rtb_Integrator_d[1];
  if (u0 > 1.0) {
    rtb_Integrator_d[1] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_d[1] = 0.3;
  } else {
    rtb_Integrator_d[1] = u0;
  }

  u0 = rtb_Integrator_d[2];
  if (u0 > 1.0) {
    rtb_Integrator_d[2] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_d[2] = 0.3;
  } else {
    rtb_Integrator_d[2] = u0;
  }

  u0 = rtb_Integrator_d[3];
  if (u0 > 1.0) {
    rtb_Integrator_d[3] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_d[3] = 0.3;
  } else {
    rtb_Integrator_d[3] = u0;
  }

  /* End of Saturate: '<S246>/Saturation' */

  /* Switch: '<S244>/Switch3' incorporates:
   *  Gain: '<S244>/     '
   *  Gain: '<S244>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Integrator_d[0];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Integrator_d[0];
  }

  /* Abs: '<S244>/Abs' incorporates:
   *  Gain: '<S244>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Product: '<S244>/Divide'
   */
  rtb_SignPreIntegrator_e[0] = fabs(13.5 * rtU.omega_wheels_FL / rtb_Saturation1);

  /* Switch: '<S244>/Switch3' incorporates:
   *  Gain: '<S244>/     '
   *  Gain: '<S244>/      '
   *  Inport: '<Root>/omega_wheels_FR'
   */
  if (rtU.omega_wheels_FR > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Integrator_d[1];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Integrator_d[1];
  }

  /* Abs: '<S244>/Abs' incorporates:
   *  Gain: '<S244>/Gain1'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Product: '<S244>/Divide'
   */
  rtb_SignPreIntegrator_e[1] = fabs(13.5 * rtU.omega_wheels_FR / rtb_Saturation1);

  /* Switch: '<S244>/Switch3' incorporates:
   *  Gain: '<S244>/     '
   *  Gain: '<S244>/      '
   *  Inport: '<Root>/omega_wheels_RL'
   */
  if (rtU.omega_wheels_RL > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Integrator_d[2];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Integrator_d[2];
  }

  /* Abs: '<S244>/Abs' incorporates:
   *  Gain: '<S244>/Gain1'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Product: '<S244>/Divide'
   */
  rtb_SignPreIntegrator_e[2] = fabs(13.5 * rtU.omega_wheels_RL / rtb_Saturation1);

  /* Switch: '<S244>/Switch3' incorporates:
   *  Gain: '<S244>/     '
   *  Gain: '<S244>/      '
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Integrator_d[3];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Integrator_d[3];
  }

  /* Abs: '<S244>/Abs' incorporates:
   *  Gain: '<S244>/Gain1'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S244>/Divide'
   */
  rtb_SignPreIntegrator_e[3] = fabs(13.5 * rtU.omega_wheels_RR / rtb_Saturation1);

  /* Gain: '<S147>/Gain' incorporates:
   *  Sum: '<S147>/Sum'
   */
  rtb_Gain3 = (z + cumRevIndex) * 0.5;

  /* Chart: '<S239>/Distribution complete' incorporates:
   *  SignalConversion generated from: '<S243>/ SFunction '
   */
  if (rtb_Gain3 >= 0.0) {
    rtb_Switch_gx = rtb_Gain3;
    rtb_Integrator_d[0] = rtDW.CFunction_f[1];
    rtb_Integrator_d[1] = rtDW.CFunction_f[3];
    rtb_Integrator_d[2] = rtDW.CFunction_f[0];
    rtb_Integrator_d[3] = rtDW.CFunction_f[2];
    rtb_UnaryMinus_d0[0] = rtDW.CFunction_p[1];
    rtb_UnaryMinus_d0[1] = rtDW.CFunction_p[3];
    rtb_UnaryMinus_d0[2] = rtDW.CFunction_p[0];
    rtb_UnaryMinus_d0[3] = rtDW.CFunction_p[2];
    rtb_RR = modValueRev;
  } else {
    rtb_Switch_gx = -rtb_Gain3;
    rtb_Integrator_d[0] = -rtDW.CFunction_p[1];
    rtb_Integrator_d[1] = -rtDW.CFunction_p[3];
    rtb_Integrator_d[2] = -rtDW.CFunction_p[0];
    rtb_Integrator_d[3] = -rtDW.CFunction_p[2];
    rtb_UnaryMinus_d0[0] = -rtDW.CFunction_f[1];
    rtb_UnaryMinus_d0[1] = -rtDW.CFunction_f[3];
    rtb_UnaryMinus_d0[2] = -rtDW.CFunction_f[0];
    rtb_UnaryMinus_d0[3] = -rtDW.CFunction_f[2];
    rtb_RR = -modValueRev;
  }

  if (rtb_RR < 0.0) {
    rtb_Gain1 = rtb_Integrator_d[2];
    rtb_RL = rtb_Integrator_d[3];
    rtb_Saturation1 = rtb_Integrator_d[0];
    rtb_SumofElements1 = rtb_Integrator_d[1];
    rtb_Integrator_d[0] = rtb_Gain1;
    rtb_Integrator_d[1] = rtb_RL;
    rtb_Integrator_d[2] = rtb_Saturation1;
    rtb_Integrator_d[3] = rtb_SumofElements1;
    rtb_Gain1 = rtb_UnaryMinus_d0[2];
    rtb_RL = rtb_UnaryMinus_d0[3];
    rtb_Saturation1 = rtb_UnaryMinus_d0[0];
    rtb_SumofElements1 = rtb_UnaryMinus_d0[1];
    rtb_UnaryMinus_d0[0] = rtb_Gain1;
    rtb_UnaryMinus_d0[1] = rtb_RL;
    rtb_UnaryMinus_d0[2] = rtb_Saturation1;
    rtb_UnaryMinus_d0[3] = rtb_SumofElements1;
  }

  for (idx = 0; idx < 4; idx++) {
    rtb_Integrator_i[idx] = rtb_Integrator_d[idx];
  }

  for (idx = 0; idx < 4; idx++) {
    rtb_UnaryMinus_f[idx] = rtb_UnaryMinus_d0[idx];
  }

  BaseDistribution(rtb_Switch_gx, rtb_Integrator_i, rtb_UnaryMinus_f, fabs
                   (rtb_RR), rtb_Tnew);
  if (!(rtb_Gain3 >= 0.0)) {
    rtb_Integrator_i[0] = -rtb_Tnew[0];
    rtb_Integrator_i[1] = -rtb_Tnew[1];
    rtb_Integrator_i[2] = -rtb_Tnew[2];
    rtb_Integrator_i[3] = -rtb_Tnew[3];
    assignBrakeTorque(rtb_Integrator_i, rtb_Tnew);
  }

  if (rtb_RR < 0.0) {
    rtb_Switch_gx = rtb_Tnew[2];
    rtb_RR = rtb_Tnew[3];
    rtb_Gain1 = rtb_Tnew[0];
    rtb_RL = rtb_Tnew[1];
    rtb_Tnew[0] = rtb_Switch_gx;
    rtb_Tnew[1] = rtb_RR;
    rtb_Tnew[2] = rtb_Gain1;
    rtb_Tnew[3] = rtb_RL;
  }

  /* End of Chart: '<S239>/Distribution complete' */

  /* CCaller: '<S139>/C Caller' incorporates:
   *  CFunction: '<S152>/C Function'
   *  CFunction: '<S249>/C Function'
   *  CFunction: '<S250>/C Function'
   *  Constant: '<S144>/Constant'
   *  UnaryMinus: '<S144>/Unary Minus'
   */
  memcpy(&rtb_CCaller_o3[0], &rtDW.CFunction[0], 26U * sizeof(real_T));
  rtb_Integrator_d[0] = -10000.0;
  rtb_Integrator_d[1] = -10000.0;
  rtb_Integrator_d[2] = -10000.0;
  rtb_Integrator_d[3] = -10000.0;
  rtb_UnaryMinus_d0[0] = 10000.0;
  rtb_UnaryMinus_d0[1] = 10000.0;
  rtb_UnaryMinus_d0[2] = 10000.0;
  rtb_UnaryMinus_d0[3] = 10000.0;
  memset(&rtb_CCaller_o6[0], 0, sizeof(real_T) << 4U);
  rtb_Product1[0] = rtDW.CFunction_p[0];
  rtb_Product1[1] = rtDW.CFunction_p[1];
  rtb_Product1[2] = rtDW.CFunction_p[2];
  rtb_Product1[3] = rtDW.CFunction_p[3];
  rtb_CCaller_o8[0] = rtDW.CFunction_f[0];
  rtb_CCaller_o8[1] = rtDW.CFunction_f[1];
  rtb_CCaller_o8[2] = rtDW.CFunction_f[2];
  rtb_CCaller_o8[3] = rtDW.CFunction_f[3];

  /* Abs: '<S238>/Abs1' incorporates:
   *  Abs: '<S237>/Abs1'
   */
  rtb_Gain3 = fabs(rtb_Switch2_i[1]);

  /* Abs: '<S238>/Abs3' incorporates:
   *  Abs: '<S237>/Abs3'
   */
  rtb_Switch_gx = fabs(rtb_Switch2_i[0]);

  /* CCaller: '<S139>/C Caller' incorporates:
   *  Abs: '<S238>/Abs1'
   *  Abs: '<S238>/Abs3'
   *  Constant: '<S139>/Constant'
   *  Constant: '<S149>/Constant'
   *  MATLAB Function: '<S148>/MATLAB Function'
   *  Saturate: '<S235>/Saturation'
   *  SignalConversion generated from: '<S139>/C Caller'
   *  UnaryMinus: '<S238>/Unary Minus'
   *  UnaryMinus: '<S238>/Unary Minus1'
   * */
  rtb_CCaller_o9[0] = cumRevIndex;
  rtb_CCaller_o9[1] = rtb_Integrator_m;
  rtb_CCaller_o9[2] = -rtb_Gain3;
  rtb_CCaller_o9[3] = -rtb_Switch_gx;
  rtb_CCaller_o9[4] = rtb_Switch;
  rtb_CCaller_o10[0] = z;
  rtb_CCaller_o10[1] = 80.0;
  rtb_CCaller_o10[2] = rtb_Gain3;
  rtb_CCaller_o10[3] = rtb_Switch_gx;
  rtb_CCaller_o10[4] = modValueRev;
  rtb_CCaller_o12[0] = 1.0;
  rtb_CCaller_o12[5] = 1.0;
  rtb_CCaller_o12[10] = 1.0;
  rtb_CCaller_o12[15] = 1.0;
  rtb_CCaller_o12[1] = rtb_SignPreIntegrator_e[0] / 1000.0;
  rtb_CCaller_o12[6] = rtb_SignPreIntegrator_e[1] / 1000.0;
  rtb_CCaller_o12[11] = rtb_SignPreIntegrator_e[2] / 1000.0;
  rtb_CCaller_o12[16] = rtb_SignPreIntegrator_e[3] / 1000.0;
  rtb_CCaller_o12[2] = 0.0;
  rtb_CCaller_o12[7] = 1.0;
  rtb_CCaller_o12[12] = 0.0;
  rtb_CCaller_o12[17] = -1.0;
  rtb_CCaller_o12[3] = 1.0;
  rtb_CCaller_o12[8] = 0.0;
  rtb_CCaller_o12[13] = -1.0;
  rtb_CCaller_o12[18] = 0.0;
  rtb_CCaller_o12[4] = rtb_Abs_i_idx_0;
  rtb_CCaller_o12[9] = rtb_Abs_l;
  rtb_CCaller_o12[14] = -0.635;
  rtb_CCaller_o12[19] = 0.635;
  rtb_CCaller_o13[0] = 1000.0;
  rtb_CCaller_o13[1] = 50.0;
  rtb_CCaller_o13[2] = 50.0;
  rtb_CCaller_o14[0] = 1000.0;
  rtb_CCaller_o14[1] = 50.0;
  rtb_CCaller_o14[2] = 50.0;
  rtb_SignPreIntegrator_e[0] = rtb_Tnew[2];
  rtb_SignPreIntegrator_e[1] = rtb_Tnew[0];
  rtb_SignPreIntegrator_e[2] = rtb_Tnew[3];
  rtb_SignPreIntegrator_e[3] = rtb_Tnew[1];
  rtb_Tnew[0] = 0.0;
  rtb_Tnew[1] = 0.0;
  rtb_Tnew[2] = 0.0;
  rtb_Tnew[3] = 0.0;

  /* CCaller: '<S139>/C Caller' */
  idx = Acados_Caller_wrapper(&rtb_Switch2_i[0], &rtb_CCaller_o3[0],
    &rtb_Integrator_d[0], &rtb_UnaryMinus_d0[0], &rtb_CCaller_o6[0],
    &rtb_Product1[0], &rtb_CCaller_o8[0], &rtb_CCaller_o9[0], &rtb_CCaller_o10[0],
    &rtb_y[0], &rtb_CCaller_o12[0], &rtb_CCaller_o13[0], &rtb_CCaller_o14[0],
    &rtb_SignPreIntegrator_e[0], &rtb_Tnew[0]);

  /* DiscreteFir: '<S156>/Discrete FIR Filter' */
  acc1 = (int64_T)idx << 30;
  for (b_exit = rtDW.DiscreteFIRFilter_circBuf; b_exit < 4; b_exit++) {
    acc1 += (int64_T)rtDW.DiscreteFIRFilter_states[b_exit] << 30;
  }

  for (b_exit = 0; b_exit < rtDW.DiscreteFIRFilter_circBuf; b_exit++) {
    acc1 += (int64_T)rtDW.DiscreteFIRFilter_states[b_exit] << 30;
  }

  /* End of DiscreteFir: '<S156>/Discrete FIR Filter' */

  /* Switch: '<S156>/Switch' */
  if ((rtb_vx > 3.0) && (!((real_T)acc1 * 9.3132257461547852E-10 >= 4.0))) {
  } else {
    /* Outputs for IfAction SubSystem: '<S145>/Vectorino' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    /* If: '<S145>/If' incorporates:
     *  Constant: '<S164>/Constant2'
     *  Inport: '<Root>/throttle'
     *  Product: '<S164>/Product'
     */
    rtb_Tnew[0] = rtU.throttle * 6.3;
    rtb_Tnew[1] = rtU.throttle * 6.3;
    rtb_Tnew[2] = rtU.throttle * 21.0;
    rtb_Tnew[3] = rtU.throttle * 21.0;

    /* End of Outputs for SubSystem: '<S145>/Vectorino' */
  }

  /* End of Switch: '<S156>/Switch' */

  /* Product: '<S145>/Divide' incorporates:
   *  Sum: '<S132>/SumI1'
   */
  rtb_Switch2_i[0] = rtb_Tnew[0];
  rtb_Switch2_i[1] = rtb_Tnew[1];
  rtb_Switch2_i[2] = rtb_Tnew[2];
  rtb_Switch2_i[3] = rtb_Tnew[3];

  /* UnitDelay: '<S17>/Unit Delay' */
  rtb_Tnew[0] = rtDW.UnitDelay_DSTATE_e[0];
  rtb_Tnew[1] = rtDW.UnitDelay_DSTATE_e[1];
  rtb_Tnew[2] = rtDW.UnitDelay_DSTATE_e[2];
  rtb_Tnew[3] = rtDW.UnitDelay_DSTATE_e[3];

  /* SignalConversion generated from: '<S26>/ SFunction ' incorporates:
   *  Chart: '<S17>/Activation logic'
   *  Chart: '<S23>/Activation logic'
   *  SignalConversion generated from: '<S83>/ SFunction '
   */
  rtb_UnaryMinus_d0[0] = rtb_Switch2_i[3];
  rtb_UnaryMinus_d0[1] = rtb_Switch2_i[2];
  rtb_UnaryMinus_d0[2] = rtb_Switch2_i[1];
  rtb_UnaryMinus_d0[3] = rtb_Switch2_i[0];

  /* Chart: '<S17>/Activation logic' incorporates:
   *  Constant: '<S11>/Constant13'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/Constant5'
   *  SignalConversion generated from: '<S26>/ SFunction '
   */
  if (rtDW.is_active_c36_TVModel == 0U) {
    rtDW.is_active_c36_TVModel = 1U;
    rtDW.is_c36_TVModel = IN_TS_OFF;
    rtDW.T_min[0] = 0.0;
    rtDW.T_min[1] = 0.0;
    rtDW.T_min[2] = 0.0;
    rtDW.T_min[3] = 0.0;
  } else if (rtDW.is_c36_TVModel == IN_TS_OFF) {
    rtDW.is_c36_TVModel = IN_TS_ON;
    rtDW.is_TS_ON_j = IN_ABS_OFF;
    rtDW.T_min[0] = 21.0;
    rtDW.T_min[1] = 21.0;
    rtDW.T_min[2] = 21.0;
    rtDW.T_min[3] = 21.0;

    /* case IN_TS_ON: */
  } else if (rtDW.is_TS_ON_j == IN_ABS_OFF) {
    if (AND) {
      rtDW.is_TS_ON_j = IN_ABS_ON;
      rtDW.is_FL_g = IN_ABS_INACTIVE;
      rtDW.T_min[0] = 21.0;
      rtDW.is_FR_o = IN_ABS_INACTIVE;
      rtDW.T_min[1] = 21.0;
      rtDW.is_RL_j = IN_ABS_INACTIVE;
      rtDW.T_min[2] = 21.0;
      rtDW.is_RR_m = IN_ABS_INACTIVE;
      rtDW.T_min[3] = 21.0;
    } else {
      rtDW.T_min[0] = 21.0;
      rtDW.T_min[1] = 21.0;
      rtDW.T_min[2] = 21.0;
      rtDW.T_min[3] = 21.0;
    }

    /* case IN_ABS_ON: */
  } else if (!AND) {
    exit_internal_ABS_ON();
    rtDW.is_TS_ON_j = IN_ABS_OFF;
    rtDW.T_min[0] = 21.0;
    rtDW.T_min[1] = 21.0;
    rtDW.T_min[2] = 21.0;
    rtDW.T_min[3] = 21.0;
  } else {
    if (rtDW.is_FL_g == IN_ABS_ACTIVE) {
      if (rtb_UnaryMinus_d0[0] > 0.9 * rtb_Tnew[0]) {
        rtDW.is_FL_g = IN_ABS_INACTIVE;
        rtDW.T_min[0] = 21.0;
      } else {
        rtDW.T_min[0] = Switch2_idx_0;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_l_idx_0 <= -0.14600000000000005) && (rtb_UnaryMinus_d0[0] <
                0.0)) {
      rtDW.is_FL_g = IN_ABS_ACTIVE;
      rtDW.T_min[0] = rtb_UnaryMinus_d0[0];
    } else {
      rtDW.T_min[0] = 21.0;
    }

    if (rtDW.is_FR_o == IN_ABS_ACTIVE) {
      if (rtb_UnaryMinus_d0[1] > 0.9 * rtb_Tnew[1]) {
        rtDW.is_FR_o = IN_ABS_INACTIVE;
        rtDW.T_min[1] = 21.0;
      } else {
        rtDW.T_min[1] = Switch2_idx_1;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_l_idx_1 <= -0.14600000000000005) && (rtb_UnaryMinus_d0[1] <
                0.0)) {
      rtDW.is_FR_o = IN_ABS_ACTIVE;
      rtDW.T_min[1] = rtb_UnaryMinus_d0[1];
    } else {
      rtDW.T_min[1] = 21.0;
    }

    if (rtDW.is_RL_j == IN_ABS_ACTIVE) {
      if (rtb_UnaryMinus_d0[2] > 0.9 * rtb_Tnew[2]) {
        rtDW.is_RL_j = IN_ABS_INACTIVE;
        rtDW.T_min[2] = 21.0;
      } else {
        rtDW.T_min[2] = Switch2_idx_2;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_l_idx_2 <= -0.14600000000000005) && (rtb_UnaryMinus_d0[2] <
                0.0)) {
      rtDW.is_RL_j = IN_ABS_ACTIVE;
      rtDW.T_min[2] = rtb_UnaryMinus_d0[2];
    } else {
      rtDW.T_min[2] = 21.0;
    }

    if (rtDW.is_RR_m == IN_ABS_ACTIVE) {
      if (rtb_UnaryMinus_d0[3] > 0.9 * rtb_Tnew[3]) {
        rtDW.is_RR_m = IN_ABS_INACTIVE;
        rtDW.T_min[3] = 21.0;
      } else {
        rtDW.T_min[3] = Switch2_idx_3;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_i <= -0.14600000000000005) && (rtb_UnaryMinus_d0[3] < 0.0))
    {
      rtDW.is_RR_m = IN_ABS_ACTIVE;
      rtDW.T_min[3] = rtb_UnaryMinus_d0[3];
    } else {
      rtDW.T_min[3] = 21.0;
    }
  }

  /* Gain: '<S52>/ZeroGain' */
  rtb_Integrator_d[0] = 0.0 * rtb_Switch_b_idx_0;
  rtb_Integrator_d[1] = 0.0 * rtb_Switch_b_idx_1;
  rtb_Integrator_d[2] = 0.0 * rtb_Switch_b_idx_2;
  rtb_Integrator_d[3] = 0.0 * rtb_k_l_idx_3;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Sum: '<S55>/Diff'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_Switch_b_idx_0 >= -4.9) {
    rtb_Switch = -4.9;
  } else if (rtb_Switch_b_idx_0 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Switch = rtb_Switch_b_idx_0;
  } else {
    rtb_Switch = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_Switch = rtb_Switch_b_idx_0 - rtb_Switch;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Sum: '<S55>/Diff'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_Switch_b_idx_1 >= -4.9) {
    rtb_Switch_b_idx_0 = -4.9;
  } else if (rtb_Switch_b_idx_1 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Switch_b_idx_0 = rtb_Switch_b_idx_1;
  } else {
    rtb_Switch_b_idx_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_Switch_b_idx_1 -= rtb_Switch_b_idx_0;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Sum: '<S55>/Diff'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_Switch_b_idx_2 >= -4.9) {
    rtb_Switch_b_idx_0 = -4.9;
  } else if (rtb_Switch_b_idx_2 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Switch_b_idx_0 = rtb_Switch_b_idx_2;
  } else {
    rtb_Switch_b_idx_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_Switch_b_idx_2 -= rtb_Switch_b_idx_0;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_k_l_idx_3 >= -4.9) {
    rtb_Switch_b_idx_0 = -4.9;
  } else if (rtb_k_l_idx_3 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Switch_b_idx_0 = rtb_k_l_idx_3;
  } else {
    rtb_Switch_b_idx_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_k_l_idx_3 -= rtb_Switch_b_idx_0;

  /* Sum: '<S75>/SumI1' incorporates:
   *  Constant: '<S17>/Constant2'
   *  Gain: '<S74>/Kt'
   *  Product: '<S59>/IProd Out'
   *  Sum: '<S17>/Minus'
   *  Sum: '<S74>/SumI3'
   */
  rtb_Tnew[0] = (rtDW.T_min[0] - Switch2_idx_0) * 100.0 + rtb_Minus_i[0] *
    2845.0;
  rtb_Tnew[1] = (rtDW.T_min[1] - Switch2_idx_1) * 100.0 + rtb_Minus_i[1] *
    2845.0;
  rtb_Tnew[2] = (rtDW.T_min[2] - Switch2_idx_2) * 100.0 + rtb_Minus_i[2] *
    2845.0;
  rtb_Tnew[3] = (-0.13600000000000004 - rtb_k_i) * 2845.0 + (rtDW.T_min[3] -
    Switch2_idx_3) * 100.0;

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  u0_tmp = rtb_Tnew[0];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Switch < 0.0) {
    rtb_Switch_b_idx_0 = -1.0;
  } else if (rtb_Switch > 0.0) {
    rtb_Switch_b_idx_0 = 1.0;
  } else if (rtb_Switch == 0.0) {
    rtb_Switch_b_idx_0 = 0.0;
  } else {
    rtb_Switch_b_idx_0 = (rtNaN);
  }

  /* Signum: '<S52>/SignPreIntegrator' */
  if (u0_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u0_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u0_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant1'
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((rtb_Integrator_d[0] != rtb_Switch) && ((int8_T)rtb_Switch_b_idx_0 ==
       (int8_T)u0_tmp)) {
    rtb_Integrator_d[0] = 0.0;
  } else {
    rtb_Integrator_d[0] = rtb_Tnew[0];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  u0_tmp = rtb_Tnew[1];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Switch_b_idx_1 < 0.0) {
    rtb_Switch = -1.0;
  } else if (rtb_Switch_b_idx_1 > 0.0) {
    rtb_Switch = 1.0;
  } else if (rtb_Switch_b_idx_1 == 0.0) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = (rtNaN);
  }

  /* Signum: '<S52>/SignPreIntegrator' */
  if (u0_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u0_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u0_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant1'
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((rtb_Integrator_d[1] != rtb_Switch_b_idx_1) && ((int8_T)rtb_Switch ==
       (int8_T)u0_tmp)) {
    rtb_Integrator_d[1] = 0.0;
  } else {
    rtb_Integrator_d[1] = rtb_Tnew[1];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  u0_tmp = rtb_Tnew[2];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Switch_b_idx_2 < 0.0) {
    rtb_Switch = -1.0;
  } else if (rtb_Switch_b_idx_2 > 0.0) {
    rtb_Switch = 1.0;
  } else if (rtb_Switch_b_idx_2 == 0.0) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = (rtNaN);
  }

  /* Signum: '<S52>/SignPreIntegrator' */
  if (u0_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u0_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u0_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant1'
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((rtb_Integrator_d[2] != rtb_Switch_b_idx_2) && ((int8_T)rtb_Switch ==
       (int8_T)u0_tmp)) {
    rtb_Integrator_d[2] = 0.0;
  } else {
    rtb_Integrator_d[2] = rtb_Tnew[2];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  u0_tmp = rtb_Tnew[3];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_k_l_idx_3 < 0.0) {
    rtb_Switch = -1.0;
  } else if (rtb_k_l_idx_3 > 0.0) {
    rtb_Switch = 1.0;
  } else if (rtb_k_l_idx_3 == 0.0) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = (rtNaN);
  }

  /* Signum: '<S52>/SignPreIntegrator' */
  if (u0_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u0_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u0_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant1'
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((rtb_Integrator_d[3] != rtb_k_l_idx_3) && ((int8_T)rtb_Switch == (int8_T)
       u0_tmp)) {
    rtb_Integrator_d[3] = 0.0;
  } else {
    rtb_Integrator_d[3] = rtb_Tnew[3];
  }

  /* Product: '<S80>/Divide' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Constant: '<S19>/Constant4'
   *  Inport: '<Root>/throttle'
   *  Sum: '<S80>/Minus'
   */
  cumRevIndex = ((rtU.throttle - 0.05) + 0.01) / 0.02;

  /* Relay: '<S80>/Relay' */
  rtDW.Relay_Mode = ((cumRevIndex >= 1.0) || ((!(cumRevIndex <= 0.0)) &&
    rtDW.Relay_Mode));

  /* Product: '<S81>/Divide' incorporates:
   *  Constant: '<S19>/Constant5'
   *  Constant: '<S19>/Constant6'
   *  Inport: '<Root>/brake'
   *  Sum: '<S81>/Minus'
   */
  rtb_Saturation1 = ((rtU.brake - 0.1) + 0.01) / 0.02;

  /* Relay: '<S81>/Relay' */
  rtDW.Relay_Mode_o = ((rtb_Saturation1 >= 1.0) || ((!(rtb_Saturation1 <= 0.0)) &&
    rtDW.Relay_Mode_o));

  /* Logic: '<S19>/AND' incorporates:
   *  Constant: '<S19>/Constant2'
   *  Logic: '<S19>/NOT'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  Relay: '<S80>/Relay'
   *  Relay: '<S81>/Relay'
   */
  rtb_Logic_d_idx_1 = ((rtb_vx > 3.0) && rtDW.Relay_Mode && (!rtDW.Relay_Mode_o));

  /* Sum: '<S23>/Minus' */
  rtb_Tnew[0] = 0.13600000000000004 - rtb_k_l_idx_0;
  rtb_Tnew[1] = 0.13600000000000004 - rtb_k_l_idx_1;
  rtb_Tnew[2] = 0.13600000000000004 - rtb_k_l_idx_2;
  rtb_Tnew[3] = 0.13600000000000004 - rtb_k_i;

  /* DiscreteIntegrator: '<S119>/Integrator' */
  if (rtb_Logic_d_idx_1 && (rtDW.Integrator_PrevResetState_g <= 0)) {
    rtDW.Integrator_DSTATE_a[0] = 0.0;
    rtDW.Integrator_DSTATE_a[1] = 0.0;
    rtDW.Integrator_DSTATE_a[2] = 0.0;
    rtDW.Integrator_DSTATE_a[3] = 0.0;
  }

  /* Sum: '<S129>/Sum' incorporates:
   *  Constant: '<S23>/Constant1'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Product: '<S124>/PProd Out'
   */
  rtb_SignPreIntegrator_e[0] = rtb_Tnew[0] * 57.0 + rtDW.Integrator_DSTATE_a[0];
  rtb_SignPreIntegrator_e[1] = rtb_Tnew[1] * 57.0 + rtDW.Integrator_DSTATE_a[1];
  rtb_SignPreIntegrator_e[2] = rtb_Tnew[2] * 57.0 + rtDW.Integrator_DSTATE_a[2];
  rtb_SignPreIntegrator_e[3] = rtb_Tnew[3] * 57.0 + rtDW.Integrator_DSTATE_a[3];

  /* Switch: '<S127>/Switch2' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S127>/LowerRelop1'
   *  RelationalOperator: '<S127>/UpperRelop'
   *  Switch: '<S127>/Switch'
   */
  if (rtb_SignPreIntegrator_e[0] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    rtb_Minus_i[0] = 21.0;
  } else if (rtb_SignPreIntegrator_e[0] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    rtb_Minus_i[0] = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Switch: '<S127>/Switch'
     */
    rtb_Minus_i[0] = rtb_SignPreIntegrator_e[0];
  }

  if (rtb_SignPreIntegrator_e[1] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    rtb_Minus_i[1] = 21.0;
  } else if (rtb_SignPreIntegrator_e[1] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    rtb_Minus_i[1] = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Switch: '<S127>/Switch'
     */
    rtb_Minus_i[1] = rtb_SignPreIntegrator_e[1];
  }

  if (rtb_SignPreIntegrator_e[2] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    rtb_Minus_i[2] = 21.0;
  } else if (rtb_SignPreIntegrator_e[2] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    rtb_Minus_i[2] = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Switch: '<S127>/Switch'
     */
    rtb_Minus_i[2] = rtb_SignPreIntegrator_e[2];
  }

  if (rtb_SignPreIntegrator_e[3] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    rtb_Minus_i[3] = 21.0;
  } else if (rtb_SignPreIntegrator_e[3] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    rtb_Minus_i[3] = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Switch: '<S127>/Switch'
     */
    rtb_Minus_i[3] = rtb_SignPreIntegrator_e[3];
  }

  /* End of Switch: '<S127>/Switch2' */

  /* Chart: '<S23>/Activation logic' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S23>/Constant4'
   *  Constant: '<S23>/Constant5'
   *  SignalConversion generated from: '<S83>/ SFunction '
   *  UnitDelay: '<S23>/Unit Delay'
   */
  if (rtDW.is_active_c38_TVModel == 0U) {
    rtDW.is_active_c38_TVModel = 1U;
    rtDW.is_c38_TVModel = IN_TS_OFF;
    rtDW.T_max[0] = 0.0;
    rtDW.T_max[1] = 0.0;
    rtDW.T_max[2] = 0.0;
    rtDW.T_max[3] = 0.0;
  } else if (rtDW.is_c38_TVModel == IN_TS_OFF) {
    rtDW.is_c38_TVModel = IN_TS_ON;
    rtDW.is_TS_ON = IN_TC_OFF;
    rtDW.T_max[0] = 21.0;
    rtDW.T_max[1] = 21.0;
    rtDW.T_max[2] = 21.0;
    rtDW.T_max[3] = 21.0;

    /* case IN_TS_ON: */
  } else if (rtDW.is_TS_ON == IN_TC_OFF) {
    if (rtb_Logic_d_idx_1) {
      rtDW.is_TS_ON = IN_TC_ON;
      rtDW.is_FL = IN_TC_INACTIVE;
      rtDW.T_max[0] = 21.0;
      rtDW.is_FR = IN_TC_INACTIVE;
      rtDW.T_max[1] = 21.0;
      rtDW.is_RL = IN_TC_INACTIVE;
      rtDW.T_max[2] = 21.0;
      rtDW.is_RR = IN_TC_INACTIVE;
      rtDW.T_max[3] = 21.0;
    } else {
      rtDW.T_max[0] = 21.0;
      rtDW.T_max[1] = 21.0;
      rtDW.T_max[2] = 21.0;
      rtDW.T_max[3] = 21.0;
    }

    /* case IN_TC_ON: */
  } else if (!rtb_Logic_d_idx_1) {
    exit_internal_TC_ON();
    rtDW.is_TS_ON = IN_TC_OFF;
    rtDW.T_max[0] = 21.0;
    rtDW.T_max[1] = 21.0;
    rtDW.T_max[2] = 21.0;
    rtDW.T_max[3] = 21.0;
  } else {
    if (rtDW.is_FL == IN_TC_ACTIVE) {
      if (rtb_UnaryMinus_d0[0] < 0.9 * rtDW.UnitDelay_DSTATE_d[0]) {
        rtDW.is_FL = IN_TC_INACTIVE;
        rtDW.T_max[0] = 21.0;
      } else {
        rtDW.T_max[0] = rtb_Minus_i[0];
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_l_idx_0 >= 0.14600000000000005) {
      rtDW.is_FL = IN_TC_ACTIVE;
      rtDW.T_max[0] = fabs(rtb_UnaryMinus_d0[0]);
    } else {
      rtDW.T_max[0] = 21.0;
    }

    if (rtDW.is_FR == IN_TC_ACTIVE) {
      if (rtb_UnaryMinus_d0[1] < 0.9 * rtDW.UnitDelay_DSTATE_d[1]) {
        rtDW.is_FR = IN_TC_INACTIVE;
        rtDW.T_max[1] = 21.0;
      } else {
        rtDW.T_max[1] = rtb_Minus_i[1];
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_l_idx_1 >= 0.14600000000000005) {
      rtDW.is_FR = IN_TC_ACTIVE;
      rtDW.T_max[1] = fabs(rtb_UnaryMinus_d0[1]);
    } else {
      rtDW.T_max[1] = 21.0;
    }

    if (rtDW.is_RL == IN_TC_ACTIVE) {
      if (rtb_UnaryMinus_d0[2] < 0.9 * rtDW.UnitDelay_DSTATE_d[2]) {
        rtDW.is_RL = IN_TC_INACTIVE;
        rtDW.T_max[2] = 21.0;
      } else {
        rtDW.T_max[2] = rtb_Minus_i[2];
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_l_idx_2 >= 0.14600000000000005) {
      rtDW.is_RL = IN_TC_ACTIVE;
      rtDW.T_max[2] = fabs(rtb_UnaryMinus_d0[2]);
    } else {
      rtDW.T_max[2] = 21.0;
    }

    if (rtDW.is_RR == IN_TC_ACTIVE) {
      if (rtb_UnaryMinus_d0[3] < 0.9 * rtDW.UnitDelay_DSTATE_d[3]) {
        rtDW.is_RR = IN_TC_INACTIVE;
        rtDW.T_max[3] = 21.0;
      } else {
        rtDW.T_max[3] = rtb_Minus_i[3];
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_i >= 0.14600000000000005) {
      rtDW.is_RR = IN_TC_ACTIVE;
      rtDW.T_max[3] = fabs(rtb_UnaryMinus_d0[3]);
    } else {
      rtDW.T_max[3] = 21.0;
    }
  }

  /* Gain: '<S109>/ZeroGain' */
  rtb_k_l_idx_0 = 0.0 * rtb_SignPreIntegrator_e[0];
  rtb_k_l_idx_1 = 0.0 * rtb_SignPreIntegrator_e[1];
  rtb_k_l_idx_2 = 0.0 * rtb_SignPreIntegrator_e[2];
  rtb_k_l_idx_3 = 0.0 * rtb_SignPreIntegrator_e[3];

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Sum: '<S112>/Diff'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_SignPreIntegrator_e[0] >= 21.0) {
    rtb_vx = 21.0;
  } else if (rtb_SignPreIntegrator_e[0] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_vx = rtb_SignPreIntegrator_e[0];
  } else {
    rtb_vx = 4.9;
  }

  /* Sum: '<S112>/Diff' */
  rtb_SignPreIntegrator_e[0] -= rtb_vx;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Sum: '<S112>/Diff'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_SignPreIntegrator_e[1] >= 21.0) {
    rtb_vx = 21.0;
  } else if (rtb_SignPreIntegrator_e[1] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_vx = rtb_SignPreIntegrator_e[1];
  } else {
    rtb_vx = 4.9;
  }

  /* Sum: '<S112>/Diff' */
  rtb_SignPreIntegrator_e[1] -= rtb_vx;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Sum: '<S112>/Diff'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_SignPreIntegrator_e[2] >= 21.0) {
    rtb_vx = 21.0;
  } else if (rtb_SignPreIntegrator_e[2] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_vx = rtb_SignPreIntegrator_e[2];
  } else {
    rtb_vx = 4.9;
  }

  /* Sum: '<S112>/Diff' */
  rtb_SignPreIntegrator_e[2] -= rtb_vx;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Sum: '<S112>/Diff'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_SignPreIntegrator_e[3] >= 21.0) {
    rtb_vx = 21.0;
  } else if (rtb_SignPreIntegrator_e[3] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_vx = rtb_SignPreIntegrator_e[3];
  } else {
    rtb_vx = 4.9;
  }

  /* Sum: '<S112>/Diff' */
  rtb_SignPreIntegrator_e[3] -= rtb_vx;

  /* Sum: '<S132>/SumI1' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S131>/Kt'
   *  Product: '<S116>/IProd Out'
   *  Sum: '<S131>/SumI3'
   */
  rtb_Tnew[0] = (rtDW.T_max[0] - rtb_Minus_i[0]) * 100.0 + rtb_Tnew[0] * 2845.0;
  rtb_Tnew[1] = (rtDW.T_max[1] - rtb_Minus_i[1]) * 100.0 + rtb_Tnew[1] * 2845.0;
  rtb_Tnew[2] = (rtDW.T_max[2] - rtb_Minus_i[2]) * 100.0 + rtb_Tnew[2] * 2845.0;
  rtb_Tnew[3] = (rtDW.T_max[3] - rtb_Minus_i[3]) * 100.0 + rtb_Tnew[3] * 2845.0;

  /* RelationalOperator: '<S145>/Less Than3' incorporates:
   *  DataStoreRead: '<S145>/Data Store General_Params1'
   *  Inport: '<Root>/brake'
   */
  rtb_LessThan3 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S145>/Overlap Chart' incorporates:
   *  Inport: '<Root>/throttle'
   */
  if (rtDW.is_active_c13_TVModel == 0U) {
    rtDW.is_active_c13_TVModel = 1U;
    rtDW.is_c13_TVModel = IN_Go;
  } else if (rtDW.is_c13_TVModel == IN_Go) {
    if (rtb_LessThan3) {
      rtDW.is_c13_TVModel = IN_Stop;
    }

    /* case IN_Stop: */
  } else if (((real_T)rtb_LessThan3 <= 0.05) && (rtU.throttle < 0.05)) {
    rtDW.is_c13_TVModel = IN_Go;
  }

  /* End of Chart: '<S145>/Overlap Chart' */

  /* Switch: '<S202>/Switch' incorporates:
   *  Constant: '<S146>/Constant10'
   *  Constant: '<S146>/Constant9'
   *  RelationalOperator: '<S202>/u_GTE_up'
   *  RelationalOperator: '<S202>/u_GT_lo'
   *  Switch: '<S202>/Switch1'
   */
  if (rtb_front_wheel_angle_single__d >= 50.0) {
    rtb_vx = 50.0;
  } else if (rtb_front_wheel_angle_single__d > -50.0) {
    /* Switch: '<S202>/Switch1' */
    rtb_vx = rtb_front_wheel_angle_single__d;
  } else {
    rtb_vx = -50.0;
  }

  /* End of Switch: '<S202>/Switch' */

  /* Sum: '<S202>/Diff' */
  cumRevIndex = rtb_front_wheel_angle_single__d - rtb_vx;

  /* RelationalOperator: '<S199>/NotEqual' incorporates:
   *  Gain: '<S199>/ZeroGain'
   */
  rtb_LessThan3 = (0.0 * rtb_front_wheel_angle_single__d != cumRevIndex);

  /* Signum: '<S199>/SignPreSat' */
  if (cumRevIndex < 0.0) {
    rtb_vx = -1.0;
  } else if (cumRevIndex > 0.0) {
    rtb_vx = 1.0;
  } else if (cumRevIndex == 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = (rtNaN);
  }

  /* End of Signum: '<S199>/SignPreSat' */

  /* Sum: '<S222>/SumI1' incorporates:
   *  Constant: '<S146>/Const10ant15'
   *  Gain: '<S221>/Kt'
   *  Product: '<S206>/IProd Out'
   *  Sum: '<S221>/SumI3'
   */
  cumRevIndex = (rtb_Switch2_ae - rtb_Switch2_ae) * 100.0 + Faeroz_tmp * 20.0;

  /* Signum: '<S199>/SignPreIntegrator' */
  if (cumRevIndex < 0.0) {
    rtb_front_wheel_angle_single__d = -1.0;
  } else if (cumRevIndex > 0.0) {
    rtb_front_wheel_angle_single__d = 1.0;
  } else if (cumRevIndex == 0.0) {
    rtb_front_wheel_angle_single__d = 0.0;
  } else {
    rtb_front_wheel_angle_single__d = (rtNaN);
  }

  /* End of Signum: '<S199>/SignPreIntegrator' */

  /* Switch: '<S199>/Switch' incorporates:
   *  Constant: '<S199>/Constant1'
   *  DataTypeConversion: '<S199>/DataTypeConv1'
   *  DataTypeConversion: '<S199>/DataTypeConv2'
   *  Logic: '<S199>/AND3'
   *  RelationalOperator: '<S199>/Equal1'
   */
  if (rtb_LessThan3 && ((int8_T)rtb_vx == (int8_T)
                        rtb_front_wheel_angle_single__d)) {
    rtb_Gain1 = 0.0;
  } else {
    rtb_Gain1 = cumRevIndex;
  }

  /* End of Switch: '<S199>/Switch' */

  /* Chart: '<S146>/Chart' */
  rtDW.chartGlobalTickCounter++;
  rtb_LessThan3 = (rtDW.is_c24_TVModel == 3);
  if ((!rtb_LessThan3) || (!rtDW.countCondWasTrueAtLastTimeStep_)) {
    rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
  }

  rtDW.countCondWasTrueAtLastTimeStep_ = rtb_LessThan3;
  if (rtDW.is_active_c24_TVModel == 0U) {
    rtDW.chartGlobalTickCounter = 0;
    rtDW.is_active_c24_TVModel = 1U;
    rtDW.is_c24_TVModel = IN_OFF;
    rtDW.mz_output = 0.0;
  } else {
    switch (rtDW.is_c24_TVModel) {
     case IN_OFF:
      rtDW.mz_output = 0.0;
      break;

     case IN_ON:
      rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
      rtDW.is_c24_TVModel = IN_SWITCHING_FILTER;
      rtDW.mz_output *= mz_filter_tau;
      rtDW.countCondWasTrueAtLastTimeStep_ = (rtDW.is_c24_TVModel == 3);
      break;

     default:
      /* case IN_SWITCHING_FILTER: */
      rtb_LessThan3 = (rtDW.is_c24_TVModel == 3);
      if ((!rtb_LessThan3) || (!rtDW.countCondWasTrueAtLastTimeStep_)) {
        rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
      }

      rtDW.countCondWasTrueAtLastTimeStep_ = rtb_LessThan3;
      if (rtDW.chartGlobalTickCounter - rtDW.countReferenceTick_1 > 10) {
        rtDW.is_c24_TVModel = IN_OFF;
        rtDW.mz_output = 0.0;
      } else {
        rtDW.mz_output *= mz_filter_tau;
      }
      break;
    }
  }

  /* End of Chart: '<S146>/Chart' */

  /* RelationalOperator: '<S278>/Less Than' incorporates:
   *  DataStoreRead: '<S278>/Data Store General_Params'
   *  Inport: '<Root>/brake'
   */
  rtb_LessThan3 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S278>/T_Req_Chart' */
  guard1 = false;
  guard2 = false;
  if (rtDW.is_active_c21_TVModel == 0U) {
    rtDW.is_active_c21_TVModel = 1U;
    rtDW.is_c21_TVModel = IN_Throttle;
    rtb_SumofElements1 = 0.0;
    guard1 = true;
  } else if (rtDW.is_c21_TVModel == IN_Brake) {
    if ((!rtb_LessThan3) && (rtU.throttle < 0.05)) {
      rtDW.is_c21_TVModel = IN_Throttle;
      rtb_SumofElements1 = 0.0;
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    /* case IN_Throttle: */
    rtb_SumofElements1 = 0.0;
    if (rtb_LessThan3) {
      rtDW.is_c21_TVModel = IN_Brake;
      guard2 = true;
    } else {
      guard1 = true;
    }
  }

  if (guard2) {
    /* SignalConversion generated from: '<S298>/1-D Lookup Table' incorporates:
     *  Constant: '<S298>/Constant'
     *  DataStoreRead: '<S298>/Data Store Read'
     *  Switch: '<S278>/Switch'
     */
    fractions[0] = rtDW.General_Params.BrakeThresh;
    fractions[1] = 1.0;

    /* Lookup_n-D: '<S298>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/brake'
     *  Switch: '<S278>/Switch'
     */
    u0 = look1_binlx(rtU.brake, fractions, rtConstP.uDLookupTable_tableData, 1U);

    /* Saturate: '<S298>/Saturation_Brake' incorporates:
     *  Switch: '<S278>/Switch'
     */
    if (u0 > 1.0) {
      u0 = 1.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    /* End of Saturate: '<S298>/Saturation_Brake' */

    /* Switch: '<S278>/Switch' incorporates:
     *  Gain: '<S298>/Gain_Max_Torque_Needed'
     */
    rtb_SumofElements1 = -529.2 * u0;
  }

  if (guard1) {
    /* Switch: '<S297>/Switch' incorporates:
     *  DataStoreRead: '<S297>/Data Store General_Params1'
     *  Inport: '<Root>/throttle'
     *  RelationalOperator: '<S297>/Less Than'
     *  Switch: '<S278>/Switch'
     */
    if (rtU.throttle > rtDW.General_Params.ThrottleThresh) {
      /* SignalConversion generated from: '<S297>/T_nominal_wheel_LUT' incorporates:
       *  Constant: '<S297>/Constant1'
       *  Constant: '<S297>/Constant2'
       *  DataStoreRead: '<S297>/Data Store General_Params'
       */
      rtb_CCaller_o13[0] = 0.0;
      rtb_CCaller_o13[1] = rtDW.General_Params.ThrottleThresh;
      rtb_CCaller_o13[2] = 1.0;

      /* MultiPortSwitch: '<S297>/Map_Selector' incorporates:
       *  Lookup_n-D: '<S297>/T_peak_wheel_LUT'
       */
      rtb_SumofElements1 = look1_binlx(rtU.throttle, rtb_CCaller_o13,
        rtConstP.T_peak_wheel_LUT_tableData, 2U);
    }

    /* End of Switch: '<S297>/Switch' */
  }

  /* End of Chart: '<S278>/T_Req_Chart' */

  /* MATLABSystem: '<S278>/Moving Average' */
  if (rtDW.obj_m.TunablePropsChanged) {
    rtDW.obj_m.TunablePropsChanged = false;
  }

  obj_0 = rtDW.obj_m.pStatistic;
  if (obj_0->isInitialized != 1) {
    obj_0->isSetupComplete = false;
    obj_0->isInitialized = 1;
    obj_0->pCumSum = 0.0;
    obj_0->pCumSumRev[0] = 0.0;
    obj_0->pCumSumRev[1] = 0.0;
    obj_0->pCumSumRev[2] = 0.0;
    obj_0->pCumSumRev[3] = 0.0;
    obj_0->pCumRevIndex = 1.0;
    obj_0->pModValueRev = 0.0;
    obj_0->isSetupComplete = true;
    obj_0->pCumSum = 0.0;
    obj_0->pCumSumRev[0] = 0.0;
    obj_0->pCumSumRev[1] = 0.0;
    obj_0->pCumSumRev[2] = 0.0;
    obj_0->pCumSumRev[3] = 0.0;
    obj_0->pCumRevIndex = 1.0;
    obj_0->pModValueRev = 0.0;
  }

  cumRevIndex = obj_0->pCumRevIndex;
  rtb_Integrator_m = obj_0->pCumSum;
  rtb_Minus_i[0] = obj_0->pCumSumRev[0];
  rtb_Minus_i[1] = obj_0->pCumSumRev[1];
  rtb_Minus_i[2] = obj_0->pCumSumRev[2];
  rtb_Minus_i[3] = obj_0->pCumSumRev[3];
  modValueRev = obj_0->pModValueRev;
  rtb_Integrator_m += rtb_SumofElements1;
  rtb_Minus_i[(int32_T)cumRevIndex - 1] = rtb_SumofElements1;
  if (cumRevIndex != 4.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    rtb_Integrator_m = 0.0;
    rtb_Minus_i[2] += rtb_Minus_i[3];
    rtb_Minus_i[1] += rtb_Minus_i[2];
    rtb_Minus_i[0] += rtb_Minus_i[1];
  }

  obj_0->pCumSum = rtb_Integrator_m;
  obj_0->pCumSumRev[0] = rtb_Minus_i[0];
  obj_0->pCumSumRev[1] = rtb_Minus_i[1];
  obj_0->pCumSumRev[2] = rtb_Minus_i[2];
  obj_0->pCumSumRev[3] = rtb_Minus_i[3];
  obj_0->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj_0->pModValueRev = modValueRev - 1.0;
  } else {
    obj_0->pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S278>/Moving Average' */

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[0] = rtDW.UnitDelay_DSTATE_j[0];

  /* Update for UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[0] = rtb_ome_wheels_idx_0;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[1] = rtDW.UnitDelay_DSTATE_j[1];

  /* Update for UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[1] = rtb_ome_wheels_idx_1;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[2] = rtDW.UnitDelay_DSTATE_j[2];

  /* Update for UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[2] = rtb_ome_wheels_idx_2;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[3] = rtDW.UnitDelay_DSTATE_j[3];

  /* Update for UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[3] = rtb_ome_wheels;

  /* Update for DiscreteIntegrator: '<S62>/Integrator' */
  rtDW.Integrator_DSTATE[0] += 0.02 * rtb_Integrator_d[0];
  rtDW.Integrator_DSTATE[1] += 0.02 * rtb_Integrator_d[1];
  rtDW.Integrator_DSTATE[2] += 0.02 * rtb_Integrator_d[2];
  rtDW.Integrator_DSTATE[3] += 0.02 * rtb_Integrator_d[3];
  rtDW.Integrator_PrevResetState = (int8_T)AND;

  /* Update for Memory: '<S139>/Memory' incorporates:
   *  Product: '<S145>/Divide'
   */
  rtDW.Memory_PreviousInput[0] = rtb_Switch2_i[0];
  rtDW.Memory_PreviousInput[1] = rtb_Switch2_i[1];
  rtDW.Memory_PreviousInput[2] = rtb_Switch2_i[2];
  rtDW.Memory_PreviousInput[3] = rtb_Switch2_i[3];

  /* Update for DiscreteIntegrator: '<S287>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S280>/1//T' incorporates:
   *  Constant: '<S282>/Time constant'
   *  MinMax: '<S282>/Max'
   */
  rtb_Saturation1 = 1.0 / fmax(rtDW.Probe[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S287>/Integrator' */
  rtDW.Integrator_PrevResetState_e = (int8_T)rtb_Compare;

  /* Update for DiscreteIntegrator: '<S296>/Integrator' */
  rtDW.Integrator_IC_LOADING_j = 0U;

  /* Product: '<S289>/1//T' incorporates:
   *  Constant: '<S291>/Time constant'
   *  MinMax: '<S291>/Max'
   */
  rtb_Switch_gx = 1.0 / fmax(rtDW.Probe_k[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S296>/Integrator' */
  rtDW.Integrator_PrevResetState_b = (int8_T)rtb_Compare_p;

  /* Update for Memory: '<S256>/Memory' */
  rtDW.Memory_PreviousInput_f = rtb_Logic_idx_0;

  /* Update for Memory: '<S257>/Memory' */
  rtDW.Memory_PreviousInput_j = rtb_Logic_d_idx_0;

  /* Update for Memory: '<S258>/Memory' */
  rtDW.Memory_PreviousInput_j4 = rtb_Logic_o_idx_0;

  /* Update for Memory: '<S259>/Memory' */
  rtDW.Memory_PreviousInput_i = rtb_Logic_ds_idx_0;

  /* Update for DiscreteIntegrator: '<S287>/Integrator' incorporates:
   *  Product: '<S280>/1//T'
   *  Sum: '<S280>/Sum1'
   */
  rtDW.Integrator_DSTATE_m[0] += (rtb_ome_wheels_idx_3 - rtb_Integrator_idx_0) *
    rtb_Saturation1 * 0.02;

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S20>/LowerRelop1'
   *  RelationalOperator: '<S20>/UpperRelop'
   *  Switch: '<S20>/Switch'
   */
  if (rtDW.T_max[0] > 21.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    rtDW.UnitDelay1_DSTATE[0] = 21.0;
  } else if (rtDW.T_max[0] < 0.0) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    rtDW.UnitDelay1_DSTATE[0] = 0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay1' incorporates:
     *  Switch: '<S20>/Switch'
     */
    rtDW.UnitDelay1_DSTATE[0] = rtDW.T_max[0];
  }

  /* Update for DiscreteIntegrator: '<S296>/Integrator' incorporates:
   *  Product: '<S289>/1//T'
   *  Sum: '<S289>/Sum1'
   */
  rtDW.Integrator_DSTATE_f[0] += (rtb_Saturation_k_idx_0 -
    rtb_Integrator_c_idx_0) * rtb_Switch_gx * 0.02;

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtDW.T_min[0] > 21.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    rtDW.UnitDelay2_DSTATE[0] = -21.0;
  } else if (rtDW.T_min[0] < 0.0) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S16>/Constant3'
     *  UnaryMinus: '<S16>/Unary Minus'
     *  UnitDelay: '<S11>/Unit Delay2'
     */
    rtDW.UnitDelay2_DSTATE[0] = -0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
     *  Switch: '<S21>/Switch'
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    rtDW.UnitDelay2_DSTATE[0] = -rtDW.T_min[0];
  }

  /* Update for Delay: '<S172>/Delay' */
  rtDW.Delay_DSTATE[0] = rtDW.Delay_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S287>/Integrator' incorporates:
   *  Product: '<S280>/1//T'
   *  Sum: '<S280>/Sum1'
   */
  rtDW.Integrator_DSTATE_m[1] += (rtb_Gain_idx_1 - rtb_Integrator_idx_1) *
    rtb_Saturation1 * 0.02;

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S20>/LowerRelop1'
   *  RelationalOperator: '<S20>/UpperRelop'
   *  Switch: '<S20>/Switch'
   */
  if (rtDW.T_max[1] > 21.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    rtDW.UnitDelay1_DSTATE[1] = 21.0;
  } else if (rtDW.T_max[1] < 0.0) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    rtDW.UnitDelay1_DSTATE[1] = 0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay1' incorporates:
     *  Switch: '<S20>/Switch'
     */
    rtDW.UnitDelay1_DSTATE[1] = rtDW.T_max[1];
  }

  /* Update for DiscreteIntegrator: '<S296>/Integrator' incorporates:
   *  Product: '<S289>/1//T'
   *  Sum: '<S289>/Sum1'
   */
  rtDW.Integrator_DSTATE_f[1] += (rtb_Saturation_k_idx_1 -
    rtb_Integrator_c_idx_1) * rtb_Switch_gx * 0.02;

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtDW.T_min[1] > 21.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    rtDW.UnitDelay2_DSTATE[1] = -21.0;
  } else if (rtDW.T_min[1] < 0.0) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S16>/Constant3'
     *  UnaryMinus: '<S16>/Unary Minus'
     *  UnitDelay: '<S11>/Unit Delay2'
     */
    rtDW.UnitDelay2_DSTATE[1] = -0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
     *  Switch: '<S21>/Switch'
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    rtDW.UnitDelay2_DSTATE[1] = -rtDW.T_min[1];
  }

  /* Update for Delay: '<S172>/Delay' */
  rtDW.Delay_DSTATE[1] = rtDW.Delay_DSTATE[2];

  /* Update for DiscreteIntegrator: '<S287>/Integrator' incorporates:
   *  Product: '<S280>/1//T'
   *  Sum: '<S280>/Sum1'
   */
  rtDW.Integrator_DSTATE_m[2] += (rtb_Gain_idx_2 - rtb_Integrator_idx_2) *
    rtb_Saturation1 * 0.02;

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S20>/LowerRelop1'
   *  RelationalOperator: '<S20>/UpperRelop'
   *  Switch: '<S20>/Switch'
   */
  if (rtDW.T_max[2] > 21.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    rtDW.UnitDelay1_DSTATE[2] = 21.0;
  } else if (rtDW.T_max[2] < 0.0) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    rtDW.UnitDelay1_DSTATE[2] = 0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay1' incorporates:
     *  Switch: '<S20>/Switch'
     */
    rtDW.UnitDelay1_DSTATE[2] = rtDW.T_max[2];
  }

  /* Update for DiscreteIntegrator: '<S296>/Integrator' incorporates:
   *  Product: '<S289>/1//T'
   *  Sum: '<S289>/Sum1'
   */
  rtDW.Integrator_DSTATE_f[2] += (rtb_Saturation_k_idx_2 -
    rtb_Integrator_c_idx_2) * rtb_Switch_gx * 0.02;

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtDW.T_min[2] > 21.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    rtDW.UnitDelay2_DSTATE[2] = -21.0;
  } else if (rtDW.T_min[2] < 0.0) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S16>/Constant3'
     *  UnaryMinus: '<S16>/Unary Minus'
     *  UnitDelay: '<S11>/Unit Delay2'
     */
    rtDW.UnitDelay2_DSTATE[2] = -0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
     *  Switch: '<S21>/Switch'
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    rtDW.UnitDelay2_DSTATE[2] = -rtDW.T_min[2];
  }

  /* Update for Delay: '<S172>/Delay' */
  rtDW.Delay_DSTATE[2] = rtDW.Delay_DSTATE[3];

  /* Update for DiscreteIntegrator: '<S287>/Integrator' incorporates:
   *  Product: '<S280>/1//T'
   *  Sum: '<S280>/Sum1'
   */
  rtDW.Integrator_DSTATE_m[3] += (rtb_Gain_idx_3 - rtb_Integrator_idx_3) *
    rtb_Saturation1 * 0.02;

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S20>/LowerRelop1'
   *  RelationalOperator: '<S20>/UpperRelop'
   *  Switch: '<S20>/Switch'
   */
  if (rtDW.T_max[3] > 21.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay1' */
    rtDW.UnitDelay1_DSTATE[3] = 21.0;
  } else if (rtDW.T_max[3] < 0.0) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    rtDW.UnitDelay1_DSTATE[3] = 0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay1' incorporates:
     *  Switch: '<S20>/Switch'
     */
    rtDW.UnitDelay1_DSTATE[3] = rtDW.T_max[3];
  }

  /* Update for DiscreteIntegrator: '<S296>/Integrator' incorporates:
   *  Product: '<S289>/1//T'
   *  Sum: '<S289>/Sum1'
   */
  rtDW.Integrator_DSTATE_f[3] += (rtb_Saturation_k_idx_3 -
    rtb_Integrator_c_idx_3) * rtb_Switch_gx * 0.02;

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtDW.T_min[3] > 21.0) {
    /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    rtDW.UnitDelay2_DSTATE[3] = -21.0;
  } else if (rtDW.T_min[3] < 0.0) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S16>/Constant3'
     *  UnaryMinus: '<S16>/Unary Minus'
     *  UnitDelay: '<S11>/Unit Delay2'
     */
    rtDW.UnitDelay2_DSTATE[3] = -0.0;
  } else {
    /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
     *  Switch: '<S21>/Switch'
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    rtDW.UnitDelay2_DSTATE[3] = -rtDW.T_min[3];
  }

  /* Update for Delay: '<S172>/Delay' */
  rtDW.Delay_DSTATE[3] = rtDW.Delay_DSTATE[4];
  rtDW.Delay_DSTATE[4] = rtb_Logic_idx_1;

  /* Update for Memory: '<S232>/Memory' */
  rtDW.Memory_PreviousInput_l = rtb_Logic_idx_1;

  /* Update for DiscreteIntegrator: '<S209>/Integrator' */
  rtDW.Integrator_DSTATE_n += 0.02 * rtb_Gain1;
  rtDW.Integrator_PrevResetState_i = (int8_T)rtb_Logic_o_idx_1;

  /* Update for DiscreteIntegrator: '<S204>/Filter' incorporates:
   *  DiscreteIntegrator: '<S209>/Integrator'
   */
  rtDW.Filter_DSTATE += 0.02 * rtb_NProdOut;
  rtDW.Filter_PrevResetState = (int8_T)rtb_Logic_o_idx_1;

  /* Update for DiscreteFir: '<S156>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf] = idx;

  /* End of Update for DiscreteFir: '<S156>/Discrete FIR Filter' */

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_e[0] = rtDW.T_min[0];
  rtDW.UnitDelay_DSTATE_e[1] = rtDW.T_min[1];
  rtDW.UnitDelay_DSTATE_e[2] = rtDW.T_min[2];
  rtDW.UnitDelay_DSTATE_e[3] = rtDW.T_min[3];

  /* Signum: '<S109>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp = rtb_SignPreIntegrator_e[0];

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp_0 = rtb_Tnew[0];

  /* Signum: '<S109>/SignPreSat' */
  if (u0_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u0_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u0_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  /* Signum: '<S109>/SignPreIntegrator' */
  if (u0_tmp_0 < 0.0) {
    u0_tmp_0 = -1.0;
  } else if (u0_tmp_0 > 0.0) {
    u0_tmp_0 = 1.0;
  } else if (u0_tmp_0 == 0.0) {
    u0_tmp_0 = 0.0;
  } else {
    u0_tmp_0 = (rtNaN);
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DataTypeConversion: '<S109>/DataTypeConv1'
   *  DataTypeConversion: '<S109>/DataTypeConv2'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/NotEqual'
   */
  if ((rtb_k_l_idx_0 != rtb_SignPreIntegrator_e[0]) && ((int8_T)u0_tmp ==
       (int8_T)u0_tmp_0)) {
    rtb_k_i = 0.0;
  } else {
    rtb_k_i = rtb_Tnew[0];
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_a[0] += 0.02 * rtb_k_i;

  /* Signum: '<S109>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp = rtb_SignPreIntegrator_e[1];

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp_0 = rtb_Tnew[1];

  /* Signum: '<S109>/SignPreSat' */
  if (u0_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u0_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u0_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  /* Signum: '<S109>/SignPreIntegrator' */
  if (u0_tmp_0 < 0.0) {
    u0_tmp_0 = -1.0;
  } else if (u0_tmp_0 > 0.0) {
    u0_tmp_0 = 1.0;
  } else if (u0_tmp_0 == 0.0) {
    u0_tmp_0 = 0.0;
  } else {
    u0_tmp_0 = (rtNaN);
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DataTypeConversion: '<S109>/DataTypeConv1'
   *  DataTypeConversion: '<S109>/DataTypeConv2'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/NotEqual'
   */
  if ((rtb_k_l_idx_1 != rtb_SignPreIntegrator_e[1]) && ((int8_T)u0_tmp ==
       (int8_T)u0_tmp_0)) {
    rtb_k_i = 0.0;
  } else {
    rtb_k_i = rtb_Tnew[1];
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_a[1] += 0.02 * rtb_k_i;

  /* Signum: '<S109>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp = rtb_SignPreIntegrator_e[2];

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp_0 = rtb_Tnew[2];

  /* Signum: '<S109>/SignPreSat' */
  if (u0_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u0_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u0_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  /* Signum: '<S109>/SignPreIntegrator' */
  if (u0_tmp_0 < 0.0) {
    u0_tmp_0 = -1.0;
  } else if (u0_tmp_0 > 0.0) {
    u0_tmp_0 = 1.0;
  } else if (u0_tmp_0 == 0.0) {
    u0_tmp_0 = 0.0;
  } else {
    u0_tmp_0 = (rtNaN);
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DataTypeConversion: '<S109>/DataTypeConv1'
   *  DataTypeConversion: '<S109>/DataTypeConv2'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/NotEqual'
   */
  if ((rtb_k_l_idx_2 != rtb_SignPreIntegrator_e[2]) && ((int8_T)u0_tmp ==
       (int8_T)u0_tmp_0)) {
    rtb_k_i = 0.0;
  } else {
    rtb_k_i = rtb_Tnew[2];
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_a[2] += 0.02 * rtb_k_i;

  /* Signum: '<S109>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp = rtb_SignPreIntegrator_e[3];

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp_0 = rtb_Tnew[3];

  /* Signum: '<S109>/SignPreSat' */
  if (u0_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u0_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u0_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  /* Signum: '<S109>/SignPreIntegrator' */
  if (u0_tmp_0 < 0.0) {
    u0_tmp_0 = -1.0;
  } else if (u0_tmp_0 > 0.0) {
    u0_tmp_0 = 1.0;
  } else if (u0_tmp_0 == 0.0) {
    u0_tmp_0 = 0.0;
  } else {
    u0_tmp_0 = (rtNaN);
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DataTypeConversion: '<S109>/DataTypeConv1'
   *  DataTypeConversion: '<S109>/DataTypeConv2'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/NotEqual'
   */
  if ((rtb_k_l_idx_3 != rtb_SignPreIntegrator_e[3]) && ((int8_T)u0_tmp ==
       (int8_T)u0_tmp_0)) {
    rtb_k_i = 0.0;
  } else {
    rtb_k_i = rtb_Tnew[3];
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_a[3] += 0.02 * rtb_k_i;
  rtDW.Integrator_PrevResetState_g = (int8_T)rtb_Logic_d_idx_1;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_d[0] = rtDW.T_max[0];
  rtDW.UnitDelay_DSTATE_d[1] = rtDW.T_max[1];
  rtDW.UnitDelay_DSTATE_d[2] = rtDW.T_max[2];
  rtDW.UnitDelay_DSTATE_d[3] = rtDW.T_max[3];

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Inport: '<Root>/brake_torque_FL'
   *  Inport: '<Root>/brake_torque_FR'
   *  Inport: '<Root>/brake_torque_RL'
   *  Inport: '<Root>/brake_torque_RR'
   */
  rtDW.UnitDelay_DSTATE_j[0] = rtU.brake_torque_FL;
  rtDW.UnitDelay_DSTATE_j[1] = rtU.brake_torque_FR;
  rtDW.UnitDelay_DSTATE_j[2] = rtU.brake_torque_RL;
  rtDW.UnitDelay_DSTATE_j[3] = rtU.brake_torque_RR;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Torque' */
  rtY.Torque[0] = rtb_Switch2_i[0];
  rtY.Torque[1] = rtb_Switch2_i[1];
  rtY.Torque[2] = rtb_Switch2_i[2];
  rtY.Torque[3] = rtb_Switch2_i[3];
}

/* Model initialize function */
void TVModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    g_dsp_internal_SlidingWindowA_l *iobj_0_0;
    g_dsp_internal_SlidingWindowAve *iobj_0;
    int32_T i;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
    /* Start for Probe: '<S282>/Probe' */
    rtDW.Probe[0] = 0.02;
    rtDW.Probe[1] = 0.0;

    /* Start for Probe: '<S291>/Probe' */
    rtDW.Probe_k[0] = 0.02;
    rtDW.Probe_k[1] = 0.0;

    /* Start for InitialCondition: '<S235>/IC' */
    rtDW.IC_FirstOutputTime = true;

    /* Start for InitialCondition: '<S236>/IC1' */
    rtDW.IC1_FirstOutputTime = true;

    /* Start for DataStoreMemory: '<S3>/Data Store_General_Params' */
    rtDW.General_Params = rtConstP.DataStore_General_Params_Initia;

    /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator' */
    rtDW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S287>/Integrator' */
    rtDW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S296>/Integrator' */
    rtDW.Integrator_IC_LOADING_j = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
    rtDW.Integrator_PrevResetState_g = 2;

    /* SystemInitialize for Chart: '<S239>/Distribution complete' */
    rtDW.tr = 1.27;
    rtDW.Rw = 0.235;

    /* Start for MATLABSystem: '<S172>/Moving Average' */
    rtDW.obj.matlabCodegenIsDeleted = true;
    rtDW.obj.isInitialized = 0;
    rtDW.obj.NumChannels = -1;
    rtDW.obj.matlabCodegenIsDeleted = false;
    rtDW.obj.isSetupComplete = false;
    rtDW.obj.isInitialized = 1;
    rtDW.obj.NumChannels = 1;
    iobj_0 = &rtDW.obj._pobj0;
    iobj_0->isInitialized = 0;
    iobj_0->isInitialized = 0;
    rtDW.obj.pStatistic = iobj_0;
    rtDW.obj.isSetupComplete = true;
    rtDW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S172>/Moving Average' */
    iobj_0 = rtDW.obj.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum = 0.0;
      for (i = 0; i < 24; i++) {
        iobj_0->pCumSumRev[i] = 0.0;
      }

      iobj_0->pCumRevIndex = 1.0;
      iobj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S172>/Moving Average' */

    /* Start for MATLABSystem: '<S278>/Moving Average' */
    rtDW.obj_m.matlabCodegenIsDeleted = true;
    rtDW.obj_m.isInitialized = 0;
    rtDW.obj_m.NumChannels = -1;
    rtDW.obj_m.matlabCodegenIsDeleted = false;
    rtDW.obj_m.isSetupComplete = false;
    rtDW.obj_m.isInitialized = 1;
    rtDW.obj_m.NumChannels = 1;
    iobj_0_0 = &rtDW.obj_m._pobj0;
    iobj_0_0->isInitialized = 0;
    iobj_0_0->isInitialized = 0;
    rtDW.obj_m.pStatistic = iobj_0_0;
    rtDW.obj_m.isSetupComplete = true;
    rtDW.obj_m.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S278>/Moving Average' */
    iobj_0_0 = rtDW.obj_m.pStatistic;
    if (iobj_0_0->isInitialized == 1) {
      iobj_0_0->pCumSum = 0.0;
      iobj_0_0->pCumSumRev[0] = 0.0;
      iobj_0_0->pCumSumRev[1] = 0.0;
      iobj_0_0->pCumSumRev[2] = 0.0;
      iobj_0_0->pCumSumRev[3] = 0.0;
      iobj_0_0->pCumRevIndex = 1.0;
      iobj_0_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S278>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
