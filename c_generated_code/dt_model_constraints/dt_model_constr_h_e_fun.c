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
  #define CASADI_PREFIX(ID) dt_model_constr_h_e_fun_ ## ID
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
static const casadi_int casadi_s1[22] = {18, 1, 0, 18, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
static const casadi_int casadi_s2[5] = {1, 1, 0, 1, 0};

/* dt_model_constr_h_e_fun:(i0[7],i1[18])->(o0) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real w0, w1, w2, w3, w4, w5, w6, w7;
  /* #0: @0 = input[1][13] */
  w0 = arg[1] ? arg[1][13] : 0;
  /* #1: @1 = input[0][3] */
  w1 = arg[0] ? arg[0][3] : 0;
  /* #2: @2 = (@0*@1) */
  w2  = (w0*w1);
  /* #3: @3 = 0.7189 */
  w3 = 7.1889999999999998e-001;
  /* #4: @4 = 0.06443 */
  w4 = 6.4430000000000001e-002;
  /* #5: @5 = fabs(@1) */
  w5 = fabs( w1 );
  /* #6: @4 = (@4*@5) */
  w4 *= w5;
  /* #7: @3 = (@3+@4) */
  w3 += w4;
  /* #8: @4 = 0.0001287 */
  w4 = 1.2870000000000001e-004;
  /* #9: @4 = (@4*@0) */
  w4 *= w0;
  /* #10: @3 = (@3+@4) */
  w3 += w4;
  /* #11: @4 = -0.0128 */
  w4 = -1.2800000000000001e-002;
  /* #12: @6 = sq(@1) */
  w6 = casadi_sq( w1 );
  /* #13: @4 = (@4*@6) */
  w4 *= w6;
  /* #14: @3 = (@3+@4) */
  w3 += w4;
  /* #15: @4 = 9.544e-005 */
  w4 = 9.5439999999999994e-005;
  /* #16: @4 = (@4*@5) */
  w4 *= w5;
  /* #17: @4 = (@4*@0) */
  w4 *= w0;
  /* #18: @3 = (@3+@4) */
  w3 += w4;
  /* #19: @4 = -8.738e-007 */
  w4 = -8.7380000000000000e-007;
  /* #20: @6 = sq(@0) */
  w6 = casadi_sq( w0 );
  /* #21: @4 = (@4*@6) */
  w4 *= w6;
  /* #22: @3 = (@3+@4) */
  w3 += w4;
  /* #23: @4 = 0.0009902 */
  w4 = 9.9020000000000011e-004;
  /* #24: @6 = 3 */
  w6 = 3.;
  /* #25: @6 = pow(@5,@6) */
  w6  = pow(w5,w6);
  /* #26: @4 = (@4*@6) */
  w4 *= w6;
  /* #27: @3 = (@3+@4) */
  w3 += w4;
  /* #28: @4 = -6.784e-006 */
  w4 = -6.7839999999999998e-006;
  /* #29: @6 = sq(@1) */
  w6 = casadi_sq( w1 );
  /* #30: @4 = (@4*@6) */
  w4 *= w6;
  /* #31: @4 = (@4*@0) */
  w4 *= w0;
  /* #32: @3 = (@3+@4) */
  w3 += w4;
  /* #33: @4 = -2.146e-008 */
  w4 = -2.1460000000000002e-008;
  /* #34: @4 = (@4*@5) */
  w4 *= w5;
  /* #35: @6 = sq(@0) */
  w6 = casadi_sq( w0 );
  /* #36: @4 = (@4*@6) */
  w4 *= w6;
  /* #37: @3 = (@3+@4) */
  w3 += w4;
  /* #38: @4 = 8.018e-010 */
  w4 = 8.0179999999999996e-010;
  /* #39: @6 = 3 */
  w6 = 3.;
  /* #40: @6 = pow(@0,@6) */
  w6  = pow(w0,w6);
  /* #41: @4 = (@4*@6) */
  w4 *= w6;
  /* #42: @3 = (@3+@4) */
  w3 += w4;
  /* #43: @4 = -3.737e-005 */
  w4 = -3.7370000000000003e-005;
  /* #44: @6 = 4 */
  w6 = 4.;
  /* #45: @6 = pow(@5,@6) */
  w6  = pow(w5,w6);
  /* #46: @4 = (@4*@6) */
  w4 *= w6;
  /* #47: @3 = (@3+@4) */
  w3 += w4;
  /* #48: @4 = 3.242e-007 */
  w4 = 3.2420000000000000e-007;
  /* #49: @6 = 3 */
  w6 = 3.;
  /* #50: @6 = pow(@5,@6) */
  w6  = pow(w5,w6);
  /* #51: @4 = (@4*@6) */
  w4 *= w6;
  /* #52: @4 = (@4*@0) */
  w4 *= w0;
  /* #53: @3 = (@3+@4) */
  w3 += w4;
  /* #54: @4 = -4.019e-010 */
  w4 = -4.0189999999999998e-010;
  /* #55: @6 = sq(@1) */
  w6 = casadi_sq( w1 );
  /* #56: @4 = (@4*@6) */
  w4 *= w6;
  /* #57: @6 = sq(@0) */
  w6 = casadi_sq( w0 );
  /* #58: @4 = (@4*@6) */
  w4 *= w6;
  /* #59: @3 = (@3+@4) */
  w3 += w4;
  /* #60: @4 = 9.786e-012 */
  w4 = 9.7860000000000005e-012;
  /* #61: @4 = (@4*@5) */
  w4 *= w5;
  /* #62: @6 = 3 */
  w6 = 3.;
  /* #63: @6 = pow(@0,@6) */
  w6  = pow(w0,w6);
  /* #64: @4 = (@4*@6) */
  w4 *= w6;
  /* #65: @3 = (@3+@4) */
  w3 += w4;
  /* #66: @4 = -3.44e-013 */
  w4 = -3.4400000000000000e-013;
  /* #67: @6 = 4 */
  w6 = 4.;
  /* #68: @6 = pow(@0,@6) */
  w6  = pow(w0,w6);
  /* #69: @4 = (@4*@6) */
  w4 *= w6;
  /* #70: @3 = (@3+@4) */
  w3 += w4;
  /* #71: @4 = 5.334e-007 */
  w4 = 5.3340000000000005e-007;
  /* #72: @6 = 5 */
  w6 = 5.;
  /* #73: @6 = pow(@5,@6) */
  w6  = pow(w5,w6);
  /* #74: @4 = (@4*@6) */
  w4 *= w6;
  /* #75: @3 = (@3+@4) */
  w3 += w4;
  /* #76: @4 = -5.236e-009 */
  w4 = -5.2359999999999997e-009;
  /* #77: @6 = 4 */
  w6 = 4.;
  /* #78: @6 = pow(@5,@6) */
  w6  = pow(w5,w6);
  /* #79: @4 = (@4*@6) */
  w4 *= w6;
  /* #80: @4 = (@4*@0) */
  w4 *= w0;
  /* #81: @3 = (@3+@4) */
  w3 += w4;
  /* #82: @4 = -4.411e-014 */
  w4 = -4.4110000000000001e-014;
  /* #83: @6 = 3 */
  w6 = 3.;
  /* #84: @6 = pow(@5,@6) */
  w6  = pow(w5,w6);
  /* #85: @4 = (@4*@6) */
  w4 *= w6;
  /* #86: @6 = sq(@0) */
  w6 = casadi_sq( w0 );
  /* #87: @4 = (@4*@6) */
  w4 *= w6;
  /* #88: @3 = (@3+@4) */
  w3 += w4;
  /* #89: @4 = 1.035e-013 */
  w4 = 1.0350000000000000e-013;
  /* #90: @1 = sq(@1) */
  w1 = casadi_sq( w1 );
  /* #91: @4 = (@4*@1) */
  w4 *= w1;
  /* #92: @1 = 3 */
  w1 = 3.;
  /* #93: @1 = pow(@0,@1) */
  w1  = pow(w0,w1);
  /* #94: @4 = (@4*@1) */
  w4 *= w1;
  /* #95: @3 = (@3+@4) */
  w3 += w4;
  /* #96: @4 = -1.745e-015 */
  w4 = -1.7450000000000000e-015;
  /* #97: @4 = (@4*@5) */
  w4 *= w5;
  /* #98: @5 = 4 */
  w5 = 4.;
  /* #99: @5 = pow(@0,@5) */
  w5  = pow(w0,w5);
  /* #100: @4 = (@4*@5) */
  w4 *= w5;
  /* #101: @3 = (@3+@4) */
  w3 += w4;
  /* #102: @4 = 5.581e-017 */
  w4 = 5.5810000000000001e-017;
  /* #103: @5 = 5 */
  w5 = 5.;
  /* #104: @0 = pow(@0,@5) */
  w0  = pow(w0,w5);
  /* #105: @4 = (@4*@0) */
  w4 *= w0;
  /* #106: @3 = (@3+@4) */
  w3 += w4;
  /* #107: @4 = 0.3 */
  w4 = 2.9999999999999999e-001;
  /* #108: @3 = fmax(@3,@4) */
  w3  = casadi_fmax(w3,w4);
  /* #109: @2 = (@2/@3) */
  w2 /= w3;
  /* #110: @3 = input[1][14] */
  w3 = arg[1] ? arg[1][14] : 0;
  /* #111: @4 = input[0][4] */
  w4 = arg[0] ? arg[0][4] : 0;
  /* #112: @0 = (@3*@4) */
  w0  = (w3*w4);
  /* #113: @5 = 0.7189 */
  w5 = 7.1889999999999998e-001;
  /* #114: @1 = 0.06443 */
  w1 = 6.4430000000000001e-002;
  /* #115: @6 = fabs(@4) */
  w6 = fabs( w4 );
  /* #116: @1 = (@1*@6) */
  w1 *= w6;
  /* #117: @5 = (@5+@1) */
  w5 += w1;
  /* #118: @1 = 0.0001287 */
  w1 = 1.2870000000000001e-004;
  /* #119: @1 = (@1*@3) */
  w1 *= w3;
  /* #120: @5 = (@5+@1) */
  w5 += w1;
  /* #121: @1 = -0.0128 */
  w1 = -1.2800000000000001e-002;
  /* #122: @7 = sq(@4) */
  w7 = casadi_sq( w4 );
  /* #123: @1 = (@1*@7) */
  w1 *= w7;
  /* #124: @5 = (@5+@1) */
  w5 += w1;
  /* #125: @1 = 9.544e-005 */
  w1 = 9.5439999999999994e-005;
  /* #126: @1 = (@1*@6) */
  w1 *= w6;
  /* #127: @1 = (@1*@3) */
  w1 *= w3;
  /* #128: @5 = (@5+@1) */
  w5 += w1;
  /* #129: @1 = -8.738e-007 */
  w1 = -8.7380000000000000e-007;
  /* #130: @7 = sq(@3) */
  w7 = casadi_sq( w3 );
  /* #131: @1 = (@1*@7) */
  w1 *= w7;
  /* #132: @5 = (@5+@1) */
  w5 += w1;
  /* #133: @1 = 0.0009902 */
  w1 = 9.9020000000000011e-004;
  /* #134: @7 = 3 */
  w7 = 3.;
  /* #135: @7 = pow(@6,@7) */
  w7  = pow(w6,w7);
  /* #136: @1 = (@1*@7) */
  w1 *= w7;
  /* #137: @5 = (@5+@1) */
  w5 += w1;
  /* #138: @1 = -6.784e-006 */
  w1 = -6.7839999999999998e-006;
  /* #139: @7 = sq(@4) */
  w7 = casadi_sq( w4 );
  /* #140: @1 = (@1*@7) */
  w1 *= w7;
  /* #141: @1 = (@1*@3) */
  w1 *= w3;
  /* #142: @5 = (@5+@1) */
  w5 += w1;
  /* #143: @1 = -2.146e-008 */
  w1 = -2.1460000000000002e-008;
  /* #144: @1 = (@1*@6) */
  w1 *= w6;
  /* #145: @7 = sq(@3) */
  w7 = casadi_sq( w3 );
  /* #146: @1 = (@1*@7) */
  w1 *= w7;
  /* #147: @5 = (@5+@1) */
  w5 += w1;
  /* #148: @1 = 8.018e-010 */
  w1 = 8.0179999999999996e-010;
  /* #149: @7 = 3 */
  w7 = 3.;
  /* #150: @7 = pow(@3,@7) */
  w7  = pow(w3,w7);
  /* #151: @1 = (@1*@7) */
  w1 *= w7;
  /* #152: @5 = (@5+@1) */
  w5 += w1;
  /* #153: @1 = -3.737e-005 */
  w1 = -3.7370000000000003e-005;
  /* #154: @7 = 4 */
  w7 = 4.;
  /* #155: @7 = pow(@6,@7) */
  w7  = pow(w6,w7);
  /* #156: @1 = (@1*@7) */
  w1 *= w7;
  /* #157: @5 = (@5+@1) */
  w5 += w1;
  /* #158: @1 = 3.242e-007 */
  w1 = 3.2420000000000000e-007;
  /* #159: @7 = 3 */
  w7 = 3.;
  /* #160: @7 = pow(@6,@7) */
  w7  = pow(w6,w7);
  /* #161: @1 = (@1*@7) */
  w1 *= w7;
  /* #162: @1 = (@1*@3) */
  w1 *= w3;
  /* #163: @5 = (@5+@1) */
  w5 += w1;
  /* #164: @1 = -4.019e-010 */
  w1 = -4.0189999999999998e-010;
  /* #165: @7 = sq(@4) */
  w7 = casadi_sq( w4 );
  /* #166: @1 = (@1*@7) */
  w1 *= w7;
  /* #167: @7 = sq(@3) */
  w7 = casadi_sq( w3 );
  /* #168: @1 = (@1*@7) */
  w1 *= w7;
  /* #169: @5 = (@5+@1) */
  w5 += w1;
  /* #170: @1 = 9.786e-012 */
  w1 = 9.7860000000000005e-012;
  /* #171: @1 = (@1*@6) */
  w1 *= w6;
  /* #172: @7 = 3 */
  w7 = 3.;
  /* #173: @7 = pow(@3,@7) */
  w7  = pow(w3,w7);
  /* #174: @1 = (@1*@7) */
  w1 *= w7;
  /* #175: @5 = (@5+@1) */
  w5 += w1;
  /* #176: @1 = -3.44e-013 */
  w1 = -3.4400000000000000e-013;
  /* #177: @7 = 4 */
  w7 = 4.;
  /* #178: @7 = pow(@3,@7) */
  w7  = pow(w3,w7);
  /* #179: @1 = (@1*@7) */
  w1 *= w7;
  /* #180: @5 = (@5+@1) */
  w5 += w1;
  /* #181: @1 = 5.334e-007 */
  w1 = 5.3340000000000005e-007;
  /* #182: @7 = 5 */
  w7 = 5.;
  /* #183: @7 = pow(@6,@7) */
  w7  = pow(w6,w7);
  /* #184: @1 = (@1*@7) */
  w1 *= w7;
  /* #185: @5 = (@5+@1) */
  w5 += w1;
  /* #186: @1 = -5.236e-009 */
  w1 = -5.2359999999999997e-009;
  /* #187: @7 = 4 */
  w7 = 4.;
  /* #188: @7 = pow(@6,@7) */
  w7  = pow(w6,w7);
  /* #189: @1 = (@1*@7) */
  w1 *= w7;
  /* #190: @1 = (@1*@3) */
  w1 *= w3;
  /* #191: @5 = (@5+@1) */
  w5 += w1;
  /* #192: @1 = -4.411e-014 */
  w1 = -4.4110000000000001e-014;
  /* #193: @7 = 3 */
  w7 = 3.;
  /* #194: @7 = pow(@6,@7) */
  w7  = pow(w6,w7);
  /* #195: @1 = (@1*@7) */
  w1 *= w7;
  /* #196: @7 = sq(@3) */
  w7 = casadi_sq( w3 );
  /* #197: @1 = (@1*@7) */
  w1 *= w7;
  /* #198: @5 = (@5+@1) */
  w5 += w1;
  /* #199: @1 = 1.035e-013 */
  w1 = 1.0350000000000000e-013;
  /* #200: @4 = sq(@4) */
  w4 = casadi_sq( w4 );
  /* #201: @1 = (@1*@4) */
  w1 *= w4;
  /* #202: @4 = 3 */
  w4 = 3.;
  /* #203: @4 = pow(@3,@4) */
  w4  = pow(w3,w4);
  /* #204: @1 = (@1*@4) */
  w1 *= w4;
  /* #205: @5 = (@5+@1) */
  w5 += w1;
  /* #206: @1 = -1.745e-015 */
  w1 = -1.7450000000000000e-015;
  /* #207: @1 = (@1*@6) */
  w1 *= w6;
  /* #208: @6 = 4 */
  w6 = 4.;
  /* #209: @6 = pow(@3,@6) */
  w6  = pow(w3,w6);
  /* #210: @1 = (@1*@6) */
  w1 *= w6;
  /* #211: @5 = (@5+@1) */
  w5 += w1;
  /* #212: @1 = 5.581e-017 */
  w1 = 5.5810000000000001e-017;
  /* #213: @6 = 5 */
  w6 = 5.;
  /* #214: @3 = pow(@3,@6) */
  w3  = pow(w3,w6);
  /* #215: @1 = (@1*@3) */
  w1 *= w3;
  /* #216: @5 = (@5+@1) */
  w5 += w1;
  /* #217: @1 = 0.3 */
  w1 = 2.9999999999999999e-001;
  /* #218: @5 = fmax(@5,@1) */
  w5  = casadi_fmax(w5,w1);
  /* #219: @0 = (@0/@5) */
  w0 /= w5;
  /* #220: @2 = (@2+@0) */
  w2 += w0;
  /* #221: @0 = input[1][15] */
  w0 = arg[1] ? arg[1][15] : 0;
  /* #222: @5 = input[0][5] */
  w5 = arg[0] ? arg[0][5] : 0;
  /* #223: @1 = (@0*@5) */
  w1  = (w0*w5);
  /* #224: @3 = 0.7189 */
  w3 = 7.1889999999999998e-001;
  /* #225: @6 = 0.06443 */
  w6 = 6.4430000000000001e-002;
  /* #226: @4 = fabs(@5) */
  w4 = fabs( w5 );
  /* #227: @6 = (@6*@4) */
  w6 *= w4;
  /* #228: @3 = (@3+@6) */
  w3 += w6;
  /* #229: @6 = 0.0001287 */
  w6 = 1.2870000000000001e-004;
  /* #230: @6 = (@6*@0) */
  w6 *= w0;
  /* #231: @3 = (@3+@6) */
  w3 += w6;
  /* #232: @6 = -0.0128 */
  w6 = -1.2800000000000001e-002;
  /* #233: @7 = sq(@5) */
  w7 = casadi_sq( w5 );
  /* #234: @6 = (@6*@7) */
  w6 *= w7;
  /* #235: @3 = (@3+@6) */
  w3 += w6;
  /* #236: @6 = 9.544e-005 */
  w6 = 9.5439999999999994e-005;
  /* #237: @6 = (@6*@4) */
  w6 *= w4;
  /* #238: @6 = (@6*@0) */
  w6 *= w0;
  /* #239: @3 = (@3+@6) */
  w3 += w6;
  /* #240: @6 = -8.738e-007 */
  w6 = -8.7380000000000000e-007;
  /* #241: @7 = sq(@0) */
  w7 = casadi_sq( w0 );
  /* #242: @6 = (@6*@7) */
  w6 *= w7;
  /* #243: @3 = (@3+@6) */
  w3 += w6;
  /* #244: @6 = 0.0009902 */
  w6 = 9.9020000000000011e-004;
  /* #245: @7 = 3 */
  w7 = 3.;
  /* #246: @7 = pow(@4,@7) */
  w7  = pow(w4,w7);
  /* #247: @6 = (@6*@7) */
  w6 *= w7;
  /* #248: @3 = (@3+@6) */
  w3 += w6;
  /* #249: @6 = -6.784e-006 */
  w6 = -6.7839999999999998e-006;
  /* #250: @7 = sq(@5) */
  w7 = casadi_sq( w5 );
  /* #251: @6 = (@6*@7) */
  w6 *= w7;
  /* #252: @6 = (@6*@0) */
  w6 *= w0;
  /* #253: @3 = (@3+@6) */
  w3 += w6;
  /* #254: @6 = -2.146e-008 */
  w6 = -2.1460000000000002e-008;
  /* #255: @6 = (@6*@4) */
  w6 *= w4;
  /* #256: @7 = sq(@0) */
  w7 = casadi_sq( w0 );
  /* #257: @6 = (@6*@7) */
  w6 *= w7;
  /* #258: @3 = (@3+@6) */
  w3 += w6;
  /* #259: @6 = 8.018e-010 */
  w6 = 8.0179999999999996e-010;
  /* #260: @7 = 3 */
  w7 = 3.;
  /* #261: @7 = pow(@0,@7) */
  w7  = pow(w0,w7);
  /* #262: @6 = (@6*@7) */
  w6 *= w7;
  /* #263: @3 = (@3+@6) */
  w3 += w6;
  /* #264: @6 = -3.737e-005 */
  w6 = -3.7370000000000003e-005;
  /* #265: @7 = 4 */
  w7 = 4.;
  /* #266: @7 = pow(@4,@7) */
  w7  = pow(w4,w7);
  /* #267: @6 = (@6*@7) */
  w6 *= w7;
  /* #268: @3 = (@3+@6) */
  w3 += w6;
  /* #269: @6 = 3.242e-007 */
  w6 = 3.2420000000000000e-007;
  /* #270: @7 = 3 */
  w7 = 3.;
  /* #271: @7 = pow(@4,@7) */
  w7  = pow(w4,w7);
  /* #272: @6 = (@6*@7) */
  w6 *= w7;
  /* #273: @6 = (@6*@0) */
  w6 *= w0;
  /* #274: @3 = (@3+@6) */
  w3 += w6;
  /* #275: @6 = -4.019e-010 */
  w6 = -4.0189999999999998e-010;
  /* #276: @7 = sq(@5) */
  w7 = casadi_sq( w5 );
  /* #277: @6 = (@6*@7) */
  w6 *= w7;
  /* #278: @7 = sq(@0) */
  w7 = casadi_sq( w0 );
  /* #279: @6 = (@6*@7) */
  w6 *= w7;
  /* #280: @3 = (@3+@6) */
  w3 += w6;
  /* #281: @6 = 9.786e-012 */
  w6 = 9.7860000000000005e-012;
  /* #282: @6 = (@6*@4) */
  w6 *= w4;
  /* #283: @7 = 3 */
  w7 = 3.;
  /* #284: @7 = pow(@0,@7) */
  w7  = pow(w0,w7);
  /* #285: @6 = (@6*@7) */
  w6 *= w7;
  /* #286: @3 = (@3+@6) */
  w3 += w6;
  /* #287: @6 = -3.44e-013 */
  w6 = -3.4400000000000000e-013;
  /* #288: @7 = 4 */
  w7 = 4.;
  /* #289: @7 = pow(@0,@7) */
  w7  = pow(w0,w7);
  /* #290: @6 = (@6*@7) */
  w6 *= w7;
  /* #291: @3 = (@3+@6) */
  w3 += w6;
  /* #292: @6 = 5.334e-007 */
  w6 = 5.3340000000000005e-007;
  /* #293: @7 = 5 */
  w7 = 5.;
  /* #294: @7 = pow(@4,@7) */
  w7  = pow(w4,w7);
  /* #295: @6 = (@6*@7) */
  w6 *= w7;
  /* #296: @3 = (@3+@6) */
  w3 += w6;
  /* #297: @6 = -5.236e-009 */
  w6 = -5.2359999999999997e-009;
  /* #298: @7 = 4 */
  w7 = 4.;
  /* #299: @7 = pow(@4,@7) */
  w7  = pow(w4,w7);
  /* #300: @6 = (@6*@7) */
  w6 *= w7;
  /* #301: @6 = (@6*@0) */
  w6 *= w0;
  /* #302: @3 = (@3+@6) */
  w3 += w6;
  /* #303: @6 = -4.411e-014 */
  w6 = -4.4110000000000001e-014;
  /* #304: @7 = 3 */
  w7 = 3.;
  /* #305: @7 = pow(@4,@7) */
  w7  = pow(w4,w7);
  /* #306: @6 = (@6*@7) */
  w6 *= w7;
  /* #307: @7 = sq(@0) */
  w7 = casadi_sq( w0 );
  /* #308: @6 = (@6*@7) */
  w6 *= w7;
  /* #309: @3 = (@3+@6) */
  w3 += w6;
  /* #310: @6 = 1.035e-013 */
  w6 = 1.0350000000000000e-013;
  /* #311: @5 = sq(@5) */
  w5 = casadi_sq( w5 );
  /* #312: @6 = (@6*@5) */
  w6 *= w5;
  /* #313: @5 = 3 */
  w5 = 3.;
  /* #314: @5 = pow(@0,@5) */
  w5  = pow(w0,w5);
  /* #315: @6 = (@6*@5) */
  w6 *= w5;
  /* #316: @3 = (@3+@6) */
  w3 += w6;
  /* #317: @6 = -1.745e-015 */
  w6 = -1.7450000000000000e-015;
  /* #318: @6 = (@6*@4) */
  w6 *= w4;
  /* #319: @4 = 4 */
  w4 = 4.;
  /* #320: @4 = pow(@0,@4) */
  w4  = pow(w0,w4);
  /* #321: @6 = (@6*@4) */
  w6 *= w4;
  /* #322: @3 = (@3+@6) */
  w3 += w6;
  /* #323: @6 = 5.581e-017 */
  w6 = 5.5810000000000001e-017;
  /* #324: @4 = 5 */
  w4 = 5.;
  /* #325: @0 = pow(@0,@4) */
  w0  = pow(w0,w4);
  /* #326: @6 = (@6*@0) */
  w6 *= w0;
  /* #327: @3 = (@3+@6) */
  w3 += w6;
  /* #328: @6 = 0.3 */
  w6 = 2.9999999999999999e-001;
  /* #329: @3 = fmax(@3,@6) */
  w3  = casadi_fmax(w3,w6);
  /* #330: @1 = (@1/@3) */
  w1 /= w3;
  /* #331: @2 = (@2+@1) */
  w2 += w1;
  /* #332: @1 = input[1][16] */
  w1 = arg[1] ? arg[1][16] : 0;
  /* #333: @3 = input[0][6] */
  w3 = arg[0] ? arg[0][6] : 0;
  /* #334: @6 = (@1*@3) */
  w6  = (w1*w3);
  /* #335: @0 = 0.7189 */
  w0 = 7.1889999999999998e-001;
  /* #336: @4 = 0.06443 */
  w4 = 6.4430000000000001e-002;
  /* #337: @5 = fabs(@3) */
  w5 = fabs( w3 );
  /* #338: @4 = (@4*@5) */
  w4 *= w5;
  /* #339: @0 = (@0+@4) */
  w0 += w4;
  /* #340: @4 = 0.0001287 */
  w4 = 1.2870000000000001e-004;
  /* #341: @4 = (@4*@1) */
  w4 *= w1;
  /* #342: @0 = (@0+@4) */
  w0 += w4;
  /* #343: @4 = -0.0128 */
  w4 = -1.2800000000000001e-002;
  /* #344: @7 = sq(@3) */
  w7 = casadi_sq( w3 );
  /* #345: @4 = (@4*@7) */
  w4 *= w7;
  /* #346: @0 = (@0+@4) */
  w0 += w4;
  /* #347: @4 = 9.544e-005 */
  w4 = 9.5439999999999994e-005;
  /* #348: @4 = (@4*@5) */
  w4 *= w5;
  /* #349: @4 = (@4*@1) */
  w4 *= w1;
  /* #350: @0 = (@0+@4) */
  w0 += w4;
  /* #351: @4 = -8.738e-007 */
  w4 = -8.7380000000000000e-007;
  /* #352: @7 = sq(@1) */
  w7 = casadi_sq( w1 );
  /* #353: @4 = (@4*@7) */
  w4 *= w7;
  /* #354: @0 = (@0+@4) */
  w0 += w4;
  /* #355: @4 = 0.0009902 */
  w4 = 9.9020000000000011e-004;
  /* #356: @7 = 3 */
  w7 = 3.;
  /* #357: @7 = pow(@5,@7) */
  w7  = pow(w5,w7);
  /* #358: @4 = (@4*@7) */
  w4 *= w7;
  /* #359: @0 = (@0+@4) */
  w0 += w4;
  /* #360: @4 = -6.784e-006 */
  w4 = -6.7839999999999998e-006;
  /* #361: @7 = sq(@3) */
  w7 = casadi_sq( w3 );
  /* #362: @4 = (@4*@7) */
  w4 *= w7;
  /* #363: @4 = (@4*@1) */
  w4 *= w1;
  /* #364: @0 = (@0+@4) */
  w0 += w4;
  /* #365: @4 = -2.146e-008 */
  w4 = -2.1460000000000002e-008;
  /* #366: @4 = (@4*@5) */
  w4 *= w5;
  /* #367: @7 = sq(@1) */
  w7 = casadi_sq( w1 );
  /* #368: @4 = (@4*@7) */
  w4 *= w7;
  /* #369: @0 = (@0+@4) */
  w0 += w4;
  /* #370: @4 = 8.018e-010 */
  w4 = 8.0179999999999996e-010;
  /* #371: @7 = 3 */
  w7 = 3.;
  /* #372: @7 = pow(@1,@7) */
  w7  = pow(w1,w7);
  /* #373: @4 = (@4*@7) */
  w4 *= w7;
  /* #374: @0 = (@0+@4) */
  w0 += w4;
  /* #375: @4 = -3.737e-005 */
  w4 = -3.7370000000000003e-005;
  /* #376: @7 = 4 */
  w7 = 4.;
  /* #377: @7 = pow(@5,@7) */
  w7  = pow(w5,w7);
  /* #378: @4 = (@4*@7) */
  w4 *= w7;
  /* #379: @0 = (@0+@4) */
  w0 += w4;
  /* #380: @4 = 3.242e-007 */
  w4 = 3.2420000000000000e-007;
  /* #381: @7 = 3 */
  w7 = 3.;
  /* #382: @7 = pow(@5,@7) */
  w7  = pow(w5,w7);
  /* #383: @4 = (@4*@7) */
  w4 *= w7;
  /* #384: @4 = (@4*@1) */
  w4 *= w1;
  /* #385: @0 = (@0+@4) */
  w0 += w4;
  /* #386: @4 = -4.019e-010 */
  w4 = -4.0189999999999998e-010;
  /* #387: @7 = sq(@3) */
  w7 = casadi_sq( w3 );
  /* #388: @4 = (@4*@7) */
  w4 *= w7;
  /* #389: @7 = sq(@1) */
  w7 = casadi_sq( w1 );
  /* #390: @4 = (@4*@7) */
  w4 *= w7;
  /* #391: @0 = (@0+@4) */
  w0 += w4;
  /* #392: @4 = 9.786e-012 */
  w4 = 9.7860000000000005e-012;
  /* #393: @4 = (@4*@5) */
  w4 *= w5;
  /* #394: @7 = 3 */
  w7 = 3.;
  /* #395: @7 = pow(@1,@7) */
  w7  = pow(w1,w7);
  /* #396: @4 = (@4*@7) */
  w4 *= w7;
  /* #397: @0 = (@0+@4) */
  w0 += w4;
  /* #398: @4 = -3.44e-013 */
  w4 = -3.4400000000000000e-013;
  /* #399: @7 = 4 */
  w7 = 4.;
  /* #400: @7 = pow(@1,@7) */
  w7  = pow(w1,w7);
  /* #401: @4 = (@4*@7) */
  w4 *= w7;
  /* #402: @0 = (@0+@4) */
  w0 += w4;
  /* #403: @4 = 5.334e-007 */
  w4 = 5.3340000000000005e-007;
  /* #404: @7 = 5 */
  w7 = 5.;
  /* #405: @7 = pow(@5,@7) */
  w7  = pow(w5,w7);
  /* #406: @4 = (@4*@7) */
  w4 *= w7;
  /* #407: @0 = (@0+@4) */
  w0 += w4;
  /* #408: @4 = -5.236e-009 */
  w4 = -5.2359999999999997e-009;
  /* #409: @7 = 4 */
  w7 = 4.;
  /* #410: @7 = pow(@5,@7) */
  w7  = pow(w5,w7);
  /* #411: @4 = (@4*@7) */
  w4 *= w7;
  /* #412: @4 = (@4*@1) */
  w4 *= w1;
  /* #413: @0 = (@0+@4) */
  w0 += w4;
  /* #414: @4 = -4.411e-014 */
  w4 = -4.4110000000000001e-014;
  /* #415: @7 = 3 */
  w7 = 3.;
  /* #416: @7 = pow(@5,@7) */
  w7  = pow(w5,w7);
  /* #417: @4 = (@4*@7) */
  w4 *= w7;
  /* #418: @7 = sq(@1) */
  w7 = casadi_sq( w1 );
  /* #419: @4 = (@4*@7) */
  w4 *= w7;
  /* #420: @0 = (@0+@4) */
  w0 += w4;
  /* #421: @4 = 1.035e-013 */
  w4 = 1.0350000000000000e-013;
  /* #422: @3 = sq(@3) */
  w3 = casadi_sq( w3 );
  /* #423: @4 = (@4*@3) */
  w4 *= w3;
  /* #424: @3 = 3 */
  w3 = 3.;
  /* #425: @3 = pow(@1,@3) */
  w3  = pow(w1,w3);
  /* #426: @4 = (@4*@3) */
  w4 *= w3;
  /* #427: @0 = (@0+@4) */
  w0 += w4;
  /* #428: @4 = -1.745e-015 */
  w4 = -1.7450000000000000e-015;
  /* #429: @4 = (@4*@5) */
  w4 *= w5;
  /* #430: @5 = 4 */
  w5 = 4.;
  /* #431: @5 = pow(@1,@5) */
  w5  = pow(w1,w5);
  /* #432: @4 = (@4*@5) */
  w4 *= w5;
  /* #433: @0 = (@0+@4) */
  w0 += w4;
  /* #434: @4 = 5.581e-017 */
  w4 = 5.5810000000000001e-017;
  /* #435: @5 = 5 */
  w5 = 5.;
  /* #436: @1 = pow(@1,@5) */
  w1  = pow(w1,w5);
  /* #437: @4 = (@4*@1) */
  w4 *= w1;
  /* #438: @0 = (@0+@4) */
  w0 += w4;
  /* #439: @4 = 0.3 */
  w4 = 2.9999999999999999e-001;
  /* #440: @0 = fmax(@0,@4) */
  w0  = casadi_fmax(w0,w4);
  /* #441: @6 = (@6/@0) */
  w6 /= w0;
  /* #442: @2 = (@2+@6) */
  w2 += w6;
  /* #443: output[0][0] = @2 */
  if (res[0]) res[0][0] = w2;
  return 0;
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_e_fun(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_e_fun_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_e_fun_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_e_fun_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_e_fun_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_e_fun_release(int mem) {
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_e_fun_incref(void) {
}

CASADI_SYMBOL_EXPORT void dt_model_constr_h_e_fun_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int dt_model_constr_h_e_fun_n_in(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_int dt_model_constr_h_e_fun_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real dt_model_constr_h_e_fun_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* dt_model_constr_h_e_fun_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* dt_model_constr_h_e_fun_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* dt_model_constr_h_e_fun_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* dt_model_constr_h_e_fun_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int dt_model_constr_h_e_fun_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 4;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 8;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif