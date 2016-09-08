#include <cmath>
#include "functions.h"

using namespace std;

void source_term(int n, double h, double *x, double *p)
{
    /*!
     * \brief Evaluates the source term f(x) at point x
     */
    /*
    double *f;
    f = new double[n];
    */
    for (int i=0; i<n; i++)
    {
        p[i] = h*h*100.0*exp(-10.0*x[i]);
    }

    return;
}

void exact_solution(double *x, double *u_analytic)
{
    /*!
     * \brief Evaluates the exact solution u(x) for source term f(x) at point x
     */
    /*
    u_analytic = 1.0 - (1.0 - exp(-10.0))*x - exp(-10.0*x);
    */
    return;
}

void relative_error(double *v, double *u, double *eps)
{
    /*!
     * \brief Computes the relative error in the data set at index i
     */
    /*
    eps = log10(abs((v-u)/u));
    */
    return;
}

