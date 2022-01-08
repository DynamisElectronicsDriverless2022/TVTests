/****************************************************************DynamisPRC Property*****************************************************************************/
/*To correctly use this Lib, comment out the definition "ADCx_IS_USED" based on the peripheral it is used on the code*/

#include "adcFcnLib.h"
#define ADC1_IS_USED
//#define ADC2_IS_USED
//#define ADC3_IS_USED



/*Global Function Definition*/

void ADCStartDMA(ADCPeripheral ADCName, unsigned int * pData, unsigned int Length){
  #ifndef MATLAB_MEX_FILE

  ADC_HandleTypeDef * ADC_Handler = getADCPeripheral(ADCName);
  HAL_ADC_Start_DMA(ADC_Handler,pData,Length);

  #endif
}

void ADCStopDMA(ADCPeripheral ADCName){
  #ifndef MATLAB_MEX_FILE

  ADC_HandleTypeDef * ADC_Handler = getADCPeripheral(ADCName);
  HAL_ADC_Stop_DMA(ADC_Handler);

  #endif
}



/*Funciton Definition for Keil Enviroment*/

#ifndef MATLAB_MEX_FILE

#include "main.h"

ADC_HandleTypeDef * getADCPeripheral(ADCPeripheral ADCName){

  switch(ADCName)
  {
    case ADC1_ID :
      	#ifdef ADC1_IS_USED
      	return &hadc1;
      	#endif

    case ADC2_ID :
    	#ifdef ADC2_IS_USED
     	return &hadc2;
     	#endif

    case ADC3_ID :
    	#ifdef ADC3_IS_USED
      	return &hadc3;
      	#endif

    default :
      return 0;
    }
}

#endif

/*Function Definition for Simulink Enviroment*/

#ifdef MATLAB_MEX_FILE

/*Define here function which should be compiled only in Simulink Enviroment*/

#endif




/**************************************************************end of file**************************************************************************************/









