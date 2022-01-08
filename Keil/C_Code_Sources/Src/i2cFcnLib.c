/****************************************************************DynamisPRC Property*****************************************************************************/

#include "i2cFcnLib.h"

#define I2C1_IS_USED


/*Global Function Definition*/


/**
  * @brief  Read an amount of data in blocking mode from a specific memory address
  * @param  I2CName: I2C peripheral name
  * @param  DevAddress: Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  MemAddress: Internal memory address
  * @param  MemAddSize: Size of internal memory address
  * @param  dataArray: Pointer to data buffer
  * @param  Size: Amount of data to be sent
  * @param  Timeout: Timeout duration
  */

void i2cMemRead_wrapper(int I2CName, unsigned short int DevAddress, unsigned short int MemAddress, unsigned short int MemAddSize, unsigned char *dataArray, unsigned short int Size, unsigned int Timeout){

    #ifndef MATLAB_MEX_FILE

    I2C_HandleTypeDef * I2C_Handler = I2C_getHandler((I2CPeripheral)I2CName);

    switch(MemAddSize){

        case 8:
            HAL_I2C_Mem_Read(I2C_Handler, DevAddress<<1, MemAddress, I2C_MEMADD_SIZE_8BIT, dataArray, Size, Timeout);
            break;

        case 16:
            HAL_I2C_Mem_Read(I2C_Handler, DevAddress<<1, MemAddress, I2C_MEMADD_SIZE_16BIT, dataArray, Size, Timeout);

        default:
            break;

    }

    #endif

}


/**
  * @brief  Write an amount of data in blocking mode to a specific memory address
  * @param  I2CName: I2C peripheral name
  * @param  DevAddress: Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  MemAddress: Internal memory address
  * @param  MemAddSize: Size of internal memory address
  * @param  dataArray: Pointer to data buffer
  * @param  Size: Amount of data to be sent
  * @param  Timeout: Timeout duration
  */

void i2cMemWrite_wrapper(int I2CName, unsigned short int DevAddress, unsigned short int MemAddress, unsigned short int MemAddSize, unsigned char *dataArray, unsigned short int Size, unsigned int Timeout){

    #ifndef MATLAB_MEX_FILE

    I2C_HandleTypeDef * I2C_Handler = I2C_getHandler((I2CPeripheral)I2CName);

    switch(MemAddSize){

        case 8:
            HAL_I2C_Mem_Write(I2C_Handler, DevAddress<<1, MemAddress, I2C_MEMADD_SIZE_8BIT, dataArray, Size, Timeout);
            break;

        case 16:
            HAL_I2C_Mem_Write(I2C_Handler, DevAddress<<1, MemAddress, I2C_MEMADD_SIZE_16BIT, dataArray, Size, Timeout);

        default:
            break;

    }

    #endif

}



void i2cMemWrite_DMA(int I2CName, unsigned short int DevAddress, unsigned short int MemAddress, unsigned short int MemAddSize, unsigned char data, unsigned short int Size){
	#ifndef MATLAB_MEX_FILE
		I2C_HandleTypeDef * I2C_Handler = I2C_getHandler((I2CPeripheral)I2CName);
		HAL_I2C_Mem_Write_DMA(I2C_Handler,DevAddress,MemAddress,MemAddSize,&data, Size);
	#endif
}

/*Function Definition for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

#include "main.h"


/**
  * @brief              This function takes the I2C Peripheral name and returns its handler in Keil enviroment
  * @param I2CName      The I2C peripheral name whose handler is required
  * @return             handler to the ADC peripheral requested
  */

I2C_HandleTypeDef * I2C_getHandler(I2CPeripheral I2CName){

  switch(I2CName)
  {
		#ifdef I2C1_IS_USED
    case HI2C1 : 
        return &hi2c1;
		#endif
    default :
        return 0;
   }
}



#endif



/*Function Definition for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE


#endif

