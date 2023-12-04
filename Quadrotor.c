/*
 * Quadrotor.c
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

#include "Quadrotor.h"
#include "Quadrotor_private.h"

/* Block signals (default storage) */
B_Quadrotor_T Quadrotor_B;

/* Continuous states */
X_Quadrotor_T Quadrotor_X;

/* Real-time model */
static RT_MODEL_Quadrotor_T Quadrotor_M_;
RT_MODEL_Quadrotor_T *const Quadrotor_M = &Quadrotor_M_;

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
  int_T nXc = 34;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Quadrotor_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Quadrotor_step();
  Quadrotor_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Quadrotor_step();
  Quadrotor_derivatives();

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

/*
 * Output and update for atomic system:
 *    '<S2>/MATLAB Function1'
 *    '<S3>/MATLAB Function'
 */
void Quadrotor_MATLABFunction1(const real_T rtu_R[9], const real_T rtu_v[3],
  B_MATLABFunction1_Quadrotor_T *localB)
{
  int32_T i;

  /* :  dPdt = R*v; */
  for (i = 0; i < 3; i++) {
    localB->dPdt[i] = 0.0;
    localB->dPdt[i] += rtu_R[i] * rtu_v[0];
    localB->dPdt[i] += rtu_R[i + 3] * rtu_v[1];
    localB->dPdt[i] += rtu_R[i + 6] * rtu_v[2];
  }
}

/*
 * Output and update for atomic system:
 *    '<S2>/MATLAB Function2'
 *    '<S3>/MATLAB Function2'
 */
void Quadrotor_MATLABFunction2(const real_T rtu_R[9], const real_T rtu_Omega[3],
  B_MATLABFunction2_Quadrotor_T *localB)
{
  real_T tmp[9];
  int32_T i;
  int32_T i_0;

  /* :  dRdt = R*skew(Omega); */
  /* 'skew:2' Lx=[0,-L(3),L(2); */
  /* 'skew:3'     L(3),0,-L(1); */
  /* 'skew:4'     -L(2),L(1),0] */
  tmp[0] = 0.0;
  tmp[3] = -rtu_Omega[2];
  tmp[6] = rtu_Omega[1];
  tmp[1] = rtu_Omega[2];
  tmp[4] = 0.0;
  tmp[7] = -rtu_Omega[0];
  tmp[2] = -rtu_Omega[1];
  tmp[5] = rtu_Omega[0];
  tmp[8] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      localB->dRdt[i + 3 * i_0] = 0.0;
      localB->dRdt[i + 3 * i_0] += tmp[3 * i_0] * rtu_R[i];
      localB->dRdt[i + 3 * i_0] += tmp[3 * i_0 + 1] * rtu_R[i + 3];
      localB->dRdt[i + 3 * i_0] += tmp[3 * i_0 + 2] * rtu_R[i + 6];
    }
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Quadrotor_step(void)
{
  real_T tmp_0[64];
  real_T tmp_1[16];
  real_T Re[9];
  real_T a[9];
  real_T a_0[9];
  real_T tmp_3[9];
  real_T Cntr[4];
  real_T a_1[3];
  real_T b_a[3];
  real_T tmp_2[3];
  real_T Pitch;
  real_T a_2;
  real_T b_a_0;
  real_T tmp;
  int32_T i;
  int32_T i_0;
  static const int16_T a_3[9] = { -10000, 0, 0, 0, -10000, 0, 0, 0, -10000 };

  static const real_T b[9] = { 0.0001, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0,
    0.0001 };

  static const int16_T b_a_1[9] = { 10000, 0, 0, 0, 10000, 0, 0, 0, 10000 };

  if (rtmIsMajorTimeStep(Quadrotor_M)) {
    /* set solver stop time */
    if (!(Quadrotor_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Quadrotor_M->solverInfo,
                            ((Quadrotor_M->Timing.clockTickH0 + 1) *
        Quadrotor_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Quadrotor_M->solverInfo,
                            ((Quadrotor_M->Timing.clockTick0 + 1) *
        Quadrotor_M->Timing.stepSize0 + Quadrotor_M->Timing.clockTickH0 *
        Quadrotor_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Quadrotor_M)) {
    Quadrotor_M->Timing.t[0] = rtsiGetT(&Quadrotor_M->solverInfo);
  }

  /* Step: '<S3>/v' */
  Pitch = Quadrotor_M->Timing.t[0];
  if (Pitch < Quadrotor_P.v_Time) {
    /* Step: '<S3>/v' */
    Quadrotor_B.v = Quadrotor_P.v_Y0;
  } else {
    /* Step: '<S3>/v' */
    Quadrotor_B.v = Quadrotor_P.v_YFinal;
  }

  /* End of Step: '<S3>/v' */

  /* Clock: '<S3>/Clock' */
  Quadrotor_B.Clock = Quadrotor_M->Timing.t[0];

  /* MATLAB Function: '<S3>/MATLAB Function1' */
  /* :  vC = [0;0;0]; */
  Quadrotor_B.vC[0] = 0.0;
  Quadrotor_B.vC[1] = 0.0;
  Quadrotor_B.vC[2] = 0.0;

  /* :  if (t>20) */
  if (Quadrotor_B.Clock > 20.0) {
    /* :  vC = [v;0;0]; */
    Quadrotor_B.vC[0] = Quadrotor_B.v;
    Quadrotor_B.vC[1] = 0.0;
    Quadrotor_B.vC[2] = 0.0;
  }

  /* :  if (t>28) */
  if (Quadrotor_B.Clock > 28.0) {
    /* :  vC = [0;v;0]; */
    Quadrotor_B.vC[0] = 0.0;
    Quadrotor_B.vC[1] = Quadrotor_B.v;
    Quadrotor_B.vC[2] = 0.0;
  }

  /* :  if (t>36) */
  if (Quadrotor_B.Clock > 36.0) {
    /* :  vC = [-v;0;0]; */
    Quadrotor_B.vC[0] = -Quadrotor_B.v;
    Quadrotor_B.vC[1] = 0.0;
    Quadrotor_B.vC[2] = 0.0;
  }

  /* :  if (t>44) */
  if (Quadrotor_B.Clock > 44.0) {
    /* :  vC = [0;-v;0]; */
    Quadrotor_B.vC[0] = 0.0;
    Quadrotor_B.vC[1] = -Quadrotor_B.v;
    Quadrotor_B.vC[2] = 0.0;
  }

  /* :  if (t>60) */
  if (Quadrotor_B.Clock > 60.0) {
    /* :  vC = [0;0;0]; */
    Quadrotor_B.vC[0] = 0.0;
    Quadrotor_B.vC[1] = 0.0;
    Quadrotor_B.vC[2] = 0.0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function1' */

  /* Step: '<S3>/Omega C' */
  Pitch = Quadrotor_M->Timing.t[0];
  if (Pitch < Quadrotor_P.OmegaC_Time) {
    /* Step: '<S3>/Omega C' */
    Quadrotor_B.OmegaC[0] = Quadrotor_P.OmegaC_Y0[0];
    Quadrotor_B.OmegaC[1] = Quadrotor_P.OmegaC_Y0[1];
    Quadrotor_B.OmegaC[2] = Quadrotor_P.OmegaC_Y0[2];
  } else {
    /* Step: '<S3>/Omega C' */
    Quadrotor_B.OmegaC[0] = Quadrotor_P.OmegaC_YFinal[0];
    Quadrotor_B.OmegaC[1] = Quadrotor_P.OmegaC_YFinal[1];
    Quadrotor_B.OmegaC[2] = Quadrotor_P.OmegaC_YFinal[2];
  }

  /* End of Step: '<S3>/Omega C' */

  /* Integrator: '<S3>/P C' */
  Quadrotor_B.PC[0] = Quadrotor_X.PC_CSTATE[0];

  /* Integrator: '<S2>/Integrator' */
  Quadrotor_B.Integrator[0] = Quadrotor_X.Integrator_CSTATE[0];

  /* Integrator: '<S2>/Integrator1' */
  Quadrotor_B.Integrator1[0] = Quadrotor_X.Integrator1_CSTATE[0];

  /* Integrator: '<S3>/P C' */
  Quadrotor_B.PC[1] = Quadrotor_X.PC_CSTATE[1];

  /* Integrator: '<S2>/Integrator' */
  Quadrotor_B.Integrator[1] = Quadrotor_X.Integrator_CSTATE[1];

  /* Integrator: '<S2>/Integrator1' */
  Quadrotor_B.Integrator1[1] = Quadrotor_X.Integrator1_CSTATE[1];

  /* Integrator: '<S3>/P C' */
  Quadrotor_B.PC[2] = Quadrotor_X.PC_CSTATE[2];

  /* Integrator: '<S2>/Integrator' */
  Quadrotor_B.Integrator[2] = Quadrotor_X.Integrator_CSTATE[2];

  /* Integrator: '<S2>/Integrator1' */
  Quadrotor_B.Integrator1[2] = Quadrotor_X.Integrator1_CSTATE[2];

  /* Integrator: '<S3>/R C' */
  memcpy(&Quadrotor_B.RC[0], &Quadrotor_X.RC_CSTATE[0], 9U * sizeof(real_T));

  /* Integrator: '<S2>/Integrator2' */
  memcpy(&Quadrotor_B.Integrator2[0], &Quadrotor_X.Integrator2_CSTATE[0], 9U *
         sizeof(real_T));

  /* :  Ve = v-vC; */
  /* :  Omegae = Omega-OmegaC; */
  /* :  Re = R*RC'; */
  /* :  Pitch = atan2(-Re(3,1),sqrt(Re(1,1)^2+Re(2,1)^2)); */
  /* :  Yaw = atan2(Re(2,1)/cos(Pitch),Re(1,1)/cos(Pitch)); */
  /* :  Roll = atan2(Re(3,2)/cos(Pitch),Re(3,3)/cos(Pitch)); */
  /* :  Lambdae = [Roll;Pitch;Yaw]; */
  /* :  Pe = P-PC; */
  for (i = 0; i < 3; i++) {
    /* Integrator: '<S2>/Integrator3' */
    Quadrotor_B.Integrator3[i] = Quadrotor_X.Integrator3_CSTATE[i];

    /* MATLAB Function: '<Root>/Non Linear Transformation' incorporates:
     *  Integrator: '<S2>/Integrator2'
     *  Integrator: '<S3>/R C'
     */
    Quadrotor_B.Ve[i] = Quadrotor_B.Integrator[i] - Quadrotor_B.vC[i];
    Quadrotor_B.Omegae[i] = Quadrotor_B.Integrator1[i] - Quadrotor_B.OmegaC[i];
    for (i_0 = 0; i_0 < 3; i_0++) {
      Re[i + 3 * i_0] = 0.0;
      Pitch = Re[3 * i_0 + i];
      Pitch += Quadrotor_B.Integrator2[i] * Quadrotor_B.RC[i_0];
      Re[i + 3 * i_0] = Pitch;
      Pitch = Re[3 * i_0 + i];
      Pitch += Quadrotor_B.Integrator2[i + 3] * Quadrotor_B.RC[i_0 + 3];
      Re[i + 3 * i_0] = Pitch;
      Pitch = Re[3 * i_0 + i];
      Pitch += Quadrotor_B.Integrator2[i + 6] * Quadrotor_B.RC[i_0 + 6];
      Re[i + 3 * i_0] = Pitch;
    }

    Quadrotor_B.Pe[i] = Quadrotor_B.Integrator3[i] - Quadrotor_B.PC[i];
  }

  /* MATLAB Function: '<Root>/Non Linear Transformation' */
  Pitch = rt_atan2d_snf(-Re[2], sqrt(Re[0] * Re[0] + Re[1] * Re[1]));
  b_a_0 = cos(Pitch);
  a_2 = cos(Pitch);
  b_a_0 = rt_atan2d_snf(Re[5] / b_a_0, Re[8] / a_2);
  a_2 = cos(Pitch);
  tmp = cos(Pitch);
  a_2 = rt_atan2d_snf(Re[1] / a_2, Re[0] / tmp);
  Quadrotor_B.Lambdae[0] = b_a_0;
  Quadrotor_B.Lambdae[1] = Pitch;
  Quadrotor_B.Lambdae[2] = a_2;
  if (rtmIsMajorTimeStep(Quadrotor_M)) {
  }

  /* Integrator: '<S4>/Integrator' */
  Quadrotor_B.Integrator_j[0] = Quadrotor_X.Integrator_CSTATE_n[0];
  Quadrotor_B.Integrator_j[1] = Quadrotor_X.Integrator_CSTATE_n[1];
  Quadrotor_B.Integrator_j[2] = Quadrotor_X.Integrator_CSTATE_n[2];
  Quadrotor_B.Integrator_j[3] = Quadrotor_X.Integrator_CSTATE_n[3];

  /* MATLAB Function: '<S4>/Controller' incorporates:
   *  Constant: '<S4>/Constant'
   */
  /* :  State = [Pe;ve;Lambdae;Omegae;xI]; */
  /* :  Cntr = -K*State; */
  for (i_0 = 0; i_0 < 64; i_0++) {
    tmp_0[i_0] = -Quadrotor_P.K[i_0];
  }

  tmp_1[0] = Quadrotor_B.Pe[0];
  tmp_1[3] = Quadrotor_B.Ve[0];
  tmp_1[6] = Quadrotor_B.Lambdae[0];
  tmp_1[9] = Quadrotor_B.Omegae[0];
  tmp_1[1] = Quadrotor_B.Pe[1];
  tmp_1[4] = Quadrotor_B.Ve[1];
  tmp_1[7] = Quadrotor_B.Lambdae[1];
  tmp_1[10] = Quadrotor_B.Omegae[1];
  tmp_1[2] = Quadrotor_B.Pe[2];
  tmp_1[5] = Quadrotor_B.Ve[2];
  tmp_1[8] = Quadrotor_B.Lambdae[2];
  tmp_1[11] = Quadrotor_B.Omegae[2];
  tmp_1[12] = Quadrotor_B.Integrator_j[0];
  tmp_1[13] = Quadrotor_B.Integrator_j[1];
  tmp_1[14] = Quadrotor_B.Integrator_j[2];
  tmp_1[15] = Quadrotor_B.Integrator_j[3];
  for (i_0 = 0; i_0 < 4; i_0++) {
    Cntr[i_0] = 0.0;
    for (i = 0; i < 16; i++) {
      Pitch = Cntr[i_0];
      Pitch += tmp_0[(i << 2) + i_0] * tmp_1[i];
      Cntr[i_0] = Pitch;
    }
  }

  /* :  T = Cntr(1)+0.25*9.8; */
  Quadrotor_B.T = Cntr[0] + 2.45;

  /* :  n = Cntr(2:4); */
  Quadrotor_B.n[0] = Cntr[1];
  Quadrotor_B.n[1] = Cntr[2];
  Quadrotor_B.n[2] = Cntr[3];

  /* End of MATLAB Function: '<S4>/Controller' */
  if (rtmIsMajorTimeStep(Quadrotor_M)) {
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Quadrotor_B.Sum = Quadrotor_P.Constant1_Value + Quadrotor_B.T;

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Integrator: '<S2>/Integrator2'
   */
  /* :  m = 0.250; */
  /* :  g = 9.8; */
  /* :  J = [10.^-4,0,0;0,10.^-4,0;0,0,10.^-4]; */
  /* :  dvdt = -skew(Omega)*v+1/m*([0;0;-T]+R'*[0;0;m*g]+R'*[m*0.1;0;0]); */
  /* 'skew:2' Lx=[0,-L(3),L(2); */
  /* 'skew:3'     L(3),0,-L(1); */
  /* 'skew:4'     -L(2),L(1),0] */
  Re[0] = -0.0;
  Re[3] = Quadrotor_B.Integrator1[2];
  Re[6] = -Quadrotor_B.Integrator1[1];
  Re[1] = -Quadrotor_B.Integrator1[2];
  Re[4] = -0.0;
  Re[7] = Quadrotor_B.Integrator1[0];
  Re[2] = Quadrotor_B.Integrator1[1];
  Re[5] = -Quadrotor_B.Integrator1[0];
  Re[8] = -0.0;
  tmp_2[0] = 0.0;
  tmp_2[1] = 0.0;
  tmp_2[2] = -Quadrotor_B.Sum;

  /* :  dOmegadt = -J^-1*skew(Omega)*J*Omega+J^-1*Torque; */
  /* 'skew:2' Lx=[0,-L(3),L(2); */
  /* 'skew:3'     L(3),0,-L(1); */
  /* 'skew:4'     -L(2),L(1),0] */
  tmp_3[0] = 0.0;
  tmp_3[3] = -Quadrotor_B.Integrator1[2];
  tmp_3[6] = Quadrotor_B.Integrator1[1];
  tmp_3[1] = Quadrotor_B.Integrator1[2];
  tmp_3[4] = 0.0;
  tmp_3[7] = -Quadrotor_B.Integrator1[0];
  tmp_3[2] = -Quadrotor_B.Integrator1[1];
  tmp_3[5] = Quadrotor_B.Integrator1[0];
  tmp_3[8] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    b_a_0 = Quadrotor_B.Integrator2[3 * i_0] * 0.0;
    a_2 = Quadrotor_B.Integrator2[3 * i_0] * 0.025;
    tmp = Re[i_0] * Quadrotor_B.Integrator[0];
    b_a_0 += Quadrotor_B.Integrator2[3 * i_0 + 1] * 0.0;
    a_2 += Quadrotor_B.Integrator2[3 * i_0 + 1] * 0.0;
    tmp += Re[i_0 + 3] * Quadrotor_B.Integrator[1];
    b_a_0 += Quadrotor_B.Integrator2[3 * i_0 + 2] * 2.45;
    a_2 += Quadrotor_B.Integrator2[3 * i_0 + 2] * 0.0;
    tmp += Re[i_0 + 6] * Quadrotor_B.Integrator[2];
    b_a_0 = (tmp_2[i_0] + b_a_0) + a_2;
    Quadrotor_B.dvdt[i_0] = 4.0 * b_a_0 + tmp;
    for (i = 0; i < 3; i++) {
      a[i_0 + 3 * i] = 0.0;
      Pitch = a[3 * i + i_0];
      Pitch += tmp_3[3 * i] * (real_T)a_3[i_0];
      a[i_0 + 3 * i] = Pitch;
      Pitch = a[3 * i + i_0];
      Pitch += tmp_3[3 * i + 1] * (real_T)a_3[i_0 + 3];
      a[i_0 + 3 * i] = Pitch;
      Pitch = a[3 * i + i_0];
      Pitch += tmp_3[3 * i + 2] * (real_T)a_3[i_0 + 6];
      a[i_0 + 3 * i] = Pitch;
    }

    a_1[i_0] = 0.0;
    b_a[i_0] = 0.0;
    for (i = 0; i < 3; i++) {
      Pitch = a_1[i_0];
      b_a_0 = b_a[i_0];
      a_0[i_0 + 3 * i] = 0.0;
      a_2 = a_0[3 * i + i_0];
      a_2 += b[3 * i] * a[i_0];
      a_0[i_0 + 3 * i] = a_2;
      a_2 = a_0[3 * i + i_0];
      a_2 += b[3 * i + 1] * a[i_0 + 3];
      a_0[i_0 + 3 * i] = a_2;
      a_2 = a_0[3 * i + i_0];
      a_2 += b[3 * i + 2] * a[i_0 + 6];
      a_0[i_0 + 3 * i] = a_2;
      Pitch += a_0[3 * i + i_0] * Quadrotor_B.Integrator1[i];
      b_a_0 += (real_T)b_a_1[3 * i + i_0] * Quadrotor_B.n[i];
      b_a[i_0] = b_a_0;
      a_1[i_0] = Pitch;
    }

    Quadrotor_B.dOmegadt[i_0] = a_1[i_0] + b_a[i_0];
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  Quadrotor_MATLABFunction1(Quadrotor_B.Integrator2, Quadrotor_B.Integrator,
    &Quadrotor_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S2>/MATLAB Function2' */
  Quadrotor_MATLABFunction2(Quadrotor_B.Integrator2, Quadrotor_B.Integrator1,
    &Quadrotor_B.sf_MATLABFunction2);

  /* MATLAB Function: '<S3>/MATLAB Function' */
  Quadrotor_MATLABFunction1(Quadrotor_B.RC, Quadrotor_B.vC,
    &Quadrotor_B.sf_MATLABFunction_m);

  /* MATLAB Function: '<S3>/MATLAB Function2' */
  Quadrotor_MATLABFunction2(Quadrotor_B.RC, Quadrotor_B.OmegaC,
    &Quadrotor_B.sf_MATLABFunction2_c);

  /* MATLAB Function: '<S3>/MATLAB Function3' incorporates:
   *  Integrator: '<S3>/R C'
   */
  /* :  Pitch = atan2(-R(3,1),sqrt(R(1,1).^2+R(2,1).^2)); */
  Pitch = rt_atan2d_snf(-Quadrotor_B.RC[2], sqrt(Quadrotor_B.RC[0] *
    Quadrotor_B.RC[0] + Quadrotor_B.RC[1] * Quadrotor_B.RC[1]));

  /* :  Yaw = atan2(R(2,1)/cos(Pitch),R(1,1)/cos(Pitch)); */
  /* :  Roll = atan2(R(3,2)/cos(Pitch),R(3,3)/cos(Pitch)); */
  /* :  Lambda = [Roll;Pitch;Yaw]; */
  b_a_0 = cos(Pitch);
  a_2 = cos(Pitch);
  b_a_0 = rt_atan2d_snf(Quadrotor_B.RC[5] / b_a_0, Quadrotor_B.RC[8] / a_2);
  a_2 = cos(Pitch);
  tmp = cos(Pitch);
  a_2 = rt_atan2d_snf(Quadrotor_B.RC[1] / a_2, Quadrotor_B.RC[0] / tmp);
  Quadrotor_B.Lambda[0] = b_a_0;
  Quadrotor_B.Lambda[1] = Pitch;
  Quadrotor_B.Lambda[2] = a_2;

  /* MATLAB Function: '<S4>/IntStates' */
  /* :  dxIdt=[Pe;Lambdae(3)]; */
  Quadrotor_B.dxIdt[0] = Quadrotor_B.Pe[0];
  Quadrotor_B.dxIdt[1] = Quadrotor_B.Pe[1];
  Quadrotor_B.dxIdt[2] = Quadrotor_B.Pe[2];
  Quadrotor_B.dxIdt[3] = Quadrotor_B.Lambdae[2];
  if (rtmIsMajorTimeStep(Quadrotor_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Quadrotor_M->rtwLogInfo, (Quadrotor_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Quadrotor_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Quadrotor_M)!=-1) &&
          !((rtmGetTFinal(Quadrotor_M)-(((Quadrotor_M->Timing.clockTick1+
               Quadrotor_M->Timing.clockTickH1* 4294967296.0)) * 2.0)) >
            (((Quadrotor_M->Timing.clockTick1+Quadrotor_M->Timing.clockTickH1*
               4294967296.0)) * 2.0) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Quadrotor_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Quadrotor_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Quadrotor_M->Timing.clockTick0)) {
      ++Quadrotor_M->Timing.clockTickH0;
    }

    Quadrotor_M->Timing.t[0] = rtsiGetSolverStopTime(&Quadrotor_M->solverInfo);

    {
      /* Update absolute timer for sample time: [2.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 2.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Quadrotor_M->Timing.clockTick1++;
      if (!Quadrotor_M->Timing.clockTick1) {
        Quadrotor_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Quadrotor_derivatives(void)
{
  XDot_Quadrotor_T *_rtXdot;
  _rtXdot = ((XDot_Quadrotor_T *) Quadrotor_M->derivs);

  /* Derivatives for Integrator: '<S3>/P C' */
  _rtXdot->PC_CSTATE[0] = Quadrotor_B.sf_MATLABFunction_m.dPdt[0];

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = Quadrotor_B.dvdt[0];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = Quadrotor_B.dOmegadt[0];

  /* Derivatives for Integrator: '<S3>/P C' */
  _rtXdot->PC_CSTATE[1] = Quadrotor_B.sf_MATLABFunction_m.dPdt[1];

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = Quadrotor_B.dvdt[1];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = Quadrotor_B.dOmegadt[1];

  /* Derivatives for Integrator: '<S3>/P C' */
  _rtXdot->PC_CSTATE[2] = Quadrotor_B.sf_MATLABFunction_m.dPdt[2];

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = Quadrotor_B.dvdt[2];

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = Quadrotor_B.dOmegadt[2];

  /* Derivatives for Integrator: '<S3>/R C' */
  memcpy(&_rtXdot->RC_CSTATE[0], &Quadrotor_B.sf_MATLABFunction2_c.dRdt[0], 9U *
         sizeof(real_T));

  /* Derivatives for Integrator: '<S2>/Integrator2' */
  memcpy(&_rtXdot->Integrator2_CSTATE[0], &Quadrotor_B.sf_MATLABFunction2.dRdt[0],
         9U * sizeof(real_T));

  /* Derivatives for Integrator: '<S2>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = Quadrotor_B.sf_MATLABFunction1.dPdt[0];
  _rtXdot->Integrator3_CSTATE[1] = Quadrotor_B.sf_MATLABFunction1.dPdt[1];
  _rtXdot->Integrator3_CSTATE[2] = Quadrotor_B.sf_MATLABFunction1.dPdt[2];

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_n[0] = Quadrotor_B.dxIdt[0];
  _rtXdot->Integrator_CSTATE_n[1] = Quadrotor_B.dxIdt[1];
  _rtXdot->Integrator_CSTATE_n[2] = Quadrotor_B.dxIdt[2];
  _rtXdot->Integrator_CSTATE_n[3] = Quadrotor_B.dxIdt[3];
}

/* Model initialize function */
void Quadrotor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Quadrotor_M, 0,
                sizeof(RT_MODEL_Quadrotor_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Quadrotor_M->solverInfo,
                          &Quadrotor_M->Timing.simTimeStep);
    rtsiSetTPtr(&Quadrotor_M->solverInfo, &rtmGetTPtr(Quadrotor_M));
    rtsiSetStepSizePtr(&Quadrotor_M->solverInfo, &Quadrotor_M->Timing.stepSize0);
    rtsiSetdXPtr(&Quadrotor_M->solverInfo, &Quadrotor_M->derivs);
    rtsiSetContStatesPtr(&Quadrotor_M->solverInfo, (real_T **)
                         &Quadrotor_M->contStates);
    rtsiSetNumContStatesPtr(&Quadrotor_M->solverInfo,
      &Quadrotor_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Quadrotor_M->solverInfo,
      &Quadrotor_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Quadrotor_M->solverInfo,
      &Quadrotor_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Quadrotor_M->solverInfo,
      &Quadrotor_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Quadrotor_M->solverInfo, (&rtmGetErrorStatus
      (Quadrotor_M)));
    rtsiSetRTModelPtr(&Quadrotor_M->solverInfo, Quadrotor_M);
  }

  rtsiSetSimTimeStep(&Quadrotor_M->solverInfo, MAJOR_TIME_STEP);
  Quadrotor_M->intgData.y = Quadrotor_M->odeY;
  Quadrotor_M->intgData.f[0] = Quadrotor_M->odeF[0];
  Quadrotor_M->intgData.f[1] = Quadrotor_M->odeF[1];
  Quadrotor_M->intgData.f[2] = Quadrotor_M->odeF[2];
  Quadrotor_M->contStates = ((X_Quadrotor_T *) &Quadrotor_X);
  rtsiSetSolverData(&Quadrotor_M->solverInfo, (void *)&Quadrotor_M->intgData);
  rtsiSetSolverName(&Quadrotor_M->solverInfo,"ode3");
  rtmSetTPtr(Quadrotor_M, &Quadrotor_M->Timing.tArray[0]);
  rtmSetTFinal(Quadrotor_M, 100.0);
  Quadrotor_M->Timing.stepSize0 = 2.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Quadrotor_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Quadrotor_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Quadrotor_M->rtwLogInfo, (NULL));
    rtliSetLogT(Quadrotor_M->rtwLogInfo, "tout");
    rtliSetLogX(Quadrotor_M->rtwLogInfo, "");
    rtliSetLogXFinal(Quadrotor_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Quadrotor_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Quadrotor_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Quadrotor_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Quadrotor_M->rtwLogInfo, 1);
    rtliSetLogY(Quadrotor_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Quadrotor_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Quadrotor_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Quadrotor_B), 0,
                sizeof(B_Quadrotor_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Quadrotor_X, 0,
                  sizeof(X_Quadrotor_T));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Quadrotor_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Quadrotor_M), Quadrotor_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Quadrotor_M)));

  /* InitializeConditions for Integrator: '<S3>/P C' */
  Quadrotor_X.PC_CSTATE[0] = Quadrotor_P.PC_IC[0];

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Quadrotor_X.Integrator_CSTATE[0] = Quadrotor_P.Integrator_IC[0];

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  Quadrotor_X.Integrator1_CSTATE[0] = Quadrotor_P.Integrator1_IC[0];

  /* InitializeConditions for Integrator: '<S3>/P C' */
  Quadrotor_X.PC_CSTATE[1] = Quadrotor_P.PC_IC[1];

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Quadrotor_X.Integrator_CSTATE[1] = Quadrotor_P.Integrator_IC[1];

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  Quadrotor_X.Integrator1_CSTATE[1] = Quadrotor_P.Integrator1_IC[1];

  /* InitializeConditions for Integrator: '<S3>/P C' */
  Quadrotor_X.PC_CSTATE[2] = Quadrotor_P.PC_IC[2];

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Quadrotor_X.Integrator_CSTATE[2] = Quadrotor_P.Integrator_IC[2];

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  Quadrotor_X.Integrator1_CSTATE[2] = Quadrotor_P.Integrator1_IC[2];

  /* InitializeConditions for Integrator: '<S3>/R C' */
  memcpy(&Quadrotor_X.RC_CSTATE[0], &Quadrotor_P.RC_IC[0], 9U * sizeof(real_T));

  /* InitializeConditions for Integrator: '<S2>/Integrator2' */
  memcpy(&Quadrotor_X.Integrator2_CSTATE[0], &Quadrotor_P.Integrator2_IC[0], 9U *
         sizeof(real_T));

  /* InitializeConditions for Integrator: '<S2>/Integrator3' */
  Quadrotor_X.Integrator3_CSTATE[0] = Quadrotor_P.Integrator3_IC[0];
  Quadrotor_X.Integrator3_CSTATE[1] = Quadrotor_P.Integrator3_IC[1];
  Quadrotor_X.Integrator3_CSTATE[2] = Quadrotor_P.Integrator3_IC[2];

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  Quadrotor_X.Integrator_CSTATE_n[0] = Quadrotor_P.Integrator_IC_b[0];
  Quadrotor_X.Integrator_CSTATE_n[1] = Quadrotor_P.Integrator_IC_b[1];
  Quadrotor_X.Integrator_CSTATE_n[2] = Quadrotor_P.Integrator_IC_b[2];
  Quadrotor_X.Integrator_CSTATE_n[3] = Quadrotor_P.Integrator_IC_b[3];
}

/* Model terminate function */
void Quadrotor_terminate(void)
{
  /* (no terminate code required) */
}
