#ifndef USART_FCN_LIB
#define USART_FCN_LIB

#ifndef MATLAB_MEX_FILE
#include "main.h"
#include "usart.h"
#endif

int usartTransmit_DMA_wrapper(unsigned char usartNum, unsigned char *dataArray, unsigned short dataLen);

/*
INPUT: 
    usartNum: numero della uart utilizzata
    readArray: puntatore al vettore da ricevere
    dataLen: lunghezza in byte dei dati da ricevere
OUTPUT: 0 se compilata in MATLAB, 1 altrimenti
Description: Prepara la uart a ricevere su interrupt un messaggio di lunghezza dataLen
*/
int usartRead_IT_wrapper(unsigned char usartNum, unsigned char *readArray, unsigned short dataLen);

#endif


