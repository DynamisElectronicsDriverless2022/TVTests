/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GeneratingModel_giuse.c
 *
 * Code generated for Simulink model 'GeneratingModel_giuse'.
 *
 * Model version                  : 3.37
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Nov 11 20:04:37 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GeneratingModel_giuse.h"

/* Exported block states */
uint8_T usartDebuxTx[633];             /* '<S2>/Data Store Memory' */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void Buffer(uint16_T rtu_Inport, uint16_T rty_Out1[75], DW_Buffer
                   *localDW, uint16_T rtp_Buffer_lenght);

/*
 * Output and update for atomic system:
 *    '<S3>/Buffer'
 *    '<S3>/Buffer1'
 *    '<S3>/Buffer2'
 *    '<S3>/Buffer3'
 */
static void Buffer(uint16_T rtu_Inport, uint16_T rty_Out1[75], DW_Buffer
                   *localDW, uint16_T rtp_Buffer_lenght)
{
  /* CFunction: '<S6>/C Function' */
  if (localDW->CFunction_i == 0) {
    /* CFunction: '<S6>/C Function' incorporates:
     *  Constant: '<S6>/Constant'
     */
    localDW->CFunction = (uint8_T)(rtp_Buffer_lenght - 2);
    localDW->CFunction_i = 1U;
  }

  /* CFunction: '<S6>/C Function' */
  localDW->CFunction++;

  /* CFunction: '<S6>/C Function' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (localDW->CFunction >= rtp_Buffer_lenght) {
    /* CFunction: '<S6>/C Function' */
    localDW->CFunction = 0U;
  }

  /* Assignment: '<S6>/Assignment' */
  rty_Out1[localDW->CFunction] = rtu_Inport;
}

/* Model step function for TID0 */
void GeneratingModel_giuse_step0(void) /* Sample time: [0.0001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void GeneratingModel_giuse_step1(void) /* Explicit Task: raccolta_dati */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.01s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID1_2)++;
  if ((rtM->Timing.RateInteraction.TID1_2) > 9) {
    rtM->Timing.RateInteraction.TID1_2 = 0;
  }

  /* Outputs for Atomic SubSystem: '<Root>/raccolta_dati' */
  /* Outputs for Atomic SubSystem: '<S3>/Buffer' */
  /* Inport: '<Root>/dato1' */
  Buffer(rtU.dato1, rtDW.Assignment_n4, &rtDW.Buffer_g, 75);

  /* End of Outputs for SubSystem: '<S3>/Buffer' */

  /* Outputs for Atomic SubSystem: '<S3>/Buffer1' */
  /* Inport: '<Root>/dato2' */
  Buffer(rtU.dato2, rtDW.Assignment_a, &rtDW.Buffer1, 75);

  /* End of Outputs for SubSystem: '<S3>/Buffer1' */

  /* Outputs for Atomic SubSystem: '<S3>/Buffer2' */
  /* Inport: '<Root>/dato3' */
  Buffer(rtU.dato3, rtDW.Assignment_n, &rtDW.Buffer2, 75);

  /* End of Outputs for SubSystem: '<S3>/Buffer2' */

  /* Outputs for Atomic SubSystem: '<S3>/Buffer3' */
  /* Inport: '<Root>/dato4' */
  Buffer(rtU.dato4, rtDW.Assignment, &rtDW.Buffer3, 75);

  /* End of Outputs for SubSystem: '<S3>/Buffer3' */
  /* End of Outputs for SubSystem: '<Root>/raccolta_dati' */

  /* RateTransition: '<Root>/RT' */
  if (rtM->Timing.RateInteraction.TID1_2 == 1) {
    memcpy(&rtDW.RT_Buffer[0], &rtDW.Assignment_n4[0], 75U * sizeof(uint16_T));

    /* RateTransition: '<Root>/RT1' */
    memcpy(&rtDW.RT1_Buffer[0], &rtDW.Assignment_a[0], 75U * sizeof(uint16_T));

    /* RateTransition: '<Root>/RT2' */
    memcpy(&rtDW.RT2_Buffer[0], &rtDW.Assignment_n[0], 75U * sizeof(uint16_T));

    /* RateTransition: '<Root>/RT3' */
    memcpy(&rtDW.RT3_Buffer[0], &rtDW.Assignment[0], 75U * sizeof(uint16_T));
  }

  /* End of RateTransition: '<Root>/RT' */
}

/* Model step function for TID2 */
void USART_SEND(void)                  /* Explicit Task: USART_PARTITION */
{
  int32_T i;
  int32_T rtb_Assignment3_tmp;
  uint16_T rtb_Cast22[315];
  uint8_T rtb_Assignment3[630];
  uint8_T rtb_y[315];

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem Reference' */
  /* DataTypeConversion: '<S2>/Cast22' incorporates:
   *  RateTransition: '<Root>/RT'
   *  RateTransition: '<Root>/RT1'
   *  RateTransition: '<Root>/RT2'
   *  RateTransition: '<Root>/RT3'
   */
  for (i = 0; i < 15; i++) {
    rtb_Cast22[i] = 0U;
  }

  for (i = 0; i < 75; i++) {
    rtb_Cast22[i + 15] = rtDW.RT_Buffer[i];
    rtb_Cast22[i + 90] = rtDW.RT1_Buffer[i];
    rtb_Cast22[i + 165] = rtDW.RT2_Buffer[i];
    rtb_Cast22[i + 240] = rtDW.RT3_Buffer[i];
  }

  /* End of DataTypeConversion: '<S2>/Cast22' */

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift1' */
  /* MATLAB Function: '<S4>/bit_shift' incorporates:
   *  DataTypeConversion: '<S2>/Cast22'
   */
  for (i = 0; i < 315; i++) {
    rtb_y[i] = (uint8_T)((uint32_T)rtb_Cast22[i] >> 8);
  }

  /* End of MATLAB Function: '<S4>/bit_shift' */
  /* End of Outputs for SubSystem: '<S2>/Bit Shift1' */
  for (i = 0; i < 315; i++) {
    /* Assignment: '<S2>/Assignment2' incorporates:
     *  Assignment: '<S2>/Assignment3'
     *  DataTypeConversion: '<S2>/Cast23'
     */
    rtb_Assignment3_tmp = i << 1;
    rtb_Assignment3[rtb_Assignment3_tmp] = rtb_y[i];

    /* Assignment: '<S2>/Assignment3' incorporates:
     *  DataTypeConversion: '<S2>/Cast24'
     */
    rtb_Assignment3[rtb_Assignment3_tmp + 1] = (uint8_T)rtb_Cast22[i];
  }

  /* DataStoreWrite: '<S2>/Data Store Write' */
  usartDebuxTx[0] = 104U;
  usartDebuxTx[1] = 100U;
  usartDebuxTx[2] = 114U;
  memcpy(&usartDebuxTx[3], &rtb_Assignment3[0], 630U * sizeof(uint8_T));

  /* CCaller: '<S2>/C Caller' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read'
   */
  usartTransmit_DMA_wrapper(1U, usartDebuxTx, rtDW.Width);

  /* End of Outputs for SubSystem: '<Root>/Subsystem Reference' */
}

/* Model initialize function */
void INITIALIZE(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Subsystem Reference' */
  /* Start for Width: '<S2>/Width' */
  rtDW.Width = 633U;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem Reference' */

  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* CCaller: '<S1>/C Caller3' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  DataStoreRead: '<S1>/Data Store Read'
   */
  usartRead_IT_wrapper(1U, rtDW.usart_rxData, 1U);

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
