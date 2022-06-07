/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jun  7 23:37:14 2022
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

/* Named constants for Chart: '<S277>/T_Req_Chart' */
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

/* Forward declaration for local functions */
static void exit_internal_ABS_ON(void);
static void exit_internal_TC_ON(void);
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

/* Function for Chart: '<S17>/Activation logic' */
static void exit_internal_ABS_ON(void)
{
  rtDW.is_RR_k = IN_NO_ACTIVE_CHILD;
  rtDW.is_RL_c = IN_NO_ACTIVE_CHILD;
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

/* Function for Chart: '<S238>/Distribution complete' */
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

/* Function for Chart: '<S238>/Distribution complete' */
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

/* Function for Chart: '<S238>/Distribution complete' */
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

/* Function for Chart: '<S238>/Distribution complete' */
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
  real_T rtb_y_h[121];
  real_T varargin_1[49];
  real_T rtb_CCaller1_o12[35];
  real_T rtb_CCaller1_o3[26];
  real_T csumrev[24];
  real_T rtb_VectorConcatenate[22];
  real_T varargin_2[16];
  real_T RateTransition3[13];
  real_T rtb_TmpSignalConversionAtSFunct[11];
  real_T rtb_VectorConcatenate_k[7];
  real_T rtb_x[7];
  real_T rtb_CCaller1_o10[5];
  real_T rtb_CCaller1_o9[5];
  real_T rtb_Abs_p[4];
  real_T rtb_Braking[4];
  real_T rtb_Divide_a[4];
  real_T rtb_Tnew[4];
  real_T rtb_lbx_out[4];
  real_T rtb_CCaller1_o13[3];
  real_T rtb_CCaller1_o14[3];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T Faeroz;
  real_T Switch2_idx_0;
  real_T Switch2_idx_1;
  real_T Switch2_idx_2;
  real_T Switch2_idx_3;
  real_T b_Fz;
  real_T dT;
  real_T modValueRev;
  real_T rtb_Abs;
  real_T rtb_Abs_fc_idx_0;
  real_T rtb_Abs_g;
  real_T rtb_Gain1_o_idx_0;
  real_T rtb_Gain1_o_idx_1;
  real_T rtb_Gain1_o_idx_2;
  real_T rtb_Gain1_o_idx_3;
  real_T rtb_Integrator_b;
  real_T rtb_Integrator_ee;
  real_T rtb_Integrator_o;
  real_T rtb_Integrator_p;
  real_T rtb_Integrator_p_idx_0;
  real_T rtb_Integrator_p_idx_1;
  real_T rtb_Integrator_p_idx_2;
  real_T rtb_Integrator_p_idx_2_0;
  real_T rtb_Integrator_p_idx_3;
  real_T rtb_NProdOut;
  real_T rtb_RL;
  real_T rtb_RL_tmp;
  real_T rtb_RL_tmp_tmp;
  real_T rtb_RR;
  real_T rtb_Saturation;
  real_T rtb_Saturation1;
  real_T rtb_Sign;
  real_T rtb_SumofElements1;
  real_T rtb_Switch;
  real_T rtb_Switch2_l;
  real_T rtb_Switch_bb;
  real_T rtb_Switch_tmp;
  real_T rtb_Switch_tmp_0;
  real_T rtb_UnaryMinus_f_idx_0;
  real_T rtb_UnaryMinus_f_idx_1;
  real_T rtb_UnaryMinus_f_idx_2;
  real_T rtb_UnaryMinus_f_idx_3;
  real_T rtb_front_wheel_angle_single__g;
  real_T rtb_k_l_idx_0;
  real_T rtb_k_l_idx_1;
  real_T rtb_k_l_idx_2;
  real_T rtb_k_l_idx_3;
  real_T rtb_ome_wheels;
  real_T rtb_ome_wheels_idx_0;
  real_T rtb_ome_wheels_idx_1;
  real_T rtb_ome_wheels_idx_2;
  real_T rtb_ome_wheels_idx_3;
  real_T u0;
  real_T u0_tmp;
  real_T u0_tmp_0;
  real_T u_tmp;
  real_T yaw_rate;
  real_T z;
  int32_T tmp[2];
  int32_T idx;
  int32_T sigIdx;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  boolean_T AND;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_m;
  boolean_T rtb_LessThan1_ib;
  boolean_T rtb_Logic_b_idx_0;
  boolean_T rtb_Logic_b_idx_1;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_Logic_idx_1;
  boolean_T rtb_Logic_o_idx_0;
  boolean_T rtb_Logic_o_idx_1;
  boolean_T rtb_Logic_p_idx_0;
  static const int8_T b[7] = { 0, 0, 0, 1, 1, 1, 1 };

  static const int8_T c[7] = { 0, 0, 0, 0, 1, 0, -1 };

  static const int8_T d[7] = { 0, 0, 0, 1, 0, -1, 0 };

  real_T rtb_Braking_0[4];
  real_T rtb_Divide_m[4];
  real_T Switch2_h_idx_0;
  real_T Switch2_h_idx_1;
  real_T Switch2_h_idx_2;
  real_T Switch2_h_idx_3;
  real_T eta_idx_0;
  real_T eta_idx_1;
  real_T eta_idx_2;
  real_T eta_idx_3;
  real_T rtb_Gain_d1_idx_0;
  real_T rtb_Gain_d1_idx_1;
  real_T rtb_Gain_d1_idx_2;
  real_T rtb_Gain_d1_idx_3;
  real_T rtb_RL_tmp_tmp_0;
  real_T rtb_Switch_tmp_1;
  real_T rtb_Switch_tmp_2;
  real_T rtb_Switch_tmp_tmp;
  real_T rtb_Switch_tmp_tmp_0;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (rtU.vx <= 0.0) {
    rtb_Integrator_o = 0.0;
  } else {
    rtb_Integrator_o = rtU.vx;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Integrator_o <= 0.0) {
    rtb_Integrator_ee = 0.0;
  } else {
    rtb_Integrator_ee = rtb_Integrator_o;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/yaw_rate'
   */
  rtb_Integrator_o = 0.017453292519943295 * rtU.yaw_rate_deg;

  /* RateTransition generated from: '<S1>/Rate Transition1' */
  yaw_rate = rtb_Integrator_o;

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
  rtb_Abs_fc_idx_0 = fabs(look1_binlx(rtU.steering, rtConstP.pooled37,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Abs_g = fabs(look1_binlx(-rtU.steering, rtConstP.pooled37,
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
   *  RateTransition generated from: '<S1>/Rate Transition1'
   *  Sum: '<S12>/Subtract3'
   *  Sum: '<S13>/Subtract3'
   *  Sum: '<S14>/Subtract'
   *  Sum: '<S15>/Subtract'
   *  Switch: '<S13>/Switch'
   *  Switch: '<S14>/Switch'
   *  Switch: '<S15>/Switch'
   */
  if (rtb_Integrator_ee > 0.5) {
    /* Sum: '<S12>/Sum' incorporates:
     *  Inport: '<Root>/vy'
     *  Product: '<S12>/Divide5'
     *  Product: '<S12>/Divide6'
     *  Trigonometry: '<S12>/Cos1'
     *  Trigonometry: '<S12>/Cos2'
     */
    rtb_Sign = rtb_Integrator_ee * cos(rtb_Abs_fc_idx_0) + sin(rtb_Abs_fc_idx_0)
      * rtU.vy;
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
    rtb_Sign = rtb_Integrator_ee * cos(rtb_Abs_g) + sin(rtb_Abs_g) * rtU.vy;
    rtb_Switch_bb = (0.235 * rtU.omega_wheels_FR - rtb_Sign) / rtb_Sign;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_Integrator_ee) /
      rtb_Integrator_ee;
    rtb_RL = (0.235 * rtU.omega_wheels_RL - rtb_Integrator_ee) /
      rtb_Integrator_ee;
  } else {
    rtb_Switch = 0.0;
    rtb_Switch_bb = 0.0;
    rtb_RR = 0.0;
    rtb_RL = 0.0;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT' incorporates:
   *  Inport: '<Root>/steering'
   */
  rtb_front_wheel_angle_single__g = look1_binlx(rtU.steering, rtConstP.pooled37,
    rtConstP.steering_to_wheel_angle_single_, 32U);

  /* MATLAB Function: '<S22>/MATLAB Function2' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/vy'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   */
  Faeroz = rtb_Integrator_ee - 0.635 * rtb_Integrator_o;
  rtb_k_l_idx_0 = rtU.vy - 0.765 * rtb_Integrator_o;
  rtb_k_l_idx_1 = 0.635 * rtb_Integrator_o + rtb_Integrator_ee;

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
  rtb_NProdOut = cos(rtb_front_wheel_angle_single__g);
  rtb_Switch2_l = sin(rtb_front_wheel_angle_single__g);

  /* SignalConversion generated from: '<S138>/ SFunction ' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/vy'
   *  MATLAB Function: '<S22>/MATLAB Function2'
   *  MATLAB Function: '<S25>/MATLAB Function'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   */
  rtb_Braking[0] = (rtb_Integrator_ee - 0.635 * rtb_Integrator_o) * rtb_NProdOut
    + (0.765 * rtb_Integrator_o + rtU.vy) * rtb_Switch2_l;
  rtb_Braking[1] = (0.635 * rtb_Integrator_o + rtb_Integrator_ee) * rtb_NProdOut
    + (0.765 * rtb_Integrator_o + rtU.vy) * sin(rtb_front_wheel_angle_single__g);

  /* MATLAB Function: '<S22>/MATLAB Function2' */
  rtb_Integrator_o = rtb_k_l_idx_0 * rtb_k_l_idx_0;

  /* SignalConversion generated from: '<S138>/ SFunction ' incorporates:
   *  MATLAB Function: '<S22>/MATLAB Function2'
   *  MATLAB Function: '<S25>/MATLAB Function'
   */
  rtb_Braking[2] = sqrt(Faeroz * Faeroz + rtb_Integrator_o);
  rtb_Braking[3] = sqrt(rtb_k_l_idx_1 * rtb_k_l_idx_1 + rtb_Integrator_o);

  /* MATLAB Function: '<S25>/MATLAB Function' incorporates:
   *  Constant: '<S25>/Constant'
   */
  rtb_CCaller1_o13[0] = rtb_Braking[0];
  rtb_CCaller1_o13[1] = rtb_ome_wheels_idx_0;
  rtb_CCaller1_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller1_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    sigIdx = 2;
    exitg1 = false;
    while ((!exitg1) && (sigIdx < 4)) {
      if (!rtIsNaN(rtb_CCaller1_o13[sigIdx - 1])) {
        idx = sigIdx;
        exitg1 = true;
      } else {
        sigIdx++;
      }
    }
  }

  if (idx == 0) {
    rtb_Sign = rtb_CCaller1_o13[0];
  } else {
    rtb_Sign = rtb_CCaller1_o13[idx - 1];
    while (idx + 1 <= 3) {
      if (rtb_Sign < rtb_CCaller1_o13[idx]) {
        rtb_Sign = rtb_CCaller1_o13[idx];
      }

      idx++;
    }
  }

  rtb_k_l_idx_0 = (rtb_ome_wheels_idx_0 - rtb_Braking[0]) / rtb_Sign;
  rtb_CCaller1_o13[0] = rtb_Braking[1];
  rtb_CCaller1_o13[1] = rtb_ome_wheels_idx_1;
  rtb_CCaller1_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller1_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    sigIdx = 2;
    exitg1 = false;
    while ((!exitg1) && (sigIdx < 4)) {
      if (!rtIsNaN(rtb_CCaller1_o13[sigIdx - 1])) {
        idx = sigIdx;
        exitg1 = true;
      } else {
        sigIdx++;
      }
    }
  }

  if (idx == 0) {
    rtb_Sign = rtb_CCaller1_o13[0];
  } else {
    rtb_Sign = rtb_CCaller1_o13[idx - 1];
    while (idx + 1 <= 3) {
      if (rtb_Sign < rtb_CCaller1_o13[idx]) {
        rtb_Sign = rtb_CCaller1_o13[idx];
      }

      idx++;
    }
  }

  rtb_k_l_idx_1 = (rtb_ome_wheels_idx_1 - rtb_Braking[1]) / rtb_Sign;
  rtb_CCaller1_o13[0] = rtb_Braking[2];
  rtb_CCaller1_o13[1] = rtb_ome_wheels_idx_2;
  rtb_CCaller1_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller1_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    sigIdx = 2;
    exitg1 = false;
    while ((!exitg1) && (sigIdx < 4)) {
      if (!rtIsNaN(rtb_CCaller1_o13[sigIdx - 1])) {
        idx = sigIdx;
        exitg1 = true;
      } else {
        sigIdx++;
      }
    }
  }

  if (idx == 0) {
    rtb_Sign = rtb_CCaller1_o13[0];
  } else {
    rtb_Sign = rtb_CCaller1_o13[idx - 1];
    while (idx + 1 <= 3) {
      if (rtb_Sign < rtb_CCaller1_o13[idx]) {
        rtb_Sign = rtb_CCaller1_o13[idx];
      }

      idx++;
    }
  }

  rtb_k_l_idx_2 = (rtb_ome_wheels_idx_2 - rtb_Braking[2]) / rtb_Sign;
  rtb_CCaller1_o13[0] = rtb_Braking[3];
  rtb_CCaller1_o13[1] = rtb_ome_wheels_idx_3;
  rtb_CCaller1_o13[2] = 3.0;
  if (!rtIsNaN(rtb_CCaller1_o13[0])) {
    idx = 1;
  } else {
    idx = 0;
    sigIdx = 2;
    exitg1 = false;
    while ((!exitg1) && (sigIdx < 4)) {
      if (!rtIsNaN(rtb_CCaller1_o13[sigIdx - 1])) {
        idx = sigIdx;
        exitg1 = true;
      } else {
        sigIdx++;
      }
    }
  }

  if (idx == 0) {
    rtb_Sign = rtb_CCaller1_o13[0];
  } else {
    rtb_Sign = rtb_CCaller1_o13[idx - 1];
    while (idx + 1 <= 3) {
      if (rtb_Sign < rtb_CCaller1_o13[idx]) {
        rtb_Sign = rtb_CCaller1_o13[idx];
      }

      idx++;
    }
  }

  rtb_k_l_idx_3 = (rtb_ome_wheels_idx_3 - rtb_Braking[3]) / rtb_Sign;

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
  rtb_Integrator_p_idx_3 = (rtb_ome_wheels - rtDW.UD_DSTATE[0]) *
    0.1019367991845056 * 0.040000000000000036 + rtb_k_l_idx_0 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Abs_p[0] = -0.13600000000000004 - rtb_Integrator_p_idx_3;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_0 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_l_idx_0 = rtb_Integrator_p_idx_3;

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
  rtb_Integrator_p_idx_3 = (rtb_ome_wheels - rtDW.UD_DSTATE[1]) *
    0.1019367991845056 * 0.040000000000000036 + rtb_k_l_idx_1 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Abs_p[1] = -0.13600000000000004 - rtb_Integrator_p_idx_3;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_1 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_l_idx_1 = rtb_Integrator_p_idx_3;

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
  rtb_Integrator_p_idx_3 = (rtb_ome_wheels - rtDW.UD_DSTATE[2]) *
    0.1019367991845056 * 0.040000000000000036 + rtb_k_l_idx_2 * 0.96;

  /* Sum: '<S17>/Minus' */
  rtb_Abs_p[2] = -0.13600000000000004 - rtb_Integrator_p_idx_3;

  /* SampleTimeMath: '<S137>/TSamp'
   *
   * About '<S137>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_ome_wheels_idx_2 = rtb_ome_wheels;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Sum: '<S16>/Plus' */
  rtb_k_l_idx_2 = rtb_Integrator_p_idx_3;

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
  rtb_Integrator_p_idx_3 = (rtb_ome_wheels - rtDW.UD_DSTATE[3]) *
    0.1019367991845056 * 0.040000000000000036 + rtb_k_l_idx_3 * 0.96;

  /* Logic: '<S18>/AND' incorporates:
   *  Constant: '<S18>/Constant2'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   *  RelationalOperator: '<S18>/Relational Operator'
   */
  AND = (rtb_Integrator_ee > 3.0);

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
  rtb_k_l_idx_3 = rtb_Abs_p[0] * 57.0 + rtDW.Integrator_DSTATE[0];

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
  rtb_ome_wheels_idx_3 = rtb_k_l_idx_3;
  rtb_k_l_idx_3 = rtb_Abs_p[1] * 57.0 + rtDW.Integrator_DSTATE[1];

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
  rtb_Integrator_p_idx_1 = rtb_k_l_idx_3;
  rtb_k_l_idx_3 = rtb_Abs_p[2] * 57.0 + rtDW.Integrator_DSTATE[2];

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
  rtb_Integrator_p_idx_2 = rtb_k_l_idx_3;
  rtb_k_l_idx_3 = (-0.13600000000000004 - rtb_Integrator_p_idx_3) * 57.0 +
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

  /* DiscreteFir: '<S156>/Discrete FIR Filter' incorporates:
   *  Constant: '<S139>/Constant1'
   */
  rtb_Integrator_o = 0.0;
  for (idx = rtDW.DiscreteFIRFilter_circBuf; idx < 4; idx++) {
    rtb_Integrator_o += rtDW.DiscreteFIRFilter_states[idx];
  }

  for (idx = 0; idx < rtDW.DiscreteFIRFilter_circBuf; idx++) {
    rtb_Integrator_o += rtDW.DiscreteFIRFilter_states[idx];
  }

  /* End of DiscreteFir: '<S156>/Discrete FIR Filter' */

  /* Switch: '<S156>/Switch' incorporates:
   *  Constant: '<S156>/Constant'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   */
  if (rtb_Integrator_ee > 3.0) {
    /* If: '<S156>/If' incorporates:
     *  Constant: '<S156>/Constant1'
     *  Constant: '<S161>/Vectorino'
     *  Constant: '<S162>/Selected Map'
     *  RelationalOperator: '<S156>/Less Than1'
     *  SignalConversion generated from: '<S161>/Out1'
     *  SignalConversion generated from: '<S162>/Out1'
     */
    if (!(rtb_Integrator_o >= 4.0)) {
      /* Outputs for IfAction SubSystem: '<S156>/Selected Map' incorporates:
       *  ActionPort: '<S162>/Action Port'
       */
      rtb_Integrator_o = 1.0;

      /* End of Outputs for SubSystem: '<S156>/Selected Map' */
    } else {
      /* Outputs for IfAction SubSystem: '<S156>/Backup Map' incorporates:
       *  ActionPort: '<S161>/Action Port'
       */
      rtb_Integrator_o = 2.0;

      /* End of Outputs for SubSystem: '<S156>/Backup Map' */
    }

    /* End of If: '<S156>/If' */
  } else {
    rtb_Integrator_o = 2.0;
  }

  /* End of Switch: '<S156>/Switch' */

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_Saturation = 3.5714285714285712 * rtU.brake;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Saturation > 1.0) {
    rtb_Saturation = 1.0;
  } else if (rtb_Saturation < 0.0) {
    rtb_Saturation = 0.0;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* If: '<S145>/If' incorporates:
   *  Inport: '<S153>/In1'
   *  Signum: '<S109>/SignPreIntegrator'
   */
  if (rtb_Integrator_o == 1.0) {
    /* Outputs for IfAction SubSystem: '<S145>/MPC' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    rtb_Tnew[0] = 0.0;
    rtb_Tnew[1] = 0.0;
    rtb_Tnew[2] = 0.0;
    rtb_Tnew[3] = 0.0;

    /* End of Outputs for SubSystem: '<S145>/MPC' */
  } else {
    /* Outputs for IfAction SubSystem: '<S145>/Vectorino' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    /* Product: '<S164>/Product' incorporates:
     *  Constant: '<S164>/Constant2'
     *  Inport: '<Root>/throttle'
     */
    rtb_Tnew[0] = rtU.throttle * 6.3;
    rtb_Tnew[1] = rtU.throttle * 6.3;
    rtb_Tnew[2] = rtU.throttle * 21.0;
    rtb_Tnew[3] = rtU.throttle * 21.0;

    /* End of Outputs for SubSystem: '<S145>/Vectorino' */
  }

  /* End of If: '<S145>/If' */

  /* Product: '<S145>/Divide' incorporates:
   *  Signum: '<S109>/SignPreIntegrator'
   */
  rtb_Gain1_o_idx_0 = rtb_Tnew[0];
  rtb_Gain1_o_idx_1 = rtb_Tnew[1];
  rtb_Gain1_o_idx_2 = rtb_Tnew[2];
  rtb_Gain1_o_idx_3 = rtb_Tnew[3];

  /* Chart: '<S17>/Activation logic' incorporates:
   *  Constant: '<S11>/Constant13'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/Constant5'
   *  SignalConversion generated from: '<S26>/ SFunction '
   *  UnitDelay: '<S17>/Unit Delay'
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
      rtDW.is_FR_i = IN_ABS_INACTIVE;
      rtDW.T_min[1] = 21.0;
      rtDW.is_RL_c = IN_ABS_INACTIVE;
      rtDW.T_min[2] = 21.0;
      rtDW.is_RR_k = IN_ABS_INACTIVE;
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
      if (rtb_Gain1_o_idx_3 > 0.9 * rtDW.UnitDelay_DSTATE_e[0]) {
        rtDW.is_FL_g = IN_ABS_INACTIVE;
        rtDW.T_min[0] = 21.0;
      } else {
        rtDW.T_min[0] = Switch2_idx_0;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_l_idx_0 <= -0.14600000000000005) && (rtb_Gain1_o_idx_3 <
                0.0)) {
      rtDW.is_FL_g = IN_ABS_ACTIVE;
      rtDW.T_min[0] = rtb_Gain1_o_idx_3;
    } else {
      rtDW.T_min[0] = 21.0;
    }

    if (rtDW.is_FR_i == IN_ABS_ACTIVE) {
      if (rtb_Gain1_o_idx_2 > 0.9 * rtDW.UnitDelay_DSTATE_e[1]) {
        rtDW.is_FR_i = IN_ABS_INACTIVE;
        rtDW.T_min[1] = 21.0;
      } else {
        rtDW.T_min[1] = Switch2_idx_1;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_l_idx_1 <= -0.14600000000000005) && (rtb_Gain1_o_idx_2 <
                0.0)) {
      rtDW.is_FR_i = IN_ABS_ACTIVE;
      rtDW.T_min[1] = rtb_Gain1_o_idx_2;
    } else {
      rtDW.T_min[1] = 21.0;
    }

    if (rtDW.is_RL_c == IN_ABS_ACTIVE) {
      if (rtb_Gain1_o_idx_1 > 0.9 * rtDW.UnitDelay_DSTATE_e[2]) {
        rtDW.is_RL_c = IN_ABS_INACTIVE;
        rtDW.T_min[2] = 21.0;
      } else {
        rtDW.T_min[2] = Switch2_idx_2;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_k_l_idx_2 <= -0.14600000000000005) && (rtb_Gain1_o_idx_1 <
                0.0)) {
      rtDW.is_RL_c = IN_ABS_ACTIVE;
      rtDW.T_min[2] = rtb_Gain1_o_idx_1;
    } else {
      rtDW.T_min[2] = 21.0;
    }

    if (rtDW.is_RR_k == IN_ABS_ACTIVE) {
      if (rtb_Gain1_o_idx_0 > 0.9 * rtDW.UnitDelay_DSTATE_e[3]) {
        rtDW.is_RR_k = IN_ABS_INACTIVE;
        rtDW.T_min[3] = 21.0;
      } else {
        rtDW.T_min[3] = Switch2_idx_3;
      }

      /* case IN_ABS_INACTIVE: */
    } else if ((rtb_Integrator_p_idx_3 <= -0.14600000000000005) &&
               (rtb_Gain1_o_idx_0 < 0.0)) {
      rtDW.is_RR_k = IN_ABS_ACTIVE;
      rtDW.T_min[3] = rtb_Gain1_o_idx_0;
    } else {
      rtDW.T_min[3] = 21.0;
    }
  }

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Gain: '<S52>/ZeroGain'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_ome_wheels_idx_3 >= -4.9) {
    rtb_Integrator_p_idx_0 = -4.9;
  } else if (rtb_ome_wheels_idx_3 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Integrator_p_idx_0 = rtb_ome_wheels_idx_3;
  } else {
    rtb_Integrator_p_idx_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' incorporates:
   *  Gain: '<S52>/ZeroGain'
   */
  rtb_Integrator_b = rtb_ome_wheels_idx_3 - rtb_Integrator_p_idx_0;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Gain: '<S52>/ZeroGain'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_Integrator_p_idx_1 >= -4.9) {
    rtb_Integrator_p_idx_0 = -4.9;
  } else if (rtb_Integrator_p_idx_1 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Integrator_p_idx_0 = rtb_Integrator_p_idx_1;
  } else {
    rtb_Integrator_p_idx_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' incorporates:
   *  Gain: '<S52>/ZeroGain'
   */
  rtb_Integrator_p_idx_0 = rtb_Integrator_p_idx_1 - rtb_Integrator_p_idx_0;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Gain: '<S52>/ZeroGain'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_Integrator_p_idx_2 >= -4.9) {
    rtb_Integrator_p_idx_2_0 = -4.9;
  } else if (rtb_Integrator_p_idx_2 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Integrator_p_idx_2_0 = rtb_Integrator_p_idx_2;
  } else {
    rtb_Integrator_p_idx_2_0 = -21.0;
  }

  /* Sum: '<S55>/Diff' incorporates:
   *  Gain: '<S52>/ZeroGain'
   */
  rtb_Integrator_p_idx_2_0 = rtb_Integrator_p_idx_2 - rtb_Integrator_p_idx_2_0;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S17>/Constant4'
   *  RelationalOperator: '<S55>/u_GTE_up'
   *  RelationalOperator: '<S55>/u_GT_lo'
   *  Switch: '<S55>/Switch1'
   */
  if (rtb_k_l_idx_3 >= -4.9) {
    rtb_Integrator_p = -4.9;
  } else if (rtb_k_l_idx_3 > -21.0) {
    /* Switch: '<S55>/Switch1' */
    rtb_Integrator_p = rtb_k_l_idx_3;
  } else {
    rtb_Integrator_p = -21.0;
  }

  /* Sum: '<S55>/Diff' */
  rtb_Integrator_p = rtb_k_l_idx_3 - rtb_Integrator_p;

  /* Sum: '<S75>/SumI1' incorporates:
   *  Constant: '<S17>/Constant2'
   *  Gain: '<S74>/Kt'
   *  Product: '<S59>/IProd Out'
   *  Sum: '<S17>/Minus'
   *  Sum: '<S74>/SumI3'
   */
  rtb_Tnew[0] = (rtDW.T_min[0] - Switch2_idx_0) * 100.0 + rtb_Abs_p[0] * 2845.0;
  rtb_Tnew[1] = (rtDW.T_min[1] - Switch2_idx_1) * 100.0 + rtb_Abs_p[1] * 2845.0;
  rtb_Tnew[2] = (rtDW.T_min[2] - Switch2_idx_2) * 100.0 + rtb_Abs_p[2] * 2845.0;
  rtb_Tnew[3] = (-0.13600000000000004 - rtb_Integrator_p_idx_3) * 2845.0 +
    (rtDW.T_min[3] - Switch2_idx_3) * 100.0;

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  Faeroz = rtb_Tnew[0];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Integrator_b < 0.0) {
    Switch2_idx_3 = -1.0;
  } else if (rtb_Integrator_b > 0.0) {
    Switch2_idx_3 = 1.0;
  } else if (rtb_Integrator_b == 0.0) {
    Switch2_idx_3 = 0.0;
  } else {
    Switch2_idx_3 = (rtNaN);
  }

  /* Signum: '<S52>/SignPreIntegrator' */
  if (Faeroz < 0.0) {
    Faeroz = -1.0;
  } else if (Faeroz > 0.0) {
    Faeroz = 1.0;
  } else if (Faeroz == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant1'
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Gain: '<S52>/ZeroGain'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((0.0 * rtb_ome_wheels_idx_3 != rtb_Integrator_b) && ((int8_T)Switch2_idx_3
       == (int8_T)Faeroz)) {
    Switch2_idx_3 = 0.0;
  } else {
    Switch2_idx_3 = rtb_Tnew[0];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  Faeroz = rtb_Tnew[1];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Integrator_p_idx_0 < 0.0) {
    rtb_Integrator_b = -1.0;
  } else if (rtb_Integrator_p_idx_0 > 0.0) {
    rtb_Integrator_b = 1.0;
  } else if (rtb_Integrator_p_idx_0 == 0.0) {
    rtb_Integrator_b = 0.0;
  } else {
    rtb_Integrator_b = (rtNaN);
  }

  /* Signum: '<S52>/SignPreIntegrator' */
  if (Faeroz < 0.0) {
    Faeroz = -1.0;
  } else if (Faeroz > 0.0) {
    Faeroz = 1.0;
  } else if (Faeroz == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant1'
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Gain: '<S52>/ZeroGain'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((0.0 * rtb_Integrator_p_idx_1 != rtb_Integrator_p_idx_0) && ((int8_T)
       rtb_Integrator_b == (int8_T)Faeroz)) {
    rtb_Integrator_p_idx_0 = 0.0;
  } else {
    rtb_Integrator_p_idx_0 = rtb_Tnew[1];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  Faeroz = rtb_Tnew[2];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Integrator_p_idx_2_0 < 0.0) {
    rtb_Integrator_b = -1.0;
  } else if (rtb_Integrator_p_idx_2_0 > 0.0) {
    rtb_Integrator_b = 1.0;
  } else if (rtb_Integrator_p_idx_2_0 == 0.0) {
    rtb_Integrator_b = 0.0;
  } else {
    rtb_Integrator_b = (rtNaN);
  }

  /* Signum: '<S52>/SignPreIntegrator' */
  if (Faeroz < 0.0) {
    Faeroz = -1.0;
  } else if (Faeroz > 0.0) {
    Faeroz = 1.0;
  } else if (Faeroz == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant1'
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Gain: '<S52>/ZeroGain'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((0.0 * rtb_Integrator_p_idx_2 != rtb_Integrator_p_idx_2_0) && ((int8_T)
       rtb_Integrator_b == (int8_T)Faeroz)) {
    rtb_Integrator_p_idx_2_0 = 0.0;
  } else {
    rtb_Integrator_p_idx_2_0 = rtb_Tnew[2];
  }

  /* Signum: '<S52>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S52>/NotEqual'
   */
  Faeroz = rtb_Tnew[3];

  /* Signum: '<S52>/SignPreSat' */
  if (rtb_Integrator_p < 0.0) {
    rtb_Integrator_b = -1.0;
  } else if (rtb_Integrator_p > 0.0) {
    rtb_Integrator_b = 1.0;
  } else if (rtb_Integrator_p == 0.0) {
    rtb_Integrator_b = 0.0;
  } else {
    rtb_Integrator_b = (rtNaN);
  }

  /* Signum: '<S52>/SignPreIntegrator' */
  if (Faeroz < 0.0) {
    Faeroz = -1.0;
  } else if (Faeroz > 0.0) {
    Faeroz = 1.0;
  } else if (Faeroz == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant1'
   *  DataTypeConversion: '<S52>/DataTypeConv1'
   *  DataTypeConversion: '<S52>/DataTypeConv2'
   *  Gain: '<S52>/ZeroGain'
   *  Logic: '<S52>/AND3'
   *  RelationalOperator: '<S52>/Equal1'
   *  RelationalOperator: '<S52>/NotEqual'
   */
  if ((0.0 * rtb_k_l_idx_3 != rtb_Integrator_p) && ((int8_T)rtb_Integrator_b ==
       (int8_T)Faeroz)) {
    rtb_Integrator_b = 0.0;
  } else {
    rtb_Integrator_b = rtb_Tnew[3];
  }

  /* Product: '<S80>/Divide' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Constant: '<S19>/Constant4'
   *  Inport: '<Root>/throttle'
   *  Sum: '<S80>/Minus'
   */
  rtb_Saturation1 = ((rtU.throttle - 0.05) + 0.01) / 0.02;

  /* Relay: '<S80>/Relay1' */
  rtDW.Relay1_Mode = ((rtb_Saturation1 >= 1.0) || ((!(rtb_Saturation1 <= 0.0)) &&
    rtDW.Relay1_Mode));

  /* Product: '<S81>/Divide' incorporates:
   *  Constant: '<S19>/Constant5'
   *  Constant: '<S19>/Constant6'
   *  Inport: '<Root>/brake'
   *  Sum: '<S81>/Minus'
   */
  rtb_Saturation1 = ((rtU.brake - 0.1) + 0.01) / 0.02;

  /* Relay: '<S81>/Relay1' */
  rtDW.Relay1_Mode_k = ((rtb_Saturation1 >= 1.0) || ((!(rtb_Saturation1 <= 0.0))
    && rtDW.Relay1_Mode_k));

  /* Logic: '<S19>/AND' incorporates:
   *  Constant: '<S19>/Constant2'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  Relay: '<S80>/Relay1'
   *  Relay: '<S81>/Relay1'
   */
  rtb_LessThan1_ib = ((rtb_Integrator_ee > 3.0) && rtDW.Relay1_Mode &&
                      (!rtDW.Relay1_Mode_k));

  /* Sum: '<S23>/Minus' */
  rtb_Tnew[0] = 0.13600000000000004 - rtb_k_l_idx_0;
  rtb_Tnew[1] = 0.13600000000000004 - rtb_k_l_idx_1;
  rtb_Tnew[2] = 0.13600000000000004 - rtb_k_l_idx_2;
  rtb_Tnew[3] = 0.13600000000000004 - rtb_Integrator_p_idx_3;

  /* DiscreteIntegrator: '<S119>/Integrator' */
  if (rtb_LessThan1_ib && (rtDW.Integrator_PrevResetState_g <= 0)) {
    rtDW.Integrator_DSTATE_f[0] = 0.0;
    rtDW.Integrator_DSTATE_f[1] = 0.0;
    rtDW.Integrator_DSTATE_f[2] = 0.0;
    rtDW.Integrator_DSTATE_f[3] = 0.0;
  }

  /* Sum: '<S129>/Sum' incorporates:
   *  Constant: '<S23>/Constant1'
   *  DiscreteIntegrator: '<S119>/Integrator'
   *  Product: '<S124>/PProd Out'
   */
  rtb_Abs_p[0] = rtb_Tnew[0] * 57.0 + rtDW.Integrator_DSTATE_f[0];
  rtb_Abs_p[1] = rtb_Tnew[1] * 57.0 + rtDW.Integrator_DSTATE_f[1];
  rtb_Abs_p[2] = rtb_Tnew[2] * 57.0 + rtDW.Integrator_DSTATE_f[2];
  rtb_Abs_p[3] = rtb_Tnew[3] * 57.0 + rtDW.Integrator_DSTATE_f[3];

  /* Switch: '<S127>/Switch2' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  RelationalOperator: '<S127>/LowerRelop1'
   *  RelationalOperator: '<S127>/UpperRelop'
   *  Switch: '<S127>/Switch'
   */
  if (rtb_Abs_p[0] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    Switch2_h_idx_0 = 21.0;
  } else if (rtb_Abs_p[0] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    Switch2_h_idx_0 = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' */
    Switch2_h_idx_0 = rtb_Abs_p[0];
  }

  if (rtb_Abs_p[1] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    Switch2_h_idx_1 = 21.0;
  } else if (rtb_Abs_p[1] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    Switch2_h_idx_1 = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' */
    Switch2_h_idx_1 = rtb_Abs_p[1];
  }

  if (rtb_Abs_p[2] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    Switch2_h_idx_2 = 21.0;
  } else if (rtb_Abs_p[2] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    Switch2_h_idx_2 = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' */
    Switch2_h_idx_2 = rtb_Abs_p[2];
  }

  if (rtb_Abs_p[3] > 21.0) {
    /* Switch: '<S127>/Switch2' */
    Switch2_h_idx_3 = 21.0;
  } else if (rtb_Abs_p[3] < 4.9) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Switch: '<S127>/Switch2'
     */
    Switch2_h_idx_3 = 4.9;
  } else {
    /* Switch: '<S127>/Switch2' */
    Switch2_h_idx_3 = rtb_Abs_p[3];
  }

  /* End of Switch: '<S127>/Switch2' */

  /* Chart: '<S23>/Activation logic' incorporates:
   *  Chart: '<S17>/Activation logic'
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S23>/Constant4'
   *  Constant: '<S23>/Constant5'
   *  SignalConversion generated from: '<S26>/ SFunction '
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
    if (rtb_LessThan1_ib) {
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
  } else if (!rtb_LessThan1_ib) {
    exit_internal_TC_ON();
    rtDW.is_TS_ON = IN_TC_OFF;
    rtDW.T_max[0] = 21.0;
    rtDW.T_max[1] = 21.0;
    rtDW.T_max[2] = 21.0;
    rtDW.T_max[3] = 21.0;
  } else {
    if (rtDW.is_FL == IN_TC_ACTIVE) {
      if (rtb_Gain1_o_idx_3 < 0.9 * rtDW.UnitDelay_DSTATE_ep[0]) {
        rtDW.is_FL = IN_TC_INACTIVE;
        rtDW.T_max[0] = 21.0;
      } else {
        rtDW.T_max[0] = Switch2_h_idx_0;
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_l_idx_0 >= 0.14600000000000005) {
      rtDW.is_FL = IN_TC_ACTIVE;
      rtDW.T_max[0] = fabs(rtb_Gain1_o_idx_3);
    } else {
      rtDW.T_max[0] = 21.0;
    }

    if (rtDW.is_FR == IN_TC_ACTIVE) {
      if (rtb_Gain1_o_idx_2 < 0.9 * rtDW.UnitDelay_DSTATE_ep[1]) {
        rtDW.is_FR = IN_TC_INACTIVE;
        rtDW.T_max[1] = 21.0;
      } else {
        rtDW.T_max[1] = Switch2_h_idx_1;
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_l_idx_1 >= 0.14600000000000005) {
      rtDW.is_FR = IN_TC_ACTIVE;
      rtDW.T_max[1] = fabs(rtb_Gain1_o_idx_2);
    } else {
      rtDW.T_max[1] = 21.0;
    }

    if (rtDW.is_RL == IN_TC_ACTIVE) {
      if (rtb_Gain1_o_idx_1 < 0.9 * rtDW.UnitDelay_DSTATE_ep[2]) {
        rtDW.is_RL = IN_TC_INACTIVE;
        rtDW.T_max[2] = 21.0;
      } else {
        rtDW.T_max[2] = Switch2_h_idx_2;
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_k_l_idx_2 >= 0.14600000000000005) {
      rtDW.is_RL = IN_TC_ACTIVE;
      rtDW.T_max[2] = fabs(rtb_Gain1_o_idx_1);
    } else {
      rtDW.T_max[2] = 21.0;
    }

    if (rtDW.is_RR == IN_TC_ACTIVE) {
      if (rtb_Gain1_o_idx_0 < 0.9 * rtDW.UnitDelay_DSTATE_ep[3]) {
        rtDW.is_RR = IN_TC_INACTIVE;
        rtDW.T_max[3] = 21.0;
      } else {
        rtDW.T_max[3] = Switch2_h_idx_3;
      }

      /* case IN_TC_INACTIVE: */
    } else if (rtb_Integrator_p_idx_3 >= 0.14600000000000005) {
      rtDW.is_RR = IN_TC_ACTIVE;
      rtDW.T_max[3] = fabs(rtb_Gain1_o_idx_0);
    } else {
      rtDW.T_max[3] = 21.0;
    }
  }

  /* End of Chart: '<S23>/Activation logic' */

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S20>/LowerRelop1'
   *  RelationalOperator: '<S20>/UpperRelop'
   *  Switch: '<S20>/Switch'
   */
  if (rtDW.T_max[0] > 21.0) {
    rtb_k_l_idx_0 = 21.0;
  } else if (rtDW.T_max[0] < 0.0) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     */
    rtb_k_l_idx_0 = 0.0;
  } else {
    rtb_k_l_idx_0 = rtDW.T_max[0];
  }

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtDW.T_min[0] > 21.0) {
    rtb_ome_wheels_idx_3 = 21.0;
  } else if (rtDW.T_min[0] < 0.0) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S16>/Constant3'
     */
    rtb_ome_wheels_idx_3 = 0.0;
  } else {
    rtb_ome_wheels_idx_3 = rtDW.T_min[0];
  }

  /* Gain: '<S109>/ZeroGain' */
  Switch2_idx_0 = 0.0 * rtb_Abs_p[0];

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  Gain: '<S109>/ZeroGain'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_Abs_p[0] >= 21.0) {
    rtb_Integrator_p = 21.0;
  } else if (rtb_Abs_p[0] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_Integrator_p = rtb_Abs_p[0];
  } else {
    rtb_Integrator_p = 4.9;
  }

  /* Sum: '<S112>/Diff' incorporates:
   *  Gain: '<S109>/ZeroGain'
   */
  rtb_Integrator_p = rtb_Abs_p[0] - rtb_Integrator_p;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  Gain: '<S109>/ZeroGain'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_Abs_p[0] >= 21.0) {
    dT = 21.0;
  } else if (rtb_Abs_p[0] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    dT = rtb_Abs_p[0];
  } else {
    dT = 4.9;
  }

  /* Sum: '<S112>/Diff' incorporates:
   *  Gain: '<S109>/ZeroGain'
   */
  rtb_Abs_p[0] -= dT;

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S20>/LowerRelop1'
   *  RelationalOperator: '<S20>/UpperRelop'
   *  Switch: '<S20>/Switch'
   */
  if (rtDW.T_max[1] > 21.0) {
    rtb_k_l_idx_1 = 21.0;
  } else if (rtDW.T_max[1] < 0.0) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     */
    rtb_k_l_idx_1 = 0.0;
  } else {
    rtb_k_l_idx_1 = rtDW.T_max[1];
  }

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtDW.T_min[1] > 21.0) {
    rtb_Integrator_p_idx_1 = 21.0;
  } else if (rtDW.T_min[1] < 0.0) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S16>/Constant3'
     */
    rtb_Integrator_p_idx_1 = 0.0;
  } else {
    rtb_Integrator_p_idx_1 = rtDW.T_min[1];
  }

  /* Gain: '<S109>/ZeroGain' */
  Switch2_idx_1 = 0.0 * rtb_Abs_p[1];

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  Gain: '<S109>/ZeroGain'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_Abs_p[1] >= 21.0) {
    dT = 21.0;
  } else if (rtb_Abs_p[1] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    dT = rtb_Abs_p[1];
  } else {
    dT = 4.9;
  }

  /* Sum: '<S112>/Diff' incorporates:
   *  Gain: '<S109>/ZeroGain'
   */
  dT = rtb_Abs_p[1] - dT;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  Gain: '<S109>/ZeroGain'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_Abs_p[1] >= 21.0) {
    rtb_UnaryMinus_f_idx_1 = 21.0;
  } else if (rtb_Abs_p[1] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_UnaryMinus_f_idx_1 = rtb_Abs_p[1];
  } else {
    rtb_UnaryMinus_f_idx_1 = 4.9;
  }

  /* Sum: '<S112>/Diff' incorporates:
   *  Gain: '<S109>/ZeroGain'
   */
  rtb_Abs_p[1] -= rtb_UnaryMinus_f_idx_1;

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S20>/LowerRelop1'
   *  RelationalOperator: '<S20>/UpperRelop'
   *  Switch: '<S20>/Switch'
   */
  if (rtDW.T_max[2] > 21.0) {
    rtb_k_l_idx_2 = 21.0;
  } else if (rtDW.T_max[2] < 0.0) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     */
    rtb_k_l_idx_2 = 0.0;
  } else {
    rtb_k_l_idx_2 = rtDW.T_max[2];
  }

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtDW.T_min[2] > 21.0) {
    rtb_Integrator_p_idx_2 = 21.0;
  } else if (rtDW.T_min[2] < 0.0) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S16>/Constant3'
     */
    rtb_Integrator_p_idx_2 = 0.0;
  } else {
    rtb_Integrator_p_idx_2 = rtDW.T_min[2];
  }

  /* Gain: '<S109>/ZeroGain' */
  Switch2_idx_2 = 0.0 * rtb_Abs_p[2];

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  Gain: '<S109>/ZeroGain'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_Abs_p[2] >= 21.0) {
    rtb_UnaryMinus_f_idx_1 = 21.0;
  } else if (rtb_Abs_p[2] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_UnaryMinus_f_idx_1 = rtb_Abs_p[2];
  } else {
    rtb_UnaryMinus_f_idx_1 = 4.9;
  }

  /* Sum: '<S112>/Diff' incorporates:
   *  Gain: '<S109>/ZeroGain'
   */
  rtb_UnaryMinus_f_idx_1 = rtb_Abs_p[2] - rtb_UnaryMinus_f_idx_1;

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  Gain: '<S109>/ZeroGain'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_Abs_p[2] >= 21.0) {
    rtb_UnaryMinus_f_idx_2 = 21.0;
  } else if (rtb_Abs_p[2] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_UnaryMinus_f_idx_2 = rtb_Abs_p[2];
  } else {
    rtb_UnaryMinus_f_idx_2 = 4.9;
  }

  /* Sum: '<S112>/Diff' incorporates:
   *  Gain: '<S109>/ZeroGain'
   */
  rtb_Abs_p[2] -= rtb_UnaryMinus_f_idx_2;

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S11>/Constant12'
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S20>/LowerRelop1'
   *  RelationalOperator: '<S20>/UpperRelop'
   *  Switch: '<S20>/Switch'
   */
  if (rtDW.T_max[3] > 21.0) {
    rtb_k_l_idx_3 = 21.0;
  } else if (rtDW.T_max[3] < 0.0) {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S16>/Constant1'
     */
    rtb_k_l_idx_3 = 0.0;
  } else {
    rtb_k_l_idx_3 = rtDW.T_max[3];
  }

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S16>/Constant3'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtDW.T_min[3] > 21.0) {
    rtb_Integrator_p_idx_3 = 21.0;
  } else if (rtDW.T_min[3] < 0.0) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S16>/Constant3'
     */
    rtb_Integrator_p_idx_3 = 0.0;
  } else {
    rtb_Integrator_p_idx_3 = rtDW.T_min[3];
  }

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  Gain: '<S109>/ZeroGain'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_Abs_p[3] >= 21.0) {
    rtb_UnaryMinus_f_idx_2 = 21.0;
  } else if (rtb_Abs_p[3] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_UnaryMinus_f_idx_2 = rtb_Abs_p[3];
  } else {
    rtb_UnaryMinus_f_idx_2 = 4.9;
  }

  /* Sum: '<S112>/Diff' incorporates:
   *  Gain: '<S109>/ZeroGain'
   */
  rtb_UnaryMinus_f_idx_2 = rtb_Abs_p[3] - rtb_UnaryMinus_f_idx_2;

  /* Sum: '<S132>/SumI1' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S131>/Kt'
   *  Product: '<S116>/IProd Out'
   *  Sum: '<S131>/SumI3'
   */
  rtb_Tnew[0] = (rtDW.T_max[0] - Switch2_h_idx_0) * 100.0 + rtb_Tnew[0] * 2845.0;
  rtb_Tnew[1] = (rtDW.T_max[1] - Switch2_h_idx_1) * 100.0 + rtb_Tnew[1] * 2845.0;
  rtb_Tnew[2] = (rtDW.T_max[2] - Switch2_h_idx_2) * 100.0 + rtb_Tnew[2] * 2845.0;
  rtb_Tnew[3] = (rtDW.T_max[3] - Switch2_h_idx_3) * 100.0 + rtb_Tnew[3] * 2845.0;

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S109>/NotEqual'
   */
  Faeroz = rtb_Tnew[0];

  /* Signum: '<S109>/SignPreSat' */
  if (rtb_Integrator_p < 0.0) {
    rtb_Integrator_p = -1.0;
  } else if (rtb_Integrator_p > 0.0) {
    rtb_Integrator_p = 1.0;
  } else if (rtb_Integrator_p == 0.0) {
    rtb_Integrator_p = 0.0;
  } else {
    rtb_Integrator_p = (rtNaN);
  }

  /* Signum: '<S109>/SignPreIntegrator' */
  if (Faeroz < 0.0) {
    Faeroz = -1.0;
  } else if (Faeroz > 0.0) {
    Faeroz = 1.0;
  } else if (Faeroz == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DataTypeConversion: '<S109>/DataTypeConv1'
   *  DataTypeConversion: '<S109>/DataTypeConv2'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/NotEqual'
   */
  if ((Switch2_idx_0 != rtb_Abs_p[0]) && ((int8_T)rtb_Integrator_p == (int8_T)
       Faeroz)) {
    Switch2_idx_0 = 0.0;
  } else {
    Switch2_idx_0 = rtb_Tnew[0];
  }

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S109>/NotEqual'
   */
  Faeroz = rtb_Tnew[1];

  /* Signum: '<S109>/SignPreSat' */
  if (dT < 0.0) {
    rtb_Integrator_p = -1.0;
  } else if (dT > 0.0) {
    rtb_Integrator_p = 1.0;
  } else if (dT == 0.0) {
    rtb_Integrator_p = 0.0;
  } else {
    rtb_Integrator_p = (rtNaN);
  }

  /* Signum: '<S109>/SignPreIntegrator' */
  if (Faeroz < 0.0) {
    Faeroz = -1.0;
  } else if (Faeroz > 0.0) {
    Faeroz = 1.0;
  } else if (Faeroz == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DataTypeConversion: '<S109>/DataTypeConv1'
   *  DataTypeConversion: '<S109>/DataTypeConv2'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/NotEqual'
   */
  if ((Switch2_idx_1 != rtb_Abs_p[1]) && ((int8_T)rtb_Integrator_p == (int8_T)
       Faeroz)) {
    Switch2_idx_1 = 0.0;
  } else {
    Switch2_idx_1 = rtb_Tnew[1];
  }

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S109>/NotEqual'
   */
  Faeroz = rtb_Tnew[2];

  /* Signum: '<S109>/SignPreSat' */
  if (rtb_UnaryMinus_f_idx_1 < 0.0) {
    rtb_Integrator_p = -1.0;
  } else if (rtb_UnaryMinus_f_idx_1 > 0.0) {
    rtb_Integrator_p = 1.0;
  } else if (rtb_UnaryMinus_f_idx_1 == 0.0) {
    rtb_Integrator_p = 0.0;
  } else {
    rtb_Integrator_p = (rtNaN);
  }

  /* Signum: '<S109>/SignPreIntegrator' */
  if (Faeroz < 0.0) {
    Faeroz = -1.0;
  } else if (Faeroz > 0.0) {
    Faeroz = 1.0;
  } else if (Faeroz == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DataTypeConversion: '<S109>/DataTypeConv1'
   *  DataTypeConversion: '<S109>/DataTypeConv2'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/NotEqual'
   */
  if ((Switch2_idx_2 != rtb_Abs_p[2]) && ((int8_T)rtb_Integrator_p == (int8_T)
       Faeroz)) {
    Switch2_idx_2 = 0.0;
  } else {
    Switch2_idx_2 = rtb_Tnew[2];
  }

  /* Signum: '<S109>/SignPreIntegrator' incorporates:
   *  RelationalOperator: '<S109>/NotEqual'
   */
  Faeroz = rtb_Tnew[3];

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant6'
   *  Gain: '<S109>/ZeroGain'
   *  RelationalOperator: '<S112>/u_GTE_up'
   *  RelationalOperator: '<S112>/u_GT_lo'
   *  Switch: '<S112>/Switch1'
   */
  if (rtb_Abs_p[3] >= 21.0) {
    rtb_Integrator_p = 21.0;
  } else if (rtb_Abs_p[3] > 4.9) {
    /* Switch: '<S112>/Switch1' */
    rtb_Integrator_p = rtb_Abs_p[3];
  } else {
    rtb_Integrator_p = 4.9;
  }

  /* Signum: '<S109>/SignPreSat' */
  if (rtb_UnaryMinus_f_idx_2 < 0.0) {
    dT = -1.0;
  } else if (rtb_UnaryMinus_f_idx_2 > 0.0) {
    dT = 1.0;
  } else if (rtb_UnaryMinus_f_idx_2 == 0.0) {
    dT = 0.0;
  } else {
    dT = (rtNaN);
  }

  /* Signum: '<S109>/SignPreIntegrator' */
  if (Faeroz < 0.0) {
    Faeroz = -1.0;
  } else if (Faeroz > 0.0) {
    Faeroz = 1.0;
  } else if (Faeroz == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant1'
   *  DataTypeConversion: '<S109>/DataTypeConv1'
   *  DataTypeConversion: '<S109>/DataTypeConv2'
   *  Gain: '<S109>/ZeroGain'
   *  Logic: '<S109>/AND3'
   *  RelationalOperator: '<S109>/Equal1'
   *  RelationalOperator: '<S109>/NotEqual'
   *  Sum: '<S112>/Diff'
   */
  if ((0.0 * rtb_Abs_p[3] != rtb_Abs_p[3] - rtb_Integrator_p) && ((int8_T)dT ==
       (int8_T)Faeroz)) {
    rtb_Integrator_p = 0.0;
  } else {
    rtb_Integrator_p = rtb_Tnew[3];
  }

  /* MATLAB Function: '<S140>/MATLAB Function1' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition1'
   */
  rtb_Sign = rtb_front_wheel_angle_single__g * rtb_Integrator_ee /
    (rtb_Integrator_ee * rtb_Integrator_ee * 0.0 + 1.53);

  /* SignalConversion generated from: '<S141>/Vector Concatenate' incorporates:
   *  Constant: '<S141>/T_FL_ref'
   *  Constant: '<S141>/T_FR_ref'
   *  Constant: '<S141>/T_RL_ref'
   *  Constant: '<S141>/T_RR_ref'
   *  Constant: '<S141>/VX_ref'
   *  Constant: '<S141>/VY_ref'
   *  Constant: '<S141>/dT_FL_ref'
   *  Constant: '<S141>/dT_FR_ref'
   *  Constant: '<S141>/dT_RL_ref'
   *  Constant: '<S141>/dT_RR_ref'
   */
  rtb_TmpSignalConversionAtSFunct[0] = 0.0;
  rtb_TmpSignalConversionAtSFunct[1] = 0.0;
  rtb_TmpSignalConversionAtSFunct[2] = rtb_Sign;
  memset(&rtb_TmpSignalConversionAtSFunct[3], 0, sizeof(real_T) << 3U);
  memcpy(&rtb_VectorConcatenate[0], &rtb_TmpSignalConversionAtSFunct[0], 11U *
         sizeof(real_T));

  /* SignalConversion generated from: '<S141>/Vector Concatenate' */
  memcpy(&rtb_VectorConcatenate[11], &rtb_TmpSignalConversionAtSFunct[0], 11U *
         sizeof(real_T));

  /* RateTransition: '<S152>/Rate Transition3' incorporates:
   *  Constant: '<S142>/Inertia Scaling'
   *  Constant: '<S142>/LMUy'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = rtb_front_wheel_angle_single__g;
  RateTransition3[1] = rtb_Switch;
  RateTransition3[2] = rtb_Switch_bb;
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
  for (sigIdx = 0; sigIdx < 2; sigIdx++) {
    memcpy(&rtDW.CFunction[sigIdx * 13], &RateTransition3[0], 13U * sizeof
           (real_T));
  }

  /* End of CFunction: '<S152>/C Function' */

  /* Saturate: '<S143>/Saturation' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition1'
   */
  if (rtb_Integrator_ee <= 2.0) {
    rtb_Saturation1 = 2.0;
  } else {
    rtb_Saturation1 = rtb_Integrator_ee;
  }

  /* End of Saturate: '<S143>/Saturation' */

  /* Saturate: '<S143>/Saturation1' incorporates:
   *  Inport: '<Root>/vy'
   */
  if (rtU.vy > 5.0) {
    rtb_Integrator_o = 5.0;
  } else if (rtU.vy < -5.0) {
    rtb_Integrator_o = -5.0;
  } else {
    rtb_Integrator_o = rtU.vy;
  }

  /* End of Saturate: '<S143>/Saturation1' */

  /* Memory: '<S139>/Memory' incorporates:
   *  Abs: '<S245>/Abs'
   */
  rtb_Abs_p[0] = rtDW.Memory_PreviousInput[0];
  rtb_Abs_p[1] = rtDW.Memory_PreviousInput[1];
  rtb_Abs_p[2] = rtDW.Memory_PreviousInput[2];
  rtb_Abs_p[3] = rtDW.Memory_PreviousInput[3];

  /* SignalConversion generated from: '<S139>/C Caller1' */
  rtb_x[0] = rtb_Saturation1;
  rtb_x[1] = rtb_Integrator_o;

  /* Saturate: '<S143>/Saturation2' */
  if (yaw_rate > 4.0) {
    /* SignalConversion generated from: '<S139>/C Caller1' */
    rtb_x[2] = 4.0;
  } else if (yaw_rate < -4.0) {
    /* SignalConversion generated from: '<S139>/C Caller1' */
    rtb_x[2] = -4.0;
  } else {
    /* SignalConversion generated from: '<S139>/C Caller1' */
    rtb_x[2] = yaw_rate;
  }

  /* End of Saturate: '<S143>/Saturation2' */

  /* SignalConversion generated from: '<S139>/C Caller1' */
  rtb_x[3] = rtb_Abs_p[0];
  rtb_x[4] = rtb_Abs_p[1];
  rtb_x[5] = rtb_Abs_p[2];
  rtb_x[6] = rtb_Abs_p[3];

  /* Lookup_n-D: '<S275>/Max_Torque_Overload_Motor_LUT' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Lookup_n-D: '<S275>/Max_Torque_Overload_Inverter_LUT'
   *  Lookup_n-D: '<S276>/Display Overload Inverter LUT'
   *  Lookup_n-D: '<S276>/Display Overload Motor LUT'
   */
  rtb_Abs = look1_binlx(0.0, rtConstP.pooled46, rtConstP.pooled45, 2U);
  rtb_Braking[0] = rtb_Abs;
  rtb_Braking[1] = rtb_Abs;
  rtb_Braking[2] = rtb_Abs;
  rtb_Braking[3] = rtb_Abs;

  /* Lookup_n-D: '<S275>/Max_Torque_Overload_Inverter_LUT' */
  rtb_Divide_a[0] = rtb_Abs;
  rtb_Divide_a[1] = rtb_Abs;
  rtb_Divide_a[2] = rtb_Abs;
  rtb_Divide_a[3] = rtb_Abs;

  /* RelationalOperator: '<S284>/Compare' incorporates:
   *  Constant: '<S281>/Time constant'
   *  Constant: '<S284>/Constant'
   *  Sum: '<S281>/Sum1'
   */
  rtb_Compare = (0.079577471545947673 - rtDW.Probe[0] <= 0.0);

  /* Gain: '<S278>/Gain4' incorporates:
   *  Gain: '<S287>/Gain4'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  z = 128.91550390443524 * rtU.omega_wheels_FL;
  rtb_Saturation1 = 128.91550390443524 * rtU.omega_wheels_FR;
  u0_tmp = 128.91550390443524 * rtU.omega_wheels_RL;
  u0_tmp_0 = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Lookup_n-D: '<S278>/2-D Lookup Table' incorporates:
   *  Constant: '<S275>/Constant7'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &rtb_Integrator_o);
  fractions[1U] = rtb_Integrator_o;

  /* Saturate: '<S278>/Saturation1' incorporates:
   *  Gain: '<S278>/Gain4'
   */
  if (z <= 0.0) {
    u0 = 0.0;
  } else {
    u0 = z;
  }

  /* Lookup_n-D: '<S278>/2-D Lookup Table' */
  bpIndices[0U] = plook_binc(u0, rtConstP.pooled14, 200U, &rtb_Integrator_o);
  fractions[0U] = rtb_Integrator_o;
  rtb_UnaryMinus_f_idx_0 = intrp2d_l(bpIndices, fractions, rtConstP.pooled13,
    201U);

  /* Saturate: '<S278>/Saturation1' incorporates:
   *  Gain: '<S278>/Gain4'
   */
  if (rtb_Saturation1 <= 0.0) {
    u0 = 0.0;
  } else {
    u0 = rtb_Saturation1;
  }

  /* Lookup_n-D: '<S278>/2-D Lookup Table' */
  bpIndices[0U] = plook_binc(u0, rtConstP.pooled14, 200U, &rtb_Integrator_o);
  fractions[0U] = rtb_Integrator_o;
  rtb_UnaryMinus_f_idx_1 = intrp2d_l(bpIndices, fractions, rtConstP.pooled13,
    201U);

  /* Saturate: '<S278>/Saturation1' incorporates:
   *  Gain: '<S278>/Gain4'
   */
  if (u0_tmp <= 0.0) {
    u0 = 0.0;
  } else {
    u0 = u0_tmp;
  }

  /* Lookup_n-D: '<S278>/2-D Lookup Table' */
  bpIndices[0U] = plook_binc(u0, rtConstP.pooled14, 200U, &rtb_Integrator_o);
  fractions[0U] = rtb_Integrator_o;
  rtb_UnaryMinus_f_idx_2 = intrp2d_l(bpIndices, fractions, rtConstP.pooled13,
    201U);

  /* Saturate: '<S278>/Saturation1' incorporates:
   *  Gain: '<S278>/Gain4'
   */
  if (u0_tmp_0 <= 0.0) {
    u0 = 0.0;
  } else {
    u0 = u0_tmp_0;
  }

  /* Lookup_n-D: '<S278>/2-D Lookup Table' */
  bpIndices[0U] = plook_binc(u0, rtConstP.pooled14, 200U, &rtb_Integrator_o);
  fractions[0U] = rtb_Integrator_o;

  /* Gain: '<S278>/Gain' incorporates:
   *  Lookup_n-D: '<S278>/2-D Lookup Table'
   */
  rtb_Gain_d1_idx_0 = 0.0098000000000000014 * rtb_UnaryMinus_f_idx_0;
  rtb_Gain_d1_idx_1 = 0.0098000000000000014 * rtb_UnaryMinus_f_idx_1;
  rtb_Gain_d1_idx_2 = 0.0098000000000000014 * rtb_UnaryMinus_f_idx_2;
  rtb_Gain_d1_idx_3 = 0.0098000000000000014 * intrp2d_l(bpIndices, fractions,
    rtConstP.pooled13, 201U);

  /* DiscreteIntegrator: '<S286>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE_d[0] = rtb_Gain_d1_idx_0;
    rtDW.Integrator_DSTATE_d[1] = rtb_Gain_d1_idx_1;
    rtDW.Integrator_DSTATE_d[2] = rtb_Gain_d1_idx_2;
    rtDW.Integrator_DSTATE_d[3] = rtb_Gain_d1_idx_3;
  }

  if (rtb_Compare || (rtDW.Integrator_PrevResetState_i != 0)) {
    rtDW.Integrator_DSTATE_d[0] = rtb_Gain_d1_idx_0;
    rtDW.Integrator_DSTATE_d[1] = rtb_Gain_d1_idx_1;
    rtDW.Integrator_DSTATE_d[2] = rtb_Gain_d1_idx_2;
    rtDW.Integrator_DSTATE_d[3] = rtb_Gain_d1_idx_3;
  }

  Switch2_h_idx_0 = rtDW.Integrator_DSTATE_d[0];
  Switch2_h_idx_1 = rtDW.Integrator_DSTATE_d[1];
  Switch2_h_idx_2 = rtDW.Integrator_DSTATE_d[2];
  Switch2_h_idx_3 = rtDW.Integrator_DSTATE_d[3];

  /* MinMax: '<S275>/Min' incorporates:
   *  Constant: '<S278>/Constant'
   *  DiscreteIntegrator: '<S286>/Integrator'
   *  RelationalOperator: '<S280>/LowerRelop1'
   *  RelationalOperator: '<S280>/UpperRelop'
   *  Switch: '<S280>/Switch'
   *  Switch: '<S280>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_d[0] > 21.0) {
    Faeroz = 21.0;
  } else if (rtDW.Integrator_DSTATE_d[0] < 0.0) {
    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S278>/Constant'
     */
    Faeroz = 0.0;
  } else {
    Faeroz = rtDW.Integrator_DSTATE_d[0];
  }

  u0 = fmin(fmin(fmin(rtb_Braking[0], rtb_Divide_a[0]), 20.972), Faeroz);

  /* Saturate: '<S275>/Saturation_Positive' incorporates:
   *  MinMax: '<S275>/Min'
   */
  if (u0 <= 0.0) {
    rtb_Braking[0] = 0.0;
  } else {
    rtb_Braking[0] = u0;
  }

  /* MinMax: '<S275>/Min' incorporates:
   *  Constant: '<S278>/Constant'
   *  DiscreteIntegrator: '<S286>/Integrator'
   *  RelationalOperator: '<S280>/LowerRelop1'
   *  RelationalOperator: '<S280>/UpperRelop'
   *  Switch: '<S280>/Switch'
   *  Switch: '<S280>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_d[1] > 21.0) {
    Faeroz = 21.0;
  } else if (rtDW.Integrator_DSTATE_d[1] < 0.0) {
    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S278>/Constant'
     */
    Faeroz = 0.0;
  } else {
    Faeroz = rtDW.Integrator_DSTATE_d[1];
  }

  u0 = fmin(fmin(fmin(rtb_Braking[1], rtb_Divide_a[1]), 20.972), Faeroz);

  /* Saturate: '<S275>/Saturation_Positive' incorporates:
   *  MinMax: '<S275>/Min'
   */
  if (u0 <= 0.0) {
    rtb_Braking[1] = 0.0;
  } else {
    rtb_Braking[1] = u0;
  }

  /* MinMax: '<S275>/Min' incorporates:
   *  Constant: '<S278>/Constant'
   *  DiscreteIntegrator: '<S286>/Integrator'
   *  RelationalOperator: '<S280>/LowerRelop1'
   *  RelationalOperator: '<S280>/UpperRelop'
   *  Switch: '<S280>/Switch'
   *  Switch: '<S280>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_d[2] > 21.0) {
    Faeroz = 21.0;
  } else if (rtDW.Integrator_DSTATE_d[2] < 0.0) {
    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S278>/Constant'
     */
    Faeroz = 0.0;
  } else {
    Faeroz = rtDW.Integrator_DSTATE_d[2];
  }

  u0 = fmin(fmin(fmin(rtb_Braking[2], rtb_Divide_a[2]), 20.972), Faeroz);

  /* Saturate: '<S275>/Saturation_Positive' incorporates:
   *  MinMax: '<S275>/Min'
   */
  if (u0 <= 0.0) {
    rtb_Braking[2] = 0.0;
  } else {
    rtb_Braking[2] = u0;
  }

  /* MinMax: '<S275>/Min' incorporates:
   *  Constant: '<S278>/Constant'
   *  DiscreteIntegrator: '<S286>/Integrator'
   *  RelationalOperator: '<S280>/LowerRelop1'
   *  RelationalOperator: '<S280>/UpperRelop'
   *  Switch: '<S280>/Switch'
   *  Switch: '<S280>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_d[3] > 21.0) {
    Faeroz = 21.0;
  } else if (rtDW.Integrator_DSTATE_d[3] < 0.0) {
    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S278>/Constant'
     */
    Faeroz = 0.0;
  } else {
    Faeroz = rtDW.Integrator_DSTATE_d[3];
  }

  u0 = fmin(fmin(fmin(rtb_Braking[3], rtb_Divide_a[3]), 20.972), Faeroz);

  /* Saturate: '<S275>/Saturation_Positive' incorporates:
   *  MinMax: '<S275>/Min'
   */
  if (u0 <= 0.0) {
    rtb_Braking[3] = 0.0;
  } else {
    rtb_Braking[3] = u0;
  }

  /* Gain: '<S261>/Lateral Load Transfer' incorporates:
   *  Gain: '<S262>/Lateral Load Transfer'
   *  Gain: '<S263>/Lateral Load Transfer'
   *  Gain: '<S264>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S261>/Unary Minus'
   */
  dT = 30.826771653543307 * -rtU.ay;

  /* Gain: '<S261>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S262>/Longitudinal Load Transfer'
   *  Gain: '<S263>/Longitudinal Load Transfer'
   *  Gain: '<S264>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S261>/Unary Minus1'
   */
  rtb_UnaryMinus_f_idx_3 = 25.588235294117645 * -rtU.ax;

  /* SignalConversion generated from: '<S253>/2-D Lookup Table' incorporates:
   *  Constant: '<S261>/Static Load Front'
   *  Constant: '<S262>/Static Load Front'
   *  Constant: '<S263>/Static Load Front'
   *  Constant: '<S264>/Static Load Front'
   *  Gain: '<S261>/Drag moment'
   *  Gain: '<S261>/Lateral Load Transfer'
   *  Gain: '<S261>/Lift Force'
   *  Gain: '<S261>/Longitudinal Load Transfer'
   *  Gain: '<S262>/Drag moment'
   *  Gain: '<S262>/Lift Force'
   *  Gain: '<S263>/Drag moment'
   *  Gain: '<S263>/Lift Force'
   *  Gain: '<S264>/Drag moment'
   *  Gain: '<S264>/Lift Force'
   *  Math: '<S261>/Square1'
   *  Math: '<S261>/Square2'
   *  Math: '<S262>/Square1'
   *  Math: '<S262>/Square2'
   *  Math: '<S263>/Square1'
   *  Math: '<S263>/Square2'
   *  Math: '<S264>/Square1'
   *  Math: '<S264>/Square2'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   *  Sum: '<S261>/Subtract'
   *  Sum: '<S262>/Subtract'
   *  Sum: '<S263>/Subtract'
   *  Sum: '<S264>/Subtract'
   */
  rtb_UnaryMinus_f_idx_0 = ((rtb_Integrator_ee * rtb_Integrator_ee *
    0.92446666666666677 + (dT + 635.688)) - rtb_Integrator_ee *
    rtb_Integrator_ee * 0.21998117647058821) + rtb_UnaryMinus_f_idx_3;
  rtb_UnaryMinus_f_idx_1 = ((rtb_Integrator_ee * rtb_Integrator_ee *
    0.92446666666666677 + (635.688 - dT)) - rtb_Integrator_ee *
    rtb_Integrator_ee * 0.21998117647058821) + rtb_UnaryMinus_f_idx_3;
  rtb_UnaryMinus_f_idx_2 = ((rtb_Integrator_ee * rtb_Integrator_ee *
    0.74153333333333349 + (dT + 688.66200000000015)) + rtb_Integrator_ee *
    rtb_Integrator_ee * 0.21998117647058821) - rtb_UnaryMinus_f_idx_3;
  rtb_UnaryMinus_f_idx_3 = ((rtb_Integrator_ee * rtb_Integrator_ee *
    0.74153333333333349 + (688.66200000000015 - dT)) + rtb_Integrator_ee *
    rtb_Integrator_ee * 0.21998117647058821) - rtb_UnaryMinus_f_idx_3;

  /* Switch: '<S260>/Switch' incorporates:
   *  Constant: '<S260>/Constant'
   *  Gain: '<S265>/Gain1'
   *  Gain: '<S266>/Gain1'
   *  Gain: '<S267>/Gain1'
   *  Gain: '<S268>/Gain1'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   *  Sum: '<S265>/Subtract'
   *  Sum: '<S265>/Subtract1'
   *  Sum: '<S265>/Subtract2'
   *  Sum: '<S266>/Subtract'
   *  Sum: '<S266>/Subtract2'
   *  Sum: '<S267>/Subtract'
   *  Sum: '<S267>/Subtract1'
   *  Sum: '<S268>/Subtract'
   *  Trigonometry: '<S265>/Atan'
   *  Trigonometry: '<S266>/Atan'
   *  Trigonometry: '<S267>/Atan'
   *  Trigonometry: '<S268>/Atan'
   */
  if (rtb_Integrator_ee > 3.0) {
    /* Sum: '<S265>/Subtract1' incorporates:
     *  Gain: '<S265>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S266>/Subtract1'
     */
    dT = 0.73439999999999994 * yaw_rate + rtU.vy;
    rtb_Divide_a[0] = rt_atan2d_snf(dT, rtb_Integrator_ee - 0.635 * yaw_rate) -
      rtb_Abs_fc_idx_0;
    rtb_Divide_a[1] = rt_atan2d_snf(dT, 0.635 * yaw_rate + rtb_Integrator_ee) -
      rtb_Abs_g;

    /* Sum: '<S267>/Subtract1' incorporates:
     *  Gain: '<S265>/Gain1'
     *  Gain: '<S266>/Gain1'
     *  Gain: '<S267>/Gain'
     *  Inport: '<Root>/vy'
     *  Sum: '<S265>/Subtract'
     *  Sum: '<S265>/Subtract1'
     *  Sum: '<S265>/Subtract2'
     *  Sum: '<S266>/Subtract'
     *  Sum: '<S266>/Subtract2'
     *  Sum: '<S268>/Subtract1'
     *  Trigonometry: '<S265>/Atan'
     *  Trigonometry: '<S266>/Atan'
     */
    dT = rtU.vy - 0.79560000000000008 * yaw_rate;
    rtb_Divide_a[2] = rt_atan2d_snf(dT, rtb_Integrator_ee - 0.635 * yaw_rate);
    rtb_Divide_a[3] = rt_atan2d_snf(dT, 0.635 * yaw_rate + rtb_Integrator_ee);
  } else {
    rtb_Divide_a[0] = 0.0;
    rtb_Divide_a[1] = 0.0;
    rtb_Divide_a[2] = 0.0;
    rtb_Divide_a[3] = 0.0;
  }

  /* End of Switch: '<S260>/Switch' */

  /* Lookup_n-D: '<S253>/2-D Lookup Table' */
  rtb_lbx_out[0] = look2_binlx(rtb_UnaryMinus_f_idx_0, rtb_Divide_a[0],
    rtConstP.pooled53, rtConstP.pooled54, rtConstP.uDLookupTable_tableData_m,
    rtConstP.pooled66, 30U);
  rtb_lbx_out[1] = look2_binlx(rtb_UnaryMinus_f_idx_1, rtb_Divide_a[1],
    rtConstP.pooled53, rtConstP.pooled54, rtConstP.uDLookupTable_tableData_m,
    rtConstP.pooled66, 30U);
  rtb_lbx_out[2] = look2_binlx(rtb_UnaryMinus_f_idx_2, rtb_Divide_a[2],
    rtConstP.pooled53, rtConstP.pooled54, rtConstP.uDLookupTable_tableData_m,
    rtConstP.pooled66, 30U);
  rtb_lbx_out[3] = look2_binlx(rtb_UnaryMinus_f_idx_3, rtb_Divide_a[3],
    rtConstP.pooled53, rtConstP.pooled54, rtConstP.uDLookupTable_tableData_m,
    rtConstP.pooled66, 30U);

  /* Switch: '<S247>/Switch' */
  dT = !(rtb_Saturation > 0.95);

  /* Product: '<S253>/Product' incorporates:
   *  Gain: '<S253>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_lbx_out[0] * 20.0;

  /* Saturate: '<S253>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S247>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_Tnew[0] = fmin(fmin(rtb_Braking[0], rtDW.UnitDelay1_DSTATE[0]), u0) * dT;

  /* Product: '<S253>/Product' incorporates:
   *  Gain: '<S253>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_lbx_out[1] * 20.0;

  /* Saturate: '<S253>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S247>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_Tnew[1] = fmin(fmin(rtb_Braking[1], rtDW.UnitDelay1_DSTATE[1]), u0) * dT;

  /* Product: '<S253>/Product' incorporates:
   *  Gain: '<S253>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_lbx_out[2] * 20.0;

  /* Saturate: '<S253>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S247>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_Tnew[2] = fmin(fmin(rtb_Braking[2], rtDW.UnitDelay1_DSTATE[2]), u0) * dT;

  /* Product: '<S253>/Product' incorporates:
   *  Gain: '<S253>/Gain'
   */
  u0 = 0.017407407407407406 * rtb_lbx_out[3] * 20.0;

  /* Saturate: '<S253>/Saturation1' */
  if (u0 <= 0.0) {
    u0 = 0.0;
  }

  /* Product: '<S247>/Product' incorporates:
   *  MinMax: '<S150>/Min'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_Tnew[3] = fmin(fmin(rtb_Braking[3], rtDW.UnitDelay1_DSTATE[3]), u0) * dT;

  /* Lookup_n-D: '<S253>/2-D Lookup Table1' */
  dT = look2_binlx(rtb_UnaryMinus_f_idx_0, rtb_Divide_a[0], rtConstP.pooled53,
                   rtConstP.pooled54, rtConstP.uDLookupTable1_tableData,
                   rtConstP.pooled66, 30U);
  rtb_UnaryMinus_f_idx_1 = look2_binlx(rtb_UnaryMinus_f_idx_1, rtb_Divide_a[1],
    rtConstP.pooled53, rtConstP.pooled54, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled66, 30U);
  rtb_UnaryMinus_f_idx_2 = look2_binlx(rtb_UnaryMinus_f_idx_2, rtb_Divide_a[2],
    rtConstP.pooled53, rtConstP.pooled54, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled66, 30U);
  rtb_UnaryMinus_f_idx_0 = look2_binlx(rtb_UnaryMinus_f_idx_3, rtb_Divide_a[3],
    rtConstP.pooled53, rtConstP.pooled54, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled66, 30U);

  /* Product: '<S253>/Product1' incorporates:
   *  Gain: '<S253>/Gain1'
   */
  rtb_lbx_out[0] = 0.017407407407407406 * dT * 20.0;
  rtb_lbx_out[1] = 0.017407407407407406 * rtb_UnaryMinus_f_idx_1 * 20.0;
  rtb_lbx_out[2] = 0.017407407407407406 * rtb_UnaryMinus_f_idx_2 * 20.0;
  rtb_lbx_out[3] = 0.017407407407407406 * rtb_UnaryMinus_f_idx_0 * 20.0;

  /* Lookup_n-D: '<S276>/Display Overload Inverter LUT' */
  rtb_Divide_a[0] = rtb_Abs;
  rtb_Divide_a[1] = rtb_Abs;
  rtb_Divide_a[2] = rtb_Abs;
  rtb_Divide_a[3] = rtb_Abs;

  /* RelationalOperator: '<S293>/Compare' incorporates:
   *  Constant: '<S290>/Time constant'
   *  Constant: '<S293>/Constant'
   *  Sum: '<S290>/Sum1'
   */
  rtb_Compare_m = (0.079577471545947673 - rtDW.Probe_b[0] <= 0.0);

  /* Saturate: '<S287>/Saturation1' */
  if (z <= 0.0) {
    rtb_Braking[0] = 0.0;
  } else {
    rtb_Braking[0] = z;
  }

  if (rtb_Saturation1 <= 0.0) {
    rtb_Braking[1] = 0.0;
  } else {
    rtb_Braking[1] = rtb_Saturation1;
  }

  if (u0_tmp <= 0.0) {
    rtb_Braking[2] = 0.0;
  } else {
    rtb_Braking[2] = u0_tmp;
  }

  if (u0_tmp_0 <= 0.0) {
    rtb_Braking[3] = 0.0;
  } else {
    rtb_Braking[3] = u0_tmp_0;
  }

  /* End of Saturate: '<S287>/Saturation1' */

  /* Lookup_n-D: '<S287>/2-D Lookup Table' incorporates:
   *  Constant: '<S276>/Constant7'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled15, 45U, &rtb_Integrator_o);
  fractions_0[1U] = rtb_Integrator_o;
  bpIndices_0[0U] = plook_binc(rtb_Braking[0], rtConstP.pooled14, 200U,
    &rtb_Integrator_o);
  fractions_0[0U] = rtb_Integrator_o;
  rtb_Braking[0] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Braking[1], rtConstP.pooled14, 200U,
    &rtb_Integrator_o);
  fractions_0[0U] = rtb_Integrator_o;
  rtb_Braking[1] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Braking[2], rtConstP.pooled14, 200U,
    &rtb_Integrator_o);
  fractions_0[0U] = rtb_Integrator_o;
  rtb_Braking[2] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Braking[3], rtConstP.pooled14, 200U,
    &rtb_Integrator_o);
  fractions_0[0U] = rtb_Integrator_o;
  rtb_Braking[3] = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled13, 201U);

  /* Gain: '<S287>/Gain' */
  eta_idx_0 = 0.0098000000000000014 * rtb_Braking[0];
  eta_idx_1 = 0.0098000000000000014 * rtb_Braking[1];
  eta_idx_2 = 0.0098000000000000014 * rtb_Braking[2];
  eta_idx_3 = 0.0098000000000000014 * rtb_Braking[3];

  /* DiscreteIntegrator: '<S295>/Integrator' */
  if (rtDW.Integrator_IC_LOADING_b != 0) {
    rtDW.Integrator_DSTATE_i[0] = eta_idx_0;
    rtDW.Integrator_DSTATE_i[1] = eta_idx_1;
    rtDW.Integrator_DSTATE_i[2] = eta_idx_2;
    rtDW.Integrator_DSTATE_i[3] = eta_idx_3;
  }

  if (rtb_Compare_m || (rtDW.Integrator_PrevResetState_b != 0)) {
    rtDW.Integrator_DSTATE_i[0] = eta_idx_0;
    rtDW.Integrator_DSTATE_i[1] = eta_idx_1;
    rtDW.Integrator_DSTATE_i[2] = eta_idx_2;
    rtDW.Integrator_DSTATE_i[3] = eta_idx_3;
  }

  rtb_UnaryMinus_f_idx_2 = rtDW.Integrator_DSTATE_i[0];
  rtb_UnaryMinus_f_idx_1 = rtDW.Integrator_DSTATE_i[1];
  rtb_UnaryMinus_f_idx_0 = rtDW.Integrator_DSTATE_i[2];
  rtb_UnaryMinus_f_idx_3 = rtDW.Integrator_DSTATE_i[3];

  /* Saturate: '<S253>/Saturation' incorporates:
   *  Gain: '<S269>/Wheel2Motor'
   *  Sum: '<S269>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[0] + rtb_lbx_out[0];

  /* MinMax: '<S276>/Min1' incorporates:
   *  Constant: '<S287>/Constant'
   *  DiscreteIntegrator: '<S295>/Integrator'
   *  RelationalOperator: '<S289>/LowerRelop1'
   *  RelationalOperator: '<S289>/UpperRelop'
   *  Sum: '<S269>/Subtract'
   *  Switch: '<S289>/Switch'
   *  Switch: '<S289>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_i[0] > 21.0) {
    Faeroz = 21.0;
  } else if (rtDW.Integrator_DSTATE_i[0] < 0.0) {
    /* Switch: '<S289>/Switch' incorporates:
     *  Constant: '<S287>/Constant'
     */
    Faeroz = 0.0;
  } else {
    Faeroz = rtDW.Integrator_DSTATE_i[0];
  }

  dT = fmin(fmin(fmin(rtb_Abs, rtb_Divide_a[0]), 20.972), Faeroz);

  /* Saturate: '<S253>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S276>/Saturation_Positive' */
  if (dT <= 0.0) {
    dT = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  Sum: '<S269>/Subtract'
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Divide_a[0] = fmax(fmax(u0, -dT), rtDW.UnitDelay2_DSTATE[0]);

  /* Saturate: '<S253>/Saturation' incorporates:
   *  Gain: '<S269>/Wheel2Motor'
   *  Sum: '<S269>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[1] + rtb_lbx_out[1];

  /* MinMax: '<S276>/Min1' incorporates:
   *  Constant: '<S287>/Constant'
   *  DiscreteIntegrator: '<S295>/Integrator'
   *  RelationalOperator: '<S289>/LowerRelop1'
   *  RelationalOperator: '<S289>/UpperRelop'
   *  Sum: '<S269>/Subtract'
   *  Switch: '<S289>/Switch'
   *  Switch: '<S289>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_i[1] > 21.0) {
    Faeroz = 21.0;
  } else if (rtDW.Integrator_DSTATE_i[1] < 0.0) {
    /* Switch: '<S289>/Switch' incorporates:
     *  Constant: '<S287>/Constant'
     */
    Faeroz = 0.0;
  } else {
    Faeroz = rtDW.Integrator_DSTATE_i[1];
  }

  dT = fmin(fmin(fmin(rtb_Abs, rtb_Divide_a[1]), 20.972), Faeroz);

  /* Saturate: '<S253>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S276>/Saturation_Positive' */
  if (dT <= 0.0) {
    dT = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  Sum: '<S269>/Subtract'
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Divide_a[1] = fmax(fmax(u0, -dT), rtDW.UnitDelay2_DSTATE[1]);

  /* Saturate: '<S253>/Saturation' incorporates:
   *  Gain: '<S269>/Wheel2Motor'
   *  Sum: '<S269>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[2] + rtb_lbx_out[2];

  /* MinMax: '<S276>/Min1' incorporates:
   *  Constant: '<S287>/Constant'
   *  DiscreteIntegrator: '<S295>/Integrator'
   *  RelationalOperator: '<S289>/LowerRelop1'
   *  RelationalOperator: '<S289>/UpperRelop'
   *  Sum: '<S269>/Subtract'
   *  Switch: '<S289>/Switch'
   *  Switch: '<S289>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_i[2] > 21.0) {
    Faeroz = 21.0;
  } else if (rtDW.Integrator_DSTATE_i[2] < 0.0) {
    /* Switch: '<S289>/Switch' incorporates:
     *  Constant: '<S287>/Constant'
     */
    Faeroz = 0.0;
  } else {
    Faeroz = rtDW.Integrator_DSTATE_i[2];
  }

  dT = fmin(fmin(fmin(rtb_Abs, rtb_Divide_a[2]), 20.972), Faeroz);

  /* Saturate: '<S253>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S276>/Saturation_Positive' */
  if (dT <= 0.0) {
    dT = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  Sum: '<S269>/Subtract'
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Divide_a[2] = fmax(fmax(u0, -dT), rtDW.UnitDelay2_DSTATE[2]);

  /* Saturate: '<S253>/Saturation' incorporates:
   *  Gain: '<S269>/Wheel2Motor'
   *  Sum: '<S269>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0 = 0.07407407407407407 * rtDW.UnitDelay_DSTATE[3] + rtb_lbx_out[3];

  /* MinMax: '<S276>/Min1' incorporates:
   *  Constant: '<S287>/Constant'
   *  DiscreteIntegrator: '<S295>/Integrator'
   *  RelationalOperator: '<S289>/LowerRelop1'
   *  RelationalOperator: '<S289>/UpperRelop'
   *  Sum: '<S269>/Subtract'
   *  Switch: '<S289>/Switch'
   *  Switch: '<S289>/Switch2'
   */
  if (rtDW.Integrator_DSTATE_i[3] > 21.0) {
    Faeroz = 21.0;
  } else if (rtDW.Integrator_DSTATE_i[3] < 0.0) {
    /* Switch: '<S289>/Switch' incorporates:
     *  Constant: '<S287>/Constant'
     */
    Faeroz = 0.0;
  } else {
    Faeroz = rtDW.Integrator_DSTATE_i[3];
  }

  dT = fmin(fmin(fmin(rtb_Abs, rtb_Divide_a[3]), 20.972), Faeroz);

  /* Saturate: '<S253>/Saturation' */
  if (u0 >= 0.0) {
    u0 = 0.0;
  }

  /* Saturate: '<S276>/Saturation_Positive' */
  if (dT <= 0.0) {
    dT = 0.0;
  }

  /* MinMax: '<S150>/Min1' incorporates:
   *  Sum: '<S269>/Subtract'
   *  UnaryMinus: '<S150>/Unary Minus'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_Divide_a[3] = fmax(fmax(u0, -dT), rtDW.UnitDelay2_DSTATE[3]);

  /* CombinatorialLogic: '<S255>/Logic' incorporates:
   *  Constant: '<S246>/Constant'
   *  Constant: '<S246>/Constant1'
   *  Memory: '<S255>/Memory'
   *  RelationalOperator: '<S246>/Less Than'
   *  RelationalOperator: '<S246>/Less Than1'
   */
  idx = (int32_T)(((((uint32_T)(rtb_Switch <= -0.6) << 1) + (rtb_Switch >= -0.5))
                   << 1) + rtDW.Memory_PreviousInput_i);
  rtb_Logic_idx_0 = rtConstP.pooled69[(uint32_T)idx];
  rtb_Logic_idx_1 = rtConstP.pooled69[idx + 8U];

  /* CombinatorialLogic: '<S256>/Logic' incorporates:
   *  Constant: '<S246>/Constant'
   *  Constant: '<S246>/Constant1'
   *  Memory: '<S256>/Memory'
   *  RelationalOperator: '<S246>/Less Than'
   *  RelationalOperator: '<S246>/Less Than1'
   */
  idx = (int32_T)(((((uint32_T)(rtb_Switch_bb <= -0.6) << 1) + (rtb_Switch_bb >=
    -0.5)) << 1) + rtDW.Memory_PreviousInput_j);
  rtb_Logic_b_idx_0 = rtConstP.pooled69[(uint32_T)idx];
  rtb_Logic_b_idx_1 = rtConstP.pooled69[idx + 8U];

  /* CombinatorialLogic: '<S257>/Logic' incorporates:
   *  Constant: '<S246>/Constant'
   *  Constant: '<S246>/Constant1'
   *  Memory: '<S257>/Memory'
   *  RelationalOperator: '<S246>/Less Than'
   *  RelationalOperator: '<S246>/Less Than1'
   */
  idx = (int32_T)(((((uint32_T)(rtb_RL <= -0.6) << 1) + (rtb_RL >= -0.5)) << 1)
                  + rtDW.Memory_PreviousInput_f);
  rtb_Logic_o_idx_0 = rtConstP.pooled69[(uint32_T)idx];
  rtb_Logic_o_idx_1 = rtConstP.pooled69[idx + 8U];

  /* CombinatorialLogic: '<S258>/Logic' incorporates:
   *  Constant: '<S246>/Constant'
   *  Constant: '<S246>/Constant1'
   *  Memory: '<S258>/Memory'
   *  RelationalOperator: '<S246>/Less Than'
   *  RelationalOperator: '<S246>/Less Than1'
   */
  idx = (int32_T)(((((uint32_T)(rtb_RR <= -0.6) << 1) + (rtb_RR >= -0.5)) << 1)
                  + rtDW.Memory_PreviousInput_ib);
  rtb_Logic_p_idx_0 = rtConstP.pooled69[(uint32_T)idx];

  /* Product: '<S246>/Product' incorporates:
   *  CombinatorialLogic: '<S258>/Logic'
   */
  rtb_Braking[0] = rtb_Divide_a[0] * (real_T)rtb_Logic_idx_1;
  rtb_Braking[1] = rtb_Divide_a[1] * (real_T)rtb_Logic_b_idx_1;
  rtb_Braking[2] = (real_T)rtb_Logic_o_idx_1 * rtb_Divide_a[2];
  rtb_Braking[3] = (real_T)rtConstP.pooled69[idx + 8U] * rtb_Divide_a[3];

  /* Abs: '<S171>/Abs' */
  rtb_Abs = fabs(rtb_front_wheel_angle_single__g);

  /* MATLABSystem: '<S171>/Moving Average' */
  if (rtDW.obj.TunablePropsChanged) {
    rtDW.obj.TunablePropsChanged = false;
  }

  obj = rtDW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (idx = 0; idx < 24; idx++) {
      obj->pCumSumRev[idx] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (idx = 0; idx < 24; idx++) {
      obj->pCumSumRev[idx] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  dT = obj->pCumRevIndex;
  rtb_Integrator_o = obj->pCumSum;
  for (idx = 0; idx < 24; idx++) {
    csumrev[idx] = obj->pCumSumRev[idx];
  }

  modValueRev = obj->pModValueRev;
  z = 0.0;
  rtb_Saturation1 = 0.0;
  rtb_Integrator_o += rtb_Abs;
  if (modValueRev == 0.0) {
    z = csumrev[(int32_T)dT - 1] + rtb_Integrator_o;
  }

  csumrev[(int32_T)dT - 1] = rtb_Abs;
  if (dT != 24.0) {
    dT++;
  } else {
    dT = 1.0;
    rtb_Integrator_o = 0.0;
    for (sigIdx = 22; sigIdx >= 0; sigIdx--) {
      csumrev[sigIdx] += csumrev[sigIdx + 1];
    }
  }

  if (modValueRev == 0.0) {
    rtb_Saturation1 = z / 25.0;
  }

  obj->pCumSum = rtb_Integrator_o;
  for (idx = 0; idx < 24; idx++) {
    obj->pCumSumRev[idx] = csumrev[idx];
  }

  obj->pCumRevIndex = dT;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* CombinatorialLogic: '<S231>/Logic' incorporates:
   *  Constant: '<S171>/Constant1'
   *  Constant: '<S171>/Constant4'
   *  Delay: '<S171>/Delay'
   *  Logic: '<S171>/AND'
   *  MATLABSystem: '<S171>/Moving Average'
   *  Memory: '<S231>/Memory'
   *  RelationalOperator: '<S171>/Less Than'
   *  RelationalOperator: '<S171>/Less Than2'
   */
  rtb_Logic_idx_1 = rtConstP.pooled69[((((uint32_T)(0.017453292519943295 <=
    rtb_Abs) << 1) + ((rtb_Saturation1 < 0.0043633231299858239) &&
                      rtDW.Delay_DSTATE[0])) << 1) + rtDW.Memory_PreviousInput_a];

  /* Outputs for IfAction SubSystem: '<S171>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S230>/Action Port'
   */
  /* If: '<S171>/If' incorporates:
   *  Constant: '<S171>/Constant'
   *  DataTypeConversion: '<S230>/Data Type Conversion'
   *  Logic: '<S171>/AND1'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   *  RelationalOperator: '<S171>/Less Than1'
   */
  rtb_Logic_b_idx_1 = (rtb_Logic_idx_1 && (rtb_Integrator_ee >= 3.0));

  /* End of Outputs for SubSystem: '<S171>/If Action Subsystem1' */

  /* SignalConversion generated from: '<S250>/ SFunction ' incorporates:
   *  MATLAB Function: '<S150>/Cross Check'
   */
  dT = rtb_Braking[1];

  /* MATLAB Function: '<S150>/Cross Check' incorporates:
   *  Inport: '<Root>/brake'
   *  Inport: '<Root>/throttle'
   */
  rtb_lbx_out[0] = rtb_Braking[0];
  rtb_lbx_out[1] = rtb_Braking[1];
  rtb_lbx_out[2] = rtb_Braking[2];
  rtb_lbx_out[3] = rtb_Braking[3];
  if (rtb_Logic_b_idx_1) {
    idx = 0;
  } else {
    idx = 1;
  }

  if (idx == 0) {
    if (rtb_Braking[0] > rtb_Tnew[0]) {
      rtb_lbx_out[0] = rtb_Tnew[0] - dT;
    }

    if (rtb_Braking[1] > rtb_Tnew[1]) {
      rtb_lbx_out[1] = rtb_Tnew[1] - dT;
    }

    if (rtb_Braking[2] > rtb_Tnew[2]) {
      rtb_lbx_out[2] = rtb_Tnew[2] - dT;
    }

    if (rtb_Braking[3] > rtb_Tnew[3]) {
      rtb_lbx_out[3] = rtb_Tnew[3] - dT;
    }
  } else if (rtU.throttle > 0.05) {
    rtb_lbx_out[0] = 0.0;
    rtb_lbx_out[1] = 0.0;
    rtb_lbx_out[2] = 0.0;
    rtb_lbx_out[3] = 0.0;
  } else if (rtU.brake > 0.05) {
    rtb_Tnew[0] = 0.0;
    rtb_Tnew[1] = 0.0;
    rtb_Tnew[2] = 0.0;
    rtb_Tnew[3] = 0.0;
  }

  /* InitialCondition: '<S150>/IC1' */
  if (rtDW.IC1_FirstOutputTime) {
    rtDW.IC1_FirstOutputTime = false;
    rtb_lbx_out[0] = 0.0;
    rtb_lbx_out[1] = 0.0;
    rtb_lbx_out[2] = 0.0;
    rtb_lbx_out[3] = 0.0;
  }

  /* End of InitialCondition: '<S150>/IC1' */

  /* CFunction: '<S248>/C Function' incorporates:
   *  Constant: '<S248>/Constant3'
   */
  rtDW.CFunction_k[0] = rtb_lbx_out[0];
  rtDW.CFunction_k[1] = rtb_lbx_out[1];
  rtDW.CFunction_k[2] = rtb_lbx_out[2];
  rtDW.CFunction_k[3] = rtb_lbx_out[3];

  /* InitialCondition: '<S150>/IC' */
  if (rtDW.IC_FirstOutputTime) {
    rtDW.IC_FirstOutputTime = false;
    rtb_lbx_out[0] = 0.0;
    rtb_lbx_out[1] = 0.0;
    rtb_lbx_out[2] = 0.0;
    rtb_lbx_out[3] = 0.0;
  } else {
    rtb_lbx_out[0] = rtb_Tnew[0];
    rtb_lbx_out[1] = rtb_Tnew[1];
    rtb_lbx_out[2] = rtb_Tnew[2];
    rtb_lbx_out[3] = rtb_Tnew[3];
  }

  /* End of InitialCondition: '<S150>/IC' */

  /* CFunction: '<S249>/C Function' incorporates:
   *  Constant: '<S249>/Constant3'
   */
  rtDW.CFunction_h[0] = rtb_lbx_out[0];
  rtDW.CFunction_h[1] = rtb_lbx_out[1];
  rtDW.CFunction_h[2] = rtb_lbx_out[2];
  rtDW.CFunction_h[3] = rtb_lbx_out[3];

  /* Sum: '<S232>/Sum of Elements' */
  dT = ((rtDW.CFunction_h[0] + rtDW.CFunction_h[1]) + rtDW.CFunction_h[2]) +
    rtDW.CFunction_h[3];

  /* Product: '<S232>/Product' incorporates:
   *  Constant: '<S232>/Constant1'
   *  Constant: '<S232>/Constant2'
   *  Constant: '<S239>/Constant'
   *  Constant: '<S239>/Exponent < 0'
   *  Gain: '<S232>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S232>/ '
   *  Math: '<S239>/Power'
   *  Product: '<S232>/Product1'
   *  Product: '<S239>/Divide'
   *  Product: '<S239>/Divide1'
   *  RelationalOperator: '<S232>/Less Than'
   *  RelationalOperator: '<S232>/Less Than1'
   *  Sum: '<S232>/Subtract1'
   *  Sum: '<S239>/Subtract'
   *  Sum: '<S239>/Sum'
   */
  rtb_Integrator_o = (1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle),
    -1.5) + 1.0) - rtb_Saturation) * (real_T)(int8_T)((int8_T)(rtb_Saturation >=
    0.05) ^ (int8_T)(rtU.throttle >= 0.05)) * 84.0;

  /* Switch: '<S240>/Switch2' incorporates:
   *  RelationalOperator: '<S240>/LowerRelop1'
   */
  if (!(rtb_Integrator_o > dT)) {
    /* Sum: '<S232>/Sum of Elements1' */
    rtb_SumofElements1 = ((rtDW.CFunction_k[0] + rtDW.CFunction_k[1]) +
                          rtDW.CFunction_k[2]) + rtDW.CFunction_k[3];

    /* Switch: '<S240>/Switch' incorporates:
     *  RelationalOperator: '<S240>/UpperRelop'
     */
    if (rtb_Integrator_o < rtb_SumofElements1) {
      dT = rtb_SumofElements1;
    } else {
      dT = rtb_Integrator_o;
    }

    /* End of Switch: '<S240>/Switch' */
  }

  /* End of Switch: '<S240>/Switch2' */

  /* Gain: '<S232>/Gain2' */
  rtb_Abs = 0.95 * dT;

  /* Gain: '<S232>/Gain3' */
  z = 1.05 * dT;

  /* Switch: '<S233>/Switch2' incorporates:
   *  Constant: '<S233>/Engine Brake'
   *  Constant: '<S241>/Constant1'
   *  Constant: '<S241>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S241>/AND'
   *  MinMax: '<S233>/Max1'
   *  RelationalOperator: '<S241>/Less Than'
   *  RelationalOperator: '<S241>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_Saturation)) {
    dT = -0.0;
  } else {
    dT = fmin(rtb_Abs, z);
  }

  /* End of Switch: '<S233>/Switch2' */

  /* UnaryMinus: '<S234>/Unary Minus1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Saturate: '<S234>/Max Regen'
   */
  rtb_Saturation1 = -0.0;

  /* InitialCondition: '<S234>/IC' */
  if (rtDW.IC_FirstOutputTime_e) {
    rtDW.IC_FirstOutputTime_e = false;
    rtb_Saturation1 = -35000.0;
  }

  /* End of InitialCondition: '<S234>/IC' */

  /* Product: '<S234>/Divide1' incorporates:
   *  Constant: '<S234>/Constant'
   */
  rtb_SumofElements1 = 0.001 * rtb_Saturation1;

  /* Abs: '<S237>/Abs1' incorporates:
   *  Abs: '<S245>/Abs'
   *  Abs: '<S273>/Abs'
   */
  rtb_Saturation = fabs(rtb_Abs_p[1]);

  /* Abs: '<S237>/Abs3' incorporates:
   *  Abs: '<S245>/Abs'
   *  Abs: '<S273>/Abs'
   */
  rtb_Integrator_o = fabs(rtb_Abs_p[0]);

  /* MATLAB Function: '<S146>/MATLAB Function4' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function3'
   *  MATLAB Function: '<S148>/MATLAB Function'
   */
  rtb_Abs_fc_idx_0 = 0.765 * sin(rtb_Abs_fc_idx_0) - 0.635 * cos
    (rtb_Abs_fc_idx_0);
  rtb_Abs_g = 0.765 * sin(rtb_Abs_g) + 0.635 * cos(rtb_Abs_g);
  modValueRev = ((rtb_Abs_fc_idx_0 * rtDW.CFunction_k[0] + rtb_Abs_g *
                  rtDW.CFunction_h[1]) - 0.635 * rtDW.CFunction_k[2]) + 0.635 *
    rtDW.CFunction_h[3];

  /* SignalConversion generated from: '<S166>/ SFunction ' incorporates:
   *  MATLAB Function: '<S146>/MATLAB Function2'
   */
  rtb_Braking[0] = rtb_Switch;
  rtb_Braking[1] = rtb_Switch_bb;
  rtb_Braking[2] = rtb_RL;
  rtb_Braking[3] = rtb_RR;

  /* MATLAB Function: '<S146>/MATLAB Function2' incorporates:
   *  Constant: '<S146>/Constant'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/vy'
   *  RateTransition generated from: '<S1>/Rate Transition1'
   *  Sum: '<S169>/Sum1'
   *  Sum: '<S169>/Sum2'
   */
  rtb_RR = rtb_Integrator_ee * rtb_Integrator_ee * 1.0461500000000001;
  Faeroz = rtb_Integrator_ee * rtb_Integrator_ee * 3.14825;
  u0 = yaw_rate * 1.27 / 2.0;
  rtb_RL_tmp = yaw_rate * 0.73439999999999994 + rtU.vy;
  rtb_RL = atan(rtb_RL_tmp / (rtb_Integrator_ee - u0)) -
    rtb_front_wheel_angle_single__g;
  rtb_Saturation1 = atan(rtb_RL_tmp / (u0 + rtb_Integrator_ee)) -
    rtb_front_wheel_angle_single__g;
  rtb_Switch = rtU.vy - yaw_rate * 0.79560000000000008;
  rtb_front_wheel_angle_single__g = atan(rtb_Switch / (rtb_Integrator_ee -
    yaw_rate * 1.27 / 2.0));
  rtb_Switch = atan(rtb_Switch / (yaw_rate * 1.27 / 2.0 + rtb_Integrator_ee));
  rtb_Switch_bb = 0.5 * Faeroz * 0.55490196078431375;
  rtb_RR = 0.5 * rtb_RR / 1.53 * 0.576;
  u0_tmp = (((635.688 - 30.826771653543307 * rtU.ay) + rtb_Switch_bb) - rtb_RR)
    - 25.588235294117645 * rtU.ax;
  b_Fz = (((30.826771653543307 * rtU.ay + 635.688) + rtb_Switch_bb) - rtb_RR) -
    25.588235294117645 * rtU.ax;
  Faeroz = 0.5 * Faeroz * 0.4450980392156863;
  rtb_Switch_bb = (((688.66200000000015 - 30.826771653543307 * rtU.ay) + Faeroz)
                   + rtb_RR) + 25.588235294117645 * rtU.ax;
  rtb_RR = (((30.826771653543307 * rtU.ay + 688.66200000000015) + Faeroz) +
            rtb_RR) + 25.588235294117645 * rtU.ax;
  u0_tmp_0 = 12.4 * rtb_RL - 0.512;
  u_tmp = (1.14E-6 * u0_tmp - rtb_RL) + 0.00239;
  if (u_tmp < 0.0) {
    Faeroz = -1.0;
  } else if (u_tmp > 0.0) {
    Faeroz = 1.0;
  } else if (u_tmp == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  rtb_RL_tmp_tmp = 0.000282 * u0_tmp - 2.02;
  u0 = sin(atan(0.000559 * u0_tmp) * 2.0) * 34500.0 * u_tmp / (1.34 * u0_tmp *
    0.8 * rtb_RL_tmp_tmp - 0.01);
  u_tmp = 0.0013 * u0_tmp - 2.33;
  rtb_RL_tmp_tmp_0 = sqrt(u0_tmp_0 * u0_tmp_0 + 1.0);
  rtb_RL_tmp = (3.86E-7 * u0_tmp + 0.000205) * 13.9 / rtb_RL_tmp_tmp_0;
  rtb_RL = (sin(atan(u0 - (0.26 * Faeroz + 1.0) * (3.99E-5 * u0_tmp - 0.521) *
                     (atan(u0) - u0)) * 1.34) * (u0_tmp * 0.8) * rtb_RL_tmp_tmp
            + (7.1E-5 * u0_tmp - 0.149) * (u0_tmp * 0.8)) * cos(atan((atan
    (((3.86E-7 * u0_tmp - rtb_Braking[0]) + 0.000205) * 13.9 / rtb_RL_tmp_tmp_0)
    - ((3.86E-7 * u0_tmp - rtb_Braking[0]) + 0.000205) * 13.9 / sqrt(u0_tmp_0 *
    u0_tmp_0 + 1.0)) * u_tmp + ((3.86E-7 * u0_tmp - rtb_Braking[0]) + 0.000205) *
    13.9 / sqrt(u0_tmp_0 * u0_tmp_0 + 1.0)) * 0.958) / cos(atan((atan(rtb_RL_tmp)
    - rtb_RL_tmp) * u_tmp + rtb_RL_tmp) * 0.958) - sin(atan(16.1 * rtb_Braking[0])
    * 1.94) * (u0_tmp * 0.8) * rtb_RL_tmp_tmp * (1.03E-5 * u0_tmp - 0.000288) /
    sqrt(rtb_RL * rtb_RL * 225.0 + 1.0);
  u0_tmp_0 = 12.4 * rtb_Saturation1 - 0.512;
  u_tmp = (1.14E-6 * b_Fz - rtb_Saturation1) + 0.00239;
  if (u_tmp < 0.0) {
    Faeroz = -1.0;
  } else if (u_tmp > 0.0) {
    Faeroz = 1.0;
  } else if (u_tmp == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  u0_tmp = 0.000282 * b_Fz - 2.02;
  u0 = sin(atan(0.000559 * b_Fz) * 2.0) * 34500.0 * u_tmp / (1.34 * b_Fz * 0.8 *
    u0_tmp - 0.01);
  u_tmp = 0.0013 * b_Fz - 2.33;
  rtb_RL_tmp = sqrt(u0_tmp_0 * u0_tmp_0 + 1.0);
  rtb_RL_tmp_tmp = (3.86E-7 * b_Fz + 0.000205) * 13.9 / rtb_RL_tmp;
  rtb_Saturation1 = (sin(atan(u0 - (0.26 * Faeroz + 1.0) * (3.99E-5 * b_Fz -
    0.521) * (atan(u0) - u0)) * 1.34) * (b_Fz * 0.8) * u0_tmp + (7.1E-5 * b_Fz -
    0.149) * (b_Fz * 0.8)) * cos(atan((atan(((3.86E-7 * b_Fz - rtb_Braking[1]) +
    0.000205) * 13.9 / rtb_RL_tmp) - ((3.86E-7 * b_Fz - rtb_Braking[1]) +
    0.000205) * 13.9 / sqrt(u0_tmp_0 * u0_tmp_0 + 1.0)) * u_tmp + ((3.86E-7 *
    b_Fz - rtb_Braking[1]) + 0.000205) * 13.9 / sqrt(u0_tmp_0 * u0_tmp_0 + 1.0))
    * 0.958) / cos(atan((atan(rtb_RL_tmp_tmp) - rtb_RL_tmp_tmp) * u_tmp +
                        rtb_RL_tmp_tmp) * 0.958) - sin(atan(16.1 * rtb_Braking[1])
    * 1.94) * (b_Fz * 0.8) * u0_tmp * (1.03E-5 * b_Fz - 0.000288) / sqrt
    (rtb_Saturation1 * rtb_Saturation1 * 225.0 + 1.0);
  u0_tmp = 12.4 * rtb_front_wheel_angle_single__g - 0.512;
  u0_tmp_0 = 12.4 * rtb_Switch - 0.512;
  u_tmp = (1.14E-6 * rtb_Switch_bb - rtb_front_wheel_angle_single__g) + 0.00239;
  b_Fz = (1.14E-6 * rtb_RR - rtb_Switch) + 0.00239;
  if (u_tmp < 0.0) {
    Faeroz = -1.0;
  } else if (u_tmp > 0.0) {
    Faeroz = 1.0;
  } else if (u_tmp == 0.0) {
    Faeroz = 0.0;
  } else {
    Faeroz = (rtNaN);
  }

  if (b_Fz < 0.0) {
    u0 = -1.0;
  } else if (b_Fz > 0.0) {
    u0 = 1.0;
  } else if (b_Fz == 0.0) {
    u0 = 0.0;
  } else {
    u0 = (rtNaN);
  }

  rtb_RL_tmp = 0.000282 * rtb_Switch_bb - 2.02;
  u_tmp = sin(atan(0.000559 * rtb_Switch_bb) * 2.0) * 34500.0 * u_tmp / (1.34 *
    rtb_Switch_bb * 0.8 * rtb_RL_tmp - 0.01);
  rtb_RL_tmp_tmp = 0.0013 * rtb_Switch_bb - 2.33;
  rtb_RL_tmp_tmp_0 = 0.000282 * rtb_RR - 2.02;
  rtb_Switch_tmp = sin(atan(0.000559 * rtb_RR) * 2.0) * 34500.0 * b_Fz / (1.34 *
    rtb_RR * 0.8 * rtb_RL_tmp_tmp_0 - 0.01);
  rtb_Switch_tmp_0 = 0.0013 * rtb_RR - 2.33;
  b_Fz = rtb_Sign - yaw_rate;
  rtb_Switch_tmp_tmp = sqrt(u0_tmp * u0_tmp + 1.0);
  rtb_Switch_tmp_1 = (3.86E-7 * rtb_Switch_bb + 0.000205) * 13.9 /
    rtb_Switch_tmp_tmp;
  rtb_Switch_tmp_tmp_0 = sqrt(u0_tmp_0 * u0_tmp_0 + 1.0);
  rtb_Switch_tmp_2 = (3.86E-7 * rtb_RR + 0.000205) * 13.9 / rtb_Switch_tmp_tmp_0;
  rtb_Switch = b_Fz / 0.08 * 180.0 - (((rtb_RL + rtb_Saturation1) * rtb_NProdOut
    * 0.73439999999999994 - (((sin(atan(u_tmp - (0.26 * Faeroz + 1.0) * (3.99E-5
    * rtb_Switch_bb - 0.521) * (atan(u_tmp) - u_tmp)) * 1.34) * (rtb_Switch_bb *
    0.8) * rtb_RL_tmp + (7.1E-5 * rtb_Switch_bb - 0.149) * (rtb_Switch_bb * 0.8))
    * cos(atan((atan(((3.86E-7 * rtb_Switch_bb - rtb_Braking[2]) + 0.000205) *
                     13.9 / rtb_Switch_tmp_tmp) - ((3.86E-7 * rtb_Switch_bb -
    rtb_Braking[2]) + 0.000205) * 13.9 / sqrt(u0_tmp * u0_tmp + 1.0)) *
               rtb_RL_tmp_tmp + ((3.86E-7 * rtb_Switch_bb - rtb_Braking[2]) +
    0.000205) * 13.9 / sqrt(u0_tmp * u0_tmp + 1.0)) * 0.958) / cos(atan((atan
    (rtb_Switch_tmp_1) - rtb_Switch_tmp_1) * rtb_RL_tmp_tmp + rtb_Switch_tmp_1) *
    0.958) - sin(atan(16.1 * rtb_Braking[2]) * 1.94) * (rtb_Switch_bb * 0.8) *
    rtb_RL_tmp * (1.03E-5 * rtb_Switch_bb - 0.000288) / sqrt
    (rtb_front_wheel_angle_single__g * rtb_front_wheel_angle_single__g * 225.0 +
     1.0)) + ((sin(atan(rtb_Switch_tmp - (0.26 * u0 + 1.0) * (3.99E-5 * rtb_RR -
    0.521) * (atan(rtb_Switch_tmp) - rtb_Switch_tmp)) * 1.34) * (rtb_RR * 0.8) *
               rtb_RL_tmp_tmp_0 + (7.1E-5 * rtb_RR - 0.149) * (rtb_RR * 0.8)) *
              cos(atan((atan(((3.86E-7 * rtb_RR - rtb_Braking[3]) + 0.000205) *
    13.9 / rtb_Switch_tmp_tmp_0) - ((3.86E-7 * rtb_RR - rtb_Braking[3]) +
    0.000205) * 13.9 / sqrt(u0_tmp_0 * u0_tmp_0 + 1.0)) * rtb_Switch_tmp_0 +
                       ((3.86E-7 * rtb_RR - rtb_Braking[3]) + 0.000205) * 13.9 /
                       sqrt(u0_tmp_0 * u0_tmp_0 + 1.0)) * 0.958) / cos(atan
    ((atan(rtb_Switch_tmp_2) - rtb_Switch_tmp_2) * rtb_Switch_tmp_0 +
     rtb_Switch_tmp_2) * 0.958) - sin(atan(16.1 * rtb_Braking[3]) * 1.94) *
              (rtb_RR * 0.8) * rtb_RL_tmp_tmp_0 * (1.03E-5 * rtb_RR - 0.000288) /
              sqrt(rtb_Switch * rtb_Switch * 225.0 + 1.0))) *
    0.79560000000000008) + -(rtb_Saturation1 - rtb_RL) * rtb_Switch2_l * 1.27 /
    2.0);
  if (rtIsNaN(rtb_Switch)) {
    rtb_Switch = 0.0;
  }

  /* Logic: '<S146>/NOT1' */
  rtb_Logic_o_idx_1 = !rtb_Logic_b_idx_1;

  /* DiscreteIntegrator: '<S208>/Integrator' */
  if (rtb_Logic_o_idx_1 || (rtDW.Integrator_PrevResetState_j != 0)) {
    rtDW.Integrator_DSTATE_b = 0.0;
  }

  /* DiscreteIntegrator: '<S203>/Filter' */
  if (rtb_Logic_o_idx_1 || (rtDW.Filter_PrevResetState != 0)) {
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
  rtb_NProdOut = ((rtb_Sign * 0.0 - yaw_rate) * 0.0 - rtDW.Filter_DSTATE) * 3.0;

  /* Sum: '<S218>/Sum' incorporates:
   *  Constant: '<S146>/Constant12'
   *  DiscreteIntegrator: '<S208>/Integrator'
   *  Product: '<S213>/PProd Out'
   */
  rtb_front_wheel_angle_single__g = (b_Fz * 0.0 + rtDW.Integrator_DSTATE_b) +
    rtb_NProdOut;

  /* Switch: '<S216>/Switch2' incorporates:
   *  Constant: '<S146>/Constant10'
   *  Constant: '<S146>/Constant9'
   *  RelationalOperator: '<S216>/LowerRelop1'
   *  RelationalOperator: '<S216>/UpperRelop'
   *  Switch: '<S216>/Switch'
   */
  if (rtb_front_wheel_angle_single__g > 50.0) {
    rtb_Switch2_l = 50.0;
  } else if (rtb_front_wheel_angle_single__g < -50.0) {
    /* Switch: '<S216>/Switch' incorporates:
     *  Constant: '<S146>/Constant10'
     */
    rtb_Switch2_l = -50.0;
  } else {
    rtb_Switch2_l = rtb_front_wheel_angle_single__g;
  }

  /* End of Switch: '<S216>/Switch2' */

  /* Sum: '<S146>/Sum1' incorporates:
   *  Gain: '<S146>/Gain2'
   */
  u0 = 0.017407407407407406 * rtb_Switch + rtb_Switch2_l;

  /* Saturate: '<S146>/Saturation' */
  if (u0 > 20.0) {
    u0 = 20.0;
  } else if (u0 < -20.0) {
    u0 = -20.0;
  }

  /* End of Saturate: '<S146>/Saturation' */

  /* Product: '<S146>/Product' */
  rtb_Switch = u0 * (real_T)rtb_Logic_b_idx_1;

  /* MATLAB Function: '<S146>/MATLAB Function3' */
  rtb_Switch_bb = ((rtb_Abs_fc_idx_0 * rtDW.CFunction_h[0] + rtb_Abs_g *
                    rtDW.CFunction_k[1]) - 0.635 * rtDW.CFunction_h[2]) + 0.635 *
    rtDW.CFunction_k[3];

  /* Switch: '<S170>/Switch2' incorporates:
   *  RelationalOperator: '<S170>/LowerRelop1'
   */
  if (!(rtb_Switch > modValueRev)) {
    /* Switch: '<S170>/Switch' incorporates:
     *  RelationalOperator: '<S170>/UpperRelop'
     */
    if (rtb_Switch < rtb_Switch_bb) {
      modValueRev = rtb_Switch_bb;
    } else {
      modValueRev = rtb_Switch;
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
  if (modValueRev < 0.0) {
    guard1 = true;
  } else if (modValueRev > 0.0) {
    /* SignalConversion generated from: '<S165>/ SFunction ' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant9'
     */
    tmp[0] = -35000;
    tmp[1] = 80000;
    if (tmp[rtU.throttle >= 0.05] < 10000) {
      Faeroz = 0.0;
    } else {
      Faeroz = 0.75;
    }

    rtb_Switch = modValueRev * Faeroz;
  } else {
    if (modValueRev == 0.0) {
    }

    guard1 = true;
  }

  if (guard1) {
    rtb_Switch = modValueRev;

    /* SignalConversion generated from: '<S165>/ SFunction ' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant9'
     */
    tmp[0] = -35000;
    tmp[1] = 80000;
    if (tmp[rtU.throttle >= 0.05] < 10000) {
      Faeroz = 0.0;
    } else {
      Faeroz = 0.75;
    }

    modValueRev *= Faeroz;
  }

  /* End of MATLAB Function: '<S146>/MATLAB Function1' */

  /* MinMax: '<S233>/Max' */
  rtb_Abs = fmax(rtb_Abs, z);

  /* InitialCondition: '<S235>/IC1' */
  rtDW.IC1_FirstOutputTime_m = false;

  /* Gain: '<S271>/Gain2' incorporates:
   *  Gain: '<S243>/Gain2'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  z = 13.5 * rtU.omega_wheels_FL;

  /* Saturate: '<S271>/Saturation' incorporates:
   *  Gain: '<S271>/Gain2'
   */
  if (z > 2083.9231268812296) {
    rtb_Braking[0] = 2083.9231268812296;
  } else if (z < 10.471975511965978) {
    rtb_Braking[0] = 10.471975511965978;
  } else {
    rtb_Braking[0] = z;
  }

  /* Gain: '<S271>/Gain2' incorporates:
   *  Gain: '<S243>/Gain2'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  rtb_Saturation1 = 13.5 * rtU.omega_wheels_FR;

  /* Saturate: '<S271>/Saturation' incorporates:
   *  Gain: '<S271>/Gain2'
   */
  if (rtb_Saturation1 > 2083.9231268812296) {
    rtb_Braking[1] = 2083.9231268812296;
  } else if (rtb_Saturation1 < 10.471975511965978) {
    rtb_Braking[1] = 10.471975511965978;
  } else {
    rtb_Braking[1] = rtb_Saturation1;
  }

  /* Gain: '<S271>/Gain2' incorporates:
   *  Gain: '<S243>/Gain2'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  u0_tmp = 13.5 * rtU.omega_wheels_RL;

  /* Saturate: '<S271>/Saturation' incorporates:
   *  Gain: '<S271>/Gain2'
   */
  if (u0_tmp > 2083.9231268812296) {
    rtb_Braking[2] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Braking[2] = 10.471975511965978;
  } else {
    rtb_Braking[2] = u0_tmp;
  }

  /* Gain: '<S271>/Gain2' incorporates:
   *  Gain: '<S243>/Gain2'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0_tmp_0 = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S271>/Saturation' incorporates:
   *  Gain: '<S271>/Gain2'
   */
  if (u0_tmp_0 > 2083.9231268812296) {
    rtb_Braking[3] = 2083.9231268812296;
  } else if (u0_tmp_0 < 10.471975511965978) {
    rtb_Braking[3] = 10.471975511965978;
  } else {
    rtb_Braking[3] = u0_tmp_0;
  }

  /* Abs: '<S273>/Abs' incorporates:
   *  Abs: '<S245>/Abs'
   */
  rtb_Tnew[0] = rtb_Integrator_o;
  rtb_Tnew[1] = rtb_Saturation;
  rtb_Switch_bb = fabs(rtb_Abs_p[2]);
  rtb_Tnew[2] = rtb_Switch_bb;
  rtb_RL_tmp = fabs(rtb_Abs_p[3]);
  rtb_Tnew[3] = rtb_RL_tmp;

  /* Lookup_n-D: '<S273>/2-D Lookup Table' */
  rtb_Braking[0] = look2_binlx(rtb_Braking[0], rtb_Tnew[0], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Braking[1] = look2_binlx(rtb_Braking[1], rtb_Tnew[1], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Braking[2] = look2_binlx(rtb_Braking[2], rtb_Tnew[2], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Braking[3] = look2_binlx(rtb_Braking[3], rtb_Tnew[3], rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled67, 200U);

  /* Saturate: '<S273>/Saturation' */
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

  /* End of Saturate: '<S273>/Saturation' */

  /* Switch: '<S271>/Switch3' incorporates:
   *  Gain: '<S271>/     '
   *  Gain: '<S271>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    Faeroz = 0.96 * rtb_Braking[0];
  } else {
    Faeroz = 1.0416666666666667 * rtb_Braking[0];
  }

  if (rtU.omega_wheels_FR > 0.0) {
    rtb_RL = 0.96 * rtb_Braking[1];
  } else {
    rtb_RL = 1.0416666666666667 * rtb_Braking[1];
  }

  if (rtU.omega_wheels_RL > 0.0) {
    rtb_RR = 0.96 * rtb_Braking[2];
  } else {
    rtb_RR = 1.0416666666666667 * rtb_Braking[2];
  }

  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Sign = 0.96 * rtb_Braking[3];
  } else {
    rtb_Sign = 1.0416666666666667 * rtb_Braking[3];
  }

  /* End of Switch: '<S271>/Switch3' */

  /* MATLAB Function: '<S151>/MATLAB Function' incorporates:
   *  Constant: '<S151>/Constant'
   *  Constant: '<S151>/Constant1'
   *  Constant: '<S151>/r1'
   *  Constant: '<S151>/vx'
   *  Constant: '<S151>/vy'
   *  Gain: '<S151>/Gain'
   *  Gain: '<S271>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S271>/Product'
   *  SignalConversion generated from: '<S272>/ SFunction '
   */
  rtb_VectorConcatenate_k[0] = 0.0;
  rtb_VectorConcatenate_k[1] = 0.0;
  rtb_VectorConcatenate_k[2] = 0.0;
  rtb_VectorConcatenate_k[3] = 13.5 * rtU.omega_wheels_FL * Faeroz * 0.0;
  rtb_VectorConcatenate_k[4] = 13.5 * rtU.omega_wheels_FR * rtb_RL * 0.0;
  rtb_VectorConcatenate_k[5] = 13.5 * rtU.omega_wheels_RL * rtb_RR * 0.0;
  rtb_VectorConcatenate_k[6] = 13.5 * rtU.omega_wheels_RR * rtb_Sign * 0.0;
  memset(&varargin_1[0], 0, 49U * sizeof(real_T));
  for (idx = 0; idx < 7; idx++) {
    varargin_1[idx + 7 * idx] = rtb_VectorConcatenate_k[idx];
  }

  rtb_Braking[0] = 0.03;
  rtb_Braking[1] = 0.03;
  rtb_Braking[2] = 0.03;
  rtb_Braking[3] = 0.03;
  memset(&varargin_2[0], 0, sizeof(real_T) << 4U);
  varargin_2[0] = rtb_Braking[0];
  varargin_2[5] = rtb_Braking[1];
  varargin_2[10] = rtb_Braking[2];
  varargin_2[15] = rtb_Braking[3];
  memset(&rtb_y_h[0], 0, 121U * sizeof(real_T));
  for (idx = 0; idx < 7; idx++) {
    for (sigIdx = 0; sigIdx < 7; sigIdx++) {
      rtb_y_h[sigIdx + 11 * idx] = varargin_1[7 * idx + sigIdx];
    }
  }

  for (idx = 0; idx < 4; idx++) {
    int32_T rtb_y_i_tmp;
    sigIdx = idx << 2;
    rtb_y_i_tmp = (idx + 7) * 11;
    rtb_y_h[rtb_y_i_tmp + 7] = varargin_2[sigIdx];
    rtb_y_h[rtb_y_i_tmp + 8] = varargin_2[sigIdx + 1];
    rtb_y_h[rtb_y_i_tmp + 9] = varargin_2[sigIdx + 2];
    rtb_y_h[rtb_y_i_tmp + 10] = varargin_2[sigIdx + 3];
  }

  rtb_y_h[58] = -0.0;
  rtb_y_h[38] = -0.0;
  rtb_y_h[70] = -0.0;
  rtb_y_h[50] = -0.0;
  for (idx = 0; idx < 121; idx++) {
    rtb_y_h[idx] *= 50.0;
  }

  /* End of MATLAB Function: '<S151>/MATLAB Function' */

  /* Saturate: '<S243>/Saturation' */
  if (z > 2083.9231268812296) {
    rtb_Braking[0] = 2083.9231268812296;
  } else if (z < 10.471975511965978) {
    rtb_Braking[0] = 10.471975511965978;
  } else {
    rtb_Braking[0] = z;
  }

  if (rtb_Saturation1 > 2083.9231268812296) {
    rtb_Braking[1] = 2083.9231268812296;
  } else if (rtb_Saturation1 < 10.471975511965978) {
    rtb_Braking[1] = 10.471975511965978;
  } else {
    rtb_Braking[1] = rtb_Saturation1;
  }

  if (u0_tmp > 2083.9231268812296) {
    rtb_Braking[2] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Braking[2] = 10.471975511965978;
  } else {
    rtb_Braking[2] = u0_tmp;
  }

  if (u0_tmp_0 > 2083.9231268812296) {
    rtb_Braking[3] = 2083.9231268812296;
  } else if (u0_tmp_0 < 10.471975511965978) {
    rtb_Braking[3] = 10.471975511965978;
  } else {
    rtb_Braking[3] = u0_tmp_0;
  }

  /* End of Saturate: '<S243>/Saturation' */

  /* Lookup_n-D: '<S245>/2-D Lookup Table' */
  rtb_Braking[0] = look2_binlx(rtb_Braking[0], rtb_Integrator_o,
    rtConstP.pooled7, rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled67,
    200U);
  rtb_Braking[1] = look2_binlx(rtb_Braking[1], rtb_Saturation, rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Braking[2] = look2_binlx(rtb_Braking[2], rtb_Switch_bb, rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled67, 200U);
  rtb_Braking[3] = look2_binlx(rtb_Braking[3], rtb_RL_tmp, rtConstP.pooled7,
    rtConstP.pooled8, rtConstP.pooled5, rtConstP.pooled67, 200U);

  /* Saturate: '<S245>/Saturation' */
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

  /* End of Saturate: '<S245>/Saturation' */

  /* Switch: '<S243>/Switch3' incorporates:
   *  Gain: '<S243>/     '
   *  Gain: '<S243>/      '
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  if (rtU.omega_wheels_FL > 0.0) {
    Faeroz = 0.96 * rtb_Braking[0];
  } else {
    Faeroz = 1.0416666666666667 * rtb_Braking[0];
  }

  if (rtU.omega_wheels_FR > 0.0) {
    rtb_RL = 0.96 * rtb_Braking[1];
  } else {
    rtb_RL = 1.0416666666666667 * rtb_Braking[1];
  }

  if (rtU.omega_wheels_RL > 0.0) {
    rtb_RR = 0.96 * rtb_Braking[2];
  } else {
    rtb_RR = 1.0416666666666667 * rtb_Braking[2];
  }

  if (rtU.omega_wheels_RR > 0.0) {
    rtb_Sign = 0.96 * rtb_Braking[3];
  } else {
    rtb_Sign = 1.0416666666666667 * rtb_Braking[3];
  }

  /* End of Switch: '<S243>/Switch3' */

  /* SignalConversion generated from: '<S139>/Vector Concatenate' incorporates:
   *  RateTransition generated from: '<S1>/Rate Transition1'
   */
  rtb_VectorConcatenate_k[0] = rtb_Integrator_ee;

  /* SignalConversion generated from: '<S139>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/vy'
   */
  rtb_VectorConcatenate_k[1] = rtU.vy;

  /* SignalConversion generated from: '<S139>/Vector Concatenate' */
  rtb_VectorConcatenate_k[2] = yaw_rate;

  /* Gain: '<S147>/Gain' incorporates:
   *  Sum: '<S147>/Sum'
   */
  rtb_Integrator_ee = (rtb_Abs + dT) * 0.5;

  /* Chart: '<S238>/Distribution complete' incorporates:
   *  SignalConversion generated from: '<S242>/ SFunction '
   */
  if (rtb_Integrator_ee >= 0.0) {
    z = rtb_Integrator_ee;
    rtb_Braking[0] = rtDW.CFunction_h[1];
    rtb_Braking[1] = rtDW.CFunction_h[3];
    rtb_Braking[2] = rtDW.CFunction_h[0];
    rtb_Braking[3] = rtDW.CFunction_h[2];
    rtb_Divide_a[0] = rtDW.CFunction_k[1];
    rtb_Divide_a[1] = rtDW.CFunction_k[3];
    rtb_Divide_a[2] = rtDW.CFunction_k[0];
    rtb_Divide_a[3] = rtDW.CFunction_k[2];
    rtb_Switch_bb = modValueRev;
  } else {
    z = -rtb_Integrator_ee;
    rtb_Braking[0] = -rtDW.CFunction_k[1];
    rtb_Braking[1] = -rtDW.CFunction_k[3];
    rtb_Braking[2] = -rtDW.CFunction_k[0];
    rtb_Braking[3] = -rtDW.CFunction_k[2];
    rtb_Divide_a[0] = -rtDW.CFunction_h[1];
    rtb_Divide_a[1] = -rtDW.CFunction_h[3];
    rtb_Divide_a[2] = -rtDW.CFunction_h[0];
    rtb_Divide_a[3] = -rtDW.CFunction_h[2];
    rtb_Switch_bb = -modValueRev;
  }

  if (rtb_Switch_bb < 0.0) {
    yaw_rate = rtb_Braking[2];
    rtb_Saturation1 = rtb_Braking[3];
    u0_tmp = rtb_Braking[0];
    u0_tmp_0 = rtb_Braking[1];
    rtb_Braking[0] = yaw_rate;
    rtb_Braking[1] = rtb_Saturation1;
    rtb_Braking[2] = u0_tmp;
    rtb_Braking[3] = u0_tmp_0;
    yaw_rate = rtb_Divide_a[2];
    rtb_Saturation1 = rtb_Divide_a[3];
    u0_tmp = rtb_Divide_a[0];
    u0_tmp_0 = rtb_Divide_a[1];
    rtb_Divide_a[0] = yaw_rate;
    rtb_Divide_a[1] = rtb_Saturation1;
    rtb_Divide_a[2] = u0_tmp;
    rtb_Divide_a[3] = u0_tmp_0;
  }

  for (idx = 0; idx < 4; idx++) {
    rtb_Braking_0[idx] = rtb_Braking[idx];
  }

  for (idx = 0; idx < 4; idx++) {
    rtb_Divide_m[idx] = rtb_Divide_a[idx];
  }

  BaseDistribution(z, rtb_Braking_0, rtb_Divide_m, fabs(rtb_Switch_bb),
                   rtb_lbx_out);
  if (!(rtb_Integrator_ee >= 0.0)) {
    rtb_Braking_0[0] = -rtb_lbx_out[0];
    rtb_Braking_0[1] = -rtb_lbx_out[1];
    rtb_Braking_0[2] = -rtb_lbx_out[2];
    rtb_Braking_0[3] = -rtb_lbx_out[3];
    assignBrakeTorque(rtb_Braking_0, rtb_lbx_out);
  }

  if (rtb_Switch_bb < 0.0) {
    rtb_Integrator_ee = rtb_lbx_out[2];
    rtb_Switch_bb = rtb_lbx_out[3];
    yaw_rate = rtb_lbx_out[0];
    z = rtb_lbx_out[1];
    rtb_lbx_out[0] = rtb_Integrator_ee;
    rtb_lbx_out[1] = rtb_Switch_bb;
    rtb_lbx_out[2] = yaw_rate;
    rtb_lbx_out[3] = z;
  }

  /* End of Chart: '<S238>/Distribution complete' */

  /* SignalConversion: '<S238>/Signal Conversion' */
  rtb_VectorConcatenate_k[3] = rtb_lbx_out[2];
  rtb_VectorConcatenate_k[4] = rtb_lbx_out[0];
  rtb_VectorConcatenate_k[5] = rtb_lbx_out[3];
  rtb_VectorConcatenate_k[6] = rtb_lbx_out[1];

  /* CCaller: '<S139>/C Caller1' incorporates:
   *  Abs: '<S237>/Abs1'
   *  Abs: '<S237>/Abs3'
   *  Abs: '<S243>/Abs'
   *  CFunction: '<S152>/C Function'
   *  CFunction: '<S248>/C Function'
   *  CFunction: '<S249>/C Function'
   *  Constant: '<S139>/Constant'
   *  Constant: '<S144>/Constant'
   *  Constant: '<S149>/Constant'
   *  Gain: '<S243>/Gain1'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  MATLAB Function: '<S148>/MATLAB Function'
   *  Product: '<S243>/Divide'
   *  Saturate: '<S234>/Saturation'
   *  SignalConversion generated from: '<S139>/C Caller1'
   *  UnaryMinus: '<S144>/Unary Minus'
   *  UnaryMinus: '<S237>/Unary Minus'
   *  UnaryMinus: '<S237>/Unary Minus1'
   * */
  memcpy(&rtb_CCaller1_o3[0], &rtDW.CFunction[0], 26U * sizeof(real_T));
  rtb_Braking[0] = -10000.0;
  rtb_Braking[1] = -10000.0;
  rtb_Braking[2] = -10000.0;
  rtb_Braking[3] = -10000.0;
  rtb_Divide_a[0] = 10000.0;
  rtb_Divide_a[1] = 10000.0;
  rtb_Divide_a[2] = 10000.0;
  rtb_Divide_a[3] = 10000.0;
  rtb_lbx_out[0] = rtDW.CFunction_k[0];
  rtb_lbx_out[1] = rtDW.CFunction_k[1];
  rtb_lbx_out[2] = rtDW.CFunction_k[2];
  rtb_lbx_out[3] = rtDW.CFunction_k[3];
  rtb_Tnew[0] = rtDW.CFunction_h[0];
  rtb_Tnew[1] = rtDW.CFunction_h[1];
  rtb_Tnew[2] = rtDW.CFunction_h[2];
  rtb_Tnew[3] = rtDW.CFunction_h[3];
  rtb_CCaller1_o9[0] = dT;
  rtb_CCaller1_o9[1] = rtb_SumofElements1;
  rtb_CCaller1_o9[2] = -rtb_Saturation;
  rtb_CCaller1_o9[3] = -rtb_Integrator_o;
  rtb_CCaller1_o9[4] = rtb_Switch;
  rtb_CCaller1_o10[0] = rtb_Abs;
  rtb_CCaller1_o10[1] = 80.0;
  rtb_CCaller1_o10[2] = rtb_Saturation;
  rtb_CCaller1_o10[3] = rtb_Integrator_o;
  rtb_CCaller1_o10[4] = modValueRev;
  for (idx = 0; idx < 7; idx++) {
    rtb_CCaller1_o12[5 * idx] = b[idx];
  }

  rtb_CCaller1_o12[1] = 0.0;
  rtb_CCaller1_o12[6] = 0.0;
  rtb_CCaller1_o12[11] = 0.0;
  rtb_CCaller1_o12[16] = fabs(13.5 * rtU.omega_wheels_FL / Faeroz) / 1000.0;
  rtb_CCaller1_o12[21] = fabs(13.5 * rtU.omega_wheels_FR / rtb_RL) / 1000.0;
  rtb_CCaller1_o12[26] = fabs(13.5 * rtU.omega_wheels_RL / rtb_RR) / 1000.0;
  rtb_CCaller1_o12[31] = fabs(13.5 * rtU.omega_wheels_RR / rtb_Sign) / 1000.0;
  for (idx = 0; idx < 7; idx++) {
    rtb_CCaller1_o12[5 * idx + 2] = c[idx];
  }

  for (idx = 0; idx < 7; idx++) {
    rtb_CCaller1_o12[5 * idx + 3] = d[idx];
  }

  rtb_CCaller1_o12[4] = 0.0;
  rtb_CCaller1_o12[9] = 0.0;
  rtb_CCaller1_o12[14] = 0.0;
  rtb_CCaller1_o12[19] = rtb_Abs_fc_idx_0;
  rtb_CCaller1_o12[24] = rtb_Abs_g;
  rtb_CCaller1_o12[29] = -0.635;
  rtb_CCaller1_o12[34] = 0.635;
  rtb_CCaller1_o13[0] = 1000.0;
  rtb_CCaller1_o13[1] = 50.0;
  rtb_CCaller1_o13[2] = 50.0;
  rtb_CCaller1_o14[0] = 1000.0;
  rtb_CCaller1_o14[1] = 50.0;
  rtb_CCaller1_o14[2] = 50.0;
  rtb_Integrator_ee = 1.0;
  Acados_Caller_wrapper(&rtb_x[0], &rtb_CCaller1_o3[0], &rtb_Braking[0],
                        &rtb_Divide_a[0], &rtb_VectorConcatenate[0],
                        &rtb_lbx_out[0], &rtb_Tnew[0], &rtb_CCaller1_o9[0],
                        &rtb_CCaller1_o10[0], &rtb_y_h[0], &rtb_CCaller1_o12[0],
                        &rtb_CCaller1_o13[0], &rtb_CCaller1_o14[0],
                        &rtb_VectorConcatenate_k[0], &rtb_Integrator_ee);

  /* End of CCaller: '<S139>/C Caller1' */

  /* RelationalOperator: '<S145>/Less Than3' incorporates:
   *  DataStoreRead: '<S145>/Data Store General_Params1'
   *  Inport: '<Root>/brake'
   */
  rtb_Logic_b_idx_1 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S145>/Overlap Chart' incorporates:
   *  Inport: '<Root>/throttle'
   */
  if (rtDW.is_active_c13_TVModel == 0U) {
    rtDW.is_active_c13_TVModel = 1U;
    rtDW.is_c13_TVModel = IN_Go;
  } else if (rtDW.is_c13_TVModel == IN_Go) {
    if (rtb_Logic_b_idx_1) {
      rtDW.is_c13_TVModel = IN_Stop;
    }

    /* case IN_Stop: */
  } else if (((real_T)rtb_Logic_b_idx_1 <= 0.05) && (rtU.throttle < 0.05)) {
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
  if (rtb_front_wheel_angle_single__g >= 50.0) {
    rtb_Switch = 50.0;
  } else if (rtb_front_wheel_angle_single__g > -50.0) {
    /* Switch: '<S201>/Switch1' */
    rtb_Switch = rtb_front_wheel_angle_single__g;
  } else {
    rtb_Switch = -50.0;
  }

  /* End of Switch: '<S201>/Switch' */

  /* Sum: '<S201>/Diff' */
  dT = rtb_front_wheel_angle_single__g - rtb_Switch;

  /* RelationalOperator: '<S198>/NotEqual' incorporates:
   *  Gain: '<S198>/ZeroGain'
   */
  rtb_Logic_b_idx_1 = (0.0 * rtb_front_wheel_angle_single__g != dT);

  /* Signum: '<S198>/SignPreSat' */
  if (dT < 0.0) {
    rtb_Integrator_ee = -1.0;
  } else if (dT > 0.0) {
    rtb_Integrator_ee = 1.0;
  } else if (dT == 0.0) {
    rtb_Integrator_ee = 0.0;
  } else {
    rtb_Integrator_ee = (rtNaN);
  }

  /* End of Signum: '<S198>/SignPreSat' */

  /* Sum: '<S221>/SumI1' incorporates:
   *  Constant: '<S146>/Const10ant15'
   *  Gain: '<S220>/Kt'
   *  Product: '<S205>/IProd Out'
   *  Sum: '<S220>/SumI3'
   */
  dT = (rtb_Switch2_l - rtb_Switch2_l) * 100.0 + b_Fz * 20.0;

  /* Signum: '<S198>/SignPreIntegrator' */
  if (dT < 0.0) {
    rtb_front_wheel_angle_single__g = -1.0;
  } else if (dT > 0.0) {
    rtb_front_wheel_angle_single__g = 1.0;
  } else if (dT == 0.0) {
    rtb_front_wheel_angle_single__g = 0.0;
  } else {
    rtb_front_wheel_angle_single__g = (rtNaN);
  }

  /* End of Signum: '<S198>/SignPreIntegrator' */

  /* Switch: '<S198>/Switch' incorporates:
   *  Constant: '<S198>/Constant1'
   *  DataTypeConversion: '<S198>/DataTypeConv1'
   *  DataTypeConversion: '<S198>/DataTypeConv2'
   *  Logic: '<S198>/AND3'
   *  RelationalOperator: '<S198>/Equal1'
   */
  if (rtb_Logic_b_idx_1 && ((int8_T)floor(rtb_Integrator_ee) == (int8_T)
       rtb_front_wheel_angle_single__g)) {
    yaw_rate = 0.0;
  } else {
    yaw_rate = dT;
  }

  /* End of Switch: '<S198>/Switch' */

  /* Fcn: '<S281>/Avoid Divide by Zero' incorporates:
   *  Constant: '<S281>/Time constant'
   *  MinMax: '<S281>/Max'
   */
  rtb_Integrator_ee = fmax(rtDW.Probe[0], 0.079577471545947673);

  /* RelationalOperator: '<S277>/Less Than' incorporates:
   *  DataStoreRead: '<S277>/Data Store General_Params'
   *  Inport: '<Root>/brake'
   */
  rtb_Logic_b_idx_1 = (rtU.brake > rtDW.General_Params.BrakeThresh);

  /* Chart: '<S277>/T_Req_Chart' */
  guard1 = false;
  guard2 = false;
  if (rtDW.is_active_c21_TVModel == 0U) {
    rtDW.is_active_c21_TVModel = 1U;
    rtDW.is_c21_TVModel = IN_Throttle;
    rtb_Switch2_l = 0.0;
    guard1 = true;
  } else if (rtDW.is_c21_TVModel == IN_Brake) {
    if ((!rtb_Logic_b_idx_1) && (rtU.throttle < 0.05)) {
      rtDW.is_c21_TVModel = IN_Throttle;
      rtb_Switch2_l = 0.0;
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    /* case IN_Throttle: */
    rtb_Switch2_l = 0.0;
    if (rtb_Logic_b_idx_1) {
      rtDW.is_c21_TVModel = IN_Brake;
      guard2 = true;
    } else {
      guard1 = true;
    }
  }

  if (guard2) {
    /* SignalConversion generated from: '<S297>/1-D Lookup Table' incorporates:
     *  Constant: '<S297>/Constant'
     *  DataStoreRead: '<S297>/Data Store Read'
     *  Switch: '<S277>/Switch'
     */
    fractions[0] = rtDW.General_Params.BrakeThresh;
    fractions[1] = 1.0;

    /* Lookup_n-D: '<S297>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/brake'
     *  Switch: '<S277>/Switch'
     */
    u0 = look1_binlx(rtU.brake, fractions, rtConstP.uDLookupTable_tableData, 1U);

    /* Saturate: '<S297>/Saturation_Brake' incorporates:
     *  Switch: '<S277>/Switch'
     */
    if (u0 > 1.0) {
      u0 = 1.0;
    } else if (u0 < 0.0) {
      u0 = 0.0;
    }

    /* End of Saturate: '<S297>/Saturation_Brake' */

    /* Switch: '<S277>/Switch' incorporates:
     *  Gain: '<S297>/Gain_Max_Torque_Needed'
     */
    rtb_Switch2_l = -529.2 * u0;
  }

  if (guard1) {
    /* Switch: '<S296>/Switch' incorporates:
     *  DataStoreRead: '<S296>/Data Store General_Params1'
     *  Inport: '<Root>/throttle'
     *  RelationalOperator: '<S296>/Less Than'
     *  Switch: '<S277>/Switch'
     */
    if (rtU.throttle > rtDW.General_Params.ThrottleThresh) {
      /* SignalConversion generated from: '<S296>/T_nominal_wheel_LUT' incorporates:
       *  Constant: '<S296>/Constant1'
       *  Constant: '<S296>/Constant2'
       *  DataStoreRead: '<S296>/Data Store General_Params'
       */
      rtb_CCaller1_o13[0] = 0.0;
      rtb_CCaller1_o13[1] = rtDW.General_Params.ThrottleThresh;
      rtb_CCaller1_o13[2] = 1.0;

      /* MultiPortSwitch: '<S296>/Map_Selector' incorporates:
       *  Lookup_n-D: '<S296>/T_peak_wheel_LUT'
       */
      rtb_Switch2_l = look1_binlx(rtU.throttle, rtb_CCaller1_o13,
        rtConstP.T_peak_wheel_LUT_tableData, 2U);
    }

    /* End of Switch: '<S296>/Switch' */
  }

  /* End of Chart: '<S277>/T_Req_Chart' */

  /* MATLABSystem: '<S277>/Moving Average' */
  if (rtDW.obj_l.TunablePropsChanged) {
    rtDW.obj_l.TunablePropsChanged = false;
  }

  obj_0 = rtDW.obj_l.pStatistic;
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

  dT = obj_0->pCumRevIndex;
  rtb_Integrator_o = obj_0->pCumSum;
  rtb_Abs_p[0] = obj_0->pCumSumRev[0];
  rtb_Abs_p[1] = obj_0->pCumSumRev[1];
  rtb_Abs_p[2] = obj_0->pCumSumRev[2];
  rtb_Abs_p[3] = obj_0->pCumSumRev[3];
  modValueRev = obj_0->pModValueRev;
  rtb_Integrator_o += rtb_Switch2_l;
  rtb_Abs_p[(int32_T)dT - 1] = rtb_Switch2_l;
  if (dT != 4.0) {
    dT++;
  } else {
    dT = 1.0;
    rtb_Integrator_o = 0.0;
    rtb_Abs_p[2] += rtb_Abs_p[3];
    rtb_Abs_p[1] += rtb_Abs_p[2];
    rtb_Abs_p[0] += rtb_Abs_p[1];
  }

  obj_0->pCumSum = rtb_Integrator_o;
  obj_0->pCumSumRev[0] = rtb_Abs_p[0];
  obj_0->pCumSumRev[1] = rtb_Abs_p[1];
  obj_0->pCumSumRev[2] = rtb_Abs_p[2];
  obj_0->pCumSumRev[3] = rtb_Abs_p[3];
  obj_0->pCumRevIndex = dT;
  if (modValueRev > 0.0) {
    obj_0->pModValueRev = modValueRev - 1.0;
  } else {
    obj_0->pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S277>/Moving Average' */

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

  /* Update for DiscreteIntegrator: '<S62>/Integrator' */
  rtDW.Integrator_DSTATE[0] += 0.02 * Switch2_idx_3;

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

  /* Update for DiscreteIntegrator: '<S62>/Integrator' */
  rtDW.Integrator_DSTATE[1] += 0.02 * rtb_Integrator_p_idx_0;

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

  /* Update for DiscreteIntegrator: '<S62>/Integrator' */
  rtDW.Integrator_DSTATE[2] += 0.02 * rtb_Integrator_p_idx_2_0;

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
  rtDW.Integrator_DSTATE[3] += 0.02 * rtb_Integrator_b;
  rtDW.Integrator_PrevResetState = (int8_T)AND;

  /* Update for DiscreteFir: '<S156>/Discrete FIR Filter' incorporates:
   *  Constant: '<S139>/Constant1'
   */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 3;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf] = 0.0;

  /* End of Update for DiscreteFir: '<S156>/Discrete FIR Filter' */

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_PrevResetState_g = (int8_T)rtb_LessThan1_ib;

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_e[0] = rtDW.T_min[0];

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_f[0] += 0.02 * Switch2_idx_0;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_ep[0] = rtDW.T_max[0];

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[0] = rtb_k_l_idx_0;

  /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
   *  UnaryMinus: '<S16>/Unary Minus'
   */
  rtDW.UnitDelay2_DSTATE[0] = -rtb_ome_wheels_idx_3;

  /* Update for Memory: '<S139>/Memory' incorporates:
   *  Product: '<S145>/Divide'
   */
  rtDW.Memory_PreviousInput[0] = rtb_Gain1_o_idx_0;

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_e[1] = rtDW.T_min[1];

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_f[1] += 0.02 * Switch2_idx_1;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_ep[1] = rtDW.T_max[1];

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[1] = rtb_k_l_idx_1;

  /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
   *  UnaryMinus: '<S16>/Unary Minus'
   */
  rtDW.UnitDelay2_DSTATE[1] = -rtb_Integrator_p_idx_1;

  /* Update for Memory: '<S139>/Memory' incorporates:
   *  Product: '<S145>/Divide'
   */
  rtDW.Memory_PreviousInput[1] = rtb_Gain1_o_idx_1;

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_e[2] = rtDW.T_min[2];

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_f[2] += 0.02 * Switch2_idx_2;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_ep[2] = rtDW.T_max[2];

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[2] = rtb_k_l_idx_2;

  /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
   *  UnaryMinus: '<S16>/Unary Minus'
   */
  rtDW.UnitDelay2_DSTATE[2] = -rtb_Integrator_p_idx_2;

  /* Update for Memory: '<S139>/Memory' incorporates:
   *  Product: '<S145>/Divide'
   */
  rtDW.Memory_PreviousInput[2] = rtb_Gain1_o_idx_2;

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_e[3] = rtDW.T_min[3];

  /* Update for DiscreteIntegrator: '<S119>/Integrator' */
  rtDW.Integrator_DSTATE_f[3] += 0.02 * rtb_Integrator_p;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_ep[3] = rtDW.T_max[3];

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[3] = rtb_k_l_idx_3;

  /* Update for UnitDelay: '<S11>/Unit Delay2' incorporates:
   *  UnaryMinus: '<S16>/Unary Minus'
   */
  rtDW.UnitDelay2_DSTATE[3] = -rtb_Integrator_p_idx_3;

  /* Update for Memory: '<S139>/Memory' incorporates:
   *  Product: '<S145>/Divide'
   */
  rtDW.Memory_PreviousInput[3] = rtb_Gain1_o_idx_3;

  /* Update for DiscreteIntegrator: '<S286>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S279>/1//T' */
  Faeroz = 1.0 / rtb_Integrator_ee;

  /* Update for DiscreteIntegrator: '<S286>/Integrator' */
  rtDW.Integrator_PrevResetState_i = (int8_T)rtb_Compare;

  /* Update for DiscreteIntegrator: '<S295>/Integrator' */
  rtDW.Integrator_IC_LOADING_b = 0U;

  /* Product: '<S288>/1//T' incorporates:
   *  Constant: '<S290>/Time constant'
   *  MinMax: '<S290>/Max'
   */
  rtb_RL = 1.0 / fmax(rtDW.Probe_b[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S295>/Integrator' */
  rtDW.Integrator_PrevResetState_b = (int8_T)rtb_Compare_m;

  /* Update for Memory: '<S255>/Memory' */
  rtDW.Memory_PreviousInput_i = rtb_Logic_idx_0;

  /* Update for Memory: '<S256>/Memory' */
  rtDW.Memory_PreviousInput_j = rtb_Logic_b_idx_0;

  /* Update for Memory: '<S257>/Memory' */
  rtDW.Memory_PreviousInput_f = rtb_Logic_o_idx_0;

  /* Update for Memory: '<S258>/Memory' */
  rtDW.Memory_PreviousInput_ib = rtb_Logic_p_idx_0;

  /* Update for Memory: '<S231>/Memory' */
  rtDW.Memory_PreviousInput_a = rtb_Logic_idx_1;

  /* Update for DiscreteIntegrator: '<S208>/Integrator' */
  rtDW.Integrator_DSTATE_b += 0.02 * yaw_rate;
  rtDW.Integrator_PrevResetState_j = (int8_T)rtb_Logic_o_idx_1;

  /* Update for DiscreteIntegrator: '<S203>/Filter' incorporates:
   *  DiscreteIntegrator: '<S208>/Integrator'
   */
  rtDW.Filter_DSTATE += 0.02 * rtb_NProdOut;
  rtDW.Filter_PrevResetState = (int8_T)rtb_Logic_o_idx_1;

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

  /* Update for DiscreteIntegrator: '<S286>/Integrator' incorporates:
   *  Product: '<S279>/1//T'
   *  Sum: '<S279>/Sum1'
   */
  rtDW.Integrator_DSTATE_d[0] += (rtb_Gain_d1_idx_0 - Switch2_h_idx_0) * Faeroz *
    0.02;

  /* Update for DiscreteIntegrator: '<S295>/Integrator' incorporates:
   *  Product: '<S288>/1//T'
   *  Sum: '<S288>/Sum1'
   */
  rtDW.Integrator_DSTATE_i[0] += (eta_idx_0 - rtb_UnaryMinus_f_idx_2) * rtb_RL *
    0.02;

  /* Update for Delay: '<S171>/Delay' */
  rtDW.Delay_DSTATE[0] = rtDW.Delay_DSTATE[1];

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Torque' */
  rtY.Torque[0] = rtb_Gain1_o_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Update for DiscreteIntegrator: '<S286>/Integrator' incorporates:
   *  Product: '<S279>/1//T'
   *  Sum: '<S279>/Sum1'
   */
  rtDW.Integrator_DSTATE_d[1] += (rtb_Gain_d1_idx_1 - Switch2_h_idx_1) * Faeroz *
    0.02;

  /* Update for DiscreteIntegrator: '<S295>/Integrator' incorporates:
   *  Product: '<S288>/1//T'
   *  Sum: '<S288>/Sum1'
   */
  rtDW.Integrator_DSTATE_i[1] += (eta_idx_1 - rtb_UnaryMinus_f_idx_1) * rtb_RL *
    0.02;

  /* Update for Delay: '<S171>/Delay' */
  rtDW.Delay_DSTATE[1] = rtDW.Delay_DSTATE[2];

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Torque' */
  rtY.Torque[1] = rtb_Gain1_o_idx_1;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Update for DiscreteIntegrator: '<S286>/Integrator' incorporates:
   *  Product: '<S279>/1//T'
   *  Sum: '<S279>/Sum1'
   */
  rtDW.Integrator_DSTATE_d[2] += (rtb_Gain_d1_idx_2 - Switch2_h_idx_2) * Faeroz *
    0.02;

  /* Update for DiscreteIntegrator: '<S295>/Integrator' incorporates:
   *  Product: '<S288>/1//T'
   *  Sum: '<S288>/Sum1'
   */
  rtDW.Integrator_DSTATE_i[2] += (eta_idx_2 - rtb_UnaryMinus_f_idx_0) * rtb_RL *
    0.02;

  /* Update for Delay: '<S171>/Delay' */
  rtDW.Delay_DSTATE[2] = rtDW.Delay_DSTATE[3];

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Torque' */
  rtY.Torque[2] = rtb_Gain1_o_idx_2;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Update for DiscreteIntegrator: '<S286>/Integrator' incorporates:
   *  Product: '<S279>/1//T'
   *  Sum: '<S279>/Sum1'
   */
  rtDW.Integrator_DSTATE_d[3] += (rtb_Gain_d1_idx_3 - Switch2_h_idx_3) * Faeroz *
    0.02;

  /* Update for DiscreteIntegrator: '<S295>/Integrator' incorporates:
   *  Product: '<S288>/1//T'
   *  Sum: '<S288>/Sum1'
   */
  rtDW.Integrator_DSTATE_i[3] += (eta_idx_3 - rtb_UnaryMinus_f_idx_3) * rtb_RL *
    0.02;

  /* Update for Delay: '<S171>/Delay' */
  rtDW.Delay_DSTATE[3] = rtDW.Delay_DSTATE[4];

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Outport: '<Root>/Torque' */
  rtY.Torque[3] = rtb_Gain1_o_idx_3;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Update for Delay: '<S171>/Delay' */
  rtDW.Delay_DSTATE[4] = rtb_Logic_idx_1;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
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
    /* Start for Probe: '<S281>/Probe' */
    rtDW.Probe[0] = 0.02;
    rtDW.Probe[1] = 0.0;

    /* Start for Probe: '<S290>/Probe' */
    rtDW.Probe_b[0] = 0.02;
    rtDW.Probe_b[1] = 0.0;

    /* Start for InitialCondition: '<S150>/IC1' */
    rtDW.IC1_FirstOutputTime = true;

    /* Start for InitialCondition: '<S150>/IC' */
    rtDW.IC_FirstOutputTime = true;

    /* Start for InitialCondition: '<S234>/IC' */
    rtDW.IC_FirstOutputTime_e = true;

    /* Start for InitialCondition: '<S235>/IC1' */
    rtDW.IC1_FirstOutputTime_m = true;

    /* Start for DataStoreMemory: '<S3>/Data Store_General_Params' */
    rtDW.General_Params = rtConstP.DataStore_General_Params_Initia;

    /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator' */
    rtDW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
    rtDW.Integrator_PrevResetState_g = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S286>/Integrator' */
    rtDW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S295>/Integrator' */
    rtDW.Integrator_IC_LOADING_b = 1U;

    /* SystemInitialize for Chart: '<S238>/Distribution complete' */
    rtDW.tr = 1.27;
    rtDW.Rw = 0.235;

    /* Start for MATLABSystem: '<S171>/Moving Average' */
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

    /* InitializeConditions for MATLABSystem: '<S171>/Moving Average' */
    iobj_0 = rtDW.obj.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum = 0.0;
      for (i = 0; i < 24; i++) {
        iobj_0->pCumSumRev[i] = 0.0;
      }

      iobj_0->pCumRevIndex = 1.0;
      iobj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S171>/Moving Average' */

    /* Start for MATLABSystem: '<S277>/Moving Average' */
    rtDW.obj_l.matlabCodegenIsDeleted = true;
    rtDW.obj_l.isInitialized = 0;
    rtDW.obj_l.NumChannels = -1;
    rtDW.obj_l.matlabCodegenIsDeleted = false;
    rtDW.obj_l.isSetupComplete = false;
    rtDW.obj_l.isInitialized = 1;
    rtDW.obj_l.NumChannels = 1;
    iobj_0_0 = &rtDW.obj_l._pobj0;
    iobj_0_0->isInitialized = 0;
    iobj_0_0->isInitialized = 0;
    rtDW.obj_l.pStatistic = iobj_0_0;
    rtDW.obj_l.isSetupComplete = true;
    rtDW.obj_l.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S277>/Moving Average' */
    iobj_0_0 = rtDW.obj_l.pStatistic;
    if (iobj_0_0->isInitialized == 1) {
      iobj_0_0->pCumSum = 0.0;
      iobj_0_0->pCumSumRev[0] = 0.0;
      iobj_0_0->pCumSumRev[1] = 0.0;
      iobj_0_0->pCumSumRev[2] = 0.0;
      iobj_0_0->pCumSumRev[3] = 0.0;
      iobj_0_0->pCumRevIndex = 1.0;
      iobj_0_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S277>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
