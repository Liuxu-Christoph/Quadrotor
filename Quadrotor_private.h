/*
 * Quadrotor_private.h
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

#ifndef RTW_HEADER_Quadrotor_private_h_
#define RTW_HEADER_Quadrotor_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Quadrotor.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void Quadrotor_MATLABFunction1(const real_T rtu_R[9], const real_T rtu_v
  [3], B_MATLABFunction1_Quadrotor_T *localB);
extern void Quadrotor_MATLABFunction2(const real_T rtu_R[9], const real_T
  rtu_Omega[3], B_MATLABFunction2_Quadrotor_T *localB);

/* private model entry point functions */
extern void Quadrotor_derivatives(void);

#endif                                 /* RTW_HEADER_Quadrotor_private_h_ */
