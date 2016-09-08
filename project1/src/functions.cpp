#include <cmath>
#include "functions.h"

using namespace std;

double source_term(double *x, double *f, int n)
{
    /*!
     * \brief Evaluates the source term f(x) at point x
     */
    double *f;
    f = new double[n];

    for (int i=0; n-1; i++)
    {
        f[i] = 100.0*exp(-10.0*x);
    }

    return f;
}

double exact_solution(double *x, double *u_analytic)
{
    /*!
     * \brief Evaluates the exact solution u(x) for source term f(x) at point x
     */
    double u = 1.0 - (1.0 - exp(-10.0))*x - exp(-10.0*x);

    return u;
}

double relative_error(double v_i, double u_i)
{
    /*!
     * \brief Computes the relative error in the data set at index i
     */
    double eps;
    eps = log10(abs((v_i-u_i)/u_i));

    return eps;
}

