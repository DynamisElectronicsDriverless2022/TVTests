/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GeneratingModel_giuse.h
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

#ifndef RTW_HEADER_GeneratingModel_giuse_h_
#define RTW_HEADER_GeneratingModel_giuse_h_
#include <string.h>
#ifndef GeneratingModel_giuse_COMMON_INCLUDES_
#define GeneratingModel_giuse_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                              /* GeneratingModel_giuse_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* user code (top of header file) */
#include "constant_defines.h"
#include "id_can.h"
#include "canFcnLib.h"
#include "DPFcnLib.h"
#include "usartFcnLib.h"

/* Block signals and states (default storage) for system '<S3>/Buffer' */
typedef struct {
  uint8_T CFunction;                   /* '<S6>/C Function' */
  uint8_T CFunction_i;                 /* '<S6>/C Function' */
} DW_Buffer;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Buffer Buffer3;                   /* '<S3>/Buffer3' */
  DW_Buffer Buffer2;                   /* '<S3>/Buffer2' */
  DW_Buffer Buffer1;                   /* '<S3>/Buffer1' */
  DW_Buffer Buffer_g;                  /* '<S3>/Buffer' */
  uint16_T Assignment[75];             /* '<S9>/Assignment' */
  uint16_T Assignment_n[75];           /* '<S8>/Assignment' */
  uint16_T Assignment_a[75];           /* '<S7>/Assignment' */
  uint16_T Assignment_n4[75];          /* '<S6>/Assignment' */
  uint16_T RT_Buffer[75];              /* '<Root>/RT' */
  uint16_T RT1_Buffer[75];             /* '<Root>/RT1' */
  uint16_T RT2_Buffer[75];             /* '<Root>/RT2' */
  uint16_T RT3_Buffer[75];             /* '<Root>/RT3' */
  uint16_T Width;                      /* '<S2>/Width' */
  uint8_T usart_txData[25];            /* '<Root>/Data Store Memory5' */
  uint8_T usart_rxData[20];            /* '<Root>/Data Store Memory4' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint16_T dato1;                      /* '<Root>/dato1' */
  uint16_T dato2;                      /* '<Root>/dato2' */
  uint16_T dato3;                      /* '<Root>/dato3' */
  uint16_T dato4;                      /* '<Root>/dato4' */
} ExtU;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint8_T usartDebuxTx[633];      /* '<S2>/Data Store Memory' */

/* Model entry point functions */
extern void INITIALIZE(void);
extern void GeneratingModel_giuse_step0(void);
extern void GeneratingModel_giuse_step1(void);
extern void USART_SEND(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'GeneratingModel_giuse'
 * '<S1>'   : 'GeneratingModel_giuse/Initialize Function'
 * '<S2>'   : 'GeneratingModel_giuse/Subsystem Reference'
 * '<S3>'   : 'GeneratingModel_giuse/raccolta_dati'
 * '<S4>'   : 'GeneratingModel_giuse/Subsystem Reference/Bit Shift1'
 * '<S5>'   : 'GeneratingModel_giuse/Subsystem Reference/Bit Shift1/bit_shift'
 * '<S6>'   : 'GeneratingModel_giuse/raccolta_dati/Buffer'
 * '<S7>'   : 'GeneratingModel_giuse/raccolta_dati/Buffer1'
 * '<S8>'   : 'GeneratingModel_giuse/raccolta_dati/Buffer2'
 * '<S9>'   : 'GeneratingModel_giuse/raccolta_dati/Buffer3'
 */
#endif                                 /* RTW_HEADER_GeneratingModel_giuse_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
