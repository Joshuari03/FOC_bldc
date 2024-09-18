/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: spwm_types.h
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

#ifndef spwm_types_h_
#define spwm_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_bpMNyLZPCJBeBnOB7xlwFB
#define struct_tag_bpMNyLZPCJBeBnOB7xlwFB

struct tag_bpMNyLZPCJBeBnOB7xlwFB
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_bpMNyLZPCJBeBnOB7xlwFB */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_bpMNyLZPCJBeBnOB7xlwFB b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_ldqgYDWP5Rq6U8J4ptL7cG
#define struct_tag_ldqgYDWP5Rq6U8J4ptL7cG

struct tag_ldqgYDWP5Rq6U8J4ptL7cG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_ldqgYDWP5Rq6U8J4ptL7cG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_ldqgYDWP5Rq6U8J4ptL7cG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_spwm_T RT_MODEL_spwm_T;

#endif                                 /* spwm_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
