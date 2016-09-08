#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void source_term(int n, double h, double *x, double *p);

void exact_solution(double *x, double *u_analytic);

void relative_error(double *v, double *u,double *eps);

#endif // FUNCTIONS_H
