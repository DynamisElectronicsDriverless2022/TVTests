/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon May 16 11:16:29 2022
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
#include "ITB_Nucleo_configuration\Inc\acados_wrapper.h"
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
  dsp_simulink_MovingAverage obj;      /* '<S52>/Moving Average' */
  dsp_simulink_MovingAverage_l obj_n;  /* '<S75>/Moving Average' */
  zGeneral_Params General_Params;      /* '<S3>/Data Store_General_Params' */
  real_T CFunction[26];                /* '<S28>/C Function' */
  real_T CFunction_c[4];               /* '<S31>/C Function' */
  real_T CFunction_ch[4];              /* '<S32>/C Function' */
  real_T UnitDelay_DSTATE[4];          /* '<S2>/Unit Delay' */
  real_T DiscreteFIRFilter_states[4];  /* '<S48>/Discrete FIR Filter' */
  real_T UnitDelay_DSTATE_j[4];        /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<S16>/Memory' */
  real_T yaw_rate_desired_LUT;         /* '<S17>/Merge_LUT_results' */
  real_T yaw_rate_desired_LUT_f;       /* '<S17>/Merge_LUT_results1' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S43>/Discrete FIR Filter' */
  int32_T DiscreteFIRFilter_circBuf_j; /* '<S48>/Discrete FIR Filter' */
  int16_T DiscreteFIRFilter_states_e[9];/* '<S43>/Discrete FIR Filter' */
  uint8_T is_active_c19_TVModel;       /* '<S75>/T_Req_Chart' */
  uint8_T is_c19_TVModel;              /* '<S75>/T_Req_Chart' */
  boolean_T Delay_DSTATE[5];           /* '<S52>/Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S53>/Unit Delay1' */
  boolean_T IC_FirstOutputTime;        /* '<S24>/IC' */
  boolean_T Memory_PreviousInput_i;    /* '<S56>/Memory' */
  boolean_T IC1_FirstOutputTime;       /* '<S24>/IC1' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: TV.LV.GENERAL
   * Referenced by: '<S3>/Data Store_General_Params'
   */
  zGeneral_Params DataStore_General_Params_Initia;

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_1.ay_matrix))
   * Referenced by:
   *   '<S70>/LUT_1'
   *   '<S72>/LUT_1'
   */
  real_T pooled6[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_0.ay_matrix))
   * Referenced by:
   *   '<S69>/LUT_0'
   *   '<S71>/LUT_0'
   */
  real_T pooled7[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_neg1_5.ay_matrix))
   * Referenced by:
   *   '<S66>/LUT_-1.5'
   *   '<S67>/LUT_-1.5'
   */
  real_T pooled8[10000];

  /* Pooled Parameter (Expression: single(TV.LUT.Yrd_LUT.LUT_neg3.ay_matrix))
   * Referenced by:
   *   '<S65>/LUT_-3'
   *   '<S68>/LUT_-3'
   */
  real_T pooled10[10000];

  /* Pooled Parameter (Expression: TV.LUT.Yrd_LUT.LUT_vectors.delta_vector)
   * Referenced by:
   *   '<S65>/LUT_-3'
   *   '<S66>/LUT_-1.5'
   *   '<S67>/LUT_-1.5'
   *   '<S68>/LUT_-3'
   *   '<S69>/LUT_0'
   *   '<S70>/LUT_1'
   *   '<S71>/LUT_0'
   *   '<S72>/LUT_1'
   */
  real_T pooled11[100];

  /* Pooled Parameter (Expression: TV.LUT.Yrd_LUT.LUT_vectors.v_vector)
   * Referenced by:
   *   '<S65>/LUT_-3'
   *   '<S66>/LUT_-1.5'
   *   '<S67>/LUT_-1.5'
   *   '<S68>/LUT_-3'
   *   '<S69>/LUT_0'
   *   '<S70>/LUT_1'
   *   '<S71>/LUT_0'
   *   '<S72>/LUT_1'
   */
  real_T pooled12[100];

  /* Expression: [0,1]
   * Referenced by: '<S88>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[2];

  /* Expression: [0,0, 4*TV.LV.TORQUE.T_peak_wheel]
   * Referenced by: '<S87>/T_peak_wheel_LUT'
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
  real_T pooled17[33];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT.SteerAngle_SingleAxis
   * Referenced by: '<S9>/steering_to_wheel_angle_single_axis_LUT'
   */
  real_T steering_to_wheel_angle_single_[33];

  /* Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fx_target_positive
   * Referenced by: '<S22>/2-D Lookup Table'
   */
  real_T uDLookupTable_tableData_l[400];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fz)
   * Referenced by:
   *   '<S22>/2-D Lookup Table'
   *   '<S22>/2-D Lookup Table1'
   */
  real_T pooled28[20];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_0_10.alpha)
   * Referenced by:
   *   '<S22>/2-D Lookup Table'
   *   '<S22>/2-D Lookup Table1'
   */
  real_T pooled29[20];

  /* Expression: TV.LUT.MPC_Lut.control_bound_0_10.Fx_target_negative
   * Referenced by: '<S22>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[400];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Eta)
   * Referenced by:
   *   '<S59>/2-D Lookup Table'
   *   '<S63>/2-D Lookup Table'
   */
  real_T pooled38[4000];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Omega)
   * Referenced by:
   *   '<S59>/2-D Lookup Table'
   *   '<S63>/2-D Lookup Table'
   */
  real_T pooled39[200];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Torque)
   * Referenced by:
   *   '<S59>/2-D Lookup Table'
   *   '<S63>/2-D Lookup Table'
   */
  real_T pooled40[20];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S65>/LUT_-3'
   *   '<S66>/LUT_-1.5'
   *   '<S67>/LUT_-1.5'
   *   '<S68>/LUT_-3'
   *   '<S69>/LUT_0'
   *   '<S70>/LUT_1'
   *   '<S71>/LUT_0'
   *   '<S72>/LUT_1'
   */
  uint32_T pooled43[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S22>/2-D Lookup Table'
   *   '<S22>/2-D Lookup Table1'
   */
  uint32_T pooled44[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/2-D Lookup Table'
   *   '<S63>/2-D Lookup Table'
   */
  uint32_T pooled45[2];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S56>/Logic'
   */
  boolean_T Logic_table[16];
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
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/Constant10' : Unused code path elimination
 * Block '<S2>/Constant11' : Unused code path elimination
 * Block '<S2>/Constant12' : Unused code path elimination
 * Block '<S2>/Constant13' : Unused code path elimination
 * Block '<S2>/Constant14' : Unused code path elimination
 * Block '<S2>/Constant15' : Unused code path elimination
 * Block '<S2>/Constant7' : Unused code path elimination
 * Block '<S11>/Constant3' : Unused code path elimination
 * Block '<S22>/Unary Minus' : Unused code path elimination
 * Block '<S16>/Sum' : Unused code path elimination
 * Block '<S60>/      ' : Unused code path elimination
 * Block '<S60>/Switch3' : Unused code path elimination
 * Block '<S73>/Cast_0' : Unused code path elimination
 * Block '<S73>/Cast_1' : Unused code path elimination
 * Block '<S73>/Cast_2' : Unused code path elimination
 * Block '<S73>/Cast_3' : Unused code path elimination
 * Block '<S73>/Cast_4' : Unused code path elimination
 * Block '<S73>/Constant' : Unused code path elimination
 * Block '<S73>/Constant1' : Unused code path elimination
 * Block '<S73>/Constant2' : Unused code path elimination
 * Block '<S73>/Constant3' : Unused code path elimination
 * Block '<S73>/Constant4' : Unused code path elimination
 * Block '<S73>/Constant5' : Unused code path elimination
 * Block '<S73>/Constant6' : Unused code path elimination
 * Block '<S73>/Constant7' : Unused code path elimination
 * Block '<S73>/Max_Torque_Overload_Inverter_LUT' : Unused code path elimination
 * Block '<S73>/Max_Torque_Overload_Motor_LUT' : Unused code path elimination
 * Block '<S73>/Max_Torque_Temperature_External_LUT' : Unused code path elimination
 * Block '<S73>/Max_Torque_Temperature_IGBT_LUT' : Unused code path elimination
 * Block '<S73>/Max_Torque_Temperature_Internal_LUT' : Unused code path elimination
 * Block '<S73>/Min' : Unused code path elimination
 * Block '<S73>/Saturation_Positive' : Unused code path elimination
 * Block '<S76>/2-D Lookup Table' : Unused code path elimination
 * Block '<S76>/Constant' : Unused code path elimination
 * Block '<S76>/Constant1' : Unused code path elimination
 * Block '<S76>/Constant2' : Unused code path elimination
 * Block '<S76>/Gain' : Unused code path elimination
 * Block '<S76>/Gain4' : Unused code path elimination
 * Block '<S77>/1//T' : Unused code path elimination
 * Block '<S79>/Avoid Divide by Zero' : Unused code path elimination
 * Block '<S82>/Compare' : Unused code path elimination
 * Block '<S82>/Constant' : Unused code path elimination
 * Block '<S79>/Max' : Unused code path elimination
 * Block '<S79>/Probe' : Unused code path elimination
 * Block '<S79>/Sum1' : Unused code path elimination
 * Block '<S79>/Time constant' : Unused code path elimination
 * Block '<S84>/Integrator' : Unused code path elimination
 * Block '<S84>/Saturation' : Unused code path elimination
 * Block '<S77>/K' : Unused code path elimination
 * Block '<S77>/Sum1' : Unused code path elimination
 * Block '<S76>/Multiport Switch' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Propagation' : Unused code path elimination
 * Block '<S78>/LowerRelop1' : Unused code path elimination
 * Block '<S78>/Switch' : Unused code path elimination
 * Block '<S78>/Switch2' : Unused code path elimination
 * Block '<S78>/UpperRelop' : Unused code path elimination
 * Block '<S76>/Saturation1' : Unused code path elimination
 * Block '<S74>/Cast_0' : Unused code path elimination
 * Block '<S74>/Cast_1' : Unused code path elimination
 * Block '<S74>/Cast_2' : Unused code path elimination
 * Block '<S74>/Cast_3' : Unused code path elimination
 * Block '<S74>/Cast_4' : Unused code path elimination
 * Block '<S74>/Constant' : Unused code path elimination
 * Block '<S74>/Constant1' : Unused code path elimination
 * Block '<S74>/Constant2' : Unused code path elimination
 * Block '<S74>/Constant3' : Unused code path elimination
 * Block '<S74>/Constant4' : Unused code path elimination
 * Block '<S74>/Constant5' : Unused code path elimination
 * Block '<S74>/Constant6' : Unused code path elimination
 * Block '<S74>/Constant7' : Unused code path elimination
 * Block '<S74>/Display Overload Inverter LUT' : Unused code path elimination
 * Block '<S74>/Display Overload Motor LUT' : Unused code path elimination
 * Block '<S74>/Min1' : Unused code path elimination
 * Block '<S74>/Saturation_Positive' : Unused code path elimination
 * Block '<S74>/Temperature External LUT' : Unused code path elimination
 * Block '<S74>/Temperature IGBT LUT' : Unused code path elimination
 * Block '<S74>/Temperature Internal LUT' : Unused code path elimination
 * Block '<S85>/1-D Lookup Table' : Unused code path elimination
 * Block '<S85>/2-D Lookup Table1' : Unused code path elimination
 * Block '<S85>/Constant' : Unused code path elimination
 * Block '<S85>/Constant1' : Unused code path elimination
 * Block '<S85>/Constant2' : Unused code path elimination
 * Block '<S85>/Gain' : Unused code path elimination
 * Block '<S85>/Gain4' : Unused code path elimination
 * Block '<S85>/Min' : Unused code path elimination
 * Block '<S85>/Multiport Switch' : Unused code path elimination
 * Block '<S85>/Rate Limiter' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Propagation' : Unused code path elimination
 * Block '<S86>/LowerRelop1' : Unused code path elimination
 * Block '<S86>/Switch' : Unused code path elimination
 * Block '<S86>/Switch2' : Unused code path elimination
 * Block '<S86>/UpperRelop' : Unused code path elimination
 * Block '<S85>/Saturation1' : Unused code path elimination
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
 * Block '<S17>/Cast To Double' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double1' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double2' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double3' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double4' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double5' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double6' : Eliminate redundant data type conversion
 * Block '<S17>/Cast To Double7' : Eliminate redundant data type conversion
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
 * '<S11>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction_PID'
 * '<S12>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/FL SR'
 * '<S13>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/FR SR'
 * '<S14>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/RL RR '
 * '<S15>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Slip Ratios/RL SR'
 * '<S16>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC'
 * '<S17>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking'
 * '<S18>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output vector reference'
 * '<S19>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus '
 * '<S20>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ States'
 * '<S21>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control Constraints'
 * '<S22>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints'
 * '<S23>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults detection'
 * '<S24>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints'
 * '<S25>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix'
 * '<S26>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Selector'
 * '<S27>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation'
 * '<S28>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus /Bus p'
 * '<S29>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Anti reverse wheelspin'
 * '<S30>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Brake & ESP'
 * '<S31>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Bus lbu'
 * '<S32>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Bus ubu'
 * '<S33>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Cross Check'
 * '<S34>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Hydraulic brakes'
 * '<S35>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/LMUx Correction'
 * '<S36>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation'
 * '<S37>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Low YRD'
 * '<S38>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation'
 * '<S39>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation/Fz FL'
 * '<S40>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation/Fz FR'
 * '<S41>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation/Fz RL'
 * '<S42>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Load Transfer calculation/Fz RR'
 * '<S43>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Low YRD/Mz = 0 Bound logic'
 * '<S44>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation/Slip Angle FL'
 * '<S45>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation/Slip Angle FR'
 * '<S46>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation/Slip Angle RL'
 * '<S47>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control constraints/Slip Angle calculation/Slip Angle RR'
 * '<S48>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults detection/Subsystem2'
 * '<S49>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Accelerator mapping '
 * '<S50>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Coasting'
 * '<S51>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Mz Saturation'
 * '<S52>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Mz Saturation/Steer Activation'
 * '<S53>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Mz Saturation/Steer Activation/First Activation'
 * '<S54>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Mz Saturation/Steer Activation/If Action Subsystem'
 * '<S55>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Mz Saturation/Steer Activation/If Action Subsystem1'
 * '<S56>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Mz Saturation/Steer Activation/S-R Flip-Flop'
 * '<S57>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit'
 * '<S58>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/MATLAB Function'
 * '<S59>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit/Power to engines'
 * '<S60>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/Efficiency limit'
 * '<S61>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/MATLAB Function'
 * '<S62>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/Efficiency limit/MATLAB Function'
 * '<S63>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights generation/Efficiency limit/Power to engines'
 * '<S64>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/MATLAB Function'
 * '<S65>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-1'
 * '<S66>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-1.1'
 * '<S67>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-1.5'
 * '<S68>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-3'
 * '<S69>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_0'
 * '<S70>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_1'
 * '<S71>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_2'
 * '<S72>'  : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_3'
 * '<S73>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive'
 * '<S74>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen'
 * '<S75>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request'
 * '<S76>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve'
 * '<S77>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S78>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Saturation Dynamic'
 * '<S79>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S80>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S81>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S82>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S83>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S84>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S85>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque Curve'
 * '<S86>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque Curve/Saturation Dynamic'
 * '<S87>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Acceleration'
 * '<S88>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Braking'
 * '<S89>'  : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Chart'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
