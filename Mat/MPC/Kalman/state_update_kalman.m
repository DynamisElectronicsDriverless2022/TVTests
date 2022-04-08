function x = state_update_kalman(x,u)

%% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Intro ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
dt = 1/50;
%% ~~~~~~~~~~~~~~~~~~~~~~~~ Car parameters ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

% ~~~~~~~~~~~~~~~~~~~~~~~~ General Parameters ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
g   = 9.81;            % [m/s^2]                          
wd  = 0.5;             % [~]         
wb  = 1.53;            % [~]          
tf  = 1.27;            % [m]          
tr  = 1.27;            % [m]          
m   = 195+75;          % [Kg]            
Iz  = 120;             % [Kg*m^2]         
a   = wb*wd;           % [m]            
b   = wb - a;          % [m]            
hcog = 0.29;           % [m]           
Fzf  = m*g/2*(wd);     % [N]                 
Fzr  = m*g/2*(1-wd);   % [N]                   
tau = 13.5;            % [~]          
rs  = 0.235;           % [m]           

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Aero parameters ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
wbaero = 0.5542;       % [~]           
hcop = 0.576;          % [m]      
rho = 1.225;           % [Kg/m^3]     
CdA = 1.708;           % [m]     
ClA = 5.14;            % [m]    

% ~~~~~~~~~~~~~~~~~~~~~~~~~~ Other parameters ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Set up states  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
vx = x(1);
vy = x(2);
r  = x(3);

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Set up parameters ~~~~~~~~~~~~~~~~~~~~~~~~~~~

delta    = u(1);
kappa_FL = u(2);
kappa_FR = u(3);
kappa_RL = u(4);
kappa_RR = u(5);
T_FL     = u(6);
T_FR     = u(7);
T_RL     = u(8);
T_RR     = u(9);

ax = 0; ay = 0;
Tbrk_FL  = 0;
Tbrk_FR  = 0;
Tbrk_RL  = 0;
Tbrk_RR  = 0;
%% ~~~~~~~~~~~~~~~~~~~~~~~~~~ System Dynamics ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Aerodynamics ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Faerox = 0.5*rho*CdA*vx^2;
Faeroz = 0.5*rho*ClA*vx^2;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Slip Angles ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
alpha_FL =  (((vy + r*a)./(vx - r*tf/2)) - delta);
alpha_FR =  (((vy + r*a)./(vx + r*tf/2)) - delta);
alpha_RL =  (((vy - r*b)./(vx - r*tr/2)));     
alpha_RR =  (((vy - r*b)./(vx + r*tr/2)));     

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Vertical loads ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Fz_FL = Fzf - 0.5*(m/tf*hcog).*ay + 0.5*Faeroz*wbaero - 0.5*Faerox/wb*hcop - 0.5*(m/wb*hcog).*ax;
Fz_FR = Fzf + 0.5*(m/tf*hcog).*ay + 0.5*Faeroz*wbaero - 0.5*Faerox/wb*hcop - 0.5*(m/wb*hcog).*ax;
Fz_RL = Fzr - 0.5*(m/tr*hcog).*ay + 0.5*Faeroz*(1-wbaero) + 0.5*Faerox/wb*hcop + 0.5*(m/wb*hcog).*ax;
Fz_RR = Fzr + 0.5*(m/tr*hcog).*ay + 0.5*Faeroz*(1-wbaero) + 0.5*Faerox/wb*hcop + 0.5*(m/wb*hcog).*ax;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~ Lateral forces ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Fy_FL = - (1.0*cos(0.958*atan((atan((13.9*(3.86e-7*Fz_FL - 0.0498))/((12.4*alpha_FL - 0.512)^2 + 1.0)^(1/2)) - (13.9*(3.86e-7*Fz_FL - 0.0498))/((12.4*alpha_FL - 0.512)^2 + 1.0)^(1/2))*(0.0013*Fz_FL - 2.33) + (13.9*(3.86e-7*Fz_FL - 0.0498))/((12.4*alpha_FL - 0.512)^2 + 1.0)^(1/2)))*(0.93*Fz_FL*(2.59e-6*Fz_FL + 0.0594) - 1.0*Fz_FL*sin(1.1*atan((atan((3.41e+4*sin(2.0*atan(8.72e-4*Fz_FL))*(3.32e-6*Fz_FL - 1.0*alpha_FL + 2.0e-5))/(1.1*Fz_FL*(3.82e-4*Fz_FL - 1.97) - 0.01)) - (3.41e+4*sin(2.0*atan(8.72e-4*Fz_FL))*(3.32e-6*Fz_FL - 1.0*alpha_FL + 2.0e-5))/(1.1*Fz_FL*(3.82e-4*Fz_FL - 1.97) - 0.01))*(1.18*sign(3.32e-6*Fz_FL - 1.0*alpha_FL + 2.0e-5) + 1.0)*(6.75e-4*Fz_FL - 0.451) + (3.41e+4*sin(2.0*atan(8.72e-4*Fz_FL))*(3.32e-6*Fz_FL - 1.0*alpha_FL + 2.0e-5))/(1.1*Fz_FL*(3.82e-4*Fz_FL - 1.97) - 0.01)))*(3.82e-4*Fz_FL - 1.97)))/cos(0.958*atan((atan((13.9*(3.86e-7*Fz_FL + 2.05e-4))/((12.4*alpha_FL - 0.512)^2 + 1.0)^(1/2)) - (13.9*(3.86e-7*Fz_FL + 2.05e-4))/((12.4*alpha_FL - 0.512)^2 + 1.0)^(1/2))*(0.0013*Fz_FL - 2.33) + (13.9*(3.86e-7*Fz_FL + 2.05e-4))/((12.4*alpha_FL - 0.512)^2 + 1.0)^(1/2))) - (0.969*Fz_FL*(1.03e-5*Fz_FL - 2.88e-4)*(3.82e-4*Fz_FL - 1.97))/(225.0*alpha_FL^2 + 1.0)^(1/2);
Fy_FR = - (1.0*cos(0.958*atan((atan((13.9*(3.86e-7*Fz_FR - 0.0498))/((12.4*alpha_FR - 0.512)^2 + 1.0)^(1/2)) - (13.9*(3.86e-7*Fz_FR - 0.0498))/((12.4*alpha_FR - 0.512)^2 + 1.0)^(1/2))*(0.0013*Fz_FR - 2.33) + (13.9*(3.86e-7*Fz_FR - 0.0498))/((12.4*alpha_FR - 0.512)^2 + 1.0)^(1/2)))*(0.93*Fz_FR*(2.59e-6*Fz_FR + 0.0594) - 1.0*Fz_FR*sin(1.1*atan((atan((3.41e+4*sin(2.0*atan(8.72e-4*Fz_FR))*(3.32e-6*Fz_FR - 1.0*alpha_FR + 2.0e-5))/(1.1*Fz_FR*(3.82e-4*Fz_FR - 1.97) - 0.01)) - (3.41e+4*sin(2.0*atan(8.72e-4*Fz_FR))*(3.32e-6*Fz_FR - 1.0*alpha_FR + 2.0e-5))/(1.1*Fz_FR*(3.82e-4*Fz_FR - 1.97) - 0.01))*(1.18*sign(3.32e-6*Fz_FR - 1.0*alpha_FR + 2.0e-5) + 1.0)*(6.75e-4*Fz_FR - 0.451) + (3.41e+4*sin(2.0*atan(8.72e-4*Fz_FR))*(3.32e-6*Fz_FR - 1.0*alpha_FR + 2.0e-5))/(1.1*Fz_FR*(3.82e-4*Fz_FR - 1.97) - 0.01)))*(3.82e-4*Fz_FR - 1.97)))/cos(0.958*atan((atan((13.9*(3.86e-7*Fz_FR + 2.05e-4))/((12.4*alpha_FR - 0.512)^2 + 1.0)^(1/2)) - (13.9*(3.86e-7*Fz_FR + 2.05e-4))/((12.4*alpha_FR - 0.512)^2 + 1.0)^(1/2))*(0.0013*Fz_FR - 2.33) + (13.9*(3.86e-7*Fz_FR + 2.05e-4))/((12.4*alpha_FR - 0.512)^2 + 1.0)^(1/2))) - (0.969*Fz_FR*(1.03e-5*Fz_FR - 2.88e-4)*(3.82e-4*Fz_FR - 1.97))/(225.0*alpha_FR^2 + 1.0)^(1/2);
Fy_RL = - (1.0*cos(0.958*atan((atan((13.9*(3.86e-7*Fz_RL - 0.0498))/((12.4*alpha_RL - 0.512)^2 + 1.0)^(1/2)) - (13.9*(3.86e-7*Fz_RL - 0.0498))/((12.4*alpha_RL - 0.512)^2 + 1.0)^(1/2))*(0.0013*Fz_RL - 2.33) + (13.9*(3.86e-7*Fz_RL - 0.0498))/((12.4*alpha_RL - 0.512)^2 + 1.0)^(1/2)))*(0.93*Fz_RL*(2.59e-6*Fz_RL + 0.0594) - 1.0*Fz_RL*sin(1.1*atan((atan((3.41e+4*sin(2.0*atan(8.72e-4*Fz_RL))*(3.32e-6*Fz_RL - 1.0*alpha_RL + 2.0e-5))/(1.1*Fz_RL*(3.82e-4*Fz_RL - 1.97) - 0.01)) - (3.41e+4*sin(2.0*atan(8.72e-4*Fz_RL))*(3.32e-6*Fz_RL - 1.0*alpha_RL + 2.0e-5))/(1.1*Fz_RL*(3.82e-4*Fz_RL - 1.97) - 0.01))*(1.18*sign(3.32e-6*Fz_RL - 1.0*alpha_RL + 2.0e-5) + 1.0)*(6.75e-4*Fz_RL - 0.451) + (3.41e+4*sin(2.0*atan(8.72e-4*Fz_RL))*(3.32e-6*Fz_RL - 1.0*alpha_RL + 2.0e-5))/(1.1*Fz_RL*(3.82e-4*Fz_RL - 1.97) - 0.01)))*(3.82e-4*Fz_RL - 1.97)))/cos(0.958*atan((atan((13.9*(3.86e-7*Fz_RL + 2.05e-4))/((12.4*alpha_RL - 0.512)^2 + 1.0)^(1/2)) - (13.9*(3.86e-7*Fz_RL + 2.05e-4))/((12.4*alpha_RL - 0.512)^2 + 1.0)^(1/2))*(0.0013*Fz_RL - 2.33) + (13.9*(3.86e-7*Fz_RL + 2.05e-4))/((12.4*alpha_RL - 0.512)^2 + 1.0)^(1/2))) - (0.969*Fz_RL*(1.03e-5*Fz_RL - 2.88e-4)*(3.82e-4*Fz_RL - 1.97))/(225.0*alpha_RL^2 + 1.0)^(1/2);
Fy_RR = - (1.0*cos(0.958*atan((atan((13.9*(3.86e-7*Fz_RR - 0.0498))/((12.4*alpha_RR - 0.512)^2 + 1.0)^(1/2)) - (13.9*(3.86e-7*Fz_RR - 0.0498))/((12.4*alpha_RR - 0.512)^2 + 1.0)^(1/2))*(0.0013*Fz_RR - 2.33) + (13.9*(3.86e-7*Fz_RR - 0.0498))/((12.4*alpha_RR - 0.512)^2 + 1.0)^(1/2)))*(0.93*Fz_RR*(2.59e-6*Fz_RR + 0.0594) - 1.0*Fz_RR*sin(1.1*atan((atan((3.41e+4*sin(2.0*atan(8.72e-4*Fz_RR))*(3.32e-6*Fz_RR - 1.0*alpha_RR + 2.0e-5))/(1.1*Fz_RR*(3.82e-4*Fz_RR - 1.97) - 0.01)) - (3.41e+4*sin(2.0*atan(8.72e-4*Fz_RR))*(3.32e-6*Fz_RR - 1.0*alpha_RR + 2.0e-5))/(1.1*Fz_RR*(3.82e-4*Fz_RR - 1.97) - 0.01))*(1.18*sign(3.32e-6*Fz_RR - 1.0*alpha_RR + 2.0e-5) + 1.0)*(6.75e-4*Fz_RR - 0.451) + (3.41e+4*sin(2.0*atan(8.72e-4*Fz_RR))*(3.32e-6*Fz_RR - 1.0*alpha_RR + 2.0e-5))/(1.1*Fz_RR*(3.82e-4*Fz_RR - 1.97) - 0.01)))*(3.82e-4*Fz_RR - 1.97)))/cos(0.958*atan((atan((13.9*(3.86e-7*Fz_RR + 2.05e-4))/((12.4*alpha_RR - 0.512)^2 + 1.0)^(1/2)) - (13.9*(3.86e-7*Fz_RR + 2.05e-4))/((12.4*alpha_RR - 0.512)^2 + 1.0)^(1/2))*(0.0013*Fz_RR - 2.33) + (13.9*(3.86e-7*Fz_RR + 2.05e-4))/((12.4*alpha_RR - 0.512)^2 + 1.0)^(1/2))) - (0.969*Fz_RR*(1.03e-5*Fz_RR - 2.88e-4)*(3.82e-4*Fz_RR - 1.97))/(225.0*alpha_RR^2 + 1.0)^(1/2);
% ~~~~~~~~~~~~~~~~~~~~~~~~~~ Longitudinal forces ~~~~~~~~~~~~~~~~~~~~~~~~~~
Fx_FL = (T_FL.*tau - Tbrk_FL)/rs;
Fx_FR = (T_FR.*tau - Tbrk_FR)/rs;
Fx_RL = (T_RL.*tau - Tbrk_RL)/rs;
Fx_RR = (T_RR.*tau - Tbrk_RR)/rs;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~ E.o.M. Balance ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
X1 = (Fx_FL + Fx_FR).*cos(delta) - (Fy_FL + Fy_FR).*sin(delta);
X2 = Fx_RL + Fx_RR;
deltaX1 = ((Fx_FR - Fx_FL).*cos(delta) - (Fy_FR - Fy_FL).*sin(delta))/2;
deltaX2 = (Fx_RR - Fx_RL)/2;

Y1 = (Fy_FL + Fy_FR).*cos(delta) + (Fx_FL + Fx_FR).*sin(delta);
Y2 = Fy_RL + Fy_RR;

X = X1 + X2 - Faerox;
Y = Y1 + Y2;
N = Y1*a - Y2*b + deltaX1*tf + deltaX2*tr;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~ System Dynamics f(x,u) ~~~~~~~~~~~~~~~~~~~~~~
x(1) =  1/m.*(X + vy.*r)*dt + x(1);
x(2) =  1/m.*(Y - vx.*r)*dt + x(2);
x(3) =  1/Iz.*(N)*dt + x(3);
end