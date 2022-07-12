/*
 * Copyright 2019 Gianluca Frison, Dimitris Kouzoupis, Robin Verschueren,
 * Andrea Zanelli, Niels van Duijkeren, Jonathan Frey, Tommaso Sartor,
 * Branimir Novoselnik, Rien Quirynen, Rezart Qelibari, Dang Doan,
 * Jonas Koenemann, Yutao Chen, Tobias Schöls, Jonas Schlagenhauf, Moritz Diehl
 *
 * This file is part of acados.
 *
 * The 2-Clause BSD License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.;
 */


// standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// acados
#include "acados/utils/print.h"
#include "acados_c/ocp_nlp_interface.h"
#include "acados_solver_dt_model.h"

// mex
#include "mex.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    long long *l_ptr;
    int status = 0;

    // create solver
    dt_model_solver_capsule *acados_ocp_capsule = dt_model_acados_create_capsule();

    status = dt_model_acados_create(acados_ocp_capsule);

    if (status)
    {
        mexPrintf("dt_model_acados_create() returned status %d.\n", status);
    }
    mexPrintf("dt_model_acados_create() -> success!\n");

    // get pointers to nlp solver related objects
    ocp_nlp_plan *nlp_plan = dt_model_acados_get_nlp_plan(acados_ocp_capsule);
    ocp_nlp_config *nlp_config = dt_model_acados_get_nlp_config(acados_ocp_capsule);
    ocp_nlp_dims *nlp_dims = dt_model_acados_get_nlp_dims(acados_ocp_capsule);
    ocp_nlp_in *nlp_in = dt_model_acados_get_nlp_in(acados_ocp_capsule);
    ocp_nlp_out *nlp_out = dt_model_acados_get_nlp_out(acados_ocp_capsule);
    ocp_nlp_solver *nlp_solver = dt_model_acados_get_nlp_solver(acados_ocp_capsule);
    void *nlp_opts = dt_model_acados_get_nlp_opts(acados_ocp_capsule);

    // mexPrintf("acados: got pointer to objectes!\n");

    // field names of output struct
    #define FIELDS_OCP 9
    #define FIELDS_EXT_FUN 25
    #define MAX_FIELDS 25
    char *fieldnames[MAX_FIELDS];

    for (int i = 0; i < MAX_FIELDS; i++)
    {
        fieldnames[i] = (char*) mxMalloc(50);
    }

    memcpy(fieldnames[0],"config",sizeof("config"));
    memcpy(fieldnames[1],"dims",sizeof("dims"));
    memcpy(fieldnames[2],"opts",sizeof("opts"));
    memcpy(fieldnames[3],"in",sizeof("in"));
    memcpy(fieldnames[4],"out",sizeof("out"));
    memcpy(fieldnames[5],"solver",sizeof("solver"));
    memcpy(fieldnames[6],"sens_out",sizeof("sens_out"));
    memcpy(fieldnames[7],"plan",sizeof("plan"));
    memcpy(fieldnames[8],"capsule",sizeof("capsule"));

    // create output struct - C_ocp
    plhs[0] = mxCreateStructMatrix(1, 1, 9, (const char **) fieldnames);

    // MEX: config, dims, opts, in, out, solver, sens_out, plan
    // plan
    mxArray *plan_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(plan_mat);
    l_ptr[0] = (long long) nlp_plan;
    mxSetField(plhs[0], 0, "plan", plan_mat);

    // config
    mxArray *config_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(config_mat);
    l_ptr[0] = (long long) nlp_config;
    mxSetField(plhs[0], 0, "config", config_mat);

    // dims
    mxArray *dims_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(dims_mat);
    l_ptr[0] = (long long) nlp_dims;
    mxSetField(plhs[0], 0, "dims", dims_mat);

    // opts
    mxArray *opts_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(opts_mat);
    l_ptr[0] = (long long) nlp_opts;
    mxSetField(plhs[0], 0, "opts", opts_mat);

    // in
    mxArray *in_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(in_mat);
    l_ptr[0] = (long long) nlp_in;
    mxSetField(plhs[0], 0, "in", in_mat);

    // out
    mxArray *out_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(out_mat);
    l_ptr[0] = (long long) nlp_out;
    mxSetField(plhs[0], 0, "out", out_mat);

    // solver
    mxArray *solver_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(solver_mat);
    l_ptr[0] = (long long) nlp_solver;
    mxSetField(plhs[0], 0, "solver", solver_mat);

    // TODO: sens_out not actually implemented in templates..
    // sens_out
    mxArray *sens_out_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(sens_out_mat);
    l_ptr[0] = (long long) 1;
    mxSetField(plhs[0], 0, "sens_out", sens_out_mat);

    // capsule
    mxArray *capsule_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(capsule_mat);
    l_ptr[0] = (long long) acados_ocp_capsule;
    mxSetField(plhs[0], 0, "capsule", capsule_mat);

    /* store external function pointers */
    // dyn
    memcpy(fieldnames[0],"expl_ode_fun",sizeof("expl_ode_fun"));
    memcpy(fieldnames[1],"forw_vde",sizeof("forw_vde"));
    memcpy(fieldnames[2],"hess_vde",sizeof("hess_vde"));
    memcpy(fieldnames[3],"impl_dae_fun",sizeof("impl_dae_fun"));
    memcpy(fieldnames[4],"impl_dae_fun_jac_x_xdot_z",sizeof("impl_dae_fun_jac_x_xdot_z"));
    memcpy(fieldnames[5],"impl_dae_jac_x_xdot_u_z",sizeof("impl_dae_jac_x_xdot_u_z"));
    memcpy(fieldnames[6],"impl_dae_hess",sizeof("impl_dae_hess"));

    memcpy(fieldnames[7],"gnsf_phi_fun",sizeof("gnsf_phi_fun"));
    memcpy(fieldnames[8],"gnsf_phi_fun_jac_y",sizeof("gnsf_phi_fun_jac_y"));
    memcpy(fieldnames[9],"gnsf_phi_jac_y_uhat",sizeof("gnsf_phi_jac_y_uhat"));
    memcpy(fieldnames[10],"gnsf_f_lo_jac_x1_x1dot_u_z",sizeof("gnsf_f_lo_jac_x1_x1dot_u_z"));
    memcpy(fieldnames[11],"gnsf_get_matrices_fun",sizeof("gnsf_get_matrices_fun"));

    memcpy(fieldnames[12],"disc_phi_fun",sizeof("disc_phi_fun"));
    memcpy(fieldnames[13],"disc_phi_fun_jac",sizeof("disc_phi_fun_jac"));
    memcpy(fieldnames[14],"disc_phi_fun_jac_hess",sizeof("disc_phi_fun_jac_hess"));
    
    // cost
    memcpy(fieldnames[15],"cost_y_fun",sizeof("cost_y_fun"));
    memcpy(fieldnames[16],"cost_y_fun_jac_ut_xt",sizeof("cost_y_fun_jac_ut_xt"));
    memcpy(fieldnames[17],"cost_y_hess",sizeof("cost_y_hess"));
    memcpy(fieldnames[18],"ext_cost_fun",sizeof("ext_cost_fun"));
    memcpy(fieldnames[19],"ext_cost_fun_jac",sizeof("ext_cost_fun_jac"));
    memcpy(fieldnames[20],"ext_cost_fun_jac_hess",sizeof("ext_cost_fun_jac_hess"));

    // constraints
    memcpy(fieldnames[21],"phi_constraint",sizeof("phi_constraint"));
    memcpy(fieldnames[22],"nl_constr_h_fun_jac",sizeof("nl_constr_h_fun_jac"));
    memcpy(fieldnames[23],"nl_constr_h_fun",sizeof("nl_constr_h_fun"));
    memcpy(fieldnames[24],"nl_constr_h_fun_jac_hess",sizeof("nl_constr_h_fun_jac_hess"));


    // create output struct - C_ocp_ext_fun
    plhs[1] = mxCreateStructMatrix(1, 1, FIELDS_EXT_FUN, (const char **) fieldnames);


    for (int i = 0; i < FIELDS_EXT_FUN; i++)
    {
        mxFree( fieldnames[i] );
    }

/* dynamics */
    mxArray *expl_ode_fun_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *forw_vde_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *hess_vde_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *impl_dae_fun_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *impl_dae_fun_jac_x_xdot_z_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *impl_dae_jac_x_xdot_u_z_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *impl_dae_hess_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);

    mxArray *gnsf_phi_fun_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *gnsf_phi_fun_jac_y_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *gnsf_phi_jac_y_uhat_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *gnsf_f_lo_jac_x1_x1dot_u_z_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *gnsf_get_matrices_fun_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);

    mxArray *disc_phi_fun_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *disc_phi_fun_jac_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    mxArray *disc_phi_fun_jac_hess_mat = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);


    l_ptr = mxGetData(disc_phi_fun_mat);
    l_ptr[0] = (long long) acados_ocp_capsule->discr_dyn_phi_fun;
    l_ptr = mxGetData(disc_phi_fun_jac_mat);
    l_ptr[0] = (long long) acados_ocp_capsule->discr_dyn_phi_fun_jac_ut_xt;

    mxSetField(plhs[1], 0, "expl_ode_fun", expl_ode_fun_mat);
    mxSetField(plhs[1], 0, "forw_vde", forw_vde_mat);
    mxSetField(plhs[1], 0, "hess_vde", hess_vde_mat);

    mxSetField(plhs[1], 0, "gnsf_phi_fun", gnsf_phi_fun_mat);
    mxSetField(plhs[1], 0, "gnsf_phi_fun_jac_y", gnsf_phi_fun_jac_y_mat);
    mxSetField(plhs[1], 0, "gnsf_phi_jac_y_uhat", gnsf_phi_jac_y_uhat_mat);
    mxSetField(plhs[1], 0, "gnsf_f_lo_jac_x1_x1dot_u_z", gnsf_f_lo_jac_x1_x1dot_u_z_mat);
    mxSetField(plhs[1], 0, "gnsf_get_matrices_fun", gnsf_get_matrices_fun_mat);

    mxSetField(plhs[1], 0, "impl_dae_fun", impl_dae_fun_mat);
    mxSetField(plhs[1], 0, "impl_dae_fun_jac_x_xdot_z", impl_dae_fun_jac_x_xdot_z_mat);
    mxSetField(plhs[1], 0, "impl_dae_jac_x_xdot_u_z", impl_dae_jac_x_xdot_u_z_mat);
    mxSetField(plhs[1], 0, "impl_dae_hess", impl_dae_hess_mat);

    mxSetField(plhs[1], 0, "disc_phi_fun", disc_phi_fun_mat);
    mxSetField(plhs[1], 0, "disc_phi_fun_jac", disc_phi_fun_jac_mat);
    mxSetField(plhs[1], 0, "disc_phi_fun_jac_hess", disc_phi_fun_jac_hess_mat);
/* constaints */
    mxArray *phi_constraint_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(phi_constraint_mat);

    mxSetField(plhs[1], 0, "phi_constraint", phi_constraint_mat);

    mxArray *nl_constr_h_fun_jac_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(nl_constr_h_fun_jac_mat);


    mxSetField(plhs[1], 0, "nl_constr_h_fun_jac", nl_constr_h_fun_jac_mat);

    mxArray *nl_constr_h_fun_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(nl_constr_h_fun_mat);


    mxSetField(plhs[1], 0, "nl_constr_h_fun", nl_constr_h_fun_mat);

    mxArray *nl_constr_h_fun_jac_hess_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(nl_constr_h_fun_jac_hess_mat);


    mxSetField(plhs[1], 0, "nl_constr_h_fun_jac_hess", nl_constr_h_fun_jac_hess_mat);

/* cost */
    mxArray *cost_y_fun_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(cost_y_fun_mat);


    mxSetField(plhs[1], 0, "cost_y_fun", cost_y_fun_mat);

    mxArray *cost_y_fun_jac_ut_xt_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(cost_y_fun_jac_ut_xt_mat);


    mxSetField(plhs[1], 0, "cost_y_fun_jac_ut_xt", cost_y_fun_jac_ut_xt_mat);

    mxArray *cost_y_hess_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(cost_y_hess_mat);


    mxSetField(plhs[1], 0, "cost_y_hess", cost_y_hess_mat);

    mxArray *ext_cost_fun_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(ext_cost_fun_mat);

    mxSetField(plhs[1], 0, "ext_cost_fun", ext_cost_fun_mat);

    mxArray *ext_cost_fun_jac_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(ext_cost_fun_jac_mat);

    mxSetField(plhs[1], 0, "ext_cost_fun_jac", ext_cost_fun_jac_mat);

    mxArray *ext_cost_fun_jac_hess_mat = mxCreateNumericMatrix(1, 2, mxINT64_CLASS, mxREAL);
    l_ptr = mxGetData(ext_cost_fun_jac_hess_mat);

    mxSetField(plhs[1], 0, "ext_cost_fun_jac_hess", ext_cost_fun_jac_hess_mat);


    return;
}