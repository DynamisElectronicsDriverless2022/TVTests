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
 * C/C++ source code generated on : Sat Jan  8 15:05:35 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "TVModel.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void TV(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/TV' */
  /* Outport: '<Root>/Outport' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/Input'
   *  Sum: '<S1>/Add'
   */
  rtY.Outport = rtU.Input + 1.0;

  /* End of Outputs for SubSystem: '<Root>/TV' */
}

/* Model initialize function */
void TVModel_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
