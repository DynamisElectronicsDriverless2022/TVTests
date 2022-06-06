/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TVModel.h
 *
 * Code generated for Simulink model 'TVModel'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Jun  6 11:03:25 2022
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

/* Block signals and states (default storage) for system '<S22>/Chart' */
typedef struct {
  int32_T chartGlobalTickCounter;      /* '<S22>/Chart' */
  int32_T countReferenceTick_1;        /* '<S22>/Chart' */
  uint8_T is_active_c26_TVModel;       /* '<S22>/Chart' */
  uint8_T is_c26_TVModel;              /* '<S22>/Chart' */
  boolean_T countCondWasTrueAtLastTimeStep_;/* '<S22>/Chart' */
} DW_Chart;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Chart sf_Chart3_d;                /* '<S85>/Chart3' */
  DW_Chart sf_Chart2_n;                /* '<S85>/Chart2' */
  DW_Chart sf_Chart1_b;                /* '<S85>/Chart1' */
  DW_Chart sf_Chart_c;                 /* '<S85>/Chart' */
  DW_Chart sf_Chart3;                  /* '<S22>/Chart3' */
  DW_Chart sf_Chart2;                  /* '<S22>/Chart2' */
  DW_Chart sf_Chart1;                  /* '<S22>/Chart1' */
  DW_Chart sf_Chart;                   /* '<S22>/Chart' */
  dsp_simulink_MovingAverage obj;      /* '<S177>/Moving Average' */
  dsp_simulink_MovingAverage_l obj_o;  /* '<S281>/Moving Average' */
  zGeneral_Params General_Params;      /* '<S3>/Data Store_General_Params' */
  real_T CFunction[26];                /* '<S157>/C Function' */
  real_T Probe[2];                     /* '<S285>/Probe' */
  real_T Probe_h[2];                   /* '<S294>/Probe' */
  real_T CFunction_p[4];               /* '<S251>/C Function' */
  real_T CFunction_a[4];               /* '<S252>/C Function' */
  real_T UnitDelay_DSTATE[4];          /* '<S2>/Unit Delay' */
  real_T UD_DSTATE[4];                 /* '<S18>/UD' */
  real_T Integrator_DSTATE[4];         /* '<S60>/Integrator' */
  real_T Filter_DSTATE[4];             /* '<S55>/Filter' */
  real_T UD_DSTATE_e[4];               /* '<S81>/UD' */
  real_T Integrator_DSTATE_b[4];       /* '<S123>/Integrator' */
  real_T Filter_DSTATE_f[4];           /* '<S118>/Filter' */
  real_T Integrator_DSTATE_e[4];       /* '<S290>/Integrator' */
  real_T Integrator_DSTATE_i[4];       /* '<S299>/Integrator' */
  real_T UnitDelay_DSTATE_a[4];        /* '<S151>/Unit Delay' */
  real_T UnitDelay1_DSTATE[4];         /* '<S151>/Unit Delay1' */
  real_T UnitDelay2_DSTATE[2];         /* '<S151>/Unit Delay2' */
  real_T UnitDelay3_DSTATE[4];         /* '<S151>/Unit Delay3' */
  real_T UnitDelay5_DSTATE[4];         /* '<S151>/Unit Delay5' */
  real_T UnitDelay4_DSTATE[2];         /* '<S151>/Unit Delay4' */
  real_T DiscreteFIRFilter_states[4];  /* '<S161>/Discrete FIR Filter' */
  real_T UnitDelay_DSTATE_j[4];        /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<S144>/Memory' */
  real_T mz_output;                    /* '<S151>/Chart' */
  real_T TC_max;                       /* '<S85>/Chart3' */
  real_T TC_max_a;                     /* '<S85>/Chart2' */
  real_T TC_max_k;                     /* '<S85>/Chart1' */
  real_T TC_max_i;                     /* '<S85>/Chart' */
  real_T TC_max_e;                     /* '<S22>/Chart3' */
  real_T TC_max_f;                     /* '<S22>/Chart2' */
  real_T TC_max_fo;                    /* '<S22>/Chart1' */
  real_T TC_max_m;                     /* '<S22>/Chart' */
  real_T Integrator_DSTATE_ek;         /* '<S214>/Integrator' */
  real_T Filter_DSTATE_g;              /* '<S209>/Filter' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S161>/Discrete FIR Filter' */
  int32_T chartGlobalTickCounter;      /* '<S151>/Chart' */
  int32_T countReferenceTick_1;        /* '<S151>/Chart' */
  int8_T Integrator_PrevResetState_f[4];/* '<S123>/Integrator' */
  int8_T Filter_PrevResetState_g[4];   /* '<S118>/Filter' */
  int8_T Integrator_PrevResetState;    /* '<S60>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S55>/Filter' */
  int8_T Integrator_PrevResetState_k;  /* '<S290>/Integrator' */
  int8_T Integrator_PrevResetState_l;  /* '<S299>/Integrator' */
  int8_T Integrator_PrevResetState_h;  /* '<S214>/Integrator' */
  int8_T Filter_PrevResetState_m;      /* '<S209>/Filter' */
  uint8_T Integrator_IC_LOADING;       /* '<S290>/Integrator' */
  uint8_T Integrator_IC_LOADING_f;     /* '<S299>/Integrator' */
  uint8_T is_active_c21_TVModel;       /* '<S281>/T_Req_Chart' */
  uint8_T is_c21_TVModel;              /* '<S281>/T_Req_Chart' */
  uint8_T is_active_c24_TVModel;       /* '<S151>/Chart' */
  uint8_T is_c24_TVModel;              /* '<S151>/Chart' */
  uint8_T is_active_c13_TVModel;       /* '<S150>/Overlap Chart' */
  uint8_T is_c13_TVModel;              /* '<S150>/Overlap Chart' */
  boolean_T Delay_DSTATE[5];           /* '<S177>/Delay' */
  boolean_T IC_1_FirstOutputTime;      /* '<S11>/IC' */
  boolean_T IC_3_FirstOutputTime;      /* '<S11>/IC' */
  boolean_T IC_4_FirstOutputTime;      /* '<S11>/IC' */
  boolean_T IC_7_FirstOutputTime;      /* '<S11>/IC' */
  boolean_T IC1_1_FirstOutputTime;     /* '<S11>/IC1' */
  boolean_T IC1_2_FirstOutputTime;     /* '<S11>/IC1' */
  boolean_T IC1_3_FirstOutputTime;     /* '<S11>/IC1' */
  boolean_T IC1_4_FirstOutputTime;     /* '<S11>/IC1' */
  boolean_T IC2_1_FirstOutputTime;     /* '<S11>/IC2' */
  boolean_T IC2_3_FirstOutputTime;     /* '<S11>/IC2' */
  boolean_T IC2_4_FirstOutputTime;     /* '<S11>/IC2' */
  boolean_T IC2_7_FirstOutputTime;     /* '<S11>/IC2' */
  boolean_T IC3_1_FirstOutputTime;     /* '<S11>/IC3' */
  boolean_T IC3_2_FirstOutputTime;     /* '<S11>/IC3' */
  boolean_T IC3_3_FirstOutputTime;     /* '<S11>/IC3' */
  boolean_T IC3_4_FirstOutputTime;     /* '<S11>/IC3' */
  boolean_T Memory_PreviousInput_c;    /* '<S258>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S259>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S260>/Memory' */
  boolean_T Memory_PreviousInput_k;    /* '<S261>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S237>/Memory' */
  boolean_T IC_FirstOutputTime;        /* '<S240>/IC' */
  boolean_T IC_FirstOutputTime_k;      /* '<S151>/IC' */
  boolean_T IC1_FirstOutputTime;       /* '<S241>/IC1' */
  boolean_T countCondWasTrueAtLastTimeStep_;/* '<S151>/Chart' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: TV.LV.GENERAL
   * Referenced by: '<S3>/Data Store_General_Params'
   */
  zGeneral_Params DataStore_General_Params_Initia;

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Eta)
   * Referenced by:
   *   '<S163>/Constant1'
   *   '<S248>/2-D Lookup Table'
   *   '<S277>/2-D Lookup Table'
   */
  real_T pooled5[4000];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Omega)
   * Referenced by:
   *   '<S163>/Constant2'
   *   '<S248>/2-D Lookup Table'
   *   '<S277>/2-D Lookup Table'
   */
  real_T pooled7[200];

  /* Pooled Parameter (Expression: TV.LV.efficiency_LUT.Torque)
   * Referenced by:
   *   '<S163>/Constant3'
   *   '<S248>/2-D Lookup Table'
   *   '<S277>/2-D Lookup Table'
   */
  real_T pooled8[20];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.table_data )
   * Referenced by:
   *   '<S282>/2-D Lookup Table'
   *   '<S291>/2-D Lookup Table'
   *   '<S163>/2-D Lookup Table'
   */
  real_T pooled13[9246];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints1)
   * Referenced by:
   *   '<S282>/2-D Lookup Table'
   *   '<S291>/2-D Lookup Table'
   *   '<S163>/2-D Lookup Table'
   */
  real_T pooled14[201];

  /* Pooled Parameter (Expression: TV.LV.TORQUE.T_lim_pos.breakpoints2)
   * Referenced by:
   *   '<S282>/2-D Lookup Table'
   *   '<S291>/2-D Lookup Table'
   *   '<S163>/2-D Lookup Table'
   */
  real_T pooled15[46];

  /* Expression: [0,1]
   * Referenced by: '<S301>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[2];

  /* Expression: [0,0, 4*TV.LV.TORQUE.T_peak_wheel]
   * Referenced by: '<S300>/T_peak_wheel_LUT'
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
  real_T pooled34[33];

  /* Expression: TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT.SteerAngle_SingleAxis
   * Referenced by: '<S9>/steering_to_wheel_angle_single_axis_LUT'
   */
  real_T steering_to_wheel_angle_single_[33];

  /* Pooled Parameter (Expression: [TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 TV.LV.AMK.ID82*TV.LV.AMK.ID32771/100 0])
   * Referenced by:
   *   '<S279>/Max_Torque_Overload_Inverter_LUT'
   *   '<S279>/Max_Torque_Overload_Motor_LUT'
   *   '<S279>/Max_Torque_Temperature_External_LUT'
   *   '<S279>/Max_Torque_Temperature_IGBT_LUT'
   *   '<S279>/Max_Torque_Temperature_Internal_LUT'
   *   '<S280>/Display Overload Inverter LUT'
   *   '<S280>/Display Overload Motor LUT'
   *   '<S280>/Temperature External LUT'
   *   '<S280>/Temperature IGBT LUT'
   *   '<S280>/Temperature Internal LUT'
   */
  real_T pooled50[3];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S279>/Max_Torque_Overload_Inverter_LUT'
   *   '<S279>/Max_Torque_Overload_Motor_LUT'
   *   '<S280>/Display Overload Inverter LUT'
   *   '<S280>/Display Overload Motor LUT'
   */
  real_T pooled51[3];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_positive
   * Referenced by: '<S256>/2-D Lookup Table'
   */
  real_T uDLookupTable_tableData_d[900];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.Fz)
   * Referenced by:
   *   '<S256>/2-D Lookup Table'
   *   '<S256>/2-D Lookup Table1'
   */
  real_T pooled54[30];

  /* Pooled Parameter (Expression: TV.LUT.MPC_Lut.control_bound_dry.alpha)
   * Referenced by:
   *   '<S256>/2-D Lookup Table'
   *   '<S256>/2-D Lookup Table1'
   */
  real_T pooled55[30];

  /* Expression: TV.LUT.MPC_Lut.control_bound_dry.Fx_target_negative
   * Referenced by: '<S256>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[900];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S256>/2-D Lookup Table'
   *   '<S256>/2-D Lookup Table1'
   */
  uint32_T pooled67[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S248>/2-D Lookup Table'
   *   '<S277>/2-D Lookup Table'
   */
  uint32_T pooled68[2];

  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S237>/Logic'
   *   '<S258>/Logic'
   *   '<S259>/Logic'
   *   '<S260>/Logic'
   *   '<S261>/Logic'
   */
  boolean_T pooled70[16];
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
 * Block '<S11>/Saturation4' : Unused code path elimination
 * Block '<S11>/Saturation5' : Unused code path elimination
 * Block '<S16>/Constant4' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/IC' : Unused code path elimination
 * Block '<S16>/Less Than1' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Data Type Propagation' : Unused code path elimination
 * Block '<S151>/Equal' : Unused code path elimination
 * Block '<S151>/NOT' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate' : Unused code path elimination
 * Block '<S222>/Data Type Propagation' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Propagation' : Unused code path elimination
 * Block '<S154>/Constant' : Unused code path elimination
 * Block '<S249>/NOT' : Unused code path elimination
 * Block '<S144>/Sum' : Unused code path elimination
 * Block '<S145>/Constant' : Unused code path elimination
 * Block '<S145>/Constant1' : Unused code path elimination
 * Block '<S284>/Data Type Duplicate' : Unused code path elimination
 * Block '<S284>/Data Type Propagation' : Unused code path elimination
 * Block '<S293>/Data Type Duplicate' : Unused code path elimination
 * Block '<S293>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S279>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S279>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S279>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S279>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S279>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S290>/Saturation' : Eliminated Saturate block
 * Block '<S283>/K' : Eliminated nontunable gain of 1
 * Block '<S280>/Cast_0' : Eliminate redundant data type conversion
 * Block '<S280>/Cast_1' : Eliminate redundant data type conversion
 * Block '<S280>/Cast_2' : Eliminate redundant data type conversion
 * Block '<S280>/Cast_3' : Eliminate redundant data type conversion
 * Block '<S280>/Cast_4' : Eliminate redundant data type conversion
 * Block '<S299>/Saturation' : Eliminated Saturate block
 * Block '<S292>/K' : Eliminated nontunable gain of 1
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
 * '<S16>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem'
 * '<S17>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1'
 * '<S18>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Discrete Derivative'
 * '<S19>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Load Transfer Calculation'
 * '<S20>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/MATLAB Function1'
 * '<S21>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller'
 * '<S22>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Subsystem'
 * '<S23>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Load Transfer Calculation/Fz FL'
 * '<S24>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Load Transfer Calculation/Fz FR'
 * '<S25>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Load Transfer Calculation/Fz RL'
 * '<S26>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Load Transfer Calculation/Fz RR'
 * '<S27>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Anti-windup'
 * '<S28>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/D Gain'
 * '<S29>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Filter'
 * '<S30>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Filter ICs'
 * '<S31>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/I Gain'
 * '<S32>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Ideal P Gain'
 * '<S33>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S34>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Integrator'
 * '<S35>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Integrator ICs'
 * '<S36>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/N Copy'
 * '<S37>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/N Gain'
 * '<S38>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/P Copy'
 * '<S39>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Parallel P Gain'
 * '<S40>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Reset Signal'
 * '<S41>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Saturation'
 * '<S42>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Saturation Fdbk'
 * '<S43>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Sum'
 * '<S44>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Sum Fdbk'
 * '<S45>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Tracking Mode'
 * '<S46>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Tracking Mode Sum'
 * '<S47>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Tsamp - Integral'
 * '<S48>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Tsamp - Ngain'
 * '<S49>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/postSat Signal'
 * '<S50>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/preSat Signal'
 * '<S51>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S52>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S53>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S54>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/D Gain/Internal Parameters'
 * '<S55>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S56>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S57>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S58>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S59>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S60>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Integrator/Discrete'
 * '<S61>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S62>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/N Copy/Disabled'
 * '<S63>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/N Gain/Internal Parameters'
 * '<S64>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/P Copy/Disabled'
 * '<S65>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S66>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Reset Signal/External Reset'
 * '<S67>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Saturation/Enabled'
 * '<S68>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S69>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Sum/Sum_PID'
 * '<S70>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S71>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S72>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S73>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Tsamp - Integral/Passthrough'
 * '<S74>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S75>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S76>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/PID Controller/preSat Signal/Forward_Path'
 * '<S77>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Subsystem/Chart'
 * '<S78>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Subsystem/Chart1'
 * '<S79>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Subsystem/Chart2'
 * '<S80>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem/Subsystem/Chart3'
 * '<S81>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Discrete Derivative'
 * '<S82>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Load Transfer Calculation'
 * '<S83>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/MATLAB Function1'
 * '<S84>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller'
 * '<S85>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Subsystem'
 * '<S86>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Load Transfer Calculation/Fz FL'
 * '<S87>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Load Transfer Calculation/Fz FR'
 * '<S88>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Load Transfer Calculation/Fz RL'
 * '<S89>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Load Transfer Calculation/Fz RR'
 * '<S90>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Anti-windup'
 * '<S91>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/D Gain'
 * '<S92>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Filter'
 * '<S93>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Filter ICs'
 * '<S94>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/I Gain'
 * '<S95>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Ideal P Gain'
 * '<S96>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Ideal P Gain Fdbk'
 * '<S97>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Integrator'
 * '<S98>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Integrator ICs'
 * '<S99>'  : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/N Copy'
 * '<S100>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/N Gain'
 * '<S101>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/P Copy'
 * '<S102>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Parallel P Gain'
 * '<S103>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Reset Signal'
 * '<S104>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Saturation'
 * '<S105>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Saturation Fdbk'
 * '<S106>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Sum'
 * '<S107>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Sum Fdbk'
 * '<S108>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Tracking Mode'
 * '<S109>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Tracking Mode Sum'
 * '<S110>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Tsamp - Integral'
 * '<S111>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Tsamp - Ngain'
 * '<S112>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/postSat Signal'
 * '<S113>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/preSat Signal'
 * '<S114>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S115>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S116>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S117>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/D Gain/Internal Parameters'
 * '<S118>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S119>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S120>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/I Gain/Internal Parameters'
 * '<S121>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Ideal P Gain/Passthrough'
 * '<S122>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S123>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Integrator/Discrete'
 * '<S124>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Integrator ICs/Internal IC'
 * '<S125>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/N Copy/Disabled'
 * '<S126>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/N Gain/Internal Parameters'
 * '<S127>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/P Copy/Disabled'
 * '<S128>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S129>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Reset Signal/External Reset'
 * '<S130>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Saturation/Enabled'
 * '<S131>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Saturation Fdbk/Disabled'
 * '<S132>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Sum/Sum_PID'
 * '<S133>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Sum Fdbk/Disabled'
 * '<S134>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Tracking Mode/Disabled'
 * '<S135>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S136>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Tsamp - Integral/Passthrough'
 * '<S137>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S138>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/postSat Signal/Forward_Path'
 * '<S139>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/PID Controller/preSat Signal/Forward_Path'
 * '<S140>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Subsystem/Chart'
 * '<S141>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Subsystem/Chart1'
 * '<S142>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Subsystem/Chart2'
 * '<S143>' : 'TVModel/Subsystem/Subsystem1/Slip Control/Traction Control/Subsystem1/Subsystem/Chart3'
 * '<S144>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC'
 * '<S145>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking'
 * '<S146>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/     Output Vector Reference'
 * '<S147>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus '
 * '<S148>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ States'
 * '<S149>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Control Constraints'
 * '<S150>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection'
 * '<S151>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation'
 * '<S152>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints'
 * '<S153>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix'
 * '<S154>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Slack variables Weights '
 * '<S155>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints'
 * '<S156>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation'
 * '<S157>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/ Parameter Bus /Bus p'
 * '<S158>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/MPC'
 * '<S159>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Overlap Chart'
 * '<S160>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque'
 * '<S161>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem'
 * '<S162>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino'
 * '<S163>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV'
 * '<S164>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/MATLAB Function'
 * '<S165>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Simple torque/No_TV/Saturation Dynamic'
 * '<S166>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem/Backup Map'
 * '<S167>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Subsystem/Selected Map'
 * '<S168>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino/Vectorino'
 * '<S169>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Faults Detection/Vectorino/Vectorino/30//70'
 * '<S170>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Chart'
 * '<S171>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function1'
 * '<S172>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function2'
 * '<S173>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function3'
 * '<S174>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/MATLAB Function4'
 * '<S175>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1'
 * '<S176>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Saturation Dynamic'
 * '<S177>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation'
 * '<S178>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup'
 * '<S179>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/D Gain'
 * '<S180>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter'
 * '<S181>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter ICs'
 * '<S182>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/I Gain'
 * '<S183>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain'
 * '<S184>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain Fdbk'
 * '<S185>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator'
 * '<S186>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator ICs'
 * '<S187>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Copy'
 * '<S188>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Gain'
 * '<S189>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/P Copy'
 * '<S190>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Parallel P Gain'
 * '<S191>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Reset Signal'
 * '<S192>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation'
 * '<S193>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation Fdbk'
 * '<S194>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum'
 * '<S195>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum Fdbk'
 * '<S196>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode'
 * '<S197>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode Sum'
 * '<S198>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Integral'
 * '<S199>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Ngain'
 * '<S200>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/b Gain'
 * '<S201>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/c Gain'
 * '<S202>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/postSat Signal'
 * '<S203>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/preSat Signal'
 * '<S204>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel'
 * '<S205>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S206>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S207>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S208>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/D Gain/External Parameters'
 * '<S209>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter/Disc. Forward Euler Filter'
 * '<S210>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Filter ICs/Internal IC - Filter'
 * '<S211>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/I Gain/External Parameters'
 * '<S212>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain/Passthrough'
 * '<S213>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Ideal P Gain Fdbk/Disabled'
 * '<S214>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator/Discrete'
 * '<S215>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Integrator ICs/Internal IC'
 * '<S216>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Copy/Disabled'
 * '<S217>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/N Gain/External Parameters'
 * '<S218>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/P Copy/Disabled'
 * '<S219>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Parallel P Gain/External Parameters'
 * '<S220>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Reset Signal/External Reset'
 * '<S221>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation/External'
 * '<S222>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation/External/Saturation Dynamic'
 * '<S223>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Saturation Fdbk/Disabled'
 * '<S224>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum/Sum_PID'
 * '<S225>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Sum Fdbk/Disabled'
 * '<S226>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode/Enabled'
 * '<S227>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tracking Mode Sum/Tracking Mode'
 * '<S228>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Integral/Passthrough'
 * '<S229>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/Tsamp - Ngain/Passthrough'
 * '<S230>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/b Gain/External Parameters'
 * '<S231>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/c Gain/External Parameters'
 * '<S232>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/postSat Signal/Forward_Path'
 * '<S233>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/PID Controller (2DOF)1/preSat Signal/Forward_Path'
 * '<S234>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/First Activation'
 * '<S235>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/If Action Subsystem'
 * '<S236>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/If Action Subsystem1'
 * '<S237>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Mz Generation/Steer Activation/S-R Flip-Flop'
 * '<S238>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs'
 * '<S239>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver g'
 * '<S240>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Power Limits Negative'
 * '<S241>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Power Limits Positive'
 * '<S242>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem'
 * '<S243>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Subsystem1'
 * '<S244>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver Inputs/Accelerator Mapping '
 * '<S245>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytopic Constraints/Driver g/Coasting'
 * '<S246>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit'
 * '<S247>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/MATLAB Function'
 * '<S248>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Polytropic Matrix/Efficiency limit/Power to engines'
 * '<S249>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin'
 * '<S250>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Brake & ESP'
 * '<S251>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Bus lbx'
 * '<S252>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Bus ubx'
 * '<S253>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Cross Check'
 * '<S254>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Low YRD'
 * '<S255>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics'
 * '<S256>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds'
 * '<S257>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops'
 * '<S258>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop'
 * '<S259>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop1'
 * '<S260>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop2'
 * '<S261>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Anti reverse wheelspin/S-R Flip Flops/S-R Flip-Flop3'
 * '<S262>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation'
 * '<S263>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation'
 * '<S264>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz FL'
 * '<S265>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz FR'
 * '<S266>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz RL'
 * '<S267>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Load Transfer Calculation/Fz RR'
 * '<S268>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle FL'
 * '<S269>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle FR'
 * '<S270>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle RL'
 * '<S271>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bound Dynamics/Slip Angle Calculation/Slip Angle RR'
 * '<S272>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds/Hydraulic brakes'
 * '<S273>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/States Constraints/Tire Bounds/LMUx Correction'
 * '<S274>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit'
 * '<S275>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/MATLAB Function'
 * '<S276>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit/MATLAB Function'
 * '<S277>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/MPC/Weights Generation/Efficiency limit/Power to engines'
 * '<S278>' : 'TVModel/Subsystem/Subsystem1/Torque Distribution/Reference Tracking/MATLAB Function1'
 * '<S279>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive'
 * '<S280>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen'
 * '<S281>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request'
 * '<S282>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve'
 * '<S283>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S284>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Saturation Dynamic'
 * '<S285>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S286>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S287>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S288>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S289>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S290>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Positive/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S291>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve'
 * '<S292>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)'
 * '<S293>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Saturation Dynamic'
 * '<S294>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S295>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S296>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S297>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S298>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S299>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Limits Regen/Torque_Curve/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S300>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Acceleration'
 * '<S301>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Braking'
 * '<S302>' : 'TVModel/Subsystem/Subsystem1/Torque Limits/Torque Request/T_Req_Chart'
 */
#endif                                 /* RTW_HEADER_TVModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
