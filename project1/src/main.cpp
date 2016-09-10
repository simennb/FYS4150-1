#include <stdio.h>      /* printf */
#include <math.h>       /* mathfunctions */
#include <iostream>     /* output */
#include <string>
#include <fstream>      /* output to file */
#include <iomanip>      /* pretty, pretty */
#include "time.h"
#include "functions.h"
#include "tridiag_solver.h"


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
    clock_t start, finish;

    /* Defining arrays */
    double *a = new double[n+2];
    double *b = new double[n+2];
    double *c = new double[n+2];

    double *p = new double[n+2];

    double *v = new double[n+2]; /* numerical approximated solution */
    double *u = new double[n+2]; /* exact solution */

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
    exact_solution(n,x,u); /* adding exact solution */

    start = clock();
    /* Tridiagonal solving */
    general_tridiag_solver(n,a,b,c,p,v);

    /* Timing solver */
    finish = clock();
    double time_elapsed = ((finish-start)/((double)CLOCKS_PER_SEC));
    cout <<"time = "<<time_elapsed<<" s"<<endl;

    outfile = "../textfiles/1bN" + to_string(n) + ".txt";

    /*! Simen: should probably not save every index, in case n is super large.
     * For n=100k, datafile is 5 mb, so yeah
    */

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
