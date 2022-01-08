/****************************************************************DynamisPRC Property*****************************************************************************/

#include "gpioFcnLib.h"

/*Global Function Definition*/

/*
@brief            This function writes a boolean value on a GPIO pin.
@param PortName   the GPIO Port name (letter) that contains the needed pin
@param Pin        the pin to be written to
@param state      the value of the GPIO: 1 = SET, 0 = RESET
*/
void GPIO_WritePin(int PortName, unsigned short Pin, unsigned char state) {
#ifndef MATLAB_MEX_FILE

  GPIO_TypeDef *gpioPort;
  uint16_t gpioPin;

  gpioPort = getGPIOPort((GPIOPortName)PortName);
  gpioPin = getGPIOPin(Pin);

  switch (state) {
    case 0:
      HAL_GPIO_WritePin(gpioPort, gpioPin, GPIO_PIN_RESET);
      break;
    case 1:
      HAL_GPIO_WritePin(gpioPort, gpioPin, GPIO_PIN_SET);
    default:
      break;
  }
  HAL_GPIO_WritePin(gpioPort, gpioPin, state);

#endif
}

/*
@brief            This function writes a boolean value on a GPIO pin.
@param PortName   the GPIO Port name (letter) that contains the needed pin
@param Pin        the pin to be read
*/
unsigned char GPIO_ReadPin(GPIOPortName PortName, unsigned short Pin) {
#ifndef MATLAB_MEX_FILE

  GPIO_TypeDef *gpioPort;
  uint16_t gpioPin;

  gpioPort = getGPIOPort(PortName);
  gpioPin = getGPIOPin(Pin);

  return HAL_GPIO_ReadPin(gpioPort, gpioPin);

#endif
}

/*Funciton Definition for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

GPIO_TypeDef *getGPIOPort(GPIOPortName PortName) {
  switch (PortName) {
    case A:
      return GPIOA;

    case B:
      return GPIOB;

    case C:
      return GPIOC;

    case D:
      return GPIOD;

    case E:
      return GPIOE;

    case F:
      return GPIOF;

    case G:
      return GPIOG;

    case H:
      return GPIOH;

    case I:
      return GPIOI;

    case J:
      return GPIOJ;

    default:
      return GPIOK;
  }
}

uint16_t getGPIOPin(unsigned short Pin) {
  switch (Pin) {
    case 0:
      return GPIO_PIN_0;

    case 1:
      return GPIO_PIN_1;

    case 2:
      return GPIO_PIN_2;

    case 3:
      return GPIO_PIN_3;

    case 4:
      return GPIO_PIN_4;

    case 5:
      return GPIO_PIN_5;

    case 6:
      return GPIO_PIN_6;

    case 7:
      return GPIO_PIN_7;

    case 8:
      return GPIO_PIN_8;

    case 9:
      return GPIO_PIN_9;

    case 10:
      return GPIO_PIN_10;

    case 11:
      return GPIO_PIN_11;

    case 12:
      return GPIO_PIN_12;

    case 13:
      return GPIO_PIN_13;

    case 14:
      return GPIO_PIN_14;

    default:
      return GPIO_PIN_15;
  }
}

#endif

/*Function Definition for Simulink Enviroment*/
#ifdef MATLAB_MEX_FILE

/*Define here function which should be compiled only in Simulink Enviroment*/

#endif
