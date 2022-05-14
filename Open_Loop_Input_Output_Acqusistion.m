
uiopen('Select and Open .mat associated to Acquisitions')

ax = timeseries(Ax,time);
ax = cut(ax);

ay = timeseries(Ay,time);
ay = cut(ay);

vx = timeseries(vx/3.6,time);
vx = cut(vx);

vy = timeseries(vy/3.6,time);
vy = cut(vy);

yaw_rate = timeseries(wYaw*180/pi,time);
yaw_rate = cut(yaw_rate);

steering = timeseries(aSteeringWheel,time);
steering = cut(steering);

omega_wheels_FL = timeseries(nMotor_FL*pi/30,time);
omega_wheels_FR = timeseries(nMotor_FR*pi/30,time);
omega_wheels_RL = timeseries(nMotor_RL*pi/30,time);
omega_wheels_RR = timeseries(nMotor_RR*pi/30,time);

omega_wheels_FL = cut(omega_wheels_FL);
omega_wheels_FR = cut(omega_wheels_FR);
omega_wheels_RL = cut(omega_wheels_RL);
omega_wheels_RR = cut(omega_wheels_RR);

brake_torque_FL = timeseries(zeros(length(pBrakeFront),1),time);
brake_torque_FR = timeseries(zeros(length(pBrakeFront),1),time);
brake_torque_RL = timeseries(zeros(length(pBrakeFront),1),time);
brake_torque_RR = timeseries(zeros(length(pBrakeFront),1),time);

brake_torque_FL = cut(brake_torque_FL);
brake_torque_FR = cut(brake_torque_FR);
brake_torque_RL = cut(brake_torque_RL);
brake_torque_RR = cut(brake_torque_RR);

throttle = timeseries(xAPPS/100,time);
throttle = cut(throttle);

brake    = timeseries(xLoadCell/100,time);
brake = cut(brake);

save('Open_Loop_Input_Output.mat','ax','ay','vx','vy','yaw_rate','steering','omega_wheels_FL','omega_wheels_FR','omega_wheels_RL','omega_wheels_RR', ...
     'brake_torque_FL','brake_torque_FR','brake_torque_RL','brake_torque_RR','throttle','brake');

function x = cut(x)

n = length(x.Data)/4;

Data = interp1(1:length(x.Data),x.Data,linspace(1,length(x.Data),n))';
Time = interp1(1:length(x.Time),x.Time,linspace(1,length(x.Time),n))';

x = timeseries(Data,Time);

end