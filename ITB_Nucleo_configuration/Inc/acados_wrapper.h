#ifndef ACADOS_WRAPPER_H
#define ACADOS_WRAPPER_H

// include ad acados
//#include "acados/utils/print.h"
#include "acados_c/sim_interface.h"
#include "acados_c/external_function_interface.h"

// include al solver specifico
#include "dt_model_model/dt_model_model.h"
#include "acados_solver_dt_model.h"


double Acados_Caller(double x0[],double extParam[],double limDown[],double limUp[],double reference[],double limAggrDown[],double limAggrUp[],dt_model_solver_capsule *capsule_long_,dt_model_solver_capsule * capsule);


#endif