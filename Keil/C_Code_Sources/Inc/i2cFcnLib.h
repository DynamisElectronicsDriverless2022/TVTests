/*****************************************************************DynamisPRC Property*****************************************************************************/

#ifndef I2C_FCN_LIB
#define I2C_FCN_LIB


/*Global Function Declaration*/

typedef enum{
	HI2C1
}I2CPeripheral;

void i2cMemRead_wrapper(int I2CName, unsigned short int DevAddress, unsigned short int MemAddress, unsigned short int MemAddSize, unsigned char *dataArray, unsigned short int Size, unsigned int Timeout);
void i2cMemWrite_wrapper(int I2CName, unsigned short int DevAddress, unsigned short int MemAddress, unsigned short int MemAddSize, unsigned char *dataArray, unsigned short int Size, unsigned int Timeout);
void i2cMemWrite_DMA(int I2CName, unsigned short int DevAddress, unsigned short int MemAddress, unsigned short int MemAddSize, unsigned char data, unsigned short int Size);

/*Function declaration for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

#include "main.h"
#include "i2c.h"

I2C_HandleTypeDef * I2C_getHandler(I2CPeripheral I2CName);

#endif



/*Function declaration for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE



#endif



#endif
