#include <stdio.h>      /* printf */
#include <math.h>       /* mathfunctions */
#include <iostream>     /* output */
#include <fstream>      /* output to file */
#include <iomanip>      /* pretty, pretty */

using namespace std;


int main(int argc, char *argv[])
{
    int n = 10;

    int *a = new int[n+1];
    int *b = new int[n+1];
    int *c = new int[n+1];

    double *p = new double[n+1];
    double *v = new double[n+1];

    double *x = new double[n+2];
    double h = 1.0/(n+1.0);

    for (int i=0; i< n+1; i++){
        x[i] = i*h;
    }

    for (int i=0; i < n; i++){
        a[i] = -1;
        b[i] = 2;
        c[i] = -1;

    }
    p = h*h*f(x_i, n);   /*remember to define h and x*/

    for (int i=1; i < n; i++){
        p[i] = p[i] - p[i-1]*(a[i-1]/b[i-1]);
        b[i] = b[i] - ((c[i-1]*a[i-1])/b[i-1]);
    }

    v[n+1] = p[n+1]/b[n+1];   /*I believe there is something wrong with my indexing*/

    for (int i=n; i > 0; i--){
        v[i] = (p[i] - c[i]*v[i+1])/b[i];
    }
    return 0;

}
