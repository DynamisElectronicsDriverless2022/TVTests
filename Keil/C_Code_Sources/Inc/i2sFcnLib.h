/*****************************************************************DynamisPRC Property*****************************************************************************/

#ifndef I2S_FCN_LIB
#define I2S_FCN_LIB

/*Global Function Declaration*/

	typedef enum{
		HI2S1,
		HI2S2,
		HI2S3
	}I2SPeripheral;

	void i2S_DMA_Transimit(int I2SName,unsigned long long pData, unsigned short int Size, unsigned long long lenght);

/*Function declaration for Keil Enviroment*/

	#ifndef MATLAB_MEX_FILE
	
	#include "main.h"
	#include "i2s.h"
	
		I2S_HandleTypeDef * I2S_getHandler(I2SPeripheral I2SName);

	#endif

/*Function declaration for Simulink Enviroment*/

	#ifdef MATLAB_MEX_FILE
	
	#endif

#endif
