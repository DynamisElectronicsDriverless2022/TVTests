#include "acados_wrapper.h"
#ifndef MATLAB_MEX_FILE
// include ad acados
//#include "acados/utils/print.h"
#include "acados_c/sim_interface.h"
#include "acados_c/external_function_interface.h"
#include "usart.h"
// include al solver specifico
#include "dt_model_model/dt_model_model.h"
#include "acados_solver_dt_model.h"
extern dt_model_solver_capsule * capsule;

// Inizializzazione solver, questa la mettiamo nel .h

// Inizializzazione solver, noi la facciamo nel costruttore della classe

double Acados_Caller(double x0[],double extParam[],double y_ref0[],double y_ref[],double y_refe[],double lbx[], double ubx[],double limDown[],double limUp[],double lh[],double uh[],double cost_W[],double zl_e[], double zu_e[],double lh_0[], double uh_0[],double D[],double C[], dt_model_solver_capsule * capsule,double u0[],double x1[]){
    /** Da qua in poi Ã¨ il codice che va messo nella funzione che viene chiamata ogni iterazione per chiamare il solver **/
    // Inizializzazione delle variabili del solver
    ocp_nlp_config *nlp_config = dt_model_acados_get_nlp_config(capsule);
    ocp_nlp_dims *nlp_dims = dt_model_acados_get_nlp_dims(capsule);
    ocp_nlp_in *nlp_in = dt_model_acados_get_nlp_in(capsule);
    ocp_nlp_out *nlp_out = dt_model_acados_get_nlp_out(capsule);

    double N_it = 2;

    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "lbx",(void *) x0);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "ubx",(void *) x0);

    // Parameters
    for (int ii = 0; ii <= N_it; ii++) {
        dt_model_acados_update_params(capsule, ii,(void *) &extParam[ii*18], 18);
    }


    // References y_ref_0
    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 0, "yref", (void *) y_ref0);
    // References y_ref
    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 1, "yref", (void *) y_ref);
    // References y_ref_e
    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 2, "yref", (void *) y_refe);


    // Lower bound states
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 1, "lbx", (void *) lbx);

    // Upper bound states
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 1, "ubx", (void *) ubx);

    
    // Lower bound control action
    for (int ii = 0; ii < N_it; ii++) {
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "lbu", (void *) &limDown[4*ii]);
    }

    // Upper bound control action
    for (int ii = 0; ii < N_it; ii++) {
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "ubu", (void *) &limUp[4*ii]);
    }
    //}


    // Lower bound non-linear constraints 
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 1, "lg", (void *) lg);
    // Upper bound non-linear constraints
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 1, "ug", (void *) ug);

    // Weighting matrix
    ocp_nlp_cost_model_set(nlp_config,nlp_dims,nlp_in,1,"W",(void *) cost_W);

    // Lower cost slack variableas+
    for(int ii=0;ii<N_it;ii++){
        ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, ii, "zu",(void *) zu_e);
    }
    // Upper cost slack variables
    for(int ii=0;ii<N_it;ii++){
        ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, ii, "zl",(void *) zl_e);
    }
    
    // Lower bound non-linear constraints stage 0
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "lg", (void *) lg_0);
    // Upper bound non-linear constraints stage 0
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "ug", (void *) ug_0);

    // Control constraint matrix D
    for (int ii = 0; ii < 2; ii++)
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "D",(void *) D);

    // State constraint matrix C
    for (int ii = 0; ii < 2; ii++)
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 1, "C",(void *) C);

    // chiamata al solver
    int rti_phase = 0;
    ocp_nlp_solver_opts_set(nlp_config, capsule->nlp_opts, "rti_phase", &rti_phase);
    int volatile acados_status = dt_model_acados_solve(capsule);

    // prendo il vettore delle variabili predette dal solver al primo step (u + x)

    ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, 0, "u", (void *) u0);



    ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, 1, "x", (void *) x1);


    int AcadosStatus;
    ocp_nlp_get(nlp_config, capsule->nlp_solver, "status", &AcadosStatus);

    return AcadosStatus;
}
#endif
double Acados_Caller_wrapper(double x0[],double extParam[],double y_ref0[],double y_ref[],double y_refe[],double lbx[], double ubx[],double limDown[],double limUp[],double lh[],double uh[],double cost_W[],double zl_e[], double zu_e[],double lh_0[], double uh_0[],double D[],double C[],double u0[],double x1[]){
#ifndef MATLAB_MEX_FILE
    return Acados_Caller(x0,extParam,y_ref0,y_ref,y_refe,lbx,ubx,limDown,limUp,lh,uh,cost_W,zl_e,zu_e,lh_0,uh_0,D,C, capsule,u0,x1);
#endif
    return x0[0]+x0[1];
}
