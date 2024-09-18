/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: spwm.h
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

#ifndef spwm_h_
#define spwm_h_
#ifndef spwm_COMMON_INCLUDES_
#define spwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* spwm_COMMON_INCLUDES_ */

#include "spwm_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output' */
  int32_T counter;                     /* '<Root>/Sine Wave' */
  uint32_T m_bpIndex;                  /* '<S2>/1-D Lookup Table' */
} DW_spwm_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 2 0]
   * Referenced by: '<S2>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[3];

  /* Expression: [0 .5 1]
   * Referenced by: '<S2>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[3];
} ConstP_spwm_T;

/* Real-time Model Data Structure */
struct tag_RTM_spwm_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block states (default storage) */
extern DW_spwm_T spwm_DW;

/* Constant parameters (default storage) */
extern const ConstP_spwm_T spwm_ConstP;

/* Model entry point functions */
extern void spwm_initialize(void);
extern void spwm_step(void);
extern void spwm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_spwm_T *const spwm_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'spwm'
 * '<S1>'   : 'spwm/Triangle Generator'
 * '<S2>'   : 'spwm/Triangle Generator/Model'
 */
#endif                                 /* spwm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
