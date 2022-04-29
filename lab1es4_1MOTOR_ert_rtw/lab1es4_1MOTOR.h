/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: lab1es4_1MOTOR.h
 *
 * Code generated for Simulink model 'lab1es4_1MOTOR'.
 *
 * Model version                  : 3.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 29 15:23:08 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_lab1es4_1MOTOR_h_
#define RTW_HEADER_lab1es4_1MOTOR_h_
#include <stddef.h>
#include <string.h>
#ifndef lab1es4_1MOTOR_COMMON_INCLUDES_
#define lab1es4_1MOTOR_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#endif                                 /* lab1es4_1MOTOR_COMMON_INCLUDES_ */

#include "lab1es4_1MOTOR_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  uint16_T ADC1;                       /* '<Root>/ADC1' */
} B_lab1es4_1MOTOR_T;

/* Parameters (default storage) */
struct P_lab1es4_1MOTOR_T_ {
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_lab1es4_1MOTOR_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_lab1es4_1MOTOR_T lab1es4_1MOTOR_P;

/* Block signals (default storage) */
extern B_lab1es4_1MOTOR_T lab1es4_1MOTOR_B;

/* Model entry point functions */
extern void lab1es4_1MOTOR_initialize(void);
extern void lab1es4_1MOTOR_step(void);
extern void lab1es4_1MOTOR_terminate(void);

/* Real-time Model object */
extern RT_MODEL_lab1es4_1MOTOR_T *const lab1es4_1MOTOR_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'lab1es4_1MOTOR'
 */
#endif                                 /* RTW_HEADER_lab1es4_1MOTOR_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
