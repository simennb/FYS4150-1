#include <cmath>
#include "functions.h"

using namespace std;

void source_term(int n, double h, double *x, double *p)
{
    /*!
     * \brief Evaluates the source term f(x) at point x
     */
    for (int i=0; i<n; i++)
    {
        p[i] = h*h*100.0*exp(-10.0*x[i]);
    }

    return;
}

void exact_solution(int n, double *x, double *u_analytic)
{
    /*!
     * \brief Evaluates the exact solution u(x) for source term f(x) at point x
     */
    for (int i=0; i<n; i++){
        u_analytic[i] = 1.0 - (1.0 - exp(-10.0))*x[i] - exp(-10.0*x[i]);
    }
    return;
}

void relative_error(int n, double *v, double *u, double *eps)
{
    /*!
     * \brief Computes the relative error in the data set at index i
     */
    for (int i=0; i<n; i++)
    {
        eps[i] = log10(abs((v[i]-u[i])/u[i]));
    }
    return;
}
