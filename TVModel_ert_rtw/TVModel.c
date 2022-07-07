/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Jul  7 16:26:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TVModel.h"

/* Named constants for Chart: '<S164>/Overlap Chart' */
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
static void MATLABFunction(const real_T rtu_u[4], real_T rty_y[4]);
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
 * Output and update for atomic system:
 *    '<S169>/MATLAB Function'
 *    '<S169>/MATLAB Function1'
 */
static void MATLABFunction(const real_T rtu_u[4], real_T rty_y[4])
{
  rty_y[0] = rtu_u[0];
  rty_y[1] = rtu_u[1];
  rty_y[2] = rtu_u[2];
  rty_y[3] = rtu_u[3];
}

/*
 * Output and update for action system:
 *    '<S159>/YRD_LUT_1'
 *    '<S159>/YRD_LUT_3'
 */
static void YRD_LUT_1(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_LUT_1;
  real_T rtb_vx_o;

  /* Abs: '<S224>/Abs' */
  rtb_LUT_1 = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S224>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_o = 3.0;
  } else {
    rtb_vx_o = rtu_vx;
  }

  /* End of Saturate: '<S224>/Saturation' */

  /* Product: '<S224>/Divide2' incorporates:
   *  Lookup_n-D: '<S224>/LUT_1'
   *  Product: '<S224>/Divide'
   *  Product: '<S224>/Divide1'
   *  Saturate: '<S224>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_LUT_1 * (look2_binlx(rtb_LUT_1,
    rtb_vx_o, rtConstP.pooled20, rtConstP.pooled21, rtConstP.pooled15,
    rtConstP.pooled56, 100U) / rtb_vx_o);
}

/*
 * Output and update for action system:
 *    '<S159>/YRD_LUT_0'
 *    '<S159>/YRD_LUT_2'
 */
static void YRD_LUT_0(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_LUT_0;
  real_T rtb_vx_n;

  /* Abs: '<S223>/Abs' */
  rtb_LUT_0 = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S223>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_n = 3.0;
  } else {
    rtb_vx_n = rtu_vx;
  }

  /* End of Saturate: '<S223>/Saturation' */

  /* Product: '<S223>/Divide2' incorporates:
   *  Lookup_n-D: '<S223>/LUT_0'
   *  Product: '<S223>/Divide'
   *  Product: '<S223>/Divide1'
   *  Saturate: '<S223>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_LUT_0 * (look2_binlx(rtb_LUT_0,
    rtb_vx_n, rtConstP.pooled20, rtConstP.pooled21, rtConstP.pooled16,
    rtConstP.pooled56, 100U) / rtb_vx_n);
}

/*
 * Output and update for action system:
 *    '<S159>/YRD_LUT_-1.5'
 *    '<S159>/YRD_LUT_-1.1'
 */
static void YRD_LUT_15(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
  *rty_yrd)
{
  real_T rtb_LUT_15;
  real_T rtb_vx_ox;

  /* Abs: '<S221>/Abs' */
  rtb_LUT_15 = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S221>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_ox = 3.0;
  } else {
    rtb_vx_ox = rtu_vx;
  }

  /* End of Saturate: '<S221>/Saturation' */

  /* Product: '<S221>/Divide2' incorporates:
   *  Lookup_n-D: '<S221>/LUT_-1.5'
   *  Product: '<S221>/Divide'
   *  Product: '<S221>/Divide1'
   *  Saturate: '<S221>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_LUT_15 * (look2_binlx(rtb_LUT_15,
    rtb_vx_ox, rtConstP.pooled20, rtConstP.pooled21, rtConstP.pooled17,
    rtConstP.pooled56, 100U) / rtb_vx_ox);
}

/*
 * Output and update for action system:
 *    '<S159>/YRD_LUT_-3'
 *    '<S159>/YRD_LUT_-1'
 */
static void YRD_LUT_3(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_a;
  real_T rtb_vx_e;

  /* Abs: '<S222>/Abs' */
  rtb_a = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S222>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_e = 3.0;
  } else {
    rtb_vx_e = rtu_vx;
  }

  /* End of Saturate: '<S222>/Saturation' */

  /* Product: '<S222>/Divide2' incorporates:
   *  Lookup_n-D: '<S222>/LUT_-3'
   *  Product: '<S222>/Divide'
   *  Product: '<S222>/Divide1'
   *  Saturate: '<S222>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_a * (look2_binlx(rtb_a, rtb_vx_e,
    rtConstP.pooled20, rtConstP.pooled21, rtConstP.pooled19, rtConstP.pooled56,
    100U) / rtb_vx_e);
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
  real_T rtb_y[121];
  real_T varargin_1[49];
  real_T RateTransition3[18];
  real_T varargin_2[16];
  real_T rtb_y_d[11];
  real_T rtb_y_ref_0[11];
  real_T rtb_UnaryMinus_ci[8];
  real_T rtb_y_b[8];
  real_T rtb_CCaller_o3[7];
  real_T rtb_x[7];
  real_T v[7];
  real_T rtb_lg[6];
  real_T rtb_ug[6];
  real_T rtb_CCaller_o2[4];
  real_T rtb_Product[4];
  real_T rtb_max_torque_overload_inverte[4];
  real_T rtb_y_m[4];
  real_T rtb_y_p[4];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T rtb_Abs3;
  real_T rtb_Abs_idx_0;
  real_T rtb_AvoidDividebyZero;
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
  real_T rtb_Integrator_iq_idx_0;
  real_T rtb_Integrator_iq_idx_1;
  real_T rtb_Integrator_iq_idx_2;
  real_T rtb_Integrator_iq_idx_3;
  real_T rtb_Memory_idx_0;
  real_T rtb_Memory_idx_1;
  real_T rtb_Mzlim;
  real_T rtb_RL;
  real_T rtb_RR;
  real_T rtb_Sign;
  real_T rtb_SignPreIntegrator;
  real_T rtb_SignPreIntegrator_idx_0;
  real_T rtb_SignPreIntegrator_idx_1;
  real_T rtb_SignPreIntegrator_idx_2;
  real_T rtb_SignPreIntegrator_idx_3;
  real_T rtb_SignPreIntegrator_idx_3_0;
  real_T rtb_Subtract_e5;
  real_T rtb_Subtract_m;
  real_T rtb_Subtract_m4_tmp;
  real_T rtb_Subtract_m4_tmp_0;
  real_T rtb_Subtract_m4_tmp_1;
  real_T rtb_Subtract_o;
  real_T rtb_Sum1_g;
  real_T rtb_Switch;
  real_T rtb_Switch_m;
  real_T rtb_T_max_k_idx_0;
  real_T rtb_T_max_k_idx_1;
  real_T rtb_T_max_k_idx_2;
  real_T rtb_T_max_k_idx_3;
  real_T rtb_UnaryMinus_ot_idx_0;
  real_T rtb_UnitDelay_e_idx_1;
  real_T rtb_UnitDelay_e_idx_2;
  real_T rtb_UnitDelay_e_idx_3;
  real_T rtb_UnitDelay_idx_0;
  real_T rtb_UnitDelay_idx_1;
  real_T rtb_UnitDelay_idx_2;
  real_T rtb_ZeroGain_a;
  real_T rtb_ZeroGain_o;
  real_T rtb_front_wheel_angle_single__p;
  real_T rtb_lg_saturation;
  real_T rtb_vx;
  real_T u0;
  int32_T ibcol;
  int32_T rowIdx;
  int32_T rowIdx_0;
  int32_T rtb_mz_output;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  uint32_T acc1;
  uint8_T DataTypeConversion;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_d;
  boolean_T rtb_Compare_g;
  boolean_T rtb_Compare_n;
  boolean_T rtb_Equal_c_idx_0;
  boolean_T rtb_Equal_c_idx_1;
  boolean_T rtb_Equal_c_idx_2;
  boolean_T rtb_Equal_c_idx_3;
  boolean_T rtb_Equal_idx_0;
  boolean_T rtb_Equal_idx_1;
  boolean_T rtb_Equal_idx_2;
  boolean_T rtb_Equal_idx_3;
  boolean_T rtb_LessThan3;
  boolean_T rtb_Logic_b_idx_0;
  boolean_T rtb_Logic_e_idx_0;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_k_idx_0;
  boolean_T rtb_Logic_l_idx_0;
  boolean_T rtb_Memory_e_idx_0;
  boolean_T rtb_Memory_e_idx_1;
  boolean_T rtb_Memory_e_idx_2;
  boolean_T rtb_Memory_e_idx_3;
  boolean_T rtb_Memory_i_idx_0;
  boolean_T rtb_Memory_i_idx_1;
  boolean_T rtb_Memory_i_idx_2;
  boolean_T rtb_Memory_i_idx_3;

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
  rtb_Sign = 30.826771653543307 * -rtU.ay;

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
  rtb_Subtract_m4_tmp_0 = rtb_Subtract_m4_tmp * 0.21998117647058821;

  /* Gain: '<S14>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S15>/Longitudinal Load Transfer'
   *  Gain: '<S16>/Longitudinal Load Transfer'
   *  Gain: '<S17>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S14>/Unary Minus1'
   */
  rtb_Subtract_m4_tmp_1 = 25.588235294117645 * -rtU.ax;

  /* Sum: '<S14>/Subtract' incorporates:
   *  Constant: '<S14>/Static Load Front'
   *  Gain: '<S14>/Drag moment'
   *  Gain: '<S14>/Lateral Load Transfer'
   *  Gain: '<S14>/Lift Force'
   *  Gain: '<S14>/Longitudinal Load Transfer'
   */
  rtb_Subtract_e5 = (((rtb_Sign + 635.688) + rtb_FilterCoefficient_idx_0) -
                     rtb_Subtract_m4_tmp_0) + rtb_Subtract_m4_tmp_1;

  /* Sum: '<S15>/Subtract' incorporates:
   *  Constant: '<S15>/Static Load Front'
   */
  rtb_Subtract_o = (((635.688 - rtb_Sign) + rtb_FilterCoefficient_idx_0) -
                    rtb_Subtract_m4_tmp_0) + rtb_Subtract_m4_tmp_1;

  /* Gain: '<S16>/Lift Force' incorporates:
   *  Gain: '<S17>/Lift Force'
   */
  rtb_Subtract_m4_tmp *= 0.74153333333333349;

  /* Sum: '<S16>/Subtract' incorporates:
   *  Constant: '<S16>/Static Load Front'
   *  Gain: '<S16>/Lift Force'
   */
  rtb_Subtract_m = (((rtb_Sign + 688.66200000000015) + rtb_Subtract_m4_tmp) +
                    rtb_Subtract_m4_tmp_0) - rtb_Subtract_m4_tmp_1;

  /* Sum: '<S17>/Subtract' incorporates:
   *  Constant: '<S17>/Static Load Front'
   */
  rtb_Sum1_g = (((688.66200000000015 - rtb_Sign) + rtb_Subtract_m4_tmp) +
                rtb_Subtract_m4_tmp_0) - rtb_Subtract_m4_tmp_1;

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
  rtb_Abs_idx_0 = fabs(look1_binlx(rtU.steering, rtConstP.pooled36,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Mzlim = fabs(look1_binlx(-rtU.steering, rtConstP.pooled36,
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
    rtb_Sign = 0.73439999999999994 * rtb_Gain1 + rtU.vy;

    /* Sum: '<S18>/Subtract' incorporates:
     *  Gain: '<S18>/Gain1'
     *  Sum: '<S20>/Subtract'
     */
    rtb_Subtract_m4_tmp_0 = rtb_vx - 0.635 * rtb_Gain1;
    rtb_y_m[0] = rt_atan2d_snf(rtb_Sign, rtb_Subtract_m4_tmp_0) - rtb_Abs_idx_0;

    /* Sum: '<S19>/Subtract' incorporates:
     *  Gain: '<S19>/Gain1'
     *  Sum: '<S18>/Subtract'
     *  Sum: '<S18>/Subtract1'
     *  Sum: '<S18>/Subtract2'
     *  Sum: '<S21>/Subtract'
     *  Trigonometry: '<S18>/Atan'
     */
    rtb_Subtract_m4_tmp_1 = 0.635 * rtb_Gain1 + rtb_vx;
    rtb_y_m[1] = rt_atan2d_snf(rtb_Sign, rtb_Subtract_m4_tmp_1) - rtb_Mzlim;

    /* Sum: '<S20>/Subtract1' incorporates:
     *  Gain: '<S20>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S19>/Subtract'
     *  Sum: '<S19>/Subtract2'
     *  Sum: '<S21>/Subtract1'
     *  Trigonometry: '<S19>/Atan'
     */
    rtb_Sign = rtU.vy - 0.79560000000000008 * rtb_Gain1;
    rtb_y_m[2] = rt_atan2d_snf(rtb_Sign, rtb_Subtract_m4_tmp_0);
    rtb_y_m[3] = rt_atan2d_snf(rtb_Sign, rtb_Subtract_m4_tmp_1);
  } else {
    rtb_y_m[0] = 0.0;
    rtb_y_m[1] = 0.0;
    rtb_y_m[2] = 0.0;
    rtb_y_m[3] = 0.0;
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
    rtb_Sign = rtb_vx * cos(rtb_Mzlim) + sin(rtb_Mzlim) * rtU.vy;
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
  rtb_Sign = rtU.omega_wheels_FL * 50.0;
  rtb_Subtract_m4_tmp_0 = rtU.omega_wheels_FR * 50.0;
  rtb_Subtract_m4_tmp_1 = rtU.omega_wheels_RL * 50.0;
  rtb_Subtract_m4_tmp = rtU.omega_wheels_RR * 50.0;

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S33>/Time constant'
   *  Constant: '<S36>/Constant'
   *  Sum: '<S33>/Sum1'
   */
  rtb_Compare = (0.1 - rtDW.Probe[0] <= 0.0);

  /* Memory: '<S26>/Memory' */
  rtb_Memory_i_idx_0 = rtDW.Memory_PreviousInput_f[0];

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
  rtb_Memory_i_idx_1 = rtDW.Memory_PreviousInput_f[1];

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
  rtb_Memory_i_idx_2 = rtDW.Memory_PreviousInput_f[2];

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
  rtb_Memory_i_idx_3 = rtDW.Memory_PreviousInput_f[3];

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
  rtb_y_p[0] = rtDW.UnitDelay3_1_DSTATE;
  rtb_y_p[1] = rtDW.UnitDelay3_2_DSTATE;
  rtb_y_p[2] = rtDW.UnitDelay3_3_DSTATE;
  rtb_y_p[3] = rtDW.UnitDelay3_4_DSTATE;

  /* MATLAB Function: '<S26>/MATLAB Function3' */
  rtb_y_p[0] *= 13.5;
  rtb_y_p[1] *= 13.5;
  rtb_y_p[2] *= 13.5;
  rtb_y_p[3] *= 13.5;

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
    rtb_y_p[0] / 0.235) - (rtb_Sign - rtDW.UD_DSTATE[0]) * 0.235 * 0.2 /
    0.055224999999999996) / 13.5;

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
    rtb_y_p[1] / 0.235) - (rtb_Subtract_m4_tmp_0 - rtDW.UD_DSTATE[1]) * 0.235 *
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
    rtb_y_p[2] / 0.235) - (rtb_Subtract_m4_tmp_1 - rtDW.UD_DSTATE[2]) * 0.235 *
    0.2 / 0.055224999999999996) / 13.5;

  /* Saturate: '<S81>/Saturation' */
  if (rtb_Filter_l_idx_3 > 2.0) {
    rtb_UnitDelay_idx_0 = 2.0;
  } else if (rtb_Filter_l_idx_3 < 0.0) {
    rtb_UnitDelay_idx_0 = 0.0;
  } else {
    rtb_UnitDelay_idx_0 = rtb_Filter_l_idx_3;
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
  rtb_T_max_k_idx_3 = (0.2 / ((rtb_UnitDelay_idx_0 + 0.5) * 67.5 *
    0.055224999999999996) + 1.0) * 0.235 * ((-rtDW.UnitDelay_DSTATE[3] / 0.235 +
    rtb_y_p[3] / 0.235) - (rtb_Subtract_m4_tmp - rtDW.UD_DSTATE[3]) * 0.235 *
    0.2 / 0.055224999999999996) / 13.5;
  if (rtb_y_p[0] / 13.5 > -5.0) {
    rtb_T_max_k_idx_0 = -21.0;
  }

  if (rtb_y_p[1] / 13.5 > -5.0) {
    rtb_T_max_k_idx_1 = -21.0;
  }

  if (rtb_y_p[2] / 13.5 > -5.0) {
    rtb_T_max_k_idx_2 = -21.0;
  }

  if (rtb_y_p[3] / 13.5 > -5.0) {
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
  rtb_y_p[0] = rtb_Switch;
  rtb_y_p[1] = rtb_Switch_m;
  rtb_y_p[2] = rtb_RL;
  rtb_y_p[3] = rtb_RR;

  /* MATLAB Function: '<S26>/MATLAB Function2' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  SignalConversion generated from: '<S30>/ SFunction '
   *  UnitDelay: '<S26>/Unit Delay'
   *  UnitDelay generated from: '<S26>/Unit Delay2'
   */
  if (rtb_y_p[0] < -0.1) {
    rtDW.UnitDelay_DSTATE_n[0] = rtDW.Integrator_DSTATE_h[0];
  } else if (rtDW.UnitDelay2_1_DSTATE > rtDW.UnitDelay_DSTATE_n[0] * 0.75 - 0.1)
  {
    rtDW.UnitDelay_DSTATE_n[0]--;
    if (rtDW.UnitDelay_DSTATE_n[0] < -21.0) {
      rtDW.UnitDelay_DSTATE_n[0] = -21.0;
    }
  } else {
    rtDW.UnitDelay_DSTATE_n[0] = rtDW.Integrator_DSTATE_h[0];
  }

  if (rtb_y_p[1] < -0.1) {
    rtDW.UnitDelay_DSTATE_n[1] = rtDW.Integrator_DSTATE_h[1];
  } else if (rtDW.UnitDelay2_2_DSTATE > rtDW.UnitDelay_DSTATE_n[1] * 0.75 - 0.1)
  {
    rtDW.UnitDelay_DSTATE_n[1]--;
    if (rtDW.UnitDelay_DSTATE_n[1] < -21.0) {
      rtDW.UnitDelay_DSTATE_n[1] = -21.0;
    }
  } else {
    rtDW.UnitDelay_DSTATE_n[1] = rtDW.Integrator_DSTATE_h[1];
  }

  if (rtb_y_p[2] < -0.1) {
    rtDW.UnitDelay_DSTATE_n[2] = rtDW.Integrator_DSTATE_h[2];
  } else if (rtDW.UnitDelay2_3_DSTATE > rtDW.UnitDelay_DSTATE_n[2] * 0.75 - 0.1)
  {
    rtDW.UnitDelay_DSTATE_n[2]--;
    if (rtDW.UnitDelay_DSTATE_n[2] < -21.0) {
      rtDW.UnitDelay_DSTATE_n[2] = -21.0;
    }
  } else {
    rtDW.UnitDelay_DSTATE_n[2] = rtDW.Integrator_DSTATE_h[2];
  }

  if (rtb_y_p[3] < -0.1) {
    rtDW.UnitDelay_DSTATE_n[3] = rtDW.Integrator_DSTATE_h[3];
  } else if (rtDW.UnitDelay2_4_DSTATE > rtDW.UnitDelay_DSTATE_n[3] * 0.75 - 0.1)
  {
    rtDW.UnitDelay_DSTATE_n[3]--;
    if (rtDW.UnitDelay_DSTATE_n[3] < -21.0) {
      rtDW.UnitDelay_DSTATE_n[3] = -21.0;
    }
  } else {
    rtDW.UnitDelay_DSTATE_n[3] = rtDW.Integrator_DSTATE_h[3];
  }

  /* Fcn: '<S33>/Avoid Divide by Zero' incorporates:
   *  Constant: '<S33>/Time constant'
   *  MinMax: '<S33>/Max'
   */
  rtb_AvoidDividebyZero = fmax(rtDW.Probe[0], 0.1);

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

  /* RelationalOperator: '<S26>/Equal' incorporates:
   *  Constant: '<S26>/Constant6'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  rtb_Equal_idx_0 = (rtDW.UnitDelay_DSTATE_n[0] == -21.0);

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
    rtb_UnitDelay_idx_0 = 0.0;
  } else {
    rtb_UnitDelay_idx_0 = -0.15 - rtb_Switch;
  }

  /* Gain: '<S65>/ZeroGain' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   */
  rtb_Filter_f = rtb_Filter_l_idx_1;

  /* RelationalOperator: '<S26>/Equal' incorporates:
   *  Constant: '<S26>/Constant6'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  rtb_Equal_idx_1 = (rtDW.UnitDelay_DSTATE_n[1] == -21.0);

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
    rtb_UnitDelay_idx_1 = 0.0;
  } else {
    rtb_UnitDelay_idx_1 = -0.15 - rtb_Switch_m;
  }

  /* Gain: '<S65>/ZeroGain' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   */
  rtb_Filter_f = rtb_Filter_l_idx_2;

  /* RelationalOperator: '<S26>/Equal' incorporates:
   *  Constant: '<S26>/Constant6'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  rtb_Equal_idx_2 = (rtDW.UnitDelay_DSTATE_n[2] == -21.0);

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
    rtb_UnitDelay_idx_2 = 0.0;
  } else {
    rtb_UnitDelay_idx_2 = -0.15 - rtb_RL;
  }

  /* Gain: '<S65>/ZeroGain' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   */
  rtb_Filter_f = rtb_Filter_l_idx_3;

  /* RelationalOperator: '<S26>/Equal' incorporates:
   *  Constant: '<S26>/Constant6'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  rtb_Equal_idx_3 = (rtDW.UnitDelay_DSTATE_n[3] == -21.0);

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
  rtb_y_p[0] = rtDW.UnitDelay3_1_DSTATE_f;
  rtb_y_p[1] = rtDW.UnitDelay3_2_DSTATE_b;
  rtb_y_p[2] = rtDW.UnitDelay3_3_DSTATE_k;
  rtb_y_p[3] = rtDW.UnitDelay3_4_DSTATE_o;

  /* MATLAB Function: '<S27>/MATLAB Function3' */
  rtb_y_p[0] *= 13.5;
  rtb_y_p[1] *= 13.5;
  rtb_y_p[2] *= 13.5;
  rtb_y_p[3] *= 13.5;

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
    0.055224999999999996) + 1.0) * 0.235 * (rtb_y_p[0] / 0.235 - (rtb_Sign -
    rtDW.UD_DSTATE_f[0]) * 0.235 * 0.2 / 0.055224999999999996) / 13.5;

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
    0.055224999999999996) + 1.0) * 0.235 * (rtb_y_p[1] / 0.235 -
    (rtb_Subtract_m4_tmp_0 - rtDW.UD_DSTATE_f[1]) * 0.235 * 0.2 /
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
    0.055224999999999996) + 1.0) * 0.235 * (rtb_y_p[2] / 0.235 -
    (rtb_Subtract_m4_tmp_1 - rtDW.UD_DSTATE_f[2]) * 0.235 * 0.2 /
    0.055224999999999996) / 13.5;

  /* Saturate: '<S146>/Saturation' */
  if (rtb_SignPreIntegrator_idx_3 > 2.0) {
    rtb_SignPreIntegrator_idx_3_0 = 2.0;
  } else if (rtb_SignPreIntegrator_idx_3 < 0.0) {
    rtb_SignPreIntegrator_idx_3_0 = 0.0;
  } else {
    rtb_SignPreIntegrator_idx_3_0 = rtb_SignPreIntegrator_idx_3;
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
  rtb_Integrator_iq_idx_3 = (0.2 / ((rtb_SignPreIntegrator_idx_3_0 + 0.1) * 67.5
    * 0.055224999999999996) + 1.0) * 0.235 * (rtb_y_p[3] / 0.235 -
    (rtb_Subtract_m4_tmp - rtDW.UD_DSTATE_f[3]) * 0.235 * 0.2 /
    0.055224999999999996) / 13.5;
  if (rtb_y_p[0] / 13.5 < 2.0) {
    rtb_Integrator_iq_idx_0 = 21.0;
  }

  if (rtb_y_p[1] / 13.5 < 2.0) {
    rtb_Integrator_iq_idx_1 = 21.0;
  }

  if (rtb_y_p[2] / 13.5 < 2.0) {
    rtb_Integrator_iq_idx_2 = 21.0;
  }

  if (rtb_y_p[3] / 13.5 < 2.0) {
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
  rtb_y_p[0] = rtb_Switch;
  rtb_y_p[1] = rtb_Switch_m;
  rtb_y_p[2] = rtb_RL;
  rtb_y_p[3] = rtb_RR;

  /* MATLAB Function: '<S27>/MATLAB Function2' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  SignalConversion generated from: '<S95>/ SFunction '
   *  UnitDelay: '<S27>/Unit Delay'
   *  UnitDelay generated from: '<S27>/Unit Delay2'
   */
  if (rtb_y_p[0] > 0.1) {
    rtDW.UnitDelay_DSTATE_g[0] = rtDW.Integrator_DSTATE_f3[0];
  } else if (rtDW.UnitDelay2_1_DSTATE_i < rtDW.UnitDelay_DSTATE_g[0] * 0.75 +
             0.1) {
    rtDW.UnitDelay_DSTATE_g[0]++;
    if (rtDW.UnitDelay_DSTATE_g[0] > 21.0) {
      rtDW.UnitDelay_DSTATE_g[0] = 21.0;
    }
  } else {
    rtDW.UnitDelay_DSTATE_g[0] = rtDW.Integrator_DSTATE_f3[0];
  }

  if (rtb_y_p[1] > 0.1) {
    rtDW.UnitDelay_DSTATE_g[1] = rtDW.Integrator_DSTATE_f3[1];
  } else if (rtDW.UnitDelay2_2_DSTATE_f < rtDW.UnitDelay_DSTATE_g[1] * 0.75 +
             0.1) {
    rtDW.UnitDelay_DSTATE_g[1]++;
    if (rtDW.UnitDelay_DSTATE_g[1] > 21.0) {
      rtDW.UnitDelay_DSTATE_g[1] = 21.0;
    }
  } else {
    rtDW.UnitDelay_DSTATE_g[1] = rtDW.Integrator_DSTATE_f3[1];
  }

  if (rtb_y_p[2] > 0.1) {
    rtDW.UnitDelay_DSTATE_g[2] = rtDW.Integrator_DSTATE_f3[2];
  } else if (rtDW.UnitDelay2_3_DSTATE_j < rtDW.UnitDelay_DSTATE_g[2] * 0.75 +
             0.1) {
    rtDW.UnitDelay_DSTATE_g[2]++;
    if (rtDW.UnitDelay_DSTATE_g[2] > 21.0) {
      rtDW.UnitDelay_DSTATE_g[2] = 21.0;
    }
  } else {
    rtDW.UnitDelay_DSTATE_g[2] = rtDW.Integrator_DSTATE_f3[2];
  }

  if (rtb_y_p[3] > 0.1) {
    rtDW.UnitDelay_DSTATE_g[3] = rtDW.Integrator_DSTATE_f3[3];
  } else if (rtDW.UnitDelay2_4_DSTATE_c < rtDW.UnitDelay_DSTATE_g[3] * 0.75 +
             0.1) {
    rtDW.UnitDelay_DSTATE_g[3]++;
    if (rtDW.UnitDelay_DSTATE_g[3] > 21.0) {
      rtDW.UnitDelay_DSTATE_g[3] = 21.0;
    }
  } else {
    rtDW.UnitDelay_DSTATE_g[3] = rtDW.Integrator_DSTATE_f3[3];
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

  /* RelationalOperator: '<S27>/Equal' incorporates:
   *  Constant: '<S27>/Constant6'
   *  UnitDelay: '<S27>/Unit Delay'
   */
  rtb_Equal_c_idx_0 = (rtDW.UnitDelay_DSTATE_g[0] == 21.0);

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
    rtb_UnitDelay_e_idx_1 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_UnitDelay_e_idx_1 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_UnitDelay_e_idx_1 = 0.0;
  } else {
    rtb_UnitDelay_e_idx_1 = (rtNaN);
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
       rtb_UnitDelay_e_idx_1 == (int8_T)rtb_Abs3)) {
    rtb_SignPreIntegrator_idx_3_0 = 0.0;
  } else {
    rtb_SignPreIntegrator_idx_3_0 = -(0.15 - rtb_Switch);
  }

  /* Sum: '<S94>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   */
  rtb_Integrator_iq_idx_0 -= rtDW.Integrator_DSTATE_f3[0];

  /* Gain: '<S130>/ZeroGain' incorporates:
   *  Signum: '<S130>/SignPreIntegrator'
   */
  rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_1;

  /* RelationalOperator: '<S27>/Equal' incorporates:
   *  Constant: '<S27>/Constant6'
   *  UnitDelay: '<S27>/Unit Delay'
   */
  rtb_Equal_c_idx_1 = (rtDW.UnitDelay_DSTATE_g[1] == 21.0);

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
    rtb_UnitDelay_e_idx_1 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_UnitDelay_e_idx_1 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_UnitDelay_e_idx_1 = 0.0;
  } else {
    rtb_UnitDelay_e_idx_1 = (rtNaN);
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
       rtb_UnitDelay_e_idx_1 == (int8_T)rtb_Abs3)) {
    rtb_ZeroGain_a = 0.0;
  } else {
    rtb_ZeroGain_a = -(0.15 - rtb_Switch_m);
  }

  /* Sum: '<S94>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   */
  rtb_Integrator_iq_idx_1 -= rtDW.Integrator_DSTATE_f3[1];

  /* Gain: '<S130>/ZeroGain' incorporates:
   *  Signum: '<S130>/SignPreIntegrator'
   */
  rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_2;

  /* RelationalOperator: '<S27>/Equal' incorporates:
   *  Constant: '<S27>/Constant6'
   *  UnitDelay: '<S27>/Unit Delay'
   */
  rtb_Equal_c_idx_2 = (rtDW.UnitDelay_DSTATE_g[2] == 21.0);

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
    rtb_UnitDelay_e_idx_1 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_UnitDelay_e_idx_1 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_UnitDelay_e_idx_1 = 0.0;
  } else {
    rtb_UnitDelay_e_idx_1 = (rtNaN);
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
       rtb_UnitDelay_e_idx_1 == (int8_T)rtb_Abs3)) {
    rtb_ZeroGain_o = 0.0;
  } else {
    rtb_ZeroGain_o = -(0.15 - rtb_RL);
  }

  /* Sum: '<S94>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   */
  rtb_Integrator_iq_idx_2 -= rtDW.Integrator_DSTATE_f3[2];

  /* Gain: '<S130>/ZeroGain' incorporates:
   *  Signum: '<S130>/SignPreIntegrator'
   */
  rtb_SignPreIntegrator = rtb_SignPreIntegrator_idx_3;

  /* RelationalOperator: '<S27>/Equal' incorporates:
   *  Constant: '<S27>/Constant6'
   *  UnitDelay: '<S27>/Unit Delay'
   */
  rtb_Equal_c_idx_3 = (rtDW.UnitDelay_DSTATE_g[3] == 21.0);

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
    rtb_UnitDelay_e_idx_1 = -1.0;
  } else if (rtb_SignPreIntegrator > 0.0) {
    rtb_UnitDelay_e_idx_1 = 1.0;
  } else if (rtb_SignPreIntegrator == 0.0) {
    rtb_UnitDelay_e_idx_1 = 0.0;
  } else {
    rtb_UnitDelay_e_idx_1 = (rtNaN);
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
       rtb_UnitDelay_e_idx_1 == (int8_T)rtb_Abs3)) {
    rtb_SignPreIntegrator = 0.0;
  } else {
    rtb_SignPreIntegrator = -(0.15 - rtb_RR);
  }

  /* Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_front_wheel_angle_single__p = look1_binlx(rtU.steering, rtConstP.pooled36,
    rtConstP.steering_to_wheel_angle_single_, 32U);

  /* Outputs for IfAction SubSystem: '<S159>/YRD_LUT_-3' incorporates:
   *  ActionPort: '<S222>/Action Port'
   */
  /* If: '<S159>/If' */
  YRD_LUT_3(rtb_front_wheel_angle_single__p, rtb_vx, &rtDW.yaw_rate_desired_LUT);

  /* End of Outputs for SubSystem: '<S159>/YRD_LUT_-3' */

  /* Outputs for IfAction SubSystem: '<S159>/YRD_LUT_-1' incorporates:
   *  ActionPort: '<S219>/Action Port'
   */
  /* If: '<S159>/If1' */
  YRD_LUT_3(rtb_front_wheel_angle_single__p, rtb_vx,
            &rtDW.yaw_rate_desired_LUT_d);

  /* End of Outputs for SubSystem: '<S159>/YRD_LUT_-1' */

  /* SignalConversion generated from: '<S171>/ SFunction ' incorporates:
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
  rtb_y_ref_0[2] = (1.0 - rtU.brake) * rtDW.yaw_rate_desired_LUT_d +
    rtDW.yaw_rate_desired_LUT * rtU.brake;
  memset(&rtb_y_ref_0[3], 0, sizeof(real_T) << 3U);

  /* MATLAB Function: '<S160>/MATLAB Function' */
  memcpy(&rtb_y_d[0], &rtb_y_ref_0[0], 11U * sizeof(real_T));

  /* RateTransition: '<S172>/Rate Transition3' incorporates:
   *  Constant: '<S161>/Constant'
   *  Gain: '<S161>/Gain'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = rtb_front_wheel_angle_single__p;
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
  RateTransition3[12] = rtb_Sum1_g;
  RateTransition3[13] = 13.5 * rtU.omega_wheels_FL;
  RateTransition3[14] = 13.5 * rtU.omega_wheels_FR;
  RateTransition3[15] = 13.5 * rtU.omega_wheels_RL;
  RateTransition3[16] = 13.5 * rtU.omega_wheels_RR;
  RateTransition3[17] = 0.8;

  /* CFunction: '<S172>/C Function' incorporates:
   *  Constant: '<S172>/Constant3'
   */
  for (rtb_mz_output = 0; rtb_mz_output < 3; rtb_mz_output++) {
    memcpy(&rtDW.CFunction[rtb_mz_output * 18], &RateTransition3[0], 18U *
           sizeof(real_T));
  }

  /* End of CFunction: '<S172>/C Function' */

  /* Memory: '<S158>/Memory' */
  rtb_Memory_idx_0 = rtDW.Memory_PreviousInput[0];
  rtb_Memory_idx_1 = rtDW.Memory_PreviousInput[1];

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
   *  Memory: '<S158>/Memory'
   */
  rtb_x[1] = rtU.vy;
  rtb_x[2] = rtb_Gain1;
  rtb_x[3] = rtb_Memory_idx_0;
  rtb_x[4] = rtb_Memory_idx_1;
  rtb_x[5] = rtDW.Memory_PreviousInput[2];
  rtb_x[6] = rtDW.Memory_PreviousInput[3];

  /* RelationalOperator: '<S235>/Compare' incorporates:
   *  Constant: '<S232>/Time constant'
   *  Constant: '<S235>/Constant'
   *  Sum: '<S232>/Sum1'
   */
  rtb_Compare_g = (0.079577471545947673 - rtDW.Probe_kx[0] <= 0.0);

  /* Gain: '<S229>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   */
  u0 = 128.91550390443524 * rtU.omega_wheels_FL;

  /* Saturate: '<S229>/Saturation1' */
  if (u0 <= 0.0) {
    rtb_y_p[0] = 0.0;
  } else {
    rtb_y_p[0] = u0;
  }

  /* Gain: '<S229>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_FR'
   */
  u0 = 128.91550390443524 * rtU.omega_wheels_FR;

  /* Saturate: '<S229>/Saturation1' */
  if (u0 <= 0.0) {
    rtb_y_p[1] = 0.0;
  } else {
    rtb_y_p[1] = u0;
  }

  /* Gain: '<S229>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_RL'
   */
  u0 = 128.91550390443524 * rtU.omega_wheels_RL;

  /* Saturate: '<S229>/Saturation1' */
  if (u0 <= 0.0) {
    rtb_y_p[2] = 0.0;
  } else {
    rtb_y_p[2] = u0;
  }

  /* Gain: '<S229>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0 = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S229>/Saturation1' */
  if (u0 <= 0.0) {
    rtb_y_p[3] = 0.0;
  } else {
    rtb_y_p[3] = u0;
  }

  /* Lookup_n-D: '<S229>/2-D Lookup Table' incorporates:
   *  Constant: '<S227>/Constant7'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled48, 45U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions[1U] = rtb_UnaryMinus_ot_idx_0;
  bpIndices[0U] = plook_binc(rtb_y_p[0], rtConstP.pooled47, 200U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions[0U] = rtb_UnaryMinus_ot_idx_0;
  rtb_y_p[0] = intrp2d_l(bpIndices, fractions, rtConstP.pooled46, 201U);
  bpIndices[0U] = plook_binc(rtb_y_p[1], rtConstP.pooled47, 200U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions[0U] = rtb_UnaryMinus_ot_idx_0;
  rtb_y_p[1] = intrp2d_l(bpIndices, fractions, rtConstP.pooled46, 201U);
  bpIndices[0U] = plook_binc(rtb_y_p[2], rtConstP.pooled47, 200U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions[0U] = rtb_UnaryMinus_ot_idx_0;
  rtb_y_p[2] = intrp2d_l(bpIndices, fractions, rtConstP.pooled46, 201U);
  bpIndices[0U] = plook_binc(rtb_y_p[3], rtConstP.pooled47, 200U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions[0U] = rtb_UnaryMinus_ot_idx_0;
  rtb_y_p[3] = intrp2d_l(bpIndices, fractions, rtConstP.pooled46, 201U);

  /* Gain: '<S229>/Gain' */
  rtb_SignPreIntegrator_idx_0 = 0.0098000000000000014 * rtb_y_p[0];
  rtb_SignPreIntegrator_idx_1 = 0.0098000000000000014 * rtb_y_p[1];
  rtb_SignPreIntegrator_idx_2 = 0.0098000000000000014 * rtb_y_p[2];
  rtb_SignPreIntegrator_idx_3 = 0.0098000000000000014 * rtb_y_p[3];

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

  rtb_Gain1 = rtDW.Integrator_DSTATE_j[0];

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
  rtb_lg_saturation = look1_binlx(0.0, rtConstP.pooled43, rtConstP.pooled42, 2U);

  /* MinMax: '<S227>/Min' incorporates:
   *  Lookup_n-D: '<S227>/Max_Torque_Overload_Motor_LUT'
   *  MinMax: '<S228>/Min1'
   */
  rtb_lg_saturation = fmin(fmin(rtb_lg_saturation, rtb_lg_saturation), 20.972);
  rtb_max_torque_overload_inverte[0] = fmin(rtb_lg_saturation, rtb_Abs3);

  /* DiscreteIntegrator: '<S237>/Integrator' */
  rtb_UnitDelay_e_idx_1 = rtDW.Integrator_DSTATE_j[1];

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

  rtb_max_torque_overload_inverte[1] = fmin(rtb_lg_saturation, rtb_Abs3);

  /* DiscreteIntegrator: '<S237>/Integrator' */
  rtb_UnitDelay_e_idx_2 = rtDW.Integrator_DSTATE_j[2];

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

  rtb_max_torque_overload_inverte[2] = fmin(rtb_lg_saturation, rtb_Abs3);

  /* DiscreteIntegrator: '<S237>/Integrator' */
  rtb_UnitDelay_e_idx_3 = rtDW.Integrator_DSTATE_j[3];

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

  rtb_max_torque_overload_inverte[3] = fmin(rtb_lg_saturation, rtb_Abs3);

  /* SignalConversion generated from: '<S209>/2-D Lookup Table' */
  rtb_y_p[0] = rtb_Subtract_e5;
  rtb_y_p[1] = rtb_Subtract_o;
  rtb_y_p[2] = rtb_Subtract_m;
  rtb_y_p[3] = rtb_Sum1_g;

  /* Lookup_n-D: '<S209>/2-D Lookup Table' */
  rtb_Abs3 = rtb_y_m[0];
  rtb_UnaryMinus_ot_idx_0 = look2_binlx(rtb_y_p[0], rtb_Abs3, rtConstP.pooled50,
    rtConstP.pooled51, rtConstP.uDLookupTable_tableData, rtConstP.pooled58, 30U);
  rtb_Abs3 = rtb_y_m[1];
  rtb_Subtract_o = look2_binlx(rtb_y_p[1], rtb_Abs3, rtConstP.pooled50,
    rtConstP.pooled51, rtConstP.uDLookupTable_tableData, rtConstP.pooled58, 30U);
  rtb_Abs3 = rtb_y_m[2];
  rtb_Subtract_m = look2_binlx(rtb_y_p[2], rtb_Abs3, rtConstP.pooled50,
    rtConstP.pooled51, rtConstP.uDLookupTable_tableData, rtConstP.pooled58, 30U);
  rtb_Abs3 = rtb_y_m[3];
  rtb_Sum1_g = look2_binlx(rtb_y_p[3], rtb_Abs3, rtConstP.pooled50,
    rtConstP.pooled51, rtConstP.uDLookupTable_tableData, rtConstP.pooled58, 30U);

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

  /* Switch: '<S204>/Switch' */
  rtb_Abs3 = !(rtb_Subtract_e5 > 0.95);

  /* Saturate: '<S209>/Saturation1' incorporates:
   *  Gain: '<S209>/Gain'
   *  Product: '<S209>/Product'
   */
  u0 = 0.017407407407407406 * rtb_UnaryMinus_ot_idx_0 * 1000.0;

  /* Saturate: '<S227>/Saturation_Positive' */
  if (rtb_max_torque_overload_inverte[0] <= 0.0) {
    rtb_UnaryMinus_ot_idx_0 = 0.0;
  } else {
    rtb_UnaryMinus_ot_idx_0 = rtb_max_torque_overload_inverte[0];
  }

  /* Saturate: '<S209>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S204>/Product' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  MinMax: '<S169>/Min'
   *  Saturate: '<S227>/Saturation_Positive'
   */
  rtb_Product[0] = fmin(fmin(rtb_UnaryMinus_ot_idx_0, rtDW.Integrator_DSTATE_f3
    [0]), u0) * rtb_Abs3;

  /* Saturate: '<S209>/Saturation1' incorporates:
   *  Gain: '<S209>/Gain'
   *  Product: '<S209>/Product'
   */
  u0 = 0.017407407407407406 * rtb_Subtract_o * 1000.0;

  /* Saturate: '<S227>/Saturation_Positive' */
  if (rtb_max_torque_overload_inverte[1] <= 0.0) {
    rtb_UnaryMinus_ot_idx_0 = 0.0;
  } else {
    rtb_UnaryMinus_ot_idx_0 = rtb_max_torque_overload_inverte[1];
  }

  /* Saturate: '<S209>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S204>/Product' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  MinMax: '<S169>/Min'
   *  Saturate: '<S227>/Saturation_Positive'
   */
  rtb_Product[1] = fmin(fmin(rtb_UnaryMinus_ot_idx_0, rtDW.Integrator_DSTATE_f3
    [1]), u0) * rtb_Abs3;

  /* Saturate: '<S209>/Saturation1' incorporates:
   *  Gain: '<S209>/Gain'
   *  Product: '<S209>/Product'
   */
  u0 = 0.017407407407407406 * rtb_Subtract_m * 1000.0;

  /* Saturate: '<S227>/Saturation_Positive' */
  if (rtb_max_torque_overload_inverte[2] <= 0.0) {
    rtb_UnaryMinus_ot_idx_0 = 0.0;
  } else {
    rtb_UnaryMinus_ot_idx_0 = rtb_max_torque_overload_inverte[2];
  }

  /* Saturate: '<S209>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S204>/Product' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  MinMax: '<S169>/Min'
   *  Saturate: '<S227>/Saturation_Positive'
   */
  rtb_Product[2] = fmin(fmin(rtb_UnaryMinus_ot_idx_0, rtDW.Integrator_DSTATE_f3
    [2]), u0) * rtb_Abs3;

  /* Saturate: '<S209>/Saturation1' incorporates:
   *  Gain: '<S209>/Gain'
   *  Product: '<S209>/Product'
   */
  u0 = 0.017407407407407406 * rtb_Sum1_g * 1000.0;

  /* Saturate: '<S227>/Saturation_Positive' */
  if (rtb_max_torque_overload_inverte[3] <= 0.0) {
    rtb_UnaryMinus_ot_idx_0 = 0.0;
  } else {
    rtb_UnaryMinus_ot_idx_0 = rtb_max_torque_overload_inverte[3];
  }

  /* Saturate: '<S209>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S204>/Product' incorporates:
   *  DiscreteIntegrator: '<S103>/Integrator'
   *  MinMax: '<S169>/Min'
   *  Saturate: '<S227>/Saturation_Positive'
   */
  rtb_Product[3] = fmin(fmin(rtb_UnaryMinus_ot_idx_0, rtDW.Integrator_DSTATE_f3
    [3]), u0) * rtb_Abs3;

  /* Lookup_n-D: '<S209>/2-D Lookup Table1' */
  rtb_Abs3 = rtb_y_m[0];
  rtb_y_p[0] = look2_binlx(rtb_y_p[0], rtb_Abs3, rtConstP.pooled50,
    rtConstP.pooled51, rtConstP.uDLookupTable1_tableData, rtConstP.pooled58, 30U);
  rtb_Abs3 = rtb_y_m[1];
  rtb_y_p[1] = look2_binlx(rtb_y_p[1], rtb_Abs3, rtConstP.pooled50,
    rtConstP.pooled51, rtConstP.uDLookupTable1_tableData, rtConstP.pooled58, 30U);
  rtb_Abs3 = rtb_y_m[2];
  rtb_y_p[2] = look2_binlx(rtb_y_p[2], rtb_Abs3, rtConstP.pooled50,
    rtConstP.pooled51, rtConstP.uDLookupTable1_tableData, rtConstP.pooled58, 30U);
  rtb_Abs3 = rtb_y_m[3];
  rtb_y_p[3] = look2_binlx(rtb_y_p[3], rtb_Abs3, rtConstP.pooled50,
    rtConstP.pooled51, rtConstP.uDLookupTable1_tableData, rtConstP.pooled58, 30U);

  /* RelationalOperator: '<S244>/Compare' incorporates:
   *  Constant: '<S241>/Time constant'
   *  Constant: '<S244>/Constant'
   *  Sum: '<S241>/Sum1'
   */
  rtb_Compare_d = (0.079577471545947673 - rtDW.Probe_b[0] <= 0.0);

  /* Gain: '<S238>/Gain4' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_y_m[0] = 128.91550390443524 * rtU.omega_wheels_FL;
  rtb_y_m[1] = 128.91550390443524 * rtU.omega_wheels_FR;
  rtb_y_m[2] = 128.91550390443524 * rtU.omega_wheels_RL;
  rtb_y_m[3] = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S238>/Saturation1' */
  u0 = rtb_y_m[0];
  if (u0 <= 0.0) {
    rtb_y_m[0] = 0.0;
  } else {
    rtb_y_m[0] = u0;
  }

  u0 = rtb_y_m[1];
  if (u0 <= 0.0) {
    rtb_y_m[1] = 0.0;
  } else {
    rtb_y_m[1] = u0;
  }

  u0 = rtb_y_m[2];
  if (u0 <= 0.0) {
    rtb_y_m[2] = 0.0;
  } else {
    rtb_y_m[2] = u0;
  }

  u0 = rtb_y_m[3];
  if (u0 <= 0.0) {
    rtb_y_m[3] = 0.0;
  } else {
    rtb_y_m[3] = u0;
  }

  /* End of Saturate: '<S238>/Saturation1' */

  /* Lookup_n-D: '<S238>/2-D Lookup Table' incorporates:
   *  Constant: '<S228>/Constant7'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled48, 45U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions_0[1U] = rtb_UnaryMinus_ot_idx_0;
  rtb_Abs3 = rtb_y_m[0];
  bpIndices_0[0U] = plook_binc(rtb_Abs3, rtConstP.pooled47, 200U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions_0[0U] = rtb_UnaryMinus_ot_idx_0;
  rtb_y_m[0] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled46, 201U);
  rtb_Abs3 = rtb_y_m[1];
  bpIndices_0[0U] = plook_binc(rtb_Abs3, rtConstP.pooled47, 200U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions_0[0U] = rtb_UnaryMinus_ot_idx_0;
  rtb_y_m[1] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled46, 201U);
  rtb_Abs3 = rtb_y_m[2];
  bpIndices_0[0U] = plook_binc(rtb_Abs3, rtConstP.pooled47, 200U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions_0[0U] = rtb_UnaryMinus_ot_idx_0;
  rtb_y_m[2] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled46, 201U);
  rtb_Abs3 = rtb_y_m[3];
  bpIndices_0[0U] = plook_binc(rtb_Abs3, rtConstP.pooled47, 200U,
    &rtb_UnaryMinus_ot_idx_0);
  fractions_0[0U] = rtb_UnaryMinus_ot_idx_0;
  rtb_y_m[3] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled46, 201U);

  /* Gain: '<S238>/Gain' */
  rtb_Subtract_o = 0.0098000000000000014 * rtb_y_m[0];
  rtb_Subtract_m = 0.0098000000000000014 * rtb_y_m[1];
  rtb_Sum1_g = 0.0098000000000000014 * rtb_y_m[2];
  rtb_UnaryMinus_ot_idx_0 = 0.0098000000000000014 * rtb_y_m[3];

  /* DiscreteIntegrator: '<S246>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_b != 0) {
    rtDW.Integrator_DSTATE_ff[0] = rtb_Subtract_o;
    rtDW.Integrator_DSTATE_ff[1] = rtb_Subtract_m;
    rtDW.Integrator_DSTATE_ff[2] = rtb_Sum1_g;
    rtDW.Integrator_DSTATE_ff[3] = rtb_UnaryMinus_ot_idx_0;
  }

  if (rtb_Compare_d || (rtDW.Integrator_PrevResetState_f != 0)) {
    rtDW.Integrator_DSTATE_ff[0] = rtb_Subtract_o;
    rtDW.Integrator_DSTATE_ff[1] = rtb_Subtract_m;
    rtDW.Integrator_DSTATE_ff[2] = rtb_Sum1_g;
    rtDW.Integrator_DSTATE_ff[3] = rtb_UnaryMinus_ot_idx_0;
  }

  rtb_Integrator_d_idx_0 = rtDW.Integrator_DSTATE_ff[0];
  rtb_Integrator_d_idx_1 = rtDW.Integrator_DSTATE_ff[1];
  rtb_Integrator_d_idx_2 = rtDW.Integrator_DSTATE_ff[2];
  rtb_Integrator_d_idx_3 = rtDW.Integrator_DSTATE_ff[3];

  /* Switch: '<S240>/Switch' incorporates:
   *  Constant: '<S238>/Constant'
   *  DiscreteIntegrator: '<S246>/Integrator'
   *  RelationalOperator: '<S240>/UpperRelop'
   */
  if (rtDW.Integrator_DSTATE_ff[0] < 0.0) {
    rtb_y_m[0] = 0.0;
  } else {
    rtb_y_m[0] = rtDW.Integrator_DSTATE_ff[0];
  }

  if (rtDW.Integrator_DSTATE_ff[1] < 0.0) {
    rtb_y_m[1] = 0.0;
  } else {
    rtb_y_m[1] = rtDW.Integrator_DSTATE_ff[1];
  }

  if (rtDW.Integrator_DSTATE_ff[2] < 0.0) {
    rtb_y_m[2] = 0.0;
  } else {
    rtb_y_m[2] = rtDW.Integrator_DSTATE_ff[2];
  }

  if (rtDW.Integrator_DSTATE_ff[3] < 0.0) {
    rtb_y_m[3] = 0.0;
  } else {
    rtb_y_m[3] = rtDW.Integrator_DSTATE_ff[3];
  }

  /* End of Switch: '<S240>/Switch' */

  /* Switch: '<S240>/Switch2' incorporates:
   *  DiscreteIntegrator: '<S246>/Integrator'
   *  RelationalOperator: '<S240>/LowerRelop1'
   */
  if (rtDW.Integrator_DSTATE_ff[0] > 21.0) {
    rtb_y_m[0] = 21.0;
  }

  if (rtDW.Integrator_DSTATE_ff[1] > 21.0) {
    rtb_y_m[1] = 21.0;
  }

  if (rtDW.Integrator_DSTATE_ff[2] > 21.0) {
    rtb_y_m[2] = 21.0;
  }

  if (rtDW.Integrator_DSTATE_ff[3] > 21.0) {
    rtb_y_m[3] = 21.0;
  }

  /* End of Switch: '<S240>/Switch2' */

  /* MinMax: '<S228>/Min1' */
  rtb_y_m[0] = fmin(rtb_lg_saturation, rtb_y_m[0]);
  rtb_y_m[1] = fmin(rtb_lg_saturation, rtb_y_m[1]);
  rtb_y_m[2] = fmin(rtb_lg_saturation, rtb_y_m[2]);
  rtb_y_m[3] = fmin(rtb_lg_saturation, rtb_y_m[3]);

  /* Saturate: '<S209>/Saturation' incorporates:
   *  Gain: '<S209>/Gain1'
   *  Gain: '<S215>/Wheel2Motor'
   *  Product: '<S209>/Product1'
   *  Sum: '<S215>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.017407407407407406 * rtb_y_p[0] * 1000.0 + 0.07407407407407407 *
    rtDW.UnitDelay_DSTATE[0];

  /* MinMax: '<S228>/Min1' incorporates:
   *  Product: '<S209>/Product1'
   */
  rtb_Abs3 = fmin(rtb_y_m[0], 21.0);

  /* Saturate: '<S209>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S228>/Saturation_Positive' */
  if (rtb_Abs3 <= 0.0) {
    rtb_Abs3 = 0.0;
  }

  /* MinMax: '<S169>/Min1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Product: '<S209>/Product1'
   *  UnaryMinus: '<S169>/Unary Minus'
   */
  rtb_y_p[0] = fmax(fmax(u0, -rtb_Abs3), rtDW.Integrator_DSTATE_h[0]);

  /* Saturate: '<S209>/Saturation' incorporates:
   *  Gain: '<S209>/Gain1'
   *  Gain: '<S215>/Wheel2Motor'
   *  Product: '<S209>/Product1'
   *  Sum: '<S215>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.017407407407407406 * rtb_y_p[1] * 1000.0 + 0.07407407407407407 *
    rtDW.UnitDelay_DSTATE[1];

  /* MinMax: '<S228>/Min1' incorporates:
   *  Product: '<S209>/Product1'
   */
  rtb_Abs3 = fmin(rtb_y_m[1], 21.0);

  /* Saturate: '<S209>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S228>/Saturation_Positive' */
  if (rtb_Abs3 <= 0.0) {
    rtb_Abs3 = 0.0;
  }

  /* MinMax: '<S169>/Min1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Product: '<S209>/Product1'
   *  UnaryMinus: '<S169>/Unary Minus'
   */
  rtb_y_p[1] = fmax(fmax(u0, -rtb_Abs3), rtDW.Integrator_DSTATE_h[1]);

  /* Saturate: '<S209>/Saturation' incorporates:
   *  Gain: '<S209>/Gain1'
   *  Gain: '<S215>/Wheel2Motor'
   *  Product: '<S209>/Product1'
   *  Sum: '<S215>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.017407407407407406 * rtb_y_p[2] * 1000.0 + 0.07407407407407407 *
    rtDW.UnitDelay_DSTATE[2];

  /* MinMax: '<S228>/Min1' incorporates:
   *  Product: '<S209>/Product1'
   */
  rtb_Abs3 = fmin(rtb_y_m[2], 21.0);

  /* Saturate: '<S209>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S228>/Saturation_Positive' */
  if (rtb_Abs3 <= 0.0) {
    rtb_Abs3 = 0.0;
  }

  /* MinMax: '<S169>/Min1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Product: '<S209>/Product1'
   *  UnaryMinus: '<S169>/Unary Minus'
   */
  rtb_y_p[2] = fmax(fmax(u0, -rtb_Abs3), rtDW.Integrator_DSTATE_h[2]);

  /* Saturate: '<S209>/Saturation' incorporates:
   *  Gain: '<S209>/Gain1'
   *  Gain: '<S215>/Wheel2Motor'
   *  Product: '<S209>/Product1'
   *  Sum: '<S215>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.017407407407407406 * rtb_y_p[3] * 1000.0 + 0.07407407407407407 *
    rtDW.UnitDelay_DSTATE[3];

  /* MinMax: '<S228>/Min1' incorporates:
   *  Product: '<S209>/Product1'
   */
  rtb_Abs3 = fmin(rtb_y_m[3], 21.0);

  /* Saturate: '<S209>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S228>/Saturation_Positive' */
  if (rtb_Abs3 <= 0.0) {
    rtb_Abs3 = 0.0;
  }

  /* MinMax: '<S169>/Min1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Product: '<S209>/Product1'
   *  UnaryMinus: '<S169>/Unary Minus'
   */
  rtb_y_p[3] = fmax(fmax(u0, -rtb_Abs3), rtDW.Integrator_DSTATE_h[3]);

  /* CombinatorialLogic: '<S211>/Logic' incorporates:
   *  Constant: '<S203>/Constant'
   *  Constant: '<S203>/Constant1'
   *  Memory: '<S211>/Memory'
   *  RelationalOperator: '<S203>/Less Than'
   *  RelationalOperator: '<S203>/Less Than1'
   */
  rtb_mz_output = (int32_T)(((((uint32_T)(rtb_Switch <= -0.6) << 1) +
    (rtb_Switch >= -0.3)) << 1) + rtDW.bitsForTID0.Memory_PreviousInput_n);
  rtb_Logic_idx_0 = rtConstP.pooled61[(uint32_T)rtb_mz_output];

  /* CombinatorialLogic: '<S212>/Logic' incorporates:
   *  Constant: '<S203>/Constant'
   *  Constant: '<S203>/Constant1'
   *  Memory: '<S212>/Memory'
   *  RelationalOperator: '<S203>/Less Than'
   *  RelationalOperator: '<S203>/Less Than1'
   */
  ibcol = (int32_T)(((((uint32_T)(rtb_Switch_m <= -0.6) << 1) + (rtb_Switch_m >=
    -0.3)) << 1) + rtDW.bitsForTID0.Memory_PreviousInput_i);
  rtb_Logic_e_idx_0 = rtConstP.pooled61[(uint32_T)ibcol];

  /* CombinatorialLogic: '<S213>/Logic' incorporates:
   *  Constant: '<S203>/Constant'
   *  Constant: '<S203>/Constant1'
   *  Memory: '<S213>/Memory'
   *  RelationalOperator: '<S203>/Less Than'
   *  RelationalOperator: '<S203>/Less Than1'
   */
  rowIdx = (int32_T)(((((uint32_T)(rtb_RL <= -0.6) << 1) + (rtb_RL >= -0.3)) <<
                      1) + rtDW.bitsForTID0.Memory_PreviousInput_h);
  rtb_Logic_l_idx_0 = rtConstP.pooled61[(uint32_T)rowIdx];

  /* CombinatorialLogic: '<S214>/Logic' incorporates:
   *  Constant: '<S203>/Constant'
   *  Constant: '<S203>/Constant1'
   *  Memory: '<S214>/Memory'
   *  RelationalOperator: '<S203>/Less Than'
   *  RelationalOperator: '<S203>/Less Than1'
   */
  rowIdx_0 = (int32_T)(((((uint32_T)(rtb_RR <= -0.6) << 1) + (rtb_RR >= -0.3)) <<
                        1) + rtDW.bitsForTID0.Memory_PreviousInput_d);
  rtb_Logic_k_idx_0 = rtConstP.pooled61[(uint32_T)rowIdx_0];

  /* Product: '<S203>/Product' incorporates:
   *  CombinatorialLogic: '<S211>/Logic'
   *  CombinatorialLogic: '<S212>/Logic'
   *  CombinatorialLogic: '<S213>/Logic'
   *  CombinatorialLogic: '<S214>/Logic'
   */
  rtb_y_m[0] = (real_T)rtConstP.pooled61[rtb_mz_output + 8U] * rtb_y_p[0];
  rtb_y_m[1] = (real_T)rtConstP.pooled61[ibcol + 8U] * rtb_y_p[1];
  rtb_y_m[2] = (real_T)rtConstP.pooled61[rowIdx + 8U] * rtb_y_p[2];
  rtb_y_m[3] = (real_T)rtConstP.pooled61[rowIdx_0 + 8U] * rtb_y_p[3];

  /* Abs: '<S190>/Abs' */
  rtb_Abs3 = fabs(rtb_front_wheel_angle_single__p);

  /* CombinatorialLogic: '<S191>/Logic' incorporates:
   *  Constant: '<S190>/Constant1'
   *  Constant: '<S190>/Constant4'
   *  Memory: '<S191>/Memory'
   *  RelationalOperator: '<S190>/Less Than'
   *  RelationalOperator: '<S190>/Less Than2'
   */
  rtb_Logic_b_idx_0 = rtConstP.pooled61[((((uint32_T)(0.034906585039886591 <=
    rtb_Abs3) << 1) + (rtb_Abs3 < 0.0087266462599716477)) << 1) +
    rtDW.bitsForTID0.Memory_PreviousInput_e];

  /* SignalConversion generated from: '<S205>/ SFunction ' incorporates:
   *  MATLAB Function: '<S169>/Cross Check'
   */
  rtb_Switch = rtb_y_m[1];

  /* MATLAB Function: '<S169>/Cross Check' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/throttle'
   *  SignalConversion generated from: '<S205>/ SFunction '
   */
  rtb_max_torque_overload_inverte[0] = rtb_y_m[0];
  rtb_max_torque_overload_inverte[1] = rtb_y_m[1];
  rtb_max_torque_overload_inverte[2] = rtb_y_m[2];
  rtb_max_torque_overload_inverte[3] = rtb_y_m[3];
  if (rtb_Logic_b_idx_0) {
    rtb_mz_output = 0;
  } else {
    rtb_mz_output = 1;
  }

  if (rtb_mz_output == 0) {
    if (rtb_y_m[0] > rtb_Product[0]) {
      rtb_max_torque_overload_inverte[0] = rtb_Product[0] - rtb_Switch;
    }

    if (rtb_y_m[1] > rtb_Product[1]) {
      rtb_max_torque_overload_inverte[1] = rtb_Product[1] - rtb_Switch;
    }

    if (rtb_y_m[2] > rtb_Product[2]) {
      rtb_max_torque_overload_inverte[2] = rtb_Product[2] - rtb_Switch;
    }

    if (rtb_y_m[3] > rtb_Product[3]) {
      rtb_max_torque_overload_inverte[3] = rtb_Product[3] - rtb_Switch;
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

  /* MATLAB Function: '<S169>/MATLAB Function1' */
  MATLABFunction(rtb_max_torque_overload_inverte, rtb_y_m);

  /* MATLAB Function: '<S169>/MATLAB Function' */
  MATLABFunction(rtb_Product, rtb_y_p);

  /* MATLAB Function: '<S163>/MATLAB Function1' incorporates:
   *  Constant: '<S163>/Constant'
   */
  for (rtb_mz_output = 0; rtb_mz_output < 2; rtb_mz_output++) {
    ibcol = rtb_mz_output << 2;
    rtb_y_b[ibcol] = 100000.0;
    rtb_y_b[ibcol + 1] = 100000.0;
    rtb_y_b[ibcol + 2] = 100000.0;
    rtb_y_b[ibcol + 3] = 100000.0;
  }

  /* End of MATLAB Function: '<S163>/MATLAB Function1' */

  /* UnaryMinus: '<S163>/Unary Minus' */
  for (rtb_mz_output = 0; rtb_mz_output < 8; rtb_mz_output++) {
    rtb_UnaryMinus_ci[rtb_mz_output] = -rtb_y_b[rtb_mz_output];
  }

  /* End of UnaryMinus: '<S163>/Unary Minus' */

  /* Outputs for IfAction SubSystem: '<S164>/Simple torque' incorporates:
   *  ActionPort: '<S176>/Action Port'
   */
  /* If: '<S164>/If' incorporates:
   *  MATLAB Function: '<S192>/MATLAB Function4'
   *  MinMax: '<S182>/Min'
   *  MinMax: '<S182>/Min1'
   */
  rtb_Switch = fmin(rtb_Product[0], rtb_Product[1]);
  rtb_Switch_m = fmin(rtb_Product[2], rtb_Product[3]);

  /* End of Outputs for SubSystem: '<S164>/Simple torque' */

  /* MATLAB Function: '<S192>/MATLAB Function4' */
  rtb_Abs3 = (rtb_Switch + rtb_Switch_m) * 2.0;

  /* Product: '<S192>/Product' incorporates:
   *  Constant: '<S192>/Constant1'
   *  Constant: '<S192>/Constant2'
   *  Constant: '<S198>/Constant'
   *  Constant: '<S198>/Exponent < 0'
   *  Gain: '<S192>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S192>/ '
   *  Math: '<S198>/Power'
   *  Product: '<S192>/Product1'
   *  Product: '<S198>/Divide'
   *  Product: '<S198>/Divide1'
   *  RelationalOperator: '<S192>/Less Than'
   *  RelationalOperator: '<S192>/Less Than1'
   *  Sum: '<S192>/Subtract1'
   *  Sum: '<S198>/Subtract'
   *  Sum: '<S198>/Sum'
   */
  rtb_front_wheel_angle_single__p = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 -
    rtU.throttle), -1.5) + 1.0) - rtb_Subtract_e5) * (real_T)(boolean_T)
    ((rtb_Subtract_e5 >= 0.05) ^ (rtU.throttle >= 0.05)) * 84.0;

  /* Outputs for IfAction SubSystem: '<S164>/Simple torque' incorporates:
   *  ActionPort: '<S176>/Action Port'
   */
  /* If: '<S164>/If' incorporates:
   *  MATLAB Function: '<S192>/MATLAB Function3'
   *  MinMax: '<S182>/Min2'
   *  MinMax: '<S182>/Min3'
   */
  rtb_RR = fmax(rtb_max_torque_overload_inverte[0],
                rtb_max_torque_overload_inverte[1]);
  rtb_RL = fmax(rtb_max_torque_overload_inverte[2],
                rtb_max_torque_overload_inverte[3]);

  /* End of Outputs for SubSystem: '<S164>/Simple torque' */

  /* MATLAB Function: '<S192>/MATLAB Function3' */
  rtb_lg_saturation = (rtb_RR + rtb_RL) * 2.0;

  /* Switch: '<S201>/Switch2' incorporates:
   *  RelationalOperator: '<S201>/LowerRelop1'
   *  RelationalOperator: '<S201>/UpperRelop'
   *  Switch: '<S201>/Switch'
   */
  if (rtb_front_wheel_angle_single__p > rtb_Abs3) {
    rtb_front_wheel_angle_single__p = rtb_Abs3;
  } else if (rtb_front_wheel_angle_single__p < rtb_lg_saturation) {
    /* Switch: '<S201>/Switch' */
    rtb_front_wheel_angle_single__p = rtb_lg_saturation;
  }

  /* End of Switch: '<S201>/Switch2' */

  /* Gain: '<S192>/Gain2' */
  rtb_lg_saturation = 0.99 * rtb_front_wheel_angle_single__p;

  /* UnaryMinus: '<S194>/Unary Minus1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Saturate: '<S194>/Max Regen'
   */
  rtb_Abs3 = -0.0;

  /* InitialCondition: '<S194>/IC' */
  if (rtDW.bitsForTID0.IC_FirstOutputTime) {
    rtDW.bitsForTID0.IC_FirstOutputTime = false;
    rtb_Abs3 = -35000.0;
  }

  /* End of InitialCondition: '<S194>/IC' */

  /* MATLAB Function: '<S165>/MATLAB Function4' incorporates:
   *  MATLAB Function: '<S165>/MATLAB Function3'
   */
  rtb_Abs_idx_0 = 0.765 * sin(rtb_Abs_idx_0) - 0.635 * cos(rtb_Abs_idx_0);
  u0 = 0.765 * sin(rtb_Mzlim) + 0.635 * cos(rtb_Mzlim);
  rtb_Mzlim = ((rtb_Abs_idx_0 * rtb_max_torque_overload_inverte[0] + u0 *
                rtb_Product[1]) - 0.635 * rtb_max_torque_overload_inverte[2]) +
    0.635 * rtb_Product[3];

  /* Product: '<S165>/Product1' incorporates:
   *  Constant: '<S165>/Constant2'
   */
  rtb_mz_output = 50 * rtb_Logic_b_idx_0;

  /* MATLAB Function: '<S165>/MATLAB Function3' */
  rtb_Abs_idx_0 = ((rtb_Abs_idx_0 * rtb_Product[0] + u0 *
                    rtb_max_torque_overload_inverte[1]) - 0.635 * rtb_Product[2])
    + 0.635 * rtb_max_torque_overload_inverte[3];

  /* Switch: '<S189>/Switch2' incorporates:
   *  RelationalOperator: '<S189>/LowerRelop1'
   *  RelationalOperator: '<S189>/UpperRelop'
   *  Switch: '<S189>/Switch'
   */
  if (rtb_mz_output > rtb_Mzlim) {
    rtb_Abs_idx_0 = rtb_Mzlim;
  } else if (!(rtb_mz_output < rtb_Abs_idx_0)) {
    rtb_Abs_idx_0 = rtb_mz_output;
  }

  /* End of Switch: '<S189>/Switch2' */

  /* MATLAB Function: '<S165>/MATLAB Function' */
  if (!rtb_Logic_b_idx_0) {
    rtb_Mzlim = -0.1;
    rtb_Abs_idx_0 = 0.1;
  } else {
    rtb_Mzlim = -rtb_Abs_idx_0;
  }

  /* End of MATLAB Function: '<S165>/MATLAB Function' */

  /* Abs: '<S197>/Abs1' incorporates:
   *  Abs: '<S196>/Abs1'
   */
  rtb_Memory_idx_1 = fabs(rtb_Memory_idx_1);

  /* Abs: '<S197>/Abs3' incorporates:
   *  Abs: '<S196>/Abs3'
   */
  rtb_Memory_idx_0 = fabs(rtb_Memory_idx_0);

  /* Switch: '<S193>/Switch2' incorporates:
   *  Constant: '<S202>/Constant1'
   *  Constant: '<S202>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S202>/AND'
   *  RelationalOperator: '<S202>/Less Than'
   *  RelationalOperator: '<S202>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_Subtract_e5)) {
    /* SignalConversion generated from: '<S158>/C Caller' incorporates:
     *  Constant: '<S193>/Engine Brake'
     */
    rtb_lg[0] = -0.0;
  } else {
    /* SignalConversion generated from: '<S158>/C Caller' incorporates:
     *  MinMax: '<S193>/Max1'
     */
    rtb_lg[0] = fmin(rtb_lg_saturation, rtb_front_wheel_angle_single__p);
  }

  /* End of Switch: '<S193>/Switch2' */

  /* SignalConversion generated from: '<S158>/C Caller' incorporates:
   *  Abs: '<S197>/Abs1'
   *  Abs: '<S197>/Abs3'
   *  Constant: '<S167>/Constant2'
   *  Gain: '<S194>/Gain'
   *  UnaryMinus: '<S197>/Unary Minus'
   *  UnaryMinus: '<S197>/Unary Minus1'
   */
  rtb_lg[1] = 0.001 * rtb_Abs3;
  rtb_lg[2] = -rtb_Memory_idx_1;
  rtb_lg[3] = -rtb_Memory_idx_0;
  rtb_lg[4] = rtb_Mzlim;
  rtb_lg[5] = -0.1;

  /* InitialCondition: '<S195>/IC1' */
  rtDW.bitsForTID0.IC1_FirstOutputTime = false;

  /* SignalConversion generated from: '<S158>/C Caller' incorporates:
   *  Constant: '<S167>/Constant1'
   *  Gain: '<S195>/Gain'
   *  MinMax: '<S193>/Max'
   */
  rtb_ug[0] = fmax(rtb_lg_saturation, rtb_front_wheel_angle_single__p);
  rtb_ug[1] = 80.0;
  rtb_ug[2] = rtb_Memory_idx_1;
  rtb_ug[3] = rtb_Memory_idx_0;
  rtb_ug[4] = rtb_Abs_idx_0;
  rtb_ug[5] = 0.1;

  /* MATLAB Function: '<S170>/MATLAB Function' */
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 1.0;
  v[3] = 0.0001;
  v[4] = 0.0001;
  v[5] = 0.0001;
  v[6] = 0.0001;
  memset(&varargin_1[0], 0, 49U * sizeof(real_T));
  for (ibcol = 0; ibcol < 7; ibcol++) {
    varargin_1[ibcol + 7 * ibcol] = v[ibcol];
  }

  memset(&varargin_2[0], 0, sizeof(real_T) << 4U);
  varargin_2[0] = 1.0E-5;
  varargin_2[5] = 1.0E-5;
  varargin_2[10] = 1.0E-5;
  varargin_2[15] = 1.0E-5;
  memset(&rtb_y[0], 0, 121U * sizeof(real_T));
  for (rtb_mz_output = 0; rtb_mz_output < 7; rtb_mz_output++) {
    for (ibcol = 0; ibcol < 7; ibcol++) {
      rtb_y[ibcol + 11 * rtb_mz_output] = varargin_1[7 * rtb_mz_output + ibcol];
    }
  }

  for (rtb_mz_output = 0; rtb_mz_output < 4; rtb_mz_output++) {
    ibcol = rtb_mz_output << 2;
    rowIdx = (rtb_mz_output + 7) * 11;
    rtb_y[rowIdx + 7] = varargin_2[ibcol];
    rtb_y[rowIdx + 8] = varargin_2[ibcol + 1];
    rtb_y[rowIdx + 9] = varargin_2[ibcol + 2];
    rtb_y[rowIdx + 10] = varargin_2[ibcol + 3];
  }

  for (rtb_mz_output = 0; rtb_mz_output < 121; rtb_mz_output++) {
    rtb_y[rtb_mz_output] *= 50.0;
  }

  /* End of MATLAB Function: '<S170>/MATLAB Function' */

  /* CCaller: '<S158>/C Caller' incorporates:
   *  CFunction: '<S172>/C Function'
   *  Constant: '<S166>/Constant'
   *  Constant: '<S168>/Constant'
   *  UnaryMinus: '<S166>/Unary Minus'
   */
  rtb_Subtract_e5 = Acados_Caller_wrapper(&rtb_x[0], &rtDW.CFunction[0],
    &rtb_y_ref_0[0], &rtb_y_d[0], &rtb_y_ref_0[0], &rtb_y_m[0], &rtb_y_p[0],
    &rtb_UnaryMinus_ci[0], &rtb_y_b[0], &rtb_lg[0], &rtb_ug[0], &rtb_y[0],
    &rtConstP.Constant_Value_fo[0], &rtConstP.Constant_Value_fo[0],
    &rtConstB.UnaryMinus[0], &rtConstP.Constant_Value_b[0], &rtb_CCaller_o2[0],
    &rtb_CCaller_o3[0]);

  /* DataTypeConversion: '<S177>/Data Type Conversion' incorporates:
   *  Constant: '<S177>/Constant2'
   *  RelationalOperator: '<S177>/Equal'
   */
  DataTypeConversion = (uint8_T)(rtb_Subtract_e5 == 4.0);

  /* DiscreteFir: '<S177>/Discrete FIR Filter' */
  acc1 = (uint32_T)DataTypeConversion << 7;
  for (ibcol = rtDW.DiscreteFIRFilter_circBuf; ibcol < 4; ibcol++) {
    acc1 += (uint32_T)rtDW.DiscreteFIRFilter_states[ibcol] << 7;
  }

  for (ibcol = 0; ibcol < rtDW.DiscreteFIRFilter_circBuf; ibcol++) {
    acc1 += (uint32_T)rtDW.DiscreteFIRFilter_states[ibcol] << 7;
  }

  /* End of DiscreteFir: '<S177>/Discrete FIR Filter' */

  /* Switch: '<S177>/Switch' */
  if ((rtb_vx > 3.0) && (acc1 < 512U)) {
    /* Outputs for IfAction SubSystem: '<S164>/MPC' incorporates:
     *  ActionPort: '<S174>/Action Port'
     */
    /* If: '<S164>/If' incorporates:
     *  Inport: '<S174>/X1'
     *  Merge: '<S164>/Merge'
     *  Product: '<S179>/Product2'
     */
    rtDW.Merge[0] = rtb_CCaller_o3[3];
    rtDW.Merge[1] = rtb_CCaller_o3[4];
    rtDW.Merge[2] = rtb_CCaller_o3[5];
    rtDW.Merge[3] = rtb_CCaller_o3[6];

    /* End of Outputs for SubSystem: '<S164>/MPC' */
  } else {
    /* Outputs for IfAction SubSystem: '<S164>/Simple torque' incorporates:
     *  ActionPort: '<S176>/Action Port'
     */
    /* If: '<S164>/If' incorporates:
     *  Constant: '<S179>/Constant'
     *  Constant: '<S179>/Constant2'
     *  Constant: '<S180>/Constant'
     *  Constant: '<S180>/Exponent < 0'
     *  Gain: '<S179>/Gain1'
     *  Inport: '<Root>/throttle'
     *  Math: '<S180>/Power'
     *  Product: '<S179>/Product'
     *  Product: '<S179>/Product1'
     *  Product: '<S179>/Product2'
     *  Product: '<S180>/Divide'
     *  Product: '<S180>/Divide1'
     *  RelationalOperator: '<S179>/Less Than1'
     *  RelationalOperator: '<S181>/LowerRelop1'
     *  RelationalOperator: '<S183>/LowerRelop1'
     *  RelationalOperator: '<S183>/UpperRelop'
     *  SignalConversion generated from: '<S182>/Vector Concatenate1'
     *  SignalConversion generated from: '<S182>/Vector Concatenate'
     *  Sum: '<S179>/Sum of Elements'
     *  Sum: '<S180>/Subtract'
     *  Sum: '<S180>/Sum'
     *  Switch: '<S181>/Switch2'
     *  Switch: '<S183>/Switch'
     *  Switch: '<S183>/Switch2'
     * */
    rtb_vx = ((rtb_Product[0] + rtb_Product[1]) + rtb_Product[2]) + rtb_Product
      [3];
    rtb_Abs_idx_0 = 1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle), -1.5)
      + 1.0) * (real_T)(rtU.throttle >= 0.05) * 84.0;
    if (!(rtb_Abs_idx_0 > rtb_vx)) {
      /* Sum: '<S179>/Sum of Elements1' */
      rtb_vx = ((rtb_max_torque_overload_inverte[0] +
                 rtb_max_torque_overload_inverte[1]) +
                rtb_max_torque_overload_inverte[2]) +
        rtb_max_torque_overload_inverte[3];

      /* Switch: '<S181>/Switch' incorporates:
       *  RelationalOperator: '<S181>/UpperRelop'
       *  Sum: '<S179>/Sum of Elements1'
       */
      if (!(rtb_Abs_idx_0 < rtb_vx)) {
        rtb_vx = rtb_Abs_idx_0;
      }

      /* End of Switch: '<S181>/Switch' */
    }

    rtDW.Merge[0] = rtb_vx * 0.3;
    rtDW.Merge[1] = rtb_vx * 0.3;
    rtDW.Merge[2] = rtb_vx * 0.7;
    rtDW.Merge[3] = rtb_vx * 0.7;
    rtb_CCaller_o2[0] = rtb_Switch;
    rtb_CCaller_o2[1] = rtb_Switch;
    rtb_CCaller_o2[2] = rtb_Switch_m;
    rtb_CCaller_o2[3] = rtb_Switch_m;
    rtb_y_m[0] = rtb_RR;
    rtb_y_m[1] = rtb_RR;
    rtb_y_m[2] = rtb_RL;
    rtb_y_m[3] = rtb_RL;
    if (rtDW.Merge[0] > rtb_CCaller_o2[0]) {
      /* Merge: '<S164>/Merge' incorporates:
       *  SignalConversion generated from: '<S176>/Out1'
       */
      rtDW.Merge[0] = rtb_CCaller_o2[0];
    } else if (rtDW.Merge[0] < rtb_y_m[0]) {
      /* Switch: '<S183>/Switch' incorporates:
       *  Merge: '<S164>/Merge'
       *  SignalConversion generated from: '<S176>/Out1'
       */
      rtDW.Merge[0] = rtb_y_m[0];
    }

    if (rtDW.Merge[1] > rtb_CCaller_o2[1]) {
      /* Merge: '<S164>/Merge' incorporates:
       *  SignalConversion generated from: '<S176>/Out1'
       */
      rtDW.Merge[1] = rtb_CCaller_o2[1];
    } else if (rtDW.Merge[1] < rtb_y_m[1]) {
      /* Switch: '<S183>/Switch' incorporates:
       *  Merge: '<S164>/Merge'
       *  SignalConversion generated from: '<S176>/Out1'
       */
      rtDW.Merge[1] = rtb_y_m[1];
    }

    if (rtDW.Merge[2] > rtb_CCaller_o2[2]) {
      /* Merge: '<S164>/Merge' incorporates:
       *  SignalConversion generated from: '<S176>/Out1'
       */
      rtDW.Merge[2] = rtb_CCaller_o2[2];
    } else if (rtDW.Merge[2] < rtb_y_m[2]) {
      /* Switch: '<S183>/Switch' incorporates:
       *  Merge: '<S164>/Merge'
       *  SignalConversion generated from: '<S176>/Out1'
       */
      rtDW.Merge[2] = rtb_y_m[2];
    }

    if (rtDW.Merge[3] > rtb_CCaller_o2[3]) {
      /* Merge: '<S164>/Merge' incorporates:
       *  SignalConversion generated from: '<S176>/Out1'
       */
      rtDW.Merge[3] = rtb_CCaller_o2[3];
    } else if (rtDW.Merge[3] < rtb_y_m[3]) {
      /* Switch: '<S183>/Switch' incorporates:
       *  Merge: '<S164>/Merge'
       *  SignalConversion generated from: '<S176>/Out1'
       */
      rtDW.Merge[3] = rtb_y_m[3];
    }

    /* End of Outputs for SubSystem: '<S164>/Simple torque' */
  }

  /* End of Switch: '<S177>/Switch' */

  /* Product: '<S164>/Divide' */
  rtDW.Memory_PreviousInput[0] = rtDW.Merge[0];
  rtDW.Memory_PreviousInput[1] = rtDW.Merge[1];
  rtDW.Memory_PreviousInput[2] = rtDW.Merge[2];
  rtDW.Memory_PreviousInput[3] = rtDW.Merge[3];

  /* RelationalOperator: '<S164>/Less Than3' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Inport: '<Root>/brake'
   */
  rtb_LessThan3 = (rtU.brake > 0.05);

  /* Chart: '<S164>/Overlap Chart' incorporates:
   *  Inport: '<Root>/throttle'
   */
  if (rtDW.bitsForTID0.is_active_c75_TVModel == 0U) {
    rtDW.bitsForTID0.is_active_c75_TVModel = 1U;
    rtDW.bitsForTID0.is_c75_TVModel = IN_Go;
  } else if (rtDW.bitsForTID0.is_c75_TVModel == IN_Go) {
    if (rtb_LessThan3) {
      rtDW.bitsForTID0.is_c75_TVModel = IN_Stop;
    }

    /* case IN_Stop: */
  } else if (((real_T)rtb_LessThan3 <= 0.05) && (rtU.throttle < 0.05)) {
    rtDW.bitsForTID0.is_c75_TVModel = IN_Go;
  }

  /* End of Chart: '<S164>/Overlap Chart' */

  /* Update for UnitDelay generated from: '<S26>/Unit Delay3' */
  rtDW.UnitDelay3_1_DSTATE = rtDW.Memory_PreviousInput[3];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay3' */
  rtDW.UnitDelay3_2_DSTATE = rtDW.Memory_PreviousInput[2];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay3' */
  rtDW.UnitDelay3_3_DSTATE = rtDW.Memory_PreviousInput[1];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay3' */
  rtDW.UnitDelay3_4_DSTATE = rtDW.Memory_PreviousInput[0];

  /* Update for DiscreteIntegrator: '<S38>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S29>/1//T' */
  rtb_Abs3 = 1.0 / rtb_AvoidDividebyZero;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' */
  rtDW.Integrator_PrevResetState_d = (int8_T)rtb_Compare;

  /* Update for UnitDelay generated from: '<S26>/Unit Delay2' */
  rtDW.UnitDelay2_1_DSTATE = rtDW.Memory_PreviousInput[3];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay2' */
  rtDW.UnitDelay2_2_DSTATE = rtDW.Memory_PreviousInput[2];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay2' */
  rtDW.UnitDelay2_3_DSTATE = rtDW.Memory_PreviousInput[1];

  /* Update for UnitDelay generated from: '<S26>/Unit Delay2' */
  rtDW.UnitDelay2_4_DSTATE = rtDW.Memory_PreviousInput[0];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay3' */
  rtDW.UnitDelay3_1_DSTATE_f = rtDW.Memory_PreviousInput[3];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay3' */
  rtDW.UnitDelay3_2_DSTATE_b = rtDW.Memory_PreviousInput[2];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay3' */
  rtDW.UnitDelay3_3_DSTATE_k = rtDW.Memory_PreviousInput[1];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay3' */
  rtDW.UnitDelay3_4_DSTATE_o = rtDW.Memory_PreviousInput[0];

  /* Update for DiscreteIntegrator: '<S103>/Integrator' */
  rtDW.Integrator_IC_LOADING_i = 0U;

  /* Product: '<S94>/1//T' */
  rtb_vx = 1.0 / rtb_AvoidDividebyZero_h;

  /* Update for DiscreteIntegrator: '<S103>/Integrator' */
  rtDW.Integrator_PrevResetState_m = (int8_T)rtb_Compare_n;

  /* Update for UnitDelay generated from: '<S27>/Unit Delay2' */
  rtDW.UnitDelay2_1_DSTATE_i = rtDW.Memory_PreviousInput[3];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay2' */
  rtDW.UnitDelay2_2_DSTATE_f = rtDW.Memory_PreviousInput[2];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay2' */
  rtDW.UnitDelay2_3_DSTATE_j = rtDW.Memory_PreviousInput[1];

  /* Update for UnitDelay generated from: '<S27>/Unit Delay2' */
  rtDW.UnitDelay2_4_DSTATE_c = rtDW.Memory_PreviousInput[0];

  /* Update for DiscreteIntegrator: '<S237>/Integrator' */
  rtDW.Integrator_IC_LOADING_it = 0U;

  /* Product: '<S230>/1//T' incorporates:
   *  Constant: '<S232>/Time constant'
   *  MinMax: '<S232>/Max'
   */
  rtb_Abs_idx_0 = 1.0 / fmax(rtDW.Probe_kx[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S237>/Integrator' */
  rtDW.Integrator_PrevResetState_i = (int8_T)rtb_Compare_g;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' */
  rtDW.Integrator_IC_LOADING_b = 0U;

  /* Product: '<S239>/1//T' incorporates:
   *  Constant: '<S241>/Time constant'
   *  MinMax: '<S241>/Max'
   */
  rtb_Mzlim = 1.0 / fmax(rtDW.Probe_b[0], 0.079577471545947673);

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
  rtDW.UD_DSTATE[0] = rtb_Sign;

  /* Update for Memory: '<S26>/Memory' incorporates:
   *  RelationalOperator: '<S26>/Equal'
   */
  rtDW.Memory_PreviousInput_f[0] = rtb_Equal_idx_0;

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   *  Switch: '<S65>/Switch'
   */
  rtDW.Integrator_DSTATE[0] += 0.02 * rtb_UnitDelay_idx_0;
  rtDW.Integrator_PrevResetState[0] = (int8_T)rtb_Memory_i_idx_0;

  /* Update for DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Memory: '<S26>/Memory'
   */
  rtDW.Filter_DSTATE[0] += 0.02 * rtb_FilterCoefficient_idx_0;
  rtDW.Filter_PrevResetState[0] = (int8_T)rtb_Memory_i_idx_0;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Product: '<S29>/1//T'
   *  Sum: '<S29>/Sum1'
   */
  rtDW.Integrator_DSTATE_h[0] += rtb_Abs3 * rtb_T_max_k_idx_0 * 0.02;

  /* Update for UnitDelay: '<S93>/UD' incorporates:
   *  SampleTimeMath: '<S28>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f[0] = rtb_Sign;

  /* Update for Memory: '<S27>/Memory' incorporates:
   *  RelationalOperator: '<S27>/Equal'
   */
  rtDW.Memory_PreviousInput_m[0] = rtb_Equal_c_idx_0;

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  rtDW.Integrator_DSTATE_f[0] += 0.02 * rtb_SignPreIntegrator_idx_3_0;
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
  rtDW.Integrator_DSTATE_f3[0] += rtb_vx * rtb_Integrator_iq_idx_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
   *  Product: '<S230>/1//T'
   *  Sum: '<S230>/Sum1'
   */
  rtDW.Integrator_DSTATE_j[0] += (rtb_SignPreIntegrator_idx_0 - rtb_Gain1) *
    rtb_Abs_idx_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' incorporates:
   *  Product: '<S239>/1//T'
   *  Sum: '<S239>/Sum1'
   */
  rtDW.Integrator_DSTATE_ff[0] += (rtb_Subtract_o - rtb_Integrator_d_idx_0) *
    rtb_Mzlim * 0.02;

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
  rtDW.UD_DSTATE[1] = rtb_Subtract_m4_tmp_0;

  /* Update for Memory: '<S26>/Memory' incorporates:
   *  RelationalOperator: '<S26>/Equal'
   */
  rtDW.Memory_PreviousInput_f[1] = rtb_Equal_idx_1;

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   *  Switch: '<S65>/Switch'
   */
  rtDW.Integrator_DSTATE[1] += 0.02 * rtb_UnitDelay_idx_1;
  rtDW.Integrator_PrevResetState[1] = (int8_T)rtb_Memory_i_idx_1;

  /* Update for DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Memory: '<S26>/Memory'
   */
  rtDW.Filter_DSTATE[1] += 0.02 * rtb_FilterCoefficient_idx_1;
  rtDW.Filter_PrevResetState[1] = (int8_T)rtb_Memory_i_idx_1;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Product: '<S29>/1//T'
   *  Sum: '<S29>/Sum1'
   */
  rtDW.Integrator_DSTATE_h[1] += rtb_Abs3 * rtb_T_max_k_idx_1 * 0.02;

  /* Update for UnitDelay: '<S93>/UD' incorporates:
   *  SampleTimeMath: '<S28>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f[1] = rtb_Subtract_m4_tmp_0;

  /* Update for Memory: '<S27>/Memory' incorporates:
   *  RelationalOperator: '<S27>/Equal'
   */
  rtDW.Memory_PreviousInput_m[1] = rtb_Equal_c_idx_1;

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  rtDW.Integrator_DSTATE_f[1] += 0.02 * rtb_ZeroGain_a;
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
  rtDW.Integrator_DSTATE_f3[1] += rtb_vx * rtb_Integrator_iq_idx_1 * 0.02;

  /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
   *  Product: '<S230>/1//T'
   *  Sum: '<S230>/Sum1'
   */
  rtDW.Integrator_DSTATE_j[1] += (rtb_SignPreIntegrator_idx_1 -
    rtb_UnitDelay_e_idx_1) * rtb_Abs_idx_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' incorporates:
   *  Product: '<S239>/1//T'
   *  Sum: '<S239>/Sum1'
   */
  rtDW.Integrator_DSTATE_ff[1] += (rtb_Subtract_m - rtb_Integrator_d_idx_1) *
    rtb_Mzlim * 0.02;

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
  rtDW.UD_DSTATE[2] = rtb_Subtract_m4_tmp_1;

  /* Update for Memory: '<S26>/Memory' incorporates:
   *  RelationalOperator: '<S26>/Equal'
   */
  rtDW.Memory_PreviousInput_f[2] = rtb_Equal_idx_2;

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   *  Switch: '<S65>/Switch'
   */
  rtDW.Integrator_DSTATE[2] += 0.02 * rtb_UnitDelay_idx_2;
  rtDW.Integrator_PrevResetState[2] = (int8_T)rtb_Memory_i_idx_2;

  /* Update for DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Memory: '<S26>/Memory'
   */
  rtDW.Filter_DSTATE[2] += 0.02 * rtb_FilterCoefficient_idx_2;
  rtDW.Filter_PrevResetState[2] = (int8_T)rtb_Memory_i_idx_2;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Product: '<S29>/1//T'
   *  Sum: '<S29>/Sum1'
   */
  rtDW.Integrator_DSTATE_h[2] += rtb_Abs3 * rtb_T_max_k_idx_2 * 0.02;

  /* Update for UnitDelay: '<S93>/UD' incorporates:
   *  SampleTimeMath: '<S28>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f[2] = rtb_Subtract_m4_tmp_1;

  /* Update for Memory: '<S27>/Memory' incorporates:
   *  RelationalOperator: '<S27>/Equal'
   */
  rtDW.Memory_PreviousInput_m[2] = rtb_Equal_c_idx_2;

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Memory: '<S27>/Memory'
   */
  rtDW.Integrator_DSTATE_f[2] += 0.02 * rtb_ZeroGain_o;
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
  rtDW.Integrator_DSTATE_f3[2] += rtb_vx * rtb_Integrator_iq_idx_2 * 0.02;

  /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
   *  Product: '<S230>/1//T'
   *  Sum: '<S230>/Sum1'
   */
  rtDW.Integrator_DSTATE_j[2] += (rtb_SignPreIntegrator_idx_2 -
    rtb_UnitDelay_e_idx_2) * rtb_Abs_idx_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' incorporates:
   *  Product: '<S239>/1//T'
   *  Sum: '<S239>/Sum1'
   */
  rtDW.Integrator_DSTATE_ff[2] += (rtb_Sum1_g - rtb_Integrator_d_idx_2) *
    rtb_Mzlim * 0.02;

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

  /* Update for Memory: '<S26>/Memory' incorporates:
   *  RelationalOperator: '<S26>/Equal'
   */
  rtDW.Memory_PreviousInput_f[3] = rtb_Equal_idx_3;

  /* Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
   *  Memory: '<S26>/Memory'
   */
  rtDW.Integrator_DSTATE[3] += 0.02 * rtb_Filter_f;
  rtDW.Integrator_PrevResetState[3] = (int8_T)rtb_Memory_i_idx_3;

  /* Update for DiscreteIntegrator: '<S69>/Filter' incorporates:
   *  DiscreteIntegrator: '<S74>/Integrator'
   *  Gain: '<S77>/Filter Coefficient'
   *  Memory: '<S26>/Memory'
   */
  rtDW.Filter_DSTATE[3] += 0.02 * rtb_FilterCoefficient_idx_3;
  rtDW.Filter_PrevResetState[3] = (int8_T)rtb_Memory_i_idx_3;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Product: '<S29>/1//T'
   */
  rtDW.Integrator_DSTATE_h[3] += rtb_Abs3 * rtb_T_max_k_idx_3 * 0.02;

  /* Update for UnitDelay: '<S93>/UD' incorporates:
   *  SampleTimeMath: '<S28>/TSamp'
   *
   * About '<S28>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S93>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f[3] = rtb_Subtract_m4_tmp;

  /* Update for Memory: '<S27>/Memory' incorporates:
   *  RelationalOperator: '<S27>/Equal'
   */
  rtDW.Memory_PreviousInput_m[3] = rtb_Equal_c_idx_3;

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
  rtDW.Integrator_DSTATE_f3[3] += rtb_vx * rtb_Integrator_iq_idx_3 * 0.02;

  /* Update for DiscreteIntegrator: '<S237>/Integrator' incorporates:
   *  Product: '<S230>/1//T'
   *  Sum: '<S230>/Sum1'
   */
  rtDW.Integrator_DSTATE_j[3] += (rtb_SignPreIntegrator_idx_3 -
    rtb_UnitDelay_e_idx_3) * rtb_Abs_idx_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S246>/Integrator' incorporates:
   *  Product: '<S239>/1//T'
   *  Sum: '<S239>/Sum1'
   */
  rtDW.Integrator_DSTATE_ff[3] += (rtb_UnaryMinus_ot_idx_0 -
    rtb_Integrator_d_idx_3) * rtb_Mzlim * 0.02;
  rtDW.Integrator_PrevResetState_f = (int8_T)rtb_Compare_d;

  /* Update for Memory: '<S211>/Memory' */
  rtDW.bitsForTID0.Memory_PreviousInput_n = rtb_Logic_idx_0;

  /* Update for Memory: '<S212>/Memory' */
  rtDW.bitsForTID0.Memory_PreviousInput_i = rtb_Logic_e_idx_0;

  /* Update for Memory: '<S213>/Memory' */
  rtDW.bitsForTID0.Memory_PreviousInput_h = rtb_Logic_l_idx_0;

  /* Update for Memory: '<S214>/Memory' */
  rtDW.bitsForTID0.Memory_PreviousInput_d = rtb_Logic_k_idx_0;

  /* Update for Memory: '<S191>/Memory' */
  rtDW.bitsForTID0.Memory_PreviousInput_e = rtb_Logic_b_idx_0;

  /* Update for DiscreteFir: '<S177>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf] =
    DataTypeConversion;

  /* End of Update for DiscreteFir: '<S177>/Discrete FIR Filter' */

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
  rtY.Torque[0] = rtDW.Memory_PreviousInput[0];
  rtY.Torque[1] = rtDW.Memory_PreviousInput[1];
  rtY.Torque[2] = rtDW.Memory_PreviousInput[2];
  rtY.Torque[3] = rtDW.Memory_PreviousInput[3];
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

  /* Start for InitialCondition: '<S194>/IC' */
  rtDW.bitsForTID0.IC_FirstOutputTime = true;

  /* Start for InitialCondition: '<S195>/IC1' */
  rtDW.bitsForTID0.IC1_FirstOutputTime = true;

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
