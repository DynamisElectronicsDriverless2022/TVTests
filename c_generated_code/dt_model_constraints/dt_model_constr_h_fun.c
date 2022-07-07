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
  #define CASADI_PREFIX(ID) dt_model_constr_h_fun_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fmax CASADI_PREFIX(fmax)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_sq CASADI_PREFIX(sq)

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

casadi_real casadi_sq(casadi_real x) { return x*x;}

casadi_real casadi_fmax(casadi_real x, casadi_real y) {
/* Pre-c99 compatibility */
#if __STDC_VERSION__ < 199901L
  return x>y ? x : y;
#else
  return fmax(x, y);
#endif
}

static const casadi_int casadi_s0[11] = {7, 1, 0, 7, 0, 1, 2, 3, 4, 5, 6};
static const casadi_int casadi_s1[8] = {4, 1, 0, 4, 0, 1, 2, 3};
static const casadi_int casadi_s2[3] = {0, 0, 0};
static const casadi_int casadi_s3[22] = {18, 1, 0, 18, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
static const casadi_int casadi_s4[10] = {6, 1, 0, 6, 0, 1, 2, 3, 4, 5};

/* dt_model_constr_h_fun:(i0[7],i1[4],i2[],i3[18])->(o0[6]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real w0, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10;
  /* #0: @0 = input[0][3] */
  w0 = arg[0] ? arg[0][3] : 0;
  /* #1: @1 = input[0][4] */
  w1 = arg[0] ? arg[0][4] : 0;
  /* #2: @2 = (@0+@1) */
  w2  = (w0+w1);
  /* #3: @3 = input[0][5] */
  w3 = arg[0] ? arg[0][5] : 0;
  /* #4: @2 = (@2+@3) */
  w2 += w3;
  /* #5: @4 = input[0][6] */
  w4 = arg[0] ? arg[0][6] : 0;
  /* #6: @2 = (@2+@4) */
  w2 += w4;
  /* #7: output[0][0] = @2 */
  if (res[0]) res[0][0] = w2;
  /* #8: @2 = input[3][13] */
  w2 = arg[3] ? arg[3][13] : 0;
  /* #9: @5 = (@2*@0) */
  w5  = (w2*w0);
  /* #10: @6 = 0.7189 */
  w6 = 7.1889999999999998e-001;
  /* #11: @7 = 0.06443 */
  w7 = 6.4430000000000001e-002;
  /* #12: @8 = fabs(@0) */
  w8 = fabs( w0 );
  /* #13: @7 = (@7*@8) */
  w7 *= w8;
  /* #14: @6 = (@6+@7) */
  w6 += w7;
  /* #15: @7 = 0.0001287 */
  w7 = 1.2870000000000001e-004;
  /* #16: @7 = (@7*@2) */
  w7 *= w2;
  /* #17: @6 = (@6+@7) */
  w6 += w7;
  /* #18: @7 = -0.0128 */
  w7 = -1.2800000000000001e-002;
  /* #19: @9 = sq(@0) */
  w9 = casadi_sq( w0 );
  /* #20: @7 = (@7*@9) */
  w7 *= w9;
  /* #21: @6 = (@6+@7) */
  w6 += w7;
  /* #22: @7 = 9.544e-005 */
  w7 = 9.5439999999999994e-005;
  /* #23: @7 = (@7*@8) */
  w7 *= w8;
  /* #24: @7 = (@7*@2) */
  w7 *= w2;
  /* #25: @6 = (@6+@7) */
  w6 += w7;
  /* #26: @7 = -8.738e-007 */
  w7 = -8.7380000000000000e-007;
  /* #27: @9 = sq(@2) */
  w9 = casadi_sq( w2 );
  /* #28: @7 = (@7*@9) */
  w7 *= w9;
  /* #29: @6 = (@6+@7) */
  w6 += w7;
  /* #30: @7 = 0.0009902 */
  w7 = 9.9020000000000011e-004;
  /* #31: @9 = 3 */
  w9 = 3.;
  /* #32: @9 = pow(@8,@9) */
  w9  = pow(w8,w9);
  /* #33: @7 = (@7*@9) */
  w7 *= w9;
  /* #34: @6 = (@6+@7) */
  w6 += w7;
  /* #35: @7 = -6.784e-006 */
  w7 = -6.7839999999999998e-006;
  /* #36: @9 = sq(@0) */
  w9 = casadi_sq( w0 );
  /* #37: @7 = (@7*@9) */
  w7 *= w9;
  /* #38: @7 = (@7*@2) */
  w7 *= w2;
  /* #39: @6 = (@6+@7) */
  w6 += w7;
  /* #40: @7 = -2.146e-008 */
  w7 = -2.1460000000000002e-008;
  /* #41: @7 = (@7*@8) */
  w7 *= w8;
  /* #42: @9 = sq(@2) */
  w9 = casadi_sq( w2 );
  /* #43: @7 = (@7*@9) */
  w7 *= w9;
  /* #44: @6 = (@6+@7) */
  w6 += w7;
  /* #45: @7 = 8.018e-010 */
  w7 = 8.0179999999999996e-010;
  /* #46: @9 = 3 */
  w9 = 3.;
  /* #47: @9 = pow(@2,@9) */
  w9  = pow(w2,w9);
  /* #48: @7 = (@7*@9) */
  w7 *= w9;
  /* #49: @6 = (@6+@7) */
  w6 += w7;
  /* #50: @7 = -3.737e-005 */
  w7 = -3.7370000000000003e-005;
  /* #51: @9 = 4 */
  w9 = 4.;
  /* #52: @9 = pow(@8,@9) */
  w9  = pow(w8,w9);
  /* #53: @7 = (@7*@9) */
  w7 *= w9;
  /* #54: @6 = (@6+@7) */
  w6 += w7;
  /* #55: @7 = 3.242e-007 */
  w7 = 3.2420000000000000e-007;
  /* #56: @9 = 3 */
  w9 = 3.;
  /* #57: @9 = pow(@8,@9) */
  w9  = pow(w8,w9);
  /* #58: @7 = (@7*@9) */
  w7 *= w9;
  /* #59: @7 = (@7*@2) */
  w7 *= w2;
  /* #60: @6 = (@6+@7) */
  w6 += w7;
  /* #61: @7 = -4.019e-010 */
  w7 = -4.0189999999999998e-010;
  /* #62: @9 = sq(@0) */
  w9 = casadi_sq( w0 );
  /* #63: @7 = (@7*@9) */
  w7 *= w9;
  /* #64: @9 = sq(@2) */
  w9 = casadi_sq( w2 );
  /* #65: @7 = (@7*@9) */
  w7 *= w9;
  /* #66: @6 = (@6+@7) */
  w6 += w7;
  /* #67: @7 = 9.786e-012 */
  w7 = 9.7860000000000005e-012;
  /* #68: @7 = (@7*@8) */
  w7 *= w8;
  /* #69: @9 = 3 */
  w9 = 3.;
  /* #70: @9 = pow(@2,@9) */
  w9  = pow(w2,w9);
  /* #71: @7 = (@7*@9) */
  w7 *= w9;
  /* #72: @6 = (@6+@7) */
  w6 += w7;
  /* #73: @7 = -3.44e-013 */
  w7 = -3.4400000000000000e-013;
  /* #74: @9 = 4 */
  w9 = 4.;
  /* #75: @9 = pow(@2,@9) */
  w9  = pow(w2,w9);
  /* #76: @7 = (@7*@9) */
  w7 *= w9;
  /* #77: @6 = (@6+@7) */
  w6 += w7;
  /* #78: @7 = 5.334e-007 */
  w7 = 5.3340000000000005e-007;
  /* #79: @9 = 5 */
  w9 = 5.;
  /* #80: @9 = pow(@8,@9) */
  w9  = pow(w8,w9);
  /* #81: @7 = (@7*@9) */
  w7 *= w9;
  /* #82: @6 = (@6+@7) */
  w6 += w7;
  /* #83: @7 = -5.236e-009 */
  w7 = -5.2359999999999997e-009;
  /* #84: @9 = 4 */
  w9 = 4.;
  /* #85: @9 = pow(@8,@9) */
  w9  = pow(w8,w9);
  /* #86: @7 = (@7*@9) */
  w7 *= w9;
  /* #87: @7 = (@7*@2) */
  w7 *= w2;
  /* #88: @6 = (@6+@7) */
  w6 += w7;
  /* #89: @7 = -4.411e-014 */
  w7 = -4.4110000000000001e-014;
  /* #90: @9 = 3 */
  w9 = 3.;
  /* #91: @9 = pow(@8,@9) */
  w9  = pow(w8,w9);
  /* #92: @7 = (@7*@9) */
  w7 *= w9;
  /* #93: @9 = sq(@2) */
  w9 = casadi_sq( w2 );
  /* #94: @7 = (@7*@9) */
  w7 *= w9;
  /* #95: @6 = (@6+@7) */
  w6 += w7;
  /* #96: @7 = 1.035e-013 */
  w7 = 1.0350000000000000e-013;
  /* #97: @9 = sq(@0) */
  w9 = casadi_sq( w0 );
  /* #98: @7 = (@7*@9) */
  w7 *= w9;
  /* #99: @9 = 3 */
  w9 = 3.;
  /* #100: @9 = pow(@2,@9) */
  w9  = pow(w2,w9);
  /* #101: @7 = (@7*@9) */
  w7 *= w9;
  /* #102: @6 = (@6+@7) */
  w6 += w7;
  /* #103: @7 = -1.745e-015 */
  w7 = -1.7450000000000000e-015;
  /* #104: @7 = (@7*@8) */
  w7 *= w8;
  /* #105: @8 = 4 */
  w8 = 4.;
  /* #106: @8 = pow(@2,@8) */
  w8  = pow(w2,w8);
  /* #107: @7 = (@7*@8) */
  w7 *= w8;
  /* #108: @6 = (@6+@7) */
  w6 += w7;
  /* #109: @7 = 5.581e-017 */
  w7 = 5.5810000000000001e-017;
  /* #110: @8 = 5 */
  w8 = 5.;
  /* #111: @2 = pow(@2,@8) */
  w2  = pow(w2,w8);
  /* #112: @7 = (@7*@2) */
  w7 *= w2;
  /* #113: @6 = (@6+@7) */
  w6 += w7;
  /* #114: @7 = 0.3 */
  w7 = 2.9999999999999999e-001;
  /* #115: @6 = fmax(@6,@7) */
  w6  = casadi_fmax(w6,w7);
  /* #116: @5 = (@5/@6) */
  w5 /= w6;
  /* #117: @6 = input[3][14] */
  w6 = arg[3] ? arg[3][14] : 0;
  /* #118: @7 = (@6*@1) */
  w7  = (w6*w1);
  /* #119: @2 = 0.7189 */
  w2 = 7.1889999999999998e-001;
  /* #120: @8 = 0.06443 */
  w8 = 6.4430000000000001e-002;
  /* #121: @9 = fabs(@1) */
  w9 = fabs( w1 );
  /* #122: @8 = (@8*@9) */
  w8 *= w9;
  /* #123: @2 = (@2+@8) */
  w2 += w8;
  /* #124: @8 = 0.0001287 */
  w8 = 1.2870000000000001e-004;
  /* #125: @8 = (@8*@6) */
  w8 *= w6;
  /* #126: @2 = (@2+@8) */
  w2 += w8;
  /* #127: @8 = -0.0128 */
  w8 = -1.2800000000000001e-002;
  /* #128: @10 = sq(@1) */
  w10 = casadi_sq( w1 );
  /* #129: @8 = (@8*@10) */
  w8 *= w10;
  /* #130: @2 = (@2+@8) */
  w2 += w8;
  /* #131: @8 = 9.544e-005 */
  w8 = 9.5439999999999994e-005;
  /* #132: @8 = (@8*@9) */
  w8 *= w9;
  /* #133: @8 = (@8*@6) */
  w8 *= w6;
  /* #134: @2 = (@2+@8) */
  w2 += w8;
  /* #135: @8 = -8.738e-007 */
  w8 = -8.7380000000000000e-007;
  /* #136: @10 = sq(@6) */
  w10 = casadi_sq( w6 );
  /* #137: @8 = (@8*@10) */
  w8 *= w10;
  /* #138: @2 = (@2+@8) */
  w2 += w8;
  /* #139: @8 = 0.0009902 */
  w8 = 9.9020000000000011e-004;
  /* #140: @10 = 3 */
  w10 = 3.;
  /* #141: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #142: @8 = (@8*@10) */
  w8 *= w10;
  /* #143: @2 = (@2+@8) */
  w2 += w8;
  /* #144: @8 = -6.784e-006 */
  w8 = -6.7839999999999998e-006;
  /* #145: @10 = sq(@1) */
  w10 = casadi_sq( w1 );
  /* #146: @8 = (@8*@10) */
  w8 *= w10;
  /* #147: @8 = (@8*@6) */
  w8 *= w6;
  /* #148: @2 = (@2+@8) */
  w2 += w8;
  /* #149: @8 = -2.146e-008 */
  w8 = -2.1460000000000002e-008;
  /* #150: @8 = (@8*@9) */
  w8 *= w9;
  /* #151: @10 = sq(@6) */
  w10 = casadi_sq( w6 );
  /* #152: @8 = (@8*@10) */
  w8 *= w10;
  /* #153: @2 = (@2+@8) */
  w2 += w8;
  /* #154: @8 = 8.018e-010 */
  w8 = 8.0179999999999996e-010;
  /* #155: @10 = 3 */
  w10 = 3.;
  /* #156: @10 = pow(@6,@10) */
  w10  = pow(w6,w10);
  /* #157: @8 = (@8*@10) */
  w8 *= w10;
  /* #158: @2 = (@2+@8) */
  w2 += w8;
  /* #159: @8 = -3.737e-005 */
  w8 = -3.7370000000000003e-005;
  /* #160: @10 = 4 */
  w10 = 4.;
  /* #161: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #162: @8 = (@8*@10) */
  w8 *= w10;
  /* #163: @2 = (@2+@8) */
  w2 += w8;
  /* #164: @8 = 3.242e-007 */
  w8 = 3.2420000000000000e-007;
  /* #165: @10 = 3 */
  w10 = 3.;
  /* #166: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #167: @8 = (@8*@10) */
  w8 *= w10;
  /* #168: @8 = (@8*@6) */
  w8 *= w6;
  /* #169: @2 = (@2+@8) */
  w2 += w8;
  /* #170: @8 = -4.019e-010 */
  w8 = -4.0189999999999998e-010;
  /* #171: @10 = sq(@1) */
  w10 = casadi_sq( w1 );
  /* #172: @8 = (@8*@10) */
  w8 *= w10;
  /* #173: @10 = sq(@6) */
  w10 = casadi_sq( w6 );
  /* #174: @8 = (@8*@10) */
  w8 *= w10;
  /* #175: @2 = (@2+@8) */
  w2 += w8;
  /* #176: @8 = 9.786e-012 */
  w8 = 9.7860000000000005e-012;
  /* #177: @8 = (@8*@9) */
  w8 *= w9;
  /* #178: @10 = 3 */
  w10 = 3.;
  /* #179: @10 = pow(@6,@10) */
  w10  = pow(w6,w10);
  /* #180: @8 = (@8*@10) */
  w8 *= w10;
  /* #181: @2 = (@2+@8) */
  w2 += w8;
  /* #182: @8 = -3.44e-013 */
  w8 = -3.4400000000000000e-013;
  /* #183: @10 = 4 */
  w10 = 4.;
  /* #184: @10 = pow(@6,@10) */
  w10  = pow(w6,w10);
  /* #185: @8 = (@8*@10) */
  w8 *= w10;
  /* #186: @2 = (@2+@8) */
  w2 += w8;
  /* #187: @8 = 5.334e-007 */
  w8 = 5.3340000000000005e-007;
  /* #188: @10 = 5 */
  w10 = 5.;
  /* #189: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #190: @8 = (@8*@10) */
  w8 *= w10;
  /* #191: @2 = (@2+@8) */
  w2 += w8;
  /* #192: @8 = -5.236e-009 */
  w8 = -5.2359999999999997e-009;
  /* #193: @10 = 4 */
  w10 = 4.;
  /* #194: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #195: @8 = (@8*@10) */
  w8 *= w10;
  /* #196: @8 = (@8*@6) */
  w8 *= w6;
  /* #197: @2 = (@2+@8) */
  w2 += w8;
  /* #198: @8 = -4.411e-014 */
  w8 = -4.4110000000000001e-014;
  /* #199: @10 = 3 */
  w10 = 3.;
  /* #200: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #201: @8 = (@8*@10) */
  w8 *= w10;
  /* #202: @10 = sq(@6) */
  w10 = casadi_sq( w6 );
  /* #203: @8 = (@8*@10) */
  w8 *= w10;
  /* #204: @2 = (@2+@8) */
  w2 += w8;
  /* #205: @8 = 1.035e-013 */
  w8 = 1.0350000000000000e-013;
  /* #206: @10 = sq(@1) */
  w10 = casadi_sq( w1 );
  /* #207: @8 = (@8*@10) */
  w8 *= w10;
  /* #208: @10 = 3 */
  w10 = 3.;
  /* #209: @10 = pow(@6,@10) */
  w10  = pow(w6,w10);
  /* #210: @8 = (@8*@10) */
  w8 *= w10;
  /* #211: @2 = (@2+@8) */
  w2 += w8;
  /* #212: @8 = -1.745e-015 */
  w8 = -1.7450000000000000e-015;
  /* #213: @8 = (@8*@9) */
  w8 *= w9;
  /* #214: @9 = 4 */
  w9 = 4.;
  /* #215: @9 = pow(@6,@9) */
  w9  = pow(w6,w9);
  /* #216: @8 = (@8*@9) */
  w8 *= w9;
  /* #217: @2 = (@2+@8) */
  w2 += w8;
  /* #218: @8 = 5.581e-017 */
  w8 = 5.5810000000000001e-017;
  /* #219: @9 = 5 */
  w9 = 5.;
  /* #220: @6 = pow(@6,@9) */
  w6  = pow(w6,w9);
  /* #221: @8 = (@8*@6) */
  w8 *= w6;
  /* #222: @2 = (@2+@8) */
  w2 += w8;
  /* #223: @8 = 0.3 */
  w8 = 2.9999999999999999e-001;
  /* #224: @2 = fmax(@2,@8) */
  w2  = casadi_fmax(w2,w8);
  /* #225: @7 = (@7/@2) */
  w7 /= w2;
  /* #226: @5 = (@5+@7) */
  w5 += w7;
  /* #227: @7 = input[3][15] */
  w7 = arg[3] ? arg[3][15] : 0;
  /* #228: @2 = (@7*@3) */
  w2  = (w7*w3);
  /* #229: @8 = 0.7189 */
  w8 = 7.1889999999999998e-001;
  /* #230: @6 = 0.06443 */
  w6 = 6.4430000000000001e-002;
  /* #231: @9 = fabs(@3) */
  w9 = fabs( w3 );
  /* #232: @6 = (@6*@9) */
  w6 *= w9;
  /* #233: @8 = (@8+@6) */
  w8 += w6;
  /* #234: @6 = 0.0001287 */
  w6 = 1.2870000000000001e-004;
  /* #235: @6 = (@6*@7) */
  w6 *= w7;
  /* #236: @8 = (@8+@6) */
  w8 += w6;
  /* #237: @6 = -0.0128 */
  w6 = -1.2800000000000001e-002;
  /* #238: @10 = sq(@3) */
  w10 = casadi_sq( w3 );
  /* #239: @6 = (@6*@10) */
  w6 *= w10;
  /* #240: @8 = (@8+@6) */
  w8 += w6;
  /* #241: @6 = 9.544e-005 */
  w6 = 9.5439999999999994e-005;
  /* #242: @6 = (@6*@9) */
  w6 *= w9;
  /* #243: @6 = (@6*@7) */
  w6 *= w7;
  /* #244: @8 = (@8+@6) */
  w8 += w6;
  /* #245: @6 = -8.738e-007 */
  w6 = -8.7380000000000000e-007;
  /* #246: @10 = sq(@7) */
  w10 = casadi_sq( w7 );
  /* #247: @6 = (@6*@10) */
  w6 *= w10;
  /* #248: @8 = (@8+@6) */
  w8 += w6;
  /* #249: @6 = 0.0009902 */
  w6 = 9.9020000000000011e-004;
  /* #250: @10 = 3 */
  w10 = 3.;
  /* #251: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #252: @6 = (@6*@10) */
  w6 *= w10;
  /* #253: @8 = (@8+@6) */
  w8 += w6;
  /* #254: @6 = -6.784e-006 */
  w6 = -6.7839999999999998e-006;
  /* #255: @10 = sq(@3) */
  w10 = casadi_sq( w3 );
  /* #256: @6 = (@6*@10) */
  w6 *= w10;
  /* #257: @6 = (@6*@7) */
  w6 *= w7;
  /* #258: @8 = (@8+@6) */
  w8 += w6;
  /* #259: @6 = -2.146e-008 */
  w6 = -2.1460000000000002e-008;
  /* #260: @6 = (@6*@9) */
  w6 *= w9;
  /* #261: @10 = sq(@7) */
  w10 = casadi_sq( w7 );
  /* #262: @6 = (@6*@10) */
  w6 *= w10;
  /* #263: @8 = (@8+@6) */
  w8 += w6;
  /* #264: @6 = 8.018e-010 */
  w6 = 8.0179999999999996e-010;
  /* #265: @10 = 3 */
  w10 = 3.;
  /* #266: @10 = pow(@7,@10) */
  w10  = pow(w7,w10);
  /* #267: @6 = (@6*@10) */
  w6 *= w10;
  /* #268: @8 = (@8+@6) */
  w8 += w6;
  /* #269: @6 = -3.737e-005 */
  w6 = -3.7370000000000003e-005;
  /* #270: @10 = 4 */
  w10 = 4.;
  /* #271: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #272: @6 = (@6*@10) */
  w6 *= w10;
  /* #273: @8 = (@8+@6) */
  w8 += w6;
  /* #274: @6 = 3.242e-007 */
  w6 = 3.2420000000000000e-007;
  /* #275: @10 = 3 */
  w10 = 3.;
  /* #276: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #277: @6 = (@6*@10) */
  w6 *= w10;
  /* #278: @6 = (@6*@7) */
  w6 *= w7;
  /* #279: @8 = (@8+@6) */
  w8 += w6;
  /* #280: @6 = -4.019e-010 */
  w6 = -4.0189999999999998e-010;
  /* #281: @10 = sq(@3) */
  w10 = casadi_sq( w3 );
  /* #282: @6 = (@6*@10) */
  w6 *= w10;
  /* #283: @10 = sq(@7) */
  w10 = casadi_sq( w7 );
  /* #284: @6 = (@6*@10) */
  w6 *= w10;
  /* #285: @8 = (@8+@6) */
  w8 += w6;
  /* #286: @6 = 9.786e-012 */
  w6 = 9.7860000000000005e-012;
  /* #287: @6 = (@6*@9) */
  w6 *= w9;
  /* #288: @10 = 3 */
  w10 = 3.;
  /* #289: @10 = pow(@7,@10) */
  w10  = pow(w7,w10);
  /* #290: @6 = (@6*@10) */
  w6 *= w10;
  /* #291: @8 = (@8+@6) */
  w8 += w6;
  /* #292: @6 = -3.44e-013 */
  w6 = -3.4400000000000000e-013;
  /* #293: @10 = 4 */
  w10 = 4.;
  /* #294: @10 = pow(@7,@10) */
  w10  = pow(w7,w10);
  /* #295: @6 = (@6*@10) */
  w6 *= w10;
  /* #296: @8 = (@8+@6) */
  w8 += w6;
  /* #297: @6 = 5.334e-007 */
  w6 = 5.3340000000000005e-007;
  /* #298: @10 = 5 */
  w10 = 5.;
  /* #299: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #300: @6 = (@6*@10) */
  w6 *= w10;
  /* #301: @8 = (@8+@6) */
  w8 += w6;
  /* #302: @6 = -5.236e-009 */
  w6 = -5.2359999999999997e-009;
  /* #303: @10 = 4 */
  w10 = 4.;
  /* #304: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #305: @6 = (@6*@10) */
  w6 *= w10;
  /* #306: @6 = (@6*@7) */
  w6 *= w7;
  /* #307: @8 = (@8+@6) */
  w8 += w6;
  /* #308: @6 = -4.411e-014 */
  w6 = -4.4110000000000001e-014;
  /* #309: @10 = 3 */
  w10 = 3.;
  /* #310: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #311: @6 = (@6*@10) */
  w6 *= w10;
  /* #312: @10 = sq(@7) */
  w10 = casadi_sq( w7 );
  /* #313: @6 = (@6*@10) */
  w6 *= w10;
  /* #314: @8 = (@8+@6) */
  w8 += w6;
  /* #315: @6 = 1.035e-013 */
  w6 = 1.0350000000000000e-013;
  /* #316: @10 = sq(@3) */
  w10 = casadi_sq( w3 );
  /* #317: @6 = (@6*@10) */
  w6 *= w10;
  /* #318: @10 = 3 */
  w10 = 3.;
  /* #319: @10 = pow(@7,@10) */
  w10  = pow(w7,w10);
  /* #320: @6 = (@6*@10) */
  w6 *= w10;
  /* #321: @8 = (@8+@6) */
  w8 += w6;
  /* #322: @6 = -1.745e-015 */
  w6 = -1.7450000000000000e-015;
  /* #323: @6 = (@6*@9) */
  w6 *= w9;
  /* #324: @9 = 4 */
  w9 = 4.;
  /* #325: @9 = pow(@7,@9) */
  w9  = pow(w7,w9);
  /* #326: @6 = (@6*@9) */
  w6 *= w9;
  /* #327: @8 = (@8+@6) */
  w8 += w6;
  /* #328: @6 = 5.581e-017 */
  w6 = 5.5810000000000001e-017;
  /* #329: @9 = 5 */
  w9 = 5.;
  /* #330: @7 = pow(@7,@9) */
  w7  = pow(w7,w9);
  /* #331: @6 = (@6*@7) */
  w6 *= w7;
  /* #332: @8 = (@8+@6) */
  w8 += w6;
  /* #333: @6 = 0.3 */
  w6 = 2.9999999999999999e-001;
  /* #334: @8 = fmax(@8,@6) */
  w8  = casadi_fmax(w8,w6);
  /* #335: @2 = (@2/@8) */
  w2 /= w8;
  /* #336: @5 = (@5+@2) */
  w5 += w2;
  /* #337: @2 = input[3][16] */
  w2 = arg[3] ? arg[3][16] : 0;
  /* #338: @8 = (@2*@4) */
  w8  = (w2*w4);
  /* #339: @6 = 0.7189 */
  w6 = 7.1889999999999998e-001;
  /* #340: @7 = 0.06443 */
  w7 = 6.4430000000000001e-002;
  /* #341: @9 = fabs(@4) */
  w9 = fabs( w4 );
  /* #342: @7 = (@7*@9) */
  w7 *= w9;
  /* #343: @6 = (@6+@7) */
  w6 += w7;
  /* #344: @7 = 0.0001287 */
  w7 = 1.2870000000000001e-004;
  /* #345: @7 = (@7*@2) */
  w7 *= w2;
  /* #346: @6 = (@6+@7) */
  w6 += w7;
  /* #347: @7 = -0.0128 */
  w7 = -1.2800000000000001e-002;
  /* #348: @10 = sq(@4) */
  w10 = casadi_sq( w4 );
  /* #349: @7 = (@7*@10) */
  w7 *= w10;
  /* #350: @6 = (@6+@7) */
  w6 += w7;
  /* #351: @7 = 9.544e-005 */
  w7 = 9.5439999999999994e-005;
  /* #352: @7 = (@7*@9) */
  w7 *= w9;
  /* #353: @7 = (@7*@2) */
  w7 *= w2;
  /* #354: @6 = (@6+@7) */
  w6 += w7;
  /* #355: @7 = -8.738e-007 */
  w7 = -8.7380000000000000e-007;
  /* #356: @10 = sq(@2) */
  w10 = casadi_sq( w2 );
  /* #357: @7 = (@7*@10) */
  w7 *= w10;
  /* #358: @6 = (@6+@7) */
  w6 += w7;
  /* #359: @7 = 0.0009902 */
  w7 = 9.9020000000000011e-004;
  /* #360: @10 = 3 */
  w10 = 3.;
  /* #361: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #362: @7 = (@7*@10) */
  w7 *= w10;
  /* #363: @6 = (@6+@7) */
  w6 += w7;
  /* #364: @7 = -6.784e-006 */
  w7 = -6.7839999999999998e-006;
  /* #365: @10 = sq(@4) */
  w10 = casadi_sq( w4 );
  /* #366: @7 = (@7*@10) */
  w7 *= w10;
  /* #367: @7 = (@7*@2) */
  w7 *= w2;
  /* #368: @6 = (@6+@7) */
  w6 += w7;
  /* #369: @7 = -2.146e-008 */
  w7 = -2.1460000000000002e-008;
  /* #370: @7 = (@7*@9) */
  w7 *= w9;
  /* #371: @10 = sq(@2) */
  w10 = casadi_sq( w2 );
  /* #372: @7 = (@7*@10) */
  w7 *= w10;
  /* #373: @6 = (@6+@7) */
  w6 += w7;
  /* #374: @7 = 8.018e-010 */
  w7 = 8.0179999999999996e-010;
  /* #375: @10 = 3 */
  w10 = 3.;
  /* #376: @10 = pow(@2,@10) */
  w10  = pow(w2,w10);
  /* #377: @7 = (@7*@10) */
  w7 *= w10;
  /* #378: @6 = (@6+@7) */
  w6 += w7;
  /* #379: @7 = -3.737e-005 */
  w7 = -3.7370000000000003e-005;
  /* #380: @10 = 4 */
  w10 = 4.;
  /* #381: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #382: @7 = (@7*@10) */
  w7 *= w10;
  /* #383: @6 = (@6+@7) */
  w6 += w7;
  /* #384: @7 = 3.242e-007 */
  w7 = 3.2420000000000000e-007;
  /* #385: @10 = 3 */
  w10 = 3.;
  /* #386: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #387: @7 = (@7*@10) */
  w7 *= w10;
  /* #388: @7 = (@7*@2) */
  w7 *= w2;
  /* #389: @6 = (@6+@7) */
  w6 += w7;
  /* #390: @7 = -4.019e-010 */
  w7 = -4.0189999999999998e-010;
  /* #391: @10 = sq(@4) */
  w10 = casadi_sq( w4 );
  /* #392: @7 = (@7*@10) */
  w7 *= w10;
  /* #393: @10 = sq(@2) */
  w10 = casadi_sq( w2 );
  /* #394: @7 = (@7*@10) */
  w7 *= w10;
  /* #395: @6 = (@6+@7) */
  w6 += w7;
  /* #396: @7 = 9.786e-012 */
  w7 = 9.7860000000000005e-012;
  /* #397: @7 = (@7*@9) */
  w7 *= w9;
  /* #398: @10 = 3 */
  w10 = 3.;
  /* #399: @10 = pow(@2,@10) */
  w10  = pow(w2,w10);
  /* #400: @7 = (@7*@10) */
  w7 *= w10;
  /* #401: @6 = (@6+@7) */
  w6 += w7;
  /* #402: @7 = -3.44e-013 */
  w7 = -3.4400000000000000e-013;
  /* #403: @10 = 4 */
  w10 = 4.;
  /* #404: @10 = pow(@2,@10) */
  w10  = pow(w2,w10);
  /* #405: @7 = (@7*@10) */
  w7 *= w10;
  /* #406: @6 = (@6+@7) */
  w6 += w7;
  /* #407: @7 = 5.334e-007 */
  w7 = 5.3340000000000005e-007;
  /* #408: @10 = 5 */
  w10 = 5.;
  /* #409: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #410: @7 = (@7*@10) */
  w7 *= w10;
  /* #411: @6 = (@6+@7) */
  w6 += w7;
  /* #412: @7 = -5.236e-009 */
  w7 = -5.2359999999999997e-009;
  /* #413: @10 = 4 */
  w10 = 4.;
  /* #414: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #415: @7 = (@7*@10) */
  w7 *= w10;
  /* #416: @7 = (@7*@2) */
  w7 *= w2;
  /* #417: @6 = (@6+@7) */
  w6 += w7;
  /* #418: @7 = -4.411e-014 */
  w7 = -4.4110000000000001e-014;
  /* #419: @10 = 3 */
  w10 = 3.;
  /* #420: @10 = pow(@9,@10) */
  w10  = pow(w9,w10);
  /* #421: @7 = (@7*@10) */
  w7 *= w10;
  /* #422: @10 = sq(@2) */
  w10 = casadi_sq( w2 );
  /* #423: @7 = (@7*@10) */
  w7 *= w10;
  /* #424: @6 = (@6+@7) */
  w6 += w7;
  /* #425: @7 = 1.035e-013 */
  w7 = 1.0350000000000000e-013;
  /* #426: @10 = sq(@4) */
  w10 = casadi_sq( w4 );
  /* #427: @7 = (@7*@10) */
  w7 *= w10;
  /* #428: @10 = 3 */
  w10 = 3.;
  /* #429: @10 = pow(@2,@10) */
  w10  = pow(w2,w10);
  /* #430: @7 = (@7*@10) */
  w7 *= w10;
  /* #431: @6 = (@6+@7) */
  w6 += w7;
  /* #432: @7 = -1.745e-015 */
  w7 = -1.7450000000000000e-015;
  /* #433: @7 = (@7*@9) */
  w7 *= w9;
  /* #434: @9 = 4 */
  w9 = 4.;
  /* #435: @9 = pow(@2,@9) */
  w9  = pow(w2,w9);
  /* #436: @7 = (@7*@9) */
  w7 *= w9;
  /* #437: @6 = (@6+@7) */
  w6 += w7;
  /* #438: @7 = 5.581e-017 */
  w7 = 5.5810000000000001e-017;
  /* #439: @9 = 5 */
  w9 = 5.;
  /* #440: @2 = pow(@2,@9) */
  w2  = pow(w2,w9);
  /* #441: @7 = (@7*@2) */
  w7 *= w2;
  /* #442: @6 = (@6+@7) */
  w6 += w7;
  /* #443: @7 = 0.3 */
  w7 = 2.9999999999999999e-001;
  /* #444: @6 = fmax(@6,@7) */
  w6  = casadi_fmax(w6,w7);
  /* #445: @8 = (@8/@6) */
  w8 /= w6;
  /* #446: @5 = (@5+@8) */
  w5 += w8;
  /* #447: @8 = 0.95 */
  w8 = 9.4999999999999996e-001;
  /* #448: @5 = (@5/@8) */
  w5 /= w8;
  /* #449: @8 = 1000 */
  w8 = 1000.;
  /* #450: @5 = (@5/@8) */
  w5 /= w8;
  /* #451: @8 = 0.9 */
  w8 = 9.0000000000000002e-001;
  /* #452: @5 = (@5/@8) */
  w5 /= w8;
  /* #453: output[0][1] = @5 */
  if (res[0]) res[0][1] = w5;
  /* #454: @5 = (@1-@4) */
  w5  = (w1-w4);
  /* #455: output[0][2] = @5 */
  if (res[0]) res[0][2] = w5;
  /* #456: @5 = (@0-@3) */
  w5  = (w0-w3);
  /* #457: output[0][3] = @5 */
  if (res[0]) res[0][3] = w5;
  /* #458: @5 = 0.7497 */
  w5 = 7.4970000000000003e-001;
  /* #459: @8 = input[3][0] */
  w8 = arg[3] ? arg[3][0] : 0;
  /* #460: @6 = sin(@8) */
  w6 = sin( w8 );
  /* #461: @5 = (@5*@6) */
  w5 *= w6;
  /* #462: @6 = 0.635 */
  w6 = 6.3500000000000001e-001;
  /* #463: @7 = cos(@8) */
  w7 = cos( w8 );
  /* #464: @6 = (@6*@7) */
  w6 *= w7;
  /* #465: @5 = (@5-@6) */
  w5 -= w6;
  /* #466: @5 = (@5*@0) */
  w5 *= w0;
  /* #467: @0 = 0.7497 */
  w0 = 7.4970000000000003e-001;
  /* #468: @6 = sin(@8) */
  w6 = sin( w8 );
  /* #469: @0 = (@0*@6) */
  w0 *= w6;
  /* #470: @6 = 0.635 */
  w6 = 6.3500000000000001e-001;
  /* #471: @7 = cos(@8) */
  w7 = cos( w8 );
  /* #472: @6 = (@6*@7) */
  w6 *= w7;
  /* #473: @0 = (@0+@6) */
  w0 += w6;
  /* #474: @0 = (@0*@1) */
  w0 *= w1;
  /* #475: @5 = (@5+@0) */
  w5 += w0;
  /* #476: @0 = -0.635 */
  w0 = -6.3500000000000001e-001;
  /* #477: @0 = (@0*@3) */
  w0 *= w3;
  /* #478: @5 = (@5+@0) */
  w5 += w0;
  /* #479: @0 = 0.635 */
  w0 = 6.3500000000000001e-001;
  /* #480: @0 = (@0*@4) */
  w0 *= w4;
  /* #481: @5 = (@5+@0) */
  w5 += w0;
  /* #482: output[0][4] = @5 */
  if (res[0]) res[0][4] = w5;
  /* #483: @5 = 0.7497 */
  w5 = 7.4970000000000003e-001;
  /* #484: @0 = sin(@8) */
  w0 = sin( w8 );
  /* #485: @5 = (@5*@0) */
  w5 *= w0;
  /* #486: @0 = 0.635 */
  w0 = 6.3500000000000001e-001;
  /* #487: @4 = cos(@8) */
  w4 = cos( w8 );
  /* #488: @0 = (@0*@4) */
  w0 *= w4;
  /* #489: @5 = (@5-@0) */
  w5 -= w0;
  /* #490: @0 = input[1][0] */
  w0 = arg[1] ? arg[1][0] : 0;
  /* #491: @5 = (@5*@0) */
  w5 *= w0;
  /* #492: @0 = 0.7497 */
  w0 = 7.4970000000000003e-001;
  /* #493: @4 = sin(@8) */
  w4 = sin( w8 );
  /* #494: @0 = (@0*@4) */
  w0 *= w4;
  /* #495: @4 = 0.635 */
  w4 = 6.3500000000000001e-001;
  /* #496: @8 = cos(@8) */
  w8 = cos( w8 );
  /* #497: @4 = (@4*@8) */
  w4 *= w8;
  /* #498: @0 = (@0+@4) */
  w0 += w4;
  /* #499: @4 = input[1][1] */
  w4 = arg[1] ? arg[1][1] : 0;
  /* #500: @0 = (@0*@4) */
  w0 *= w4;
  /* #501: @5 = (@5+@0) */
  w5 += w0;
  /* #502: @0 = -0.635 */
  w0 = -6.3500000000000001e-001;
  /* #503: @4 = input[1][2] */
  w4 = arg[1] ? arg[1][2] : 0;
  /* #504: @0 = (@0*@4) */
  w0 *= w4;
  /* #505: @5 = (@5+@0) */
  w5 += w0;
  /* #506: @0 = 0.635 */
  w0 = 6.3500000000000001e-001;
  /* #507: @4 = input[1][3] */
  w4 = arg[1] ? arg[1][3] : 0;
  /* #508: @0 = (@0*@4) */
  w0 *= w4;
  /* #509: @5 = (@5+@0) */
  w5 += w0;
  /* #510: output[0][5] = @5 */
  if (res[0]) res[0][5] = w5;
  return 0;
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_fun_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_fun_release(int mem) {
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_fun_incref(void) {
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_fun_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int dt_model_constr_h_fun_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int dt_model_constr_h_fun_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real dt_model_constr_h_fun_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* dt_model_constr_h_fun_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* dt_model_constr_h_fun_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* dt_model_constr_h_fun_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    case 2: return casadi_s2;
    case 3: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* dt_model_constr_h_fun_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_fun_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 6;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 11;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
