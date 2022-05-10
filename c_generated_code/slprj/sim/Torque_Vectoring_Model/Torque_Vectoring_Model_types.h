#ifndef RTW_HEADER_Torque_Vectoring_Model_types_h_
#define RTW_HEADER_Torque_Vectoring_Model_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_zGeneral_Params_
#define DEFINED_TYPEDEF_FOR_zGeneral_Params_
typedef struct { real_T ThrottleThresh ; real_T BrakeThresh ; real_T
SteerTresh ; real_T SteerRelayAmplitude ; real_T YRDTresh ; } zGeneral_Params
;
#endif
#ifndef DEFINED_TYPEDEF_FOR_zMap_Params_
#define DEFINED_TYPEDEF_FOR_zMap_Params_
typedef struct { uint8_T YrdSelection ; uint8_T sl_padding0 [ 7 ] ; }
zMap_Params ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_vefxkWTvd3J3SvcZRqA1FH_
#define DEFINED_TYPEDEF_FOR_struct_vefxkWTvd3J3SvcZRqA1FH_
typedef struct { real_T T [ 7 ] ; real_T mu [ 7 ] ; }
struct_vefxkWTvd3J3SvcZRqA1FH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_5doPCiFs38QXBqBk1A3QBE_
#define DEFINED_TYPEDEF_FOR_struct_5doPCiFs38QXBqBk1A3QBE_
typedef struct { real_T Tau ; real_T rs ; real_T g ; real_T wd ; real_T wb ;
real_T tf ; real_T tr ; real_T m ; real_T Iz ; real_T a ; real_T b ; real_T
hcog ; real_T Fzf ; real_T Fzr ; real_T xcop ; real_T hcop ; real_T rho ;
real_T CdA ; real_T ClA ; real_T BrkArea_front ; real_T DiskDiameter_front ;
real_T DiskDiameter_rear ; real_T BrkArea_rear ;
struct_vefxkWTvd3J3SvcZRqA1FH z04 ; } struct_5doPCiFs38QXBqBk1A3QBE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_ceHSa1udHDBqGGoVDJctFH_
#define DEFINED_TYPEDEF_FOR_struct_ceHSa1udHDBqGGoVDJctFH_
typedef struct { real_T ID109 ; real_T ID114 ; real_T ID32771 ; real_T
ID32798_11 ; real_T ID32798_12 ; real_T ID32798_5 ; real_T ID32798_6 ; real_T
ID32798_8 ; real_T ID32798_9 ; real_T ID32999 ; real_T ID34096 ; real_T
ID34168 ; real_T ID82 ; real_T Kt ; real_T Nm [ 221 ] ; real_T Total_Loss [
4221 ] ; real_T Tpeak ; real_T rpm [ 221 ] ; } struct_ceHSa1udHDBqGGoVDJctFH
;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_myYnN0W7OmXmGj5tCEaOWG_
#define DEFINED_TYPEDEF_FOR_struct_myYnN0W7OmXmGj5tCEaOWG_
typedef struct { real_T Eta [ 4000 ] ; real_T Omega [ 200 ] ; real_T Torque [
20 ] ; } struct_myYnN0W7OmXmGj5tCEaOWG ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_kFxodBJdgZDU8k23gzQl8_
#define DEFINED_TYPEDEF_FOR_struct_kFxodBJdgZDU8k23gzQl8_
typedef struct { uint16_T breakpoints1 [ 201 ] ; uint16_T breakpoints2 [ 46 ]
; uint16_T table_data [ 9246 ] ; uint8_T sl_padding0 [ 6 ] ; }
struct_kFxodBJdgZDU8k23gzQl8 ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_EPHiECHuK31aaLSFJu9vjH_
#define DEFINED_TYPEDEF_FOR_struct_EPHiECHuK31aaLSFJu9vjH_
typedef struct { real_T T_nominal_motor ; real_T T_peak_motor ; real_T
T_nominal_wheel ; real_T T_peak_wheel ; real_T T_nominal_setting ; real_T
T_peak_setting ; struct_kFxodBJdgZDU8k23gzQl8 T_lim_pos ; }
struct_EPHiECHuK31aaLSFJu9vjH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_aZ8UFD17UYKl2v5x5JydHG_
#define DEFINED_TYPEDEF_FOR_struct_aZ8UFD17UYKl2v5x5JydHG_
typedef struct { struct_ceHSa1udHDBqGGoVDJctFH AMK ; real_T inv_efficiency ;
struct_myYnN0W7OmXmGj5tCEaOWG efficiency_LUT ; struct_EPHiECHuK31aaLSFJu9vjH
TORQUE ; zGeneral_Params GENERAL ; zMap_Params MAP ; }
struct_aZ8UFD17UYKl2v5x5JydHG ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_9DbYHPGSUbxCldGZsYfiGC_
#define DEFINED_TYPEDEF_FOR_struct_9DbYHPGSUbxCldGZsYfiGC_
typedef struct { real_T Fx_target_negative [ 400 ] ; real_T
Fx_target_positive [ 400 ] ; real_T Fz [ 20 ] ; real_T alpha [ 20 ] ; }
struct_9DbYHPGSUbxCldGZsYfiGC ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_3jv5r8HQRzLTP7P0JZohcD_
#define DEFINED_TYPEDEF_FOR_struct_3jv5r8HQRzLTP7P0JZohcD_
typedef struct { struct_9DbYHPGSUbxCldGZsYfiGC control_bound_0_10 ; }
struct_3jv5r8HQRzLTP7P0JZohcD ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_0AV1cKZTHhsgN5YcLEFWqH_
#define DEFINED_TYPEDEF_FOR_struct_0AV1cKZTHhsgN5YcLEFWqH_
typedef struct { real_T Y [ 20 ] ; real_T X [ 20 ] ; }
struct_0AV1cKZTHhsgN5YcLEFWqH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_Cnc7cfMj0PtoUwdvAnLIHH_
#define DEFINED_TYPEDEF_FOR_struct_Cnc7cfMj0PtoUwdvAnLIHH_
typedef struct { uint32_T LUT_P_active [ 6 ] ; uint32_T LUT_Pel [ 6 ] ;
struct_0AV1cKZTHhsgN5YcLEFWqH LUT_regen ; } struct_Cnc7cfMj0PtoUwdvAnLIHH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_6WSKabhx9v8Cky3XApOXyF_
#define DEFINED_TYPEDEF_FOR_struct_6WSKabhx9v8Cky3XApOXyF_
typedef struct { struct_Cnc7cfMj0PtoUwdvAnLIHH Power ; }
struct_6WSKabhx9v8Cky3XApOXyF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_JtE21Q5LlU4aYlpS3e1GEB_
#define DEFINED_TYPEDEF_FOR_struct_JtE21Q5LlU4aYlpS3e1GEB_
typedef struct { real_T SteerAngle_SingleAxis [ 33 ] ; real_T Steering [ 33 ]
; } struct_JtE21Q5LlU4aYlpS3e1GEB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_ywpVrAamiyVsotNocMmP4G_
#define DEFINED_TYPEDEF_FOR_struct_ywpVrAamiyVsotNocMmP4G_
typedef struct { real_T SteerAngle_FL [ 33 ] ; real_T Steering [ 33 ] ; }
struct_ywpVrAamiyVsotNocMmP4G ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_oq1QAjAcF2fU80io5OxjDB_
#define DEFINED_TYPEDEF_FOR_struct_oq1QAjAcF2fU80io5OxjDB_
typedef struct { struct_JtE21Q5LlU4aYlpS3e1GEB
steer_at_ground_single_axis_LUT ; struct_ywpVrAamiyVsotNocMmP4G
steer_at_ground_LUT ; } struct_oq1QAjAcF2fU80io5OxjDB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_Q9JAmdDlymHbbIUFtGpR0F_
#define DEFINED_TYPEDEF_FOR_struct_Q9JAmdDlymHbbIUFtGpR0F_
typedef struct { real32_T ay_matrix [ 10000 ] ; real32_T delta_vector [ 100 ]
; real32_T v_vector [ 100 ] ; } struct_Q9JAmdDlymHbbIUFtGpR0F ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_CjoDyU5xXrxJwaLTj7O9XG_
#define DEFINED_TYPEDEF_FOR_struct_CjoDyU5xXrxJwaLTj7O9XG_
typedef struct { real_T ay_matrix [ 10000 ] ; } struct_CjoDyU5xXrxJwaLTj7O9XG
;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_y2MOMieainmLFRr8yMr5rH_
#define DEFINED_TYPEDEF_FOR_struct_y2MOMieainmLFRr8yMr5rH_
typedef struct { real_T r [ 10000 ] ; } struct_y2MOMieainmLFRr8yMr5rH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_sEDUFSUN7i4hAuLRzIbgF_
#define DEFINED_TYPEDEF_FOR_struct_sEDUFSUN7i4hAuLRzIbgF_
typedef struct { struct_Q9JAmdDlymHbbIUFtGpR0F LUT_vectors ;
struct_CjoDyU5xXrxJwaLTj7O9XG LUT_0 ; struct_y2MOMieainmLFRr8yMr5rH LUT_1 ;
struct_y2MOMieainmLFRr8yMr5rH LUT_neg1_5 ; struct_CjoDyU5xXrxJwaLTj7O9XG
LUT_neg3 ; } struct_sEDUFSUN7i4hAuLRzIbgF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_VGctP11MdPfOra9unk63tB_
#define DEFINED_TYPEDEF_FOR_struct_VGctP11MdPfOra9unk63tB_
typedef struct { struct_3jv5r8HQRzLTP7P0JZohcD MPC_Lut ;
struct_6WSKabhx9v8Cky3XApOXyF Power_LUT ; struct_oq1QAjAcF2fU80io5OxjDB
Car_LUT ; struct_sEDUFSUN7i4hAuLRzIbgF Yrd_LUT ; }
struct_VGctP11MdPfOra9unk63tB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_R4Nbc43uHnRiYOCfL6HW1E_
#define DEFINED_TYPEDEF_FOR_struct_R4Nbc43uHnRiYOCfL6HW1E_
typedef struct { real_T N ; real_T T ; real_T nx ; real_T np ; real_T ny ;
real_T nu ; } struct_R4Nbc43uHnRiYOCfL6HW1E ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_NfxKnoaXlpNFz9gB5ulgKB_
#define DEFINED_TYPEDEF_FOR_struct_NfxKnoaXlpNFz9gB5ulgKB_
typedef struct { real_T movingAverage ; real_T sampleTime ; }
struct_NfxKnoaXlpNFz9gB5ulgKB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_6D3M1rE4XRVx7SMF3a1ufC_
#define DEFINED_TYPEDEF_FOR_struct_6D3M1rE4XRVx7SMF3a1ufC_
typedef struct { struct_5doPCiFs38QXBqBk1A3QBE CAR ;
struct_aZ8UFD17UYKl2v5x5JydHG LV ; struct_VGctP11MdPfOra9unk63tB LUT ;
struct_R4Nbc43uHnRiYOCfL6HW1E MPC ; struct_NfxKnoaXlpNFz9gB5ulgKB FILTERS ; }
struct_6D3M1rE4XRVx7SMF3a1ufC ;
#endif
#ifndef struct_tag_3NiWMXO734j2vYCmGs3lz
#define struct_tag_3NiWMXO734j2vYCmGs3lz
struct tag_3NiWMXO734j2vYCmGs3lz { int32_T isInitialized ; boolean_T
isSetupComplete ; real_T pCumSum ; real_T pCumSumRev [ 24 ] ; real_T
pCumRevIndex ; real_T pModValueRev ; } ;
#endif
#ifndef typedef_hsb44yccha
#define typedef_hsb44yccha
typedef struct tag_3NiWMXO734j2vYCmGs3lz hsb44yccha ;
#endif
#ifndef struct_tag_twKmvSwtXFvwm110YFDILC
#define struct_tag_twKmvSwtXFvwm110YFDILC
struct tag_twKmvSwtXFvwm110YFDILC { int32_T isInitialized ; boolean_T
isSetupComplete ; real_T pCumSum ; real_T pCumSumRev [ 4 ] ; real_T
pCumRevIndex ; real_T pModValueRev ; } ;
#endif
#ifndef typedef_hsb44yccha2
#define typedef_hsb44yccha2
typedef struct tag_twKmvSwtXFvwm110YFDILC hsb44yccha2 ;
#endif
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE
struct tag_BlgwLpgj2bjudmbmVKWwDE { uint32_T f1 [ 8 ] ; } ;
#endif
#ifndef typedef_i0p5bmy5r2
#define typedef_i0p5bmy5r2
typedef struct tag_BlgwLpgj2bjudmbmVKWwDE i0p5bmy5r2 ;
#endif
#ifndef struct_tag_jzS6kMpFJO3FhRUJgNdkWF
#define struct_tag_jzS6kMpFJO3FhRUJgNdkWF
struct tag_jzS6kMpFJO3FhRUJgNdkWF { boolean_T matlabCodegenIsDeleted ;
int32_T isInitialized ; boolean_T isSetupComplete ; boolean_T
TunablePropsChanged ; i0p5bmy5r2 inputVarSize ; hsb44yccha * pStatistic ;
int32_T NumChannels ; hsb44yccha _pobj0 ; } ;
#endif
#ifndef typedef_lv0lucodty
#define typedef_lv0lucodty
typedef struct tag_jzS6kMpFJO3FhRUJgNdkWF lv0lucodty ;
#endif
#ifndef struct_tag_VSW2YOpcQ0JoSsliuYZ3uD
#define struct_tag_VSW2YOpcQ0JoSsliuYZ3uD
struct tag_VSW2YOpcQ0JoSsliuYZ3uD { boolean_T matlabCodegenIsDeleted ;
int32_T isInitialized ; boolean_T isSetupComplete ; boolean_T
TunablePropsChanged ; i0p5bmy5r2 inputVarSize ; hsb44yccha2 * pStatistic ;
int32_T NumChannels ; hsb44yccha2 _pobj0 ; } ;
#endif
#ifndef typedef_lv0lucodtya
#define typedef_lv0lucodtya
typedef struct tag_VSW2YOpcQ0JoSsliuYZ3uD lv0lucodtya ;
#endif
#ifndef SS_UINT64
#define SS_UINT64 48
#endif
#ifndef SS_INT64
#define SS_INT64 49
#endif
typedef struct a5svlsfqid_ a5svlsfqid ; typedef struct m4vt05vhn0_ m4vt05vhn0
; typedef struct ju222yfnnj_ ju222yfnnj ; typedef struct a02g2bdxht_
a02g2bdxht ; typedef struct pamws4jgisk_ pamws4jgisk ; typedef struct
f3wpm1dhxd ezpkkyrudv ;
#endif
