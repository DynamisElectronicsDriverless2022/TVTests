#ifndef ID_CAN_H
#define ID_CAN_H

/****************************CAN1***************************/

/****************************Priorità messaggi CAN1**************/
#define Pos_INSS_GPS                 24
#define Pos_M1_CURR                  5
#define Pos_M2_CURR                  9
#define Pos_M3_CURR                  13
#define Pos_M4_CURR                  17
#define Pos_INSS_X                   18
#define Pos_INSS_Y                   19
#define Pos_INSS_Z                   20
#define Pos_INSS_SPEED               21
#define Pos_INSS_LAT                 22
#define Pos_M1_STATUS                1
#define Pos_M1_CTRL                  3
#define Pos_M2_STATUS                6
#define Pos_M2_CTRL                  8
#define Pos_M3_STATUS                10
#define Pos_M3_CTRL                  12
#define Pos_M4_STATUS                14
#define Pos_M4_CTRL                  16
#define Pos_DRIVER_INPUT             25
#define Pos_M1_COOL                  2
#define Pos_M2_COOL                  7
#define Pos_M3_COOL                  11
#define Pos_M4_COOL                  15
#define Pos_FEEDBACK                 0
#define Pos_DEBUG_1                  27
#define Pos_DEBUG_2                  28
#define Pos_COOLING                  30
#define Pos_CRITICAL_DEBUG           26    
#define Pos_DEBUG_3                  29   
#define Pos_INSS_TIME                23       
#define Pos_MX_ERROR                 4   
#define Pos_AUX                      31
        
      
/********************* STEERING WHEEL *********************/
#define SW_TARGET_ID										0x200
#define SW_BUTTONS_ID										0x201
#define SW_ACQUISITION_ID									0x400
#define SW_DEBUG_ID											0x700

/************************** DCU ***************************/
#define DCU_ACQUISITION_FEEDBACK_ID							0x410
#define DCU_DEBUG_1_ID										0x701
#define DCU_DEBUG_2_ID										0x702

/************************** DAU ***************************/
#define DAU_FRONT_LIN_ID									0x302
#define DAU_FRONT_WH_ID										0x340
#define DAU_FRONT_IR_1_ID									0x342
#define DAU_FRONT_IR_2_ID									0x344
#define DAU_FRONT_MISC_ID									0x304
#define DAU_FRONT_4TV_ID									0x300
#define DAU_FRONT_DEBUG_ID									0x704
#define DAU_REAR_LIN_ID										0x301
#define DAU_REAR_WH_ID										0x341
#define DAU_REAR_IR_1_ID									0x343
#define DAU_REAR_IR_2_ID									0x345
#define DAU_REAR_COOL_ID									0x347
#define DAU_REAR_4TV_ID										0x303	
#define DAU_REAR_DEBUG_ID									0x703

/************************** IMU ***************************/
#define IMU_FRONT_ACC_ID									0x600
#define IMU_FRONT_GYRO_ID									0x602
#define IMU_FRONT_DEBUG_ID									0x706
#define IMU_REAR_ACC_ID										0x601
#define IMU_REAR_GYRO_ID									0x603
#define IMU_REAR_DEBUG_ID									0x705

/************************** VCU ***************************/
#define VCU_FEEDBACK_ID										0x202
#define VCU_DRIVER_INPUT_ID									0x650
#define VCU_CRITICAL_DEBUG_ID								0x651
#define VCU_DEBUG_1_ID										0x707
#define VCU_DEBUG_2_ID										0x708
#define VCU_DEBUG_3_ID										0x709
#define VCU_COOLING_ID										0x70A
#define VCU_INSS_X_ID										0x610
#define VCU_INSS_Y_ID										0x611
#define VCU_INSS_Z_ID										0x612
#define VCU_INSS_SPEED_ID									0x613
#define VCU_INSS_LAT_ID										0x614
#define VCU_INSS_TIME_ID									0x615
#define VCU_INSS_GPS_ID										0x616
#define VCU_M1_STATUS_ID									0x500
#define VCU_M1_COOL_ID										0x501
#define VCU_M1_CTRL_ID										0x502
#define VCU_M1_CURRENT_ID									0x504
#define VCU_M2_STATUS_ID									0x510
#define VCU_M2_COOL_ID										0x511
#define VCU_M2_CTRL_ID										0x512
#define VCU_M2_CURRENT_ID									0x514
#define VCU_M3_STATUS_ID									0x520
#define VCU_M3_COOL_ID										0x521
#define VCU_M3_CTRL_ID										0x522
#define VCU_M3_CURRENT_ID									0x524
#define VCU_M4_STATUS_ID									0x530
#define VCU_M4_COOL_ID										0x531
#define VCU_M4_CTRL_ID										0x532
#define VCU_M4_CURRENT_ID									0x534
#define VCU_MX_ERROR_ID										0x503
#define VCU_AUX_ID											0x711

/************************** BMS ***************************/
#define BMS_ACCUMULATOR_VOLTAGE_ID							0x210
#define BMS_CURRENT_LIMITER_AIR_TEMP_ID						0x211
#define BMS_ACCUMULATOR_CELL_STATE_ID						0x70B
#define BMS_DATALOGGER_STATE_ID								0x78E
#define BMS_ACCUMULATOR_FAULT_ID							0x660
#define BMS_ACCUMULATOR_SYSTEM_STATE1_ID					0x661
#define BMS_ACCUMULATOR_SYSTEM_STATE2_ID					0x70C
#define BMS_DEBUG_1_ID										0x70D
#define BMS_DEBUG_2_ID										0x70E
#define BMS_CELL_TEMPERATURE_ID								0x462
#define BMS_AUX_ID											0x713


/************************ DATRON *************************/
#define DATRON_1_ID											0x632
#define DATRON_2_ID											0x633


//#define TPMS_1_ID
//#define TPMS_2_ID

/************************CAN2*******************************/

#define INV1_Status                                  0x304
#define INV1_COOL_FB                                 0x400
#define INV1_PID_FB                                  0x306
#define INV1_Ramp_FB                                 0x308
#define INV1_ErrorInfo_1                             0x300
#define INV1_ErrorInfo_2                             0x302
#define INV1_DebugInfo_1                             0x402
#define INV1_VoltageInfo                             0x404
#define INV1_CurrentInfo                             0x406


#define INV2_Status                                  0x305
#define INV2_COOL_FB                                 0x401
#define INV2_PID_FB                                  0x307
#define INV2_Ramp_FB                                 0x309
#define INV2_ErrorInfo_1                             0x301 
#define INV2_ErrorInfo_2                             0x303
#define INV2_DebugInfo_1                             0x403
#define INV2_VoltageInfo                             0x405
#define INV2_CurrentInfo                             0x407

#define INV1_Control                                 0x200
#define INV1_SpeedControl                            0x204
#define INV1_PID                                     0x202
#define INV1_Ramp                                    0x206
#define INV2_Control                                 0x201
#define INV2_SpeedControl                            0x205
#define INV2_PID                                     0x203
#define INV2_Ramp                                    0x207


/************************PRIORITA' MESSAGGI CAN2***********/
#define Pos_INV1_Control 1
#define Pos_INV1_SpeedControl 3
#define Pos_INV1_PID 5
#define Pos_INV1_Ramp 6
#define Pos_INV2_Control 2
#define Pos_INV2_SpeedControl 4
#define Pos_INV2_PID 5
#define Pos_INV2_Ramp 6
/************************CAN3*****************************/

#define INV3_Status               0x604
#define INV3_COOL_FB              0x700
#define INV3_PID_FB               0x606
#define INV3_Ramp_FB              0x608
#define INV3_ErrorInfo_1          0x600
#define INV3_ErrorInfo_2          0x602
#define INV3_DebugInfo_1          0x702
#define INV3_VoltageInfo          0x704
#define INV3_CurrentInfo          0x706

#define INV4_Status               0x605
#define INV4_COOL_FB              0x701
#define INV4_PID_FB               0x607
#define INV4_Ramp_FB              0x609
#define INV4_ErrorInfo_1          0x601
#define INV4_ErrorInfo_2          0x603
#define INV4_DebugInfo_1          0x703
#define INV4_VoltageInfo          0x705
#define INV4_CurrentInfo          0x707


#define INV3_Control              0x500
#define INV3_SpeedControl         0x504
#define INV3_PID                  0x502
#define INV3_Ramp                 0x506
#define INV4_Control              0x501
#define INV4_SpeedControl         0x505
#define INV4_PID                  0x503
#define INV4_Ramp                 0x507
/************************PRIORITA' MESSAGGI CAN3***********/
#define Pos_INV3_Control 1
#define Pos_INV3_SpeedControl 3
#define Pos_INV3_PID 5
#define Pos_INV3_Ramp 6
#define Pos_INV4_Control 2
#define Pos_INV4_SpeedControl 4
#define Pos_INV4_PID 5
#define Pos_INV4_Ramp 6




/******************* MASKS & FILTERS **********************/



#endif //ID_CAN_H

