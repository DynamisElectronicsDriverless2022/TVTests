#ifndef RTW_HEADER_Torque_Vectoring_Model_h_
#define RTW_HEADER_Torque_Vectoring_Model_h_
#ifndef Torque_Vectoring_Model_COMMON_INCLUDES_
#define Torque_Vectoring_Model_COMMON_INCLUDES_
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "Torque_Vectoring_Model_types.h"
#include <stddef.h>
#include <string.h>
#include "model_reference_types.h"
#include "rtGetInf.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_nonfinite.h"
typedef struct { int8_T hxinfjq0k1 ; } g4ajwvgfs4 ; typedef struct { int8_T
cf0xinclcr ; } jibpbd3msq ; typedef struct { int8_T fcirhlhinq ; } molz4lx31h
; typedef struct { int8_T cms2fen1zz ; } mwlk5pxv4k ; typedef struct { real_T
mn0dabrw1b ; real_T c0cemd115h ; real_T bhwqng3rfw ; real_T oihwj1rovz ;
real_T i50wkc1mgb [ 2 ] ; real_T mr3toqolmr [ 4 ] ; real_T gfnlhpd5p4 [ 4 ] ;
real_T akzkdf4uwt ; real_T be3tn0zzdl [ 5 ] ; real_T hndxvmt3v5 [ 5 ] ;
real_T g1gn0dehdj [ 39 ] ; real_T muvpeqbe51 [ 7 ] ; real_T esx0m2cptl [ 8 ]
; real_T jjq3pltzeg [ 8 ] ; real_T lxfzna2yxk [ 4 ] ; real_T jitqsut1jf ;
real_T pv5cgfvnzu ; real_T aoeuf5tdin [ 3 ] ; real_T pua2k5adks ; real_T
eoy25amtzy ; real_T cpdpfollmz [ 4 ] ; real_T iitczk2oov [ 4 ] ; real_T
bexpzuq1yw ; real_T cbgryml5lp ; real_T hoql2cdatv ; real_T prpnkgs0dr ;
real_T e0pykywxfb [ 4 ] ; real_T bjva3vkzu0 ; real_T ogu5db5opv ; real_T
jimuldznfc ; real_T n5wjgzqko2 ; real_T hhw3dna01h [ 49 ] ; real_T chlx410rnf
[ 20 ] ; real_T duvvrbh3if ; real_T ejtiiudpzk ; int16_T d4wfekqcuu ;
boolean_T o2hr1d4hel ; boolean_T gm3uzw1z2t [ 2 ] ; } l5xhjwfmkd ; typedef
struct { lv0lucodty nurdoy2tef ; lv0lucodtya g0t1clrqpe ; zGeneral_Params
ictrktoaty ; real_T hpgo02yjst [ 4 ] ; real_T l54on5e34r [ 4 ] ; real_T
l1hwxxcf3t ; real_T k3gnkpqipr [ 4 ] ; real_T fs0ljll4su ; real_T acvt1aef4t
; real_T dqqreqix3a ; real_T ok50zydx5t ; real_T l0t2uc31ke ; real_T
mdkk02nr3s ; real_T edlyxjurtr ; real_T lcsm5q23bl [ 4 ] ; real_T gkssnnzqt4
[ 4 ] ; real_T fxaifyt0vm [ 4 ] ; real_T fzuzh3pii0 ; real_T kzmww4ht21 [ 4 ]
; real_T b3v3rqmjak ; real_T jcwild03xf ; real_T ntvjqc11m4 [ 4 ] ; real_T
hio3lnb42q [ 4 ] ; real_T gsy40j31c3 ; real_T k0myjrwy5j ; real_T ne4fviglpp
; real_T npy5pws14k ; real_T p5fcy3i4jr ; real_T ebzf4ml3xp ; real_T
kegpr5fxk1 [ 4 ] ; real_T l4l51x5hrg ; zMap_Params drbrzgtvpw ; struct { void
* AQHandles [ 60 ] ; } da4zpaea2s ; struct { void * AQHandles ; } jjbchhdgh4
; struct { void * AQHandles ; } mzvi1gql1a ; struct { void * AQHandles ; }
ksdv0er15h ; struct { void * AQHandles ; } f4c5wze2mx ; struct { void *
AQHandles ; } atdvb3fdrs ; struct { void * AQHandles ; } msip3gje2z ; struct
{ void * AQHandles ; } ctd3p3x4hn ; struct { void * AQHandles ; } fh3kzp22lf
; struct { void * AQHandles ; } jjbchhdgh42 ; struct { void * AQHandles ; }
fbd0iynpjo ; struct { void * AQHandles ; } ksdv0er15hv ; struct { void *
AQHandles ; } j5uctii0pz ; struct { void * AQHandles ; } e1bey0co0g ; struct
{ void * AQHandles ; } ksdv0er15hvz ; int32_T ikp1er2ybh ; int32_T oltejywlb5
; int16_T ayvrdlqgwy [ 9 ] ; boolean_T kjpqgomqpj ; boolean_T p1qn01wqap [ 5
] ; int8_T apt25oimjl ; int8_T mpkeuyessu ; int8_T op04mp35bl ; int8_T
e0ozw4ht22 ; int8_T eswfw4zt2l ; int8_T cuj32ioisf ; uint8_T hiecy3kvl2 ;
uint8_T pdzto3hdil ; uint8_T jxd4oys4au ; uint8_T hde0dfa0nx ; uint8_T
iy5txw2jbf ; uint8_T eyhyybitps ; boolean_T ksvfeovzie ; boolean_T l0lgmtcayg
; boolean_T pdpdmr12vn ; mwlk5pxv4k cvp5xo4aw2 ; molz4lx31h cjp0ll3pd2 ;
jibpbd3msq c0dwlf5j11 ; g4ajwvgfs4 l1plnz21yr ; mwlk5pxv4k pf5ohd3jye0 ;
molz4lx31h peozus1dnst ; jibpbd3msq hfgcehfk2gx ; g4ajwvgfs4 fsg3uy4quct ; }
lm02cmjnzh ; typedef struct { real_T dcitxr0qmt ; real_T jylybj1aho ; real_T
kddiqlzre2 ; real_T lan15trgft ; real_T mpgtiyrp0l ; } njcbhnzhxv ; typedef
struct { real_T dcitxr0qmt ; real_T jylybj1aho ; real_T kddiqlzre2 ; real_T
lan15trgft ; real_T mpgtiyrp0l ; } mncg4apdvm ; typedef struct { boolean_T
dcitxr0qmt ; boolean_T jylybj1aho ; boolean_T kddiqlzre2 ; boolean_T
lan15trgft ; boolean_T mpgtiyrp0l ; } lw3qyj3edu ; struct a5svlsfqid_ {
real_T P_0 ; real_T P_1 ; real_T P_2 [ 10000 ] ; real_T P_3 [ 100 ] ; real_T
P_4 [ 100 ] ; uint32_T P_5 [ 2 ] ; } ; struct m4vt05vhn0_ { real_T P_0 ;
real_T P_1 ; real_T P_2 [ 10000 ] ; real_T P_3 [ 100 ] ; real_T P_4 [ 100 ] ;
uint32_T P_5 [ 2 ] ; } ; struct ju222yfnnj_ { real_T P_0 ; real_T P_1 ;
real_T P_2 [ 10000 ] ; real_T P_3 [ 100 ] ; real_T P_4 [ 100 ] ; uint32_T P_5
[ 2 ] ; } ; struct a02g2bdxht_ { real_T P_0 ; real_T P_1 ; real_T P_2 [ 10000
] ; real_T P_3 [ 100 ] ; real_T P_4 [ 100 ] ; uint32_T P_5 [ 2 ] ; } ; struct
pamws4jgisk_ { real_T P_1 ; real_T P_2 ; boolean_T P_3 ; real_T P_4 ; real_T
P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 [ 2 ] ;
real_T P_11 ; real_T P_12 ; real_T P_13 [ 3 ] ; real_T P_14 [ 3 ] ; real_T
P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ;
real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T
P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ;
real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T
P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 [ 3 ] ; real_T P_41 [ 3 ] ;
real_T P_42 [ 3 ] ; real_T P_43 [ 3 ] ; real_T P_44 [ 3 ] ; real_T P_45 [ 3 ]
; real_T P_46 ; real_T P_47 ; real_T P_48 [ 9246 ] ; real_T P_49 [ 201 ] ;
real_T P_50 [ 46 ] ; real_T P_51 ; real_T P_52 ; real_T P_53 ; real_T P_54 ;
real_T P_55 ; real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T
P_60 ; real_T P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ;
real_T P_66 [ 3 ] ; real_T P_67 [ 3 ] ; real_T P_68 [ 3 ] ; real_T P_69 [ 3 ]
; real_T P_70 [ 3 ] ; real_T P_71 [ 3 ] ; real_T P_72 ; real_T P_73 ; real_T
P_74 [ 20 ] ; real_T P_75 [ 20 ] ; real_T P_76 [ 9246 ] ; real_T P_77 [ 201 ]
; real_T P_78 [ 46 ] ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82
; real_T P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ;
real_T P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T
P_93 ; real_T P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ;
real_T P_99 ; real_T P_100 ; real_T P_101 ; real_T P_102 [ 5 ] ; real_T P_103
; real_T P_104 ; real_T P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ;
real_T P_109 ; real_T P_110 ; real_T P_111 ; real_T P_112 ; real_T P_113 ;
real_T P_114 [ 4 ] ; real_T P_115 [ 4 ] ; real_T P_116 ; real_T P_117 ;
real_T P_118 ; real_T P_119 [ 4 ] ; real_T P_120 ; real_T P_121 ; real_T
P_122 ; real_T P_123 ; real_T P_124 ; real_T P_125 ; real_T P_126 ; real_T
P_127 ; real_T P_128 ; real_T P_129 ; real_T P_130 ; real_T P_131 ; real_T
P_132 ; real_T P_133 ; real_T P_134 ; real_T P_135 ; real_T P_136 ; real_T
P_137 ; real_T P_138 ; real_T P_139 ; real_T P_140 ; real_T P_141 ; real_T
P_142 ; real_T P_143 ; real_T P_144 ; real_T P_145 ; real_T P_146 ; real_T
P_147 ; real_T P_148 ; real_T P_149 ; real_T P_150 ; real_T P_151 ; real_T
P_152 ; real_T P_153 ; real_T P_154 ; real_T P_155 ; real_T P_156 ; real_T
P_157 ; real_T P_158 ; real_T P_159 ; real_T P_160 ; real_T P_161 ; real_T
P_162 ; real_T P_163 ; real_T P_164 ; real_T P_165 ; real_T P_166 ; real_T
P_167 [ 3 ] ; real_T P_168 [ 3 ] ; real_T P_169 [ 3 ] ; real_T P_170 [ 3 ] ;
real_T P_171 ; real_T P_172 ; real_T P_173 ; real_T P_174 ; real_T P_175 ;
real_T P_176 ; real_T P_177 ; real_T P_178 [ 3 ] ; real_T P_179 [ 3 ] ;
real_T P_180 [ 3 ] ; real_T P_181 [ 3 ] ; real_T P_182 ; real_T P_183 ;
real_T P_184 ; real_T P_185 ; real_T P_186 ; uint32_T P_187 [ 2 ] ; uint32_T
P_188 [ 2 ] ; uint32_T P_189 [ 2 ] ; uint32_T P_190 [ 2 ] ; uint32_T P_191 [
2 ] ; uint32_T P_192 [ 2 ] ; uint32_T P_193 [ 2 ] ; int16_T P_194 ; int16_T
P_195 [ 10 ] ; boolean_T P_196 ; boolean_T P_197 ; boolean_T P_198 [ 16 ] ;
uint8_T P_199 ; uint8_T P_200 ; uint8_T P_201 ; uint8_T P_202 ; uint8_T P_203
; uint8_T P_204 ; uint8_T P_205 ; uint8_T P_206 ; uint8_T P_207 ; uint8_T
P_208 ; uint8_T P_209 ; a02g2bdxht cvp5xo4aw2 ; ju222yfnnj cjp0ll3pd2 ;
m4vt05vhn0 c0dwlf5j11 ; a5svlsfqid l1plnz21yr ; a02g2bdxht pf5ohd3jye0 ;
ju222yfnnj peozus1dnst ; m4vt05vhn0 hfgcehfk2gx ; a5svlsfqid fsg3uy4quct ; }
; struct f3wpm1dhxd { struct SimStruct_tag * * childSfunctions ; struct
SimStruct_tag * _mdlRefSfcnS ; SS_SimMode simMode ; RTWSolverInfo solverInfo
; RTWSolverInfo * solverInfoPtr ; void * sfcnInfo ; struct { time_T *
taskTimePtrs [ 4 ] ; SimStruct childSFunctions [ 1 ] ; SimStruct *
childSFunctionPtrs [ 1 ] ; struct _ssBlkInfo2 blkInfo2 [ 1 ] ; struct
_ssBlkInfoSLSize blkInfoSLSize [ 1 ] ; struct _ssSFcnModelMethods2 methods2 [
1 ] ; struct _ssSFcnModelMethods3 methods3 [ 1 ] ; struct
_ssSFcnModelMethods4 methods4 [ 1 ] ; struct _ssStatesInfo2 statesInfo2 [ 1 ]
; ssPeriodicStatesInfo periodicStatesInfo [ 1 ] ; struct _ssPortInfo2
inputOutputPortInfo2 [ 1 ] ; struct { time_T sfcnPeriod [ 1 ] ; time_T
sfcnOffset [ 1 ] ; int_T sfcnTsMap [ 1 ] ; struct _ssPortInputs inputPortInfo
[ 11 ] ; struct _ssPortInputsSLSize inputPortInfoSLSize [ 11 ] ; struct
_ssInPortUnit inputPortUnits [ 11 ] ; struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 11 ] ; real_T const * UPtrs0 [ 3 ] ; real_T const *
UPtrs1 [ 3 ] ; real_T const * UPtrs2 [ 39 ] ; real_T const * UPtrs3 [ 7 ] ;
real_T const * UPtrs4 [ 7 ] ; real_T const * UPtrs5 [ 8 ] ; real_T const *
UPtrs6 [ 8 ] ; real_T const * UPtrs7 [ 5 ] ; real_T const * UPtrs8 [ 5 ] ;
real_T const * UPtrs9 [ 49 ] ; real_T const * UPtrs10 [ 20 ] ; struct
_ssPortOutputs outputPortInfo [ 6 ] ; struct _ssPortOutputsSLSize
outputPortInfoSLSize [ 6 ] ; struct _ssOutPortUnit outputPortUnits [ 6 ] ;
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 6 ] ; } Sfcn0 ; }
NonInlinedSFcns ; const rtTimingBridge * timingBridge ; boolean_T
zCCacheNeedsReset ; boolean_T derivCacheNeedsReset ; boolean_T
CTOutputIncnstWithState ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; void * dataAddress [
14 ] ; int32_T * vardimsAddress [ 14 ] ; RTWLoggingFcnPtr loggingPtrs [ 14 ]
; sysRanDType * systemRan [ 37 ] ; int_T systemTid [ 37 ] ; } DataMapInfo ;
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
perTaskSampleHitsArray [ 9 ] ; } Timing ; } ; typedef struct { l5xhjwfmkd rtb
; lm02cmjnzh rtdw ; ezpkkyrudv rtm ; } hwaeqpclxoh ; extern
struct_6D3M1rE4XRVx7SMF3a1ufC rtP_TV ; extern void ksz5rp3ega ( SimStruct *
_mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , int_T mdlref_TID2 ,
int_T mdlref_TID3 , ezpkkyrudv * const bl3qdbldo0 , l5xhjwfmkd * localB ,
lm02cmjnzh * localDW , njcbhnzhxv * localX , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_Torque_Vectoring_Model_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray *
mr_Torque_Vectoring_Model_GetDWork ( const hwaeqpclxoh * mdlrefDW ) ; extern
void mr_Torque_Vectoring_Model_SetDWork ( hwaeqpclxoh * mdlrefDW , const
mxArray * ssDW ) ; extern void
mr_Torque_Vectoring_Model_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_Torque_Vectoring_Model_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo *
Torque_Vectoring_Model_GetCAPIStaticMap ( void ) ; extern void fsg3uy4quc (
real_T myyvctin51 , real_T haa2gpbrog , real_T * doijvdetnf , a5svlsfqid *
localP ) ; extern void hfgcehfk2g ( real_T bnsmipmqow , real_T kfnarqnr4h ,
real_T * f2f0knvxkr , m4vt05vhn0 * localP ) ; extern void peozus1dns ( real_T
nit3tlrlm0 , real_T iks15haz3d , real_T * iwlykboi0t , ju222yfnnj * localP )
; extern void pf5ohd3jye ( real_T jeises1qcv , real_T m5msfypk12 , real_T *
khnay1d4uc , a02g2bdxht * localP ) ; extern void beujqdm4ls ( ezpkkyrudv *
const bl3qdbldo0 , lm02cmjnzh * localDW ) ; extern void lm1bkn5lj5 (
ezpkkyrudv * const bl3qdbldo0 , l5xhjwfmkd * localB , lm02cmjnzh * localDW ,
njcbhnzhxv * localX ) ; extern void iahyqsjt3r ( ezpkkyrudv * const
bl3qdbldo0 , lm02cmjnzh * localDW , njcbhnzhxv * localX ) ; extern void
bh5yhqzged ( ezpkkyrudv * const bl3qdbldo0 , lm02cmjnzh * localDW ) ; extern
void pfrtdtpwm1 ( ezpkkyrudv * const bl3qdbldo0 , l5xhjwfmkd * localB ,
lm02cmjnzh * localDW ) ; extern void bga5a2wpc1 ( const real_T * ced2btt0kk ,
const real_T * n5prdwuyvf , const real_T * nvvsqz4iav , const real_T *
dtcgukfbym , const real_T * l4iewo1blu , njcbhnzhxv * localX , mncg4apdvm *
localXdot ) ; extern void dltgulevs1 ( ezpkkyrudv * const bl3qdbldo0 , const
real_T * a5b4kem0fc , const real_T * pwg5licxsg , const real_T * fhmowxvqea ,
const real_T * g3bry1m20x , l5xhjwfmkd * localB , lm02cmjnzh * localDW ) ;
extern void Torque_Vectoring_Model ( ezpkkyrudv * const bl3qdbldo0 , const
real_T * hyugnbzqh3 , const real_T * idmq23clxt , const real_T * n3ewocgpn2 ,
const real_T * lsye0lohqf , const real_T * azphamwq1z , const real_T *
elpfojh1qu , const real_T * jpcn4d5b2m , real_T * gv0oijkz2v , real_T *
gu1yvp54oe , real_T * jluz4klwza , real_T * lnoqzx1c34 , l5xhjwfmkd * localB
, lm02cmjnzh * localDW , njcbhnzhxv * localX ) ; extern void
Torque_Vectoring_ModelTID3 ( ezpkkyrudv * const bl3qdbldo0 , l5xhjwfmkd *
localB , lm02cmjnzh * localDW ) ; extern void cgam1v1lqa ( ezpkkyrudv * const
bl3qdbldo0 , lm02cmjnzh * localDW ) ; extern const real_T
Torque_Vectoring_Model_RGND ;
#endif
