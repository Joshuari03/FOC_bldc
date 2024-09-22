/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: spwm.h
 *
 * Code generated for Simulink model 'spwm'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Sep 22 12:27:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef spwm_h_
#define spwm_h_
#ifndef spwm_COMMON_INCLUDES_
#define spwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* spwm_COMMON_INCLUDES_ */

#include "spwm_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T pin9;                      /* '<Root>/GreaterThan' */
  boolean_T pin10;                     /* '<Root>/NOT' */
} B_spwm_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output' */
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
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block signals (default storage) */
extern B_spwm_T spwm_B;

/* Block states (default storage) */
extern DW_spwm_T spwm_DW;

/* Constant parameters (default storage) */
extern const ConstP_spwm_T spwm_ConstP;

/* External function called from main */
extern void spwm_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void spwm_initialize(void);
extern void spwm_step0(void);          /* Sample time: [0.0s, 0.0s] */
extern void spwm_step2(void);          /* Sample time: [0.01s, 0.005s] */
extern void spwm_step(int_T tid);
extern void spwm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_spwm_T *const spwm_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Unit Delay' : Unused code path elimination
 */

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
