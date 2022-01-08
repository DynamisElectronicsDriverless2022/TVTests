#ifndef PWM_FCN_LIB
#define PWM_FCN_LIB

#ifndef MATLAB_MEX_FILE
#include "main.h"
#include "tim.h"


void pwm_setDutyCycle(TIM_HandleTypeDef *htim, uint32_t *CCR_reg, unsigned char dutyCycle);

//void get_pwm_handlers(uint8_t timerNum, uint8_t channelNum, TIM_HandleTypeDef *htim_PWM, uint32_t *CCR_pwm, uint32_t *pwmChannel);
#endif

void pwmStart_wrapper(unsigned char timerNum, unsigned char channelNum);

// dutyCycle espresso come una percentuale da 0 a 100
void pwm_setDutyCycle_wrapper(unsigned char timerNum, unsigned char channelNum, unsigned char dutyCycle);

#endif


