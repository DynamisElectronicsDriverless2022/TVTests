/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Jun  9 12:20:35 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TVModel.h"

/* Named constants for Chart: '<S22>/Overlap Chart' */
#define IN_Go                          ((uint8_T)1U)
#define IN_Stop                        ((uint8_T)2U)

/* Named constants for Chart: '<S23>/Chart' */
#define IN_OFF                         ((uint8_T)1U)
#define IN_ON                          ((uint8_T)2U)
#define IN_SWITCHING_FILTER            ((uint8_T)3U)
#define mz_filter_tau                  (0.98019867330675525)

/* Named constants for Chart: '<S155>/T_Req_Chart' */
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

/* Function for Chart: '<S116>/Distribution complete' */
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

/* Function for Chart: '<S116>/Distribution complete' */
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

/* Function for Chart: '<S116>/Distribution complete' */
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

/* Function for Chart: '<S116>/Distribution complete' */
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
  real_T rtb_Braking[4];
  real_T rtb_Braking_0[4];
  real_T rtb_CCaller_o8[4];
  real_T rtb_Memory[4];
  real_T rtb_Product[4];
  real_T rtb_Product1[4];
  real_T rtb_Tnew[4];
  real_T rtb_UnaryMinus_d0[4];
  real_T rtb_UnaryMinus_f[4];
  real_T rtb_CCaller_o13[3];
  real_T rtb_CCaller_o14[3];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T Faeroz_tmp;
  real_T Fy_FR;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T rtb_Abs_i_idx_0;
  real_T rtb_Abs_l;
  real_T rtb_Gain1;
  real_T rtb_Gain_idx_0;
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
  real_T rtb_RL;
  real_T rtb_RL_tmp;
  real_T rtb_RL_tmp_0;
  real_T rtb_RL_tmp_tmp;
  real_T rtb_RR;
  real_T rtb_Saturation1;
  real_T rtb_Saturation1_tmp;
  real_T rtb_Saturation1_tmp_0;
  real_T rtb_Saturation1_tmp_1;
  real_T rtb_Saturation1_tmp_2;
  real_T rtb_Saturation1_tmp_tmp;
  real_T rtb_Saturation1_tmp_tmp_0;
  real_T rtb_Saturation_k_idx_0;
  real_T rtb_Saturation_k_idx_1;
  real_T rtb_Saturation_k_idx_2;
  real_T rtb_Saturation_k_idx_3;
  real_T rtb_Sign;
  real_T rtb_SumofElements1;
  real_T rtb_Switch;
  real_T rtb_Switch_b;
  real_T rtb_UnaryMinus_f_tmp;
  real_T rtb_front_wheel_angle_single__d;
  real_T rtb_vx;
  real_T rtb_yrd;
  real_T u0;
  real_T u0_tmp;
  real_T u_tmp;
  real_T z;
  int32_T tmp[2];
  int32_T X1;
  int32_T b_exit;
  int32_T rtb_y_tmp;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_p;
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
    rtb_Sign = (rtNaN);
  }

  /* End of Signum: '<S9>/Sign' */

  /* Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Product: '<S9>/Divide1'
   */
  rtb_Abs_i_idx_0 = fabs(look1_binlx(rtU.steering, rtConstP.pooled33,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Abs_l = fabs(look1_binlx(-rtU.steering, rtConstP.pooled33,
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
    rtb_Switch_b = (0.235 * rtU.omega_wheels_FR - rtb_Sign) / rtb_Sign;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_vx) / rtb_vx;
    rtb_RL = (0.235 * rtU.omega_wheels_RL - rtb_vx) / rtb_vx;
  } else {
    rtb_Switch = 0.0;
    rtb_Switch_b = 0.0;
    rtb_RR = 0.0;
    rtb_RL = 0.0;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_front_wheel_angle_single__d = look1_binlx(rtU.steering, rtConstP.pooled33,
    rtConstP.steering_to_wheel_angle_single_, 32U);

  /* RateTransition: '<S29>/Rate Transition3' incorporates:
   *  Constant: '<S19>/Inertia Scaling'
   *  Constant: '<S19>/LMUy'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = rtb_front_wheel_angle_single__d;
  RateTransition3[1] = rtb_Switch;
  RateTransition3[2] = rtb_Switch_b;
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

  /* CFunction: '<S29>/C Function' incorporates:
   *  Constant: '<S29>/Constant3'
   */
  for (X1 = 0; X1 < 2; X1++) {
    memcpy(&rtDW.CFunction[X1 * 13], &RateTransition3[0], 13U * sizeof(real_T));
  }

  /* End of CFunction: '<S29>/C Function' */

  /* Memory: '<S16>/Memory' */
  rtb_Memory[0] = rtDW.Memory_PreviousInput[0];
  rtb_Memory[1] = rtDW.Memory_PreviousInput[1];
  rtb_Memory[2] = rtDW.Memory_PreviousInput[2];
  rtb_Memory[3] = rtDW.Memory_PreviousInput[3];

  /* Lookup_n-D: '<S153>/Max_Torque_Overload_Motor_LUT' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Lookup_n-D: '<S153>/Max_Torque_Overload_Inverter_LUT'
   *  Lookup_n-D: '<S154>/Display Overload Inverter LUT'
   *  Lookup_n-D: '<S154>/Display Overload Motor LUT'
   */
  rtb_Integrator_c_idx_0 = look1_binlx(0.0, rtConstP.pooled36, rtConstP.pooled35,
    2U);
  rtb_Braking[0] = rtb_Integrator_c_idx_0;
  rtb_Braking[1] = rtb_Integrator_c_idx_0;
  rtb_Braking[2] = rtb_Integrator_c_idx_0;
  rtb_Braking[3] = rtb_Integrator_c_idx_0;

  /* Lookup_n-D: '<S153>/Max_Torque_Overload_Inverter_LUT' */
  rtb_Tnew[0] = rtb_Integrator_c_idx_0;
  rtb_Tnew[1] = rtb_Integrator_c_idx_0;
  rtb_Tnew[2] = rtb_Integrator_c_idx_0;
  rtb_Tnew[3] = rtb_Integrator_c_idx_0;

  /* RelationalOperator: '<S162>/Compare' incorporates:
   *  Constant: '<S159>/Time constant'
   *  Constant: '<S162>/Constant'
   *  Sum: '<S159>/Sum1'
   */
  rtb_Compare = (0.079577471545947673 - rtDW.Probe[0] <= 0.0);

  /* Gain: '<S156>/Gain4' incorporates:
   *  Gain: '<S165>/Gain4'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  z = 128.91550390443524 * rtU.omega_wheels_FL;

  /* Saturate: '<S156>/Saturation1' incorporates:
   *  Gain: '<S156>/Gain4'
   */
  if (z <= 0.0) {
    rtb_UnaryMinus_d0[0] = 0.0;
  } else {
    rtb_UnaryMinus_d0[0] = z;
  }

  /* Gain: '<S156>/Gain4' incorporates:
   *  Gain: '<S165>/Gain4'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  Fy_FR = 128.91550390443524 * rtU.omega_wheels_FR;

  /* Saturate: '<S156>/Saturation1' incorporates:
   *  Gain: '<S156>/Gain4'
   */
  if (Fy_FR <= 0.0) {
    rtb_UnaryMinus_d0[1] = 0.0;
  } else {
    rtb_UnaryMinus_d0[1] = Fy_FR;
  }

  /* Gain: '<S156>/Gain4' incorporates:
   *  Gain: '<S165>/Gain4'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  rtb_yrd = 128.91550390443524 * rtU.omega_wheels_RL;

  /* Saturate: '<S156>/Saturation1' incorporates:
   *  Gain: '<S156>/Gain4'
   */
  if (rtb_yrd <= 0.0) {
    rtb_UnaryMinus_d0[2] = 0.0;
  } else {
    rtb_UnaryMinus_d0[2] = rtb_yrd;
  }

  /* Gain: '<S156>/Gain4' incorporates:
   *  Gain: '<S165>/Gain4'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0_tmp = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S156>/Saturation1' incorporates:
   *  Gain: '<S156>/Gain4'
   */
  if (u0_tmp <= 0.0) {
    rtb_UnaryMinus_d0[3] = 0.0;
  } else {
    rtb_UnaryMinus_d0[3] = u0_tmp;
  }

  /* Lookup_n-D: '<S156>/2-D Lookup Table' incorporates:
   *  Constant: '<S153>/Constant7'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &cumRevIndex);
  fractions[1U] = cumRevIndex;
  bpIndices[0U] = plook_binc(rtb_UnaryMinus_d0[0], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_UnaryMinus_d0[0] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_UnaryMinus_d0[1], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_UnaryMinus_d0[1] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_UnaryMinus_d0[2], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_UnaryMinus_d0[2] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_UnaryMinus_d0[3], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_UnaryMinus_d0[3] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);

  /* Gain: '<S156>/Gain' */
  rtb_Gain_idx_0 = 0.0098000000000000014 * rtb_UnaryMinus_d0[0];
  rtb_Gain_idx_1 = 0.0098000000000000014 * rtb_UnaryMinus_d0[1];
  rtb_Gain_idx_2 = 0.0098000000000000014 * rtb_UnaryMinus_d0[2];
  rtb_Gain_idx_3 = 0.0098000000000000014 * rtb_UnaryMinus_d0[3];

  /* DiscreteIntegrator: '<S164>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE[0] = rtb_Gain_idx_0;
    rtDW.Integrator_DSTATE[1] = rtb_Gain_idx_1;
    rtDW.Integrator_DSTATE[2] = rtb_Gain_idx_2;
    rtDW.Integrator_DSTATE[3] = rtb_Gain_idx_3;
  }

  if (rtb_Compare || (rtDW.Integrator_PrevResetState != 0)) {
    rtDW.Integrator_DSTATE[0] = rtb_Gain_idx_0;
    rtDW.Integrator_DSTATE[1] = rtb_Gain_idx_1;
    rtDW.Integrator_DSTATE[2] = rtb_Gain_idx_2;
    rtDW.Integrator_DSTATE[3] = rtb_Gain_idx_3;
  }

  rtb_Integrator_idx_0 = rtDW.Integrator_DSTATE[0];
  rtb_Integrator_idx_1 = rtDW.Integrator_DSTATE[1];
  rtb_Integrator_idx_2 = rtDW.Integrator_DSTATE[2];
  rtb_Integrator_idx_3 = rtDW.Integrator_DSTATE[3];

  /* MinMax: '<S153>/Min' incorporates:
   *  Constant: '<S156>/Constant'
   *  DiscreteIntegrator: '<S164>/Integrator'
   *  RelationalOperator: '<S158>/LowerRelop1'
   *  RelationalOperator: '<S158>/UpperRelop'
   *  Switch: '<S158>/Switch'
   *  Switch: '<S158>/Switch2'
   */
  if (rtDW.Integrator_DSTATE[0] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE[0] < 0.0) {
    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S156>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE[0];
  }

  u0 = fmin(fmin(fmin(rtb_Braking[0], rtb_Tnew[0]), 20.972), rtb_Saturation1);

  /* Saturate: '<S153>/Saturation_Positive' incorporates:
   *  MinMax: '<S153>/Min'
   */
  if (u0 <= 0.0) {
    rtb_Braking[0] = 0.0;
  } else {
    rtb_Braking[0] = u0;
  }

  /* MinMax: '<S153>/Min' incorporates:
   *  Constant: '<S156>/Constant'
   *  DiscreteIntegrator: '<S164>/Integrator'
   *  RelationalOperator: '<S158>/LowerRelop1'
   *  RelationalOperator: '<S158>/UpperRelop'
   *  Switch: '<S158>/Switch'
   *  Switch: '<S158>/Switch2'
   */
  if (rtDW.Integrator_DSTATE[1] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE[1] < 0.0) {
    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S156>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE[1];
  }

  u0 = fmin(fmin(fmin(rtb_Braking[1], rtb_Tnew[1]), 20.972), rtb_Saturation1);

  /* Saturate: '<S153>/Saturation_Positive' incorporates:
   *  MinMax: '<S153>/Min'
   */
  if (u0 <= 0.0) {
    rtb_Braking[1] = 0.0;
  } else {
    rtb_Braking[1] = u0;
  }

  /* MinMax: '<S153>/Min' incorporates:
   *  Constant: '<S156>/Constant'
   *  DiscreteIntegrator: '<S164>/Integrator'
   *  RelationalOperator: '<S158>/LowerRelop1'
   *  RelationalOperator: '<S158>/UpperRelop'
   *  Switch: '<S158>/Switch'
   *  Switch: '<S158>/Switch2'
   */
  if (rtDW.Integrator_DSTATE[2] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE[2] < 0.0) {
    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S156>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE[2];
  }

  u0 = fmin(fmin(fmin(rtb_Braking[2], rtb_Tnew[2]), 20.972), rtb_Saturation1);

  /* Saturate: '<S153>/Saturation_Positive' incorporates:
   *  MinMax: '<S153>/Min'
   */
  if (u0 <= 0.0) {
    rtb_Braking[2] = 0.0;
  } else {
    rtb_Braking[2] = u0;
  }

  /* MinMax: '<S153>/Min' incorporates:
   *  Constant: '<S156>/Constant'
   *  DiscreteIntegrator: '<S164>/Integrator'
   *  RelationalOperator: '<S158>/LowerRelop1'
   *  RelationalOperator: '<S158>/UpperRelop'
   *  Switch: '<S158>/Switch'
   *  Switch: '<S158>/Switch2'
   */
  if (rtDW.Integrator_DSTATE[3] > 21.0) {
    rtb_Saturation1 = 21.0;
  } else if (rtDW.Integrator_DSTATE[3] < 0.0) {
    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S156>/Constant'
     */
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtDW.Integrator_DSTATE[3];
  }

  u0 = fmin(fmin(fmin(rtb_Braking[3], rtb_Tnew[3]), 20.972), rtb_Saturation1);

  /* Saturate: '<S153>/Saturation_Positive' incorporates:
   *  MinMax: '<S153>/Min'
   */
  if (u0 <= 0.0) {
    rtb_Braking[3] = 0.0;
  } else {
    rtb_Braking[3] = u0;
  }

  /* Math: '<S139>/Square1' incorporates:
   *  MATLAB Function: '<S23>/MATLAB Function2'
   *  Math: '<S139>/Square2'
   *  Math: '<S141>/Square1'
   */
  rtb_UnaryMinus_f_tmp = rtb_vx * rtb_vx;

  /* Gain: '<S139>/Lateral Load Transfer' incorporates:
   *  Gain: '<S140>/Lateral Load Transfer'
   *  Gain: '<S141>/Lateral Load Transfer'
   *  Gain: '<S142>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S139>/Unary Minus'
   */
  rtb_Saturation_k_idx_0 = 30.826771653543307 * -rtU.ay;

  /* Gain: '<S139>/Lift Force' incorporates:
   *  Gain: '<S140>/Lift Force'
   *  Math: '<S139>/Square1'
   */
  rtb_Saturation_k_idx_1 = rtb_UnaryMinus_f_tmp * 0.92446666666666677;

  /* Gain: '<S139>/Drag moment' incorporates:
   *  Gain: '<S140>/Drag moment'
   *  Gain: '<S141>/Drag moment'
   *  Gain: '<S142>/Drag moment'
   */
  rtb_Saturation_k_idx_2 = rtb_UnaryMinus_f_tmp * 0.21998117647058821;

  /* Gain: '<S139>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S140>/Longitudinal Load Transfer'
   *  Gain: '<S141>/Longitudinal Load Transfer'
   *  Gain: '<S142>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S139>/Unary Minus1'
   */
  rtb_Saturation_k_idx_3 = 25.588235294117645 * -rtU.ax;

  /* SignalConversion generated from: '<S131>/2-D Lookup Table' incorporates:
   *  Constant: '<S139>/Static Load Front'
   *  Constant: '<S140>/Static Load Front'
   *  Gain: '<S139>/Drag moment'
   *  Gain: '<S139>/Lateral Load Transfer'
   *  Gain: '<S139>/Lift Force'
   *  Gain: '<S139>/Longitudinal Load Transfer'
   *  Sum: '<S139>/Subtract'
   *  Sum: '<S140>/Subtract'
   */
  rtb_UnaryMinus_d0[0] = (((rtb_Saturation_k_idx_0 + 635.688) +
    rtb_Saturation_k_idx_1) - rtb_Saturation_k_idx_2) + rtb_Saturation_k_idx_3;
  rtb_UnaryMinus_d0[1] = (((635.688 - rtb_Saturation_k_idx_0) +
    rtb_Saturation_k_idx_1) - rtb_Saturation_k_idx_2) + rtb_Saturation_k_idx_3;

  /* Gain: '<S141>/Lift Force' incorporates:
   *  Gain: '<S142>/Lift Force'
   */
  rtb_Saturation_k_idx_1 = rtb_UnaryMinus_f_tmp * 0.74153333333333349;

  /* SignalConversion generated from: '<S131>/2-D Lookup Table' incorporates:
   *  Constant: '<S141>/Static Load Front'
   *  Constant: '<S142>/Static Load Front'
   *  Gain: '<S141>/Lift Force'
   *  Sum: '<S141>/Subtract'
   *  Sum: '<S142>/Subtract'
   */
  rtb_UnaryMinus_d0[2] = (((rtb_Saturation_k_idx_0 + 688.66200000000015) +
    rtb_Saturation_k_idx_1) + rtb_Saturation_k_idx_2) - rtb_Saturation_k_idx_3;
  rtb_UnaryMinus_d0[3] = (((688.66200000000015 - rtb_Saturation_k_idx_0) +
    rtb_Saturation_k_idx_1) + rtb_Saturation_k_idx_2) - rtb_Saturation_k_idx_3;

  /* Switch: '<S138>/Switch' incorporates:
   *  Constant: '<S138>/Constant'
   *  Sum: '<S143>/Subtract'
   *  Sum: '<S143>/Subtract1'
   *  Sum: '<S143>/Subtract2'
   *  Sum: '<S144>/Subtract'
   *  Sum: '<S144>/Subtract2'
   *  Sum: '<S145>/Subtract1'
   *  Trigonometry: '<S143>/Atan'
   *  Trigonometry: '<S144>/Atan'
   *  Trigonometry: '<S145>/Atan'
   *  Trigonometry: '<S146>/Atan'
   */
  if (rtb_vx > 3.0) {
    /* Sum: '<S143>/Subtract1' incorporates:
     *  Gain: '<S143>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S144>/Subtract1'
     */
    rtb_Saturation_k_idx_0 = 0.73439999999999994 * rtb_Gain1 + rtU.vy;

    /* Sum: '<S143>/Subtract' incorporates:
     *  Gain: '<S143>/Gain1'
     *  Sum: '<S145>/Subtract'
     */
    rtb_Saturation_k_idx_1 = rtb_vx - 0.635 * rtb_Gain1;
    rtb_Tnew[0] = rt_atan2d_snf(rtb_Saturation_k_idx_0, rtb_Saturation_k_idx_1)
      - rtb_Abs_i_idx_0;

    /* Sum: '<S144>/Subtract' incorporates:
     *  Gain: '<S144>/Gain1'
     *  Sum: '<S143>/Subtract'
     *  Sum: '<S143>/Subtract1'
     *  Sum: '<S143>/Subtract2'
     *  Sum: '<S146>/Subtract'
     *  Trigonometry: '<S143>/Atan'
     */
    rtb_Saturation_k_idx_2 = 0.635 * rtb_Gain1 + rtb_vx;
    rtb_Tnew[1] = rt_atan2d_snf(rtb_Saturation_k_idx_0, rtb_Saturation_k_idx_2)
      - rtb_Abs_l;

    /* Sum: '<S145>/Subtract1' incorporates:
     *  Gain: '<S145>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S144>/Subtract'
     *  Sum: '<S144>/Subtract2'
     *  Sum: '<S146>/Subtract1'
     *  Trigonometry: '<S144>/Atan'
     */
    rtb_Saturation_k_idx_0 = rtU.vy - 0.79560000000000008 * rtb_Gain1;
    rtb_Tnew[2] = rt_atan2d_snf(rtb_Saturation_k_idx_0, rtb_Saturation_k_idx_1);
    rtb_Tnew[3] = rt_atan2d_snf(rtb_Saturation_k_idx_0, rtb_Saturation_k_idx_2);
  } else {
    rtb_Tnew[0] = 0.0;
    rtb_Tnew[1] = 0.0;
    rtb_Tnew[2] = 0.0;
    rtb_Tnew[3] = 0.0;
  }

  /* End of Switch: '<S138>/Switch' */

  /* Lookup_n-D: '<S131>/2-D Lookup Table' */
  rtb_Saturation_k_idx_0 = look2_binlx(rtb_UnaryMinus_d0[0], rtb_Tnew[0],
    rtConstP.pooled44, rtConstP.pooled45, rtConstP.uDLookupTable_tableData_h,
    rtConstP.pooled58, 30U);
  rtb_Saturation_k_idx_1 = look2_binlx(rtb_UnaryMinus_d0[1], rtb_Tnew[1],
    rtConstP.pooled44, rtConstP.pooled45, rtConstP.uDLookupTable_tableData_h,
    rtConstP.pooled58, 30U);
  rtb_Saturation_k_idx_2 = look2_binlx(rtb_UnaryMinus_d0[2], rtb_Tnew[2],
    rtConstP.pooled44, rtConstP.pooled45, rtConstP.uDLookupTable_tableData_h,
    rtConstP.pooled58, 30U);
  rtb_Saturation_k_idx_3 = look2_binlx(rtb_UnaryMinus_d0[3], rtb_Tnew[3],
    rtConstP.pooled44, rtConstP.pooled45, rtConstP.uDLookupTable_tableData_h,
    rtConstP.pooled58, 30U);

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

  /* Switch: '<S125>/Switch' */
  rtb_Saturation1 = !(rtb_Sign > 0.95);

  /* Product: '<S131>/Product' incorporates:
   *  Gain: '<S131>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_k_idx_0 * 20.0;

  /* Saturate: '<S131>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S125>/Product' incorporates:
   *  Constant: '<S11>/Constant6'
   *  MinMax: '<S27>/Min'
   */
  rtb_Product[0] = fmin(fmin(rtb_Braking[0], 21.0), u0) * rtb_Saturation1;

  /* Product: '<S131>/Product' incorporates:
   *  Gain: '<S131>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_k_idx_1 * 20.0;

  /* Saturate: '<S131>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S125>/Product' incorporates:
   *  Constant: '<S11>/Constant6'
   *  MinMax: '<S27>/Min'
   */
  rtb_Product[1] = fmin(fmin(rtb_Braking[1], 21.0), u0) * rtb_Saturation1;

  /* Product: '<S131>/Product' incorporates:
   *  Gain: '<S131>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_k_idx_2 * 20.0;

  /* Saturate: '<S131>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S125>/Product' incorporates:
   *  Constant: '<S11>/Constant6'
   *  MinMax: '<S27>/Min'
   */
  rtb_Product[2] = fmin(fmin(rtb_Braking[2], 21.0), u0) * rtb_Saturation1;

  /* Product: '<S131>/Product' incorporates:
   *  Gain: '<S131>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_k_idx_3 * 20.0;

  /* Saturate: '<S131>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S125>/Product' incorporates:
   *  Constant: '<S11>/Constant6'
   *  MinMax: '<S27>/Min'
   */
  rtb_Product[3] = fmin(fmin(rtb_Braking[3], 21.0), u0) * rtb_Saturation1;

  /* Lookup_n-D: '<S131>/2-D Lookup Table1' */
  rtb_UnaryMinus_d0[0] = look2_binlx(rtb_UnaryMinus_d0[0], rtb_Tnew[0],
    rtConstP.pooled44, rtConstP.pooled45, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled58, 30U);
  rtb_UnaryMinus_d0[1] = look2_binlx(rtb_UnaryMinus_d0[1], rtb_Tnew[1],
    rtConstP.pooled44, rtConstP.pooled45, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled58, 30U);
  rtb_UnaryMinus_d0[2] = look2_binlx(rtb_UnaryMinus_d0[2], rtb_Tnew[2],
    rtConstP.pooled44, rtConstP.pooled45, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled58, 30U);
  rtb_UnaryMinus_d0[3] = look2_binlx(rtb_UnaryMinus_d0[3], rtb_Tnew[3],
    rtConstP.pooled44, rtConstP.pooled45, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled58, 30U);

  /* Product: '<S131>/Product1' incorporates:
   *  Gain: '<S131>/Gain1'
   */
  rtb_Product1[0] = 0.017407407407407406 * rtb_UnaryMinus_d0[0] * 20.0;
  rtb_Product1[1] = 0.017407407407407406 * rtb_UnaryMinus_d0[1] * 20.0;
  rtb_Product1[2] = 0.017407407407407406 * rtb_UnaryMinus_d0[2] * 20.0;
  rtb_Product1[3] = 0.017407407407407406 * rtb_UnaryMinus_d0[3] * 20.0;

  /* Lookup_n-D: '<S154>/Display Overload Motor LUT' */
  rtb_UnaryMinus_d0[0] = rtb_Integrator_c_idx_0;
  rtb_UnaryMinus_d0[1] = rtb_Integrator_c_idx_0;
  rtb_UnaryMinus_d0[2] = rtb_Integrator_c_idx_0;
  rtb_UnaryMinus_d0[3] = rtb_Integrator_c_idx_0;

  /* Lookup_n-D: '<S154>/Display Overload Inverter LUT' */
  rtb_Tnew[0] = rtb_Integrator_c_idx_0;
  rtb_Tnew[1] = rtb_Integrator_c_idx_0;
  rtb_Tnew[2] = rtb_Integrator_c_idx_0;
  rtb_Tnew[3] = rtb_Integrator_c_idx_0;

  /* RelationalOperator: '<S171>/Compare' incorporates:
   *  Constant: '<S168>/Time constant'
   *  Constant: '<S171>/Constant'
   *  Sum: '<S168>/Sum1'
   */
  rtb_Compare_p = (0.079577471545947673 - rtDW.Probe_k[0] <= 0.0);

  /* Saturate: '<S165>/Saturation1' */
  if (z <= 0.0) {
    rtb_Braking[0] = 0.0;
  } else {
    rtb_Braking[0] = z;
  }

  if (Fy_FR <= 0.0) {
    rtb_Braking[1] = 0.0;
  } else {
    rtb_Braking[1] = Fy_FR;
  }

  if (rtb_yrd <= 0.0) {
    rtb_Braking[2] = 0.0;
  } else {
    rtb_Braking[2] = rtb_yrd;
  }

  if (u0_tmp <= 0.0) {
    rtb_Braking[3] = 0.0;
  } else {
    rtb_Braking[3] = u0_tmp;
  }

  /* End of Saturate: '<S165>/Saturation1' */

  /* Lookup_n-D: '<S165>/2-D Lookup Table' incorporates:
   *  Constant: '<S154>/Constant7'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &cumRevIndex);
  fractions_0[1U] = cumRevIndex;
  bpIndices_0[0U] = plook_binc(rtb_Braking[0], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions_0[0U] = cumRevIndex;
  rtb_Braking[0] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Braking[1], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions_0[0U] = cumRevIndex;
  rtb_Braking[1] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Braking[2], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions_0[0U] = cumRevIndex;
  rtb_Braking[2] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Braking[3], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions_0[0U] = cumRevIndex;
  rtb_Braking[3] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);

  /* Gain: '<S165>/Gain' */
  rtb_Saturation_k_idx_0 = 0.0098000000000000014 * rtb_Braking[0];
  rtb_Saturation_k_idx_1 = 0.0098000000000000014 * rtb_Braking[1];
  rtb_Saturation_k_idx_2 = 0.0098000000000000014 * rtb_Braking[2];
  rtb_Saturation_k_idx_3 = 0.0098000000000000014 * rtb_Braking[3];

  /* DiscreteIntegrator: '<S173>/Integrator' */
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

  /* End of DiscreteIntegrator: '<S173>/Integrator' */

  /* MinMax: '<S27>/Min1' incorporates:
   *  Constant: '<S11>/Constant9'
   */
  rtb_Braking[0] = 21.0;
  rtb_Braking[1] = 21.0;
  rtb_Braking[2] = 21.0;
  rtb_Braking[3] = 21.0;

  /* CombinatorialLogic: '<S133>/Logic' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S124>/Constant1'
   *  Memory: '<S133>/Memory'
   *  RelationalOperator: '<S124>/Less Than'
   *  RelationalOperator: '<S124>/Less Than1'
   */
  b_exit = (int32_T)(((((uint32_T)(rtb_Switch <= -0.6) << 1) + (rtb_Switch >=
    -0.5)) << 1) + rtDW.Memory_PreviousInput_f);
  rtb_Logic_idx_0 = rtConstP.pooled61[(uint32_T)b_exit];
  rtb_Logic_idx_1 = rtConstP.pooled61[b_exit + 8U];

  /* CombinatorialLogic: '<S134>/Logic' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S124>/Constant1'
   *  Memory: '<S134>/Memory'
   *  RelationalOperator: '<S124>/Less Than'
   *  RelationalOperator: '<S124>/Less Than1'
   */
  b_exit = (int32_T)(((((uint32_T)(rtb_Switch_b <= -0.6) << 1) + (rtb_Switch_b >=
    -0.5)) << 1) + rtDW.Memory_PreviousInput_j);
  rtb_Logic_d_idx_0 = rtConstP.pooled61[(uint32_T)b_exit];
  rtb_Logic_d_idx_1 = rtConstP.pooled61[b_exit + 8U];

  /* CombinatorialLogic: '<S135>/Logic' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S124>/Constant1'
   *  Memory: '<S135>/Memory'
   *  RelationalOperator: '<S124>/Less Than'
   *  RelationalOperator: '<S124>/Less Than1'
   */
  b_exit = (int32_T)(((((uint32_T)(rtb_RL <= -0.6) << 1) + (rtb_RL >= -0.5)) <<
                      1) + rtDW.Memory_PreviousInput_j4);
  rtb_Logic_o_idx_0 = rtConstP.pooled61[(uint32_T)b_exit];
  rtb_Logic_o_idx_1 = rtConstP.pooled61[b_exit + 8U];

  /* CombinatorialLogic: '<S136>/Logic' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S124>/Constant1'
   *  Memory: '<S136>/Memory'
   *  RelationalOperator: '<S124>/Less Than'
   *  RelationalOperator: '<S124>/Less Than1'
   */
  b_exit = (int32_T)(((((uint32_T)(rtb_RR <= -0.6) << 1) + (rtb_RR >= -0.5)) <<
                      1) + rtDW.Memory_PreviousInput_i);
  rtb_Logic_ds_idx_0 = rtConstP.pooled61[(uint32_T)b_exit];

  /* Product: '<S124>/Product' incorporates:
   *  CombinatorialLogic: '<S136>/Logic'
   */
  rtb_Tnew[0] = rtb_Braking[0] * (real_T)rtb_Logic_idx_1;
  rtb_Tnew[1] = rtb_Braking[1] * (real_T)rtb_Logic_d_idx_1;
  rtb_Tnew[2] = (real_T)rtb_Logic_o_idx_1 * rtb_Braking[2];
  rtb_Tnew[3] = (real_T)rtConstP.pooled61[b_exit + 8U] * rtb_Braking[3];

  /* Outputs for Atomic SubSystem: '<S17>/YRD_LUT_-2' */
  /* Abs: '<S49>/Abs' incorporates:
   *  Abs: '<S152>/Abs'
   */
  rtb_yrd = fabs(rtb_front_wheel_angle_single__d);

  /* End of Outputs for SubSystem: '<S17>/YRD_LUT_-2' */

  /* MATLABSystem: '<S49>/Moving Average' incorporates:
   *  Abs: '<S49>/Abs'
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
  rtb_Saturation1 = 0.0;
  rtb_Integrator_m += rtb_yrd;
  if (modValueRev == 0.0) {
    z = csumrev[(int32_T)cumRevIndex - 1] + rtb_Integrator_m;
  }

  csumrev[(int32_T)cumRevIndex - 1] = rtb_yrd;
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
    rtb_Saturation1 = z / 25.0;
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

  /* CombinatorialLogic: '<S109>/Logic' incorporates:
   *  Abs: '<S49>/Abs'
   *  Constant: '<S49>/Constant1'
   *  Constant: '<S49>/Constant4'
   *  Delay: '<S49>/Delay'
   *  Logic: '<S49>/AND'
   *  MATLABSystem: '<S49>/Moving Average'
   *  Memory: '<S109>/Memory'
   *  RelationalOperator: '<S49>/Less Than'
   *  RelationalOperator: '<S49>/Less Than2'
   */
  rtb_Logic_idx_1 = rtConstP.pooled61[((((uint32_T)(0.017453292519943295 <=
    rtb_yrd) << 1) + ((rtb_Saturation1 < 0.0043633231299858239) &&
                      rtDW.Delay_DSTATE[0])) << 1) + rtDW.Memory_PreviousInput_l];

  /* Outputs for IfAction SubSystem: '<S49>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S108>/Action Port'
   */
  /* If: '<S49>/If' incorporates:
   *  Constant: '<S49>/Constant'
   *  DataTypeConversion: '<S108>/Data Type Conversion'
   *  Logic: '<S49>/AND1'
   *  RelationalOperator: '<S49>/Less Than1'
   */
  rtb_Logic_d_idx_1 = (rtb_Logic_idx_1 && (rtb_vx >= 3.0));

  /* End of Outputs for SubSystem: '<S49>/If Action Subsystem1' */

  /* SignalConversion generated from: '<S128>/ SFunction ' incorporates:
   *  MATLAB Function: '<S27>/Cross Check'
   */
  cumRevIndex = rtb_Tnew[1];

  /* MATLAB Function: '<S27>/Cross Check' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/throttle'
   */
  rtb_Braking[0] = rtb_Tnew[0];
  rtb_Braking[1] = rtb_Tnew[1];
  rtb_Braking[2] = rtb_Tnew[2];
  rtb_Braking[3] = rtb_Tnew[3];
  if (rtb_Logic_d_idx_1) {
    b_exit = 0;
  } else {
    b_exit = 1;
  }

  if (b_exit == 0) {
    if (rtb_Tnew[0] > rtb_Product[0]) {
      rtb_Braking[0] = rtb_Product[0] - cumRevIndex;
    }

    if (rtb_Tnew[1] > rtb_Product[1]) {
      rtb_Braking[1] = rtb_Product[1] - cumRevIndex;
    }

    if (rtb_Tnew[2] > rtb_Product[2]) {
      rtb_Braking[2] = rtb_Product[2] - cumRevIndex;
    }

    if (rtb_Tnew[3] > rtb_Product[3]) {
      rtb_Braking[3] = rtb_Product[3] - cumRevIndex;
    }
  } else if (rtU.throttle > 0.05) {
    rtb_Braking[0] = 0.0;
    rtb_Braking[1] = 0.0;
    rtb_Braking[2] = 0.0;
    rtb_Braking[3] = 0.0;
  } else if (rtU.brake > 0.05) {
    rtb_Product[0] = 0.0;
    rtb_Product[1] = 0.0;
    rtb_Product[2] = 0.0;
    rtb_Product[3] = 0.0;
  }

  /* CFunction: '<S126>/C Function' incorporates:
   *  Constant: '<S126>/Constant3'
   */
  rtDW.CFunction_p[0] = rtb_Braking[0];
  rtDW.CFunction_p[1] = rtb_Braking[1];
  rtDW.CFunction_p[2] = rtb_Braking[2];
  rtDW.CFunction_p[3] = rtb_Braking[3];

  /* CFunction: '<S127>/C Function' incorporates:
   *  Constant: '<S127>/Constant3'
   */
  rtDW.CFunction_f[0] = rtb_Product[0];
  rtDW.CFunction_f[1] = rtb_Product[1];
  rtDW.CFunction_f[2] = rtb_Product[2];
  rtDW.CFunction_f[3] = rtb_Product[3];

  /* Sum: '<S110>/Sum of Elements' */
  rtb_Saturation1 = ((rtDW.CFunction_f[0] + rtDW.CFunction_f[1]) +
                     rtDW.CFunction_f[2]) + rtDW.CFunction_f[3];

  /* Product: '<S110>/Product' incorporates:
   *  Constant: '<S110>/Constant1'
   *  Constant: '<S110>/Constant2'
   *  Constant: '<S117>/Constant'
   *  Constant: '<S117>/Exponent < 0'
   *  Gain: '<S110>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S110>/ '
   *  Math: '<S117>/Power'
   *  Product: '<S110>/Product1'
   *  Product: '<S117>/Divide'
   *  Product: '<S117>/Divide1'
   *  RelationalOperator: '<S110>/Less Than'
   *  RelationalOperator: '<S110>/Less Than1'
   *  Sum: '<S110>/Subtract1'
   *  Sum: '<S117>/Subtract'
   *  Sum: '<S117>/Sum'
   */
  cumRevIndex = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle), -1.5) +
                        1.0) - rtb_Sign) * (real_T)(int8_T)((int8_T)(rtb_Sign >=
    0.05) ^ (int8_T)(rtU.throttle >= 0.05)) * 84.0;

  /* Switch: '<S118>/Switch2' incorporates:
   *  RelationalOperator: '<S118>/LowerRelop1'
   */
  if (!(cumRevIndex > rtb_Saturation1)) {
    /* Sum: '<S110>/Sum of Elements1' */
    rtb_SumofElements1 = ((rtDW.CFunction_p[0] + rtDW.CFunction_p[1]) +
                          rtDW.CFunction_p[2]) + rtDW.CFunction_p[3];

    /* Switch: '<S118>/Switch' incorporates:
     *  RelationalOperator: '<S118>/UpperRelop'
     */
    if (cumRevIndex < rtb_SumofElements1) {
      rtb_Saturation1 = rtb_SumofElements1;
    } else {
      rtb_Saturation1 = cumRevIndex;
    }

    /* End of Switch: '<S118>/Switch' */
  }

  /* End of Switch: '<S118>/Switch2' */

  /* Gain: '<S110>/Gain2' */
  modValueRev = 0.95 * rtb_Saturation1;

  /* Gain: '<S110>/Gain3' */
  z = 1.05 * rtb_Saturation1;

  /* Switch: '<S111>/Switch2' incorporates:
   *  Constant: '<S111>/Engine Brake'
   *  Constant: '<S119>/Constant1'
   *  Constant: '<S119>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S119>/AND'
   *  MinMax: '<S111>/Max1'
   *  RelationalOperator: '<S119>/Less Than'
   *  RelationalOperator: '<S119>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_Sign)) {
    rtb_SumofElements1 = -0.0;
  } else {
    rtb_SumofElements1 = fmin(modValueRev, z);
  }

  /* End of Switch: '<S111>/Switch2' */

  /* UnaryMinus: '<S112>/Unary Minus1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Saturate: '<S112>/Max Regen'
   */
  rtb_Saturation1 = -0.0;

  /* InitialCondition: '<S112>/IC' */
  if (rtDW.IC_FirstOutputTime) {
    rtDW.IC_FirstOutputTime = false;
    rtb_Saturation1 = -35000.0;
  }

  /* End of InitialCondition: '<S112>/IC' */

  /* Product: '<S112>/Divide1' incorporates:
   *  Constant: '<S112>/Constant'
   */
  cumRevIndex = 0.001 * rtb_Saturation1;

  /* MATLAB Function: '<S23>/MATLAB Function4' incorporates:
   *  MATLAB Function: '<S23>/MATLAB Function3'
   *  MATLAB Function: '<S25>/MATLAB Function'
   */
  rtb_Abs_i_idx_0 = 0.765 * sin(rtb_Abs_i_idx_0) - 0.635 * cos(rtb_Abs_i_idx_0);
  rtb_Abs_l = 0.765 * sin(rtb_Abs_l) + 0.635 * cos(rtb_Abs_l);
  rtb_Integrator_m = ((rtb_Abs_i_idx_0 * rtDW.CFunction_p[0] + rtb_Abs_l *
                       rtDW.CFunction_f[1]) - 0.635 * rtDW.CFunction_p[2]) +
    0.635 * rtDW.CFunction_f[3];

  /* Outputs for Atomic SubSystem: '<S17>/YRD_LUT_-2' */
  /* Saturate: '<S152>/Saturation' */
  if (rtb_vx <= 3.0) {
    rtb_Saturation1 = 3.0;
  } else {
    rtb_Saturation1 = rtb_vx;
  }

  /* End of Saturate: '<S152>/Saturation' */

  /* Product: '<S152>/Divide2' incorporates:
   *  Lookup_n-D: '<S152>/LUT_-3'
   *  Product: '<S152>/Divide'
   *  Product: '<S152>/Divide1'
   *  Signum: '<S76>/SignPreIntegrator'
   */
  rtb_yrd = rtb_front_wheel_angle_single__d / rtb_yrd * (look2_binlx(rtb_yrd,
    rtb_Saturation1, rtConstP.LUT_3_bp01Data, rtConstP.LUT_3_bp02Data,
    rtConstP.LUT_3_tableData, rtConstP.LUT_3_maxIndex, 100U) / rtb_Saturation1);

  /* End of Outputs for SubSystem: '<S17>/YRD_LUT_-2' */

  /* SignalConversion generated from: '<S44>/ SFunction ' incorporates:
   *  MATLAB Function: '<S23>/MATLAB Function2'
   */
  rtb_Braking[0] = rtb_Switch;
  rtb_Braking[1] = rtb_Switch_b;
  rtb_Braking[2] = rtb_RL;
  rtb_Braking[3] = rtb_RR;

  /* MATLAB Function: '<S23>/MATLAB Function2' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/vy'
   *  Sum: '<S47>/Sum1'
   *  Sum: '<S47>/Sum2'
   */
  rtb_Switch_b = rtb_UnaryMinus_f_tmp * 3.14825;
  rtb_RL_tmp = rtb_Gain1 * 1.27 / 2.0;
  rtb_RL_tmp_0 = rtb_Gain1 * 0.73439999999999994 + rtU.vy;
  u0 = rtb_vx - rtb_RL_tmp;
  rtb_RL = atan(rtb_RL_tmp_0 / u0) - rtb_front_wheel_angle_single__d;
  rtb_Sign = rtb_RL_tmp + rtb_vx;
  Fy_FR = atan(rtb_RL_tmp_0 / rtb_Sign) - rtb_front_wheel_angle_single__d;
  rtb_RR = rtU.vy - rtb_Gain1 * 0.79560000000000008;
  rtb_Switch = atan(rtb_RR / u0);
  rtb_Saturation1 = atan(rtb_RR / rtb_Sign);
  u0 = 0.5 * rtb_Switch_b * 0.55490196078431375;
  rtb_RR = rtb_UnaryMinus_f_tmp * 1.0461500000000001 * 0.5 / 1.53 * 0.576;
  rtb_Sign = (((635.688 - 30.826771653543307 * rtU.ay) + u0) - rtb_RR) -
    25.588235294117645 * rtU.ax;
  rtb_UnaryMinus_f_tmp = (((30.826771653543307 * rtU.ay + 635.688) + u0) -
    rtb_RR) - 25.588235294117645 * rtU.ax;
  u0_tmp = 0.5 * rtb_Switch_b * 0.4450980392156863;
  rtb_Switch_b = (((688.66200000000015 - 30.826771653543307 * rtU.ay) + u0_tmp)
                  + rtb_RR) + 25.588235294117645 * rtU.ax;
  rtb_RR = (((30.826771653543307 * rtU.ay + 688.66200000000015) + u0_tmp) +
            rtb_RR) + 25.588235294117645 * rtU.ax;
  Faeroz_tmp = 12.4 * rtb_RL - 0.512;
  u_tmp = (1.14E-6 * rtb_Sign - rtb_RL) + 0.00239;
  if (u_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  rtb_RL_tmp_tmp = 0.000282 * rtb_Sign - 2.02;
  rtb_RL_tmp = sin(atan(0.000559 * rtb_Sign) * 2.0) * 34500.0 * u_tmp / (1.34 *
    rtb_Sign * 0.8 * rtb_RL_tmp_tmp - 0.01);
  u0 = 0.0013 * rtb_Sign - 2.33;
  u_tmp = sqrt(Faeroz_tmp * Faeroz_tmp + 1.0);
  rtb_RL_tmp_0 = (3.86E-7 * rtb_Sign + 0.000205) * 13.9 / u_tmp;
  rtb_RL = (sin(atan(rtb_RL_tmp - (0.26 * u0_tmp + 1.0) * (3.99E-5 * rtb_Sign -
    0.521) * (atan(rtb_RL_tmp) - rtb_RL_tmp)) * 1.34) * (rtb_Sign * 0.8) *
            rtb_RL_tmp_tmp + (7.1E-5 * rtb_Sign - 0.149) * (rtb_Sign * 0.8)) *
    cos(atan((atan(((3.86E-7 * rtb_Sign - rtb_Braking[0]) + 0.000205) * 13.9 /
                   u_tmp) - ((3.86E-7 * rtb_Sign - rtb_Braking[0]) + 0.000205) *
              13.9 / sqrt(Faeroz_tmp * Faeroz_tmp + 1.0)) * u0 + ((3.86E-7 *
           rtb_Sign - rtb_Braking[0]) + 0.000205) * 13.9 / sqrt(Faeroz_tmp *
          Faeroz_tmp + 1.0)) * 0.958) / cos(atan((atan(rtb_RL_tmp_0) -
    rtb_RL_tmp_0) * u0 + rtb_RL_tmp_0) * 0.958) - sin(atan(16.1 * rtb_Braking[0])
    * 1.94) * (rtb_Sign * 0.8) * rtb_RL_tmp_tmp * (1.03E-5 * rtb_Sign - 0.000288)
    / sqrt(rtb_RL * rtb_RL * 225.0 + 1.0);
  u0 = 12.4 * Fy_FR - 0.512;
  u_tmp = (1.14E-6 * rtb_UnaryMinus_f_tmp - Fy_FR) + 0.00239;
  if (u_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  rtb_RL_tmp_0 = 0.000282 * rtb_UnaryMinus_f_tmp - 2.02;
  rtb_Sign = sin(atan(0.000559 * rtb_UnaryMinus_f_tmp) * 2.0) * 34500.0 * u_tmp /
    (1.34 * rtb_UnaryMinus_f_tmp * 0.8 * rtb_RL_tmp_0 - 0.01);
  u_tmp = 0.0013 * rtb_UnaryMinus_f_tmp - 2.33;
  rtb_RL_tmp = sqrt(u0 * u0 + 1.0);
  rtb_RL_tmp_tmp = (3.86E-7 * rtb_UnaryMinus_f_tmp + 0.000205) * 13.9 /
    rtb_RL_tmp;
  Fy_FR = (sin(atan(rtb_Sign - (0.26 * u0_tmp + 1.0) * (3.99E-5 *
              rtb_UnaryMinus_f_tmp - 0.521) * (atan(rtb_Sign) - rtb_Sign)) *
               1.34) * (rtb_UnaryMinus_f_tmp * 0.8) * rtb_RL_tmp_0 + (7.1E-5 *
            rtb_UnaryMinus_f_tmp - 0.149) * (rtb_UnaryMinus_f_tmp * 0.8)) * cos
    (atan((atan(((3.86E-7 * rtb_UnaryMinus_f_tmp - rtb_Braking[1]) + 0.000205) *
                13.9 / rtb_RL_tmp) - ((3.86E-7 * rtb_UnaryMinus_f_tmp -
         rtb_Braking[1]) + 0.000205) * 13.9 / sqrt(u0 * u0 + 1.0)) * u_tmp +
          ((3.86E-7 * rtb_UnaryMinus_f_tmp - rtb_Braking[1]) + 0.000205) * 13.9 /
          sqrt(u0 * u0 + 1.0)) * 0.958) / cos(atan((atan(rtb_RL_tmp_tmp) -
    rtb_RL_tmp_tmp) * u_tmp + rtb_RL_tmp_tmp) * 0.958) - sin(atan(16.1 *
    rtb_Braking[1]) * 1.94) * (rtb_UnaryMinus_f_tmp * 0.8) * rtb_RL_tmp_0 *
    (1.03E-5 * rtb_UnaryMinus_f_tmp - 0.000288) / sqrt(Fy_FR * Fy_FR * 225.0 +
    1.0);
  rtb_Sign = 12.4 * rtb_Switch - 0.512;
  u0 = 12.4 * rtb_Saturation1 - 0.512;
  u_tmp = (1.14E-6 * rtb_Switch_b - rtb_Switch) + 0.00239;
  rtb_UnaryMinus_f_tmp = (1.14E-6 * rtb_RR - rtb_Saturation1) + 0.00239;
  if (u_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  if (rtb_UnaryMinus_f_tmp < 0.0) {
    rtb_RL_tmp_0 = -1.0;
  } else if (rtb_UnaryMinus_f_tmp > 0.0) {
    rtb_RL_tmp_0 = 1.0;
  } else if (rtb_UnaryMinus_f_tmp == 0.0) {
    rtb_RL_tmp_0 = 0.0;
  } else {
    rtb_RL_tmp_0 = (rtNaN);
  }

  rtb_RL_tmp = 0.000282 * rtb_Switch_b - 2.02;
  u_tmp = sin(atan(0.000559 * rtb_Switch_b) * 2.0) * 34500.0 * u_tmp / (1.34 *
    rtb_Switch_b * 0.8 * rtb_RL_tmp - 0.01);
  rtb_RL_tmp_tmp = 0.0013 * rtb_Switch_b - 2.33;
  Faeroz_tmp = 0.000282 * rtb_RR - 2.02;
  rtb_Saturation1_tmp = sin(atan(0.000559 * rtb_RR) * 2.0) * 34500.0 *
    rtb_UnaryMinus_f_tmp / (1.34 * rtb_RR * 0.8 * Faeroz_tmp - 0.01);
  rtb_Saturation1_tmp_0 = 0.0013 * rtb_RR - 2.33;
  rtb_UnaryMinus_f_tmp = rtb_yrd - rtb_Gain1;
  rtb_Saturation1_tmp_tmp = sqrt(rtb_Sign * rtb_Sign + 1.0);
  rtb_Saturation1_tmp_1 = (3.86E-7 * rtb_Switch_b + 0.000205) * 13.9 /
    rtb_Saturation1_tmp_tmp;
  rtb_Saturation1_tmp_tmp_0 = sqrt(u0 * u0 + 1.0);
  rtb_Saturation1_tmp_2 = (3.86E-7 * rtb_RR + 0.000205) * 13.9 /
    rtb_Saturation1_tmp_tmp_0;
  rtb_Saturation1 = rtb_UnaryMinus_f_tmp / 0.08 * 180.0 - (((rtb_RL + Fy_FR) *
    cos(rtb_front_wheel_angle_single__d) * 0.73439999999999994 - (((sin(atan
    (u_tmp - (0.26 * u0_tmp + 1.0) * (3.99E-5 * rtb_Switch_b - 0.521) * (atan
    (u_tmp) - u_tmp)) * 1.34) * (rtb_Switch_b * 0.8) * rtb_RL_tmp + (7.1E-5 *
    rtb_Switch_b - 0.149) * (rtb_Switch_b * 0.8)) * cos(atan((atan(((3.86E-7 *
    rtb_Switch_b - rtb_Braking[2]) + 0.000205) * 13.9 / rtb_Saturation1_tmp_tmp)
    - ((3.86E-7 * rtb_Switch_b - rtb_Braking[2]) + 0.000205) * 13.9 / sqrt
    (rtb_Sign * rtb_Sign + 1.0)) * rtb_RL_tmp_tmp + ((3.86E-7 * rtb_Switch_b -
    rtb_Braking[2]) + 0.000205) * 13.9 / sqrt(rtb_Sign * rtb_Sign + 1.0)) *
    0.958) / cos(atan((atan(rtb_Saturation1_tmp_1) - rtb_Saturation1_tmp_1) *
                      rtb_RL_tmp_tmp + rtb_Saturation1_tmp_1) * 0.958) - sin
    (atan(16.1 * rtb_Braking[2]) * 1.94) * (rtb_Switch_b * 0.8) * rtb_RL_tmp *
    (1.03E-5 * rtb_Switch_b - 0.000288) / sqrt(rtb_Switch * rtb_Switch * 225.0 +
    1.0)) + ((sin(atan(rtb_Saturation1_tmp - (0.26 * rtb_RL_tmp_0 + 1.0) *
                       (3.99E-5 * rtb_RR - 0.521) * (atan(rtb_Saturation1_tmp) -
    rtb_Saturation1_tmp)) * 1.34) * (rtb_RR * 0.8) * Faeroz_tmp + (7.1E-5 *
    rtb_RR - 0.149) * (rtb_RR * 0.8)) * cos(atan((atan(((3.86E-7 * rtb_RR -
    rtb_Braking[3]) + 0.000205) * 13.9 / rtb_Saturation1_tmp_tmp_0) - ((3.86E-7 *
    rtb_RR - rtb_Braking[3]) + 0.000205) * 13.9 / sqrt(u0 * u0 + 1.0)) *
    rtb_Saturation1_tmp_0 + ((3.86E-7 * rtb_RR - rtb_Braking[3]) + 0.000205) *
    13.9 / sqrt(u0 * u0 + 1.0)) * 0.958) / cos(atan((atan(rtb_Saturation1_tmp_2)
    - rtb_Saturation1_tmp_2) * rtb_Saturation1_tmp_0 + rtb_Saturation1_tmp_2) *
    0.958) - sin(atan(16.1 * rtb_Braking[3]) * 1.94) * (rtb_RR * 0.8) *
             Faeroz_tmp * (1.03E-5 * rtb_RR - 0.000288) / sqrt(rtb_Saturation1 *
    rtb_Saturation1 * 225.0 + 1.0))) * 0.79560000000000008) + -(Fy_FR - rtb_RL) *
    sin(rtb_front_wheel_angle_single__d) * 1.27 / 2.0);
  if (rtIsNaN(rtb_Saturation1)) {
    rtb_Saturation1 = 0.0;
  }

  /* Logic: '<S23>/NOT1' */
  rtb_Logic_o_idx_1 = !rtb_Logic_d_idx_1;

  /* DiscreteIntegrator: '<S86>/Integrator' */
  if (rtb_Logic_o_idx_1 || (rtDW.Integrator_PrevResetState_i != 0)) {
    rtDW.Integrator_DSTATE_n = 0.0;
  }

  /* DiscreteIntegrator: '<S81>/Filter' */
  if (rtb_Logic_o_idx_1 || (rtDW.Filter_PrevResetState != 0)) {
    rtDW.Filter_DSTATE = 0.0;
  }

  /* Product: '<S89>/NProd Out' incorporates:
   *  Constant: '<S23>/Constant11'
   *  Constant: '<S23>/Constant13'
   *  Constant: '<S23>/Constant14'
   *  DiscreteIntegrator: '<S81>/Filter'
   *  Product: '<S103>/cProd Out'
   *  Product: '<S80>/DProd Out'
   *  Sum: '<S47>/Sum3'
   *  Sum: '<S81>/SumD'
   */
  rtb_front_wheel_angle_single__d = ((rtb_yrd * 0.0 - rtb_Gain1) * 0.0 -
    rtDW.Filter_DSTATE) * 3.0;

  /* Sum: '<S96>/Sum' incorporates:
   *  Constant: '<S23>/Constant12'
   *  DiscreteIntegrator: '<S86>/Integrator'
   *  Product: '<S91>/PProd Out'
   */
  rtb_Switch_b = (rtb_UnaryMinus_f_tmp * 0.0 + rtDW.Integrator_DSTATE_n) +
    rtb_front_wheel_angle_single__d;

  /* Switch: '<S94>/Switch2' incorporates:
   *  Constant: '<S23>/Constant10'
   *  Constant: '<S23>/Constant9'
   *  RelationalOperator: '<S94>/LowerRelop1'
   *  RelationalOperator: '<S94>/UpperRelop'
   *  Switch: '<S94>/Switch'
   */
  if (rtb_Switch_b > 50.0) {
    rtb_Switch = 50.0;
  } else if (rtb_Switch_b < -50.0) {
    /* Switch: '<S94>/Switch' incorporates:
     *  Constant: '<S23>/Constant10'
     */
    rtb_Switch = -50.0;
  } else {
    rtb_Switch = rtb_Switch_b;
  }

  /* End of Switch: '<S94>/Switch2' */

  /* Sum: '<S23>/Sum1' incorporates:
   *  Gain: '<S23>/Gain2'
   */
  u0 = 0.017407407407407406 * rtb_Saturation1 + rtb_Switch;

  /* Saturate: '<S23>/Saturation' */
  if (u0 > 20.0) {
    u0 = 20.0;
  } else if (u0 < -20.0) {
    u0 = -20.0;
  }

  /* End of Saturate: '<S23>/Saturation' */

  /* Product: '<S23>/Product' */
  rtb_Saturation1 = u0 * (real_T)rtb_Logic_d_idx_1;

  /* MATLAB Function: '<S23>/MATLAB Function3' */
  rtb_RR = ((rtb_Abs_i_idx_0 * rtDW.CFunction_f[0] + rtb_Abs_l *
             rtDW.CFunction_p[1]) - 0.635 * rtDW.CFunction_f[2]) + 0.635 *
    rtDW.CFunction_p[3];

  /* Switch: '<S48>/Switch2' incorporates:
   *  RelationalOperator: '<S48>/LowerRelop1'
   */
  if (!(rtb_Saturation1 > rtb_Integrator_m)) {
    /* Switch: '<S48>/Switch' incorporates:
     *  RelationalOperator: '<S48>/UpperRelop'
     */
    if (rtb_Saturation1 < rtb_RR) {
      rtb_Integrator_m = rtb_RR;
    } else {
      rtb_Integrator_m = rtb_Saturation1;
    }

    /* End of Switch: '<S48>/Switch' */
  }

  /* End of Switch: '<S48>/Switch2' */

  /* MATLAB Function: '<S23>/MATLAB Function1' incorporates:
   *  Constant: '<S23>/Constant15'
   *  Inport: '<Root>/throttle'
   *  RelationalOperator: '<S23>/Less Than'
   */
  if (rtb_Integrator_m < 0.0) {
    rtb_RR = -1.0;
  } else if (rtb_Integrator_m > 0.0) {
    rtb_RR = 1.0;
  } else if (rtb_Integrator_m == 0.0) {
    rtb_RR = 0.0;
  } else {
    rtb_RR = (rtNaN);
  }

  if (rtb_RR > 0.0) {
    /* SignalConversion generated from: '<S43>/ SFunction ' incorporates:
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

    rtb_RR = rtb_Integrator_m * rtb_Saturation1;
  } else {
    rtb_RR = rtb_Integrator_m;

    /* SignalConversion generated from: '<S43>/ SFunction ' incorporates:
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

    rtb_Integrator_m *= rtb_Saturation1;
  }

  /* End of MATLAB Function: '<S23>/MATLAB Function1' */

  /* MinMax: '<S111>/Max' */
  modValueRev = fmax(modValueRev, z);

  /* InitialCondition: '<S113>/IC1' */
  rtDW.IC1_FirstOutputTime = false;

  /* Gain: '<S149>/Gain2' incorporates:
   *  Gain: '<S121>/Gain2'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  z = 13.5 * rtU.omega_wheels_FL;

  /* Saturate: '<S149>/Saturation' incorporates:
   *  Gain: '<S149>/Gain2'
   */
  if (z > 2083.9231268812296) {
    rtb_Braking[0] = 2083.9231268812296;
  } else if (z < 10.471975511965978) {
    rtb_Braking[0] = 10.471975511965978;
  } else {
    rtb_Braking[0] = z;
  }

  /* Gain: '<S149>/Gain2' incorporates:
   *  Gain: '<S121>/Gain2'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  Fy_FR = 13.5 * rtU.omega_wheels_FR;

  /* Saturate: '<S149>/Saturation' incorporates:
   *  Gain: '<S149>/Gain2'
   */
  if (Fy_FR > 2083.9231268812296) {
    rtb_Braking[1] = 2083.9231268812296;
  } else if (Fy_FR < 10.471975511965978) {
    rtb_Braking[1] = 10.471975511965978;
  } else {
    rtb_Braking[1] = Fy_FR;
  }

  /* Gain: '<S149>/Gain2' incorporates:
   *  Gain: '<S121>/Gain2'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  rtb_yrd = 13.5 * rtU.omega_wheels_RL;

  /* Saturate: '<S149>/Saturation' incorporates:
   *  Gain: '<S149>/Gain2'
   */
  if (rtb_yrd > 2083.9231268812296) {
    rtb_Braking[2] = 2083.9231268812296;
  } else if (rtb_yrd < 10.471975511965978) {
    rtb_Braking[2] = 10.471975511965978;
  } else {
    rtb_Braking[2] = rtb_yrd;
  }

  /* Gain: '<S149>/Gain2' incorporates:
   *  Gain: '<S121>/Gain2'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0_tmp = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S149>/Saturation' incorporates:
   *  Gain: '<S149>/Gain2'
   */
  if (u0_tmp > 2083.9231268812296) {
    rtb_Braking[3] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Braking[3] = 10.471975511965978;
  } else {
    rtb_Braking[3] = u0_tmp;
  }

  /* Abs: '<S151>/Abs' */
  rtb_Tnew[0] = fabs(rtb_Memory[0]);
  rtb_Tnew[1] = fabs(rtb_Memory[1]);
  rtb_Tnew[2] = fabs(rtb_Memory[2]);
  rtb_Tnew[3] = fabs(rtb_Memory[3]);

  /* Lookup_n-D: '<S151>/2-D Lookup Table' */
  rtb_Braking[0] = look2_binlx(rtb_Braking[0], rtb_Tnew[0], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled59, 200U);
  rtb_Braking[1] = look2_binlx(rtb_Braking[1], rtb_Tnew[1], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled59, 200U);
  rtb_Braking[2] = look2_binlx(rtb_Braking[2], rtb_Tnew[2], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled59, 200U);
  rtb_Braking[3] = look2_binlx(rtb_Braking[3], rtb_Tnew[3], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled59, 200U);

  /* Saturate: '<S151>/Saturation' */
  u0 = rtb_Braking[0];
  if (u0 > 1.0) {
    rtb_Braking[0] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Braking[0] = 0.3;
  } else {
    rtb_Braking[0] = u0;
  }

  u0 = rtb_Braking[1];
  if (u0 > 1.0) {
    rtb_Braking[1] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Braking[1] = 0.3;
  } else {
    rtb_Braking[1] = u0;
  }

  u0 = rtb_Braking[2];
  if (u0 > 1.0) {
    rtb_Braking[2] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Braking[2] = 0.3;
  } else {
    rtb_Braking[2] = u0;
  }

  u0 = rtb_Braking[3];
  if (u0 > 1.0) {
    rtb_Braking[3] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Braking[3] = 0.3;
  } else {
    rtb_Braking[3] = u0;
  }

  /* End of Saturate: '<S151>/Saturation' */

  /* Switch: '<S149>/Switch3' incorporates:
   *  Gain: '<S149>/     '
   *  Gain: '<S149>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Braking[0];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Braking[0];
  }

  if (rtU.omega_wheels_FR > 0.0) {
    rtb_RL = 0.96 * rtb_Braking[1];
  } else {
    rtb_RL = 1.0416666666666667 * rtb_Braking[1];
  }

  if (rtU.omega_wheels_RL > 0.0) {
    rtb_Gain1 = 0.96 * rtb_Braking[2];
  } else {
    rtb_Gain1 = 1.0416666666666667 * rtb_Braking[2];
  }

  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Sign = 0.96 * rtb_Braking[3];
  } else {
    rtb_Sign = 1.0416666666666667 * rtb_Braking[3];
  }

  /* End of Switch: '<S149>/Switch3' */

  /* MATLAB Function: '<S28>/MATLAB Function' incorporates:
   *  Gain: '<S149>/Gain1'
   *  Gain: '<S28>/Gain'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S149>/Product'
   */
  rtb_Tnew[0] = 13.5 * rtU.omega_wheels_FL * rtb_Saturation1 * 0.0;
  rtb_Tnew[1] = 13.5 * rtU.omega_wheels_FR * rtb_RL * 0.0;
  rtb_Tnew[2] = 13.5 * rtU.omega_wheels_RL * rtb_Gain1 * 0.0;
  rtb_Tnew[3] = 13.5 * rtU.omega_wheels_RR * rtb_Sign * 0.0;
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
    X1 = b_exit << 2;
    rtb_y_tmp = b_exit << 3;
    rtb_y[rtb_y_tmp] = rtb_CCaller_o6[X1];
    rtb_y[rtb_y_tmp + 1] = rtb_CCaller_o6[X1 + 1];
    rtb_y[rtb_y_tmp + 2] = rtb_CCaller_o6[X1 + 2];
    rtb_y[rtb_y_tmp + 3] = rtb_CCaller_o6[X1 + 3];
  }

  for (b_exit = 0; b_exit < 4; b_exit++) {
    X1 = b_exit << 2;
    rtb_y_tmp = (b_exit + 4) << 3;
    rtb_y[rtb_y_tmp + 4] = varargin_2[X1];
    rtb_y[rtb_y_tmp + 5] = varargin_2[X1 + 1];
    rtb_y[rtb_y_tmp + 6] = varargin_2[X1 + 2];
    rtb_y[rtb_y_tmp + 7] = varargin_2[X1 + 3];
  }

  for (b_exit = 0; b_exit < 64; b_exit++) {
    rtb_y[b_exit] *= 50.0;
  }

  /* End of MATLAB Function: '<S28>/MATLAB Function' */

  /* Saturate: '<S121>/Saturation' */
  if (z > 2083.9231268812296) {
    rtb_Braking[0] = 2083.9231268812296;
  } else if (z < 10.471975511965978) {
    rtb_Braking[0] = 10.471975511965978;
  } else {
    rtb_Braking[0] = z;
  }

  if (Fy_FR > 2083.9231268812296) {
    rtb_Braking[1] = 2083.9231268812296;
  } else if (Fy_FR < 10.471975511965978) {
    rtb_Braking[1] = 10.471975511965978;
  } else {
    rtb_Braking[1] = Fy_FR;
  }

  if (rtb_yrd > 2083.9231268812296) {
    rtb_Braking[2] = 2083.9231268812296;
  } else if (rtb_yrd < 10.471975511965978) {
    rtb_Braking[2] = 10.471975511965978;
  } else {
    rtb_Braking[2] = rtb_yrd;
  }

  if (u0_tmp > 2083.9231268812296) {
    rtb_Braking[3] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Braking[3] = 10.471975511965978;
  } else {
    rtb_Braking[3] = u0_tmp;
  }

  /* End of Saturate: '<S121>/Saturation' */

  /* Abs: '<S123>/Abs' */
  rtb_Tnew[0] = fabs(rtb_Memory[0]);
  rtb_Tnew[1] = fabs(rtb_Memory[1]);
  rtb_Tnew[2] = fabs(rtb_Memory[2]);
  rtb_Tnew[3] = fabs(rtb_Memory[3]);

  /* Lookup_n-D: '<S123>/2-D Lookup Table' */
  rtb_Braking[0] = look2_binlx(rtb_Braking[0], rtb_Tnew[0], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled59, 200U);
  rtb_Braking[1] = look2_binlx(rtb_Braking[1], rtb_Tnew[1], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled59, 200U);
  rtb_Braking[2] = look2_binlx(rtb_Braking[2], rtb_Tnew[2], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled59, 200U);
  rtb_Braking[3] = look2_binlx(rtb_Braking[3], rtb_Tnew[3], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled59, 200U);

  /* Saturate: '<S123>/Saturation' */
  u0 = rtb_Braking[0];
  if (u0 > 1.0) {
    rtb_Braking[0] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Braking[0] = 0.3;
  } else {
    rtb_Braking[0] = u0;
  }

  u0 = rtb_Braking[1];
  if (u0 > 1.0) {
    rtb_Braking[1] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Braking[1] = 0.3;
  } else {
    rtb_Braking[1] = u0;
  }

  u0 = rtb_Braking[2];
  if (u0 > 1.0) {
    rtb_Braking[2] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Braking[2] = 0.3;
  } else {
    rtb_Braking[2] = u0;
  }

  u0 = rtb_Braking[3];
  if (u0 > 1.0) {
    rtb_Braking[3] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Braking[3] = 0.3;
  } else {
    rtb_Braking[3] = u0;
  }

  /* End of Saturate: '<S123>/Saturation' */

  /* Switch: '<S121>/Switch3' incorporates:
   *  Gain: '<S121>/     '
   *  Gain: '<S121>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Braking[0];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Braking[0];
  }

  /* Abs: '<S121>/Abs' incorporates:
   *  Gain: '<S121>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Product: '<S121>/Divide'
   */
  rtb_Product[0] = fabs(13.5 * rtU.omega_wheels_FL / rtb_Saturation1);

  /* Switch: '<S121>/Switch3' incorporates:
   *  Gain: '<S121>/     '
   *  Gain: '<S121>/      '
   *  Inport: '<Root>/omega_wheels_FR'
   */
  if (rtU.omega_wheels_FR > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Braking[1];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Braking[1];
  }

  /* Abs: '<S121>/Abs' incorporates:
   *  Gain: '<S121>/Gain1'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Product: '<S121>/Divide'
   */
  rtb_Product[1] = fabs(13.5 * rtU.omega_wheels_FR / rtb_Saturation1);

  /* Switch: '<S121>/Switch3' incorporates:
   *  Gain: '<S121>/     '
   *  Gain: '<S121>/      '
   *  Inport: '<Root>/omega_wheels_RL'
   */
  if (rtU.omega_wheels_RL > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Braking[2];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Braking[2];
  }

  /* Abs: '<S121>/Abs' incorporates:
   *  Gain: '<S121>/Gain1'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Product: '<S121>/Divide'
   */
  rtb_Product[2] = fabs(13.5 * rtU.omega_wheels_RL / rtb_Saturation1);

  /* Switch: '<S121>/Switch3' incorporates:
   *  Gain: '<S121>/     '
   *  Gain: '<S121>/      '
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Saturation1 = 0.96 * rtb_Braking[3];
  } else {
    rtb_Saturation1 = 1.0416666666666667 * rtb_Braking[3];
  }

  /* Abs: '<S121>/Abs' incorporates:
   *  Gain: '<S121>/Gain1'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S121>/Divide'
   */
  rtb_Product[3] = fabs(13.5 * rtU.omega_wheels_RR / rtb_Saturation1);

  /* Gain: '<S24>/Gain' incorporates:
   *  Sum: '<S24>/Sum'
   */
  z = (modValueRev + rtb_SumofElements1) * 0.5;

  /* Chart: '<S116>/Distribution complete' incorporates:
   *  SignalConversion generated from: '<S120>/ SFunction '
   */
  if (z >= 0.0) {
    rtb_RL = z;
    rtb_Braking[0] = rtDW.CFunction_f[1];
    rtb_Braking[1] = rtDW.CFunction_f[3];
    rtb_Braking[2] = rtDW.CFunction_f[0];
    rtb_Braking[3] = rtDW.CFunction_f[2];
    rtb_UnaryMinus_d0[0] = rtDW.CFunction_p[1];
    rtb_UnaryMinus_d0[1] = rtDW.CFunction_p[3];
    rtb_UnaryMinus_d0[2] = rtDW.CFunction_p[0];
    rtb_UnaryMinus_d0[3] = rtDW.CFunction_p[2];
    Fy_FR = rtb_Integrator_m;
  } else {
    rtb_RL = -z;
    rtb_Braking[0] = -rtDW.CFunction_p[1];
    rtb_Braking[1] = -rtDW.CFunction_p[3];
    rtb_Braking[2] = -rtDW.CFunction_p[0];
    rtb_Braking[3] = -rtDW.CFunction_p[2];
    rtb_UnaryMinus_d0[0] = -rtDW.CFunction_f[1];
    rtb_UnaryMinus_d0[1] = -rtDW.CFunction_f[3];
    rtb_UnaryMinus_d0[2] = -rtDW.CFunction_f[0];
    rtb_UnaryMinus_d0[3] = -rtDW.CFunction_f[2];
    Fy_FR = -rtb_Integrator_m;
  }

  if (Fy_FR < 0.0) {
    rtb_Gain1 = rtb_Braking[2];
    rtb_Saturation1 = rtb_Braking[3];
    rtb_yrd = rtb_Braking[0];
    u0_tmp = rtb_Braking[1];
    rtb_Braking[0] = rtb_Gain1;
    rtb_Braking[1] = rtb_Saturation1;
    rtb_Braking[2] = rtb_yrd;
    rtb_Braking[3] = u0_tmp;
    rtb_Gain1 = rtb_UnaryMinus_d0[2];
    rtb_Saturation1 = rtb_UnaryMinus_d0[3];
    rtb_yrd = rtb_UnaryMinus_d0[0];
    u0_tmp = rtb_UnaryMinus_d0[1];
    rtb_UnaryMinus_d0[0] = rtb_Gain1;
    rtb_UnaryMinus_d0[1] = rtb_Saturation1;
    rtb_UnaryMinus_d0[2] = rtb_yrd;
    rtb_UnaryMinus_d0[3] = u0_tmp;
  }

  for (X1 = 0; X1 < 4; X1++) {
    rtb_Braking_0[X1] = rtb_Braking[X1];
  }

  for (X1 = 0; X1 < 4; X1++) {
    rtb_UnaryMinus_f[X1] = rtb_UnaryMinus_d0[X1];
  }

  BaseDistribution(rtb_RL, rtb_Braking_0, rtb_UnaryMinus_f, fabs(Fy_FR),
                   rtb_Tnew);
  if (!(z >= 0.0)) {
    rtb_Braking_0[0] = -rtb_Tnew[0];
    rtb_Braking_0[1] = -rtb_Tnew[1];
    rtb_Braking_0[2] = -rtb_Tnew[2];
    rtb_Braking_0[3] = -rtb_Tnew[3];
    assignBrakeTorque(rtb_Braking_0, rtb_Tnew);
  }

  if (Fy_FR < 0.0) {
    rtb_RL = rtb_Tnew[2];
    rtb_Gain1 = rtb_Tnew[3];
    z = rtb_Tnew[0];
    rtb_Saturation1 = rtb_Tnew[1];
    rtb_Tnew[0] = rtb_RL;
    rtb_Tnew[1] = rtb_Gain1;
    rtb_Tnew[2] = z;
    rtb_Tnew[3] = rtb_Saturation1;
  }

  /* End of Chart: '<S116>/Distribution complete' */

  /* CCaller: '<S16>/C Caller' incorporates:
   *  CFunction: '<S126>/C Function'
   *  CFunction: '<S127>/C Function'
   *  CFunction: '<S29>/C Function'
   *  Constant: '<S21>/Constant'
   *  UnaryMinus: '<S21>/Unary Minus'
   */
  memcpy(&rtb_CCaller_o3[0], &rtDW.CFunction[0], 26U * sizeof(real_T));
  rtb_Braking[0] = -10000.0;
  rtb_Braking[1] = -10000.0;
  rtb_Braking[2] = -10000.0;
  rtb_Braking[3] = -10000.0;
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

  /* Abs: '<S115>/Abs1' incorporates:
   *  Abs: '<S114>/Abs1'
   */
  z = fabs(rtb_Memory[1]);

  /* Abs: '<S115>/Abs3' incorporates:
   *  Abs: '<S114>/Abs3'
   */
  rtb_RL = fabs(rtb_Memory[0]);

  /* CCaller: '<S16>/C Caller' incorporates:
   *  Abs: '<S115>/Abs1'
   *  Abs: '<S115>/Abs3'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S26>/Constant'
   *  MATLAB Function: '<S25>/MATLAB Function'
   *  Saturate: '<S112>/Saturation'
   *  SignalConversion generated from: '<S16>/C Caller'
   *  UnaryMinus: '<S115>/Unary Minus'
   *  UnaryMinus: '<S115>/Unary Minus1'
   * */
  rtb_CCaller_o9[0] = rtb_SumofElements1;
  rtb_CCaller_o9[1] = cumRevIndex;
  rtb_CCaller_o9[2] = -z;
  rtb_CCaller_o9[3] = -rtb_RL;
  rtb_CCaller_o9[4] = rtb_RR;
  rtb_CCaller_o10[0] = modValueRev;
  rtb_CCaller_o10[1] = 80.0;
  rtb_CCaller_o10[2] = z;
  rtb_CCaller_o10[3] = rtb_RL;
  rtb_CCaller_o10[4] = rtb_Integrator_m;
  rtb_CCaller_o12[0] = 1.0;
  rtb_CCaller_o12[5] = 1.0;
  rtb_CCaller_o12[10] = 1.0;
  rtb_CCaller_o12[15] = 1.0;
  rtb_CCaller_o12[1] = rtb_Product[0] / 1000.0;
  rtb_CCaller_o12[6] = rtb_Product[1] / 1000.0;
  rtb_CCaller_o12[11] = rtb_Product[2] / 1000.0;
  rtb_CCaller_o12[16] = rtb_Product[3] / 1000.0;
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
  rtb_Product[0] = rtb_Tnew[2];
  rtb_Product[1] = rtb_Tnew[0];
  rtb_Product[2] = rtb_Tnew[3];
  rtb_Product[3] = rtb_Tnew[1];
  rtb_Tnew[0] = 0.0;
  rtb_Tnew[1] = 0.0;
  rtb_Tnew[2] = 0.0;
  rtb_Tnew[3] = 0.0;

  /* CCaller: '<S16>/C Caller' */
  X1 = Acados_Caller_wrapper(&rtb_Memory[0], &rtb_CCaller_o3[0], &rtb_Braking[0],
    &rtb_UnaryMinus_d0[0], &rtb_CCaller_o6[0], &rtb_Product1[0],
    &rtb_CCaller_o8[0], &rtb_CCaller_o9[0], &rtb_CCaller_o10[0], &rtb_y[0],
    &rtb_CCaller_o12[0], &rtb_CCaller_o13[0], &rtb_CCaller_o14[0], &rtb_Product
    [0], &rtb_Tnew[0]);

  /* DiscreteFir: '<S33>/Discrete FIR Filter' */
  acc1 = (int64_T)X1 << 30;
  for (b_exit = rtDW.DiscreteFIRFilter_circBuf; b_exit < 4; b_exit++) {
    acc1 += (int64_T)rtDW.DiscreteFIRFilter_states[b_exit] << 30;
  }

  for (b_exit = 0; b_exit < rtDW.DiscreteFIRFilter_circBuf; b_exit++) {
    acc1 += (int64_T)rtDW.DiscreteFIRFilter_states[b_exit] << 30;
  }

  /* End of DiscreteFir: '<S33>/Discrete FIR Filter' */

  /* Switch: '<S33>/Switch' */
  if ((rtb_vx > 3.0) && (!((real_T)acc1 * 9.3132257461547852E-10 >= 4.0))) {
  } else {
    /* Outputs for IfAction SubSystem: '<S22>/Vectorino' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* If: '<S22>/If' incorporates:
     *  Constant: '<S41>/Constant2'
     *  Inport: '<Root>/throttle'
     *  Product: '<S41>/Product'
     */
    rtb_Tnew[0] = rtU.throttle * 6.3;
    rtb_Tnew[1] = rtU.throttle * 6.3;
    rtb_Tnew[2] = rtU.throttle * 21.0;
    rtb_Tnew[3] = rtU.throttle * 21.0;

    /* End of Outputs for SubSystem: '<S22>/Vectorino' */
  }

  /* End of Switch: '<S33>/Switch' */

  /* RelationalOperator: '<S22>/Less Than3' incorporates:
   *  DataStoreRead: '<S22>/Data Store General_Params1'
   *  Inport: '<Root>/brake'
   */
  rtb_Logic_d_idx_1 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S22>/Overlap Chart' incorporates:
   *  Inport: '<Root>/throttle'
   */
  if (rtDW.is_active_c13_TVModel == 0U) {
    rtDW.is_active_c13_TVModel = 1U;
    rtDW.is_c13_TVModel = IN_Go;
  } else if (rtDW.is_c13_TVModel == 1) {
    if (rtb_Logic_d_idx_1) {
      rtDW.is_c13_TVModel = IN_Stop;
    }

    /* case IN_Stop: */
  } else if (((real_T)rtb_Logic_d_idx_1 <= 0.05) && (rtU.throttle < 0.05)) {
    rtDW.is_c13_TVModel = IN_Go;
  }

  /* End of Chart: '<S22>/Overlap Chart' */

  /* Switch: '<S79>/Switch' incorporates:
   *  Constant: '<S23>/Constant10'
   *  Constant: '<S23>/Constant9'
   *  RelationalOperator: '<S79>/u_GTE_up'
   *  RelationalOperator: '<S79>/u_GT_lo'
   *  Switch: '<S79>/Switch1'
   */
  if (rtb_Switch_b >= 50.0) {
    rtb_vx = 50.0;
  } else if (rtb_Switch_b > -50.0) {
    /* Switch: '<S79>/Switch1' */
    rtb_vx = rtb_Switch_b;
  } else {
    rtb_vx = -50.0;
  }

  /* End of Switch: '<S79>/Switch' */

  /* Sum: '<S79>/Diff' */
  rtb_vx = rtb_Switch_b - rtb_vx;

  /* RelationalOperator: '<S76>/NotEqual' incorporates:
   *  Gain: '<S76>/ZeroGain'
   */
  rtb_Logic_d_idx_1 = (0.0 * rtb_Switch_b != rtb_vx);

  /* Signum: '<S76>/SignPreSat' */
  if (rtb_vx < 0.0) {
    rtb_Sign = -1.0;
  } else if (rtb_vx > 0.0) {
    rtb_Sign = 1.0;
  } else if (rtb_vx == 0.0) {
    rtb_Sign = 0.0;
  } else {
    rtb_Sign = (rtNaN);
  }

  /* End of Signum: '<S76>/SignPreSat' */

  /* Sum: '<S99>/SumI1' incorporates:
   *  Constant: '<S23>/Const10ant15'
   *  Gain: '<S98>/Kt'
   *  Product: '<S83>/IProd Out'
   *  Sum: '<S98>/SumI3'
   */
  rtb_vx = (rtb_Switch - rtb_Switch) * 100.0 + rtb_UnaryMinus_f_tmp * 20.0;

  /* Signum: '<S76>/SignPreIntegrator' */
  if (rtb_vx < 0.0) {
    rtb_Switch = -1.0;
  } else if (rtb_vx > 0.0) {
    rtb_Switch = 1.0;
  } else if (rtb_vx == 0.0) {
    rtb_Switch = 0.0;
  } else {
    rtb_Switch = (rtNaN);
  }

  /* End of Signum: '<S76>/SignPreIntegrator' */

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/Constant1'
   *  DataTypeConversion: '<S76>/DataTypeConv1'
   *  DataTypeConversion: '<S76>/DataTypeConv2'
   *  Logic: '<S76>/AND3'
   *  RelationalOperator: '<S76>/Equal1'
   */
  if (rtb_Logic_d_idx_1 && ((int8_T)rtb_Sign == (int8_T)rtb_Switch)) {
    rtb_Gain1 = 0.0;
  } else {
    rtb_Gain1 = rtb_vx;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Chart: '<S23>/Chart' */
  rtDW.chartGlobalTickCounter++;
  rtb_Logic_d_idx_1 = (rtDW.is_c24_TVModel == 3);
  if ((!rtb_Logic_d_idx_1) || (!rtDW.countCondWasTrueAtLastTimeStep_)) {
    rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
  }

  rtDW.countCondWasTrueAtLastTimeStep_ = rtb_Logic_d_idx_1;
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
      rtb_Logic_d_idx_1 = (rtDW.is_c24_TVModel == 3);
      if ((!rtb_Logic_d_idx_1) || (!rtDW.countCondWasTrueAtLastTimeStep_)) {
        rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
      }

      rtDW.countCondWasTrueAtLastTimeStep_ = rtb_Logic_d_idx_1;
      if (rtDW.chartGlobalTickCounter - rtDW.countReferenceTick_1 > 10) {
        rtDW.is_c24_TVModel = IN_OFF;
        rtDW.mz_output = 0.0;
      } else {
        rtDW.mz_output *= mz_filter_tau;
      }
      break;
    }
  }

  /* End of Chart: '<S23>/Chart' */

  /* RelationalOperator: '<S155>/Less Than' incorporates:
   *  DataStoreRead: '<S155>/Data Store General_Params'
   *  Inport: '<Root>/brake'
   */
  rtb_Logic_d_idx_1 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S155>/T_Req_Chart' */
  guard1 = false;
  guard2 = false;
  if (rtDW.is_active_c21_TVModel == 0U) {
    rtDW.is_active_c21_TVModel = 1U;
    rtDW.is_c21_TVModel = IN_Throttle;
    rtb_yrd = 0.0;
    guard1 = true;
  } else if (rtDW.is_c21_TVModel == 1) {
    if ((!rtb_Logic_d_idx_1) && (rtU.throttle < 0.05)) {
      rtDW.is_c21_TVModel = IN_Throttle;
      rtb_yrd = 0.0;
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    /* case IN_Throttle: */
    rtb_yrd = 0.0;
    if (rtb_Logic_d_idx_1) {
      rtDW.is_c21_TVModel = IN_Brake;
      guard2 = true;
    } else {
      guard1 = true;
    }
  }

  if (guard2) {
    /* SignalConversion generated from: '<S175>/1-D Lookup Table' incorporates:
     *  Constant: '<S175>/Constant'
     *  DataStoreRead: '<S175>/Data Store Read'
     *  Switch: '<S155>/Switch'
     */
    fractions[0] = rtDW.General_Params.BrakeThresh;
    fractions[1] = 1.0;

    /* Lookup_n-D: '<S175>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/brake'
     *  Switch: '<S155>/Switch'
     */
    u0 = look1_binlx(rtU.brake, fractions, rtConstP.uDLookupTable_tableData, 1U);

    /* Saturate: '<S175>/Saturation_Brake' incorporates:
     *  Switch: '<S155>/Switch'
     */
    if (u0 > 1.0) {
      u0 = 1.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    /* End of Saturate: '<S175>/Saturation_Brake' */

    /* Switch: '<S155>/Switch' incorporates:
     *  Gain: '<S175>/Gain_Max_Torque_Needed'
     */
    rtb_yrd = -529.2 * u0;
  }

  if (guard1) {
    /* Switch: '<S174>/Switch' incorporates:
     *  DataStoreRead: '<S174>/Data Store General_Params1'
     *  Inport: '<Root>/throttle'
     *  RelationalOperator: '<S174>/Less Than'
     *  Switch: '<S155>/Switch'
     */
    if (rtU.throttle > rtDW.General_Params.ThrottleThresh) {
      /* SignalConversion generated from: '<S174>/T_nominal_wheel_LUT' incorporates:
       *  Constant: '<S174>/Constant1'
       *  Constant: '<S174>/Constant2'
       *  DataStoreRead: '<S174>/Data Store General_Params'
       */
      rtb_CCaller_o13[0] = 0.0;
      rtb_CCaller_o13[1] = rtDW.General_Params.ThrottleThresh;
      rtb_CCaller_o13[2] = 1.0;

      /* MultiPortSwitch: '<S174>/Map_Selector' incorporates:
       *  Lookup_n-D: '<S174>/T_peak_wheel_LUT'
       */
      rtb_yrd = look1_binlx(rtU.throttle, rtb_CCaller_o13,
                            rtConstP.T_peak_wheel_LUT_tableData, 2U);
    }

    /* End of Switch: '<S174>/Switch' */
  }

  /* End of Chart: '<S155>/T_Req_Chart' */

  /* MATLABSystem: '<S155>/Moving Average' */
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
  rtb_Memory[0] = obj_0->pCumSumRev[0];
  rtb_Memory[1] = obj_0->pCumSumRev[1];
  rtb_Memory[2] = obj_0->pCumSumRev[2];
  rtb_Memory[3] = obj_0->pCumSumRev[3];
  modValueRev = obj_0->pModValueRev;
  rtb_Integrator_m += rtb_yrd;
  rtb_Memory[(int32_T)cumRevIndex - 1] = rtb_yrd;
  if (cumRevIndex != 4.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    rtb_Integrator_m = 0.0;
    rtb_Memory[2] += rtb_Memory[3];
    rtb_Memory[1] += rtb_Memory[2];
    rtb_Memory[0] += rtb_Memory[1];
  }

  obj_0->pCumSum = rtb_Integrator_m;
  obj_0->pCumSumRev[0] = rtb_Memory[0];
  obj_0->pCumSumRev[1] = rtb_Memory[1];
  obj_0->pCumSumRev[2] = rtb_Memory[2];
  obj_0->pCumSumRev[3] = rtb_Memory[3];
  obj_0->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj_0->pModValueRev = modValueRev - 1.0;
  } else {
    obj_0->pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S155>/Moving Average' */

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[0] = rtDW.UnitDelay_DSTATE_j[0];
  rtDW.UnitDelay_DSTATE[1] = rtDW.UnitDelay_DSTATE_j[1];
  rtDW.UnitDelay_DSTATE[2] = rtDW.UnitDelay_DSTATE_j[2];
  rtDW.UnitDelay_DSTATE[3] = rtDW.UnitDelay_DSTATE_j[3];

  /* Update for Memory: '<S16>/Memory' incorporates:
   *  Product: '<S22>/Divide'
   */
  rtDW.Memory_PreviousInput[0] = rtb_Tnew[0];
  rtDW.Memory_PreviousInput[1] = rtb_Tnew[1];
  rtDW.Memory_PreviousInput[2] = rtb_Tnew[2];
  rtDW.Memory_PreviousInput[3] = rtb_Tnew[3];

  /* Update for DiscreteIntegrator: '<S164>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S157>/1//T' incorporates:
   *  Constant: '<S159>/Time constant'
   *  MinMax: '<S159>/Max'
   */
  rtb_Saturation1 = 1.0 / fmax(rtDW.Probe[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S164>/Integrator' */
  rtDW.Integrator_PrevResetState = (int8_T)rtb_Compare;

  /* Update for DiscreteIntegrator: '<S173>/Integrator' */
  rtDW.Integrator_IC_LOADING_j = 0U;

  /* Product: '<S166>/1//T' incorporates:
   *  Constant: '<S168>/Time constant'
   *  MinMax: '<S168>/Max'
   */
  rtb_RL = 1.0 / fmax(rtDW.Probe_k[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S173>/Integrator' */
  rtDW.Integrator_PrevResetState_b = (int8_T)rtb_Compare_p;

  /* Update for Memory: '<S133>/Memory' */
  rtDW.Memory_PreviousInput_f = rtb_Logic_idx_0;

  /* Update for Memory: '<S134>/Memory' */
  rtDW.Memory_PreviousInput_j = rtb_Logic_d_idx_0;

  /* Update for Memory: '<S135>/Memory' */
  rtDW.Memory_PreviousInput_j4 = rtb_Logic_o_idx_0;

  /* Update for Memory: '<S136>/Memory' */
  rtDW.Memory_PreviousInput_i = rtb_Logic_ds_idx_0;

  /* Update for DiscreteIntegrator: '<S164>/Integrator' incorporates:
   *  Product: '<S157>/1//T'
   *  Sum: '<S157>/Sum1'
   */
  rtDW.Integrator_DSTATE[0] += (rtb_Gain_idx_0 - rtb_Integrator_idx_0) *
    rtb_Saturation1 * 0.02;

  /* Update for DiscreteIntegrator: '<S173>/Integrator' incorporates:
   *  Product: '<S166>/1//T'
   *  Sum: '<S166>/Sum1'
   */
  rtDW.Integrator_DSTATE_f[0] += (rtb_Saturation_k_idx_0 -
    rtb_Integrator_c_idx_0) * rtb_RL * 0.02;

  /* Update for Delay: '<S49>/Delay' */
  rtDW.Delay_DSTATE[0] = rtDW.Delay_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S164>/Integrator' incorporates:
   *  Product: '<S157>/1//T'
   *  Sum: '<S157>/Sum1'
   */
  rtDW.Integrator_DSTATE[1] += (rtb_Gain_idx_1 - rtb_Integrator_idx_1) *
    rtb_Saturation1 * 0.02;

  /* Update for DiscreteIntegrator: '<S173>/Integrator' incorporates:
   *  Product: '<S166>/1//T'
   *  Sum: '<S166>/Sum1'
   */
  rtDW.Integrator_DSTATE_f[1] += (rtb_Saturation_k_idx_1 -
    rtb_Integrator_c_idx_1) * rtb_RL * 0.02;

  /* Update for Delay: '<S49>/Delay' */
  rtDW.Delay_DSTATE[1] = rtDW.Delay_DSTATE[2];

  /* Update for DiscreteIntegrator: '<S164>/Integrator' incorporates:
   *  Product: '<S157>/1//T'
   *  Sum: '<S157>/Sum1'
   */
  rtDW.Integrator_DSTATE[2] += (rtb_Gain_idx_2 - rtb_Integrator_idx_2) *
    rtb_Saturation1 * 0.02;

  /* Update for DiscreteIntegrator: '<S173>/Integrator' incorporates:
   *  Product: '<S166>/1//T'
   *  Sum: '<S166>/Sum1'
   */
  rtDW.Integrator_DSTATE_f[2] += (rtb_Saturation_k_idx_2 -
    rtb_Integrator_c_idx_2) * rtb_RL * 0.02;

  /* Update for Delay: '<S49>/Delay' */
  rtDW.Delay_DSTATE[2] = rtDW.Delay_DSTATE[3];

  /* Update for DiscreteIntegrator: '<S164>/Integrator' incorporates:
   *  Product: '<S157>/1//T'
   *  Sum: '<S157>/Sum1'
   */
  rtDW.Integrator_DSTATE[3] += (rtb_Gain_idx_3 - rtb_Integrator_idx_3) *
    rtb_Saturation1 * 0.02;

  /* Update for DiscreteIntegrator: '<S173>/Integrator' incorporates:
   *  Product: '<S166>/1//T'
   *  Sum: '<S166>/Sum1'
   */
  rtDW.Integrator_DSTATE_f[3] += (rtb_Saturation_k_idx_3 -
    rtb_Integrator_c_idx_3) * rtb_RL * 0.02;

  /* Update for Delay: '<S49>/Delay' */
  rtDW.Delay_DSTATE[3] = rtDW.Delay_DSTATE[4];
  rtDW.Delay_DSTATE[4] = rtb_Logic_idx_1;

  /* Update for Memory: '<S109>/Memory' */
  rtDW.Memory_PreviousInput_l = rtb_Logic_idx_1;

  /* Update for DiscreteIntegrator: '<S86>/Integrator' */
  rtDW.Integrator_DSTATE_n += 0.02 * rtb_Gain1;
  rtDW.Integrator_PrevResetState_i = (int8_T)rtb_Logic_o_idx_1;

  /* Update for DiscreteIntegrator: '<S81>/Filter' incorporates:
   *  DiscreteIntegrator: '<S86>/Integrator'
   */
  rtDW.Filter_DSTATE += 0.02 * rtb_front_wheel_angle_single__d;
  rtDW.Filter_PrevResetState = (int8_T)rtb_Logic_o_idx_1;

  /* Update for DiscreteFir: '<S33>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf] = X1;

  /* End of Update for DiscreteFir: '<S33>/Discrete FIR Filter' */

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
  rtY.Torque[0] = rtb_Tnew[0];
  rtY.Torque[1] = rtb_Tnew[1];
  rtY.Torque[2] = rtb_Tnew[2];
  rtY.Torque[3] = rtb_Tnew[3];
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
    /* Start for Probe: '<S159>/Probe' */
    rtDW.Probe[0] = 0.02;
    rtDW.Probe[1] = 0.0;

    /* Start for Probe: '<S168>/Probe' */
    rtDW.Probe_k[0] = 0.02;
    rtDW.Probe_k[1] = 0.0;

    /* Start for InitialCondition: '<S112>/IC' */
    rtDW.IC_FirstOutputTime = true;

    /* Start for InitialCondition: '<S113>/IC1' */
    rtDW.IC1_FirstOutputTime = true;

    /* Start for DataStoreMemory: '<S3>/Data Store_General_Params' */
    rtDW.General_Params = rtConstP.DataStore_General_Params_Initia;

    /* InitializeConditions for DiscreteIntegrator: '<S164>/Integrator' */
    rtDW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S173>/Integrator' */
    rtDW.Integrator_IC_LOADING_j = 1U;

    /* SystemInitialize for Chart: '<S116>/Distribution complete' */
    rtDW.tr = 1.27;
    rtDW.Rw = 0.235;

    /* Start for MATLABSystem: '<S49>/Moving Average' */
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

    /* InitializeConditions for MATLABSystem: '<S49>/Moving Average' */
    iobj_0 = rtDW.obj.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum = 0.0;
      for (i = 0; i < 24; i++) {
        iobj_0->pCumSumRev[i] = 0.0;
      }

      iobj_0->pCumRevIndex = 1.0;
      iobj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S49>/Moving Average' */

    /* Start for MATLABSystem: '<S155>/Moving Average' */
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

    /* InitializeConditions for MATLABSystem: '<S155>/Moving Average' */
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

    /* End of InitializeConditions for MATLABSystem: '<S155>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
