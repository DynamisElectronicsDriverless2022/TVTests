/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jun  7 23:37:14 2022
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
  dsp_simulink_MovingAverage obj;      /* '<S171>/Moving Average' */
  dsp_simulink_MovingAverage_l obj_l;  /* '<S277>/Moving Average' */
  zGeneral_Params General_Params;      /* '<S3>/Data Store_General_Params' */
  real_T CFunction[26];                /* '<S152>/C Function' */
  real_T Probe[2];                     /* '<S281>/Probe' */
  real_T Probe_b[2];                   /* '<S290>/Probe' */
  real_T CFunction_k[4];               /* '<S248>/C Function' */
  real_T CFunction_h[4];               /* '<S249>/C Function' */
  real_T T_max[4];                     /* '<S23>/Activation logic' */
  real_T T_min[4];                     /* '<S17>/Activation logic' */
  real_T UnitDelay_DSTATE[4];          /* '<S2>/Unit Delay' */
  real_T UD_DSTATE[4];                 /* '<S137>/UD' */
  real_T Integrator_DSTATE[4];         /* '<S62>/Integrator' */
  real_T DiscreteFIRFilter_states[4];  /* '<S156>/Discrete FIR Filter' */
  real_T UnitDelay_DSTATE_e[4];        /* '<S17>/Unit Delay' */
  real_T Integrator_DSTATE_f[4];       /* '<S119>/Integrator' */
  real_T UnitDelay_DSTATE_ep[4];       /* '<S23>/Unit Delay' */
  real_T UnitDelay1_DSTATE[4];         /* '<S11>/Unit Delay1' */
  real_T UnitDelay2_DSTATE[4];         /* '<S11>/Unit Delay2' */
  real_T Integrator_DSTATE_d[4];       /* '<S286>/Integrator' */
  real_T Integrator_DSTATE_i[4];       /* '<S295>/Integrator' */
  real_T UnitDelay_DSTATE_j[4];        /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<S139>/Memory' */
  real_T Integrator_DSTATE_b;          /* '<S208>/Integrator' */
  real_T Filter_DSTATE;                /* '<S203>/Filter' */
  real_T tr;                           /* '<S238>/Distribution complete' */
  real_T Rw;                           /* '<S238>/Distribution complete' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S156>/Discrete FIR Filter' */
  int8_T Integrator_PrevResetState;    /* '<S62>/Integrator' */
  int8_T Integrator_PrevResetState_g;  /* '<S119>/Integrator' */
  int8_T Integrator_PrevResetState_i;  /* '<S286>/Integrator' */
  int8_T Integrator_PrevResetState_b;  /* '<S295>/Integrator' */
  int8_T Integrator_PrevResetState_j;  /* '<S208>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S203>/Filter' */
  uint8_T Integrator_IC_LOADING;       /* '<S286>/Integrator' */
  uint8_T Integrator_IC_LOADING_b;     /* '<S295>/Integrator' */
  uint8_T is_active_c21_TVModel;       /* '<S277>/T_Req_Chart' */
  uint8_T is_c21_TVModel;              /* '<S277>/T_Req_Chart' */
  uint8_T is_active_c13_TVModel;       /* '<S145>/Overlap Chart' */
  uint8_T is_c13_TVModel;              /* '<S145>/Overlap Chart' */
  uint8_T is_active_c38_TVModel;       /* '<S23>/Activation logic' */
  uint8_T is_c38_TVModel;              /* '<S23>/Activation logic' */
  uint8_T is_TS_ON;                    /* '<S23>/Activation logic' */
  uint8_T is_FL;                       /* '<S23>/Activation logic' */
  uint8_T is_FR;                       /* '<S23>/Activation logic' */
  uint8_T is_RL;                       /* '<S23>/Activation logic' */
  uint8_T is_RR;                       /* '<S23>/Activation logic' */
  uint8_T is_active_c36_TVModel;       /* '<S17>/Activation logic' */
  uint8_T is_c36_TVModel;              /* '<S17>/Activation logic' */
  uint8_T is_TS_ON_j;                  /* '<S17>/Activation logic' */
  uint8_T is_FL_g;                     /* '<S17>/Activation logic' */
  uint8_T is_FR_i;                     /* '<S17>/Activation logic' */
  uint8_T is_RL_c;                     /* '<S17>/Activation logic' */
  uint8_T is_RR_k;                     /* '<S17>/Activation logic' */
  boolean_T Delay_DSTATE[5];           /* '<S171>/Delay' */
  boolean_T Relay1_Mode;               /* '<S80>/Relay1' */
  boolean_T Relay1_Mode_k;             /* '<S81>/Relay1' */
  boolean_T Memory_PreviousInput_i;    /* '<S255>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S256>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S257>/Memory' */
  boolean_T Memory_PreviousInput_ib;   /* '<S258>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S231>/Memory' */
  boolean_T IC1_FirstOutputTime;       /* '<S150>/IC1' */
  boolean_T IC_FirstOutputTime;        /* '<S150>/IC' */
  boolean_T IC_FirstOutputTime_e;      /* '<S234>/IC' */
  boolean_T IC1_FirstOutputTime_m;     /* '<S235>/IC1' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: TV.LV.GENERAL
   * Referenced by: '<S3>/Data Store_General_Params'
   */
  zGeneral_Params DataStore_General_Params_Initia;

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Eta)
   * Referenced by:
   *   '<S158>/Constant1'
   *   '<S245>/2-D Lookup Table'
   *   '<S273>/2-D Lookup Table'
   */
  real_T pooled5[4000];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Omega)
   * Referenced by:
   *   '<S158>/Constant2'
   *   '<S245>/2-D Lookup Table'
   *   '<S273>/2-D Lookup Table'
   */
  real_T pooled7[200];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Torque)
   * Referenced by:
   *   '<S158>/Constant3'
   *   '<S245>/2-D Lookup Table'
   *   '<S273>/2-D Lookup Table'
   */
  real_T pooled8[20];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.table_data )
   * Referenced by:
   *   '<S278>/2-D Lookup Table'
   *   '<S287>/2-D Lookup Table'
   *   '<S158>/2-D Lookup Table'
   */
  real_T pooled13[9246];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints1)
   * Referenced by:
   *   '<S278>/2-D Lookup Table'
   *   '<S287>/2-D Lookup Table'
   *   '<S158>/2-D Lookup Table'
   */
  real_T pooled14[201];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints2)
   * Referenced by:
   *   '<S278>/2-D Lookup Table'
   *   '<S287>/2-D Lookup Table'
   *   '<S158>/2-D Lookup Table'
   */
  real_T pooled15[46];

  /* Expression: [0,1]
   * Referenced by: '<S297>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[2];

  /* Expression: [0,0, 4*TV.LV.TORQUE.T_peak_wheel]
   * Referenced by: '<S296>/T_peak_wheel_LUT'
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
  real_T pooled37[33];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT.SteerAngle_SingleAxis
   * Referenced by: '<S9>/steering_to_wheel_angle_single_axis_LUT'
   */
  real_T steering_to_wheel_angle_single_[33];

  /* Pooled Parameter (Expression: [TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 0])
   * Referenced by:
   *   '<S275>/Max_Torque_Overload_Inverter_LUT'
   *   '<S275>/Max_Torque_Overload_Motor_LUT'
   *   '<S275>/Max_Torque_Temperature_External_LUT'
   *   '<S275>/Max_Torque_Temperature_IGBT_LUT'
   *   '<S275>/Max_Torque_Temperature_Internal_LUT'
   *   '<S276>/Display Overload Inverter LUT'
   *   '<S276>/Display Overload Motor LUT'
   *   '<S276>/Temperature External LUT'
   *   '<S276>/Temperature IGBT LUT'
   *   '<S276>/Temperature Internal LUT'
   */
  real_T pooled45[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S275>/Max_Torque_Overload_Inverter_LUT'
   *   '<S275>/Max_Torque_Overload_Motor_LUT'
   *   '<S276>/Display Overload Inverter LUT'
   *   '<S276>/Display Overload Motor LUT'
   */
  real_T pooled46[3];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_positive
   * Referenced by: '<S253>/2-D Lookup Table'
   */
  real_T uDLookupTable_tableData_m[900];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.Fz)
   * Referenced by:
   *   '<S253>/2-D Lookup Table'
   *   '<S253>/2-D Lookup Table1'
   */
  real_T pooled53[30];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.alpha)
   * Referenced by:
   *   '<S253>/2-D Lookup Table'
   *   '<S253>/2-D Lookup Table1'
   */
  real_T pooled54[30];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_negative
   * Referenced by: '<S253>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[900];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S253>/2-D Lookup Table'
   *   '<S253>/2-D Lookup Table1'
   */
  uint32_T pooled66[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S245>/2-D Lookup Table'
   *   '<S273>/2-D Lookup Table'
   */
  uint32_T pooled67[2];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S231>/Logic'
   *   '<S255>/Logic'
   *   '<S256>/Logic'
   *   '<S257>/Logic'
   *   '<S258>/Logic'
   */
  boolean_T pooled69[16];
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
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Propagation' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Propagation' : Unused code path elimination
 * Block '<S137>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Propagation' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S216>/Data Type Propagation' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Propagation' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate' : Unused code path elimination
 * Block '<S240>/Data Type Propagation' : Unused code path elimination
 * Block '<S246>/NOT' : Unused code path elimination
 * Block '<S139>/Sum' : Unused code path elimination
 * Block '<S140>/Cast To Double7' : Unused code path elimination
 * Block '<S280>/Data Type Duplicate' : Unused code path elimination
 * Block '<S280>/Data Type Propagation' : Unused code path elimination
 * Block '<S289>/Data Type Duplicate' : Unused code path elimination
 * Block '<S289>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S275>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S275>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S275>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S275>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S275>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S286>/Saturation' : Eliminated Saturate block
 * Block '<S279>/K' : Eliminated nontunable gain of 1
 * Block '<S276>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S295>/Saturation' : Eliminated Saturate block
 * Block '<S288>/K' : Eliminated nontunable gain of 1
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
 * '<S16>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control'
 * '<S17>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS'
 * '<S18>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/Reset ABS'
 * '<S19>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/Reset TC'
 * '<S20>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/Saturation Dynamic'
 * '<S21>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/Saturation Dynamic1'
 * '<S22>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/Slip computation'
 * '<S23>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC'
 * '<S24>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/epsTarget computation'
 * '<S25>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/slip ratio'
 * '<S26>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/Activation logic'
 * '<S27>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5'
 * '<S28>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Anti-windup'
 * '<S29>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/D Gain'
 * '<S30>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Filter'
 * '<S31>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Filter ICs'
 * '<S32>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/I Gain'
 * '<S33>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Ideal P Gain'
 * '<S34>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Ideal P Gain Fdbk'
 * '<S35>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Integrator'
 * '<S36>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Integrator ICs'
 * '<S37>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/N Copy'
 * '<S38>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/N Gain'
 * '<S39>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/P Copy'
 * '<S40>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Parallel P Gain'
 * '<S41>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Reset Signal'
 * '<S42>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Saturation'
 * '<S43>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Saturation Fdbk'
 * '<S44>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Sum'
 * '<S45>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Sum Fdbk'
 * '<S46>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Tracking Mode'
 * '<S47>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Tracking Mode Sum'
 * '<S48>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Tsamp - Integral'
 * '<S49>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Tsamp - Ngain'
 * '<S50>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/postSat Signal'
 * '<S51>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/preSat Signal'
 * '<S52>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Anti-windup/Disc. Clamping Parallel'
 * '<S53>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S54>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S55>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S56>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/D Gain/Disabled'
 * '<S57>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Filter/Disabled'
 * '<S58>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Filter ICs/Disabled'
 * '<S59>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/I Gain/External Parameters'
 * '<S60>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Ideal P Gain/Passthrough'
 * '<S61>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Ideal P Gain Fdbk/Disabled'
 * '<S62>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Integrator/Discrete'
 * '<S63>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Integrator ICs/Internal IC'
 * '<S64>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/N Copy/Disabled wSignal Specification'
 * '<S65>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/N Gain/Disabled'
 * '<S66>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/P Copy/Disabled'
 * '<S67>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Parallel P Gain/External Parameters'
 * '<S68>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Reset Signal/External Reset'
 * '<S69>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Saturation/External'
 * '<S70>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Saturation/External/Saturation Dynamic'
 * '<S71>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Saturation Fdbk/Disabled'
 * '<S72>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Sum/Sum_PI'
 * '<S73>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Sum Fdbk/Disabled'
 * '<S74>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Tracking Mode/Enabled'
 * '<S75>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Tracking Mode Sum/Tracking Mode'
 * '<S76>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Tsamp - Integral/Passthrough'
 * '<S77>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/Tsamp - Ngain/Passthrough'
 * '<S78>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/postSat Signal/Forward_Path'
 * '<S79>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/ABS/PID Controller5/preSat Signal/Forward_Path'
 * '<S80>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/Reset TC/Subsystem'
 * '<S81>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/Reset TC/Subsystem1'
 * '<S82>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/Slip computation/MATLAB Function2'
 * '<S83>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/Activation logic'
 * '<S84>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5'
 * '<S85>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Anti-windup'
 * '<S86>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/D Gain'
 * '<S87>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Filter'
 * '<S88>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Filter ICs'
 * '<S89>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/I Gain'
 * '<S90>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Ideal P Gain'
 * '<S91>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Ideal P Gain Fdbk'
 * '<S92>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Integrator'
 * '<S93>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Integrator ICs'
 * '<S94>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/N Copy'
 * '<S95>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/N Gain'
 * '<S96>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/P Copy'
 * '<S97>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Parallel P Gain'
 * '<S98>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Reset Signal'
 * '<S99>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Saturation'
 * '<S100>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Saturation Fdbk'
 * '<S101>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Sum'
 * '<S102>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Sum Fdbk'
 * '<S103>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Tracking Mode'
 * '<S104>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Tracking Mode Sum'
 * '<S105>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Tsamp - Integral'
 * '<S106>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Tsamp - Ngain'
 * '<S107>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/postSat Signal'
 * '<S108>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/preSat Signal'
 * '<S109>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Anti-windup/Disc. Clamping Parallel'
 * '<S110>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S111>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S112>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S113>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/D Gain/Disabled'
 * '<S114>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Filter/Disabled'
 * '<S115>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Filter ICs/Disabled'
 * '<S116>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/I Gain/External Parameters'
 * '<S117>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Ideal P Gain/Passthrough'
 * '<S118>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Ideal P Gain Fdbk/Disabled'
 * '<S119>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Integrator/Discrete'
 * '<S120>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Integrator ICs/Internal IC'
 * '<S121>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/N Copy/Disabled wSignal Specification'
 * '<S122>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/N Gain/Disabled'
 * '<S123>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/P Copy/Disabled'
 * '<S124>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Parallel P Gain/External Parameters'
 * '<S125>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Reset Signal/External Reset'
 * '<S126>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Saturation/External'
 * '<S127>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Saturation/External/Saturation Dynamic'
 * '<S128>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Saturation Fdbk/Disabled'
 * '<S129>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Sum/Sum_PI'
 * '<S130>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Sum Fdbk/Disabled'
 * '<S131>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Tracking Mode/Enabled'
 * '<S132>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Tracking Mode Sum/Tracking Mode'
 * '<S133>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Tsamp - Integral/Passthrough'
 * '<S134>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/Tsamp - Ngain/Passthrough'
 * '<S135>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/postSat Signal/Forward_Path'
 * '<S136>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/TC/PID Controller5/preSat Signal/Forward_Path'
 * '<S137>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/slip ratio/Discrete Derivative'
 * '<S138>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Slip Control/slip ratio/MATLAB Function'
 * '<S139>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC'
 * '<S140>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking'
 * '<S141>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output Vector Reference'
 * '<S142>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus '
 * '<S143>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ States'
 * '<S144>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control Constraints'
 * '<S145>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection'
 * '<S146>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation'
 * '<S147>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints'
 * '<S148>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix'
 * '<S149>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Slack variables Weights '
 * '<S150>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints'
 * '<S151>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation'
 * '<S152>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus /Bus p'
 * '<S153>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/MPC'
 * '<S154>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Overlap Chart'
 * '<S155>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque'
 * '<S156>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem'
 * '<S157>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino'
 * '<S158>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV'
 * '<S159>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/MATLAB Function'
 * '<S160>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/Saturation Dynamic'
 * '<S161>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem/Backup Map'
 * '<S162>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem/Selected Map'
 * '<S163>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino/Vectorino'
 * '<S164>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino/Vectorino/30//70'
 * '<S165>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function1'
 * '<S166>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function2'
 * '<S167>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function3'
 * '<S168>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function4'
 * '<S169>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1'
 * '<S170>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Saturation Dynamic'
 * '<S171>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation'
 * '<S172>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup'
 * '<S173>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/D Gain'
 * '<S174>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter'
 * '<S175>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter ICs'
 * '<S176>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/I Gain'
 * '<S177>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain'
 * '<S178>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain Fdbk'
 * '<S179>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator'
 * '<S180>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator ICs'
 * '<S181>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Copy'
 * '<S182>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Gain'
 * '<S183>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/P Copy'
 * '<S184>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Parallel P Gain'
 * '<S185>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Reset Signal'
 * '<S186>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation'
 * '<S187>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation Fdbk'
 * '<S188>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum'
 * '<S189>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum Fdbk'
 * '<S190>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode'
 * '<S191>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode Sum'
 * '<S192>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Integral'
 * '<S193>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Ngain'
 * '<S194>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/b Gain'
 * '<S195>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/c Gain'
 * '<S196>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/postSat Signal'
 * '<S197>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/preSat Signal'
 * '<S198>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel'
 * '<S199>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S200>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S201>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S202>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/D Gain/External Parameters'
 * '<S203>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter/Disc. Forward Euler Filter'
 * '<S204>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter ICs/Internal IC - Filter'
 * '<S205>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/I Gain/External Parameters'
 * '<S206>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain/Passthrough'
 * '<S207>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain Fdbk/Disabled'
 * '<S208>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator/Discrete'
 * '<S209>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator ICs/Internal IC'
 * '<S210>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Copy/Disabled'
 * '<S211>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Gain/External Parameters'
 * '<S212>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/P Copy/Disabled'
 * '<S213>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Parallel P Gain/External Parameters'
 * '<S214>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Reset Signal/External Reset'
 * '<S215>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation/External'
 * '<S216>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation/External/Saturation Dynamic'
 * '<S217>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation Fdbk/Disabled'
 * '<S218>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum/Sum_PID'
 * '<S219>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum Fdbk/Disabled'
 * '<S220>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode/Enabled'
 * '<S221>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode Sum/Tracking Mode'
 * '<S222>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Integral/Passthrough'
 * '<S223>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Ngain/Passthrough'
 * '<S224>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/b Gain/External Parameters'
 * '<S225>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/c Gain/External Parameters'
 * '<S226>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/postSat Signal/Forward_Path'
 * '<S227>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/preSat Signal/Forward_Path'
 * '<S228>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/First Activation'
 * '<S229>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/If Action Subsystem'
 * '<S230>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/If Action Subsystem1'
 * '<S231>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/S-R Flip-Flop'
 * '<S232>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs'
 * '<S233>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver g'
 * '<S234>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Power Limits Negative'
 * '<S235>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Power Limits Positive'
 * '<S236>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem'
 * '<S237>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem1'
 * '<S238>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem2'
 * '<S239>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Accelerator Mapping '
 * '<S240>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Saturation Dynamic'
 * '<S241>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver g/Coasting'
 * '<S242>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem2/Distribution complete'
 * '<S243>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit'
 * '<S244>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/MATLAB Function'
 * '<S245>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit/Power to engines'
 * '<S246>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin'
 * '<S247>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Brake & ESP'
 * '<S248>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Bus lbx'
 * '<S249>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Bus ubx'
 * '<S250>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Cross Check'
 * '<S251>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Low YRD'
 * '<S252>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics'
 * '<S253>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds'
 * '<S254>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops'
 * '<S255>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop'
 * '<S256>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop1'
 * '<S257>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop2'
 * '<S258>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop3'
 * '<S259>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation'
 * '<S260>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation'
 * '<S261>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz FL'
 * '<S262>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz FR'
 * '<S263>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz RL'
 * '<S264>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz RR'
 * '<S265>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle FL'
 * '<S266>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle FR'
 * '<S267>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle RL'
 * '<S268>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle RR'
 * '<S269>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds/Hydraulic brakes'
 * '<S270>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds/LMUx Correction'
 * '<S271>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit'
 * '<S272>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/MATLAB Function'
 * '<S273>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit/Power to engines'
 * '<S274>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/MATLAB Function1'
 * '<S275>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive'
 * '<S276>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen'
 * '<S277>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request'
 * '<S278>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve'
 * '<S279>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S280>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Saturation Dynamic'
 * '<S281>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S282>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S283>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S284>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S285>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S286>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S287>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve'
 * '<S288>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S289>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Saturation Dynamic'
 * '<S290>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S291>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S292>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S293>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S294>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S295>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S296>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Acceleration'
 * '<S297>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Braking'
 * '<S298>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Chart'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
