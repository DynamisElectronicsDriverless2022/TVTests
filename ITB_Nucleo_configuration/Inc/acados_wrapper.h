#ifndef ACADOS_WRAPPER_H
#define ACADOS_WRAPPER_H

#ifndef MATLAB_MEX_FILE
// include ad acados
//#include "acados/utils/print.h"
#include "acados_c/sim_interface.h"
#include "acados_c/external_function_interface.h"

// include al solver specifico
#include "dt_model_model/dt_model_model.h"
#include "acados_solver_dt_model.h"


double Acados_Caller(double x0[],double extParam[],double limDown[],double limUp[],double reference[],double lbx[], double ubx[],double limAggrDown[],double limAggrUp[],double cost_W[],double constr_C[],dt_model_solver_capsule * capsule, double torqueOut[]);

#endif
double Acados_Caller_wrapper(double x0[],double extParam[],double limDown[],double limUp[],double reference[],double lbx[], double ubx[],double limAggrDown[],double limAggrUp[],double cost_W[],double constr_C[], double torqueOut[]);

#endif