/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScaleandOffset.c
 *
 * Code generated for Simulink model 'ScaleandOffset'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jun 12 19:43:18 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ScaleandOffset.h"
#include "ScaleandOffset_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_ScaleandOffset_T ScaleandOffset_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ScaleandOffset_T ScaleandOffset_Y;

/* Real-time model */
RT_MODEL_ScaleandOffset_T ScaleandOffset_M_;
RT_MODEL_ScaleandOffset_T *const ScaleandOffset_M = &ScaleandOffset_M_;

/* Model step function */
void ScaleandOffset_step(void)
{
  /* Sum: '<S2>/Add' incorporates:
   *  Inport: '<Root>/Offset'
   *  Inport: '<Root>/Scaling'
   *  Inport: '<Root>/coolantTemp'
   *  Product: '<S2>/Product'
   */
  ScaleandOffset_Y.Temperature = (int16_T)(ScaleandOffset_U.coolantTemp *
    ScaleandOffset_U.Scaling - ScaleandOffset_U.Offset);

  /* RelationalOperator: '<S1>/Relational Operator' incorporates:
   *  Constant: '<S1>/MaxTemp'
   */
  ScaleandOffset_Y.Error = (ScaleandOffset_Y.Temperature > 210);

  /* Switch: '<S1>/Switch' */
  if (ScaleandOffset_Y.Error) {
    /* Outport: '<Root>/Temperature' incorporates:
     *  Constant: '<S1>/DefaultTemp'
     */
    ScaleandOffset_Y.Temperature = 20;
  }

  /* End of Switch: '<S1>/Switch' */
}

/* Model initialize function */
void ScaleandOffset_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void ScaleandOffset_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
