#include "usartFcnLib.h"


int usartTransmit_DMA_wrapper(unsigned char usartNum, unsigned char *dataArray, unsigned short dataLen)
{
    #ifndef MATLAB_MEX_FILE

    //if (usartNum == 1)
        //HAL_UART_Transmit_DMA(&huart1, (uint8_t*) dataArray, dataLen);

     if (usartNum == 3)
        HAL_UART_Transmit_IT(&huart3, (uint8_t*) dataArray, dataLen);    

    return 1;
    #else
    return 0;
    #endif

    
}


int usartRead_IT_wrapper(unsigned char usartNum, unsigned char *readArray, unsigned short dataLen)
{
    #ifndef MATLAB_MEX_FILE

    //if (usartNum == 1)
        //HAL_UART_Receive_IT(&huart1, (uint8_t*) readArray, dataLen);

     if (usartNum == 3)
        HAL_UART_Receive_IT(&huart3, (uint8_t*) readArray, dataLen);
        
    return 1;
    #else
    return 0;
    #endif
}








