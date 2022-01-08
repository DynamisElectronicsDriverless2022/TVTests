#ifndef CONST_DEF_INCLUDE
#define CONST_DEF_INCLUDE
//define vector dimensions
//UART
#define UART_SENT_DATA_WIDTH    		40    //dimensione dei dati inviati via seriale dal modello
#define UART_READ_DATA_WIDTH    		4    //dimensione del vettore dei dati letto da seriale

//CAN
#define CAN_SENT_DATA_WIDTH     		8     //dimensione del vettore dei dati inviati CAN
#define CAN_READ_DATA_WIDTH     		8     //dimensione del vettore dei dati letti CAN

#define CAN_Vehicle                     2
#define CAN_Inv12                       1
#define CAN_Inv34                       0

//SPI
#define SPI_SEND_DATA_WIDTH             2    //dimensione del vettore dei dati inviati SPI

// extADC_CHANNELS_Utilized
#define SPI_CH  8
//GPIO ports
#define ADCRESETPORT C
#define ADCRESETPIN 13


//PWM
#define IuTIM 2
#define IuCh 2

#define IvTIM 3
#define IvCh 2

#define IwTIM 8
#define IwCh 2



//Periodi 
#define SEND_SERIAL_DATA_PERIOD 50     //periodo di invio dei dati su seriale 
#define SEND_CAN_DATA_PERIOD    10
#define TOGGLE_LED_PERIOD       500   //periodo di accensione del led
#define ADC_PERIOD              1           //periodo di campionamento dei sensori


//Filtri impostati per il CAN
#define CAN_FILTER_NUMBER   14

//Set e Reset del 
#define GPIO_SET_ON     1
#define GPIO_SET_OFF    0


//define multiportSwitch signals
#define UART_Mode 1
#define CAN_Mode 2

//define inverter constant for parameters managment
#define Inverter_1 0
#define Inverter_2 1
#define Inverter_3 2
#define Inverter_4 3
//define inverter defines for TV
#define Inv_FL 0
#define Inv_FR 1
#define Inv_RL 2
#define Inv_RR 3
//define inverter defines for TV
#define Inv_1 Inv_FL
#define Inv_2 Inv_FR
#define Inv_3 Inv_RL
#define Inv_4 Inv_RR

//Calibrazione
#define NUM_SENS 6

/* calibration constants*/

#define APPS_MIN_CAL        1
#define APPS_MAX_CAL        2   
#define Linear_CAL          4
#define SW_Angle_CAL        3
#define LoadCell_CAL        6

/*Logic constants*/
#define FREQUENCY          0.01

/*I2C Addresses*/
#define SPEAKER_ADDRESS     0xD4



//Define driving modalities
#define CRUISE_CONTROL_MODE 100
#define SKIDPAD_MODE	   4
#define AUTOX_MODE         3
#define ACCELERATION_MODE  2
#define ENDURANCE_MODE	   1
//#define SETTING1         250
//#define SETTING2         251
//#define SETTING3         252
//define SETTING4          253

//Define acceleration and cruise states
#define IDLE                1
#define READY               2
#define GO                  3

//Define acceleration and cruise constants
//#define ACC_SLOPE								1.0
#define ACC_THROTTLE_THRESH     0.8
#define ACC_BRAKE_THRESH        0.1
#define CRUISE_THROTTLE_THRESH  0.1
#define CRUISE_BRAKE_THRESH     0.1

//OPSTATES
#define OFF     0
#define LV_ON   1
#define KEY_ON  2
#define TS_ON   3
#define RTD     4

//LOGIC
#define FALSE 0
#define TRUE 1

#define RS 0.982
#define LD 2.9e-3
#define LQ 3e-3

#define POLE_PAIRS 4
#define FLUX_LINKAGE 75e-3
#define MAX_CURR 7.1
#define BASE_SPEED 4107

#define JMOTOR 27.4e-3


#define SWITCHING 10000
#define BANDWIDTH 100

#define KA_D LD*BANDWIDTH
#define KB_D RS/LD

#define KA_Q LQ*BANDWIDTH
#define KB_Q RS/LQ

#define VDD 12




/*define test_INverter*/
#define FrequencyTest          0.01
#define OffTime            1
#define T_ON               1

#define TORQUELIMITATION 1000.0
#define THROTTLE_GAIN 1.0
#define MZ_LIM 700.0





#endif
