/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr  8 14:42:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TVModel_h_
#define RTW_HEADER_TVModel_h_
#include "rtwtypes.h"
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef TVModel_COMMON_INCLUDES_
#define TVModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TVModel_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef DEFINED_TYPEDEF_FOR_zGeneral_Params_
#define DEFINED_TYPEDEF_FOR_zGeneral_Params_

typedef struct {
  real_T ThrottleThresh;
  real_T BrakeThresh;
  real_T SteerTresh;
  real_T SteerRelayAmplitude;
  real_T YRDTresh;
} zGeneral_Params;

#endif

#ifndef DEFINED_TYPEDEF_FOR_zMap_Params_
#define DEFINED_TYPEDEF_FOR_zMap_Params_

typedef struct {
  uint8_T YrdSelection;
} zMap_Params;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T CFunction[14];                /* '<S27>/C Function' */
  real_T CFunction_c[39];              /* '<S30>/C Function' */
  real_T Probe[2];                     /* '<S73>/Probe' */
  real_T CFunction_i[8];               /* '<S34>/C Function' */
  real_T CFunction_a[8];               /* '<S35>/C Function' */
  real_T UnitDelay_DSTATE[4];          /* '<S1>/Unit Delay' */
  real_T Integrator_DSTATE[4];         /* '<S78>/Integrator' */
  real_T DiscreteFIRFilter_states[4];  /* '<S55>/Discrete FIR Filter' */
  real_T Memory_PreviousInput[4];      /* '<S16>/Memory' */
  real_T PrevY[4];                     /* '<S79>/Rate Limiter' */
  real_T yaw_rate_desired_LUT;         /* '<S17>/Merge_LUT_results' */
  real_T yaw_rate_desired_LUT_g;       /* '<S17>/Merge_LUT_results1' */
  real_T UnitDelay1_DSTATE;            /* '<S41>/Unit Delay1' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S47>/Discrete FIR Filter' */
  int32_T DiscreteFIRFilter_circBuf_h; /* '<S55>/Discrete FIR Filter' */
  int16_T DiscreteFIRFilter_states_b[9];/* '<S47>/Discrete FIR Filter' */
  int8_T Integrator_PrevResetState;    /* '<S78>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S78>/Integrator' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_1.r))
   * Referenced by:
   *   '<S65>/LUT_1'
   *   '<S67>/LUT_1'
   */
  real_T pooled9[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_0.ay_matrix))
   * Referenced by:
   *   '<S64>/LUT_0'
   *   '<S66>/LUT_0'
   */
  real_T pooled10[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_neg1_5.r))
   * Referenced by:
   *   '<S61>/LUT_-1.5'
   *   '<S62>/LUT_-1.5'
   */
  real_T pooled11[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_neg3.ay_matrix))
   * Referenced by:
   *   '<S60>/LUT_-3'
   *   '<S63>/LUT_-3'
   */
  real_T pooled13[10000];

  /* Pooled Parameter (Expression: TV.LUT.Yrd_LUT.LUT_vectors.delta_vector)
   * Referenced by:
   *   '<S60>/LUT_-3'
   *   '<S61>/LUT_-1.5'
   *   '<S62>/LUT_-1.5'
   *   '<S63>/LUT_-3'
   *   '<S64>/LUT_0'
   *   '<S65>/LUT_1'
   *   '<S66>/LUT_0'
   *   '<S67>/LUT_1'
   */
  real_T pooled14[100];

  /* Pooled Parameter (Expression: TV.LUT.Yrd_LUT.LUT_vectors.v_vector)
   * Referenced by:
   *   '<S60>/LUT_-3'
   *   '<S61>/LUT_-1.5'
   *   '<S62>/LUT_-1.5'
   *   '<S63>/LUT_-3'
   *   '<S64>/LUT_0'
   *   '<S65>/LUT_1'
   *   '<S66>/LUT_0'
   *   '<S67>/LUT_1'
   */
  real_T pooled15[100];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_LUT.SteerAngle_FL
   * Referenced by: '<S10>/steering_to_wheel_angles_LUT'
   */
  real_T steering_to_wheel_angles_LUT_ta[33];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S10>/steering_to_wheel_angle_single_axis_LUT'
   *   '<S10>/steering_to_wheel_angles_LUT'
   */
  real_T pooled18[33];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT.SteerAngle_SingleAxis
   * Referenced by: '<S10>/steering_to_wheel_angle_single_axis_LUT'
   */
  real_T steering_to_wheel_angle_single_[33];

  /* Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fx_target_positive
   * Referenced by: '<S21>/2-D Lookup Table'
   */
  real_T uDLookupTable_tableData[400];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fz)
   * Referenced by:
   *   '<S21>/2-D Lookup Table'
   *   '<S21>/2-D Lookup Table1'
   */
  real_T pooled29[20];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_0_10.alpha)
   * Referenced by:
   *   '<S21>/2-D Lookup Table'
   *   '<S21>/2-D Lookup Table1'
   */
  real_T pooled30[20];

  /* Pooled Parameter (Expression: [TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 0])
   * Referenced by:
   *   '<S68>/Max_Torque_Overload_Inverter_LUT'
   *   '<S68>/Max_Torque_Overload_Motor_LUT'
   *   '<S68>/Max_Torque_Temperature_External_LUT'
   *   '<S68>/Max_Torque_Temperature_IGBT_LUT'
   *   '<S68>/Max_Torque_Temperature_Internal_LUT'
   *   '<S69>/Display Overload Inverter LUT'
   *   '<S69>/Display Overload Motor LUT'
   *   '<S69>/Temperature External LUT'
   *   '<S69>/Temperature IGBT LUT'
   *   '<S69>/Temperature Internal LUT'
   */
  real_T pooled32[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S68>/Max_Torque_Overload_Inverter_LUT'
   *   '<S68>/Max_Torque_Overload_Motor_LUT'
   *   '<S69>/Display Overload Inverter LUT'
   *   '<S69>/Display Overload Motor LUT'
   */
  real_T pooled33[3];

  /* Pooled Parameter (Expression: [0 TV.LV.AMK.ID32798_5 TV.LV.AMK.ID32798_6])
   * Referenced by:
   *   '<S68>/Max_Torque_Temperature_Internal_LUT'
   *   '<S69>/Temperature Internal LUT'
   */
  real_T pooled34[3];

  /* Pooled Parameter (Expression: [0 TV.LV.AMK.ID32798_8 TV.LV.AMK.ID32798_9])
   * Referenced by:
   *   '<S68>/Max_Torque_Temperature_IGBT_LUT'
   *   '<S69>/Temperature IGBT LUT'
   */
  real_T pooled35[3];

  /* Pooled Parameter (Expression: [0 TV.LV.AMK.ID32798_11 TV.LV.AMK.ID32798_12])
   * Referenced by:
   *   '<S68>/Max_Torque_Temperature_External_LUT'
   *   '<S69>/Temperature External LUT'
   */
  real_T pooled36[3];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.table_data )
   * Referenced by:
   *   '<S70>/2-D Lookup Table'
   *   '<S79>/2-D Lookup Table1'
   */
  real_T pooled38[9246];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints1)
   * Referenced by:
   *   '<S70>/2-D Lookup Table'
   *   '<S79>/2-D Lookup Table1'
   */
  real_T pooled39[201];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints2)
   * Referenced by:
   *   '<S70>/2-D Lookup Table'
   *   '<S79>/2-D Lookup Table1'
   */
  real_T pooled40[46];

  /* Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fx_target_negative
   * Referenced by: '<S21>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[400];

  /* Computed Parameter: uDLookupTable_tableData_p
   * Referenced by: '<S79>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData_p[20];

  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S79>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[20];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S60>/LUT_-3'
   *   '<S61>/LUT_-1.5'
   *   '<S62>/LUT_-1.5'
   *   '<S63>/LUT_-3'
   *   '<S64>/LUT_0'
   *   '<S65>/LUT_1'
   *   '<S66>/LUT_0'
   *   '<S67>/LUT_1'
   */
  uint32_T pooled48[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S21>/2-D Lookup Table'
   *   '<S21>/2-D Lookup Table1'
   */
  uint32_T pooled49[2];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T throttle;                     /* '<Root>/throttle' */
  real_T brake;                        /* '<Root>/brake' */
  real_T steering;                     /* '<Root>/steering' */
  real_T vx;                           /* '<Root>/vx' */
  real_T vy;                           /* '<Root>/vy' */
  real_T ax;                           /* '<Root>/ax' */
  real_T ay;                           /* '<Root>/ay' */
  real_T yaw_rate_deg;                 /* '<Root>/yaw_rate' */
  real_T brake_torque_FL;              /* '<Root>/brake_torque_FL' */
  real_T brake_torque_FR;              /* '<Root>/brake_torque_FR' */
  real_T brake_torque_RL;              /* '<Root>/brake_torque_RL' */
  real_T brake_torque_RR;              /* '<Root>/brake_torque_RR' */
  real_T omega_wheels_FL;              /* '<Root>/omega_wheels_FL' */
  real_T omega_wheels_FR;              /* '<Root>/omega_wheels_FR' */
  real_T omega_wheels_RL;              /* '<Root>/omega_wheels_RL' */
  real_T omega_wheels_RR;              /* '<Root>/omega_wheels_RR' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output;                       /* '<Root>/Output' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void TVModel_initialize(void);
extern void TV(void);
extern void TVModel_step1(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/Constant11' : Unused code path elimination
 * Block '<S2>/Constant7' : Unused code path elimination
 * Block '<S16>/Display' : Unused code path elimination
 * Block '<S16>/Gain' : Unused code path elimination
 * Block '<S16>/Product' : Unused code path elimination
 * Block '<S16>/Sum' : Unused code path elimination
 * Block '<S16>/Sum1' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Propagation' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S20>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S20>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<S20>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S20>/Manual Switch3' : Eliminated due to constant selection input
 * Block '<S34>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S35>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S47>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S24>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S55>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S17>/Cast To Double' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double1' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double2' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double3' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double4' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double5' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double6' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double7' : Eliminate redundant data type conversion
 * Block '<S68>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S68>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S68>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S68>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S68>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S78>/Saturation' : Eliminated Saturate block
 * Block '<S71>/K' : Eliminated nontunable gain of 1
 * Block '<S69>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S69>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S69>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S69>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S69>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S20>/Constant' : Unused code path elimination
 * Block '<S20>/Constant1' : Unused code path elimination
 * Block '<S20>/Constant2' : Unused code path elimination
 * Block '<S20>/Constant3' : Unused code path elimination
 */

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
 * '<Root>' : 'TVModel'
 * '<S1>'   : 'TVModel/Subsystem'
 * '<S2>'   : 'TVModel/Subsystem/Subsystem'
 * '<S3>'   : 'TVModel/Subsystem/Subsystem1'
 * '<S4>'   : 'TVModel/Subsystem/Subsystem/Degrees to Radians'
 * '<S5>'   : 'TVModel/Subsystem/Subsystem/Degrees to Radians1'
 * '<S6>'   : 'TVModel/Subsystem/Subsystem1/Slip Control'
 * '<S7>'   : 'TVModel/Subsystem/Subsystem1/Torque Distribution'
 * '<S8>'   : 'TVModel/Subsystem/Subsystem1/Torque Limits'
 * '<S9>'   : 'TVModel/Subsystem/Subsystem1/regen_brake'
 * '<S10>'  : 'TVModel/Subsystem/Subsystem1/steering_to_front_wheels'
 * '<S11>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios'
 * '<S12>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/FL SR'
 * '<S13>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/FR SR'
 * '<S14>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/RL RR '
 * '<S15>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/RL SR'
 * '<S16>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC'
 * '<S17>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking'
 * '<S18>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference'
 * '<S19>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus '
 * '<S20>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ States'
 * '<S21>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints'
 * '<S22>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/D matrix'
 * '<S23>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ESP'
 * '<S24>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults detection'
 * '<S25>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints'
 * '<S26>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation'
 * '<S27>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference/Bus y_ref'
 * '<S28>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference/MATLAB Function'
 * '<S29>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference/MATLAB Function1'
 * '<S30>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus /Bus p'
 * '<S31>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ States/Minimum vx'
 * '<S32>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Anti reverse wheelspin'
 * '<S33>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Brake & ESP'
 * '<S34>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Bus lbu'
 * '<S35>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Bus ubu'
 * '<S36>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Cross Check'
 * '<S37>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Hydraulic brakes'
 * '<S38>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation'
 * '<S39>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Low YRD'
 * '<S40>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation'
 * '<S41>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/lbu_dot'
 * '<S42>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/ubu_dot'
 * '<S43>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation/Fz FL'
 * '<S44>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation/Fz FR'
 * '<S45>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation/Fz RL'
 * '<S46>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation/Fz RR'
 * '<S47>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Low YRD/Mz = 0 Bound logic'
 * '<S48>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation/Slip Angle FL'
 * '<S49>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation/Slip Angle FR'
 * '<S50>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation/Slip Angle RL'
 * '<S51>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation/Slip Angle RR'
 * '<S52>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/D matrix/Efficiency limit'
 * '<S53>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/D matrix/MATLAB Function'
 * '<S54>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/D matrix/Efficiency limit/Power to engines'
 * '<S55>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults detection/Subsystem2'
 * '<S56>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Accelerator mapping '
 * '<S57>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/Linear Activation'
 * '<S58>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/MATLAB Function'
 * '<S59>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/MATLAB Function'
 * '<S60>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-1'
 * '<S61>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-1.1'
 * '<S62>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-1.5'
 * '<S63>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-3'
 * '<S64>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_0'
 * '<S65>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_1'
 * '<S66>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_2'
 * '<S67>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_3'
 * '<S68>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive'
 * '<S69>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen'
 * '<S70>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve'
 * '<S71>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S72>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Saturation Dynamic'
 * '<S73>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S74>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S75>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S76>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S77>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S78>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S79>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque Curve'
 * '<S80>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque Curve/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
