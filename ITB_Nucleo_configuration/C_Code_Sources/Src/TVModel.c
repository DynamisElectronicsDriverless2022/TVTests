/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon May 16 11:16:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TVModel.h"

/* Named constants for Chart: '<S75>/T_Req_Chart' */
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
static real_T look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static void YRD_LUT_1(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd);
static void YRD_LUT_0(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd);
static void YRD_LUT_15(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
  *rty_yrd);
static void YRD_LUT_3(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd);
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

/*
 * Output and update for action system:
 *    '<S17>/YRD_LUT_1'
 *    '<S17>/YRD_LUT_3'
 */
static void YRD_LUT_1(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_absolute_front_wheel_angle;
  real_T rtb_vx_ni;

  /* Abs: '<S70>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S70>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_ni = 3.0;
  } else {
    rtb_vx_ni = rtu_vx;
  }

  /* End of Saturate: '<S70>/Saturation' */

  /* Product: '<S70>/Divide2' incorporates:
   *  Abs: '<S70>/Abs'
   *  Lookup_n-D: '<S70>/LUT_1'
   *  Product: '<S70>/Divide'
   *  Product: '<S70>/Divide1'
   *  Saturate: '<S70>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_ni, rtConstP.pooled11,
                 rtConstP.pooled12, rtConstP.pooled6, rtConstP.pooled43, 100U) /
     rtb_vx_ni);
}

/*
 * Output and update for action system:
 *    '<S17>/YRD_LUT_0'
 *    '<S17>/YRD_LUT_2'
 */
static void YRD_LUT_0(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_absolute_front_wheel_angle;
  real_T rtb_vx_g;

  /* Abs: '<S69>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S69>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_g = 3.0;
  } else {
    rtb_vx_g = rtu_vx;
  }

  /* End of Saturate: '<S69>/Saturation' */

  /* Product: '<S69>/Divide2' incorporates:
   *  Abs: '<S69>/Abs'
   *  Lookup_n-D: '<S69>/LUT_0'
   *  Product: '<S69>/Divide'
   *  Product: '<S69>/Divide1'
   *  Saturate: '<S69>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_g, rtConstP.pooled11,
                 rtConstP.pooled12, rtConstP.pooled7, rtConstP.pooled43, 100U) /
     rtb_vx_g);
}

/*
 * Output and update for action system:
 *    '<S17>/YRD_LUT_-1.5'
 *    '<S17>/YRD_LUT_-1.1'
 */
static void YRD_LUT_15(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
  *rty_yrd)
{
  real_T rtb_absolute_front_wheel_angle;
  real_T rtb_vx_l;

  /* Abs: '<S67>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S67>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_l = 3.0;
  } else {
    rtb_vx_l = rtu_vx;
  }

  /* End of Saturate: '<S67>/Saturation' */

  /* Product: '<S67>/Divide2' incorporates:
   *  Abs: '<S67>/Abs'
   *  Lookup_n-D: '<S67>/LUT_-1.5'
   *  Product: '<S67>/Divide'
   *  Product: '<S67>/Divide1'
   *  Saturate: '<S67>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_l, rtConstP.pooled11,
                 rtConstP.pooled12, rtConstP.pooled8, rtConstP.pooled43, 100U) /
     rtb_vx_l);
}

/*
 * Output and update for action system:
 *    '<S17>/YRD_LUT_-3'
 *    '<S17>/YRD_LUT_-1'
 */
static void YRD_LUT_3(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_absolute_front_wheel_angle;
  real_T rtb_vx_g;

  /* Abs: '<S68>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S68>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_g = 3.0;
  } else {
    rtb_vx_g = rtu_vx;
  }

  /* End of Saturate: '<S68>/Saturation' */

  /* Product: '<S68>/Divide2' incorporates:
   *  Abs: '<S68>/Abs'
   *  Lookup_n-D: '<S68>/LUT_-3'
   *  Product: '<S68>/Divide'
   *  Product: '<S68>/Divide1'
   *  Saturate: '<S68>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_g, rtConstP.pooled11,
                 rtConstP.pooled12, rtConstP.pooled10, rtConstP.pooled43, 100U) /
     rtb_vx_g);
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

/* Model step function */
void TV(void)
{
  g_dsp_internal_SlidingWindowA_l *obj_0;
  g_dsp_internal_SlidingWindowAve *obj;
  real_T rtb_y[121];
  real_T varargin_1[49];
  real_T rtb_CCaller_o12[35];
  real_T rtb_CCaller_o3[26];
  real_T csumrev[24];
  real_T rtb_VectorConcatenate[22];
  real_T varargin_2[16];
  real_T RateTransition3[13];
  real_T rtb_TmpSignalConversionAtSFunct[11];
  real_T rtb_CCaller_o2[7];
  real_T v[7];
  real_T rtb_CCaller_o10[5];
  real_T rtb_lg[5];
  real_T rtb_CCaller_o8[4];
  real_T rtb_Sum_h[4];
  real_T rtb_TmpSignalConversionAt2DLook[4];
  real_T rtb_tire_lbu[4];
  real_T tmp_0[3];
  real_T tmp[2];
  real_T modValueRev;
  real_T rtb_Abs;
  real_T rtb_Abs_e;
  real_T rtb_Abs_m;
  real_T rtb_Memory_idx_0;
  real_T rtb_Memory_idx_1;
  real_T rtb_Memory_idx_2;
  real_T rtb_Memory_idx_3;
  real_T rtb_MovingAverage_0;
  real_T rtb_Product_l;
  real_T rtb_RL_j;
  real_T rtb_RR;
  real_T rtb_Switch_b;
  real_T rtb_Switch_h;
  real_T rtb_YRD;
  real_T rtb_front_wheel_angle_single__m;
  real_T rtb_tire_lbu_tmp;
  real_T rtb_tire_lbu_tmp_0;
  real_T rtb_vx;
  real_T rtb_vx_a;
  real_T rtb_vy;
  real_T rtb_yaw_rate;
  real_T u0;
  real_T z;
  int32_T i;
  int32_T iU;
  int16_T LessThan;
  boolean_T rtb_LessThan3_n;
  boolean_T rtb_Logic_idx_0;
  static const int8_T b[7] = { 0, 0, 0, 1, 1, 1, 1 };

  static const int8_T c[7] = { 0, 0, 0, 0, 1, 0, -1 };

  static const int8_T d[7] = { 0, 0, 0, 1, 0, -1, 0 };

  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (rtU.vx <= 0.0) {
    rtb_Switch_h = 0.0;
  } else {
    rtb_Switch_h = rtU.vx;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/yaw_rate'
   */
  rtb_Product_l = 0.017453292519943295 * rtU.yaw_rate_deg;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Switch_h <= 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = rtb_Switch_h;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Signum: '<S9>/Sign' incorporates:
   *  Inport: '<Root>/steering'
   */
  if (rtU.steering < 0.0) {
    rtb_Switch_h = -1.0;
  } else if (rtU.steering > 0.0) {
    rtb_Switch_h = 1.0;
  } else if (rtU.steering == 0.0) {
    rtb_Switch_h = 0.0;
  } else {
    rtb_Switch_h = (rtNaN);
  }

  /* End of Signum: '<S9>/Sign' */

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Abs_m = fabs(look1_binlx(rtU.steering, rtConstP.pooled17,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Switch_h;
  rtb_Abs_e = fabs(look1_binlx(-rtU.steering, rtConstP.pooled17,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Switch_h;

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
    rtb_Switch_h = rtb_vx * cos(rtb_Abs_m) + sin(rtb_Abs_m) * rtU.vy;
    rtb_Switch_h = (0.235 * rtU.omega_wheels_FL - rtb_Switch_h) / rtb_Switch_h;

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
    rtb_Switch_b = rtb_vx * cos(rtb_Abs_e) + sin(rtb_Abs_e) * rtU.vy;
    rtb_Switch_b = (0.235 * rtU.omega_wheels_FR - rtb_Switch_b) / rtb_Switch_b;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_vx) / rtb_vx;
    rtb_RL_j = (0.235 * rtU.omega_wheels_RL - rtb_vx) / rtb_vx;
  } else {
    rtb_Switch_h = 0.0;
    rtb_Switch_b = 0.0;
    rtb_RR = 0.0;
    rtb_RL_j = 0.0;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_front_wheel_angle_single__m = look1_binlx(rtU.steering, rtConstP.pooled17,
    rtConstP.steering_to_wheel_angle_single_, 32U);

  /* Outputs for IfAction SubSystem: '<S17>/YRD_LUT_-3' incorporates:
   *  ActionPort: '<S68>/Action Port'
   */
  /* If: '<S17>/If' */
  YRD_LUT_3(rtb_front_wheel_angle_single__m, rtb_vx, &rtDW.yaw_rate_desired_LUT);

  /* End of Outputs for SubSystem: '<S17>/YRD_LUT_-3' */

  /* Outputs for IfAction SubSystem: '<S17>/YRD_LUT_-1' incorporates:
   *  ActionPort: '<S65>/Action Port'
   */
  /* If: '<S17>/If1' */
  YRD_LUT_3(rtb_front_wheel_angle_single__m, rtb_vx,
            &rtDW.yaw_rate_desired_LUT_f);

  /* End of Outputs for SubSystem: '<S17>/YRD_LUT_-1' */

  /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_YRD = (1.0 - rtU.brake) * rtDW.yaw_rate_desired_LUT_f +
    rtDW.yaw_rate_desired_LUT * rtU.brake;

  /* SignalConversion generated from: '<S18>/Vector Concatenate' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant1'
   *  Constant: '<S18>/T_FL_ref'
   *  Constant: '<S18>/T_FR_ref'
   *  Constant: '<S18>/T_RL_ref'
   *  Constant: '<S18>/T_RR_ref'
   *  Constant: '<S18>/dT_FL_ref'
   *  Constant: '<S18>/dT_FR_ref'
   *  Constant: '<S18>/dT_RL_ref'
   *  Constant: '<S18>/dT_RR_ref'
   */
  rtb_TmpSignalConversionAtSFunct[0] = 0.0;
  rtb_TmpSignalConversionAtSFunct[1] = 0.0;
  rtb_TmpSignalConversionAtSFunct[2] = rtb_YRD;
  memset(&rtb_TmpSignalConversionAtSFunct[3], 0, sizeof(real_T) << 3U);
  memcpy(&rtb_VectorConcatenate[0], &rtb_TmpSignalConversionAtSFunct[0], 11U *
         sizeof(real_T));

  /* SignalConversion generated from: '<S18>/Vector Concatenate' */
  memcpy(&rtb_VectorConcatenate[11], &rtb_TmpSignalConversionAtSFunct[0], 11U *
         sizeof(real_T));

  /* RateTransition: '<S28>/Rate Transition3' incorporates:
   *  Constant: '<S19>/Inertia Scaling'
   *  Constant: '<S19>/LMUy'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = rtb_front_wheel_angle_single__m;
  RateTransition3[1] = rtb_Switch_h;
  RateTransition3[2] = rtb_Switch_b;
  RateTransition3[3] = rtb_RL_j;
  RateTransition3[4] = rtb_RR;
  RateTransition3[5] = rtDW.UnitDelay_DSTATE[0];
  RateTransition3[6] = rtDW.UnitDelay_DSTATE[1];
  RateTransition3[7] = rtDW.UnitDelay_DSTATE[2];
  RateTransition3[8] = rtDW.UnitDelay_DSTATE[3];
  RateTransition3[9] = rtU.ay;
  RateTransition3[10] = rtU.ax;
  RateTransition3[11] = 0.75;
  RateTransition3[12] = 1.0;

  /* CFunction: '<S28>/C Function' incorporates:
   *  Constant: '<S28>/Constant3'
   */
  for (i = 0; i < 2; i++) {
    memcpy(&rtDW.CFunction[i * 13], &RateTransition3[0], 13U * sizeof(real_T));
  }

  /* End of CFunction: '<S28>/C Function' */

  /* Memory: '<S16>/Memory' */
  rtb_Memory_idx_0 = rtDW.Memory_PreviousInput[0];
  rtb_Memory_idx_1 = rtDW.Memory_PreviousInput[1];
  rtb_Memory_idx_2 = rtDW.Memory_PreviousInput[2];
  rtb_Memory_idx_3 = rtDW.Memory_PreviousInput[3];

  /* Saturate: '<S20>/Saturation' */
  if (rtb_vx <= 2.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_CCaller_o2[0] = 2.0;
  } else {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_CCaller_o2[0] = rtb_vx;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* Saturate: '<S20>/Saturation1' incorporates:
   *  Inport: '<Root>/vy'
   */
  if (rtU.vy > 5.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_CCaller_o2[1] = 5.0;
  } else if (rtU.vy < -5.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_CCaller_o2[1] = -5.0;
  } else {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_CCaller_o2[1] = rtU.vy;
  }

  /* End of Saturate: '<S20>/Saturation1' */

  /* Saturate: '<S20>/Saturation2' */
  if (rtb_Product_l > 4.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_CCaller_o2[2] = 4.0;
  } else if (rtb_Product_l < -4.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_CCaller_o2[2] = -4.0;
  } else {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_CCaller_o2[2] = rtb_Product_l;
  }

  /* End of Saturate: '<S20>/Saturation2' */

  /* SignalConversion generated from: '<S16>/C Caller' */
  rtb_CCaller_o2[3] = rtb_Memory_idx_0;
  rtb_CCaller_o2[4] = rtb_Memory_idx_1;
  rtb_CCaller_o2[5] = rtb_Memory_idx_2;
  rtb_CCaller_o2[6] = rtb_Memory_idx_3;

  /* Math: '<S39>/Square1' incorporates:
   *  Math: '<S39>/Square2'
   *  Math: '<S41>/Square1'
   */
  rtb_yaw_rate = rtb_vx * rtb_vx;

  /* Gain: '<S39>/Lateral Load Transfer' incorporates:
   *  Gain: '<S40>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S39>/Unary Minus'
   */
  modValueRev = 30.826771653543307 * -rtU.ay;

  /* Gain: '<S39>/Lift Force' incorporates:
   *  Gain: '<S40>/Lift Force'
   *  Math: '<S39>/Square1'
   */
  rtb_vy = rtb_yaw_rate * 0.87348504901960788;

  /* Gain: '<S39>/Drag moment' incorporates:
   *  Gain: '<S40>/Drag moment'
   *  Gain: '<S41>/Drag moment'
   *  Gain: '<S42>/Drag moment'
   */
  rtb_vx_a = rtb_yaw_rate * 0.19692235294117649;

  /* Gain: '<S39>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S40>/Longitudinal Load Transfer'
   *  Gain: '<S41>/Longitudinal Load Transfer'
   *  Gain: '<S42>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S39>/Unary Minus1'
   */
  rtb_Abs = 25.588235294117645 * -rtU.ax;

  /* SignalConversion generated from: '<S22>/2-D Lookup Table' incorporates:
   *  Constant: '<S39>/Static Load Front'
   *  Constant: '<S40>/Static Load Front'
   *  Gain: '<S39>/Drag moment'
   *  Gain: '<S39>/Lateral Load Transfer'
   *  Gain: '<S39>/Lift Force'
   *  Gain: '<S39>/Longitudinal Load Transfer'
   *  Sum: '<S39>/Subtract'
   *  Sum: '<S40>/Subtract'
   */
  rtb_Sum_h[0] = (((modValueRev + 662.17500000000007) + rtb_vy) - rtb_vx_a) +
    rtb_Abs;
  rtb_Sum_h[1] = (((662.17500000000007 - modValueRev) + rtb_vy) - rtb_vx_a) +
    rtb_Abs;

  /* Gain: '<S41>/Lift Force' incorporates:
   *  Gain: '<S42>/Lift Force'
   */
  rtb_yaw_rate *= 0.70063995098039222;

  /* SignalConversion generated from: '<S22>/2-D Lookup Table' incorporates:
   *  Constant: '<S41>/Static Load Front'
   *  Constant: '<S42>/Static Load Front'
   *  Gain: '<S41>/Lateral Load Transfer'
   *  Gain: '<S41>/Lift Force'
   *  Gain: '<S42>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  Sum: '<S41>/Subtract'
   *  Sum: '<S42>/Subtract'
   *  UnaryMinus: '<S41>/Unary Minus'
   *  UnaryMinus: '<S42>/Unary Minus'
   */
  rtb_Sum_h[2] = (((30.826771653543307 * -rtU.ay + 662.17500000000007) +
                   rtb_yaw_rate) + rtb_vx_a) - rtb_Abs;
  rtb_Sum_h[3] = (((662.17500000000007 - 30.826771653543307 * -rtU.ay) +
                   rtb_yaw_rate) + rtb_vx_a) - rtb_Abs;

  /* Sum: '<S44>/Subtract1' incorporates:
   *  Gain: '<S44>/Gain'
   *  Inport: '<Root>/vy'
   *  Sum: '<S45>/Subtract1'
   */
  rtb_yaw_rate = 0.765 * rtb_Product_l + rtU.vy;

  /* Sum: '<S44>/Subtract' incorporates:
   *  Gain: '<S44>/Gain1'
   *  Sum: '<S46>/Subtract'
   */
  modValueRev = rtb_vx - 0.635 * rtb_Product_l;

  /* SignalConversion generated from: '<S22>/2-D Lookup Table' incorporates:
   *  Sum: '<S44>/Subtract'
   *  Sum: '<S44>/Subtract1'
   *  Sum: '<S44>/Subtract2'
   *  Trigonometry: '<S44>/Atan'
   */
  rtb_TmpSignalConversionAt2DLook[0] = rt_atan2d_snf(rtb_yaw_rate, modValueRev)
    - rtb_Abs_m;

  /* Sum: '<S45>/Subtract' incorporates:
   *  Gain: '<S45>/Gain1'
   *  Sum: '<S47>/Subtract'
   */
  rtb_vy = 0.635 * rtb_Product_l + rtb_vx;

  /* SignalConversion generated from: '<S22>/2-D Lookup Table' incorporates:
   *  Sum: '<S45>/Subtract'
   *  Sum: '<S45>/Subtract2'
   *  Trigonometry: '<S45>/Atan'
   */
  rtb_TmpSignalConversionAt2DLook[1] = rt_atan2d_snf(rtb_yaw_rate, rtb_vy) -
    rtb_Abs_e;

  /* Sum: '<S46>/Subtract1' incorporates:
   *  Gain: '<S46>/Gain'
   *  Inport: '<Root>/vy'
   *  Sum: '<S47>/Subtract1'
   */
  rtb_yaw_rate = rtU.vy - 0.765 * rtb_Product_l;

  /* SignalConversion generated from: '<S22>/2-D Lookup Table' incorporates:
   *  Sum: '<S46>/Subtract1'
   *  Trigonometry: '<S46>/Atan'
   *  Trigonometry: '<S47>/Atan'
   */
  rtb_TmpSignalConversionAt2DLook[2] = rt_atan2d_snf(rtb_yaw_rate, modValueRev);
  rtb_TmpSignalConversionAt2DLook[3] = rt_atan2d_snf(rtb_yaw_rate, rtb_vy);

  /* Lookup_n-D: '<S22>/2-D Lookup Table' */
  rtb_tire_lbu[0] = look2_binlx(rtb_Sum_h[0], rtb_TmpSignalConversionAt2DLook[0],
    rtConstP.pooled28, rtConstP.pooled29, rtConstP.uDLookupTable_tableData_l,
    rtConstP.pooled44, 20U);
  rtb_tire_lbu[1] = look2_binlx(rtb_Sum_h[1], rtb_TmpSignalConversionAt2DLook[1],
    rtConstP.pooled28, rtConstP.pooled29, rtConstP.uDLookupTable_tableData_l,
    rtConstP.pooled44, 20U);
  rtb_tire_lbu[2] = look2_binlx(rtb_Sum_h[2], rtb_TmpSignalConversionAt2DLook[2],
    rtConstP.pooled28, rtConstP.pooled29, rtConstP.uDLookupTable_tableData_l,
    rtConstP.pooled44, 20U);
  rtb_tire_lbu[3] = look2_binlx(rtb_Sum_h[3], rtb_TmpSignalConversionAt2DLook[3],
    rtConstP.pooled28, rtConstP.pooled29, rtConstP.uDLookupTable_tableData_l,
    rtConstP.pooled44, 20U);

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_vx_a = 3.5714285714285712 * rtU.brake;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_vx_a > 1.0) {
    rtb_vx_a = 1.0;
  } else if (rtb_vx_a < 0.0) {
    rtb_vx_a = 0.0;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Switch: '<S30>/Switch' */
  rtb_vy = !(rtb_vx_a > 0.95);

  /* Saturate: '<S22>/Saturation1' incorporates:
   *  Gain: '<S22>/Gain'
   *  Product: '<S22>/Product'
   */
  modValueRev = 0.017407407407407406 * rtb_tire_lbu[0] * 0.5376344086021505;
  if (modValueRev <= 0.0) {
    modValueRev = 0.0;
  }

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  MinMax: '<S22>/Min'
   */
  rtb_tire_lbu[0] = fmin(modValueRev, 21.0) * rtb_vy;

  /* Saturate: '<S22>/Saturation1' incorporates:
   *  Gain: '<S22>/Gain'
   *  Product: '<S22>/Product'
   */
  modValueRev = 0.017407407407407406 * rtb_tire_lbu[1] * 0.5376344086021505;
  if (modValueRev <= 0.0) {
    modValueRev = 0.0;
  }

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  MinMax: '<S22>/Min'
   */
  rtb_tire_lbu[1] = fmin(modValueRev, 21.0) * rtb_vy;

  /* Saturate: '<S22>/Saturation1' incorporates:
   *  Gain: '<S22>/Gain'
   *  Product: '<S22>/Product'
   */
  modValueRev = 0.017407407407407406 * rtb_tire_lbu[2] * 0.5376344086021505;
  if (modValueRev <= 0.0) {
    modValueRev = 0.0;
  }

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  MinMax: '<S22>/Min'
   */
  rtb_tire_lbu[2] = fmin(modValueRev, 21.0) * rtb_vy;

  /* Saturate: '<S22>/Saturation1' incorporates:
   *  Gain: '<S22>/Gain'
   *  Product: '<S22>/Product'
   */
  modValueRev = 0.017407407407407406 * rtb_tire_lbu[3] * 0.5376344086021505;
  if (modValueRev <= 0.0) {
    modValueRev = 0.0;
  }

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain'
   *  MinMax: '<S22>/Min'
   */
  rtb_tire_lbu[3] = fmin(modValueRev, 21.0) * rtb_vy;

  /* RelationalOperator: '<S43>/Less Than' incorporates:
   *  Abs: '<S43>/Abs'
   *  Constant: '<S43>/             '
   */
  LessThan = (int16_T)(fabs(rtb_YRD) <= 0.25);

  /* DiscreteFir: '<S43>/Discrete FIR Filter' */
  i = LessThan << 14;
  for (iU = rtDW.DiscreteFIRFilter_circBuf; iU < 9; iU++) {
    i += rtDW.DiscreteFIRFilter_states_e[iU] << 14;
  }

  for (iU = 0; iU < rtDW.DiscreteFIRFilter_circBuf; iU++) {
    i += rtDW.DiscreteFIRFilter_states_e[iU] << 14;
  }

  /* RelationalOperator: '<S43>/Less Than4' incorporates:
   *  DiscreteFir: '<S43>/Discrete FIR Filter'
   */
  rtb_LessThan3_n = (i >= 163840);

  /* Lookup_n-D: '<S22>/2-D Lookup Table1' */
  rtb_Sum_h[0] = look2_binlx(rtb_Sum_h[0], rtb_TmpSignalConversionAt2DLook[0],
    rtConstP.pooled28, rtConstP.pooled29, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled44, 20U);
  rtb_Sum_h[1] = look2_binlx(rtb_Sum_h[1], rtb_TmpSignalConversionAt2DLook[1],
    rtConstP.pooled28, rtConstP.pooled29, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled44, 20U);
  rtb_Sum_h[2] = look2_binlx(rtb_Sum_h[2], rtb_TmpSignalConversionAt2DLook[2],
    rtConstP.pooled28, rtConstP.pooled29, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled44, 20U);
  rtb_Sum_h[3] = look2_binlx(rtb_Sum_h[3], rtb_TmpSignalConversionAt2DLook[3],
    rtConstP.pooled28, rtConstP.pooled29, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled44, 20U);

  /* Saturate: '<S22>/Saturation' incorporates:
   *  Gain: '<S22>/Gain1'
   *  Gain: '<S34>/Wheel2Motor'
   *  Product: '<S22>/Product1'
   *  Sum: '<S34>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  modValueRev = 0.017407407407407406 * rtb_Sum_h[0] * 0.5376344086021505 +
    0.07407407407407407 * rtDW.UnitDelay_DSTATE[0];
  if (modValueRev >= 0.0) {
    modValueRev = 0.0;
  }

  /* MinMax: '<S22>/Min1' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Product: '<S22>/Product1'
   */
  rtb_Sum_h[0] = fmax(modValueRev, -21.0);

  /* Saturate: '<S22>/Saturation' incorporates:
   *  Gain: '<S22>/Gain1'
   *  Gain: '<S34>/Wheel2Motor'
   *  Product: '<S22>/Product1'
   *  Sum: '<S34>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  modValueRev = 0.017407407407407406 * rtb_Sum_h[1] * 0.5376344086021505 +
    0.07407407407407407 * rtDW.UnitDelay_DSTATE[1];
  if (modValueRev >= 0.0) {
    modValueRev = 0.0;
  }

  /* MinMax: '<S22>/Min1' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Product: '<S22>/Product1'
   */
  rtb_Sum_h[1] = fmax(modValueRev, -21.0);

  /* Saturate: '<S22>/Saturation' incorporates:
   *  Gain: '<S22>/Gain1'
   *  Gain: '<S34>/Wheel2Motor'
   *  Product: '<S22>/Product1'
   *  Sum: '<S34>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  modValueRev = 0.017407407407407406 * rtb_Sum_h[2] * 0.5376344086021505 +
    0.07407407407407407 * rtDW.UnitDelay_DSTATE[2];
  if (modValueRev >= 0.0) {
    modValueRev = 0.0;
  }

  /* MinMax: '<S22>/Min1' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Product: '<S22>/Product1'
   */
  rtb_Sum_h[2] = fmax(modValueRev, -21.0);

  /* Saturate: '<S22>/Saturation' incorporates:
   *  Gain: '<S22>/Gain1'
   *  Gain: '<S34>/Wheel2Motor'
   *  Product: '<S22>/Product1'
   *  Sum: '<S34>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  modValueRev = 0.017407407407407406 * rtb_Sum_h[3] * 0.5376344086021505 +
    0.07407407407407407 * rtDW.UnitDelay_DSTATE[3];
  if (modValueRev >= 0.0) {
    modValueRev = 0.0;
  }

  /* MinMax: '<S22>/Min1' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Product: '<S22>/Product1'
   */
  rtb_Sum_h[3] = fmax(modValueRev, -21.0);

  /* Product: '<S29>/Product' incorporates:
   *  Constant: '<S29>/Constant'
   *  RelationalOperator: '<S29>/Less Than'
   */
  rtb_TmpSignalConversionAt2DLook[0] = (real_T)(rtb_Switch_h >= -0.5) *
    rtb_Sum_h[0];
  rtb_TmpSignalConversionAt2DLook[1] = (real_T)(rtb_Switch_b >= -0.5) *
    rtb_Sum_h[1];
  rtb_TmpSignalConversionAt2DLook[2] = (real_T)(rtb_RL_j >= -0.5) * rtb_Sum_h[2];
  rtb_TmpSignalConversionAt2DLook[3] = (real_T)(rtb_RR >= -0.5) * rtb_Sum_h[3];

  /* SignalConversion generated from: '<S33>/ SFunction ' incorporates:
   *  MATLAB Function: '<S22>/Cross Check'
   */
  RateTransition3[1] = rtb_tire_lbu[0];
  RateTransition3[2] = rtb_tire_lbu[1];
  RateTransition3[3] = rtb_tire_lbu[2];
  RateTransition3[4] = rtb_tire_lbu[3];
  RateTransition3[5] = rtb_TmpSignalConversionAt2DLook[0];
  RateTransition3[6] = rtb_TmpSignalConversionAt2DLook[1];
  RateTransition3[7] = rtb_TmpSignalConversionAt2DLook[2];
  RateTransition3[8] = rtb_TmpSignalConversionAt2DLook[3];
  RateTransition3[9] = rtb_Sum_h[0];

  /* MATLAB Function: '<S22>/Cross Check' incorporates:
   *  Constant: '<S43>/ '
   *  Constant: '<S43>/  '
   *  Constant: '<S43>/Constant'
   *  DataTypeConversion: '<S43>/Data Type Conversion'
   *  DataTypeConversion: '<S43>/Data Type Conversion1'
   *  Gain: '<S43>/Gain'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S43>/AND'
   *  Logic: '<S43>/AND1'
   *  Logic: '<S43>/AND2'
   *  RelationalOperator: '<S43>/Less Than1'
   *  RelationalOperator: '<S43>/Less Than2'
   *  RelationalOperator: '<S43>/Less Than3'
   *  Sum: '<S43>/Sum'
   */
  switch ((int32_T)((real_T)((rtb_vx_a < 0.95) && (0.05 < rtb_vx_a) &&
            rtb_LessThan3_n) * 2.0 + (real_T)(rtb_LessThan3_n && (rtU.throttle >=
             0.05)))) {
   case 0:
    if (rtb_TmpSignalConversionAt2DLook[0] > rtb_tire_lbu[0]) {
      rtb_TmpSignalConversionAt2DLook[0] = rtb_tire_lbu[0] - RateTransition3[9];
    }

    if (rtb_TmpSignalConversionAt2DLook[1] > rtb_tire_lbu[1]) {
      rtb_TmpSignalConversionAt2DLook[1] = rtb_tire_lbu[1] - RateTransition3[9];
    }

    if (rtb_TmpSignalConversionAt2DLook[2] > rtb_tire_lbu[2]) {
      rtb_TmpSignalConversionAt2DLook[2] = rtb_tire_lbu[2] - RateTransition3[9];
    }

    if (rtb_TmpSignalConversionAt2DLook[3] > rtb_tire_lbu[3]) {
      rtb_TmpSignalConversionAt2DLook[3] = rtb_tire_lbu[3] - RateTransition3[9];
    }
    break;

   case 1:
    rtb_tire_lbu[0] = RateTransition3[1];
    rtb_TmpSignalConversionAt2DLook[0] = 0.0;
    rtb_tire_lbu[1] = RateTransition3[2];
    rtb_TmpSignalConversionAt2DLook[1] = 0.0;
    rtb_tire_lbu[2] = RateTransition3[3];
    rtb_TmpSignalConversionAt2DLook[2] = 0.0;
    rtb_tire_lbu[3] = RateTransition3[4];
    rtb_TmpSignalConversionAt2DLook[3] = 0.0;
    break;

   case 2:
    rtb_TmpSignalConversionAt2DLook[0] = RateTransition3[5];
    rtb_tire_lbu[0] = 0.0;
    rtb_TmpSignalConversionAt2DLook[1] = RateTransition3[6];
    rtb_tire_lbu[1] = 0.0;
    rtb_TmpSignalConversionAt2DLook[2] = RateTransition3[7];
    rtb_tire_lbu[2] = 0.0;
    rtb_TmpSignalConversionAt2DLook[3] = RateTransition3[8];
    rtb_tire_lbu[3] = 0.0;
    break;

   case 3:
    rtb_TmpSignalConversionAt2DLook[0] = 0.0;
    rtb_tire_lbu[0] = 0.0;
    rtb_TmpSignalConversionAt2DLook[1] = 0.0;
    rtb_tire_lbu[1] = 0.0;
    rtb_TmpSignalConversionAt2DLook[2] = 0.0;
    rtb_tire_lbu[2] = 0.0;
    rtb_TmpSignalConversionAt2DLook[3] = 0.0;
    rtb_tire_lbu[3] = 0.0;
    break;
  }

  /* CFunction: '<S31>/C Function' incorporates:
   *  Constant: '<S31>/Constant3'
   */
  rtDW.CFunction_c[0] = rtb_TmpSignalConversionAt2DLook[0];
  rtDW.CFunction_c[1] = rtb_TmpSignalConversionAt2DLook[1];
  rtDW.CFunction_c[2] = rtb_TmpSignalConversionAt2DLook[2];
  rtDW.CFunction_c[3] = rtb_TmpSignalConversionAt2DLook[3];

  /* CFunction: '<S32>/C Function' incorporates:
   *  Constant: '<S32>/Constant3'
   */
  rtDW.CFunction_ch[0] = rtb_tire_lbu[0];
  rtDW.CFunction_ch[1] = rtb_tire_lbu[1];
  rtDW.CFunction_ch[2] = rtb_tire_lbu[2];
  rtDW.CFunction_ch[3] = rtb_tire_lbu[3];

  /* Product: '<S24>/Product' incorporates:
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S24>/Constant2'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S49>/Exponent < 0'
   *  Gain: '<S24>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S24>/ '
   *  Math: '<S49>/Power'
   *  Product: '<S24>/Product1'
   *  Product: '<S49>/Divide'
   *  Product: '<S49>/Divide1'
   *  RelationalOperator: '<S24>/Less Than'
   *  RelationalOperator: '<S24>/Less Than1'
   *  Sum: '<S24>/Subtract1'
   *  Sum: '<S49>/Subtract'
   *  Sum: '<S49>/Sum'
   */
  rtb_vy = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle), -1.5) + 1.0)
            - rtb_vx_a) * (real_T)(boolean_T)((rtb_vx_a >= 0.05) ^ (rtU.throttle
    >= 0.05)) * 84.0;

  /* Gain: '<S24>/Gain2' */
  rtb_YRD = 0.95 * rtb_vy;

  /* Gain: '<S24>/Gain3' */
  rtb_yaw_rate = 1.05 * rtb_vy;

  /* Switch: '<S24>/Switch2' incorporates:
   *  Constant: '<S24>/Engine Brake'
   *  Constant: '<S50>/Constant1'
   *  Constant: '<S50>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S50>/AND'
   *  MinMax: '<S24>/Max1'
   *  RelationalOperator: '<S50>/Less Than'
   *  RelationalOperator: '<S50>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_vx_a)) {
    rtb_vx_a = -0.0;
  } else {
    rtb_vx_a = fmin(rtb_YRD, rtb_yaw_rate);
  }

  /* End of Switch: '<S24>/Switch2' */

  /* UnaryMinus: '<S24>/Unary Minus1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  rtb_vy = 35000.0;

  /* InitialCondition: '<S24>/IC' */
  if (rtDW.IC_FirstOutputTime) {
    rtDW.IC_FirstOutputTime = false;
    rtb_vy = -35000.0;
  }

  /* End of InitialCondition: '<S24>/IC' */

  /* Abs: '<S52>/Abs' */
  rtb_Abs = fabs(rtb_front_wheel_angle_single__m);

  /* MATLABSystem: '<S52>/Moving Average' */
  if (rtDW.obj.TunablePropsChanged) {
    rtDW.obj.TunablePropsChanged = false;
  }

  obj = rtDW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 24; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 24; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  rtb_Product_l = obj->pCumRevIndex;
  rtb_front_wheel_angle_single__m = obj->pCumSum;
  for (i = 0; i < 24; i++) {
    csumrev[i] = obj->pCumSumRev[i];
  }

  modValueRev = obj->pModValueRev;
  z = 0.0;
  rtb_MovingAverage_0 = 0.0;
  rtb_front_wheel_angle_single__m += rtb_Abs;
  if (modValueRev == 0.0) {
    z = csumrev[(int32_T)rtb_Product_l - 1] + rtb_front_wheel_angle_single__m;
  }

  csumrev[(int32_T)rtb_Product_l - 1] = rtb_Abs;
  if (rtb_Product_l != 24.0) {
    rtb_Product_l++;
  } else {
    rtb_Product_l = 1.0;
    rtb_front_wheel_angle_single__m = 0.0;
    for (i = 22; i >= 0; i--) {
      csumrev[i] += csumrev[i + 1];
    }
  }

  if (modValueRev == 0.0) {
    rtb_MovingAverage_0 = z / 25.0;
  }

  obj->pCumSum = rtb_front_wheel_angle_single__m;
  for (i = 0; i < 24; i++) {
    obj->pCumSumRev[i] = csumrev[i];
  }

  obj->pCumRevIndex = rtb_Product_l;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* CombinatorialLogic: '<S56>/Logic' incorporates:
   *  Constant: '<S52>/Constant1'
   *  Constant: '<S52>/Constant4'
   *  Delay: '<S52>/Delay'
   *  Logic: '<S52>/AND'
   *  MATLABSystem: '<S52>/Moving Average'
   *  Memory: '<S56>/Memory'
   *  RelationalOperator: '<S52>/Less Than'
   *  RelationalOperator: '<S52>/Less Than2'
   */
  rtb_Logic_idx_0 = rtConstP.Logic_table[((((uint32_T)(0.017453292519943295 <=
    rtb_Abs) << 1) + ((rtb_MovingAverage_0 < 0.0043633231299858239) &&
                      rtDW.Delay_DSTATE[0])) << 1) + rtDW.Memory_PreviousInput_i];

  /* If: '<S52>/If' incorporates:
   *  Constant: '<S53>/Constant9'
   *  Logic: '<S53>/AND1'
   *  RelationalOperator: '<S53>/Less Than4'
   *  UnitDelay: '<S53>/Unit Delay1'
   */
  if ((!rtDW.UnitDelay1_DSTATE) && (0 < (int32_T)rtb_Logic_idx_0)) {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    /* Saturate: '<S55>/Saturation1' incorporates:
     *  Constant: '<S55>/Constant'
     *  Sum: '<S55>/Subtract'
     */
    if (rtb_Abs - 0.017453292519943295 <= 0.0) {
      rtb_Abs = 0.0;
    } else {
      rtb_Abs -= 0.017453292519943295;
    }

    /* End of Saturate: '<S55>/Saturation1' */

    /* Gain: '<S55>/Gain' */
    rtb_Product_l = 28.647889756541161 * rtb_Abs;

    /* Saturate: '<S55>/Saturation' */
    if (rtb_Product_l > 1.0) {
      rtb_Product_l = 1.0;
    }

    /* End of Saturate: '<S55>/Saturation' */
    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    /* DataTypeConversion: '<S54>/Data Type Conversion' */
    rtb_Product_l = rtb_Logic_idx_0;

    /* End of Outputs for SubSystem: '<S52>/If Action Subsystem' */
  }

  /* End of If: '<S52>/If' */

  /* Product: '<S51>/Product' incorporates:
   *  Constant: '<S51>/Constant'
   */
  rtb_Product_l *= 20.0;

  /* SignalConversion generated from: '<S16>/C Caller' */
  rtb_lg[0] = rtb_vx_a;

  /* Product: '<S24>/Divide' incorporates:
   *  Gain: '<S24>/Gain'
   *  Product: '<S24>/Divide1'
   */
  rtb_front_wheel_angle_single__m = 1.0 / (57.4468085106383 * rtb_vx);
  modValueRev = rtb_front_wheel_angle_single__m * rtb_vy;

  /* Saturate: '<S24>/Saturation' */
  if (modValueRev > 0.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_lg[1] = 0.0;
  } else if (modValueRev < -210.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_lg[1] = -210.0;
  } else {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_lg[1] = modValueRev;
  }

  /* End of Saturate: '<S24>/Saturation' */

  /* SignalConversion generated from: '<S16>/C Caller' incorporates:
   *  Constant: '<S24>/Constant3'
   *  UnaryMinus: '<S24>/Unary Minus'
   */
  rtb_lg[2] = -2.0;
  rtb_lg[3] = -2.0;
  rtb_lg[4] = -rtb_Product_l;

  /* InitialCondition: '<S24>/IC1' */
  rtDW.IC1_FirstOutputTime = false;

  /* Product: '<S24>/Divide1' */
  modValueRev = rtb_front_wheel_angle_single__m * 80000.0;

  /* Gain: '<S60>/Gain2' incorporates:
   *  Gain: '<S57>/Gain2'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_front_wheel_angle_single__m = 13.5 * rtU.omega_wheels_FL;

  /* Saturate: '<S60>/Saturation' incorporates:
   *  Gain: '<S60>/Gain2'
   */
  if (rtb_front_wheel_angle_single__m > 2083.9231268812296) {
    rtb_Sum_h[0] = 2083.9231268812296;
  } else if (rtb_front_wheel_angle_single__m < 10.471975511965978) {
    rtb_Sum_h[0] = 10.471975511965978;
  } else {
    rtb_Sum_h[0] = rtb_front_wheel_angle_single__m;
  }

  /* Gain: '<S60>/Gain2' incorporates:
   *  Gain: '<S57>/Gain2'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  rtb_vy = 13.5 * rtU.omega_wheels_FR;

  /* Saturate: '<S60>/Saturation' incorporates:
   *  Gain: '<S60>/Gain2'
   */
  if (rtb_vy > 2083.9231268812296) {
    rtb_Sum_h[1] = 2083.9231268812296;
  } else if (rtb_vy < 10.471975511965978) {
    rtb_Sum_h[1] = 10.471975511965978;
  } else {
    rtb_Sum_h[1] = rtb_vy;
  }

  /* Gain: '<S60>/Gain2' incorporates:
   *  Gain: '<S57>/Gain2'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  rtb_vx_a = 13.5 * rtU.omega_wheels_RL;

  /* Saturate: '<S60>/Saturation' incorporates:
   *  Gain: '<S60>/Gain2'
   */
  if (rtb_vx_a > 2083.9231268812296) {
    rtb_Sum_h[2] = 2083.9231268812296;
  } else if (rtb_vx_a < 10.471975511965978) {
    rtb_Sum_h[2] = 10.471975511965978;
  } else {
    rtb_Sum_h[2] = rtb_vx_a;
  }

  /* Gain: '<S60>/Gain2' incorporates:
   *  Gain: '<S57>/Gain2'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_Abs = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S60>/Saturation' incorporates:
   *  Gain: '<S60>/Gain2'
   */
  if (rtb_Abs > 2083.9231268812296) {
    rtb_Sum_h[3] = 2083.9231268812296;
  } else if (rtb_Abs < 10.471975511965978) {
    rtb_Sum_h[3] = 10.471975511965978;
  } else {
    rtb_Sum_h[3] = rtb_Abs;
  }

  /* Abs: '<S63>/Abs' incorporates:
   *  Abs: '<S59>/Abs'
   */
  z = fabs(rtb_Memory_idx_0);
  rtb_tire_lbu[0] = z;
  rtb_MovingAverage_0 = fabs(rtb_Memory_idx_1);
  rtb_tire_lbu[1] = rtb_MovingAverage_0;
  rtb_tire_lbu_tmp = fabs(rtb_Memory_idx_2);
  rtb_tire_lbu[2] = rtb_tire_lbu_tmp;
  rtb_tire_lbu_tmp_0 = fabs(rtb_Memory_idx_3);
  rtb_tire_lbu[3] = rtb_tire_lbu_tmp_0;

  /* Lookup_n-D: '<S63>/2-D Lookup Table' */
  rtb_Sum_h[0] = look2_binlx(rtb_Sum_h[0], rtb_tire_lbu[0], rtConstP.pooled39,
    rtConstP.pooled40, rtConstP.pooled38, rtConstP.pooled45, 200U);
  rtb_Sum_h[1] = look2_binlx(rtb_Sum_h[1], rtb_tire_lbu[1], rtConstP.pooled39,
    rtConstP.pooled40, rtConstP.pooled38, rtConstP.pooled45, 200U);
  rtb_Sum_h[2] = look2_binlx(rtb_Sum_h[2], rtb_tire_lbu[2], rtConstP.pooled39,
    rtConstP.pooled40, rtConstP.pooled38, rtConstP.pooled45, 200U);
  rtb_Sum_h[3] = look2_binlx(rtb_Sum_h[3], rtb_tire_lbu[3], rtConstP.pooled39,
    rtConstP.pooled40, rtConstP.pooled38, rtConstP.pooled45, 200U);

  /* Saturate: '<S63>/Saturation' */
  u0 = rtb_Sum_h[0];
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < 0.3) {
    u0 = 0.3;
  }

  /* Product: '<S60>/Divide' incorporates:
   *  Constant: '<S60>/Constant'
   *  Gain: '<S60>/     '
   *  Saturate: '<S63>/Saturation'
   */
  rtb_Sum_h[0] = 1.0 / (0.96 * u0);

  /* Saturate: '<S63>/Saturation' */
  u0 = rtb_Sum_h[1];
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < 0.3) {
    u0 = 0.3;
  }

  /* Product: '<S60>/Divide' incorporates:
   *  Constant: '<S60>/Constant'
   *  Gain: '<S60>/     '
   *  Saturate: '<S63>/Saturation'
   */
  rtb_Sum_h[1] = 1.0 / (0.96 * u0);

  /* Saturate: '<S63>/Saturation' */
  u0 = rtb_Sum_h[2];
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < 0.3) {
    u0 = 0.3;
  }

  /* Product: '<S60>/Divide' incorporates:
   *  Constant: '<S60>/Constant'
   *  Gain: '<S60>/     '
   *  Saturate: '<S63>/Saturation'
   */
  rtb_Sum_h[2] = 1.0 / (0.96 * u0);

  /* Saturate: '<S63>/Saturation' */
  u0 = rtb_Sum_h[3];
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < 0.3) {
    u0 = 0.3;
  }

  /* Product: '<S60>/Divide' incorporates:
   *  Constant: '<S60>/Constant'
   *  Gain: '<S60>/     '
   *  Saturate: '<S63>/Saturation'
   */
  rtb_Sum_h[3] = 1.0 / (0.96 * u0);

  /* MATLAB Function: '<S60>/MATLAB Function' */
  if (rtb_Memory_idx_0 <= 0.0) {
    rtb_Sum_h[0] = 0.0;
  }

  if (rtb_Memory_idx_1 <= 0.0) {
    rtb_Sum_h[1] = 0.0;
  }

  if (rtb_Memory_idx_2 <= 0.0) {
    rtb_Sum_h[2] = 0.0;
  }

  if (rtb_Memory_idx_3 <= 0.0) {
    rtb_Sum_h[3] = 0.0;
  }

  /* End of MATLAB Function: '<S60>/MATLAB Function' */

  /* SignalConversion generated from: '<S61>/ SFunction ' incorporates:
   *  Gain: '<S27>/Gain'
   *  MATLAB Function: '<S27>/MATLAB Function'
   */
  rtb_TmpSignalConversionAtSFunct[3] = 0.001 * rtb_Sum_h[0];
  rtb_TmpSignalConversionAtSFunct[4] = 0.001 * rtb_Sum_h[1];
  rtb_TmpSignalConversionAtSFunct[5] = 0.001 * rtb_Sum_h[2];
  rtb_TmpSignalConversionAtSFunct[6] = 0.001 * rtb_Sum_h[3];

  /* MATLAB Function: '<S27>/MATLAB Function' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/r1'
   *  Constant: '<S27>/vx'
   *  Constant: '<S27>/vy'
   *  SignalConversion generated from: '<S61>/ SFunction '
   */
  v[0] = 0.0;
  v[1] = 100.0;
  v[2] = 1000.0;
  v[3] = rtb_TmpSignalConversionAtSFunct[3];
  v[4] = rtb_TmpSignalConversionAtSFunct[4];
  v[5] = rtb_TmpSignalConversionAtSFunct[5];
  v[6] = rtb_TmpSignalConversionAtSFunct[6];
  memset(&varargin_1[0], 0, 49U * sizeof(real_T));
  for (iU = 0; iU < 7; iU++) {
    varargin_1[iU + 7 * iU] = v[iU];
  }

  rtb_Sum_h[0] = 0.001;
  rtb_Sum_h[1] = 0.001;
  rtb_Sum_h[2] = 0.001;
  rtb_Sum_h[3] = 0.001;
  memset(&varargin_2[0], 0, sizeof(real_T) << 4U);
  varargin_2[0] = rtb_Sum_h[0];
  varargin_2[5] = rtb_Sum_h[1];
  varargin_2[10] = rtb_Sum_h[2];
  varargin_2[15] = rtb_Sum_h[3];
  memset(&rtb_y[0], 0, 121U * sizeof(real_T));
  for (iU = 0; iU < 7; iU++) {
    for (i = 0; i < 7; i++) {
      rtb_y[i + 11 * iU] = varargin_1[7 * iU + i];
    }
  }

  for (iU = 0; iU < 4; iU++) {
    int32_T rtb_y_tmp;
    i = iU << 2;
    rtb_y_tmp = (iU + 7) * 11;
    rtb_y[rtb_y_tmp + 7] = varargin_2[i];
    rtb_y[rtb_y_tmp + 8] = varargin_2[i + 1];
    rtb_y[rtb_y_tmp + 9] = varargin_2[i + 2];
    rtb_y[rtb_y_tmp + 10] = varargin_2[i + 3];
  }

  for (iU = 0; iU < 121; iU++) {
    rtb_y[iU] *= 50.0;
  }

  /* Saturate: '<S57>/Saturation' */
  if (rtb_front_wheel_angle_single__m > 2083.9231268812296) {
    rtb_tire_lbu[0] = 2083.9231268812296;
  } else if (rtb_front_wheel_angle_single__m < 10.471975511965978) {
    rtb_tire_lbu[0] = 10.471975511965978;
  } else {
    rtb_tire_lbu[0] = rtb_front_wheel_angle_single__m;
  }

  if (rtb_vy > 2083.9231268812296) {
    rtb_tire_lbu[1] = 2083.9231268812296;
  } else if (rtb_vy < 10.471975511965978) {
    rtb_tire_lbu[1] = 10.471975511965978;
  } else {
    rtb_tire_lbu[1] = rtb_vy;
  }

  if (rtb_vx_a > 2083.9231268812296) {
    rtb_tire_lbu[2] = 2083.9231268812296;
  } else if (rtb_vx_a < 10.471975511965978) {
    rtb_tire_lbu[2] = 10.471975511965978;
  } else {
    rtb_tire_lbu[2] = rtb_vx_a;
  }

  if (rtb_Abs > 2083.9231268812296) {
    rtb_tire_lbu[3] = 2083.9231268812296;
  } else if (rtb_Abs < 10.471975511965978) {
    rtb_tire_lbu[3] = 10.471975511965978;
  } else {
    rtb_tire_lbu[3] = rtb_Abs;
  }

  /* End of Saturate: '<S57>/Saturation' */

  /* Lookup_n-D: '<S59>/2-D Lookup Table' */
  rtb_tire_lbu[0] = look2_binlx(rtb_tire_lbu[0], z, rtConstP.pooled39,
    rtConstP.pooled40, rtConstP.pooled38, rtConstP.pooled45, 200U);
  rtb_tire_lbu[1] = look2_binlx(rtb_tire_lbu[1], rtb_MovingAverage_0,
    rtConstP.pooled39, rtConstP.pooled40, rtConstP.pooled38, rtConstP.pooled45,
    200U);
  rtb_tire_lbu[2] = look2_binlx(rtb_tire_lbu[2], rtb_tire_lbu_tmp,
    rtConstP.pooled39, rtConstP.pooled40, rtConstP.pooled38, rtConstP.pooled45,
    200U);
  rtb_tire_lbu[3] = look2_binlx(rtb_tire_lbu[3], rtb_tire_lbu_tmp_0,
    rtConstP.pooled39, rtConstP.pooled40, rtConstP.pooled38, rtConstP.pooled45,
    200U);

  /* Saturate: '<S59>/Saturation' */
  u0 = rtb_tire_lbu[0];
  if (u0 > 1.0) {
    rtb_tire_lbu[0] = 1.0;
  } else if (u0 < 0.3) {
    rtb_tire_lbu[0] = 0.3;
  } else {
    rtb_tire_lbu[0] = u0;
  }

  u0 = rtb_tire_lbu[1];
  if (u0 > 1.0) {
    rtb_tire_lbu[1] = 1.0;
  } else if (u0 < 0.3) {
    rtb_tire_lbu[1] = 0.3;
  } else {
    rtb_tire_lbu[1] = u0;
  }

  u0 = rtb_tire_lbu[2];
  if (u0 > 1.0) {
    rtb_tire_lbu[2] = 1.0;
  } else if (u0 < 0.3) {
    rtb_tire_lbu[2] = 0.3;
  } else {
    rtb_tire_lbu[2] = u0;
  }

  u0 = rtb_tire_lbu[3];
  if (u0 > 1.0) {
    rtb_tire_lbu[3] = 1.0;
  } else if (u0 < 0.3) {
    rtb_tire_lbu[3] = 0.3;
  } else {
    rtb_tire_lbu[3] = u0;
  }

  /* End of Saturate: '<S59>/Saturation' */

  /* Switch: '<S57>/Switch3' incorporates:
   *  Gain: '<S57>/     '
   *  Gain: '<S57>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    rtb_Memory_idx_1 = 0.96 * rtb_tire_lbu[0];
  } else {
    rtb_Memory_idx_1 = 1.0416666666666667 * rtb_tire_lbu[0];
  }

  /* Product: '<S57>/Divide' incorporates:
   *  Constant: '<S57>/Constant'
   *  Sum: '<S57>/Sum'
   */
  rtb_Memory_idx_0 = (rtb_Switch_h + 1.0) / rtb_Memory_idx_1;

  /* Switch: '<S57>/Switch3' incorporates:
   *  Gain: '<S57>/     '
   *  Gain: '<S57>/      '
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_FR > 0.0) {
    rtb_Memory_idx_1 = 0.96 * rtb_tire_lbu[1];
  } else {
    rtb_Memory_idx_1 = 1.0416666666666667 * rtb_tire_lbu[1];
  }

  if (rtU.omega_wheels_RL > 0.0) {
    rtb_Memory_idx_2 = 0.96 * rtb_tire_lbu[2];
  } else {
    rtb_Memory_idx_2 = 1.0416666666666667 * rtb_tire_lbu[2];
  }

  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Memory_idx_3 = 0.96 * rtb_tire_lbu[3];
  } else {
    rtb_Memory_idx_3 = 1.0416666666666667 * rtb_tire_lbu[3];
  }

  /* CCaller: '<S16>/C Caller' incorporates:
   *  CFunction: '<S28>/C Function'
   *  CFunction: '<S31>/C Function'
   *  CFunction: '<S32>/C Function'
   *  Constant: '<S21>/Constant'
   *  MinMax: '<S24>/Max'
   *  UnaryMinus: '<S21>/Unary Minus'
   */
  memcpy(&rtb_CCaller_o3[0], &rtDW.CFunction[0], 26U * sizeof(real_T));
  rtb_Sum_h[0] = -1000.0;
  rtb_Sum_h[1] = -1000.0;
  rtb_Sum_h[2] = -1000.0;
  rtb_Sum_h[3] = -1000.0;
  rtb_tire_lbu[0] = 1000.0;
  rtb_tire_lbu[1] = 1000.0;
  rtb_tire_lbu[2] = 1000.0;
  rtb_tire_lbu[3] = 1000.0;
  rtb_TmpSignalConversionAt2DLook[0] = rtDW.CFunction_c[0];
  rtb_TmpSignalConversionAt2DLook[1] = rtDW.CFunction_c[1];
  rtb_TmpSignalConversionAt2DLook[2] = rtDW.CFunction_c[2];
  rtb_TmpSignalConversionAt2DLook[3] = rtDW.CFunction_c[3];
  rtb_CCaller_o8[0] = rtDW.CFunction_ch[0];
  rtb_CCaller_o8[1] = rtDW.CFunction_ch[1];
  rtb_CCaller_o8[2] = rtDW.CFunction_ch[2];
  rtb_CCaller_o8[3] = rtDW.CFunction_ch[3];
  rtb_CCaller_o10[0] = fmax(rtb_YRD, rtb_yaw_rate);

  /* Saturate: '<S24>/Saturation1' */
  if (modValueRev > 210.0) {
    /* CCaller: '<S16>/C Caller' */
    rtb_CCaller_o10[1] = 210.0;
  } else if (modValueRev < 0.0) {
    /* CCaller: '<S16>/C Caller' */
    rtb_CCaller_o10[1] = 0.0;
  } else {
    /* CCaller: '<S16>/C Caller' */
    rtb_CCaller_o10[1] = modValueRev;
  }

  /* End of Saturate: '<S24>/Saturation1' */

  /* CCaller: '<S16>/C Caller' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S24>/Constant4'
   *  Constant: '<S57>/Constant'
   *  MATLAB Function: '<S25>/MATLAB Function'
   *  Product: '<S57>/Divide'
   *  SignalConversion generated from: '<S16>/C Caller'
   *  Sum: '<S57>/Sum'
   */
  rtb_CCaller_o10[2] = 2.0;
  rtb_CCaller_o10[3] = 2.0;
  rtb_CCaller_o10[4] = rtb_Product_l;
  for (iU = 0; iU < 7; iU++) {
    rtb_CCaller_o12[5 * iU] = b[iU];
  }

  rtb_CCaller_o12[1] = 0.0;
  rtb_CCaller_o12[6] = 0.0;
  rtb_CCaller_o12[11] = 0.0;
  rtb_CCaller_o12[16] = rtb_Memory_idx_0;
  rtb_CCaller_o12[21] = (rtb_Switch_b + 1.0) / rtb_Memory_idx_1;
  rtb_CCaller_o12[26] = (rtb_RL_j + 1.0) / rtb_Memory_idx_2;
  rtb_CCaller_o12[31] = (rtb_RR + 1.0) / rtb_Memory_idx_3;
  for (iU = 0; iU < 7; iU++) {
    rtb_CCaller_o12[5 * iU + 2] = c[iU];
  }

  for (iU = 0; iU < 7; iU++) {
    rtb_CCaller_o12[5 * iU + 3] = d[iU];
  }

  rtb_CCaller_o12[4] = 0.0;
  rtb_CCaller_o12[9] = 0.0;
  rtb_CCaller_o12[14] = 0.0;
  rtb_CCaller_o12[19] = -0.635 * cos(rtb_Abs_m);
  rtb_CCaller_o12[24] = 0.635 * cos(rtb_Abs_e);
  rtb_CCaller_o12[29] = -0.635;
  rtb_CCaller_o12[34] = 0.635;
  rtb_Switch_h = 1.0;
  Acados_Caller_wrapper(&rtb_CCaller_o2[0], &rtb_CCaller_o3[0], &rtb_Sum_h[0],
                        &rtb_tire_lbu[0], &rtb_VectorConcatenate[0],
                        &rtb_TmpSignalConversionAt2DLook[0], &rtb_CCaller_o8[0],
                        &rtb_lg[0], &rtb_CCaller_o10[0], &rtb_y[0],
                        &rtb_CCaller_o12[0], &rtb_Switch_h);

  /* DiscreteFir: '<S48>/Discrete FIR Filter' */
  rtb_vx_a = 0.0;
  for (iU = rtDW.DiscreteFIRFilter_circBuf_j; iU < 4; iU++) {
    rtb_vx_a += rtDW.DiscreteFIRFilter_states[iU];
  }

  for (iU = 0; iU < rtDW.DiscreteFIRFilter_circBuf_j; iU++) {
    rtb_vx_a += rtDW.DiscreteFIRFilter_states[iU];
  }

  /* End of DiscreteFir: '<S48>/Discrete FIR Filter' */

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S48>/Constant'
   *  Constant: '<S48>/Constant1'
   *  Logic: '<S48>/OR'
   *  RelationalOperator: '<S48>/Less Than'
   *  RelationalOperator: '<S48>/Less Than1'
   */
  if ((rtb_vx < 3.0) || (rtb_vx_a >= 4.0)) {
    /* Product: '<S48>/Product' incorporates:
     *  Constant: '<S48>/Constant2'
     *  Inport: '<Root>/throttle'
     */
    rtb_Memory_idx_0 = rtU.throttle * 6.3;
    rtb_Memory_idx_1 = rtb_Memory_idx_0;

    /* Product: '<S48>/Product' incorporates:
     *  Constant: '<S48>/Constant2'
     *  Inport: '<Root>/throttle'
     */
    rtb_Memory_idx_2 = rtU.throttle * 21.0;
    rtb_Memory_idx_3 = rtb_Memory_idx_2;
  } else {
    rtb_Memory_idx_0 = rtb_CCaller_o2[3];
    rtb_Memory_idx_1 = rtb_CCaller_o2[4];
    rtb_Memory_idx_2 = rtb_CCaller_o2[5];
    rtb_Memory_idx_3 = rtb_CCaller_o2[6];
  }

  /* End of Switch: '<S23>/Switch' */

  /* RelationalOperator: '<S75>/Less Than' incorporates:
   *  DataStoreRead: '<S75>/Data Store General_Params'
   *  Inport: '<Root>/brake'
   */
  rtb_LessThan3_n = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S75>/T_Req_Chart' */
  guard1 = false;
  guard2 = false;
  if (rtDW.is_active_c19_TVModel == 0U) {
    rtDW.is_active_c19_TVModel = 1U;
    rtDW.is_c19_TVModel = IN_Throttle;
    rtb_vx = 0.0;
    guard1 = true;
  } else if (rtDW.is_c19_TVModel == 1) {
    if ((!rtb_LessThan3_n) && (rtU.throttle < 0.05)) {
      rtDW.is_c19_TVModel = IN_Throttle;
      rtb_vx = 0.0;
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    /* case IN_Throttle: */
    rtb_vx = 0.0;
    if (rtb_LessThan3_n) {
      rtDW.is_c19_TVModel = IN_Brake;
      guard2 = true;
    } else {
      guard1 = true;
    }
  }

  if (guard2) {
    /* SignalConversion generated from: '<S88>/1-D Lookup Table' incorporates:
     *  Constant: '<S88>/Constant'
     *  DataStoreRead: '<S88>/Data Store Read'
     *  Switch: '<S75>/Switch'
     */
    tmp[0] = rtDW.General_Params.BrakeThresh;
    tmp[1] = 1.0;

    /* Lookup_n-D: '<S88>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/brake'
     *  Switch: '<S75>/Switch'
     */
    modValueRev = look1_binlx(rtU.brake, tmp, rtConstP.uDLookupTable_tableData,
      1U);

    /* Saturate: '<S88>/Saturation_Brake' incorporates:
     *  Switch: '<S75>/Switch'
     */
    if (modValueRev > 1.0) {
      modValueRev = 1.0;
    } else if (modValueRev < 0.0) {
      modValueRev = 0.0;
    }

    /* End of Saturate: '<S88>/Saturation_Brake' */

    /* Switch: '<S75>/Switch' incorporates:
     *  Gain: '<S88>/Gain_Max_Torque_Needed'
     */
    rtb_vx = -529.2 * modValueRev;
  }

  if (guard1) {
    /* Switch: '<S87>/Switch' incorporates:
     *  DataStoreRead: '<S87>/Data Store General_Params1'
     *  Inport: '<Root>/throttle'
     *  RelationalOperator: '<S87>/Less Than'
     *  Switch: '<S75>/Switch'
     */
    if (rtU.throttle > rtDW.General_Params.ThrottleThresh) {
      /* SignalConversion generated from: '<S87>/T_nominal_wheel_LUT' incorporates:
       *  Constant: '<S87>/Constant1'
       *  Constant: '<S87>/Constant2'
       *  DataStoreRead: '<S87>/Data Store General_Params'
       */
      tmp_0[0] = 0.0;
      tmp_0[1] = rtDW.General_Params.ThrottleThresh;
      tmp_0[2] = 1.0;

      /* MultiPortSwitch: '<S87>/Map_Selector' incorporates:
       *  Lookup_n-D: '<S87>/T_peak_wheel_LUT'
       */
      rtb_vx = look1_binlx(rtU.throttle, tmp_0,
                           rtConstP.T_peak_wheel_LUT_tableData, 2U);
    }

    /* End of Switch: '<S87>/Switch' */
  }

  /* End of Chart: '<S75>/T_Req_Chart' */

  /* MATLABSystem: '<S75>/Moving Average' */
  if (rtDW.obj_n.TunablePropsChanged) {
    rtDW.obj_n.TunablePropsChanged = false;
  }

  obj_0 = rtDW.obj_n.pStatistic;
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

  rtb_Product_l = obj_0->pCumRevIndex;
  rtb_front_wheel_angle_single__m = obj_0->pCumSum;
  rtb_Abs_m = obj_0->pCumSumRev[0];
  rtb_Abs_e = obj_0->pCumSumRev[1];
  rtb_Switch_b = obj_0->pCumSumRev[2];
  rtb_RR = obj_0->pCumSumRev[3];
  rtb_Sum_h[0] = rtb_Abs_m;
  rtb_Sum_h[1] = rtb_Abs_e;
  rtb_Sum_h[2] = rtb_Switch_b;
  rtb_Sum_h[3] = rtb_RR;
  modValueRev = obj_0->pModValueRev;
  rtb_front_wheel_angle_single__m += rtb_vx;
  rtb_Sum_h[(int32_T)rtb_Product_l - 1] = rtb_vx;
  if (rtb_Product_l != 4.0) {
    rtb_Product_l++;
  } else {
    rtb_Product_l = 1.0;
    rtb_front_wheel_angle_single__m = 0.0;
    rtb_Sum_h[2] += rtb_Sum_h[3];
    rtb_Sum_h[1] += rtb_Sum_h[2];
    rtb_Sum_h[0] += rtb_Sum_h[1];
  }

  obj_0->pCumSum = rtb_front_wheel_angle_single__m;
  rtb_vx = rtb_Sum_h[0];
  rtb_Abs_m = rtb_Sum_h[1];
  rtb_Abs_e = rtb_Sum_h[2];
  rtb_Switch_b = rtb_Sum_h[3];
  obj_0->pCumSumRev[0] = rtb_vx;
  obj_0->pCumSumRev[1] = rtb_Abs_m;
  obj_0->pCumSumRev[2] = rtb_Abs_e;
  obj_0->pCumSumRev[3] = rtb_Switch_b;
  obj_0->pCumRevIndex = rtb_Product_l;
  if (modValueRev > 0.0) {
    obj_0->pModValueRev = modValueRev - 1.0;
  } else {
    obj_0->pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S75>/Moving Average' */

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[0] = rtDW.UnitDelay_DSTATE_j[0];

  /* Update for Memory: '<S16>/Memory' */
  rtDW.Memory_PreviousInput[0] = rtb_Memory_idx_0;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[1] = rtDW.UnitDelay_DSTATE_j[1];

  /* Update for Memory: '<S16>/Memory' */
  rtDW.Memory_PreviousInput[1] = rtb_Memory_idx_1;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[2] = rtDW.UnitDelay_DSTATE_j[2];

  /* Update for Memory: '<S16>/Memory' */
  rtDW.Memory_PreviousInput[2] = rtb_Memory_idx_2;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[3] = rtDW.UnitDelay_DSTATE_j[3];

  /* Update for Memory: '<S16>/Memory' */
  rtDW.Memory_PreviousInput[3] = rtb_Memory_idx_3;

  /* Update for DiscreteFir: '<S43>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 8;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states_e[rtDW.DiscreteFIRFilter_circBuf] = LessThan;

  /* End of Update for DiscreteFir: '<S43>/Discrete FIR Filter' */

  /* Update for UnitDelay: '<S53>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtb_Logic_idx_0;

  /* Update for Delay: '<S52>/Delay' */
  rtDW.Delay_DSTATE[0] = rtDW.Delay_DSTATE[1];
  rtDW.Delay_DSTATE[1] = rtDW.Delay_DSTATE[2];
  rtDW.Delay_DSTATE[2] = rtDW.Delay_DSTATE[3];
  rtDW.Delay_DSTATE[3] = rtDW.Delay_DSTATE[4];
  rtDW.Delay_DSTATE[4] = rtb_Logic_idx_0;

  /* Update for Memory: '<S56>/Memory' */
  rtDW.Memory_PreviousInput_i = rtb_Logic_idx_0;

  /* Update for DiscreteFir: '<S48>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf_j--;
  if (rtDW.DiscreteFIRFilter_circBuf_j < 0) {
    rtDW.DiscreteFIRFilter_circBuf_j = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf_j] = 0.0;

  /* End of Update for DiscreteFir: '<S48>/Discrete FIR Filter' */

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
  rtY.Torque[0] = rtb_Memory_idx_0;
  rtY.Torque[1] = rtb_Memory_idx_1;
  rtY.Torque[2] = rtb_Memory_idx_2;
  rtY.Torque[3] = rtb_Memory_idx_3;
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
    /* Start for InitialCondition: '<S24>/IC' */
    rtDW.IC_FirstOutputTime = true;

    /* Start for InitialCondition: '<S24>/IC1' */
    rtDW.IC1_FirstOutputTime = true;

    /* Start for DataStoreMemory: '<S3>/Data Store_General_Params' */
    rtDW.General_Params = rtConstP.DataStore_General_Params_Initia;

    /* Start for MATLABSystem: '<S52>/Moving Average' */
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

    /* InitializeConditions for MATLABSystem: '<S52>/Moving Average' */
    iobj_0 = rtDW.obj.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum = 0.0;
      for (i = 0; i < 24; i++) {
        iobj_0->pCumSumRev[i] = 0.0;
      }

      iobj_0->pCumRevIndex = 1.0;
      iobj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S52>/Moving Average' */

    /* Start for MATLABSystem: '<S75>/Moving Average' */
    rtDW.obj_n.matlabCodegenIsDeleted = true;
    rtDW.obj_n.isInitialized = 0;
    rtDW.obj_n.NumChannels = -1;
    rtDW.obj_n.matlabCodegenIsDeleted = false;
    rtDW.obj_n.isSetupComplete = false;
    rtDW.obj_n.isInitialized = 1;
    rtDW.obj_n.NumChannels = 1;
    iobj_0_0 = &rtDW.obj_n._pobj0;
    iobj_0_0->isInitialized = 0;
    iobj_0_0->isInitialized = 0;
    rtDW.obj_n.pStatistic = iobj_0_0;
    rtDW.obj_n.isSetupComplete = true;
    rtDW.obj_n.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S75>/Moving Average' */
    iobj_0_0 = rtDW.obj_n.pStatistic;
    if (iobj_0_0->isInitialized == 1) {
      iobj_0_0->pCumSum = 0.0;
      iobj_0_0->pCumSumRev[0] = 0.0;
      iobj_0_0->pCumSumRev[1] = 0.0;
      iobj_0_0->pCumSumRev[2] = 0.0;
      iobj_0_0->pCumSumRev[3] = 0.0;
      iobj_0_0->pCumRevIndex = 1.0;
      iobj_0_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S75>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
