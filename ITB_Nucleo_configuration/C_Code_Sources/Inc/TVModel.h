/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Jun  9 12:20:35 2022
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
  real_T YRDTresh;
  real_T VxTresh;
} zGeneral_Params;

#endif

#ifndef DEFINED_TYPEDEF_FOR_zMap_Params_
#define DEFINED_TYPEDEF_FOR_zMap_Params_

typedef struct {
  uint8_T YrdSelection;
} zMap_Params;

#endif

#ifndef struct_tag_3NiWMXO734j2vYCmGs3lz
#define struct_tag_3NiWMXO734j2vYCmGs3lz

struct tag_3NiWMXO734j2vYCmGs3lz
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[24];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_3NiWMXO734j2vYCmGs3lz */

#ifndef typedef_g_dsp_internal_SlidingWindowAve
#define typedef_g_dsp_internal_SlidingWindowAve

typedef struct tag_3NiWMXO734j2vYCmGs3lz g_dsp_internal_SlidingWindowAve;

#endif                             /* typedef_g_dsp_internal_SlidingWindowAve */

#ifndef struct_tag_twKmvSwtXFvwm110YFDILC
#define struct_tag_twKmvSwtXFvwm110YFDILC

struct tag_twKmvSwtXFvwm110YFDILC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[4];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_twKmvSwtXFvwm110YFDILC */

#ifndef typedef_g_dsp_internal_SlidingWindowA_l
#define typedef_g_dsp_internal_SlidingWindowA_l

typedef struct tag_twKmvSwtXFvwm110YFDILC g_dsp_internal_SlidingWindowA_l;

#endif                             /* typedef_g_dsp_internal_SlidingWindowA_l */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap;

#endif                                 /* typedef_cell_wrap */

#ifndef struct_tag_jzS6kMpFJO3FhRUJgNdkWF
#define struct_tag_jzS6kMpFJO3FhRUJgNdkWF

struct tag_jzS6kMpFJO3FhRUJgNdkWF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  g_dsp_internal_SlidingWindowAve *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowAve _pobj0;
};

#endif                                 /* struct_tag_jzS6kMpFJO3FhRUJgNdkWF */

#ifndef typedef_dsp_simulink_MovingAverage
#define typedef_dsp_simulink_MovingAverage

typedef struct tag_jzS6kMpFJO3FhRUJgNdkWF dsp_simulink_MovingAverage;

#endif                                 /* typedef_dsp_simulink_MovingAverage */

#ifndef struct_tag_VSW2YOpcQ0JoSsliuYZ3uD
#define struct_tag_VSW2YOpcQ0JoSsliuYZ3uD

struct tag_VSW2YOpcQ0JoSsliuYZ3uD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  g_dsp_internal_SlidingWindowA_l *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowA_l _pobj0;
};

#endif                                 /* struct_tag_VSW2YOpcQ0JoSsliuYZ3uD */

#ifndef typedef_dsp_simulink_MovingAverage_l
#define typedef_dsp_simulink_MovingAverage_l

typedef struct tag_VSW2YOpcQ0JoSsliuYZ3uD dsp_simulink_MovingAverage_l;

#endif                                /* typedef_dsp_simulink_MovingAverage_l */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage obj;      /* '<S49>/Moving Average' */
  dsp_simulink_MovingAverage_l obj_m;  /* '<S155>/Moving Average' */
  zGeneral_Params General_Params;      /* '<S3>/Data Store_General_Params' */
  real_T CFunction[26];                /* '<S29>/C Function' */
  real_T Probe[2];                     /* '<S159>/Probe' */
  real_T Probe_k[2];                   /* '<S168>/Probe' */
  real_T CFunction_p[4];               /* '<S126>/C Function' */
  real_T CFunction_f[4];               /* '<S127>/C Function' */
  real_T UnitDelay_DSTATE[4];          /* '<S2>/Unit Delay' */
  real_T Integrator_DSTATE[4];         /* '<S164>/Integrator' */
  real_T Integrator_DSTATE_f[4];       /* '<S173>/Integrator' */
  real_T UnitDelay_DSTATE_j[4];        /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<S16>/Memory' */
  real_T mz_output;                    /* '<S23>/Chart' */
  real_T Integrator_DSTATE_n;          /* '<S86>/Integrator' */
  real_T Filter_DSTATE;                /* '<S81>/Filter' */
  real_T tr;                           /* '<S116>/Distribution complete' */
  real_T Rw;                           /* '<S116>/Distribution complete' */
  int32_T DiscreteFIRFilter_states[4]; /* '<S33>/Discrete FIR Filter' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S33>/Discrete FIR Filter' */
  int32_T chartGlobalTickCounter;      /* '<S23>/Chart' */
  int32_T countReferenceTick_1;        /* '<S23>/Chart' */
  int8_T Integrator_PrevResetState;    /* '<S164>/Integrator' */
  int8_T Integrator_PrevResetState_b;  /* '<S173>/Integrator' */
  int8_T Integrator_PrevResetState_i;  /* '<S86>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S81>/Filter' */
  uint8_T Integrator_IC_LOADING;       /* '<S164>/Integrator' */
  uint8_T Integrator_IC_LOADING_j;     /* '<S173>/Integrator' */
  uint8_T is_active_c21_TVModel;       /* '<S155>/T_Req_Chart' */
  uint8_T is_c21_TVModel;              /* '<S155>/T_Req_Chart' */
  uint8_T is_active_c24_TVModel;       /* '<S23>/Chart' */
  uint8_T is_c24_TVModel;              /* '<S23>/Chart' */
  uint8_T is_active_c13_TVModel;       /* '<S22>/Overlap Chart' */
  uint8_T is_c13_TVModel;              /* '<S22>/Overlap Chart' */
  boolean_T Delay_DSTATE[5];           /* '<S49>/Delay' */
  boolean_T Memory_PreviousInput_f;    /* '<S133>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S134>/Memory' */
  boolean_T Memory_PreviousInput_j4;   /* '<S135>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S136>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S109>/Memory' */
  boolean_T IC_FirstOutputTime;        /* '<S112>/IC' */
  boolean_T IC1_FirstOutputTime;       /* '<S113>/IC1' */
  boolean_T countCondWasTrueAtLastTimeStep_;/* '<S23>/Chart' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: TV.LV.GENERAL
   * Referenced by: '<S3>/Data Store_General_Params'
   */
  zGeneral_Params DataStore_General_Params_Initia;

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Eta)
   * Referenced by:
   *   '<S35>/Constant1'
   *   '<S123>/2-D Lookup Table'
   *   '<S151>/2-D Lookup Table'
   */
  real_T pooled5[4000];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Omega)
   * Referenced by:
   *   '<S35>/Constant2'
   *   '<S123>/2-D Lookup Table'
   *   '<S151>/2-D Lookup Table'
   */
  real_T pooled7[200];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Torque)
   * Referenced by:
   *   '<S35>/Constant3'
   *   '<S123>/2-D Lookup Table'
   *   '<S151>/2-D Lookup Table'
   */
  real_T pooled8[20];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.table_data )
   * Referenced by:
   *   '<S156>/2-D Lookup Table'
   *   '<S165>/2-D Lookup Table'
   *   '<S35>/2-D Lookup Table'
   */
  real_T pooled13[9246];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints1)
   * Referenced by:
   *   '<S156>/2-D Lookup Table'
   *   '<S165>/2-D Lookup Table'
   *   '<S35>/2-D Lookup Table'
   */
  real_T pooled14[201];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints2)
   * Referenced by:
   *   '<S156>/2-D Lookup Table'
   *   '<S165>/2-D Lookup Table'
   *   '<S35>/2-D Lookup Table'
   */
  real_T pooled15[46];

  /* Computed Parameter: LUT_3_tableData
   * Referenced by: '<S152>/LUT_-3'
   */
  real_T LUT_3_tableData[10000];

  /* Expression: TV.LUT.Yrd_LUT.LUT_vectors.delta_vector
   * Referenced by: '<S152>/LUT_-3'
   */
  real_T LUT_3_bp01Data[100];

  /* Expression: TV.LUT.Yrd_LUT.LUT_vectors.v_vector
   * Referenced by: '<S152>/LUT_-3'
   */
  real_T LUT_3_bp02Data[100];

  /* Expression: [0,1]
   * Referenced by: '<S175>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[2];

  /* Expression: [0,0, 4*TV.LV.TORQUE.T_peak_wheel]
   * Referenced by: '<S174>/T_peak_wheel_LUT'
   */
  real_T T_peak_wheel_LUT_tableData[3];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_LUT.SteerAngle_FL
   * Referenced by: '<S9>/steering_to_wheel_angles_LUT'
   */
  real_T steering_to_wheel_angles_LUT_ta[33];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S9>/steering_to_wheel_angle_single_axis_LUT'
   *   '<S9>/steering_to_wheel_angles_LUT'
   */
  real_T pooled33[33];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT.SteerAngle_SingleAxis
   * Referenced by: '<S9>/steering_to_wheel_angle_single_axis_LUT'
   */
  real_T steering_to_wheel_angle_single_[33];

  /* Pooled Parameter (Expression: [TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 0])
   * Referenced by:
   *   '<S153>/Max_Torque_Overload_Inverter_LUT'
   *   '<S153>/Max_Torque_Overload_Motor_LUT'
   *   '<S153>/Max_Torque_Temperature_External_LUT'
   *   '<S153>/Max_Torque_Temperature_IGBT_LUT'
   *   '<S153>/Max_Torque_Temperature_Internal_LUT'
   *   '<S154>/Display Overload Inverter LUT'
   *   '<S154>/Display Overload Motor LUT'
   *   '<S154>/Temperature External LUT'
   *   '<S154>/Temperature IGBT LUT'
   *   '<S154>/Temperature Internal LUT'
   */
  real_T pooled35[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S153>/Max_Torque_Overload_Inverter_LUT'
   *   '<S153>/Max_Torque_Overload_Motor_LUT'
   *   '<S154>/Display Overload Inverter LUT'
   *   '<S154>/Display Overload Motor LUT'
   */
  real_T pooled36[3];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_positive
   * Referenced by: '<S131>/2-D Lookup Table'
   */
  real_T uDLookupTable_tableData_h[900];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.Fz)
   * Referenced by:
   *   '<S131>/2-D Lookup Table'
   *   '<S131>/2-D Lookup Table1'
   */
  real_T pooled44[30];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.alpha)
   * Referenced by:
   *   '<S131>/2-D Lookup Table'
   *   '<S131>/2-D Lookup Table1'
   */
  real_T pooled45[30];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_negative
   * Referenced by: '<S131>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[900];

  /* Computed Parameter: LUT_3_maxIndex
   * Referenced by: '<S152>/LUT_-3'
   */
  uint32_T LUT_3_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S131>/2-D Lookup Table'
   *   '<S131>/2-D Lookup Table1'
   */
  uint32_T pooled58[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S123>/2-D Lookup Table'
   *   '<S151>/2-D Lookup Table'
   */
  uint32_T pooled59[2];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S109>/Logic'
   *   '<S133>/Logic'
   *   '<S134>/Logic'
   *   '<S135>/Logic'
   *   '<S136>/Logic'
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
 * Block '<S11>/Constant10' : Unused code path elimination
 * Block '<S11>/Constant11' : Unused code path elimination
 * Block '<S11>/Constant12' : Unused code path elimination
 * Block '<S11>/Constant13' : Unused code path elimination
 * Block '<S18>/VX_ref' : Unused code path elimination
 * Block '<S18>/VY_ref' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Propagation' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Data Type Propagation' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Propagation' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S118>/Data Type Propagation' : Unused code path elimination
 * Block '<S124>/NOT' : Unused code path elimination
 * Block '<S16>/Sum' : Unused code path elimination
 * Block '<S28>/r1' : Unused code path elimination
 * Block '<S28>/vx' : Unused code path elimination
 * Block '<S28>/vy' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Data Type Propagation' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S116>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S17>/Cast To Double8' : Eliminate redundant data type conversion
 * Block '<S153>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S153>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S153>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S153>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S153>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S164>/Saturation' : Eliminated Saturate block
 * Block '<S157>/K' : Eliminated nontunable gain of 1
 * Block '<S154>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S154>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S154>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S154>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S154>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S173>/Saturation' : Eliminated Saturate block
 * Block '<S166>/K' : Eliminated nontunable gain of 1
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
 * '<S11>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control'
 * '<S12>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/FL SR'
 * '<S13>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/FR SR'
 * '<S14>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/RL RR '
 * '<S15>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/RL SR'
 * '<S16>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC'
 * '<S17>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking'
 * '<S18>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output Vector Reference'
 * '<S19>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus '
 * '<S20>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ States'
 * '<S21>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control Constraints'
 * '<S22>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection'
 * '<S23>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation'
 * '<S24>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints'
 * '<S25>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix'
 * '<S26>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Slack variables Weights '
 * '<S27>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints'
 * '<S28>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation'
 * '<S29>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus /Bus p'
 * '<S30>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/MPC'
 * '<S31>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Overlap Chart'
 * '<S32>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque'
 * '<S33>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem'
 * '<S34>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino'
 * '<S35>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV'
 * '<S36>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/MATLAB Function'
 * '<S37>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/Saturation Dynamic'
 * '<S38>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem/Backup Map'
 * '<S39>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem/Selected Map'
 * '<S40>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino/Vectorino'
 * '<S41>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino/Vectorino/30//70'
 * '<S42>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Chart'
 * '<S43>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function1'
 * '<S44>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function2'
 * '<S45>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function3'
 * '<S46>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function4'
 * '<S47>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1'
 * '<S48>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Saturation Dynamic'
 * '<S49>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation'
 * '<S50>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup'
 * '<S51>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/D Gain'
 * '<S52>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter'
 * '<S53>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter ICs'
 * '<S54>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/I Gain'
 * '<S55>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain'
 * '<S56>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain Fdbk'
 * '<S57>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator'
 * '<S58>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator ICs'
 * '<S59>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Copy'
 * '<S60>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Gain'
 * '<S61>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/P Copy'
 * '<S62>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Parallel P Gain'
 * '<S63>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Reset Signal'
 * '<S64>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation'
 * '<S65>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation Fdbk'
 * '<S66>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum'
 * '<S67>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum Fdbk'
 * '<S68>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode'
 * '<S69>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode Sum'
 * '<S70>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Integral'
 * '<S71>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Ngain'
 * '<S72>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/b Gain'
 * '<S73>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/c Gain'
 * '<S74>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/postSat Signal'
 * '<S75>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/preSat Signal'
 * '<S76>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel'
 * '<S77>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S78>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S79>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S80>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/D Gain/External Parameters'
 * '<S81>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter/Disc. Forward Euler Filter'
 * '<S82>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter ICs/Internal IC - Filter'
 * '<S83>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/I Gain/External Parameters'
 * '<S84>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain/Passthrough'
 * '<S85>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain Fdbk/Disabled'
 * '<S86>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator/Discrete'
 * '<S87>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator ICs/Internal IC'
 * '<S88>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Copy/Disabled'
 * '<S89>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Gain/External Parameters'
 * '<S90>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/P Copy/Disabled'
 * '<S91>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Parallel P Gain/External Parameters'
 * '<S92>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Reset Signal/External Reset'
 * '<S93>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation/External'
 * '<S94>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation/External/Saturation Dynamic'
 * '<S95>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation Fdbk/Disabled'
 * '<S96>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum/Sum_PID'
 * '<S97>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum Fdbk/Disabled'
 * '<S98>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode/Enabled'
 * '<S99>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode Sum/Tracking Mode'
 * '<S100>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Integral/Passthrough'
 * '<S101>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Ngain/Passthrough'
 * '<S102>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/b Gain/External Parameters'
 * '<S103>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/c Gain/External Parameters'
 * '<S104>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/postSat Signal/Forward_Path'
 * '<S105>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/preSat Signal/Forward_Path'
 * '<S106>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/First Activation'
 * '<S107>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/If Action Subsystem'
 * '<S108>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/If Action Subsystem1'
 * '<S109>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/S-R Flip-Flop'
 * '<S110>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs'
 * '<S111>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver g'
 * '<S112>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Power Limits Negative'
 * '<S113>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Power Limits Positive'
 * '<S114>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem'
 * '<S115>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem1'
 * '<S116>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem2'
 * '<S117>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Accelerator Mapping '
 * '<S118>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Saturation Dynamic'
 * '<S119>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver g/Coasting'
 * '<S120>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem2/Distribution complete'
 * '<S121>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit'
 * '<S122>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/MATLAB Function'
 * '<S123>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit/Power to engines'
 * '<S124>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin'
 * '<S125>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Brake & ESP'
 * '<S126>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Bus lbx'
 * '<S127>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Bus ubx'
 * '<S128>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Cross Check'
 * '<S129>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Low YRD'
 * '<S130>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics'
 * '<S131>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds'
 * '<S132>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops'
 * '<S133>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop'
 * '<S134>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop1'
 * '<S135>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop2'
 * '<S136>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop3'
 * '<S137>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation'
 * '<S138>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation'
 * '<S139>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz FL'
 * '<S140>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz FR'
 * '<S141>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz RL'
 * '<S142>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz RR'
 * '<S143>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle FL'
 * '<S144>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle FR'
 * '<S145>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle RL'
 * '<S146>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle RR'
 * '<S147>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds/Hydraulic brakes'
 * '<S148>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds/LMUx Correction'
 * '<S149>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit'
 * '<S150>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/MATLAB Function'
 * '<S151>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit/Power to engines'
 * '<S152>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-2'
 * '<S153>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive'
 * '<S154>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen'
 * '<S155>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request'
 * '<S156>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve'
 * '<S157>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S158>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Saturation Dynamic'
 * '<S159>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S160>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S161>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S162>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S163>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S164>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S165>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve'
 * '<S166>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S167>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Saturation Dynamic'
 * '<S168>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S169>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S170>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S171>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S172>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S173>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S174>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Acceleration'
 * '<S175>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Braking'
 * '<S176>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Chart'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
