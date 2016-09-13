#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void source_term(int n, double h, double *x, double *p);

void exact_solution(int n, double *x, double *u_analytic);

double relative_error(int n, double *v, double *u, double *eps);

#endif // FUNCTIONS_H
