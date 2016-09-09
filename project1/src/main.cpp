#include <stdio.h>      /* printf */
#include <math.h>       /* mathfunctions */
#include <iostream>     /* output */
#include <string>
#include <fstream>      /* output to file */
#include <iomanip>      /* pretty, pretty */
#include "functions.h"

using namespace std;
ofstream myfile;

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
    string outfile;

    /* Defining arrays */
    double *a = new double[n+2];
    double *b = new double[n+2];
    double *c = new double[n+2];

    double *p = new double[n+2];
    double *v = new double[n+2];

    double *u = new double[n+2]; /* for exact solution */

    /* since p = h^2*f, its probably better computationally to just do multiply by h in the function for f(x)
    double *f = new double[n+1];
    */

    double *x = new double[n+2];
    double h = 1.0/(n);

    for (int i=0; i<= n+1; i++){
        x[i] = i*h;
    }

    for (int i=0; i < n+1; i++){
        a[i] = -1.0;
        b[i] = 2.0;
        c[i] = -1.0;

    }

    /* Filling array p with values */
    source_term(n,h,x,p);

    for (int i=1; i <= n; i++){ //n+1 instead?
        p[i] = p[i] - p[i-1]*(a[i]/b[i-1]);
        b[i] = b[i] - ((c[i-1]*a[i])/b[i-1]);
        u[i] = 1.0 - (1.0 - exp(-10.0))*x[i] - exp(-10.0*x[i]);
    }
    cout << u[0] << endl;

    v[n] = p[n]/b[n];   /*I believe there is something wrong with my indexing*/
    for (int i=n-1; i >= 1; i--){
        v[i] = (p[i] - c[i]*v[i+1])/b[i];
    }

    outfile = "../textfiles/1bN" + to_string(n) + ".txt";

    // Open file and write the results to file:
        myfile.open(outfile);
        myfile << setiosflags(ios::showpoint | ios::uppercase);
        myfile << "       x:          u(x):          v(x):  " << endl;
        for (int i=0;i<=n;i++) {
           myfile << setw(15) << setprecision(8) << x[i] << ",";
           myfile << setw(15) << setprecision(8) << u[i] << ",";
           myfile << setw(15) << setprecision(8) << v[i] << endl;
        }
        myfile.close();
    return 0;
}
