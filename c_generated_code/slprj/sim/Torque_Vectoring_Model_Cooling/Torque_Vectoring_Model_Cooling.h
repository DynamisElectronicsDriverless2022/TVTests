#ifndef RTW_HEADER_Torque_Vectoring_Model_Cooling_h_
#define RTW_HEADER_Torque_Vectoring_Model_Cooling_h_
#ifndef Torque_Vectoring_Model_Cooling_COMMON_INCLUDES_
#define Torque_Vectoring_Model_Cooling_COMMON_INCLUDES_
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "Torque_Vectoring_Model_Cooling_types.h"
#include <stddef.h>
#include <string.h>
#include "model_reference_types.h"
#include "rtGetInf.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
typedef struct { int8_T fpjiixhyl5 ; } acgv3qwvn1 ; typedef struct { int8_T
p2o4a4dw11 ; } cwt52jx01h ; typedef struct { int8_T df54wvvk40 ; } pcxhrguynk
; typedef struct { int8_T m3ocyz4afo ; } kt4wn1c5ml ; typedef struct { real_T
ociu2143ll [ 4 ] ; real_T b1xpup50vt ; real_T im0ohmfgrp ; real_T bcudb1w2on
; real_T aowmfadp1i ; real_T af4ilctdr5 [ 2 ] ; real_T ha5h5ubmuo ; real_T
kpylo533xf [ 4 ] ; real_T ildtwr3340 [ 4 ] ; real_T oolituaia0 [ 39 ] ;
real_T nkmofyxdce [ 7 ] ; real_T lksqt0uz1s [ 8 ] ; real_T g41jphkfl3 [ 8 ] ;
real_T pkzrt24uj2 [ 4 ] ; real_T mjxigy2kgy ; real_T jybrsuyeez ; real_T
hw4yn5vm0z [ 3 ] ; real_T ast3kmkjgt ; real_T g5as2ajofs ; real_T hzrvyrotoy
[ 4 ] ; real_T etwsq5nryw [ 4 ] ; real_T hjtf5at1g3 ; real_T b0ysmtiugu ;
real_T holaxblqic ; real_T lmzwkacgpj ; real_T fogmmhrnz1 [ 4 ] ; real_T
klsfjqpubp ; real_T pybcom0x0y ; real_T oswwfw5ckr ; real_T jva4buackr ;
real_T abn3fmscih [ 49 ] ; real_T gou1055a3w [ 16 ] ; real_T e1swqiu14u ;
real_T iaqpuaxl5p ; int16_T lwc4lhfmbh ; boolean_T ndowumugm4 ; boolean_T
dqevgzuzvn [ 2 ] ; } geuopffatc ; typedef struct { plkhuy0dou g4tv3f0akx ;
plkhuy0douz ovwmrd32ys ; zGeneral_Params kfggldxldy ; real_T cekljt2ymr [ 4 ]
; real_T pdxgxplqmn ; real_T n1da0wcaf3 ; real_T gwxz5m5c00 ; real_T
nx2hykgwlx ; real_T krjzmknqx5 ; real_T gvyx1brndr ; real_T bgdtgcb4oy ;
real_T ae3zmggup2 [ 4 ] ; real_T hajatyzjx5 ; real_T ejjut2mdfk [ 4 ] ;
real_T gxkoi0s2qq ; real_T ab4t1tor20 ; real_T c45cn1mdtd ; real_T jcm1wmdwhf
; real_T fgclyjpjwk ; real_T b42byfdhdy ; real_T bunz4kaihu ; real_T
chdydi0k1s ; real_T kptm3bljr4 [ 4 ] ; real_T gx1ndprmob [ 4 ] ; real_T
gmhkkh0xp5 [ 4 ] ; real_T jkahtwx3fg ; real_T apdt0pxhdv ; real_T crfcaejq3l
[ 4 ] ; real_T dxdcockk1a ; real_T jp45u1vjc2 ; real_T ictxzlkfs0 ; real_T
jljlt2kni4 ; real_T djxwhd5b53 ; real_T htkqhugtpq ; real_T esrldc02v0 ;
real_T dkbkwpw1v3 ; real_T diq1jsi0wv ; real_T i1skx0tnh3 ; real_T dfwijsup0g
; real_T jswdjcfcul [ 4 ] ; real_T m1qagzy0os [ 4 ] ; zMap_Params daspjzebk0
; struct { void * AQHandles [ 62 ] ; } ppbn3rykje ; struct { void * AQHandles
; } i4of1oetxr ; struct { void * AQHandles ; } i1mlg3stwv ; struct { void *
AQHandles ; } pemwjiuijy ; struct { void * AQHandles ; } bohppfm4wz ; struct
{ void * AQHandles ; } m4zhl01g05 ; struct { void * AQHandles ; } ktefutlkde
; struct { void * AQHandles ; } mgcbcgtc0v ; struct { void * AQHandles ; }
a1umnwfaal ; struct { void * AQHandles ; } imovlchy2i ; struct { void *
AQHandles ; } i1mlg3stwvt ; struct { void * AQHandles ; } psbbg5qtrt ; struct
{ void * AQHandles ; } henaaz2fpc ; struct { void * AQHandles ; }
i1mlg3stwvt0 ; int32_T eivhquhkdw ; int32_T i1l0bqw5lx ; int16_T dgsobaf5wq [
9 ] ; boolean_T gfjyfh03up ; boolean_T o4w5h0xslh [ 5 ] ; int8_T ojygcufbe5 ;
int8_T l3rxy3oz3v ; int8_T hmjv3rztkk ; int8_T ohlcvohqcu ; int8_T ikwgolg1up
; int8_T oqcd3cplaf ; uint8_T cajoa3xw3i ; uint8_T kb3u2lebap ; uint8_T
mrcx23zqpp ; uint8_T pemggequ4r ; uint8_T evsdu2vxpl ; boolean_T jyzr1fg3ex ;
boolean_T gbzir14yz1 ; boolean_T bma04vx3ef ; kt4wn1c5ml k2qa4dutqw ;
pcxhrguynk jtklenszl2 ; cwt52jx01h il54uu1pjc ; acgv3qwvn1 dl4mqb4pfs ;
kt4wn1c5ml olrlhhrjjg0 ; pcxhrguynk i54nxukymky ; cwt52jx01h pwa0sx1vmmq ;
acgv3qwvn1 kymnflaougc ; } mgp55fs13f ; typedef struct { real_T inywxj3phd ;
real_T o0bszejbom ; real_T e4b4ty00oh ; real_T izf2sqtdun ; real_T czus4khhe5
; real_T dfm0kp31sv ; } lietroj0em ; typedef struct { real_T inywxj3phd ;
real_T o0bszejbom ; real_T e4b4ty00oh ; real_T izf2sqtdun ; real_T czus4khhe5
; real_T dfm0kp31sv ; } j4t221w5my ; typedef struct { boolean_T inywxj3phd ;
boolean_T o0bszejbom ; boolean_T e4b4ty00oh ; boolean_T izf2sqtdun ;
boolean_T czus4khhe5 ; boolean_T dfm0kp31sv ; } bx1k22h5pf ; struct
aleiimaknm_ { real_T P_0 ; real_T P_1 ; real_T P_2 [ 10000 ] ; real_T P_3 [
100 ] ; real_T P_4 [ 100 ] ; uint32_T P_5 [ 2 ] ; } ; struct a2pektskpt_ {
real_T P_0 ; real_T P_1 ; real_T P_2 [ 10000 ] ; real_T P_3 [ 100 ] ; real_T
P_4 [ 100 ] ; uint32_T P_5 [ 2 ] ; } ; struct gmdp13mlne_ { real_T P_0 ;
real_T P_1 ; real_T P_2 [ 10000 ] ; real_T P_3 [ 100 ] ; real_T P_4 [ 100 ] ;
uint32_T P_5 [ 2 ] ; } ; struct p4acrmrl1n_ { real_T P_0 ; real_T P_1 ;
real_T P_2 [ 10000 ] ; real_T P_3 [ 100 ] ; real_T P_4 [ 100 ] ; uint32_T P_5
[ 2 ] ; } ; struct ms4e4ssiy0o_ { real_T P_1 ; real_T P_2 ; boolean_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 [ 2 ] ; real_T P_11 ; real_T P_12 ; real_T P_13 [ 3 ] ; real_T
P_14 [ 3 ] ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T
P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ;
real_T P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T
P_30 ; real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ;
real_T P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T
P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ;
real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 [ 3 ] ; real_T P_51 [ 3
] ; real_T P_52 [ 3 ] ; real_T P_53 [ 3 ] ; real_T P_54 [ 3 ] ; real_T P_55 [
3 ] ; real_T P_56 ; real_T P_57 ; real_T P_58 [ 9246 ] ; real_T P_59 [ 201 ]
; real_T P_60 [ 46 ] ; real_T P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64
; real_T P_65 ; real_T P_66 ; real_T P_67 ; real_T P_68 ; real_T P_69 ;
real_T P_70 ; real_T P_71 ; real_T P_72 ; real_T P_73 ; real_T P_74 ; real_T
P_75 [ 3 ] ; real_T P_76 [ 3 ] ; real_T P_77 [ 3 ] ; real_T P_78 [ 3 ] ;
real_T P_79 [ 3 ] ; real_T P_80 [ 3 ] ; real_T P_81 ; real_T P_82 ; real_T
P_83 [ 20 ] ; real_T P_84 [ 20 ] ; real_T P_85 [ 9246 ] ; real_T P_86 [ 201 ]
; real_T P_87 [ 46 ] ; real_T P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91
; real_T P_92 ; real_T P_93 ; real_T P_94 ; real_T P_95 ; real_T P_96 ;
real_T P_97 ; real_T P_98 ; real_T P_99 ; real_T P_100 ; real_T P_101 ;
real_T P_102 ; real_T P_103 ; real_T P_104 ; real_T P_105 ; real_T P_106 ;
real_T P_107 ; real_T P_108 [ 5 ] ; real_T P_109 ; real_T P_110 ; real_T
P_111 ; real_T P_112 ; real_T P_113 ; real_T P_114 ; real_T P_115 ; real_T
P_116 [ 4 ] ; real_T P_117 [ 4 ] ; real_T P_118 ; real_T P_119 ; real_T P_120
; real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ; real_T P_125 ;
real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ; real_T P_130 ;
real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ; real_T P_135 ;
real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T P_139 ; real_T P_140 ;
real_T P_141 ; real_T P_142 ; real_T P_143 ; real_T P_144 ; real_T P_145 ;
real_T P_146 ; real_T P_147 ; real_T P_148 ; real_T P_149 ; real_T P_150 ;
real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T P_154 ; real_T P_155 ;
real_T P_156 ; real_T P_157 ; real_T P_158 ; real_T P_159 ; real_T P_160 ;
real_T P_161 [ 3 ] ; real_T P_162 [ 3 ] ; real_T P_163 [ 3 ] ; real_T P_164 [
3 ] ; real_T P_165 ; real_T P_166 ; real_T P_167 ; real_T P_168 ; real_T
P_169 ; real_T P_170 ; real_T P_171 ; real_T P_172 [ 3 ] ; real_T P_173 [ 3 ]
; real_T P_174 [ 3 ] ; real_T P_175 [ 3 ] ; real_T P_176 ; real_T P_177 ;
real_T P_178 ; real_T P_179 ; real_T P_180 ; uint32_T P_181 [ 2 ] ; uint32_T
P_182 [ 2 ] ; uint32_T P_183 [ 2 ] ; uint32_T P_184 [ 2 ] ; uint32_T P_185 [
2 ] ; int16_T P_186 ; int16_T P_187 [ 10 ] ; boolean_T P_188 ; boolean_T
P_189 ; boolean_T P_190 [ 16 ] ; uint8_T P_191 ; uint8_T P_192 ; uint8_T
P_193 ; uint8_T P_194 ; uint8_T P_195 ; uint8_T P_196 ; uint8_T P_197 ;
uint8_T P_198 ; uint8_T P_199 ; uint8_T P_200 ; p4acrmrl1n k2qa4dutqw ;
gmdp13mlne jtklenszl2 ; a2pektskpt il54uu1pjc ; aleiimaknm dl4mqb4pfs ;
p4acrmrl1n olrlhhrjjg0 ; gmdp13mlne i54nxukymky ; a2pektskpt pwa0sx1vmmq ;
aleiimaknm kymnflaougc ; } ; struct gvdx343rko { struct SimStruct_tag * *
childSfunctions ; struct SimStruct_tag * _mdlRefSfcnS ; SS_SimMode simMode ;
RTWSolverInfo solverInfo ; RTWSolverInfo * solverInfoPtr ; void * sfcnInfo ;
struct { time_T * taskTimePtrs [ 4 ] ; SimStruct childSFunctions [ 1 ] ;
SimStruct * childSFunctionPtrs [ 1 ] ; struct _ssBlkInfo2 blkInfo2 [ 1 ] ;
struct _ssBlkInfoSLSize blkInfoSLSize [ 1 ] ; struct _ssSFcnModelMethods2
methods2 [ 1 ] ; struct _ssSFcnModelMethods3 methods3 [ 1 ] ; struct
_ssSFcnModelMethods4 methods4 [ 1 ] ; struct _ssStatesInfo2 statesInfo2 [ 1 ]
; ssPeriodicStatesInfo periodicStatesInfo [ 1 ] ; struct _ssPortInfo2
inputOutputPortInfo2 [ 1 ] ; struct { time_T sfcnPeriod [ 1 ] ; time_T
sfcnOffset [ 1 ] ; int_T sfcnTsMap [ 1 ] ; struct _ssPortInputs inputPortInfo
[ 11 ] ; struct _ssPortInputsSLSize inputPortInfoSLSize [ 11 ] ; struct
_ssInPortUnit inputPortUnits [ 11 ] ; struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 11 ] ; real_T const * UPtrs0 [ 3 ] ; real_T const *
UPtrs1 [ 3 ] ; real_T const * UPtrs2 [ 39 ] ; real_T const * UPtrs3 [ 7 ] ;
real_T const * UPtrs4 [ 7 ] ; real_T const * UPtrs5 [ 8 ] ; real_T const *
UPtrs6 [ 8 ] ; real_T const * UPtrs7 [ 4 ] ; real_T const * UPtrs8 [ 4 ] ;
real_T const * UPtrs9 [ 49 ] ; real_T const * UPtrs10 [ 16 ] ; struct
_ssPortOutputs outputPortInfo [ 6 ] ; struct _ssPortOutputsSLSize
outputPortInfoSLSize [ 6 ] ; struct _ssOutPortUnit outputPortUnits [ 6 ] ;
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 6 ] ; } Sfcn0 ; }
NonInlinedSFcns ; const rtTimingBridge * timingBridge ; boolean_T
zCCacheNeedsReset ; boolean_T derivCacheNeedsReset ; boolean_T
CTOutputIncnstWithState ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; void * dataAddress [
22 ] ; int32_T * vardimsAddress [ 22 ] ; RTWLoggingFcnPtr loggingPtrs [ 22 ]
; sysRanDType * systemRan [ 35 ] ; int_T systemTid [ 35 ] ; } DataMapInfo ;
struct { uint32_T options ; int_T numContStates ; int_T numU ; int_T numY ;
int_T numSampTimes ; int_T numBlocks ; int_T numBlockIO ; int_T numBlockPrms
; int_T numDwork ; int_T numSFcnPrms ; int_T numSFcns ; int_T numIports ;
int_T numOports ; int_T numNonSampZCs ; int_T sysDirFeedThru ; int_T
rtwGenSfcn ; } Sizes ; struct { time_T stepSize ; uint8_T rtmDbBufReadBuf3 ;
uint8_T rtmDbBufWriteBuf3 ; boolean_T rtmDbBufLastBufWr3 ; uint32_T
rtmDbBufClockTick3 [ 2 ] ; int_T mdlref_GlobalTID [ 4 ] ; time_T tStart ;
time_T tFinal ; time_T timeOfLastOutput ; time_T * sampleTimes ; time_T *
offsetTimes ; int_T * sampleTimeTaskIDPtr ; int_T * sampleHits ; int_T *
perTaskSampleHits ; time_T sampleTimesArray [ 3 ] ; time_T offsetTimesArray [
3 ] ; int_T sampleTimeTaskIDArray [ 3 ] ; int_T sampleHitArray [ 3 ] ; int_T
perTaskSampleHitsArray [ 9 ] ; } Timing ; } ; typedef struct { geuopffatc rtb
; mgp55fs13f rtdw ; lmmo4anm52 rtm ; } djynksnhd4a ; extern
struct_VErj1hGlw6L5R7K3AuDTiC rtP_TV ; extern void krzmzwaah3 ( SimStruct *
_mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , int_T mdlref_TID2 ,
int_T mdlref_TID3 , lmmo4anm52 * const m0dkyunhwk , geuopffatc * localB ,
mgp55fs13f * localDW , lietroj0em * localX , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_Torque_Vectoring_Model_Cooling_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS ,
char_T * modelName , int_T * retVal ) ; extern mxArray *
mr_Torque_Vectoring_Model_Cooling_GetDWork ( const djynksnhd4a * mdlrefDW ) ;
extern void mr_Torque_Vectoring_Model_Cooling_SetDWork ( djynksnhd4a *
mdlrefDW , const mxArray * ssDW ) ; extern void
mr_Torque_Vectoring_Model_Cooling_RegisterSimStateChecksum ( SimStruct * S )
; extern mxArray *
mr_Torque_Vectoring_Model_Cooling_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo *
Torque_Vectoring_Model_Cooling_GetCAPIStaticMap ( void ) ; extern void
kymnflaoug ( real_T odqiw4uywm , real_T dqgw4a3kly , real_T * j3mrewg3ep ,
aleiimaknm * localP ) ; extern void pwa0sx1vmm ( real_T awql4okgz0 , real_T
pg2dkp5xon , real_T * kvdcvrgi1r , a2pektskpt * localP ) ; extern void
i54nxukymk ( real_T ilp0bu0z12 , real_T b4jz1v0phl , real_T * n1utnre0iy ,
gmdp13mlne * localP ) ; extern void olrlhhrjjg ( real_T ndfvxnrxe2 , real_T
ag3w1fbk2l , real_T * gk5upomwkg , p4acrmrl1n * localP ) ; extern void
mw22bjqtbb ( lmmo4anm52 * const m0dkyunhwk , mgp55fs13f * localDW ) ; extern
void njtux15dzh ( lmmo4anm52 * const m0dkyunhwk , geuopffatc * localB ,
mgp55fs13f * localDW , lietroj0em * localX ) ; extern void cc2mloeum2 (
lmmo4anm52 * const m0dkyunhwk , mgp55fs13f * localDW , lietroj0em * localX )
; extern void dgkz1olqma ( lmmo4anm52 * const m0dkyunhwk , mgp55fs13f *
localDW ) ; extern void o2joeltd34 ( lmmo4anm52 * const m0dkyunhwk ,
geuopffatc * localB , mgp55fs13f * localDW ) ; extern void pi0v2qwoey ( const
real_T * dw4io5j3ch , const real_T * djibksf4gg , const real_T * arjg5uvfwb ,
const real_T * awomkra4ex , const real_T * dp1mnfwoc2 , const real_T *
pwragurunc , lietroj0em * localX , j4t221w5my * localXdot ) ; extern void
icxn3b14hxTID0 ( lmmo4anm52 * const m0dkyunhwk , const real_T * hkyee321bc ,
const real_T * okb20nbbxy , const real_T * h41nuog54q , const real_T *
doceiypgnu , const real_T * pcl1n1kmib , const real_T * iw21wiouqu , const
real_T * aualpuov0i , const real_T * nxrd3k4tzj , const real_T * k1xy3ln12l ,
const real_T * cvjfiedn0f , const real_T * oysyb5ncmo , mgp55fs13f * localDW
) ; extern void icxn3b14hxTID1 ( void ) ; extern void icxn3b14hxTID2 (
geuopffatc * localB , mgp55fs13f * localDW ) ; extern void
Torque_Vectoring_Model_CoolingTID0 ( lmmo4anm52 * const m0dkyunhwk , const
real_T * n0nklkcfwt , const real_T * mwnmsbmqdx , const real_T * itohwvatvc ,
const real_T * kgbsqo3dwa , const real_T * blnbk3c034 , const real_T *
er1prkxq3f , geuopffatc * localB , mgp55fs13f * localDW , lietroj0em * localX
) ; extern void Torque_Vectoring_Model_CoolingTID1 ( void ) ; extern void
Torque_Vectoring_Model_CoolingTID2 ( lmmo4anm52 * const m0dkyunhwk , real_T *
bqrdhkq2iy , real_T * o4th55yncd , real_T * fkmhylkvfh , real_T * lfdx3kalla
, geuopffatc * localB , mgp55fs13f * localDW ) ; extern void
Torque_Vectoring_Model_CoolingTID3 ( lmmo4anm52 * const m0dkyunhwk ,
geuopffatc * localB , mgp55fs13f * localDW ) ; extern void dcficcp3zq (
lmmo4anm52 * const m0dkyunhwk , mgp55fs13f * localDW ) ; extern const real_T
Torque_Vectoring_Model_Cooling_RGND ;
#endif
