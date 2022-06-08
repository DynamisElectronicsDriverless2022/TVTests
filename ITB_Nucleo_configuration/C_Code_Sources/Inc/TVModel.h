/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jun  8 13:17:33 2022
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
  dsp_simulink_MovingAverage obj;      /* '<S172>/Moving Average' */
  dsp_simulink_MovingAverage_l obj_m;  /* '<S278>/Moving Average' */
  zGeneral_Params General_Params;      /* '<S3>/Data Store_General_Params' */
  real_T CFunction[26];                /* '<S152>/C Function' */
  real_T Probe[2];                     /* '<S282>/Probe' */
  real_T Probe_k[2];                   /* '<S291>/Probe' */
  real_T CFunction_p[4];               /* '<S249>/C Function' */
  real_T CFunction_f[4];               /* '<S250>/C Function' */
  real_T T_max[4];                     /* '<S23>/Activation logic' */
  real_T T_min[4];                     /* '<S17>/Activation logic' */
  real_T UnitDelay_DSTATE[4];          /* '<S2>/Unit Delay' */
  real_T UD_DSTATE[4];                 /* '<S137>/UD' */
  real_T Integrator_DSTATE[4];         /* '<S62>/Integrator' */
  real_T Integrator_DSTATE_m[4];       /* '<S287>/Integrator' */
  real_T UnitDelay1_DSTATE[4];         /* '<S11>/Unit Delay1' */
  real_T Integrator_DSTATE_f[4];       /* '<S296>/Integrator' */
  real_T UnitDelay2_DSTATE[4];         /* '<S11>/Unit Delay2' */
  real_T UnitDelay_DSTATE_e[4];        /* '<S17>/Unit Delay' */
  real_T Integrator_DSTATE_a[4];       /* '<S119>/Integrator' */
  real_T UnitDelay_DSTATE_d[4];        /* '<S23>/Unit Delay' */
  real_T UnitDelay_DSTATE_j[4];        /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<S139>/Memory' */
  real_T mz_output;                    /* '<S146>/Chart' */
  real_T Integrator_DSTATE_n;          /* '<S209>/Integrator' */
  real_T Filter_DSTATE;                /* '<S204>/Filter' */
  real_T tr;                           /* '<S239>/Distribution complete' */
  real_T Rw;                           /* '<S239>/Distribution complete' */
  int32_T DiscreteFIRFilter_states[4]; /* '<S156>/Discrete FIR Filter' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S156>/Discrete FIR Filter' */
  int32_T chartGlobalTickCounter;      /* '<S146>/Chart' */
  int32_T countReferenceTick_1;        /* '<S146>/Chart' */
  int8_T Integrator_PrevResetState;    /* '<S62>/Integrator' */
  int8_T Integrator_PrevResetState_e;  /* '<S287>/Integrator' */
  int8_T Integrator_PrevResetState_b;  /* '<S296>/Integrator' */
  int8_T Integrator_PrevResetState_i;  /* '<S209>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S204>/Filter' */
  int8_T Integrator_PrevResetState_g;  /* '<S119>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S287>/Integrator' */
  uint8_T Integrator_IC_LOADING_j;     /* '<S296>/Integrator' */
  uint8_T is_active_c21_TVModel;       /* '<S278>/T_Req_Chart' */
  uint8_T is_c21_TVModel;              /* '<S278>/T_Req_Chart' */
  uint8_T is_active_c24_TVModel;       /* '<S146>/Chart' */
  uint8_T is_c24_TVModel;              /* '<S146>/Chart' */
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
  uint8_T is_FR_o;                     /* '<S17>/Activation logic' */
  uint8_T is_RL_j;                     /* '<S17>/Activation logic' */
  uint8_T is_RR_m;                     /* '<S17>/Activation logic' */
  boolean_T Delay_DSTATE[5];           /* '<S172>/Delay' */
  boolean_T Memory_PreviousInput_f;    /* '<S256>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S257>/Memory' */
  boolean_T Memory_PreviousInput_j4;   /* '<S258>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S259>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S232>/Memory' */
  boolean_T IC_FirstOutputTime;        /* '<S235>/IC' */
  boolean_T IC1_FirstOutputTime;       /* '<S236>/IC1' */
  boolean_T Relay_Mode;                /* '<S80>/Relay' */
  boolean_T Relay_Mode_o;              /* '<S81>/Relay' */
  boolean_T countCondWasTrueAtLastTimeStep_;/* '<S146>/Chart' */
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
   *   '<S246>/2-D Lookup Table'
   *   '<S274>/2-D Lookup Table'
   */
  real_T pooled5[4000];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Omega)
   * Referenced by:
   *   '<S158>/Constant2'
   *   '<S246>/2-D Lookup Table'
   *   '<S274>/2-D Lookup Table'
   */
  real_T pooled7[200];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Torque)
   * Referenced by:
   *   '<S158>/Constant3'
   *   '<S246>/2-D Lookup Table'
   *   '<S274>/2-D Lookup Table'
   */
  real_T pooled8[20];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.table_data )
   * Referenced by:
   *   '<S279>/2-D Lookup Table'
   *   '<S288>/2-D Lookup Table'
   *   '<S158>/2-D Lookup Table'
   */
  real_T pooled13[9246];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints1)
   * Referenced by:
   *   '<S279>/2-D Lookup Table'
   *   '<S288>/2-D Lookup Table'
   *   '<S158>/2-D Lookup Table'
   */
  real_T pooled14[201];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints2)
   * Referenced by:
   *   '<S279>/2-D Lookup Table'
   *   '<S288>/2-D Lookup Table'
   *   '<S158>/2-D Lookup Table'
   */
  real_T pooled15[46];

  /* Computed Parameter: LUT_3_tableData
   * Referenced by: '<S275>/LUT_-3'
   */
  real_T LUT_3_tableData[10000];

  /* Expression: TV.LUT.Yrd_LUT.LUT_vectors.delta_vector
   * Referenced by: '<S275>/LUT_-3'
   */
  real_T LUT_3_bp01Data[100];

  /* Expression: TV.LUT.Yrd_LUT.LUT_vectors.v_vector
   * Referenced by: '<S275>/LUT_-3'
   */
  real_T LUT_3_bp02Data[100];

  /* Expression: [0,1]
   * Referenced by: '<S298>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[2];

  /* Expression: [0,0, 4*TV.LV.TORQUE.T_peak_wheel]
   * Referenced by: '<S297>/T_peak_wheel_LUT'
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
  real_T pooled38[33];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT.SteerAngle_SingleAxis
   * Referenced by: '<S9>/steering_to_wheel_angle_single_axis_LUT'
   */
  real_T steering_to_wheel_angle_single_[33];

  /* Pooled Parameter (Expression: [TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 0])
   * Referenced by:
   *   '<S276>/Max_Torque_Overload_Inverter_LUT'
   *   '<S276>/Max_Torque_Overload_Motor_LUT'
   *   '<S276>/Max_Torque_Temperature_External_LUT'
   *   '<S276>/Max_Torque_Temperature_IGBT_LUT'
   *   '<S276>/Max_Torque_Temperature_Internal_LUT'
   *   '<S277>/Display Overload Inverter LUT'
   *   '<S277>/Display Overload Motor LUT'
   *   '<S277>/Temperature External LUT'
   *   '<S277>/Temperature IGBT LUT'
   *   '<S277>/Temperature Internal LUT'
   */
  real_T pooled42[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S276>/Max_Torque_Overload_Inverter_LUT'
   *   '<S276>/Max_Torque_Overload_Motor_LUT'
   *   '<S277>/Display Overload Inverter LUT'
   *   '<S277>/Display Overload Motor LUT'
   */
  real_T pooled43[3];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_positive
   * Referenced by: '<S254>/2-D Lookup Table'
   */
  real_T uDLookupTable_tableData_h[900];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.Fz)
   * Referenced by:
   *   '<S254>/2-D Lookup Table'
   *   '<S254>/2-D Lookup Table1'
   */
  real_T pooled50[30];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.alpha)
   * Referenced by:
   *   '<S254>/2-D Lookup Table'
   *   '<S254>/2-D Lookup Table1'
   */
  real_T pooled51[30];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_negative
   * Referenced by: '<S254>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[900];

  /* Computed Parameter: LUT_3_maxIndex
   * Referenced by: '<S275>/LUT_-3'
   */
  uint32_T LUT_3_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S254>/2-D Lookup Table'
   *   '<S254>/2-D Lookup Table1'
   */
  uint32_T pooled66[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S246>/2-D Lookup Table'
   *   '<S274>/2-D Lookup Table'
   */
  uint32_T pooled67[2];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S232>/Logic'
   *   '<S256>/Logic'
   *   '<S257>/Logic'
   *   '<S258>/Logic'
   *   '<S259>/Logic'
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
 * Block '<S141>/VX_ref' : Unused code path elimination
 * Block '<S141>/VY_ref' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Propagation' : Unused code path elimination
 * Block '<S217>/Data Type Duplicate' : Unused code path elimination
 * Block '<S217>/Data Type Propagation' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Propagation' : Unused code path elimination
 * Block '<S241>/Data Type Duplicate' : Unused code path elimination
 * Block '<S241>/Data Type Propagation' : Unused code path elimination
 * Block '<S247>/NOT' : Unused code path elimination
 * Block '<S139>/Sum' : Unused code path elimination
 * Block '<S151>/r1' : Unused code path elimination
 * Block '<S151>/vx' : Unused code path elimination
 * Block '<S151>/vy' : Unused code path elimination
 * Block '<S281>/Data Type Duplicate' : Unused code path elimination
 * Block '<S281>/Data Type Propagation' : Unused code path elimination
 * Block '<S290>/Data Type Duplicate' : Unused code path elimination
 * Block '<S290>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S239>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S140>/Cast To Double8' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S276>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S287>/Saturation' : Eliminated Saturate block
 * Block '<S280>/K' : Eliminated nontunable gain of 1
 * Block '<S277>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S277>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S277>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S277>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S277>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S296>/Saturation' : Eliminated Saturate block
 * Block '<S289>/K' : Eliminated nontunable gain of 1
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
 * '<S165>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Chart'
 * '<S166>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function1'
 * '<S167>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function2'
 * '<S168>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function3'
 * '<S169>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function4'
 * '<S170>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1'
 * '<S171>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Saturation Dynamic'
 * '<S172>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation'
 * '<S173>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup'
 * '<S174>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/D Gain'
 * '<S175>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter'
 * '<S176>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter ICs'
 * '<S177>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/I Gain'
 * '<S178>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain'
 * '<S179>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain Fdbk'
 * '<S180>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator'
 * '<S181>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator ICs'
 * '<S182>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Copy'
 * '<S183>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Gain'
 * '<S184>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/P Copy'
 * '<S185>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Parallel P Gain'
 * '<S186>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Reset Signal'
 * '<S187>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation'
 * '<S188>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation Fdbk'
 * '<S189>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum'
 * '<S190>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum Fdbk'
 * '<S191>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode'
 * '<S192>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode Sum'
 * '<S193>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Integral'
 * '<S194>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Ngain'
 * '<S195>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/b Gain'
 * '<S196>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/c Gain'
 * '<S197>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/postSat Signal'
 * '<S198>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/preSat Signal'
 * '<S199>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel'
 * '<S200>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S201>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S202>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S203>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/D Gain/External Parameters'
 * '<S204>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter/Disc. Forward Euler Filter'
 * '<S205>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter ICs/Internal IC - Filter'
 * '<S206>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/I Gain/External Parameters'
 * '<S207>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain/Passthrough'
 * '<S208>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain Fdbk/Disabled'
 * '<S209>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator/Discrete'
 * '<S210>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator ICs/Internal IC'
 * '<S211>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Copy/Disabled'
 * '<S212>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Gain/External Parameters'
 * '<S213>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/P Copy/Disabled'
 * '<S214>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Parallel P Gain/External Parameters'
 * '<S215>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Reset Signal/External Reset'
 * '<S216>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation/External'
 * '<S217>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation/External/Saturation Dynamic'
 * '<S218>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation Fdbk/Disabled'
 * '<S219>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum/Sum_PID'
 * '<S220>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum Fdbk/Disabled'
 * '<S221>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode/Enabled'
 * '<S222>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode Sum/Tracking Mode'
 * '<S223>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Integral/Passthrough'
 * '<S224>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Ngain/Passthrough'
 * '<S225>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/b Gain/External Parameters'
 * '<S226>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/c Gain/External Parameters'
 * '<S227>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/postSat Signal/Forward_Path'
 * '<S228>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/preSat Signal/Forward_Path'
 * '<S229>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/First Activation'
 * '<S230>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/If Action Subsystem'
 * '<S231>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/If Action Subsystem1'
 * '<S232>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/S-R Flip-Flop'
 * '<S233>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs'
 * '<S234>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver g'
 * '<S235>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Power Limits Negative'
 * '<S236>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Power Limits Positive'
 * '<S237>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem'
 * '<S238>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem1'
 * '<S239>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem2'
 * '<S240>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Accelerator Mapping '
 * '<S241>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Saturation Dynamic'
 * '<S242>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver g/Coasting'
 * '<S243>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem2/Distribution complete'
 * '<S244>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit'
 * '<S245>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/MATLAB Function'
 * '<S246>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit/Power to engines'
 * '<S247>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin'
 * '<S248>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Brake & ESP'
 * '<S249>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Bus lbx'
 * '<S250>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Bus ubx'
 * '<S251>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Cross Check'
 * '<S252>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Low YRD'
 * '<S253>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics'
 * '<S254>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds'
 * '<S255>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops'
 * '<S256>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop'
 * '<S257>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop1'
 * '<S258>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop2'
 * '<S259>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop3'
 * '<S260>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation'
 * '<S261>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation'
 * '<S262>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz FL'
 * '<S263>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz FR'
 * '<S264>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz RL'
 * '<S265>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz RR'
 * '<S266>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle FL'
 * '<S267>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle FR'
 * '<S268>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle RL'
 * '<S269>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle RR'
 * '<S270>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds/Hydraulic brakes'
 * '<S271>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds/LMUx Correction'
 * '<S272>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit'
 * '<S273>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/MATLAB Function'
 * '<S274>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit/Power to engines'
 * '<S275>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/YRD_LUT_-2'
 * '<S276>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive'
 * '<S277>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen'
 * '<S278>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request'
 * '<S279>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve'
 * '<S280>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S281>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Saturation Dynamic'
 * '<S282>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S283>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S284>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S285>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S286>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S287>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S288>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve'
 * '<S289>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S290>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Saturation Dynamic'
 * '<S291>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S292>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S293>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S294>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S295>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S296>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S297>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Acceleration'
 * '<S298>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Braking'
 * '<S299>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Chart'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
