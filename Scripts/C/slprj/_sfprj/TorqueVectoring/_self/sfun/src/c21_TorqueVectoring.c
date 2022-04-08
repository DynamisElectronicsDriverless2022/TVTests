/* Include files */

#include "TorqueVectoring_sfun.h"
#include "c21_TorqueVectoring.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c21_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c21_const_Tn                   (9.8)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance);
static void initialize_params_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void enable_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance);
static void disable_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance);
static void c21_update_jit_animation_state_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void c21_do_animation_call_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void ext_mode_exec_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void set_sim_state_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance, const mxArray *c21_st);
static void c21_set_sim_state_side_effects_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void sf_gateway_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance);
static void mdl_start_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance);
static void mdl_terminate_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void initSimStructsc21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void c21_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_b_maxDefineTorques, const char_T
  *c21_identifier, real_T c21_y[4]);
static void c21_b_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[4]);
static uint8_T c21_c_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_TorqueVectoring, const
  char_T *c21_identifier);
static uint8_T c21_d_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static const mxArray *c21_e_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_b_setSimStateSideEffectsInfo, const char_T *
  c21_identifier);
static const mxArray *c21_f_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_slStringInitializeDynamicBuffers
  (SFc21_TorqueVectoringInstanceStruct *chartInstance);
static void c21_init_sf_message_store_memory(SFc21_TorqueVectoringInstanceStruct
  *chartInstance);
static void c21_chart_data_browse_helper(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, int32_T c21_ssIdNumber, const mxArray **c21_mxData, uint8_T
  *c21_isValueTooBig);
static void init_dsm_address_info(SFc21_TorqueVectoringInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc21_TorqueVectoringInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance)
{
  int32_T c21_i;
  int32_T c21_i1;
  sim_mode_is_external(chartInstance->S);
  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_doSetSimStateSideEffects = 0U;
  chartInstance->c21_setSimStateSideEffectsInfo = NULL;
  chartInstance->c21_is_active_c21_TorqueVectoring = 0U;
  chartInstance->c21_Tn = 9.8;
  if (sf_get_output_port_reusable(chartInstance->S, 1) == 0) {
    for (c21_i = 0; c21_i < 4; c21_i++) {
      (*chartInstance->c21_maxDefineTorques)[c21_i] = 0.0;
    }
  }

  covrtSigUpdateFcn(chartInstance->c21_covrtInstance, 1U, chartInstance->c21_Tn);
  for (c21_i1 = 0; c21_i1 < 4; c21_i1++) {
    covrtSigUpdateFcn(chartInstance->c21_covrtInstance, 0U,
                      (*chartInstance->c21_maxDefineTorques)[c21_i1]);
  }
}

static void initialize_params_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c21_update_jit_animation_state_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c21_do_animation_call_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  const mxArray *c21_b_y = NULL;
  const mxArray *c21_c_y = NULL;
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellmatrix(2, 1), false);
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y",
    *chartInstance->c21_maxDefineTorques, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y",
    &chartInstance->c21_is_active_c21_TorqueVectoring, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  sf_mex_assign(&c21_st, c21_y, false);
  return c21_st;
}

static void set_sim_state_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  real_T c21_dv[4];
  int32_T c21_i;
  chartInstance->c21_doneDoubleBufferReInit = true;
  c21_u = sf_mex_dup(c21_st);
  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 0)),
                       "maxDefineTorques", c21_dv);
  for (c21_i = 0; c21_i < 4; c21_i++) {
    (*chartInstance->c21_maxDefineTorques)[c21_i] = c21_dv[c21_i];
  }

  chartInstance->c21_is_active_c21_TorqueVectoring = c21_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 1)),
     "is_active_c21_TorqueVectoring");
  sf_mex_assign(&chartInstance->c21_setSimStateSideEffectsInfo,
                c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c21_u, 2)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c21_u);
  chartInstance->c21_doSetSimStateSideEffects = 1U;
  sf_mex_destroy(&c21_st);
}

static void c21_set_sim_state_side_effects_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  if (chartInstance->c21_doSetSimStateSideEffects != 0) {
    chartInstance->c21_doSetSimStateSideEffects = 0U;
  }
}

static void sf_gateway_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance)
{
  int32_T c21_i;
  int32_T c21_i1;
  int32_T c21_i2;
  int32_T c21_i3;
  c21_set_sim_state_side_effects_c21_TorqueVectoring(chartInstance);
  chartInstance->c21_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_sfEvent = CALL_EVENT;
  chartInstance->c21_JITTransitionAnimation[0U] = 1U;
  (*chartInstance->c21_maxDefineTorques)[0] = 0.0098000000000000014 * (real_T)
    TORQUE_LIMIT_FL;
  for (c21_i = 0; c21_i < 4; c21_i++) {
    covrtSigUpdateFcn(chartInstance->c21_covrtInstance, 0U,
                      (*chartInstance->c21_maxDefineTorques)[c21_i]);
  }

  (*chartInstance->c21_maxDefineTorques)[1] = 0.0098000000000000014 * (real_T)
    TORQUE_LIMIT_FR;
  for (c21_i1 = 0; c21_i1 < 4; c21_i1++) {
    covrtSigUpdateFcn(chartInstance->c21_covrtInstance, 0U,
                      (*chartInstance->c21_maxDefineTorques)[c21_i1]);
  }

  (*chartInstance->c21_maxDefineTorques)[2] = 0.0098000000000000014 * (real_T)
    TORQUE_LIMIT_RL;
  for (c21_i2 = 0; c21_i2 < 4; c21_i2++) {
    covrtSigUpdateFcn(chartInstance->c21_covrtInstance, 0U,
                      (*chartInstance->c21_maxDefineTorques)[c21_i2]);
  }

  (*chartInstance->c21_maxDefineTorques)[3] = 0.0098000000000000014 * (real_T)
    TORQUE_LIMIT_RR;
  for (c21_i3 = 0; c21_i3 < 4; c21_i3++) {
    covrtSigUpdateFcn(chartInstance->c21_covrtInstance, 0U,
                      (*chartInstance->c21_maxDefineTorques)[c21_i3]);
  }

  c21_do_animation_call_c21_TorqueVectoring(chartInstance);
}

static void mdl_start_c21_TorqueVectoring(SFc21_TorqueVectoringInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_terminate_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c21_chart_data_browse_helper);
  chartInstance->c21_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c21_RuntimeVar,
    &chartInstance->c21_IsDebuggerActive,
    &chartInstance->c21_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c21_mlFcnLineNumber, &chartInstance->c21_IsHeatMapPresent, 0);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c21_covrtInstance, 0U, 0U, 1U,
    17U);
  covrtChartInitFcn(chartInstance->c21_covrtInstance, 0U, false, false, false);
  covrtTransInitFcn(chartInstance->c21_covrtInstance, 0U, 0, NULL, NULL, 0U,
                    NULL);
}

static void mdl_cleanup_runtime_resources_c21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c21_RuntimeVar);
  sf_mex_destroy(&chartInstance->c21_setSimStateSideEffectsInfo);
  covrtDeleteStateflowInstanceData(chartInstance->c21_covrtInstance);
}

static void initSimStructsc21_TorqueVectoring
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c21_TorqueVectoring_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  sf_mex_assign(&c21_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c21_nameCaptureInfo;
}

static void c21_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_b_maxDefineTorques, const char_T
  *c21_identifier, real_T c21_y[4])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = (const char_T *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_maxDefineTorques),
    &c21_thisId, c21_y);
  sf_mex_destroy(&c21_b_maxDefineTorques);
}

static void c21_b_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[4])
{
  real_T c21_dv[4];
  int32_T c21_i;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv, 1, 0, 0U, 1, 0U, 1, 4);
  for (c21_i = 0; c21_i < 4; c21_i++) {
    c21_y[c21_i] = c21_dv[c21_i];
  }

  sf_mex_destroy(&c21_u);
}

static uint8_T c21_c_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_TorqueVectoring, const
  char_T *c21_identifier)
{
  emlrtMsgIdentifier c21_thisId;
  uint8_T c21_y;
  c21_thisId.fIdentifier = (const char_T *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  c21_y = c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_is_active_c21_TorqueVectoring), &c21_thisId);
  sf_mex_destroy(&c21_b_is_active_c21_TorqueVectoring);
  return c21_y;
}

static uint8_T c21_d_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_b_u;
  uint8_T c21_y;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_b_u, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_b_u;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static const mxArray *c21_e_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_b_setSimStateSideEffectsInfo, const char_T *
  c21_identifier)
{
  emlrtMsgIdentifier c21_thisId;
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  c21_thisId.fIdentifier = (const char_T *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  sf_mex_assign(&c21_y, c21_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_setSimStateSideEffectsInfo), &c21_thisId), true);
  sf_mex_destroy(&c21_b_setSimStateSideEffectsInfo);
  return c21_y;
}

static const mxArray *c21_f_emlrt_marshallIn(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  const mxArray *c21_y = NULL;
  (void)chartInstance;
  (void)c21_parentId;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_duplicatearraysafe(&c21_u), true);
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_slStringInitializeDynamicBuffers
  (SFc21_TorqueVectoringInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c21_init_sf_message_store_memory(SFc21_TorqueVectoringInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c21_chart_data_browse_helper(SFc21_TorqueVectoringInstanceStruct
  *chartInstance, int32_T c21_ssIdNumber, const mxArray **c21_mxData, uint8_T
  *c21_isValueTooBig)
{
  *c21_mxData = NULL;
  *c21_mxData = NULL;
  *c21_isValueTooBig = 0U;
  switch (c21_ssIdNumber) {
   case 1U:
    sf_mex_assign(c21_mxData, sf_mex_create("mxData",
      *chartInstance->c21_maxDefineTorques, 0, 0U, 1U, 0U, 1, 4), false);
    break;

   case 2U:
    sf_mex_assign(c21_mxData, sf_mex_create("mxData", &chartInstance->c21_Tn, 0,
      0U, 0U, 0U, 0), false);
    break;
  }
}

static void init_dsm_address_info(SFc21_TorqueVectoringInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc21_TorqueVectoringInstanceStruct
  *chartInstance)
{
  chartInstance->c21_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c21_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c21_maxDefineTorques = (real_T (*)[4])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c21_TorqueVectoring_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(560838861U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1029406260U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1970163682U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1290809074U);
}

mxArray *sf_c21_TorqueVectoring_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c21_TorqueVectoring_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("custom_code");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c21_TorqueVectoring_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c21_TorqueVectoring(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDmYGJgYAPRQMzEAAGsUD4jVIwRLs4CF1cA4pLKglSQeHFRsmcKkM5LzAXzE0s"
    "rPPPS8sHmWzAgzGfDYj4jkvmcUHEI+GBPDf0OSPpZsOgXQNIvAMW5iRUuqWmZeakh+UWFpanFfF"
    "B5ytyj4ECZfoj9AQT8I4vmHxA/szg+Mbkksyw1PtnIMB7iqbDU5JL8osy8dKi5IAAAH7YhUw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_TorqueVectoring_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "s4SQq8dKIcQeKX3IVzkXGqE";
}

static void sf_opaque_initialize_c21_TorqueVectoring(void *chartInstanceVar)
{
  initialize_params_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    chartInstanceVar);
  initialize_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c21_TorqueVectoring(void *chartInstanceVar)
{
  enable_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c21_TorqueVectoring(void *chartInstanceVar)
{
  disable_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c21_TorqueVectoring(void *chartInstanceVar)
{
  sf_gateway_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c21_TorqueVectoring(SimStruct* S)
{
  return get_sim_state_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c21_TorqueVectoring(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c21_TorqueVectoring(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_TorqueVectoringInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_TorqueVectoring_optimization_info();
    }

    mdl_cleanup_runtime_resources_c21_TorqueVectoring
      ((SFc21_TorqueVectoringInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c21_TorqueVectoring(void *chartInstanceVar)
{
  mdl_start_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_mdl_terminate_c21_TorqueVectoring(void *chartInstanceVar)
{
  mdl_terminate_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_TorqueVectoring(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc21_TorqueVectoring((SFc21_TorqueVectoringInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c21_TorqueVectoring_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrtWE2P20QYdqKlaiWoFnHgQkUlkOCECuXQE+xuPsBtlk1xNlRcVrPjN/Eo4xnvfGQ3/IH2j5T",
    "fwJ0D/AQkLpwRB34C79hO1ji207RVWQGWHGc8z/v9MW/itfxDD6+beP/2luddw+d1vNtedr2Wr1",
    "uFO3u/432Qr39FImHjIVEk1l7jJUgMX4OW3BomhS8mshLGxAQUCIrYRCpTx02z2HImZn0rqOOnv",
    "4kYjYJIWh4eIC0JjwRfILfEmiHy6TIF1PQBQhMpaadRn5PpSmNlzjsR0Jm2cZMJGkxgE6eWPrTc",
    "sIRD7wKoL7QhqLG+1C0wxEDHXNSa6SzVwRIo44QzIiqtjYgOIEEHGzhOQvw8sgaNKsNoRJQ5gIj",
    "MQQ/YLOUpBZR5Mo0bp0wQIxUjvBfzjiNc123IUZ9DGQJvcAjqdqCAzBLJhKmPf9BHS3uCnHLowq",
    "md1nML4My64I8ZnIOq9dukI+egyBSORK3Q1CG9izRaqyxZhxkWw5iofYrx0xDWZi9mjg4IxglGS",
    "FEHg9RIX48Um6N7a7nZ2HeZualkbJwFW2+Cpdx6c2iKwopbn4oO4VzXwkYyGcAceMq1SwxphmVc",
    "q3Fas3Ak0cEuveurwQqGgc9hHSlCVhmueQmQ9p2vsLH8HUmtNjLuYPJ2B4P17XWYLwyoCaFQ1QU",
    "UYRrQZ6l767mFTLvYIxC1Mql6VeAsQzahPD2xonsu1Qx90tBELk1wEa0FQjjFyjOQFkEPQzcm3K",
    "4LjfUUQ44Fc6yxtmq5IcyFfBOOEhpB6PoQ43CI1YXYCtdp1wH3UbM5M4suaKpYUhF8i8WJ3copP",
    "1okcCxmQp6LvpJxkB8FWRQAMCmJEkxMD7DNqUUfpa+JVXA2Siu1oT8vL3c+3vEuz8fXn+F8fBY6",
    "b43uUt7y+WGBvlUh1ys8y/JutJv1bOO3Vk63V6B7oyRnp0TncLt4f3/6ZPD4/T/uv0d/fPPnn57",
    "+/iLyf2hvN3/czNfvLBv9qnDna/XisF8W9Nqp4P92gf9uvtafBg/P7oUPfPoQHjy664+/mz364q",
    "yX8ru+Qd92Sd/l+9vuxMH0TRNfUT/MByO3JjYbFxz/ewV9r23wx41CPnnen5+/DPq9Df7aLfnL3",
    "TG56MKECRhJhc1cF/P4+fW5vfdi9Jn84QZ7bpXsuZXOGSfEtSU4oZ98fJIZNcYWioOTmJbq9Hnz",
    "fls673+6K0HX+g/a97LOvSq6Vy3P+4fs2/Y8v2r4Ow191Cvhd6+wHV5D/95mTrtqdv3ibTdHvZu",
    "vP1v9VOtEjIcV43i+jbP1pGr3X5Lf2/pvOTd+5PyX/zX07d19QfhCs+xXx/L1ULn/LApbr/oc+A",
    "t8Htrg",
    ""
  };

  static char newstr [1357] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c21_TorqueVectoring(SimStruct *S)
{
  const char* newstr = sf_c21_TorqueVectoring_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1284006566U));
  ssSetChecksum1(S,(1256989831U));
  ssSetChecksum2(S,(298017571U));
  ssSetChecksum3(S,(3936733128U));
}

static void mdlRTW_c21_TorqueVectoring(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlSetupRuntimeResources_c21_TorqueVectoring(SimStruct *S)
{
  SFc21_TorqueVectoringInstanceStruct *chartInstance;
  chartInstance = (SFc21_TorqueVectoringInstanceStruct *)utMalloc(sizeof
    (SFc21_TorqueVectoringInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc21_TorqueVectoringInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_TorqueVectoring;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_TorqueVectoring;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c21_TorqueVectoring;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c21_TorqueVectoring;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c21_TorqueVectoring;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_TorqueVectoring;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_TorqueVectoring;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_TorqueVectoring;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_TorqueVectoring;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_TorqueVectoring;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_TorqueVectoring;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_TorqueVectoring;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.chartStateSetterFcn = NULL;
  chartInstance->chartInfo.chartStateGetterFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c21_JITStateAnimation,
    chartInstance->c21_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c21_TorqueVectoring(chartInstance);
}

void c21_TorqueVectoring_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c21_TorqueVectoring(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_TorqueVectoring(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_TorqueVectoring(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_TorqueVectoring_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
