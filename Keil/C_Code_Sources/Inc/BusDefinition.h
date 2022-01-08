#ifndef BUS_DEFINITION
#define BUS_DEFINITION

typedef struct {
	short int Negative_Torque_Lim;
	short int Positive_Torque_Lim;
	short int Torque_Target;
}MotorTargets;

typedef struct {
	unsigned char Dc_On;
	unsigned char Inverter_On;
	unsigned char Enable;
	unsigned char Error_Reset;
}InverterControl;

typedef struct {
	double TorqueCurrent;
	double MagnetizingCurrent;
	double ActualSpeed;
	double ActualTorque;
	double ActivePower;
	double ReactivePower;
}MotorFeedback;

typedef struct {
	unsigned char bDcOn;
	unsigned char bDerating;
	unsigned char bError;
	unsigned char bInverterOn;
	unsigned char bQuitDcOn;
	unsigned char bQuitInverterOn;
	unsigned char bSysReady;
	unsigned char bWarn;
	unsigned int DiagnosticNumber;
	unsigned int ErrorInfo1;
	unsigned int ErrorInfo2;
	unsigned int ErrorInfo3;
}LogicFeedback;

typedef struct {
	unsigned char DcBus;
	unsigned char OverLoadCurrent;
	unsigned char OverLoadMotor;
	unsigned char T_ColdPlate;
	unsigned char T_Motor;
	unsigned char T_IGBT;
}SensorData;









#endif
