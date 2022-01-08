#ifndef CAN_FCN_LIB
#define CAN_FCN_LIB

#ifndef MATLAB_MEX_FILE
#include "main.h"


void canStart(CAN_HandleTypeDef *hcan);
void canFilterConfig(CAN_HandleTypeDef *hcan);
void canSend(CAN_HandleTypeDef *hcan, unsigned short ID, uint8_t dataArray[8], uint8_t dlc_value);
int canFreeMailbox(CAN_HandleTypeDef *hcan);
#endif


int canStart_wrapper(int canNumber);
int canSend_wrapper(unsigned char canNumber, unsigned short ID, unsigned char dataArray[8], unsigned char dlc_value);
int canFreeMailbox_wrapper(int canNumber);
#endif


