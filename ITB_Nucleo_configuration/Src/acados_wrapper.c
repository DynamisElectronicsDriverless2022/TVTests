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
int AcadosFlag;
double AcadosState[3];

// Inizializzazione solver, questa la mettiamo nel .h


// Inizializzazione solver, noi la facciamo nel costruttore della classe


double Acados_Caller(double x0[],double extParam[],double limDown[],double limUp[],double reference[],double lbx[], double ubx[],double limAggrDown[],double limAggrUp[],double cost_W[],double constr_C[],double zl_e[], double zu_e[],double x_init[], dt_model_solver_capsule * capsule,double devTorqueOut[]){
    /** Da qua in poi Ã¨ il codice che va messo nella funzione che viene chiamata ogni iterazione per chiamare il solver **/
    // Inizializzazione delle variabili del solver
    ocp_nlp_config *nlp_config = dt_model_acados_get_nlp_config(capsule);
    ocp_nlp_dims *nlp_dims = dt_model_acados_get_nlp_dims(capsule);
    ocp_nlp_in *nlp_in = dt_model_acados_get_nlp_in(capsule);
    ocp_nlp_out *nlp_out = dt_model_acados_get_nlp_out(capsule);

    double N_it = 1;

    // Gli passo lo stato iniziale x0
    //double x0[3];
    //x0[0] = 16
    //x0[1] = -0.2
    //x0[2] = 0.15
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "lbx",(void *) x0);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "ubx",(void *) x0);

    // Gli passo i parametri esterni, in questo caso un solo parametro per il numero di step del solver
    for (int ii = 0; ii <= N_it; ii++) {
        dt_model_acados_update_params(capsule, ii,(void *) &extParam[ii*13], 13);
    }


    // limiti inferiori della variabile di controllo
    for (int ii = 0; ii < N_it; ii++) {
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "lbu", (void *) &limDown[4*ii]);
    }

    // limiti superiori della variabile di controllo
    for (int ii = 0; ii < N_it; ii++) {
        //double temp[]
        //temp[0] = +20; // COPPIA DI PICCO
        //temp[1] = +20; // COPPIA DI PICCO
        //temp[2] = +20; // COPPIA DI PICCO
        //temp[3] = +20; // COPPIA DI PICCO
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "ubu", (void *) &limUp[4*ii]);
    }
    //}

    // riferimento che deve seguire lo stato
    for (int ii = 0; ii <= N_it; ii++) {
        ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, ii, "yref", (void *) &reference[ii*11]);
    }

    // lower bound states
    for (int ii=1; ii<=N_it; ii++) {
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "lbx", (void *) lbx);
    }

    // upper bound states
    for (int ii=1; ii<=N_it; ii++) {
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "ubx", (void *) ubx);
    }

    // constraint affine (somma di coppie)
    for (int ii = 0; ii <= N_it; ii++) {
        //double temp[1]
        //temp[0] = -4*20; //
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "lg", (void *) limAggrDown);
    }
    // constraint affine (somma di coppie)
    for (int ii = 0; ii <= N_it; ii++) {
        //double temp[1]
        //temp[0] = +4*20; //
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "ug", (void *) limAggrUp);
    }
    for(int ii=1; ii < N_it; ii++){
        ocp_nlp_cost_model_set(nlp_config,nlp_dims,nlp_in,ii,"W",(void *) cost_W);
    }

    for (int ii = 0; ii <= N_it; ii++)
        ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, ii, "C", (void *) constr_C);

    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 1, "zu",(void *) zu_e);
    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, 1, "zl",(void *) zl_e);

    for (int ii = 0; ii < 1; ii++)
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, 1, "x", (void *) x_init);  
    // chiamata al solver
    int rti_phase = 0;
    ocp_nlp_solver_opts_set(nlp_config, capsule->nlp_opts, "rti_phase", &rti_phase);
    int volatile acados_status = dt_model_acados_solve(capsule);

    // prendo il vettore delle variabili predette dal solver al primo step (u + x)

    ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, 0, "u", (void *) devTorqueOut);


    double stateOut[7];
    ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, 1, "x", (void *) &stateOut[0]);
    AcadosState[0]=stateOut[0]; //Vx
    AcadosState[1]=stateOut[1]; //Vy
    AcadosState[2]=stateOut[2]; //r
    AcadosState[3]=stateOut[3]; //T_FL
    AcadosState[4]=stateOut[4]; //T_FR
    AcadosState[5]=stateOut[5]; //T_RL
    AcadosState[6]=stateOut[6]; //T_RR

    int acados_status_My[1];
    ocp_nlp_get(nlp_config, capsule->nlp_solver, "status", acados_status_My);
    int volatile exitflag = acados_status_My[0];
    AcadosFlag= exitflag;

    // tempo di solving
//  double out_cpu_time[1];
//  ocp_nlp_get(nlp_config, capsule->nlp_solver, "time_tot", (void *) out_cpu_time);
//
//  // per debug
//  if (acados_status != 0) printf("Acados longitudinal mpc failed, exitflag = %i.\n", acados_status);
//  acadostime_long = out_cpu_time[0];

    // estraggo il valore di interesse della variabile di controllo dal vettore delle variabili predette
    return 1;
}
#endif
double Acados_Caller_wrapper(double x0[],double extParam[],double limDown[],double limUp[],double reference[],double lbx[], double ubx[],double limAggrDown[],double limAggrUp[],double cost_W[],double constr_C[],double zl_e[], double zu_e[],double x_init[],double devTorqueOut[]){
	#ifndef MATLAB_MEX_FILE
		return Acados_Caller(x0,extParam,limDown,limUp,reference,lbx,ubx,limAggrDown,limAggrUp,cost_W,constr_C,zl_e,zu_e,x_init,capsule,devTorqueOut);
	#endif
	return x0[0]+x0[1];	
}

