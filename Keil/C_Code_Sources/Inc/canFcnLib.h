/****************************************************************DynamisPRC Property*****************************************************************************/


#ifndef CAN_FCN_LIB
#define CAN_FCN_LIB


/*Global Function Declaration*/


typedef enum {
	CAN1_ID,
	CAN2_ID,
	CAN3_ID
} CANPeripheral;

typedef struct{
	unsigned int FilterBank;
	unsigned int FilterMode;
	unsigned int FilterScale;
	unsigned int FilterIDHigh;
	unsigned int FilterIDLow;
	unsigned int FilterMaskIDHigh;
	unsigned int FilterMaskIDLow;
	unsigned int filterFIFOAssignment;
	unsigned int FilterActivation;
	unsigned int SalveStartFilterBank;	
}CAN_FilterType;


typedef struct{
	unsigned int StdId;
	unsigned int ExtId;
	unsigned int RTR;
	unsigned int IDE;
	unsigned int DLC;
	unsigned int TransmitGlobalTime;
}CAN_TxHeaderType;

typedef struct{
	unsigned int StdId;
	unsigned int ExtId;
	unsigned int RTR;
	unsigned int IDE;
	unsigned int DLC;
	unsigned int Timestamp;
	unsigned int FilterMatchIndex;	
}CAN_RxHeaderType;

typedef struct {
  unsigned char Extended;
  unsigned char Length;
  unsigned char Remote;
  unsigned char  Error;
  unsigned int ID;
  double Timestamp;
  unsigned char Data[8];
} CAN_Msg;

typedef struct{
    unsigned char 	Extended;
	unsigned char 	Length;
	unsigned char 	Remote;
	unsigned char 	Error;
	unsigned int 	ID;
	double          Timestamp;
	unsigned char   Data[8];
}CAN_Msg_Pack;

void CANStart(CANPeripheral CANName);
int canFreeMailbox(CANPeripheral CANName);
unsigned canSendINT(int CANName, unsigned short ID,  unsigned char dataArray[8],  unsigned char dlc_value);
void CANConfigFilter(CANPeripheral CANName);		
unsigned int CANSend(CANPeripheral CANName, CAN_TxHeaderType CAN_TxHeader , unsigned char * Data, unsigned int * pTxMailbox);							
unsigned int CANRecive(CANPeripheral CANName, CAN_RxHeaderType * CAN_RxHeader, unsigned char * Data, unsigned int RxFifo);	
unsigned int CANSendRaw(CANPeripheral CANName,CAN_Msg CAN_MessageTx );
unsigned int CANReciveRaw(CANPeripheral CANName,unsigned int RxFifo, CAN_Msg * CAN_MessageTx, unsigned int Length);


/*Funciton declaration for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

#include "main.h"
#include "can.h"

/*Library Defines*/

/*CANTx and CANRx Header Index*/
#define STDID_INDEX 				0
#define RTR_INDEX 	 				1
#define IDE_INDEX  					2
#define DLC_INDEX					3
#define TRANSMIT_GLOBAL_TIME_INDEX	4

/*CANConfigFilter Index*/
#define FILTER_BANK_INDEX 				0
#define FILTER_MODE_INDEX				1
#define FILTER_SCALE_INDEX				2
#define FILTER_ID_HIGH_INDEX			3
#define FILTER_ID_LOW_INDEX				4
#define FILTER_MASK_ID_HIGH_INDEX		5
#define FILTER_MASK_ID_LOW_INDEX		6
#define FILTER_FIFO_ASSINGMENT_INDEX	7
#define FILTER_ACTIVATION_INDEX			8
#define SLAVE_START_FILTER_BANK_INDEX	9


CAN_HandleTypeDef * getCANPeripheral(CANPeripheral CANName);

#endif


/*Funciton declaration for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE



#endif



#endif

/**************************************************************end of file**************************************************************************************/
