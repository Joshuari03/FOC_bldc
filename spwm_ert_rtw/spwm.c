/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * File: spwm.c
 *
 * Code generated for Simulink model 'spwm'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat Sep 14 01:07:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "spwm.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_spwm_T spwm_DW;

/* Real-time model */
static RT_MODEL_spwm_T spwm_M_;
RT_MODEL_spwm_T *const spwm_M = &spwm_M_;

/* Model step function */
void spwm_step(void)
{
  int16_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = ((spwm_DW.clockTickCounter < 500L) &&
                        (spwm_DW.clockTickCounter >= 0L));
  if (spwm_DW.clockTickCounter >= 999L) {
    spwm_DW.clockTickCounter = 0L;
  } else {
    spwm_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(9, (uint8_T)rtb_PulseGenerator);
}

/* Model initialize function */
void spwm_initialize(void)
{
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
