/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Apr 27 15:54:04 2022
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
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
static real_T look2_binlx(real_T u0, real_T u1, const real_T bp0[], const real_T
  bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
static real_T intrp2d_l(const uint32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride);
static uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static uint32_T plook_binc(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction);
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

/*
 * Output and update for action system:
 *    '<S17>/YRD_LUT_1'
 *    '<S17>/YRD_LUT_3'
 */
static void YRD_LUT_1(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_LUT_1;
  real_T rtu_vx_0;

  /* Abs: '<S65>/Abs' */
  rtb_LUT_1 = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S65>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtu_vx_0 = 3.0;
  } else {
    rtu_vx_0 = rtu_vx;
  }

  /* End of Saturate: '<S65>/Saturation' */

  /* Product: '<S65>/Divide2' incorporates:
   *  Lookup_n-D: '<S65>/LUT_1'
   *  Product: '<S65>/Divide1'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_LUT_1 * look2_binlx(rtb_LUT_1, rtu_vx_0,
    rtConstP.pooled14, rtConstP.pooled15, rtConstP.pooled9, rtConstP.pooled48,
    100U);
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
  real_T rtb_vx_e4;

  /* Abs: '<S64>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S64>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_e4 = 3.0;
  } else {
    rtb_vx_e4 = rtu_vx;
  }

  /* End of Saturate: '<S64>/Saturation' */

  /* Product: '<S64>/Divide2' incorporates:
   *  Abs: '<S64>/Abs'
   *  Lookup_n-D: '<S64>/LUT_0'
   *  Product: '<S64>/Divide'
   *  Product: '<S64>/Divide1'
   *  Saturate: '<S64>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_e4, rtConstP.pooled14,
                 rtConstP.pooled15, rtConstP.pooled10, rtConstP.pooled48, 100U) /
     rtb_vx_e4);
}

/*
 * Output and update for action system:
 *    '<S17>/YRD_LUT_-1.5'
 *    '<S17>/YRD_LUT_-1.1'
 */
static void YRD_LUT_15(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
  *rty_yrd)
{
  real_T rtb_LUT_15;
  real_T rtu_vx_0;

  /* Abs: '<S62>/Abs' */
  rtb_LUT_15 = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S62>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtu_vx_0 = 3.0;
  } else {
    rtu_vx_0 = rtu_vx;
  }

  /* End of Saturate: '<S62>/Saturation' */

  /* Product: '<S62>/Divide2' incorporates:
   *  Lookup_n-D: '<S62>/LUT_-1.5'
   *  Product: '<S62>/Divide1'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_LUT_15 * look2_binlx(rtb_LUT_15,
    rtu_vx_0, rtConstP.pooled14, rtConstP.pooled15, rtConstP.pooled11,
    rtConstP.pooled48, 100U);
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
  real_T rtb_vx_d;

  /* Abs: '<S63>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S63>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_d = 3.0;
  } else {
    rtb_vx_d = rtu_vx;
  }

  /* End of Saturate: '<S63>/Saturation' */

  /* Product: '<S63>/Divide2' incorporates:
   *  Abs: '<S63>/Abs'
   *  Lookup_n-D: '<S63>/LUT_-3'
   *  Product: '<S63>/Divide'
   *  Product: '<S63>/Divide1'
   *  Saturate: '<S63>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_d, rtConstP.pooled14,
                 rtConstP.pooled15, rtConstP.pooled13, rtConstP.pooled48, 100U) /
     rtb_vx_d);
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

/* Model step function for TID0 */
void TVModel_step0(void)               /* Sample time: [0.01s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void TV(void)                          /* Explicit Task: Subsystem */
{
  real_T rtb_y[49];
  real_T varargin_2[16];
  real_T rtb_TmpSignalConversionAtCFunct[13];
  real_T varargin_1[9];
  real_T rtb_TmpSignalConversionAtSFun_o[7];
  real_T rtb_CCaller_o2[4];
  real_T rtb_Efficiency[4];
  real_T rtb_Saturation_e[4];
  real_T rtb_TmpSignalConversionAtCCalle[3];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T minV_idx_0;
  real_T minV_idx_1;
  real_T rtb_Abs_o_idx_0;
  real_T rtb_CCaller_o2_tmp;
  real_T rtb_Gain_a_idx_0;
  real_T rtb_Gain_a_idx_1;
  real_T rtb_Gain_a_idx_2;
  real_T rtb_Gain_a_idx_3;
  real_T rtb_Integrator_idx_0;
  real_T rtb_Integrator_idx_1;
  real_T rtb_Integrator_idx_2;
  real_T rtb_Integrator_idx_3;
  real_T rtb_Memory_idx_0;
  real_T rtb_Memory_idx_1;
  real_T rtb_Memory_idx_2;
  real_T rtb_Memory_idx_3;
  real_T rtb_RL_m;
  real_T rtb_RR;
  real_T rtb_Sign;
  real_T rtb_Sum;
  real_T rtb_Sum1;
  real_T rtb_Sum1_tmp;
  real_T rtb_Sum_ks;
  real_T rtb_Switch_c;
  real_T rtb_YRD;
  real_T rtb_max_torque_available_idx_1;
  real_T rtb_max_torque_available_idx_2;
  real_T rtb_max_torque_available_idx_3;
  real_T rtb_max_torque_temperature_IGBT;
  real_T rtb_max_torque_temperature_IG_0;
  real_T rtb_max_torque_temperature_in_0;
  real_T rtb_torquemapselected;
  real_T rtb_torquemapselected_tmp;
  real_T rtb_uDLookupTable_idx_0;
  real_T rtb_uDLookupTable_idx_1;
  real_T rtb_uDLookupTable_idx_2;
  real_T rtb_uDLookupTable_idx_3;
  real_T rtb_ubu_idx_0;
  real_T rtb_ubu_idx_1;
  real_T rtb_ubu_idx_2;
  real_T rtb_vx;
  real_T u0;
  int32_T i;
  int32_T iU;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  int16_T LessThan;
  boolean_T rtb_AND_n;
  boolean_T rtb_Compare;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (rtU.vx <= 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = rtU.vx;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_max_torque_temperature_IGBT = 0.017453292519943295 * rtU.steering;

  /* Gain: '<S5>/Gain1' incorporates:
   *  Inport: '<Root>/yaw_rate'
   */
  rtb_torquemapselected = 0.017453292519943295 * rtU.yaw_rate_deg;

  /* Signum: '<S10>/Sign' */
  if (rtb_max_torque_temperature_IGBT < 0.0) {
    rtb_Sign = -1.0;
  } else if (rtb_max_torque_temperature_IGBT > 0.0) {
    rtb_Sign = 1.0;
  } else if (rtb_max_torque_temperature_IGBT == 0.0) {
    rtb_Sign = 0.0;
  } else {
    rtb_Sign = (rtNaN);
  }

  /* End of Signum: '<S10>/Sign' */

  /* Lookup_n-D: '<S10>/steering_to_wheel_angles_LUT' incorporates:
   *  Abs: '<S10>/Abs'
   *  Product: '<S10>/Divide1'
   *  SignalConversion generated from: '<S10>/steering_to_wheel_angles_LUT'
   */
  rtb_Abs_o_idx_0 = fabs(look1_binlx(rtb_max_torque_temperature_IGBT,
    rtConstP.pooled18, rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) *
    rtb_Sign;

  /* Product: '<S10>/Divide1' incorporates:
   *  Abs: '<S10>/Abs'
   *  Lookup_n-D: '<S10>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S10>/Unary Minus'
   */
  rtb_max_torque_available_idx_1 = fabs(look1_binlx
    (-rtb_max_torque_temperature_IGBT, rtConstP.pooled18,
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
    rtb_Sign = rtb_vx * cos(rtb_Abs_o_idx_0) + sin(rtb_Abs_o_idx_0) * rtU.vy;
    rtb_Sign = (0.235 * rtU.omega_wheels_FL - rtb_Sign) / rtb_Sign;

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
    rtb_Sum_ks = rtb_vx * cos(rtb_max_torque_available_idx_1) + sin
      (rtb_max_torque_available_idx_1) * rtU.vy;
    rtb_Switch_c = (0.235 * rtU.omega_wheels_FR - rtb_Sum_ks) / rtb_Sum_ks;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_vx) / rtb_vx;
    rtb_RL_m = (0.235 * rtU.omega_wheels_RL - rtb_vx) / rtb_vx;
  } else {
    rtb_Sign = 0.0;
    rtb_Switch_c = 0.0;
    rtb_RR = 0.0;
    rtb_RL_m = 0.0;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Lookup_n-D: '<S10>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Lookup_n-D: '<S68>/Max_Torque_Temperature_IGBT_LUT'
   */
  rtb_Sum_ks = look1_binlx(rtb_max_torque_temperature_IGBT, rtConstP.pooled18,
    rtConstP.steering_to_wheel_angle_single_, 32U);

  /* Outputs for IfAction SubSystem: '<S17>/YRD_LUT_0' incorporates:
   *  ActionPort: '<S64>/Action Port'
   */
  /* If: '<S17>/If' */
  YRD_LUT_0(rtb_Sum_ks, rtb_vx, &rtDW.yaw_rate_desired_LUT);

  /* End of Outputs for SubSystem: '<S17>/YRD_LUT_0' */

  /* Outputs for IfAction SubSystem: '<S17>/YRD_LUT_2' incorporates:
   *  ActionPort: '<S66>/Action Port'
   */
  /* If: '<S17>/If1' */
  YRD_LUT_0(rtb_Sum_ks, rtb_vx, &rtDW.yaw_rate_desired_LUT_g);

  /* End of Outputs for SubSystem: '<S17>/YRD_LUT_2' */

  /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_YRD = (1.0 - rtU.brake) * rtDW.yaw_rate_desired_LUT_g +
    rtDW.yaw_rate_desired_LUT * rtU.brake;

  /* SignalConversion generated from: '<S27>/C Function' incorporates:
   *  Constant: '<S18>/T_FL_ref'
   *  Constant: '<S18>/T_FR_ref'
   *  Constant: '<S18>/T_RL_ref'
   *  Constant: '<S18>/T_RR_ref'
   *  MATLAB Function: '<S18>/MATLAB Function'
   *  MATLAB Function: '<S18>/MATLAB Function1'
   */
  rtb_TmpSignalConversionAtSFun_o[0] = 0.0;
  rtb_TmpSignalConversionAtSFun_o[1] = 0.0;
  rtb_TmpSignalConversionAtSFun_o[2] = rtb_YRD;
  rtb_TmpSignalConversionAtSFun_o[3] = 0.0;
  rtb_TmpSignalConversionAtSFun_o[4] = 0.0;
  rtb_TmpSignalConversionAtSFun_o[5] = 0.0;
  rtb_TmpSignalConversionAtSFun_o[6] = 0.0;

  /* CFunction: '<S27>/C Function' incorporates:
   *  Constant: '<S27>/Constant3'
   */
  for (i = 0; i < 2; i++) {
    for (iU = 0; iU < 7; iU++) {
      rtDW.CFunction[i * 7 + iU] = rtb_TmpSignalConversionAtSFun_o[iU];
    }
  }

  /* End of CFunction: '<S27>/C Function' */

  /* SignalConversion generated from: '<S30>/C Function' incorporates:
   *  Constant: '<S19>/Inertia Scaling'
   *  Constant: '<S19>/LMU'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_TmpSignalConversionAtCFunct[0] = rtb_Sum_ks;
  rtb_TmpSignalConversionAtCFunct[1] = rtb_Sign;
  rtb_TmpSignalConversionAtCFunct[2] = rtb_Switch_c;
  rtb_TmpSignalConversionAtCFunct[3] = rtb_RL_m;
  rtb_TmpSignalConversionAtCFunct[4] = rtb_RR;
  rtb_TmpSignalConversionAtCFunct[5] = rtDW.UnitDelay_DSTATE[0];
  rtb_TmpSignalConversionAtCFunct[6] = rtDW.UnitDelay_DSTATE[1];
  rtb_TmpSignalConversionAtCFunct[7] = rtDW.UnitDelay_DSTATE[2];
  rtb_TmpSignalConversionAtCFunct[8] = rtDW.UnitDelay_DSTATE[3];
  rtb_TmpSignalConversionAtCFunct[9] = rtU.ay;
  rtb_TmpSignalConversionAtCFunct[10] = rtU.ax;
  rtb_TmpSignalConversionAtCFunct[11] = 0.75;
  rtb_TmpSignalConversionAtCFunct[12] = 1.0;

  /* CFunction: '<S30>/C Function' incorporates:
   *  Constant: '<S30>/Constant3'
   */
  for (i = 0; i < 3; i++) {
    memcpy(&rtDW.CFunction_c[i * 13], &rtb_TmpSignalConversionAtCFunct[0], 13U *
           sizeof(real_T));
  }

  /* End of CFunction: '<S30>/C Function' */

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/Constant3'
   *  Sum: '<S31>/Subtract'
   */
  if (rtb_vx - 2.0 > 0.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_TmpSignalConversionAtCCalle[0] = rtb_vx;
  } else {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_TmpSignalConversionAtCCalle[0] = 2.0;
  }

  /* End of Switch: '<S31>/Switch1' */

  /* SignalConversion generated from: '<S16>/C Caller' incorporates:
   *  Inport: '<Root>/vy'
   */
  rtb_TmpSignalConversionAtCCalle[1] = rtU.vy;
  rtb_TmpSignalConversionAtCCalle[2] = rtb_torquemapselected;

  /* Sum: '<S42>/Subtract' incorporates:
   *  Sum: '<S41>/Subtract'
   *  Switch: '<S41>/Switch1'
   */
  rtb_Sum1_tmp = rtb_torquemapselected - rtb_YRD;

  /* Sum: '<S42>/Sum1' incorporates:
   *  Abs: '<S42>/Abs'
   *  Constant: '<S42>/Constant7'
   *  Sum: '<S42>/Subtract'
   */
  rtb_Sum1 = fabs(rtb_Sum1_tmp) + 5.0;

  /* Math: '<S43>/Square1' incorporates:
   *  Math: '<S43>/Square2'
   *  Math: '<S45>/Square1'
   */
  rtb_uDLookupTable_idx_2 = rtb_vx * rtb_vx;

  /* Gain: '<S43>/Lateral Load Transfer' incorporates:
   *  Gain: '<S44>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S43>/Unary Minus'
   */
  rtb_uDLookupTable_idx_1 = 15.413385826771654 * -rtU.ay;

  /* Gain: '<S43>/Lift Force' incorporates:
   *  Gain: '<S44>/Lift Force'
   *  Math: '<S43>/Square1'
   */
  rtb_Gain_a_idx_1 = rtb_uDLookupTable_idx_2 * 0.87348504901960788;

  /* Gain: '<S43>/Drag moment' incorporates:
   *  Gain: '<S44>/Drag moment'
   *  Gain: '<S45>/Drag moment'
   *  Gain: '<S46>/Drag moment'
   */
  rtb_uDLookupTable_idx_3 = rtb_uDLookupTable_idx_2 * 0.19692235294117649;

  /* Gain: '<S43>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S44>/Longitudinal Load Transfer'
   *  Gain: '<S45>/Longitudinal Load Transfer'
   *  Gain: '<S46>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S43>/Unary Minus1'
   */
  rtb_Gain_a_idx_0 = 25.588235294117645 * -rtU.ax;

  /* SignalConversion generated from: '<S21>/2-D Lookup Table' incorporates:
   *  Constant: '<S43>/Static Load Front'
   *  Constant: '<S44>/Static Load Front'
   *  Gain: '<S43>/Drag moment'
   *  Gain: '<S43>/Lateral Load Transfer'
   *  Gain: '<S43>/Lift Force'
   *  Gain: '<S43>/Longitudinal Load Transfer'
   *  Sum: '<S43>/Subtract'
   *  Sum: '<S44>/Subtract'
   */
  rtb_uDLookupTable_idx_0 = (((rtb_uDLookupTable_idx_1 + 662.17500000000007) +
    rtb_Gain_a_idx_1) - rtb_uDLookupTable_idx_3) + rtb_Gain_a_idx_0;
  rtb_uDLookupTable_idx_1 = (((662.17500000000007 - rtb_uDLookupTable_idx_1) +
    rtb_Gain_a_idx_1) - rtb_uDLookupTable_idx_3) + rtb_Gain_a_idx_0;

  /* Gain: '<S45>/Lift Force' incorporates:
   *  Gain: '<S46>/Lift Force'
   */
  rtb_Gain_a_idx_1 = rtb_uDLookupTable_idx_2 * 0.70063995098039222;

  /* SignalConversion generated from: '<S21>/2-D Lookup Table' incorporates:
   *  Constant: '<S45>/Static Load Front'
   *  Constant: '<S46>/Static Load Front'
   *  Gain: '<S45>/Lateral Load Transfer'
   *  Gain: '<S45>/Lift Force'
   *  Gain: '<S46>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  Sum: '<S45>/Subtract'
   *  Sum: '<S46>/Subtract'
   *  UnaryMinus: '<S45>/Unary Minus'
   *  UnaryMinus: '<S46>/Unary Minus'
   */
  rtb_uDLookupTable_idx_2 = (((15.413385826771654 * -rtU.ay + 662.17500000000007)
    + rtb_Gain_a_idx_1) + rtb_uDLookupTable_idx_3) - rtb_Gain_a_idx_0;
  rtb_uDLookupTable_idx_3 = (((662.17500000000007 - 15.413385826771654 * -rtU.ay)
    + rtb_Gain_a_idx_1) + rtb_uDLookupTable_idx_3) - rtb_Gain_a_idx_0;

  /* Sum: '<S48>/Subtract1' incorporates:
   *  Gain: '<S48>/Gain'
   *  Inport: '<Root>/vy'
   *  Sum: '<S49>/Subtract1'
   */
  rtb_Gain_a_idx_2 = 0.765 * rtb_torquemapselected + rtU.vy;

  /* Sum: '<S48>/Subtract' incorporates:
   *  Gain: '<S48>/Gain1'
   *  Sum: '<S50>/Subtract'
   */
  rtb_Gain_a_idx_0 = rtb_vx - 0.635 * rtb_torquemapselected;

  /* SignalConversion generated from: '<S21>/2-D Lookup Table' incorporates:
   *  Sum: '<S48>/Subtract'
   *  Sum: '<S48>/Subtract1'
   *  Sum: '<S48>/Subtract2'
   *  Trigonometry: '<S48>/Atan'
   */
  rtb_Abs_o_idx_0 = rt_atan2d_snf(rtb_Gain_a_idx_2, rtb_Gain_a_idx_0) -
    rtb_Abs_o_idx_0;

  /* Sum: '<S49>/Subtract' incorporates:
   *  Gain: '<S49>/Gain1'
   *  Sum: '<S51>/Subtract'
   */
  rtb_Gain_a_idx_1 = 0.635 * rtb_torquemapselected + rtb_vx;

  /* SignalConversion generated from: '<S21>/2-D Lookup Table' incorporates:
   *  Sum: '<S49>/Subtract'
   *  Sum: '<S49>/Subtract2'
   *  Trigonometry: '<S49>/Atan'
   */
  rtb_max_torque_available_idx_1 = rt_atan2d_snf(rtb_Gain_a_idx_2,
    rtb_Gain_a_idx_1) - rtb_max_torque_available_idx_1;

  /* Sum: '<S50>/Subtract1' incorporates:
   *  Gain: '<S50>/Gain'
   *  Inport: '<Root>/vy'
   *  Sum: '<S51>/Subtract1'
   */
  rtb_torquemapselected = rtU.vy - 0.765 * rtb_torquemapselected;

  /* SignalConversion generated from: '<S21>/2-D Lookup Table' incorporates:
   *  Sum: '<S50>/Subtract1'
   *  Trigonometry: '<S50>/Atan'
   *  Trigonometry: '<S51>/Atan'
   */
  rtb_max_torque_available_idx_2 = rt_atan2d_snf(rtb_torquemapselected,
    rtb_Gain_a_idx_0);
  rtb_max_torque_available_idx_3 = rt_atan2d_snf(rtb_torquemapselected,
    rtb_Gain_a_idx_1);

  /* Memory: '<S16>/Memory' */
  rtb_Memory_idx_0 = rtDW.Memory_PreviousInput[0];
  rtb_Memory_idx_1 = rtDW.Memory_PreviousInput[1];
  rtb_Memory_idx_2 = rtDW.Memory_PreviousInput[2];
  rtb_Memory_idx_3 = rtDW.Memory_PreviousInput[3];

  /* Lookup_n-D: '<S68>/Max_Torque_Overload_Motor_LUT' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Lookup_n-D: '<S68>/Max_Torque_Overload_Inverter_LUT'
   *  Lookup_n-D: '<S69>/Display Overload Inverter LUT'
   *  Lookup_n-D: '<S69>/Display Overload Motor LUT'
   */
  rtb_CCaller_o2_tmp = look1_binlx(0.0, rtConstP.pooled33, rtConstP.pooled32, 2U);
  rtb_CCaller_o2[0] = rtb_CCaller_o2_tmp;
  rtb_CCaller_o2[1] = rtb_CCaller_o2_tmp;
  rtb_CCaller_o2[2] = rtb_CCaller_o2_tmp;
  rtb_CCaller_o2[3] = rtb_CCaller_o2_tmp;

  /* Lookup_n-D: '<S68>/Max_Torque_Overload_Inverter_LUT' */
  rtb_Efficiency[0] = rtb_CCaller_o2_tmp;
  rtb_Efficiency[1] = rtb_CCaller_o2_tmp;
  rtb_Efficiency[2] = rtb_CCaller_o2_tmp;
  rtb_Efficiency[3] = rtb_CCaller_o2_tmp;

  /* Lookup_n-D: '<S68>/Max_Torque_Temperature_Internal_LUT' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Lookup_n-D: '<S69>/Temperature Internal LUT'
   */
  rtb_max_torque_temperature_in_0 = look1_binlx(0.0, rtConstP.pooled34,
    rtConstP.pooled32, 2U);

  /* Lookup_n-D: '<S68>/Max_Torque_Temperature_IGBT_LUT' incorporates:
   *  Constant: '<S68>/Constant4'
   *  Lookup_n-D: '<S69>/Temperature IGBT LUT'
   */
  rtb_max_torque_temperature_IG_0 = look1_binlx(0.0, rtConstP.pooled35,
    rtConstP.pooled32, 2U);

  /* Lookup_n-D: '<S68>/Max_Torque_Temperature_External_LUT' incorporates:
   *  Constant: '<S68>/Constant5'
   *  Lookup_n-D: '<S69>/Temperature External LUT'
   */
  rtb_torquemapselected_tmp = look1_binlx(0.0, rtConstP.pooled36,
    rtConstP.pooled32, 2U);

  /* RelationalOperator: '<S76>/Compare' incorporates:
   *  Constant: '<S73>/Time constant'
   *  Constant: '<S76>/Constant'
   *  Sum: '<S73>/Sum1'
   */
  rtb_Compare = (0.079577471545947673 - rtDW.Probe[0] <= 0.0);

  /* Gain: '<S70>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_Saturation_e[0] = 128.91550390443524 * rtU.omega_wheels_FL;
  rtb_Saturation_e[1] = 128.91550390443524 * rtU.omega_wheels_FR;
  rtb_Saturation_e[2] = 128.91550390443524 * rtU.omega_wheels_RL;
  rtb_Saturation_e[3] = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S70>/Saturation1' */
  u0 = rtb_Saturation_e[0];
  if (u0 <= 0.0) {
    rtb_Saturation_e[0] = 0.0;
  } else {
    rtb_Saturation_e[0] = u0;
  }

  u0 = rtb_Saturation_e[1];
  if (u0 <= 0.0) {
    rtb_Saturation_e[1] = 0.0;
  } else {
    rtb_Saturation_e[1] = u0;
  }

  u0 = rtb_Saturation_e[2];
  if (u0 <= 0.0) {
    rtb_Saturation_e[2] = 0.0;
  } else {
    rtb_Saturation_e[2] = u0;
  }

  u0 = rtb_Saturation_e[3];
  if (u0 <= 0.0) {
    rtb_Saturation_e[3] = 0.0;
  } else {
    rtb_Saturation_e[3] = u0;
  }

  /* End of Saturate: '<S70>/Saturation1' */

  /* Lookup_n-D: '<S70>/2-D Lookup Table' incorporates:
   *  Constant: '<S2>/Constant5'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled40, 45U,
    &rtb_torquemapselected);
  fractions[1U] = rtb_torquemapselected;
  rtb_Sum = rtb_Saturation_e[0];
  bpIndices[0U] = plook_binc(rtb_Sum, rtConstP.pooled39, 200U,
    &rtb_torquemapselected);
  fractions[0U] = rtb_torquemapselected;
  rtb_Saturation_e[0] = intrp2d_l(bpIndices, fractions, rtConstP.pooled38, 201U);
  rtb_Sum = rtb_Saturation_e[1];
  bpIndices[0U] = plook_binc(rtb_Sum, rtConstP.pooled39, 200U,
    &rtb_torquemapselected);
  fractions[0U] = rtb_torquemapselected;
  rtb_Saturation_e[1] = intrp2d_l(bpIndices, fractions, rtConstP.pooled38, 201U);
  rtb_Sum = rtb_Saturation_e[2];
  bpIndices[0U] = plook_binc(rtb_Sum, rtConstP.pooled39, 200U,
    &rtb_torquemapselected);
  fractions[0U] = rtb_torquemapselected;
  rtb_Saturation_e[2] = intrp2d_l(bpIndices, fractions, rtConstP.pooled38, 201U);
  rtb_Sum = rtb_Saturation_e[3];
  bpIndices[0U] = plook_binc(rtb_Sum, rtConstP.pooled39, 200U,
    &rtb_torquemapselected);
  fractions[0U] = rtb_torquemapselected;
  rtb_Saturation_e[3] = intrp2d_l(bpIndices, fractions, rtConstP.pooled38, 201U);

  /* Gain: '<S70>/Gain' */
  rtb_Gain_a_idx_0 = 0.0098000000000000014 * rtb_Saturation_e[0];
  rtb_Gain_a_idx_1 = 0.0098000000000000014 * rtb_Saturation_e[1];
  rtb_Gain_a_idx_2 = 0.0098000000000000014 * rtb_Saturation_e[2];
  rtb_Gain_a_idx_3 = 0.0098000000000000014 * rtb_Saturation_e[3];

  /* DiscreteIntegrator: '<S78>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE[0] = rtb_Gain_a_idx_0;
    rtDW.Integrator_DSTATE[1] = rtb_Gain_a_idx_1;
    rtDW.Integrator_DSTATE[2] = rtb_Gain_a_idx_2;
    rtDW.Integrator_DSTATE[3] = rtb_Gain_a_idx_3;
  }

  if (rtb_Compare || (rtDW.Integrator_PrevResetState != 0)) {
    rtDW.Integrator_DSTATE[0] = rtb_Gain_a_idx_0;
    rtDW.Integrator_DSTATE[1] = rtb_Gain_a_idx_1;
    rtDW.Integrator_DSTATE[2] = rtb_Gain_a_idx_2;
    rtDW.Integrator_DSTATE[3] = rtb_Gain_a_idx_3;
  }

  rtb_Integrator_idx_0 = rtDW.Integrator_DSTATE[0];
  rtb_Integrator_idx_1 = rtDW.Integrator_DSTATE[1];
  rtb_Integrator_idx_2 = rtDW.Integrator_DSTATE[2];
  rtb_Integrator_idx_3 = rtDW.Integrator_DSTATE[3];

  /* Switch: '<S72>/Switch' incorporates:
   *  Constant: '<S70>/Constant'
   *  DiscreteIntegrator: '<S78>/Integrator'
   *  RelationalOperator: '<S72>/UpperRelop'
   */
  if (rtDW.Integrator_DSTATE[0] < 0.0) {
    rtb_Saturation_e[0] = 0.0;
  } else {
    rtb_Saturation_e[0] = rtDW.Integrator_DSTATE[0];
  }

  if (rtDW.Integrator_DSTATE[1] < 0.0) {
    rtb_Saturation_e[1] = 0.0;
  } else {
    rtb_Saturation_e[1] = rtDW.Integrator_DSTATE[1];
  }

  if (rtDW.Integrator_DSTATE[2] < 0.0) {
    rtb_Saturation_e[2] = 0.0;
  } else {
    rtb_Saturation_e[2] = rtDW.Integrator_DSTATE[2];
  }

  if (rtDW.Integrator_DSTATE[3] < 0.0) {
    rtb_Saturation_e[3] = 0.0;
  } else {
    rtb_Saturation_e[3] = rtDW.Integrator_DSTATE[3];
  }

  /* End of Switch: '<S72>/Switch' */

  /* Switch: '<S72>/Switch2' incorporates:
   *  DiscreteIntegrator: '<S78>/Integrator'
   *  RelationalOperator: '<S72>/LowerRelop1'
   */
  if (rtDW.Integrator_DSTATE[0] > 21.0) {
    rtb_Saturation_e[0] = 21.0;
  }

  if (rtDW.Integrator_DSTATE[1] > 21.0) {
    rtb_Saturation_e[1] = 21.0;
  }

  if (rtDW.Integrator_DSTATE[2] > 21.0) {
    rtb_Saturation_e[2] = 21.0;
  }

  if (rtDW.Integrator_DSTATE[3] > 21.0) {
    rtb_Saturation_e[3] = 21.0;
  }

  /* End of Switch: '<S72>/Switch2' */

  /* MinMax: '<S68>/Min' incorporates:
   *  Constant: '<S68>/Constant'
   *  Constant: '<S68>/Constant1'
   *  Constant: '<S68>/Constant2'
   *  Constant: '<S68>/Constant3'
   *  Lookup_n-D: '<S68>/Max_Torque_Temperature_External_LUT'
   *  Lookup_n-D: '<S68>/Max_Torque_Temperature_IGBT_LUT'
   *  Lookup_n-D: '<S68>/Max_Torque_Temperature_Internal_LUT'
   */
  minV_idx_0 = fmin(rtb_CCaller_o2[0], rtb_Efficiency[0]);
  minV_idx_1 = fmin(rtb_CCaller_o2[1], rtb_Efficiency[1]);
  rtb_Sum = fmin(rtb_CCaller_o2[2], rtb_Efficiency[2]);
  u0 = fmin(rtb_CCaller_o2[3], rtb_Efficiency[3]);
  rtb_torquemapselected = fmin(fmin(fmin(fmin(minV_idx_0,
    rtb_max_torque_temperature_in_0), rtb_max_torque_temperature_IG_0),
    rtb_torquemapselected_tmp), rtb_Saturation_e[0]);
  rtb_max_torque_temperature_IGBT = fmin(fmin(fmin(fmin(minV_idx_1,
    rtb_max_torque_temperature_in_0), rtb_max_torque_temperature_IG_0),
    rtb_torquemapselected_tmp), rtb_Saturation_e[1]);
  rtb_Sum = fmin(fmin(fmin(fmin(rtb_Sum, rtb_max_torque_temperature_in_0),
    rtb_max_torque_temperature_IG_0), rtb_torquemapselected_tmp),
                 rtb_Saturation_e[2]);
  u0 = fmin(fmin(fmin(fmin(u0, rtb_max_torque_temperature_in_0),
                      rtb_max_torque_temperature_IG_0),
                 rtb_torquemapselected_tmp), rtb_Saturation_e[3]);
  rtb_CCaller_o2[0] = fmin(rtb_torquemapselected, 21.560000000000002);
  rtb_CCaller_o2[1] = fmin(rtb_max_torque_temperature_IGBT, 21.560000000000002);
  rtb_CCaller_o2[2] = fmin(rtb_Sum, 21.560000000000002);
  rtb_CCaller_o2[3] = fmin(u0, 21.560000000000002);

  /* Saturate: '<S68>/Saturation_Positive' */
  u0 = rtb_CCaller_o2[0];
  if (u0 <= 0.0) {
    rtb_CCaller_o2[0] = 0.0;
  } else {
    rtb_CCaller_o2[0] = u0;
  }

  u0 = rtb_CCaller_o2[1];
  if (u0 <= 0.0) {
    rtb_CCaller_o2[1] = 0.0;
  } else {
    rtb_CCaller_o2[1] = u0;
  }

  u0 = rtb_CCaller_o2[2];
  if (u0 <= 0.0) {
    rtb_CCaller_o2[2] = 0.0;
  } else {
    rtb_CCaller_o2[2] = u0;
  }

  u0 = rtb_CCaller_o2[3];
  if (u0 <= 0.0) {
    rtb_CCaller_o2[3] = 0.0;
  } else {
    rtb_CCaller_o2[3] = u0;
  }

  /* End of Saturate: '<S68>/Saturation_Positive' */

  /* Product: '<S21>/Product' incorporates:
   *  Constant: '<S21>/Actual LMU // Nominal LMU'
   *  Gain: '<S21>/Gain'
   *  Lookup_n-D: '<S21>/2-D Lookup Table'
   */
  u0 = 0.017407407407407406 * look2_binlx(rtb_uDLookupTable_idx_0,
    rtb_Abs_o_idx_0, rtConstP.pooled29, rtConstP.pooled30,
    rtConstP.uDLookupTable_tableData, rtConstP.pooled49, 20U) *
    0.80645161290322576;

  /* Saturate: '<S21>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* MinMax: '<S21>/Min' */
  minV_idx_0 = fmin(u0, rtb_CCaller_o2[0]);

  /* Product: '<S21>/Product' incorporates:
   *  Constant: '<S21>/Actual LMU // Nominal LMU'
   *  Gain: '<S21>/Gain'
   *  Lookup_n-D: '<S21>/2-D Lookup Table'
   */
  u0 = 0.017407407407407406 * look2_binlx(rtb_uDLookupTable_idx_1,
    rtb_max_torque_available_idx_1, rtConstP.pooled29, rtConstP.pooled30,
    rtConstP.uDLookupTable_tableData, rtConstP.pooled49, 20U) *
    0.80645161290322576;

  /* Saturate: '<S21>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* MinMax: '<S21>/Min' */
  minV_idx_1 = fmin(u0, rtb_CCaller_o2[1]);

  /* Product: '<S21>/Product' incorporates:
   *  Constant: '<S21>/Actual LMU // Nominal LMU'
   *  Gain: '<S21>/Gain'
   *  Lookup_n-D: '<S21>/2-D Lookup Table'
   */
  u0 = 0.017407407407407406 * look2_binlx(rtb_uDLookupTable_idx_2,
    rtb_max_torque_available_idx_2, rtConstP.pooled29, rtConstP.pooled30,
    rtConstP.uDLookupTable_tableData, rtConstP.pooled49, 20U) *
    0.80645161290322576;

  /* Saturate: '<S21>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* MinMax: '<S21>/Min' */
  rtb_Sum = fmin(u0, rtb_CCaller_o2[2]);

  /* Product: '<S21>/Product' incorporates:
   *  Constant: '<S21>/Actual LMU // Nominal LMU'
   *  Gain: '<S21>/Gain'
   *  Lookup_n-D: '<S21>/2-D Lookup Table'
   */
  u0 = 0.017407407407407406 * look2_binlx(rtb_uDLookupTable_idx_3,
    rtb_max_torque_available_idx_3, rtConstP.pooled29, rtConstP.pooled30,
    rtConstP.uDLookupTable_tableData, rtConstP.pooled49, 20U) *
    0.80645161290322576;

  /* Saturate: '<S21>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* MinMax: '<S21>/Min' */
  u0 = fmin(u0, rtb_CCaller_o2[3]);

  /* Gain: '<S9>/Gain' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_max_torque_temperature_IGBT = 3.5714285714285712 * rtU.brake;

  /* Saturate: '<S9>/Saturation' */
  if (rtb_max_torque_temperature_IGBT > 1.0) {
    rtb_max_torque_temperature_IGBT = 1.0;
  } else if (rtb_max_torque_temperature_IGBT < 0.0) {
    rtb_max_torque_temperature_IGBT = 0.0;
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* Switch: '<S33>/Switch' */
  rtb_torquemapselected = !(rtb_max_torque_temperature_IGBT > 0.95);

  /* Product: '<S33>/Product' incorporates:
   *  Constant: '<S21>/Constant'
   *  Memory: '<S16>/Memory'
   *  MinMax: '<S21>/Min'
   *  MinMax: '<S21>/Min2'
   *  Sum: '<S42>/Sum'
   */
  rtb_ubu_idx_0 = fmin(rtDW.Memory_PreviousInput[0] + rtb_Sum1, fmin(minV_idx_0,
    100.0)) * rtb_torquemapselected;
  rtb_ubu_idx_1 = fmin(rtDW.Memory_PreviousInput[1] + rtb_Sum1, fmin(minV_idx_1,
    100.0)) * rtb_torquemapselected;
  rtb_ubu_idx_2 = fmin(rtDW.Memory_PreviousInput[2] + rtb_Sum1, fmin(rtb_Sum,
    100.0)) * rtb_torquemapselected;
  rtb_Sum1 = fmin(rtDW.Memory_PreviousInput[3] + rtb_Sum1, fmin(u0, 100.0)) *
    rtb_torquemapselected;

  /* RelationalOperator: '<S47>/Less Than' incorporates:
   *  Abs: '<S47>/Abs'
   *  Constant: '<S47>/             '
   */
  LessThan = (int16_T)(fabs(rtb_YRD) <= 0.25);

  /* DiscreteFir: '<S47>/Discrete FIR Filter' */
  i = LessThan << 14;
  for (iU = rtDW.DiscreteFIRFilter_circBuf; iU < 9; iU++) {
    i += rtDW.DiscreteFIRFilter_states_b[iU] << 14;
  }

  for (iU = 0; iU < rtDW.DiscreteFIRFilter_circBuf; iU++) {
    i += rtDW.DiscreteFIRFilter_states_b[iU] << 14;
  }

  /* RelationalOperator: '<S47>/Less Than4' incorporates:
   *  DiscreteFir: '<S47>/Discrete FIR Filter'
   */
  rtb_AND_n = (i >= 163840);

  /* Sum: '<S37>/Subtract' incorporates:
   *  Constant: '<S21>/Actual LMU // Nominal LMU'
   *  Gain: '<S21>/Gain1'
   *  Gain: '<S37>/Wheel2Motor'
   *  Lookup_n-D: '<S21>/2-D Lookup Table1'
   *  Product: '<S21>/Product1'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Saturation_e[0] = 0.017407407407407406 * look2_binlx
    (rtb_uDLookupTable_idx_0, rtb_Abs_o_idx_0, rtConstP.pooled29,
     rtConstP.pooled30, rtConstP.uDLookupTable1_tableData, rtConstP.pooled49,
     20U) * 0.80645161290322576 + 0.07407407407407407 * rtDW.UnitDelay_DSTATE[0];
  rtb_Saturation_e[1] = 0.017407407407407406 * look2_binlx
    (rtb_uDLookupTable_idx_1, rtb_max_torque_available_idx_1, rtConstP.pooled29,
     rtConstP.pooled30, rtConstP.uDLookupTable1_tableData, rtConstP.pooled49,
     20U) * 0.80645161290322576 + 0.07407407407407407 * rtDW.UnitDelay_DSTATE[1];
  rtb_Saturation_e[2] = 0.017407407407407406 * look2_binlx
    (rtb_uDLookupTable_idx_2, rtb_max_torque_available_idx_2, rtConstP.pooled29,
     rtConstP.pooled30, rtConstP.uDLookupTable1_tableData, rtConstP.pooled49,
     20U) * 0.80645161290322576 + 0.07407407407407407 * rtDW.UnitDelay_DSTATE[2];
  rtb_Saturation_e[3] = 0.017407407407407406 * look2_binlx
    (rtb_uDLookupTable_idx_3, rtb_max_torque_available_idx_3, rtConstP.pooled29,
     rtConstP.pooled30, rtConstP.uDLookupTable1_tableData, rtConstP.pooled49,
     20U) * 0.80645161290322576 + 0.07407407407407407 * rtDW.UnitDelay_DSTATE[3];

  /* Saturate: '<S21>/Saturation' */
  u0 = rtb_Saturation_e[0];
  if (u0 >= 0.0) {
    rtb_Saturation_e[0] = 0.0;
  } else {
    rtb_Saturation_e[0] = u0;
  }

  u0 = rtb_Saturation_e[1];
  if (u0 >= 0.0) {
    rtb_Saturation_e[1] = 0.0;
  } else {
    rtb_Saturation_e[1] = u0;
  }

  u0 = rtb_Saturation_e[2];
  if (u0 >= 0.0) {
    rtb_Saturation_e[2] = 0.0;
  } else {
    rtb_Saturation_e[2] = u0;
  }

  u0 = rtb_Saturation_e[3];
  if (u0 >= 0.0) {
    rtb_Saturation_e[3] = 0.0;
  } else {
    rtb_Saturation_e[3] = u0;
  }

  /* End of Saturate: '<S21>/Saturation' */

  /* Lookup_n-D: '<S69>/Display Overload Motor LUT' */
  rtb_Efficiency[0] = rtb_CCaller_o2_tmp;
  rtb_Efficiency[1] = rtb_CCaller_o2_tmp;
  rtb_Efficiency[2] = rtb_CCaller_o2_tmp;
  rtb_Efficiency[3] = rtb_CCaller_o2_tmp;

  /* Lookup_n-D: '<S69>/Display Overload Inverter LUT' */
  rtb_CCaller_o2[0] = rtb_CCaller_o2_tmp;
  rtb_CCaller_o2[1] = rtb_CCaller_o2_tmp;
  rtb_CCaller_o2[2] = rtb_CCaller_o2_tmp;
  rtb_CCaller_o2[3] = rtb_CCaller_o2_tmp;

  /* Gain: '<S79>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_Abs_o_idx_0 = 128.91550390443524 * rtU.omega_wheels_FL;

  /* Saturate: '<S79>/Saturation1' */
  if (rtb_Abs_o_idx_0 <= 0.0) {
    rtb_Abs_o_idx_0 = 0.0;
  }

  /* Gain: '<S79>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_FR'
   */
  rtb_max_torque_available_idx_1 = 128.91550390443524 * rtU.omega_wheels_FR;

  /* Saturate: '<S79>/Saturation1' */
  if (rtb_max_torque_available_idx_1 <= 0.0) {
    rtb_max_torque_available_idx_1 = 0.0;
  }

  /* Gain: '<S79>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_RL'
   */
  rtb_max_torque_available_idx_2 = 128.91550390443524 * rtU.omega_wheels_RL;

  /* Saturate: '<S79>/Saturation1' */
  if (rtb_max_torque_available_idx_2 <= 0.0) {
    rtb_max_torque_available_idx_2 = 0.0;
  }

  /* Gain: '<S79>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_max_torque_available_idx_3 = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S79>/Saturation1' */
  if (rtb_max_torque_available_idx_3 <= 0.0) {
    rtb_max_torque_available_idx_3 = 0.0;
  }

  /* Lookup_n-D: '<S79>/1-D Lookup Table' */
  rtb_uDLookupTable_idx_0 = look1_binlx(rtb_Abs_o_idx_0,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData_p, 19U);
  rtb_uDLookupTable_idx_1 = look1_binlx(rtb_max_torque_available_idx_1,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData_p, 19U);
  rtb_uDLookupTable_idx_2 = look1_binlx(rtb_max_torque_available_idx_2,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData_p, 19U);

  /* Lookup_n-D: '<S79>/2-D Lookup Table1' incorporates:
   *  Constant: '<S2>/Constant5'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled40, 45U,
    &rtb_torquemapselected);
  fractions_0[1U] = rtb_torquemapselected;
  bpIndices_0[0U] = plook_binc(rtb_Abs_o_idx_0, rtConstP.pooled39, 200U,
    &rtb_torquemapselected);
  fractions_0[0U] = rtb_torquemapselected;
  rtb_Abs_o_idx_0 = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled38, 201U);
  bpIndices_0[0U] = plook_binc(rtb_max_torque_available_idx_1, rtConstP.pooled39,
    200U, &rtb_torquemapselected);
  fractions_0[0U] = rtb_torquemapselected;
  rtb_max_torque_available_idx_1 = intrp2d_l(bpIndices_0, fractions_0,
    rtConstP.pooled38, 201U);
  bpIndices_0[0U] = plook_binc(rtb_max_torque_available_idx_2, rtConstP.pooled39,
    200U, &rtb_torquemapselected);
  fractions_0[0U] = rtb_torquemapselected;
  rtb_max_torque_available_idx_2 = intrp2d_l(bpIndices_0, fractions_0,
    rtConstP.pooled38, 201U);
  bpIndices_0[0U] = plook_binc(rtb_max_torque_available_idx_3, rtConstP.pooled39,
    200U, &rtb_torquemapselected);
  fractions_0[0U] = rtb_torquemapselected;

  /* Gain: '<S79>/Gain' incorporates:
   *  MinMax: '<S79>/Min'
   */
  rtb_YRD = 0.0098000000000000014 * fmin(rtb_uDLookupTable_idx_0,
    rtb_Abs_o_idx_0);

  /* Switch: '<S80>/Switch2' incorporates:
   *  Constant: '<S79>/Constant'
   *  RelationalOperator: '<S80>/LowerRelop1'
   *  RelationalOperator: '<S80>/UpperRelop'
   *  Switch: '<S80>/Switch'
   */
  if (rtb_YRD > 21.0) {
    rtb_YRD = 21.0;
  } else if (rtb_YRD < 0.0) {
    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S79>/Constant'
     */
    rtb_YRD = 0.0;
  }

  /* RateLimiter: '<S79>/Rate Limiter' */
  if (rtb_YRD - rtDW.PrevY[0] > 0.84) {
    rtb_YRD = rtDW.PrevY[0] + 0.84;
  }

  rtDW.PrevY[0] = rtb_YRD;

  /* Gain: '<S79>/Gain' incorporates:
   *  MinMax: '<S79>/Min'
   */
  rtb_Abs_o_idx_0 = rtb_YRD;
  rtb_YRD = 0.0098000000000000014 * fmin(rtb_uDLookupTable_idx_1,
    rtb_max_torque_available_idx_1);

  /* Switch: '<S80>/Switch2' incorporates:
   *  Constant: '<S79>/Constant'
   *  RelationalOperator: '<S80>/LowerRelop1'
   *  RelationalOperator: '<S80>/UpperRelop'
   *  Switch: '<S80>/Switch'
   */
  if (rtb_YRD > 21.0) {
    rtb_YRD = 21.0;
  } else if (rtb_YRD < 0.0) {
    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S79>/Constant'
     */
    rtb_YRD = 0.0;
  }

  /* RateLimiter: '<S79>/Rate Limiter' */
  if (rtb_YRD - rtDW.PrevY[1] > 0.84) {
    rtb_YRD = rtDW.PrevY[1] + 0.84;
  }

  rtDW.PrevY[1] = rtb_YRD;

  /* Gain: '<S79>/Gain' incorporates:
   *  MinMax: '<S79>/Min'
   */
  rtb_max_torque_available_idx_1 = rtb_YRD;
  rtb_YRD = 0.0098000000000000014 * fmin(rtb_uDLookupTable_idx_2,
    rtb_max_torque_available_idx_2);

  /* Switch: '<S80>/Switch2' incorporates:
   *  Constant: '<S79>/Constant'
   *  RelationalOperator: '<S80>/LowerRelop1'
   *  RelationalOperator: '<S80>/UpperRelop'
   *  Switch: '<S80>/Switch'
   */
  if (rtb_YRD > 21.0) {
    rtb_YRD = 21.0;
  } else if (rtb_YRD < 0.0) {
    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S79>/Constant'
     */
    rtb_YRD = 0.0;
  }

  /* RateLimiter: '<S79>/Rate Limiter' */
  if (rtb_YRD - rtDW.PrevY[2] > 0.84) {
    rtb_YRD = rtDW.PrevY[2] + 0.84;
  }

  rtDW.PrevY[2] = rtb_YRD;

  /* Gain: '<S79>/Gain' incorporates:
   *  Lookup_n-D: '<S79>/1-D Lookup Table'
   *  Lookup_n-D: '<S79>/2-D Lookup Table1'
   *  MinMax: '<S79>/Min'
   */
  rtb_max_torque_available_idx_2 = rtb_YRD;
  rtb_YRD = 0.0098000000000000014 * fmin(look1_binlx
    (rtb_max_torque_available_idx_3, rtConstP.uDLookupTable_bp01Data,
     rtConstP.uDLookupTable_tableData_p, 19U), intrp2d_l(bpIndices_0,
    fractions_0, rtConstP.pooled38, 201U));

  /* Switch: '<S80>/Switch2' incorporates:
   *  Constant: '<S79>/Constant'
   *  RelationalOperator: '<S80>/LowerRelop1'
   *  RelationalOperator: '<S80>/UpperRelop'
   *  Switch: '<S80>/Switch'
   */
  if (rtb_YRD > 21.0) {
    rtb_YRD = 21.0;
  } else if (rtb_YRD < 0.0) {
    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S79>/Constant'
     */
    rtb_YRD = 0.0;
  }

  /* RateLimiter: '<S79>/Rate Limiter' */
  if (rtb_YRD - rtDW.PrevY[3] > 0.84) {
    rtb_YRD = rtDW.PrevY[3] + 0.84;
  }

  rtDW.PrevY[3] = rtb_YRD;

  /* MinMax: '<S69>/Min1' incorporates:
   *  Constant: '<S69>/Constant'
   *  Constant: '<S69>/Constant1'
   *  Constant: '<S69>/Constant2'
   *  Constant: '<S69>/Constant3'
   */
  minV_idx_0 = fmin(rtb_Efficiency[0], rtb_CCaller_o2[0]);
  minV_idx_1 = fmin(rtb_Efficiency[1], rtb_CCaller_o2[1]);
  rtb_Sum = fmin(rtb_Efficiency[2], rtb_CCaller_o2[2]);
  u0 = fmin(rtb_Efficiency[3], rtb_CCaller_o2[3]);
  rtb_Efficiency[0] = fmin(fmin(fmin(fmin(fmin(minV_idx_0,
    rtb_max_torque_temperature_in_0), rtb_max_torque_temperature_IG_0),
    rtb_torquemapselected_tmp), rtb_Abs_o_idx_0), 21.0);
  rtb_Efficiency[1] = fmin(fmin(fmin(fmin(fmin(minV_idx_1,
    rtb_max_torque_temperature_in_0), rtb_max_torque_temperature_IG_0),
    rtb_torquemapselected_tmp), rtb_max_torque_available_idx_1), 21.0);
  rtb_Efficiency[2] = fmin(fmin(fmin(fmin(fmin(rtb_Sum,
    rtb_max_torque_temperature_in_0), rtb_max_torque_temperature_IG_0),
    rtb_torquemapselected_tmp), rtb_max_torque_available_idx_2), 21.0);
  rtb_Efficiency[3] = fmin(fmin(fmin(fmin(fmin(u0,
    rtb_max_torque_temperature_in_0), rtb_max_torque_temperature_IG_0),
    rtb_torquemapselected_tmp), rtb_YRD), 21.0);

  /* Saturate: '<S69>/Saturation_Positive' */
  u0 = rtb_Efficiency[0];
  if (u0 <= 0.0) {
    rtb_Efficiency[0] = 0.0;
  } else {
    rtb_Efficiency[0] = u0;
  }

  u0 = rtb_Efficiency[1];
  if (u0 <= 0.0) {
    rtb_Efficiency[1] = 0.0;
  } else {
    rtb_Efficiency[1] = u0;
  }

  u0 = rtb_Efficiency[2];
  if (u0 <= 0.0) {
    rtb_Efficiency[2] = 0.0;
  } else {
    rtb_Efficiency[2] = u0;
  }

  u0 = rtb_Efficiency[3];
  if (u0 <= 0.0) {
    rtb_Efficiency[3] = 0.0;
  } else {
    rtb_Efficiency[3] = u0;
  }

  /* End of Saturate: '<S69>/Saturation_Positive' */

  /* UnaryMinus: '<S21>/Unary Minus' */
  rtb_Efficiency[0] = -rtb_Efficiency[0];
  rtb_Efficiency[1] = -rtb_Efficiency[1];
  rtb_Efficiency[2] = -rtb_Efficiency[2];
  rtb_Efficiency[3] = -rtb_Efficiency[3];

  /* MinMax: '<S21>/Min1' */
  rtb_Efficiency[0] = fmax(rtb_Saturation_e[0], rtb_Efficiency[0]);
  rtb_Efficiency[1] = fmax(rtb_Saturation_e[1], rtb_Efficiency[1]);
  rtb_Efficiency[2] = fmax(rtb_Saturation_e[2], rtb_Efficiency[2]);
  rtb_Efficiency[3] = fmax(rtb_Saturation_e[3], rtb_Efficiency[3]);

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S41>/Constant6'
   *  Constant: '<S41>/Constant9'
   *  Logic: '<S41>/AND'
   *  Memory: '<S16>/Memory'
   *  RelationalOperator: '<S41>/Less Than3'
   *  RelationalOperator: '<S41>/Less Than4'
   *  Sum: '<S41>/Sum'
   *  UnitDelay: '<S41>/Unit Delay1'
   */
  if ((rtDW.UnitDelay1_DSTATE < 0.05) && (0.05 < rtb_max_torque_temperature_IGBT))
  {
    rtb_Saturation_e[0] = -21.0;
    rtb_Saturation_e[1] = -21.0;
    rtb_Saturation_e[2] = -21.0;
    rtb_Saturation_e[3] = -21.0;
  } else {
    /* Sum: '<S41>/Sum1' incorporates:
     *  Abs: '<S41>/Abs'
     *  Constant: '<S41>/Constant5'
     *  Constant: '<S41>/Constant8'
     *  Product: '<S41>/Product'
     */
    rtb_torquemapselected = fabs(rtb_Sum1_tmp * 5.0) + 5.0;
    rtb_Saturation_e[0] = rtDW.Memory_PreviousInput[0] - rtb_torquemapselected;
    rtb_Saturation_e[1] = rtDW.Memory_PreviousInput[1] - rtb_torquemapselected;
    rtb_Saturation_e[2] = rtDW.Memory_PreviousInput[2] - rtb_torquemapselected;
    rtb_Saturation_e[3] = rtDW.Memory_PreviousInput[3] - rtb_torquemapselected;
  }

  /* MinMax: '<S21>/Max' incorporates:
   *  MinMax: '<S21>/Min1'
   */
  rtb_Saturation_e[0] = fmax(rtb_Efficiency[0], rtb_Saturation_e[0]);
  rtb_Saturation_e[1] = fmax(rtb_Efficiency[1], rtb_Saturation_e[1]);
  rtb_Saturation_e[2] = fmax(rtb_Efficiency[2], rtb_Saturation_e[2]);
  rtb_Saturation_e[3] = fmax(rtb_Efficiency[3], rtb_Saturation_e[3]);

  /* Product: '<S32>/Product' incorporates:
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S32>/Less Than'
   */
  rtb_Abs_o_idx_0 = (real_T)(rtb_Sign >= -0.5) * rtb_Saturation_e[0];
  rtb_max_torque_available_idx_1 = (real_T)(rtb_Switch_c >= -0.5) *
    rtb_Saturation_e[1];
  rtb_max_torque_available_idx_2 = (real_T)(rtb_RL_m >= -0.5) *
    rtb_Saturation_e[2];
  rtb_max_torque_available_idx_3 = (real_T)(rtb_RR >= -0.5) * rtb_Saturation_e[3];

  /* SignalConversion generated from: '<S36>/ SFunction ' incorporates:
   *  MATLAB Function: '<S21>/Cross Check'
   *  MinMax: '<S21>/Min1'
   */
  rtb_TmpSignalConversionAtCFunct[9] = rtb_Efficiency[0];

  /* MATLAB Function: '<S21>/Cross Check' incorporates:
   *  Constant: '<S47>/ '
   *  Constant: '<S47>/  '
   *  Constant: '<S47>/Constant'
   *  DataTypeConversion: '<S47>/Data Type Conversion'
   *  DataTypeConversion: '<S47>/Data Type Conversion1'
   *  Gain: '<S47>/Gain'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S47>/AND'
   *  Logic: '<S47>/AND1'
   *  Logic: '<S47>/AND2'
   *  RelationalOperator: '<S47>/Less Than1'
   *  RelationalOperator: '<S47>/Less Than2'
   *  RelationalOperator: '<S47>/Less Than3'
   *  Sum: '<S47>/Sum'
   */
  switch ((int32_T)((real_T)((rtb_max_torque_temperature_IGBT < 0.95) && (0.05 <
             rtb_max_torque_temperature_IGBT) && rtb_AND_n) * 2.0 + (real_T)
                    (rtb_AND_n && (rtU.throttle >= 0.05)))) {
   case 0:
    rtb_YRD = rtb_Abs_o_idx_0;
    if (rtb_Abs_o_idx_0 > rtb_ubu_idx_0) {
      rtb_YRD = rtb_ubu_idx_0 - rtb_TmpSignalConversionAtCFunct[9];
    }

    rtb_Abs_o_idx_0 = rtb_YRD;
    rtb_YRD = rtb_max_torque_available_idx_1;
    if (rtb_max_torque_available_idx_1 > rtb_ubu_idx_1) {
      rtb_YRD = rtb_ubu_idx_1 - rtb_TmpSignalConversionAtCFunct[9];
    }

    rtb_max_torque_available_idx_1 = rtb_YRD;
    rtb_YRD = rtb_max_torque_available_idx_2;
    if (rtb_max_torque_available_idx_2 > rtb_ubu_idx_2) {
      rtb_YRD = rtb_ubu_idx_2 - rtb_TmpSignalConversionAtCFunct[9];
    }

    rtb_max_torque_available_idx_2 = rtb_YRD;
    rtb_YRD = rtb_max_torque_available_idx_3;
    if (rtb_max_torque_available_idx_3 > rtb_Sum1) {
      rtb_YRD = rtb_Sum1 - rtb_TmpSignalConversionAtCFunct[9];
    }

    rtb_max_torque_available_idx_3 = rtb_YRD;
    break;

   case 1:
    rtb_Abs_o_idx_0 = 0.0;
    rtb_max_torque_available_idx_1 = 0.0;
    rtb_max_torque_available_idx_2 = 0.0;
    rtb_max_torque_available_idx_3 = 0.0;
    break;

   case 2:
    rtb_ubu_idx_0 = 0.0;
    rtb_ubu_idx_1 = 0.0;
    rtb_ubu_idx_2 = 0.0;
    rtb_Sum1 = 0.0;
    break;

   case 3:
    rtb_Abs_o_idx_0 = 0.0;
    rtb_ubu_idx_0 = 0.0;
    rtb_max_torque_available_idx_1 = 0.0;
    rtb_ubu_idx_1 = 0.0;
    rtb_max_torque_available_idx_2 = 0.0;
    rtb_ubu_idx_2 = 0.0;
    rtb_max_torque_available_idx_3 = 0.0;
    rtb_Sum1 = 0.0;
    break;
  }

  /* CFunction: '<S34>/C Function' */
  for (i = 0; i < 2; i++) {
    iU = i << 2;
    rtDW.CFunction_i[iU] = rtb_Abs_o_idx_0;
    rtDW.CFunction_i[iU + 1] = rtb_max_torque_available_idx_1;
    rtDW.CFunction_i[iU + 2] = rtb_max_torque_available_idx_2;
    rtDW.CFunction_i[iU + 3] = rtb_max_torque_available_idx_3;
  }

  /* End of CFunction: '<S34>/C Function' */

  /* CFunction: '<S35>/C Function' */
  for (i = 0; i < 2; i++) {
    rtDW.CFunction_a[i << 2] = rtb_ubu_idx_0;
    rtDW.CFunction_a[(i << 2) + 1] = rtb_ubu_idx_1;
    rtDW.CFunction_a[(i << 2) + 2] = rtb_ubu_idx_2;
    rtDW.CFunction_a[(i << 2) + 3] = rtb_Sum1;
  }

  /* End of CFunction: '<S35>/C Function' */

  /* Product: '<S25>/Product' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Constant: '<S25>/Constant2'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S56>/Exponent < 0'
   *  Gain: '<S25>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S25>/ '
   *  Math: '<S56>/Power'
   *  Product: '<S25>/Product1'
   *  Product: '<S56>/Divide'
   *  Product: '<S56>/Divide1'
   *  RelationalOperator: '<S25>/Less Than'
   *  RelationalOperator: '<S25>/Less Than1'
   *  Sum: '<S25>/Subtract1'
   *  Sum: '<S56>/Subtract'
   *  Sum: '<S56>/Sum'
   */
  rtb_Sign = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle), -1.5) +
                     1.0) - rtb_max_torque_temperature_IGBT) * (real_T)(int8_T)
    ((int8_T)(rtb_max_torque_temperature_IGBT >= 0.05) ^ (int8_T)(rtU.throttle >=
      0.05)) * 84.0;

  /* Gain: '<S25>/Gain2' */
  rtb_torquemapselected = 0.95 * rtb_Sign;

  /* Gain: '<S25>/Gain3' */
  rtb_Sign *= 1.05;

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S23>/AND'
   *  RelationalOperator: '<S23>/Less Than'
   *  RelationalOperator: '<S23>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_max_torque_temperature_IGBT)) {
    /* SignalConversion generated from: '<S16>/C Caller' incorporates:
     *  Constant: '<S25>/Constant'
     */
    rtb_Saturation_e[0] = -0.0;
  } else {
    /* SignalConversion generated from: '<S16>/C Caller' incorporates:
     *  MinMax: '<S25>/Max1'
     */
    rtb_Saturation_e[0] = fmin(rtb_torquemapselected, rtb_Sign);
  }

  /* End of Switch: '<S25>/Switch2' */

  /* Product: '<S25>/Divide' incorporates:
   *  Constant: '<S2>/Constant8'
   *  Gain: '<S25>/Gain'
   *  Gain: '<S25>/Powertrain Efficiency Regen'
   *  Product: '<S25>/Divide1'
   */
  rtb_Switch_c = 1.0 / (57.4468085106383 * rtb_vx);
  u0 = rtb_Switch_c * -28000.0;

  /* Saturate: '<S25>/Saturation' */
  if (u0 > 0.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_Saturation_e[1] = 0.0;
  } else if (u0 < -84.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_Saturation_e[1] = -84.0;
  } else {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_Saturation_e[1] = u0;
  }

  /* End of Saturate: '<S25>/Saturation' */

  /* SignalConversion generated from: '<S16>/C Caller' incorporates:
   *  Constant: '<S25>/Constant3'
   */
  rtb_Saturation_e[2] = 0.0;
  rtb_Saturation_e[3] = 0.0;

  /* SignalConversion generated from: '<S16>/C Caller' incorporates:
   *  MinMax: '<S25>/Max'
   */
  rtb_Efficiency[0] = fmax(rtb_torquemapselected, rtb_Sign);

  /* Product: '<S25>/Divide1' incorporates:
   *  Constant: '<S2>/Constant9'
   *  Gain: '<S25>/Powertrain Efficiency Tractive'
   */
  u0 = rtb_Switch_c * 64000.0;

  /* Saturate: '<S25>/Saturation1' */
  if (u0 > 84.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_Efficiency[1] = 84.0;
  } else if (u0 < 0.0) {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_Efficiency[1] = 0.0;
  } else {
    /* SignalConversion generated from: '<S16>/C Caller' */
    rtb_Efficiency[1] = u0;
  }

  /* End of Saturate: '<S25>/Saturation1' */

  /* SignalConversion generated from: '<S16>/C Caller' incorporates:
   *  Constant: '<S25>/Constant4'
   */
  rtb_Efficiency[2] = 0.0;
  rtb_Efficiency[3] = 0.0;

  /* Gain: '<S26>/Gain' incorporates:
   *  Abs: '<S26>/Abs'
   */
  rtb_torquemapselected = 57.295779513082323 * fabs(rtb_Sum_ks);

  /* Saturate: '<S26>/Saturation' */
  if (rtb_torquemapselected > 1.0) {
    rtb_torquemapselected = 1.0;
  }

  /* End of Saturate: '<S26>/Saturation' */

  /* MATLAB Function: '<S26>/Linear Activation' */
  rtb_torquemapselected = 1.0 / (rt_powd_snf(rtb_torquemapselected / (1.0 -
    rtb_torquemapselected), -3.0) + 1.0);

  /* MATLAB Function: '<S26>/MATLAB Function' incorporates:
   *  Constant: '<S26>/r'
   *  Constant: '<S26>/r1'
   *  MATLAB Function: '<S26>/Linear Activation'
   */
  memset(&varargin_1[0], 0, 9U * sizeof(real_T));
  varargin_1[0] = 0.0;
  varargin_1[4] = 0.0;
  varargin_1[8] = (1.0 - rtb_torquemapselected) * 0.0 + 0.0001 *
    rtb_torquemapselected;
  memset(&varargin_2[0], 0, sizeof(real_T) << 4U);
  varargin_2[0] = 0.01;
  varargin_2[5] = 0.01;
  varargin_2[10] = 0.01;
  varargin_2[15] = 0.01;
  memset(&rtb_y[0], 0, 49U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    rtb_y[7 * i] = 0.0;
    rtb_y[7 * i + 1] = 0.0;
    rtb_y[7 * i + 2] = varargin_1[3 * i + 2];
  }

  for (i = 0; i < 4; i++) {
    int32_T rtb_y_tmp;
    iU = i << 2;
    rtb_y_tmp = (i + 3) * 7;
    rtb_y[rtb_y_tmp + 3] = varargin_2[iU];
    rtb_y[rtb_y_tmp + 4] = varargin_2[iU + 1];
    rtb_y[rtb_y_tmp + 5] = varargin_2[iU + 2];
    rtb_y[rtb_y_tmp + 6] = varargin_2[iU + 3];
  }

  for (i = 0; i < 49; i++) {
    rtb_y[i] *= 50.0;
  }

  /* End of MATLAB Function: '<S26>/MATLAB Function' */

  /* CCaller: '<S16>/C Caller' incorporates:
   *  CFunction: '<S27>/C Function'
   *  CFunction: '<S30>/C Function'
   *  CFunction: '<S34>/C Function'
   *  CFunction: '<S35>/C Function'
   */
  Acados_Caller_wrapper(&rtb_TmpSignalConversionAtCCalle[0], &rtDW.CFunction_c[0],
                        &rtDW.CFunction_i[0], &rtDW.CFunction_a[0],
                        &rtDW.CFunction[0], &rtb_Saturation_e[0],
                        &rtb_Efficiency[0], &rtb_y[0], &rtb_CCaller_o2[0]);

  /* Gain: '<S52>/Gain2' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_Saturation_e[0] = 13.5 * rtU.omega_wheels_FL;
  rtb_Saturation_e[1] = 13.5 * rtU.omega_wheels_FR;
  rtb_Saturation_e[2] = 13.5 * rtU.omega_wheels_RL;
  rtb_Saturation_e[3] = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S52>/Saturation' */
  u0 = rtb_Saturation_e[0];
  if (u0 > 2083.9231268812296) {
    rtb_Saturation_e[0] = 2083.9231268812296;
  } else if (u0 < 10.471975511965978) {
    rtb_Saturation_e[0] = 10.471975511965978;
  } else {
    rtb_Saturation_e[0] = u0;
  }

  u0 = rtb_Saturation_e[1];
  if (u0 > 2083.9231268812296) {
    rtb_Saturation_e[1] = 2083.9231268812296;
  } else if (u0 < 10.471975511965978) {
    rtb_Saturation_e[1] = 10.471975511965978;
  } else {
    rtb_Saturation_e[1] = u0;
  }

  u0 = rtb_Saturation_e[2];
  if (u0 > 2083.9231268812296) {
    rtb_Saturation_e[2] = 2083.9231268812296;
  } else if (u0 < 10.471975511965978) {
    rtb_Saturation_e[2] = 10.471975511965978;
  } else {
    rtb_Saturation_e[2] = u0;
  }

  u0 = rtb_Saturation_e[3];
  if (u0 > 2083.9231268812296) {
    rtb_Saturation_e[3] = 2083.9231268812296;
  } else if (u0 < 10.471975511965978) {
    rtb_Saturation_e[3] = 10.471975511965978;
  } else {
    rtb_Saturation_e[3] = u0;
  }

  /* End of Saturate: '<S52>/Saturation' */

  /* Abs: '<S54>/Abs' */
  rtb_Efficiency[0] = fabs(rtb_Memory_idx_0);
  rtb_Efficiency[1] = fabs(rtb_Memory_idx_1);
  rtb_Efficiency[2] = fabs(rtb_Memory_idx_2);
  rtb_Efficiency[3] = fabs(rtb_Memory_idx_3);

  /* Lookup_n-D: '<S54>/2-D Lookup Table' */
  rtb_Sum = rtb_Saturation_e[0];
  rtb_torquemapselected = rtb_Efficiency[0];
  rtb_Efficiency[0] = look2_binlx(rtb_Sum, rtb_torquemapselected,
    rtConstP.uDLookupTable_bp01Data_e, rtConstP.uDLookupTable_bp02Data,
    rtConstP.uDLookupTable_tableData_i, rtConstP.uDLookupTable_maxIndex, 51U);
  rtb_Sum = rtb_Saturation_e[1];
  rtb_torquemapselected = rtb_Efficiency[1];
  rtb_Efficiency[1] = look2_binlx(rtb_Sum, rtb_torquemapselected,
    rtConstP.uDLookupTable_bp01Data_e, rtConstP.uDLookupTable_bp02Data,
    rtConstP.uDLookupTable_tableData_i, rtConstP.uDLookupTable_maxIndex, 51U);
  rtb_Sum = rtb_Saturation_e[2];
  rtb_torquemapselected = rtb_Efficiency[2];
  rtb_Efficiency[2] = look2_binlx(rtb_Sum, rtb_torquemapselected,
    rtConstP.uDLookupTable_bp01Data_e, rtConstP.uDLookupTable_bp02Data,
    rtConstP.uDLookupTable_tableData_i, rtConstP.uDLookupTable_maxIndex, 51U);
  rtb_Sum = rtb_Saturation_e[3];
  rtb_torquemapselected = rtb_Efficiency[3];
  rtb_Efficiency[3] = look2_binlx(rtb_Sum, rtb_torquemapselected,
    rtConstP.uDLookupTable_bp01Data_e, rtConstP.uDLookupTable_bp02Data,
    rtConstP.uDLookupTable_tableData_i, rtConstP.uDLookupTable_maxIndex, 51U);

  /* Saturate: '<S54>/Saturation' */
  u0 = rtb_Efficiency[0];
  if (u0 > 1.0) {
    rtb_Efficiency[0] = 1.0;
  } else if (u0 < 0.5) {
    rtb_Efficiency[0] = 0.5;
  } else {
    rtb_Efficiency[0] = u0;
  }

  u0 = rtb_Efficiency[1];
  if (u0 > 1.0) {
    rtb_Efficiency[1] = 1.0;
  } else if (u0 < 0.5) {
    rtb_Efficiency[1] = 0.5;
  } else {
    rtb_Efficiency[1] = u0;
  }

  u0 = rtb_Efficiency[2];
  if (u0 > 1.0) {
    rtb_Efficiency[2] = 1.0;
  } else if (u0 < 0.5) {
    rtb_Efficiency[2] = 0.5;
  } else {
    rtb_Efficiency[2] = u0;
  }

  u0 = rtb_Efficiency[3];
  if (u0 > 1.0) {
    rtb_Efficiency[3] = 1.0;
  } else if (u0 < 0.5) {
    rtb_Efficiency[3] = 0.5;
  } else {
    rtb_Efficiency[3] = u0;
  }

  /* End of Saturate: '<S54>/Saturation' */

  /* Switch: '<S52>/Switch3' incorporates:
   *  Gain: '<S52>/     '
   *  Gain: '<S52>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    rtb_Efficiency[0] *= 0.96;
    rtb_Efficiency[1] *= 0.96;
    rtb_Efficiency[2] *= 0.96;
    rtb_Efficiency[3] *= 0.96;
  } else {
    rtb_Efficiency[0] *= 1.0416666666666667;
    rtb_Efficiency[1] *= 1.0416666666666667;
    rtb_Efficiency[2] *= 1.0416666666666667;
    rtb_Efficiency[3] *= 1.0416666666666667;
  }

  /* End of Switch: '<S52>/Switch3' */

  /* DiscreteFir: '<S55>/Discrete FIR Filter' */
  rtb_torquemapselected = 0.0;
  for (iU = rtDW.DiscreteFIRFilter_circBuf_h; iU < 4; iU++) {
    rtb_torquemapselected += rtDW.DiscreteFIRFilter_states[iU];
  }

  for (iU = 0; iU < rtDW.DiscreteFIRFilter_circBuf_h; iU++) {
    rtb_torquemapselected += rtDW.DiscreteFIRFilter_states[iU];
  }

  /* End of DiscreteFir: '<S55>/Discrete FIR Filter' */

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S55>/Constant'
   *  Constant: '<S55>/Constant1'
   *  Logic: '<S55>/OR'
   *  RelationalOperator: '<S55>/Less Than'
   *  RelationalOperator: '<S55>/Less Than1'
   */
  if ((rtb_vx < 3.0) || (rtb_torquemapselected >= 4.0)) {
    /* Update for Memory: '<S16>/Memory' incorporates:
     *  Constant: '<S55>/Constant2'
     *  Inport: '<Root>/throttle'
     *  Product: '<S55>/Product'
     */
    rtDW.Memory_PreviousInput[0] = rtU.throttle * 6.3;
    rtDW.Memory_PreviousInput[1] = rtU.throttle * 6.3;
    rtDW.Memory_PreviousInput[2] = rtU.throttle * 21.0;
    rtDW.Memory_PreviousInput[3] = rtU.throttle * 21.0;
  } else {
    /* Update for Memory: '<S16>/Memory' */
    rtDW.Memory_PreviousInput[0] = rtb_CCaller_o2[0];
    rtDW.Memory_PreviousInput[1] = rtb_CCaller_o2[1];
    rtDW.Memory_PreviousInput[2] = rtb_CCaller_o2[2];
    rtDW.Memory_PreviousInput[3] = rtb_CCaller_o2[3];
  }

  /* End of Switch: '<S24>/Switch' */

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Inport: '<Root>/brake_torque_FL'
   *  Inport: '<Root>/brake_torque_FR'
   *  Inport: '<Root>/brake_torque_RL'
   *  Inport: '<Root>/brake_torque_RR'
   */
  rtDW.UnitDelay_DSTATE[0] = rtU.brake_torque_FL;
  rtDW.UnitDelay_DSTATE[1] = rtU.brake_torque_FR;
  rtDW.UnitDelay_DSTATE[2] = rtU.brake_torque_RL;
  rtDW.UnitDelay_DSTATE[3] = rtU.brake_torque_RR;

  /* Update for DiscreteIntegrator: '<S78>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S71>/1//T' incorporates:
   *  Constant: '<S73>/Time constant'
   *  MinMax: '<S73>/Max'
   */
  rtb_vx = 1.0 / fmax(rtDW.Probe[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S78>/Integrator' incorporates:
   *  Product: '<S71>/1//T'
   *  Sum: '<S71>/Sum1'
   */
  rtDW.Integrator_DSTATE[0] += (rtb_Gain_a_idx_0 - rtb_Integrator_idx_0) *
    rtb_vx * 0.02;
  rtDW.Integrator_DSTATE[1] += (rtb_Gain_a_idx_1 - rtb_Integrator_idx_1) *
    rtb_vx * 0.02;
  rtDW.Integrator_DSTATE[2] += (rtb_Gain_a_idx_2 - rtb_Integrator_idx_2) *
    rtb_vx * 0.02;
  rtDW.Integrator_DSTATE[3] += (rtb_Gain_a_idx_3 - rtb_Integrator_idx_3) *
    rtb_vx * 0.02;
  rtDW.Integrator_PrevResetState = (int8_T)rtb_Compare;

  /* Update for DiscreteFir: '<S47>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 8;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states_b[rtDW.DiscreteFIRFilter_circBuf] = LessThan;

  /* End of Update for DiscreteFir: '<S47>/Discrete FIR Filter' */

  /* Update for UnitDelay: '<S41>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtb_max_torque_temperature_IGBT;

  /* Update for DiscreteFir: '<S55>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf_h--;
  if (rtDW.DiscreteFIRFilter_circBuf_h < 0) {
    rtDW.DiscreteFIRFilter_circBuf_h = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf_h] = 0.0;

  /* End of Update for DiscreteFir: '<S55>/Discrete FIR Filter' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Torque' */
  rtY.Torque = 0.0;
}

/* Model initialize function */
void TVModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
  /* Start for Probe: '<S73>/Probe' */
  rtDW.Probe[0] = 0.02;
  rtDW.Probe[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator' */
  rtDW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for RateLimiter: '<S79>/Rate Limiter' */
  rtDW.PrevY[0] = 21.0;
  rtDW.PrevY[1] = 21.0;
  rtDW.PrevY[2] = 21.0;
  rtDW.PrevY[3] = 21.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
