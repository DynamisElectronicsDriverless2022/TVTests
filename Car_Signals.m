%%Script di inizializazione delle flag che arriveranno da elettronica

%% FLAGS
TV.SIGNALS.FLAGS.rtd_flag = 1;
TV.SIGNALS.FLAGS.torque_map = 1;
TV.SIGNALS.FLAGS.tc_flag = 1;

%% CAR SIGNALS
TV.SIGNALS.COOLING.display_overload_inverter = zeros(4, 1);
TV.SIGNALS.COOLING.display_overload_motor = zeros(4, 1);

%% SW SIGNALS
TV.SIGNALS.SW.power_target = 2;

%% SETTINGS SIGNALS
% Expressed in [0,1] w.r.t. nominal torque
TV.SIGNALS.SETTINGS.EngineBrake = 0;

TV.SIGNALS.SETTINGS.LMU = 0.8;
TV.SIGNALS.SETTINGS.IzScale = 1;

% ~~~~~~~~~~~~~~~~~  STANDARD ~~~~~~~~~~~~~~~~~~~~~~~~~ %
%% 
TV.SIGNALS.SETTINGS.LMUxScaleFront = 1;
TV.SIGNALS.SETTINGS.LMUxScaleRear = 1;

TV.SIGNALS.SETTINGS.ThrottleShape = 1.5;

% TV.SIGNALS.SETTINGS.DeltaAxle = 0;

TV.SIGNALS.SETTINGS.VyWeight = 0;
TV.SIGNALS.SETTINGS.wYawWeight = 0e3;
TV.SIGNALS.SETTINGS.TorqueWeight = 1e-4;
TV.SIGNALS.SETTINGS.DerivativeTorqueWeight = 1*3e-2; %1e-6;
