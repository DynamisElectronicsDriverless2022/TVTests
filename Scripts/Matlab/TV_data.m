%% Questo script serve per inizializzare tutte le variabili necessarie al 
%funzionamento del torque vectoring

% % intro
% clear
% clc
% close all

% % folder selection (per ora vuoto)
% addpath(genpath('c_generated_code'));
% addpath(genpath('Model_Data'));
% addpath(genpath('Mask_Icon'));
% addpath(genpath('FIS'));

Nabbo;
Car_Signals;

%% car info
TV.CAR.Tau                                     = 13.5;
TV.CAR.rs                                      = 0.235;
TV.CAR.g                                       = 9.81;
TV.CAR.wd                                      = 0.48;
TV.CAR.wb                                      = 1.53;
TV.CAR.tf                                      = 1.27;
TV.CAR.tr                                      = 1.27;
TV.CAR.m                                       = 195+75;
TV.CAR.Iz                                      = 180;
TV.CAR.a                                       = TV.CAR.wb*TV.CAR.wd; 
TV.CAR.b                                       = TV.CAR.wb - TV.CAR.a;
TV.CAR.hcog                                    = 0.29;
TV.CAR.Fzf                                     = TV.CAR.m*TV.CAR.g/2*(TV.CAR.wd);
TV.CAR.Fzr                                     = TV.CAR.m*TV.CAR.g/2*(1-TV.CAR.wd);
TV.CAR.xcop                                    = 0.6810;
TV.CAR.hcop                                    = 0.576;
TV.CAR.rho                                     = 1.225;
TV.CAR.CdA                                     = 1.908;
TV.CAR.ClA                                     = 5.44;
TV.CAR.BrkArea_front                           = 4*(pi*0.024^2/4);
TV.CAR.DiskDiameter_front                      = 0.185;
TV.CAR.DiskDiameter_rear                       = 0.171;
TV.CAR.BrkArea_rear                            = 2*(pi*0.022^2/4);

% Brembo Z04 brakes
TV.CAR.z04.T                                   = [0,100,200,300,400,500,600];
TV.CAR.z04.mu                                  = [0.6 0.78 0.82 0.82 0.82 0.82 0.82];

%% parametri motori
TV.LV.AMK                                      = load('parametri_amk.mat');
 
% Inverter Efficiency
TV.LV.inv_efficiency                           = 0.96;   

% Motor Efficiency
TV.LV.efficiency_LUT                           = load('AMK_Efficiency.mat');

%% parametri mpc
TV.LUT.MPC_Lut.control_bound_dry               = load("control_bound_dry.mat");

% Time Horizon Settings
TV.MPC.N                                       = 2;
TV.MPC.T                                       = 0.02*2;

% Other data
TV.MPC.nx                                      = 7;
TV.MPC.np                                      = 18;
TV.MPC.ny                                      = 11;
TV.MPC.nu                                      = 4;
TV.MPC.mz_filter_time                          = 0.2;
TV.MPC.mz_filter_tau                           = exp(-TV.MPC.mz_filter_time*5*TV.MPC.T);

%% torque limits
TV.LV.TORQUE.T_nominal_motor                   = 9.8;
TV.LV.TORQUE.T_peak_motor                      = 21;
TV.LV.TORQUE.T_nominal_wheel                   = TV.LV.TORQUE.T_nominal_motor*TV.CAR.Tau;
TV.LV.TORQUE.T_peak_wheel                      = TV.LV.TORQUE.T_peak_motor*TV.CAR.Tau;
TV.LV.TORQUE.T_nominal_setting                 = 1;
TV.LV.TORQUE.T_peak_setting                    = 2;
TV.LV.TORQUE.T_lim_pos                         = load('amkTorqueLimitsLut');
TV.LV.TORQUE.T_lim_pos.table_data              = uint16(TV.LV.TORQUE.T_lim_pos.table_data./TV.LV.TORQUE.T_nominal_motor*1000);
TV.LV.TORQUE.T_lim_pos.breakpoints1            = uint16(TV.LV.TORQUE.T_lim_pos.breakpoints1);
TV.LV.TORQUE.T_lim_pos.breakpoints2            = uint16(TV.LV.TORQUE.T_lim_pos.breakpoints2);
%% LUT potenza
TV.LUT.Power_LUT.Power                         = load('Model_Data\Mat\AMK\power_torque_LUTs.mat');

%% LUT dinamica
TV.LUT.Car_LUT.steer_at_ground_single_axis_LUT = load('steer_at_ground_single_axis.mat');
TV.LUT.Car_LUT.steer_at_ground_LUT             = load('steer_at_ground_different_axis.mat');

%% LUT yrd
TV.LUT.Yrd_LUT.LUT_vectors                     = load('YRD_vectors.mat');
TV.LUT.Yrd_LUT.LUT_0                           = load('YRD_LUT_0.mat');
TV.LUT.Yrd_LUT.LUT_1                           = load('YRD_LUT_1e-3.mat');
TV.LUT.Yrd_LUT.LUT_neg1_5                      = load('YRD_LUT_-1.5e-3.mat');
TV.LUT.Yrd_LUT.LUT_neg3                        = load('YRD_LUT_-3e-3.mat');
%% filter values
TV.FILTERS.movingAverage                       = 5;
TV.FILTERS.sampleTime                          = 0.01;

%% General parameters
TV.LV.GENERAL.ThrottleThresh                   = 0.05;
TV.LV.GENERAL.BrakeThresh                      = 0.05;
% TV.LV.GENERAL.SteerTresh                       = pi/180;
% TV.LV.GENERAL.SteerRelayAmplitude              = 1/4*pi/180;
TV.LV.GENERAL.YRDTresh                         = 0.25;
TV.LV.GENERAL.VxTresh                          = 3;

%% Map parameters
TV.LV.MAP.YrdSelection                         = uint8(2);

%% Simulink Bus
zGeneral_Params                                = struct2bus(TV.LV.GENERAL,'double');
zMap_Params                                    = struct2bus(TV.LV.MAP,'uint8');

%% Functions
function  outBus                               = struct2bus(inStruct, type)

outBus                                         = Simulink.Bus;

fields                                         = fieldnames(inStruct);

for k                                          = 1:length(fields)
    if(strcmp(fields{k},'eepInfo'))
        outBus.Elements(k).Name                        = 'eepInfo';
        outBus.Elements(k).DataType                    = 'Bus: eepromInfo';
        outBus.Elements(k).Complexity                  = 'real';
        outBus.Elements(k).Dimensions                  = 1;
        outBus.Elements(k).DimensionsMode              = 'Fixed';
    else 
        outBus.Elements(k).Name                        = fields{k};
        outBus.Elements(k).DataType                    = type;
        outBus.Elements(k).Complexity                  = 'real';
        outBus.Elements(k).Dimensions                  = 1;
        outBus.Elements(k).DimensionsMode              = 'Fixed';
        
    end    
end  

end