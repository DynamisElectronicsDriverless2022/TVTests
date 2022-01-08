/****************************************************************DynamisPRC Property*****************************************************************************/
/*To correctly use this Lib, comment out the definition "CANx_IS_USED" based on the peripheral it is used on the code*/

#include "canFcnLib.h"
#define CAN1_IS_USED
#define CAN2_IS_USED
#define CAN3_IS_USED

#include "stdlib.h"


/*Global Function Definition*/


/*

@general : This function start the CAN peripheral unmasking the Transmission Cmplt Interrupt and the Reception Cplt Interrupt on both FIFOs.
@param CANName : the CAN peripheral name that must be started
@return        : none

*/
void CANStart(CANPeripheral CANName){
	#ifndef MATLAB_MEX_FILE
	

	CAN_HandleTypeDef * CAN_Handler = getCANPeripheral(CANName);


	CANConfigFilter(CANName);
	
	HAL_CAN_ActivateNotification(CAN_Handler, CAN_IT_TX_MAILBOX_EMPTY);
	HAL_CAN_ActivateNotification(CAN_Handler, CAN_IT_RX_FIFO0_MSG_PENDING);
  HAL_CAN_ActivateNotification(CAN_Handler, CAN_IT_RX_FIFO1_MSG_PENDING);
	HAL_CAN_Start(CAN_Handler);

	#endif
}

/*

@general : This function gets free mailboxes.
@param CANName 		: the CAN peripheral name that whose filter must be applied
@return        		: none

*/
int canFreeMailbox(CANPeripheral CANName){
    #ifndef MATLAB_MEX_FILE
	CAN_HandleTypeDef * CAN_Handler = getCANPeripheral(CANName);
	return HAL_CAN_GetTxMailboxesFreeLevel(CAN_Handler);
	#endif
}

/*

@general : This function configures the CAN Filters.
@param CANName 		: the CAN peripheral name that whose filter must be applied
@param sCANFilter	: CanFilterType variable which stores the Filters parameters that must be applied
@return        		: none

*/
void CANConfigFilter(CANPeripheral CANName){
	#ifndef MATLAB_MEX_FILE

	CAN_HandleTypeDef * CAN_Handler = getCANPeripheral(CANName);
	CAN_FilterTypeDef  sFilterConfig;
	if(CAN_Handler->Instance == CAN2)
	{
		sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
		sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
		sFilterConfig.FilterIdHigh = (0x000 << 5);
		sFilterConfig.FilterIdLow = 0x0000;
		sFilterConfig.FilterMaskIdHigh = (0x000 << 5);
		sFilterConfig.FilterMaskIdLow = 0x0000;
		sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
		sFilterConfig.FilterActivation = ENABLE;	
		sFilterConfig.FilterBank = 14;
		sFilterConfig.SlaveStartFilterBank = 14;		
		
		HAL_CAN_ConfigFilter(CAN_Handler, &sFilterConfig);
	}
	else if (CAN_Handler->Instance == CAN1)
	{	
		sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
		sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
		sFilterConfig.FilterIdHigh = (0x000 << 5);
		sFilterConfig.FilterIdLow = 0x0000;
		sFilterConfig.FilterMaskIdHigh = (0x000 << 5);
		sFilterConfig.FilterMaskIdLow = 0x0000;
		sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
		sFilterConfig.FilterActivation = ENABLE;	
		sFilterConfig.FilterBank = 0;
		sFilterConfig.SlaveStartFilterBank = 14;
		
		HAL_CAN_ConfigFilter(CAN_Handler, &sFilterConfig);		
	}
	
	else if (CAN_Handler->Instance == CAN3)
	{
		sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
		sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
		sFilterConfig.FilterIdHigh = (0x200 << 5);
		sFilterConfig.FilterIdLow = 0x0000;
		sFilterConfig.FilterMaskIdHigh = (0x7EE << 5);
		sFilterConfig.FilterMaskIdLow = 0x0000;
		sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
		sFilterConfig.FilterActivation = ENABLE;	
		sFilterConfig.FilterBank = 0;
		sFilterConfig.SlaveStartFilterBank = 14;
		
		HAL_CAN_ConfigFilter(CAN_Handler, &sFilterConfig);	
	
		
		sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
		sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
		sFilterConfig.FilterIdHigh = (0x300 << 5);
		sFilterConfig.FilterIdLow = 0x0000;
		sFilterConfig.FilterMaskIdHigh = (0x7B8 << 5);
		sFilterConfig.FilterMaskIdLow = 0x0000;
		sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
		sFilterConfig.FilterActivation = ENABLE;	
		sFilterConfig.FilterBank = 1;
		sFilterConfig.SlaveStartFilterBank = 14;
		
		HAL_CAN_ConfigFilter(CAN_Handler, &sFilterConfig);		
	
	
		sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
		sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
		sFilterConfig.FilterIdHigh = (0x400 << 5);
		sFilterConfig.FilterIdLow = 0x0000;
		sFilterConfig.FilterMaskIdHigh = (0x7FF << 5);
		sFilterConfig.FilterMaskIdLow = 0x0000;
		sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
		sFilterConfig.FilterActivation = ENABLE;	
		sFilterConfig.FilterBank = 2;
		sFilterConfig.SlaveStartFilterBank = 14;
		
		HAL_CAN_ConfigFilter(CAN_Handler, &sFilterConfig);	
	
	
		sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
		sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
		sFilterConfig.FilterIdHigh = (0x661 << 5);
		sFilterConfig.FilterIdLow = 0x0000;
		sFilterConfig.FilterMaskIdHigh = (0x7FF << 5);
		sFilterConfig.FilterMaskIdLow = 0x0000;
		sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
		sFilterConfig.FilterActivation = ENABLE;	
		sFilterConfig.FilterBank = 3;
		sFilterConfig.SlaveStartFilterBank = 14;
		
		HAL_CAN_ConfigFilter(CAN_Handler, &sFilterConfig);	
	}
	
	
	
	


	#endif
}

/*

@general : This function send a CAN Data Packet.
@param CANName 		: the CAN peripheral name that must transmit the packet
@param CAN_TxHeader	: CAN_TxHeaderType variable which stores the Tx Packet Information
@param Data  		: Pointer to the data that must be sent
@param pTxMailbox 	: pointer to a variable where the function will return the TxMailbox used to store the Tx message.
This parameter can be a value of @arg CAN_Tx_Mailboxes.
@return        		: HAL Status

*/
unsigned CANSend(CANPeripheral CANName, CAN_TxHeaderType CAN_TxHeader , unsigned char * Data, unsigned int * pTxMailbox){
	
	unsigned int CANTxFcnReturn;

	#ifndef MATLAB_MEX_FILE

	CAN_HandleTypeDef * CAN_Handler = getCANPeripheral(CANName);
	CAN_TxHeaderTypeDef   TxHeader;

	TxHeader.StdId 				= CAN_TxHeader.StdId;
    TxHeader.ExtId				= CAN_TxHeader.ExtId;
    TxHeader.RTR 				= CAN_TxHeader.RTR;
    TxHeader.IDE 				= CAN_TxHeader.IDE;
    TxHeader.DLC 				= CAN_TxHeader.DLC;
    TxHeader.TransmitGlobalTime = ((FunctionalState)CAN_TxHeader.TransmitGlobalTime);

    CANTxFcnReturn = (unsigned int)HAL_CAN_AddTxMessage(CAN_Handler, &TxHeader,Data, pTxMailbox);

	#endif

	return CANTxFcnReturn;
}

/*

@general : This function send a CAN Data Packet.
@param CANName 		: the CAN peripheral name that must transmit the packet
@param ID	        : Id of the message
@param dataArray    : Pointer to the array with the message
@param dlc_value 	: dlc value
@return        		: HAL Status

*/


unsigned canSendINT(int CANName, unsigned short ID, unsigned char dataArray[8], unsigned char dlc_value){
    unsigned int CANTxFcnReturn;
    #ifndef MATLAB_MEX_FILE
    CAN_HandleTypeDef * CAN_Handler = getCANPeripheral((CANPeripheral)CANName);
    uint32_t mailbox;
	uint8_t dataPacket[8];
	CAN_TxHeaderTypeDef   packetHeader;
	
	packetHeader.StdId = ID;
	packetHeader.RTR = CAN_RTR_DATA;
	packetHeader.IDE = CAN_ID_STD;
	packetHeader.DLC = (uint8_t)dlc_value;

    for(int i=0; i<8; i++)
    dataPacket[i] = (uint8_t)dataArray[i];
    CANTxFcnReturn=(unsigned int)HAL_CAN_AddTxMessage(CAN_Handler, &packetHeader, dataPacket, &mailbox);
	#endif
    return CANTxFcnReturn; 
}


/*

@general : This function parse a CAN Data Packet previously recived.
@param CANName 		: the CAN peripheral name that has recived the packet
@param RxFifo 		: Fifo number of the received message to be read. This parameter can be a value of @arg CAN_receive_FIFO_number.
@param CAN_RxHeader	: CAN_RxHeaderType variable which will store the Rx Packet Information
@param Data 		: Pointer to the variable which will store the Rx Packet Data
@return        		: HAL status

*/
unsigned int CANRecive(CANPeripheral CANName, CAN_RxHeaderType * CAN_RxHeader, unsigned char * Data, unsigned int RxFifo){
	
	unsigned int CANRxFcnReturn;

	#ifndef MATLAB_MEX_FILE

	CAN_HandleTypeDef * CAN_Handler = getCANPeripheral(CANName);
	CAN_RxHeaderTypeDef   RxHeader;

	CANRxFcnReturn = (unsigned int)HAL_CAN_GetRxMessage(CAN_Handler, RxFifo, &RxHeader, Data);

	CAN_RxHeader->StdId 				= RxHeader.StdId;
    CAN_RxHeader->ExtId 				= RxHeader.ExtId;
    CAN_RxHeader->RTR 					= RxHeader.RTR;
    CAN_RxHeader->IDE 					= RxHeader.IDE;
    CAN_RxHeader->DLC					= RxHeader.DLC;
    CAN_RxHeader->Timestamp 			= RxHeader.Timestamp;
    CAN_RxHeader->FilterMatchIndex 		= RxHeader.FilterMatchIndex;

	#endif

	return CANRxFcnReturn ;

}

/*

@general : This function parse a CAN Data Packet previously recived. This function is strucuterd particularly to work with CAN Unpack Library Block from Vehicle Network Toolbox in Simulink enviroment
@param CANName 		: the CAN peripheral name that has recived the packet
@param RxFifo 		: Fifo number of the received message to be read. This parameter can be a value of @arg CAN_receive_FIFO_number.
@param CAN_MessageTx: CAN_Msg Type variable which will contain the basic data of the message recived. This prototype is created to match the input requirement of the CAN Unpack Library Block
@param Length 		: CAN Message Length which is to be read
@return        		: HAL status

*/
unsigned int CANReciveRaw(CANPeripheral CANName,unsigned int RxFifo, CAN_Msg * CAN_MessageRx, unsigned int Length){
	
	unsigned int CANRxFcnReturn;

	#ifndef MATLAB_MEX_FILE
	
	CAN_HandleTypeDef * CAN_Handler = getCANPeripheral(CANName);
	CAN_RxHeaderTypeDef   RxHeader;
	uint8_t CAN_RxBuffer[8]={0,0,0,0,0,0,0,0};

	CANRxFcnReturn = (unsigned int)HAL_CAN_GetRxMessage(CAN_Handler, RxFifo, &RxHeader, CAN_RxBuffer);

	CAN_MessageRx->Length				= RxHeader.DLC;
	CAN_MessageRx->ID					= RxHeader.StdId;
	CAN_MessageRx->Extended				= RxHeader.ExtId;
	for ( int i=0;i<8;i++)
		CAN_MessageRx->Data[i] 				= CAN_RxBuffer[i];


	#endif

	return CANRxFcnReturn ;

}

unsigned int CANSendRaw(CANPeripheral CANName, CAN_Msg CAN_MessageTx){

	unsigned int CANTxFcnReturn;
	
	#ifndef MATLAB_MEX_FILE
    uint32_t mailbox;
    
	CAN_HandleTypeDef * CAN_Handler = getCANPeripheral(CANName);
	CAN_TxHeaderTypeDef   TxHeader;

	TxHeader.StdId 				= CAN_MessageTx.ID;
    TxHeader.ExtId				= CAN_MessageTx.Extended;
    TxHeader.RTR 				= CAN_RTR_DATA;
    TxHeader.IDE 				= CAN_ID_STD;
    TxHeader.DLC 				= CAN_MessageTx.Length;
    TxHeader.TransmitGlobalTime = ((FunctionalState)CAN_MessageTx.Timestamp);

    CANTxFcnReturn = (unsigned int)HAL_CAN_AddTxMessage(CAN_Handler, &TxHeader, CAN_MessageTx.Data, &mailbox);

	#endif

	return CANTxFcnReturn;

}


/*Funciton Definition for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

#include "main.h"

/*

@general : This function takes the CAN Peripheral name and returns its handler in Keil enviroment
@param CANName : the CAN peripheral name whose handler is required
@return        : handler to the CAN peripheral requested

*/
CAN_HandleTypeDef * getCANPeripheral(CANPeripheral CANName){

	switch(CANName)
	{
		case CAN1_ID :
			#ifdef CAN1_IS_USED
			return &hcan1;
			#endif

		case CAN2_ID :
			#ifdef CAN2_IS_USED
			return &hcan2;
			#endif

		case CAN3_ID :
			#ifdef CAN3_IS_USED	
			return &hcan3;
			#endif

		default :
			return 0;
	}
}





#endif


/*Function Definition for Simulink Enviroment*/


#ifdef MATLAB_MEX_FILE

/*Define here function which should be compiled only in Simulink Enviroment*/

#endif



/**************************************************************end of file************************************************************************************/




