#include "pwmFcnLib.h"


#ifndef MATLAB_MEX_FILE
void pwm_setDutyCycle(TIM_HandleTypeDef *htim, uint32_t *CCR_reg, unsigned char dutyCycle)
{
  int pwmValue;
  
  pwmValue = (htim->Init.Period)*((double)dutyCycle)/100;
  
  *CCR_reg = pwmValue;    
}
#endif

void pwmStart_wrapper(unsigned char timerNum, unsigned char channelNum)
{
    #ifndef MATLAB_MEX_FILE
//    if (timerNum == 8)
//    {
//        if (channelNum == 2)
//            HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_2);                              
//    }
//		else if (timerNum == 3)
//    {
//			if (channelNum == 2)
//            HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);   
//		}
//		else if (timerNum == 2)
//    {
//			if (channelNum == 2)
//            HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);   
//		}
    #endif    
}
 


void pwm_setDutyCycle_wrapper(unsigned char timerNum, unsigned char channelNum, unsigned char dutyCycle)
{
    #ifndef MATLAB_MEX_FILE
    TIM_HandleTypeDef *htim_PWM;
    uint32_t *CCR_pwm;

//    if (timerNum == 8)
//    {
//        htim_PWM = &htim8;
//        if (channelNum == 2)
//            CCR_pwm = (uint32_t *)&(htim_PWM->Instance->CCR2);                   
//    }
//		else if (timerNum == 3)
//    {
//        htim_PWM = &htim3;
//        if (channelNum == 2)
//            CCR_pwm = (uint32_t *)&(htim_PWM->Instance->CCR2);                          
//    }
//		else if (timerNum == 2)
//    {
//        htim_PWM = &htim2;
//        if (channelNum == 2)
//            CCR_pwm = (uint32_t *)&(htim_PWM->Instance->CCR2);                          
//    }


    pwm_setDutyCycle(htim_PWM, CCR_pwm, dutyCycle);
    #endif 
}








