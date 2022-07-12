/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jul 12 18:16:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TVModel.h"

/* Named constants for Chart: '<S165>/Overlap Chart' */
#define IN_Go                          ((uint8_T)1U)
#define IN_Stop                        ((uint8_T)2U)
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
static void MATLABFunction(const real_T rtu_u[4], real_T rty_y[4]);

/* Forward declaration for local functions */
static void interp2(const real_T varargin_1[20], const real_T varargin_2[200],
                    const real_T varargin_3[4000], const real_T varargin_4[4],
                    const real_T varargin_5[4], real_T Vq[4]);
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

/*
 * Output and update for atomic system:
 *    '<S171>/MATLAB Function'
 *    '<S171>/MATLAB Function1'
 */
static void MATLABFunction(const real_T rtu_u[4], real_T rty_y[4])
{
  rty_y[0] = rtu_u[0];
  rty_y[1] = rtu_u[1];
  rty_y[2] = rtu_u[2];
  rty_y[3] = rtu_u[3];
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

/* Function for MATLAB Function: '<S181>/MATLAB Function' */
static void interp2(const real_T varargin_1[20], const real_T varargin_2[200],
                    const real_T varargin_3[4000], const real_T varargin_4[4],
                    const real_T varargin_5[4], real_T Vq[4])
{
  real_T qx1;
  real_T rx;
  real_T ry;
  int32_T b_low_ip1;
  int32_T b_mid_i;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  if (varargin_4[0] >= varargin_1[0]) {
    if (varargin_4[0] <= varargin_1[19]) {
      if (varargin_5[0] >= varargin_2[0]) {
        if (varargin_5[0] <= varargin_2[199]) {
          high_i = 20;
          low_i = 0;
          low_ip1 = 2;
          while (high_i > low_ip1) {
            b_low_ip1 = ((low_i + high_i) + 1) >> 1;
            if (varargin_4[0] >= varargin_1[b_low_ip1 - 1]) {
              low_i = b_low_ip1 - 1;
              low_ip1 = b_low_ip1 + 1;
            } else {
              high_i = b_low_ip1;
            }
          }

          high_i = 200;
          low_ip1 = 1;
          b_low_ip1 = 2;
          while (high_i > b_low_ip1) {
            b_mid_i = (low_ip1 + high_i) >> 1;
            if (varargin_5[0] >= varargin_2[b_mid_i - 1]) {
              low_ip1 = b_mid_i;
              b_low_ip1 = b_mid_i + 1;
            } else {
              high_i = b_mid_i;
            }
          }

          if (varargin_4[0] == varargin_1[low_i]) {
            low_i = 200 * low_i + low_ip1;
            qx1 = varargin_3[low_i - 1];
            rx = varargin_3[low_i];
          } else {
            ry = varargin_1[low_i + 1];
            if (ry == varargin_4[0]) {
              low_i = (low_i + 1) * 200 + low_ip1;
              qx1 = varargin_3[low_i - 1];
              rx = varargin_3[low_i];
            } else {
              rx = (varargin_4[0] - varargin_1[low_i]) / (ry - varargin_1[low_i]);
              ry = varargin_3[((low_i + 1) * 200 + low_ip1) - 1];
              high_i = (200 * low_i + low_ip1) - 1;
              qx1 = varargin_3[high_i];
              if (ry == qx1) {
                qx1 = varargin_3[high_i];
              } else {
                qx1 = (1.0 - rx) * qx1 + ry * rx;
              }

              high_i = (low_i + 1) * 200 + low_ip1;
              low_i = 200 * low_i + low_ip1;
              if (varargin_3[high_i] == varargin_3[low_i]) {
                rx = varargin_3[low_i];
              } else {
                rx = (1.0 - rx) * varargin_3[low_i] + varargin_3[high_i] * rx;
              }
            }
          }

          ry = varargin_2[low_ip1 - 1];
          if (ry == varargin_5[0]) {
            Vq[0] = qx1;
          } else if (qx1 == rx) {
            Vq[0] = qx1;
          } else if (varargin_5[0] == varargin_2[low_ip1]) {
            Vq[0] = rx;
          } else {
            ry = (varargin_5[0] - ry) / (varargin_2[low_ip1] - ry);
            Vq[0] = (1.0 - ry) * qx1 + ry * rx;
          }
        } else {
          Vq[0] = (rtNaN);
        }
      } else {
        Vq[0] = (rtNaN);
      }
    } else {
      Vq[0] = (rtNaN);
    }
  } else {
    Vq[0] = (rtNaN);
  }

  if (varargin_4[1] >= varargin_1[0]) {
    if (varargin_4[1] <= varargin_1[19]) {
      if (varargin_5[1] >= varargin_2[0]) {
        if (varargin_5[1] <= varargin_2[199]) {
          high_i = 20;
          low_i = 0;
          low_ip1 = 2;
          while (high_i > low_ip1) {
            b_low_ip1 = ((low_i + high_i) + 1) >> 1;
            if (varargin_4[1] >= varargin_1[b_low_ip1 - 1]) {
              low_i = b_low_ip1 - 1;
              low_ip1 = b_low_ip1 + 1;
            } else {
              high_i = b_low_ip1;
            }
          }

          high_i = 200;
          low_ip1 = 1;
          b_low_ip1 = 2;
          while (high_i > b_low_ip1) {
            b_mid_i = (low_ip1 + high_i) >> 1;
            if (varargin_5[1] >= varargin_2[b_mid_i - 1]) {
              low_ip1 = b_mid_i;
              b_low_ip1 = b_mid_i + 1;
            } else {
              high_i = b_mid_i;
            }
          }

          if (varargin_4[1] == varargin_1[low_i]) {
            low_i = 200 * low_i + low_ip1;
            qx1 = varargin_3[low_i - 1];
            rx = varargin_3[low_i];
          } else {
            ry = varargin_1[low_i + 1];
            if (ry == varargin_4[1]) {
              low_i = (low_i + 1) * 200 + low_ip1;
              qx1 = varargin_3[low_i - 1];
              rx = varargin_3[low_i];
            } else {
              rx = (varargin_4[1] - varargin_1[low_i]) / (ry - varargin_1[low_i]);
              ry = varargin_3[((low_i + 1) * 200 + low_ip1) - 1];
              b_low_ip1 = 200 * low_i + low_ip1;
              qx1 = varargin_3[b_low_ip1 - 1];
              if (ry == qx1) {
                qx1 = varargin_3[b_low_ip1 - 1];
              } else {
                qx1 = (1.0 - rx) * qx1 + ry * rx;
              }

              high_i = (low_i + 1) * 200 + low_ip1;
              if (varargin_3[high_i] == varargin_3[b_low_ip1]) {
                rx = varargin_3[b_low_ip1];
              } else {
                rx = (1.0 - rx) * varargin_3[b_low_ip1] + varargin_3[high_i] *
                  rx;
              }
            }
          }

          ry = varargin_2[low_ip1 - 1];
          if (ry == varargin_5[1]) {
            Vq[1] = qx1;
          } else if (qx1 == rx) {
            Vq[1] = qx1;
          } else if (varargin_5[1] == varargin_2[low_ip1]) {
            Vq[1] = rx;
          } else {
            ry = (varargin_5[1] - ry) / (varargin_2[low_ip1] - ry);
            Vq[1] = (1.0 - ry) * qx1 + ry * rx;
          }
        } else {
          Vq[1] = (rtNaN);
        }
      } else {
        Vq[1] = (rtNaN);
      }
    } else {
      Vq[1] = (rtNaN);
    }
  } else {
    Vq[1] = (rtNaN);
  }

  if (varargin_4[2] >= varargin_1[0]) {
    if (varargin_4[2] <= varargin_1[19]) {
      if (varargin_5[2] >= varargin_2[0]) {
        if (varargin_5[2] <= varargin_2[199]) {
          high_i = 20;
          low_i = 0;
          low_ip1 = 2;
          while (high_i > low_ip1) {
            b_low_ip1 = ((low_i + high_i) + 1) >> 1;
            if (varargin_4[2] >= varargin_1[b_low_ip1 - 1]) {
              low_i = b_low_ip1 - 1;
              low_ip1 = b_low_ip1 + 1;
            } else {
              high_i = b_low_ip1;
            }
          }

          high_i = 200;
          low_ip1 = 1;
          b_low_ip1 = 2;
          while (high_i > b_low_ip1) {
            b_mid_i = (low_ip1 + high_i) >> 1;
            if (varargin_5[2] >= varargin_2[b_mid_i - 1]) {
              low_ip1 = b_mid_i;
              b_low_ip1 = b_mid_i + 1;
            } else {
              high_i = b_mid_i;
            }
          }

          if (varargin_4[2] == varargin_1[low_i]) {
            low_i = 200 * low_i + low_ip1;
            qx1 = varargin_3[low_i - 1];
            rx = varargin_3[low_i];
          } else {
            ry = varargin_1[low_i + 1];
            if (ry == varargin_4[2]) {
              low_i = (low_i + 1) * 200 + low_ip1;
              qx1 = varargin_3[low_i - 1];
              rx = varargin_3[low_i];
            } else {
              rx = (varargin_4[2] - varargin_1[low_i]) / (ry - varargin_1[low_i]);
              ry = varargin_3[((low_i + 1) * 200 + low_ip1) - 1];
              b_low_ip1 = 200 * low_i + low_ip1;
              qx1 = varargin_3[b_low_ip1 - 1];
              if (ry == qx1) {
                qx1 = varargin_3[b_low_ip1 - 1];
              } else {
                qx1 = (1.0 - rx) * qx1 + ry * rx;
              }

              high_i = (low_i + 1) * 200 + low_ip1;
              if (varargin_3[high_i] == varargin_3[b_low_ip1]) {
                rx = varargin_3[b_low_ip1];
              } else {
                rx = (1.0 - rx) * varargin_3[b_low_ip1] + varargin_3[high_i] *
                  rx;
              }
            }
          }

          ry = varargin_2[low_ip1 - 1];
          if (ry == varargin_5[2]) {
            Vq[2] = qx1;
          } else if (qx1 == rx) {
            Vq[2] = qx1;
          } else if (varargin_5[2] == varargin_2[low_ip1]) {
            Vq[2] = rx;
          } else {
            ry = (varargin_5[2] - ry) / (varargin_2[low_ip1] - ry);
            Vq[2] = (1.0 - ry) * qx1 + ry * rx;
          }
        } else {
          Vq[2] = (rtNaN);
        }
      } else {
        Vq[2] = (rtNaN);
      }
    } else {
      Vq[2] = (rtNaN);
    }
  } else {
    Vq[2] = (rtNaN);
  }

  if (varargin_4[3] >= varargin_1[0]) {
    if (varargin_4[3] <= varargin_1[19]) {
      if (varargin_5[3] >= varargin_2[0]) {
        if (varargin_5[3] <= varargin_2[199]) {
          high_i = 20;
          low_i = 0;
          low_ip1 = 2;
          while (high_i > low_ip1) {
            b_low_ip1 = ((low_i + high_i) + 1) >> 1;
            if (varargin_4[3] >= varargin_1[b_low_ip1 - 1]) {
              low_i = b_low_ip1 - 1;
              low_ip1 = b_low_ip1 + 1;
            } else {
              high_i = b_low_ip1;
            }
          }

          high_i = 200;
          low_ip1 = 1;
          b_low_ip1 = 2;
          while (high_i > b_low_ip1) {
            b_mid_i = (low_ip1 + high_i) >> 1;
            if (varargin_5[3] >= varargin_2[b_mid_i - 1]) {
              low_ip1 = b_mid_i;
              b_low_ip1 = b_mid_i + 1;
            } else {
              high_i = b_mid_i;
            }
          }

          if (varargin_4[3] == varargin_1[low_i]) {
            low_i = 200 * low_i + low_ip1;
            qx1 = varargin_3[low_i - 1];
            rx = varargin_3[low_i];
          } else {
            ry = varargin_1[low_i + 1];
            if (ry == varargin_4[3]) {
              low_i = (low_i + 1) * 200 + low_ip1;
              qx1 = varargin_3[low_i - 1];
              rx = varargin_3[low_i];
            } else {
              rx = (varargin_4[3] - varargin_1[low_i]) / (ry - varargin_1[low_i]);
              ry = varargin_3[((low_i + 1) * 200 + low_ip1) - 1];
              b_low_ip1 = 200 * low_i + low_ip1;
              qx1 = varargin_3[b_low_ip1 - 1];
              if (ry == qx1) {
                qx1 = varargin_3[b_low_ip1 - 1];
              } else {
                qx1 = (1.0 - rx) * qx1 + ry * rx;
              }

              high_i = (low_i + 1) * 200 + low_ip1;
              if (varargin_3[high_i] == varargin_3[b_low_ip1]) {
                rx = varargin_3[b_low_ip1];
              } else {
                rx = (1.0 - rx) * varargin_3[b_low_ip1] + varargin_3[high_i] *
                  rx;
              }
            }
          }

          ry = varargin_2[low_ip1 - 1];
          if (ry == varargin_5[3]) {
            Vq[3] = qx1;
          } else if (qx1 == rx) {
            Vq[3] = qx1;
          } else if (varargin_5[3] == varargin_2[low_ip1]) {
            Vq[3] = rx;
          } else {
            ry = (varargin_5[3] - ry) / (varargin_2[low_ip1] - ry);
            Vq[3] = (1.0 - ry) * qx1 + ry * rx;
          }
        } else {
          Vq[3] = (rtNaN);
        }
      } else {
        Vq[3] = (rtNaN);
      }
    } else {
      Vq[3] = (rtNaN);
    }
  } else {
    Vq[3] = (rtNaN);
  }
}

/* Model step function */
void TV(void)
{
  real_T rtb_y[121];
  real_T varargin_1[49];
  real_T rtb_y_p[42];
  real_T rtb_y_ik[24];
  real_T RateTransition3[18];
  real_T varargin_2[16];
  real_T rtb_y_f[11];
  real_T rtb_y_ref_0[11];
  real_T rtb_UnaryMinus_ci[8];
  real_T rtb_y_c[8];
  real_T rtb_CCaller_o3[7];
  real_T rtb_x[7];
  real_T v[7];
  real_T rtb_lg[6];
  real_T rtb_ug[6];
  real_T rtb_CCaller_o2[4];
  real_T rtb_Product[4];
  real_T rtb_Switch3[4];
  real_T rtb_max_torque_overload_inverte[4];
  real_T rtb_y_kf[4];
  real_T rtb_y_o[4];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T rtb_Abs;
  real_T rtb_Abs3;
  real_T rtb_Abs_idx_0;
  real_T rtb_Abs_o_idx_0;
  real_T rtb_Abs_o_idx_1;
  real_T rtb_Abs_o_idx_2;
  real_T rtb_Abs_o_idx_3;
  real_T rtb_AvoidDividebyZero_h;
  real_T rtb_FilterCoefficient_idx_0;
  real_T rtb_FilterCoefficient_idx_1;
  real_T rtb_FilterCoefficient_idx_2;
  real_T rtb_FilterCoefficient_idx_3;
  real_T rtb_Filter_f;
  real_T rtb_Filter_l_idx_0;
  real_T rtb_Filter_l_idx_1;
  real_T rtb_Filter_l_idx_2;
  real_T rtb_Filter_l_idx_3;
  real_T rtb_Gain1;
  real_T rtb_Integrator_d_idx_0;
  real_T rtb_Integrator_d_idx_1;
  real_T rtb_Integrator_d_idx_2;
  real_T rtb_Integrator_d_idx_3;
  real_T rtb_Integrator_i_idx_0;
  real_T rtb_Integrator_i_idx_1;
  real_T rtb_Integrator_i_idx_2;
  real_T rtb_Integrator_i_idx_3;
  real_T rtb_Integrator_iq_idx_0;
  real_T rtb_Integrator_iq_idx_1;
  real_T rtb_Integrator_iq_idx_2;
  real_T rtb_Integrator_iq_idx_3;
  real_T rtb_Max_m_tmp;
  real_T rtb_RL;
  real_T rtb_RR;
  real_T rtb_Sign;
  real_T rtb_SignPreIntegrator;
  real_T rtb_SignPreIntegrator_idx_0;
  real_T rtb_SignPreIntegrator_idx_1;
  real_T rtb_SignPreIntegrator_idx_2;
  real_T rtb_SignPreIntegrator_idx_3;
  real_T rtb_Subtract_e5;
  real_T rtb_Subtract_km;
  real_T rtb_Subtract_m;
  real_T rtb_Subtract_m4_tmp;
  real_T rtb_Subtract_m4_tmp_0;
  real_T rtb_Subtract_m4_tmp_1;
  real_T rtb_Subtract_m4_tmp_2;
  real_T rtb_Subtract_o;
  real_T rtb_Switch;
  real_T rtb_Switch_m;
  real_T rtb_T_max_ay;
  real_T rtb_T_max_d_idx_0;
  real_T rtb_T_max_d_idx_1;
  real_T rtb_T_max_d_idx_2;
  real_T rtb_T_max_f;
  real_T rtb_T_max_h_idx_0;
  real_T rtb_T_max_h_idx_1;
  real_T rtb_T_max_h_idx_2;
  real_T rtb_T_max_k_idx_0;
  real_T rtb_T_max_k_idx_1;
  real_T rtb_T_max_k_idx_2;
  real_T rtb_T_max_k_idx_3;
  real_T rtb_UnaryMinus_ot_idx_3;
  real_T rtb_ZeroGain_a;
  real_T rtb_ZeroGain_h;
  real_T rtb_ZeroGain_idx_0;
  real_T rtb_ZeroGain_idx_1;
  real_T rtb_ZeroGain_idx_2;
  real_T rtb_ZeroGain_o;
  real_T rtb_max_torque_overload_inver_0;
  real_T rtb_vx;
  int32_T b_exit;
  int32_T i;
  int32_T rowIdx;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  uint32_T acc1;
  uint8_T DataTypeConversion;
  boolean_T rtb_LessThan_m[4];
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_d;
  boolean_T rtb_Compare_g;
  boolean_T rtb_Compare_n;
  boolean_T rtb_Logic_e_idx_0;
  boolean_T rtb_Logic_e_idx_1;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_idx_1;
  boolean_T rtb_Logic_k_idx_0;
  boolean_T rtb_Logic_l_idx_0;
  boolean_T rtb_Logic_l_idx_1;
  boolean_T rtb_Memory_e_idx_0;
  boolean_T rtb_Memory_e_idx_1;
  boolean_T rtb_Memory_e_idx_2;
  boolean_T rtb_Memory_e_idx_3;
  boolean_T rtb_Memory_idx_0;
  boolean_T rtb_Memory_idx_1;
  boolean_T rtb_Memory_idx_2;
  boolean_T rtb_Memory_idx_3;
  static const int8_T b[7] = { 0, 0, 0, 1, 1, 1, 1 };

  static const int8_T c[7] = { 0, 0, 0, 0, 1, 0, -1 };

  static const int8_T d[7] = { 0, 0, 0, 1, 0, -1, 0 };

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (rtU.vx <= 0.0) {
    rtb_Subtract_e5 = 0.0;
  } else {
    rtb_Subtract_e5 = rtU.vx;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/yaw_rate'
   */
  rtb_Gain1 = 0.017453292519943295 * rtU.yaw_rate_deg;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Subtract_e5 <= 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = rtb_Subtract_e5;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Math: '<S14>/Square1' incorporates:
   *  Math: '<S14>/Square2'
   *  Math: '<S16>/Square1'
   */
  rtb_Subtract_m4_tmp = rtb_vx * rtb_vx;

  /* Gain: '<S14>/Lateral Load Transfer' incorporates:
   *  Gain: '<S15>/Lateral Load Transfer'
   *  Gain: '<S16>/Lateral Load Transfer'
   *  Gain: '<S17>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S14>/Unary Minus'
   */
  rtb_Subtract_m4_tmp_0 = 30.826771653543307 * -rtU.ay;

  /* Gain: '<S14>/Lift Force' incorporates:
   *  Gain: '<S15>/Lift Force'
   *  Math: '<S14>/Square1'
   */
  rtb_FilterCoefficient_idx_0 = rtb_Subtract_m4_tmp * 0.92446666666666677;

  /* Gain: '<S14>/Drag moment' incorporates:
   *  Gain: '<S15>/Drag moment'
   *  Gain: '<S16>/Drag moment'
   *  Gain: '<S17>/Drag moment'
   */
  rtb_Subtract_m4_tmp_1 = rtb_Subtract_m4_tmp * 0.21998117647058821;

  /* Gain: '<S14>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S15>/Longitudinal Load Transfer'
   *  Gain: '<S16>/Longitudinal Load Transfer'
   *  Gain: '<S17>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S14>/Unary Minus1'
   */
  rtb_Subtract_m4_tmp_2 = 25.588235294117645 * -rtU.ax;

  /* Sum: '<S14>/Subtract' incorporates:
   *  Constant: '<S14>/Static Load Front'
   *  Gain: '<S14>/Drag moment'
   *  Gain: '<S14>/Lateral Load Transfer'
   *  Gain: '<S14>/Lift Force'
   *  Gain: '<S14>/Longitudinal Load Transfer'
   */
  rtb_Subtract_e5 = (((rtb_Subtract_m4_tmp_0 + 635.688) +
                      rtb_FilterCoefficient_idx_0) - rtb_Subtract_m4_tmp_1) +
    rtb_Subtract_m4_tmp_2;

  /* Sum: '<S15>/Subtract' incorporates:
   *  Constant: '<S15>/Static Load Front'
   */
  rtb_Subtract_o = (((635.688 - rtb_Subtract_m4_tmp_0) +
                     rtb_FilterCoefficient_idx_0) - rtb_Subtract_m4_tmp_1) +
    rtb_Subtract_m4_tmp_2;

  /* Gain: '<S16>/Lift Force' incorporates:
   *  Gain: '<S17>/Lift Force'
   */
  rtb_RR = rtb_Subtract_m4_tmp * 0.74153333333333349;

  /* Sum: '<S16>/Subtract' incorporates:
   *  Constant: '<S16>/Static Load Front'
   *  Gain: '<S16>/Lift Force'
   */
  rtb_Subtract_m = (((rtb_Subtract_m4_tmp_0 + 688.66200000000015) + rtb_RR) +
                    rtb_Subtract_m4_tmp_1) - rtb_Subtract_m4_tmp_2;

  /* Sum: '<S17>/Subtract' incorporates:
   *  Constant: '<S17>/Static Load Front'
   */
  rtb_Subtract_km = (((688.66200000000015 - rtb_Subtract_m4_tmp_0) + rtb_RR) +
                     rtb_Subtract_m4_tmp_1) - rtb_Subtract_m4_tmp_2;

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
  rtb_Abs_idx_0 = fabs(look1_binlx(rtU.steering, rtConstP.pooled34,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Abs = fabs(look1_binlx(-rtU.steering, rtConstP.pooled34,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  Sum: '<S18>/Subtract'
   *  Sum: '<S18>/Subtract1'
   *  Sum: '<S18>/Subtract2'
   *  Sum: '<S19>/Subtract'
   *  Sum: '<S19>/Subtract2'
   *  Sum: '<S20>/Subtract1'
   *  Trigonometry: '<S18>/Atan'
   *  Trigonometry: '<S19>/Atan'
   *  Trigonometry: '<S20>/Atan'
   *  Trigonometry: '<S21>/Atan'
   */
  if (rtb_vx > 3.0) {
    /* Sum: '<S18>/Subtract1' incorporates:
     *  Gain: '<S18>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S19>/Subtract1'
     */
    rtb_Subtract_m4_tmp_2 = 0.73439999999999994 * rtb_Gain1 + rtU.vy;

    /* Sum: '<S18>/Subtract' incorporates:
     *  Gain: '<S18>/Gain1'
     *  Sum: '<S20>/Subtract'
     */
    rtb_Subtract_m4_tmp_1 = rtb_vx - 0.635 * rtb_Gain1;
    rtb_Abs_o_idx_0 = rt_atan2d_snf(rtb_Subtract_m4_tmp_2, rtb_Subtract_m4_tmp_1)
      - rtb_Abs_idx_0;

    /* Sum: '<S19>/Subtract' incorporates:
     *  Gain: '<S19>/Gain1'
     *  Sum: '<S18>/Subtract'
     *  Sum: '<S18>/Subtract1'
     *  Sum: '<S18>/Subtract2'
     *  Sum: '<S21>/Subtract'
     *  Trigonometry: '<S18>/Atan'
     */
    rtb_Subtract_m4_tmp_0 = 0.635 * rtb_Gain1 + rtb_vx;
    rtb_Abs_o_idx_1 = rt_atan2d_snf(rtb_Subtract_m4_tmp_2, rtb_Subtract_m4_tmp_0)
      - rtb_Abs;

    /* Sum: '<S20>/Subtract1' incorporates:
     *  Gain: '<S20>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S19>/Subtract'
     *  Sum: '<S19>/Subtract2'
     *  Sum: '<S21>/Subtract1'
     *  Trigonometry: '<S19>/Atan'
     */
    rtb_Subtract_m4_tmp_2 = rtU.vy - 0.79560000000000008 * rtb_Gain1;
    rtb_Abs_o_idx_2 = rt_atan2d_snf(rtb_Subtract_m4_tmp_2, rtb_Subtract_m4_tmp_1);
    rtb_Abs_o_idx_3 = rt_atan2d_snf(rtb_Subtract_m4_tmp_2, rtb_Subtract_m4_tmp_0);
  } else {
    rtb_Abs_o_idx_0 = 0.0;
    rtb_Abs_o_idx_1 = 0.0;
    rtb_Abs_o_idx_2 = 0.0;
    rtb_Abs_o_idx_3 = 0.0;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Gain: '<S22>/Gain3'
   *  Gain: '<S23>/Gain3'
   *  Gain: '<S24>/Gain'
   *  Gain: '<S25>/Gain'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S22>/Divide4'
   *  Product: '<S23>/Divide4'
   *  Product: '<S24>/Divide'
   *  Product: '<S25>/Divide'
   *  Sum: '<S22>/Subtract3'
   *  Sum: '<S23>/Subtract3'
   *  Sum: '<S24>/Subtract'
   *  Sum: '<S25>/Subtract'
   *  Switch: '<S23>/Switch'
   *  Switch: '<S24>/Switch'
   *  Switch: '<S25>/Switch'
   */
  if (rtb_vx > 0.5) {
    /* Sum: '<S22>/Sum' incorporates:
     *  Inport: '<Root>/vy'
     *  Product: '<S22>/Divide5'
     *  Product: '<S22>/Divide6'
     *  Trigonometry: '<S22>/Cos1'
     *  Trigonometry: '<S22>/Cos2'
     */
    rtb_Sign = rtb_vx * cos(rtb_Abs_idx_0) + sin(rtb_Abs_idx_0) * rtU.vy;
    rtb_Switch = (0.235 * rtU.omega_wheels_FL - rtb_Sign) / rtb_Sign;

    /* Sum: '<S23>/Sum' incorporates:
     *  Gain: '<S22>/Gain3'
     *  Inport: '<Root>/omega_wheels_FL'
     *  Inport: '<Root>/vy'
     *  Product: '<S22>/Divide4'
     *  Product: '<S23>/Divide5'
     *  Product: '<S23>/Divide6'
     *  Sum: '<S22>/Subtract3'
     *  Trigonometry: '<S23>/Cos1'
     *  Trigonometry: '<S23>/Cos2'
     */
    rtb_Sign = rtb_vx * cos(rtb_Abs) + sin(rtb_Abs) * rtU.vy;
    rtb_Switch_m = (0.235 * rtU.omega_wheels_FR - rtb_Sign) / rtb_Sign;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_vx) / rtb_vx;
    rtb_RL = (0.235 * rtU.omega_wheels_RL - rtb_vx) / rtb_vx;
  } else {
    rtb_Switch = 0.0;
    rtb_Switch_m = 0.0;
    rtb_RR = 0.0;
    rtb_RL = 0.0;
  }

  /* End of Switch: '<S22>/Switch' */

  /* SampleTimeMath: '<S28>/TSamp' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  SampleTimeMath: '<S93>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Subtract_m4_tmp_0 = rtU.omega_wheels_FL * 50.0;
  rtb_Subtract_m4_tmp_1 = rtU.omega_wheels_FR * 50.0;
  rtb_Subtract_m4_tmp_2 = rtU.omega_wheels_RL * 50.0;
  rtb_Subtract_m4_tmp = rtU.omega_wheels_RR * 50.0;

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S33>/Time constant'
   *  Constant: '<S36>/Constant'
   *  Sum: '<S33>/Sum1'
   */
  rtb_Compare = (0.1 - rtDW.Probe[0] <= 0.0);

  /* Memory: '<S26>/Memory' */
  rtb_Memory_idx_0 = rtDW.Memory_PreviousInput_f[0];

  /* DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   */
  if (rtDW.Memory_PreviousInput_f[0] || (rtDW.Integrator_PrevResetState[0] != 0))
  {
    rtDW.Integrator_DSTATE[0] = 0.0;
  }

  /* DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  Memory: '<S26>/Memory'
   */
  if (rtDW.Memory_PreviousInput_f[0] || (rtDW.Filter_PrevResetState[0] != 0)) {
    rtDW.Filter_DSTATE[0] = 0.0;
  }

  /* Memory: '<S26>/Memory' */
  rtb_Memory_idx_1 = rtDW.Memory_PreviousInput_f[1];

  /* DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   */
  if (rtDW.Memory_PreviousInput_f[1] || (rtDW.Integrator_PrevResetState[1] != 0))
  {
    rtDW.Integrator_DSTATE[1] = 0.0;
  }

  /* DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  Memory: '<S26>/Memory'
   */
  if (rtDW.Memory_PreviousInput_f[1] || (rtDW.Filter_PrevResetState[1] != 0)) {
    rtDW.Filter_DSTATE[1] = 0.0;
  }

  /* Memory: '<S26>/Memory' */
  rtb_Memory_idx_2 = rtDW.Memory_PreviousInput_f[2];

  /* DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   */
  if (rtDW.Memory_PreviousInput_f[2] || (rtDW.Integrator_PrevResetState[2] != 0))
  {
    rtDW.Integrator_DSTATE[2] = 0.0;
  }

  /* DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  Memory: '<S26>/Memory'
   */
  if (rtDW.Memory_PreviousInput_f[2] || (rtDW.Filter_PrevResetState[2] != 0)) {
    rtDW.Filter_DSTATE[2] = 0.0;
  }

  /* Memory: '<S26>/Memory' */
  rtb_Memory_idx_3 = rtDW.Memory_PreviousInput_f[3];

  /* DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   */
  if (rtDW.Memory_PreviousInput_f[3] || (rtDW.Integrator_PrevResetState[3] != 0))
  {
    rtDW.Integrator_DSTATE[3] = 0.0;
  }

  /* DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  Memory: '<S26>/Memory'
   */
  if (rtDW.Memory_PreviousInput_f[3] || (rtDW.Filter_PrevResetState[3] != 0)) {
    rtDW.Filter_DSTATE[3] = 0.0;
  }

  /* Gain: '<S77>/Filter Coefficient' incorporates:
   *  Constant: '<S26>/Constant5'
   *  DiscreteIntegrator: '<S69>/Filter'
   *  Gain: '<S68>/Derivative Gain'
   *  Sum: '<S32>/Sum3'
   *  Sum: '<S69>/SumD'
   */
  rtb_FilterCoefficient_idx_0 = ((-0.15 - rtb_Switch) * 0.0 -
    rtDW.Filter_DSTATE[0]) * 100.0;
  rtb_FilterCoefficient_idx_1 = ((-0.15 - rtb_Switch_m) * 0.0 -
    rtDW.Filter_DSTATE[1]) * 100.0;
  rtb_FilterCoefficient_idx_2 = ((-0.15 - rtb_RL) * 0.0 - rtDW.Filter_DSTATE[2])
    * 100.0;
  rtb_FilterCoefficient_idx_3 = ((-0.15 - rtb_RR) * 0.0 - rtDW.Filter_DSTATE[3])
    * 100.0;

  /* Sum: '<S83>/Sum' incorporates:
   *  Constant: '<S26>/Constant5'
   *  DiscreteIntegrator: '<S134>/Filter'
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Sum: '<S32>/Sum1'
   */
  rtb_Filter_l_idx_0 = ((-0.15 - rtb_Switch) + rtDW.Integrator_DSTATE[0]) +
    rtb_FilterCoefficient_idx_0;
  rtb_Filter_l_idx_1 = ((-0.15 - rtb_Switch_m) + rtDW.Integrator_DSTATE[1]) +
    rtb_FilterCoefficient_idx_1;
  rtb_Filter_l_idx_2 = ((-0.15 - rtb_RL) + rtDW.Integrator_DSTATE[2]) +
    rtb_FilterCoefficient_idx_2;
  rtb_Filter_l_idx_3 = ((-0.15 - rtb_RR) + rtDW.Integrator_DSTATE[3]) +
    rtb_FilterCoefficient_idx_3;

  /* SignalConversion generated from: '<S31>/ SFunction ' incorporates:
   *  MATLAB Function: '<S26>/MATLAB Function3'
   *  UnitDelay generated from: '<S26>/Unit Delay3'
   */
  rtb_y_o[0] = rtDW.UnitDelay3_1_DSTATE;
  rtb_y_o[1] = rtDW.UnitDelay3_2_DSTATE;
  rtb_y_o[2] = rtDW.UnitDelay3_3_DSTATE;
  rtb_y_o[3] = rtDW.UnitDelay3_4_DSTATE;

  /* MATLAB Function: '<S26>/MATLAB Function3' */
  rtb_y_o[0] *= 13.5;
  rtb_y_o[1] *= 13.5;
  rtb_y_o[2] *= 13.5;
  rtb_y_o[3] *= 13.5;

  /* Saturate: '<S81>/Saturation' */
  if (rtb_Filter_l_idx_0 > 2.0) {
    rtb_T_max_k_idx_0 = 2.0;
  } else if (rtb_Filter_l_idx_0 < 0.0) {
    rtb_T_max_k_idx_0 = 0.0;
  } else {
    rtb_T_max_k_idx_0 = rtb_Filter_l_idx_0;
  }

  /* MATLAB Function: '<S26>/MATLAB Function3' incorporates:
   *  Constant: '<S26>/Constant4'
   *  SampleTimeMath: '<S28>/TSamp'
   *  Sum: '<S26>/Sum'
   *  Sum: '<S28>/Diff'
   *  UnitDelay: '<S28>/UD'
   *  UnitDelay: '<S2>/Unit Delay'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S28>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtb_T_max_k_idx_0 = (0.2 / ((rtb_T_max_k_idx_0 + 0.5) * 67.5 *
    0.055224999999999996) + 1.0) * 0.235 * ((-rtDW.UnitDelay_DSTATE[0] / 0.235 +
    rtb_y_o[0] / 0.235) - (rtb_Subtract_m4_tmp_0 - rtDW.UD_DSTATE[0]) * 0.235 *
    0.2 / 0.055224999999999996) / 13.5;

  /* Saturate: '<S81>/Saturation' */
  if (rtb_Filter_l_idx_1 > 2.0) {
    rtb_T_max_k_idx_1 = 2.0;
  } else if (rtb_Filter_l_idx_1 < 0.0) {
    rtb_T_max_k_idx_1 = 0.0;
  } else {
    rtb_T_max_k_idx_1 = rtb_Filter_l_idx_1;
  }

  /* MATLAB Function: '<S26>/MATLAB Function3' incorporates:
   *  Constant: '<S26>/Constant4'
   *  SampleTimeMath: '<S28>/TSamp'
   *  Sum: '<S26>/Sum'
   *  Sum: '<S28>/Diff'
   *  UnitDelay: '<S28>/UD'
   *  UnitDelay: '<S2>/Unit Delay'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S28>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtb_T_max_k_idx_1 = (0.2 / ((rtb_T_max_k_idx_1 + 0.5) * 67.5 *
    0.055224999999999996) + 1.0) * 0.235 * ((-rtDW.UnitDelay_DSTATE[1] / 0.235 +
    rtb_y_o[1] / 0.235) - (rtb_Subtract_m4_tmp_1 - rtDW.UD_DSTATE[1]) * 0.235 *
    0.2 / 0.055224999999999996) / 13.5;

  /* Saturate: '<S81>/Saturation' */
  if (rtb_Filter_l_idx_2 > 2.0) {
    rtb_T_max_k_idx_2 = 2.0;
  } else if (rtb_Filter_l_idx_2 < 0.0) {
    rtb_T_max_k_idx_2 = 0.0;
  } else {
    rtb_T_max_k_idx_2 = rtb_Filter_l_idx_2;
  }

  /* MATLAB Function: '<S26>/MATLAB Function3' incorporates:
   *  Constant: '<S26>/Constant4'
   *  SampleTimeMath: '<S28>/TSamp'
   *  Sum: '<S26>/Sum'
   *  Sum: '<S28>/Diff'
   *  UnitDelay: '<S28>/UD'
   *  UnitDelay: '<S2>/Unit Delay'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S28>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtb_T_max_k_idx_2 = (0.2 / ((rtb_T_max_k_idx_2 + 0.5) * 67.5 *
    0.055224999999999996) + 1.0) * 0.235 * ((-rtDW.UnitDelay_DSTATE[2] / 0.235 +
    rtb_y_o[2] / 0.235) - (rtb_Subtract_m4_tmp_2 - rtDW.UD_DSTATE[2]) * 0.235 *
    0.2 / 0.055224999999999996) / 13.5;

  /* Saturate: '<S81>/Saturation' */
  if (rtb_Filter_l_idx_3 > 2.0) {
    rtb_Sign = 2.0;
  } else if (rtb_Filter_l_idx_3 < 0.0) {
    rtb_Sign = 0.0;
  } else {
    rtb_Sign = rtb_Filter_l_idx_3;
  }

  /* MATLAB Function: '<S26>/MATLAB Function3' incorporates:
   *  Constant: '<S26>/Constant4'
   *  SampleTimeMath: '<S28>/TSamp'
   *  Sum: '<S26>/Sum'
   *  Sum: '<S28>/Diff'
   *  UnitDelay: '<S28>/UD'
   *  UnitDelay: '<S2>/Unit Delay'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S28>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtb_T_max_k_idx_3 = (0.2 / ((rtb_Sign + 0.5) * 67.5 * 0.055224999999999996) +
                       1.0) * 0.235 * ((-rtDW.UnitDelay_DSTATE[3] / 0.235 +
    rtb_y_o[3] / 0.235) - (rtb_Subtract_m4_tmp - rtDW.UD_DSTATE[3]) * 0.235 *
    0.2 / 0.055224999999999996) / 13.5;
  if (rtb_y_o[0] / 13.5 > -5.0) {
    rtb_T_max_k_idx_0 = -21.0;
  }

  if (rtb_y_o[1] / 13.5 > -5.0) {
    rtb_T_max_k_idx_1 = -21.0;
  }

  if (rtb_y_o[2] / 13.5 > -5.0) {
    rtb_T_max_k_idx_2 = -21.0;
  }

  if (rtb_y_o[3] / 13.5 > -5.0) {
    rtb_T_max_k_idx_3 = -21.0;
  }

  /* DiscreteIntegrator: '<S38>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE_h[0] = rtb_T_max_k_idx_0;
    rtDW.Integrator_DSTATE_h[1] = rtb_T_max_k_idx_1;
    rtDW.Integrator_DSTATE_h[2] = rtb_T_max_k_idx_2;
    rtDW.Integrator_DSTATE_h[3] = rtb_T_max_k_idx_3;
  }

  if (rtb_Compare || (rtDW.Integrator_PrevResetState_d != 0)) {
    rtDW.Integrator_DSTATE_h[0] = rtb_T_max_k_idx_0;
    rtDW.Integrator_DSTATE_h[1] = rtb_T_max_k_idx_1;
    rtDW.Integrator_DSTATE_h[2] = rtb_T_max_k_idx_2;
    rtDW.Integrator_DSTATE_h[3] = rtb_T_max_k_idx_3;
  }

  /* SignalConversion generated from: '<S30>/ SFunction ' incorporates:
   *  MATLAB Function: '<S26>/MATLAB Function2'
   */
  rtb_y_o[0] = rtb_Switch;
  rtb_y_o[1] = rtb_Switch_m;
  rtb_y_o[2] = rtb_RL;
  rtb_y_o[3] = rtb_RR;

  /* SignalConversion generated from: '<S30>/ SFunction ' incorporates:
   *  MATLAB Function: '<S26>/MATLAB Function2'
   *  UnitDelay generated from: '<S26>/Unit Delay2'
   */
  rtb_y_kf[0] = rtDW.UnitDelay2_1_DSTATE;
  rtb_y_kf[1] = rtDW.UnitDelay2_2_DSTATE;
  rtb_y_kf[2] = rtDW.UnitDelay2_3_DSTATE;
  rtb_y_kf[3] = rtDW.UnitDelay2_4_DSTATE;

  /* MATLAB Function: '<S26>/MATLAB Function2' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  if (rtb_y_o[0] < -0.1) {
    rtb_T_max_d_idx_0 = rtDW.Integrator_DSTATE_h[0];
  } else if (rtb_y_kf[0] > rtDW.UnitDelay_DSTATE_n[0] * 0.75 - 0.1) {
    rtb_T_max_d_idx_0 = rtDW.UnitDelay_DSTATE_n[0] - 1.0;
    if (rtDW.UnitDelay_DSTATE_n[0] - 1.0 < -21.0) {
      rtb_T_max_d_idx_0 = -21.0;
    }
  } else {
    rtb_T_max_d_idx_0 = rtDW.Integrator_DSTATE_h[0];
  }

  if (rtb_y_o[1] < -0.1) {
    rtb_T_max_d_idx_1 = rtDW.Integrator_DSTATE_h[1];
  } else if (rtb_y_kf[1] > rtDW.UnitDelay_DSTATE_n[1] * 0.75 - 0.1) {
    rtb_T_max_d_idx_1 = rtDW.UnitDelay_DSTATE_n[1] - 1.0;
    if (rtDW.UnitDelay_DSTATE_n[1] - 1.0 < -21.0) {
      rtb_T_max_d_idx_1 = -21.0;
    }
  } else {
    rtb_T_max_d_idx_1 = rtDW.Integrator_DSTATE_h[1];
  }

  if (rtb_y_o[2] < -0.1) {
    rtb_T_max_d_idx_2 = rtDW.Integrator_DSTATE_h[2];
  } else if (rtb_y_kf[2] > rtDW.UnitDelay_DSTATE_n[2] * 0.75 - 0.1) {
    rtb_T_max_d_idx_2 = rtDW.UnitDelay_DSTATE_n[2] - 1.0;
    if (rtDW.UnitDelay_DSTATE_n[2] - 1.0 < -21.0) {
      rtb_T_max_d_idx_2 = -21.0;
    }
  } else {
    rtb_T_max_d_idx_2 = rtDW.Integrator_DSTATE_h[2];
  }

  if (rtb_y_o[3] < -0.1) {
    rtb_T_max_ay = rtDW.Integrator_DSTATE_h[3];
  } else if (rtb_y_kf[3] > rtDW.UnitDelay_DSTATE_n[3] * 0.75 - 0.1) {
    rtb_T_max_ay = rtDW.UnitDelay_DSTATE_n[3] - 1.0;
    if (rtDW.UnitDelay_DSTATE_n[3] - 1.0 < -21.0) {
      rtb_T_max_ay = -21.0;
    }
  } else {
    rtb_T_max_ay = rtDW.Integrator_DSTATE_h[3];
  }

  /* Fcn: '<S33>/Avoid Divide by Zero' incorporates:
   *  Constant: '<S33>/Time constant'
   *  MinMax: '<S33>/Max'
   */
  rtb_Sign = fmax(rtDW.Probe[0], 0.1);

  /* RelationalOperator: '<S101>/Compare' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S98>/Time constant'
   *  Sum: '<S98>/Sum1'
   */
  rtb_Compare_n = (0.1 - rtDW.Probe_k[0] <= 0.0);

  /* Gain: '<S65>/ZeroGain' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   */
  rtb_Filter_f = rtb_Filter_l_idx_0;

  /* DeadZone: '<S67>/DeadZone' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S65>/ZeroGain'
   */
  if (rtb_Filter_l_idx_0 > 2.0) {
    rtb_Filter_f = rtb_Filter_l_idx_0 - 2.0;
  } else if (rtb_Filter_l_idx_0 >= 0.0) {
    rtb_Filter_f = 0.0;
  }

  /* Memory: '<S27>/Memory' */
  rtb_Memory_e_idx_0 = rtDW.Memory_PreviousInput_m[0];

  /* DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  if (rtDW.Memory_PreviousInput_m[0] || (rtDW.Integrator_PrevResetState_a[0] !=
       0)) {
    rtDW.Integrator_DSTATE_f[0] = 0.0;
  }

  /* DiscreteIntegrator: '<S134>/Filter' incorporates:
   *  Memory: '<S27>/Memory'
   */
  if (rtDW.Memory_PreviousInput_m[0] || (rtDW.Filter_PrevResetState_d[0] != 0))
  {
    rtDW.Filter_DSTATE_d[0] = 0.0;
  }

  /* Sum: '<S29>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   */
  rtb_T_max_k_idx_0 -= rtDW.Integrator_DSTATE_h[0];

  /* Signum: '<S65>/SignPreSat' */
  if (rtb_Filter_f < 0.0) {
    rtb_SignPreIntegrator_idx_0 = -1.0;
  } else if (rtb_Filter_f > 0.0) {
    rtb_SignPreIntegrator_idx_0 = 1.0;
  } else if (rtb_Filter_f == 0.0) {
    rtb_SignPreIntegrator_idx_0 = 0.0;
  } else {
    rtb_SignPreIntegrator_idx_0 = (rtNaN);
  }

  /* Signum: '<S65>/SignPreIntegrator' incorporates:
   *  Constant: '<S26>/Constant5'
   *  Sum: '<S32>/Sum2'
   */
  if (-0.15 - rtb_Switch < 0.0) {
    rtb_Abs3 = -1.0;
  } else if (-0.15 - rtb_Switch > 0.0) {
    rtb_Abs3 = 1.0;
  } else if (-0.15 - rtb_Switch == 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = (rtNaN);
  }

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S26>/Constant5'
   *  Constant: '<S65>/Constant1'
   *  DataTypeConversion: '<S65>/DataTypeConv1'
   *  DataTypeConversion: '<S65>/DataTypeConv2'
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S65>/ZeroGain'
   *  Logic: '<S65>/AND3'
   *  RelationalOperator: '<S65>/Equal1'
   *  RelationalOperator: '<S65>/NotEqual'
   *  Sum: '<S32>/Sum2'
   */
  if ((0.0 * rtb_Filter_l_idx_0 != rtb_Filter_f) && ((int8_T)
       rtb_SignPreIntegrator_idx_0 == (int8_T)rtb_Abs3)) {
    rtb_ZeroGain_idx_0 = 0.0;
  } else {
    rtb_ZeroGain_idx_0 = -0.15 - rtb_Switch;
  }

  /* Gain: '<S65>/ZeroGain' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   */
  rtb_Filter_f = rtb_Filter_l_idx_1;

  /* DeadZone: '<S67>/DeadZone' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S65>/ZeroGain'
   */
  if (rtb_Filter_l_idx_1 > 2.0) {
    rtb_Filter_f = rtb_Filter_l_idx_1 - 2.0;
  } else if (rtb_Filter_l_idx_1 >= 0.0) {
    rtb_Filter_f = 0.0;
  }

  /* Memory: '<S27>/Memory' */
  rtb_Memory_e_idx_1 = rtDW.Memory_PreviousInput_m[1];

  /* DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  if (rtDW.Memory_PreviousInput_m[1] || (rtDW.Integrator_PrevResetState_a[1] !=
       0)) {
    rtDW.Integrator_DSTATE_f[1] = 0.0;
  }

  /* DiscreteIntegrator: '<S134>/Filter' incorporates:
   *  Memory: '<S27>/Memory'
   */
  if (rtDW.Memory_PreviousInput_m[1] || (rtDW.Filter_PrevResetState_d[1] != 0))
  {
    rtDW.Filter_DSTATE_d[1] = 0.0;
  }

  /* Sum: '<S29>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   */
  rtb_T_max_k_idx_1 -= rtDW.Integrator_DSTATE_h[1];

  /* Signum: '<S65>/SignPreSat' */
  if (rtb_Filter_f < 0.0) {
    rtb_SignPreIntegrator_idx_0 = -1.0;
  } else if (rtb_Filter_f > 0.0) {
    rtb_SignPreIntegrator_idx_0 = 1.0;
  } else if (rtb_Filter_f == 0.0) {
    rtb_SignPreIntegrator_idx_0 = 0.0;
  } else {
    rtb_SignPreIntegrator_idx_0 = (rtNaN);
  }

  /* Signum: '<S65>/SignPreIntegrator' incorporates:
   *  Constant: '<S26>/Constant5'
   *  Sum: '<S32>/Sum2'
   */
  if (-0.15 - rtb_Switch_m < 0.0) {
    rtb_Abs3 = -1.0;
  } else if (-0.15 - rtb_Switch_m > 0.0) {
    rtb_Abs3 = 1.0;
  } else if (-0.15 - rtb_Switch_m == 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = (rtNaN);
  }

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S26>/Constant5'
   *  Constant: '<S65>/Constant1'
   *  DataTypeConversion: '<S65>/DataTypeConv1'
   *  DataTypeConversion: '<S65>/DataTypeConv2'
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S65>/ZeroGain'
   *  Logic: '<S65>/AND3'
   *  RelationalOperator: '<S65>/Equal1'
   *  RelationalOperator: '<S65>/NotEqual'
   *  Sum: '<S32>/Sum2'
   */
  if ((0.0 * rtb_Filter_l_idx_1 != rtb_Filter_f) && ((int8_T)
       rtb_SignPreIntegrator_idx_0 == (int8_T)rtb_Abs3)) {
    rtb_ZeroGain_idx_1 = 0.0;
  } else {
    rtb_ZeroGain_idx_1 = -0.15 - rtb_Switch_m;
  }

  /* Gain: '<S65>/ZeroGain' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   */
  rtb_Filter_f = rtb_Filter_l_idx_2;

  /* DeadZone: '<S67>/DeadZone' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S65>/ZeroGain'
   */
  if (rtb_Filter_l_idx_2 > 2.0) {
    rtb_Filter_f = rtb_Filter_l_idx_2 - 2.0;
  } else if (rtb_Filter_l_idx_2 >= 0.0) {
    rtb_Filter_f = 0.0;
  }

  /* Memory: '<S27>/Memory' */
  rtb_Memory_e_idx_2 = rtDW.Memory_PreviousInput_m[2];

  /* DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  if (rtDW.Memory_PreviousInput_m[2] || (rtDW.Integrator_PrevResetState_a[2] !=
       0)) {
    rtDW.Integrator_DSTATE_f[2] = 0.0;
  }

  /* DiscreteIntegrator: '<S134>/Filter' incorporates:
   *  Memory: '<S27>/Memory'
   */
  if (rtDW.Memory_PreviousInput_m[2] || (rtDW.Filter_PrevResetState_d[2] != 0))
  {
    rtDW.Filter_DSTATE_d[2] = 0.0;
  }

  /* Sum: '<S29>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   */
  rtb_T_max_k_idx_2 -= rtDW.Integrator_DSTATE_h[2];

  /* Signum: '<S65>/SignPreSat' */
  if (rtb_Filter_f < 0.0) {
    rtb_SignPreIntegrator_idx_0 = -1.0;
  } else if (rtb_Filter_f > 0.0) {
    rtb_SignPreIntegrator_idx_0 = 1.0;
  } else if (rtb_Filter_f == 0.0) {
    rtb_SignPreIntegrator_idx_0 = 0.0;
  } else {
    rtb_SignPreIntegrator_idx_0 = (rtNaN);
  }

  /* Signum: '<S65>/SignPreIntegrator' incorporates:
   *  Constant: '<S26>/Constant5'
   *  Sum: '<S32>/Sum2'
   */
  if (-0.15 - rtb_RL < 0.0) {
    rtb_Abs3 = -1.0;
  } else if (-0.15 - rtb_RL > 0.0) {
    rtb_Abs3 = 1.0;
  } else if (-0.15 - rtb_RL == 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = (rtNaN);
  }

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S26>/Constant5'
   *  Constant: '<S65>/Constant1'
   *  DataTypeConversion: '<S65>/DataTypeConv1'
   *  DataTypeConversion: '<S65>/DataTypeConv2'
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S65>/ZeroGain'
   *  Logic: '<S65>/AND3'
   *  RelationalOperator: '<S65>/Equal1'
   *  RelationalOperator: '<S65>/NotEqual'
   *  Sum: '<S32>/Sum2'
   */
  if ((0.0 * rtb_Filter_l_idx_2 != rtb_Filter_f) && ((int8_T)
       rtb_SignPreIntegrator_idx_0 == (int8_T)rtb_Abs3)) {
    rtb_ZeroGain_idx_2 = 0.0;
  } else {
    rtb_ZeroGain_idx_2 = -0.15 - rtb_RL;
  }

  /* Gain: '<S65>/ZeroGain' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   */
  rtb_Filter_f = rtb_Filter_l_idx_3;

  /* Sum: '<S29>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   */
  rtb_T_max_k_idx_3 -= rtDW.Integrator_DSTATE_h[3];

  /* DeadZone: '<S67>/DeadZone' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S65>/ZeroGain'
   */
  if (rtb_Filter_l_idx_3 > 2.0) {
    rtb_Filter_f = rtb_Filter_l_idx_3 - 2.0;
  } else if (rtb_Filter_l_idx_3 >= 0.0) {
    rtb_Filter_f = 0.0;
  }

  /* Signum: '<S65>/SignPreSat' */
  if (rtb_Filter_f < 0.0) {
    rtb_SignPreIntegrator_idx_0 = -1.0;
  } else if (rtb_Filter_f > 0.0) {
    rtb_SignPreIntegrator_idx_0 = 1.0;
  } else if (rtb_Filter_f == 0.0) {
    rtb_SignPreIntegrator_idx_0 = 0.0;
  } else {
    rtb_SignPreIntegrator_idx_0 = (rtNaN);
  }

  /* Signum: '<S65>/SignPreIntegrator' incorporates:
   *  Constant: '<S26>/Constant5'
   *  Sum: '<S32>/Sum2'
   */
  if (-0.15 - rtb_RR < 0.0) {
    rtb_Abs3 = -1.0;
  } else if (-0.15 - rtb_RR > 0.0) {
    rtb_Abs3 = 1.0;
  } else if (-0.15 - rtb_RR == 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = (rtNaN);
  }

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S26>/Constant5'
   *  Constant: '<S65>/Constant1'
   *  DataTypeConversion: '<S65>/DataTypeConv1'
   *  DataTypeConversion: '<S65>/DataTypeConv2'
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S65>/ZeroGain'
   *  Logic: '<S65>/AND3'
   *  RelationalOperator: '<S65>/Equal1'
   *  RelationalOperator: '<S65>/NotEqual'
   *  Sum: '<S32>/Sum2'
   */
  if ((0.0 * rtb_Filter_l_idx_3 != rtb_Filter_f) && ((int8_T)
       rtb_SignPreIntegrator_idx_0 == (int8_T)rtb_Abs3)) {
    rtb_Filter_f = 0.0;
  } else {
    rtb_Filter_f = -0.15 - rtb_RR;
  }

  /* Memory: '<S27>/Memory' */
  rtb_Memory_e_idx_3 = rtDW.Memory_PreviousInput_m[3];

  /* DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  if (rtDW.Memory_PreviousInput_m[3] || (rtDW.Integrator_PrevResetState_a[3] !=
       0)) {
    rtDW.Integrator_DSTATE_f[3] = 0.0;
  }

  /* DiscreteIntegrator: '<S134>/Filter' incorporates:
   *  Memory: '<S27>/Memory'
   */
  if (rtDW.Memory_PreviousInput_m[3] || (rtDW.Filter_PrevResetState_d[3] != 0))
  {
    rtDW.Filter_DSTATE_d[3] = 0.0;
  }

  /* Gain: '<S142>/Filter Coefficient' incorporates:
   *  Constant: '<S27>/Constant5'
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S133>/Derivative Gain'
   *  Sum: '<S134>/SumD'
   *  Sum: '<S97>/Sum3'
   */
  rtb_Filter_l_idx_0 = ((0.15 - rtb_Switch) * 0.0 - rtDW.Filter_DSTATE_d[0]) *
    100.0;
  rtb_Filter_l_idx_1 = ((0.15 - rtb_Switch_m) * 0.0 - rtDW.Filter_DSTATE_d[1]) *
    100.0;
  rtb_Filter_l_idx_2 = ((0.15 - rtb_RL) * 0.0 - rtDW.Filter_DSTATE_d[2]) * 100.0;
  rtb_Filter_l_idx_3 = ((0.15 - rtb_RR) * 0.0 - rtDW.Filter_DSTATE_d[3]) * 100.0;

  /* Sum: '<S148>/Sum' incorporates:
   *  Constant: '<S27>/Constant5'
   *  DiscreteIntegrator: '<S139>/Integrator'
   *  Gain: '<S142>/Filter Coefficient'
   *  Gain: '<S144>/Proportional Gain'
   *  Signum: '<S130>/SignPreIntegrator'
   *  Sum: '<S97>/Sum1'
   */
  rtb_SignPreIntegrator_idx_0 = ((0.15 - rtb_Switch) * -2.0 +
    rtDW.Integrator_DSTATE_f[0]) + rtb_Filter_l_idx_0;
  rtb_SignPreIntegrator_idx_1 = ((0.15 - rtb_Switch_m) * -2.0 +
    rtDW.Integrator_DSTATE_f[1]) + rtb_Filter_l_idx_1;
  rtb_SignPreIntegrator_idx_2 = ((0.15 - rtb_RL) * -2.0 +
    rtDW.Integrator_DSTATE_f[2]) + rtb_Filter_l_idx_2;
  rtb_SignPreIntegrator_idx_3 = ((0.15 - rtb_RR) * -2.0 +
    rtDW.Integrator_DSTATE_f[3]) + rtb_Filter_l_idx_3;

  /* SignalConversion generated from: '<S96>/ SFunction ' incorporates:
   *  MATLAB Function: '<S27>/MATLAB Function3'
   *  UnitDelay generated from: '<S27>/Unit Delay3'
   */
  rtb_y_o[0] = rtDW.UnitDelay3_1_DSTATE_f;
  rtb_y_o[1] = rtDW.UnitDelay3_2_DSTATE_b;
  rtb_y_o[2] = rtDW.UnitDelay3_3_DSTATE_k;
  rtb_y_o[3] = rtDW.UnitDelay3_4_DSTATE_o;

  /* MATLAB Function: '<S27>/MATLAB Function3' */
  rtb_y_o[0] *= 13.5;
  rtb_y_o[1] *= 13.5;
  rtb_y_o[2] *= 13.5;
  rtb_y_o[3] *= 13.5;

  /* Saturate: '<S146>/Saturation' */
  if (rtb_SignPreIntegrator_idx_0 > 2.0) {
    rtb_Integrator_iq_idx_0 = 2.0;
  } else if (rtb_SignPreIntegrator_idx_0 < 0.0) {
    rtb_Integrator_iq_idx_0 = 0.0;
  } else {
    rtb_Integrator_iq_idx_0 = rtb_SignPreIntegrator_idx_0;
  }

  /* MATLAB Function: '<S27>/MATLAB Function3' incorporates:
   *  Constant: '<S27>/Constant4'
   *  SampleTimeMath: '<S93>/TSamp'
   *  Sum: '<S27>/Sum'
   *  Sum: '<S93>/Diff'
   *  UnitDelay: '<S93>/UD'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integrator_iq_idx_0 = (0.2 / ((rtb_Integrator_iq_idx_0 + 0.1) * 67.5 *
    0.055224999999999996) + 1.0) * 0.235 * (rtb_y_o[0] / 0.235 -
    (rtb_Subtract_m4_tmp_0 - rtDW.UD_DSTATE_f[0]) * 0.235 * 0.2 /
    0.055224999999999996) / 13.5;

  /* Saturate: '<S146>/Saturation' */
  if (rtb_SignPreIntegrator_idx_1 > 2.0) {
    rtb_Integrator_iq_idx_1 = 2.0;
  } else if (rtb_SignPreIntegrator_idx_1 < 0.0) {
    rtb_Integrator_iq_idx_1 = 0.0;
  } else {
    rtb_Integrator_iq_idx_1 = rtb_SignPreIntegrator_idx_1;
  }

  /* MATLAB Function: '<S27>/MATLAB Function3' incorporates:
   *  Constant: '<S27>/Constant4'
   *  SampleTimeMath: '<S93>/TSamp'
   *  Sum: '<S27>/Sum'
   *  Sum: '<S93>/Diff'
   *  UnitDelay: '<S93>/UD'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integrator_iq_idx_1 = (0.2 / ((rtb_Integrator_iq_idx_1 + 0.1) * 67.5 *
    0.055224999999999996) + 1.0) * 0.235 * (rtb_y_o[1] / 0.235 -
    (rtb_Subtract_m4_tmp_1 - rtDW.UD_DSTATE_f[1]) * 0.235 * 0.2 /
    0.055224999999999996) / 13.5;

  /* Saturate: '<S146>/Saturation' */
  if (rtb_SignPreIntegrator_idx_2 > 2.0) {
    rtb_Integrator_iq_idx_2 = 2.0;
  } else if (rtb_SignPreIntegrator_idx_2 < 0.0) {
    rtb_Integrator_iq_idx_2 = 0.0;
  } else {
    rtb_Integrator_iq_idx_2 = rtb_SignPreIntegrator_idx_2;
  }

  /* MATLAB Function: '<S27>/MATLAB Function3' incorporates:
   *  Constant: '<S27>/Constant4'
   *  SampleTimeMath: '<S93>/TSamp'
   *  Sum: '<S27>/Sum'
   *  Sum: '<S93>/Diff'
   *  UnitDelay: '<S93>/UD'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integrator_iq_idx_2 = (0.2 / ((rtb_Integrator_iq_idx_2 + 0.1) * 67.5 *
    0.055224999999999996) + 1.0) * 0.235 * (rtb_y_o[2] / 0.235 -
    (rtb_Subtract_m4_tmp_2 - rtDW.UD_DSTATE_f[2]) * 0.235 * 0.2 /
    0.055224999999999996) / 13.5;

  /* Saturate: '<S146>/Saturation' */
  if (rtb_SignPreIntegrator_idx_3 > 2.0) {
    rtb_T_max_h_idx_0 = 2.0;
  } else if (rtb_SignPreIntegrator_idx_3 < 0.0) {
    rtb_T_max_h_idx_0 = 0.0;
  } else {
    rtb_T_max_h_idx_0 = rtb_SignPreIntegrator_idx_3;
  }

  /* MATLAB Function: '<S27>/MATLAB Function3' incorporates:
   *  Constant: '<S27>/Constant4'
   *  SampleTimeMath: '<S93>/TSamp'
   *  Sum: '<S27>/Sum'
   *  Sum: '<S93>/Diff'
   *  UnitDelay: '<S93>/UD'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integrator_iq_idx_3 = (0.2 / ((rtb_T_max_h_idx_0 + 0.1) * 67.5 *
    0.055224999999999996) + 1.0) * 0.235 * (rtb_y_o[3] / 0.235 -
    (rtb_Subtract_m4_tmp - rtDW.UD_DSTATE_f[3]) * 0.235 * 0.2 /
    0.055224999999999996) / 13.5;
  if (rtb_y_o[0] / 13.5 < 2.0) {
    rtb_Integrator_iq_idx_0 = 21.0;
  }

  if (rtb_y_o[1] / 13.5 < 2.0) {
    rtb_Integrator_iq_idx_1 = 21.0;
  }

  if (rtb_y_o[2] / 13.5 < 2.0) {
    rtb_Integrator_iq_idx_2 = 21.0;
  }

  if (rtb_y_o[3] / 13.5 < 2.0) {
    rtb_Integrator_iq_idx_3 = 21.0;
  }

  /* DiscreteIntegrator: '<S103>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_i != 0) {
    rtDW.Integrator_DSTATE_f3[0] = rtb_Integrator_iq_idx_0;
    rtDW.Integrator_DSTATE_f3[1] = rtb_Integrator_iq_idx_1;
    rtDW.Integrator_DSTATE_f3[2] = rtb_Integrator_iq_idx_2;
    rtDW.Integrator_DSTATE_f3[3] = rtb_Integrator_iq_idx_3;
  }

  if (rtb_Compare_n || (rtDW.Integrator_PrevResetState_m != 0)) {
    rtDW.Integrator_DSTATE_f3[0] = rtb_Integrator_iq_idx_0;
    rtDW.Integrator_DSTATE_f3[1] = rtb_Integrator_iq_idx_1;
    rtDW.Integrator_DSTATE_f3[2] = rtb_Integrator_iq_idx_2;
    rtDW.Integrator_DSTATE_f3[3] = rtb_Integrator_iq_idx_3;
  }

  /* SignalConversion generated from: '<S95>/ SFunction ' incorporates:
   *  MATLAB Function: '<S26>/MATLAB Function2'
   *  MATLAB Function: '<S27>/MATLAB Function2'
   *  SignalConversion generated from: '<S30>/ SFunction '
   */
  rtb_y_o[0] = rtb_Switch;
  rtb_y_o[1] = rtb_Switch_m;
  rtb_y_o[2] = rtb_RL;
  rtb_y_o[3] = rtb_RR;

  /* SignalConversion generated from: '<S95>/ SFunction ' incorporates:
   *  MATLAB Function: '<S27>/MATLAB Function2'
   *  UnitDelay generated from: '<S27>/Unit Delay2'
   */
  rtb_y_kf[0] = rtDW.UnitDelay2_1_DSTATE_i;
  rtb_y_kf[1] = rtDW.UnitDelay2_2_DSTATE_f;
  rtb_y_kf[2] = rtDW.UnitDelay2_3_DSTATE_j;
  rtb_y_kf[3] = rtDW.UnitDelay2_4_DSTATE_c;

  /* MATLAB Function: '<S27>/MATLAB Function2' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  UnitDelay: '<S27>/Unit Delay'
   */
  if (rtb_y_o[0] > 0.1) {
    rtb_T_max_h_idx_0 = rtDW.Integrator_DSTATE_f3[0];
  } else if (rtb_y_kf[0] < rtDW.UnitDelay_DSTATE_g[0] * 0.75 + 0.1) {
    rtb_T_max_h_idx_0 = rtDW.UnitDelay_DSTATE_g[0] + 1.0;
    if (rtDW.UnitDelay_DSTATE_g[0] + 1.0 > 21.0) {
      rtb_T_max_h_idx_0 = 21.0;
    }
  } else {
    rtb_T_max_h_idx_0 = rtDW.Integrator_DSTATE_f3[0];
  }

  if (rtb_y_o[1] > 0.1) {
    rtb_T_max_h_idx_1 = rtDW.Integrator_DSTATE_f3[1];
  } else if (rtb_y_kf[1] < rtDW.UnitDelay_DSTATE_g[1] * 0.75 + 0.1) {
    rtb_T_max_h_idx_1 = rtDW.UnitDelay_DSTATE_g[1] + 1.0;
    if (rtDW.UnitDelay_DSTATE_g[1] + 1.0 > 21.0) {
      rtb_T_max_h_idx_1 = 21.0;
    }
  } else {
    rtb_T_max_h_idx_1 = rtDW.Integrator_DSTATE_f3[1];
  }

  if (rtb_y_o[2] > 0.1) {
    rtb_T_max_h_idx_2 = rtDW.Integrator_DSTATE_f3[2];
  } else if (rtb_y_kf[2] < rtDW.UnitDelay_DSTATE_g[2] * 0.75 + 0.1) {
    rtb_T_max_h_idx_2 = rtDW.UnitDelay_DSTATE_g[2] + 1.0;
    if (rtDW.UnitDelay_DSTATE_g[2] + 1.0 > 21.0) {
      rtb_T_max_h_idx_2 = 21.0;
    }
  } else {
    rtb_T_max_h_idx_2 = rtDW.Integrator_DSTATE_f3[2];
  }

  if (rtb_y_o[3] > 0.1) {
    rtb_T_max_f = rtDW.Integrator_DSTATE_f3[3];
  } else if (rtb_y_kf[3] < rtDW.UnitDelay_DSTATE_g[3] * 0.75 + 0.1) {
    rtb_T_max_f = rtDW.UnitDelay_DSTATE_g[3] + 1.0;
    if (rtDW.UnitDelay_DSTATE_g[3] + 1.0 > 21.0) {
      rtb_T_max_f = 21.0;
    }
  } else {
    rtb_T_max_f = rtDW.Integrator_DSTATE_f3[3];
  }

  /* Fcn: '<S98>/Avoid Divide by Zero' incorporates:
   *  Constant: '<S98>/Time constant'
   *  MinMax: '<S98>/Max'
   */
  rtb_AvoidDividebyZero_h = fmax(rtDW.Probe_k[0], 0.1);

  /* Gain: '<S130>/ZeroGain' incorporates:
   *  Signum: '<S130>/SignPreIntegrator'
   */
  rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_0;

  /* DeadZone: '<S132>/DeadZone' incorporates:
   *  Gain: '<S130>/ZeroGain'
   *  Signum: '<S130>/SignPreIntegrator'
   */
  if (rtb_SignPreIntegrator_idx_0 > 2.0) {
    rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_0 - 2.0;
  } else if (rtb_SignPreIntegrator_idx_0 >= 0.0) {
    rtb_SignPreIntegrator = 0.0;
  }

  /* Signum: '<S130>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_Integrator_i_idx_0 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_Integrator_i_idx_0 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_Integrator_i_idx_0 = 0.0;
  } else {
    rtb_Integrator_i_idx_0 = (rtNaN);
  }

  /* Signum: '<S130>/SignPreIntegrator' incorporates:
   *  Constant: '<S27>/Constant5'
   *  Gain: '<S136>/Integral Gain'
   *  Sum: '<S97>/Sum2'
   */
  if (-(0.15 - rtb_Switch) < 0.0) {
    rtb_Abs3 = -1.0;
  } else if (-(0.15 - rtb_Switch) > 0.0) {
    rtb_Abs3 = 1.0;
  } else if (-(0.15 - rtb_Switch) == 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = (rtNaN);
  }

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S130>/Constant1'
   *  Constant: '<S27>/Constant5'
   *  DataTypeConversion: '<S130>/DataTypeConv1'
   *  DataTypeConversion: '<S130>/DataTypeConv2'
   *  Gain: '<S130>/ZeroGain'
   *  Gain: '<S136>/Integral Gain'
   *  Logic: '<S130>/AND3'
   *  RelationalOperator: '<S130>/Equal1'
   *  RelationalOperator: '<S130>/NotEqual'
   *  Signum: '<S130>/SignPreIntegrator'
   *  Sum: '<S97>/Sum2'
   */
  if ((0.0 * rtb_SignPreIntegrator_idx_0 != rtb_SignPreIntegrator) && ((int8_T)
       rtb_Integrator_i_idx_0 == (int8_T)rtb_Abs3)) {
    rtb_ZeroGain_a = 0.0;
  } else {
    rtb_ZeroGain_a = -(0.15 - rtb_Switch);
  }

  /* Sum: '<S94>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   */
  rtb_Integrator_iq_idx_0 -= rtDW.Integrator_DSTATE_f3[0];

  /* Gain: '<S130>/ZeroGain' incorporates:
   *  Signum: '<S130>/SignPreIntegrator'
   */
  rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_1;

  /* DeadZone: '<S132>/DeadZone' incorporates:
   *  Gain: '<S130>/ZeroGain'
   *  Signum: '<S130>/SignPreIntegrator'
   */
  if (rtb_SignPreIntegrator_idx_1 > 2.0) {
    rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_1 - 2.0;
  } else if (rtb_SignPreIntegrator_idx_1 >= 0.0) {
    rtb_SignPreIntegrator = 0.0;
  }

  /* Signum: '<S130>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_Integrator_i_idx_0 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_Integrator_i_idx_0 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_Integrator_i_idx_0 = 0.0;
  } else {
    rtb_Integrator_i_idx_0 = (rtNaN);
  }

  /* Signum: '<S130>/SignPreIntegrator' incorporates:
   *  Constant: '<S27>/Constant5'
   *  Gain: '<S136>/Integral Gain'
   *  Sum: '<S97>/Sum2'
   */
  if (-(0.15 - rtb_Switch_m) < 0.0) {
    rtb_Abs3 = -1.0;
  } else if (-(0.15 - rtb_Switch_m) > 0.0) {
    rtb_Abs3 = 1.0;
  } else if (-(0.15 - rtb_Switch_m) == 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = (rtNaN);
  }

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S130>/Constant1'
   *  Constant: '<S27>/Constant5'
   *  DataTypeConversion: '<S130>/DataTypeConv1'
   *  DataTypeConversion: '<S130>/DataTypeConv2'
   *  Gain: '<S130>/ZeroGain'
   *  Gain: '<S136>/Integral Gain'
   *  Logic: '<S130>/AND3'
   *  RelationalOperator: '<S130>/Equal1'
   *  RelationalOperator: '<S130>/NotEqual'
   *  Signum: '<S130>/SignPreIntegrator'
   *  Sum: '<S97>/Sum2'
   */
  if ((0.0 * rtb_SignPreIntegrator_idx_1 != rtb_SignPreIntegrator) && ((int8_T)
       rtb_Integrator_i_idx_0 == (int8_T)rtb_Abs3)) {
    rtb_ZeroGain_o = 0.0;
  } else {
    rtb_ZeroGain_o = -(0.15 - rtb_Switch_m);
  }

  /* Sum: '<S94>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   */
  rtb_Integrator_iq_idx_1 -= rtDW.Integrator_DSTATE_f3[1];

  /* Gain: '<S130>/ZeroGain' incorporates:
   *  Signum: '<S130>/SignPreIntegrator'
   */
  rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_2;

  /* DeadZone: '<S132>/DeadZone' incorporates:
   *  Gain: '<S130>/ZeroGain'
   *  Signum: '<S130>/SignPreIntegrator'
   */
  if (rtb_SignPreIntegrator_idx_2 > 2.0) {
    rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_2 - 2.0;
  } else if (rtb_SignPreIntegrator_idx_2 >= 0.0) {
    rtb_SignPreIntegrator = 0.0;
  }

  /* Signum: '<S130>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_Integrator_i_idx_0 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_Integrator_i_idx_0 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_Integrator_i_idx_0 = 0.0;
  } else {
    rtb_Integrator_i_idx_0 = (rtNaN);
  }

  /* Signum: '<S130>/SignPreIntegrator' incorporates:
   *  Constant: '<S27>/Constant5'
   *  Gain: '<S136>/Integral Gain'
   *  Sum: '<S97>/Sum2'
   */
  if (-(0.15 - rtb_RL) < 0.0) {
    rtb_Abs3 = -1.0;
  } else if (-(0.15 - rtb_RL) > 0.0) {
    rtb_Abs3 = 1.0;
  } else if (-(0.15 - rtb_RL) == 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = (rtNaN);
  }

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S130>/Constant1'
   *  Constant: '<S27>/Constant5'
   *  DataTypeConversion: '<S130>/DataTypeConv1'
   *  DataTypeConversion: '<S130>/DataTypeConv2'
   *  Gain: '<S130>/ZeroGain'
   *  Gain: '<S136>/Integral Gain'
   *  Logic: '<S130>/AND3'
   *  RelationalOperator: '<S130>/Equal1'
   *  RelationalOperator: '<S130>/NotEqual'
   *  Signum: '<S130>/SignPreIntegrator'
   *  Sum: '<S97>/Sum2'
   */
  if ((0.0 * rtb_SignPreIntegrator_idx_2 != rtb_SignPreIntegrator) && ((int8_T)
       rtb_Integrator_i_idx_0 == (int8_T)rtb_Abs3)) {
    rtb_ZeroGain_h = 0.0;
  } else {
    rtb_ZeroGain_h = -(0.15 - rtb_RL);
  }

  /* Sum: '<S94>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   */
  rtb_Integrator_iq_idx_2 -= rtDW.Integrator_DSTATE_f3[2];

  /* Gain: '<S130>/ZeroGain' incorporates:
   *  Signum: '<S130>/SignPreIntegrator'
   */
  rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_3;

  /* Sum: '<S94>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   */
  rtb_Integrator_iq_idx_3 -= rtDW.Integrator_DSTATE_f3[3];

  /* DeadZone: '<S132>/DeadZone' incorporates:
   *  Gain: '<S130>/ZeroGain'
   *  Signum: '<S130>/SignPreIntegrator'
   */
  if (rtb_SignPreIntegrator_idx_3 > 2.0) {
    rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_3 - 2.0;
  } else if (rtb_SignPreIntegrator_idx_3 >= 0.0) {
    rtb_SignPreIntegrator = 0.0;
  }

  /* Signum: '<S130>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0) {
    rtb_Integrator_i_idx_0 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_Integrator_i_idx_0 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_Integrator_i_idx_0 = 0.0;
  } else {
    rtb_Integrator_i_idx_0 = (rtNaN);
  }

  /* Signum: '<S130>/SignPreIntegrator' incorporates:
   *  Constant: '<S27>/Constant5'
   *  Gain: '<S136>/Integral Gain'
   *  Sum: '<S97>/Sum2'
   */
  if (-(0.15 - rtb_RR) < 0.0) {
    rtb_Abs3 = -1.0;
  } else if (-(0.15 - rtb_RR) > 0.0) {
    rtb_Abs3 = 1.0;
  } else if (-(0.15 - rtb_RR) == 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = (rtNaN);
  }

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S130>/Constant1'
   *  Constant: '<S27>/Constant5'
   *  DataTypeConversion: '<S130>/DataTypeConv1'
   *  DataTypeConversion: '<S130>/DataTypeConv2'
   *  Gain: '<S130>/ZeroGain'
   *  Gain: '<S136>/Integral Gain'
   *  Logic: '<S130>/AND3'
   *  RelationalOperator: '<S130>/Equal1'
   *  RelationalOperator: '<S130>/NotEqual'
   *  Signum: '<S130>/SignPreIntegrator'
   *  Sum: '<S97>/Sum2'
   */
  if ((0.0 * rtb_SignPreIntegrator_idx_3 != rtb_SignPreIntegrator) && ((int8_T)
       rtb_Integrator_i_idx_0 == (int8_T)rtb_Abs3)) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = -(0.15 - rtb_RR);
  }

  /* Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_SignPreIntegrator_idx_0 = look1_binlx(rtU.steering, rtConstP.pooled34,
    rtConstP.steering_to_wheel_angle_single_, 32U);

  /* Outputs for Atomic SubSystem: '<S159>/YRD_LUT-1' */
  /* Abs: '<S226>/Abs' incorporates:
   *  Abs: '<S194>/Abs'
   */
  rtb_Max_m_tmp = fabs(rtb_SignPreIntegrator_idx_0);

  /* Saturate: '<S226>/Saturation' */
  if (rtb_vx <= 3.0) {
    rtb_Abs3 = 3.0;
  } else {
    rtb_Abs3 = rtb_vx;
  }

  /* End of Saturate: '<S226>/Saturation' */

  /* Product: '<S226>/Divide2' incorporates:
   *  Abs: '<S200>/Abs3'
   *  Abs: '<S226>/Abs'
   *  Lookup_n-D: '<S226>/LUT_-3'
   *  Product: '<S226>/Divide'
   *  Product: '<S226>/Divide1'
   */
  rtb_Abs3 = rtb_SignPreIntegrator_idx_0 / rtb_Max_m_tmp * (look2_binlx
    (rtb_Max_m_tmp, rtb_Abs3, rtConstP.LUT_3_bp01Data, rtConstP.LUT_3_bp02Data,
     rtConstP.LUT_3_tableData, rtConstP.LUT_3_maxIndex, 100U) / rtb_Abs3);

  /* End of Outputs for SubSystem: '<S159>/YRD_LUT-1' */

  /* SignalConversion generated from: '<S173>/ SFunction ' incorporates:
   *  Constant: '<S160>/VX_ref'
   *  Constant: '<S160>/VY_ref'
   *  Constant: '<S160>/dT_FL_ref'
   *  Constant: '<S160>/dT_FL_ref1'
   *  Constant: '<S160>/dT_FL_ref2'
   *  Constant: '<S160>/dT_FL_ref3'
   *  Constant: '<S160>/dT_FL_ref4'
   *  Constant: '<S160>/dT_FR_ref'
   *  Constant: '<S160>/dT_RL_ref'
   *  Constant: '<S160>/dT_RR_ref'
   *  Inport: '<Root>/brake'
   *  MATLAB Function: '<S159>/MATLAB Function'
   *  MATLAB Function: '<S160>/MATLAB Function'
   *  SignalConversion generated from: '<S158>/C Caller'
   */
  rtb_y_ref_0[0] = 0.0;
  rtb_y_ref_0[1] = 0.0;
  rtb_y_ref_0[2] = (1.0 - rtU.brake) * rtb_Abs3 + rtb_Abs3 * rtU.brake;
  memset(&rtb_y_ref_0[3], 0, sizeof(real_T) << 3U);

  /* MATLAB Function: '<S160>/MATLAB Function' */
  memcpy(&rtb_y_f[0], &rtb_y_ref_0[0], 11U * sizeof(real_T));

  /* RateTransition: '<S174>/Rate Transition3' incorporates:
   *  Constant: '<S161>/Constant'
   *  Gain: '<S161>/Gain'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = rtb_SignPreIntegrator_idx_0;
  RateTransition3[1] = rtb_Switch;
  RateTransition3[2] = rtb_Switch_m;
  RateTransition3[3] = rtb_RL;
  RateTransition3[4] = rtb_RR;
  RateTransition3[5] = rtDW.UnitDelay_DSTATE[0];
  RateTransition3[6] = rtDW.UnitDelay_DSTATE[1];
  RateTransition3[7] = rtDW.UnitDelay_DSTATE[2];
  RateTransition3[8] = rtDW.UnitDelay_DSTATE[3];
  RateTransition3[9] = rtb_Subtract_e5;
  RateTransition3[10] = rtb_Subtract_o;
  RateTransition3[11] = rtb_Subtract_m;
  RateTransition3[12] = rtb_Subtract_km;
  RateTransition3[13] = 13.5 * rtU.omega_wheels_FL;
  RateTransition3[14] = 13.5 * rtU.omega_wheels_FR;
  RateTransition3[15] = 13.5 * rtU.omega_wheels_RL;
  RateTransition3[16] = 13.5 * rtU.omega_wheels_RR;
  RateTransition3[17] = 0.8;

  /* CFunction: '<S174>/C Function' incorporates:
   *  Constant: '<S174>/Constant3'
   */
  for (i = 0; i < 3; i++) {
    memcpy(&rtDW.CFunction[i * 18], &RateTransition3[0], 18U * sizeof(real_T));
  }

  /* End of CFunction: '<S174>/C Function' */

  /* Memory: '<S158>/Memory' incorporates:
   *  Switch: '<S207>/Switch3'
   */
  rtb_Switch3[0] = rtDW.Memory_PreviousInput[0];
  rtb_Switch3[1] = rtDW.Memory_PreviousInput[1];
  rtb_Switch3[2] = rtDW.Memory_PreviousInput[2];
  rtb_Switch3[3] = rtDW.Memory_PreviousInput[3];

  /* Saturate: '<S162>/Saturation' */
  if (rtb_vx <= 2.0) {
    /* SignalConversion generated from: '<S158>/C Caller' */
    rtb_x[0] = 2.0;
  } else {
    /* SignalConversion generated from: '<S158>/C Caller' */
    rtb_x[0] = rtb_vx;
  }

  /* End of Saturate: '<S162>/Saturation' */

  /* SignalConversion generated from: '<S158>/C Caller' incorporates:
   *  Inport: '<Root>/vy'
   */
  rtb_x[1] = rtU.vy;
  rtb_x[2] = rtb_Gain1;
  rtb_x[3] = rtb_Switch3[0];
  rtb_x[4] = rtb_Switch3[1];
  rtb_x[5] = rtb_Switch3[2];
  rtb_x[6] = rtb_Switch3[3];

  /* RelationalOperator: '<S235>/Compare' incorporates:
   *  Constant: '<S232>/Time constant'
   *  Constant: '<S235>/Constant'
   *  Sum: '<S232>/Sum1'
   */
  rtb_Compare_g = (0.079577471545947673 - rtDW.Probe_kx[0] <= 0.0);

  /* Gain: '<S229>/Gain4' incorporates:
   *  Gain: '<S238>/Gain4'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_Integrator_d_idx_0 = 128.91550390443524 * rtU.omega_wheels_FL;

  /* Saturate: '<S229>/Saturation1' incorporates:
   *  Gain: '<S229>/Gain4'
   */
  if (rtb_Integrator_d_idx_0 <= 0.0) {
    rtb_y_o[0] = 0.0;
  } else {
    rtb_y_o[0] = rtb_Integrator_d_idx_0;
  }

  /* Gain: '<S229>/Gain4' incorporates:
   *  Gain: '<S238>/Gain4'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  rtb_Integrator_d_idx_1 = 128.91550390443524 * rtU.omega_wheels_FR;

  /* Saturate: '<S229>/Saturation1' incorporates:
   *  Gain: '<S229>/Gain4'
   */
  if (rtb_Integrator_d_idx_1 <= 0.0) {
    rtb_y_o[1] = 0.0;
  } else {
    rtb_y_o[1] = rtb_Integrator_d_idx_1;
  }

  /* Gain: '<S229>/Gain4' incorporates:
   *  Gain: '<S238>/Gain4'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  rtb_Integrator_d_idx_2 = 128.91550390443524 * rtU.omega_wheels_RL;

  /* Saturate: '<S229>/Saturation1' incorporates:
   *  Gain: '<S229>/Gain4'
   */
  if (rtb_Integrator_d_idx_2 <= 0.0) {
    rtb_y_o[2] = 0.0;
  } else {
    rtb_y_o[2] = rtb_Integrator_d_idx_2;
  }

  /* Gain: '<S229>/Gain4' incorporates:
   *  Gain: '<S238>/Gain4'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_Integrator_d_idx_3 = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S229>/Saturation1' incorporates:
   *  Gain: '<S229>/Gain4'
   */
  if (rtb_Integrator_d_idx_3 <= 0.0) {
    rtb_y_o[3] = 0.0;
  } else {
    rtb_y_o[3] = rtb_Integrator_d_idx_3;
  }

  /* Lookup_n-D: '<S229>/2-D Lookup Table' incorporates:
   *  Constant: '<S227>/Constant7'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled46, 45U, &rtb_Gain1);
  fractions[1U] = rtb_Gain1;
  bpIndices[0U] = plook_binc(rtb_y_o[0], rtConstP.pooled45, 200U, &rtb_Gain1);
  fractions[0U] = rtb_Gain1;
  rtb_y_o[0] = intrp2d_l(bpIndices, fractions, rtConstP.pooled44, 201U);
  bpIndices[0U] = plook_binc(rtb_y_o[1], rtConstP.pooled45, 200U, &rtb_Gain1);
  fractions[0U] = rtb_Gain1;
  rtb_y_o[1] = intrp2d_l(bpIndices, fractions, rtConstP.pooled44, 201U);
  bpIndices[0U] = plook_binc(rtb_y_o[2], rtConstP.pooled45, 200U, &rtb_Gain1);
  fractions[0U] = rtb_Gain1;
  rtb_y_o[2] = intrp2d_l(bpIndices, fractions, rtConstP.pooled44, 201U);
  bpIndices[0U] = plook_binc(rtb_y_o[3], rtConstP.pooled45, 200U, &rtb_Gain1);
  fractions[0U] = rtb_Gain1;
  rtb_y_o[3] = intrp2d_l(bpIndices, fractions, rtConstP.pooled44, 201U);

  /* Gain: '<S229>/Gain' */
  rtb_SignPreIntegrator_idx_0 = 0.0098000000000000014 * rtb_y_o[0];
  rtb_SignPreIntegrator_idx_1 = 0.0098000000000000014 * rtb_y_o[1];
  rtb_SignPreIntegrator_idx_2 = 0.0098000000000000014 * rtb_y_o[2];
  rtb_SignPreIntegrator_idx_3 = 0.0098000000000000014 * rtb_y_o[3];

  /* DiscreteIntegrator: '<S237>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_it != 0) {
    rtDW.Integrator_DSTATE_j[0] = rtb_SignPreIntegrator_idx_0;
    rtDW.Integrator_DSTATE_j[1] = rtb_SignPreIntegrator_idx_1;
    rtDW.Integrator_DSTATE_j[2] = rtb_SignPreIntegrator_idx_2;
    rtDW.Integrator_DSTATE_j[3] = rtb_SignPreIntegrator_idx_3;
  }

  if (rtb_Compare_g || (rtDW.Integrator_PrevResetState_i != 0)) {
    rtDW.Integrator_DSTATE_j[0] = rtb_SignPreIntegrator_idx_0;
    rtDW.Integrator_DSTATE_j[1] = rtb_SignPreIntegrator_idx_1;
    rtDW.Integrator_DSTATE_j[2] = rtb_SignPreIntegrator_idx_2;
    rtDW.Integrator_DSTATE_j[3] = rtb_SignPreIntegrator_idx_3;
  }

  rtb_Integrator_i_idx_0 = rtDW.Integrator_DSTATE_j[0];

  /* MinMax: '<S227>/Min' incorporates:
   *  Constant: '<S229>/Constant'
   *  DiscreteIntegrator: '<S237>/Integrator'
   *  RelationalOperator: '<S231>/LowerRelop1'
   *  RelationalOperator: '<S231>/UpperRelop'
   *  Switch: '<S231>/Switch'
   *  Switch: '<S231>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_j[0] > 21.0) {
    rtb_Abs3 = 21.0;
  } else if (rtDW.Integrator_DSTATE_j[0] < 0.0) {
    /* Switch: '<S231>/Switch' incorporates:
     *  Constant: '<S229>/Constant'
     */
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtDW.Integrator_DSTATE_j[0];
  }

  /* Lookup_n-D: '<S227>/Max_Torque_Overload_Motor_LUT' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Lookup_n-D: '<S227>/Max_Torque_Overload_Inverter_LUT'
   */
  rtb_max_torque_overload_inver_0 = look1_binlx(0.0, rtConstP.pooled41,
    rtConstP.pooled40, 2U);

  /* MinMax: '<S227>/Min' incorporates:
   *  Lookup_n-D: '<S227>/Max_Torque_Overload_Motor_LUT'
   *  MinMax: '<S228>/Min1'
   */
  rtb_max_torque_overload_inver_0 = fmin(fmin(rtb_max_torque_overload_inver_0,
    rtb_max_torque_overload_inver_0), 20.972);
  rtb_max_torque_overload_inverte[0] = fmin(rtb_max_torque_overload_inver_0,
    rtb_Abs3);

  /* DiscreteIntegrator: '<S237>/Integrator' */
  rtb_Integrator_i_idx_1 = rtDW.Integrator_DSTATE_j[1];

  /* MinMax: '<S227>/Min' incorporates:
   *  Constant: '<S229>/Constant'
   *  DiscreteIntegrator: '<S237>/Integrator'
   *  RelationalOperator: '<S231>/LowerRelop1'
   *  RelationalOperator: '<S231>/UpperRelop'
   *  Switch: '<S231>/Switch'
   *  Switch: '<S231>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_j[1] > 21.0) {
    rtb_Abs3 = 21.0;
  } else if (rtDW.Integrator_DSTATE_j[1] < 0.0) {
    /* Switch: '<S231>/Switch' incorporates:
     *  Constant: '<S229>/Constant'
     */
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtDW.Integrator_DSTATE_j[1];
  }

  rtb_max_torque_overload_inverte[1] = fmin(rtb_max_torque_overload_inver_0,
    rtb_Abs3);

  /* DiscreteIntegrator: '<S237>/Integrator' */
  rtb_Integrator_i_idx_2 = rtDW.Integrator_DSTATE_j[2];

  /* MinMax: '<S227>/Min' incorporates:
   *  Constant: '<S229>/Constant'
   *  DiscreteIntegrator: '<S237>/Integrator'
   *  RelationalOperator: '<S231>/LowerRelop1'
   *  RelationalOperator: '<S231>/UpperRelop'
   *  Switch: '<S231>/Switch'
   *  Switch: '<S231>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_j[2] > 21.0) {
    rtb_Abs3 = 21.0;
  } else if (rtDW.Integrator_DSTATE_j[2] < 0.0) {
    /* Switch: '<S231>/Switch' incorporates:
     *  Constant: '<S229>/Constant'
     */
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtDW.Integrator_DSTATE_j[2];
  }

  rtb_max_torque_overload_inverte[2] = fmin(rtb_max_torque_overload_inver_0,
    rtb_Abs3);

  /* DiscreteIntegrator: '<S237>/Integrator' */
  rtb_Integrator_i_idx_3 = rtDW.Integrator_DSTATE_j[3];

  /* MinMax: '<S227>/Min' incorporates:
   *  Constant: '<S229>/Constant'
   *  DiscreteIntegrator: '<S237>/Integrator'
   *  RelationalOperator: '<S231>/LowerRelop1'
   *  RelationalOperator: '<S231>/UpperRelop'
   *  Switch: '<S231>/Switch'
   *  Switch: '<S231>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_j[3] > 21.0) {
    rtb_Abs3 = 21.0;
  } else if (rtDW.Integrator_DSTATE_j[3] < 0.0) {
    /* Switch: '<S231>/Switch' incorporates:
     *  Constant: '<S229>/Constant'
     */
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtDW.Integrator_DSTATE_j[3];
  }

  rtb_max_torque_overload_inverte[3] = fmin(rtb_max_torque_overload_inver_0,
    rtb_Abs3);

  /* SignalConversion generated from: '<S216>/2-D Lookup Table' */
  rtb_y_o[0] = rtb_Subtract_e5;
  rtb_y_o[1] = rtb_Subtract_o;
  rtb_y_o[2] = rtb_Subtract_m;
  rtb_y_o[3] = rtb_Subtract_km;

  /* Lookup_n-D: '<S216>/2-D Lookup Table' */
  rtb_Gain1 = look2_binlx(rtb_y_o[0], rtb_Abs_o_idx_0, rtConstP.pooled48,
    rtConstP.pooled49, rtConstP.uDLookupTable_tableData, rtConstP.pooled55, 30U);
  rtb_Subtract_m = look2_binlx(rtb_y_o[1], rtb_Abs_o_idx_1, rtConstP.pooled48,
    rtConstP.pooled49, rtConstP.uDLookupTable_tableData, rtConstP.pooled55, 30U);
  rtb_Subtract_km = look2_binlx(rtb_y_o[2], rtb_Abs_o_idx_2, rtConstP.pooled48,
    rtConstP.pooled49, rtConstP.uDLookupTable_tableData, rtConstP.pooled55, 30U);
  rtb_UnaryMinus_ot_idx_3 = look2_binlx(rtb_y_o[3], rtb_Abs_o_idx_3,
    rtConstP.pooled48, rtConstP.pooled49, rtConstP.uDLookupTable_tableData,
    rtConstP.pooled55, 30U);

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_Subtract_e5 = 3.5714285714285712 * rtU.brake;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Subtract_e5 > 1.0) {
    rtb_Subtract_e5 = 1.0;
  } else if (rtb_Subtract_e5 < 0.0) {
    rtb_Subtract_e5 = 0.0;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Switch: '<S211>/Switch' */
  rtb_Subtract_o = !(rtb_Subtract_e5 > 0.95);

  /* Saturate: '<S216>/Saturation1' incorporates:
   *  Gain: '<S216>/Gain'
   *  Product: '<S216>/Product'
   */
  rtb_Gain1 = 0.017407407407407406 * rtb_Gain1 * 1000.0;

  /* Saturate: '<S227>/Saturation_Positive' */
  if (rtb_max_torque_overload_inverte[0] <= 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtb_max_torque_overload_inverte[0];
  }

  /* Saturate: '<S216>/Saturation1' */
  if (rtb_Gain1 <= 0.0) {
    rtb_Gain1 = 0.0;
  }

  /* Product: '<S211>/Product' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  MinMax: '<S171>/Min'
   *  Saturate: '<S227>/Saturation_Positive'
   */
  rtb_Product[0] = fmin(fmin(rtb_Abs3, rtDW.Integrator_DSTATE_f3[0]), rtb_Gain1)
    * rtb_Subtract_o;

  /* Saturate: '<S216>/Saturation1' incorporates:
   *  Gain: '<S216>/Gain'
   *  Product: '<S216>/Product'
   */
  rtb_Gain1 = 0.017407407407407406 * rtb_Subtract_m * 1000.0;

  /* Saturate: '<S227>/Saturation_Positive' */
  if (rtb_max_torque_overload_inverte[1] <= 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtb_max_torque_overload_inverte[1];
  }

  /* Saturate: '<S216>/Saturation1' */
  if (rtb_Gain1 <= 0.0) {
    rtb_Gain1 = 0.0;
  }

  /* Product: '<S211>/Product' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  MinMax: '<S171>/Min'
   *  Saturate: '<S227>/Saturation_Positive'
   */
  rtb_Product[1] = fmin(fmin(rtb_Abs3, rtDW.Integrator_DSTATE_f3[1]), rtb_Gain1)
    * rtb_Subtract_o;

  /* Saturate: '<S216>/Saturation1' incorporates:
   *  Gain: '<S216>/Gain'
   *  Product: '<S216>/Product'
   */
  rtb_Gain1 = 0.017407407407407406 * rtb_Subtract_km * 1000.0;

  /* Saturate: '<S227>/Saturation_Positive' */
  if (rtb_max_torque_overload_inverte[2] <= 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtb_max_torque_overload_inverte[2];
  }

  /* Saturate: '<S216>/Saturation1' */
  if (rtb_Gain1 <= 0.0) {
    rtb_Gain1 = 0.0;
  }

  /* Product: '<S211>/Product' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  MinMax: '<S171>/Min'
   *  Saturate: '<S227>/Saturation_Positive'
   */
  rtb_Product[2] = fmin(fmin(rtb_Abs3, rtDW.Integrator_DSTATE_f3[2]), rtb_Gain1)
    * rtb_Subtract_o;

  /* Saturate: '<S216>/Saturation1' incorporates:
   *  Gain: '<S216>/Gain'
   *  Product: '<S216>/Product'
   */
  rtb_Gain1 = 0.017407407407407406 * rtb_UnaryMinus_ot_idx_3 * 1000.0;

  /* Saturate: '<S227>/Saturation_Positive' */
  if (rtb_max_torque_overload_inverte[3] <= 0.0) {
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtb_max_torque_overload_inverte[3];
  }

  /* Saturate: '<S216>/Saturation1' */
  if (rtb_Gain1 <= 0.0) {
    rtb_Gain1 = 0.0;
  }

  /* Product: '<S211>/Product' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  MinMax: '<S171>/Min'
   *  Saturate: '<S227>/Saturation_Positive'
   */
  rtb_Product[3] = fmin(fmin(rtb_Abs3, rtDW.Integrator_DSTATE_f3[3]), rtb_Gain1)
    * rtb_Subtract_o;

  /* Lookup_n-D: '<S216>/2-D Lookup Table1' */
  rtb_y_o[0] = look2_binlx(rtb_y_o[0], rtb_Abs_o_idx_0, rtConstP.pooled48,
    rtConstP.pooled49, rtConstP.uDLookupTable1_tableData, rtConstP.pooled55, 30U);
  rtb_y_o[1] = look2_binlx(rtb_y_o[1], rtb_Abs_o_idx_1, rtConstP.pooled48,
    rtConstP.pooled49, rtConstP.uDLookupTable1_tableData, rtConstP.pooled55, 30U);
  rtb_y_o[2] = look2_binlx(rtb_y_o[2], rtb_Abs_o_idx_2, rtConstP.pooled48,
    rtConstP.pooled49, rtConstP.uDLookupTable1_tableData, rtConstP.pooled55, 30U);
  rtb_y_o[3] = look2_binlx(rtb_y_o[3], rtb_Abs_o_idx_3, rtConstP.pooled48,
    rtConstP.pooled49, rtConstP.uDLookupTable1_tableData, rtConstP.pooled55, 30U);

  /* RelationalOperator: '<S244>/Compare' incorporates:
   *  Constant: '<S241>/Time constant'
   *  Constant: '<S244>/Constant'
   *  Sum: '<S241>/Sum1'
   */
  rtb_Compare_d = (0.079577471545947673 - rtDW.Probe_b[0] <= 0.0);

  /* Lookup_n-D: '<S238>/2-D Lookup Table' incorporates:
   *  Constant: '<S228>/Constant7'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled46, 45U, &rtb_Gain1);
  fractions_0[1U] = rtb_Gain1;

  /* Saturate: '<S238>/Saturation1' */
  if (rtb_Integrator_d_idx_0 <= 0.0) {
    rtb_Integrator_d_idx_0 = 0.0;
  }

  /* Lookup_n-D: '<S238>/2-D Lookup Table' */
  bpIndices_0[0U] = plook_binc(rtb_Integrator_d_idx_0, rtConstP.pooled45, 200U,
    &rtb_Gain1);
  fractions_0[0U] = rtb_Gain1;
  rtb_Abs_o_idx_0 = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled44, 201U);

  /* Saturate: '<S238>/Saturation1' */
  if (rtb_Integrator_d_idx_1 <= 0.0) {
    rtb_Integrator_d_idx_1 = 0.0;
  }

  /* Lookup_n-D: '<S238>/2-D Lookup Table' */
  bpIndices_0[0U] = plook_binc(rtb_Integrator_d_idx_1, rtConstP.pooled45, 200U,
    &rtb_Gain1);
  fractions_0[0U] = rtb_Gain1;
  rtb_Abs_o_idx_1 = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled44, 201U);

  /* Saturate: '<S238>/Saturation1' */
  if (rtb_Integrator_d_idx_2 <= 0.0) {
    rtb_Integrator_d_idx_2 = 0.0;
  }

  /* Lookup_n-D: '<S238>/2-D Lookup Table' */
  bpIndices_0[0U] = plook_binc(rtb_Integrator_d_idx_2, rtConstP.pooled45, 200U,
    &rtb_Gain1);
  fractions_0[0U] = rtb_Gain1;
  rtb_Abs_o_idx_2 = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled44, 201U);

  /* Saturate: '<S238>/Saturation1' */
  if (rtb_Integrator_d_idx_3 <= 0.0) {
    rtb_Integrator_d_idx_3 = 0.0;
  }

  /* Lookup_n-D: '<S238>/2-D Lookup Table' */
  bpIndices_0[0U] = plook_binc(rtb_Integrator_d_idx_3, rtConstP.pooled45, 200U,
    &rtb_Gain1);
  fractions_0[0U] = rtb_Gain1;

  /* Gain: '<S238>/Gain' incorporates:
   *  Lookup_n-D: '<S238>/2-D Lookup Table'
   */
  rtb_Abs_o_idx_0 *= 0.0098000000000000014;
  rtb_Abs_o_idx_1 *= 0.0098000000000000014;
  rtb_Abs_o_idx_2 *= 0.0098000000000000014;
  rtb_Abs_o_idx_3 = 0.0098000000000000014 * intrp2d_l(bpIndices_0, fractions_0,
    rtConstP.pooled44, 201U);

  /* DiscreteIntegrator: '<S246>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_b != 0) {
    rtDW.Integrator_DSTATE_ff[0] = rtb_Abs_o_idx_0;
    rtDW.Integrator_DSTATE_ff[1] = rtb_Abs_o_idx_1;
    rtDW.Integrator_DSTATE_ff[2] = rtb_Abs_o_idx_2;
    rtDW.Integrator_DSTATE_ff[3] = rtb_Abs_o_idx_3;
  }

  if (rtb_Compare_d || (rtDW.Integrator_PrevResetState_f != 0)) {
    rtDW.Integrator_DSTATE_ff[0] = rtb_Abs_o_idx_0;
    rtDW.Integrator_DSTATE_ff[1] = rtb_Abs_o_idx_1;
    rtDW.Integrator_DSTATE_ff[2] = rtb_Abs_o_idx_2;
    rtDW.Integrator_DSTATE_ff[3] = rtb_Abs_o_idx_3;
  }

  rtb_Integrator_d_idx_0 = rtDW.Integrator_DSTATE_ff[0];
  rtb_Integrator_d_idx_1 = rtDW.Integrator_DSTATE_ff[1];
  rtb_Integrator_d_idx_2 = rtDW.Integrator_DSTATE_ff[2];
  rtb_Integrator_d_idx_3 = rtDW.Integrator_DSTATE_ff[3];

  /* Sum: '<S222>/Subtract' incorporates:
   *  Gain: '<S216>/Gain1'
   *  Gain: '<S222>/Wheel2Motor'
   *  Product: '<S216>/Product1'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Gain1 = 0.017407407407407406 * rtb_y_o[0] * 1000.0 + 0.07407407407407407 *
    rtDW.UnitDelay_DSTATE[0];

  /* Switch: '<S240>/Switch2' incorporates:
   *  Constant: '<S238>/Constant'
   *  DiscreteIntegrator: '<S246>/Integrator'
   *  RelationalOperator: '<S240>/LowerRelop1'
   *  RelationalOperator: '<S240>/UpperRelop'
   *  Switch: '<S240>/Switch'
   */
  if (rtDW.Integrator_DSTATE_ff[0] > 21.0) {
    rtb_Abs3 = 21.0;
  } else if (rtDW.Integrator_DSTATE_ff[0] < 0.0) {
    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S238>/Constant'
     */
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtDW.Integrator_DSTATE_ff[0];
  }

  /* MinMax: '<S228>/Min1' */
  rtb_Subtract_m = fmin(rtb_max_torque_overload_inver_0, rtb_Abs3);

  /* Saturate: '<S216>/Saturation' */
  if (rtb_Gain1 >= 0.0) {
    rtb_Gain1 = 0.0;
  }

  /* Saturate: '<S228>/Saturation_Positive' */
  if (rtb_Subtract_m <= 0.0) {
    rtb_Subtract_m = 0.0;
  }

  /* MinMax: '<S171>/Min1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  UnaryMinus: '<S171>/Unary Minus'
   */
  rtb_y_kf[0] = fmax(fmax(rtb_Gain1, -rtb_Subtract_m), rtDW.Integrator_DSTATE_h
                     [0]);

  /* Sum: '<S222>/Subtract' incorporates:
   *  Gain: '<S216>/Gain1'
   *  Gain: '<S222>/Wheel2Motor'
   *  Product: '<S216>/Product1'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Gain1 = 0.017407407407407406 * rtb_y_o[1] * 1000.0 + 0.07407407407407407 *
    rtDW.UnitDelay_DSTATE[1];

  /* Switch: '<S240>/Switch2' incorporates:
   *  Constant: '<S238>/Constant'
   *  DiscreteIntegrator: '<S246>/Integrator'
   *  RelationalOperator: '<S240>/LowerRelop1'
   *  RelationalOperator: '<S240>/UpperRelop'
   *  Switch: '<S240>/Switch'
   */
  if (rtDW.Integrator_DSTATE_ff[1] > 21.0) {
    rtb_Abs3 = 21.0;
  } else if (rtDW.Integrator_DSTATE_ff[1] < 0.0) {
    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S238>/Constant'
     */
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtDW.Integrator_DSTATE_ff[1];
  }

  /* MinMax: '<S228>/Min1' */
  rtb_Subtract_m = fmin(rtb_max_torque_overload_inver_0, rtb_Abs3);

  /* Saturate: '<S216>/Saturation' */
  if (rtb_Gain1 >= 0.0) {
    rtb_Gain1 = 0.0;
  }

  /* Saturate: '<S228>/Saturation_Positive' */
  if (rtb_Subtract_m <= 0.0) {
    rtb_Subtract_m = 0.0;
  }

  /* MinMax: '<S171>/Min1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  UnaryMinus: '<S171>/Unary Minus'
   */
  rtb_y_kf[1] = fmax(fmax(rtb_Gain1, -rtb_Subtract_m), rtDW.Integrator_DSTATE_h
                     [1]);

  /* Sum: '<S222>/Subtract' incorporates:
   *  Gain: '<S216>/Gain1'
   *  Gain: '<S222>/Wheel2Motor'
   *  Product: '<S216>/Product1'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Gain1 = 0.017407407407407406 * rtb_y_o[2] * 1000.0 + 0.07407407407407407 *
    rtDW.UnitDelay_DSTATE[2];

  /* Switch: '<S240>/Switch2' incorporates:
   *  Constant: '<S238>/Constant'
   *  DiscreteIntegrator: '<S246>/Integrator'
   *  RelationalOperator: '<S240>/LowerRelop1'
   *  RelationalOperator: '<S240>/UpperRelop'
   *  Switch: '<S240>/Switch'
   */
  if (rtDW.Integrator_DSTATE_ff[2] > 21.0) {
    rtb_Abs3 = 21.0;
  } else if (rtDW.Integrator_DSTATE_ff[2] < 0.0) {
    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S238>/Constant'
     */
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtDW.Integrator_DSTATE_ff[2];
  }

  /* MinMax: '<S228>/Min1' */
  rtb_Subtract_m = fmin(rtb_max_torque_overload_inver_0, rtb_Abs3);

  /* Saturate: '<S216>/Saturation' */
  if (rtb_Gain1 >= 0.0) {
    rtb_Gain1 = 0.0;
  }

  /* Saturate: '<S228>/Saturation_Positive' */
  if (rtb_Subtract_m <= 0.0) {
    rtb_Subtract_m = 0.0;
  }

  /* MinMax: '<S171>/Min1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  UnaryMinus: '<S171>/Unary Minus'
   */
  rtb_y_kf[2] = fmax(fmax(rtb_Gain1, -rtb_Subtract_m), rtDW.Integrator_DSTATE_h
                     [2]);

  /* Sum: '<S222>/Subtract' incorporates:
   *  Gain: '<S216>/Gain1'
   *  Gain: '<S222>/Wheel2Motor'
   *  Product: '<S216>/Product1'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Gain1 = 0.017407407407407406 * rtb_y_o[3] * 1000.0 + 0.07407407407407407 *
    rtDW.UnitDelay_DSTATE[3];

  /* Switch: '<S240>/Switch2' incorporates:
   *  Constant: '<S238>/Constant'
   *  DiscreteIntegrator: '<S246>/Integrator'
   *  RelationalOperator: '<S240>/LowerRelop1'
   *  RelationalOperator: '<S240>/UpperRelop'
   *  Switch: '<S240>/Switch'
   */
  if (rtDW.Integrator_DSTATE_ff[3] > 21.0) {
    rtb_Abs3 = 21.0;
  } else if (rtDW.Integrator_DSTATE_ff[3] < 0.0) {
    /* Switch: '<S240>/Switch' incorporates:
     *  Constant: '<S238>/Constant'
     */
    rtb_Abs3 = 0.0;
  } else {
    rtb_Abs3 = rtDW.Integrator_DSTATE_ff[3];
  }

  /* MinMax: '<S228>/Min1' */
  rtb_Subtract_m = fmin(rtb_max_torque_overload_inver_0, rtb_Abs3);

  /* Saturate: '<S216>/Saturation' */
  if (rtb_Gain1 >= 0.0) {
    rtb_Gain1 = 0.0;
  }

  /* Saturate: '<S228>/Saturation_Positive' */
  if (rtb_Subtract_m <= 0.0) {
    rtb_Subtract_m = 0.0;
  }

  /* MinMax: '<S171>/Min1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  UnaryMinus: '<S171>/Unary Minus'
   */
  rtb_y_kf[3] = fmax(fmax(rtb_Gain1, -rtb_Subtract_m), rtDW.Integrator_DSTATE_h
                     [3]);

  /* CombinatorialLogic: '<S218>/Logic' incorporates:
   *  Constant: '<S210>/Constant'
   *  Constant: '<S210>/Constant1'
   *  Memory: '<S218>/Memory'
   *  RelationalOperator: '<S210>/Less Than'
   *  RelationalOperator: '<S210>/Less Than1'
   */
  rowIdx = (int32_T)(((((uint32_T)(rtb_Switch <= -0.6) << 1) + (rtb_Switch >=
    -0.3)) << 1) + rtDW.Memory_PreviousInput_n);
  rtb_Logic_idx_0 = rtConstP.pooled58[(uint32_T)rowIdx];
  rtb_Logic_idx_1 = rtConstP.pooled58[rowIdx + 8U];

  /* CombinatorialLogic: '<S219>/Logic' incorporates:
   *  Constant: '<S210>/Constant'
   *  Constant: '<S210>/Constant1'
   *  Memory: '<S219>/Memory'
   *  RelationalOperator: '<S210>/Less Than'
   *  RelationalOperator: '<S210>/Less Than1'
   */
  rowIdx = (int32_T)(((((uint32_T)(rtb_Switch_m <= -0.6) << 1) + (rtb_Switch_m >=
    -0.3)) << 1) + rtDW.Memory_PreviousInput_i);
  rtb_Logic_e_idx_0 = rtConstP.pooled58[(uint32_T)rowIdx];
  rtb_Logic_e_idx_1 = rtConstP.pooled58[rowIdx + 8U];

  /* CombinatorialLogic: '<S220>/Logic' incorporates:
   *  Constant: '<S210>/Constant'
   *  Constant: '<S210>/Constant1'
   *  Memory: '<S220>/Memory'
   *  RelationalOperator: '<S210>/Less Than'
   *  RelationalOperator: '<S210>/Less Than1'
   */
  rowIdx = (int32_T)(((((uint32_T)(rtb_RL <= -0.6) << 1) + (rtb_RL >= -0.3)) <<
                      1) + rtDW.Memory_PreviousInput_h);
  rtb_Logic_l_idx_0 = rtConstP.pooled58[(uint32_T)rowIdx];
  rtb_Logic_l_idx_1 = rtConstP.pooled58[rowIdx + 8U];

  /* CombinatorialLogic: '<S221>/Logic' incorporates:
   *  Constant: '<S210>/Constant'
   *  Constant: '<S210>/Constant1'
   *  Memory: '<S221>/Memory'
   *  RelationalOperator: '<S210>/Less Than'
   *  RelationalOperator: '<S210>/Less Than1'
   */
  rowIdx = (int32_T)(((((uint32_T)(rtb_RR <= -0.6) << 1) + (rtb_RR >= -0.3)) <<
                      1) + rtDW.Memory_PreviousInput_d);
  rtb_Logic_k_idx_0 = rtConstP.pooled58[(uint32_T)rowIdx];

  /* Product: '<S210>/Product' incorporates:
   *  CombinatorialLogic: '<S221>/Logic'
   */
  rtb_y_o[0] = rtb_y_kf[0] * (real_T)rtb_Logic_idx_1;
  rtb_y_o[1] = rtb_y_kf[1] * (real_T)rtb_Logic_e_idx_1;
  rtb_y_o[2] = (real_T)rtb_Logic_l_idx_1 * rtb_y_kf[2];
  rtb_y_o[3] = (real_T)rtConstP.pooled58[rowIdx + 8U] * rtb_y_kf[3];

  /* CombinatorialLogic: '<S195>/Logic' incorporates:
   *  Constant: '<S194>/Constant1'
   *  Constant: '<S194>/Constant4'
   *  Memory: '<S195>/Memory'
   *  RelationalOperator: '<S194>/Less Than'
   *  RelationalOperator: '<S194>/Less Than2'
   */
  rtb_Logic_idx_1 = rtConstP.pooled58[((((uint32_T)(0.034906585039886591 <=
    rtb_Max_m_tmp) << 1) + (rtb_Max_m_tmp < 0.0087266462599716477)) << 1) +
    rtDW.Memory_PreviousInput_e];

  /* SignalConversion generated from: '<S212>/ SFunction ' incorporates:
   *  MATLAB Function: '<S171>/Cross Check'
   */
  rtb_Subtract_o = rtb_y_o[1];

  /* MATLAB Function: '<S171>/Cross Check' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/throttle'
   *  SignalConversion generated from: '<S212>/ SFunction '
   */
  rtb_max_torque_overload_inverte[0] = rtb_y_o[0];
  rtb_max_torque_overload_inverte[1] = rtb_y_o[1];
  rtb_max_torque_overload_inverte[2] = rtb_y_o[2];
  rtb_max_torque_overload_inverte[3] = rtb_y_o[3];
  if (rtb_Logic_idx_1) {
    rowIdx = 0;
  } else {
    rowIdx = 1;
  }

  if (rowIdx == 0) {
    if (rtb_y_o[0] > rtb_Product[0]) {
      rtb_max_torque_overload_inverte[0] = rtb_Product[0] - rtb_Subtract_o;
    }

    if (rtb_y_o[1] > rtb_Product[1]) {
      rtb_max_torque_overload_inverte[1] = rtb_Product[1] - rtb_Subtract_o;
    }

    if (rtb_y_o[2] > rtb_Product[2]) {
      rtb_max_torque_overload_inverte[2] = rtb_Product[2] - rtb_Subtract_o;
    }

    if (rtb_y_o[3] > rtb_Product[3]) {
      rtb_max_torque_overload_inverte[3] = rtb_Product[3] - rtb_Subtract_o;
    }
  } else if (rtU.throttle > 0.05) {
    rtb_max_torque_overload_inverte[0] = 0.0;
    rtb_max_torque_overload_inverte[1] = 0.0;
    rtb_max_torque_overload_inverte[2] = 0.0;
    rtb_max_torque_overload_inverte[3] = 0.0;
  } else if (rtU.brake > 0.05) {
    rtb_Product[0] = 0.0;
    rtb_Product[1] = 0.0;
    rtb_Product[2] = 0.0;
    rtb_Product[3] = 0.0;
  }

  /* MATLAB Function: '<S171>/MATLAB Function1' */
  MATLABFunction(rtb_max_torque_overload_inverte, rtb_y_kf);

  /* MATLAB Function: '<S171>/MATLAB Function' */
  MATLABFunction(rtb_Product, rtb_y_o);

  /* MATLAB Function: '<S163>/MATLAB Function1' incorporates:
   *  Constant: '<S163>/Constant'
   */
  for (b_exit = 0; b_exit < 2; b_exit++) {
    i = b_exit << 2;
    rtb_y_c[i] = 100000.0;
    rtb_y_c[i + 1] = 100000.0;
    rtb_y_c[i + 2] = 100000.0;
    rtb_y_c[i + 3] = 100000.0;
  }

  /* End of MATLAB Function: '<S163>/MATLAB Function1' */

  /* UnaryMinus: '<S163>/Unary Minus' */
  for (i = 0; i < 8; i++) {
    rtb_UnaryMinus_ci[i] = -rtb_y_c[i];
  }

  /* End of UnaryMinus: '<S163>/Unary Minus' */

  /* Outputs for IfAction SubSystem: '<S165>/Simple torque' incorporates:
   *  ActionPort: '<S179>/Action Port'
   */
  /* If: '<S165>/If' incorporates:
   *  MATLAB Function: '<S196>/MATLAB Function4'
   *  MinMax: '<S186>/Min'
   *  MinMax: '<S186>/Min1'
   */
  rtb_RR = fmin(rtb_Product[0], rtb_Product[1]);
  rtb_max_torque_overload_inver_0 = fmin(rtb_Product[2], rtb_Product[3]);

  /* End of Outputs for SubSystem: '<S165>/Simple torque' */

  /* MATLAB Function: '<S196>/MATLAB Function4' */
  rtb_Subtract_m = (rtb_RR + rtb_max_torque_overload_inver_0) * 2.0;

  /* Product: '<S196>/Product' incorporates:
   *  Constant: '<S196>/Constant1'
   *  Constant: '<S196>/Constant2'
   *  Constant: '<S202>/Constant'
   *  Constant: '<S202>/Exponent < 0'
   *  Gain: '<S196>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S196>/ '
   *  Math: '<S202>/Power'
   *  Product: '<S196>/Product1'
   *  Product: '<S202>/Divide'
   *  Product: '<S202>/Divide1'
   *  RelationalOperator: '<S196>/Less Than'
   *  RelationalOperator: '<S196>/Less Than1'
   *  Sum: '<S196>/Subtract1'
   *  Sum: '<S202>/Subtract'
   *  Sum: '<S202>/Sum'
   */
  rtb_Abs3 = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle), -1.5) +
                     1.0) - rtb_Subtract_e5) * (real_T)(int8_T)((int8_T)
    (rtb_Subtract_e5 >= 0.05) ^ (int8_T)(rtU.throttle >= 0.05)) * 84.0;

  /* Outputs for IfAction SubSystem: '<S165>/Simple torque' incorporates:
   *  ActionPort: '<S179>/Action Port'
   */
  /* If: '<S165>/If' incorporates:
   *  MATLAB Function: '<S196>/MATLAB Function3'
   *  MinMax: '<S186>/Min2'
   *  MinMax: '<S186>/Min3'
   */
  rtb_RL = fmax(rtb_max_torque_overload_inverte[0],
                rtb_max_torque_overload_inverte[1]);
  rtb_Max_m_tmp = fmax(rtb_max_torque_overload_inverte[2],
                       rtb_max_torque_overload_inverte[3]);

  /* End of Outputs for SubSystem: '<S165>/Simple torque' */

  /* MATLAB Function: '<S196>/MATLAB Function3' */
  rtb_Subtract_o = (rtb_RL + rtb_Max_m_tmp) * 2.0;

  /* Switch: '<S205>/Switch2' incorporates:
   *  RelationalOperator: '<S205>/LowerRelop1'
   */
  if (!(rtb_Abs3 > rtb_Subtract_m)) {
    /* Switch: '<S205>/Switch' incorporates:
     *  RelationalOperator: '<S205>/UpperRelop'
     */
    if (rtb_Abs3 < rtb_Subtract_o) {
      rtb_Subtract_m = rtb_Subtract_o;
    } else {
      rtb_Subtract_m = rtb_Abs3;
    }

    /* End of Switch: '<S205>/Switch' */
  }

  /* End of Switch: '<S205>/Switch2' */

  /* Gain: '<S196>/Gain2' */
  rtb_Subtract_km = 0.99 * rtb_Subtract_m;

  /* UnaryMinus: '<S198>/Unary Minus1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Saturate: '<S198>/Max Regen'
   */
  rtb_Abs3 = -0.0;

  /* InitialCondition: '<S198>/IC' */
  if (rtDW.IC_FirstOutputTime) {
    rtDW.IC_FirstOutputTime = false;
    rtb_Abs3 = -35000.0;
  }

  /* End of InitialCondition: '<S198>/IC' */

  /* MATLAB Function: '<S166>/MATLAB Function4' incorporates:
   *  MATLAB Function: '<S164>/MATLAB Function'
   *  MATLAB Function: '<S166>/MATLAB Function3'
   *  MATLAB Function: '<S169>/MATLAB Function'
   */
  rtb_Subtract_o = 0.765 * sin(rtb_Abs_idx_0) - 0.635 * cos(rtb_Abs_idx_0);
  rtb_Abs = 0.765 * sin(rtb_Abs) + 0.635 * cos(rtb_Abs);
  rtb_Switch = ((rtb_Subtract_o * rtb_max_torque_overload_inverte[0] + rtb_Abs *
                 rtb_Product[1]) - 0.635 * rtb_max_torque_overload_inverte[2]) +
    0.635 * rtb_Product[3];

  /* Product: '<S166>/Product1' incorporates:
   *  Constant: '<S166>/Constant2'
   */
  rtb_Gain1 = 50.0 * (real_T)rtb_Logic_idx_1;

  /* MATLAB Function: '<S166>/MATLAB Function3' */
  rtb_Switch_m = ((rtb_Subtract_o * rtb_Product[0] + rtb_Abs *
                   rtb_max_torque_overload_inverte[1]) - 0.635 * rtb_Product[2])
    + 0.635 * rtb_max_torque_overload_inverte[3];

  /* Switch: '<S193>/Switch2' incorporates:
   *  RelationalOperator: '<S193>/LowerRelop1'
   */
  if (!(rtb_Gain1 > rtb_Switch)) {
    /* Switch: '<S193>/Switch' incorporates:
     *  RelationalOperator: '<S193>/UpperRelop'
     */
    if (rtb_Gain1 < rtb_Switch_m) {
      rtb_Switch = rtb_Switch_m;
    } else {
      rtb_Switch = rtb_Gain1;
    }

    /* End of Switch: '<S193>/Switch' */
  }

  /* End of Switch: '<S193>/Switch2' */

  /* MATLAB Function: '<S166>/MATLAB Function' */
  if (!rtb_Logic_idx_1) {
    rtb_Gain1 = -0.1;
    rtb_Switch = 0.1;
  } else {
    rtb_Gain1 = -rtb_Switch;
  }

  /* End of MATLAB Function: '<S166>/MATLAB Function' */

  /* Abs: '<S201>/Abs1' incorporates:
   *  Abs: '<S209>/Abs'
   */
  rtb_Abs_idx_0 = fabs(rtb_Switch3[1]);

  /* Abs: '<S201>/Abs3' incorporates:
   *  Abs: '<S209>/Abs'
   */
  rtb_Switch_m = fabs(rtb_Switch3[0]);

  /* Switch: '<S197>/Switch2' incorporates:
   *  Constant: '<S206>/Constant1'
   *  Constant: '<S206>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S206>/AND'
   *  RelationalOperator: '<S206>/Less Than'
   *  RelationalOperator: '<S206>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_Subtract_e5)) {
    /* SignalConversion generated from: '<S158>/C Caller' incorporates:
     *  Constant: '<S197>/Engine Brake'
     */
    rtb_lg[0] = -0.0;
  } else {
    /* SignalConversion generated from: '<S158>/C Caller' incorporates:
     *  MinMax: '<S197>/Max1'
     */
    rtb_lg[0] = fmin(rtb_Subtract_km, rtb_Subtract_m);
  }

  /* End of Switch: '<S197>/Switch2' */

  /* SignalConversion generated from: '<S158>/C Caller' incorporates:
   *  Abs: '<S201>/Abs1'
   *  Abs: '<S201>/Abs3'
   *  Constant: '<S168>/Constant2'
   *  Gain: '<S198>/Gain'
   *  UnaryMinus: '<S201>/Unary Minus'
   *  UnaryMinus: '<S201>/Unary Minus1'
   */
  rtb_lg[1] = 0.001 * rtb_Abs3;
  rtb_lg[2] = -rtb_Abs_idx_0;
  rtb_lg[3] = -rtb_Switch_m;
  rtb_lg[4] = rtb_Gain1;
  rtb_lg[5] = -0.1;

  /* InitialCondition: '<S199>/IC1' */
  rtDW.IC1_FirstOutputTime = false;

  /* SignalConversion generated from: '<S158>/C Caller' incorporates:
   *  Abs: '<S201>/Abs1'
   *  Abs: '<S201>/Abs3'
   *  Constant: '<S168>/Constant1'
   *  Gain: '<S199>/Gain'
   *  MinMax: '<S197>/Max'
   */
  rtb_ug[0] = fmax(rtb_Subtract_km, rtb_Subtract_m);
  rtb_ug[1] = 80.0;
  rtb_ug[2] = rtb_Abs_idx_0;
  rtb_ug[3] = rtb_Switch_m;
  rtb_ug[4] = rtb_Switch;
  rtb_ug[5] = 0.1;

  /* MATLAB Function: '<S172>/MATLAB Function' */
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 1.0;
  v[3] = 0.0001;
  v[4] = 0.0001;
  v[5] = 0.0001;
  v[6] = 0.0001;
  memset(&varargin_1[0], 0, 49U * sizeof(real_T));
  for (b_exit = 0; b_exit < 7; b_exit++) {
    varargin_1[b_exit + 7 * b_exit] = v[b_exit];
  }

  memset(&varargin_2[0], 0, sizeof(real_T) << 4U);
  varargin_2[0] = 1.0E-5;
  varargin_2[5] = 1.0E-5;
  varargin_2[10] = 1.0E-5;
  varargin_2[15] = 1.0E-5;
  memset(&rtb_y[0], 0, 121U * sizeof(real_T));
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    for (i = 0; i < 7; i++) {
      rtb_y[i + 11 * rowIdx] = varargin_1[7 * rowIdx + i];
    }
  }

  for (rowIdx = 0; rowIdx < 4; rowIdx++) {
    i = rowIdx << 2;
    b_exit = (rowIdx + 7) * 11;
    rtb_y[b_exit + 7] = varargin_2[i];
    rtb_y[b_exit + 8] = varargin_2[i + 1];
    rtb_y[b_exit + 9] = varargin_2[i + 2];
    rtb_y[b_exit + 10] = varargin_2[i + 3];
  }

  for (rowIdx = 0; rowIdx < 121; rowIdx++) {
    rtb_y[rowIdx] *= 50.0;
  }

  /* End of MATLAB Function: '<S172>/MATLAB Function' */

  /* MATLAB Function: '<S164>/MATLAB Function' */
  rtb_y_ik[0] = 0.0;
  rtb_y_ik[6] = 0.0;
  rtb_y_ik[12] = 0.0;
  rtb_y_ik[18] = 0.0;
  rtb_y_ik[1] = 0.0;
  rtb_y_ik[7] = 0.0;
  rtb_y_ik[13] = 0.0;
  rtb_y_ik[19] = 0.0;
  rtb_y_ik[2] = 0.0;
  rtb_y_ik[8] = 0.0;
  rtb_y_ik[14] = 0.0;
  rtb_y_ik[20] = 0.0;
  rtb_y_ik[3] = 0.0;
  rtb_y_ik[9] = 0.0;
  rtb_y_ik[15] = 0.0;
  rtb_y_ik[21] = 0.0;
  rtb_y_ik[4] = 0.0;
  rtb_y_ik[10] = 0.0;
  rtb_y_ik[16] = 0.0;
  rtb_y_ik[22] = 0.0;
  rtb_y_ik[5] = rtb_Subtract_o;
  rtb_y_ik[11] = rtb_Abs;
  rtb_y_ik[17] = -0.635;
  rtb_y_ik[23] = 0.635;

  /* Gain: '<S207>/Gain2' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_Gain1 = 13.5 * rtU.omega_wheels_FL;
  rtb_Subtract_m = 13.5 * rtU.omega_wheels_FR;
  rtb_Subtract_km = 13.5 * rtU.omega_wheels_RL;
  rtb_Switch = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S207>/Saturation' */
  if (rtb_Gain1 > 2083.9231268812296) {
    rtb_Gain1 = 2083.9231268812296;
  } else if (rtb_Gain1 < 10.471975511965978) {
    rtb_Gain1 = 10.471975511965978;
  }

  /* Lookup_n-D: '<S209>/2-D Lookup Table' */
  rtb_Gain1 = look2_binlx(rtb_Gain1, rtb_Switch_m, rtConstP.pooled9,
    rtConstP.pooled10, rtConstP.pooled8, rtConstP.uDLookupTable_maxIndex, 200U);

  /* Saturate: '<S209>/Saturation' incorporates:
   *  Lookup_n-D: '<S209>/2-D Lookup Table'
   */
  if (rtb_Gain1 > 1.0) {
    rtb_Gain1 = 1.0;
  } else if (rtb_Gain1 < 0.3) {
    rtb_Gain1 = 0.3;
  }

  /* Saturate: '<S207>/Saturation' */
  if (rtb_Subtract_m > 2083.9231268812296) {
    rtb_Subtract_m = 2083.9231268812296;
  } else if (rtb_Subtract_m < 10.471975511965978) {
    rtb_Subtract_m = 10.471975511965978;
  }

  /* Lookup_n-D: '<S209>/2-D Lookup Table' */
  rtb_Subtract_m = look2_binlx(rtb_Subtract_m, rtb_Abs_idx_0, rtConstP.pooled9,
    rtConstP.pooled10, rtConstP.pooled8, rtConstP.uDLookupTable_maxIndex, 200U);

  /* Saturate: '<S209>/Saturation' incorporates:
   *  Lookup_n-D: '<S209>/2-D Lookup Table'
   */
  if (rtb_Subtract_m > 1.0) {
    rtb_Subtract_m = 1.0;
  } else if (rtb_Subtract_m < 0.3) {
    rtb_Subtract_m = 0.3;
  }

  /* Saturate: '<S207>/Saturation' */
  if (rtb_Subtract_km > 2083.9231268812296) {
    rtb_Subtract_km = 2083.9231268812296;
  } else if (rtb_Subtract_km < 10.471975511965978) {
    rtb_Subtract_km = 10.471975511965978;
  }

  /* Lookup_n-D: '<S209>/2-D Lookup Table' incorporates:
   *  Abs: '<S209>/Abs'
   */
  rtb_Subtract_km = look2_binlx(rtb_Subtract_km, fabs(rtb_Switch3[2]),
    rtConstP.pooled9, rtConstP.pooled10, rtConstP.pooled8,
    rtConstP.uDLookupTable_maxIndex, 200U);

  /* Saturate: '<S209>/Saturation' incorporates:
   *  Lookup_n-D: '<S209>/2-D Lookup Table'
   */
  if (rtb_Subtract_km > 1.0) {
    rtb_Subtract_km = 1.0;
  } else if (rtb_Subtract_km < 0.3) {
    rtb_Subtract_km = 0.3;
  }

  /* Saturate: '<S207>/Saturation' */
  if (rtb_Switch > 2083.9231268812296) {
    rtb_Switch = 2083.9231268812296;
  } else if (rtb_Switch < 10.471975511965978) {
    rtb_Switch = 10.471975511965978;
  }

  /* Lookup_n-D: '<S209>/2-D Lookup Table' incorporates:
   *  Abs: '<S209>/Abs'
   */
  rtb_Abs_idx_0 = look2_binlx(rtb_Switch, fabs(rtb_Switch3[3]), rtConstP.pooled9,
    rtConstP.pooled10, rtConstP.pooled8, rtConstP.uDLookupTable_maxIndex, 200U);

  /* Saturate: '<S209>/Saturation' */
  if (rtb_Abs_idx_0 > 1.0) {
    rtb_Abs_idx_0 = 1.0;
  } else if (rtb_Abs_idx_0 < 0.3) {
    rtb_Abs_idx_0 = 0.3;
  }

  /* MATLAB Function: '<S169>/MATLAB Function' */
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_y_p[6 * rowIdx] = b[rowIdx];
  }

  rtb_y_p[1] = 0.0;
  rtb_y_p[7] = 0.0;
  rtb_y_p[13] = 0.0;

  /* Switch: '<S207>/Switch3' incorporates:
   *  Gain: '<S207>/     '
   *  Gain: '<S207>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    rtb_Abs3 = 0.96 * rtb_Gain1;
  } else {
    rtb_Abs3 = 1.0416666666666667 * rtb_Gain1;
  }

  /* MATLAB Function: '<S169>/MATLAB Function' incorporates:
   *  Abs: '<S207>/Abs'
   *  Gain: '<S169>/Gain'
   *  Gain: '<S207>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Product: '<S207>/Divide'
   */
  rtb_y_p[19] = fabs(13.5 * rtU.omega_wheels_FL / rtb_Abs3) * 0.001;

  /* Switch: '<S207>/Switch3' incorporates:
   *  Gain: '<S207>/     '
   *  Gain: '<S207>/      '
   *  Inport: '<Root>/omega_wheels_FR'
   */
  if (rtU.omega_wheels_FR > 0.0) {
    rtb_Abs3 = 0.96 * rtb_Subtract_m;
  } else {
    rtb_Abs3 = 1.0416666666666667 * rtb_Subtract_m;
  }

  /* MATLAB Function: '<S169>/MATLAB Function' incorporates:
   *  Abs: '<S207>/Abs'
   *  Gain: '<S169>/Gain'
   *  Gain: '<S207>/Gain1'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Product: '<S207>/Divide'
   */
  rtb_y_p[25] = fabs(13.5 * rtU.omega_wheels_FR / rtb_Abs3) * 0.001;

  /* Switch: '<S207>/Switch3' incorporates:
   *  Gain: '<S207>/     '
   *  Gain: '<S207>/      '
   *  Inport: '<Root>/omega_wheels_RL'
   */
  if (rtU.omega_wheels_RL > 0.0) {
    rtb_Abs3 = 0.96 * rtb_Subtract_km;
  } else {
    rtb_Abs3 = 1.0416666666666667 * rtb_Subtract_km;
  }

  /* MATLAB Function: '<S169>/MATLAB Function' incorporates:
   *  Abs: '<S207>/Abs'
   *  Gain: '<S169>/Gain'
   *  Gain: '<S207>/Gain1'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Product: '<S207>/Divide'
   */
  rtb_y_p[31] = fabs(13.5 * rtU.omega_wheels_RL / rtb_Abs3) * 0.001;

  /* Switch: '<S207>/Switch3' incorporates:
   *  Gain: '<S207>/     '
   *  Gain: '<S207>/      '
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Abs3 = 0.96 * rtb_Abs_idx_0;
  } else {
    rtb_Abs3 = 1.0416666666666667 * rtb_Abs_idx_0;
  }

  /* MATLAB Function: '<S169>/MATLAB Function' incorporates:
   *  Abs: '<S207>/Abs'
   *  Gain: '<S169>/Gain'
   *  Gain: '<S207>/Gain1'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S207>/Divide'
   */
  rtb_y_p[37] = fabs(13.5 * rtU.omega_wheels_RR / rtb_Abs3) * 0.001;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_y_p[6 * rowIdx + 2] = c[rowIdx];
  }

  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_y_p[6 * rowIdx + 3] = d[rowIdx];
  }

  rtb_y_p[4] = 0.0;
  rtb_y_p[10] = 0.0;
  rtb_y_p[16] = 0.0;
  rtb_y_p[22] = rtb_Subtract_o;
  rtb_y_p[28] = rtb_Abs;
  rtb_y_p[34] = -0.635;
  rtb_y_p[40] = 0.635;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_y_p[6 * rowIdx + 5] = 0.0;
  }

  /* CCaller: '<S158>/C Caller' incorporates:
   *  CFunction: '<S174>/C Function'
   *  Constant: '<S167>/Constant'
   *  Constant: '<S170>/Constant'
   *  UnaryMinus: '<S167>/Unary Minus'
   */
  rtb_Subtract_o = Acados_Caller_wrapper(&rtb_x[0], &rtDW.CFunction[0],
    &rtb_y_ref_0[0], &rtb_y_f[0], &rtb_y_ref_0[0], &rtb_y_kf[0], &rtb_y_o[0],
    &rtb_UnaryMinus_ci[0], &rtb_y_c[0], &rtb_lg[0], &rtb_ug[0], &rtb_y[0],
    &rtConstP.Constant_Value_fo[0], &rtConstP.Constant_Value_fo[0],
    &rtConstB.UnaryMinus[0], &rtConstP.Constant_Value_b[0], &rtb_y_ik[0],
    &rtb_y_p[0], &rtb_CCaller_o2[0], &rtb_CCaller_o3[0]);

  /* DataTypeConversion: '<S180>/Data Type Conversion' incorporates:
   *  Constant: '<S180>/Constant2'
   *  RelationalOperator: '<S180>/Equal'
   */
  DataTypeConversion = (uint8_T)(rtb_Subtract_o == 4.0);

  /* DiscreteFir: '<S180>/Discrete FIR Filter' */
  acc1 = (uint32_T)DataTypeConversion << 7;
  for (b_exit = rtDW.DiscreteFIRFilter_circBuf; b_exit < 4; b_exit++) {
    acc1 += (uint32_T)rtDW.DiscreteFIRFilter_states[b_exit] << 7;
  }

  for (b_exit = 0; b_exit < rtDW.DiscreteFIRFilter_circBuf; b_exit++) {
    acc1 += (uint32_T)rtDW.DiscreteFIRFilter_states[b_exit] << 7;
  }

  /* End of DiscreteFir: '<S180>/Discrete FIR Filter' */

  /* Switch: '<S180>/Switch' */
  if ((rtb_vx > 3.0) && (acc1 < 512U)) {
    /* Outputs for IfAction SubSystem: '<S165>/MPC' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    /* If: '<S165>/If' incorporates:
     *  Inport: '<S177>/X1'
     *  Merge: '<S165>/Merge'
     */
    rtDW.Merge[0] = rtb_CCaller_o3[3];
    rtDW.Merge[1] = rtb_CCaller_o3[4];
    rtDW.Merge[2] = rtb_CCaller_o3[5];
    rtDW.Merge[3] = rtb_CCaller_o3[6];

    /* End of Outputs for SubSystem: '<S165>/MPC' */
  } else {
    /* Outputs for IfAction SubSystem: '<S165>/Simple torque' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    /* If: '<S165>/If' incorporates:
     *  Constant: '<S181>/Constant1'
     *  Constant: '<S181>/Constant2'
     *  Constant: '<S181>/Constant3'
     *  Constant: '<S181>/Constant4'
     *  Constant: '<S182>/Constant'
     *  Constant: '<S182>/Constant2'
     *  Constant: '<S184>/Constant'
     *  Constant: '<S184>/Exponent < 0'
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant9'
     *  Gain: '<S181>/Gain1'
     *  Gain: '<S182>/Gain1'
     *  Inport: '<Root>/omega_wheels_FL'
     *  Inport: '<Root>/omega_wheels_FR'
     *  Inport: '<Root>/omega_wheels_RL'
     *  Inport: '<Root>/omega_wheels_RR'
     *  Inport: '<Root>/throttle'
     *  MATLAB Function: '<S181>/MATLAB Function'
     *  Math: '<S184>/Power'
     *  Merge: '<S165>/Merge'
     *  Product: '<S182>/Product'
     *  Product: '<S182>/Product1'
     *  Product: '<S182>/Product2'
     *  Product: '<S184>/Divide'
     *  Product: '<S184>/Divide1'
     *  RelationalOperator: '<S181>/Less Than1'
     *  RelationalOperator: '<S182>/Less Than1'
     *  RelationalOperator: '<S185>/LowerRelop1'
     *  RelationalOperator: '<S187>/LowerRelop1'
     *  RelationalOperator: '<S187>/UpperRelop'
     *  SignalConversion generated from: '<S179>/Out1'
     *  SignalConversion generated from: '<S186>/Vector Concatenate'
     *  Sum: '<S182>/Sum of Elements'
     *  Sum: '<S184>/Subtract'
     *  Sum: '<S184>/Sum'
     *  Switch: '<S181>/Switch1'
     *  Switch: '<S185>/Switch2'
     *  Switch: '<S187>/Switch'
     *  Switch: '<S187>/Switch2'
     * */
    rtb_Logic_e_idx_1 = (0.05 < rtb_Subtract_e5);
    if (rtb_Logic_e_idx_1) {
      rtb_vx = -35000.0;
    } else {
      rtb_vx = 80000.0;
    }

    rtb_y_o[0] = rtb_RR;
    rtb_y_o[1] = rtb_RR;
    rtb_y_o[2] = rtb_max_torque_overload_inver_0;
    rtb_y_o[3] = rtb_max_torque_overload_inver_0;
    rtb_Abs3 = ((rtb_Product[0] + rtb_Product[1]) + rtb_Product[2]) +
      rtb_Product[3];
    rtb_Subtract_e5 = 1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle),
      -1.5) + 1.0) * (real_T)(rtU.throttle >= 0.05) * 84.0;
    if (!(rtb_Subtract_e5 > rtb_Abs3)) {
      /* Sum: '<S182>/Sum of Elements1' */
      rtb_Subtract_o = ((rtb_max_torque_overload_inverte[0] +
                         rtb_max_torque_overload_inverte[1]) +
                        rtb_max_torque_overload_inverte[2]) +
        rtb_max_torque_overload_inverte[3];

      /* Switch: '<S185>/Switch' incorporates:
       *  RelationalOperator: '<S185>/UpperRelop'
       *  Switch: '<S182>/Switch'
       */
      if (rtb_Subtract_e5 < rtb_Subtract_o) {
        rtb_Abs3 = rtb_Subtract_o;
      } else {
        rtb_Abs3 = rtb_Subtract_e5;
      }

      /* End of Switch: '<S185>/Switch' */
    }

    rtb_CCaller_o2[0] = rtb_Abs3 * 0.3;
    rtb_CCaller_o2[1] = rtb_Abs3 * 0.3;
    rtb_CCaller_o2[2] = rtb_Abs3 * 0.7;
    rtb_CCaller_o2[3] = rtb_Abs3 * 0.7;
    if (rtb_CCaller_o2[0] > rtb_y_o[0]) {
      rtb_CCaller_o2[0] = rtb_y_o[0];
    } else if (rtb_CCaller_o2[0] < rtb_RL) {
      /* Switch: '<S187>/Switch' */
      rtb_CCaller_o2[0] = rtb_RL;
    }

    if (rtb_CCaller_o2[1] > rtb_y_o[1]) {
      rtb_CCaller_o2[1] = rtb_y_o[1];
    } else if (rtb_CCaller_o2[1] < rtb_RL) {
      /* Switch: '<S187>/Switch' */
      rtb_CCaller_o2[1] = rtb_RL;
    }

    if (rtb_CCaller_o2[2] > rtb_y_o[2]) {
      rtb_CCaller_o2[2] = rtb_y_o[2];
    } else if (rtb_CCaller_o2[2] < rtb_Max_m_tmp) {
      /* Switch: '<S187>/Switch' */
      rtb_CCaller_o2[2] = rtb_Max_m_tmp;
    }

    if (rtb_CCaller_o2[3] > rtb_y_o[3]) {
      rtb_CCaller_o2[3] = rtb_y_o[3];
    } else if (rtb_CCaller_o2[3] < rtb_Max_m_tmp) {
      /* Switch: '<S187>/Switch' */
      rtb_CCaller_o2[3] = rtb_Max_m_tmp;
    }

    rtb_Product[0] = 13.5 * rtU.omega_wheels_FL;
    rtb_Product[1] = 13.5 * rtU.omega_wheels_FR;
    rtb_Product[2] = 13.5 * rtU.omega_wheels_RL;
    rtb_Product[3] = 13.5 * rtU.omega_wheels_RR;
    rtb_y_o[0] = 0.0;
    rtb_y_o[1] = 0.0;
    rtb_y_o[2] = 0.0;
    rtb_y_o[3] = 0.0;
    rowIdx = 0;
    b_exit = 0;
    rtb_Subtract_o = 0.0;
    while (b_exit == 0) {
      boolean_T exitg1;
      if (!rtb_Logic_e_idx_1) {
        rtb_y_o[0] = rtb_CCaller_o2[0] - rtb_Subtract_o;
        rtb_y_o[1] = rtb_CCaller_o2[1] - rtb_Subtract_o;
        rtb_y_o[2] = rtb_CCaller_o2[2] - rtb_Subtract_o;
        rtb_y_o[3] = rtb_CCaller_o2[3] - rtb_Subtract_o;
        rtb_y_kf[0] = fabs(rtb_y_o[0]);
        rtb_y_kf[1] = fabs(rtb_y_o[1]);
        rtb_y_kf[2] = fabs(rtb_y_o[2]);
        rtb_y_kf[3] = fabs(rtb_y_o[3]);
        rtb_Switch3[0] = fabs(rtb_Product[0]);
        rtb_Switch3[1] = fabs(rtb_Product[1]);
        rtb_Switch3[2] = fabs(rtb_Product[2]);
        rtb_Switch3[3] = fabs(rtb_Product[3]);
        interp2(rtConstP.pooled10, rtConstP.pooled9, rtConstP.pooled8, rtb_y_kf,
                rtb_Switch3, rtb_max_torque_overload_inverte);
        if (rtb_y_o[0] <= 0.0) {
          rtb_y_o[0] = 0.0;
        }

        if (rtb_y_o[1] <= 0.0) {
          rtb_y_o[1] = 0.0;
        }

        if (rtb_y_o[2] <= 0.0) {
          rtb_y_o[2] = 0.0;
        }

        if (rtb_y_o[3] <= 0.0) {
          rtb_y_o[3] = 0.0;
        }
      } else {
        rtb_y_o[0] = rtb_CCaller_o2[0] + rtb_Subtract_o;
        rtb_y_o[1] = rtb_CCaller_o2[1] + rtb_Subtract_o;
        rtb_y_o[2] = rtb_CCaller_o2[2] + rtb_Subtract_o;
        rtb_y_o[3] = rtb_CCaller_o2[3] + rtb_Subtract_o;
        rtb_y_kf[0] = fabs(rtb_y_o[0]);
        rtb_y_kf[1] = fabs(rtb_y_o[1]);
        rtb_y_kf[2] = fabs(rtb_y_o[2]);
        rtb_y_kf[3] = fabs(rtb_y_o[3]);
        rtb_Switch3[0] = fabs(rtb_Product[0]);
        rtb_Switch3[1] = fabs(rtb_Product[1]);
        rtb_Switch3[2] = fabs(rtb_Product[2]);
        rtb_Switch3[3] = fabs(rtb_Product[3]);
        interp2(rtConstP.pooled10, rtConstP.pooled9, rtConstP.pooled8, rtb_y_kf,
                rtb_Switch3, rtb_max_torque_overload_inverte);
        if (rtb_y_o[0] >= 0.0) {
          rtb_y_o[0] = 0.0;
        }

        if (rtb_y_o[1] >= 0.0) {
          rtb_y_o[1] = 0.0;
        }

        if (rtb_y_o[2] >= 0.0) {
          rtb_y_o[2] = 0.0;
        }

        if (rtb_y_o[3] >= 0.0) {
          rtb_y_o[3] = 0.0;
        }
      }

      rtb_Abs3 = rtb_y_o[0] / rtb_max_torque_overload_inverte[0];
      rtb_Subtract_e5 = rtb_y_o[1] / rtb_max_torque_overload_inverte[1];
      rtb_Gain1 = rtb_y_o[2] / rtb_max_torque_overload_inverte[2];
      rtb_Abs = rtb_y_o[3] / rtb_max_torque_overload_inverte[3];
      rtb_Abs3 = (((rtb_Abs3 * rtb_Product[0] + rtb_Subtract_e5 * rtb_Product[1])
                   + rtb_Gain1 * rtb_Product[2]) + rtb_Abs * rtb_Product[3]) -
        rtb_vx;
      if ((rowIdx >= 100) || (rtb_Abs3 < 0.0)) {
        b_exit = 1;
      } else if (rtIsNaN(rtb_Abs3)) {
        b_exit = 1;
      } else {
        rtb_Subtract_o += 0.3;
        rowIdx++;
      }

      rtb_LessThan_m[0] = rtIsNaN(rtb_y_o[0]);
      rtb_LessThan_m[1] = rtIsNaN(rtb_y_o[1]);
      rtb_LessThan_m[2] = rtIsNaN(rtb_y_o[2]);
      rtb_LessThan_m[3] = rtIsNaN(rtb_y_o[3]);
      rtb_Logic_l_idx_1 = true;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 4)) {
        if (!rtb_LessThan_m[i]) {
          rtb_Logic_l_idx_1 = false;
          exitg1 = true;
        } else {
          i++;
        }
      }

      if (rtb_Logic_l_idx_1) {
        rtb_y_o[0] = 0.0;
        rtb_y_o[1] = 0.0;
        rtb_y_o[2] = 0.0;
        rtb_y_o[3] = 0.0;
      }
    }

    rtDW.Merge[0] = rtb_y_o[0];
    rtDW.Merge[1] = rtb_y_o[1];
    rtDW.Merge[2] = rtb_y_o[2];
    rtDW.Merge[3] = rtb_y_o[3];

    /* End of Outputs for SubSystem: '<S165>/Simple torque' */
  }

  /* End of Switch: '<S180>/Switch' */

  /* Product: '<S165>/Divide' incorporates:
   *  Merge: '<S165>/Merge'
   */
  rtb_CCaller_o2[0] = rtDW.Merge[0];
  rtb_CCaller_o2[1] = rtDW.Merge[1];
  rtb_CCaller_o2[2] = rtDW.Merge[2];
  rtb_CCaller_o2[3] = rtDW.Merge[3];

  /* RelationalOperator: '<S165>/Less Than3' incorporates:
   *  Constant: '<S165>/Constant1'
   *  Inport: '<Root>/brake'
   */
  rtb_Logic_e_idx_1 = (rtU.brake > 0.05);

  /* Chart: '<S165>/Overlap Chart' incorporates:
   *  Inport: '<Root>/throttle'
   */
  if (rtDW.is_active_c75_TVModel == 0U) {
    rtDW.is_active_c75_TVModel = 1U;
    rtDW.is_c75_TVModel = IN_Go;
  } else if (rtDW.is_c75_TVModel == IN_Go) {
    if (rtb_Logic_e_idx_1) {
      rtDW.is_c75_TVModel = IN_Stop;
    }

    /* case IN_Stop: */
  } else if (((real_T)rtb_Logic_e_idx_1 <= 0.05) && (rtU.throttle < 0.05)) {
    rtDW.is_c75_TVModel = IN_Go;
  }

  /* End of Chart: '<S165>/Overlap Chart' */

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[0] = rtDW.UnitDelay_DSTATE_j[0];

  /* Update for UnitDelay: '<S28>/UD' incorporates:
   *  SampleTimeMath: '<S28>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[0] = rtb_Subtract_m4_tmp_0;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[1] = rtDW.UnitDelay_DSTATE_j[1];

  /* Update for UnitDelay: '<S28>/UD' incorporates:
   *  SampleTimeMath: '<S28>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[1] = rtb_Subtract_m4_tmp_1;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[2] = rtDW.UnitDelay_DSTATE_j[2];

  /* Update for UnitDelay: '<S28>/UD' incorporates:
   *  SampleTimeMath: '<S28>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[2] = rtb_Subtract_m4_tmp_2;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[3] = rtDW.UnitDelay_DSTATE_j[3];

  /* Update for UnitDelay: '<S28>/UD' incorporates:
   *  SampleTimeMath: '<S28>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S28>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[3] = rtb_Subtract_m4_tmp;

  /* Update for UnitDelay generated from: '<S26>/Unit Delay3' */
  rtDW.UnitDelay3_1_DSTATE = rtb_CCaller_o2[3];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay3' */
  rtDW.UnitDelay3_2_DSTATE = rtb_CCaller_o2[2];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay3' */
  rtDW.UnitDelay3_3_DSTATE = rtb_CCaller_o2[1];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay3' */
  rtDW.UnitDelay3_4_DSTATE = rtb_CCaller_o2[0];

  /* Update for DiscreteIntegrator: '<S38>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S29>/1//T' */
  rtb_Abs3 = 1.0 / rtb_Sign;

  /* Update for Memory: '<S26>/Memory' incorporates:
   *  Constant: '<S26>/Constant6'
   *  RelationalOperator: '<S26>/Equal'
   */
  rtDW.Memory_PreviousInput_f[0] = (rtb_T_max_d_idx_0 == -21.0);

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   *  Switch: '<S65>/Switch'
   */
  rtDW.Integrator_DSTATE[0] += 0.02 * rtb_ZeroGain_idx_0;
  rtDW.Integrator_PrevResetState[0] = (int8_T)rtb_Memory_idx_0;

  /* Update for DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Memory: '<S26>/Memory'
   */
  rtDW.Filter_DSTATE[0] += 0.02 * rtb_FilterCoefficient_idx_0;
  rtDW.Filter_PrevResetState[0] = (int8_T)rtb_Memory_idx_0;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Product: '<S29>/1//T'
   *  Sum: '<S29>/Sum1'
   */
  rtDW.Integrator_DSTATE_h[0] += rtb_Abs3 * rtb_T_max_k_idx_0 * 0.02;

  /* Update for Memory: '<S26>/Memory' incorporates:
   *  Constant: '<S26>/Constant6'
   *  RelationalOperator: '<S26>/Equal'
   */
  rtDW.Memory_PreviousInput_f[1] = (rtb_T_max_d_idx_1 == -21.0);

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   *  Switch: '<S65>/Switch'
   */
  rtDW.Integrator_DSTATE[1] += 0.02 * rtb_ZeroGain_idx_1;
  rtDW.Integrator_PrevResetState[1] = (int8_T)rtb_Memory_idx_1;

  /* Update for DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Memory: '<S26>/Memory'
   */
  rtDW.Filter_DSTATE[1] += 0.02 * rtb_FilterCoefficient_idx_1;
  rtDW.Filter_PrevResetState[1] = (int8_T)rtb_Memory_idx_1;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Product: '<S29>/1//T'
   *  Sum: '<S29>/Sum1'
   */
  rtDW.Integrator_DSTATE_h[1] += rtb_Abs3 * rtb_T_max_k_idx_1 * 0.02;

  /* Update for Memory: '<S26>/Memory' incorporates:
   *  Constant: '<S26>/Constant6'
   *  RelationalOperator: '<S26>/Equal'
   */
  rtDW.Memory_PreviousInput_f[2] = (rtb_T_max_d_idx_2 == -21.0);

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   *  Switch: '<S65>/Switch'
   */
  rtDW.Integrator_DSTATE[2] += 0.02 * rtb_ZeroGain_idx_2;
  rtDW.Integrator_PrevResetState[2] = (int8_T)rtb_Memory_idx_2;

  /* Update for DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Memory: '<S26>/Memory'
   */
  rtDW.Filter_DSTATE[2] += 0.02 * rtb_FilterCoefficient_idx_2;
  rtDW.Filter_PrevResetState[2] = (int8_T)rtb_Memory_idx_2;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Product: '<S29>/1//T'
   *  Sum: '<S29>/Sum1'
   */
  rtDW.Integrator_DSTATE_h[2] += rtb_Abs3 * rtb_T_max_k_idx_2 * 0.02;

  /* Update for Memory: '<S26>/Memory' incorporates:
   *  Constant: '<S26>/Constant6'
   *  RelationalOperator: '<S26>/Equal'
   */
  rtDW.Memory_PreviousInput_f[3] = (rtb_T_max_ay == -21.0);

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   */
  rtDW.Integrator_DSTATE[3] += 0.02 * rtb_Filter_f;
  rtDW.Integrator_PrevResetState[3] = (int8_T)rtb_Memory_idx_3;

  /* Update for DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Memory: '<S26>/Memory'
   */
  rtDW.Filter_DSTATE[3] += 0.02 * rtb_FilterCoefficient_idx_3;
  rtDW.Filter_PrevResetState[3] = (int8_T)rtb_Memory_idx_3;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Product: '<S29>/1//T'
   */
  rtDW.Integrator_DSTATE_h[3] += rtb_Abs3 * rtb_T_max_k_idx_3 * 0.02;
  rtDW.Integrator_PrevResetState_d = (int8_T)rtb_Compare;

  /* Update for UnitDelay generated from: '<S26>/Unit Delay2' */
  rtDW.UnitDelay2_1_DSTATE = rtb_CCaller_o2[3];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay2' */
  rtDW.UnitDelay2_2_DSTATE = rtb_CCaller_o2[2];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay2' */
  rtDW.UnitDelay2_3_DSTATE = rtb_CCaller_o2[1];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay2' */
  rtDW.UnitDelay2_4_DSTATE = rtb_CCaller_o2[0];

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_n[0] = rtb_T_max_d_idx_0;

  /* Update for UnitDelay: '<S93>/UD' incorporates:
   *  SampleTimeMath: '<S93>/TSamp'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f[0] = rtb_Subtract_m4_tmp_0;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_n[1] = rtb_T_max_d_idx_1;

  /* Update for UnitDelay: '<S93>/UD' incorporates:
   *  SampleTimeMath: '<S93>/TSamp'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f[1] = rtb_Subtract_m4_tmp_1;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_n[2] = rtb_T_max_d_idx_2;

  /* Update for UnitDelay: '<S93>/UD' incorporates:
   *  SampleTimeMath: '<S93>/TSamp'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f[2] = rtb_Subtract_m4_tmp_2;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_n[3] = rtb_T_max_ay;

  /* Update for UnitDelay: '<S93>/UD' incorporates:
   *  SampleTimeMath: '<S93>/TSamp'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f[3] = rtb_Subtract_m4_tmp;

  /* Update for UnitDelay generated from: '<S27>/Unit Delay3' */
  rtDW.UnitDelay3_1_DSTATE_f = rtb_CCaller_o2[3];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay3' */
  rtDW.UnitDelay3_2_DSTATE_b = rtb_CCaller_o2[2];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay3' */
  rtDW.UnitDelay3_3_DSTATE_k = rtb_CCaller_o2[1];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay3' */
  rtDW.UnitDelay3_4_DSTATE_o = rtb_CCaller_o2[0];

  /* Update for DiscreteIntegrator: '<S103>/Integrator' */
  rtDW.Integrator_IC_LOADING_i = 0U;

  /* Product: '<S94>/1//T' */
  rtb_Abs3 = 1.0 / rtb_AvoidDividebyZero_h;

  /* Update for Memory: '<S27>/Memory' incorporates:
   *  Constant: '<S27>/Constant6'
   *  RelationalOperator: '<S27>/Equal'
   */
  rtDW.Memory_PreviousInput_m[0] = (rtb_T_max_h_idx_0 == 21.0);

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  rtDW.Integrator_DSTATE_f[0] += 0.02 * rtb_ZeroGain_a;
  rtDW.Integrator_PrevResetState_a[0] = (int8_T)rtb_Memory_e_idx_0;

  /* Update for DiscreteIntegrator: '<S134>/Filter' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator'
   *  Gain: '<S142>/Filter Coefficient'
   *  Memory: '<S27>/Memory'
   */
  rtDW.Filter_DSTATE_d[0] += 0.02 * rtb_Filter_l_idx_0;
  rtDW.Filter_PrevResetState_d[0] = (int8_T)rtb_Memory_e_idx_0;

  /* Update for DiscreteIntegrator: '<S103>/Integrator' incorporates:
   *  Product: '<S94>/1//T'
   *  Sum: '<S94>/Sum1'
   */
  rtDW.Integrator_DSTATE_f3[0] += rtb_Abs3 * rtb_Integrator_iq_idx_0 * 0.02;

  /* Update for Memory: '<S27>/Memory' incorporates:
   *  Constant: '<S27>/Constant6'
   *  RelationalOperator: '<S27>/Equal'
   */
  rtDW.Memory_PreviousInput_m[1] = (rtb_T_max_h_idx_1 == 21.0);

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  rtDW.Integrator_DSTATE_f[1] += 0.02 * rtb_ZeroGain_o;
  rtDW.Integrator_PrevResetState_a[1] = (int8_T)rtb_Memory_e_idx_1;

  /* Update for DiscreteIntegrator: '<S134>/Filter' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator'
   *  Gain: '<S142>/Filter Coefficient'
   *  Memory: '<S27>/Memory'
   */
  rtDW.Filter_DSTATE_d[1] += 0.02 * rtb_Filter_l_idx_1;
  rtDW.Filter_PrevResetState_d[1] = (int8_T)rtb_Memory_e_idx_1;

  /* Update for DiscreteIntegrator: '<S103>/Integrator' incorporates:
   *  Product: '<S94>/1//T'
   *  Sum: '<S94>/Sum1'
   */
  rtDW.Integrator_DSTATE_f3[1] += rtb_Abs3 * rtb_Integrator_iq_idx_1 * 0.02;

  /* Update for Memory: '<S27>/Memory' incorporates:
   *  Constant: '<S27>/Constant6'
   *  RelationalOperator: '<S27>/Equal'
   */
  rtDW.Memory_PreviousInput_m[2] = (rtb_T_max_h_idx_2 == 21.0);

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  rtDW.Integrator_DSTATE_f[2] += 0.02 * rtb_ZeroGain_h;
  rtDW.Integrator_PrevResetState_a[2] = (int8_T)rtb_Memory_e_idx_2;

  /* Update for DiscreteIntegrator: '<S134>/Filter' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator'
   *  Gain: '<S142>/Filter Coefficient'
   *  Memory: '<S27>/Memory'
   */
  rtDW.Filter_DSTATE_d[2] += 0.02 * rtb_Filter_l_idx_2;
  rtDW.Filter_PrevResetState_d[2] = (int8_T)rtb_Memory_e_idx_2;

  /* Update for DiscreteIntegrator: '<S103>/Integrator' incorporates:
   *  Product: '<S94>/1//T'
   *  Sum: '<S94>/Sum1'
   */
  rtDW.Integrator_DSTATE_f3[2] += rtb_Abs3 * rtb_Integrator_iq_idx_2 * 0.02;

  /* Update for Memory: '<S27>/Memory' incorporates:
   *  Constant: '<S27>/Constant6'
   *  RelationalOperator: '<S27>/Equal'
   */
  rtDW.Memory_PreviousInput_m[3] = (rtb_T_max_f == 21.0);

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  rtDW.Integrator_DSTATE_f[3] += 0.02 * rtb_SignPreIntegrator;
  rtDW.Integrator_PrevResetState_a[3] = (int8_T)rtb_Memory_e_idx_3;

  /* Update for DiscreteIntegrator: '<S134>/Filter' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator'
   *  Gain: '<S142>/Filter Coefficient'
   *  Memory: '<S27>/Memory'
   */
  rtDW.Filter_DSTATE_d[3] += 0.02 * rtb_Filter_l_idx_3;
  rtDW.Filter_PrevResetState_d[3] = (int8_T)rtb_Memory_e_idx_3;

  /* Update for DiscreteIntegrator: '<S103>/Integrator' incorporates:
   *  Product: '<S94>/1//T'
   */
  rtDW.Integrator_DSTATE_f3[3] += rtb_Abs3 * rtb_Integrator_iq_idx_3 * 0.02;
  rtDW.Integrator_PrevResetState_m = (int8_T)rtb_Compare_n;

  /* Update for UnitDelay generated from: '<S27>/Unit Delay2' */
  rtDW.UnitDelay2_1_DSTATE_i = rtb_CCaller_o2[3];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay2' */
  rtDW.UnitDelay2_2_DSTATE_f = rtb_CCaller_o2[2];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay2' */
  rtDW.UnitDelay2_3_DSTATE_j = rtb_CCaller_o2[1];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay2' */
  rtDW.UnitDelay2_4_DSTATE_c = rtb_CCaller_o2[0];

  /* Update for UnitDelay: '<S27>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_g[0] = rtb_T_max_h_idx_0;
  rtDW.UnitDelay_DSTATE_g[1] = rtb_T_max_h_idx_1;
  rtDW.UnitDelay_DSTATE_g[2] = rtb_T_max_h_idx_2;
  rtDW.UnitDelay_DSTATE_g[3] = rtb_T_max_f;

  /* Update for Memory: '<S158>/Memory' incorporates:
   *  Product: '<S165>/Divide'
   */
  rtDW.Memory_PreviousInput[0] = rtb_CCaller_o2[0];
  rtDW.Memory_PreviousInput[1] = rtb_CCaller_o2[1];
  rtDW.Memory_PreviousInput[2] = rtb_CCaller_o2[2];
  rtDW.Memory_PreviousInput[3] = rtb_CCaller_o2[3];

  /* Update for DiscreteIntegrator: '<S237>/Integrator' */
  rtDW.Integrator_IC_LOADING_it = 0U;

  /* Product: '<S230>/1//T' incorporates:
   *  Constant: '<S232>/Time constant'
   *  MinMax: '<S232>/Max'
   */
  rtb_Abs3 = 1.0 / fmax(rtDW.Probe_kx[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S237>/Integrator' */
  rtDW.Integrator_PrevResetState_i = (int8_T)rtb_Compare_g;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' */
  rtDW.Integrator_IC_LOADING_b = 0U;

  /* Product: '<S239>/1//T' incorporates:
   *  Constant: '<S241>/Time constant'
   *  MinMax: '<S241>/Max'
   */
  rtb_vx = 1.0 / fmax(rtDW.Probe_b[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
   *  Product: '<S230>/1//T'
   *  Sum: '<S230>/Sum1'
   */
  rtDW.Integrator_DSTATE_j[0] += (rtb_SignPreIntegrator_idx_0 -
    rtb_Integrator_i_idx_0) * rtb_Abs3 * 0.02;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' incorporates:
   *  Product: '<S239>/1//T'
   *  Sum: '<S239>/Sum1'
   */
  rtDW.Integrator_DSTATE_ff[0] += (rtb_Abs_o_idx_0 - rtb_Integrator_d_idx_0) *
    rtb_vx * 0.02;

  /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
   *  Product: '<S230>/1//T'
   *  Sum: '<S230>/Sum1'
   */
  rtDW.Integrator_DSTATE_j[1] += (rtb_SignPreIntegrator_idx_1 -
    rtb_Integrator_i_idx_1) * rtb_Abs3 * 0.02;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' incorporates:
   *  Product: '<S239>/1//T'
   *  Sum: '<S239>/Sum1'
   */
  rtDW.Integrator_DSTATE_ff[1] += (rtb_Abs_o_idx_1 - rtb_Integrator_d_idx_1) *
    rtb_vx * 0.02;

  /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
   *  Product: '<S230>/1//T'
   *  Sum: '<S230>/Sum1'
   */
  rtDW.Integrator_DSTATE_j[2] += (rtb_SignPreIntegrator_idx_2 -
    rtb_Integrator_i_idx_2) * rtb_Abs3 * 0.02;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' incorporates:
   *  Product: '<S239>/1//T'
   *  Sum: '<S239>/Sum1'
   */
  rtDW.Integrator_DSTATE_ff[2] += (rtb_Abs_o_idx_2 - rtb_Integrator_d_idx_2) *
    rtb_vx * 0.02;

  /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
   *  Product: '<S230>/1//T'
   *  Sum: '<S230>/Sum1'
   */
  rtDW.Integrator_DSTATE_j[3] += (rtb_SignPreIntegrator_idx_3 -
    rtb_Integrator_i_idx_3) * rtb_Abs3 * 0.02;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' incorporates:
   *  Product: '<S239>/1//T'
   *  Sum: '<S239>/Sum1'
   */
  rtDW.Integrator_DSTATE_ff[3] += (rtb_Abs_o_idx_3 - rtb_Integrator_d_idx_3) *
    rtb_vx * 0.02;
  rtDW.Integrator_PrevResetState_f = (int8_T)rtb_Compare_d;

  /* Update for Memory: '<S218>/Memory' */
  rtDW.Memory_PreviousInput_n = rtb_Logic_idx_0;

  /* Update for Memory: '<S219>/Memory' */
  rtDW.Memory_PreviousInput_i = rtb_Logic_e_idx_0;

  /* Update for Memory: '<S220>/Memory' */
  rtDW.Memory_PreviousInput_h = rtb_Logic_l_idx_0;

  /* Update for Memory: '<S221>/Memory' */
  rtDW.Memory_PreviousInput_d = rtb_Logic_k_idx_0;

  /* Update for Memory: '<S195>/Memory' */
  rtDW.Memory_PreviousInput_e = rtb_Logic_idx_1;

  /* Update for DiscreteFir: '<S180>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf] =
    DataTypeConversion;

  /* End of Update for DiscreteFir: '<S180>/Discrete FIR Filter' */

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

  /* Outport: '<Root>/States' */
  for (i = 0; i < 7; i++) {
    rtY.States[i] = rtb_CCaller_o3[i];
  }

  /* End of Outport: '<Root>/States' */

  /* Outport: '<Root>/Torque' */
  rtY.Torque[0] = rtb_CCaller_o2[0];
  rtY.Torque[1] = rtb_CCaller_o2[1];
  rtY.Torque[2] = rtb_CCaller_o2[2];
  rtY.Torque[3] = rtb_CCaller_o2[3];
}

/* Model initialize function */
void TVModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
  /* Start for Probe: '<S33>/Probe' */
  rtDW.Probe[0] = 0.02;
  rtDW.Probe[1] = 0.0;

  /* Start for Probe: '<S98>/Probe' */
  rtDW.Probe_k[0] = 0.02;
  rtDW.Probe_k[1] = 0.0;

  /* Start for Probe: '<S232>/Probe' */
  rtDW.Probe_kx[0] = 0.02;
  rtDW.Probe_kx[1] = 0.0;

  /* Start for Probe: '<S241>/Probe' */
  rtDW.Probe_b[0] = 0.02;
  rtDW.Probe_b[1] = 0.0;

  /* Start for InitialCondition: '<S198>/IC' */
  rtDW.IC_FirstOutputTime = true;

  /* Start for InitialCondition: '<S199>/IC1' */
  rtDW.IC1_FirstOutputTime = true;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
  rtDW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S103>/Integrator' */
  rtDW.Integrator_IC_LOADING_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S237>/Integrator' */
  rtDW.Integrator_IC_LOADING_it = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S246>/Integrator' */
  rtDW.Integrator_IC_LOADING_b = 1U;

  /* InitializeConditions for Memory: '<S26>/Memory' */
  rtDW.Memory_PreviousInput_f[0] = true;

  /* InitializeConditions for Memory: '<S27>/Memory' */
  rtDW.Memory_PreviousInput_m[0] = true;

  /* InitializeConditions for Memory: '<S26>/Memory' */
  rtDW.Memory_PreviousInput_f[1] = true;

  /* InitializeConditions for Memory: '<S27>/Memory' */
  rtDW.Memory_PreviousInput_m[1] = true;

  /* InitializeConditions for Memory: '<S26>/Memory' */
  rtDW.Memory_PreviousInput_f[2] = true;

  /* InitializeConditions for Memory: '<S27>/Memory' */
  rtDW.Memory_PreviousInput_m[2] = true;

  /* InitializeConditions for Memory: '<S26>/Memory' */
  rtDW.Memory_PreviousInput_f[3] = true;

  /* InitializeConditions for Memory: '<S27>/Memory' */
  rtDW.Memory_PreviousInput_m[3] = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
