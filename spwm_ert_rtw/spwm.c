/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * File: spwm.c
 *
 * Code generated for Simulink model 'spwm'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Sep 17 22:21:52 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "spwm.h"
#include <math.h>
#include "spwm_private.h"
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
static void rate_scheduler(void);
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
  if (u0 <= bp0[0UL]) {
    bpIdx = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0UL];
    iLeft = 0UL;
    iRght = maxIndex;
    found = 0UL;
    while (found == 0UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1UL;
        bpIdx = ((bpIdx + iLeft) - 1UL) >> 1UL;
      } else if (u0 < bp0[bpIdx + 1UL]) {
        found = 1UL;
      } else {
        iLeft = bpIdx + 1UL;
        bpIdx = ((bpIdx + iRght) + 1UL) >> 1UL;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1UL] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  prevIndex[0UL] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (table[bpIdx + 1UL] - yL_0d0) * frac + yL_0d0;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
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

/* Model step function */
void spwm_step(void)
{
  {
    real_T rtb_uDLookupTable;

    /* Sin: '<Root>/Sine Wave' */
    if (spwm_DW.systemEnable != 0L) {
      rtb_uDLookupTable = ((spwm_M->Timing.clockTick1) * 0.001);
      spwm_DW.lastSin = sin(10.0 * rtb_uDLookupTable);
      spwm_DW.lastCos = cos(10.0 * rtb_uDLookupTable);
      spwm_DW.systemEnable = 0L;
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
      spwm_ConstP.uDLookupTable_tableData, &spwm_DW.m_bpIndex, 2UL);

    /* RelationalOperator: '<Root>/GreaterThan' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Sin: '<Root>/Sine Wave'
     *  Sum: '<S2>/Add3'
     */
    spwm_B.GreaterThan = ((spwm_DW.lastSin * 0.99995000041666526 +
      spwm_DW.lastCos * -0.0099998333341666645) * 0.99995000041666526 +
                          (spwm_DW.lastCos * 0.99995000041666526 -
      spwm_DW.lastSin * -0.0099998333341666645) * 0.0099998333341666645 >
                          rtb_uDLookupTable - 1.0);

    /* MATLABSystem: '<Root>/Digital Output' */
    writeDigitalPin(9, (uint8_T)spwm_B.GreaterThan);
  }

  {
    real_T HoldSine;

    /* Update for Sin: '<Root>/Sine Wave' */
    HoldSine = spwm_DW.lastSin;
    spwm_DW.lastSin = spwm_DW.lastSin * 0.99995000041666526 + spwm_DW.lastCos *
      0.0099998333341666645;
    spwm_DW.lastCos = spwm_DW.lastCos * 0.99995000041666526 - HoldSine *
      0.0099998333341666645;
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((spwm_M->Timing.clockTick1 * 1) + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (spwm_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.01s, 0.005s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((spwm_M->Timing.clockTick2 * 10) + 5);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(2, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  spwm_M->Timing.t[0] =
    ((time_T)(++spwm_M->Timing.clockTick0)) * spwm_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    spwm_M->Timing.clockTick1++;
  }

  if (spwm_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.005s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    spwm_M->Timing.clockTick2++;
  }

  rate_scheduler();
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
  rtmSetTFinal(spwm_M, 2.0);
  spwm_M->Timing.stepSize0 = 0.001;

  /* initialize sample time offsets */
  spwm_M->Timing.TaskCounters.TID[2] = 5;/* Sample time: [0.01s, 0.005s] */

  /* External mode info */
  spwm_M->Sizes.checksums[0] = (1891699297U);
  spwm_M->Sizes.checksums[1] = (3220477630U);
  spwm_M->Sizes.checksums[2] = (4168827423U);
  spwm_M->Sizes.checksums[3] = (1327258857U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    spwm_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(spwm_M->extModeInfo,
      &spwm_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(spwm_M->extModeInfo, spwm_M->Sizes.checksums);
    rteiSetTFinalTicks(spwm_M->extModeInfo, 2000);
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  spwm_DW.obj.matlabCodegenIsDeleted = false;
  spwm_DW.obj.isInitialized = 1L;
  digitalIOSetup(9, 1);
  spwm_DW.obj.isSetupComplete = true;

  /* Enable for Sin: '<Root>/Sine Wave' */
  spwm_DW.systemEnable = 1L;
}

/* Model terminate function */
void spwm_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!spwm_DW.obj.matlabCodegenIsDeleted) {
    spwm_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
