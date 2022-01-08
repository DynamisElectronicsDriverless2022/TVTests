#ifndef USART_FCN_LIB
#define USART_FCN_LIB

#ifndef MATLAB_MEX_FILE
#include "main.h"
#include "usart.h"
#endif

int usartTransmit_DMA_wrapper(unsigned char usartNum, unsigned char *dataArray, unsigned short dataLen);

int usartRead_IT_wrapper(unsigned char usartNum, unsigned char *readArray, unsigned short dataLen);

#endif


