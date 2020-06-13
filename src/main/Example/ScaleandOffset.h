/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ScaleandOffset.h
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

#ifndef RTW_HEADER_ScaleandOffset_h_
#define RTW_HEADER_ScaleandOffset_h_
#ifndef ScaleandOffset_COMMON_INCLUDES_
# define ScaleandOffset_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ScaleandOffset_COMMON_INCLUDES_ */

#include "ScaleandOffset_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  int8_T coolantTemp;                  /* '<Root>/coolantTemp' */
  int8_T Scaling;                      /* '<Root>/Scaling' */
  int16_T Offset;                      /* '<Root>/Offset' */
} ExtU_ScaleandOffset_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T Temperature;                 /* '<Root>/Temperature' */
  boolean_T Error;                     /* '<Root>/Error' */
} ExtY_ScaleandOffset_T;

/* Real-time Model Data Structure */
struct tag_RTM_ScaleandOffset_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_ScaleandOffset_T ScaleandOffset_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ScaleandOffset_T ScaleandOffset_Y;

/* Model entry point functions */
extern void ScaleandOffset_initialize(void);
extern void ScaleandOffset_step(void);
extern void ScaleandOffset_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ScaleandOffset_T *const ScaleandOffset_M;

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
 * '<Root>' : 'ScaleandOffset'
 * '<S1>'   : 'ScaleandOffset/OutOfRange'
 * '<S2>'   : 'ScaleandOffset/ScaleandOffset'
 */
#endif                                 /* RTW_HEADER_ScaleandOffset_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
