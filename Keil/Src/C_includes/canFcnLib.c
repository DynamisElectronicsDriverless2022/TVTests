#include "canFcnLib.h"


#ifndef MATLAB_MEX_FILE

#include "can.h"

CAN_TxHeaderTypeDef packetHeader;
CAN_FilterTypeDef canFilterConfigHeader;
uint8_t dataPacket[8];


void canStart(CAN_HandleTypeDef *hcan)
{
	canFilterConfig(hcan);
	
	HAL_CAN_ActivateNotification(hcan, CAN_IT_TX_MAILBOX_EMPTY);
	HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
    HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO1_MSG_PENDING);
	HAL_CAN_Start(hcan);
	return;
}


void canFilterConfig(CAN_HandleTypeDef *hcan)
{	
    if 	(hcan->Instance==CAN2)
	{
		canFilterConfigHeader.FilterBank = 14;
	}
	else
	{
		canFilterConfigHeader.FilterBank = 0;
	}

    canFilterConfigHeader.FilterMode = CAN_FILTERMODE_IDMASK;
    canFilterConfigHeader.FilterScale = CAN_FILTERSCALE_32BIT;
	canFilterConfigHeader.FilterIdHigh = (0x000 << 5);
    canFilterConfigHeader.FilterIdLow = 0x0000;
    canFilterConfigHeader.FilterMaskIdHigh = (0x000 << 5);
    canFilterConfigHeader.FilterMaskIdLow = 0x0000;
	canFilterConfigHeader.FilterFIFOAssignment = CAN_RX_FIFO0;
    canFilterConfigHeader.FilterActivation = ENABLE;	
    canFilterConfigHeader.SlaveStartFilterBank = 14;

	HAL_CAN_ConfigFilter(hcan, &canFilterConfigHeader);

	return;
}


void canSend(CAN_HandleTypeDef *hcan, unsigned short ID, uint8_t dataArray[8], uint8_t dlc_value)
{
	uint32_t mailbox;
	
	packetHeader.StdId = ID;
	packetHeader.RTR = CAN_RTR_DATA;
	packetHeader.IDE = CAN_ID_STD;
	packetHeader.DLC = dlc_value;

    for(int i=0; i<8; i++)
    dataPacket[i] = dataArray[i];
	
     HAL_CAN_AddTxMessage(hcan, &packetHeader, dataPacket, &mailbox);
}
int canFreeMailbox(CAN_HandleTypeDef *hcan){
	return HAL_CAN_GetTxMailboxesFreeLevel(hcan);
}
#endif


int canStart_wrapper(int canNumber)
{
    #ifndef MATLAB_MEX_FILE

    if (canNumber == 1)
        canStart(&hcan1);
    else if (canNumber == 2)
        canStart(&hcan2);
    else if (canNumber == 3)
        canStart(&hcan3);

    return 1;

    #else 
    return 0;

    #endif  
}


int canSend_wrapper(unsigned char canNumber, unsigned short ID, unsigned char dataArray[8], unsigned char dlc_value)
{
    #ifndef MATLAB_MEX_FILE

    if (canNumber == 1)
        CAN_send(&hcan1, ID, (uint8_t*) dataArray, (uint8_t) dlc_value);

    else if (canNumber == 2)
        CAN_send(&hcan2, ID, (uint8_t*) dataArray, (uint8_t) dlc_value);

    else if (canNumber == 3)
        CAN_send(&hcan3, ID, (uint8_t*) dataArray, (uint8_t) dlc_value);       

    return 1;

    #else
    return 0;

    #endif
}

int canFreeMailbox_wrapper(int canNumber)
{
    #ifndef MATLAB_MEX_FILE
    if (canNumber == 1)
        return canFreeMailbox(&hcan1)
    else if (canNumber == 2)
        return canFreeMailbox(&hcan2)
    else if (canNumber == 3)
        return canFreeMailbox(&hcan3)   
    #else
    return 0;
    #endif
}









