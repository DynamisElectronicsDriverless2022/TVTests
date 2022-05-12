/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.c
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu May 12 19:12:17 2022
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

/* Model step function */
void TV(void)
{
  real_T rtb_y[121];
  real_T varargin_1[49];
  real_T rtb_CCaller_o12[28];
  real_T rtb_CCaller_o3[26];
  real_T rtb_CCaller_o6[22];
  real_T varargin_2[16];
  real_T RateTransition3[13];
  real_T rtb_CCaller_o2[7];
  real_T rtb_Efficiency[4];
  real_T rtb_Memory[4];
  real_T rtb_Tire_lbu[4];
  real_T rtb_uDLookupTable[4];
  real_T rtb_ubu[4];
  real_T rtb_ug_p[4];
  real_T fractions[2];
  real_T fractions_0[2];
  real_T rtb_Abs;
  real_T rtb_Abs_b_idx_1;
  real_T rtb_Abs_b_idx_2;
  real_T rtb_Abs_b_idx_3;
  real_T rtb_Abs_idx_0;
  real_T rtb_Integrator_idx_0;
  real_T rtb_Integrator_idx_1;
  real_T rtb_Integrator_idx_2;
  real_T rtb_Integrator_idx_3;
  real_T rtb_Max;
  real_T rtb_RL_m;
  real_T rtb_RR;
  real_T rtb_Saturation;
  real_T rtb_Sign;
  real_T rtb_Switch_l;
  real_T rtb_Tire_lbu_tmp;
  real_T rtb_Tire_lbu_tmp_0;
  real_T rtb_lg;
  real_T rtb_lg_idx_0;
  real_T rtb_lg_idx_1;
  real_T rtb_lg_idx_2;
  real_T rtb_torquemapselected;
  real_T rtb_vx;
  real_T rtb_yaw_rate;
  real_T u0_tmp;
  real_T u0_tmp_0;
  real_T u0_tmp_1;
  int32_T i;
  int32_T iU;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  boolean_T rtb_AND_o;
  boolean_T rtb_Compare;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Saturate: '<S1>/Saturation' incorporates:
   *  Inport: '<Root>/vx'
   */
  if (rtU.vx <= 0.0) {
    rtb_Switch_l = 0.0;
  } else {
    rtb_Switch_l = rtU.vx;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/yaw_rate'
   */
  rtb_torquemapselected = 0.017453292519943295 * rtU.yaw_rate_deg;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Switch_l <= 0.0) {
    rtb_vx = 0.0;
  } else {
    rtb_vx = rtb_Switch_l;
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
  rtb_Abs_idx_0 = fabs(look1_binlx(rtU.steering, rtConstP.pooled15,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Product: '<S9>/Divide1' incorporates:
   *  Abs: '<S9>/Abs'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angles_LUT'
   *  UnaryMinus: '<S9>/Unary Minus'
   */
  rtb_Abs = fabs(look1_binlx(-rtU.steering, rtConstP.pooled15,
    rtConstP.steering_to_wheel_angles_LUT_ta, 32U)) * rtb_Sign;

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S12>/Gain3'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   *  Product: '<S11>/Divide4'
   *  Product: '<S12>/Divide4'
   *  Product: '<S13>/Divide'
   *  Product: '<S14>/Divide'
   *  Sum: '<S11>/Subtract3'
   *  Sum: '<S12>/Subtract3'
   *  Sum: '<S13>/Subtract'
   *  Sum: '<S14>/Subtract'
   *  Switch: '<S12>/Switch'
   *  Switch: '<S13>/Switch'
   *  Switch: '<S14>/Switch'
   */
  if (rtb_vx > 0.5) {
    /* Sum: '<S11>/Sum' incorporates:
     *  Inport: '<Root>/vy'
     *  Product: '<S11>/Divide5'
     *  Product: '<S11>/Divide6'
     *  Trigonometry: '<S11>/Cos1'
     *  Trigonometry: '<S11>/Cos2'
     */
    rtb_Sign = rtb_vx * cos(rtb_Abs_idx_0) + sin(rtb_Abs_idx_0) * rtU.vy;
    rtb_Switch_l = (0.235 * rtU.omega_wheels_FL - rtb_Sign) / rtb_Sign;

    /* Sum: '<S12>/Sum' incorporates:
     *  Gain: '<S11>/Gain3'
     *  Inport: '<Root>/omega_wheels_FL'
     *  Inport: '<Root>/vy'
     *  Product: '<S11>/Divide4'
     *  Product: '<S12>/Divide5'
     *  Product: '<S12>/Divide6'
     *  Sum: '<S11>/Subtract3'
     *  Trigonometry: '<S12>/Cos1'
     *  Trigonometry: '<S12>/Cos2'
     */
    rtb_Sign = rtb_vx * cos(rtb_Abs) + sin(rtb_Abs) * rtU.vy;
    rtb_Sign = (0.235 * rtU.omega_wheels_FR - rtb_Sign) / rtb_Sign;
    rtb_RR = (0.235 * rtU.omega_wheels_RR - rtb_vx) / rtb_vx;
    rtb_RL_m = (0.235 * rtU.omega_wheels_RL - rtb_vx) / rtb_vx;
  } else {
    rtb_Switch_l = 0.0;
    rtb_Sign = 0.0;
    rtb_RR = 0.0;
    rtb_RL_m = 0.0;
  }

  /* End of Switch: '<S11>/Switch' */

  /* CFunction: '<S28>/C Function' */
  memset(&rtDW.CFunction[0], 0, 11U * sizeof(real_T));

  /* RateTransition: '<S31>/Rate Transition3' incorporates:
   *  Constant: '<S18>/Inertia Scaling'
   *  Constant: '<S18>/LMUy'
   *  Inport: '<Root>/ax'
   *  Inport: '<Root>/ay'
   *  Inport: '<Root>/steering'
   *  Lookup_n-D: '<S9>/steering_to_wheel_angle_single_axis_LUT'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  RateTransition3[0] = look1_binlx(rtU.steering, rtConstP.pooled15,
    rtConstP.steering_to_wheel_angle_single_, 32U);
  RateTransition3[1] = rtb_Switch_l;
  RateTransition3[2] = rtb_Sign;
  RateTransition3[3] = rtb_RL_m;
  RateTransition3[4] = rtb_RR;
  RateTransition3[5] = rtDW.UnitDelay_DSTATE[0];
  RateTransition3[6] = rtDW.UnitDelay_DSTATE[1];
  RateTransition3[7] = rtDW.UnitDelay_DSTATE[2];
  RateTransition3[8] = rtDW.UnitDelay_DSTATE[3];
  RateTransition3[9] = rtU.ay;
  RateTransition3[10] = rtU.ax;
  RateTransition3[11] = 0.93;
  RateTransition3[12] = 1.0;

  /* CFunction: '<S31>/C Function' incorporates:
   *  Constant: '<S31>/Constant3'
   */
  for (i = 0; i < 2; i++) {
    memcpy(&rtDW.CFunction_n[i * 13], &RateTransition3[0], 13U * sizeof(real_T));
  }

  /* End of CFunction: '<S31>/C Function' */

  /* Saturate: '<S19>/Saturation2' */
  if (rtb_torquemapselected > 4.0) {
    rtb_yaw_rate = 4.0;
  } else if (rtb_torquemapselected < -4.0) {
    rtb_yaw_rate = -4.0;
  } else {
    rtb_yaw_rate = rtb_torquemapselected;
  }

  /* End of Saturate: '<S19>/Saturation2' */

  /* Memory: '<S15>/Memory' */
  rtb_Memory[0] = rtDW.Memory_PreviousInput[0];
  rtb_Memory[1] = rtDW.Memory_PreviousInput[1];
  rtb_Memory[2] = rtDW.Memory_PreviousInput[2];
  rtb_Memory[3] = rtDW.Memory_PreviousInput[3];

  /* Math: '<S47>/Square1' incorporates:
   *  Math: '<S47>/Square2'
   *  Math: '<S49>/Square1'
   */
  rtb_Tire_lbu_tmp = rtb_vx * rtb_vx;

  /* Gain: '<S47>/Lateral Load Transfer' incorporates:
   *  Gain: '<S48>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  UnaryMinus: '<S47>/Unary Minus'
   */
  rtb_lg_idx_0 = 15.413385826771654 * -rtU.ay;

  /* Gain: '<S47>/Lift Force' incorporates:
   *  Gain: '<S48>/Lift Force'
   *  Math: '<S47>/Square1'
   */
  rtb_Tire_lbu_tmp_0 = rtb_Tire_lbu_tmp * 0.87348504901960788;

  /* Gain: '<S47>/Drag moment' incorporates:
   *  Gain: '<S48>/Drag moment'
   *  Gain: '<S49>/Drag moment'
   *  Gain: '<S50>/Drag moment'
   */
  rtb_lg_idx_1 = rtb_Tire_lbu_tmp * 0.19692235294117649;

  /* Gain: '<S47>/Longitudinal Load Transfer' incorporates:
   *  Gain: '<S48>/Longitudinal Load Transfer'
   *  Gain: '<S49>/Longitudinal Load Transfer'
   *  Gain: '<S50>/Longitudinal Load Transfer'
   *  Inport: '<Root>/ax'
   *  UnaryMinus: '<S47>/Unary Minus1'
   */
  rtb_Abs_b_idx_2 = 25.588235294117645 * -rtU.ax;

  /* SignalConversion generated from: '<S25>/2-D Lookup Table' incorporates:
   *  Constant: '<S47>/Static Load Front'
   *  Constant: '<S48>/Static Load Front'
   *  Gain: '<S47>/Drag moment'
   *  Gain: '<S47>/Lateral Load Transfer'
   *  Gain: '<S47>/Lift Force'
   *  Gain: '<S47>/Longitudinal Load Transfer'
   *  Sum: '<S47>/Subtract'
   *  Sum: '<S48>/Subtract'
   */
  rtb_Tire_lbu[0] = (((rtb_lg_idx_0 + 662.17500000000007) + rtb_Tire_lbu_tmp_0)
                     - rtb_lg_idx_1) + rtb_Abs_b_idx_2;
  rtb_Tire_lbu[1] = (((662.17500000000007 - rtb_lg_idx_0) + rtb_Tire_lbu_tmp_0)
                     - rtb_lg_idx_1) + rtb_Abs_b_idx_2;

  /* Gain: '<S49>/Lift Force' incorporates:
   *  Gain: '<S50>/Lift Force'
   */
  rtb_Tire_lbu_tmp *= 0.70063995098039222;

  /* SignalConversion generated from: '<S25>/2-D Lookup Table' incorporates:
   *  Constant: '<S49>/Static Load Front'
   *  Constant: '<S50>/Static Load Front'
   *  Gain: '<S49>/Lateral Load Transfer'
   *  Gain: '<S49>/Lift Force'
   *  Gain: '<S50>/Lateral Load Transfer'
   *  Inport: '<Root>/ay'
   *  Sum: '<S49>/Subtract'
   *  Sum: '<S50>/Subtract'
   *  UnaryMinus: '<S49>/Unary Minus'
   *  UnaryMinus: '<S50>/Unary Minus'
   */
  rtb_Tire_lbu[2] = (((15.413385826771654 * -rtU.ay + 662.17500000000007) +
                      rtb_Tire_lbu_tmp) + rtb_lg_idx_1) - rtb_Abs_b_idx_2;
  rtb_Tire_lbu[3] = (((662.17500000000007 - 15.413385826771654 * -rtU.ay) +
                      rtb_Tire_lbu_tmp) + rtb_lg_idx_1) - rtb_Abs_b_idx_2;

  /* SignalConversion generated from: '<S25>/2-D Lookup Table' incorporates:
   *  Gain: '<S52>/Gain'
   *  Gain: '<S52>/Gain1'
   *  Gain: '<S53>/Gain'
   *  Gain: '<S53>/Gain1'
   *  Gain: '<S54>/Gain'
   *  Gain: '<S54>/Gain1'
   *  Gain: '<S55>/Gain'
   *  Gain: '<S55>/Gain1'
   *  Inport: '<Root>/vy'
   *  Sum: '<S52>/Subtract'
   *  Sum: '<S52>/Subtract1'
   *  Sum: '<S52>/Subtract2'
   *  Sum: '<S53>/Subtract'
   *  Sum: '<S53>/Subtract1'
   *  Sum: '<S53>/Subtract2'
   *  Sum: '<S54>/Subtract'
   *  Sum: '<S54>/Subtract1'
   *  Sum: '<S55>/Subtract'
   *  Sum: '<S55>/Subtract1'
   *  Trigonometry: '<S52>/Atan'
   *  Trigonometry: '<S53>/Atan'
   *  Trigonometry: '<S54>/Atan'
   *  Trigonometry: '<S55>/Atan'
   */
  rtb_uDLookupTable[0] = rt_atan2d_snf(0.765 * rtb_torquemapselected + rtU.vy,
    rtb_vx - 0.635 * rtb_torquemapselected) - rtb_Abs_idx_0;
  rtb_uDLookupTable[1] = rt_atan2d_snf(0.765 * rtb_torquemapselected + rtU.vy,
    0.635 * rtb_torquemapselected + rtb_vx) - rtb_Abs;
  rtb_uDLookupTable[2] = rt_atan2d_snf(rtU.vy - 0.765 * rtb_torquemapselected,
    rtb_vx - 0.635 * rtb_torquemapselected);
  rtb_uDLookupTable[3] = rt_atan2d_snf(rtU.vy - 0.765 * rtb_torquemapselected,
    0.635 * rtb_torquemapselected + rtb_vx);

  /* Lookup_n-D: '<S25>/2-D Lookup Table' */
  rtb_Abs_idx_0 = look2_binlx(rtb_Tire_lbu[0], rtb_uDLookupTable[0],
    rtConstP.pooled26, rtConstP.pooled27, rtConstP.uDLookupTable_tableData,
    rtConstP.pooled49, 20U);
  rtb_Abs_b_idx_1 = look2_binlx(rtb_Tire_lbu[1], rtb_uDLookupTable[1],
    rtConstP.pooled26, rtConstP.pooled27, rtConstP.uDLookupTable_tableData,
    rtConstP.pooled49, 20U);
  rtb_Abs_b_idx_2 = look2_binlx(rtb_Tire_lbu[2], rtb_uDLookupTable[2],
    rtConstP.pooled26, rtConstP.pooled27, rtConstP.uDLookupTable_tableData,
    rtConstP.pooled49, 20U);
  rtb_Abs_b_idx_3 = look2_binlx(rtb_Tire_lbu[3], rtb_uDLookupTable[3],
    rtConstP.pooled26, rtConstP.pooled27, rtConstP.uDLookupTable_tableData,
    rtConstP.pooled49, 20U);

  /* Lookup_n-D: '<S61>/Max_Torque_Overload_Motor_LUT' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Lookup_n-D: '<S61>/Max_Torque_Overload_Inverter_LUT'
   *  Lookup_n-D: '<S62>/Display Overload Inverter LUT'
   *  Lookup_n-D: '<S62>/Display Overload Motor LUT'
   */
  rtb_torquemapselected = look1_binlx(0.0, rtConstP.pooled30, rtConstP.pooled29,
    2U);
  rtb_Efficiency[0] = rtb_torquemapselected;
  rtb_Efficiency[1] = rtb_torquemapselected;
  rtb_Efficiency[2] = rtb_torquemapselected;
  rtb_Efficiency[3] = rtb_torquemapselected;

  /* Lookup_n-D: '<S61>/Max_Torque_Overload_Inverter_LUT' */
  rtb_ug_p[0] = rtb_torquemapselected;
  rtb_ug_p[1] = rtb_torquemapselected;
  rtb_ug_p[2] = rtb_torquemapselected;
  rtb_ug_p[3] = rtb_torquemapselected;

  /* Lookup_n-D: '<S61>/Max_Torque_Temperature_Internal_LUT' incorporates:
   *  Constant: '<S2>/Constant13'
   *  Lookup_n-D: '<S62>/Temperature Internal LUT'
   */
  rtb_Abs = look1_binlx(0.0, rtConstP.pooled31, rtConstP.pooled29, 2U);

  /* RelationalOperator: '<S69>/Compare' incorporates:
   *  Constant: '<S66>/Time constant'
   *  Constant: '<S69>/Constant'
   *  Sum: '<S66>/Sum1'
   */
  rtb_Compare = (0.079577471545947673 - rtDW.Probe[0] <= 0.0);

  /* Gain: '<S63>/Gain4' incorporates:
   *  Gain: '<S72>/Gain4'
   *  Inport: '<Root>/omega_wheels_FL'
   *  Inport: '<Root>/omega_wheels_FR'
   *  Inport: '<Root>/omega_wheels_RL'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  rtb_Tire_lbu_tmp_0 = 128.91550390443524 * rtU.omega_wheels_FL;
  u0_tmp = 128.91550390443524 * rtU.omega_wheels_FR;
  u0_tmp_0 = 128.91550390443524 * rtU.omega_wheels_RL;
  u0_tmp_1 = 128.91550390443524 * rtU.omega_wheels_RR;

  /* Lookup_n-D: '<S63>/2-D Lookup Table' incorporates:
   *  Constant: '<S2>/Constant14'
   */
  bpIndices[1U] = plook_binc(540.0, rtConstP.pooled35, 45U, &rtb_Saturation);
  fractions[1U] = rtb_Saturation;

  /* Saturate: '<S63>/Saturation1' incorporates:
   *  Gain: '<S63>/Gain4'
   */
  if (rtb_Tire_lbu_tmp_0 <= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  } else {
    rtb_Tire_lbu_tmp = rtb_Tire_lbu_tmp_0;
  }

  /* Lookup_n-D: '<S63>/2-D Lookup Table' */
  bpIndices[0U] = plook_binc(rtb_Tire_lbu_tmp, rtConstP.pooled34, 200U,
    &rtb_Saturation);
  fractions[0U] = rtb_Saturation;
  rtb_lg_idx_0 = intrp2d_l(bpIndices, fractions, rtConstP.pooled33, 201U);

  /* Saturate: '<S63>/Saturation1' incorporates:
   *  Gain: '<S63>/Gain4'
   */
  if (u0_tmp <= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  } else {
    rtb_Tire_lbu_tmp = u0_tmp;
  }

  /* Lookup_n-D: '<S63>/2-D Lookup Table' */
  bpIndices[0U] = plook_binc(rtb_Tire_lbu_tmp, rtConstP.pooled34, 200U,
    &rtb_Saturation);
  fractions[0U] = rtb_Saturation;
  rtb_lg_idx_1 = intrp2d_l(bpIndices, fractions, rtConstP.pooled33, 201U);

  /* Saturate: '<S63>/Saturation1' incorporates:
   *  Gain: '<S63>/Gain4'
   */
  if (u0_tmp_0 <= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  } else {
    rtb_Tire_lbu_tmp = u0_tmp_0;
  }

  /* Lookup_n-D: '<S63>/2-D Lookup Table' */
  bpIndices[0U] = plook_binc(rtb_Tire_lbu_tmp, rtConstP.pooled34, 200U,
    &rtb_Saturation);
  fractions[0U] = rtb_Saturation;
  rtb_lg_idx_2 = intrp2d_l(bpIndices, fractions, rtConstP.pooled33, 201U);

  /* Saturate: '<S63>/Saturation1' incorporates:
   *  Gain: '<S63>/Gain4'
   */
  if (u0_tmp_1 <= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  } else {
    rtb_Tire_lbu_tmp = u0_tmp_1;
  }

  /* Lookup_n-D: '<S63>/2-D Lookup Table' */
  bpIndices[0U] = plook_binc(rtb_Tire_lbu_tmp, rtConstP.pooled34, 200U,
    &rtb_Saturation);
  fractions[0U] = rtb_Saturation;

  /* Gain: '<S63>/Gain' incorporates:
   *  Lookup_n-D: '<S63>/2-D Lookup Table'
   */
  rtb_lg_idx_0 *= 0.0098000000000000014;
  rtb_lg_idx_1 *= 0.0098000000000000014;
  rtb_lg_idx_2 *= 0.0098000000000000014;
  rtb_lg = 0.0098000000000000014 * intrp2d_l(bpIndices, fractions,
    rtConstP.pooled33, 201U);

  /* DiscreteIntegrator: '<S71>/Integrator' */
  if (rtDW.Integrator_IC_LOADING != 0) {
    rtDW.Integrator_DSTATE[0] = rtb_lg_idx_0;
    rtDW.Integrator_DSTATE[1] = rtb_lg_idx_1;
    rtDW.Integrator_DSTATE[2] = rtb_lg_idx_2;
    rtDW.Integrator_DSTATE[3] = rtb_lg;
  }

  if (rtb_Compare || (rtDW.Integrator_PrevResetState != 0)) {
    rtDW.Integrator_DSTATE[0] = rtb_lg_idx_0;
    rtDW.Integrator_DSTATE[1] = rtb_lg_idx_1;
    rtDW.Integrator_DSTATE[2] = rtb_lg_idx_2;
    rtDW.Integrator_DSTATE[3] = rtb_lg;
  }

  rtb_Integrator_idx_0 = rtDW.Integrator_DSTATE[0];
  rtb_Integrator_idx_1 = rtDW.Integrator_DSTATE[1];
  rtb_Integrator_idx_2 = rtDW.Integrator_DSTATE[2];
  rtb_Integrator_idx_3 = rtDW.Integrator_DSTATE[3];

  /* MinMax: '<S61>/Min' incorporates:
   *  Constant: '<S63>/Constant'
   *  DiscreteIntegrator: '<S71>/Integrator'
   *  Lookup_n-D: '<S61>/Max_Torque_Temperature_Internal_LUT'
   *  RelationalOperator: '<S65>/LowerRelop1'
   *  RelationalOperator: '<S65>/UpperRelop'
   *  Switch: '<S65>/Switch'
   *  Switch: '<S65>/Switch2'
   */
  if (rtDW.Integrator_DSTATE[0] > 21.0) {
    rtb_Tire_lbu_tmp = 21.0;
  } else if (rtDW.Integrator_DSTATE[0] < 0.0) {
    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Tire_lbu_tmp = 0.0;
  } else {
    rtb_Tire_lbu_tmp = rtDW.Integrator_DSTATE[0];
  }

  rtb_Tire_lbu_tmp = fmin(fmin(fmin(fmin(rtb_Efficiency[0], rtb_ug_p[0]),
    rtb_Abs), 20.972), rtb_Tire_lbu_tmp);

  /* Saturate: '<S61>/Saturation_Positive' incorporates:
   *  MinMax: '<S61>/Min'
   */
  if (rtb_Tire_lbu_tmp <= 0.0) {
    rtb_Efficiency[0] = 0.0;
  } else {
    rtb_Efficiency[0] = rtb_Tire_lbu_tmp;
  }

  /* MinMax: '<S61>/Min' incorporates:
   *  Constant: '<S63>/Constant'
   *  DiscreteIntegrator: '<S71>/Integrator'
   *  Lookup_n-D: '<S61>/Max_Torque_Temperature_Internal_LUT'
   *  RelationalOperator: '<S65>/LowerRelop1'
   *  RelationalOperator: '<S65>/UpperRelop'
   *  Switch: '<S65>/Switch'
   *  Switch: '<S65>/Switch2'
   */
  if (rtDW.Integrator_DSTATE[1] > 21.0) {
    rtb_Tire_lbu_tmp = 21.0;
  } else if (rtDW.Integrator_DSTATE[1] < 0.0) {
    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Tire_lbu_tmp = 0.0;
  } else {
    rtb_Tire_lbu_tmp = rtDW.Integrator_DSTATE[1];
  }

  rtb_Tire_lbu_tmp = fmin(fmin(fmin(fmin(rtb_Efficiency[1], rtb_ug_p[1]),
    rtb_Abs), 20.972), rtb_Tire_lbu_tmp);

  /* Saturate: '<S61>/Saturation_Positive' incorporates:
   *  MinMax: '<S61>/Min'
   */
  if (rtb_Tire_lbu_tmp <= 0.0) {
    rtb_Efficiency[1] = 0.0;
  } else {
    rtb_Efficiency[1] = rtb_Tire_lbu_tmp;
  }

  /* MinMax: '<S61>/Min' incorporates:
   *  Constant: '<S63>/Constant'
   *  DiscreteIntegrator: '<S71>/Integrator'
   *  Lookup_n-D: '<S61>/Max_Torque_Temperature_Internal_LUT'
   *  RelationalOperator: '<S65>/LowerRelop1'
   *  RelationalOperator: '<S65>/UpperRelop'
   *  Switch: '<S65>/Switch'
   *  Switch: '<S65>/Switch2'
   */
  if (rtDW.Integrator_DSTATE[2] > 21.0) {
    rtb_Tire_lbu_tmp = 21.0;
  } else if (rtDW.Integrator_DSTATE[2] < 0.0) {
    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Tire_lbu_tmp = 0.0;
  } else {
    rtb_Tire_lbu_tmp = rtDW.Integrator_DSTATE[2];
  }

  rtb_Tire_lbu_tmp = fmin(fmin(fmin(fmin(rtb_Efficiency[2], rtb_ug_p[2]),
    rtb_Abs), 20.972), rtb_Tire_lbu_tmp);

  /* Saturate: '<S61>/Saturation_Positive' incorporates:
   *  MinMax: '<S61>/Min'
   */
  if (rtb_Tire_lbu_tmp <= 0.0) {
    rtb_Efficiency[2] = 0.0;
  } else {
    rtb_Efficiency[2] = rtb_Tire_lbu_tmp;
  }

  /* MinMax: '<S61>/Min' incorporates:
   *  Constant: '<S63>/Constant'
   *  DiscreteIntegrator: '<S71>/Integrator'
   *  Lookup_n-D: '<S61>/Max_Torque_Temperature_Internal_LUT'
   *  RelationalOperator: '<S65>/LowerRelop1'
   *  RelationalOperator: '<S65>/UpperRelop'
   *  Switch: '<S65>/Switch'
   *  Switch: '<S65>/Switch2'
   */
  if (rtDW.Integrator_DSTATE[3] > 21.0) {
    rtb_Tire_lbu_tmp = 21.0;
  } else if (rtDW.Integrator_DSTATE[3] < 0.0) {
    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Tire_lbu_tmp = 0.0;
  } else {
    rtb_Tire_lbu_tmp = rtDW.Integrator_DSTATE[3];
  }

  rtb_Tire_lbu_tmp = fmin(fmin(fmin(fmin(rtb_Efficiency[3], rtb_ug_p[3]),
    rtb_Abs), 20.972), rtb_Tire_lbu_tmp);

  /* Saturate: '<S61>/Saturation_Positive' incorporates:
   *  MinMax: '<S61>/Min'
   */
  if (rtb_Tire_lbu_tmp <= 0.0) {
    rtb_Efficiency[3] = 0.0;
  } else {
    rtb_Efficiency[3] = rtb_Tire_lbu_tmp;
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/brake'
   */
  rtb_Max = 3.5714285714285712 * rtU.brake;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Max > 1.0) {
    rtb_Max = 1.0;
  } else if (rtb_Max < 0.0) {
    rtb_Max = 0.0;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Switch: '<S38>/Switch' */
  rtb_Saturation = !(rtb_Max > 0.95);

  /* Product: '<S25>/Product' incorporates:
   *  Gain: '<S25>/Gain'
   */
  rtb_Tire_lbu_tmp = 0.017407407407407406 * rtb_Abs_idx_0 * 0.80645161290322576;

  /* Saturate: '<S25>/Saturation1' */
  if (rtb_Tire_lbu_tmp <= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  }

  /* Product: '<S38>/Product' incorporates:
   *  Constant: '<S25>/Constant'
   *  MinMax: '<S25>/Min'
   */
  rtb_ubu[0] = fmin(fmin(rtb_Tire_lbu_tmp, rtb_Efficiency[0]), 100.0) *
    rtb_Saturation;

  /* Product: '<S25>/Product' incorporates:
   *  Gain: '<S25>/Gain'
   */
  rtb_Tire_lbu_tmp = 0.017407407407407406 * rtb_Abs_b_idx_1 *
    0.80645161290322576;

  /* Saturate: '<S25>/Saturation1' */
  if (rtb_Tire_lbu_tmp <= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  }

  /* Product: '<S38>/Product' incorporates:
   *  Constant: '<S25>/Constant'
   *  MinMax: '<S25>/Min'
   */
  rtb_ubu[1] = fmin(fmin(rtb_Tire_lbu_tmp, rtb_Efficiency[1]), 100.0) *
    rtb_Saturation;

  /* Product: '<S25>/Product' incorporates:
   *  Gain: '<S25>/Gain'
   */
  rtb_Tire_lbu_tmp = 0.017407407407407406 * rtb_Abs_b_idx_2 *
    0.80645161290322576;

  /* Saturate: '<S25>/Saturation1' */
  if (rtb_Tire_lbu_tmp <= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  }

  /* Product: '<S38>/Product' incorporates:
   *  Constant: '<S25>/Constant'
   *  MinMax: '<S25>/Min'
   */
  rtb_ubu[2] = fmin(fmin(rtb_Tire_lbu_tmp, rtb_Efficiency[2]), 100.0) *
    rtb_Saturation;

  /* Product: '<S25>/Product' incorporates:
   *  Gain: '<S25>/Gain'
   */
  rtb_Tire_lbu_tmp = 0.017407407407407406 * rtb_Abs_b_idx_3 *
    0.80645161290322576;

  /* Saturate: '<S25>/Saturation1' */
  if (rtb_Tire_lbu_tmp <= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  }

  /* Product: '<S38>/Product' incorporates:
   *  Constant: '<S25>/Constant'
   *  MinMax: '<S25>/Min'
   */
  rtb_ubu[3] = fmin(fmin(rtb_Tire_lbu_tmp, rtb_Efficiency[3]), 100.0) *
    rtb_Saturation;

  /* DiscreteFir: '<S51>/Discrete FIR Filter' */
  i = 16384;
  for (iU = rtDW.DiscreteFIRFilter_circBuf; iU < 9; iU++) {
    i += rtDW.DiscreteFIRFilter_states[iU] << 14;
  }

  for (iU = 0; iU < rtDW.DiscreteFIRFilter_circBuf; iU++) {
    i += rtDW.DiscreteFIRFilter_states[iU] << 14;
  }

  /* RelationalOperator: '<S51>/Less Than4' incorporates:
   *  DiscreteFir: '<S51>/Discrete FIR Filter'
   */
  rtb_AND_o = (i >= 163840);

  /* Lookup_n-D: '<S25>/2-D Lookup Table1' */
  rtb_Tire_lbu[0] = look2_binlx(rtb_Tire_lbu[0], rtb_uDLookupTable[0],
    rtConstP.pooled26, rtConstP.pooled27, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled49, 20U);
  rtb_Tire_lbu[1] = look2_binlx(rtb_Tire_lbu[1], rtb_uDLookupTable[1],
    rtConstP.pooled26, rtConstP.pooled27, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled49, 20U);
  rtb_Tire_lbu[2] = look2_binlx(rtb_Tire_lbu[2], rtb_uDLookupTable[2],
    rtConstP.pooled26, rtConstP.pooled27, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled49, 20U);
  rtb_Tire_lbu[3] = look2_binlx(rtb_Tire_lbu[3], rtb_uDLookupTable[3],
    rtConstP.pooled26, rtConstP.pooled27, rtConstP.uDLookupTable1_tableData,
    rtConstP.pooled49, 20U);

  /* Lookup_n-D: '<S62>/Display Overload Motor LUT' */
  rtb_ug_p[0] = rtb_torquemapselected;
  rtb_ug_p[1] = rtb_torquemapselected;
  rtb_ug_p[2] = rtb_torquemapselected;
  rtb_ug_p[3] = rtb_torquemapselected;

  /* Lookup_n-D: '<S62>/Display Overload Inverter LUT' */
  rtb_Efficiency[0] = rtb_torquemapselected;
  rtb_Efficiency[1] = rtb_torquemapselected;
  rtb_Efficiency[2] = rtb_torquemapselected;
  rtb_Efficiency[3] = rtb_torquemapselected;

  /* MultiPortSwitch: '<S72>/Multiport Switch' incorporates:
   *  Constant: '<S72>/Constant1'
   */
  rtb_torquemapselected = 21.0;

  /* Saturate: '<S72>/Saturation1' */
  if (rtb_Tire_lbu_tmp_0 <= 0.0) {
    rtb_Abs_idx_0 = 0.0;
  } else {
    rtb_Abs_idx_0 = rtb_Tire_lbu_tmp_0;
  }

  if (u0_tmp <= 0.0) {
    rtb_Abs_b_idx_1 = 0.0;
  } else {
    rtb_Abs_b_idx_1 = u0_tmp;
  }

  if (u0_tmp_0 <= 0.0) {
    rtb_Abs_b_idx_2 = 0.0;
  } else {
    rtb_Abs_b_idx_2 = u0_tmp_0;
  }

  if (u0_tmp_1 <= 0.0) {
    rtb_Abs_b_idx_3 = 0.0;
  } else {
    rtb_Abs_b_idx_3 = u0_tmp_1;
  }

  /* End of Saturate: '<S72>/Saturation1' */

  /* Lookup_n-D: '<S72>/1-D Lookup Table' */
  rtb_uDLookupTable[0] = look1_binlx(rtb_Abs_idx_0,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData_d, 19U);
  rtb_uDLookupTable[1] = look1_binlx(rtb_Abs_b_idx_1,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData_d, 19U);
  rtb_uDLookupTable[2] = look1_binlx(rtb_Abs_b_idx_2,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData_d, 19U);
  rtb_uDLookupTable[3] = look1_binlx(rtb_Abs_b_idx_3,
    rtConstP.uDLookupTable_bp01Data, rtConstP.uDLookupTable_tableData_d, 19U);

  /* Lookup_n-D: '<S72>/2-D Lookup Table1' incorporates:
   *  Constant: '<S2>/Constant14'
   */
  bpIndices_0[1U] = plook_binc(540.0, rtConstP.pooled35, 45U, &rtb_Saturation);
  fractions_0[1U] = rtb_Saturation;
  bpIndices_0[0U] = plook_binc(rtb_Abs_idx_0, rtConstP.pooled34, 200U,
    &rtb_Saturation);
  fractions_0[0U] = rtb_Saturation;
  rtb_Abs_idx_0 = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled33, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Abs_b_idx_1, rtConstP.pooled34, 200U,
    &rtb_Saturation);
  fractions_0[0U] = rtb_Saturation;
  rtb_Abs_b_idx_1 = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled33, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Abs_b_idx_2, rtConstP.pooled34, 200U,
    &rtb_Saturation);
  fractions_0[0U] = rtb_Saturation;
  rtb_Abs_b_idx_2 = intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled33, 201U);
  bpIndices_0[0U] = plook_binc(rtb_Abs_b_idx_3, rtConstP.pooled34, 200U,
    &rtb_Saturation);
  fractions_0[0U] = rtb_Saturation;

  /* Gain: '<S72>/Gain' incorporates:
   *  Lookup_n-D: '<S72>/2-D Lookup Table1'
   *  MinMax: '<S72>/Min'
   */
  rtb_Abs_idx_0 = 0.0098000000000000014 * fmin(rtb_uDLookupTable[0],
    rtb_Abs_idx_0);
  rtb_Abs_b_idx_1 = 0.0098000000000000014 * fmin(rtb_uDLookupTable[1],
    rtb_Abs_b_idx_1);
  rtb_Abs_b_idx_2 = 0.0098000000000000014 * fmin(rtb_uDLookupTable[2],
    rtb_Abs_b_idx_2);
  rtb_Tire_lbu_tmp_0 = 0.0098000000000000014 * fmin(rtb_uDLookupTable[3],
    intrp2d_l(bpIndices_0, fractions_0, rtConstP.pooled33, 201U));

  /* Switch: '<S73>/Switch2' incorporates:
   *  Constant: '<S72>/Constant'
   *  RelationalOperator: '<S73>/LowerRelop1'
   *  RelationalOperator: '<S73>/UpperRelop'
   *  Switch: '<S73>/Switch'
   */
  if (rtb_Abs_idx_0 > rtb_torquemapselected) {
    rtb_Abs_idx_0 = rtb_torquemapselected;
  } else if (rtb_Abs_idx_0 < 0.0) {
    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S72>/Constant'
     */
    rtb_Abs_idx_0 = 0.0;
  }

  if (rtb_Abs_b_idx_1 > rtb_torquemapselected) {
    rtb_Abs_b_idx_1 = rtb_torquemapselected;
  } else if (rtb_Abs_b_idx_1 < 0.0) {
    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S72>/Constant'
     */
    rtb_Abs_b_idx_1 = 0.0;
  }

  if (rtb_Abs_b_idx_2 > rtb_torquemapselected) {
    rtb_Abs_b_idx_2 = rtb_torquemapselected;
  } else if (rtb_Abs_b_idx_2 < 0.0) {
    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S72>/Constant'
     */
    rtb_Abs_b_idx_2 = 0.0;
  }

  if (rtb_Tire_lbu_tmp_0 > rtb_torquemapselected) {
    rtb_Tire_lbu_tmp_0 = rtb_torquemapselected;
  } else if (rtb_Tire_lbu_tmp_0 < 0.0) {
    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S72>/Constant'
     */
    rtb_Tire_lbu_tmp_0 = 0.0;
  }

  /* End of Switch: '<S73>/Switch2' */

  /* RateLimiter: '<S72>/Rate Limiter' */
  rtb_uDLookupTable[0] = rtb_Abs_idx_0 - rtDW.PrevY[0];
  rtb_uDLookupTable[1] = rtb_Abs_b_idx_1 - rtDW.PrevY[1];
  rtb_uDLookupTable[2] = rtb_Abs_b_idx_2 - rtDW.PrevY[2];
  rtb_uDLookupTable[3] = rtb_Tire_lbu_tmp_0 - rtDW.PrevY[3];
  if (rtb_uDLookupTable[0] > 0.84) {
    rtb_Abs_idx_0 = rtDW.PrevY[0] + 0.84;
  }

  if (rtb_uDLookupTable[1] > 0.84) {
    rtb_Abs_b_idx_1 = rtDW.PrevY[1] + 0.84;
  }

  if (rtb_uDLookupTable[2] > 0.84) {
    rtb_Abs_b_idx_2 = rtDW.PrevY[2] + 0.84;
  }

  if (rtb_uDLookupTable[3] > 0.84) {
    rtb_Tire_lbu_tmp_0 = rtDW.PrevY[3] + 0.84;
  }

  rtDW.PrevY[0] = rtb_Abs_idx_0;
  rtDW.PrevY[1] = rtb_Abs_b_idx_1;
  rtDW.PrevY[2] = rtb_Abs_b_idx_2;
  rtDW.PrevY[3] = rtb_Tire_lbu_tmp_0;

  /* End of RateLimiter: '<S72>/Rate Limiter' */

  /* Saturate: '<S25>/Saturation' incorporates:
   *  Gain: '<S25>/Gain1'
   *  Gain: '<S42>/Wheel2Motor'
   *  Product: '<S25>/Product1'
   *  Sum: '<S42>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Tire_lbu_tmp = 0.017407407407407406 * rtb_Tire_lbu[0] *
    0.80645161290322576 + 0.07407407407407407 * rtDW.UnitDelay_DSTATE[0];

  /* MinMax: '<S62>/Min1' incorporates:
   *  Product: '<S25>/Product1'
   */
  rtb_Abs_b_idx_3 = fmin(fmin(fmin(fmin(rtb_ug_p[0], rtb_Efficiency[0]), rtb_Abs),
    20.972), rtb_Abs_idx_0);

  /* Saturate: '<S25>/Saturation' */
  if (rtb_Tire_lbu_tmp >= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  }

  /* Saturate: '<S62>/Saturation_Positive' */
  if (rtb_Abs_b_idx_3 <= 0.0) {
    rtb_Abs_b_idx_3 = 0.0;
  }

  /* MinMax: '<S25>/Min1' incorporates:
   *  UnaryMinus: '<S25>/Unary Minus'
   */
  rtb_Abs_idx_0 = fmax(rtb_Tire_lbu_tmp, -rtb_Abs_b_idx_3);

  /* Saturate: '<S25>/Saturation' incorporates:
   *  Gain: '<S25>/Gain1'
   *  Gain: '<S42>/Wheel2Motor'
   *  Product: '<S25>/Product1'
   *  Sum: '<S42>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Tire_lbu_tmp = 0.017407407407407406 * rtb_Tire_lbu[1] *
    0.80645161290322576 + 0.07407407407407407 * rtDW.UnitDelay_DSTATE[1];

  /* MinMax: '<S62>/Min1' incorporates:
   *  Product: '<S25>/Product1'
   */
  rtb_Abs_b_idx_3 = fmin(fmin(fmin(fmin(rtb_ug_p[1], rtb_Efficiency[1]), rtb_Abs),
    20.972), rtb_Abs_b_idx_1);

  /* Saturate: '<S25>/Saturation' incorporates:
   *  Gain: '<S25>/Gain1'
   *  Gain: '<S42>/Wheel2Motor'
   *  Product: '<S25>/Product1'
   *  Sum: '<S42>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Abs_b_idx_1 = 0.017407407407407406 * rtb_Tire_lbu[2] * 0.80645161290322576
    + 0.07407407407407407 * rtDW.UnitDelay_DSTATE[2];

  /* MinMax: '<S62>/Min1' incorporates:
   *  Product: '<S25>/Product1'
   */
  rtb_Abs_b_idx_2 = fmin(fmin(fmin(fmin(rtb_ug_p[2], rtb_Efficiency[2]), rtb_Abs),
    20.972), rtb_Abs_b_idx_2);

  /* Saturate: '<S25>/Saturation' incorporates:
   *  Gain: '<S25>/Gain1'
   *  Gain: '<S42>/Wheel2Motor'
   *  Product: '<S25>/Product1'
   *  Sum: '<S42>/Subtract'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  u0_tmp = 0.017407407407407406 * rtb_Tire_lbu[3] * 0.80645161290322576 +
    0.07407407407407407 * rtDW.UnitDelay_DSTATE[3];

  /* MinMax: '<S62>/Min1' incorporates:
   *  Product: '<S25>/Product1'
   */
  rtb_torquemapselected = fmin(fmin(fmin(fmin(rtb_ug_p[3], rtb_Efficiency[3]),
    rtb_Abs), 20.972), rtb_Tire_lbu_tmp_0);

  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant'
   *  RelationalOperator: '<S37>/Less Than'
   */
  rtb_Tire_lbu[0] = (real_T)(rtb_Switch_l >= -0.5) * rtb_Abs_idx_0;

  /* Saturate: '<S25>/Saturation' */
  if (rtb_Tire_lbu_tmp >= 0.0) {
    rtb_Tire_lbu_tmp = 0.0;
  }

  /* Saturate: '<S62>/Saturation_Positive' */
  if (rtb_Abs_b_idx_3 <= 0.0) {
    rtb_Abs_b_idx_3 = 0.0;
  }

  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant'
   *  MinMax: '<S25>/Min1'
   *  RelationalOperator: '<S37>/Less Than'
   *  UnaryMinus: '<S25>/Unary Minus'
   */
  rtb_Tire_lbu[1] = (real_T)(rtb_Sign >= -0.5) * fmax(rtb_Tire_lbu_tmp,
    -rtb_Abs_b_idx_3);

  /* Saturate: '<S25>/Saturation' */
  if (rtb_Abs_b_idx_1 >= 0.0) {
    rtb_Abs_b_idx_1 = 0.0;
  }

  /* Saturate: '<S62>/Saturation_Positive' */
  if (rtb_Abs_b_idx_2 <= 0.0) {
    rtb_Abs_b_idx_2 = 0.0;
  }

  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant'
   *  MinMax: '<S25>/Min1'
   *  RelationalOperator: '<S37>/Less Than'
   *  UnaryMinus: '<S25>/Unary Minus'
   */
  rtb_Tire_lbu[2] = (real_T)(rtb_RL_m >= -0.5) * fmax(rtb_Abs_b_idx_1,
    -rtb_Abs_b_idx_2);

  /* Saturate: '<S25>/Saturation' */
  if (u0_tmp >= 0.0) {
    u0_tmp = 0.0;
  }

  /* Saturate: '<S62>/Saturation_Positive' */
  if (rtb_torquemapselected <= 0.0) {
    rtb_torquemapselected = 0.0;
  }

  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant'
   *  MinMax: '<S25>/Min1'
   *  RelationalOperator: '<S37>/Less Than'
   *  UnaryMinus: '<S25>/Unary Minus'
   */
  rtb_Tire_lbu[3] = (real_T)(rtb_RR >= -0.5) * fmax(u0_tmp,
    -rtb_torquemapselected);

  /* SignalConversion generated from: '<S41>/ SFunction ' incorporates:
   *  MATLAB Function: '<S25>/Cross Check'
   */
  RateTransition3[1] = rtb_ubu[0];
  RateTransition3[2] = rtb_ubu[1];
  RateTransition3[3] = rtb_ubu[2];
  RateTransition3[4] = rtb_ubu[3];
  RateTransition3[5] = rtb_Tire_lbu[0];
  RateTransition3[6] = rtb_Tire_lbu[1];
  RateTransition3[7] = rtb_Tire_lbu[2];
  RateTransition3[8] = rtb_Tire_lbu[3];

  /* MATLAB Function: '<S25>/Cross Check' incorporates:
   *  Constant: '<S51>/ '
   *  Constant: '<S51>/  '
   *  Constant: '<S51>/Constant'
   *  DataTypeConversion: '<S51>/Data Type Conversion'
   *  DataTypeConversion: '<S51>/Data Type Conversion1'
   *  Gain: '<S51>/Gain'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S51>/AND'
   *  Logic: '<S51>/AND1'
   *  Logic: '<S51>/AND2'
   *  RelationalOperator: '<S51>/Less Than1'
   *  RelationalOperator: '<S51>/Less Than2'
   *  RelationalOperator: '<S51>/Less Than3'
   *  SignalConversion generated from: '<S41>/ SFunction '
   *  Sum: '<S51>/Sum'
   */
  switch ((int32_T)((real_T)((rtb_Max < 0.95) && (0.05 < rtb_Max) && rtb_AND_o) *
                    2.0 + (real_T)(rtb_AND_o && (rtU.throttle >= 0.05)))) {
   case 0:
    if (rtb_Tire_lbu[0] > rtb_ubu[0]) {
      rtb_Tire_lbu[0] = rtb_ubu[0] - rtb_Abs_idx_0;
    }

    if (rtb_Tire_lbu[1] > rtb_ubu[1]) {
      rtb_Tire_lbu[1] = rtb_ubu[1] - rtb_Abs_idx_0;
    }

    if (rtb_Tire_lbu[2] > rtb_ubu[2]) {
      rtb_Tire_lbu[2] = rtb_ubu[2] - rtb_Abs_idx_0;
    }

    if (rtb_Tire_lbu[3] > rtb_ubu[3]) {
      rtb_Tire_lbu[3] = rtb_ubu[3] - rtb_Abs_idx_0;
    }
    break;

   case 1:
    rtb_ubu[0] = RateTransition3[1];
    rtb_Tire_lbu[0] = 0.0;
    rtb_ubu[1] = RateTransition3[2];
    rtb_Tire_lbu[1] = 0.0;
    rtb_ubu[2] = RateTransition3[3];
    rtb_Tire_lbu[2] = 0.0;
    rtb_ubu[3] = RateTransition3[4];
    rtb_Tire_lbu[3] = 0.0;
    break;

   case 2:
    rtb_Tire_lbu[0] = RateTransition3[5];
    rtb_ubu[0] = 0.0;
    rtb_Tire_lbu[1] = RateTransition3[6];
    rtb_ubu[1] = 0.0;
    rtb_Tire_lbu[2] = RateTransition3[7];
    rtb_ubu[2] = 0.0;
    rtb_Tire_lbu[3] = RateTransition3[8];
    rtb_ubu[3] = 0.0;
    break;

   case 3:
    rtb_Tire_lbu[0] = 0.0;
    rtb_ubu[0] = 0.0;
    rtb_Tire_lbu[1] = 0.0;
    rtb_ubu[1] = 0.0;
    rtb_Tire_lbu[2] = 0.0;
    rtb_ubu[2] = 0.0;
    rtb_Tire_lbu[3] = 0.0;
    rtb_ubu[3] = 0.0;
    break;
  }

  /* Sum: '<S23>/Subtract1' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/Exponent < 0'
   *  Inport: '<Root>/throttle'
   *  Math: '<S33>/Power'
   *  Product: '<S33>/Divide'
   *  Product: '<S33>/Divide1'
   *  Sum: '<S33>/Subtract'
   *  Sum: '<S33>/Sum'
   */
  rtb_torquemapselected = 1.0 / (rt_powd_snf(rtU.throttle / (1.0 - rtU.throttle),
    -1.5) + 1.0) - rtb_Max;

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S23>/Constant2'
   *  Gain: '<S23>/Gain1'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S23>/ '
   *  Product: '<S23>/Product1'
   *  RelationalOperator: '<S23>/Less Than'
   *  RelationalOperator: '<S23>/Less Than1'
   */
  rtb_Saturation = (real_T)(boolean_T)((rtb_Max >= 0.05) ^ (rtU.throttle >= 0.05))
    * rtb_torquemapselected * 84.0;

  /* Gain: '<S23>/Gain2' */
  rtb_torquemapselected = 0.95 * rtb_Saturation;

  /* Gain: '<S23>/Gain3' */
  rtb_Switch_l = 1.05 * rtb_Saturation;

  /* Switch: '<S23>/Switch2' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/throttle'
   *  Logic: '<S21>/AND'
   *  MinMax: '<S23>/Max1'
   *  RelationalOperator: '<S21>/Less Than'
   *  RelationalOperator: '<S21>/Less Than1'
   */
  if ((rtU.throttle < 0.05) && (0.05 > rtb_Max)) {
    rtb_Max = -0.0;
  } else {
    rtb_Max = fmin(rtb_torquemapselected, rtb_Switch_l);
  }

  /* End of Switch: '<S23>/Switch2' */

  /* Gain: '<S56>/Gain2' incorporates:
   *  Gain: '<S34>/Gain2'
   *  Inport: '<Root>/omega_wheels_FL'
   */
  rtb_Tire_lbu_tmp_0 = 13.5 * rtU.omega_wheels_FL;

  /* Saturate: '<S56>/Saturation' incorporates:
   *  Gain: '<S56>/Gain2'
   */
  if (rtb_Tire_lbu_tmp_0 > 2083.9231268812296) {
    rtb_Efficiency[0] = 2083.9231268812296;
  } else if (rtb_Tire_lbu_tmp_0 < 10.471975511965978) {
    rtb_Efficiency[0] = 10.471975511965978;
  } else {
    rtb_Efficiency[0] = rtb_Tire_lbu_tmp_0;
  }

  /* Gain: '<S56>/Gain2' incorporates:
   *  Gain: '<S34>/Gain2'
   *  Inport: '<Root>/omega_wheels_FR'
   */
  u0_tmp = 13.5 * rtU.omega_wheels_FR;

  /* Saturate: '<S56>/Saturation' incorporates:
   *  Gain: '<S56>/Gain2'
   */
  if (u0_tmp > 2083.9231268812296) {
    rtb_Efficiency[1] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Efficiency[1] = 10.471975511965978;
  } else {
    rtb_Efficiency[1] = u0_tmp;
  }

  /* Gain: '<S56>/Gain2' incorporates:
   *  Gain: '<S34>/Gain2'
   *  Inport: '<Root>/omega_wheels_RL'
   */
  u0_tmp_0 = 13.5 * rtU.omega_wheels_RL;

  /* Saturate: '<S56>/Saturation' incorporates:
   *  Gain: '<S56>/Gain2'
   */
  if (u0_tmp_0 > 2083.9231268812296) {
    rtb_Efficiency[2] = 2083.9231268812296;
  } else if (u0_tmp_0 < 10.471975511965978) {
    rtb_Efficiency[2] = 10.471975511965978;
  } else {
    rtb_Efficiency[2] = u0_tmp_0;
  }

  /* Gain: '<S56>/Gain2' incorporates:
   *  Gain: '<S34>/Gain2'
   *  Inport: '<Root>/omega_wheels_RR'
   */
  u0_tmp_1 = 13.5 * rtU.omega_wheels_RR;

  /* Saturate: '<S56>/Saturation' incorporates:
   *  Gain: '<S56>/Gain2'
   */
  if (u0_tmp_1 > 2083.9231268812296) {
    rtb_Efficiency[3] = 2083.9231268812296;
  } else if (u0_tmp_1 < 10.471975511965978) {
    rtb_Efficiency[3] = 10.471975511965978;
  } else {
    rtb_Efficiency[3] = u0_tmp_1;
  }

  /* Abs: '<S60>/Abs' */
  rtb_Abs_idx_0 = fabs(rtb_Memory[0]);
  rtb_Abs_b_idx_1 = fabs(rtb_Memory[1]);
  rtb_Abs_b_idx_2 = fabs(rtb_Memory[2]);
  rtb_Abs_b_idx_3 = fabs(rtb_Memory[3]);

  /* Lookup_n-D: '<S60>/2-D Lookup Table' */
  rtb_Efficiency[0] = look2_binlx(rtb_Efficiency[0], rtb_Abs_idx_0,
    rtConstP.pooled45, rtConstP.pooled46, rtConstP.pooled44, rtConstP.pooled51,
    200U);
  rtb_Efficiency[1] = look2_binlx(rtb_Efficiency[1], rtb_Abs_b_idx_1,
    rtConstP.pooled45, rtConstP.pooled46, rtConstP.pooled44, rtConstP.pooled51,
    200U);
  rtb_Efficiency[2] = look2_binlx(rtb_Efficiency[2], rtb_Abs_b_idx_2,
    rtConstP.pooled45, rtConstP.pooled46, rtConstP.pooled44, rtConstP.pooled51,
    200U);
  rtb_Efficiency[3] = look2_binlx(rtb_Efficiency[3], rtb_Abs_b_idx_3,
    rtConstP.pooled45, rtConstP.pooled46, rtConstP.pooled44, rtConstP.pooled51,
    200U);

  /* Saturate: '<S60>/Saturation' */
  rtb_Tire_lbu_tmp = rtb_Efficiency[0];
  if (rtb_Tire_lbu_tmp > 1.0) {
    rtb_Tire_lbu_tmp = 1.0;
  } else if (rtb_Tire_lbu_tmp < 0.3) {
    rtb_Tire_lbu_tmp = 0.3;
  }

  /* Product: '<S56>/Divide' incorporates:
   *  Constant: '<S56>/Constant'
   *  Gain: '<S56>/     '
   */
  rtb_Abs_idx_0 = 1.0 / (0.96 * rtb_Tire_lbu_tmp);

  /* Saturate: '<S60>/Saturation' */
  rtb_Tire_lbu_tmp = rtb_Efficiency[1];
  if (rtb_Tire_lbu_tmp > 1.0) {
    rtb_Tire_lbu_tmp = 1.0;
  } else if (rtb_Tire_lbu_tmp < 0.3) {
    rtb_Tire_lbu_tmp = 0.3;
  }

  /* Product: '<S56>/Divide' incorporates:
   *  Constant: '<S56>/Constant'
   *  Gain: '<S56>/     '
   */
  rtb_Abs_b_idx_1 = 1.0 / (0.96 * rtb_Tire_lbu_tmp);

  /* Saturate: '<S60>/Saturation' */
  rtb_Tire_lbu_tmp = rtb_Efficiency[2];
  if (rtb_Tire_lbu_tmp > 1.0) {
    rtb_Tire_lbu_tmp = 1.0;
  } else if (rtb_Tire_lbu_tmp < 0.3) {
    rtb_Tire_lbu_tmp = 0.3;
  }

  /* Product: '<S56>/Divide' incorporates:
   *  Constant: '<S56>/Constant'
   *  Gain: '<S56>/     '
   */
  rtb_Abs_b_idx_2 = 1.0 / (0.96 * rtb_Tire_lbu_tmp);

  /* Saturate: '<S60>/Saturation' */
  rtb_Tire_lbu_tmp = rtb_Efficiency[3];
  if (rtb_Tire_lbu_tmp > 1.0) {
    rtb_Tire_lbu_tmp = 1.0;
  } else if (rtb_Tire_lbu_tmp < 0.3) {
    rtb_Tire_lbu_tmp = 0.3;
  }

  /* Product: '<S56>/Divide' incorporates:
   *  Constant: '<S56>/Constant'
   *  Gain: '<S56>/     '
   */
  rtb_Abs_b_idx_3 = 1.0 / (0.96 * rtb_Tire_lbu_tmp);

  /* MATLAB Function: '<S56>/MATLAB Function' */
  if (rtb_Memory[0] <= 0.0) {
    rtb_Abs_idx_0 = 0.0;
  }

  if (rtb_Memory[1] <= 0.0) {
    rtb_Abs_b_idx_1 = 0.0;
  }

  if (rtb_Memory[2] <= 0.0) {
    rtb_Abs_b_idx_2 = 0.0;
  }

  if (rtb_Memory[3] <= 0.0) {
    rtb_Abs_b_idx_3 = 0.0;
  }

  /* End of MATLAB Function: '<S56>/MATLAB Function' */

  /* MATLAB Function: '<S27>/MATLAB Function' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/r1'
   *  Constant: '<S27>/vx'
   *  Constant: '<S27>/vy'
   *  Gain: '<S27>/Gain'
   *  SignalConversion generated from: '<S57>/ SFunction '
   */
  rtb_CCaller_o2[0] = 0.0;
  rtb_CCaller_o2[1] = 10.0;
  rtb_CCaller_o2[2] = 100.0;
  rtb_CCaller_o2[3] = 0.01 * rtb_Abs_idx_0;
  rtb_CCaller_o2[4] = 0.01 * rtb_Abs_b_idx_1;
  rtb_CCaller_o2[5] = 0.01 * rtb_Abs_b_idx_2;
  rtb_CCaller_o2[6] = 0.01 * rtb_Abs_b_idx_3;
  memset(&varargin_1[0], 0, 49U * sizeof(real_T));
  for (iU = 0; iU < 7; iU++) {
    varargin_1[iU + 7 * iU] = rtb_CCaller_o2[iU];
  }

  memset(&varargin_2[0], 0, sizeof(real_T) << 4U);
  varargin_2[0] = 1.0;
  varargin_2[5] = 1.0;
  varargin_2[10] = 1.0;
  varargin_2[15] = 1.0;
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

  /* End of MATLAB Function: '<S27>/MATLAB Function' */

  /* Saturate: '<S34>/Saturation' */
  if (rtb_Tire_lbu_tmp_0 > 2083.9231268812296) {
    rtb_Efficiency[0] = 2083.9231268812296;
  } else if (rtb_Tire_lbu_tmp_0 < 10.471975511965978) {
    rtb_Efficiency[0] = 10.471975511965978;
  } else {
    rtb_Efficiency[0] = rtb_Tire_lbu_tmp_0;
  }

  if (u0_tmp > 2083.9231268812296) {
    rtb_Efficiency[1] = 2083.9231268812296;
  } else if (u0_tmp < 10.471975511965978) {
    rtb_Efficiency[1] = 10.471975511965978;
  } else {
    rtb_Efficiency[1] = u0_tmp;
  }

  if (u0_tmp_0 > 2083.9231268812296) {
    rtb_Efficiency[2] = 2083.9231268812296;
  } else if (u0_tmp_0 < 10.471975511965978) {
    rtb_Efficiency[2] = 10.471975511965978;
  } else {
    rtb_Efficiency[2] = u0_tmp_0;
  }

  if (u0_tmp_1 > 2083.9231268812296) {
    rtb_Efficiency[3] = 2083.9231268812296;
  } else if (u0_tmp_1 < 10.471975511965978) {
    rtb_Efficiency[3] = 10.471975511965978;
  } else {
    rtb_Efficiency[3] = u0_tmp_1;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Abs: '<S36>/Abs' */
  rtb_Abs_idx_0 = fabs(rtb_Memory[0]);
  rtb_Abs_b_idx_1 = fabs(rtb_Memory[1]);
  rtb_Abs_b_idx_2 = fabs(rtb_Memory[2]);
  rtb_Abs_b_idx_3 = fabs(rtb_Memory[3]);

  /* Lookup_n-D: '<S36>/2-D Lookup Table' */
  rtb_Efficiency[0] = look2_binlx(rtb_Efficiency[0], rtb_Abs_idx_0,
    rtConstP.pooled45, rtConstP.pooled46, rtConstP.pooled44, rtConstP.pooled51,
    200U);
  rtb_Efficiency[1] = look2_binlx(rtb_Efficiency[1], rtb_Abs_b_idx_1,
    rtConstP.pooled45, rtConstP.pooled46, rtConstP.pooled44, rtConstP.pooled51,
    200U);
  rtb_Efficiency[2] = look2_binlx(rtb_Efficiency[2], rtb_Abs_b_idx_2,
    rtConstP.pooled45, rtConstP.pooled46, rtConstP.pooled44, rtConstP.pooled51,
    200U);
  rtb_Efficiency[3] = look2_binlx(rtb_Efficiency[3], rtb_Abs_b_idx_3,
    rtConstP.pooled45, rtConstP.pooled46, rtConstP.pooled44, rtConstP.pooled51,
    200U);

  /* Saturate: '<S36>/Saturation' */
  rtb_Tire_lbu_tmp = rtb_Efficiency[0];
  rtb_Abs_b_idx_3 = rtb_Efficiency[1];
  rtb_Abs_b_idx_1 = rtb_Efficiency[2];
  rtb_Abs_b_idx_2 = rtb_Efficiency[3];

  /* Saturate: '<S19>/Saturation' */
  if (rtb_vx <= 2.0) {
    /* CCaller: '<S15>/C Caller' */
    rtb_CCaller_o2[0] = 2.0;
  } else {
    /* CCaller: '<S15>/C Caller' */
    rtb_CCaller_o2[0] = rtb_vx;
  }

  /* End of Saturate: '<S19>/Saturation' */

  /* Saturate: '<S19>/Saturation1' incorporates:
   *  Inport: '<Root>/vy'
   */
  if (rtU.vy > 5.0) {
    /* CCaller: '<S15>/C Caller' */
    rtb_CCaller_o2[1] = 5.0;
  } else if (rtU.vy < -5.0) {
    /* CCaller: '<S15>/C Caller' */
    rtb_CCaller_o2[1] = -5.0;
  } else {
    /* CCaller: '<S15>/C Caller' */
    rtb_CCaller_o2[1] = rtU.vy;
  }

  /* End of Saturate: '<S19>/Saturation1' */

  /* CCaller: '<S15>/C Caller' incorporates:
   *  CFunction: '<S28>/C Function'
   *  CFunction: '<S31>/C Function'
   *  Constant: '<S20>/Constant'
   *  SignalConversion generated from: '<S15>/C Caller'
   *  UnaryMinus: '<S20>/Unary Minus'
   * */
  rtb_CCaller_o2[2] = rtb_yaw_rate;
  rtb_CCaller_o2[3] = rtb_Memory[0];
  rtb_CCaller_o2[4] = rtb_Memory[1];
  rtb_CCaller_o2[5] = rtb_Memory[2];
  rtb_CCaller_o2[6] = rtb_Memory[3];
  memcpy(&rtb_CCaller_o3[0], &rtDW.CFunction_n[0], 26U * sizeof(real_T));
  rtb_Memory[0] = -1000.0;
  rtb_Memory[1] = -1000.0;
  rtb_Memory[2] = -1000.0;
  rtb_Memory[3] = -1000.0;
  rtb_Efficiency[0] = 1000.0;
  rtb_Efficiency[1] = 1000.0;
  rtb_Efficiency[2] = 1000.0;
  rtb_Efficiency[3] = 1000.0;
  memcpy(&rtb_CCaller_o6[0], &rtDW.CFunction[0], 22U * sizeof(real_T));
  rtb_ug_p[0] = rtb_Max;

  /* Product: '<S23>/Divide' incorporates:
   *  Constant: '<S2>/Constant8'
   *  Gain: '<S23>/Gain'
   *  Product: '<S23>/Divide1'
   */
  rtb_Tire_lbu_tmp_0 = 1.0 / (57.4468085106383 * rtb_vx);
  u0_tmp = rtb_Tire_lbu_tmp_0 * -35000.0;

  /* Saturate: '<S23>/Saturation' */
  if (u0_tmp < -210.0) {
    /* CCaller: '<S15>/C Caller' */
    rtb_ug_p[1] = -210.0;
  } else {
    /* CCaller: '<S15>/C Caller' */
    rtb_ug_p[1] = u0_tmp;
  }

  /* End of Saturate: '<S23>/Saturation' */

  /* CCaller: '<S15>/C Caller' incorporates:
   *  Constant: '<S23>/Constant3'
   *  MinMax: '<S23>/Max'
   *  SignalConversion generated from: '<S15>/C Caller'
   */
  rtb_ug_p[2] = 0.0;
  rtb_ug_p[3] = 0.0;
  rtb_uDLookupTable[0] = fmax(rtb_torquemapselected, rtb_Switch_l);

  /* Product: '<S23>/Divide1' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  u0_tmp = rtb_Tire_lbu_tmp_0 * 80000.0;

  /* Saturate: '<S23>/Saturation1' */
  if (u0_tmp > 210.0) {
    /* CCaller: '<S15>/C Caller' */
    rtb_uDLookupTable[1] = 210.0;
  } else {
    /* CCaller: '<S15>/C Caller' */
    rtb_uDLookupTable[1] = u0_tmp;
  }

  /* End of Saturate: '<S23>/Saturation1' */

  /* CCaller: '<S15>/C Caller' incorporates:
   *  Constant: '<S23>/Constant4'
   *  MATLAB Function: '<S24>/MATLAB Function'
   *  SignalConversion generated from: '<S15>/C Caller'
   */
  rtb_uDLookupTable[2] = 0.0;
  rtb_uDLookupTable[3] = 0.0;
  memset(&rtb_CCaller_o12[0], 0, 12U * sizeof(real_T));
  rtb_CCaller_o12[12] = 1.0;

  /* Saturate: '<S36>/Saturation' */
  if (rtb_Tire_lbu_tmp > 1.0) {
    rtb_Tire_lbu_tmp = 1.0;
  } else if (rtb_Tire_lbu_tmp < 0.3) {
    rtb_Tire_lbu_tmp = 0.3;
  }

  /* CCaller: '<S15>/C Caller' incorporates:
   *  Constant: '<S34>/Constant'
   *  Gain: '<S34>/     '
   *  MATLAB Function: '<S24>/MATLAB Function'
   *  Product: '<S34>/Divide'
   */
  rtb_CCaller_o12[13] = 1.0 / (0.96 * rtb_Tire_lbu_tmp);
  rtb_CCaller_o12[14] = 0.0;
  rtb_CCaller_o12[15] = 1.0;
  rtb_CCaller_o12[16] = 1.0;

  /* Saturate: '<S36>/Saturation' */
  if (rtb_Abs_b_idx_3 > 1.0) {
    rtb_Abs_b_idx_3 = 1.0;
  } else if (rtb_Abs_b_idx_3 < 0.3) {
    rtb_Abs_b_idx_3 = 0.3;
  }

  /* CCaller: '<S15>/C Caller' incorporates:
   *  Constant: '<S34>/Constant'
   *  Gain: '<S34>/     '
   *  MATLAB Function: '<S24>/MATLAB Function'
   *  Product: '<S34>/Divide'
   */
  rtb_CCaller_o12[17] = 1.0 / (0.96 * rtb_Abs_b_idx_3);
  rtb_CCaller_o12[18] = 1.0;
  rtb_CCaller_o12[19] = 0.0;
  rtb_CCaller_o12[20] = 1.0;

  /* Saturate: '<S36>/Saturation' */
  if (rtb_Abs_b_idx_1 > 1.0) {
    rtb_Abs_b_idx_1 = 1.0;
  } else if (rtb_Abs_b_idx_1 < 0.3) {
    rtb_Abs_b_idx_1 = 0.3;
  }

  /* CCaller: '<S15>/C Caller' incorporates:
   *  Constant: '<S34>/Constant'
   *  Gain: '<S34>/     '
   *  MATLAB Function: '<S24>/MATLAB Function'
   *  Product: '<S34>/Divide'
   */
  rtb_CCaller_o12[21] = 1.0 / (0.96 * rtb_Abs_b_idx_1);
  rtb_CCaller_o12[22] = 0.0;
  rtb_CCaller_o12[23] = -1.0;
  rtb_CCaller_o12[24] = 1.0;

  /* Saturate: '<S36>/Saturation' */
  if (rtb_Abs_b_idx_2 > 1.0) {
    rtb_Abs_b_idx_2 = 1.0;
  } else if (rtb_Abs_b_idx_2 < 0.3) {
    rtb_Abs_b_idx_2 = 0.3;
  }

  /* CCaller: '<S15>/C Caller' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S34>/Constant'
   *  Gain: '<S34>/     '
   *  MATLAB Function: '<S24>/MATLAB Function'
   *  Product: '<S34>/Divide'
   */
  rtb_CCaller_o12[25] = 1.0 / (0.96 * rtb_Abs_b_idx_2);
  rtb_CCaller_o12[26] = -1.0;
  rtb_CCaller_o12[27] = 0.0;
  rtb_torquemapselected = 1.0;
  Acados_Caller_wrapper(&rtb_CCaller_o2[0], &rtb_CCaller_o3[0], &rtb_Memory[0],
                        &rtb_Efficiency[0], &rtb_CCaller_o6[0], &rtb_Tire_lbu[0],
                        &rtb_ubu[0], &rtb_ug_p[0], &rtb_uDLookupTable[0],
                        &rtb_y[0], &rtb_CCaller_o12[0], &rtb_torquemapselected);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant2'
   *  Inport: '<Root>/throttle'
   *  Product: '<S32>/Product'
   *  RelationalOperator: '<S32>/Less Than'
   */
  if (rtb_vx < 3.0) {
    rtb_ubu[0] = rtU.throttle * 6.3;
    rtb_ubu[1] = rtU.throttle * 6.3;
    rtb_ubu[2] = rtU.throttle * 21.0;
    rtb_ubu[3] = rtU.throttle * 21.0;
  } else {
    rtb_ubu[0] = 0.0;
    rtb_ubu[1] = 0.0;
    rtb_ubu[2] = 0.0;
    rtb_ubu[3] = 0.0;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE[0] = rtDW.UnitDelay_DSTATE_j[0];
  rtDW.UnitDelay_DSTATE[1] = rtDW.UnitDelay_DSTATE_j[1];
  rtDW.UnitDelay_DSTATE[2] = rtDW.UnitDelay_DSTATE_j[2];
  rtDW.UnitDelay_DSTATE[3] = rtDW.UnitDelay_DSTATE_j[3];

  /* Update for Memory: '<S15>/Memory' */
  rtDW.Memory_PreviousInput[0] = rtb_ubu[0];
  rtDW.Memory_PreviousInput[1] = rtb_ubu[1];
  rtDW.Memory_PreviousInput[2] = rtb_ubu[2];
  rtDW.Memory_PreviousInput[3] = rtb_ubu[3];

  /* Update for DiscreteIntegrator: '<S71>/Integrator' */
  rtDW.Integrator_IC_LOADING = 0U;

  /* Product: '<S64>/1//T' incorporates:
   *  Constant: '<S66>/Time constant'
   *  MinMax: '<S66>/Max'
   */
  rtb_Tire_lbu_tmp = 1.0 / fmax(rtDW.Probe[0], 0.079577471545947673);

  /* Update for DiscreteIntegrator: '<S71>/Integrator' incorporates:
   *  Product: '<S64>/1//T'
   *  Sum: '<S64>/Sum1'
   */
  rtDW.Integrator_DSTATE[0] += (rtb_lg_idx_0 - rtb_Integrator_idx_0) *
    rtb_Tire_lbu_tmp * 0.02;
  rtDW.Integrator_DSTATE[1] += (rtb_lg_idx_1 - rtb_Integrator_idx_1) *
    rtb_Tire_lbu_tmp * 0.02;
  rtDW.Integrator_DSTATE[2] += (rtb_lg_idx_2 - rtb_Integrator_idx_2) *
    rtb_Tire_lbu_tmp * 0.02;
  rtDW.Integrator_DSTATE[3] += (rtb_lg - rtb_Integrator_idx_3) *
    rtb_Tire_lbu_tmp * 0.02;
  rtDW.Integrator_PrevResetState = (int8_T)rtb_Compare;

  /* Update for DiscreteFir: '<S51>/Discrete FIR Filter' */
  /* Update circular buffer index */
  rtDW.DiscreteFIRFilter_circBuf--;
  if (rtDW.DiscreteFIRFilter_circBuf < 0) {
    rtDW.DiscreteFIRFilter_circBuf = 8;
  }

  /* Update circular buffer */
  rtDW.DiscreteFIRFilter_states[rtDW.DiscreteFIRFilter_circBuf] = 1;

  /* End of Update for DiscreteFir: '<S51>/Discrete FIR Filter' */

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
  rtY.Torque[0] = rtb_ubu[0];
  rtY.Torque[1] = rtb_ubu[1];
  rtY.Torque[2] = rtb_ubu[2];
  rtY.Torque[3] = rtb_ubu[3];
}

/* Model initialize function */
void TVModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem' */
  /* Start for Probe: '<S66>/Probe' */
  rtDW.Probe[0] = 0.02;
  rtDW.Probe[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S71>/Integrator' */
  rtDW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for RateLimiter: '<S72>/Rate Limiter' */
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
