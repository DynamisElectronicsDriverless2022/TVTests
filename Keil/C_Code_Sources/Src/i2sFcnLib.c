/****************************************************************DynamisPRC Property*****************************************************************************/

#include "i2sFcnLib.h"

#define I2S1_IS_USED
//#define I2S2_IS_USED
//#define I2S3_IS_USED

/**
  * @brief  Send elements starting from pData[0] to pData[Size-1] via i2s with dma 
  * @param  I2SName: I2S peripheral name
  * @param  pData: array with the data to send, pdata must be an uint16_t type and must be a campioned stereo audio signal, 
  WARNING: unsigned long long is for keil an uint32_t but is for matlab an uint64, if you're using the function in to matlab code remember to create the inport
  as uint64, the compiler when casting will turn it into a proper pointer
  * @param  Size: number of elements of pData to be sent, the maximun is 65536
  */

void i2S_DMA_Transimit(int I2SName,unsigned long long pData, unsigned short int Size, unsigned long long lenght){

    #ifndef MATLAB_MEX_FILE
			I2S_HandleTypeDef * I2S_Handler = I2S_getHandler((I2SPeripheral)I2SName);
			HAL_I2S_Transmit_DMA(I2S_Handler,(uint16_t*) pData+lenght, Size);
    #endif
}


/*Function Definition for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

	#include "main.h"


/**
  * @brief              This function takes the I2S Peripheral name and returns its handler in Keil enviroment
  * @param I2CName      The I2S peripheral name whose handler is required
  * @return             handler to the I2S peripheral requested
  */

	I2S_HandleTypeDef * I2S_getHandler(I2SPeripheral I2SName){
	
	  switch(I2SName)
	  {
			#ifdef I2S1_IS_USED
	    case HI2S1 :
	        return &hi2s1;
		  #endif
			#ifdef I2S2_IS_USED
	    case HI2S2 :
	        return &hi2s2;
			#endif
			#ifdef I2S3_IS_USED
	    case HI2S3 :
	        return &hi2s3;
			#endif
	
	    default :
	        return 0;
	   }
	}



#endif



/*Function Definition for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE


#endif

