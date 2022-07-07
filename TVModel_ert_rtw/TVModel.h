/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Jul  7 16:26:30 2022
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
#include "ITB_Nucleo_configuration\Inc\acados_wrapper.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Probe[2];                     /* '<S33>/Probe' */
  real_T Probe_k[2];                   /* '<S98>/Probe' */
  real_T CFunction[54];                /* '<S172>/C Function' */
  real_T Probe_kx[2];                  /* '<S232>/Probe' */
  real_T Probe_b[2];                   /* '<S241>/Probe' */
  real_T Merge[4];                     /* '<S164>/Merge' */
  real_T UnitDelay_DSTATE[4];          /* '<S2>/Unit Delay' */
  real_T UD_DSTATE[4];                 /* '<S28>/UD' */
  real_T Integrator_DSTATE[4];         /* '<S74>/Integrator' */
  real_T Filter_DSTATE[4];             /* '<S69>/Filter' */
  real_T Integrator_DSTATE_h[4];       /* '<S38>/Integrator' */
  real_T UnitDelay_DSTATE_n[4];        /* '<S26>/Unit Delay' */
  real_T UD_DSTATE_f[4];               /* '<S93>/UD' */
  real_T Integrator_DSTATE_f[4];       /* '<S139>/Integrator' */
  real_T Filter_DSTATE_d[4];           /* '<S134>/Filter' */
  real_T Integrator_DSTATE_f3[4];      /* '<S103>/Integrator' */
  real_T UnitDelay_DSTATE_g[4];        /* '<S27>/Unit Delay' */
  real_T Integrator_DSTATE_j[4];       /* '<S237>/Integrator' */
  real_T Integrator_DSTATE_ff[4];      /* '<S246>/Integrator' */
  real_T UnitDelay_DSTATE_j[4];        /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<S158>/Memory' */
  real_T yaw_rate_desired_LUT;         /* '<S159>/Merge_LUT_results' */
  real_T yaw_rate_desired_LUT_d;       /* '<S159>/Merge_LUT_results1' */
  real_T UnitDelay3_1_DSTATE;          /* '<S26>/Unit Delay3' */
  real_T UnitDelay3_2_DSTATE;          /* '<S26>/Unit Delay3' */
  real_T UnitDelay3_3_DSTATE;          /* '<S26>/Unit Delay3' */
  real_T UnitDelay3_4_DSTATE;          /* '<S26>/Unit Delay3' */
  real_T UnitDelay2_1_DSTATE;          /* '<S26>/Unit Delay2' */
  real_T UnitDelay2_2_DSTATE;          /* '<S26>/Unit Delay2' */
  real_T UnitDelay2_3_DSTATE;          /* '<S26>/Unit Delay2' */
  real_T UnitDelay2_4_DSTATE;          /* '<S26>/Unit Delay2' */
  real_T UnitDelay3_1_DSTATE_f;        /* '<S27>/Unit Delay3' */
  real_T UnitDelay3_2_DSTATE_b;        /* '<S27>/Unit Delay3' */
  real_T UnitDelay3_3_DSTATE_k;        /* '<S27>/Unit Delay3' */
  real_T UnitDelay3_4_DSTATE_o;        /* '<S27>/Unit Delay3' */
  real_T UnitDelay2_1_DSTATE_i;        /* '<S27>/Unit Delay2' */
  real_T UnitDelay2_2_DSTATE_f;        /* '<S27>/Unit Delay2' */
  real_T UnitDelay2_3_DSTATE_j;        /* '<S27>/Unit Delay2' */
  real_T UnitDelay2_4_DSTATE_c;        /* '<S27>/Unit Delay2' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S177>/Discrete FIR Filter' */
  struct {
    uint_T is_c75_TVModel:2;           /* '<S164>/Overlap Chart' */
    uint_T is_active_c75_TVModel:1;    /* '<S164>/Overlap Chart' */
    uint_T Memory_PreviousInput_n:1;   /* '<S211>/Memory' */
    uint_T Memory_PreviousInput_i:1;   /* '<S212>/Memory' */
    uint_T Memory_PreviousInput_h:1;   /* '<S213>/Memory' */
    uint_T Memory_PreviousInput_d:1;   /* '<S214>/Memory' */
    uint_T Memory_PreviousInput_e:1;   /* '<S191>/Memory' */
    uint_T IC_FirstOutputTime:1;       /* '<S194>/IC' */
    uint_T IC1_FirstOutputTime:1;      /* '<S195>/IC1' */
  } bitsForTID0;

  int8_T Integrator_PrevResetState[4]; /* '<S74>/Integrator' */
  int8_T Filter_PrevResetState[4];     /* '<S69>/Filter' */
  int8_T Integrator_PrevResetState_a[4];/* '<S139>/Integrator' */
  int8_T Filter_PrevResetState_d[4];   /* '<S134>/Filter' */
  int8_T Integrator_PrevResetState_d;  /* '<S38>/Integrator' */
  int8_T Integrator_PrevResetState_m;  /* '<S103>/Integrator' */
  int8_T Integrator_PrevResetState_i;  /* '<S237>/Integrator' */
  int8_T Integrator_PrevResetState_f;  /* '<S246>/Integrator' */
  uint8_T DiscreteFIRFilter_states[4]; /* '<S177>/Discrete FIR Filter' */
  uint8_T Integrator_IC_LOADING;       /* '<S38>/Integrator' */
  uint8_T Integrator_IC_LOADING_i;     /* '<S103>/Integrator' */
  uint8_T Integrator_IC_LOADING_it;    /* '<S237>/Integrator' */
  uint8_T Integrator_IC_LOADING_b;     /* '<S246>/Integrator' */
  boolean_T Memory_PreviousInput_f[4]; /* '<S26>/Memory' */
  boolean_T Memory_PreviousInput_m[4]; /* '<S27>/Memory' */
} DW;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T UnaryMinus[6];          /* '<S166>/Unary Minus' */
} ConstB;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_1.ay_matrix))
   * Referenced by:
   *   '<S224>/LUT_1'
   *   '<S226>/LUT_1'
   */
  real_T pooled15[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_0.ay_matrix))
   * Referenced by:
   *   '<S223>/LUT_0'
   *   '<S225>/LUT_0'
   */
  real_T pooled16[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_neg1_5.ay_matrix))
   * Referenced by:
   *   '<S220>/LUT_-1.5'
   *   '<S221>/LUT_-1.5'
   */
  real_T pooled17[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_neg3.ay_matrix))
   * Referenced by:
   *   '<S219>/LUT_-3'
   *   '<S222>/LUT_-3'
   */
  real_T pooled19[10000];

  /* Pooled Parameter (Expression: TV.LUT.Yrd_LUT.LUT_vectors.delta_vector)
   * Referenced by:
   *   '<S219>/LUT_-3'
   *   '<S220>/LUT_-1.5'
   *   '<S221>/LUT_-1.5'
   *   '<S222>/LUT_-3'
   *   '<S223>/LUT_0'
   *   '<S224>/LUT_1'
   *   '<S225>/LUT_0'
   *   '<S226>/LUT_1'
   */
  real_T pooled20[100];

  /* Pooled Parameter (Expression: TV.LUT.Yrd_LUT.LUT_vectors.v_vector)
   * Referenced by:
   *   '<S219>/LUT_-3'
   *   '<S220>/LUT_-1.5'
   *   '<S221>/LUT_-1.5'
   *   '<S222>/LUT_-3'
   *   '<S223>/LUT_0'
   *   '<S224>/LUT_1'
   *   '<S225>/LUT_0'
   *   '<S226>/LUT_1'
   */
  real_T pooled21[100];

  /* Expression: [1e4;8e5;1e4;1e4;1e4;0.1]
   * Referenced by: '<S166>/Constant'
   */
  real_T Constant_Value_b[6];

  /* Expression: [1;5;5;1e-3]
   * Referenced by: '<S168>/Constant'
   */
  real_T Constant_Value_fo[4];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_LUT.SteerAngle_FL
   * Referenced by: '<S9>/steering_to_wheel_angles_LUT'
   */
  real_T steering_to_wheel_angles_LUT_ta[33];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S9>/steering_to_wheel_angle_single_axis_LUT'
   *   '<S9>/steering_to_wheel_angles_LUT'
   */
  real_T pooled36[33];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT.SteerAngle_SingleAxis
   * Referenced by: '<S9>/steering_to_wheel_angle_single_axis_LUT'
   */
  real_T steering_to_wheel_angle_single_[33];

  /* Pooled Parameter (Expression: [TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 0])
   * Referenced by:
   *   '<S227>/Max_Torque_Overload_Inverter_LUT'
   *   '<S227>/Max_Torque_Overload_Motor_LUT'
   *   '<S227>/Max_Torque_Temperature_External_LUT'
   *   '<S227>/Max_Torque_Temperature_IGBT_LUT'
   *   '<S227>/Max_Torque_Temperature_Internal_LUT'
   *   '<S228>/Display Overload Inverter LUT'
   *   '<S228>/Display Overload Motor LUT'
   *   '<S228>/Temperature External LUT'
   *   '<S228>/Temperature IGBT LUT'
   *   '<S228>/Temperature Internal LUT'
   */
  real_T pooled42[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S227>/Max_Torque_Overload_Inverter_LUT'
   *   '<S227>/Max_Torque_Overload_Motor_LUT'
   *   '<S228>/Display Overload Inverter LUT'
   *   '<S228>/Display Overload Motor LUT'
   */
  real_T pooled43[3];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.table_data )
   * Referenced by:
   *   '<S229>/2-D Lookup Table'
   *   '<S238>/2-D Lookup Table'
   */
  real_T pooled46[9246];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints1)
   * Referenced by:
   *   '<S229>/2-D Lookup Table'
   *   '<S238>/2-D Lookup Table'
   */
  real_T pooled47[201];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints2)
   * Referenced by:
   *   '<S229>/2-D Lookup Table'
   *   '<S238>/2-D Lookup Table'
   */
  real_T pooled48[46];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_positive
   * Referenced by: '<S209>/2-D Lookup Table'
   */
  real_T uDLookupTable_tableData[900];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.Fz)
   * Referenced by:
   *   '<S209>/2-D Lookup Table'
   *   '<S209>/2-D Lookup Table1'
   */
  real_T pooled50[30];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.alpha)
   * Referenced by:
   *   '<S209>/2-D Lookup Table'
   *   '<S209>/2-D Lookup Table1'
   */
  real_T pooled51[30];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_negative
   * Referenced by: '<S209>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[900];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S219>/LUT_-3'
   *   '<S220>/LUT_-1.5'
   *   '<S221>/LUT_-1.5'
   *   '<S222>/LUT_-3'
   *   '<S223>/LUT_0'
   *   '<S224>/LUT_1'
   *   '<S225>/LUT_0'
   *   '<S226>/LUT_1'
   */
  uint32_T pooled56[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S209>/2-D Lookup Table'
   *   '<S209>/2-D Lookup Table1'
   */
  uint32_T pooled58[2];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S191>/Logic'
   *   '<S211>/Logic'
   *   '<S212>/Logic'
   *   '<S213>/Logic'
   *   '<S214>/Logic'
   */
  boolean_T pooled61[16];
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
extern const ConstB rtConstB;          /* constant block i/o */

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
 * Block '<S2>/Constant13' : Unused code path elimination
 * Block '<S2>/Constant14' : Unused code path elimination
 * Block '<S2>/Constant15' : Unused code path elimination
 * Block '<S2>/Constant7' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Propagation' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Propagation' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Propagation' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate' : Unused code path elimination
 * Block '<S201>/Data Type Propagation' : Unused code path elimination
 * Block '<S203>/NOT' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/Data Type Propagation' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate' : Unused code path elimination
 * Block '<S240>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S38>/Saturation' : Eliminated Saturate block
 * Block '<S29>/K' : Eliminated nontunable gain of 1
 * Block '<S71>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S79>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S89>/Setpoint Weighting (Proportional)' : Eliminated nontunable gain of 1
 * Block '<S90>/Setpoint Weighting (Derivative)' : Eliminated nontunable gain of 1
 * Block '<S103>/Saturation' : Eliminated Saturate block
 * Block '<S94>/K' : Eliminated nontunable gain of 1
 * Block '<S154>/Setpoint Weighting (Proportional)' : Eliminated nontunable gain of 1
 * Block '<S155>/Setpoint Weighting (Derivative)' : Eliminated nontunable gain of 1
 * Block '<S192>/Gain3' : Eliminated nontunable gain of 1
 * Block '<S159>/Cast To Double' : Eliminate redundant data type conversion
 * Block '<S159>/Cast To Double1' : Eliminate redundant data type conversion
 * Block '<S159>/Cast To Double2' : Eliminate redundant data type conversion
 * Block '<S159>/Cast To Double3' : Eliminate redundant data type conversion
 * Block '<S159>/Cast To Double4' : Eliminate redundant data type conversion
 * Block '<S159>/Cast To Double5' : Eliminate redundant data type conversion
 * Block '<S159>/Cast To Double6' : Eliminate redundant data type conversion
 * Block '<S159>/Cast To Double7' : Eliminate redundant data type conversion
 * Block '<S227>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S227>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S227>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S227>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S227>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S237>/Saturation' : Eliminated Saturate block
 * Block '<S230>/K' : Eliminated nontunable gain of 1
 * Block '<S228>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S228>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S228>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S228>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S228>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S246>/Saturation' : Eliminated Saturate block
 * Block '<S239>/K' : Eliminated nontunable gain of 1
 * Block '<S179>/Constant3' : Unused code path elimination
 * Block '<S179>/Constant4' : Unused code path elimination
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
 * '<S3>'   : 'TVModel/Subsystem/Subsystem2'
 * '<S4>'   : 'TVModel/Subsystem/Subsystem/Degrees to Radians1'
 * '<S5>'   : 'TVModel/Subsystem/Subsystem2/Slip Control'
 * '<S6>'   : 'TVModel/Subsystem/Subsystem2/Torque Distribution'
 * '<S7>'   : 'TVModel/Subsystem/Subsystem2/Torque Limits'
 * '<S8>'   : 'TVModel/Subsystem/Subsystem2/regen_brake'
 * '<S9>'   : 'TVModel/Subsystem/Subsystem2/steering_to_front_wheels'
 * '<S10>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Load Transfer Calculation'
 * '<S11>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Angle Calculation'
 * '<S12>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Ratios'
 * '<S13>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control'
 * '<S14>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Load Transfer Calculation/Fz FL'
 * '<S15>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Load Transfer Calculation/Fz FR'
 * '<S16>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Load Transfer Calculation/Fz RL'
 * '<S17>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Load Transfer Calculation/Fz RR'
 * '<S18>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Angle Calculation/Slip Angle FL'
 * '<S19>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Angle Calculation/Slip Angle FR'
 * '<S20>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Angle Calculation/Slip Angle RL'
 * '<S21>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Angle Calculation/Slip Angle RR'
 * '<S22>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Ratios/FL SR'
 * '<S23>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Ratios/FR SR'
 * '<S24>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Ratios/RL RR '
 * '<S25>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Slip Ratios/RL SR'
 * '<S26>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS'
 * '<S27>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC'
 * '<S28>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/Discrete Derivative1'
 * '<S29>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/Low-Pass Filter (Discrete or Continuous)'
 * '<S30>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/MATLAB Function2'
 * '<S31>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/MATLAB Function3'
 * '<S32>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)'
 * '<S33>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S34>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S35>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S36>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S37>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S38>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S39>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Anti-windup'
 * '<S40>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/D Gain'
 * '<S41>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Filter'
 * '<S42>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Filter ICs'
 * '<S43>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/I Gain'
 * '<S44>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Ideal P Gain'
 * '<S45>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Ideal P Gain Fdbk'
 * '<S46>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Integrator'
 * '<S47>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Integrator ICs'
 * '<S48>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/N Copy'
 * '<S49>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/N Gain'
 * '<S50>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/P Copy'
 * '<S51>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Parallel P Gain'
 * '<S52>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Reset Signal'
 * '<S53>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Saturation'
 * '<S54>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Saturation Fdbk'
 * '<S55>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Sum'
 * '<S56>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Sum Fdbk'
 * '<S57>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Tracking Mode'
 * '<S58>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Tracking Mode Sum'
 * '<S59>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Tsamp - Integral'
 * '<S60>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Tsamp - Ngain'
 * '<S61>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/b Gain'
 * '<S62>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/c Gain'
 * '<S63>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/postSat Signal'
 * '<S64>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/preSat Signal'
 * '<S65>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Anti-windup/Disc. Clamping Parallel'
 * '<S66>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S67>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S68>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/D Gain/Internal Parameters'
 * '<S69>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Filter/Disc. Forward Euler Filter'
 * '<S70>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Filter ICs/Internal IC - Filter'
 * '<S71>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/I Gain/Internal Parameters'
 * '<S72>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Ideal P Gain/Passthrough'
 * '<S73>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Ideal P Gain Fdbk/Disabled'
 * '<S74>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Integrator/Discrete'
 * '<S75>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Integrator ICs/Internal IC'
 * '<S76>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/N Copy/Disabled'
 * '<S77>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/N Gain/Internal Parameters'
 * '<S78>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/P Copy/Disabled'
 * '<S79>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Parallel P Gain/Internal Parameters'
 * '<S80>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Reset Signal/External Reset'
 * '<S81>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Saturation/Enabled'
 * '<S82>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Saturation Fdbk/Disabled'
 * '<S83>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Sum/Sum_PID'
 * '<S84>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Sum Fdbk/Disabled'
 * '<S85>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Tracking Mode/Disabled'
 * '<S86>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Tracking Mode Sum/Passthrough'
 * '<S87>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Tsamp - Integral/Passthrough'
 * '<S88>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/Tsamp - Ngain/Passthrough'
 * '<S89>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/b Gain/Internal Parameters'
 * '<S90>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/c Gain/Internal Parameters'
 * '<S91>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/postSat Signal/Forward_Path'
 * '<S92>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/ABS/PID Controller (2DOF)/preSat Signal/Forward_Path'
 * '<S93>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/Discrete Derivative1'
 * '<S94>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/Low-Pass Filter (Discrete or Continuous)'
 * '<S95>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/MATLAB Function2'
 * '<S96>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/MATLAB Function3'
 * '<S97>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)'
 * '<S98>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S99>'  : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S100>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S101>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S102>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S103>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S104>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Anti-windup'
 * '<S105>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/D Gain'
 * '<S106>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Filter'
 * '<S107>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Filter ICs'
 * '<S108>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/I Gain'
 * '<S109>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Ideal P Gain'
 * '<S110>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Ideal P Gain Fdbk'
 * '<S111>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Integrator'
 * '<S112>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Integrator ICs'
 * '<S113>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/N Copy'
 * '<S114>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/N Gain'
 * '<S115>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/P Copy'
 * '<S116>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Parallel P Gain'
 * '<S117>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Reset Signal'
 * '<S118>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Saturation'
 * '<S119>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Saturation Fdbk'
 * '<S120>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Sum'
 * '<S121>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Sum Fdbk'
 * '<S122>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Tracking Mode'
 * '<S123>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Tracking Mode Sum'
 * '<S124>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Tsamp - Integral'
 * '<S125>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Tsamp - Ngain'
 * '<S126>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/b Gain'
 * '<S127>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/c Gain'
 * '<S128>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/postSat Signal'
 * '<S129>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/preSat Signal'
 * '<S130>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Anti-windup/Disc. Clamping Parallel'
 * '<S131>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S132>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S133>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/D Gain/Internal Parameters'
 * '<S134>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Filter/Disc. Forward Euler Filter'
 * '<S135>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Filter ICs/Internal IC - Filter'
 * '<S136>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/I Gain/Internal Parameters'
 * '<S137>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Ideal P Gain/Passthrough'
 * '<S138>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Ideal P Gain Fdbk/Disabled'
 * '<S139>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Integrator/Discrete'
 * '<S140>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Integrator ICs/Internal IC'
 * '<S141>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/N Copy/Disabled'
 * '<S142>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/N Gain/Internal Parameters'
 * '<S143>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/P Copy/Disabled'
 * '<S144>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Parallel P Gain/Internal Parameters'
 * '<S145>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Reset Signal/External Reset'
 * '<S146>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Saturation/Enabled'
 * '<S147>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Saturation Fdbk/Disabled'
 * '<S148>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Sum/Sum_PID'
 * '<S149>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Sum Fdbk/Disabled'
 * '<S150>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Tracking Mode/Disabled'
 * '<S151>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Tracking Mode Sum/Passthrough'
 * '<S152>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Tsamp - Integral/Passthrough'
 * '<S153>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/Tsamp - Ngain/Passthrough'
 * '<S154>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/b Gain/Internal Parameters'
 * '<S155>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/c Gain/Internal Parameters'
 * '<S156>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/postSat Signal/Forward_Path'
 * '<S157>' : 'TVModel/Subsystem/Subsystem2/Slip Control/Traction Control/TC/PID Controller (2DOF)/preSat Signal/Forward_Path'
 * '<S158>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC'
 * '<S159>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking'
 * '<S160>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/     Output Vector Reference'
 * '<S161>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/ Parameter Bus '
 * '<S162>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/ States'
 * '<S163>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Control Constraints'
 * '<S164>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection'
 * '<S165>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Mz Generation'
 * '<S166>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Nonlinear constraints_0'
 * '<S167>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints'
 * '<S168>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Slack variables Weights '
 * '<S169>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints'
 * '<S170>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Weights Generation'
 * '<S171>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/     Output Vector Reference/MATLAB Function'
 * '<S172>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/ Parameter Bus /Bus p'
 * '<S173>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Control Constraints/MATLAB Function1'
 * '<S174>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/MPC'
 * '<S175>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Overlap Chart'
 * '<S176>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Simple torque'
 * '<S177>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Subsystem'
 * '<S178>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV'
 * '<S179>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/Driver Inputs'
 * '<S180>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/Driver Inputs/Accelerator Mapping '
 * '<S181>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/Driver Inputs/Saturation Dynamic'
 * '<S182>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/Driver Inputs/Simple Traction'
 * '<S183>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/Driver Inputs/Simple Traction/Saturation Dynamic1'
 * '<S184>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Subsystem/Backup Map'
 * '<S185>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Faults Detection/Subsystem/Selected Map'
 * '<S186>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Mz Generation/MATLAB Function'
 * '<S187>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Mz Generation/MATLAB Function3'
 * '<S188>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Mz Generation/MATLAB Function4'
 * '<S189>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Mz Generation/Saturation Dynamic'
 * '<S190>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Mz Generation/Steer Activation'
 * '<S191>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Mz Generation/Steer Activation/S-R Flip-Flop'
 * '<S192>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs'
 * '<S193>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Driver g'
 * '<S194>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Power Limits Negative'
 * '<S195>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Power Limits Positive'
 * '<S196>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Subsystem'
 * '<S197>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Subsystem1'
 * '<S198>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Accelerator Mapping '
 * '<S199>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/MATLAB Function3'
 * '<S200>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/MATLAB Function4'
 * '<S201>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Saturation Dynamic'
 * '<S202>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Polytopic Constraints/Driver g/Coasting'
 * '<S203>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin'
 * '<S204>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Brake & ESP'
 * '<S205>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Cross Check'
 * '<S206>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Low YRD'
 * '<S207>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/MATLAB Function'
 * '<S208>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/MATLAB Function1'
 * '<S209>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Tire Bounds'
 * '<S210>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops'
 * '<S211>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop'
 * '<S212>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop1'
 * '<S213>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop2'
 * '<S214>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop3'
 * '<S215>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Tire Bounds/Hydraulic brakes'
 * '<S216>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/States Constraints/Tire Bounds/LMUx Correction'
 * '<S217>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/MPC/Weights Generation/MATLAB Function'
 * '<S218>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/MATLAB Function'
 * '<S219>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/YRD_LUT_-1'
 * '<S220>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/YRD_LUT_-1.1'
 * '<S221>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/YRD_LUT_-1.5'
 * '<S222>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/YRD_LUT_-3'
 * '<S223>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/YRD_LUT_0'
 * '<S224>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/YRD_LUT_1'
 * '<S225>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/YRD_LUT_2'
 * '<S226>' : 'TVModel/Subsystem/Subsystem2/Torque Distribution/Reference Tracking/YRD_LUT_3'
 * '<S227>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive'
 * '<S228>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen'
 * '<S229>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve'
 * '<S230>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S231>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve/Saturation Dynamic'
 * '<S232>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S233>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S234>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S235>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S236>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S237>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S238>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve'
 * '<S239>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S240>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve/Saturation Dynamic'
 * '<S241>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S242>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S243>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S244>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S245>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S246>' : 'TVModel/Subsystem/Subsystem2/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
