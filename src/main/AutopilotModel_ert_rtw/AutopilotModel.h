/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AutopilotModel.h
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

#ifndef RTW_HEADER_AutopilotModel_h_
#define RTW_HEADER_AutopilotModel_h_
#include <string.h>
#ifndef AutopilotModel_COMMON_INCLUDES_
# define AutopilotModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* AutopilotModel_COMMON_INCLUDES_ */

#include "AutopilotModel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T AltitudeDiscreteController; /* '<Root>/Altitude Discrete Controller' */
  real_T Subtract1;                    /* '<Root>/Subtract1' */
  real_T DerivativeGain;               /* '<S29>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S38>/Filter Coefficient' */
  real_T ProportionalGain;             /* '<S40>/Proportional Gain' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T IntegralGain;                 /* '<S32>/Integral Gain' */
} B_AutopilotModel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T AltitudeDiscreteController_DSTA[2];
                                     /* '<Root>/Altitude Discrete Controller' */
  real_T UD_DSTATE;                    /* '<S2>/UD' */
} DW_AutopilotModel_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Plant_CSTATE[2];              /* '<Root>/Plant' */
  real_T Filter_CSTATE;                /* '<S30>/Filter' */
  real_T Integrator_CSTATE;            /* '<S35>/Integrator' */
} X_AutopilotModel_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Plant_CSTATE[2];              /* '<Root>/Plant' */
  real_T Filter_CSTATE;                /* '<S30>/Filter' */
  real_T Integrator_CSTATE;            /* '<S35>/Integrator' */
} XDot_AutopilotModel_T;

/* State disabled  */
typedef struct {
  boolean_T Plant_CSTATE[2];           /* '<Root>/Plant' */
  boolean_T Filter_CSTATE;             /* '<S30>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S35>/Integrator' */
} XDis_AutopilotModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T altCmd;                       /* '<Root>/altCmd' */
  real_T theta;                        /* '<Root>/theta' */
} ExtU_AutopilotModel_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T altError;                     /* '<Root>/altError' */
  real_T elevCmd;                      /* '<Root>/elevCmd' */
} ExtY_AutopilotModel_T;

/* Real-time Model Data Structure */
struct tag_RTM_AutopilotModel_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_AutopilotModel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_AutopilotModel_T AutopilotModel_B;

/* Continuous states (default storage) */
extern X_AutopilotModel_T AutopilotModel_X;

/* Block states (default storage) */
extern DW_AutopilotModel_T AutopilotModel_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_AutopilotModel_T AutopilotModel_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_AutopilotModel_T AutopilotModel_Y;

/* Model entry point functions */
extern void AutopilotModel_initialize(void);
extern void AutopilotModel_step(void);
extern void AutopilotModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AutopilotModel_T *const AutopilotModel_M;

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
 * '<Root>' : 'AutopilotModel'
 * '<S1>'   : 'AutopilotModel/Degrees to Radians'
 * '<S2>'   : 'AutopilotModel/Difference Filter'
 * '<S3>'   : 'AutopilotModel/PID Controller'
 * '<S4>'   : 'AutopilotModel/PID Controller/Anti-windup'
 * '<S5>'   : 'AutopilotModel/PID Controller/D Gain'
 * '<S6>'   : 'AutopilotModel/PID Controller/Filter'
 * '<S7>'   : 'AutopilotModel/PID Controller/Filter ICs'
 * '<S8>'   : 'AutopilotModel/PID Controller/I Gain'
 * '<S9>'   : 'AutopilotModel/PID Controller/Ideal P Gain'
 * '<S10>'  : 'AutopilotModel/PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'AutopilotModel/PID Controller/Integrator'
 * '<S12>'  : 'AutopilotModel/PID Controller/Integrator ICs'
 * '<S13>'  : 'AutopilotModel/PID Controller/N Copy'
 * '<S14>'  : 'AutopilotModel/PID Controller/N Gain'
 * '<S15>'  : 'AutopilotModel/PID Controller/P Copy'
 * '<S16>'  : 'AutopilotModel/PID Controller/Parallel P Gain'
 * '<S17>'  : 'AutopilotModel/PID Controller/Reset Signal'
 * '<S18>'  : 'AutopilotModel/PID Controller/Saturation'
 * '<S19>'  : 'AutopilotModel/PID Controller/Saturation Fdbk'
 * '<S20>'  : 'AutopilotModel/PID Controller/Sum'
 * '<S21>'  : 'AutopilotModel/PID Controller/Sum Fdbk'
 * '<S22>'  : 'AutopilotModel/PID Controller/Tracking Mode'
 * '<S23>'  : 'AutopilotModel/PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'AutopilotModel/PID Controller/Tsamp - Integral'
 * '<S25>'  : 'AutopilotModel/PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'AutopilotModel/PID Controller/postSat Signal'
 * '<S27>'  : 'AutopilotModel/PID Controller/preSat Signal'
 * '<S28>'  : 'AutopilotModel/PID Controller/Anti-windup/Passthrough'
 * '<S29>'  : 'AutopilotModel/PID Controller/D Gain/Internal Parameters'
 * '<S30>'  : 'AutopilotModel/PID Controller/Filter/Cont. Filter'
 * '<S31>'  : 'AutopilotModel/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S32>'  : 'AutopilotModel/PID Controller/I Gain/Internal Parameters'
 * '<S33>'  : 'AutopilotModel/PID Controller/Ideal P Gain/Passthrough'
 * '<S34>'  : 'AutopilotModel/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S35>'  : 'AutopilotModel/PID Controller/Integrator/Continuous'
 * '<S36>'  : 'AutopilotModel/PID Controller/Integrator ICs/Internal IC'
 * '<S37>'  : 'AutopilotModel/PID Controller/N Copy/Disabled'
 * '<S38>'  : 'AutopilotModel/PID Controller/N Gain/Internal Parameters'
 * '<S39>'  : 'AutopilotModel/PID Controller/P Copy/Disabled'
 * '<S40>'  : 'AutopilotModel/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S41>'  : 'AutopilotModel/PID Controller/Reset Signal/Disabled'
 * '<S42>'  : 'AutopilotModel/PID Controller/Saturation/Passthrough'
 * '<S43>'  : 'AutopilotModel/PID Controller/Saturation Fdbk/Disabled'
 * '<S44>'  : 'AutopilotModel/PID Controller/Sum/Sum_PID'
 * '<S45>'  : 'AutopilotModel/PID Controller/Sum Fdbk/Disabled'
 * '<S46>'  : 'AutopilotModel/PID Controller/Tracking Mode/Disabled'
 * '<S47>'  : 'AutopilotModel/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S48>'  : 'AutopilotModel/PID Controller/Tsamp - Integral/Passthrough'
 * '<S49>'  : 'AutopilotModel/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S50>'  : 'AutopilotModel/PID Controller/postSat Signal/Forward_Path'
 * '<S51>'  : 'AutopilotModel/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_AutopilotModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
