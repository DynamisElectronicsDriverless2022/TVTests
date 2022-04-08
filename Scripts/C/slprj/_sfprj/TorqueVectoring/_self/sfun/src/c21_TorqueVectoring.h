#ifndef __c21_TorqueVectoring_h__
#define __c21_TorqueVectoring_h__

/* Forward Declarations */

/* Type Definitions */
#ifndef typedef_SFc21_TorqueVectoringInstanceStruct
#define typedef_SFc21_TorqueVectoringInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c21_JITTransitionAnimation[1];
  int32_T c21_sfEvent;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_TorqueVectoring;
  uint8_T c21_JITStateAnimation[1];
  real_T c21_Tn;
  int32_T c21_IsDebuggerActive;
  int32_T c21_IsSequenceViewerPresent;
  int32_T c21_SequenceViewerOptimization;
  int32_T c21_IsHeatMapPresent;
  void *c21_RuntimeVar;
  uint8_T c21_doSetSimStateSideEffects;
  const mxArray *c21_setSimStateSideEffectsInfo;
  uint32_T c21_mlFcnLineNumber;
  CovrtStateflowInstance *c21_covrtInstance;
  void *c21_fEmlrtCtx;
  real_T (*c21_maxDefineTorques)[4];
} SFc21_TorqueVectoringInstanceStruct;

#endif                                 /* typedef_SFc21_TorqueVectoringInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_TorqueVectoring_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c21_TorqueVectoring_get_check_sum(mxArray *plhs[]);
extern void c21_TorqueVectoring_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
