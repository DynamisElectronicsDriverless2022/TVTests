/**
  ******************************************************************************
  * File Name          : USART.c
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "acados_wrapper.h"
#include "tim.h"
#include "usartFcnLib.h"
#include "TVModel.h"

#define BUFFER 128
uint64_t h=0;

int i;
int j;
uint64_t Number;
double Data[2*BUFFER];
uint8_t RxData[2*BUFFER];
uint32_t Time=0;

int BufferTime=0,UsartTime,Count=0;
//uint8_t TxData[36]={'\0','\0','\r',10};
uint8_t TxData[37];
uint64_t* ptr;
double outData[4]={3333, 5555, 4444, 7777};
uint16_t TemopoEsecuzione1=0,TemopoEsecuzione2=0;

extern dt_model_solver_capsule *capsule;
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_rx;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PB14     ------> USART1_TX
    PB15     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART1 DMA Init */
    /* USART1_RX Init */
    hdma_usart1_rx.Instance = DMA2_Stream2;
    hdma_usart1_rx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_rx.Init.Mode = DMA_NORMAL;
    hdma_usart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart1_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart1_rx);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PB14     ------> USART1_TX
    PB15     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_14|GPIO_PIN_15);

    /* USART1 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void IdleCallback(void)
{
    //if((&huart1)->RxXferCount != 256){

        //Penso che questi incrementi possano essere tolti
        h++;

        Number=0;
        //Creo un array "Data" contenente gli ingressi del blocco TV

        for(j=0;j<BUFFER/8;j++){
            //Creo un double come 8 gruppi di 8 bit ciascuno
            for(i=0;i<8;i++){
                Number+=((int64_t)RxData[8*j+i])<<(8*i);
            }
            Data[j]=*((double *)&Number);
            Number=0;
        }

        //Assegnazione degli elementi di Data[] agli import di Simulink
        rtU.throttle= Data[0];
        rtU.brake= Data[1];
        rtU.steering= Data[2];
        rtU.vx= Data[3];
        rtU.vy= Data[4];
        rtU.ax= Data[5];
        rtU.ay= Data[6];
        rtU.yaw_rate_deg= Data[7];
        rtU.brake_torque_FL= Data[8];
        rtU.brake_torque_FR= Data[9];
        rtU.brake_torque_RL= Data[10];
        rtU.brake_torque_RR= Data[11];
        rtU.omega_wheels_FL= Data[12];
        rtU.omega_wheels_FR= Data[13];
        rtU.omega_wheels_RL= Data[14];
        rtU.omega_wheels_RR= Data[15];



        //reset periferica con dimensione iniziale del BUFFER
        (&huart1)->RxXferCount = 256;
        (&huart1)->pRxBuffPtr = RxData;
        (&htim6)->Instance->CNT = 0;
        Time = 0;

        //Chiamare funzione TV(void) quando sarà definita
        TV();


        TemopoEsecuzione1=Time*1000+((uint16_t)(&htim6)->Instance->CNT);
        //TemopoEsecuzione2=TemopoEsecuzione1/96;
        TxData[0]=(TemopoEsecuzione1 & 0xFF00)>>8;
        TxData[1]=(TemopoEsecuzione1 & 0x00FF);
        //Qui assegnare a outData i quattro valori di coppia in out da Acados
        for (j=0; j<4; j++){
            //j conta a che output di Acados sono arrivato tr i 4 disponibili
            ptr=(uint64_t *)&(outData[j]);
            for(i=0; i<8 ; i++){
                //i conta a che byte sono arrivato tra gli 8 disponibili nel double (64 bit)
                TxData[2+j*8+i]= (*ptr>>(i*8))&0xFF;     //Assegno ad una cella di TxData il byte puntato da i, a partire dalla seconda
            }
        }
        TxData[34]= exitFlag; //Da definire
        TxData[35]='\r';
        TxData[36]= 10;

        if(TxData[0]==13 && TxData[1]== 10) TxData[1]=11;
        usartTransmit_DMA_wrapper(1,TxData,36);
        BufferTime=0;
    //}
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
