/****************************************************************DynamisPRC Property*****************************************************************************/

#ifndef SPI_FCN_LIB
#define SPI_FCN_LIB

/*Global Function Declaration*/
typedef enum {
  SPI1_ID,
  SPI2_ID,
  SPI3_ID,
  SPI4_ID,
  SPI5_ID,
  SPI6_ID
} SPIPeripheral;

void SPITransmitDMA(int SPIName, unsigned char* pData, unsigned short length);
void SPIReceiveDMA(int SPIName, unsigned char* pData, unsigned short length);
void SPITransmitDMA_VCU_ADC(int SPIName, unsigned char firstByte,unsigned char secondByte, unsigned short length);
/*Funciton declaration for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

#include "main.h"
#include "spi.h"

SPI_HandleTypeDef* getSPIPeripheral(SPIPeripheral SPIName);

#endif

/*Funciton declaration for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE

#endif

#endif

/**************************************************************end of file**************************************************************************************/
