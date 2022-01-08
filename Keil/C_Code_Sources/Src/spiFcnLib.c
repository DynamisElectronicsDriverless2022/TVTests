/****************************************************************DynamisPRC Property*****************************************************************************/
/*To correctly use this Lib, comment out the definition "SPIx_IS_USED" based on the peripheral it is used on the code*/

#include "spiFcnLib.h"

//#define SPI1_IS_USED
//#define SPI2_IS_USED
//#define SPI3_IS_USED
//#define SPI4_IS_USED
#define SPI5_IS_USED
//#define SPI6_IS_USED

/*Global Function Definition*/

/*
@brief            This function starts the SPI Transmission in DMA mode. When the transmission is over the TxCmpltCallback is invoked.
@param SPIName    the SPI peripheral name that must perform the transmission
@param pData      the pointer to the array where the data to be transmitted is stored
@param length     number of elements (bytes) in pData to be transmitted
*/
void SPITransmitDMA(int SPIName, unsigned char* pData, unsigned short length) {
#ifndef MATLAB_MEX_FILE
	//unsigned char RxData[2];
  SPI_HandleTypeDef* SPI_Handler = getSPIPeripheral((SPIPeripheral) SPIName);
  HAL_SPI_Transmit_IT(SPI_Handler, pData, length);
	//HAL_SPI_TransmitReceive_DMA(SPI_Handler,pData, RxData, length);
#endif
}


void SPITransmitDMA_VCU_ADC(int SPIName, unsigned char firstByte,unsigned char secondByte, unsigned short length) {
	unsigned char pdata[2]={secondByte,firstByte};
	SPITransmitDMA(SPIName,pdata,length);
}
/*
@bried            This function starts the SPI Reception in DMA mode. When the transmission is over the data is stored by DMA in the array pointed to by pData, and the RxCmpltCallback is invoked.
@param SPIName    the SPI peripheral name that must perform the conversion
@param pData      the pointer to the array where the data will be stored
@param length     number of elements (bytes) to be stored in the array pData
*/
void SPIReceiveDMA(int SPIName, unsigned char* pData, unsigned short length) {
#ifndef MATLAB_MEX_FILE
	unsigned char TxData[2]={0,0};
  SPI_HandleTypeDef* SPI_Handler = getSPIPeripheral((SPIPeripheral)SPIName);
  HAL_SPI_TransmitReceive_DMA(SPI_Handler,TxData, pData, length);

#endif
}

/*Funciton Definition for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

#include "main.h"

/*

@brief            This function takes the SPI Peripheral name and returns its handler in Keil enviroment
@param SPIName    the SPI peripheral name whose handler is required
@return           handler to the SPI peripheral requested

*/
SPI_HandleTypeDef* getSPIPeripheral(SPIPeripheral SPIName) {
  switch (SPIName) {
    case SPI1_ID:
#ifdef SPI1_IS_USED
      return &hspi1;
#endif

    case SPI2_ID:
#ifdef SPI2_IS_USED
      return &hspi2;
#endif

    case SPI3_ID:
#ifdef SPI3_IS_USED
      return &hspi3;
#endif

    case SPI4_ID:
#ifdef SPI4_IS_USED
      return &hspi4;
#endif

    case SPI5_ID:
#ifdef SPI5_IS_USED
      return &hspi5;
#endif

    case SPI6_ID:
#ifdef SPI6_IS_USED
      return &hspi6;
#endif

    default:
      return 0;
  }
}

#endif

/*Function Definition for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE

/*Define here function which should be compiled only in Simulink Enviroment*/

#endif

/**************************************************************end of file**************************************************************************************/
