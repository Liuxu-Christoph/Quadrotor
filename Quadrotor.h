/*
 * Quadrotor.h
 *
 * Code generation for model "Quadrotor".
 *
 * Model version              : 1.104
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Dec  4 11:06:24 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Quadrotor_h_
#define RTW_HEADER_Quadrotor_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Quadrotor_COMMON_INCLUDES_
#define Quadrotor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Quadrotor_COMMON_INCLUDES_ */

#include "Quadrotor_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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

/* Block signals for system '<S2>/MATLAB Function1' */
typedef struct {
  real_T dPdt[3];                      /* '<S2>/MATLAB Function1' */
} B_MATLABFunction1_Quadrotor_T;

/* Block signals for system '<S2>/MATLAB Function2' */
typedef struct {
  real_T dRdt[9];                      /* '<S2>/MATLAB Function2' */
} B_MATLABFunction2_Quadrotor_T;

/* Block signals (default storage) */
typedef struct {
  real_T v;                            /* '<S3>/v' */
  real_T Clock;                        /* '<S3>/Clock' */
  real_T OmegaC[3];                    /* '<S3>/Omega C' */
  real_T RC[9];                        /* '<S3>/R C' */
  real_T PC[3];                        /* '<S3>/P C' */
  real_T Integrator[3];                /* '<S2>/Integrator' */
  real_T Integrator1[3];               /* '<S2>/Integrator1' */
  real_T Integrator2[9];               /* '<S2>/Integrator2' */
  real_T Integrator3[3];               /* '<S2>/Integrator3' */
  real_T Integrator_j[4];              /* '<S4>/Integrator' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T dxIdt[4];                     /* '<S4>/IntStates' */
  real_T T;                            /* '<S4>/Controller' */
  real_T n[3];                         /* '<S4>/Controller' */
  real_T Lambda[3];                    /* '<S3>/MATLAB Function3' */
  real_T vC[3];                        /* '<S3>/MATLAB Function1' */
  real_T dvdt[3];                      /* '<S2>/MATLAB Function' */
  real_T dOmegadt[3];                  /* '<S2>/MATLAB Function' */
  real_T Ve[3];                        /* '<Root>/Non Linear Transformation' */
  real_T Omegae[3];                    /* '<Root>/Non Linear Transformation' */
  real_T Lambdae[3];                   /* '<Root>/Non Linear Transformation' */
  real_T Pe[3];                        /* '<Root>/Non Linear Transformation' */
  B_MATLABFunction2_Quadrotor_T sf_MATLABFunction2_c;/* '<S3>/MATLAB Function2' */
  B_MATLABFunction1_Quadrotor_T sf_MATLABFunction_m;/* '<S3>/MATLAB Function' */
  B_MATLABFunction2_Quadrotor_T sf_MATLABFunction2;/* '<S2>/MATLAB Function2' */
  B_MATLABFunction1_Quadrotor_T sf_MATLABFunction1;/* '<S2>/MATLAB Function1' */
} B_Quadrotor_T;

/* Continuous states (default storage) */
typedef struct {
  real_T RC_CSTATE[9];                 /* '<S3>/R C' */
  real_T PC_CSTATE[3];                 /* '<S3>/P C' */
  real_T Integrator_CSTATE[3];         /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S2>/Integrator1' */
  real_T Integrator2_CSTATE[9];        /* '<S2>/Integrator2' */
  real_T Integrator3_CSTATE[3];        /* '<S2>/Integrator3' */
  real_T Integrator_CSTATE_n[4];       /* '<S4>/Integrator' */
} X_Quadrotor_T;

/* State derivatives (default storage) */
typedef struct {
  real_T RC_CSTATE[9];                 /* '<S3>/R C' */
  real_T PC_CSTATE[3];                 /* '<S3>/P C' */
  real_T Integrator_CSTATE[3];         /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S2>/Integrator1' */
  real_T Integrator2_CSTATE[9];        /* '<S2>/Integrator2' */
  real_T Integrator3_CSTATE[3];        /* '<S2>/Integrator3' */
  real_T Integrator_CSTATE_n[4];       /* '<S4>/Integrator' */
} XDot_Quadrotor_T;

/* State disabled  */
typedef struct {
  boolean_T RC_CSTATE[9];              /* '<S3>/R C' */
  boolean_T PC_CSTATE[3];              /* '<S3>/P C' */
  boolean_T Integrator_CSTATE[3];      /* '<S2>/Integrator' */
  boolean_T Integrator1_CSTATE[3];     /* '<S2>/Integrator1' */
  boolean_T Integrator2_CSTATE[9];     /* '<S2>/Integrator2' */
  boolean_T Integrator3_CSTATE[3];     /* '<S2>/Integrator3' */
  boolean_T Integrator_CSTATE_n[4];    /* '<S4>/Integrator' */
} XDis_Quadrotor_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Quadrotor_T_ {
  real_T K[64];                        /* Variable: K
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T v_Time;                       /* Expression: 0
                                        * Referenced by: '<S3>/v'
                                        */
  real_T v_Y0;                         /* Expression: 0.25
                                        * Referenced by: '<S3>/v'
                                        */
  real_T v_YFinal;                     /* Expression: 0.25
                                        * Referenced by: '<S3>/v'
                                        */
  real_T OmegaC_Time;                  /* Expression: 0
                                        * Referenced by: '<S3>/Omega C'
                                        */
  real_T OmegaC_Y0[3];                 /* Expression: [0;0;0]
                                        * Referenced by: '<S3>/Omega C'
                                        */
  real_T OmegaC_YFinal[3];             /* Expression: [0;0;0]
                                        * Referenced by: '<S3>/Omega C'
                                        */
  real_T RC_IC[9];                     /* Expression: eye(3)
                                        * Referenced by: '<S3>/R C'
                                        */
  real_T PC_IC[3];                     /* Expression: [0;0;0]
                                        * Referenced by: '<S3>/P C'
                                        */
  real_T Integrator_IC[3];             /* Expression: [0;0;0]
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0;0;0]
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  real_T Integrator2_IC[9];            /* Expression: eye(3)
                                        * Referenced by: '<S2>/Integrator2'
                                        */
  real_T Integrator3_IC[3];            /* Expression: [0;0;0]
                                        * Referenced by: '<S2>/Integrator3'
                                        */
  real_T Integrator_IC_b[4];           /* Expression: [0;0;0;0]
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Constant1_Value;              /* Expression: 9.8*0.25
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Quadrotor_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_Quadrotor_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[34];
  real_T odeF[3][34];
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Quadrotor_T Quadrotor_P;

/* Block signals (default storage) */
extern B_Quadrotor_T Quadrotor_B;

/* Continuous states (default storage) */
extern X_Quadrotor_T Quadrotor_X;

/* Model entry point functions */
extern void Quadrotor_initialize(void);
extern void Quadrotor_step(void);
extern void Quadrotor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Quadrotor_T *const Quadrotor_M;

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
 * '<Root>' : 'Quadrotor'
 * '<S1>'   : 'Quadrotor/Non Linear Transformation'
 * '<S2>'   : 'Quadrotor/Quadrotor'
 * '<S3>'   : 'Quadrotor/Subsystem'
 * '<S4>'   : 'Quadrotor/Subsystem1'
 * '<S5>'   : 'Quadrotor/Quadrotor/MATLAB Function'
 * '<S6>'   : 'Quadrotor/Quadrotor/MATLAB Function1'
 * '<S7>'   : 'Quadrotor/Quadrotor/MATLAB Function2'
 * '<S8>'   : 'Quadrotor/Subsystem/MATLAB Function'
 * '<S9>'   : 'Quadrotor/Subsystem/MATLAB Function1'
 * '<S10>'  : 'Quadrotor/Subsystem/MATLAB Function2'
 * '<S11>'  : 'Quadrotor/Subsystem/MATLAB Function3'
 * '<S12>'  : 'Quadrotor/Subsystem1/Controller'
 * '<S13>'  : 'Quadrotor/Subsystem1/IntStates'
 */
#endif                                 /* RTW_HEADER_Quadrotor_h_ */
