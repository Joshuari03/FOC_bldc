/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: spwm.c
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

#include "spwm.h"
#include "spwm_private.h"
#include <math.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Block states (default storage) */
DW_spwm_T spwm_DW;

/* Real-time model */
static RT_MODEL_spwm_T spwm_M_;
RT_MODEL_spwm_T *const spwm_M = &spwm_M_;
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
  real_T rtb_uDLookupTable;

  /* Lookup_n-D: '<S2>/1-D Lookup Table' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant3'
   *  DigitalClock: '<S2>/Digital Clock'
   *  Gain: '<S2>/1\ib1'
   *  Math: '<S2>/Math Function'
   *  Sum: '<S2>/Add1'
   */
  rtb_uDLookupTable = look1_pbinlxpw(rt_remd_snf(((spwm_M->Timing.clockTick0) *
    0.001) + 0.005, 0.02) * 50.0, spwm_ConstP.uDLookupTable_bp01Data,
    spwm_ConstP.uDLookupTable_tableData, &spwm_DW.m_bpIndex, 2UL);

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<S2>/Constant2'
   *  RelationalOperator: '<Root>/GreaterThan'
   *  Sin: '<Root>/Sine Wave'
   *  Sum: '<S2>/Add3'
   */
  writeDigitalPin(9, (uint8_T)(sin((real_T)spwm_DW.counter * 2.0 *
    3.1415926535897931 / 1000.0) > rtb_uDLookupTable - 1.0));

  /* Update for Sin: '<Root>/Sine Wave' */
  spwm_DW.counter++;
  if (spwm_DW.counter == 1000L) {
    spwm_DW.counter = 0L;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  spwm_M->Timing.clockTick0++;
}

/* Model initialize function */
void spwm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  spwm_DW.obj.matlabCodegenIsDeleted = false;
  spwm_DW.obj.isInitialized = 1L;
  digitalIOSetup(9, 1);
  spwm_DW.obj.isSetupComplete = true;
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
