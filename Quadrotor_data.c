/*
 * Quadrotor_data.c
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

/* Block parameters (default storage) */
P_Quadrotor_T Quadrotor_P = {
  /* Variable: K
   * Referenced by: '<S4>/Constant'
   */
  { -7.7046153820576625E-14, 2.0568415980101727E-15, -2.9620934621891788,
    -2.69243311824812E-14, -5.0706175897881024E-13, 2.9620934621876818,
    5.3253085137376416E-14, -1.1699912557763339E-13, -17.566976012231553,
    7.489813748663142E-14, 1.4813006373187932E-15, -2.635071270510476E-14,
    -4.5056041772798421E-14, 6.0529611424578327E-14, -3.8869988393684087,
    -1.4423234882363729E-13, -3.5809071470470815E-13, 3.8869988393680694,
    6.66050035692533E-14, -2.3604596335540535E-14, -10.429932310715913,
    -4.5703703838308467E-15, -5.45830558525804E-16, -3.7379391353805728E-15,
    -7.0969200487941072E-13, 8.7889874960754941, 1.5461464859303925E-13,
    -1.8999567820468504E-14, 9.8547333387505833E-14, -6.957843162920595E-14,
    8.7889874960757073, 2.3795726316028558E-13, -5.475120950364824E-13,
    1.1927325531320073E-14, -1.1450329846972094E-13, 1.7321508017958152,
    -6.6438564028469282E-14, 1.0008785128571973, 1.7582738180471403E-14,
    -1.4856693293264527E-15, 1.086566538116691E-14, -5.1288970252711008E-16,
    1.0008785128572002, 8.0948420252069362E-17, -2.9698328573891379E-13,
    4.01725895004081E-15, -6.3962378206545369E-14, 1.0001732000810113,
    -3.8420071273415418E-14, 2.6780040704538831E-14, -0.99999999999992684,
    3.6512320495907916E-14, -2.553649591752875E-13, 0.99999999999988853,
    9.5438824453605161E-15, -4.0656664253674394E-14, -10.000000000000016,
    1.8996766183083947E-14, -2.0331128108018186E-15, -1.5525366411597476E-14,
    -3.2218579328538396E-13, 3.08803755040334E-15, -6.3361311774436266E-14,
    0.99999999999996581 },

  /* Expression: 0
   * Referenced by: '<S3>/v'
   */
  0.0,

  /* Expression: 0.25
   * Referenced by: '<S3>/v'
   */
  0.25,

  /* Expression: 0.25
   * Referenced by: '<S3>/v'
   */
  0.25,

  /* Expression: 0
   * Referenced by: '<S3>/Omega C'
   */
  0.0,

  /* Expression: [0;0;0]
   * Referenced by: '<S3>/Omega C'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0;0;0]
   * Referenced by: '<S3>/Omega C'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: eye(3)
   * Referenced by: '<S3>/R C'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [0;0;0]
   * Referenced by: '<S3>/P C'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0;0;0]
   * Referenced by: '<S2>/Integrator'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0;0;0]
   * Referenced by: '<S2>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: eye(3)
   * Referenced by: '<S2>/Integrator2'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [0;0;0]
   * Referenced by: '<S2>/Integrator3'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: [0;0;0;0]
   * Referenced by: '<S4>/Integrator'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 9.8*0.25
   * Referenced by: '<Root>/Constant1'
   */
  2.45
};
