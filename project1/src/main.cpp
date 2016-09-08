#include <stdio.h>      /* printf */
#include <math.h>       /* mathfunctions */
#include <iostream>     /* output */
#include <fstream>      /* output to file */
#include <iomanip>      /* pretty, pretty */
#include "functions.h"

using namespace std;


int main(int argc, char *argv[])
{
    /*
    if (argc < 2)
    {
        cout<<"Usage: "<<argv[0]<<"n"<<endl;
        exit(1);
    }
    else
    {
    n = argv[1]
    }*/

    int n = 10;

    /* Defining arrays */
    int *a = new int[n+1];
    int *b = new int[n+1];
    int *c = new int[n+1];

    double *p = new double[n+1];
    double *v = new double[n+1];

    double *u = new double[n+1]; /* for exact solution */

    /* since p = h^2*f, its probably better computationally to just do multiply by h in the function for f(x)
    double *f = new double[n+1];
    */

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

    /* Filling array p with values */
    source_term(n,h,x,p);
    for (int i=0; i < n; i++)
    {
        cout<<"i = "<<i<<" x="<<x[i]<<" p="<<p[i] <<endl;
    }

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
