/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AutopilotModel.c
 *
 * Code generated for Simulink model 'AutopilotModel'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jun 12 17:15:24 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AutopilotModel.h"
#include "AutopilotModel_private.h"

/* Block signals (default storage) */
B_AutopilotModel_T AutopilotModel_B;

/* Continuous states */
X_AutopilotModel_T AutopilotModel_X;

/* Block states (default storage) */
DW_AutopilotModel_T AutopilotModel_DW;

/* External inputs (root inport signals with default storage) */
ExtU_AutopilotModel_T AutopilotModel_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_AutopilotModel_T AutopilotModel_Y;

/* Real-time model */
RT_MODEL_AutopilotModel_T AutopilotModel_M_;
RT_MODEL_AutopilotModel_T *const AutopilotModel_M = &AutopilotModel_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  AutopilotModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  AutopilotModel_step();
  AutopilotModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  AutopilotModel_step();
  AutopilotModel_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void AutopilotModel_step(void)
{
  real_T rtb_Diff;
  if (rtmIsMajorTimeStep(AutopilotModel_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&AutopilotModel_M->solverInfo,
                          ((AutopilotModel_M->Timing.clockTick0+1)*
      AutopilotModel_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(AutopilotModel_M)) {
    AutopilotModel_M->Timing.t[0] = rtsiGetT(&AutopilotModel_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Plant' */
  AutopilotModel_Y.elevCmd = 0.0 * AutopilotModel_X.Plant_CSTATE[0] + -400000.0 *
    AutopilotModel_X.Plant_CSTATE[1];

  /* Sum: '<Root>/Subtract' incorporates:
   *  Inport: '<Root>/altCmd'
   */
  AutopilotModel_B.Subtract = AutopilotModel_U.altCmd - AutopilotModel_Y.elevCmd;

  /* Outport: '<Root>/altError' */
  AutopilotModel_Y.altError = AutopilotModel_B.Subtract;
  if (rtmIsMajorTimeStep(AutopilotModel_M)) {
    /* DiscreteZeroPole: '<Root>/Altitude Discrete Controller' */
    {
      AutopilotModel_B.AltitudeDiscreteController = (-0.0018202327040000006)*
        AutopilotModel_DW.AltitudeDiscreteController_DSTA[0]
        + (0.0018978263120453566)*
        AutopilotModel_DW.AltitudeDiscreteController_DSTA[1];
      AutopilotModel_B.AltitudeDiscreteController += 0.033728*
        AutopilotModel_B.Subtract;
    }
  }

  /* Sum: '<Root>/Subtract1' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Inport: '<Root>/theta'
   */
  AutopilotModel_B.Subtract1 = AutopilotModel_B.AltitudeDiscreteController -
    0.017453292519943295 * AutopilotModel_U.theta;
  if (rtmIsMajorTimeStep(AutopilotModel_M)) {
    /* Sum: '<S2>/Diff' incorporates:
     *  UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Diff = AutopilotModel_B.Subtract1 - AutopilotModel_DW.UD_DSTATE;

    /* Gain: '<S29>/Derivative Gain' */
    AutopilotModel_B.DerivativeGain = 2.0 * rtb_Diff;

    /* Gain: '<S40>/Proportional Gain' */
    AutopilotModel_B.ProportionalGain = -300.0 * rtb_Diff;
  }

  /* Gain: '<S38>/Filter Coefficient' incorporates:
   *  Integrator: '<S30>/Filter'
   *  Sum: '<S30>/SumD'
   */
  AutopilotModel_B.FilterCoefficient = (AutopilotModel_B.DerivativeGain -
    AutopilotModel_X.Filter_CSTATE) * 100.0;

  /* Sum: '<S44>/Sum' incorporates:
   *  Integrator: '<S35>/Integrator'
   */
  AutopilotModel_B.Saturation = (AutopilotModel_B.ProportionalGain +
    AutopilotModel_X.Integrator_CSTATE) + AutopilotModel_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (AutopilotModel_B.Saturation > 0.35) {
    /* Sum: '<S44>/Sum' */
    AutopilotModel_B.Saturation = 0.35;
  } else {
    if (AutopilotModel_B.Saturation < -0.35) {
      /* Sum: '<S44>/Sum' */
      AutopilotModel_B.Saturation = -0.35;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(AutopilotModel_M)) {
    /* Gain: '<S32>/Integral Gain' */
    AutopilotModel_B.IntegralGain = -15000.0 * rtb_Diff;
  }

  if (rtmIsMajorTimeStep(AutopilotModel_M)) {
    if (rtmIsMajorTimeStep(AutopilotModel_M)) {
      /* Update for DiscreteZeroPole: '<Root>/Altitude Discrete Controller' */
      {
        real_T xnew[2];
        xnew[0] = (1.920841)*AutopilotModel_DW.AltitudeDiscreteController_DSTA[0]
          + (-0.95960460607481457)*
          AutopilotModel_DW.AltitudeDiscreteController_DSTA[1];
        xnew[0] += 1.0*AutopilotModel_B.Subtract;
        xnew[1] = (0.95960460607481457)*
          AutopilotModel_DW.AltitudeDiscreteController_DSTA[0];
        (void) memcpy(&AutopilotModel_DW.AltitudeDiscreteController_DSTA[0],
                      xnew,
                      sizeof(real_T)*2);
      }

      /* Update for UnitDelay: '<S2>/UD'
       *
       * Block description for '<S2>/UD':
       *
       *  Store in Global RAM
       */
      AutopilotModel_DW.UD_DSTATE = AutopilotModel_B.Subtract1;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(AutopilotModel_M)) {
    rt_ertODEUpdateContinuousStates(&AutopilotModel_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++AutopilotModel_M->Timing.clockTick0;
    AutopilotModel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&AutopilotModel_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      AutopilotModel_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void AutopilotModel_derivatives(void)
{
  XDot_AutopilotModel_T *_rtXdot;
  _rtXdot = ((XDot_AutopilotModel_T *) AutopilotModel_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Plant' */
  _rtXdot->Plant_CSTATE[0] = 0.0;
  _rtXdot->Plant_CSTATE[0] += -1200.0 * AutopilotModel_X.Plant_CSTATE[0];
  _rtXdot->Plant_CSTATE[1] = 0.0;
  _rtXdot->Plant_CSTATE[0] += -2400.0 * AutopilotModel_X.Plant_CSTATE[1];
  _rtXdot->Plant_CSTATE[1] += AutopilotModel_X.Plant_CSTATE[0];
  _rtXdot->Plant_CSTATE[0] += AutopilotModel_B.Saturation;

  /* Derivatives for Integrator: '<S30>/Filter' */
  _rtXdot->Filter_CSTATE = AutopilotModel_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S35>/Integrator' */
  _rtXdot->Integrator_CSTATE = AutopilotModel_B.IntegralGain;
}

/* Model initialize function */
void AutopilotModel_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&AutopilotModel_M->solverInfo,
                          &AutopilotModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&AutopilotModel_M->solverInfo, &rtmGetTPtr(AutopilotModel_M));
    rtsiSetStepSizePtr(&AutopilotModel_M->solverInfo,
                       &AutopilotModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&AutopilotModel_M->solverInfo, &AutopilotModel_M->derivs);
    rtsiSetContStatesPtr(&AutopilotModel_M->solverInfo, (real_T **)
                         &AutopilotModel_M->contStates);
    rtsiSetNumContStatesPtr(&AutopilotModel_M->solverInfo,
      &AutopilotModel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&AutopilotModel_M->solverInfo,
      &AutopilotModel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&AutopilotModel_M->solverInfo,
      &AutopilotModel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&AutopilotModel_M->solverInfo,
      &AutopilotModel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&AutopilotModel_M->solverInfo, (&rtmGetErrorStatus
      (AutopilotModel_M)));
    rtsiSetRTModelPtr(&AutopilotModel_M->solverInfo, AutopilotModel_M);
  }

  rtsiSetSimTimeStep(&AutopilotModel_M->solverInfo, MAJOR_TIME_STEP);
  AutopilotModel_M->intgData.y = AutopilotModel_M->odeY;
  AutopilotModel_M->intgData.f[0] = AutopilotModel_M->odeF[0];
  AutopilotModel_M->intgData.f[1] = AutopilotModel_M->odeF[1];
  AutopilotModel_M->intgData.f[2] = AutopilotModel_M->odeF[2];
  AutopilotModel_M->contStates = ((X_AutopilotModel_T *) &AutopilotModel_X);
  rtsiSetSolverData(&AutopilotModel_M->solverInfo, (void *)
                    &AutopilotModel_M->intgData);
  rtsiSetSolverName(&AutopilotModel_M->solverInfo,"ode3");
  rtmSetTPtr(AutopilotModel_M, &AutopilotModel_M->Timing.tArray[0]);
  AutopilotModel_M->Timing.stepSize0 = 0.001;

  /* InitializeConditions for TransferFcn: '<Root>/Plant' */
  AutopilotModel_X.Plant_CSTATE[0] = 0.0;
  AutopilotModel_X.Plant_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S30>/Filter' */
  AutopilotModel_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S35>/Integrator' */
  AutopilotModel_X.Integrator_CSTATE = 0.0;
}

/* Model terminate function */
void AutopilotModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
