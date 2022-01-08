/****************************************************************DynamisPRC Property*****************************************************************************/

#ifndef GPIO_FCN_LIB
#define GPIO_FCN_LIB

/*Global Function Declaration*/

typedef enum {
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K
} GPIOPortName;

void GPIO_WritePin(int PortName, unsigned short Pin, unsigned char state);
unsigned char GPIO_ReadPin(GPIOPortName PortName, unsigned short Pin);

/*Funciton declaration for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

#include "gpio.h"
#include "main.h"

GPIO_TypeDef* getGPIOPort(GPIOPortName PortName);
uint16_t getGPIOPin(unsigned short Pin);

#endif

/*Funciton declaration for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE

#endif

#endif
