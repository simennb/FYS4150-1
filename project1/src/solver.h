#ifndef SOLVER_H
#define SOLVER_H

void general_tridiag_solver(int n, double *a, double *b, double *c, double *p, double*v);

void special_tridiag_solver(int n, double *b, double *p, double *v);

void LU_decomp_solver(int n, double *b, double *p, double *v);

#endif // SOLVER_H
