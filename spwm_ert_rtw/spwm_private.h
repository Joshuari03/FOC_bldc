/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: spwm_private.h
 *
 * Code generated for Simulink model 'spwm'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Sep 18 22:36:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef spwm_private_h_
#define spwm_private_h_
#include "rtwtypes.h"
#include "spwm_types.h"
#include "spwm.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T look1_pbinlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T prevIndex[], uint32_T maxIndex);

#endif                                 /* spwm_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
