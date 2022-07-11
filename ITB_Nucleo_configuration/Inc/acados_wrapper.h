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


double Acados_Caller(double x0[],double extParam[],double y_ref0[],double y_ref[],double y_refe[],double lbx[], double ubx[],double limDown[],double limUp[],double lh[],double uh[],double cost_W[],double zl_e[], double zu_e[],double lh_0[], double uh_0[],double D[], double C[], dt_model_solver_capsule * capsule,double u0[],double x1[]);

#endif
double Acados_Caller_wrapper(double x0[],double extParam[],double y_ref0[],double y_ref[],double y_refe[],double lbx[], double ubx[],double limDown[],double limUp[],double lh[],double uh[],double cost_W[],double zl_e[], double zu_e[],double lh_0[], double uh_0[],double D[],double C[],double u0[],double x1[]);

#endif