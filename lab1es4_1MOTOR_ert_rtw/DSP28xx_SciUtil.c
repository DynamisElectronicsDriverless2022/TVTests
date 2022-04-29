/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DSP28xx_SciUtil.c
 *
 * Code generated for Simulink model 'lab1es4_1MOTOR'.
 *
 * Model version                  : 3.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 29 15:23:08 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DSP28xx_SciUtil.h"

/* Transmit character(s) from the SCIa*/
void scia_xmit(char* pmsg, int msglen, int typeLen)
{
  int i,j;
  if (typeLen==1) {
    for (i = 0; i < msglen; i++) {
      while (SciaRegs.SCIFFTX.bit.TXFFST == 4) {
      }                                /* The buffer is full;*/

      SciaRegs.SCITXBUF= pmsg[i];
    }

    //while(SciaRegs.SCIFFTX.bit.TXFFST != 0){}
  } else {
    for (i = 0; i < (msglen/2); i++) {
      for (j = 0; j<=1; j++) {
        while (SciaRegs.SCIFFTX.bit.TXFFST == 4) {
        }                              /* The buffer is full;*/

        SciaRegs.SCITXBUF= pmsg[i]>>(8*j);
      }
    }

    //while(SciaRegs.SCIFFTX.bit.TXFFST != 0){}
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
