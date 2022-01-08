#ifndef CONST_DEF_INCLUDE
#define CONST_DEF_INCLUDE

//#define UART_SENT_EEPROM_DATA_WIDTH 19 	//dimensione dei dati inviati via serial al programma eeprom
//#define I2C_SENT_EEPROM_DATA_WIDTH 	16	//dimensione dei dati da scrivere via i2c su eeprom
//#define ADC_DATA_SIZE           		9   //numero di segnali campionati dall'adc
//#define UART_READ_EEPROM_DATA_WIDTH 20 	//dimensione del vettore dei dati letto da seriale per eeprom

//define vector dimensions
//UART
#define UART_SENT_DATA_WIDTH    		40    //dimensione dei dati inviati via seriale dal modello
#define UART_READ_DATA_WIDTH    		10    //dimensione del vettore dei dati letto da seriale
//CAN
#define CAN_SENT_DATA_WIDTH     		8     //dimensione del vettore dei dati inviati CAN
#define CAN_READ_DATA_WIDTH     		8     //dimensione del vettore dei dati letti CAN
//SPI
#define SPI_SEND_DATA_WIDTH             2    //dimensione del vettore dei dati inviati SPI

// extADC_CHANNELS_Utilized
#define SPI_CH  8


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
//define inverter Node address
#define InverterNode_1 0
#define InverterNode_2 1
#define InverterNode_3 0
#define InverterNode_4 1


//Mesaggi Can
#define NUMMsg   32
#define NUMMsgCAN23   7

//Calibrazione
#define NUM_SENS 4



//Costanti IMU
#define GPS_MAX_LENGTH_GGA							(uint8_t)200
#define GPS_MAX_LENGTH_PIMU							(uint8_t)200
#define GPS_MAX_LENGTH_PPIMU						(uint8_t)200
#define GPS_MAX_LENGTH_PINS1						(uint8_t)200
#define GPS_MAX_LENGTH                              (uint8_t)200

/* Message type defines */
#define MESSAGE_TYPE_GGA								(uint8_t)1
#define MESSAGE_TYPE_PIMU								(uint8_t)2
#define MESSAGE_TYPE_PPIMU 							(uint8_t)3
#define MESSAGE_TYPE_PINS1 							(uint8_t)4
#define MESSAGE_TYPE_UNKNOWN						(uint8_t)255

/*date related variable*/
/* Second in a single day */
#define CSECOND_IN_DAY									(uint32_t)8640000
#define CSECOND_IN_HOUR									(uint32_t)360000
#define CSECOND_IN_MINUTE								(uint16_t)6000
#define CSECOND_IN_SECOND								(uint8_t)100
#define DAYS_IN_YEAR										(uint16_t)365
#define MONTHS_IN_YEAR									(uint8_t)12
#define GEN															(uint8_t)31
#define FEB															(uint8_t)28
#define MAR															(uint8_t)31
#define APR															(uint8_t)30
#define MAG															(uint8_t)31
#define GIU															(uint8_t)30
#define LUG															(uint8_t)31
#define AGO															(uint8_t)31
#define SETT														(uint8_t)30
#define OTT															(uint8_t)31
#define NOV															(uint8_t)30
#define DIC															(uint8_t)31


/* calibration constants*/

#define APPS_MIN_CAL        1
#define APPS_MAX_CAL        2   
#define Linear_CAL          3
#define SW_Angle_CAL        4
#define LoadCell_CAL        5

/*Logic constants*/
#define FREQUENCY          0.01


//Define driving modalities
#define SKIDPAD_MODE	   1
#define AUTOX_MODE         3
#define ACCELERATION_MODE  0
#define ENDURANCE_MODE	   2

//OPSTATES
#define OFF 0
#define ON  1
#define RTD 2

//LOGIC
#define FALSE 0
#define TRUE 1

// thresholds
#define PBRAKELOW          5
#define PBRAKEHIGH         10

#define LOADCELLLOW        4.2
#define LOADCELLHIGH       4.3

#define RADTEMPLOW         45
#define RADTEMPHIGH        50

#define DC_DCSENSELOW      10
#define DC_DCSENSEHIGH     12

#define OVERRIDE_LIMIT     500


//times lenght
#define MUSICTIME          3
#define PLAUSIBILITYTIME   0.1
#define BATTFANSTOFF       2
#define BATTFANBFOFF       3  
#define OVERRIDETIME       0.5





#endif
