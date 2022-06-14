/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jun 15 00:24:37 2022
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

/* Named constants for Chart: '<S283>/T_Req_Chart' */
#define IN_Brake                       ((uint8_T)1U)
#define IN_Throttle                    ((uint8_T)2U)
#define NumBitsPerChar                 8U

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
static void YRD_LUT_1(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd);
static void YRD_LUT_0(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd);
static void YRD_LUT_15(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
  *rty_yrd);
static void YRD_LUT_3(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd);

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
 *    '<S140>/YRD_LUT_1'
 *    '<S140>/YRD_LUT_3'
 */
static void YRD_LUT_1(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_absolute_front_wheel_angle;
  real_T rtb_vx_j;

  /* Abs: '<S278>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S278>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_j = 3.0;
  } else {
    rtb_vx_j = rtu_vx;
  }

  /* End of Saturate: '<S278>/Saturation' */

  /* Product: '<S278>/Divide2' incorporates:
   *  Abs: '<S278>/Abs'
   *  Lookup_n-D: '<S278>/LUT_1'
   *  Product: '<S278>/Divide'
   *  Product: '<S278>/Divide1'
   *  Saturate: '<S278>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_j, rtConstP.pooled28,
                 rtConstP.pooled29, rtConstP.pooled23, rtConstP.pooled72, 100U) /
     rtb_vx_j);
}

/*
 * Output and update for action system:
 *    '<S140>/YRD_LUT_0'
 *    '<S140>/YRD_LUT_2'
 */
static void YRD_LUT_0(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_absolute_front_wheel_angle;
  real_T rtb_vx_a;

  /* Abs: '<S277>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S277>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_a = 3.0;
  } else {
    rtb_vx_a = rtu_vx;
  }

  /* End of Saturate: '<S277>/Saturation' */

  /* Product: '<S277>/Divide2' incorporates:
   *  Abs: '<S277>/Abs'
   *  Lookup_n-D: '<S277>/LUT_0'
   *  Product: '<S277>/Divide'
   *  Product: '<S277>/Divide1'
   *  Saturate: '<S277>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_a, rtConstP.pooled28,
                 rtConstP.pooled29, rtConstP.pooled24, rtConstP.pooled72, 100U) /
     rtb_vx_a);
}

/*
 * Output and update for action system:
 *    '<S140>/YRD_LUT_-1.5'
 *    '<S140>/YRD_LUT_-1.1'
 */
static void YRD_LUT_15(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
  *rty_yrd)
{
  real_T rtb_absolute_front_wheel_angle;
  real_T rtb_vx_n;

  /* Abs: '<S275>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S275>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_n = 3.0;
  } else {
    rtb_vx_n = rtu_vx;
  }

  /* End of Saturate: '<S275>/Saturation' */

  /* Product: '<S275>/Divide2' incorporates:
   *  Abs: '<S275>/Abs'
   *  Lookup_n-D: '<S275>/LUT_-1.5'
   *  Product: '<S275>/Divide'
   *  Product: '<S275>/Divide1'
   *  Saturate: '<S275>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_n, rtConstP.pooled28,
                 rtConstP.pooled29, rtConstP.pooled25, rtConstP.pooled72, 100U) /
     rtb_vx_n);
}

/*
 * Output and update for action system:
 *    '<S140>/YRD_LUT_-3'
 *    '<S140>/YRD_LUT_-1'
 */
static void YRD_LUT_3(real_T rtu_front_wheel_angle, real_T rtu_vx, real_T
                      *rty_yrd)
{
  real_T rtb_absolute_front_wheel_angle;
  real_T rtb_vx_o;

  /* Abs: '<S276>/Abs' */
  rtb_absolute_front_wheel_angle = fabs(rtu_front_wheel_angle);

  /* Saturate: '<S276>/Saturation' */
  if (rtu_vx <= 3.0) {
    rtb_vx_o = 3.0;
  } else {
    rtb_vx_o = rtu_vx;
  }

  /* End of Saturate: '<S276>/Saturation' */

  /* Product: '<S276>/Divide2' incorporates:
   *  Abs: '<S276>/Abs'
   *  Lookup_n-D: '<S276>/LUT_-3'
   *  Product: '<S276>/Divide'
   *  Product: '<S276>/Divide1'
   *  Saturate: '<S276>/Saturation'
   */
  *rty_yrd = rtu_front_wheel_angle / rtb_absolute_front_wheel_angle *
    (look2_binlx(rtb_absolute_front_wheel_angle, rtb_vx_o, rtConstP.pooled28,
                 rtConstP.pooled29, rtConstP.pooled27, rtConstP.pooled72, 100U) /
     rtb_vx_o);
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

/* Function for Chart: '<S236>/Distribution complete' */
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

/* Function for Chart: '<S236>/Distribution complete' */
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

/* Function for Chart: '<S236>/Distribution complete' */
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

/* Function for Chart: '<S236>/Distribution complete' */
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
  rtDW.is_RR_p = IN_NO_ACTIVE_CHILD;
  rtDW.is_RL_g = IN_NO_ACTIVE_CHILD;
  rtDW.is_FR_i = IN_NO_ACTIVE_CHILD;
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
  real_T rtb_y[64];
  real_T rtb_CCaller_o3[26];
  real_T rtb_CCaller_o12[20];
  real_T rtb_CCaller_o6[16];
  real_T varargin_2[16];
  real_T RateTransition3[13];
  real_T rtb_CCaller_o10[5];
  real_T rtb_CCaller_o9[5];
  real_T rtb_CCaller_o8[4];
  real_T rtb_Integrator_c[4];
  real_T rtb_Integrator_i[4];
  real_T rtb_Minus[4];
  real_T rtb_Product1[4];
  real_T rtb_Switch2_c[4];
  real_T rtb_TmpSignalConversionAtSFun_e[4];
  real_T rtb_Tnew[4];
  real_T rtb_UnaryMinus_a[4];
  real_T rtb_UnaryMinus_k4[4];
  real_T rtb_CCaller_o13[3];
  real_T rtb_CCaller_o14[3];
  real_T csumrev[2];
  real_T fractions[2];
  real_T Faeroz_tmp;
  real_T Switch2_idx_0;
  real_T Switch2_idx_1;
  real_T Switch2_idx_2;
  real_T Switch2_idx_3;
  real_T csum;
  real_T cumRevIndex;
  real_T cumRevIndex_tmp;
  real_T cumRevIndex_tmp_0;
  real_T cumRevIndex_tmp_tmp;
  real_T cumRevIndex_tmp_tmp_0;
  real_T modValueRev;
  real_T rtb_Abs_c;
  real_T rtb_Abs_o_idx_0;
  real_T rtb_Gain1;
  real_T rtb_Gain_idx_1;
  real_T rtb_Gain_idx_2;
  real_T rtb_Gain_idx_3;
  real_T rtb_Integrator_a_idx_0;
  real_T rtb_Integrator_a_idx_1;
  real_T rtb_Integrator_a_idx_2;
  real_T rtb_Integrator_a_idx_3;
  real_T rtb_Integrator_ac;
  real_T rtb_Integrator_idx_0;
  real_T rtb_Integrator_idx_1;
  real_T rtb_Integrator_idx_2;
  real_T rtb_Integrator_idx_3;
  real_T rtb_NProdOut;
  real_T rtb_RL;
  real_T rtb_RR;
  real_T rtb_RR_tmp;
  real_T rtb_RR_tmp_tmp;
  real_T rtb_Saturation1_tmp;
  real_T rtb_Saturation1_tmp_0;
  real_T rtb_Saturation_c_idx_0;
  real_T rtb_Saturation_c_idx_1;
  real_T rtb_Saturation_c_idx_2;
  real_T rtb_Saturation_c_idx_3;
  real_T rtb_Sign;
  real_T rtb_SumofElements1;
  real_T rtb_Switch;
  real_T rtb_Switch2_o;
  real_T rtb_Switch_c;
  real_T rtb_Switch_n_idx_0;
  real_T rtb_Switch_n_idx_1;
  real_T rtb_Switch_n_idx_2;
  real_T rtb_front_wheel_angle_single__o;
  real_T rtb_k_e;
  real_T rtb_k_p_idx_0;
  real_T rtb_k_p_idx_1;
  real_T rtb_k_p_idx_2;
  real_T rtb_k_p_idx_3;
  real_T rtb_ome_wheels;
  real_T rtb_ome_wheels_idx_0;
  real_T rtb_ome_wheels_idx_1;
  real_T rtb_ome_wheels_idx_2;
  real_T rtb_ome_wheels_idx_3;
  real_T rtb_vx;
  real_T u0;
  real_T u0_tmp;
  real_T u0_tmp_0;
  real_T u0_tmp_1;
  real_T u_tmp;
  real_T z;
  int32_T tmp[2];
  int32_T b_j;
  int32_T idx;
  int32_T rtb_y_tmp;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  boolean_T AND;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_c;
  boolean_T rtb_LessThan3;
  boolean_T rtb_Logic_a_idx_0;
  boolean_T rtb_Logic_a_idx_1;
  boolean_T rtb_Logic_i_idx_0;
  boolean_T rtb_Logic_i_idx_1;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_idx_1;
  boolean_T rtb_Logic_m_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (rtU.vx <= 0.0) {
    rtb_Integrator_ac = 0.0;
  } else {
    rtb_Integrator_ac = rtU.vx;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/yaw_rate'
   */
  rtb_Gain1 = 0.017453292519943295 * rtU.yaw_rate_deg;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Integrator_ac <= 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = rtb_Integrator_ac;
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
  rtb_Abs_o_idx_0 = fabs(look1_binlx(rtU.steering, rtConstP.pooled43,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Abs_c = fabs(look1_binlx(-rtU.steering, rtConstP.pooled43,
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
    rtb_Sign = rtb_vx * cos(rtb_Abs_c) + sin(rtb_Abs_c) * rtU.vy;
    rtb_Switch_c = (0.235 * rtU.omega_wheels_FR - rtb_Sign) / rtb_Sign;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_vx) / rtb_vx;
    rtb_RL = (0.235 * rtU.omega_wheels_RL - rtb_vx) / rtb_vx;
  } else {
    rtb_Switch = 0.0;
    rtb_Switch_c = 0.0;
    rtb_RR = 0.0;
    rtb_RL = 0.0;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_front_wheel_angle_single__o = look1_binlx(rtU.steering, rtConstP.pooled43,
    rtConstP.steering_to_wheel_angle_single_, 32U);

  /* MATLAB Function: '<S22>/MATLAB Function2' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/vy'
   */
  Faeroz_tmp = rtb_vx - 0.635 * rtb_Gain1;
  rtb_k_p_idx_0 = rtU.vy - 0.765 * rtb_Gain1;
  rtb_k_p_idx_1 = 0.635 * rtb_Gain1 + rtb_vx;

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
  rtb_NProdOut = cos(rtb_front_wheel_angle_single__o);
  rtb_Switch2_o = sin(rtb_front_wheel_angle_single__o);

  /* SignalConversion generated from: '<S138>/ SFunction ' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Inport: '<Root>/vy'
   *  MATLAB Function: '<S22>/MATLAB Function2'
   *  MATLAB Function: '<S25>/MATLAB Function'
   */
  rtb_Integrator_i[0] = (0.765 * rtb_Gain1 + rtU.vy) * rtb_Switch2_o +
    Faeroz_tmp * rtb_NProdOut;
  rtb_Integrator_i[1] = (0.765 * rtb_Gain1 + rtU.vy) * sin
    (rtb_front_wheel_angle_single__o) + rtb_k_p_idx_1 * rtb_NProdOut;

  /* MATLAB Function: '<S22>/MATLAB Function2' */
  rtb_Integrator_ac = rtb_k_p_idx_0 * rtb_k_p_idx_0;

  /* SignalConversion generated from: '<S138>/ SFunction ' incorporates:
   *  MATLAB Function: '<S22>/MATLAB Function2'
   *  MATLAB Function: '<S25>/MATLAB Function'
   */
  rtb_Integrator_i[2] = sqrt(Faeroz_tmp * Faeroz_tmp + rtb_Integrator_ac);
  rtb_Integrator_i[3] = sqrt(rtb_k_p_idx_1 * rtb_k_p_idx_1 + rtb_Integrator_ac);

  /* MATLAB Function: '<S25>/MATLAB Function' incorporates:
   *  Constant: '<S25>/Constant'
   */
  rtb_CCaller_o13[0] = rtb_Integrator_i[0];
  rtb_CCaller_o13[1] = rtb_ome_wheels_idx_0;
  rtb_CCaller_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    b_j = 2;
    exitg1 = false;
    while ((!exitg1) && (b_j < 4)) {
      if (!rtIsNaN(rtb_CCaller_o13[b_j - 1])) {
        idx = b_j;
        exitg1 = true;
      } else {
        b_j++;
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

  rtb_k_p_idx_0 = (rtb_ome_wheels_idx_0 - rtb_Integrator_i[0]) / rtb_Sign;
  rtb_CCaller_o13[0] = rtb_Integrator_i[1];
  rtb_CCaller_o13[1] = rtb_ome_wheels_idx_1;
  rtb_CCaller_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    b_j = 2;
    exitg1 = false;
    while ((!exitg1) && (b_j < 4)) {
      if (!rtIsNaN(rtb_CCaller_o13[b_j - 1])) {
        idx = b_j;
        exitg1 = true;
      } else {
        b_j++;
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

  rtb_k_p_idx_1 = (rtb_ome_wheels_idx_1 - rtb_Integrator_i[1]) / rtb_Sign;
  rtb_CCaller_o13[0] = rtb_Integrator_i[2];
  rtb_CCaller_o13[1] = rtb_ome_wheels_idx_2;
  rtb_CCaller_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    b_j = 2;
    exitg1 = false;
    while ((!exitg1) && (b_j < 4)) {
      if (!rtIsNaN(rtb_CCaller_o13[b_j - 1])) {
        idx = b_j;
        exitg1 = true;
      } else {
        b_j++;
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

  rtb_k_p_idx_2 = (rtb_ome_wheels_idx_2 - rtb_Integrator_i[2]) / rtb_Sign;
  rtb_CCaller_o13[0] = rtb_Integrator_i[3];
  rtb_CCaller_o13[1] = rtb_ome_wheels_idx_3;
  rtb_CCaller_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    b_j = 2;
    exitg1 = false;
    while ((!exitg1) && (b_j < 4)) {
      if (!rtIsNaN(rtb_CCaller_o13[b_j - 1])) {
        idx = b_j;
        exitg1 = true;
      } else {
        b_j++;
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

  rtb_k_p_idx_3 = (rtb_ome_wheels_idx_3 - rtb_Integrator_i[3]) / rtb_Sign;

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
  rtb_k_e = (rtb_ome_wheels - rtDW.UD_DSTATE[0]) * 0.1019367991845056 *
    0.040000000000000036 + rtb_k_p_idx_0 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Minus[0] = -0.13600000000000004 - rtb_k_e;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_0 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_p_idx_0 = rtb_k_e;

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
  rtb_k_e = (rtb_ome_wheels - rtDW.UD_DSTATE[1]) * 0.1019367991845056 *
    0.040000000000000036 + rtb_k_p_idx_1 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Minus[1] = -0.13600000000000004 - rtb_k_e;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_1 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_p_idx_1 = rtb_k_e;

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
  rtb_k_e = (rtb_ome_wheels - rtDW.UD_DSTATE[2]) * 0.1019367991845056 *
    0.040000000000000036 + rtb_k_p_idx_2 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Minus[2] = -0.13600000000000004 - rtb_k_e;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_2 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_p_idx_2 = rtb_k_e;

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
  rtb_k_e = (rtb_ome_wheels - rtDW.UD_DSTATE[3]) * 0.1019367991845056 *
    0.040000000000000036 + rtb_k_p_idx_3 * 0.96;

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
  rtb_k_p_idx_3 = rtb_Minus[0] * 57.0 + rtDW.Integrator_DSTATE[0];

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_k_p_idx_3 > -4.9) {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_0 = -4.9;
  } else if (rtb_k_p_idx_3 < -21.0) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Switch: '<S70>/Switch2'
     */
    Switch2_idx_0 = -21.0;
  } else {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_0 = rtb_k_p_idx_3;
  }

  /* Sum: '<S72>/Sum' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Product: '<S67>/PProd Out'
   */
  rtb_Switch_n_idx_0 = rtb_k_p_idx_3;
  rtb_k_p_idx_3 = rtb_Minus[1] * 57.0 + rtDW.Integrator_DSTATE[1];

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_k_p_idx_3 > -4.9) {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_1 = -4.9;
  } else if (rtb_k_p_idx_3 < -21.0) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Switch: '<S70>/Switch2'
     */
    Switch2_idx_1 = -21.0;
  } else {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_1 = rtb_k_p_idx_3;
  }

  /* Sum: '<S72>/Sum' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Product: '<S67>/PProd Out'
   */
  rtb_Switch_n_idx_1 = rtb_k_p_idx_3;
  rtb_k_p_idx_3 = rtb_Minus[2] * 57.0 + rtDW.Integrator_DSTATE[2];

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_k_p_idx_3 > -4.9) {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_2 = -4.9;
  } else if (rtb_k_p_idx_3 < -21.0) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Switch: '<S70>/Switch2'
     */
    Switch2_idx_2 = -21.0;
  } else {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_2 = rtb_k_p_idx_3;
  }

  /* Sum: '<S72>/Sum' incorporates:
   *  Constant: '<S17>/Constant1'
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Product: '<S67>/PProd Out'
   *  Sum: '<S17>/Minus'
   */
  rtb_Switch_n_idx_2 = rtb_k_p_idx_3;
  rtb_k_p_idx_3 = (-0.13600000000000004 - rtb_k_e) * 57.0 +
    rtDW.Integrator_DSTATE[3];

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (rtb_k_p_idx_3 > -4.9) {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_3 = -4.9;
  } else if (rtb_k_p_idx_3 < -21.0) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Switch: '<S70>/Switch2'
     */
    Switch2_idx_3 = -21.0;
  } else {
    /* Switch: '<S70>/Switch2' */
    Switch2_idx_3 = rtb_k_p_idx_3;
  }

  /* Memory: '<S139>/Memory' incorporates:
   *  Switch: '<S21>/Switch2'
   */
  rtb_Switch2_c[0] = rtDW.Memory_PreviousInput[0];
  rtb_Switch2_c[1] = rtDW.Memory_PreviousInput[1];
  rtb_Switch2_c[2] = rtDW.Memory_PreviousInput[2];
  rtb_Switch2_c[3] = rtDW.Memory_PreviousInput[3];

  /* RateTransition: '<S152>/Rate Transition3' incorporates:
   *  Constant: '<S142>/Inertia Scaling'
   *  Constant: '<S142>/LMUy'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = rtb_front_wheel_angle_single__o;
  RateTransition3[1] = rtb_Switch;
  RateTransition3[2] = rtb_Switch_c;
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
  for (b_j = 0; b_j < 2; b_j++) {
    memcpy(&rtDW.CFunction[b_j * 13], &RateTransition3[0], 13U * sizeof(real_T));
  }

  /* End of CFunction: '<S152>/C Function' */

  /* Lookup_n-D: '<S281>/Max_Torque_Overload_Motor_LUT' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Lookup_n-D: '<S281>/Max_Torque_Overload_Inverter_LUT'
   *  Lookup_n-D: '<S282>/Display Overload Inverter LUT'
   *  Lookup_n-D: '<S282>/Display Overload Motor LUT'
   */
  rtb_Integrator_a_idx_0 = look1_binlx(0.0, rtConstP.pooled48, rtConstP.pooled47,
    2U);
  rtb_TmpSignalConversionAtSFun_e[0] = rtb_Integrator_a_idx_0;
  rtb_TmpSignalConversionAtSFun_e[1] = rtb_Integrator_a_idx_0;
  rtb_TmpSignalConversionAtSFun_e[2] = rtb_Integrator_a_idx_0;
  rtb_TmpSignalConversionAtSFun_e[3] = rtb_Integrator_a_idx_0;

  /* Lookup_n-D: '<S281>/Max_Torque_Overload_Inverter_LUT' */
  rtb_Integrator_i[0] = rtb_Integrator_a_idx_0;
  rtb_Integrator_i[1] = rtb_Integrator_a_idx_0;
  rtb_Integrator_i[2] = rtb_Integrator_a_idx_0;
  rtb_Integrator_i[3] = rtb_Integrator_a_idx_0;

  /* RelationalOperator: '<S290>/Compare' incorporates:
   *  Constant: '<S287>/Time constant'
   *  Constant: '<S290>/Constant'
   *  Sum: '<S287>/Sum1'
   */
  rtb_Compare = (0.079577471545947673 - rtDW.Probe[0] <= 0.0);

  /* Gain: '<S284>/Gain4' incorporates:
   *  Gain: '<S293>/Gain4'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_SumofElements1 = 128.91550390443524 * rtU.omega_wheels_FL;

  /* Saturate: '<S284>/Saturation1' incorporates:
   *  Gain: '<S284>/Gain4'
   */
  if (rtb_SumofElements1 <= 0.0) {
    rtb_Tnew[0] = 0.0;
  } else {
    rtb_Tnew[0] = rtb_SumofElements1;
  }

  /* Gain: '<S284>/Gain4' incorporates:
   *  Gain: '<S293>/Gain4'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  u0_tmp = 128.91550390443524 * rtU.omega_wheels_FR;

  /* Saturate: '<S284>/Saturation1' incorporates:
   *  Gain: '<S284>/Gain4'
   */
  if (u0_tmp <= 0.0) {
    rtb_Tnew[1] = 0.0;
  } else {
    rtb_Tnew[1] = u0_tmp;
  }

  /* Gain: '<S284>/Gain4' incorporates:
   *  Gain: '<S293>/Gain4'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  u0_tmp_0 = 128.91550390443524 * rtU.omega_wheels_RL;

  /* Saturate: '<S284>/Saturation1' incorporates:
   *  Gain: '<S284>/Gain4'
   */
  if (u0_tmp_0 <= 0.0) {
    rtb_Tnew[2] = 0.0;
  } else {
    rtb_Tnew[2] = u0_tmp_0;
  }

  /* Gain: '<S284>/Gain4' incorporates:
   *  Gain: '<S293>/Gain4'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0_tmp_1 = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S284>/Saturation1' incorporates:
   *  Gain: '<S284>/Gain4'
   */
  if (u0_tmp_1 <= 0.0) {
    rtb_Tnew[3] = 0.0;
  } else {
    rtb_Tnew[3] = u0_tmp_1;
  }

  /* Lookup_n-D: '<S284>/2-D Lookup Table' incorporates:
   *  Constant: '<S281>/Constant7'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &cumRevIndex);
  csumrev[1U] = cumRevIndex;
  bpIndices[0U] = plook_binc(rtb_Tnew[0], rtConstP.pooled14, 200U, &cumRevIndex);
  csumrev[0U] = cumRevIndex;
  rtb_Tnew[0] = intrp2d_l(bpIndices, csumrev, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_Tnew[1], rtConstP.pooled14, 200U, &cumRevIndex);
  csumrev[0U] = cumRevIndex;
  rtb_Tnew[1] = intrp2d_l(bpIndices, csumrev, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_Tnew[2], rtConstP.pooled14, 200U, &cumRevIndex);
  csumrev[0U] = cumRevIndex;
  rtb_Tnew[2] = intrp2d_l(bpIndices, csumrev, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_Tnew[3], rtConstP.pooled14, 200U, &cumRevIndex);
  csumrev[0U] = cumRevIndex;
  rtb_Tnew[3] = intrp2d_l(bpIndices, csumrev, rtConstP.pooled13, 201U);

  /* Gain: '<S284>/Gain' */
  rtb_ome_wheels_idx_3 = 0.0098000000000000014 * rtb_Tnew[0];
  rtb_Gain_idx_1 = 0.0098000000000000014 * rtb_Tnew[1];
  rtb_Gain_idx_2 = 0.0098000000000000014 * rtb_Tnew[2];
  rtb_Gain_idx_3 = 0.0098000000000000014 * rtb_Tnew[3];

  /* DiscreteIntegrator: '<S292>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE_a[0] = rtb_ome_wheels_idx_3;
    rtDW.Integrator_DSTATE_a[1] = rtb_Gain_idx_1;
    rtDW.Integrator_DSTATE_a[2] = rtb_Gain_idx_2;
    rtDW.Integrator_DSTATE_a[3] = rtb_Gain_idx_3;
  }

  if (rtb_Compare || (rtDW.Integrator_PrevResetState_i != 0)) {
    rtDW.Integrator_DSTATE_a[0] = rtb_ome_wheels_idx_3;
    rtDW.Integrator_DSTATE_a[1] = rtb_Gain_idx_1;
    rtDW.Integrator_DSTATE_a[2] = rtb_Gain_idx_2;
    rtDW.Integrator_DSTATE_a[3] = rtb_Gain_idx_3;
  }

  rtb_Integrator_idx_0 = rtDW.Integrator_DSTATE_a[0];
  rtb_Integrator_idx_1 = rtDW.Integrator_DSTATE_a[1];
  rtb_Integrator_idx_2 = rtDW.Integrator_DSTATE_a[2];
  rtb_Integrator_idx_3 = rtDW.Integrator_DSTATE_a[3];

  /* MinMax: '<S281>/Min' incorporates:
   *  Constant: '<S284>/Constant'
   *  DiscreteIntegrator: '<S292>/Integrator'
   *  RelationalOperator: '<S286>/LowerRelop1'
   *  RelationalOperator: '<S286>/UpperRelop'
   *  Switch: '<S286>/Switch'
   *  Switch: '<S286>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_a[0] > 21.0) {
    cumRevIndex = 21.0;
  } else if (rtDW.Integrator_DSTATE_a[0] < 0.0) {
    /* Switch: '<S286>/Switch' incorporates:
     *  Constant: '<S284>/Constant'
     */
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = rtDW.Integrator_DSTATE_a[0];
  }

  u0 = fmin(fmin(fmin(rtb_TmpSignalConversionAtSFun_e[0], rtb_Integrator_i[0]),
                 20.972), cumRevIndex);

  /* Saturate: '<S281>/Saturation_Positive' incorporates:
   *  MinMax: '<S281>/Min'
   */
  if (u0 <= 0.0) {
    rtb_TmpSignalConversionAtSFun_e[0] = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_e[0] = u0;
  }

  /* MinMax: '<S281>/Min' incorporates:
   *  Constant: '<S284>/Constant'
   *  DiscreteIntegrator: '<S292>/Integrator'
   *  RelationalOperator: '<S286>/LowerRelop1'
   *  RelationalOperator: '<S286>/UpperRelop'
   *  Switch: '<S286>/Switch'
   *  Switch: '<S286>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_a[1] > 21.0) {
    cumRevIndex = 21.0;
  } else if (rtDW.Integrator_DSTATE_a[1] < 0.0) {
    /* Switch: '<S286>/Switch' incorporates:
     *  Constant: '<S284>/Constant'
     */
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = rtDW.Integrator_DSTATE_a[1];
  }

  u0 = fmin(fmin(fmin(rtb_TmpSignalConversionAtSFun_e[1], rtb_Integrator_i[1]),
                 20.972), cumRevIndex);

  /* Saturate: '<S281>/Saturation_Positive' incorporates:
   *  MinMax: '<S281>/Min'
   */
  if (u0 <= 0.0) {
    rtb_TmpSignalConversionAtSFun_e[1] = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_e[1] = u0;
  }

  /* MinMax: '<S281>/Min' incorporates:
   *  Constant: '<S284>/Constant'
   *  DiscreteIntegrator: '<S292>/Integrator'
   *  RelationalOperator: '<S286>/LowerRelop1'
   *  RelationalOperator: '<S286>/UpperRelop'
   *  Switch: '<S286>/Switch'
   *  Switch: '<S286>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_a[2] > 21.0) {
    cumRevIndex = 21.0;
  } else if (rtDW.Integrator_DSTATE_a[2] < 0.0) {
    /* Switch: '<S286>/Switch' incorporates:
     *  Constant: '<S284>/Constant'
     */
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = rtDW.Integrator_DSTATE_a[2];
  }

  u0 = fmin(fmin(fmin(rtb_TmpSignalConversionAtSFun_e[2], rtb_Integrator_i[2]),
                 20.972), cumRevIndex);

  /* Saturate: '<S281>/Saturation_Positive' incorporates:
   *  MinMax: '<S281>/Min'
   */
  if (u0 <= 0.0) {
    rtb_TmpSignalConversionAtSFun_e[2] = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_e[2] = u0;
  }

  /* MinMax: '<S281>/Min' incorporates:
   *  Constant: '<S284>/Constant'
   *  DiscreteIntegrator: '<S292>/Integrator'
   *  RelationalOperator: '<S286>/LowerRelop1'
   *  RelationalOperator: '<S286>/UpperRelop'
   *  Switch: '<S286>/Switch'
   *  Switch: '<S286>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_a[3] > 21.0) {
    cumRevIndex = 21.0;
  } else if (rtDW.Integrator_DSTATE_a[3] < 0.0) {
    /* Switch: '<S286>/Switch' incorporates:
     *  Constant: '<S284>/Constant'
     */
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = rtDW.Integrator_DSTATE_a[3];
  }

  u0 = fmin(fmin(fmin(rtb_TmpSignalConversionAtSFun_e[3], rtb_Integrator_i[3]),
                 20.972), cumRevIndex);

  /* Saturate: '<S281>/Saturation_Positive' incorporates:
   *  MinMax: '<S281>/Min'
   */
  if (u0 <= 0.0) {
    rtb_TmpSignalConversionAtSFun_e[3] = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_e[3] = u0;
  }

  /* UnitDelay: '<S11>/Unit Delay1' */
  rtb_Tnew[0] = rtDW.UnitDelay1_DSTATE[0];
  rtb_Tnew[1] = rtDW.UnitDelay1_DSTATE[1];
  rtb_Tnew[2] = rtDW.UnitDelay1_DSTATE[2];
  rtb_Tnew[3] = rtDW.UnitDelay1_DSTATE[3];

  /* Math: '<S259>/Square1' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function2'
   *  Math: '<S259>/Square2'
   *  Math: '<S261>/Square1'
   */
  Faeroz_tmp = rtb_vx * rtb_vx;

  /* Gain: '<S259>/Lateral Load Transfer' incorporates:
   *  Gain: '<S260>/Lateral Load Transfer'
   *  Gain: '<S261>/Lateral Load Transfer'
   *  Gain: '<S262>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S259>/Unary Minus'
   */
  rtb_Saturation_c_idx_0 = 30.826771653543307 * -rtU.ay;

  /* Gain: '<S259>/Lift Force' incorporates:
   *  Gain: '<S260>/Lift Force'
   *  Math: '<S259>/Square1'
   */
  rtb_Saturation_c_idx_1 = Faeroz_tmp * 0.92446666666666677;

  /* Gain: '<S259>/Drag moment' incorporates:
   *  Gain: '<S260>/Drag moment'
   *  Gain: '<S261>/Drag moment'
   *  Gain: '<S262>/Drag moment'
   */
  rtb_Saturation_c_idx_2 = Faeroz_tmp * 0.21998117647058821;

  /* Gain: '<S259>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S260>/Longitudinal Load Transfer'
   *  Gain: '<S261>/Longitudinal Load Transfer'
   *  Gain: '<S262>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S259>/Unary Minus1'
   */
  rtb_Saturation_c_idx_3 = 25.588235294117645 * -rtU.ax;

  /* SignalConversion generated from: '<S251>/2-D Lookup Table' incorporates:
   *  Constant: '<S259>/Static Load Front'
   *  Constant: '<S260>/Static Load Front'
   *  Gain: '<S259>/Drag moment'
   *  Gain: '<S259>/Lateral Load Transfer'
   *  Gain: '<S259>/Lift Force'
   *  Gain: '<S259>/Longitudinal Load Transfer'
   *  Sum: '<S259>/Subtract'
   *  Sum: '<S260>/Subtract'
   */
  rtb_Integrator_i[0] = (((rtb_Saturation_c_idx_0 + 635.688) +
    rtb_Saturation_c_idx_1) - rtb_Saturation_c_idx_2) + rtb_Saturation_c_idx_3;
  rtb_Integrator_i[1] = (((635.688 - rtb_Saturation_c_idx_0) +
    rtb_Saturation_c_idx_1) - rtb_Saturation_c_idx_2) + rtb_Saturation_c_idx_3;

  /* Gain: '<S261>/Lift Force' incorporates:
   *  Gain: '<S262>/Lift Force'
   */
  rtb_Saturation_c_idx_1 = Faeroz_tmp * 0.74153333333333349;

  /* SignalConversion generated from: '<S251>/2-D Lookup Table' incorporates:
   *  Constant: '<S261>/Static Load Front'
   *  Constant: '<S262>/Static Load Front'
   *  Gain: '<S261>/Lift Force'
   *  Sum: '<S261>/Subtract'
   *  Sum: '<S262>/Subtract'
   */
  rtb_Integrator_i[2] = (((rtb_Saturation_c_idx_0 + 688.66200000000015) +
    rtb_Saturation_c_idx_1) + rtb_Saturation_c_idx_2) - rtb_Saturation_c_idx_3;
  rtb_Integrator_i[3] = (((688.66200000000015 - rtb_Saturation_c_idx_0) +
    rtb_Saturation_c_idx_1) + rtb_Saturation_c_idx_2) - rtb_Saturation_c_idx_3;

  /* Switch: '<S258>/Switch' incorporates:
   *  Constant: '<S258>/Constant'
   *  Sum: '<S263>/Subtract'
   *  Sum: '<S263>/Subtract1'
   *  Sum: '<S263>/Subtract2'
   *  Sum: '<S264>/Subtract'
   *  Sum: '<S264>/Subtract2'
   *  Sum: '<S265>/Subtract1'
   *  Trigonometry: '<S263>/Atan'
   *  Trigonometry: '<S264>/Atan'
   *  Trigonometry: '<S265>/Atan'
   *  Trigonometry: '<S266>/Atan'
   */
  if (rtb_vx > 3.0) {
    /* Sum: '<S263>/Subtract1' incorporates:
     *  Gain: '<S263>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S264>/Subtract1'
     */
    rtb_Saturation_c_idx_0 = 0.73439999999999994 * rtb_Gain1 + rtU.vy;

    /* Sum: '<S263>/Subtract' incorporates:
     *  Gain: '<S263>/Gain1'
     *  Sum: '<S265>/Subtract'
     */
    rtb_Saturation_c_idx_1 = rtb_vx - 0.635 * rtb_Gain1;
    rtb_UnaryMinus_k4[0] = rt_atan2d_snf(rtb_Saturation_c_idx_0,
      rtb_Saturation_c_idx_1) - rtb_Abs_o_idx_0;

    /* Sum: '<S264>/Subtract' incorporates:
     *  Gain: '<S264>/Gain1'
     *  Sum: '<S263>/Subtract'
     *  Sum: '<S263>/Subtract1'
     *  Sum: '<S263>/Subtract2'
     *  Sum: '<S266>/Subtract'
     *  Trigonometry: '<S263>/Atan'
     */
    rtb_Saturation_c_idx_2 = 0.635 * rtb_Gain1 + rtb_vx;
    rtb_UnaryMinus_k4[1] = rt_atan2d_snf(rtb_Saturation_c_idx_0,
      rtb_Saturation_c_idx_2) - rtb_Abs_c;

    /* Sum: '<S265>/Subtract1' incorporates:
     *  Gain: '<S265>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S264>/Subtract'
     *  Sum: '<S264>/Subtract2'
     *  Sum: '<S266>/Subtract1'
     *  Trigonometry: '<S264>/Atan'
     */
    rtb_Saturation_c_idx_0 = rtU.vy - 0.79560000000000008 * rtb_Gain1;
    rtb_UnaryMinus_k4[2] = rt_atan2d_snf(rtb_Saturation_c_idx_0,
      rtb_Saturation_c_idx_1);
    rtb_UnaryMinus_k4[3] = rt_atan2d_snf(rtb_Saturation_c_idx_0,
      rtb_Saturation_c_idx_2);
  } else {
    rtb_UnaryMinus_k4[0] = 0.0;
    rtb_UnaryMinus_k4[1] = 0.0;
    rtb_UnaryMinus_k4[2] = 0.0;
    rtb_UnaryMinus_k4[3] = 0.0;
  }

  /* End of Switch: '<S258>/Switch' */

  /* Lookup_n-D: '<S251>/2-D Lookup Table' */
  rtb_Saturation_c_idx_0 = look2_binlx(rtb_Integrator_i[0], rtb_UnaryMinus_k4[0],
    rtConstP.pooled55, rtConstP.pooled56, rtConstP.uDLookupTable_tableData_d,
    rtConstP.pooled73, 30U);
  rtb_Saturation_c_idx_1 = look2_binlx(rtb_Integrator_i[1], rtb_UnaryMinus_k4[1],
    rtConstP.pooled55, rtConstP.pooled56, rtConstP.uDLookupTable_tableData_d,
    rtConstP.pooled73, 30U);
  rtb_Saturation_c_idx_2 = look2_binlx(rtb_Integrator_i[2], rtb_UnaryMinus_k4[2],
    rtConstP.pooled55, rtConstP.pooled56, rtConstP.uDLookupTable_tableData_d,
    rtConstP.pooled73, 30U);
  rtb_Saturation_c_idx_3 = look2_binlx(rtb_Integrator_i[3], rtb_UnaryMinus_k4[3],
    rtConstP.pooled55, rtConstP.pooled56, rtConstP.uDLookupTable_tableData_d,
    rtConstP.pooled73, 30U);

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

  /* Switch: '<S245>/Switch' */
  cumRevIndex = !(rtb_Sign > 0.95);

  /* Saturate: '<S251>/Saturation1' incorporates:
   *  Gain: '<S251>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_c_idx_0;
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S245>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_TmpSignalConversionAtSFun_e[0] = fmin(fmin
    (rtb_TmpSignalConversionAtSFun_e[0], rtDW.UnitDelay1_DSTATE[0]), u0) *
    cumRevIndex;

  /* Saturate: '<S251>/Saturation1' incorporates:
   *  Gain: '<S251>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_c_idx_1;
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S245>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_TmpSignalConversionAtSFun_e[1] = fmin(fmin
    (rtb_TmpSignalConversionAtSFun_e[1], rtDW.UnitDelay1_DSTATE[1]), u0) *
    cumRevIndex;

  /* Saturate: '<S251>/Saturation1' incorporates:
   *  Gain: '<S251>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_c_idx_2;
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S245>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_TmpSignalConversionAtSFun_e[2] = fmin(fmin
    (rtb_TmpSignalConversionAtSFun_e[2], rtDW.UnitDelay1_DSTATE[2]), u0) *
    cumRevIndex;

  /* Saturate: '<S251>/Saturation1' incorporates:
   *  Gain: '<S251>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_Saturation_c_idx_3;
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S245>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_TmpSignalConversionAtSFun_e[3] = fmin(fmin
    (rtb_TmpSignalConversionAtSFun_e[3], rtDW.UnitDelay1_DSTATE[3]), u0) *
    cumRevIndex;

  /* Lookup_n-D: '<S251>/2-D Lookup Table1' */
  rtb_Integrator_i[0] = look2_binlx(rtb_Integrator_i[0], rtb_UnaryMinus_k4[0],
    rtConstP.pooled55, rtConstP.pooled56, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled73, 30U);
  rtb_Integrator_i[1] = look2_binlx(rtb_Integrator_i[1], rtb_UnaryMinus_k4[1],
    rtConstP.pooled55, rtConstP.pooled56, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled73, 30U);
  rtb_Integrator_i[2] = look2_binlx(rtb_Integrator_i[2], rtb_UnaryMinus_k4[2],
    rtConstP.pooled55, rtConstP.pooled56, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled73, 30U);
  rtb_Integrator_i[3] = look2_binlx(rtb_Integrator_i[3], rtb_UnaryMinus_k4[3],
    rtConstP.pooled55, rtConstP.pooled56, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled73, 30U);

  /* Product: '<S251>/Product1' incorporates:
   *  Gain: '<S251>/Gain1'
   */
  rtb_Product1[0] = 0.017407407407407406 * rtb_Integrator_i[0];
  rtb_Product1[1] = 0.017407407407407406 * rtb_Integrator_i[1];
  rtb_Product1[2] = 0.017407407407407406 * rtb_Integrator_i[2];
  rtb_Product1[3] = 0.017407407407407406 * rtb_Integrator_i[3];

  /* Lookup_n-D: '<S282>/Display Overload Motor LUT' */
  rtb_UnaryMinus_k4[0] = rtb_Integrator_a_idx_0;
  rtb_UnaryMinus_k4[1] = rtb_Integrator_a_idx_0;
  rtb_UnaryMinus_k4[2] = rtb_Integrator_a_idx_0;
  rtb_UnaryMinus_k4[3] = rtb_Integrator_a_idx_0;

  /* Lookup_n-D: '<S282>/Display Overload Inverter LUT' */
  rtb_Tnew[0] = rtb_Integrator_a_idx_0;
  rtb_Tnew[1] = rtb_Integrator_a_idx_0;
  rtb_Tnew[2] = rtb_Integrator_a_idx_0;
  rtb_Tnew[3] = rtb_Integrator_a_idx_0;

  /* RelationalOperator: '<S299>/Compare' incorporates:
   *  Constant: '<S296>/Time constant'
   *  Constant: '<S299>/Constant'
   *  Sum: '<S296>/Sum1'
   */
  rtb_Compare_c = (0.079577471545947673 - rtDW.Probe_g[0] <= 0.0);

  /* Saturate: '<S293>/Saturation1' */
  if (rtb_SumofElements1 <= 0.0) {
    rtb_Integrator_i[0] = 0.0;
  } else {
    rtb_Integrator_i[0] = rtb_SumofElements1;
  }

  if (u0_tmp <= 0.0) {
    rtb_Integrator_i[1] = 0.0;
  } else {
    rtb_Integrator_i[1] = u0_tmp;
  }

  if (u0_tmp_0 <= 0.0) {
    rtb_Integrator_i[2] = 0.0;
  } else {
    rtb_Integrator_i[2] = u0_tmp_0;
  }

  if (u0_tmp_1 <= 0.0) {
    rtb_Integrator_i[3] = 0.0;
  } else {
    rtb_Integrator_i[3] = u0_tmp_1;
  }

  /* End of Saturate: '<S293>/Saturation1' */

  /* Lookup_n-D: '<S293>/2-D Lookup Table' incorporates:
   *  Constant: '<S282>/Constant7'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &cumRevIndex);
  fractions[1U] = cumRevIndex;
  bpIndices_0[0U] = plook_binc(rtb_Integrator_i[0], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_Integrator_i[0] = intrp2d_l(bpIndices_0, fractions, rtConstP.pooled13,
    201U);
  bpIndices_0[0U] = plook_binc(rtb_Integrator_i[1], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_Integrator_i[1] = intrp2d_l(bpIndices_0, fractions, rtConstP.pooled13,
    201U);
  bpIndices_0[0U] = plook_binc(rtb_Integrator_i[2], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_Integrator_i[2] = intrp2d_l(bpIndices_0, fractions, rtConstP.pooled13,
    201U);
  bpIndices_0[0U] = plook_binc(rtb_Integrator_i[3], rtConstP.pooled14, 200U,
    &cumRevIndex);
  fractions[0U] = cumRevIndex;
  rtb_Integrator_i[3] = intrp2d_l(bpIndices_0, fractions, rtConstP.pooled13,
    201U);

  /* Gain: '<S293>/Gain' */
  rtb_Saturation_c_idx_0 = 0.0098000000000000014 * rtb_Integrator_i[0];
  rtb_Saturation_c_idx_1 = 0.0098000000000000014 * rtb_Integrator_i[1];
  rtb_Saturation_c_idx_2 = 0.0098000000000000014 * rtb_Integrator_i[2];
  rtb_Saturation_c_idx_3 = 0.0098000000000000014 * rtb_Integrator_i[3];

  /* DiscreteIntegrator: '<S301>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_m != 0) {
    rtDW.Integrator_DSTATE_e[0] = rtb_Saturation_c_idx_0;
    rtDW.Integrator_DSTATE_e[1] = rtb_Saturation_c_idx_1;
    rtDW.Integrator_DSTATE_e[2] = rtb_Saturation_c_idx_2;
    rtDW.Integrator_DSTATE_e[3] = rtb_Saturation_c_idx_3;
  }

  if (rtb_Compare_c || (rtDW.Integrator_PrevResetState_c != 0)) {
    rtDW.Integrator_DSTATE_e[0] = rtb_Saturation_c_idx_0;
    rtDW.Integrator_DSTATE_e[1] = rtb_Saturation_c_idx_1;
    rtDW.Integrator_DSTATE_e[2] = rtb_Saturation_c_idx_2;
    rtDW.Integrator_DSTATE_e[3] = rtb_Saturation_c_idx_3;
  }

  rtb_Integrator_a_idx_0 = rtDW.Integrator_DSTATE_e[0];
  rtb_Integrator_a_idx_1 = rtDW.Integrator_DSTATE_e[1];
  rtb_Integrator_a_idx_2 = rtDW.Integrator_DSTATE_e[2];
  rtb_Integrator_a_idx_3 = rtDW.Integrator_DSTATE_e[3];

  /* Sum: '<S267>/Subtract' incorporates:
   *  Gain: '<S267>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[0] + rtb_Product1[0];

  /* Switch: '<S295>/Switch2' incorporates:
   *  Constant: '<S293>/Constant'
   *  DiscreteIntegrator: '<S301>/Integrator'
   *  RelationalOperator: '<S295>/LowerRelop1'
   *  RelationalOperator: '<S295>/UpperRelop'
   *  Switch: '<S295>/Switch'
   */
  if (rtDW.Integrator_DSTATE_e[0] > 21.0) {
    cumRevIndex = 21.0;
  } else if (rtDW.Integrator_DSTATE_e[0] < 0.0) {
    /* Switch: '<S295>/Switch' incorporates:
     *  Constant: '<S293>/Constant'
     */
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = rtDW.Integrator_DSTATE_e[0];
  }

  /* MinMax: '<S282>/Min1' */
  rtb_Integrator_ac = fmin(fmin(fmin(rtb_UnaryMinus_k4[0], rtb_Tnew[0]), 20.972),
    cumRevIndex);

  /* Saturate: '<S251>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S282>/Saturation_Positive' */
  if (rtb_Integrator_ac <= 0.0) {
    rtb_Integrator_ac = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Integrator_i[0] = fmax(fmax(u0, -rtb_Integrator_ac),
    rtDW.UnitDelay2_DSTATE[0]);

  /* Sum: '<S267>/Subtract' incorporates:
   *  Gain: '<S267>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[1] + rtb_Product1[1];

  /* Switch: '<S295>/Switch2' incorporates:
   *  Constant: '<S293>/Constant'
   *  DiscreteIntegrator: '<S301>/Integrator'
   *  RelationalOperator: '<S295>/LowerRelop1'
   *  RelationalOperator: '<S295>/UpperRelop'
   *  Switch: '<S295>/Switch'
   */
  if (rtDW.Integrator_DSTATE_e[1] > 21.0) {
    cumRevIndex = 21.0;
  } else if (rtDW.Integrator_DSTATE_e[1] < 0.0) {
    /* Switch: '<S295>/Switch' incorporates:
     *  Constant: '<S293>/Constant'
     */
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = rtDW.Integrator_DSTATE_e[1];
  }

  /* MinMax: '<S282>/Min1' */
  rtb_Integrator_ac = fmin(fmin(fmin(rtb_UnaryMinus_k4[1], rtb_Tnew[1]), 20.972),
    cumRevIndex);

  /* Saturate: '<S251>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S282>/Saturation_Positive' */
  if (rtb_Integrator_ac <= 0.0) {
    rtb_Integrator_ac = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Integrator_i[1] = fmax(fmax(u0, -rtb_Integrator_ac),
    rtDW.UnitDelay2_DSTATE[1]);

  /* Sum: '<S267>/Subtract' incorporates:
   *  Gain: '<S267>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[2] + rtb_Product1[2];

  /* Switch: '<S295>/Switch2' incorporates:
   *  Constant: '<S293>/Constant'
   *  DiscreteIntegrator: '<S301>/Integrator'
   *  RelationalOperator: '<S295>/LowerRelop1'
   *  RelationalOperator: '<S295>/UpperRelop'
   *  Switch: '<S295>/Switch'
   */
  if (rtDW.Integrator_DSTATE_e[2] > 21.0) {
    cumRevIndex = 21.0;
  } else if (rtDW.Integrator_DSTATE_e[2] < 0.0) {
    /* Switch: '<S295>/Switch' incorporates:
     *  Constant: '<S293>/Constant'
     */
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = rtDW.Integrator_DSTATE_e[2];
  }

  /* MinMax: '<S282>/Min1' */
  rtb_Integrator_ac = fmin(fmin(fmin(rtb_UnaryMinus_k4[2], rtb_Tnew[2]), 20.972),
    cumRevIndex);

  /* Saturate: '<S251>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S282>/Saturation_Positive' */
  if (rtb_Integrator_ac <= 0.0) {
    rtb_Integrator_ac = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Integrator_i[2] = fmax(fmax(u0, -rtb_Integrator_ac),
    rtDW.UnitDelay2_DSTATE[2]);

  /* Sum: '<S267>/Subtract' incorporates:
   *  Gain: '<S267>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[3] + rtb_Product1[3];

  /* Switch: '<S295>/Switch2' incorporates:
   *  Constant: '<S293>/Constant'
   *  DiscreteIntegrator: '<S301>/Integrator'
   *  RelationalOperator: '<S295>/LowerRelop1'
   *  RelationalOperator: '<S295>/UpperRelop'
   *  Switch: '<S295>/Switch'
   */
  if (rtDW.Integrator_DSTATE_e[3] > 21.0) {
    cumRevIndex = 21.0;
  } else if (rtDW.Integrator_DSTATE_e[3] < 0.0) {
    /* Switch: '<S295>/Switch' incorporates:
     *  Constant: '<S293>/Constant'
     */
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = rtDW.Integrator_DSTATE_e[3];
  }

  /* MinMax: '<S282>/Min1' */
  rtb_Integrator_ac = fmin(fmin(fmin(rtb_UnaryMinus_k4[3], rtb_Tnew[3]), 20.972),
    cumRevIndex);

  /* Saturate: '<S251>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S282>/Saturation_Positive' */
  if (rtb_Integrator_ac <= 0.0) {
    rtb_Integrator_ac = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Integrator_i[3] = fmax(fmax(u0, -rtb_Integrator_ac),
    rtDW.UnitDelay2_DSTATE[3]);

  /* CombinatorialLogic: '<S253>/Logic' incorporates:
   *  Constant: '<S244>/Constant'
   *  Constant: '<S244>/Constant1'
   *  Memory: '<S253>/Memory'
   *  RelationalOperator: '<S244>/Less Than'
   *  RelationalOperator: '<S244>/Less Than1'
   */
  idx = (int32_T)(((((uint32_T)(rtb_Switch <= -0.6) << 1) + (rtb_Switch >= -0.5))
                   << 1) + rtDW.Memory_PreviousInput_k);
  rtb_Logic_idx_0 = rtConstP.pooled76[(uint32_T)idx];
  rtb_Logic_idx_1 = rtConstP.pooled76[idx + 8U];

  /* CombinatorialLogic: '<S254>/Logic' incorporates:
   *  Constant: '<S244>/Constant'
   *  Constant: '<S244>/Constant1'
   *  Memory: '<S254>/Memory'
   *  RelationalOperator: '<S244>/Less Than'
   *  RelationalOperator: '<S244>/Less Than1'
   */
  idx = (int32_T)(((((uint32_T)(rtb_Switch_c <= -0.6) << 1) + (rtb_Switch_c >=
    -0.5)) << 1) + rtDW.Memory_PreviousInput_kk);
  rtb_Logic_a_idx_0 = rtConstP.pooled76[(uint32_T)idx];
  rtb_Logic_a_idx_1 = rtConstP.pooled76[idx + 8U];

  /* CombinatorialLogic: '<S255>/Logic' incorporates:
   *  Constant: '<S244>/Constant'
   *  Constant: '<S244>/Constant1'
   *  Memory: '<S255>/Memory'
   *  RelationalOperator: '<S244>/Less Than'
   *  RelationalOperator: '<S244>/Less Than1'
   */
  idx = (int32_T)(((((uint32_T)(rtb_RL <= -0.6) << 1) + (rtb_RL >= -0.5)) << 1)
                  + rtDW.Memory_PreviousInput_b);
  rtb_Logic_i_idx_0 = rtConstP.pooled76[(uint32_T)idx];
  rtb_Logic_i_idx_1 = rtConstP.pooled76[idx + 8U];

  /* CombinatorialLogic: '<S256>/Logic' incorporates:
   *  Constant: '<S244>/Constant'
   *  Constant: '<S244>/Constant1'
   *  Memory: '<S256>/Memory'
   *  RelationalOperator: '<S244>/Less Than'
   *  RelationalOperator: '<S244>/Less Than1'
   */
  idx = (int32_T)(((((uint32_T)(rtb_RR <= -0.6) << 1) + (rtb_RR >= -0.5)) << 1)
                  + rtDW.Memory_PreviousInput_a);
  rtb_Logic_m_idx_0 = rtConstP.pooled76[(uint32_T)idx];

  /* Product: '<S244>/Product' incorporates:
   *  CombinatorialLogic: '<S256>/Logic'
   */
  rtb_Tnew[0] = rtb_Integrator_i[0] * (real_T)rtb_Logic_idx_1;
  rtb_Tnew[1] = rtb_Integrator_i[1] * (real_T)rtb_Logic_a_idx_1;
  rtb_Tnew[2] = (real_T)rtb_Logic_i_idx_1 * rtb_Integrator_i[2];
  rtb_Tnew[3] = (real_T)rtConstP.pooled76[idx + 8U] * rtb_Integrator_i[3];

  /* Abs: '<S171>/Abs' */
  rtb_Integrator_ac = fabs(rtb_front_wheel_angle_single__o);

  /* MATLABSystem: '<S171>/Moving Average' */
  if (rtDW.obj_o.TunablePropsChanged) {
    rtDW.obj_o.TunablePropsChanged = false;
  }

  obj = rtDW.obj_o.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  csumrev[0] = obj->pCumSumRev[0];
  csumrev[1] = obj->pCumSumRev[1];
  modValueRev = obj->pModValueRev;
  z = 0.0;
  u0_tmp_0 = 0.0;
  csum += rtb_Integrator_ac;
  if (modValueRev == 0.0) {
    z = csumrev[(int32_T)cumRevIndex - 1] + csum;
  }

  csumrev[(int32_T)cumRevIndex - 1] = rtb_Integrator_ac;
  if (cumRevIndex != 2.0) {
    cumRevIndex = 2.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    csumrev[0] += csumrev[1];
  }

  if (modValueRev == 0.0) {
    u0_tmp_0 = z / 3.0;
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = csumrev[0];
  obj->pCumSumRev[1] = csumrev[1];
  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* CombinatorialLogic: '<S228>/Logic' incorporates:
   *  Constant: '<S171>/Constant1'
   *  Constant: '<S171>/Constant4'
   *  MATLABSystem: '<S171>/Moving Average'
   *  Memory: '<S228>/Memory'
   *  RelationalOperator: '<S171>/Less Than'
   *  RelationalOperator: '<S171>/Less Than2'
   */
  rtb_Logic_idx_1 = rtConstP.pooled76[((((uint32_T)(0.026179938779914941 <=
    rtb_Integrator_ac) << 1) + (u0_tmp_0 < 0.0043633231299858239)) << 1) +
    rtDW.Memory_PreviousInput_n];

  /* SignalConversion generated from: '<S248>/ SFunction ' incorporates:
   *  MATLAB Function: '<S150>/Cross Check'
   */
  rtb_Integrator_ac = rtb_Tnew[1];

  /* MATLAB Function: '<S150>/Cross Check' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/throttle'
   */
  rtb_Integrator_i[0] = rtb_Tnew[0];
  rtb_Integrator_i[1] = rtb_Tnew[1];
  rtb_Integrator_i[2] = rtb_Tnew[2];
  rtb_Integrator_i[3] = rtb_Tnew[3];
  if (rtb_Logic_idx_1) {
    idx = 0;
  } else {
    idx = 1;
  }

  if (idx == 0) {
    if (rtb_Tnew[0] > rtb_TmpSignalConversionAtSFun_e[0]) {
      rtb_Integrator_i[0] = rtb_TmpSignalConversionAtSFun_e[0] -
        rtb_Integrator_ac;
    }

    if (rtb_Tnew[1] > rtb_TmpSignalConversionAtSFun_e[1]) {
      rtb_Integrator_i[1] = rtb_TmpSignalConversionAtSFun_e[1] -
        rtb_Integrator_ac;
    }

    if (rtb_Tnew[2] > rtb_TmpSignalConversionAtSFun_e[2]) {
      rtb_Integrator_i[2] = rtb_TmpSignalConversionAtSFun_e[2] -
        rtb_Integrator_ac;
    }

    if (rtb_Tnew[3] > rtb_TmpSignalConversionAtSFun_e[3]) {
      rtb_Integrator_i[3] = rtb_TmpSignalConversionAtSFun_e[3] -
        rtb_Integrator_ac;
    }
  } else if (rtU.throttle > 0.05) {
    rtb_Integrator_i[0] = 0.0;
    rtb_Integrator_i[1] = 0.0;
    rtb_Integrator_i[2] = 0.0;
    rtb_Integrator_i[3] = 0.0;
  } else if (rtU.brake > 0.05) {
    rtb_TmpSignalConversionAtSFun_e[0] = 0.0;
    rtb_TmpSignalConversionAtSFun_e[1] = 0.0;
    rtb_TmpSignalConversionAtSFun_e[2] = 0.0;
    rtb_TmpSignalConversionAtSFun_e[3] = 0.0;
  }

  /* CFunction: '<S246>/C Function' incorporates:
   *  Constant: '<S246>/Constant3'
   */
  rtDW.CFunction_d[0] = rtb_Integrator_i[0];
  rtDW.CFunction_d[1] = rtb_Integrator_i[1];
  rtDW.CFunction_d[2] = rtb_Integrator_i[2];
  rtDW.CFunction_d[3] = rtb_Integrator_i[3];

  /* CFunction: '<S247>/C Function' incorporates:
   *  Constant: '<S247>/Constant3'
   */
  rtDW.CFunction_f[0] = rtb_TmpSignalConversionAtSFun_e[0];
  rtDW.CFunction_f[1] = rtb_TmpSignalConversionAtSFun_e[1];
  rtDW.CFunction_f[2] = rtb_TmpSignalConversionAtSFun_e[2];
  rtDW.CFunction_f[3] = rtb_TmpSignalConversionAtSFun_e[3];

  /* Sum: '<S229>/Sum of Elements' */
  cumRevIndex = ((rtDW.CFunction_f[0] + rtDW.CFunction_f[1]) + rtDW.CFunction_f
                 [2]) + rtDW.CFunction_f[3];

  /* Product: '<S229>/Product' incorporates:
   *  Constant: '<S229>/Constant1'
   *  Constant: '<S229>/Constant2'
   *  Constant: '<S237>/Constant'
   *  Constant: '<S237>/Exponent < 0'
   *  Gain: '<S229>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S229>/ '
   *  Math: '<S237>/Power'
   *  Product: '<S229>/Product1'
   *  Product: '<S237>/Divide'
   *  Product: '<S237>/Divide1'
   *  RelationalOperator: '<S229>/Less Than'
   *  RelationalOperator: '<S229>/Less Than1'
   *  Sum: '<S229>/Subtract1'
   *  Sum: '<S237>/Subtract'
   *  Sum: '<S237>/Sum'
   */
  rtb_Integrator_ac = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle),
    -1.5) + 1.0) - rtb_Sign) * (real_T)(int8_T)((int8_T)(rtb_Sign >= 0.05) ^
    (int8_T)(rtU.throttle >= 0.05)) * 84.0;

  /* Switch: '<S238>/Switch2' incorporates:
   *  RelationalOperator: '<S238>/LowerRelop1'
   */
  if (!(rtb_Integrator_ac > cumRevIndex)) {
    /* Sum: '<S229>/Sum of Elements1' */
    rtb_SumofElements1 = ((rtDW.CFunction_d[0] + rtDW.CFunction_d[1]) +
                          rtDW.CFunction_d[2]) + rtDW.CFunction_d[3];

    /* Switch: '<S238>/Switch' incorporates:
     *  RelationalOperator: '<S238>/UpperRelop'
     */
    if (rtb_Integrator_ac < rtb_SumofElements1) {
      cumRevIndex = rtb_SumofElements1;
    } else {
      cumRevIndex = rtb_Integrator_ac;
    }

    /* End of Switch: '<S238>/Switch' */
  }

  /* End of Switch: '<S238>/Switch2' */

  /* Gain: '<S229>/Gain2' */
  modValueRev = 0.95 * cumRevIndex;

  /* Gain: '<S229>/Gain3' */
  z = 1.05 * cumRevIndex;

  /* Switch: '<S230>/Switch2' incorporates:
   *  Constant: '<S230>/Engine Brake'
   *  Constant: '<S239>/Constant1'
   *  Constant: '<S239>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S239>/AND'
   *  MinMax: '<S230>/Max1'
   *  RelationalOperator: '<S239>/Less Than'
   *  RelationalOperator: '<S239>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_Sign)) {
    rtb_Integrator_ac = -0.0;
  } else {
    rtb_Integrator_ac = fmin(modValueRev, z);
  }

  /* End of Switch: '<S230>/Switch2' */

  /* InitialCondition: '<S232>/IC' */
  rtDW.IC_FirstOutputTime = false;

  /* MATLAB Function: '<S146>/MATLAB Function4' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function3'
   *  MATLAB Function: '<S148>/MATLAB Function'
   */
  rtb_Abs_o_idx_0 = 0.765 * sin(rtb_Abs_o_idx_0) - 0.635 * cos(rtb_Abs_o_idx_0);
  rtb_Abs_c = 0.765 * sin(rtb_Abs_c) + 0.635 * cos(rtb_Abs_c);
  csum = ((rtb_Abs_o_idx_0 * rtDW.CFunction_d[0] + rtb_Abs_c * rtDW.CFunction_f
           [1]) - 0.635 * rtDW.CFunction_d[2]) + 0.635 * rtDW.CFunction_f[3];

  /* Outputs for IfAction SubSystem: '<S140>/YRD_LUT_-3' incorporates:
   *  ActionPort: '<S276>/Action Port'
   */
  /* If: '<S140>/If' */
  YRD_LUT_3(rtb_front_wheel_angle_single__o, rtb_vx, &rtDW.yaw_rate_desired_LUT);

  /* End of Outputs for SubSystem: '<S140>/YRD_LUT_-3' */

  /* Outputs for IfAction SubSystem: '<S140>/YRD_LUT_-1' incorporates:
   *  ActionPort: '<S273>/Action Port'
   */
  /* If: '<S140>/If1' */
  YRD_LUT_3(rtb_front_wheel_angle_single__o, rtb_vx,
            &rtDW.yaw_rate_desired_LUT_h);

  /* End of Outputs for SubSystem: '<S140>/YRD_LUT_-1' */

  /* MATLAB Function: '<S140>/MATLAB Function' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_SumofElements1 = (1.0 - rtU.brake) * rtDW.yaw_rate_desired_LUT_h +
    rtDW.yaw_rate_desired_LUT * rtU.brake;

  /* SignalConversion generated from: '<S166>/ SFunction ' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function2'
   */
  rtb_Integrator_i[0] = rtb_Switch;
  rtb_Integrator_i[1] = rtb_Switch_c;
  rtb_Integrator_i[2] = rtb_RL;
  rtb_Integrator_i[3] = rtb_RR;

  /* MATLAB Function: '<S146>/MATLAB Function2' incorporates:
   *  Constant: '<S146>/Constant'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/vy'
   *  Sum: '<S169>/Sum1'
   *  Sum: '<S169>/Sum2'
   */
  rtb_Switch = Faeroz_tmp * 3.14825;
  rtb_RR_tmp = rtb_Gain1 * 1.27 / 2.0;
  u0 = rtb_Gain1 * 0.73439999999999994 + rtU.vy;
  rtb_Sign = rtb_vx - rtb_RR_tmp;
  rtb_RR = atan(u0 / rtb_Sign) - rtb_front_wheel_angle_single__o;
  u0_tmp_1 = rtb_RR_tmp + rtb_vx;
  rtb_RL = atan(u0 / u0_tmp_1) - rtb_front_wheel_angle_single__o;
  u0_tmp_0 = rtU.vy - rtb_Gain1 * 0.79560000000000008;
  cumRevIndex = atan(u0_tmp_0 / rtb_Sign);
  rtb_front_wheel_angle_single__o = atan(u0_tmp_0 / u0_tmp_1);
  u0_tmp = 0.5 * rtb_Switch * 0.55490196078431375;
  rtb_Switch_c = Faeroz_tmp * 1.0461500000000001 * 0.5 / 1.53 * 0.576;
  u0_tmp_1 = (((635.688 - 30.826771653543307 * rtU.ay) + u0_tmp) - rtb_Switch_c)
    - 25.588235294117645 * rtU.ax;
  u0_tmp_0 = (((30.826771653543307 * rtU.ay + 635.688) + u0_tmp) - rtb_Switch_c)
    - 25.588235294117645 * rtU.ax;
  Faeroz_tmp = 0.5 * rtb_Switch * 0.4450980392156863;
  rtb_Switch = (((688.66200000000015 - 30.826771653543307 * rtU.ay) + Faeroz_tmp)
                + rtb_Switch_c) + 25.588235294117645 * rtU.ax;
  rtb_Switch_c = (((30.826771653543307 * rtU.ay + 688.66200000000015) +
                   Faeroz_tmp) + rtb_Switch_c) + 25.588235294117645 * rtU.ax;
  Faeroz_tmp = 12.4 * rtb_RR - 0.512;
  u_tmp = (1.14E-6 * u0_tmp_1 - rtb_RR) + 0.00239;
  if (u_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  rtb_RR_tmp_tmp = 0.000282 * u0_tmp_1 - 2.02;
  rtb_RR_tmp = sin(atan(0.000559 * u0_tmp_1) * 2.0) * 34500.0 * u_tmp / (1.34 *
    u0_tmp_1 * 0.8 * rtb_RR_tmp_tmp - 0.01);
  rtb_Sign = 0.0013 * u0_tmp_1 - 2.33;
  u0 = sqrt(Faeroz_tmp * Faeroz_tmp + 1.0);
  u_tmp = (3.86E-7 * u0_tmp_1 + 0.000205) * 13.9 / u0;
  rtb_RR = (sin(atan(rtb_RR_tmp - (0.26 * u0_tmp + 1.0) * (3.99E-5 * u0_tmp_1 -
    0.521) * (atan(rtb_RR_tmp) - rtb_RR_tmp)) * 1.34) * (u0_tmp_1 * 0.8) *
            rtb_RR_tmp_tmp + (7.1E-5 * u0_tmp_1 - 0.149) * (u0_tmp_1 * 0.8)) *
    cos(atan((atan(((3.86E-7 * u0_tmp_1 - rtb_Integrator_i[0]) + 0.000205) *
                   13.9 / u0) - ((3.86E-7 * u0_tmp_1 - rtb_Integrator_i[0]) +
           0.000205) * 13.9 / sqrt(Faeroz_tmp * Faeroz_tmp + 1.0)) * rtb_Sign +
             ((3.86E-7 * u0_tmp_1 - rtb_Integrator_i[0]) + 0.000205) * 13.9 /
             sqrt(Faeroz_tmp * Faeroz_tmp + 1.0)) * 0.958) / cos(atan((atan
    (u_tmp) - u_tmp) * rtb_Sign + u_tmp) * 0.958) - sin(atan(16.1 *
    rtb_Integrator_i[0]) * 1.94) * (u0_tmp_1 * 0.8) * rtb_RR_tmp_tmp * (1.03E-5 *
    u0_tmp_1 - 0.000288) / sqrt(rtb_RR * rtb_RR * 225.0 + 1.0);
  Faeroz_tmp = 12.4 * rtb_RL - 0.512;
  u_tmp = (1.14E-6 * u0_tmp_0 - rtb_RL) + 0.00239;
  if (u_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  rtb_Sign = 0.000282 * u0_tmp_0 - 2.02;
  u0_tmp_1 = sin(atan(0.000559 * u0_tmp_0) * 2.0) * 34500.0 * u_tmp / (1.34 *
    u0_tmp_0 * 0.8 * rtb_Sign - 0.01);
  rtb_RR_tmp = 0.0013 * u0_tmp_0 - 2.33;
  rtb_RR_tmp_tmp = sqrt(Faeroz_tmp * Faeroz_tmp + 1.0);
  u0 = (3.86E-7 * u0_tmp_0 + 0.000205) * 13.9 / rtb_RR_tmp_tmp;
  rtb_RL = (sin(atan(u0_tmp_1 - (0.26 * u0_tmp + 1.0) * (3.99E-5 * u0_tmp_0 -
    0.521) * (atan(u0_tmp_1) - u0_tmp_1)) * 1.34) * (u0_tmp_0 * 0.8) * rtb_Sign
            + (7.1E-5 * u0_tmp_0 - 0.149) * (u0_tmp_0 * 0.8)) * cos(atan((atan
    (((3.86E-7 * u0_tmp_0 - rtb_Integrator_i[1]) + 0.000205) * 13.9 /
     rtb_RR_tmp_tmp) - ((3.86E-7 * u0_tmp_0 - rtb_Integrator_i[1]) + 0.000205) *
    13.9 / sqrt(Faeroz_tmp * Faeroz_tmp + 1.0)) * rtb_RR_tmp + ((3.86E-7 *
    u0_tmp_0 - rtb_Integrator_i[1]) + 0.000205) * 13.9 / sqrt(Faeroz_tmp *
    Faeroz_tmp + 1.0)) * 0.958) / cos(atan((atan(u0) - u0) * rtb_RR_tmp + u0) *
    0.958) - sin(atan(16.1 * rtb_Integrator_i[1]) * 1.94) * (u0_tmp_0 * 0.8) *
    rtb_Sign * (1.03E-5 * u0_tmp_0 - 0.000288) / sqrt(rtb_RL * rtb_RL * 225.0 +
    1.0);
  rtb_Sign = 12.4 * cumRevIndex - 0.512;
  u0 = 12.4 * rtb_front_wheel_angle_single__o - 0.512;
  u_tmp = (1.14E-6 * rtb_Switch - cumRevIndex) + 0.00239;
  Faeroz_tmp = (1.14E-6 * rtb_Switch_c - rtb_front_wheel_angle_single__o) +
    0.00239;
  if (u_tmp < 0.0) {
    u0_tmp = -1.0;
  } else if (u_tmp > 0.0) {
    u0_tmp = 1.0;
  } else if (u_tmp == 0.0) {
    u0_tmp = 0.0;
  } else {
    u0_tmp = (rtNaN);
  }

  if (Faeroz_tmp < 0.0) {
    u0_tmp_1 = -1.0;
  } else if (Faeroz_tmp > 0.0) {
    u0_tmp_1 = 1.0;
  } else if (Faeroz_tmp == 0.0) {
    u0_tmp_1 = 0.0;
  } else {
    u0_tmp_1 = (rtNaN);
  }

  rtb_RR_tmp = 0.000282 * rtb_Switch - 2.02;
  u0_tmp_0 = sin(atan(0.000559 * rtb_Switch) * 2.0) * 34500.0 * u_tmp / (1.34 *
    rtb_Switch * 0.8 * rtb_RR_tmp - 0.01);
  rtb_RR_tmp_tmp = 0.0013 * rtb_Switch - 2.33;
  u_tmp = 0.000282 * rtb_Switch_c - 2.02;
  rtb_Saturation1_tmp = sin(atan(0.000559 * rtb_Switch_c) * 2.0) * 34500.0 *
    Faeroz_tmp / (1.34 * rtb_Switch_c * 0.8 * u_tmp - 0.01);
  rtb_Saturation1_tmp_0 = 0.0013 * rtb_Switch_c - 2.33;
  Faeroz_tmp = rtb_SumofElements1 - rtb_Gain1;
  cumRevIndex_tmp_tmp = sqrt(rtb_Sign * rtb_Sign + 1.0);
  cumRevIndex_tmp = (3.86E-7 * rtb_Switch + 0.000205) * 13.9 /
    cumRevIndex_tmp_tmp;
  cumRevIndex_tmp_tmp_0 = sqrt(u0 * u0 + 1.0);
  cumRevIndex_tmp_0 = (3.86E-7 * rtb_Switch_c + 0.000205) * 13.9 /
    cumRevIndex_tmp_tmp_0;
  cumRevIndex = Faeroz_tmp / 0.08 * 180.0 - (((rtb_RR + rtb_RL) * rtb_NProdOut *
    0.73439999999999994 - (((sin(atan(u0_tmp_0 - (0.26 * u0_tmp + 1.0) *
    (3.99E-5 * rtb_Switch - 0.521) * (atan(u0_tmp_0) - u0_tmp_0)) * 1.34) *
    (rtb_Switch * 0.8) * rtb_RR_tmp + (7.1E-5 * rtb_Switch - 0.149) *
    (rtb_Switch * 0.8)) * cos(atan((atan(((3.86E-7 * rtb_Switch -
    rtb_Integrator_i[2]) + 0.000205) * 13.9 / cumRevIndex_tmp_tmp) - ((3.86E-7 *
    rtb_Switch - rtb_Integrator_i[2]) + 0.000205) * 13.9 / sqrt(rtb_Sign *
    rtb_Sign + 1.0)) * rtb_RR_tmp_tmp + ((3.86E-7 * rtb_Switch -
    rtb_Integrator_i[2]) + 0.000205) * 13.9 / sqrt(rtb_Sign * rtb_Sign + 1.0)) *
    0.958) / cos(atan((atan(cumRevIndex_tmp) - cumRevIndex_tmp) * rtb_RR_tmp_tmp
                      + cumRevIndex_tmp) * 0.958) - sin(atan(16.1 *
    rtb_Integrator_i[2]) * 1.94) * (rtb_Switch * 0.8) * rtb_RR_tmp * (1.03E-5 *
    rtb_Switch - 0.000288) / sqrt(cumRevIndex * cumRevIndex * 225.0 + 1.0)) +
    ((sin(atan(rtb_Saturation1_tmp - (0.26 * u0_tmp_1 + 1.0) * (3.99E-5 *
    rtb_Switch_c - 0.521) * (atan(rtb_Saturation1_tmp) - rtb_Saturation1_tmp)) *
          1.34) * (rtb_Switch_c * 0.8) * u_tmp + (7.1E-5 * rtb_Switch_c - 0.149)
      * (rtb_Switch_c * 0.8)) * cos(atan((atan(((3.86E-7 * rtb_Switch_c -
    rtb_Integrator_i[3]) + 0.000205) * 13.9 / cumRevIndex_tmp_tmp_0) - ((3.86E-7
    * rtb_Switch_c - rtb_Integrator_i[3]) + 0.000205) * 13.9 / sqrt(u0 * u0 +
    1.0)) * rtb_Saturation1_tmp_0 + ((3.86E-7 * rtb_Switch_c - rtb_Integrator_i
    [3]) + 0.000205) * 13.9 / sqrt(u0 * u0 + 1.0)) * 0.958) / cos(atan((atan
    (cumRevIndex_tmp_0) - cumRevIndex_tmp_0) * rtb_Saturation1_tmp_0 +
    cumRevIndex_tmp_0) * 0.958) - sin(atan(16.1 * rtb_Integrator_i[3]) * 1.94) *
     (rtb_Switch_c * 0.8) * u_tmp * (1.03E-5 * rtb_Switch_c - 0.000288) / sqrt
     (rtb_front_wheel_angle_single__o * rtb_front_wheel_angle_single__o * 225.0
      + 1.0))) * 0.79560000000000008) + -(rtb_RL - rtb_RR) * rtb_Switch2_o *
    1.27 / 2.0);
  if (rtIsNaN(cumRevIndex)) {
    cumRevIndex = 0.0;
  }

  /* Logic: '<S146>/NOT1' */
  rtb_Logic_a_idx_1 = !rtb_Logic_idx_1;

  /* DiscreteIntegrator: '<S208>/Integrator' */
  if (rtb_Logic_a_idx_1 || (rtDW.Integrator_PrevResetState_n != 0)) {
    rtDW.Integrator_DSTATE_b = 0.0;
  }

  /* DiscreteIntegrator: '<S203>/Filter' */
  if (rtb_Logic_a_idx_1 || (rtDW.Filter_PrevResetState != 0)) {
    rtDW.Filter_DSTATE = 0.0;
  }

  /* Product: '<S211>/NProd Out' incorporates:
   *  Constant: '<S146>/Constant11'
   *  Constant: '<S146>/Constant13'
   *  Constant: '<S146>/Constant14'
   *  DiscreteIntegrator: '<S203>/Filter'
   *  Product: '<S202>/DProd Out'
   *  Product: '<S225>/cProd Out'
   *  Sum: '<S169>/Sum3'
   *  Sum: '<S203>/SumD'
   */
  rtb_NProdOut = ((rtb_SumofElements1 * 0.0 - rtb_Gain1) * 0.0 -
                  rtDW.Filter_DSTATE) * 3.0;

  /* Sum: '<S218>/Sum' incorporates:
   *  Constant: '<S146>/Constant12'
   *  DiscreteIntegrator: '<S208>/Integrator'
   *  Product: '<S213>/PProd Out'
   */
  rtb_front_wheel_angle_single__o = (Faeroz_tmp * 0.0 + rtDW.Integrator_DSTATE_b)
    + rtb_NProdOut;

  /* Switch: '<S216>/Switch2' incorporates:
   *  Constant: '<S146>/Constant10'
   *  Constant: '<S146>/Constant9'
   *  RelationalOperator: '<S216>/LowerRelop1'
   *  RelationalOperator: '<S216>/UpperRelop'
   *  Switch: '<S216>/Switch'
   */
  if (rtb_front_wheel_angle_single__o > 50.0) {
    rtb_Switch2_o = 50.0;
  } else if (rtb_front_wheel_angle_single__o < -50.0) {
    /* Switch: '<S216>/Switch' incorporates:
     *  Constant: '<S146>/Constant10'
     */
    rtb_Switch2_o = -50.0;
  } else {
    rtb_Switch2_o = rtb_front_wheel_angle_single__o;
  }

  /* End of Switch: '<S216>/Switch2' */

  /* Sum: '<S146>/Sum1' incorporates:
   *  Gain: '<S146>/Gain2'
   */
  u0 = 0.017407407407407406 * cumRevIndex + rtb_Switch2_o;

  /* Saturate: '<S146>/Saturation' */
  if (u0 > 20.0) {
    u0 = 20.0;
  } else if (u0 < -20.0) {
    u0 = -20.0;
  }

  /* End of Saturate: '<S146>/Saturation' */

  /* Product: '<S146>/Product' */
  cumRevIndex = u0 * (real_T)rtb_Logic_idx_1;

  /* MATLAB Function: '<S146>/MATLAB Function3' */
  rtb_Switch = ((rtb_Abs_o_idx_0 * rtDW.CFunction_f[0] + rtb_Abs_c *
                 rtDW.CFunction_d[1]) - 0.635 * rtDW.CFunction_f[2]) + 0.635 *
    rtDW.CFunction_d[3];

  /* Switch: '<S170>/Switch2' incorporates:
   *  RelationalOperator: '<S170>/LowerRelop1'
   */
  if (!(cumRevIndex > csum)) {
    /* Switch: '<S170>/Switch' incorporates:
     *  RelationalOperator: '<S170>/UpperRelop'
     */
    if (cumRevIndex < rtb_Switch) {
      csum = rtb_Switch;
    } else {
      csum = cumRevIndex;
    }

    /* End of Switch: '<S170>/Switch' */
  }

  /* End of Switch: '<S170>/Switch2' */

  /* MATLAB Function: '<S146>/MATLAB Function1' incorporates:
   *  Constant: '<S146>/Constant15'
   *  Inport: '<Root>/throttle'
   *  RelationalOperator: '<S146>/Less Than'
   */
  guard1 = false;
  if (csum < 0.0) {
    guard1 = true;
  } else if (csum > 0.0) {
    /* SignalConversion generated from: '<S165>/ SFunction ' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant9'
     */
    tmp[0] = -35000;
    tmp[1] = 80000;
    if (tmp[rtU.throttle >= 0.05] < 10000) {
      cumRevIndex = 0.0;
    } else {
      cumRevIndex = 0.75;
    }

    rtb_Switch = csum * cumRevIndex;
  } else {
    if (csum == 0.0) {
    }

    guard1 = true;
  }

  if (guard1) {
    rtb_Switch = csum;

    /* SignalConversion generated from: '<S165>/ SFunction ' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant9'
     */
    tmp[0] = -35000;
    tmp[1] = 80000;
    if (tmp[rtU.throttle >= 0.05] < 10000) {
      cumRevIndex = 0.0;
    } else {
      cumRevIndex = 0.75;
    }

    csum *= cumRevIndex;
  }

  /* End of MATLAB Function: '<S146>/MATLAB Function1' */

  /* MinMax: '<S230>/Max' */
  z = fmax(modValueRev, z);

  /* InitialCondition: '<S233>/IC1' */
  rtDW.IC1_FirstOutputTime = false;

  /* Abs: '<S234>/Abs3' incorporates:
   *  Abs: '<S235>/Abs3'
   */
  modValueRev = fabs(rtb_Switch2_c[0]);

  /* Gain: '<S269>/Gain2' incorporates:
   *  Gain: '<S241>/Gain2'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_SumofElements1 = 13.5 * rtU.omega_wheels_FL;

  /* Saturate: '<S269>/Saturation' incorporates:
   *  Gain: '<S269>/Gain2'
   */
  if (rtb_SumofElements1 > 2083.9231268812296) {
    rtb_Integrator_i[0] = 2083.9231268812296;
  } else if (rtb_SumofElements1 < 10.471975511965978) {
    rtb_Integrator_i[0] = 10.471975511965978;
  } else {
    rtb_Integrator_i[0] = rtb_SumofElements1;
  }

  /* Gain: '<S269>/Gain2' incorporates:
   *  Gain: '<S241>/Gain2'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  u0_tmp = 13.5 * rtU.omega_wheels_FR;

  /* Saturate: '<S269>/Saturation' incorporates:
   *  Gain: '<S269>/Gain2'
   */
  if (u0_tmp > 2083.9231268812296) {
    rtb_Integrator_i[1] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Integrator_i[1] = 10.471975511965978;
  } else {
    rtb_Integrator_i[1] = u0_tmp;
  }

  /* Gain: '<S269>/Gain2' incorporates:
   *  Gain: '<S241>/Gain2'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  u0_tmp_0 = 13.5 * rtU.omega_wheels_RL;

  /* Saturate: '<S269>/Saturation' incorporates:
   *  Gain: '<S269>/Gain2'
   */
  if (u0_tmp_0 > 2083.9231268812296) {
    rtb_Integrator_i[2] = 2083.9231268812296;
  } else if (u0_tmp_0 < 10.471975511965978) {
    rtb_Integrator_i[2] = 10.471975511965978;
  } else {
    rtb_Integrator_i[2] = u0_tmp_0;
  }

  /* Gain: '<S269>/Gain2' incorporates:
   *  Gain: '<S241>/Gain2'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0_tmp_1 = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S269>/Saturation' incorporates:
   *  Gain: '<S269>/Gain2'
   */
  if (u0_tmp_1 > 2083.9231268812296) {
    rtb_Integrator_i[3] = 2083.9231268812296;
  } else if (u0_tmp_1 < 10.471975511965978) {
    rtb_Integrator_i[3] = 10.471975511965978;
  } else {
    rtb_Integrator_i[3] = u0_tmp_1;
  }

  /* Abs: '<S271>/Abs' */
  rtb_TmpSignalConversionAtSFun_e[0] = fabs(rtb_Switch2_c[0]);
  rtb_TmpSignalConversionAtSFun_e[1] = fabs(rtb_Switch2_c[1]);
  rtb_TmpSignalConversionAtSFun_e[2] = fabs(rtb_Switch2_c[2]);
  rtb_TmpSignalConversionAtSFun_e[3] = fabs(rtb_Switch2_c[3]);

  /* Lookup_n-D: '<S271>/2-D Lookup Table' */
  rtb_Integrator_i[0] = look2_binlx(rtb_Integrator_i[0],
    rtb_TmpSignalConversionAtSFun_e[0], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled74, 200U);
  rtb_Integrator_i[1] = look2_binlx(rtb_Integrator_i[1],
    rtb_TmpSignalConversionAtSFun_e[1], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled74, 200U);
  rtb_Integrator_i[2] = look2_binlx(rtb_Integrator_i[2],
    rtb_TmpSignalConversionAtSFun_e[2], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled74, 200U);
  rtb_Integrator_i[3] = look2_binlx(rtb_Integrator_i[3],
    rtb_TmpSignalConversionAtSFun_e[3], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled74, 200U);

  /* Saturate: '<S271>/Saturation' */
  u0 = rtb_Integrator_i[0];
  if (u0 > 1.0) {
    rtb_Integrator_i[0] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_i[0] = 0.3;
  } else {
    rtb_Integrator_i[0] = u0;
  }

  u0 = rtb_Integrator_i[1];
  if (u0 > 1.0) {
    rtb_Integrator_i[1] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_i[1] = 0.3;
  } else {
    rtb_Integrator_i[1] = u0;
  }

  u0 = rtb_Integrator_i[2];
  if (u0 > 1.0) {
    rtb_Integrator_i[2] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_i[2] = 0.3;
  } else {
    rtb_Integrator_i[2] = u0;
  }

  u0 = rtb_Integrator_i[3];
  if (u0 > 1.0) {
    rtb_Integrator_i[3] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_i[3] = 0.3;
  } else {
    rtb_Integrator_i[3] = u0;
  }

  /* End of Saturate: '<S271>/Saturation' */

  /* Switch: '<S269>/Switch3' incorporates:
   *  Gain: '<S269>/     '
   *  Gain: '<S269>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    cumRevIndex = 0.96 * rtb_Integrator_i[0];
  } else {
    cumRevIndex = 1.0416666666666667 * rtb_Integrator_i[0];
  }

  if (rtU.omega_wheels_FR > 0.0) {
    rtb_RR = 0.96 * rtb_Integrator_i[1];
  } else {
    rtb_RR = 1.0416666666666667 * rtb_Integrator_i[1];
  }

  if (rtU.omega_wheels_RL > 0.0) {
    rtb_RL = 0.96 * rtb_Integrator_i[2];
  } else {
    rtb_RL = 1.0416666666666667 * rtb_Integrator_i[2];
  }

  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Switch_c = 0.96 * rtb_Integrator_i[3];
  } else {
    rtb_Switch_c = 1.0416666666666667 * rtb_Integrator_i[3];
  }

  /* End of Switch: '<S269>/Switch3' */

  /* MATLAB Function: '<S151>/MATLAB Function' incorporates:
   *  Gain: '<S151>/Gain'
   *  Gain: '<S269>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S269>/Product'
   */
  rtb_Tnew[0] = 13.5 * rtU.omega_wheels_FL * cumRevIndex * 0.0001;
  rtb_Tnew[1] = 13.5 * rtU.omega_wheels_FR * rtb_RR * 0.0001;
  rtb_Tnew[2] = 13.5 * rtU.omega_wheels_RL * rtb_RL * 0.0001;
  rtb_Tnew[3] = 13.5 * rtU.omega_wheels_RR * rtb_Switch_c * 0.0001;
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
  for (idx = 0; idx < 4; idx++) {
    b_j = idx << 2;
    rtb_y_tmp = idx << 3;
    rtb_y[rtb_y_tmp] = rtb_CCaller_o6[b_j];
    rtb_y[rtb_y_tmp + 1] = rtb_CCaller_o6[b_j + 1];
    rtb_y[rtb_y_tmp + 2] = rtb_CCaller_o6[b_j + 2];
    rtb_y[rtb_y_tmp + 3] = rtb_CCaller_o6[b_j + 3];
  }

  for (idx = 0; idx < 4; idx++) {
    b_j = idx << 2;
    rtb_y_tmp = (idx + 4) << 3;
    rtb_y[rtb_y_tmp + 4] = varargin_2[b_j];
    rtb_y[rtb_y_tmp + 5] = varargin_2[b_j + 1];
    rtb_y[rtb_y_tmp + 6] = varargin_2[b_j + 2];
    rtb_y[rtb_y_tmp + 7] = varargin_2[b_j + 3];
  }

  for (idx = 0; idx < 64; idx++) {
    rtb_y[idx] *= 50.0;
  }

  /* End of MATLAB Function: '<S151>/MATLAB Function' */

  /* Saturate: '<S241>/Saturation' */
  if (rtb_SumofElements1 > 2083.9231268812296) {
    rtb_Integrator_i[0] = 2083.9231268812296;
  } else if (rtb_SumofElements1 < 10.471975511965978) {
    rtb_Integrator_i[0] = 10.471975511965978;
  } else {
    rtb_Integrator_i[0] = rtb_SumofElements1;
  }

  if (u0_tmp > 2083.9231268812296) {
    rtb_Integrator_i[1] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Integrator_i[1] = 10.471975511965978;
  } else {
    rtb_Integrator_i[1] = u0_tmp;
  }

  if (u0_tmp_0 > 2083.9231268812296) {
    rtb_Integrator_i[2] = 2083.9231268812296;
  } else if (u0_tmp_0 < 10.471975511965978) {
    rtb_Integrator_i[2] = 10.471975511965978;
  } else {
    rtb_Integrator_i[2] = u0_tmp_0;
  }

  if (u0_tmp_1 > 2083.9231268812296) {
    rtb_Integrator_i[3] = 2083.9231268812296;
  } else if (u0_tmp_1 < 10.471975511965978) {
    rtb_Integrator_i[3] = 10.471975511965978;
  } else {
    rtb_Integrator_i[3] = u0_tmp_1;
  }

  /* End of Saturate: '<S241>/Saturation' */

  /* Abs: '<S243>/Abs' */
  rtb_TmpSignalConversionAtSFun_e[0] = fabs(rtb_Switch2_c[0]);
  rtb_TmpSignalConversionAtSFun_e[1] = fabs(rtb_Switch2_c[1]);
  rtb_TmpSignalConversionAtSFun_e[2] = fabs(rtb_Switch2_c[2]);
  rtb_TmpSignalConversionAtSFun_e[3] = fabs(rtb_Switch2_c[3]);

  /* Lookup_n-D: '<S243>/2-D Lookup Table' */
  rtb_Integrator_i[0] = look2_binlx(rtb_Integrator_i[0],
    rtb_TmpSignalConversionAtSFun_e[0], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled74, 200U);
  rtb_Integrator_i[1] = look2_binlx(rtb_Integrator_i[1],
    rtb_TmpSignalConversionAtSFun_e[1], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled74, 200U);
  rtb_Integrator_i[2] = look2_binlx(rtb_Integrator_i[2],
    rtb_TmpSignalConversionAtSFun_e[2], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled74, 200U);
  rtb_Integrator_i[3] = look2_binlx(rtb_Integrator_i[3],
    rtb_TmpSignalConversionAtSFun_e[3], rtConstP.pooled7, rtConstP.pooled8,
    rtConstP.pooled5, rtConstP.pooled74, 200U);

  /* Saturate: '<S243>/Saturation' */
  u0 = rtb_Integrator_i[0];
  if (u0 > 1.0) {
    rtb_Integrator_i[0] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_i[0] = 0.3;
  } else {
    rtb_Integrator_i[0] = u0;
  }

  u0 = rtb_Integrator_i[1];
  if (u0 > 1.0) {
    rtb_Integrator_i[1] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_i[1] = 0.3;
  } else {
    rtb_Integrator_i[1] = u0;
  }

  u0 = rtb_Integrator_i[2];
  if (u0 > 1.0) {
    rtb_Integrator_i[2] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_i[2] = 0.3;
  } else {
    rtb_Integrator_i[2] = u0;
  }

  u0 = rtb_Integrator_i[3];
  if (u0 > 1.0) {
    rtb_Integrator_i[3] = 1.0;
  } else if (u0 < 0.3) {
    rtb_Integrator_i[3] = 0.3;
  } else {
    rtb_Integrator_i[3] = u0;
  }

  /* End of Saturate: '<S243>/Saturation' */

  /* Switch: '<S241>/Switch3' incorporates:
   *  Gain: '<S241>/     '
   *  Gain: '<S241>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    cumRevIndex = 0.96 * rtb_Integrator_i[0];
  } else {
    cumRevIndex = 1.0416666666666667 * rtb_Integrator_i[0];
  }

  /* Abs: '<S241>/Abs' incorporates:
   *  Gain: '<S241>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Product: '<S241>/Divide'
   */
  rtb_TmpSignalConversionAtSFun_e[0] = fabs(13.5 * rtU.omega_wheels_FL /
    cumRevIndex);

  /* Switch: '<S241>/Switch3' incorporates:
   *  Gain: '<S241>/     '
   *  Gain: '<S241>/      '
   *  Inport: '<Root>/omega_wheels_FR'
   */
  if (rtU.omega_wheels_FR > 0.0) {
    cumRevIndex = 0.96 * rtb_Integrator_i[1];
  } else {
    cumRevIndex = 1.0416666666666667 * rtb_Integrator_i[1];
  }

  /* Abs: '<S241>/Abs' incorporates:
   *  Gain: '<S241>/Gain1'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Product: '<S241>/Divide'
   */
  rtb_TmpSignalConversionAtSFun_e[1] = fabs(13.5 * rtU.omega_wheels_FR /
    cumRevIndex);

  /* Switch: '<S241>/Switch3' incorporates:
   *  Gain: '<S241>/     '
   *  Gain: '<S241>/      '
   *  Inport: '<Root>/omega_wheels_RL'
   */
  if (rtU.omega_wheels_RL > 0.0) {
    cumRevIndex = 0.96 * rtb_Integrator_i[2];
  } else {
    cumRevIndex = 1.0416666666666667 * rtb_Integrator_i[2];
  }

  /* Abs: '<S241>/Abs' incorporates:
   *  Gain: '<S241>/Gain1'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Product: '<S241>/Divide'
   */
  rtb_TmpSignalConversionAtSFun_e[2] = fabs(13.5 * rtU.omega_wheels_RL /
    cumRevIndex);

  /* Switch: '<S241>/Switch3' incorporates:
   *  Gain: '<S241>/     '
   *  Gain: '<S241>/      '
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_RR > 0.0) {
    cumRevIndex = 0.96 * rtb_Integrator_i[3];
  } else {
    cumRevIndex = 1.0416666666666667 * rtb_Integrator_i[3];
  }

  /* Abs: '<S241>/Abs' incorporates:
   *  Gain: '<S241>/Gain1'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S241>/Divide'
   */
  rtb_TmpSignalConversionAtSFun_e[3] = fabs(13.5 * rtU.omega_wheels_RR /
    cumRevIndex);

  /* Gain: '<S147>/Gain' incorporates:
   *  Sum: '<S147>/Sum'
   */
  rtb_Switch_c = (z + rtb_Integrator_ac) * 0.5;

  /* Chart: '<S236>/Distribution complete' incorporates:
   *  SignalConversion generated from: '<S240>/ SFunction '
   */
  if (rtb_Switch_c >= 0.0) {
    rtb_RR = rtb_Switch_c;
    rtb_Integrator_i[0] = rtDW.CFunction_f[1];
    rtb_Integrator_i[1] = rtDW.CFunction_f[3];
    rtb_Integrator_i[2] = rtDW.CFunction_f[0];
    rtb_Integrator_i[3] = rtDW.CFunction_f[2];
    rtb_UnaryMinus_k4[0] = rtDW.CFunction_d[1];
    rtb_UnaryMinus_k4[1] = rtDW.CFunction_d[3];
    rtb_UnaryMinus_k4[2] = rtDW.CFunction_d[0];
    rtb_UnaryMinus_k4[3] = rtDW.CFunction_d[2];
    rtb_RL = csum;
  } else {
    rtb_RR = -rtb_Switch_c;
    rtb_Integrator_i[0] = -rtDW.CFunction_d[1];
    rtb_Integrator_i[1] = -rtDW.CFunction_d[3];
    rtb_Integrator_i[2] = -rtDW.CFunction_d[0];
    rtb_Integrator_i[3] = -rtDW.CFunction_d[2];
    rtb_UnaryMinus_k4[0] = -rtDW.CFunction_f[1];
    rtb_UnaryMinus_k4[1] = -rtDW.CFunction_f[3];
    rtb_UnaryMinus_k4[2] = -rtDW.CFunction_f[0];
    rtb_UnaryMinus_k4[3] = -rtDW.CFunction_f[2];
    rtb_RL = -csum;
  }

  if (rtb_RL < 0.0) {
    rtb_Gain1 = rtb_Integrator_i[2];
    cumRevIndex = rtb_Integrator_i[3];
    rtb_SumofElements1 = rtb_Integrator_i[0];
    u0_tmp = rtb_Integrator_i[1];
    rtb_Integrator_i[0] = rtb_Gain1;
    rtb_Integrator_i[1] = cumRevIndex;
    rtb_Integrator_i[2] = rtb_SumofElements1;
    rtb_Integrator_i[3] = u0_tmp;
    rtb_Gain1 = rtb_UnaryMinus_k4[2];
    cumRevIndex = rtb_UnaryMinus_k4[3];
    rtb_SumofElements1 = rtb_UnaryMinus_k4[0];
    u0_tmp = rtb_UnaryMinus_k4[1];
    rtb_UnaryMinus_k4[0] = rtb_Gain1;
    rtb_UnaryMinus_k4[1] = cumRevIndex;
    rtb_UnaryMinus_k4[2] = rtb_SumofElements1;
    rtb_UnaryMinus_k4[3] = u0_tmp;
  }

  for (idx = 0; idx < 4; idx++) {
    rtb_Integrator_c[idx] = rtb_Integrator_i[idx];
  }

  for (idx = 0; idx < 4; idx++) {
    rtb_UnaryMinus_a[idx] = rtb_UnaryMinus_k4[idx];
  }

  BaseDistribution(rtb_RR, rtb_Integrator_c, rtb_UnaryMinus_a, fabs(rtb_RL),
                   rtb_Tnew);
  if (!(rtb_Switch_c >= 0.0)) {
    rtb_Integrator_c[0] = -rtb_Tnew[0];
    rtb_Integrator_c[1] = -rtb_Tnew[1];
    rtb_Integrator_c[2] = -rtb_Tnew[2];
    rtb_Integrator_c[3] = -rtb_Tnew[3];
    assignBrakeTorque(rtb_Integrator_c, rtb_Tnew);
  }

  if (rtb_RL < 0.0) {
    rtb_RR = rtb_Tnew[2];
    rtb_RL = rtb_Tnew[3];
    rtb_Switch_c = rtb_Tnew[0];
    rtb_Gain1 = rtb_Tnew[1];
    rtb_Tnew[0] = rtb_RR;
    rtb_Tnew[1] = rtb_RL;
    rtb_Tnew[2] = rtb_Switch_c;
    rtb_Tnew[3] = rtb_Gain1;
  }

  /* End of Chart: '<S236>/Distribution complete' */

  /* CCaller: '<S139>/C Caller' incorporates:
   *  CFunction: '<S152>/C Function'
   *  CFunction: '<S246>/C Function'
   *  CFunction: '<S247>/C Function'
   *  Constant: '<S144>/Constant'
   *  UnaryMinus: '<S144>/Unary Minus'
   */
  memcpy(&rtb_CCaller_o3[0], &rtDW.CFunction[0], 26U * sizeof(real_T));
  rtb_Integrator_i[0] = -10000.0;
  rtb_Integrator_i[1] = -10000.0;
  rtb_Integrator_i[2] = -10000.0;
  rtb_Integrator_i[3] = -10000.0;
  rtb_UnaryMinus_k4[0] = 10000.0;
  rtb_UnaryMinus_k4[1] = 10000.0;
  rtb_UnaryMinus_k4[2] = 10000.0;
  rtb_UnaryMinus_k4[3] = 10000.0;
  memset(&rtb_CCaller_o6[0], 0, sizeof(real_T) << 4U);
  rtb_Product1[0] = rtDW.CFunction_d[0];
  rtb_Product1[1] = rtDW.CFunction_d[1];
  rtb_Product1[2] = rtDW.CFunction_d[2];
  rtb_Product1[3] = rtDW.CFunction_d[3];
  rtb_CCaller_o8[0] = rtDW.CFunction_f[0];
  rtb_CCaller_o8[1] = rtDW.CFunction_f[1];
  rtb_CCaller_o8[2] = rtDW.CFunction_f[2];
  rtb_CCaller_o8[3] = rtDW.CFunction_f[3];

  /* Abs: '<S235>/Abs1' incorporates:
   *  Abs: '<S234>/Abs1'
   */
  rtb_Switch_c = fabs(rtb_Switch2_c[1]);

  /* CCaller: '<S139>/C Caller' incorporates:
   *  Abs: '<S234>/Abs3'
   *  Abs: '<S235>/Abs1'
   *  Constant: '<S139>/Constant'
   *  Constant: '<S149>/Constant'
   *  MATLAB Function: '<S148>/MATLAB Function'
   *  SignalConversion generated from: '<S139>/C Caller'
   *  UnaryMinus: '<S235>/Unary Minus'
   *  UnaryMinus: '<S235>/Unary Minus1'
   * */
  rtb_CCaller_o9[0] = rtb_Integrator_ac;
  rtb_CCaller_o9[1] = -35.0;
  rtb_CCaller_o9[2] = -rtb_Switch_c;
  rtb_CCaller_o9[3] = -modValueRev;
  rtb_CCaller_o9[4] = rtb_Switch;
  rtb_CCaller_o10[0] = z;
  rtb_CCaller_o10[1] = 80.0;
  rtb_CCaller_o10[2] = rtb_Switch_c;
  rtb_CCaller_o10[3] = modValueRev;
  rtb_CCaller_o10[4] = csum;
  rtb_CCaller_o12[0] = 1.0;
  rtb_CCaller_o12[5] = 1.0;
  rtb_CCaller_o12[10] = 1.0;
  rtb_CCaller_o12[15] = 1.0;
  rtb_CCaller_o12[1] = rtb_TmpSignalConversionAtSFun_e[0] / 1000.0;
  rtb_CCaller_o12[6] = rtb_TmpSignalConversionAtSFun_e[1] / 1000.0;
  rtb_CCaller_o12[11] = rtb_TmpSignalConversionAtSFun_e[2] / 1000.0;
  rtb_CCaller_o12[16] = rtb_TmpSignalConversionAtSFun_e[3] / 1000.0;
  rtb_CCaller_o12[2] = 0.0;
  rtb_CCaller_o12[7] = 1.0;
  rtb_CCaller_o12[12] = 0.0;
  rtb_CCaller_o12[17] = -1.0;
  rtb_CCaller_o12[3] = 1.0;
  rtb_CCaller_o12[8] = 0.0;
  rtb_CCaller_o12[13] = -1.0;
  rtb_CCaller_o12[18] = 0.0;
  rtb_CCaller_o12[4] = rtb_Abs_o_idx_0;
  rtb_CCaller_o12[9] = rtb_Abs_c;
  rtb_CCaller_o12[14] = -0.635;
  rtb_CCaller_o12[19] = 0.635;
  rtb_CCaller_o13[0] = 1000.0;
  rtb_CCaller_o13[1] = 50.0;
  rtb_CCaller_o13[2] = 50.0;
  rtb_CCaller_o14[0] = 1000.0;
  rtb_CCaller_o14[1] = 50.0;
  rtb_CCaller_o14[2] = 50.0;
  rtb_TmpSignalConversionAtSFun_e[0] = rtb_Tnew[2];
  rtb_TmpSignalConversionAtSFun_e[1] = rtb_Tnew[0];
  rtb_TmpSignalConversionAtSFun_e[2] = rtb_Tnew[3];
  rtb_TmpSignalConversionAtSFun_e[3] = rtb_Tnew[1];
  rtb_Tnew[0] = 0.0;
  rtb_Tnew[1] = 0.0;
  rtb_Tnew[2] = 0.0;
  rtb_Tnew[3] = 0.0;

  /* CCaller: '<S139>/C Caller' */
  rtb_Integrator_ac = Acados_Caller_wrapper(&rtb_Switch2_c[0], &rtb_CCaller_o3[0],
    &rtb_Integrator_i[0], &rtb_UnaryMinus_k4[0], &rtb_CCaller_o6[0],
    &rtb_Product1[0], &rtb_CCaller_o8[0], &rtb_CCaller_o9[0], &rtb_CCaller_o10[0],
    &rtb_y[0], &rtb_CCaller_o12[0], &rtb_CCaller_o13[0], &rtb_CCaller_o14[0],
    &rtb_TmpSignalConversionAtSFun_e[0], &rtb_Tnew[0]);

  /* DiscreteFir: '<S156>/Discrete FIR Filter' */
  modValueRev = rtb_Integrator_ac;
  for (idx = rtDW.DiscreteFIRFilter_circBuf; idx < 4; idx++) {
    modValueRev += rtDW.DiscreteFIRFilter_states[idx];
  }

  for (idx = 0; idx < rtDW.DiscreteFIRFilter_circBuf; idx++) {
    modValueRev += rtDW.DiscreteFIRFilter_states[idx];
  }

  /* End of DiscreteFir: '<S156>/Discrete FIR Filter' */

  /* Switch: '<S156>/Switch' */
  if ((rtb_vx > 3.0) && (!(modValueRev >= 4.0))) {
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
  rtb_Switch2_c[0] = rtb_Tnew[0];
  rtb_Switch2_c[1] = rtb_Tnew[1];
  rtb_Switch2_c[2] = rtb_Tnew[2];
  rtb_Switch2_c[3] = rtb_Tnew[3];

  /* UnitDelay: '<S17>/Unit Delay' */
  rtb_Tnew[0] = rtDW.UnitDelay_DSTATE_f[0];
  rtb_Tnew[1] = rtDW.UnitDelay_DSTATE_f[1];
  rtb_Tnew[2] = rtDW.UnitDelay_DSTATE_f[2];
  rtb_Tnew[3] = rtDW.UnitDelay_DSTATE_f[3];

  /* SignalConversion generated from: '<S26>/ SFunction ' incorporates:
   *  Chart: '<S17>/Activation logic'
   *  Chart: '<S23>/Activation logic'
   *  SignalConversion generated from: '<S83>/ SFunction '
   */
  rtb_UnaryMinus_k4[0] = rtb_Switch2_c[3];
  rtb_UnaryMinus_k4[1] = rtb_Switch2_c[2];
  rtb_UnaryMinus_k4[2] = rtb_Switch2_c[1];
  rtb_UnaryMinus_k4[3] = rtb_Switch2_c[0];

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
    rtDW.is_TS_ON_l = IN_ABS_OFF;
    rtDW.T_min[0] = 21.0;
    rtDW.T_min[1] = 21.0;
    rtDW.T_min[2] = 21.0;
    rtDW.T_min[3] = 21.0;

    /* case IN_TS_ON: */
  } else if (rtDW.is_TS_ON_l == IN_ABS_OFF) {
    if (AND) {
      rtDW.is_TS_ON_l = IN_ABS_ON;
      rtDW.is_FL_g = IN_ABS_INACTIVE;
      rtDW.T_min[0] = 21.0;
      rtDW.is_FR_i = IN_ABS_INACTIVE;
      rtDW.T_min[1] = 21.0;
      rtDW.is_RL_g = IN_ABS_INACTIVE;
      rtDW.T_min[2] = 21.0;
      rtDW.is_RR_p = IN_ABS_INACTIVE;
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
    rtDW.is_TS_ON_l = IN_ABS_OFF;
    rtDW.T_min[0] = 21.0;
    rtDW.T_min[1] = 21.0;
    rtDW.T_min[2] = 21.0;
    rtDW.T_min[3] = 21.0;
  } else {
    if (rtDW.is_FL_g == IN_ABS_ACTIVE) {
      if (rtb_UnaryMinus_k4[0] > 0.9 * rtb_Tnew[0]) {
        rtDW.is_FL_g = IN_ABS_INACTIVE;
        rtDW.T_min[0] = 21.0;
      } else {
        rtDW.T_min[0] = Switch2_idx_0;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_p_idx_0 <= -0.14600000000000005) && (rtb_UnaryMinus_k4[0] <
                0.0)) {
      rtDW.is_FL_g = IN_ABS_ACTIVE;
      rtDW.T_min[0] = rtb_UnaryMinus_k4[0];
    } else {
      rtDW.T_min[0] = 21.0;
    }

    if (rtDW.is_FR_i == IN_ABS_ACTIVE) {
      if (rtb_UnaryMinus_k4[1] > 0.9 * rtb_Tnew[1]) {
        rtDW.is_FR_i = IN_ABS_INACTIVE;
        rtDW.T_min[1] = 21.0;
      } else {
        rtDW.T_min[1] = Switch2_idx_1;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_p_idx_1 <= -0.14600000000000005) && (rtb_UnaryMinus_k4[1] <
                0.0)) {
      rtDW.is_FR_i = IN_ABS_ACTIVE;
      rtDW.T_min[1] = rtb_UnaryMinus_k4[1];
    } else {
      rtDW.T_min[1] = 21.0;
    }

    if (rtDW.is_RL_g == IN_ABS_ACTIVE) {
      if (rtb_UnaryMinus_k4[2] > 0.9 * rtb_Tnew[2]) {
        rtDW.is_RL_g = IN_ABS_INACTIVE;
        rtDW.T_min[2] = 21.0;
      } else {
        rtDW.T_min[2] = Switch2_idx_2;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_p_idx_2 <= -0.14600000000000005) && (rtb_UnaryMinus_k4[2] <
                0.0)) {
      rtDW.is_RL_g = IN_ABS_ACTIVE;
      rtDW.T_min[2] = rtb_UnaryMinus_k4[2];
    } else {
      rtDW.T_min[2] = 21.0;
    }

    if (rtDW.is_RR_p == IN_ABS_ACTIVE) {
      if (rtb_UnaryMinus_k4[3] > 0.9 * rtb_Tnew[3]) {
        rtDW.is_RR_p = IN_ABS_INACTIVE;
        rtDW.T_min[3] = 21.0;
      } else {
        rtDW.T_min[3] = Switch2_idx_3;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_e <= -0.14600000000000005) && (rtb_UnaryMinus_k4[3] < 0.0))
    {
      rtDW.is_RR_p = IN_ABS_ACTIVE;
      rtDW.T_min[3] = rtb_UnaryMinus_k4[3];
    } else {
      rtDW.T_min[3] = 21.0;
    }
  }

  /* Gain: '<S52>/ZeroGain' */
  rtb_Integrator_i[0] = 0.0 * rtb_Switch_n_idx_0;
  rtb_Integrator_i[1] = 0.0 * rtb_Switch_n_idx_1;
  rtb_Integrator_i[2] = 0.0 * rtb_Switch_n_idx_2;
  rtb_Integrator_i[3] = 0.0 * rtb_k_p_idx_3;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Sum: '<S55>/Diff'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_Switch_n_idx_0 >= -4.9) {
    rtb_Switch = -4.9;
  } else if (rtb_Switch_n_idx_0 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Switch = rtb_Switch_n_idx_0;
  } else {
    rtb_Switch = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_Switch = rtb_Switch_n_idx_0 - rtb_Switch;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Sum: '<S55>/Diff'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_Switch_n_idx_1 >= -4.9) {
    rtb_Switch_n_idx_0 = -4.9;
  } else if (rtb_Switch_n_idx_1 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Switch_n_idx_0 = rtb_Switch_n_idx_1;
  } else {
    rtb_Switch_n_idx_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_Switch_n_idx_1 -= rtb_Switch_n_idx_0;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Sum: '<S55>/Diff'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_Switch_n_idx_2 >= -4.9) {
    rtb_Switch_n_idx_0 = -4.9;
  } else if (rtb_Switch_n_idx_2 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Switch_n_idx_0 = rtb_Switch_n_idx_2;
  } else {
    rtb_Switch_n_idx_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_Switch_n_idx_2 -= rtb_Switch_n_idx_0;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_k_p_idx_3 >= -4.9) {
    rtb_Switch_n_idx_0 = -4.9;
  } else if (rtb_k_p_idx_3 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Switch_n_idx_0 = rtb_k_p_idx_3;
  } else {
    rtb_Switch_n_idx_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_k_p_idx_3 -= rtb_Switch_n_idx_0;

  /* Sum: '<S75>/SumI1' incorporates:
   *  Constant: '<S17>/Constant2'
   *  Gain: '<S74>/Kt'
   *  Product: '<S59>/IProd Out'
   *  Sum: '<S17>/Minus'
   *  Sum: '<S74>/SumI3'
   */
  rtb_Tnew[0] = (rtDW.T_min[0] - Switch2_idx_0) * 100.0 + rtb_Minus[0] * 2845.0;
  rtb_Tnew[1] = (rtDW.T_min[1] - Switch2_idx_1) * 100.0 + rtb_Minus[1] * 2845.0;
  rtb_Tnew[2] = (rtDW.T_min[2] - Switch2_idx_2) * 100.0 + rtb_Minus[2] * 2845.0;
  rtb_Tnew[3] = (-0.13600000000000004 - rtb_k_e) * 2845.0 + (rtDW.T_min[3] -
    Switch2_idx_3) * 100.0;

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  u0_tmp = rtb_Tnew[0];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Switch < 0.0) {
    rtb_Switch_n_idx_0 = -1.0;
  } else if (rtb_Switch > 0.0) {
    rtb_Switch_n_idx_0 = 1.0;
  } else if (rtb_Switch == 0.0) {
    rtb_Switch_n_idx_0 = 0.0;
  } else {
    rtb_Switch_n_idx_0 = (rtNaN);
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
  if ((rtb_Integrator_i[0] != rtb_Switch) && ((int8_T)rtb_Switch_n_idx_0 ==
       (int8_T)u0_tmp)) {
    rtb_Integrator_i[0] = 0.0;
  } else {
    rtb_Integrator_i[0] = rtb_Tnew[0];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  u0_tmp = rtb_Tnew[1];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Switch_n_idx_1 < 0.0) {
    rtb_Switch = -1.0;
  } else if (rtb_Switch_n_idx_1 > 0.0) {
    rtb_Switch = 1.0;
  } else if (rtb_Switch_n_idx_1 == 0.0) {
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
  if ((rtb_Integrator_i[1] != rtb_Switch_n_idx_1) && ((int8_T)rtb_Switch ==
       (int8_T)u0_tmp)) {
    rtb_Integrator_i[1] = 0.0;
  } else {
    rtb_Integrator_i[1] = rtb_Tnew[1];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  u0_tmp = rtb_Tnew[2];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Switch_n_idx_2 < 0.0) {
    rtb_Switch = -1.0;
  } else if (rtb_Switch_n_idx_2 > 0.0) {
    rtb_Switch = 1.0;
  } else if (rtb_Switch_n_idx_2 == 0.0) {
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
  if ((rtb_Integrator_i[2] != rtb_Switch_n_idx_2) && ((int8_T)rtb_Switch ==
       (int8_T)u0_tmp)) {
    rtb_Integrator_i[2] = 0.0;
  } else {
    rtb_Integrator_i[2] = rtb_Tnew[2];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  u0_tmp = rtb_Tnew[3];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_k_p_idx_3 < 0.0) {
    rtb_Switch = -1.0;
  } else if (rtb_k_p_idx_3 > 0.0) {
    rtb_Switch = 1.0;
  } else if (rtb_k_p_idx_3 == 0.0) {
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
  if ((rtb_Integrator_i[3] != rtb_k_p_idx_3) && ((int8_T)rtb_Switch == (int8_T)
       u0_tmp)) {
    rtb_Integrator_i[3] = 0.0;
  } else {
    rtb_Integrator_i[3] = rtb_Tnew[3];
  }

  /* Product: '<S80>/Divide' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Constant: '<S19>/Constant4'
   *  Inport: '<Root>/throttle'
   *  Sum: '<S80>/Subtract'
   */
  modValueRev = ((rtU.throttle - 0.05) + 0.01) / 0.02;

  /* Relay: '<S80>/Relay' */
  rtDW.Relay_Mode = ((modValueRev >= 2.2204460492503131E-16) || ((!(modValueRev <=
    2.2204460492503131E-16)) && rtDW.Relay_Mode));

  /* Product: '<S81>/Divide' incorporates:
   *  Constant: '<S19>/Constant5'
   *  Constant: '<S19>/Constant6'
   *  Inport: '<Root>/brake'
   *  Sum: '<S81>/Subtract'
   */
  rtb_Sign = ((rtU.brake - 0.1) + 0.01) / 0.02;

  /* Relay: '<S81>/Relay' */
  rtDW.Relay_Mode_o = ((rtb_Sign >= 2.2204460492503131E-16) || ((!(rtb_Sign <=
    2.2204460492503131E-16)) && rtDW.Relay_Mode_o));

  /* Logic: '<S19>/AND' incorporates:
   *  Constant: '<S19>/Constant2'
   *  Logic: '<S19>/NOT'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  Relay: '<S80>/Relay'
   *  Relay: '<S81>/Relay'
   */
  rtb_Logic_i_idx_1 = ((rtb_vx > 3.0) && rtDW.Relay_Mode && (!rtDW.Relay_Mode_o));

  /* Sum: '<S23>/Minus' */
  rtb_Tnew[0] = 0.13600000000000004 - rtb_k_p_idx_0;
  rtb_Tnew[1] = 0.13600000000000004 - rtb_k_p_idx_1;
  rtb_Tnew[2] = 0.13600000000000004 - rtb_k_p_idx_2;
  rtb_Tnew[3] = 0.13600000000000004 - rtb_k_e;

  /* DiscreteIntegrator: '<S119>/Integrator' */
  if (rtb_Logic_i_idx_1 && (rtDW.Integrator_PrevResetState_ig <= 0)) {
    rtDW.Integrator_DSTATE_k[0] = 0.0;
    rtDW.Integrator_DSTATE_k[1] = 0.0;
    rtDW.Integrator_DSTATE_k[2] = 0.0;
    rtDW.Integrator_DSTATE_k[3] = 0.0;
  }

  /* Sum: '<S129>/Sum' incorporates:
   *  Constant: '<S23>/Constant1'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Product: '<S124>/PProd Out'
   */
  rtb_TmpSignalConversionAtSFun_e[0] = rtb_Tnew[0] * 57.0 +
    rtDW.Integrator_DSTATE_k[0];
  rtb_TmpSignalConversionAtSFun_e[1] = rtb_Tnew[1] * 57.0 +
    rtDW.Integrator_DSTATE_k[1];
  rtb_TmpSignalConversionAtSFun_e[2] = rtb_Tnew[2] * 57.0 +
    rtDW.Integrator_DSTATE_k[2];
  rtb_TmpSignalConversionAtSFun_e[3] = rtb_Tnew[3] * 57.0 +
    rtDW.Integrator_DSTATE_k[3];

  /* Switch: '<S127>/Switch2' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S127>/LowerRelop1'
   *  RelationalOperator: '<S127>/UpperRelop'
   *  Switch: '<S127>/Switch'
   */
  if (rtb_TmpSignalConversionAtSFun_e[0] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    rtb_Minus[0] = 21.0;
  } else if (rtb_TmpSignalConversionAtSFun_e[0] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    rtb_Minus[0] = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Switch: '<S127>/Switch'
     */
    rtb_Minus[0] = rtb_TmpSignalConversionAtSFun_e[0];
  }

  if (rtb_TmpSignalConversionAtSFun_e[1] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    rtb_Minus[1] = 21.0;
  } else if (rtb_TmpSignalConversionAtSFun_e[1] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    rtb_Minus[1] = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Switch: '<S127>/Switch'
     */
    rtb_Minus[1] = rtb_TmpSignalConversionAtSFun_e[1];
  }

  if (rtb_TmpSignalConversionAtSFun_e[2] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    rtb_Minus[2] = 21.0;
  } else if (rtb_TmpSignalConversionAtSFun_e[2] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    rtb_Minus[2] = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Switch: '<S127>/Switch'
     */
    rtb_Minus[2] = rtb_TmpSignalConversionAtSFun_e[2];
  }

  if (rtb_TmpSignalConversionAtSFun_e[3] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    rtb_Minus[3] = 21.0;
  } else if (rtb_TmpSignalConversionAtSFun_e[3] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    rtb_Minus[3] = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Switch: '<S127>/Switch'
     */
    rtb_Minus[3] = rtb_TmpSignalConversionAtSFun_e[3];
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
    if (rtb_Logic_i_idx_1) {
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
  } else if (!rtb_Logic_i_idx_1) {
    exit_internal_TC_ON();
    rtDW.is_TS_ON = IN_TC_OFF;
    rtDW.T_max[0] = 21.0;
    rtDW.T_max[1] = 21.0;
    rtDW.T_max[2] = 21.0;
    rtDW.T_max[3] = 21.0;
  } else {
    if (rtDW.is_FL == IN_TC_ACTIVE) {
      if (rtb_UnaryMinus_k4[0] < 0.9 * rtDW.UnitDelay_DSTATE_b[0]) {
        rtDW.is_FL = IN_TC_INACTIVE;
        rtDW.T_max[0] = 21.0;
      } else {
        rtDW.T_max[0] = rtb_Minus[0];
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_p_idx_0 >= 0.14600000000000005) {
      rtDW.is_FL = IN_TC_ACTIVE;
      rtDW.T_max[0] = fabs(rtb_UnaryMinus_k4[0]);
    } else {
      rtDW.T_max[0] = 21.0;
    }

    if (rtDW.is_FR == IN_TC_ACTIVE) {
      if (rtb_UnaryMinus_k4[1] < 0.9 * rtDW.UnitDelay_DSTATE_b[1]) {
        rtDW.is_FR = IN_TC_INACTIVE;
        rtDW.T_max[1] = 21.0;
      } else {
        rtDW.T_max[1] = rtb_Minus[1];
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_p_idx_1 >= 0.14600000000000005) {
      rtDW.is_FR = IN_TC_ACTIVE;
      rtDW.T_max[1] = fabs(rtb_UnaryMinus_k4[1]);
    } else {
      rtDW.T_max[1] = 21.0;
    }

    if (rtDW.is_RL == IN_TC_ACTIVE) {
      if (rtb_UnaryMinus_k4[2] < 0.9 * rtDW.UnitDelay_DSTATE_b[2]) {
        rtDW.is_RL = IN_TC_INACTIVE;
        rtDW.T_max[2] = 21.0;
      } else {
        rtDW.T_max[2] = rtb_Minus[2];
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_p_idx_2 >= 0.14600000000000005) {
      rtDW.is_RL = IN_TC_ACTIVE;
      rtDW.T_max[2] = fabs(rtb_UnaryMinus_k4[2]);
    } else {
      rtDW.T_max[2] = 21.0;
    }

    if (rtDW.is_RR == IN_TC_ACTIVE) {
      if (rtb_UnaryMinus_k4[3] < 0.9 * rtDW.UnitDelay_DSTATE_b[3]) {
        rtDW.is_RR = IN_TC_INACTIVE;
        rtDW.T_max[3] = 21.0;
      } else {
        rtDW.T_max[3] = rtb_Minus[3];
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_e >= 0.14600000000000005) {
      rtDW.is_RR = IN_TC_ACTIVE;
      rtDW.T_max[3] = fabs(rtb_UnaryMinus_k4[3]);
    } else {
      rtDW.T_max[3] = 21.0;
    }
  }

  /* Gain: '<S109>/ZeroGain' */
  rtb_k_p_idx_0 = 0.0 * rtb_TmpSignalConversionAtSFun_e[0];
  rtb_k_p_idx_1 = 0.0 * rtb_TmpSignalConversionAtSFun_e[1];
  rtb_k_p_idx_2 = 0.0 * rtb_TmpSignalConversionAtSFun_e[2];
  rtb_k_p_idx_3 = 0.0 * rtb_TmpSignalConversionAtSFun_e[3];

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Sum: '<S112>/Diff'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_TmpSignalConversionAtSFun_e[0] >= 21.0) {
    rtb_vx = 21.0;
  } else if (rtb_TmpSignalConversionAtSFun_e[0] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_vx = rtb_TmpSignalConversionAtSFun_e[0];
  } else {
    rtb_vx = 4.9;
  }

  /* Sum: '<S112>/Diff' */
  rtb_TmpSignalConversionAtSFun_e[0] -= rtb_vx;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Sum: '<S112>/Diff'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_TmpSignalConversionAtSFun_e[1] >= 21.0) {
    rtb_vx = 21.0;
  } else if (rtb_TmpSignalConversionAtSFun_e[1] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_vx = rtb_TmpSignalConversionAtSFun_e[1];
  } else {
    rtb_vx = 4.9;
  }

  /* Sum: '<S112>/Diff' */
  rtb_TmpSignalConversionAtSFun_e[1] -= rtb_vx;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Sum: '<S112>/Diff'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_TmpSignalConversionAtSFun_e[2] >= 21.0) {
    rtb_vx = 21.0;
  } else if (rtb_TmpSignalConversionAtSFun_e[2] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_vx = rtb_TmpSignalConversionAtSFun_e[2];
  } else {
    rtb_vx = 4.9;
  }

  /* Sum: '<S112>/Diff' */
  rtb_TmpSignalConversionAtSFun_e[2] -= rtb_vx;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Sum: '<S112>/Diff'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_TmpSignalConversionAtSFun_e[3] >= 21.0) {
    rtb_vx = 21.0;
  } else if (rtb_TmpSignalConversionAtSFun_e[3] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_vx = rtb_TmpSignalConversionAtSFun_e[3];
  } else {
    rtb_vx = 4.9;
  }

  /* Sum: '<S112>/Diff' */
  rtb_TmpSignalConversionAtSFun_e[3] -= rtb_vx;

  /* Sum: '<S132>/SumI1' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S131>/Kt'
   *  Product: '<S116>/IProd Out'
   *  Sum: '<S131>/SumI3'
   */
  rtb_Tnew[0] = (rtDW.T_max[0] - rtb_Minus[0]) * 100.0 + rtb_Tnew[0] * 2845.0;
  rtb_Tnew[1] = (rtDW.T_max[1] - rtb_Minus[1]) * 100.0 + rtb_Tnew[1] * 2845.0;
  rtb_Tnew[2] = (rtDW.T_max[2] - rtb_Minus[2]) * 100.0 + rtb_Tnew[2] * 2845.0;
  rtb_Tnew[3] = (rtDW.T_max[3] - rtb_Minus[3]) * 100.0 + rtb_Tnew[3] * 2845.0;

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

  /* Switch: '<S201>/Switch' incorporates:
   *  Constant: '<S146>/Constant10'
   *  Constant: '<S146>/Constant9'
   *  RelationalOperator: '<S201>/u_GTE_up'
   *  RelationalOperator: '<S201>/u_GT_lo'
   *  Switch: '<S201>/Switch1'
   */
  if (rtb_front_wheel_angle_single__o >= 50.0) {
    rtb_vx = 50.0;
  } else if (rtb_front_wheel_angle_single__o > -50.0) {
    /* Switch: '<S201>/Switch1' */
    rtb_vx = rtb_front_wheel_angle_single__o;
  } else {
    rtb_vx = -50.0;
  }

  /* End of Switch: '<S201>/Switch' */

  /* Sum: '<S201>/Diff' */
  modValueRev = rtb_front_wheel_angle_single__o - rtb_vx;

  /* RelationalOperator: '<S198>/NotEqual' incorporates:
   *  Gain: '<S198>/ZeroGain'
   */
  rtb_LessThan3 = (0.0 * rtb_front_wheel_angle_single__o != modValueRev);

  /* Signum: '<S198>/SignPreSat' */
  if (modValueRev < 0.0) {
    rtb_vx = -1.0;
  } else if (modValueRev > 0.0) {
    rtb_vx = 1.0;
  } else if (modValueRev == 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = (rtNaN);
  }

  /* End of Signum: '<S198>/SignPreSat' */

  /* Sum: '<S221>/SumI1' incorporates:
   *  Constant: '<S146>/Const10ant15'
   *  Gain: '<S220>/Kt'
   *  Product: '<S205>/IProd Out'
   *  Sum: '<S220>/SumI3'
   */
  modValueRev = (rtb_Switch2_o - rtb_Switch2_o) * 100.0 + Faeroz_tmp * 20.0;

  /* Signum: '<S198>/SignPreIntegrator' */
  if (modValueRev < 0.0) {
    rtb_front_wheel_angle_single__o = -1.0;
  } else if (modValueRev > 0.0) {
    rtb_front_wheel_angle_single__o = 1.0;
  } else if (modValueRev == 0.0) {
    rtb_front_wheel_angle_single__o = 0.0;
  } else {
    rtb_front_wheel_angle_single__o = (rtNaN);
  }

  /* End of Signum: '<S198>/SignPreIntegrator' */

  /* Switch: '<S198>/Switch' incorporates:
   *  Constant: '<S198>/Constant1'
   *  DataTypeConversion: '<S198>/DataTypeConv1'
   *  DataTypeConversion: '<S198>/DataTypeConv2'
   *  Logic: '<S198>/AND3'
   *  RelationalOperator: '<S198>/Equal1'
   */
  if (rtb_LessThan3 && ((int8_T)rtb_vx == (int8_T)
                        rtb_front_wheel_angle_single__o)) {
    rtb_Gain1 = 0.0;
  } else {
    rtb_Gain1 = modValueRev;
  }

  /* End of Switch: '<S198>/Switch' */

  /* RelationalOperator: '<S283>/Less Than' incorporates:
   *  DataStoreRead: '<S283>/Data Store General_Params'
   *  Inport: '<Root>/brake'
   */
  rtb_LessThan3 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S283>/T_Req_Chart' */
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
    /* SignalConversion generated from: '<S303>/1-D Lookup Table' incorporates:
     *  Constant: '<S303>/Constant'
     *  DataStoreRead: '<S303>/Data Store Read'
     *  Switch: '<S283>/Switch'
     */
    csumrev[0] = rtDW.General_Params.BrakeThresh;
    csumrev[1] = 1.0;

    /* Lookup_n-D: '<S303>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/brake'
     *  Switch: '<S283>/Switch'
     */
    u0 = look1_binlx(rtU.brake, csumrev, rtConstP.uDLookupTable_tableData, 1U);

    /* Saturate: '<S303>/Saturation_Brake' incorporates:
     *  Switch: '<S283>/Switch'
     */
    if (u0 > 1.0) {
      u0 = 1.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    /* End of Saturate: '<S303>/Saturation_Brake' */

    /* Switch: '<S283>/Switch' incorporates:
     *  Gain: '<S303>/Gain_Max_Torque_Needed'
     */
    rtb_SumofElements1 = -529.2 * u0;
  }

  if (guard1) {
    /* Switch: '<S302>/Switch' incorporates:
     *  DataStoreRead: '<S302>/Data Store General_Params1'
     *  Inport: '<Root>/throttle'
     *  RelationalOperator: '<S302>/Less Than'
     *  Switch: '<S283>/Switch'
     */
    if (rtU.throttle > rtDW.General_Params.ThrottleThresh) {
      /* SignalConversion generated from: '<S302>/T_nominal_wheel_LUT' incorporates:
       *  Constant: '<S302>/Constant1'
       *  Constant: '<S302>/Constant2'
       *  DataStoreRead: '<S302>/Data Store General_Params'
       */
      rtb_CCaller_o13[0] = 0.0;
      rtb_CCaller_o13[1] = rtDW.General_Params.ThrottleThresh;
      rtb_CCaller_o13[2] = 1.0;

      /* MultiPortSwitch: '<S302>/Map_Selector' incorporates:
       *  Lookup_n-D: '<S302>/T_peak_wheel_LUT'
       */
      rtb_SumofElements1 = look1_binlx(rtU.throttle, rtb_CCaller_o13,
        rtConstP.T_peak_wheel_LUT_tableData, 2U);
    }

    /* End of Switch: '<S302>/Switch' */
  }

  /* End of Chart: '<S283>/T_Req_Chart' */

  /* MATLABSystem: '<S283>/Moving Average' */
  if (rtDW.obj.TunablePropsChanged) {
    rtDW.obj.TunablePropsChanged = false;
  }

  obj_0 = rtDW.obj.pStatistic;
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
  csum = obj_0->pCumSum;
  rtb_Minus[0] = obj_0->pCumSumRev[0];
  rtb_Minus[1] = obj_0->pCumSumRev[1];
  rtb_Minus[2] = obj_0->pCumSumRev[2];
  rtb_Minus[3] = obj_0->pCumSumRev[3];
  modValueRev = obj_0->pModValueRev;
  csum += rtb_SumofElements1;
  rtb_Minus[(int32_T)cumRevIndex - 1] = rtb_SumofElements1;
  if (cumRevIndex != 4.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    rtb_Minus[2] += rtb_Minus[3];
    rtb_Minus[1] += rtb_Minus[2];
    rtb_Minus[0] += rtb_Minus[1];
  }

  obj_0->pCumSum = csum;
  obj_0->pCumSumRev[0] = rtb_Minus[0];
  obj_0->pCumSumRev[1] = rtb_Minus[1];
  obj_0->pCumSumRev[2] = rtb_Minus[2];
  obj_0->pCumSumRev[3] = rtb_Minus[3];
  obj_0->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj_0->pModValueRev = modValueRev - 1.0;
  } else {
    obj_0->pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S283>/Moving Average' */

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
  rtDW.Integrator_DSTATE[0] += 0.02 * rtb_Integrator_i[0];
  rtDW.Integrator_DSTATE[1] += 0.02 * rtb_Integrator_i[1];
  rtDW.Integrator_DSTATE[2] += 0.02 * rtb_Integrator_i[2];
  rtDW.Integrator_DSTATE[3] += 0.02 * rtb_Integrator_i[3];
  rtDW.Integrator_PrevResetState = (int8_T)AND;

  /* Update for Memory: '<S139>/Memory' incorporates:
   *  Product: '<S145>/Divide'
   */
  rtDW.Memory_PreviousInput[0] = rtb_Switch2_c[0];
  rtDW.Memory_PreviousInput[1] = rtb_Switch2_c[1];
  rtDW.Memory_PreviousInput[2] = rtb_Switch2_c[2];
  rtDW.Memory_PreviousInput[3] = rtb_Switch2_c[3];

  /* Update for DiscreteIntegrator: '<S292>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S285>/1//T' incorporates:
   *  Constant: '<S287>/Time constant'
   *  MinMax: '<S287>/Max'
   */
  cumRevIndex = 1.0 / fmax(rtDW.Probe[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S292>/Integrator' */
  rtDW.Integrator_PrevResetState_i = (int8_T)rtb_Compare;

  /* Update for DiscreteIntegrator: '<S301>/Integrator' */
  rtDW.Integrator_IC_LOADING_m = 0U;

  /* Product: '<S294>/1//T' incorporates:
   *  Constant: '<S296>/Time constant'
   *  MinMax: '<S296>/Max'
   */
  rtb_RR = 1.0 / fmax(rtDW.Probe_g[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S301>/Integrator' */
  rtDW.Integrator_PrevResetState_c = (int8_T)rtb_Compare_c;

  /* Update for DiscreteIntegrator: '<S292>/Integrator' incorporates:
   *  Product: '<S285>/1//T'
   *  Sum: '<S285>/Sum1'
   */
  rtDW.Integrator_DSTATE_a[0] += (rtb_ome_wheels_idx_3 - rtb_Integrator_idx_0) *
    cumRevIndex * 0.02;

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

  /* Update for DiscreteIntegrator: '<S301>/Integrator' incorporates:
   *  Product: '<S294>/1//T'
   *  Sum: '<S294>/Sum1'
   */
  rtDW.Integrator_DSTATE_e[0] += (rtb_Saturation_c_idx_0 -
    rtb_Integrator_a_idx_0) * rtb_RR * 0.02;

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

  /* Update for DiscreteIntegrator: '<S292>/Integrator' incorporates:
   *  Product: '<S285>/1//T'
   *  Sum: '<S285>/Sum1'
   */
  rtDW.Integrator_DSTATE_a[1] += (rtb_Gain_idx_1 - rtb_Integrator_idx_1) *
    cumRevIndex * 0.02;

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

  /* Update for DiscreteIntegrator: '<S301>/Integrator' incorporates:
   *  Product: '<S294>/1//T'
   *  Sum: '<S294>/Sum1'
   */
  rtDW.Integrator_DSTATE_e[1] += (rtb_Saturation_c_idx_1 -
    rtb_Integrator_a_idx_1) * rtb_RR * 0.02;

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

  /* Update for DiscreteIntegrator: '<S292>/Integrator' incorporates:
   *  Product: '<S285>/1//T'
   *  Sum: '<S285>/Sum1'
   */
  rtDW.Integrator_DSTATE_a[2] += (rtb_Gain_idx_2 - rtb_Integrator_idx_2) *
    cumRevIndex * 0.02;

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

  /* Update for DiscreteIntegrator: '<S301>/Integrator' incorporates:
   *  Product: '<S294>/1//T'
   *  Sum: '<S294>/Sum1'
   */
  rtDW.Integrator_DSTATE_e[2] += (rtb_Saturation_c_idx_2 -
    rtb_Integrator_a_idx_2) * rtb_RR * 0.02;

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

  /* Update for DiscreteIntegrator: '<S292>/Integrator' incorporates:
   *  Product: '<S285>/1//T'
   *  Sum: '<S285>/Sum1'
   */
  rtDW.Integrator_DSTATE_a[3] += (rtb_Gain_idx_3 - rtb_Integrator_idx_3) *
    cumRevIndex * 0.02;

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

  /* Update for DiscreteIntegrator: '<S301>/Integrator' incorporates:
   *  Product: '<S294>/1//T'
   *  Sum: '<S294>/Sum1'
   */
  rtDW.Integrator_DSTATE_e[3] += (rtb_Saturation_c_idx_3 -
    rtb_Integrator_a_idx_3) * rtb_RR * 0.02;

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

  /* Update for Memory: '<S253>/Memory' */
  rtDW.Memory_PreviousInput_k = rtb_Logic_idx_0;

  /* Update for Memory: '<S254>/Memory' */
  rtDW.Memory_PreviousInput_kk = rtb_Logic_a_idx_0;

  /* Update for Memory: '<S255>/Memory' */
  rtDW.Memory_PreviousInput_b = rtb_Logic_i_idx_0;

  /* Update for Memory: '<S256>/Memory' */
  rtDW.Memory_PreviousInput_a = rtb_Logic_m_idx_0;

  /* Update for Memory: '<S228>/Memory' */
  rtDW.Memory_PreviousInput_n = rtb_Logic_idx_1;

  /* Update for DiscreteIntegrator: '<S208>/Integrator' */
  rtDW.Integrator_DSTATE_b += 0.02 * rtb_Gain1;
  rtDW.Integrator_PrevResetState_n = (int8_T)rtb_Logic_a_idx_1;

  /* Update for DiscreteIntegrator: '<S203>/Filter' incorporates:
   *  DiscreteIntegrator: '<S208>/Integrator'
   */
  rtDW.Filter_DSTATE += 0.02 * rtb_NProdOut;
  rtDW.Filter_PrevResetState = (int8_T)rtb_Logic_a_idx_1;

  /* Update for DiscreteFir: '<S156>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf] =
    rtb_Integrator_ac;

  /* End of Update for DiscreteFir: '<S156>/Discrete FIR Filter' */

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_f[0] = rtDW.T_min[0];
  rtDW.UnitDelay_DSTATE_f[1] = rtDW.T_min[1];
  rtDW.UnitDelay_DSTATE_f[2] = rtDW.T_min[2];
  rtDW.UnitDelay_DSTATE_f[3] = rtDW.T_min[3];

  /* Signum: '<S109>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp = rtb_TmpSignalConversionAtSFun_e[0];

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp_1 = rtb_Tnew[0];

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
  if (u0_tmp_1 < 0.0) {
    u0_tmp_1 = -1.0;
  } else if (u0_tmp_1 > 0.0) {
    u0_tmp_1 = 1.0;
  } else if (u0_tmp_1 == 0.0) {
    u0_tmp_1 = 0.0;
  } else {
    u0_tmp_1 = (rtNaN);
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
  if ((rtb_k_p_idx_0 != rtb_TmpSignalConversionAtSFun_e[0]) && ((int8_T)u0_tmp ==
       (int8_T)u0_tmp_1)) {
    rtb_k_e = 0.0;
  } else {
    rtb_k_e = rtb_Tnew[0];
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_k[0] += 0.02 * rtb_k_e;

  /* Signum: '<S109>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp = rtb_TmpSignalConversionAtSFun_e[1];

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp_1 = rtb_Tnew[1];

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
  if (u0_tmp_1 < 0.0) {
    u0_tmp_1 = -1.0;
  } else if (u0_tmp_1 > 0.0) {
    u0_tmp_1 = 1.0;
  } else if (u0_tmp_1 == 0.0) {
    u0_tmp_1 = 0.0;
  } else {
    u0_tmp_1 = (rtNaN);
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
  if ((rtb_k_p_idx_1 != rtb_TmpSignalConversionAtSFun_e[1]) && ((int8_T)u0_tmp ==
       (int8_T)u0_tmp_1)) {
    rtb_k_e = 0.0;
  } else {
    rtb_k_e = rtb_Tnew[1];
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_k[1] += 0.02 * rtb_k_e;

  /* Signum: '<S109>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp = rtb_TmpSignalConversionAtSFun_e[2];

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp_1 = rtb_Tnew[2];

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
  if (u0_tmp_1 < 0.0) {
    u0_tmp_1 = -1.0;
  } else if (u0_tmp_1 > 0.0) {
    u0_tmp_1 = 1.0;
  } else if (u0_tmp_1 == 0.0) {
    u0_tmp_1 = 0.0;
  } else {
    u0_tmp_1 = (rtNaN);
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
  if ((rtb_k_p_idx_2 != rtb_TmpSignalConversionAtSFun_e[2]) && ((int8_T)u0_tmp ==
       (int8_T)u0_tmp_1)) {
    rtb_k_e = 0.0;
  } else {
    rtb_k_e = rtb_Tnew[2];
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_k[2] += 0.02 * rtb_k_e;

  /* Signum: '<S109>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp = rtb_TmpSignalConversionAtSFun_e[3];

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S119>/Integrator'
   */
  u0_tmp_1 = rtb_Tnew[3];

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
  if (u0_tmp_1 < 0.0) {
    u0_tmp_1 = -1.0;
  } else if (u0_tmp_1 > 0.0) {
    u0_tmp_1 = 1.0;
  } else if (u0_tmp_1 == 0.0) {
    u0_tmp_1 = 0.0;
  } else {
    u0_tmp_1 = (rtNaN);
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
  if ((rtb_k_p_idx_3 != rtb_TmpSignalConversionAtSFun_e[3]) && ((int8_T)u0_tmp ==
       (int8_T)u0_tmp_1)) {
    rtb_k_e = 0.0;
  } else {
    rtb_k_e = rtb_Tnew[3];
  }

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_k[3] += 0.02 * rtb_k_e;
  rtDW.Integrator_PrevResetState_ig = (int8_T)rtb_Logic_i_idx_1;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_b[0] = rtDW.T_max[0];
  rtDW.UnitDelay_DSTATE_b[1] = rtDW.T_max[1];
  rtDW.UnitDelay_DSTATE_b[2] = rtDW.T_max[2];
  rtDW.UnitDelay_DSTATE_b[3] = rtDW.T_max[3];

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
  rtY.Torque[0] = rtb_Switch2_c[0];
  rtY.Torque[1] = rtb_Switch2_c[1];
  rtY.Torque[2] = rtb_Switch2_c[2];
  rtY.Torque[3] = rtb_Switch2_c[3];
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

    /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
    /* Start for Probe: '<S287>/Probe' */
    rtDW.Probe[0] = 0.02;
    rtDW.Probe[1] = 0.0;

    /* Start for Probe: '<S296>/Probe' */
    rtDW.Probe_g[0] = 0.02;
    rtDW.Probe_g[1] = 0.0;

    /* Start for InitialCondition: '<S232>/IC' */
    rtDW.IC_FirstOutputTime = true;

    /* Start for InitialCondition: '<S233>/IC1' */
    rtDW.IC1_FirstOutputTime = true;

    /* Start for DataStoreMemory: '<S3>/Data Store_General_Params' */
    rtDW.General_Params = rtConstP.DataStore_General_Params_Initia;

    /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator' */
    rtDW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S292>/Integrator' */
    rtDW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator' */
    rtDW.Integrator_IC_LOADING_m = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
    rtDW.Integrator_PrevResetState_ig = 2;

    /* SystemInitialize for Chart: '<S236>/Distribution complete' */
    rtDW.tr = 1.27;
    rtDW.Rw = 0.235;

    /* Start for MATLABSystem: '<S171>/Moving Average' */
    rtDW.obj_o.matlabCodegenIsDeleted = true;
    rtDW.obj_o.isInitialized = 0;
    rtDW.obj_o.NumChannels = -1;
    rtDW.obj_o.matlabCodegenIsDeleted = false;
    rtDW.obj_o.isSetupComplete = false;
    rtDW.obj_o.isInitialized = 1;
    rtDW.obj_o.NumChannels = 1;
    iobj_0 = &rtDW.obj_o._pobj0;
    iobj_0->isInitialized = 0;
    iobj_0->isInitialized = 0;
    rtDW.obj_o.pStatistic = iobj_0;
    rtDW.obj_o.isSetupComplete = true;
    rtDW.obj_o.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S171>/Moving Average' */
    iobj_0 = rtDW.obj_o.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum = 0.0;
      iobj_0->pCumSumRev[0] = 0.0;
      iobj_0->pCumSumRev[1] = 0.0;
      iobj_0->pCumRevIndex = 1.0;
      iobj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S171>/Moving Average' */

    /* Start for MATLABSystem: '<S283>/Moving Average' */
    rtDW.obj.matlabCodegenIsDeleted = true;
    rtDW.obj.isInitialized = 0;
    rtDW.obj.NumChannels = -1;
    rtDW.obj.matlabCodegenIsDeleted = false;
    rtDW.obj.isSetupComplete = false;
    rtDW.obj.isInitialized = 1;
    rtDW.obj.NumChannels = 1;
    iobj_0_0 = &rtDW.obj._pobj0;
    iobj_0_0->isInitialized = 0;
    iobj_0_0->isInitialized = 0;
    rtDW.obj.pStatistic = iobj_0_0;
    rtDW.obj.isSetupComplete = true;
    rtDW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S283>/Moving Average' */
    iobj_0_0 = rtDW.obj.pStatistic;
    if (iobj_0_0->isInitialized == 1) {
      iobj_0_0->pCumSum = 0.0;
      iobj_0_0->pCumSumRev[0] = 0.0;
      iobj_0_0->pCumSumRev[1] = 0.0;
      iobj_0_0->pCumSumRev[2] = 0.0;
      iobj_0_0->pCumSumRev[3] = 0.0;
      iobj_0_0->pCumRevIndex = 1.0;
      iobj_0_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S283>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
