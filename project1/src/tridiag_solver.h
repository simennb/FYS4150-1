#ifndef TRIDIAG_SOLVER_H
#define TRIDIAG_SOLVER_H

void general_tridiag_solver(int n, double *a, double *b, double *c, double *p, double*v);

void special_tridiag_solver(int n, double *b, double *p, double *v);

#endif // TRIDIAG_SOLVER_H
