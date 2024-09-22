/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: spwm.c
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

#include "spwm.h"
#include "spwm_private.h"
#include <math.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Block signals (default storage) */
B_spwm_T spwm_B;

/* Block states (default storage) */
DW_spwm_T spwm_DW;

/* Real-time model */
static RT_MODEL_spwm_T spwm_M_;
RT_MODEL_spwm_T *const spwm_M = &spwm_M_;
static void rate_monotonic_scheduler(void);
real_T look1_pbinlxpw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T prevIndex[], uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (table[bpIdx + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void spwm_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(spwm_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   *
   * Sample time offsets are handled by priming the counter with the
   * appropriate non-zero value in the model initialize function.
   */
  (spwm_M->Timing.TaskCounters.TID[2])++;
  if ((spwm_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.005s] */
    spwm_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model step function for TID0 */
void spwm_step0(void)                  /* Sample time: [0.0s, 0.0s] */
{
  real_T rtb_uDLookupTable;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Lookup_n-D: '<S2>/1-D Lookup Table' incorporates:
   *  Clock: '<S2>/Clock'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Gain: '<S2>/1\ib1'
   *  Math: '<S2>/Math Function'
   *  Sum: '<S2>/Add1'
   */
  rtb_uDLookupTable = look1_pbinlxpw(rt_remd_snf(spwm_M->Timing.t[0] + 0.005,
    0.02) * 50.0, spwm_ConstP.uDLookupTable_bp01Data,
    spwm_ConstP.uDLookupTable_tableData, &spwm_DW.m_bpIndex, 2U);

  /* RelationalOperator: '<Root>/GreaterThan' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Sin: '<Root>/Sine Wave'
   *  Sum: '<S2>/Add3'
   */
  spwm_B.pin9 = (sin(spwm_M->Timing.t[0]) > rtb_uDLookupTable - 1.0);

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(32, (uint8_T)spwm_B.pin9);

  /* Logic: '<Root>/NOT' */
  spwm_B.pin10 = !spwm_B.pin9;

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(2, (uint8_T)spwm_B.pin10);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  spwm_M->Timing.t[0] =
    ((time_T)(++spwm_M->Timing.clockTick0)) * spwm_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  spwm_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void spwm_step2(void)                  /* Sample time: [0.01s, 0.005s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  spwm_M->Timing.clockTick2++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void spwm_step(int_T tid)
{
  switch (tid) {
   case 0 :
    spwm_step0();
    break;

   case 2 :
    spwm_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void spwm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&spwm_M->solverInfo, &spwm_M->Timing.simTimeStep);
    rtsiSetTPtr(&spwm_M->solverInfo, &rtmGetTPtr(spwm_M));
    rtsiSetStepSizePtr(&spwm_M->solverInfo, &spwm_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&spwm_M->solverInfo, (&rtmGetErrorStatus(spwm_M)));
    rtsiSetRTModelPtr(&spwm_M->solverInfo, spwm_M);
  }

  rtsiSetSimTimeStep(&spwm_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&spwm_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&spwm_M->solverInfo, false);
  rtsiSetSolverName(&spwm_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(spwm_M, &spwm_M->Timing.tArray[0]);
  rtmSetTFinal(spwm_M, -1);
  spwm_M->Timing.stepSize0 = 0.001;

  /* initialize sample time offsets */
  spwm_M->Timing.TaskCounters.TID[2] = 5;/* Sample time: [0.01s, 0.005s] */

  /* External mode info */
  spwm_M->Sizes.checksums[0] = (1582874665U);
  spwm_M->Sizes.checksums[1] = (2450610310U);
  spwm_M->Sizes.checksums[2] = (692344644U);
  spwm_M->Sizes.checksums[3] = (1485622711U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    spwm_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(spwm_M->extModeInfo,
      &spwm_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(spwm_M->extModeInfo, spwm_M->Sizes.checksums);
    rteiSetTPtr(spwm_M->extModeInfo, rtmGetTPtr(spwm_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  spwm_DW.obj_h.matlabCodegenIsDeleted = false;
  spwm_DW.obj_h.isInitialized = 1;
  digitalIOSetup(32, 1);
  spwm_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  spwm_DW.obj.matlabCodegenIsDeleted = false;
  spwm_DW.obj.isInitialized = 1;
  digitalIOSetup(2, 1);
  spwm_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void spwm_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!spwm_DW.obj_h.matlabCodegenIsDeleted) {
    spwm_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!spwm_DW.obj.matlabCodegenIsDeleted) {
    spwm_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
