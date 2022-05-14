/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri May 13 18:30:58 2022
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
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* user code (top of header file) */
#include "acados_wrapper.h"
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
  real_T CFunction[22];                /* '<S28>/C Function' */
  real_T CFunction_n[26];              /* '<S31>/C Function' */
  real_T Probe[2];                     /* '<S67>/Probe' */
  real_T UnitDelay_DSTATE[4];          /* '<S2>/Unit Delay' */
  real_T Integrator_DSTATE[4];         /* '<S72>/Integrator' */
  real_T UnitDelay_DSTATE_j[4];        /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<S15>/Memory' */
  real_T PrevY[4];                     /* '<S73>/Rate Limiter' */
  real_T yrd;                          /* '<S61>/Divide2' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S51>/Discrete FIR Filter' */
  int16_T DiscreteFIRFilter_states[9]; /* '<S51>/Discrete FIR Filter' */
  int8_T Integrator_PrevResetState;    /* '<S72>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S72>/Integrator' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: TV.LUT.Car_LUT.steer_at_ground_LUT.SteerAngle_FL
   * Referenced by: '<S9>/steering_to_wheel_angles_LUT'
   */
  real_T steering_to_wheel_angles_LUT_ta[33];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S9>/steering_to_wheel_angle_single_axis_LUT'
   *   '<S9>/steering_to_wheel_angles_LUT'
   */
  real_T pooled16[33];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT.SteerAngle_SingleAxis
   * Referenced by: '<S9>/steering_to_wheel_angle_single_axis_LUT'
   */
  real_T steering_to_wheel_angle_single_[33];

  /* Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fx_target_positive
   * Referenced by: '<S25>/2-D Lookup Table'
   */
  real_T uDLookupTable_tableData[400];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fz)
   * Referenced by:
   *   '<S25>/2-D Lookup Table'
   *   '<S25>/2-D Lookup Table1'
   */
  real_T pooled27[20];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_0_10.alpha)
   * Referenced by:
   *   '<S25>/2-D Lookup Table'
   *   '<S25>/2-D Lookup Table1'
   */
  real_T pooled28[20];

  /* Pooled Parameter (Expression: [TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 0])
   * Referenced by:
   *   '<S62>/Max_Torque_Overload_Inverter_LUT'
   *   '<S62>/Max_Torque_Overload_Motor_LUT'
   *   '<S62>/Max_Torque_Temperature_External_LUT'
   *   '<S62>/Max_Torque_Temperature_IGBT_LUT'
   *   '<S62>/Max_Torque_Temperature_Internal_LUT'
   *   '<S63>/Display Overload Inverter LUT'
   *   '<S63>/Display Overload Motor LUT'
   *   '<S63>/Temperature External LUT'
   *   '<S63>/Temperature IGBT LUT'
   *   '<S63>/Temperature Internal LUT'
   */
  real_T pooled30[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S62>/Max_Torque_Overload_Inverter_LUT'
   *   '<S62>/Max_Torque_Overload_Motor_LUT'
   *   '<S63>/Display Overload Inverter LUT'
   *   '<S63>/Display Overload Motor LUT'
   */
  real_T pooled31[3];

  /* Pooled Parameter (Expression: [0 TV.LV.AMK.ID32798_5 TV.LV.AMK.ID32798_6])
   * Referenced by:
   *   '<S62>/Max_Torque_Temperature_Internal_LUT'
   *   '<S63>/Temperature Internal LUT'
   */
  real_T pooled32[3];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.table_data )
   * Referenced by:
   *   '<S64>/2-D Lookup Table'
   *   '<S73>/2-D Lookup Table1'
   */
  real_T pooled34[9246];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints1)
   * Referenced by:
   *   '<S64>/2-D Lookup Table'
   *   '<S73>/2-D Lookup Table1'
   */
  real_T pooled35[201];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints2)
   * Referenced by:
   *   '<S64>/2-D Lookup Table'
   *   '<S73>/2-D Lookup Table1'
   */
  real_T pooled36[46];

  /* Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fx_target_negative
   * Referenced by: '<S25>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[400];

  /* Computed Parameter: uDLookupTable_tableData_d
   * Referenced by: '<S73>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData_d[20];

  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S73>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[20];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Eta)
   * Referenced by:
   *   '<S36>/2-D Lookup Table'
   *   '<S60>/2-D Lookup Table'
   */
  real_T pooled45[4000];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Omega)
   * Referenced by:
   *   '<S36>/2-D Lookup Table'
   *   '<S60>/2-D Lookup Table'
   */
  real_T pooled46[200];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Torque)
   * Referenced by:
   *   '<S36>/2-D Lookup Table'
   *   '<S60>/2-D Lookup Table'
   */
  real_T pooled47[20];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S25>/2-D Lookup Table'
   *   '<S25>/2-D Lookup Table1'
   */
  uint32_T pooled50[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S36>/2-D Lookup Table'
   *   '<S60>/2-D Lookup Table'
   */
  uint32_T pooled52[2];
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
  real_T Torque[4];                    /* '<Root>/Torque' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

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

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/Constant11' : Unused code path elimination
 * Block '<S2>/Constant12' : Unused code path elimination
 * Block '<S2>/Constant15' : Unused code path elimination
 * Block '<S2>/Constant7' : Unused code path elimination
 * Block '<S32>/Constant1' : Unused code path elimination
 * Block '<S32>/Discrete FIR Filter' : Unused code path elimination
 * Block '<S32>/Less Than1' : Unused code path elimination
 * Block '<S32>/OR' : Unused code path elimination
 * Block '<S34>/      ' : Unused code path elimination
 * Block '<S34>/Switch3' : Unused code path elimination
 * Block '<S39>/C Function' : Unused code path elimination
 * Block '<S39>/Constant1' : Unused code path elimination
 * Block '<S39>/Constant3' : Unused code path elimination
 * Block '<S40>/C Function' : Unused code path elimination
 * Block '<S40>/Constant1' : Unused code path elimination
 * Block '<S40>/Constant3' : Unused code path elimination
 * Block '<S15>/Sum' : Unused code path elimination
 * Block '<S56>/      ' : Unused code path elimination
 * Block '<S56>/Switch3' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Propagation' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition14' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition15' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition16' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S16>/Cast To Double4' : Eliminate redundant data type conversion
 * Block '<S62>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S62>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S62>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S62>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S62>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S72>/Saturation' : Eliminated Saturate block
 * Block '<S65>/K' : Eliminated nontunable gain of 1
 * Block '<S63>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S63>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S63>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S63>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S63>/Cast_4' : Eliminate redundant data type conversion
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
 * '<S4>'   : 'TVModel/Subsystem/Subsystem/Degrees to Radians1'
 * '<S5>'   : 'TVModel/Subsystem/Subsystem1/Slip Control'
 * '<S6>'   : 'TVModel/Subsystem/Subsystem1/Torque Distribution'
 * '<S7>'   : 'TVModel/Subsystem/Subsystem1/Torque Limits'
 * '<S8>'   : 'TVModel/Subsystem/Subsystem1/regen_brake'
 * '<S9>'   : 'TVModel/Subsystem/Subsystem1/steering_to_front_wheels'
 * '<S10>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios'
 * '<S11>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/FL SR'
 * '<S12>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/FR SR'
 * '<S13>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/RL RR '
 * '<S14>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/RL SR'
 * '<S15>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC'
 * '<S16>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking'
 * '<S17>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference'
 * '<S18>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus '
 * '<S19>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ States'
 * '<S20>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control Constraints'
 * '<S21>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ESP'
 * '<S22>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults detection'
 * '<S23>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints'
 * '<S24>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix'
 * '<S25>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints'
 * '<S26>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Subsystem'
 * '<S27>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation'
 * '<S28>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference/Bus y_ref'
 * '<S29>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference/MATLAB Function'
 * '<S30>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference/MATLAB Function1'
 * '<S31>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus /Bus p'
 * '<S32>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults detection/Subsystem2'
 * '<S33>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Accelerator mapping '
 * '<S34>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit'
 * '<S35>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/MATLAB Function'
 * '<S36>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit/Power to engines'
 * '<S37>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Anti reverse wheelspin'
 * '<S38>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Brake & ESP'
 * '<S39>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Bus lbu'
 * '<S40>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Bus ubu'
 * '<S41>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Cross Check'
 * '<S42>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Hydraulic brakes'
 * '<S43>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/LMUx Correction'
 * '<S44>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Load Transfer calculation'
 * '<S45>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Low YRD'
 * '<S46>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Slip Angle calculation'
 * '<S47>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Load Transfer calculation/Fz FL'
 * '<S48>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Load Transfer calculation/Fz FR'
 * '<S49>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Load Transfer calculation/Fz RL'
 * '<S50>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Load Transfer calculation/Fz RR'
 * '<S51>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Low YRD/Mz = 0 Bound logic'
 * '<S52>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Slip Angle calculation/Slip Angle FL'
 * '<S53>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Slip Angle calculation/Slip Angle FR'
 * '<S54>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Slip Angle calculation/Slip Angle RL'
 * '<S55>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States constraints/Slip Angle calculation/Slip Angle RR'
 * '<S56>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/Efficiency limit'
 * '<S57>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/MATLAB Function'
 * '<S58>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/Non-Linear Activation'
 * '<S59>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/Efficiency limit/MATLAB Function'
 * '<S60>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/Efficiency limit/Power to engines'
 * '<S61>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_2'
 * '<S62>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive'
 * '<S63>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen'
 * '<S64>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve'
 * '<S65>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S66>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Saturation Dynamic'
 * '<S67>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S68>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S69>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S70>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S71>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S72>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S73>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque Curve'
 * '<S74>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque Curve/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
