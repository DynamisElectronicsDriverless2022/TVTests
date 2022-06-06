/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Jun  6 11:03:25 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TVModel.h"

/* Named constants for Chart: '<S22>/Chart' */
#define IN_OFF                         ((uint8_T)1U)
#define IN_ON                          ((uint8_T)2U)
#define IN_SWITCHING_FILTER            ((uint8_T)3U)
#define TC_filter_tau                  (0.98019867330675525)

/* Named constants for Chart: '<S150>/Overlap Chart' */
#define IN_Go                          ((uint8_T)1U)
#define IN_Stop                        ((uint8_T)2U)

/* Named constants for Chart: '<S151>/Chart' */
#define IN_OFF_c                       ((uint8_T)1U)
#define IN_ON_n                        ((uint8_T)2U)
#define IN_SWITCHING_FILTER_p          ((uint8_T)3U)
#define mz_filter_tau                  (0.98019867330675525)

/* Named constants for Chart: '<S281>/T_Req_Chart' */
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
static void MATLABFunction1(real_T rtu_vx, real_T rtu_kappa, real_T rtu_kappa_o,
  real_T rtu_kappa_d, real_T rtu_kappa_f, real_T rtu_Fz, real_T rtu_Fz_e, real_T
  rtu_Fz_l, real_T rtu_Fz_d, const real_T rtu_kappa_p[4], const real_T
  rtu_omega_p[4], real_T rty_T_ff[4], real_T rty_T_ff_deceleration[4], real_T
  rty_T_ff_slip[4]);
static void Chart_Init(real_T *rty_TC_max);
static void Chart(real_T rtu_T_ff, boolean_T rtu_epsilon, real_T *rty_TC_max,
                  DW_Chart *localDW);
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
 *    '<S16>/MATLAB Function1'
 *    '<S17>/MATLAB Function1'
 */
static void MATLABFunction1(real_T rtu_vx, real_T rtu_kappa, real_T rtu_kappa_o,
  real_T rtu_kappa_d, real_T rtu_kappa_f, real_T rtu_Fz, real_T rtu_Fz_e, real_T
  rtu_Fz_l, real_T rtu_Fz_d, const real_T rtu_kappa_p[4], const real_T
  rtu_omega_p[4], real_T rty_T_ff[4], real_T rty_T_ff_deceleration[4], real_T
  rty_T_ff_slip[4])
{
  real_T b_tmp;
  real_T b_tmp_0;
  real_T tmp;

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  rty_T_ff_slip[0] = rtu_kappa;
  rty_T_ff_slip[1] = rtu_kappa_o;
  rty_T_ff_slip[2] = rtu_kappa_d;
  rty_T_ff_slip[3] = rtu_kappa_f;
  tmp = 1.0 / rtu_vx;

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  b_tmp = (rty_T_ff_slip[0] - 1.57E-6 * rtu_Fz) + 0.000666;
  rty_T_ff_deceleration[0] = rtu_Fz * rtu_Fz;
  if (b_tmp < 0.0) {
    b_tmp_0 = -1.0;
  } else if (b_tmp > 0.0) {
    b_tmp_0 = 1.0;
  } else if (b_tmp == 0.0) {
    b_tmp_0 = 0.0;
  } else {
    b_tmp_0 = (rtNaN);
  }

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  b_tmp = exp(0.0135 - 1.35E-5 * rtu_Fz) * (0.7 * rtu_Fz) * (0.015 * rtu_Fz +
    67.7) * b_tmp / (2.71 * rtu_Fz * 0.93 + 0.01);
  rty_T_ff_deceleration[0] = (0.0001 * rty_T_ff_deceleration[0] * 0.93 - sin
    (atan((5.95E-5 * rtu_Fz - 0.657) * 0.7 * (0.524 * b_tmp_0 + 1.0) * (atan
    (b_tmp) - b_tmp) - b_tmp) * 1.41) * (1.92 * rtu_Fz * 0.93)) / rtu_Fz;
  rty_T_ff_slip[0] = (((1.0 - rty_T_ff_slip[0]) / 67.5 + 0.27612499999999995) *
                      tmp * rtu_Fz * rty_T_ff_deceleration[0] + rtu_kappa_p[0]) *
    rtu_vx * 0.2 / 0.235 / 13.5;
  rty_T_ff_deceleration[0] = (0.028147298674821606 * rty_T_ff_deceleration[0] *
    rtu_Fz - -rtu_omega_p[0] * 0.235 / 9.81) * 0.2 * 9.81 / 0.235 / 13.5 / 2.0;
  rty_T_ff[0] = rty_T_ff_deceleration[0] * 0.0 + rty_T_ff_slip[0];

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  b_tmp = (rty_T_ff_slip[1] - 1.57E-6 * rtu_Fz_e) + 0.000666;
  rty_T_ff_deceleration[1] = rtu_Fz_e * rtu_Fz_e;
  if (b_tmp < 0.0) {
    b_tmp_0 = -1.0;
  } else if (b_tmp > 0.0) {
    b_tmp_0 = 1.0;
  } else if (b_tmp == 0.0) {
    b_tmp_0 = 0.0;
  } else {
    b_tmp_0 = (rtNaN);
  }

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  b_tmp = exp(0.0135 - 1.35E-5 * rtu_Fz_e) * (0.7 * rtu_Fz_e) * (0.015 *
    rtu_Fz_e + 67.7) * b_tmp / (2.71 * rtu_Fz_e * 0.93 + 0.01);
  rty_T_ff_deceleration[1] = (0.0001 * rty_T_ff_deceleration[1] * 0.93 - sin
    (atan((5.95E-5 * rtu_Fz_e - 0.657) * 0.7 * (0.524 * b_tmp_0 + 1.0) * (atan
    (b_tmp) - b_tmp) - b_tmp) * 1.41) * (1.92 * rtu_Fz_e * 0.93)) / rtu_Fz_e;
  rty_T_ff_slip[1] = (((1.0 - rty_T_ff_slip[1]) / 67.5 + 0.27612499999999995) *
                      tmp * rtu_Fz_e * rty_T_ff_deceleration[1] + rtu_kappa_p[1])
    * rtu_vx * 0.2 / 0.235 / 13.5;
  rty_T_ff_deceleration[1] = (0.028147298674821606 * rty_T_ff_deceleration[1] *
    rtu_Fz_e - -rtu_omega_p[1] * 0.235 / 9.81) * 0.2 * 9.81 / 0.235 / 13.5 / 2.0;
  rty_T_ff[1] = rty_T_ff_deceleration[1] * 0.0 + rty_T_ff_slip[1];

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  b_tmp = (rty_T_ff_slip[2] - 1.57E-6 * rtu_Fz_l) + 0.000666;
  rty_T_ff_deceleration[2] = rtu_Fz_l * rtu_Fz_l;
  if (b_tmp < 0.0) {
    b_tmp_0 = -1.0;
  } else if (b_tmp > 0.0) {
    b_tmp_0 = 1.0;
  } else if (b_tmp == 0.0) {
    b_tmp_0 = 0.0;
  } else {
    b_tmp_0 = (rtNaN);
  }

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  b_tmp = exp(0.0135 - 1.35E-5 * rtu_Fz_l) * (0.7 * rtu_Fz_l) * (0.015 *
    rtu_Fz_l + 67.7) * b_tmp / (2.71 * rtu_Fz_l * 0.93 + 0.01);
  rty_T_ff_deceleration[2] = (0.0001 * rty_T_ff_deceleration[2] * 0.93 - sin
    (atan((5.95E-5 * rtu_Fz_l - 0.657) * 0.7 * (0.524 * b_tmp_0 + 1.0) * (atan
    (b_tmp) - b_tmp) - b_tmp) * 1.41) * (1.92 * rtu_Fz_l * 0.93)) / rtu_Fz_l;
  rty_T_ff_slip[2] = (((1.0 - rty_T_ff_slip[2]) / 67.5 + 0.27612499999999995) *
                      tmp * rtu_Fz_l * rty_T_ff_deceleration[2] + rtu_kappa_p[2])
    * rtu_vx * 0.2 / 0.235 / 13.5;
  rty_T_ff_deceleration[2] = (0.028147298674821606 * rty_T_ff_deceleration[2] *
    rtu_Fz_l - -rtu_omega_p[2] * 0.235 / 9.81) * 0.2 * 9.81 / 0.235 / 13.5 / 2.0;
  rty_T_ff[2] = rty_T_ff_deceleration[2] * 0.0 + rty_T_ff_slip[2];

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  b_tmp = (rty_T_ff_slip[3] - 1.57E-6 * rtu_Fz_d) + 0.000666;
  rty_T_ff_deceleration[3] = rtu_Fz_d * rtu_Fz_d;
  if (b_tmp < 0.0) {
    b_tmp_0 = -1.0;
  } else if (b_tmp > 0.0) {
    b_tmp_0 = 1.0;
  } else if (b_tmp == 0.0) {
    b_tmp_0 = 0.0;
  } else {
    b_tmp_0 = (rtNaN);
  }

  /* SignalConversion generated from: '<S20>/ SFunction ' */
  b_tmp = exp(0.0135 - 1.35E-5 * rtu_Fz_d) * (0.7 * rtu_Fz_d) * (0.015 *
    rtu_Fz_d + 67.7) * b_tmp / (2.71 * rtu_Fz_d * 0.93 + 0.01);
  rty_T_ff_deceleration[3] = (0.0001 * rty_T_ff_deceleration[3] * 0.93 - sin
    (atan((5.95E-5 * rtu_Fz_d - 0.657) * 0.7 * (0.524 * b_tmp_0 + 1.0) * (atan
    (b_tmp) - b_tmp) - b_tmp) * 1.41) * (1.92 * rtu_Fz_d * 0.93)) / rtu_Fz_d;
  rty_T_ff_slip[3] = (((1.0 - rty_T_ff_slip[3]) / 67.5 + 0.27612499999999995) *
                      tmp * rtu_Fz_d * rty_T_ff_deceleration[3] + rtu_kappa_p[3])
    * rtu_vx * 0.2 / 0.235 / 13.5;
  rty_T_ff_deceleration[3] = (0.028147298674821606 * rty_T_ff_deceleration[3] *
    rtu_Fz_d - -rtu_omega_p[3] * 0.235 / 9.81) * 0.2 * 9.81 / 0.235 / 13.5 / 2.0;
  rty_T_ff[3] = rty_T_ff_deceleration[3] * 0.0 + rty_T_ff_slip[3];
}

/*
 * System initialize for atomic system:
 *    '<S22>/Chart'
 *    '<S22>/Chart1'
 *    '<S22>/Chart2'
 *    '<S22>/Chart3'
 *    '<S85>/Chart'
 *    '<S85>/Chart1'
 *    '<S85>/Chart2'
 *    '<S85>/Chart3'
 */
static void Chart_Init(real_T *rty_TC_max)
{
  *rty_TC_max = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S22>/Chart'
 *    '<S22>/Chart1'
 *    '<S22>/Chart2'
 *    '<S22>/Chart3'
 *    '<S85>/Chart'
 *    '<S85>/Chart1'
 *    '<S85>/Chart2'
 *    '<S85>/Chart3'
 */
static void Chart(real_T rtu_T_ff, boolean_T rtu_epsilon, real_T *rty_TC_max,
                  DW_Chart *localDW)
{
  boolean_T countCondIsTrue;
  localDW->chartGlobalTickCounter++;
  countCondIsTrue = (localDW->is_c26_TVModel == 3);
  if ((!countCondIsTrue) || (!localDW->countCondWasTrueAtLastTimeStep_)) {
    localDW->countReferenceTick_1 = localDW->chartGlobalTickCounter;
  }

  localDW->countCondWasTrueAtLastTimeStep_ = countCondIsTrue;

  /* Chart: '<S22>/Chart' */
  if (localDW->is_active_c26_TVModel == 0U) {
    localDW->chartGlobalTickCounter = 0;
    localDW->is_active_c26_TVModel = 1U;
    localDW->is_c26_TVModel = IN_OFF;
    *rty_TC_max = 21.0;
  } else {
    switch (localDW->is_c26_TVModel) {
     case IN_OFF:
      if (rtu_epsilon) {
        localDW->is_c26_TVModel = IN_ON;
        *rty_TC_max = rtu_T_ff;
      } else {
        *rty_TC_max = 21.0;
      }
      break;

     case IN_ON:
      if (!rtu_epsilon) {
        localDW->countReferenceTick_1 = localDW->chartGlobalTickCounter;
        localDW->is_c26_TVModel = IN_SWITCHING_FILTER;
        *rty_TC_max *= TC_filter_tau;
        localDW->countCondWasTrueAtLastTimeStep_ = (localDW->is_c26_TVModel == 3);
      } else {
        *rty_TC_max = rtu_T_ff;
      }
      break;

     default:
      /* case IN_SWITCHING_FILTER: */
      countCondIsTrue = (localDW->is_c26_TVModel == 3);
      if ((!countCondIsTrue) || (!localDW->countCondWasTrueAtLastTimeStep_)) {
        localDW->countReferenceTick_1 = localDW->chartGlobalTickCounter;
      }

      localDW->countCondWasTrueAtLastTimeStep_ = countCondIsTrue;
      if (localDW->chartGlobalTickCounter - localDW->countReferenceTick_1 > 10)
      {
        localDW->is_c26_TVModel = IN_OFF;
        *rty_TC_max = 21.0;
      } else if (rtu_epsilon) {
        localDW->is_c26_TVModel = IN_ON;
        *rty_TC_max = rtu_T_ff;
      } else {
        *rty_TC_max *= TC_filter_tau;
      }
      break;
    }
  }

  /* End of Chart: '<S22>/Chart' */
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
  real_T rtb_y_c[121];
  real_T varargin_1[49];
  real_T rtb_CCaller_o12[35];
  real_T rtb_CCaller_o3[26];
  real_T csumrev[24];
  real_T rtb_VectorConcatenate[22];
  real_T varargin_2[16];
  real_T RateTransition3[13];
  real_T rtb_TmpSignalConversionAtSFunct[11];
  real_T rtb_X1[7];
  real_T rtb_CCaller_o10[5];
  real_T rtb_lg[5];
  real_T rtb_Diff[4];
  real_T rtb_Driving[4];
  real_T rtb_Saturation[4];
  real_T rtb_T_ff_deceleration[4];
  real_T rtb_T_ff_deceleration_n[4];
  real_T rtb_T_ff_slip_g[4];
  real_T rtb_UnaryMinus_e5[4];
  real_T tmp[3];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T Faeroz_tmp;
  real_T rtb_Abs_g;
  real_T rtb_Abs_m_idx_0;
  real_T rtb_Diff_i;
  real_T rtb_Diff_m;
  real_T rtb_Diff_p;
  real_T rtb_FilterCoefficient_idx_0;
  real_T rtb_FilterCoefficient_idx_1;
  real_T rtb_FilterCoefficient_idx_2;
  real_T rtb_Filter_n_idx_0;
  real_T rtb_Filter_n_idx_1;
  real_T rtb_Filter_n_idx_2;
  real_T rtb_Filter_n_idx_3;
  real_T rtb_Gain1;
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_1;
  real_T rtb_IntegralGain_idx_0;
  real_T rtb_IntegralGain_idx_1;
  real_T rtb_IntegralGain_idx_2;
  real_T rtb_IntegralGain_idx_3;
  real_T rtb_IntegralGain_n;
  real_T rtb_Integrator_b;
  real_T rtb_Integrator_d;
  real_T rtb_Integrator_g;
  real_T rtb_Integrator_h_idx_0;
  real_T rtb_Integrator_h_idx_1;
  real_T rtb_Integrator_h_idx_2;
  real_T rtb_Integrator_h_idx_3;
  real_T rtb_Integrator_k;
  real_T rtb_Integrator_k_idx_2;
  real_T rtb_RL;
  real_T rtb_RR;
  real_T rtb_RR_tmp;
  real_T rtb_RR_tmp_0;
  real_T rtb_Saturation_c_idx_0;
  real_T rtb_Saturation_c_idx_1;
  real_T rtb_Saturation_c_idx_2;
  real_T rtb_Saturation_c_idx_3;
  real_T rtb_Saturation_fy;
  real_T rtb_SumofElements1;
  real_T rtb_Switch;
  real_T rtb_Switch_g;
  real_T rtb_Switch_h;
  real_T rtb_T_ff_deceleration_a;
  real_T rtb_T_ff_deceleration_bl;
  real_T rtb_T_ff_deceleration_f;
  real_T rtb_T_ff_deceleration_p;
  real_T rtb_Tnew_idx_1;
  real_T rtb_Tnew_idx_2;
  real_T rtb_Tnew_idx_3;
  real_T rtb_UnaryMinus_pe;
  real_T rtb_fl;
  real_T rtb_fl_c;
  real_T rtb_fr;
  real_T rtb_fr_a;
  real_T rtb_rl;
  real_T rtb_rl_d;
  real_T rtb_rr;
  real_T rtb_rr_l;
  real_T rtb_vx;
  real_T tmp_0;
  real_T vx;
  real_T vx_p;
  int32_T b_exit;
  int32_T i;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_n;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_idx_1;
  boolean_T rtb_Logic_l_idx_0;
  boolean_T rtb_Logic_l_idx_1;
  boolean_T rtb_Logic_o_idx_0;
  boolean_T rtb_Logic_p_idx_0;
  boolean_T rtb_Logic_p_idx_1;
  boolean_T rtb_NOT_idx_0;
  boolean_T rtb_NOT_idx_1;
  boolean_T rtb_NOT_idx_2;
  boolean_T rtb_NOT_idx_3;
  static const int8_T b[7] = { 0, 0, 0, 1, 1, 1, 1 };

  static const int8_T c[7] = { 0, 0, 0, 0, 1, 0, -1 };

  static const int8_T d[7] = { 0, 0, 0, 1, 0, -1, 0 };

  real_T rtb_Product1_idx_0;
  real_T rtb_RR_tmp_1;
  real_T rtb_RR_tmp_2;
  real_T rtb_RR_tmp_tmp;
  real_T rtb_RR_tmp_tmp_0;
  real_T rtb_fr_k_tmp;
  real_T rtb_fr_k_tmp_tmp;
  boolean_T guard1 = false;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (rtU.vx <= 0.0) {
    rtb_Integrator_b = 0.0;
  } else {
    rtb_Integrator_b = rtU.vx;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/yaw_rate'
   */
  rtb_Gain1 = 0.017453292519943295 * rtU.yaw_rate_deg;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Integrator_b <= 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = rtb_Integrator_b;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Signum: '<S9>/Sign' incorporates:
   *  Inport: '<Root>/steering'
   */
  if (rtU.steering < 0.0) {
    rtb_Integrator_b = -1.0;
  } else if (rtU.steering > 0.0) {
    rtb_Integrator_b = 1.0;
  } else if (rtU.steering == 0.0) {
    rtb_Integrator_b = 0.0;
  } else {
    rtb_Integrator_b = rtU.steering;
  }

  /* End of Signum: '<S9>/Sign' */

  /* Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Product: '<S9>/Divide1'
   */
  rtb_Abs_m_idx_0 = fabs(look1_binlx(rtU.steering, rtConstP.pooled34,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Integrator_b;

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Abs_g = fabs(look1_binlx(-rtU.steering, rtConstP.pooled34,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Integrator_b;

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
    rtb_Integrator_b = rtb_vx * cos(rtb_Abs_m_idx_0) + sin(rtb_Abs_m_idx_0) *
      rtU.vy;
    rtb_Switch = (0.235 * rtU.omega_wheels_FL - rtb_Integrator_b) /
      rtb_Integrator_b;

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
    rtb_Integrator_b = rtb_vx * cos(rtb_Abs_g) + sin(rtb_Abs_g) * rtU.vy;
    rtb_Switch_h = (0.235 * rtU.omega_wheels_FR - rtb_Integrator_b) /
      rtb_Integrator_b;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_vx) / rtb_vx;
    rtb_RL = (0.235 * rtU.omega_wheels_RL - rtb_vx) / rtb_vx;
  } else {
    rtb_Switch = 0.0;
    rtb_Switch_h = 0.0;
    rtb_RR = 0.0;
    rtb_RL = 0.0;
  }

  /* End of Switch: '<S12>/Switch' */

  /* InitialCondition generated from: '<S11>/IC' */
  if (rtDW.IC_1_FirstOutputTime) {
    rtDW.IC_1_FirstOutputTime = false;

    /* InitialCondition generated from: '<S11>/IC' */
    vx = 0.0;
  } else {
    /* InitialCondition generated from: '<S11>/IC' */
    vx = rtb_vx;
  }

  /* InitialCondition generated from: '<S11>/IC' incorporates:
   *  Inport: '<Root>/ax'
   */
  if (rtDW.IC_3_FirstOutputTime) {
    rtDW.IC_3_FirstOutputTime = false;
    rtb_Integrator_b = 0.0;
  } else {
    rtb_Integrator_b = rtU.ax;
  }

  /* InitialCondition generated from: '<S11>/IC' incorporates:
   *  Inport: '<Root>/ay'
   */
  if (rtDW.IC_4_FirstOutputTime) {
    rtDW.IC_4_FirstOutputTime = false;
    rtb_UnaryMinus_pe = 0.0;
  } else {
    rtb_UnaryMinus_pe = rtU.ay;
  }

  /* InitialCondition generated from: '<S11>/IC' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtDW.IC_7_FirstOutputTime) {
    rtDW.IC_7_FirstOutputTime = false;
    rtb_Integrator_h_idx_0 = 0.0;
    rtb_Integrator_h_idx_1 = 0.0;
    rtb_Integrator_h_idx_2 = 0.0;
    rtb_Integrator_h_idx_3 = 0.0;
  } else {
    rtb_Integrator_h_idx_0 = rtU.omega_wheels_FL;
    rtb_Integrator_h_idx_1 = rtU.omega_wheels_FR;
    rtb_Integrator_h_idx_2 = rtU.omega_wheels_RL;
    rtb_Integrator_h_idx_3 = rtU.omega_wheels_RR;
  }

  /* InitialCondition generated from: '<S11>/IC1' */
  if (rtDW.IC1_1_FirstOutputTime) {
    rtDW.IC1_1_FirstOutputTime = false;
    rtb_fl = 0.0;
  } else {
    rtb_fl = rtb_Switch;
  }

  /* InitialCondition generated from: '<S11>/IC1' */
  if (rtDW.IC1_2_FirstOutputTime) {
    rtDW.IC1_2_FirstOutputTime = false;
    rtb_fr = 0.0;
  } else {
    rtb_fr = rtb_Switch_h;
  }

  /* InitialCondition generated from: '<S11>/IC1' */
  if (rtDW.IC1_3_FirstOutputTime) {
    rtDW.IC1_3_FirstOutputTime = false;
    rtb_rl = 0.0;
  } else {
    rtb_rl = rtb_RL;
  }

  /* InitialCondition generated from: '<S11>/IC1' */
  if (rtDW.IC1_4_FirstOutputTime) {
    rtDW.IC1_4_FirstOutputTime = false;
    rtb_rr = 0.0;
  } else {
    rtb_rr = rtb_RR;
  }

  /* InitialCondition generated from: '<S11>/IC2' */
  if (rtDW.IC2_1_FirstOutputTime) {
    rtDW.IC2_1_FirstOutputTime = false;

    /* InitialCondition generated from: '<S11>/IC2' */
    vx_p = 0.0;
  } else {
    /* InitialCondition generated from: '<S11>/IC2' */
    vx_p = rtb_vx;
  }

  /* InitialCondition generated from: '<S11>/IC2' incorporates:
   *  Inport: '<Root>/ax'
   */
  if (rtDW.IC2_3_FirstOutputTime) {
    rtDW.IC2_3_FirstOutputTime = false;
    rtb_Saturation_fy = 0.0;
  } else {
    rtb_Saturation_fy = rtU.ax;
  }

  /* InitialCondition generated from: '<S11>/IC2' incorporates:
   *  Inport: '<Root>/ay'
   */
  if (rtDW.IC2_4_FirstOutputTime) {
    rtDW.IC2_4_FirstOutputTime = false;
    rtb_Switch_g = 0.0;
  } else {
    rtb_Switch_g = rtU.ay;
  }

  /* InitialCondition generated from: '<S11>/IC2' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtDW.IC2_7_FirstOutputTime) {
    rtDW.IC2_7_FirstOutputTime = false;
    rtb_Filter_n_idx_0 = 0.0;
    rtb_Filter_n_idx_1 = 0.0;
    rtb_Filter_n_idx_2 = 0.0;
    rtb_Filter_n_idx_3 = 0.0;
  } else {
    rtb_Filter_n_idx_0 = rtU.omega_wheels_FL;
    rtb_Filter_n_idx_1 = rtU.omega_wheels_FR;
    rtb_Filter_n_idx_2 = rtU.omega_wheels_RL;
    rtb_Filter_n_idx_3 = rtU.omega_wheels_RR;
  }

  /* InitialCondition generated from: '<S11>/IC3' */
  if (rtDW.IC3_1_FirstOutputTime) {
    rtDW.IC3_1_FirstOutputTime = false;
    rtb_fl_c = 0.0;
  } else {
    rtb_fl_c = rtb_Switch;
  }

  /* InitialCondition generated from: '<S11>/IC3' */
  if (rtDW.IC3_2_FirstOutputTime) {
    rtDW.IC3_2_FirstOutputTime = false;
    rtb_fr_a = 0.0;
  } else {
    rtb_fr_a = rtb_Switch_h;
  }

  /* InitialCondition generated from: '<S11>/IC3' */
  if (rtDW.IC3_3_FirstOutputTime) {
    rtDW.IC3_3_FirstOutputTime = false;
    rtb_rl_d = 0.0;
  } else {
    rtb_rl_d = rtb_RL;
  }

  /* InitialCondition generated from: '<S11>/IC3' */
  if (rtDW.IC3_4_FirstOutputTime) {
    rtDW.IC3_4_FirstOutputTime = false;
    rtb_rr_l = 0.0;
  } else {
    rtb_rr_l = rtb_RR;
  }

  /* SampleTimeMath: '<S18>/TSamp'
   *
   * About '<S18>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Integrator_g = rtb_Integrator_h_idx_0 * 50.0;

  /* Sum: '<S18>/Diff' incorporates:
   *  UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Diff[0] = rtb_Integrator_g - rtDW.UD_DSTATE[0];

  /* SampleTimeMath: '<S18>/TSamp'
   *
   * About '<S18>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Integrator_h_idx_0 = rtb_Integrator_g;
  rtb_Integrator_g = rtb_Integrator_h_idx_1 * 50.0;

  /* Sum: '<S18>/Diff' incorporates:
   *  UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Diff[1] = rtb_Integrator_g - rtDW.UD_DSTATE[1];

  /* SampleTimeMath: '<S18>/TSamp'
   *
   * About '<S18>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Integrator_h_idx_1 = rtb_Integrator_g;
  rtb_Integrator_g = rtb_Integrator_h_idx_2 * 50.0;

  /* Sum: '<S18>/Diff' incorporates:
   *  UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Diff[2] = rtb_Integrator_g - rtDW.UD_DSTATE[2];

  /* SampleTimeMath: '<S18>/TSamp'
   *
   * About '<S18>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Integrator_h_idx_2 = rtb_Integrator_g;
  rtb_Integrator_g = rtb_Integrator_h_idx_3 * 50.0;

  /* Sum: '<S18>/Diff' incorporates:
   *  UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Diff[3] = rtb_Integrator_g - rtDW.UD_DSTATE[3];

  /* DiscreteIntegrator: '<S60>/Integrator' */
  if (rtDW.Integrator_PrevResetState != 0) {
    rtDW.Integrator_DSTATE[0] = 0.0;
    rtDW.Integrator_DSTATE[1] = 0.0;
    rtDW.Integrator_DSTATE[2] = 0.0;
    rtDW.Integrator_DSTATE[3] = 0.0;
  }

  /* DiscreteIntegrator: '<S55>/Filter' */
  if (rtDW.Filter_PrevResetState != 0) {
    rtDW.Filter_DSTATE[0] = 0.0;
    rtDW.Filter_DSTATE[1] = 0.0;
    rtDW.Filter_DSTATE[2] = 0.0;
    rtDW.Filter_DSTATE[3] = 0.0;
  }

  /* Gain: '<S63>/Filter Coefficient' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DiscreteIntegrator: '<S55>/Filter'
   *  Gain: '<S54>/Derivative Gain'
   *  Sum: '<S16>/Subtract'
   *  Sum: '<S55>/SumD'
   */
  rtb_Integrator_h_idx_3 = ((0.1 - rtb_fl) * 0.0 - rtDW.Filter_DSTATE[0]) *
    100.0;

  /* Sum: '<S69>/Sum' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DiscreteIntegrator: '<S60>/Integrator'
   *  Gain: '<S65>/Proportional Gain'
   *  Sum: '<S16>/Subtract'
   */
  rtb_IntegralGain = ((0.1 - rtb_fl) * 16.666666666666668 +
                      rtDW.Integrator_DSTATE[0]) + rtb_Integrator_h_idx_3;

  /* Saturate: '<S67>/Saturation' */
  if (rtb_IntegralGain > 20.0) {
    rtb_Saturation[0] = 20.0;
  } else if (rtb_IntegralGain < -20.0) {
    rtb_Saturation[0] = -20.0;
  } else {
    rtb_Saturation[0] = rtb_IntegralGain;
  }

  /* Gain: '<S63>/Filter Coefficient' */
  rtb_FilterCoefficient_idx_0 = rtb_Integrator_h_idx_3;

  /* Sum: '<S69>/Sum' */
  rtb_IntegralGain_idx_0 = rtb_IntegralGain;

  /* Gain: '<S63>/Filter Coefficient' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DiscreteIntegrator: '<S55>/Filter'
   *  Gain: '<S54>/Derivative Gain'
   *  Sum: '<S16>/Subtract'
   *  Sum: '<S55>/SumD'
   */
  rtb_Integrator_h_idx_3 = ((0.1 - rtb_fr) * 0.0 - rtDW.Filter_DSTATE[1]) *
    100.0;

  /* Sum: '<S69>/Sum' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DiscreteIntegrator: '<S60>/Integrator'
   *  Gain: '<S65>/Proportional Gain'
   *  Sum: '<S16>/Subtract'
   */
  rtb_IntegralGain = ((0.1 - rtb_fr) * 16.666666666666668 +
                      rtDW.Integrator_DSTATE[1]) + rtb_Integrator_h_idx_3;

  /* Saturate: '<S67>/Saturation' */
  if (rtb_IntegralGain > 20.0) {
    rtb_Saturation[1] = 20.0;
  } else if (rtb_IntegralGain < -20.0) {
    rtb_Saturation[1] = -20.0;
  } else {
    rtb_Saturation[1] = rtb_IntegralGain;
  }

  /* Gain: '<S63>/Filter Coefficient' */
  rtb_FilterCoefficient_idx_1 = rtb_Integrator_h_idx_3;

  /* Sum: '<S69>/Sum' */
  rtb_IntegralGain_idx_1 = rtb_IntegralGain;

  /* Gain: '<S63>/Filter Coefficient' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DiscreteIntegrator: '<S55>/Filter'
   *  Gain: '<S54>/Derivative Gain'
   *  Sum: '<S16>/Subtract'
   *  Sum: '<S55>/SumD'
   */
  rtb_Integrator_h_idx_3 = ((0.1 - rtb_rl) * 0.0 - rtDW.Filter_DSTATE[2]) *
    100.0;

  /* Sum: '<S69>/Sum' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DiscreteIntegrator: '<S60>/Integrator'
   *  Gain: '<S65>/Proportional Gain'
   *  Sum: '<S16>/Subtract'
   */
  rtb_IntegralGain = ((0.1 - rtb_rl) * 16.666666666666668 +
                      rtDW.Integrator_DSTATE[2]) + rtb_Integrator_h_idx_3;

  /* Saturate: '<S67>/Saturation' */
  if (rtb_IntegralGain > 20.0) {
    rtb_Saturation[2] = 20.0;
  } else if (rtb_IntegralGain < -20.0) {
    rtb_Saturation[2] = -20.0;
  } else {
    rtb_Saturation[2] = rtb_IntegralGain;
  }

  /* Gain: '<S63>/Filter Coefficient' */
  rtb_FilterCoefficient_idx_2 = rtb_Integrator_h_idx_3;

  /* Sum: '<S69>/Sum' */
  rtb_IntegralGain_idx_2 = rtb_IntegralGain;

  /* Gain: '<S63>/Filter Coefficient' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DiscreteIntegrator: '<S55>/Filter'
   *  Gain: '<S54>/Derivative Gain'
   *  Sum: '<S16>/Subtract'
   *  Sum: '<S55>/SumD'
   */
  rtb_Integrator_h_idx_3 = ((0.1 - rtb_rr) * 0.0 - rtDW.Filter_DSTATE[3]) *
    100.0;

  /* Sum: '<S69>/Sum' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DiscreteIntegrator: '<S60>/Integrator'
   *  Gain: '<S65>/Proportional Gain'
   *  Sum: '<S16>/Subtract'
   */
  rtb_IntegralGain = ((0.1 - rtb_rr) * 16.666666666666668 +
                      rtDW.Integrator_DSTATE[3]) + rtb_Integrator_h_idx_3;

  /* Saturate: '<S67>/Saturation' */
  if (rtb_IntegralGain > 20.0) {
    rtb_Saturation[3] = 20.0;
  } else if (rtb_IntegralGain < -20.0) {
    rtb_Saturation[3] = -20.0;
  } else {
    rtb_Saturation[3] = rtb_IntegralGain;
  }

  /* MATLAB Function: '<S16>/MATLAB Function1' incorporates:
   *  Constant: '<S23>/Static Load Front'
   *  Constant: '<S24>/Static Load Front'
   *  Constant: '<S25>/Static Load Front'
   *  Constant: '<S26>/Static Load Front'
   *  Gain: '<S23>/Drag moment'
   *  Gain: '<S23>/Lateral Load Transfer'
   *  Gain: '<S23>/Lift Force'
   *  Gain: '<S23>/Longitudinal Load Transfer'
   *  Gain: '<S24>/Drag moment'
   *  Gain: '<S24>/Lateral Load Transfer'
   *  Gain: '<S24>/Lift Force'
   *  Gain: '<S24>/Longitudinal Load Transfer'
   *  Gain: '<S25>/Drag moment'
   *  Gain: '<S25>/Lateral Load Transfer'
   *  Gain: '<S25>/Lift Force'
   *  Gain: '<S25>/Longitudinal Load Transfer'
   *  Gain: '<S26>/Drag moment'
   *  Gain: '<S26>/Lateral Load Transfer'
   *  Gain: '<S26>/Lift Force'
   *  Gain: '<S26>/Longitudinal Load Transfer'
   *  Math: '<S23>/Square1'
   *  Math: '<S23>/Square2'
   *  Math: '<S24>/Square1'
   *  Math: '<S24>/Square2'
   *  Math: '<S25>/Square1'
   *  Math: '<S25>/Square2'
   *  Math: '<S26>/Square1'
   *  Math: '<S26>/Square2'
   *  Sum: '<S23>/Subtract'
   *  Sum: '<S24>/Subtract'
   *  Sum: '<S25>/Subtract'
   *  Sum: '<S26>/Subtract'
   *  UnaryMinus: '<S23>/Unary Minus'
   *  UnaryMinus: '<S23>/Unary Minus1'
   *  UnaryMinus: '<S24>/Unary Minus'
   *  UnaryMinus: '<S24>/Unary Minus1'
   *  UnaryMinus: '<S25>/Unary Minus'
   *  UnaryMinus: '<S25>/Unary Minus1'
   *  UnaryMinus: '<S26>/Unary Minus'
   *  UnaryMinus: '<S26>/Unary Minus1'
   */
  MATLABFunction1(vx, rtb_fl, rtb_fr, rtb_rl, rtb_rr, (((30.826771653543307 *
    -rtb_UnaryMinus_pe + 635.688) + 0.92446666666666677 * (vx * vx)) -
    0.21998117647058821 * (vx * vx)) + 25.588235294117645 * -rtb_Integrator_b,
                  (((635.688 - 30.826771653543307 * -rtb_UnaryMinus_pe) +
                    0.92446666666666677 * (vx * vx)) - 0.21998117647058821 * (vx
    * vx)) + 25.588235294117645 * -rtb_Integrator_b, (((30.826771653543307 *
    -rtb_UnaryMinus_pe + 688.66200000000015) + 0.74153333333333349 * (vx * vx))
    + 0.21998117647058821 * (vx * vx)) - 25.588235294117645 * -rtb_Integrator_b,
                  (((688.66200000000015 - 30.826771653543307 *
                     -rtb_UnaryMinus_pe) + 0.74153333333333349 * (vx * vx)) +
                   0.21998117647058821 * (vx * vx)) - 25.588235294117645 *
                  -rtb_Integrator_b, rtb_Saturation, rtb_Diff, rtb_Driving,
                  rtb_T_ff_deceleration_n, rtb_T_ff_slip_g);

  /* DeadZone: '<S53>/DeadZone' incorporates:
   *  Gain: '<S51>/ZeroGain'
   */
  if (rtb_IntegralGain_idx_0 > 20.0) {
    rtb_IntegralGain_n = rtb_IntegralGain_idx_0 - 20.0;
  } else if (rtb_IntegralGain_idx_0 >= -20.0) {
    rtb_IntegralGain_n = 0.0;
  } else {
    rtb_IntegralGain_n = rtb_IntegralGain_idx_0 - -20.0;
  }

  /* Gain: '<S57>/Integral Gain' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Sum: '<S16>/Subtract'
   */
  rtb_Integrator_d = (0.1 - rtb_fl) * 100.0;

  /* Signum: '<S51>/SignPreSat' */
  if (rtb_IntegralGain_n < 0.0) {
    rtb_IntegralGain_1 = -1.0;
  } else if (rtb_IntegralGain_n > 0.0) {
    rtb_IntegralGain_1 = 1.0;
  } else if (rtb_IntegralGain_n == 0.0) {
    rtb_IntegralGain_1 = 0.0;
  } else {
    rtb_IntegralGain_1 = (rtNaN);
  }

  /* Signum: '<S51>/SignPreIntegrator' */
  if (rtb_Integrator_d < 0.0) {
    rtb_Integrator_k = -1.0;
  } else if (rtb_Integrator_d > 0.0) {
    rtb_Integrator_k = 1.0;
  } else if (rtb_Integrator_d == 0.0) {
    rtb_Integrator_k = 0.0;
  } else {
    rtb_Integrator_k = (rtNaN);
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant1'
   *  DataTypeConversion: '<S51>/DataTypeConv1'
   *  DataTypeConversion: '<S51>/DataTypeConv2'
   *  Gain: '<S51>/ZeroGain'
   *  Logic: '<S51>/AND3'
   *  RelationalOperator: '<S51>/Equal1'
   *  RelationalOperator: '<S51>/NotEqual'
   */
  if ((0.0 * rtb_IntegralGain_idx_0 != rtb_IntegralGain_n) && ((int8_T)
       rtb_IntegralGain_1 == (int8_T)rtb_Integrator_k)) {
    rtb_Diff_i = 0.0;
  } else {
    rtb_Diff_i = rtb_Integrator_d;
  }

  /* DeadZone: '<S53>/DeadZone' incorporates:
   *  Gain: '<S51>/ZeroGain'
   */
  if (rtb_IntegralGain_idx_1 > 20.0) {
    rtb_IntegralGain_n = rtb_IntegralGain_idx_1 - 20.0;
  } else if (rtb_IntegralGain_idx_1 >= -20.0) {
    rtb_IntegralGain_n = 0.0;
  } else {
    rtb_IntegralGain_n = rtb_IntegralGain_idx_1 - -20.0;
  }

  /* Gain: '<S57>/Integral Gain' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Sum: '<S16>/Subtract'
   */
  rtb_Integrator_d = (0.1 - rtb_fr) * 100.0;

  /* Signum: '<S51>/SignPreSat' */
  if (rtb_IntegralGain_n < 0.0) {
    rtb_IntegralGain_1 = -1.0;
  } else if (rtb_IntegralGain_n > 0.0) {
    rtb_IntegralGain_1 = 1.0;
  } else if (rtb_IntegralGain_n == 0.0) {
    rtb_IntegralGain_1 = 0.0;
  } else {
    rtb_IntegralGain_1 = (rtNaN);
  }

  /* Signum: '<S51>/SignPreIntegrator' */
  if (rtb_Integrator_d < 0.0) {
    rtb_Integrator_k = -1.0;
  } else if (rtb_Integrator_d > 0.0) {
    rtb_Integrator_k = 1.0;
  } else if (rtb_Integrator_d == 0.0) {
    rtb_Integrator_k = 0.0;
  } else {
    rtb_Integrator_k = (rtNaN);
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant1'
   *  DataTypeConversion: '<S51>/DataTypeConv1'
   *  DataTypeConversion: '<S51>/DataTypeConv2'
   *  Gain: '<S51>/ZeroGain'
   *  Logic: '<S51>/AND3'
   *  RelationalOperator: '<S51>/Equal1'
   *  RelationalOperator: '<S51>/NotEqual'
   */
  if ((0.0 * rtb_IntegralGain_idx_1 != rtb_IntegralGain_n) && ((int8_T)
       rtb_IntegralGain_1 == (int8_T)rtb_Integrator_k)) {
    rtb_Diff_m = 0.0;
  } else {
    rtb_Diff_m = rtb_Integrator_d;
  }

  /* DeadZone: '<S53>/DeadZone' incorporates:
   *  Gain: '<S51>/ZeroGain'
   */
  if (rtb_IntegralGain_idx_2 > 20.0) {
    rtb_IntegralGain_n = rtb_IntegralGain_idx_2 - 20.0;
  } else if (rtb_IntegralGain_idx_2 >= -20.0) {
    rtb_IntegralGain_n = 0.0;
  } else {
    rtb_IntegralGain_n = rtb_IntegralGain_idx_2 - -20.0;
  }

  /* Gain: '<S57>/Integral Gain' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Sum: '<S16>/Subtract'
   */
  rtb_Integrator_d = (0.1 - rtb_rl) * 100.0;

  /* Signum: '<S51>/SignPreSat' */
  if (rtb_IntegralGain_n < 0.0) {
    rtb_IntegralGain_1 = -1.0;
  } else if (rtb_IntegralGain_n > 0.0) {
    rtb_IntegralGain_1 = 1.0;
  } else if (rtb_IntegralGain_n == 0.0) {
    rtb_IntegralGain_1 = 0.0;
  } else {
    rtb_IntegralGain_1 = (rtNaN);
  }

  /* Signum: '<S51>/SignPreIntegrator' */
  if (rtb_Integrator_d < 0.0) {
    rtb_Integrator_k = -1.0;
  } else if (rtb_Integrator_d > 0.0) {
    rtb_Integrator_k = 1.0;
  } else if (rtb_Integrator_d == 0.0) {
    rtb_Integrator_k = 0.0;
  } else {
    rtb_Integrator_k = (rtNaN);
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant1'
   *  DataTypeConversion: '<S51>/DataTypeConv1'
   *  DataTypeConversion: '<S51>/DataTypeConv2'
   *  Gain: '<S51>/ZeroGain'
   *  Logic: '<S51>/AND3'
   *  RelationalOperator: '<S51>/Equal1'
   *  RelationalOperator: '<S51>/NotEqual'
   */
  if ((0.0 * rtb_IntegralGain_idx_2 != rtb_IntegralGain_n) && ((int8_T)
       rtb_IntegralGain_1 == (int8_T)rtb_Integrator_k)) {
    rtb_Diff_p = 0.0;
  } else {
    rtb_Diff_p = rtb_Integrator_d;
  }

  /* DeadZone: '<S53>/DeadZone' */
  if (rtb_IntegralGain > 20.0) {
    rtb_IntegralGain_n = rtb_IntegralGain - 20.0;
  } else if (rtb_IntegralGain >= -20.0) {
    rtb_IntegralGain_n = 0.0;
  } else {
    rtb_IntegralGain_n = rtb_IntegralGain - -20.0;
  }

  /* Gain: '<S57>/Integral Gain' incorporates:
   *  Constant: '<S16>/Constant3'
   *  Sum: '<S16>/Subtract'
   */
  rtb_Integrator_d = (0.1 - rtb_rr) * 100.0;

  /* Chart: '<S22>/Chart' incorporates:
   *  Abs: '<S16>/Abs'
   *  Constant: '<S16>/Constant1'
   *  Logic: '<S16>/NOT'
   *  RelationalOperator: '<S16>/Less Than'
   */
  Chart(rtb_Driving[0], !(fabs(rtb_fl) < 0.01), &rtDW.TC_max_m, &rtDW.sf_Chart);

  /* Chart: '<S22>/Chart1' incorporates:
   *  Abs: '<S16>/Abs'
   *  Constant: '<S16>/Constant1'
   *  Logic: '<S16>/NOT'
   *  RelationalOperator: '<S16>/Less Than'
   */
  Chart(rtb_Driving[1], !(fabs(rtb_fr) < 0.01), &rtDW.TC_max_fo, &rtDW.sf_Chart1);

  /* Chart: '<S22>/Chart2' incorporates:
   *  Abs: '<S16>/Abs'
   *  Constant: '<S16>/Constant1'
   *  Logic: '<S16>/NOT'
   *  RelationalOperator: '<S16>/Less Than'
   */
  Chart(rtb_Driving[2], !(fabs(rtb_rl) < 0.01), &rtDW.TC_max_f, &rtDW.sf_Chart2);

  /* Chart: '<S22>/Chart3' incorporates:
   *  Abs: '<S16>/Abs'
   *  Constant: '<S16>/Constant1'
   *  Logic: '<S16>/NOT'
   *  RelationalOperator: '<S16>/Less Than'
   */
  Chart(rtb_Driving[3], !(fabs(rtb_rr) < 0.01), &rtDW.TC_max_e, &rtDW.sf_Chart3);

  /* RelationalOperator: '<S17>/Less Than' incorporates:
   *  Abs: '<S17>/Abs'
   *  Constant: '<S17>/Constant1'
   */
  rtb_NOT_idx_0 = (fabs(rtb_fl_c) < 0.01);
  rtb_NOT_idx_1 = (fabs(rtb_fr_a) < 0.01);
  rtb_NOT_idx_2 = (fabs(rtb_rl_d) < 0.01);
  rtb_NOT_idx_3 = (fabs(rtb_rr_l) < 0.01);

  /* SampleTimeMath: '<S81>/TSamp'
   *
   * About '<S81>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_fl = rtb_Filter_n_idx_0 * 50.0;

  /* Sum: '<S81>/Diff' incorporates:
   *  UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtb_T_ff_deceleration_n[0] = rtb_fl - rtDW.UD_DSTATE_e[0];

  /* DiscreteIntegrator: '<S123>/Integrator' */
  if (rtb_NOT_idx_0 || (rtDW.Integrator_PrevResetState_f[0] != 0)) {
    rtDW.Integrator_DSTATE_b[0] = 0.0;
  }

  /* DiscreteIntegrator: '<S118>/Filter' incorporates:
   *  DiscreteIntegrator: '<S123>/Integrator'
   */
  if (rtb_NOT_idx_0 || (rtDW.Filter_PrevResetState_g[0] != 0)) {
    rtDW.Filter_DSTATE_f[0] = 0.0;
  }

  /* Gain: '<S126>/Filter Coefficient' incorporates:
   *  Constant: '<S17>/Constant3'
   *  DiscreteIntegrator: '<S118>/Filter'
   *  Gain: '<S117>/Derivative Gain'
   *  Sum: '<S118>/SumD'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Integrator_k = ((-0.1 - rtb_fl_c) * 0.0 - rtDW.Filter_DSTATE_f[0]) * 100.0;

  /* Sum: '<S132>/Sum' incorporates:
   *  Constant: '<S17>/Constant3'
   *  DiscreteIntegrator: '<S123>/Integrator'
   *  Gain: '<S128>/Proportional Gain'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Saturation[0] = ((-0.1 - rtb_fl_c) * 16.666666666666668 +
                       rtDW.Integrator_DSTATE_b[0]) + rtb_Integrator_k;

  /* SampleTimeMath: '<S81>/TSamp'
   *
   * About '<S81>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Filter_n_idx_0 = rtb_fl;

  /* Gain: '<S126>/Filter Coefficient' */
  rtb_fr = rtb_Integrator_k;

  /* SampleTimeMath: '<S81>/TSamp'
   *
   * About '<S81>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_fl = rtb_Filter_n_idx_1 * 50.0;

  /* Sum: '<S81>/Diff' incorporates:
   *  UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtb_T_ff_deceleration_n[1] = rtb_fl - rtDW.UD_DSTATE_e[1];

  /* DiscreteIntegrator: '<S123>/Integrator' */
  if (rtb_NOT_idx_1 || (rtDW.Integrator_PrevResetState_f[1] != 0)) {
    rtDW.Integrator_DSTATE_b[1] = 0.0;
  }

  /* DiscreteIntegrator: '<S118>/Filter' incorporates:
   *  DiscreteIntegrator: '<S123>/Integrator'
   */
  if (rtb_NOT_idx_1 || (rtDW.Filter_PrevResetState_g[1] != 0)) {
    rtDW.Filter_DSTATE_f[1] = 0.0;
  }

  /* Gain: '<S126>/Filter Coefficient' incorporates:
   *  Constant: '<S17>/Constant3'
   *  DiscreteIntegrator: '<S118>/Filter'
   *  Gain: '<S117>/Derivative Gain'
   *  Sum: '<S118>/SumD'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Integrator_k = ((-0.1 - rtb_fr_a) * 0.0 - rtDW.Filter_DSTATE_f[1]) * 100.0;

  /* Sum: '<S132>/Sum' incorporates:
   *  Constant: '<S17>/Constant3'
   *  DiscreteIntegrator: '<S123>/Integrator'
   *  Gain: '<S128>/Proportional Gain'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Saturation[1] = ((-0.1 - rtb_fr_a) * 16.666666666666668 +
                       rtDW.Integrator_DSTATE_b[1]) + rtb_Integrator_k;

  /* SampleTimeMath: '<S81>/TSamp'
   *
   * About '<S81>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Filter_n_idx_1 = rtb_fl;

  /* Gain: '<S126>/Filter Coefficient' */
  rtb_rl = rtb_Integrator_k;

  /* SampleTimeMath: '<S81>/TSamp'
   *
   * About '<S81>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_fl = rtb_Filter_n_idx_2 * 50.0;

  /* Sum: '<S81>/Diff' incorporates:
   *  UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtb_T_ff_deceleration_n[2] = rtb_fl - rtDW.UD_DSTATE_e[2];

  /* DiscreteIntegrator: '<S123>/Integrator' */
  if (rtb_NOT_idx_2 || (rtDW.Integrator_PrevResetState_f[2] != 0)) {
    rtDW.Integrator_DSTATE_b[2] = 0.0;
  }

  /* DiscreteIntegrator: '<S118>/Filter' incorporates:
   *  DiscreteIntegrator: '<S123>/Integrator'
   */
  if (rtb_NOT_idx_2 || (rtDW.Filter_PrevResetState_g[2] != 0)) {
    rtDW.Filter_DSTATE_f[2] = 0.0;
  }

  /* Gain: '<S126>/Filter Coefficient' incorporates:
   *  Constant: '<S17>/Constant3'
   *  DiscreteIntegrator: '<S118>/Filter'
   *  Gain: '<S117>/Derivative Gain'
   *  Sum: '<S118>/SumD'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Integrator_k = ((-0.1 - rtb_rl_d) * 0.0 - rtDW.Filter_DSTATE_f[2]) * 100.0;

  /* Sum: '<S132>/Sum' incorporates:
   *  Constant: '<S17>/Constant3'
   *  DiscreteIntegrator: '<S123>/Integrator'
   *  Gain: '<S128>/Proportional Gain'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Saturation[2] = ((-0.1 - rtb_rl_d) * 16.666666666666668 +
                       rtDW.Integrator_DSTATE_b[2]) + rtb_Integrator_k;

  /* SampleTimeMath: '<S81>/TSamp'
   *
   * About '<S81>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Filter_n_idx_2 = rtb_fl;

  /* Gain: '<S126>/Filter Coefficient' */
  rtb_Integrator_k_idx_2 = rtb_Integrator_k;

  /* SampleTimeMath: '<S81>/TSamp'
   *
   * About '<S81>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_fl = rtb_Filter_n_idx_3 * 50.0;

  /* Sum: '<S81>/Diff' incorporates:
   *  UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtb_T_ff_deceleration_n[3] = rtb_fl - rtDW.UD_DSTATE_e[3];

  /* DiscreteIntegrator: '<S123>/Integrator' */
  if (rtb_NOT_idx_3 || (rtDW.Integrator_PrevResetState_f[3] != 0)) {
    rtDW.Integrator_DSTATE_b[3] = 0.0;
  }

  /* DiscreteIntegrator: '<S118>/Filter' incorporates:
   *  DiscreteIntegrator: '<S123>/Integrator'
   */
  if (rtb_NOT_idx_3 || (rtDW.Filter_PrevResetState_g[3] != 0)) {
    rtDW.Filter_DSTATE_f[3] = 0.0;
  }

  /* Gain: '<S126>/Filter Coefficient' incorporates:
   *  Constant: '<S17>/Constant3'
   *  DiscreteIntegrator: '<S118>/Filter'
   *  Gain: '<S117>/Derivative Gain'
   *  Sum: '<S118>/SumD'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Integrator_k = ((-0.1 - rtb_rr_l) * 0.0 - rtDW.Filter_DSTATE_f[3]) * 100.0;

  /* Sum: '<S132>/Sum' incorporates:
   *  Constant: '<S17>/Constant3'
   *  DiscreteIntegrator: '<S123>/Integrator'
   *  Gain: '<S128>/Proportional Gain'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Saturation[3] = ((-0.1 - rtb_rr_l) * 16.666666666666668 +
                       rtDW.Integrator_DSTATE_b[3]) + rtb_Integrator_k;

  /* Saturate: '<S130>/Saturation' */
  if (rtb_Saturation[0] > -5.0) {
    rtb_T_ff_slip_g[0] = -5.0;
  } else if (rtb_Saturation[0] < -20.0) {
    rtb_T_ff_slip_g[0] = -20.0;
  } else {
    rtb_T_ff_slip_g[0] = rtb_Saturation[0];
  }

  if (rtb_Saturation[1] > -5.0) {
    rtb_T_ff_slip_g[1] = -5.0;
  } else if (rtb_Saturation[1] < -20.0) {
    rtb_T_ff_slip_g[1] = -20.0;
  } else {
    rtb_T_ff_slip_g[1] = rtb_Saturation[1];
  }

  if (rtb_Saturation[2] > -5.0) {
    rtb_T_ff_slip_g[2] = -5.0;
  } else if (rtb_Saturation[2] < -20.0) {
    rtb_T_ff_slip_g[2] = -20.0;
  } else {
    rtb_T_ff_slip_g[2] = rtb_Saturation[2];
  }

  if (rtb_Saturation[3] > -5.0) {
    rtb_T_ff_slip_g[3] = -5.0;
  } else if (rtb_Saturation[3] < -20.0) {
    rtb_T_ff_slip_g[3] = -20.0;
  } else {
    rtb_T_ff_slip_g[3] = rtb_Saturation[3];
  }

  /* End of Saturate: '<S130>/Saturation' */

  /* MATLAB Function: '<S17>/MATLAB Function1' incorporates:
   *  Constant: '<S86>/Static Load Front'
   *  Constant: '<S87>/Static Load Front'
   *  Constant: '<S88>/Static Load Front'
   *  Constant: '<S89>/Static Load Front'
   *  Gain: '<S86>/Drag moment'
   *  Gain: '<S86>/Lateral Load Transfer'
   *  Gain: '<S86>/Lift Force'
   *  Gain: '<S86>/Longitudinal Load Transfer'
   *  Gain: '<S87>/Drag moment'
   *  Gain: '<S87>/Lateral Load Transfer'
   *  Gain: '<S87>/Lift Force'
   *  Gain: '<S87>/Longitudinal Load Transfer'
   *  Gain: '<S88>/Drag moment'
   *  Gain: '<S88>/Lateral Load Transfer'
   *  Gain: '<S88>/Lift Force'
   *  Gain: '<S88>/Longitudinal Load Transfer'
   *  Gain: '<S89>/Drag moment'
   *  Gain: '<S89>/Lateral Load Transfer'
   *  Gain: '<S89>/Lift Force'
   *  Gain: '<S89>/Longitudinal Load Transfer'
   *  Math: '<S86>/Square1'
   *  Math: '<S86>/Square2'
   *  Math: '<S87>/Square1'
   *  Math: '<S87>/Square2'
   *  Math: '<S88>/Square1'
   *  Math: '<S88>/Square2'
   *  Math: '<S89>/Square1'
   *  Math: '<S89>/Square2'
   *  Sum: '<S86>/Subtract'
   *  Sum: '<S87>/Subtract'
   *  Sum: '<S88>/Subtract'
   *  Sum: '<S89>/Subtract'
   *  UnaryMinus: '<S86>/Unary Minus'
   *  UnaryMinus: '<S86>/Unary Minus1'
   *  UnaryMinus: '<S87>/Unary Minus'
   *  UnaryMinus: '<S87>/Unary Minus1'
   *  UnaryMinus: '<S88>/Unary Minus'
   *  UnaryMinus: '<S88>/Unary Minus1'
   *  UnaryMinus: '<S89>/Unary Minus'
   *  UnaryMinus: '<S89>/Unary Minus1'
   */
  MATLABFunction1(vx_p, rtb_fl_c, rtb_fr_a, rtb_rl_d, rtb_rr_l,
                  (((30.826771653543307 * -rtb_Switch_g + 635.688) +
                    0.92446666666666677 * (vx_p * vx_p)) - 0.21998117647058821 *
                   (vx_p * vx_p)) + 25.588235294117645 * -rtb_Saturation_fy,
                  (((635.688 - 30.826771653543307 * -rtb_Switch_g) +
                    0.92446666666666677 * (vx_p * vx_p)) - 0.21998117647058821 *
                   (vx_p * vx_p)) + 25.588235294117645 * -rtb_Saturation_fy,
                  (((30.826771653543307 * -rtb_Switch_g + 688.66200000000015) +
                    0.74153333333333349 * (vx_p * vx_p)) + 0.21998117647058821 *
                   (vx_p * vx_p)) - 25.588235294117645 * -rtb_Saturation_fy,
                  (((688.66200000000015 - 30.826771653543307 * -rtb_Switch_g) +
                    0.74153333333333349 * (vx_p * vx_p)) + 0.21998117647058821 *
                   (vx_p * vx_p)) - 25.588235294117645 * -rtb_Saturation_fy,
                  rtb_T_ff_slip_g, rtb_T_ff_deceleration_n, rtb_Driving,
                  rtb_T_ff_deceleration, rtb_Diff);

  /* DeadZone: '<S116>/DeadZone' incorporates:
   *  Gain: '<S114>/ZeroGain'
   */
  if (rtb_Saturation[0] > -5.0) {
    rtb_Filter_n_idx_3 = rtb_Saturation[0] - -5.0;
  } else if (rtb_Saturation[0] >= -20.0) {
    rtb_Filter_n_idx_3 = 0.0;
  } else {
    rtb_Filter_n_idx_3 = rtb_Saturation[0] - -20.0;
  }

  /* Gain: '<S120>/Integral Gain' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Sum: '<S17>/Subtract'
   */
  rtb_IntegralGain_1 = (-0.1 - rtb_fl_c) * 100.0;

  /* Signum: '<S114>/SignPreSat' */
  if (rtb_Filter_n_idx_3 < 0.0) {
    rtb_IntegralGain_idx_1 = -1.0;
  } else if (rtb_Filter_n_idx_3 > 0.0) {
    rtb_IntegralGain_idx_1 = 1.0;
  } else if (rtb_Filter_n_idx_3 == 0.0) {
    rtb_IntegralGain_idx_1 = 0.0;
  } else {
    rtb_IntegralGain_idx_1 = (rtNaN);
  }

  /* Signum: '<S114>/SignPreIntegrator' */
  if (rtb_IntegralGain_1 < 0.0) {
    rtb_IntegralGain_idx_0 = -1.0;
  } else if (rtb_IntegralGain_1 > 0.0) {
    rtb_IntegralGain_idx_0 = 1.0;
  } else if (rtb_IntegralGain_1 == 0.0) {
    rtb_IntegralGain_idx_0 = 0.0;
  } else {
    rtb_IntegralGain_idx_0 = (rtNaN);
  }

  /* Switch: '<S114>/Switch' incorporates:
   *  Constant: '<S114>/Constant1'
   *  DataTypeConversion: '<S114>/DataTypeConv1'
   *  DataTypeConversion: '<S114>/DataTypeConv2'
   *  Gain: '<S114>/ZeroGain'
   *  Logic: '<S114>/AND3'
   *  RelationalOperator: '<S114>/Equal1'
   *  RelationalOperator: '<S114>/NotEqual'
   */
  if ((0.0 * rtb_Saturation[0] != rtb_Filter_n_idx_3) && ((int8_T)
       rtb_IntegralGain_idx_1 == (int8_T)rtb_IntegralGain_idx_0)) {
    rtb_T_ff_deceleration_bl = 0.0;
  } else {
    rtb_T_ff_deceleration_bl = rtb_IntegralGain_1;
  }

  /* DeadZone: '<S116>/DeadZone' incorporates:
   *  Gain: '<S114>/ZeroGain'
   */
  if (rtb_Saturation[1] > -5.0) {
    rtb_Filter_n_idx_3 = rtb_Saturation[1] - -5.0;
  } else if (rtb_Saturation[1] >= -20.0) {
    rtb_Filter_n_idx_3 = 0.0;
  } else {
    rtb_Filter_n_idx_3 = rtb_Saturation[1] - -20.0;
  }

  /* Gain: '<S120>/Integral Gain' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Sum: '<S17>/Subtract'
   */
  rtb_IntegralGain_1 = (-0.1 - rtb_fr_a) * 100.0;

  /* Signum: '<S114>/SignPreSat' */
  if (rtb_Filter_n_idx_3 < 0.0) {
    rtb_IntegralGain_idx_1 = -1.0;
  } else if (rtb_Filter_n_idx_3 > 0.0) {
    rtb_IntegralGain_idx_1 = 1.0;
  } else if (rtb_Filter_n_idx_3 == 0.0) {
    rtb_IntegralGain_idx_1 = 0.0;
  } else {
    rtb_IntegralGain_idx_1 = (rtNaN);
  }

  /* Signum: '<S114>/SignPreIntegrator' */
  if (rtb_IntegralGain_1 < 0.0) {
    rtb_IntegralGain_idx_0 = -1.0;
  } else if (rtb_IntegralGain_1 > 0.0) {
    rtb_IntegralGain_idx_0 = 1.0;
  } else if (rtb_IntegralGain_1 == 0.0) {
    rtb_IntegralGain_idx_0 = 0.0;
  } else {
    rtb_IntegralGain_idx_0 = (rtNaN);
  }

  /* Switch: '<S114>/Switch' incorporates:
   *  Constant: '<S114>/Constant1'
   *  DataTypeConversion: '<S114>/DataTypeConv1'
   *  DataTypeConversion: '<S114>/DataTypeConv2'
   *  Gain: '<S114>/ZeroGain'
   *  Logic: '<S114>/AND3'
   *  RelationalOperator: '<S114>/Equal1'
   *  RelationalOperator: '<S114>/NotEqual'
   */
  if ((0.0 * rtb_Saturation[1] != rtb_Filter_n_idx_3) && ((int8_T)
       rtb_IntegralGain_idx_1 == (int8_T)rtb_IntegralGain_idx_0)) {
    rtb_T_ff_deceleration_a = 0.0;
  } else {
    rtb_T_ff_deceleration_a = rtb_IntegralGain_1;
  }

  /* DeadZone: '<S116>/DeadZone' incorporates:
   *  Gain: '<S114>/ZeroGain'
   */
  if (rtb_Saturation[2] > -5.0) {
    rtb_Filter_n_idx_3 = rtb_Saturation[2] - -5.0;
  } else if (rtb_Saturation[2] >= -20.0) {
    rtb_Filter_n_idx_3 = 0.0;
  } else {
    rtb_Filter_n_idx_3 = rtb_Saturation[2] - -20.0;
  }

  /* Gain: '<S120>/Integral Gain' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Sum: '<S17>/Subtract'
   */
  rtb_IntegralGain_1 = (-0.1 - rtb_rl_d) * 100.0;

  /* Signum: '<S114>/SignPreSat' */
  if (rtb_Filter_n_idx_3 < 0.0) {
    rtb_IntegralGain_idx_1 = -1.0;
  } else if (rtb_Filter_n_idx_3 > 0.0) {
    rtb_IntegralGain_idx_1 = 1.0;
  } else if (rtb_Filter_n_idx_3 == 0.0) {
    rtb_IntegralGain_idx_1 = 0.0;
  } else {
    rtb_IntegralGain_idx_1 = (rtNaN);
  }

  /* Signum: '<S114>/SignPreIntegrator' */
  if (rtb_IntegralGain_1 < 0.0) {
    rtb_IntegralGain_idx_0 = -1.0;
  } else if (rtb_IntegralGain_1 > 0.0) {
    rtb_IntegralGain_idx_0 = 1.0;
  } else if (rtb_IntegralGain_1 == 0.0) {
    rtb_IntegralGain_idx_0 = 0.0;
  } else {
    rtb_IntegralGain_idx_0 = (rtNaN);
  }

  /* Switch: '<S114>/Switch' incorporates:
   *  Constant: '<S114>/Constant1'
   *  DataTypeConversion: '<S114>/DataTypeConv1'
   *  DataTypeConversion: '<S114>/DataTypeConv2'
   *  Gain: '<S114>/ZeroGain'
   *  Logic: '<S114>/AND3'
   *  RelationalOperator: '<S114>/Equal1'
   *  RelationalOperator: '<S114>/NotEqual'
   */
  if ((0.0 * rtb_Saturation[2] != rtb_Filter_n_idx_3) && ((int8_T)
       rtb_IntegralGain_idx_1 == (int8_T)rtb_IntegralGain_idx_0)) {
    rtb_T_ff_deceleration_p = 0.0;
  } else {
    rtb_T_ff_deceleration_p = rtb_IntegralGain_1;
  }

  /* Gain: '<S114>/ZeroGain' */
  rtb_T_ff_deceleration_f = 0.0 * rtb_Saturation[3];

  /* DeadZone: '<S116>/DeadZone' incorporates:
   *  Gain: '<S114>/ZeroGain'
   */
  if (rtb_Saturation[3] > -5.0) {
    rtb_Filter_n_idx_3 = rtb_Saturation[3] - -5.0;
  } else if (rtb_Saturation[3] >= -20.0) {
    rtb_Filter_n_idx_3 = 0.0;
  } else {
    rtb_Filter_n_idx_3 = rtb_Saturation[3] - -20.0;
  }

  /* Gain: '<S120>/Integral Gain' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Sum: '<S17>/Subtract'
   */
  rtb_IntegralGain_1 = (-0.1 - rtb_rr_l) * 100.0;

  /* Chart: '<S85>/Chart' incorporates:
   *  Logic: '<S17>/NOT'
   */
  Chart(rtb_Driving[0], !rtb_NOT_idx_0, &rtDW.TC_max_i, &rtDW.sf_Chart_c);

  /* Chart: '<S85>/Chart1' incorporates:
   *  Logic: '<S17>/NOT'
   */
  Chart(rtb_Driving[1], !rtb_NOT_idx_1, &rtDW.TC_max_k, &rtDW.sf_Chart1_b);

  /* Chart: '<S85>/Chart2' incorporates:
   *  Logic: '<S17>/NOT'
   */
  Chart(rtb_Driving[2], !rtb_NOT_idx_2, &rtDW.TC_max_a, &rtDW.sf_Chart2_n);

  /* Chart: '<S85>/Chart3' incorporates:
   *  Logic: '<S17>/NOT'
   */
  Chart(rtb_Driving[3], !rtb_NOT_idx_3, &rtDW.TC_max, &rtDW.sf_Chart3_d);

  /* Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_rr = look1_binlx(rtU.steering, rtConstP.pooled34,
                       rtConstP.steering_to_wheel_angle_single_, 32U);

  /* MATLAB Function: '<S145>/MATLAB Function1' incorporates:
   *  MATLAB Function: '<S151>/MATLAB Function2'
   *  Math: '<S264>/Square1'
   *  Math: '<S264>/Square2'
   *  Math: '<S266>/Square1'
   */
  rtb_rr_l = rtb_vx * rtb_vx;
  rtb_Integrator_b = rtb_rr * rtb_vx / (rtb_rr_l * 0.0 + 1.53);

  /* SignalConversion generated from: '<S146>/Vector Concatenate' incorporates:
   *  Constant: '<S146>/T_FL_ref'
   *  Constant: '<S146>/T_FR_ref'
   *  Constant: '<S146>/T_RL_ref'
   *  Constant: '<S146>/T_RR_ref'
   *  Constant: '<S146>/VX_ref'
   *  Constant: '<S146>/VY_ref'
   *  Constant: '<S146>/dT_FL_ref'
   *  Constant: '<S146>/dT_FR_ref'
   *  Constant: '<S146>/dT_RL_ref'
   *  Constant: '<S146>/dT_RR_ref'
   */
  rtb_TmpSignalConversionAtSFunct[0] = 0.0;
  rtb_TmpSignalConversionAtSFunct[1] = 0.0;
  rtb_TmpSignalConversionAtSFunct[2] = rtb_Integrator_b;
  memset(&rtb_TmpSignalConversionAtSFunct[3], 0, sizeof(real_T) << 3U);
  memcpy(&rtb_VectorConcatenate[0], &rtb_TmpSignalConversionAtSFunct[0], 11U *
         sizeof(real_T));

  /* SignalConversion generated from: '<S146>/Vector Concatenate' */
  memcpy(&rtb_VectorConcatenate[11], &rtb_TmpSignalConversionAtSFunct[0], 11U *
         sizeof(real_T));

  /* RateTransition: '<S157>/Rate Transition3' incorporates:
   *  Constant: '<S147>/Inertia Scaling'
   *  Constant: '<S147>/LMUy'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = rtb_rr;
  RateTransition3[1] = rtb_Switch;
  RateTransition3[2] = rtb_Switch_h;
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

  /* CFunction: '<S157>/C Function' incorporates:
   *  Constant: '<S157>/Constant3'
   */
  for (i = 0; i < 2; i++) {
    memcpy(&rtDW.CFunction[i * 13], &RateTransition3[0], 13U * sizeof(real_T));
  }

  /* End of CFunction: '<S157>/C Function' */

  /* Memory: '<S144>/Memory' */
  rtb_T_ff_slip_g[0] = rtDW.Memory_PreviousInput[0];
  rtb_T_ff_slip_g[1] = rtDW.Memory_PreviousInput[1];
  rtb_T_ff_slip_g[2] = rtDW.Memory_PreviousInput[2];
  rtb_T_ff_slip_g[3] = rtDW.Memory_PreviousInput[3];

  /* Lookup_n-D: '<S279>/Max_Torque_Overload_Motor_LUT' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Lookup_n-D: '<S279>/Max_Torque_Overload_Inverter_LUT'
   *  Lookup_n-D: '<S280>/Display Overload Inverter LUT'
   *  Lookup_n-D: '<S280>/Display Overload Motor LUT'
   */
  rtb_Saturation_fy = look1_binlx(0.0, rtConstP.pooled51, rtConstP.pooled50, 2U);
  rtb_Driving[0] = rtb_Saturation_fy;
  rtb_Driving[1] = rtb_Saturation_fy;
  rtb_Driving[2] = rtb_Saturation_fy;
  rtb_Driving[3] = rtb_Saturation_fy;

  /* MultiPortSwitch: '<S282>/Multiport Switch' incorporates:
   *  Constant: '<S282>/Constant1'
   */
  rtb_Switch_g = 21.0;

  /* RelationalOperator: '<S288>/Compare' incorporates:
   *  Constant: '<S285>/Time constant'
   *  Constant: '<S288>/Constant'
   *  Sum: '<S285>/Sum1'
   */
  rtb_Compare = (0.079577471545947673 - rtDW.Probe[0] <= 0.0);

  /* Gain: '<S282>/Gain4' incorporates:
   *  Gain: '<S291>/Gain4'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  vx_p = 128.91550390443524 * rtU.omega_wheels_FL;

  /* Saturate: '<S282>/Saturation1' incorporates:
   *  Gain: '<S282>/Gain4'
   */
  if (vx_p <= 0.0) {
    rtb_UnaryMinus_e5[0] = 0.0;
  } else {
    rtb_UnaryMinus_e5[0] = vx_p;
  }

  /* Gain: '<S282>/Gain4' incorporates:
   *  Gain: '<S291>/Gain4'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  rtb_fl_c = 128.91550390443524 * rtU.omega_wheels_FR;

  /* Saturate: '<S282>/Saturation1' incorporates:
   *  Gain: '<S282>/Gain4'
   */
  if (rtb_fl_c <= 0.0) {
    rtb_UnaryMinus_e5[1] = 0.0;
  } else {
    rtb_UnaryMinus_e5[1] = rtb_fl_c;
  }

  /* Gain: '<S282>/Gain4' incorporates:
   *  Gain: '<S291>/Gain4'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  rtb_fr_a = 128.91550390443524 * rtU.omega_wheels_RL;

  /* Saturate: '<S282>/Saturation1' incorporates:
   *  Gain: '<S282>/Gain4'
   */
  if (rtb_fr_a <= 0.0) {
    rtb_UnaryMinus_e5[2] = 0.0;
  } else {
    rtb_UnaryMinus_e5[2] = rtb_fr_a;
  }

  /* Gain: '<S282>/Gain4' incorporates:
   *  Gain: '<S291>/Gain4'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_SumofElements1 = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Saturate: '<S282>/Saturation1' incorporates:
   *  Gain: '<S282>/Gain4'
   */
  if (rtb_SumofElements1 <= 0.0) {
    rtb_UnaryMinus_e5[3] = 0.0;
  } else {
    rtb_UnaryMinus_e5[3] = rtb_SumofElements1;
  }

  /* Lookup_n-D: '<S282>/2-D Lookup Table' incorporates:
   *  Constant: '<S279>/Constant7'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &rtb_UnaryMinus_pe);
  fractions[1U] = rtb_UnaryMinus_pe;
  bpIndices[0U] = plook_binc(rtb_UnaryMinus_e5[0], rtConstP.pooled14, 200U,
    &rtb_UnaryMinus_pe);
  fractions[0U] = rtb_UnaryMinus_pe;
  rtb_UnaryMinus_e5[0] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_UnaryMinus_e5[1], rtConstP.pooled14, 200U,
    &rtb_UnaryMinus_pe);
  fractions[0U] = rtb_UnaryMinus_pe;
  rtb_UnaryMinus_e5[1] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_UnaryMinus_e5[2], rtConstP.pooled14, 200U,
    &rtb_UnaryMinus_pe);
  fractions[0U] = rtb_UnaryMinus_pe;
  rtb_UnaryMinus_e5[2] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);
  bpIndices[0U] = plook_binc(rtb_UnaryMinus_e5[3], rtConstP.pooled14, 200U,
    &rtb_UnaryMinus_pe);
  fractions[0U] = rtb_UnaryMinus_pe;
  rtb_UnaryMinus_e5[3] = intrp2d_l(bpIndices, fractions, rtConstP.pooled13, 201U);

  /* Gain: '<S282>/Gain' */
  rtb_IntegralGain_idx_0 = 0.0098000000000000014 * rtb_UnaryMinus_e5[0];
  rtb_IntegralGain_idx_1 = 0.0098000000000000014 * rtb_UnaryMinus_e5[1];
  rtb_IntegralGain_idx_2 = 0.0098000000000000014 * rtb_UnaryMinus_e5[2];
  rtb_IntegralGain_idx_3 = 0.0098000000000000014 * rtb_UnaryMinus_e5[3];

  /* DiscreteIntegrator: '<S290>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE_e[0] = rtb_IntegralGain_idx_0;
    rtDW.Integrator_DSTATE_e[1] = rtb_IntegralGain_idx_1;
    rtDW.Integrator_DSTATE_e[2] = rtb_IntegralGain_idx_2;
    rtDW.Integrator_DSTATE_e[3] = rtb_IntegralGain_idx_3;
  }

  if (rtb_Compare || (rtDW.Integrator_PrevResetState_k != 0)) {
    rtDW.Integrator_DSTATE_e[0] = rtb_IntegralGain_idx_0;
    rtDW.Integrator_DSTATE_e[1] = rtb_IntegralGain_idx_1;
    rtDW.Integrator_DSTATE_e[2] = rtb_IntegralGain_idx_2;
    rtDW.Integrator_DSTATE_e[3] = rtb_IntegralGain_idx_3;
  }

  rtb_Saturation[0] = rtDW.Integrator_DSTATE_e[0];
  rtb_Saturation[1] = rtDW.Integrator_DSTATE_e[1];
  rtb_Saturation[2] = rtDW.Integrator_DSTATE_e[2];
  rtb_Saturation[3] = rtDW.Integrator_DSTATE_e[3];

  /* MinMax: '<S279>/Min' incorporates:
   *  Constant: '<S282>/Constant'
   *  DiscreteIntegrator: '<S290>/Integrator'
   *  RelationalOperator: '<S284>/LowerRelop1'
   *  RelationalOperator: '<S284>/UpperRelop'
   *  Switch: '<S284>/Switch'
   *  Switch: '<S284>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_e[0] > rtb_Switch_g) {
    tmp_0 = rtb_Switch_g;
  } else if (rtDW.Integrator_DSTATE_e[0] < 0.0) {
    /* Switch: '<S284>/Switch' incorporates:
     *  Constant: '<S282>/Constant'
     */
    tmp_0 = 0.0;
  } else {
    tmp_0 = rtDW.Integrator_DSTATE_e[0];
  }

  rtb_Product1_idx_0 = fmin(fmin(fmin(rtb_Driving[0], rtb_Saturation_fy), 20.972),
    tmp_0);

  /* Saturate: '<S279>/Saturation_Positive' incorporates:
   *  MinMax: '<S279>/Min'
   */
  if (rtb_Product1_idx_0 <= 0.0) {
    rtb_Driving[0] = 0.0;
  } else {
    rtb_Driving[0] = rtb_Product1_idx_0;
  }

  /* MinMax: '<S279>/Min' incorporates:
   *  Constant: '<S282>/Constant'
   *  DiscreteIntegrator: '<S290>/Integrator'
   *  RelationalOperator: '<S284>/LowerRelop1'
   *  RelationalOperator: '<S284>/UpperRelop'
   *  Switch: '<S284>/Switch'
   *  Switch: '<S284>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_e[1] > rtb_Switch_g) {
    tmp_0 = rtb_Switch_g;
  } else if (rtDW.Integrator_DSTATE_e[1] < 0.0) {
    /* Switch: '<S284>/Switch' incorporates:
     *  Constant: '<S282>/Constant'
     */
    tmp_0 = 0.0;
  } else {
    tmp_0 = rtDW.Integrator_DSTATE_e[1];
  }

  rtb_Product1_idx_0 = fmin(fmin(fmin(rtb_Driving[1], rtb_Saturation_fy), 20.972),
    tmp_0);

  /* Saturate: '<S279>/Saturation_Positive' incorporates:
   *  MinMax: '<S279>/Min'
   */
  if (rtb_Product1_idx_0 <= 0.0) {
    rtb_Driving[1] = 0.0;
  } else {
    rtb_Driving[1] = rtb_Product1_idx_0;
  }

  /* MinMax: '<S279>/Min' incorporates:
   *  Constant: '<S282>/Constant'
   *  DiscreteIntegrator: '<S290>/Integrator'
   *  RelationalOperator: '<S284>/LowerRelop1'
   *  RelationalOperator: '<S284>/UpperRelop'
   *  Switch: '<S284>/Switch'
   *  Switch: '<S284>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_e[2] > rtb_Switch_g) {
    tmp_0 = rtb_Switch_g;
  } else if (rtDW.Integrator_DSTATE_e[2] < 0.0) {
    /* Switch: '<S284>/Switch' incorporates:
     *  Constant: '<S282>/Constant'
     */
    tmp_0 = 0.0;
  } else {
    tmp_0 = rtDW.Integrator_DSTATE_e[2];
  }

  rtb_Product1_idx_0 = fmin(fmin(fmin(rtb_Driving[2], rtb_Saturation_fy), 20.972),
    tmp_0);

  /* Saturate: '<S279>/Saturation_Positive' incorporates:
   *  MinMax: '<S279>/Min'
   */
  if (rtb_Product1_idx_0 <= 0.0) {
    rtb_Driving[2] = 0.0;
  } else {
    rtb_Driving[2] = rtb_Product1_idx_0;
  }

  /* MinMax: '<S279>/Min' incorporates:
   *  Constant: '<S282>/Constant'
   *  DiscreteIntegrator: '<S290>/Integrator'
   *  RelationalOperator: '<S284>/LowerRelop1'
   *  RelationalOperator: '<S284>/UpperRelop'
   *  Switch: '<S284>/Switch'
   *  Switch: '<S284>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_e[3] > rtb_Switch_g) {
    tmp_0 = rtb_Switch_g;
  } else if (rtDW.Integrator_DSTATE_e[3] < 0.0) {
    /* Switch: '<S284>/Switch' incorporates:
     *  Constant: '<S282>/Constant'
     */
    tmp_0 = 0.0;
  } else {
    tmp_0 = rtDW.Integrator_DSTATE_e[3];
  }

  rtb_Product1_idx_0 = fmin(fmin(fmin(rtb_Driving[3], rtb_Saturation_fy), 20.972),
    tmp_0);

  /* Saturate: '<S279>/Saturation_Positive' incorporates:
   *  MinMax: '<S279>/Min'
   */
  if (rtb_Product1_idx_0 <= 0.0) {
    rtb_Driving[3] = 0.0;
  } else {
    rtb_Driving[3] = rtb_Product1_idx_0;
  }

  /* Gain: '<S264>/Lateral Load Transfer' incorporates:
   *  Gain: '<S265>/Lateral Load Transfer'
   *  Gain: '<S266>/Lateral Load Transfer'
   *  Gain: '<S267>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S264>/Unary Minus'
   */
  rtb_Switch_g = 30.826771653543307 * -rtU.ay;

  /* Gain: '<S264>/Lift Force' incorporates:
   *  Gain: '<S265>/Lift Force'
   */
  rtb_Saturation_c_idx_3 = rtb_rr_l * 0.92446666666666677;

  /* Gain: '<S264>/Drag moment' incorporates:
   *  Gain: '<S265>/Drag moment'
   *  Gain: '<S266>/Drag moment'
   *  Gain: '<S267>/Drag moment'
   */
  rtb_Saturation_c_idx_0 = rtb_rr_l * 0.21998117647058821;

  /* Gain: '<S264>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S265>/Longitudinal Load Transfer'
   *  Gain: '<S266>/Longitudinal Load Transfer'
   *  Gain: '<S267>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S264>/Unary Minus1'
   */
  rtb_Saturation_c_idx_1 = 25.588235294117645 * -rtU.ax;

  /* SignalConversion generated from: '<S256>/2-D Lookup Table' incorporates:
   *  Constant: '<S264>/Static Load Front'
   *  Constant: '<S265>/Static Load Front'
   *  Gain: '<S264>/Drag moment'
   *  Gain: '<S264>/Lateral Load Transfer'
   *  Gain: '<S264>/Lift Force'
   *  Gain: '<S264>/Longitudinal Load Transfer'
   *  Sum: '<S264>/Subtract'
   *  Sum: '<S265>/Subtract'
   */
  rtb_UnaryMinus_e5[0] = (((rtb_Switch_g + 635.688) + rtb_Saturation_c_idx_3) -
    rtb_Saturation_c_idx_0) + rtb_Saturation_c_idx_1;
  rtb_UnaryMinus_e5[1] = (((635.688 - rtb_Switch_g) + rtb_Saturation_c_idx_3) -
    rtb_Saturation_c_idx_0) + rtb_Saturation_c_idx_1;

  /* Gain: '<S266>/Lift Force' incorporates:
   *  Gain: '<S267>/Lift Force'
   */
  rtb_Saturation_c_idx_3 = rtb_rr_l * 0.74153333333333349;

  /* SignalConversion generated from: '<S256>/2-D Lookup Table' incorporates:
   *  Constant: '<S266>/Static Load Front'
   *  Constant: '<S267>/Static Load Front'
   *  Gain: '<S266>/Lift Force'
   *  Sum: '<S266>/Subtract'
   *  Sum: '<S267>/Subtract'
   */
  rtb_UnaryMinus_e5[2] = (((rtb_Switch_g + 688.66200000000015) +
    rtb_Saturation_c_idx_3) + rtb_Saturation_c_idx_0) - rtb_Saturation_c_idx_1;
  rtb_UnaryMinus_e5[3] = (((688.66200000000015 - rtb_Switch_g) +
    rtb_Saturation_c_idx_3) + rtb_Saturation_c_idx_0) - rtb_Saturation_c_idx_1;

  /* Switch: '<S263>/Switch' incorporates:
   *  Constant: '<S263>/Constant'
   *  Sum: '<S268>/Subtract'
   *  Sum: '<S268>/Subtract1'
   *  Sum: '<S268>/Subtract2'
   *  Sum: '<S269>/Subtract'
   *  Sum: '<S269>/Subtract2'
   *  Sum: '<S270>/Subtract1'
   *  Trigonometry: '<S268>/Atan'
   *  Trigonometry: '<S269>/Atan'
   *  Trigonometry: '<S270>/Atan'
   *  Trigonometry: '<S271>/Atan'
   */
  if (rtb_vx > 3.0) {
    /* Sum: '<S268>/Subtract1' incorporates:
     *  Gain: '<S268>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S269>/Subtract1'
     */
    rtb_Saturation_c_idx_0 = 0.73439999999999994 * rtb_Gain1 + rtU.vy;

    /* Sum: '<S268>/Subtract' incorporates:
     *  Gain: '<S268>/Gain1'
     *  Sum: '<S270>/Subtract'
     */
    rtb_Saturation_c_idx_3 = rtb_vx - 0.635 * rtb_Gain1;
    rtb_rl_d = rt_atan2d_snf(rtb_Saturation_c_idx_0, rtb_Saturation_c_idx_3) -
      rtb_Abs_m_idx_0;

    /* Sum: '<S269>/Subtract' incorporates:
     *  Gain: '<S269>/Gain1'
     *  Sum: '<S268>/Subtract'
     *  Sum: '<S268>/Subtract1'
     *  Sum: '<S268>/Subtract2'
     *  Sum: '<S271>/Subtract'
     *  Trigonometry: '<S268>/Atan'
     */
    rtb_Switch_g = 0.635 * rtb_Gain1 + rtb_vx;
    rtb_Tnew_idx_1 = rt_atan2d_snf(rtb_Saturation_c_idx_0, rtb_Switch_g) -
      rtb_Abs_g;

    /* Sum: '<S270>/Subtract1' incorporates:
     *  Gain: '<S270>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S269>/Subtract'
     *  Sum: '<S269>/Subtract2'
     *  Sum: '<S271>/Subtract1'
     *  Trigonometry: '<S269>/Atan'
     */
    rtb_Saturation_c_idx_0 = rtU.vy - 0.79560000000000008 * rtb_Gain1;
    rtb_Tnew_idx_2 = rt_atan2d_snf(rtb_Saturation_c_idx_0,
      rtb_Saturation_c_idx_3);
    rtb_Tnew_idx_3 = rt_atan2d_snf(rtb_Saturation_c_idx_0, rtb_Switch_g);
  } else {
    rtb_rl_d = 0.0;
    rtb_Tnew_idx_1 = 0.0;
    rtb_Tnew_idx_2 = 0.0;
    rtb_Tnew_idx_3 = 0.0;
  }

  /* End of Switch: '<S263>/Switch' */

  /* Lookup_n-D: '<S256>/2-D Lookup Table' */
  rtb_Saturation_c_idx_0 = look2_binlx(rtb_UnaryMinus_e5[0], rtb_rl_d,
    rtConstP.pooled54, rtConstP.pooled55, rtConstP.uDLookupTable_tableData_d,
    rtConstP.pooled67, 30U);
  rtb_Saturation_c_idx_1 = look2_binlx(rtb_UnaryMinus_e5[1], rtb_Tnew_idx_1,
    rtConstP.pooled54, rtConstP.pooled55, rtConstP.uDLookupTable_tableData_d,
    rtConstP.pooled67, 30U);
  rtb_Saturation_c_idx_2 = look2_binlx(rtb_UnaryMinus_e5[2], rtb_Tnew_idx_2,
    rtConstP.pooled54, rtConstP.pooled55, rtConstP.uDLookupTable_tableData_d,
    rtConstP.pooled67, 30U);
  rtb_Saturation_c_idx_3 = look2_binlx(rtb_UnaryMinus_e5[3], rtb_Tnew_idx_3,
    rtConstP.pooled54, rtConstP.pooled55, rtConstP.uDLookupTable_tableData_d,
    rtConstP.pooled67, 30U);

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/brake'
   */
  vx = 3.5714285714285712 * rtU.brake;

  /* Saturate: '<S8>/Saturation' */
  if (vx > 1.0) {
    vx = 1.0;
  } else if (vx < 0.0) {
    vx = 0.0;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Switch: '<S250>/Switch' */
  rtb_Switch_g = !(vx > 0.95);

  /* Gain: '<S256>/Gain' */
  rtb_Product1_idx_0 = 0.017407407407407406 * rtb_Saturation_c_idx_0;

  /* Saturate: '<S256>/Saturation1' */
  if (rtb_Product1_idx_0 <= 0.0) {
    rtb_Product1_idx_0 = 0.0;
  }

  /* Product: '<S250>/Product' incorporates:
   *  Constant: '<S11>/Constant6'
   *  MinMax: '<S155>/Min'
   */
  rtb_Diff[0] = fmin(fmin(rtb_Driving[0], 21.0), rtb_Product1_idx_0) *
    rtb_Switch_g;

  /* Gain: '<S256>/Gain' */
  rtb_Product1_idx_0 = 0.017407407407407406 * rtb_Saturation_c_idx_1;

  /* Saturate: '<S256>/Saturation1' */
  if (rtb_Product1_idx_0 <= 0.0) {
    rtb_Product1_idx_0 = 0.0;
  }

  /* Product: '<S250>/Product' incorporates:
   *  Constant: '<S11>/Constant6'
   *  MinMax: '<S155>/Min'
   */
  rtb_Diff[1] = fmin(fmin(rtb_Driving[1], 21.0), rtb_Product1_idx_0) *
    rtb_Switch_g;

  /* Gain: '<S256>/Gain' */
  rtb_Product1_idx_0 = 0.017407407407407406 * rtb_Saturation_c_idx_2;

  /* Saturate: '<S256>/Saturation1' */
  if (rtb_Product1_idx_0 <= 0.0) {
    rtb_Product1_idx_0 = 0.0;
  }

  /* Product: '<S250>/Product' incorporates:
   *  Constant: '<S11>/Constant6'
   *  MinMax: '<S155>/Min'
   */
  rtb_Diff[2] = fmin(fmin(rtb_Driving[2], 21.0), rtb_Product1_idx_0) *
    rtb_Switch_g;

  /* Gain: '<S256>/Gain' */
  rtb_Product1_idx_0 = 0.017407407407407406 * rtb_Saturation_c_idx_3;

  /* Saturate: '<S256>/Saturation1' */
  if (rtb_Product1_idx_0 <= 0.0) {
    rtb_Product1_idx_0 = 0.0;
  }

  /* Product: '<S250>/Product' incorporates:
   *  Constant: '<S11>/Constant6'
   *  MinMax: '<S155>/Min'
   */
  rtb_Diff[3] = fmin(fmin(rtb_Driving[3], 21.0), rtb_Product1_idx_0) *
    rtb_Switch_g;

  /* Lookup_n-D: '<S256>/2-D Lookup Table1' */
  rtb_UnaryMinus_e5[0] = look2_binlx(rtb_UnaryMinus_e5[0], rtb_rl_d,
    rtConstP.pooled54, rtConstP.pooled55, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled67, 30U);
  rtb_UnaryMinus_e5[1] = look2_binlx(rtb_UnaryMinus_e5[1], rtb_Tnew_idx_1,
    rtConstP.pooled54, rtConstP.pooled55, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled67, 30U);
  rtb_UnaryMinus_e5[2] = look2_binlx(rtb_UnaryMinus_e5[2], rtb_Tnew_idx_2,
    rtConstP.pooled54, rtConstP.pooled55, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled67, 30U);
  rtb_UnaryMinus_e5[3] = look2_binlx(rtb_UnaryMinus_e5[3], rtb_Tnew_idx_3,
    rtConstP.pooled54, rtConstP.pooled55, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled67, 30U);

  /* Product: '<S256>/Product1' incorporates:
   *  Gain: '<S256>/Gain1'
   */
  rtb_Product1_idx_0 = 0.017407407407407406 * rtb_UnaryMinus_e5[0];
  rtb_rl_d = 0.017407407407407406 * rtb_UnaryMinus_e5[1];
  rtb_Tnew_idx_1 = 0.017407407407407406 * rtb_UnaryMinus_e5[2];
  rtb_Tnew_idx_3 = 0.017407407407407406 * rtb_UnaryMinus_e5[3];

  /* Lookup_n-D: '<S280>/Display Overload Motor LUT' */
  rtb_UnaryMinus_e5[0] = rtb_Saturation_fy;
  rtb_UnaryMinus_e5[1] = rtb_Saturation_fy;
  rtb_UnaryMinus_e5[2] = rtb_Saturation_fy;
  rtb_UnaryMinus_e5[3] = rtb_Saturation_fy;

  /* MultiPortSwitch: '<S291>/Multiport Switch' incorporates:
   *  Constant: '<S291>/Constant1'
   */
  rtb_Switch_g = 21.0;

  /* RelationalOperator: '<S297>/Compare' incorporates:
   *  Constant: '<S294>/Time constant'
   *  Constant: '<S297>/Constant'
   *  Sum: '<S294>/Sum1'
   */
  rtb_Compare_n = (0.079577471545947673 - rtDW.Probe_h[0] <= 0.0);

  /* Saturate: '<S291>/Saturation1' */
  if (vx_p <= 0.0) {
    rtb_Driving[0] = 0.0;
  } else {
    rtb_Driving[0] = vx_p;
  }

  if (rtb_fl_c <= 0.0) {
    rtb_Driving[1] = 0.0;
  } else {
    rtb_Driving[1] = rtb_fl_c;
  }

  if (rtb_fr_a <= 0.0) {
    rtb_Driving[2] = 0.0;
  } else {
    rtb_Driving[2] = rtb_fr_a;
  }

  if (rtb_SumofElements1 <= 0.0) {
    rtb_Driving[3] = 0.0;
  } else {
    rtb_Driving[3] = rtb_SumofElements1;
  }

  /* End of Saturate: '<S291>/Saturation1' */

  /* Lookup_n-D: '<S291>/2-D Lookup Table' incorporates:
   *  Constant: '<S280>/Constant7'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &rtb_UnaryMinus_pe);
  fractions_0[1U] = rtb_UnaryMinus_pe;
  bpIndices_0[0U] = plook_binc(rtb_Driving[0], rtConstP.pooled14, 200U,
    &rtb_UnaryMinus_pe);
  fractions_0[0U] = rtb_UnaryMinus_pe;
  rtb_Driving[0] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Driving[1], rtConstP.pooled14, 200U,
    &rtb_UnaryMinus_pe);
  fractions_0[0U] = rtb_UnaryMinus_pe;
  rtb_Driving[1] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Driving[2], rtConstP.pooled14, 200U,
    &rtb_UnaryMinus_pe);
  fractions_0[0U] = rtb_UnaryMinus_pe;
  rtb_Driving[2] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Driving[3], rtConstP.pooled14, 200U,
    &rtb_UnaryMinus_pe);
  fractions_0[0U] = rtb_UnaryMinus_pe;
  rtb_Driving[3] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);

  /* Gain: '<S291>/Gain' */
  rtb_Saturation_c_idx_0 = 0.0098000000000000014 * rtb_Driving[0];
  rtb_Saturation_c_idx_1 = 0.0098000000000000014 * rtb_Driving[1];
  rtb_Saturation_c_idx_2 = 0.0098000000000000014 * rtb_Driving[2];
  rtb_Saturation_c_idx_3 = 0.0098000000000000014 * rtb_Driving[3];

  /* DiscreteIntegrator: '<S299>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_f != 0) {
    rtDW.Integrator_DSTATE_i[0] = rtb_Saturation_c_idx_0;
    rtDW.Integrator_DSTATE_i[1] = rtb_Saturation_c_idx_1;
    rtDW.Integrator_DSTATE_i[2] = rtb_Saturation_c_idx_2;
    rtDW.Integrator_DSTATE_i[3] = rtb_Saturation_c_idx_3;
  }

  if (rtb_Compare_n || (rtDW.Integrator_PrevResetState_l != 0)) {
    rtDW.Integrator_DSTATE_i[0] = rtb_Saturation_c_idx_0;
    rtDW.Integrator_DSTATE_i[1] = rtb_Saturation_c_idx_1;
    rtDW.Integrator_DSTATE_i[2] = rtb_Saturation_c_idx_2;
    rtDW.Integrator_DSTATE_i[3] = rtb_Saturation_c_idx_3;
  }

  rtb_T_ff_deceleration_n[0] = rtDW.Integrator_DSTATE_i[0];
  rtb_T_ff_deceleration_n[1] = rtDW.Integrator_DSTATE_i[1];
  rtb_T_ff_deceleration_n[2] = rtDW.Integrator_DSTATE_i[2];
  rtb_T_ff_deceleration_n[3] = rtDW.Integrator_DSTATE_i[3];

  /* Switch: '<S293>/Switch2' incorporates:
   *  Constant: '<S291>/Constant'
   *  DiscreteIntegrator: '<S299>/Integrator'
   *  RelationalOperator: '<S293>/LowerRelop1'
   *  RelationalOperator: '<S293>/UpperRelop'
   *  Switch: '<S293>/Switch'
   */
  if (rtDW.Integrator_DSTATE_i[0] > rtb_Switch_g) {
    tmp_0 = rtb_Switch_g;
  } else if (rtDW.Integrator_DSTATE_i[0] < 0.0) {
    /* Switch: '<S293>/Switch' incorporates:
     *  Constant: '<S291>/Constant'
     */
    tmp_0 = 0.0;
  } else {
    tmp_0 = rtDW.Integrator_DSTATE_i[0];
  }

  /* Sum: '<S272>/Subtract' incorporates:
   *  Gain: '<S272>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Product1_idx_0 += 0.07407407407407407 * rtDW.UnitDelay_DSTATE[0];

  /* MinMax: '<S280>/Min1' */
  rtb_UnaryMinus_pe = fmin(fmin(fmin(rtb_UnaryMinus_e5[0], rtb_Saturation_fy),
    20.972), tmp_0);

  /* Saturate: '<S256>/Saturation' */
  if (rtb_Product1_idx_0 >= 0.0) {
    rtb_Product1_idx_0 = 0.0;
  }

  /* Saturate: '<S280>/Saturation_Positive' */
  if (rtb_UnaryMinus_pe <= 0.0) {
    rtb_UnaryMinus_pe = 0.0;
  }

  /* MinMax: '<S155>/Min1' incorporates:
   *  UnaryMinus: '<S155>/Unary Minus'
   */
  rtb_Driving[0] = fmax(rtb_Product1_idx_0, -rtb_UnaryMinus_pe);

  /* Switch: '<S293>/Switch2' incorporates:
   *  Constant: '<S291>/Constant'
   *  DiscreteIntegrator: '<S299>/Integrator'
   *  RelationalOperator: '<S293>/LowerRelop1'
   *  RelationalOperator: '<S293>/UpperRelop'
   *  Switch: '<S293>/Switch'
   */
  if (rtDW.Integrator_DSTATE_i[1] > rtb_Switch_g) {
    tmp_0 = rtb_Switch_g;
  } else if (rtDW.Integrator_DSTATE_i[1] < 0.0) {
    /* Switch: '<S293>/Switch' incorporates:
     *  Constant: '<S291>/Constant'
     */
    tmp_0 = 0.0;
  } else {
    tmp_0 = rtDW.Integrator_DSTATE_i[1];
  }

  /* Sum: '<S272>/Subtract' incorporates:
   *  Gain: '<S272>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Product1_idx_0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[1] + rtb_rl_d;

  /* MinMax: '<S280>/Min1' */
  rtb_UnaryMinus_pe = fmin(fmin(fmin(rtb_UnaryMinus_e5[1], rtb_Saturation_fy),
    20.972), tmp_0);

  /* Saturate: '<S256>/Saturation' */
  if (rtb_Product1_idx_0 >= 0.0) {
    rtb_Product1_idx_0 = 0.0;
  }

  /* Saturate: '<S280>/Saturation_Positive' */
  if (rtb_UnaryMinus_pe <= 0.0) {
    rtb_UnaryMinus_pe = 0.0;
  }

  /* MinMax: '<S155>/Min1' incorporates:
   *  UnaryMinus: '<S155>/Unary Minus'
   */
  rtb_Driving[1] = fmax(rtb_Product1_idx_0, -rtb_UnaryMinus_pe);

  /* Switch: '<S293>/Switch2' incorporates:
   *  Constant: '<S291>/Constant'
   *  DiscreteIntegrator: '<S299>/Integrator'
   *  RelationalOperator: '<S293>/LowerRelop1'
   *  RelationalOperator: '<S293>/UpperRelop'
   *  Switch: '<S293>/Switch'
   */
  if (rtDW.Integrator_DSTATE_i[2] > rtb_Switch_g) {
    tmp_0 = rtb_Switch_g;
  } else if (rtDW.Integrator_DSTATE_i[2] < 0.0) {
    /* Switch: '<S293>/Switch' incorporates:
     *  Constant: '<S291>/Constant'
     */
    tmp_0 = 0.0;
  } else {
    tmp_0 = rtDW.Integrator_DSTATE_i[2];
  }

  /* Sum: '<S272>/Subtract' incorporates:
   *  Gain: '<S272>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Product1_idx_0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[2] +
    rtb_Tnew_idx_1;

  /* MinMax: '<S280>/Min1' */
  rtb_UnaryMinus_pe = fmin(fmin(fmin(rtb_UnaryMinus_e5[2], rtb_Saturation_fy),
    20.972), tmp_0);

  /* Saturate: '<S256>/Saturation' */
  if (rtb_Product1_idx_0 >= 0.0) {
    rtb_Product1_idx_0 = 0.0;
  }

  /* Saturate: '<S280>/Saturation_Positive' */
  if (rtb_UnaryMinus_pe <= 0.0) {
    rtb_UnaryMinus_pe = 0.0;
  }

  /* MinMax: '<S155>/Min1' incorporates:
   *  UnaryMinus: '<S155>/Unary Minus'
   */
  rtb_Driving[2] = fmax(rtb_Product1_idx_0, -rtb_UnaryMinus_pe);

  /* Switch: '<S293>/Switch2' incorporates:
   *  Constant: '<S291>/Constant'
   *  DiscreteIntegrator: '<S299>/Integrator'
   *  RelationalOperator: '<S293>/LowerRelop1'
   *  RelationalOperator: '<S293>/UpperRelop'
   *  Switch: '<S293>/Switch'
   */
  if (rtDW.Integrator_DSTATE_i[3] > rtb_Switch_g) {
  } else if (rtDW.Integrator_DSTATE_i[3] < 0.0) {
    /* Switch: '<S293>/Switch' incorporates:
     *  Constant: '<S291>/Constant'
     */
    rtb_Switch_g = 0.0;
  } else {
    rtb_Switch_g = rtDW.Integrator_DSTATE_i[3];
  }

  /* Sum: '<S272>/Subtract' incorporates:
   *  Gain: '<S272>/Wheel2Motor'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Product1_idx_0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[3] +
    rtb_Tnew_idx_3;

  /* MinMax: '<S280>/Min1' */
  rtb_UnaryMinus_pe = fmin(fmin(fmin(rtb_UnaryMinus_e5[3], rtb_Saturation_fy),
    20.972), rtb_Switch_g);

  /* Saturate: '<S256>/Saturation' */
  if (rtb_Product1_idx_0 >= 0.0) {
    rtb_Product1_idx_0 = 0.0;
  }

  /* Saturate: '<S280>/Saturation_Positive' */
  if (rtb_UnaryMinus_pe <= 0.0) {
    rtb_UnaryMinus_pe = 0.0;
  }

  /* MinMax: '<S155>/Min1' incorporates:
   *  UnaryMinus: '<S155>/Unary Minus'
   */
  rtb_Driving[3] = fmax(rtb_Product1_idx_0, -rtb_UnaryMinus_pe);

  /* CombinatorialLogic: '<S258>/Logic' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S249>/Constant1'
   *  Memory: '<S258>/Memory'
   *  RelationalOperator: '<S249>/Less Than'
   *  RelationalOperator: '<S249>/Less Than1'
   */
  i = (int32_T)(((((uint32_T)(rtb_Switch <= -0.6) << 1) + (rtb_Switch >= -0.5)) <<
                 1) + rtDW.Memory_PreviousInput_c);
  rtb_Logic_idx_0 = rtConstP.pooled70[(uint32_T)i];
  rtb_Logic_idx_1 = rtConstP.pooled70[i + 8U];

  /* CombinatorialLogic: '<S259>/Logic' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S249>/Constant1'
   *  Memory: '<S259>/Memory'
   *  RelationalOperator: '<S249>/Less Than'
   *  RelationalOperator: '<S249>/Less Than1'
   */
  i = (int32_T)(((((uint32_T)(rtb_Switch_h <= -0.6) << 1) + (rtb_Switch_h >=
    -0.5)) << 1) + rtDW.Memory_PreviousInput_p);
  rtb_Logic_l_idx_0 = rtConstP.pooled70[(uint32_T)i];
  rtb_Logic_l_idx_1 = rtConstP.pooled70[i + 8U];

  /* CombinatorialLogic: '<S260>/Logic' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S249>/Constant1'
   *  Memory: '<S260>/Memory'
   *  RelationalOperator: '<S249>/Less Than'
   *  RelationalOperator: '<S249>/Less Than1'
   */
  i = (int32_T)(((((uint32_T)(rtb_RL <= -0.6) << 1) + (rtb_RL >= -0.5)) << 1) +
                rtDW.Memory_PreviousInput_j);
  rtb_Logic_p_idx_0 = rtConstP.pooled70[(uint32_T)i];
  rtb_Logic_p_idx_1 = rtConstP.pooled70[i + 8U];

  /* CombinatorialLogic: '<S261>/Logic' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S249>/Constant1'
   *  Memory: '<S261>/Memory'
   *  RelationalOperator: '<S249>/Less Than'
   *  RelationalOperator: '<S249>/Less Than1'
   */
  i = (int32_T)(((((uint32_T)(rtb_RR <= -0.6) << 1) + (rtb_RR >= -0.5)) << 1) +
                rtDW.Memory_PreviousInput_k);
  rtb_Logic_o_idx_0 = rtConstP.pooled70[(uint32_T)i];

  /* Product: '<S249>/Product' incorporates:
   *  CombinatorialLogic: '<S261>/Logic'
   */
  rtb_rl_d = rtb_Driving[0] * (real_T)rtb_Logic_idx_1;
  rtb_Tnew_idx_1 = rtb_Driving[1] * (real_T)rtb_Logic_l_idx_1;
  rtb_Tnew_idx_2 = (real_T)rtb_Logic_p_idx_1 * rtb_Driving[2];
  rtb_Tnew_idx_3 = (real_T)rtConstP.pooled70[i + 8U] * rtb_Driving[3];

  /* Abs: '<S177>/Abs' */
  vx_p = fabs(rtb_rr);

  /* MATLABSystem: '<S177>/Moving Average' */
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

  rtb_Switch_g = obj->pCumRevIndex;
  rtb_UnaryMinus_pe = obj->pCumSum;
  for (i = 0; i < 24; i++) {
    csumrev[i] = obj->pCumSumRev[i];
  }

  rtb_Saturation_fy = obj->pModValueRev;
  rtb_fl_c = 0.0;
  rtb_fr_a = 0.0;
  rtb_UnaryMinus_pe += vx_p;
  if (rtb_Saturation_fy == 0.0) {
    rtb_fl_c = csumrev[(int32_T)rtb_Switch_g - 1] + rtb_UnaryMinus_pe;
  }

  csumrev[(int32_T)rtb_Switch_g - 1] = vx_p;
  if (rtb_Switch_g != 24.0) {
    rtb_Switch_g++;
  } else {
    rtb_Switch_g = 1.0;
    rtb_UnaryMinus_pe = 0.0;
    for (i = 22; i >= 0; i--) {
      csumrev[i] += csumrev[i + 1];
    }
  }

  if (rtb_Saturation_fy == 0.0) {
    rtb_fr_a = rtb_fl_c / 25.0;
  }

  obj->pCumSum = rtb_UnaryMinus_pe;
  for (i = 0; i < 24; i++) {
    obj->pCumSumRev[i] = csumrev[i];
  }

  obj->pCumRevIndex = rtb_Switch_g;
  if (rtb_Saturation_fy > 0.0) {
    obj->pModValueRev = rtb_Saturation_fy - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* CombinatorialLogic: '<S237>/Logic' incorporates:
   *  Constant: '<S177>/Constant1'
   *  Constant: '<S177>/Constant4'
   *  Delay: '<S177>/Delay'
   *  Logic: '<S177>/AND'
   *  MATLABSystem: '<S177>/Moving Average'
   *  Memory: '<S237>/Memory'
   *  RelationalOperator: '<S177>/Less Than'
   *  RelationalOperator: '<S177>/Less Than2'
   */
  rtb_Logic_idx_1 = rtConstP.pooled70[((((uint32_T)(0.017453292519943295 <= vx_p)
    << 1) + ((rtb_fr_a < 0.0043633231299858239) && rtDW.Delay_DSTATE[0])) << 1)
    + rtDW.Memory_PreviousInput_f];

  /* Outputs for IfAction SubSystem: '<S177>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S236>/Action Port'
   */
  /* If: '<S177>/If' incorporates:
   *  Constant: '<S177>/Constant'
   *  DataTypeConversion: '<S236>/Data Type Conversion'
   *  Logic: '<S177>/AND1'
   *  RelationalOperator: '<S177>/Less Than1'
   */
  rtb_Logic_l_idx_1 = (rtb_Logic_idx_1 && (rtb_vx >= 3.0));

  /* End of Outputs for SubSystem: '<S177>/If Action Subsystem1' */

  /* MATLAB Function: '<S155>/Cross Check' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/throttle'
   *  SignalConversion generated from: '<S253>/ SFunction '
   */
  rtb_Driving[0] = rtb_rl_d;
  rtb_Driving[1] = rtb_Tnew_idx_1;
  rtb_Driving[2] = rtb_Tnew_idx_2;
  rtb_Driving[3] = rtb_Tnew_idx_3;
  if (rtb_Logic_l_idx_1) {
    i = 0;
  } else {
    i = 1;
  }

  if (i == 0) {
    if (rtb_rl_d > rtb_Diff[0]) {
      rtb_Driving[0] = rtb_Diff[0] - rtb_Tnew_idx_1;
    }

    if (rtb_Tnew_idx_1 > rtb_Diff[1]) {
      rtb_Driving[1] = rtb_Diff[1] - rtb_Tnew_idx_1;
    }

    if (rtb_Tnew_idx_2 > rtb_Diff[2]) {
      rtb_Driving[2] = rtb_Diff[2] - rtb_Tnew_idx_1;
    }

    if (rtb_Tnew_idx_3 > rtb_Diff[3]) {
      rtb_Driving[3] = rtb_Diff[3] - rtb_Tnew_idx_1;
    }
  } else if (rtU.throttle > 0.05) {
    rtb_Driving[0] = 0.0;
    rtb_Driving[1] = 0.0;
    rtb_Driving[2] = 0.0;
    rtb_Driving[3] = 0.0;
  } else if (rtU.brake > 0.05) {
    rtb_Diff[0] = 0.0;
    rtb_Diff[1] = 0.0;
    rtb_Diff[2] = 0.0;
    rtb_Diff[3] = 0.0;
  }

  /* End of MATLAB Function: '<S155>/Cross Check' */

  /* CFunction: '<S251>/C Function' incorporates:
   *  Constant: '<S251>/Constant3'
   */
  rtDW.CFunction_p[0] = rtb_Driving[0];
  rtDW.CFunction_p[1] = rtb_Driving[1];
  rtDW.CFunction_p[2] = rtb_Driving[2];
  rtDW.CFunction_p[3] = rtb_Driving[3];

  /* CFunction: '<S252>/C Function' incorporates:
   *  Constant: '<S252>/Constant3'
   */
  rtDW.CFunction_a[0] = rtb_Diff[0];
  rtDW.CFunction_a[1] = rtb_Diff[1];
  rtDW.CFunction_a[2] = rtb_Diff[2];
  rtDW.CFunction_a[3] = rtb_Diff[3];

  /* MultiPortSwitch: '<S238>/Multiport Switch1' incorporates:
   *  Constant: '<S238>/Constant9'
   */
  rtb_Switch_g = 21.0;

  /* Product: '<S238>/Product' incorporates:
   *  Constant: '<S238>/Constant1'
   *  Constant: '<S238>/Constant2'
   *  Constant: '<S244>/Constant'
   *  Constant: '<S244>/Exponent < 0'
   *  Gain: '<S238>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S238>/ '
   *  Math: '<S244>/Power'
   *  Product: '<S238>/Product1'
   *  Product: '<S244>/Divide'
   *  Product: '<S244>/Divide1'
   *  RelationalOperator: '<S238>/Less Than'
   *  RelationalOperator: '<S238>/Less Than1'
   *  Sum: '<S238>/Subtract1'
   *  Sum: '<S244>/Subtract'
   *  Sum: '<S244>/Sum'
   */
  rtb_Switch_g = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle), -1.5)
    + 1.0) - vx) * (real_T)(int8_T)((int8_T)(vx >= 0.05) ^ (int8_T)(rtU.throttle
    >= 0.05)) * (4.0 * rtb_Switch_g);

  /* Switch: '<S238>/Switch' incorporates:
   *  MinMax: '<S238>/Min'
   *  MinMax: '<S238>/Min1'
   *  Sum: '<S238>/Sum of Elements'
   *  Sum: '<S238>/Sum of Elements1'
   */
  if (rtb_Switch_g > 0.0) {
    rtb_Switch_g = fmin(((rtDW.CFunction_a[0] + rtDW.CFunction_a[1]) +
                         rtDW.CFunction_a[2]) + rtDW.CFunction_a[3],
                        rtb_Switch_g);
  } else {
    rtb_Switch_g = fmax(rtb_Switch_g, ((rtDW.CFunction_p[0] + rtDW.CFunction_p[1])
      + rtDW.CFunction_p[2]) + rtDW.CFunction_p[3]);
  }

  /* End of Switch: '<S238>/Switch' */

  /* Gain: '<S238>/Gain2' */
  rtb_SumofElements1 = 0.95 * rtb_Switch_g;

  /* Gain: '<S238>/Gain3' */
  vx_p = 1.05 * rtb_Switch_g;

  /* Switch: '<S239>/Switch2' incorporates:
   *  Constant: '<S239>/Engine Brake'
   *  Constant: '<S245>/Constant1'
   *  Constant: '<S245>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S245>/AND'
   *  MinMax: '<S239>/Max1'
   *  RelationalOperator: '<S245>/Less Than'
   *  RelationalOperator: '<S245>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > vx)) {
    rtb_Switch_g = -0.0;
  } else {
    rtb_Switch_g = fmin(rtb_SumofElements1, vx_p);
  }

  /* End of Switch: '<S239>/Switch2' */

  /* UnaryMinus: '<S240>/Unary Minus1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  rtb_Saturation_fy = 35000.0;

  /* InitialCondition: '<S240>/IC' */
  if (rtDW.IC_FirstOutputTime) {
    rtDW.IC_FirstOutputTime = false;
    rtb_Saturation_fy = -35000.0;
  }

  /* End of InitialCondition: '<S240>/IC' */

  /* Abs: '<S243>/Abs' incorporates:
   *  Abs: '<S242>/Abs'
   *  Inport: '<Root>/steering'
   */
  tmp_0 = fabs(rtU.steering);

  /* Switch: '<S243>/Switch' incorporates:
   *  Abs: '<S243>/Abs'
   *  Constant: '<S243>/Constant'
   *  Constant: '<S243>/Constant1'
   */
  if (tmp_0 > 0.087266462599716474) {
    rtb_UnaryMinus_pe = 0.0;
  } else {
    rtb_UnaryMinus_pe = 40.0;
  }

  /* End of Switch: '<S243>/Switch' */

  /* UnitDelay: '<S151>/Unit Delay1' */
  rtb_Driving[0] = rtDW.UnitDelay1_DSTATE[0];
  rtb_Driving[1] = rtDW.UnitDelay1_DSTATE[1];
  rtb_Driving[2] = rtDW.UnitDelay1_DSTATE[2];
  rtb_Driving[3] = rtDW.UnitDelay1_DSTATE[3];

  /* MATLAB Function: '<S151>/MATLAB Function4' incorporates:
   *  UnitDelay: '<S151>/Unit Delay'
   *  UnitDelay: '<S151>/Unit Delay2'
   */
  rtb_fl_c = (((0.765 * sin(rtDW.UnitDelay2_DSTATE[0]) - 0.635 * cos
                (rtDW.UnitDelay2_DSTATE[0])) * rtb_Driving[0] + (0.765 * sin
    (rtDW.UnitDelay2_DSTATE[1]) + 0.635 * cos(rtDW.UnitDelay2_DSTATE[1])) *
               rtDW.UnitDelay_DSTATE_a[1]) - 0.635 * rtb_Driving[2]) + 0.635 *
    rtDW.UnitDelay_DSTATE_a[3];

  /* SignalConversion generated from: '<S172>/ SFunction ' incorporates:
   *  MATLAB Function: '<S151>/MATLAB Function2'
   */
  rtb_Driving[0] = rtb_Switch;
  rtb_Driving[1] = rtb_Switch_h;
  rtb_Driving[2] = rtb_RL;
  rtb_Driving[3] = rtb_RR;

  /* MATLAB Function: '<S151>/MATLAB Function2' incorporates:
   *  Constant: '<S151>/Constant'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/vy'
   *  Sum: '<S175>/Sum1'
   *  Sum: '<S175>/Sum2'
   */
  rtb_RR = rtb_rr_l * 3.14825;
  rtb_Product1_idx_0 = rtb_Gain1 * 1.27 / 2.0;
  vx = rtb_Gain1 * 0.73439999999999994 + rtU.vy;
  rtb_Tnew_idx_2 = rtb_vx - rtb_Product1_idx_0;
  rtb_fr_a = atan(vx / rtb_Tnew_idx_2) - rtb_rr;
  rtb_Tnew_idx_3 = rtb_Product1_idx_0 + rtb_vx;
  rtb_rl_d = atan(vx / rtb_Tnew_idx_3) - rtb_rr;
  rtb_Switch_h = rtU.vy - rtb_Gain1 * 0.79560000000000008;
  rtb_Switch = atan(rtb_Switch_h / rtb_Tnew_idx_2);
  rtb_Switch_h = atan(rtb_Switch_h / rtb_Tnew_idx_3);
  vx = 0.5 * rtb_RR * 0.55490196078431375;
  rtb_RL = rtb_rr_l * 1.0461500000000001 * 0.5 / 1.53 * 0.576;
  rtb_Tnew_idx_3 = (((635.688 - 30.826771653543307 * rtU.ay) + vx) - rtb_RL) -
    25.588235294117645 * rtU.ax;
  rtb_rr_l = (((30.826771653543307 * rtU.ay + 635.688) + vx) - rtb_RL) -
    25.588235294117645 * rtU.ax;
  rtb_Tnew_idx_2 = 0.5 * rtb_RR * 0.4450980392156863;
  rtb_RR = (((688.66200000000015 - 30.826771653543307 * rtU.ay) + rtb_Tnew_idx_2)
            + rtb_RL) + 25.588235294117645 * rtU.ax;
  rtb_RL = (((30.826771653543307 * rtU.ay + 688.66200000000015) + rtb_Tnew_idx_2)
            + rtb_RL) + 25.588235294117645 * rtU.ax;
  Faeroz_tmp = 12.4 * rtb_fr_a - 0.512;
  rtb_Tnew_idx_2 = (1.14E-6 * rtb_Tnew_idx_3 - rtb_fr_a) + 0.00239;
  if (rtb_Tnew_idx_2 < 0.0) {
    rtb_Tnew_idx_1 = -1.0;
  } else if (rtb_Tnew_idx_2 > 0.0) {
    rtb_Tnew_idx_1 = 1.0;
  } else if (rtb_Tnew_idx_2 == 0.0) {
    rtb_Tnew_idx_1 = 0.0;
  } else {
    rtb_Tnew_idx_1 = (rtNaN);
  }

  vx = 0.000282 * rtb_Tnew_idx_3 - 2.02;
  rtb_Product1_idx_0 = sin(atan(0.000559 * rtb_Tnew_idx_3) * 2.0) * 34500.0 *
    rtb_Tnew_idx_2 / (1.34 * rtb_Tnew_idx_3 * 0.8 * vx - 0.01);
  rtb_Tnew_idx_2 = 0.0013 * rtb_Tnew_idx_3 - 2.33;
  rtb_fr_k_tmp_tmp = sqrt(Faeroz_tmp * Faeroz_tmp + 1.0);
  rtb_fr_k_tmp = (3.86E-7 * rtb_Tnew_idx_3 + 0.000205) * 13.9 / rtb_fr_k_tmp_tmp;
  rtb_fr_a = (sin(atan(rtb_Product1_idx_0 - (0.26 * rtb_Tnew_idx_1 + 1.0) *
                       (3.99E-5 * rtb_Tnew_idx_3 - 0.521) * (atan
    (rtb_Product1_idx_0) - rtb_Product1_idx_0)) * 1.34) * (rtb_Tnew_idx_3 * 0.8)
              * vx + (7.1E-5 * rtb_Tnew_idx_3 - 0.149) * (rtb_Tnew_idx_3 * 0.8))
    * cos(atan((atan(((3.86E-7 * rtb_Tnew_idx_3 - rtb_Driving[0]) + 0.000205) *
                     13.9 / rtb_fr_k_tmp_tmp) - ((3.86E-7 * rtb_Tnew_idx_3 -
              rtb_Driving[0]) + 0.000205) * 13.9 / sqrt(Faeroz_tmp * Faeroz_tmp
             + 1.0)) * rtb_Tnew_idx_2 + ((3.86E-7 * rtb_Tnew_idx_3 -
             rtb_Driving[0]) + 0.000205) * 13.9 / sqrt(Faeroz_tmp * Faeroz_tmp +
            1.0)) * 0.958) / cos(atan((atan(rtb_fr_k_tmp) - rtb_fr_k_tmp) *
    rtb_Tnew_idx_2 + rtb_fr_k_tmp) * 0.958) - sin(atan(16.1 * rtb_Driving[0]) *
    1.94) * (rtb_Tnew_idx_3 * 0.8) * vx * (1.03E-5 * rtb_Tnew_idx_3 - 0.000288) /
    sqrt(rtb_fr_a * rtb_fr_a * 225.0 + 1.0);
  vx = 12.4 * rtb_rl_d - 0.512;
  rtb_Tnew_idx_2 = (1.14E-6 * rtb_rr_l - rtb_rl_d) + 0.00239;
  if (rtb_Tnew_idx_2 < 0.0) {
    rtb_Tnew_idx_1 = -1.0;
  } else if (rtb_Tnew_idx_2 > 0.0) {
    rtb_Tnew_idx_1 = 1.0;
  } else if (rtb_Tnew_idx_2 == 0.0) {
    rtb_Tnew_idx_1 = 0.0;
  } else {
    rtb_Tnew_idx_1 = (rtNaN);
  }

  rtb_Product1_idx_0 = 0.000282 * rtb_rr_l - 2.02;
  rtb_Tnew_idx_3 = sin(atan(0.000559 * rtb_rr_l) * 2.0) * 34500.0 *
    rtb_Tnew_idx_2 / (1.34 * rtb_rr_l * 0.8 * rtb_Product1_idx_0 - 0.01);
  Faeroz_tmp = 0.0013 * rtb_rr_l - 2.33;
  rtb_Tnew_idx_2 = sqrt(vx * vx + 1.0);
  rtb_fr_k_tmp_tmp = (3.86E-7 * rtb_rr_l + 0.000205) * 13.9 / rtb_Tnew_idx_2;
  rtb_rl_d = (sin(atan(rtb_Tnew_idx_3 - (0.26 * rtb_Tnew_idx_1 + 1.0) * (3.99E-5
    * rtb_rr_l - 0.521) * (atan(rtb_Tnew_idx_3) - rtb_Tnew_idx_3)) * 1.34) *
              (rtb_rr_l * 0.8) * rtb_Product1_idx_0 + (7.1E-5 * rtb_rr_l - 0.149)
              * (rtb_rr_l * 0.8)) * cos(atan((atan(((3.86E-7 * rtb_rr_l -
    rtb_Driving[1]) + 0.000205) * 13.9 / rtb_Tnew_idx_2) - ((3.86E-7 * rtb_rr_l
    - rtb_Driving[1]) + 0.000205) * 13.9 / sqrt(vx * vx + 1.0)) * Faeroz_tmp +
    ((3.86E-7 * rtb_rr_l - rtb_Driving[1]) + 0.000205) * 13.9 / sqrt(vx * vx +
    1.0)) * 0.958) / cos(atan((atan(rtb_fr_k_tmp_tmp) - rtb_fr_k_tmp_tmp) *
    Faeroz_tmp + rtb_fr_k_tmp_tmp) * 0.958) - sin(atan(16.1 * rtb_Driving[1]) *
    1.94) * (rtb_rr_l * 0.8) * rtb_Product1_idx_0 * (1.03E-5 * rtb_rr_l -
    0.000288) / sqrt(rtb_rl_d * rtb_rl_d * 225.0 + 1.0);
  rtb_Tnew_idx_3 = 12.4 * rtb_Switch - 0.512;
  vx = 12.4 * rtb_Switch_h - 0.512;
  rtb_Tnew_idx_2 = (1.14E-6 * rtb_RR - rtb_Switch) + 0.00239;
  rtb_rr_l = (1.14E-6 * rtb_RL - rtb_Switch_h) + 0.00239;
  if (rtb_Tnew_idx_2 < 0.0) {
    rtb_Tnew_idx_1 = -1.0;
  } else if (rtb_Tnew_idx_2 > 0.0) {
    rtb_Tnew_idx_1 = 1.0;
  } else if (rtb_Tnew_idx_2 == 0.0) {
    rtb_Tnew_idx_1 = 0.0;
  } else {
    rtb_Tnew_idx_1 = (rtNaN);
  }

  if (rtb_rr_l < 0.0) {
    rtb_Product1_idx_0 = -1.0;
  } else if (rtb_rr_l > 0.0) {
    rtb_Product1_idx_0 = 1.0;
  } else if (rtb_rr_l == 0.0) {
    rtb_Product1_idx_0 = 0.0;
  } else {
    rtb_Product1_idx_0 = (rtNaN);
  }

  Faeroz_tmp = 0.000282 * rtb_RR - 2.02;
  rtb_Tnew_idx_2 = sin(atan(0.000559 * rtb_RR) * 2.0) * 34500.0 * rtb_Tnew_idx_2
    / (1.34 * rtb_RR * 0.8 * Faeroz_tmp - 0.01);
  rtb_fr_k_tmp_tmp = 0.0013 * rtb_RR - 2.33;
  rtb_fr_k_tmp = 0.000282 * rtb_RL - 2.02;
  rtb_RR_tmp = sin(atan(0.000559 * rtb_RL) * 2.0) * 34500.0 * rtb_rr_l / (1.34 *
    rtb_RL * 0.8 * rtb_fr_k_tmp - 0.01);
  rtb_RR_tmp_0 = 0.0013 * rtb_RL - 2.33;
  rtb_rr_l = rtb_Integrator_b - rtb_Gain1;
  rtb_RR_tmp_tmp = sqrt(rtb_Tnew_idx_3 * rtb_Tnew_idx_3 + 1.0);
  rtb_RR_tmp_1 = (3.86E-7 * rtb_RR + 0.000205) * 13.9 / rtb_RR_tmp_tmp;
  rtb_RR_tmp_tmp_0 = sqrt(vx * vx + 1.0);
  rtb_RR_tmp_2 = (3.86E-7 * rtb_RL + 0.000205) * 13.9 / rtb_RR_tmp_tmp_0;
  rtb_RR = rtb_rr_l / 0.1 * 180.0 - (((rtb_fr_a + rtb_rl_d) * cos(rtb_rr) *
    0.73439999999999994 - (((sin(atan(rtb_Tnew_idx_2 - (0.26 * rtb_Tnew_idx_1 +
    1.0) * (3.99E-5 * rtb_RR - 0.521) * (atan(rtb_Tnew_idx_2) - rtb_Tnew_idx_2))
    * 1.34) * (rtb_RR * 0.8) * Faeroz_tmp + (7.1E-5 * rtb_RR - 0.149) * (rtb_RR *
    0.8)) * cos(atan((atan(((3.86E-7 * rtb_RR - rtb_Driving[2]) + 0.000205) *
    13.9 / rtb_RR_tmp_tmp) - ((3.86E-7 * rtb_RR - rtb_Driving[2]) + 0.000205) *
                      13.9 / sqrt(rtb_Tnew_idx_3 * rtb_Tnew_idx_3 + 1.0)) *
                     rtb_fr_k_tmp_tmp + ((3.86E-7 * rtb_RR - rtb_Driving[2]) +
    0.000205) * 13.9 / sqrt(rtb_Tnew_idx_3 * rtb_Tnew_idx_3 + 1.0)) * 0.958) /
    cos(atan((atan(rtb_RR_tmp_1) - rtb_RR_tmp_1) * rtb_fr_k_tmp_tmp +
             rtb_RR_tmp_1) * 0.958) - sin(atan(16.1 * rtb_Driving[2]) * 1.94) *
    (rtb_RR * 0.8) * Faeroz_tmp * (1.03E-5 * rtb_RR - 0.000288) / sqrt
    (rtb_Switch * rtb_Switch * 225.0 + 1.0)) + ((sin(atan(rtb_RR_tmp - (0.26 *
    rtb_Product1_idx_0 + 1.0) * (3.99E-5 * rtb_RL - 0.521) * (atan(rtb_RR_tmp) -
    rtb_RR_tmp)) * 1.34) * (rtb_RL * 0.8) * rtb_fr_k_tmp + (7.1E-5 * rtb_RL -
    0.149) * (rtb_RL * 0.8)) * cos(atan((atan(((3.86E-7 * rtb_RL - rtb_Driving[3])
    + 0.000205) * 13.9 / rtb_RR_tmp_tmp_0) - ((3.86E-7 * rtb_RL - rtb_Driving[3])
    + 0.000205) * 13.9 / sqrt(vx * vx + 1.0)) * rtb_RR_tmp_0 + ((3.86E-7 *
    rtb_RL - rtb_Driving[3]) + 0.000205) * 13.9 / sqrt(vx * vx + 1.0)) * 0.958) /
    cos(atan((atan(rtb_RR_tmp_2) - rtb_RR_tmp_2) * rtb_RR_tmp_0 + rtb_RR_tmp_2) *
        0.958) - sin(atan(16.1 * rtb_Driving[3]) * 1.94) * (rtb_RL * 0.8) *
    rtb_fr_k_tmp * (1.03E-5 * rtb_RL - 0.000288) / sqrt(rtb_Switch_h *
    rtb_Switch_h * 225.0 + 1.0))) * 0.79560000000000008) + -(rtb_rl_d - rtb_fr_a)
    * sin(rtb_rr) * 1.27 / 2.0);
  if (rtIsNaN(rtb_RR)) {
    rtb_RR = 0.0;
  }

  /* InitialCondition: '<S151>/IC' incorporates:
   *  Logic: '<S151>/NOT1'
   */
  if (rtDW.IC_FirstOutputTime_k) {
    rtDW.IC_FirstOutputTime_k = false;
    rtb_Logic_p_idx_1 = true;
  } else {
    rtb_Logic_p_idx_1 = !rtb_Logic_l_idx_1;
  }

  /* End of InitialCondition: '<S151>/IC' */

  /* DiscreteIntegrator: '<S214>/Integrator' */
  if (rtb_Logic_p_idx_1 || (rtDW.Integrator_PrevResetState_h != 0)) {
    rtDW.Integrator_DSTATE_ek = 0.0;
  }

  /* DiscreteIntegrator: '<S209>/Filter' */
  if (rtb_Logic_p_idx_1 || (rtDW.Filter_PrevResetState_m != 0)) {
    rtDW.Filter_DSTATE_g = 0.0;
  }

  /* Product: '<S217>/NProd Out' incorporates:
   *  Constant: '<S151>/Constant11'
   *  Constant: '<S151>/Constant13'
   *  Constant: '<S151>/Constant14'
   *  DiscreteIntegrator: '<S209>/Filter'
   *  Product: '<S208>/DProd Out'
   *  Product: '<S231>/cProd Out'
   *  Sum: '<S175>/Sum3'
   *  Sum: '<S209>/SumD'
   */
  rtb_rr = ((rtb_Integrator_b * 0.0 - rtb_Gain1) * 0.0 - rtDW.Filter_DSTATE_g) *
    3.0;

  /* Sum: '<S224>/Sum' incorporates:
   *  Constant: '<S151>/Constant12'
   *  DiscreteIntegrator: '<S214>/Integrator'
   *  Product: '<S219>/PProd Out'
   */
  rtb_Switch_h = (rtb_rr_l * 0.0 + rtDW.Integrator_DSTATE_ek) + rtb_rr;

  /* Switch: '<S222>/Switch2' incorporates:
   *  Constant: '<S151>/Constant10'
   *  Constant: '<S151>/Constant9'
   *  RelationalOperator: '<S222>/LowerRelop1'
   *  RelationalOperator: '<S222>/UpperRelop'
   *  Switch: '<S222>/Switch'
   */
  if (rtb_Switch_h > 50.0) {
    rtb_Switch = 50.0;
  } else if (rtb_Switch_h < -50.0) {
    /* Switch: '<S222>/Switch' incorporates:
     *  Constant: '<S151>/Constant10'
     */
    rtb_Switch = -50.0;
  } else {
    rtb_Switch = rtb_Switch_h;
  }

  /* End of Switch: '<S222>/Switch2' */

  /* Sum: '<S151>/Sum1' incorporates:
   *  Gain: '<S151>/Gain2'
   */
  rtb_Product1_idx_0 = 0.017407407407407406 * rtb_RR + rtb_Switch;

  /* Saturate: '<S151>/Saturation' */
  if (rtb_Product1_idx_0 > 15.0) {
    rtb_Product1_idx_0 = 15.0;
  } else if (rtb_Product1_idx_0 < -15.0) {
    rtb_Product1_idx_0 = -15.0;
  }

  /* End of Saturate: '<S151>/Saturation' */

  /* Product: '<S151>/Product' */
  rtb_RR = rtb_Product1_idx_0 * (real_T)rtb_Logic_l_idx_1;

  /* UnitDelay: '<S151>/Unit Delay5' */
  rtb_Driving[0] = rtDW.UnitDelay5_DSTATE[0];
  rtb_Driving[1] = rtDW.UnitDelay5_DSTATE[1];
  rtb_Driving[2] = rtDW.UnitDelay5_DSTATE[2];
  rtb_Driving[3] = rtDW.UnitDelay5_DSTATE[3];

  /* MATLAB Function: '<S151>/MATLAB Function3' incorporates:
   *  UnitDelay: '<S151>/Unit Delay3'
   *  UnitDelay: '<S151>/Unit Delay4'
   */
  rtb_RL = (((0.765 * sin(rtDW.UnitDelay4_DSTATE[0]) - 0.635 * cos
              (rtDW.UnitDelay4_DSTATE[0])) * rtDW.UnitDelay3_DSTATE[0] + (0.765 *
              sin(rtDW.UnitDelay4_DSTATE[1]) + 0.635 * cos
              (rtDW.UnitDelay4_DSTATE[1])) * rtb_Driving[1]) - 0.635 *
            rtDW.UnitDelay3_DSTATE[2]) + 0.635 * rtb_Driving[3];

  /* Switch: '<S176>/Switch2' incorporates:
   *  RelationalOperator: '<S176>/LowerRelop1'
   */
  if (!(rtb_RR > rtb_fl_c)) {
    /* Switch: '<S176>/Switch' incorporates:
     *  RelationalOperator: '<S176>/UpperRelop'
     */
    if (rtb_RR < rtb_RL) {
      rtb_fl_c = rtb_RL;
    } else {
      rtb_fl_c = rtb_RR;
    }

    /* End of Switch: '<S176>/Switch' */
  }

  /* End of Switch: '<S176>/Switch2' */

  /* MATLAB Function: '<S151>/MATLAB Function1' */
  guard1 = false;
  if (rtb_fl_c < 0.0) {
    guard1 = true;
  } else if (rtb_fl_c > 0.0) {
    rtb_RR = rtb_fl_c * 0.25;
    rtb_fl_c *= 1.1;
  } else {
    if (rtb_fl_c == 0.0) {
    }

    guard1 = true;
  }

  if (guard1) {
    rtb_RR = rtb_fl_c * 1.1;
    rtb_fl_c *= 0.25;
  }

  /* End of MATLAB Function: '<S151>/MATLAB Function1' */

  /* SignalConversion generated from: '<S144>/C Caller' */
  rtb_lg[0] = rtb_Switch_g;

  /* Product: '<S240>/Divide1' incorporates:
   *  Constant: '<S240>/Constant'
   */
  rtb_Product1_idx_0 = 0.001 * rtb_Saturation_fy;

  /* Saturate: '<S240>/Saturation' */
  if (rtb_Product1_idx_0 > 0.0) {
    /* SignalConversion generated from: '<S144>/C Caller' */
    rtb_lg[1] = 0.0;
  } else {
    /* SignalConversion generated from: '<S144>/C Caller' */
    rtb_lg[1] = rtb_Product1_idx_0;
  }

  /* End of Saturate: '<S240>/Saturation' */

  /* SignalConversion generated from: '<S144>/C Caller' incorporates:
   *  UnaryMinus: '<S243>/Unary Minus'
   */
  rtb_lg[2] = -rtb_UnaryMinus_pe;
  rtb_lg[3] = -rtb_UnaryMinus_pe;
  rtb_lg[4] = rtb_RR;

  /* InitialCondition: '<S241>/IC1' */
  rtDW.IC1_FirstOutputTime = false;

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/Constant'
   *  Constant: '<S242>/Constant1'
   */
  if (tmp_0 > 0.087266462599716474) {
    rtb_Switch_g = 0.0;
  } else {
    rtb_Switch_g = 40.0;
  }

  /* End of Switch: '<S242>/Switch' */

  /* MATLAB Function: '<S156>/MATLAB Function' incorporates:
   *  Constant: '<S156>/Constant'
   *  Constant: '<S156>/Constant1'
   *  Constant: '<S156>/Constant2'
   *  Constant: '<S156>/r1'
   *  Constant: '<S156>/vx'
   *  Constant: '<S156>/vy'
   *  SignalConversion generated from: '<S275>/ SFunction '
   */
  rtb_X1[0] = 0.0;
  rtb_X1[1] = 0.0;
  rtb_X1[2] = 0.0;
  rtb_X1[3] = 0.0;
  rtb_X1[4] = 0.0;
  rtb_X1[5] = 0.0;
  rtb_X1[6] = 0.0;
  memset(&varargin_1[0], 0, 49U * sizeof(real_T));
  for (b_exit = 0; b_exit < 7; b_exit++) {
    varargin_1[b_exit + 7 * b_exit] = rtb_X1[b_exit];
  }

  memset(&varargin_2[0], 0, sizeof(real_T) << 4U);
  varargin_2[0] = 0.03;
  varargin_2[5] = 0.03;
  varargin_2[10] = 0.03;
  varargin_2[15] = 0.03;
  memset(&rtb_y_c[0], 0, 121U * sizeof(real_T));
  for (i = 0; i < 7; i++) {
    for (b_exit = 0; b_exit < 7; b_exit++) {
      rtb_y_c[b_exit + 11 * i] = varargin_1[7 * i + b_exit];
    }
  }

  for (i = 0; i < 4; i++) {
    int32_T rtb_y_g_tmp;
    b_exit = i << 2;
    rtb_y_g_tmp = (i + 7) * 11;
    rtb_y_c[rtb_y_g_tmp + 7] = varargin_2[b_exit];
    rtb_y_c[rtb_y_g_tmp + 8] = varargin_2[b_exit + 1];
    rtb_y_c[rtb_y_g_tmp + 9] = varargin_2[b_exit + 2];
    rtb_y_c[rtb_y_g_tmp + 10] = varargin_2[b_exit + 3];
  }

  rtb_y_c[58] = -1.0;
  rtb_y_c[38] = -1.0;
  rtb_y_c[70] = -1.0;
  rtb_y_c[50] = -1.0;
  for (i = 0; i < 121; i++) {
    rtb_y_c[i] *= 50.0;
  }

  /* End of MATLAB Function: '<S156>/MATLAB Function' */

  /* Gain: '<S246>/Gain2' incorporates:
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_Product1_idx_0 = 13.5 * rtU.omega_wheels_FL;

  /* Saturate: '<S246>/Saturation' */
  if (rtb_Product1_idx_0 > 2083.9231268812296) {
    rtb_Driving[0] = 2083.9231268812296;
  } else if (rtb_Product1_idx_0 < 10.471975511965978) {
    rtb_Driving[0] = 10.471975511965978;
  } else {
    rtb_Driving[0] = rtb_Product1_idx_0;
  }

  /* Gain: '<S246>/Gain2' incorporates:
   *  Inport: '<Root>/omega_wheels_FR'
   */
  rtb_Product1_idx_0 = 13.5 * rtU.omega_wheels_FR;

  /* Saturate: '<S246>/Saturation' */
  if (rtb_Product1_idx_0 > 2083.9231268812296) {
    rtb_Driving[1] = 2083.9231268812296;
  } else if (rtb_Product1_idx_0 < 10.471975511965978) {
    rtb_Driving[1] = 10.471975511965978;
  } else {
    rtb_Driving[1] = rtb_Product1_idx_0;
  }

  /* Gain: '<S246>/Gain2' incorporates:
   *  Inport: '<Root>/omega_wheels_RL'
   */
  rtb_Product1_idx_0 = 13.5 * rtU.omega_wheels_RL;

  /* Saturate: '<S246>/Saturation' */
  if (rtb_Product1_idx_0 > 2083.9231268812296) {
    rtb_Driving[2] = 2083.9231268812296;
  } else if (rtb_Product1_idx_0 < 10.471975511965978) {
    rtb_Driving[2] = 10.471975511965978;
  } else {
    rtb_Driving[2] = rtb_Product1_idx_0;
  }

  /* Gain: '<S246>/Gain2' incorporates:
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_Product1_idx_0 = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S246>/Saturation' */
  if (rtb_Product1_idx_0 > 2083.9231268812296) {
    rtb_Driving[3] = 2083.9231268812296;
  } else if (rtb_Product1_idx_0 < 10.471975511965978) {
    rtb_Driving[3] = 10.471975511965978;
  } else {
    rtb_Driving[3] = rtb_Product1_idx_0;
  }

  /* Abs: '<S248>/Abs' */
  rtb_rl_d = fabs(rtb_T_ff_slip_g[0]);
  rtb_Tnew_idx_1 = fabs(rtb_T_ff_slip_g[1]);
  rtb_Tnew_idx_2 = fabs(rtb_T_ff_slip_g[2]);
  rtb_Tnew_idx_3 = fabs(rtb_T_ff_slip_g[3]);

  /* Lookup_n-D: '<S248>/2-D Lookup Table' */
  rtb_Driving[0] = look2_binlx(rtb_Driving[0], rtb_rl_d, rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled68, 200U);
  rtb_Driving[1] = look2_binlx(rtb_Driving[1], rtb_Tnew_idx_1, rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled68, 200U);
  rtb_Driving[2] = look2_binlx(rtb_Driving[2], rtb_Tnew_idx_2, rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled68, 200U);
  rtb_Driving[3] = look2_binlx(rtb_Driving[3], rtb_Tnew_idx_3, rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled68, 200U);

  /* Saturate: '<S248>/Saturation' */
  rtb_Product1_idx_0 = rtb_Driving[0];
  if (rtb_Product1_idx_0 > 1.0) {
    rtb_Driving[0] = 1.0;
  } else if (rtb_Product1_idx_0 < 0.3) {
    rtb_Driving[0] = 0.3;
  } else {
    rtb_Driving[0] = rtb_Product1_idx_0;
  }

  rtb_Product1_idx_0 = rtb_Driving[1];
  if (rtb_Product1_idx_0 > 1.0) {
    rtb_Driving[1] = 1.0;
  } else if (rtb_Product1_idx_0 < 0.3) {
    rtb_Driving[1] = 0.3;
  } else {
    rtb_Driving[1] = rtb_Product1_idx_0;
  }

  rtb_Product1_idx_0 = rtb_Driving[2];
  if (rtb_Product1_idx_0 > 1.0) {
    rtb_Driving[2] = 1.0;
  } else if (rtb_Product1_idx_0 < 0.3) {
    rtb_Driving[2] = 0.3;
  } else {
    rtb_Driving[2] = rtb_Product1_idx_0;
  }

  rtb_Product1_idx_0 = rtb_Driving[3];
  if (rtb_Product1_idx_0 > 1.0) {
    rtb_Driving[3] = 1.0;
  } else if (rtb_Product1_idx_0 < 0.3) {
    rtb_Driving[3] = 0.3;
  } else {
    rtb_Driving[3] = rtb_Product1_idx_0;
  }

  /* End of Saturate: '<S248>/Saturation' */

  /* Switch: '<S246>/Switch3' incorporates:
   *  Gain: '<S246>/     '
   *  Gain: '<S246>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    tmp_0 = 0.96 * rtb_Driving[0];
  } else {
    tmp_0 = 1.0416666666666667 * rtb_Driving[0];
  }

  if (rtU.omega_wheels_FR > 0.0) {
    rtb_Integrator_b = 0.96 * rtb_Driving[1];
  } else {
    rtb_Integrator_b = 1.0416666666666667 * rtb_Driving[1];
  }

  if (rtU.omega_wheels_RL > 0.0) {
    rtb_RR = 0.96 * rtb_Driving[2];
  } else {
    rtb_RR = 1.0416666666666667 * rtb_Driving[2];
  }

  if (rtU.omega_wheels_RR > 0.0) {
    rtb_RL = 0.96 * rtb_Driving[3];
  } else {
    rtb_RL = 1.0416666666666667 * rtb_Driving[3];
  }

  /* End of Switch: '<S246>/Switch3' */

  /* Saturate: '<S148>/Saturation' */
  if (rtb_vx <= 2.0) {
    /* CCaller: '<S144>/C Caller' */
    rtb_X1[0] = 2.0;
  } else {
    /* CCaller: '<S144>/C Caller' */
    rtb_X1[0] = rtb_vx;
  }

  /* End of Saturate: '<S148>/Saturation' */

  /* Saturate: '<S148>/Saturation1' incorporates:
   *  Inport: '<Root>/vy'
   */
  if (rtU.vy > 5.0) {
    /* CCaller: '<S144>/C Caller' */
    rtb_X1[1] = 5.0;
  } else if (rtU.vy < -5.0) {
    /* CCaller: '<S144>/C Caller' */
    rtb_X1[1] = -5.0;
  } else {
    /* CCaller: '<S144>/C Caller' */
    rtb_X1[1] = rtU.vy;
  }

  /* End of Saturate: '<S148>/Saturation1' */

  /* Saturate: '<S148>/Saturation2' */
  if (rtb_Gain1 > 4.0) {
    /* CCaller: '<S144>/C Caller' */
    rtb_X1[2] = 4.0;
  } else if (rtb_Gain1 < -4.0) {
    /* CCaller: '<S144>/C Caller' */
    rtb_X1[2] = -4.0;
  } else {
    /* CCaller: '<S144>/C Caller' */
    rtb_X1[2] = rtb_Gain1;
  }

  /* End of Saturate: '<S148>/Saturation2' */

  /* CCaller: '<S144>/C Caller' incorporates:
   *  Abs: '<S246>/Abs'
   *  CFunction: '<S157>/C Function'
   *  CFunction: '<S251>/C Function'
   *  CFunction: '<S252>/C Function'
   *  Constant: '<S144>/Constant'
   *  Constant: '<S149>/Constant'
   *  Gain: '<S246>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  MATLAB Function: '<S153>/MATLAB Function'
   *  MinMax: '<S239>/Max'
   *  Product: '<S246>/Divide'
   *  SignalConversion generated from: '<S144>/C Caller'
   *  UnaryMinus: '<S149>/Unary Minus'
   * */
  rtb_X1[3] = rtb_T_ff_slip_g[0];
  rtb_X1[4] = rtb_T_ff_slip_g[1];
  rtb_X1[5] = rtb_T_ff_slip_g[2];
  rtb_X1[6] = rtb_T_ff_slip_g[3];
  memcpy(&rtb_CCaller_o3[0], &rtDW.CFunction[0], 26U * sizeof(real_T));
  rtb_Driving[0] = -10000.0;
  rtb_Driving[1] = -10000.0;
  rtb_Driving[2] = -10000.0;
  rtb_Driving[3] = -10000.0;
  rtb_T_ff_slip_g[0] = 10000.0;
  rtb_T_ff_slip_g[1] = 10000.0;
  rtb_T_ff_slip_g[2] = 10000.0;
  rtb_T_ff_slip_g[3] = 10000.0;
  rtb_Diff[0] = rtDW.CFunction_p[0];
  rtb_Diff[1] = rtDW.CFunction_p[1];
  rtb_Diff[2] = rtDW.CFunction_p[2];
  rtb_Diff[3] = rtDW.CFunction_p[3];
  rtb_UnaryMinus_e5[0] = rtDW.CFunction_a[0];
  rtb_UnaryMinus_e5[1] = rtDW.CFunction_a[1];
  rtb_UnaryMinus_e5[2] = rtDW.CFunction_a[2];
  rtb_UnaryMinus_e5[3] = rtDW.CFunction_a[3];
  rtb_CCaller_o10[0] = fmax(rtb_SumofElements1, vx_p);
  rtb_CCaller_o10[1] = 80.0;
  rtb_CCaller_o10[2] = rtb_Switch_g;
  rtb_CCaller_o10[3] = rtb_Switch_g;
  rtb_CCaller_o10[4] = rtb_fl_c;
  for (i = 0; i < 7; i++) {
    rtb_CCaller_o12[5 * i] = b[i];
  }

  rtb_CCaller_o12[1] = 0.0;
  rtb_CCaller_o12[6] = 0.0;
  rtb_CCaller_o12[11] = 0.0;
  rtb_CCaller_o12[16] = fabs(13.5 * rtU.omega_wheels_FL / tmp_0) / 1000.0;
  rtb_CCaller_o12[21] = fabs(13.5 * rtU.omega_wheels_FR / rtb_Integrator_b) /
    1000.0;
  rtb_CCaller_o12[26] = fabs(13.5 * rtU.omega_wheels_RL / rtb_RR) / 1000.0;
  rtb_CCaller_o12[31] = fabs(13.5 * rtU.omega_wheels_RR / rtb_RL) / 1000.0;
  for (i = 0; i < 7; i++) {
    rtb_CCaller_o12[5 * i + 2] = c[i];
  }

  for (i = 0; i < 7; i++) {
    rtb_CCaller_o12[5 * i + 3] = d[i];
  }

  rtb_CCaller_o12[4] = 0.0;
  rtb_CCaller_o12[9] = 0.0;
  rtb_CCaller_o12[14] = 0.0;
  rtb_CCaller_o12[19] = 0.765 * sin(rtb_Abs_m_idx_0) - 0.635 * cos
    (rtb_Abs_m_idx_0);
  rtb_CCaller_o12[24] = 0.765 * sin(rtb_Abs_g) + 0.635 * cos(rtb_Abs_g);
  rtb_CCaller_o12[29] = -0.635;
  rtb_CCaller_o12[34] = 0.635;
  rtb_Switch_g = 1.0;
  Acados_Caller_wrapper(&rtb_X1[0], &rtb_CCaller_o3[0], &rtb_Driving[0],
                        &rtb_T_ff_slip_g[0], &rtb_VectorConcatenate[0],
                        &rtb_Diff[0], &rtb_UnaryMinus_e5[0], &rtb_lg[0],
                        &rtb_CCaller_o10[0], &rtb_y_c[0], &rtb_CCaller_o12[0],
                        &rtb_Switch_g);

  /* DiscreteFir: '<S161>/Discrete FIR Filter' incorporates:
   *  Constant: '<S144>/Constant1'
   */
  rtb_UnaryMinus_pe = 0.0;
  for (b_exit = rtDW.DiscreteFIRFilter_circBuf; b_exit < 4; b_exit++) {
    rtb_UnaryMinus_pe += rtDW.DiscreteFIRFilter_states[b_exit];
  }

  for (b_exit = 0; b_exit < rtDW.DiscreteFIRFilter_circBuf; b_exit++) {
    rtb_UnaryMinus_pe += rtDW.DiscreteFIRFilter_states[b_exit];
  }

  /* End of DiscreteFir: '<S161>/Discrete FIR Filter' */

  /* Switch: '<S161>/Switch' */
  if ((rtb_vx > 3.0) && (!(rtb_UnaryMinus_pe >= 4.0))) {
    /* Outputs for IfAction SubSystem: '<S150>/MPC' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    /* If: '<S150>/If' incorporates:
     *  Inport: '<S158>/In1'
     *  Product: '<S150>/Divide'
     */
    rtb_rl_d = rtb_X1[3];
    rtb_Tnew_idx_1 = rtb_X1[4];
    rtb_Tnew_idx_2 = rtb_X1[5];
    rtb_Tnew_idx_3 = rtb_X1[6];

    /* End of Outputs for SubSystem: '<S150>/MPC' */
  } else {
    /* Outputs for IfAction SubSystem: '<S150>/Vectorino' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    /* If: '<S150>/If' incorporates:
     *  Constant: '<S169>/Constant2'
     *  Inport: '<Root>/throttle'
     *  Product: '<S150>/Divide'
     *  Product: '<S169>/Product'
     */
    rtb_rl_d = rtU.throttle * 6.3;
    rtb_Tnew_idx_1 = rtb_rl_d;
    rtb_Tnew_idx_2 = rtU.throttle * 21.0;
    rtb_Tnew_idx_3 = rtb_Tnew_idx_2;

    /* End of Outputs for SubSystem: '<S150>/Vectorino' */
  }

  /* End of Switch: '<S161>/Switch' */

  /* RelationalOperator: '<S150>/Less Than3' incorporates:
   *  DataStoreRead: '<S150>/Data Store General_Params1'
   *  Inport: '<Root>/brake'
   */
  rtb_Logic_l_idx_1 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S150>/Overlap Chart' incorporates:
   *  Inport: '<Root>/throttle'
   */
  if (rtDW.is_active_c13_TVModel == 0U) {
    rtDW.is_active_c13_TVModel = 1U;
    rtDW.is_c13_TVModel = IN_Go;
  } else if (rtDW.is_c13_TVModel == IN_Go) {
    if (rtb_Logic_l_idx_1) {
      rtDW.is_c13_TVModel = IN_Stop;
    }

    /* case IN_Stop: */
  } else if (((real_T)rtb_Logic_l_idx_1 <= 0.05) && (rtU.throttle < 0.05)) {
    rtDW.is_c13_TVModel = IN_Go;
  }

  /* End of Chart: '<S150>/Overlap Chart' */

  /* Switch: '<S207>/Switch' incorporates:
   *  Constant: '<S151>/Constant10'
   *  Constant: '<S151>/Constant9'
   *  RelationalOperator: '<S207>/u_GTE_up'
   *  RelationalOperator: '<S207>/u_GT_lo'
   *  Switch: '<S207>/Switch1'
   */
  if (rtb_Switch_h >= 50.0) {
    rtb_Gain1 = 50.0;
  } else if (rtb_Switch_h > -50.0) {
    /* Switch: '<S207>/Switch1' */
    rtb_Gain1 = rtb_Switch_h;
  } else {
    rtb_Gain1 = -50.0;
  }

  /* End of Switch: '<S207>/Switch' */

  /* Sum: '<S207>/Diff' */
  rtb_UnaryMinus_pe = rtb_Switch_h - rtb_Gain1;

  /* RelationalOperator: '<S204>/NotEqual' incorporates:
   *  Gain: '<S204>/ZeroGain'
   */
  rtb_Logic_l_idx_1 = (0.0 * rtb_Switch_h != rtb_UnaryMinus_pe);

  /* Signum: '<S204>/SignPreSat' */
  if (rtb_UnaryMinus_pe < 0.0) {
    rtb_vx = -1.0;
  } else if (rtb_UnaryMinus_pe > 0.0) {
    rtb_vx = 1.0;
  } else if (rtb_UnaryMinus_pe == 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = (rtNaN);
  }

  /* End of Signum: '<S204>/SignPreSat' */

  /* Sum: '<S227>/SumI1' incorporates:
   *  Constant: '<S151>/Const10ant15'
   *  Gain: '<S226>/Kt'
   *  Product: '<S211>/IProd Out'
   *  Sum: '<S226>/SumI3'
   */
  rtb_UnaryMinus_pe = (rtb_Switch - rtb_Switch) * 100.0 + rtb_rr_l * 5.0;

  /* Signum: '<S204>/SignPreIntegrator' */
  if (rtb_UnaryMinus_pe < 0.0) {
    rtb_Gain1 = -1.0;
  } else if (rtb_UnaryMinus_pe > 0.0) {
    rtb_Gain1 = 1.0;
  } else if (rtb_UnaryMinus_pe == 0.0) {
    rtb_Gain1 = 0.0;
  } else {
    rtb_Gain1 = (rtNaN);
  }

  /* End of Signum: '<S204>/SignPreIntegrator' */

  /* Switch: '<S204>/Switch' incorporates:
   *  Constant: '<S204>/Constant1'
   *  DataTypeConversion: '<S204>/DataTypeConv1'
   *  DataTypeConversion: '<S204>/DataTypeConv2'
   *  Logic: '<S204>/AND3'
   *  RelationalOperator: '<S204>/Equal1'
   */
  if (rtb_Logic_l_idx_1 && ((int8_T)rtb_vx == (int8_T)rtb_Gain1)) {
    rtb_Gain1 = 0.0;
  } else {
    rtb_Gain1 = rtb_UnaryMinus_pe;
  }

  /* End of Switch: '<S204>/Switch' */

  /* Chart: '<S151>/Chart' */
  rtDW.chartGlobalTickCounter++;
  rtb_Logic_l_idx_1 = (rtDW.is_c24_TVModel == 3);
  if ((!rtb_Logic_l_idx_1) || (!rtDW.countCondWasTrueAtLastTimeStep_)) {
    rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
  }

  rtDW.countCondWasTrueAtLastTimeStep_ = rtb_Logic_l_idx_1;
  if (rtDW.is_active_c24_TVModel == 0U) {
    rtDW.chartGlobalTickCounter = 0;
    rtDW.is_active_c24_TVModel = 1U;
    rtDW.is_c24_TVModel = IN_OFF_c;
    rtDW.mz_output = 0.0;
  } else {
    switch (rtDW.is_c24_TVModel) {
     case IN_OFF_c:
      rtDW.mz_output = 0.0;
      break;

     case IN_ON_n:
      rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
      rtDW.is_c24_TVModel = IN_SWITCHING_FILTER_p;
      rtDW.mz_output *= mz_filter_tau;
      rtDW.countCondWasTrueAtLastTimeStep_ = (rtDW.is_c24_TVModel == 3);
      break;

     default:
      /* case IN_SWITCHING_FILTER: */
      rtb_Logic_l_idx_1 = (rtDW.is_c24_TVModel == 3);
      if ((!rtb_Logic_l_idx_1) || (!rtDW.countCondWasTrueAtLastTimeStep_)) {
        rtDW.countReferenceTick_1 = rtDW.chartGlobalTickCounter;
      }

      rtDW.countCondWasTrueAtLastTimeStep_ = rtb_Logic_l_idx_1;
      if (rtDW.chartGlobalTickCounter - rtDW.countReferenceTick_1 > 10) {
        rtDW.is_c24_TVModel = IN_OFF_c;
        rtDW.mz_output = 0.0;
      } else {
        rtDW.mz_output *= mz_filter_tau;
      }
      break;
    }
  }

  /* End of Chart: '<S151>/Chart' */

  /* RelationalOperator: '<S281>/Less Than' incorporates:
   *  DataStoreRead: '<S281>/Data Store General_Params'
   *  Inport: '<Root>/brake'
   */
  rtb_Logic_l_idx_1 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S281>/T_Req_Chart' incorporates:
   *  Inport: '<Root>/throttle'
   */
  if (rtDW.is_active_c21_TVModel == 0U) {
    rtDW.is_active_c21_TVModel = 1U;
    rtDW.is_c21_TVModel = IN_Throttle;
    rtb_Switch_g = 0.0;
  } else if (rtDW.is_c21_TVModel == IN_Brake) {
    rtb_Switch_g = 1.0;
    if ((!rtb_Logic_l_idx_1) && (rtU.throttle < 0.05)) {
      rtDW.is_c21_TVModel = IN_Throttle;
      rtb_Switch_g = 0.0;
    }
  } else {
    /* case IN_Throttle: */
    rtb_Switch_g = 0.0;
    if (rtb_Logic_l_idx_1) {
      rtDW.is_c21_TVModel = IN_Brake;
      rtb_Switch_g = 1.0;
    }
  }

  /* End of Chart: '<S281>/T_Req_Chart' */

  /* Switch: '<S281>/Switch' incorporates:
   *  DataStoreRead: '<S300>/Data Store General_Params1'
   *  Gain: '<S301>/Gain_Max_Torque_Needed'
   *  Inport: '<Root>/throttle'
   *  RelationalOperator: '<S300>/Less Than'
   *  Switch: '<S300>/Switch'
   */
  if (rtb_Switch_g > 0.0) {
    /* SignalConversion generated from: '<S301>/1-D Lookup Table' incorporates:
     *  Constant: '<S301>/Constant'
     *  DataStoreRead: '<S301>/Data Store Read'
     */
    fractions[0] = rtDW.General_Params.BrakeThresh;
    fractions[1] = 1.0;

    /* Lookup_n-D: '<S301>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/brake'
     */
    rtb_Product1_idx_0 = look1_binlx(rtU.brake, fractions,
      rtConstP.uDLookupTable_tableData, 1U);

    /* Saturate: '<S301>/Saturation_Brake' */
    if (rtb_Product1_idx_0 > 1.0) {
      rtb_Product1_idx_0 = 1.0;
    } else if (rtb_Product1_idx_0 < 0.0) {
      rtb_Product1_idx_0 = 0.0;
    }

    /* End of Saturate: '<S301>/Saturation_Brake' */
    vx = -529.2 * rtb_Product1_idx_0;
  } else if (rtU.throttle > rtDW.General_Params.ThrottleThresh) {
    /* SignalConversion generated from: '<S300>/T_nominal_wheel_LUT' incorporates:
     *  Constant: '<S300>/Constant1'
     *  Constant: '<S300>/Constant2'
     *  DataStoreRead: '<S300>/Data Store General_Params'
     */
    tmp[0] = 0.0;
    tmp[1] = rtDW.General_Params.ThrottleThresh;
    tmp[2] = 1.0;

    /* MultiPortSwitch: '<S300>/Map_Selector' incorporates:
     *  Inport: '<Root>/throttle'
     *  Lookup_n-D: '<S300>/T_peak_wheel_LUT'
     *  Switch: '<S300>/Switch'
     */
    vx = look1_binlx(rtU.throttle, tmp, rtConstP.T_peak_wheel_LUT_tableData, 2U);
  } else {
    /* Switch: '<S300>/Switch' incorporates:
     *  Constant: '<S300>/Constant'
     */
    vx = 0.0;
  }

  /* End of Switch: '<S281>/Switch' */

  /* MATLABSystem: '<S281>/Moving Average' */
  if (rtDW.obj_o.TunablePropsChanged) {
    rtDW.obj_o.TunablePropsChanged = false;
  }

  obj_0 = rtDW.obj_o.pStatistic;
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

  rtb_Switch_g = obj_0->pCumRevIndex;
  rtb_UnaryMinus_pe = obj_0->pCumSum;
  rtb_vx = obj_0->pCumSumRev[0];
  rtb_Switch = obj_0->pCumSumRev[1];
  rtb_Switch_h = obj_0->pCumSumRev[2];
  rtb_Integrator_b = obj_0->pCumSumRev[3];
  rtb_Driving[0] = rtb_vx;
  rtb_Driving[1] = rtb_Switch;
  rtb_Driving[2] = rtb_Switch_h;
  rtb_Driving[3] = rtb_Integrator_b;
  rtb_Saturation_fy = obj_0->pModValueRev;
  rtb_UnaryMinus_pe += vx;
  rtb_Driving[(int32_T)rtb_Switch_g - 1] = vx;
  if (rtb_Switch_g != 4.0) {
    rtb_Switch_g++;
  } else {
    rtb_Switch_g = 1.0;
    rtb_UnaryMinus_pe = 0.0;
    rtb_Driving[2] += rtb_Driving[3];
    rtb_Driving[1] += rtb_Driving[2];
    rtb_Driving[0] += rtb_Driving[1];
  }

  obj_0->pCumSum = rtb_UnaryMinus_pe;
  rtb_vx = rtb_Driving[0];
  rtb_Switch = rtb_Driving[1];
  rtb_Switch_h = rtb_Driving[2];
  rtb_Integrator_b = rtb_Driving[3];
  obj_0->pCumSumRev[0] = rtb_vx;
  obj_0->pCumSumRev[1] = rtb_Switch;
  obj_0->pCumSumRev[2] = rtb_Switch_h;
  obj_0->pCumSumRev[3] = rtb_Integrator_b;
  obj_0->pCumRevIndex = rtb_Switch_g;
  if (rtb_Saturation_fy > 0.0) {
    obj_0->pModValueRev = rtb_Saturation_fy - 1.0;
  } else {
    obj_0->pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S281>/Moving Average' */

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  rtDW.Integrator_PrevResetState = 0;

  /* Update for DiscreteIntegrator: '<S55>/Filter' */
  rtDW.Filter_PrevResetState = 0;

  /* Update for DiscreteIntegrator: '<S290>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S283>/1//T' incorporates:
   *  Constant: '<S285>/Time constant'
   *  MinMax: '<S285>/Max'
   */
  tmp_0 = 1.0 / fmax(rtDW.Probe[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S290>/Integrator' */
  rtDW.Integrator_PrevResetState_k = (int8_T)rtb_Compare;

  /* Update for DiscreteIntegrator: '<S299>/Integrator' */
  rtDW.Integrator_IC_LOADING_f = 0U;

  /* Product: '<S292>/1//T' incorporates:
   *  Constant: '<S294>/Time constant'
   *  MinMax: '<S294>/Max'
   */
  rtb_Integrator_b = 1.0 / fmax(rtDW.Probe_h[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S299>/Integrator' */
  rtDW.Integrator_PrevResetState_l = (int8_T)rtb_Compare_n;

  /* Update for Memory: '<S258>/Memory' */
  rtDW.Memory_PreviousInput_c = rtb_Logic_idx_0;

  /* Update for Memory: '<S259>/Memory' */
  rtDW.Memory_PreviousInput_p = rtb_Logic_l_idx_0;

  /* Update for Memory: '<S260>/Memory' */
  rtDW.Memory_PreviousInput_j = rtb_Logic_p_idx_0;

  /* Update for Memory: '<S261>/Memory' */
  rtDW.Memory_PreviousInput_k = rtb_Logic_o_idx_0;

  /* Update for Memory: '<S237>/Memory' */
  rtDW.Memory_PreviousInput_f = rtb_Logic_idx_1;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[0] = rtDW.UnitDelay_DSTATE_j[0];

  /* Update for UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[0] = rtb_Integrator_h_idx_0;

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  rtDW.Integrator_DSTATE[0] += 0.02 * rtb_Diff_i;

  /* Update for DiscreteIntegrator: '<S55>/Filter' */
  rtDW.Filter_DSTATE[0] += 0.02 * rtb_FilterCoefficient_idx_0;

  /* Update for UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_e[0] = rtb_Filter_n_idx_0;

  /* Update for DiscreteIntegrator: '<S123>/Integrator' */
  rtDW.Integrator_DSTATE_b[0] += 0.02 * rtb_T_ff_deceleration_bl;
  rtDW.Integrator_PrevResetState_f[0] = (int8_T)rtb_NOT_idx_0;

  /* Update for DiscreteIntegrator: '<S118>/Filter' incorporates:
   *  DiscreteIntegrator: '<S123>/Integrator'
   */
  rtDW.Filter_DSTATE_f[0] += 0.02 * rtb_fr;
  rtDW.Filter_PrevResetState_g[0] = (int8_T)rtb_NOT_idx_0;

  /* Update for Memory: '<S144>/Memory' incorporates:
   *  Product: '<S150>/Divide'
   */
  rtDW.Memory_PreviousInput[0] = rtb_rl_d;

  /* Update for DiscreteIntegrator: '<S290>/Integrator' incorporates:
   *  Product: '<S283>/1//T'
   *  Sum: '<S283>/Sum1'
   */
  rtDW.Integrator_DSTATE_e[0] += (rtb_IntegralGain_idx_0 - rtb_Saturation[0]) *
    tmp_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S299>/Integrator' incorporates:
   *  Product: '<S292>/1//T'
   *  Sum: '<S292>/Sum1'
   */
  rtDW.Integrator_DSTATE_i[0] += (rtb_Saturation_c_idx_0 -
    rtb_T_ff_deceleration_n[0]) * rtb_Integrator_b * 0.02;

  /* Update for Delay: '<S177>/Delay' */
  rtDW.Delay_DSTATE[0] = rtDW.Delay_DSTATE[1];

  /* Update for UnitDelay: '<S151>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_a[0] = rtDW.CFunction_a[0];

  /* Update for UnitDelay: '<S151>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[0] = rtDW.CFunction_p[0];

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[1] = rtDW.UnitDelay_DSTATE_j[1];

  /* Update for UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[1] = rtb_Integrator_h_idx_1;

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  rtDW.Integrator_DSTATE[1] += 0.02 * rtb_Diff_m;

  /* Update for DiscreteIntegrator: '<S55>/Filter' */
  rtDW.Filter_DSTATE[1] += 0.02 * rtb_FilterCoefficient_idx_1;

  /* Update for UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_e[1] = rtb_Filter_n_idx_1;

  /* Update for DiscreteIntegrator: '<S123>/Integrator' */
  rtDW.Integrator_DSTATE_b[1] += 0.02 * rtb_T_ff_deceleration_a;
  rtDW.Integrator_PrevResetState_f[1] = (int8_T)rtb_NOT_idx_1;

  /* Update for DiscreteIntegrator: '<S118>/Filter' incorporates:
   *  DiscreteIntegrator: '<S123>/Integrator'
   */
  rtDW.Filter_DSTATE_f[1] += 0.02 * rtb_rl;
  rtDW.Filter_PrevResetState_g[1] = (int8_T)rtb_NOT_idx_1;

  /* Update for Memory: '<S144>/Memory' incorporates:
   *  Product: '<S150>/Divide'
   */
  rtDW.Memory_PreviousInput[1] = rtb_Tnew_idx_1;

  /* Update for DiscreteIntegrator: '<S290>/Integrator' incorporates:
   *  Product: '<S283>/1//T'
   *  Sum: '<S283>/Sum1'
   */
  rtDW.Integrator_DSTATE_e[1] += (rtb_IntegralGain_idx_1 - rtb_Saturation[1]) *
    tmp_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S299>/Integrator' incorporates:
   *  Product: '<S292>/1//T'
   *  Sum: '<S292>/Sum1'
   */
  rtDW.Integrator_DSTATE_i[1] += (rtb_Saturation_c_idx_1 -
    rtb_T_ff_deceleration_n[1]) * rtb_Integrator_b * 0.02;

  /* Update for Delay: '<S177>/Delay' */
  rtDW.Delay_DSTATE[1] = rtDW.Delay_DSTATE[2];

  /* Update for UnitDelay: '<S151>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_a[1] = rtDW.CFunction_a[1];

  /* Update for UnitDelay: '<S151>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[1] = rtDW.CFunction_p[1];

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[2] = rtDW.UnitDelay_DSTATE_j[2];

  /* Update for UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[2] = rtb_Integrator_h_idx_2;

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  rtDW.Integrator_DSTATE[2] += 0.02 * rtb_Diff_p;

  /* Update for DiscreteIntegrator: '<S55>/Filter' */
  rtDW.Filter_DSTATE[2] += 0.02 * rtb_FilterCoefficient_idx_2;

  /* Update for UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_e[2] = rtb_Filter_n_idx_2;

  /* Update for DiscreteIntegrator: '<S123>/Integrator' */
  rtDW.Integrator_DSTATE_b[2] += 0.02 * rtb_T_ff_deceleration_p;
  rtDW.Integrator_PrevResetState_f[2] = (int8_T)rtb_NOT_idx_2;

  /* Update for DiscreteIntegrator: '<S118>/Filter' incorporates:
   *  DiscreteIntegrator: '<S123>/Integrator'
   */
  rtDW.Filter_DSTATE_f[2] += 0.02 * rtb_Integrator_k_idx_2;
  rtDW.Filter_PrevResetState_g[2] = (int8_T)rtb_NOT_idx_2;

  /* Update for Memory: '<S144>/Memory' incorporates:
   *  Product: '<S150>/Divide'
   */
  rtDW.Memory_PreviousInput[2] = rtb_Tnew_idx_2;

  /* Update for DiscreteIntegrator: '<S290>/Integrator' incorporates:
   *  Product: '<S283>/1//T'
   *  Sum: '<S283>/Sum1'
   */
  rtDW.Integrator_DSTATE_e[2] += (rtb_IntegralGain_idx_2 - rtb_Saturation[2]) *
    tmp_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S299>/Integrator' incorporates:
   *  Product: '<S292>/1//T'
   *  Sum: '<S292>/Sum1'
   */
  rtDW.Integrator_DSTATE_i[2] += (rtb_Saturation_c_idx_2 -
    rtb_T_ff_deceleration_n[2]) * rtb_Integrator_b * 0.02;

  /* Update for Delay: '<S177>/Delay' */
  rtDW.Delay_DSTATE[2] = rtDW.Delay_DSTATE[3];

  /* Update for UnitDelay: '<S151>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_a[2] = rtDW.CFunction_a[2];

  /* Update for UnitDelay: '<S151>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[2] = rtDW.CFunction_p[2];

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[3] = rtDW.UnitDelay_DSTATE_j[3];

  /* Update for UnitDelay: '<S18>/UD'
   *
   * Block description for '<S18>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE[3] = rtb_Integrator_g;

  /* Signum: '<S51>/SignPreSat' */
  if (rtb_IntegralGain_n < 0.0) {
    rtb_IntegralGain_idx_0 = -1.0;
  } else if (rtb_IntegralGain_n > 0.0) {
    rtb_IntegralGain_idx_0 = 1.0;
  } else if (rtb_IntegralGain_n == 0.0) {
    rtb_IntegralGain_idx_0 = 0.0;
  } else {
    rtb_IntegralGain_idx_0 = (rtNaN);
  }

  /* Signum: '<S51>/SignPreIntegrator' */
  if (rtb_Integrator_d < 0.0) {
    rtb_Integrator_h_idx_0 = -1.0;
  } else if (rtb_Integrator_d > 0.0) {
    rtb_Integrator_h_idx_0 = 1.0;
  } else if (rtb_Integrator_d == 0.0) {
    rtb_Integrator_h_idx_0 = 0.0;
  } else {
    rtb_Integrator_h_idx_0 = (rtNaN);
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant1'
   *  DataTypeConversion: '<S51>/DataTypeConv1'
   *  DataTypeConversion: '<S51>/DataTypeConv2'
   *  Gain: '<S51>/ZeroGain'
   *  Logic: '<S51>/AND3'
   *  RelationalOperator: '<S51>/Equal1'
   *  RelationalOperator: '<S51>/NotEqual'
   */
  if ((0.0 * rtb_IntegralGain != rtb_IntegralGain_n) && ((int8_T)
       rtb_IntegralGain_idx_0 == (int8_T)rtb_Integrator_h_idx_0)) {
    rtb_Integrator_d = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  rtDW.Integrator_DSTATE[3] += 0.02 * rtb_Integrator_d;

  /* Update for DiscreteIntegrator: '<S55>/Filter' */
  rtDW.Filter_DSTATE[3] += 0.02 * rtb_Integrator_h_idx_3;

  /* Update for UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_e[3] = rtb_fl;

  /* Signum: '<S114>/SignPreSat' */
  if (rtb_Filter_n_idx_3 < 0.0) {
    rtb_IntegralGain_idx_1 = -1.0;
  } else if (rtb_Filter_n_idx_3 > 0.0) {
    rtb_IntegralGain_idx_1 = 1.0;
  } else if (rtb_Filter_n_idx_3 == 0.0) {
    rtb_IntegralGain_idx_1 = 0.0;
  } else {
    rtb_IntegralGain_idx_1 = (rtNaN);
  }

  /* Signum: '<S114>/SignPreIntegrator' */
  if (rtb_IntegralGain_1 < 0.0) {
    rtb_IntegralGain = -1.0;
  } else if (rtb_IntegralGain_1 > 0.0) {
    rtb_IntegralGain = 1.0;
  } else if (rtb_IntegralGain_1 == 0.0) {
    rtb_IntegralGain = 0.0;
  } else {
    rtb_IntegralGain = (rtNaN);
  }

  /* Switch: '<S114>/Switch' incorporates:
   *  Constant: '<S114>/Constant1'
   *  DataTypeConversion: '<S114>/DataTypeConv1'
   *  DataTypeConversion: '<S114>/DataTypeConv2'
   *  Logic: '<S114>/AND3'
   *  RelationalOperator: '<S114>/Equal1'
   *  RelationalOperator: '<S114>/NotEqual'
   */
  if ((rtb_T_ff_deceleration_f != rtb_Filter_n_idx_3) && ((int8_T)
       rtb_IntegralGain_idx_1 == (int8_T)rtb_IntegralGain)) {
    rtb_IntegralGain_1 = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S123>/Integrator' */
  rtDW.Integrator_DSTATE_b[3] += 0.02 * rtb_IntegralGain_1;
  rtDW.Integrator_PrevResetState_f[3] = (int8_T)rtb_NOT_idx_3;

  /* Update for DiscreteIntegrator: '<S118>/Filter' incorporates:
   *  DiscreteIntegrator: '<S123>/Integrator'
   */
  rtDW.Filter_DSTATE_f[3] += 0.02 * rtb_Integrator_k;
  rtDW.Filter_PrevResetState_g[3] = (int8_T)rtb_NOT_idx_3;

  /* Update for Memory: '<S144>/Memory' incorporates:
   *  Product: '<S150>/Divide'
   */
  rtDW.Memory_PreviousInput[3] = rtb_Tnew_idx_3;

  /* Update for DiscreteIntegrator: '<S290>/Integrator' incorporates:
   *  Product: '<S283>/1//T'
   *  Sum: '<S283>/Sum1'
   */
  rtDW.Integrator_DSTATE_e[3] += (rtb_IntegralGain_idx_3 - rtb_Saturation[3]) *
    tmp_0 * 0.02;

  /* Update for DiscreteIntegrator: '<S299>/Integrator' incorporates:
   *  Product: '<S292>/1//T'
   *  Sum: '<S292>/Sum1'
   */
  rtDW.Integrator_DSTATE_i[3] += (rtb_Saturation_c_idx_3 -
    rtb_T_ff_deceleration_n[3]) * rtb_Integrator_b * 0.02;

  /* Update for Delay: '<S177>/Delay' */
  rtDW.Delay_DSTATE[3] = rtDW.Delay_DSTATE[4];

  /* Update for UnitDelay: '<S151>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_a[3] = rtDW.CFunction_a[3];

  /* Update for UnitDelay: '<S151>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[3] = rtDW.CFunction_p[3];

  /* Update for Delay: '<S177>/Delay' */
  rtDW.Delay_DSTATE[4] = rtb_Logic_idx_1;

  /* Update for UnitDelay: '<S151>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE[0] = rtb_Abs_m_idx_0;
  rtDW.UnitDelay2_DSTATE[1] = rtb_Abs_g;

  /* Update for DiscreteIntegrator: '<S214>/Integrator' */
  rtDW.Integrator_DSTATE_ek += 0.02 * rtb_Gain1;
  rtDW.Integrator_PrevResetState_h = (int8_T)rtb_Logic_p_idx_1;

  /* Update for DiscreteIntegrator: '<S209>/Filter' incorporates:
   *  DiscreteIntegrator: '<S214>/Integrator'
   */
  rtDW.Filter_DSTATE_g += 0.02 * rtb_rr;
  rtDW.Filter_PrevResetState_m = (int8_T)rtb_Logic_p_idx_1;

  /* Update for UnitDelay: '<S151>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE[0] = rtDW.CFunction_a[0];

  /* Update for UnitDelay: '<S151>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE[0] = rtDW.CFunction_p[0];

  /* Update for UnitDelay: '<S151>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE[1] = rtDW.CFunction_a[1];

  /* Update for UnitDelay: '<S151>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE[1] = rtDW.CFunction_p[1];

  /* Update for UnitDelay: '<S151>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE[2] = rtDW.CFunction_a[2];

  /* Update for UnitDelay: '<S151>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE[2] = rtDW.CFunction_p[2];

  /* Update for UnitDelay: '<S151>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE[3] = rtDW.CFunction_a[3];

  /* Update for UnitDelay: '<S151>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE[3] = rtDW.CFunction_p[3];

  /* Update for UnitDelay: '<S151>/Unit Delay4' */
  rtDW.UnitDelay4_DSTATE[0] = rtb_Abs_m_idx_0;
  rtDW.UnitDelay4_DSTATE[1] = rtb_Abs_g;

  /* Update for DiscreteFir: '<S161>/Discrete FIR Filter' incorporates:
   *  Constant: '<S144>/Constant1'
   */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf] = 0.0;

  /* End of Update for DiscreteFir: '<S161>/Discrete FIR Filter' */

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
  rtY.Torque[0] = rtb_rl_d;
  rtY.Torque[1] = rtb_Tnew_idx_1;
  rtY.Torque[2] = rtb_Tnew_idx_2;
  rtY.Torque[3] = rtb_Tnew_idx_3;
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
    /* Start for InitialCondition generated from: '<S11>/IC' */
    rtDW.IC_1_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC' */
    rtDW.IC_3_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC' */
    rtDW.IC_4_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC' */
    rtDW.IC_7_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC1' */
    rtDW.IC1_1_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC1' */
    rtDW.IC1_2_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC1' */
    rtDW.IC1_3_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC1' */
    rtDW.IC1_4_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC2' */
    rtDW.IC2_1_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC2' */
    rtDW.IC2_3_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC2' */
    rtDW.IC2_4_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC2' */
    rtDW.IC2_7_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC3' */
    rtDW.IC3_1_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC3' */
    rtDW.IC3_2_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC3' */
    rtDW.IC3_3_FirstOutputTime = true;

    /* Start for InitialCondition generated from: '<S11>/IC3' */
    rtDW.IC3_4_FirstOutputTime = true;

    /* Start for Probe: '<S285>/Probe' */
    rtDW.Probe[0] = 0.02;
    rtDW.Probe[1] = 0.0;

    /* Start for Probe: '<S294>/Probe' */
    rtDW.Probe_h[0] = 0.02;
    rtDW.Probe_h[1] = 0.0;

    /* Start for InitialCondition: '<S240>/IC' */
    rtDW.IC_FirstOutputTime = true;

    /* Start for InitialCondition: '<S151>/IC' */
    rtDW.IC_FirstOutputTime_k = true;

    /* Start for InitialCondition: '<S241>/IC1' */
    rtDW.IC1_FirstOutputTime = true;

    /* Start for DataStoreMemory: '<S3>/Data Store_General_Params' */
    rtDW.General_Params = rtConstP.DataStore_General_Params_Initia;

    /* InitializeConditions for DiscreteIntegrator: '<S290>/Integrator' */
    rtDW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S299>/Integrator' */
    rtDW.Integrator_IC_LOADING_f = 1U;

    /* SystemInitialize for Chart: '<S22>/Chart' */
    Chart_Init(&rtDW.TC_max_m);

    /* SystemInitialize for Chart: '<S22>/Chart1' */
    Chart_Init(&rtDW.TC_max_fo);

    /* SystemInitialize for Chart: '<S22>/Chart2' */
    Chart_Init(&rtDW.TC_max_f);

    /* SystemInitialize for Chart: '<S22>/Chart3' */
    Chart_Init(&rtDW.TC_max_e);

    /* SystemInitialize for Chart: '<S85>/Chart' */
    Chart_Init(&rtDW.TC_max_i);

    /* SystemInitialize for Chart: '<S85>/Chart1' */
    Chart_Init(&rtDW.TC_max_k);

    /* SystemInitialize for Chart: '<S85>/Chart2' */
    Chart_Init(&rtDW.TC_max_a);

    /* SystemInitialize for Chart: '<S85>/Chart3' */
    Chart_Init(&rtDW.TC_max);

    /* Start for MATLABSystem: '<S177>/Moving Average' */
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

    /* InitializeConditions for MATLABSystem: '<S177>/Moving Average' */
    iobj_0 = rtDW.obj.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum = 0.0;
      for (i = 0; i < 24; i++) {
        iobj_0->pCumSumRev[i] = 0.0;
      }

      iobj_0->pCumRevIndex = 1.0;
      iobj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S177>/Moving Average' */

    /* Start for MATLABSystem: '<S281>/Moving Average' */
    rtDW.obj_o.matlabCodegenIsDeleted = true;
    rtDW.obj_o.isInitialized = 0;
    rtDW.obj_o.NumChannels = -1;
    rtDW.obj_o.matlabCodegenIsDeleted = false;
    rtDW.obj_o.isSetupComplete = false;
    rtDW.obj_o.isInitialized = 1;
    rtDW.obj_o.NumChannels = 1;
    iobj_0_0 = &rtDW.obj_o._pobj0;
    iobj_0_0->isInitialized = 0;
    iobj_0_0->isInitialized = 0;
    rtDW.obj_o.pStatistic = iobj_0_0;
    rtDW.obj_o.isSetupComplete = true;
    rtDW.obj_o.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S281>/Moving Average' */
    iobj_0_0 = rtDW.obj_o.pStatistic;
    if (iobj_0_0->isInitialized == 1) {
      iobj_0_0->pCumSum = 0.0;
      iobj_0_0->pCumSumRev[0] = 0.0;
      iobj_0_0->pCumSumRev[1] = 0.0;
      iobj_0_0->pCumSumRev[2] = 0.0;
      iobj_0_0->pCumSumRev[3] = 0.0;
      iobj_0_0->pCumRevIndex = 1.0;
      iobj_0_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S281>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
