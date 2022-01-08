/****************************************************************DynamisPRC Property*****************************************************************************/


#ifndef ADC_FCN_LIB
#define ADC_FCN_LIB


/*Global Function Declaration*/


typedef enum {
	ADC1_ID,
	ADC2_ID,
	ADC3_ID
} ADCPeripheral;


void ADCStartDMA(ADCPeripheral ADCName, unsigned int * pData, unsigned int Length);
void ADCStopDMA(ADCPeripheral ADCName);





/*Funciton declaration for Keil Enviroment*/


#ifndef MATLAB_MEX_FILE

#include "main.h"
#include "adc.h"

ADC_HandleTypeDef * getADCPeripheral(ADCPeripheral ADCName);

#endif


/*Funciton declaration for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE



#endif

#endif







/**************************************************************end of file**************************************************************************************/




