#ifndef ID_CAN_H
#define ID_CAN_H

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
#define INV2_Control                                 0x201


/************************PRIORITA' MESSAGGI CAN2***********/
#define Pos_INV1_Status 			0
#define Pos_INV1_COOL_FB 			1
#define Pos_INV1_ErrorInfo_1 		2
#define Pos_INV1_ErrorInfo_2 		3
#define Pos_INV1_DebugInfo_1 	4
#define Pos_INV1_PowerInfo 			5
#define Pos_INV1_CurrentInfo 		6

#define Pos_INV2_Status 			0
#define Pos_INV2_COOL_FB 			1
#define Pos_INV2_ErrorInfo_1 		2
#define Pos_INV2_ErrorInfo_2 		3
#define Pos_INV2_DebugInfo_1 	4
#define Pos_INV2_PowerInfo 			5
#define Pos_INV2_CurrentInfo 		6
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
#define INV4_Control              0x501
/************************PRIORITA' MESSAGGI CAN3***********/
#define Pos_INV3_Status 			0
#define Pos_INV3_COOL_FB 			1
#define Pos_INV3_ErrorInfo_1 		2
#define Pos_INV3_ErrorInfo_2 		3
#define Pos_INV3_DebugInfo_1 	4
#define Pos_INV3_PowerInfo 			5
#define Pos_INV3_CurrentInfo 		6

#define Pos_INV4_Status 			0
#define Pos_INV4_COOL_FB 			1
#define Pos_INV4_ErrorInfo_1 		2
#define Pos_INV4_ErrorInfo_2 		3
#define Pos_INV4_DebugInfo_1 	4
#define Pos_INV4_PowerInfo 			5
#define Pos_INV4_CurrentInfo 		6
/***************************Id test banco*******************/

#define Banco_Inverter_Id                 0x20
#define Banco_cool_id                     0x23

/******************* MASKS & FILTERS **********************/



#endif //ID_CAN_H

