/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) dt_model_constr_h_fun_jac_uxt_zt_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_clear CASADI_PREFIX(clear)
#define casadi_copy CASADI_PREFIX(copy)
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fill CASADI_PREFIX(fill)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

void casadi_copy(const casadi_real* x, casadi_int n, casadi_real* y) {
  casadi_int i;
  if (y) {
    if (x) {
      for (i=0; i<n; ++i) *y++ = *x++;
    } else {
      for (i=0; i<n; ++i) *y++ = 0.;
    }
  }
}

void casadi_clear(casadi_real* x, casadi_int n) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = 0;
  }
}

void casadi_fill(casadi_real* x, casadi_int n, casadi_real alpha) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}

static const casadi_int casadi_s0[8] = {4, 1, 0, 4, 0, 1, 2, 3};
static const casadi_int casadi_s1[3] = {0, 0, 0};
static const casadi_int casadi_s2[17] = {13, 1, 0, 13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
static const casadi_int casadi_s3[6] = {2, 1, 0, 2, 0, 1};
static const casadi_int casadi_s4[9] = {8, 2, 0, 2, 4, 4, 6, 5, 7};
static const casadi_int casadi_s5[5] = {0, 2, 0, 0, 0};

/* dt_model_constr_h_fun_jac_uxt_zt:(i0[4],i1[4],i2[],i3[13])->(o0[2],o1[8x2,4nz],o2[0x2]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real *rr, *ss;
  casadi_real *w0=w+0, w1, w2, w3, w4, w5, *w6=w+9, *w7=w+15, *w8=w+17;
  /* #0: @0 = input[0][0] */
  casadi_copy(arg[0], 4, w0);
  /* #1: @1 = @0[0] */
  for (rr=(&w1), ss=w0+0; ss!=w0+1; ss+=1) *rr++ = *ss;
  /* #2: @2 = @0[2] */
  for (rr=(&w2), ss=w0+2; ss!=w0+3; ss+=1) *rr++ = *ss;
  /* #3: @3 = (@1*@2) */
  w3  = (w1*w2);
  /* #4: output[0][0] = @3 */
  if (res[0]) res[0][0] = w3;
  /* #5: @3 = @0[1] */
  for (rr=(&w3), ss=w0+1; ss!=w0+2; ss+=1) *rr++ = *ss;
  /* #6: @4 = @0[3] */
  for (rr=(&w4), ss=w0+3; ss!=w0+4; ss+=1) *rr++ = *ss;
  /* #7: @5 = (@3*@4) */
  w5  = (w3*w4);
  /* #8: output[0][1] = @5 */
  if (res[0]) res[0][1] = w5;
  /* #9: @0 = zeros(8x2,4nz) */
  casadi_clear(w0, 4);
  /* #10: @6 = ones(8x1,6nz) */
  casadi_fill(w6, 6, 1.);
  /* #11: {NULL, @7} = vertsplit(@6) */
  casadi_copy(w6+4, 2, w7);
  /* #12: @5 = @7[0] */
  for (rr=(&w5), ss=w7+0; ss!=w7+1; ss+=1) *rr++ = *ss;
  /* #13: @2 = (@2*@5) */
  w2 *= w5;
  /* #14: @5 = @7[1] */
  for (rr=(&w5), ss=w7+1; ss!=w7+2; ss+=1) *rr++ = *ss;
  /* #15: @4 = (@4*@5) */
  w4 *= w5;
  /* #16: @7 = vertcat(@2, @4) */
  rr=w7;
  *rr++ = w2;
  *rr++ = w4;
  /* #17: (@0[:4:2] = @7) */
  for (rr=w0+0, ss=w7; rr!=w0+4; rr+=2) *rr = *ss++;
  /* #18: @7 = ones(8x1,2nz) */
  casadi_fill(w7, 2, 1.);
  /* #19: {NULL, @8} = vertsplit(@7) */
  casadi_copy(w7, 2, w8);
  /* #20: @2 = @8[0] */
  for (rr=(&w2), ss=w8+0; ss!=w8+1; ss+=1) *rr++ = *ss;
  /* #21: @1 = (@1*@2) */
  w1 *= w2;
  /* #22: @2 = @8[1] */
  for (rr=(&w2), ss=w8+1; ss!=w8+2; ss+=1) *rr++ = *ss;
  /* #23: @3 = (@3*@2) */
  w3 *= w2;
  /* #24: @8 = vertcat(@1, @3) */
  rr=w8;
  *rr++ = w1;
  *rr++ = w3;
  /* #25: (@0[1:5:2] = @8) */
  for (rr=w0+1, ss=w8; rr!=w0+5; rr+=2) *rr = *ss++;
  /* #26: output[1][0] = @0 */
  casadi_copy(w0, 4, res[1]);
  return 0;
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_jac_uxt_zt(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_jac_uxt_zt_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_jac_uxt_zt_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_fun_jac_uxt_zt_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_jac_uxt_zt_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_fun_jac_uxt_zt_release(int mem) {
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_fun_jac_uxt_zt_incref(void) {
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_fun_jac_uxt_zt_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int dt_model_constr_h_fun_jac_uxt_zt_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int dt_model_constr_h_fun_jac_uxt_zt_n_out(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_real dt_model_constr_h_fun_jac_uxt_zt_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* dt_model_constr_h_fun_jac_uxt_zt_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* dt_model_constr_h_fun_jac_uxt_zt_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    case 2: return "o2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* dt_model_constr_h_fun_jac_uxt_zt_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    case 3: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* dt_model_constr_h_fun_jac_uxt_zt_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s4;
    case 2: return casadi_s5;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_jac_uxt_zt_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 6;
  if (sz_res) *sz_res = 5;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 19;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif