#include <stdio.h>      /* printf */
#include <math.h>       /* mathfunctions */
#include <iostream>     /* output */
#include <string>
#include <fstream>      /* output to file */
#include <iomanip>      /* pretty, pretty */
#include "time.h"
#include "functions.h"
#include "solver.h"
#include "lib.h"

using namespace std;
ofstream myfile;

int main(int argc, char *argv[])
{
    /* Program could be a lot more optimized memory wise, but thats not the main point of this project.
     * We are more interested in looking at the time each of the algorithms take.
     * So even though the specialized algorithm uses less arrays and therefore less memory,
     * since we compare the two algorithms in the same program, we aren't really able to use that advantage.
     */
    if (argc < 3)
    {
        cout<<"Usage: "<<argv[0]<<" exponent"<<" task"<<endl;
        cout<<"For 'task', use: b, c, d, or e"<<endl;
        exit(1);
    }

    int exponent = atoi(argv[1]);
    int n = pow(10, exponent);
    string outfile;

    /* For timing various parts */
    clock_t start, finish;
    double time_general; double time_special; double time_ludcmp;

    /* For loop going through all the different n values we want to test */
    for (int n_counter = 1; n_counter < exponent+1; n_counter++)
    {
        n = pow(10, n_counter);

        /* Defining arrays */
        double *a = new double[n+1];
        double *b = new double[n+1];
        double *c = new double[n+1];

        double *p = new double[n+1];

        double *v_general = new double[n+1]; /* general numerical solution */
        double *v_special = new double[n+1]; /* specialized numerical solution */
        double *u = new double[n+1]; /* exact solution */
        double *eps = new double[n+1];

        double *x = new double[n+1];
        double h = 1.0/(n);

        for (int i=0; i<= n; i++){
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

        ////////////////////////////////////////////////////////////////////////////////////
        ////                                  Task (b)                                  ////
        ////////////////////////////////////////////////////////////////////////////////////
        if (strcmp(argv[2], "b") == 0)
        {
            /* Comparing numerical solution to exact solution */

            /* General tridiagonal algorithm */
            v_general[0] = v_general[n] = 0.0;
            general_tridiag_solver(n,a,b,c,p,v_general);

            /* Special tridiagonal algorithm */
            /* Initializing b and p again */
            source_term(n,h,x,p);
            b[0] = b[n] = 2; v_special[0] = v_special[n] = 0.0;
            for (int i=1; i<n; i++) b[i] = (i+1.0)/((double) i);
            special_tridiag_solver(n,b,p,v_special);

            /* Writing results to file */
            outfile = "../benchmarks/task_b_N_" + to_string(n) + ".txt";

            // Only save max 1000 values
            int step_size = 1;
            int max_vals  = 1000;
            if (n > max_vals)
            {
                step_size = (int)(n/((double)max_vals))+1;
            }

            // Open file and write the results to file:
            myfile.open(outfile);
            myfile << setiosflags(ios::showpoint | ios::uppercase);
            myfile << "        x:           u(x):           v_gen:           v_spec:  " << endl;
            for (int i=0;i<=n;i+=step_size) {
                myfile << setw(15) << setprecision(8) << x[i] << ",";
                myfile << setw(15) << setprecision(8) << u[i] << ",";
                myfile << setw(15) << setprecision(8) << v_general[i] << ",";
                myfile << setw(15) << setprecision(8) << v_special[i] << endl;
            }
            myfile.close();

        }

        ////////////////////////////////////////////////////////////////////////////////////
        ////                           Task (c) and task (d)                            ////
        ////////////////////////////////////////////////////////////////////////////////////
        if (strcmp(argv[2], "c") == 0)
        {
            /* Comparing CPU time of general algorithm with specialized algorithm */
            if (n_counter == 1) /* In order to not initialize file multiple time */
            {
                outfile = "../benchmarks/time_and_relative_error_" + to_string(exponent)+ ".txt";
                myfile.open(outfile);
                myfile << setiosflags(ios::showpoint | ios::uppercase);
                myfile << "       n:        t_gen:         t_spec:          eps_rel:  " << endl;
            }

            /* General tridiagonal algorithm */
            v_general[0] = v_general[n] = 0.0;
            start = clock();
            general_tridiag_solver(n,a,b,c,p,v_general);

            finish = clock();
            time_general = ((finish-start)/((double)CLOCKS_PER_SEC));

            /* Special tridiagonal algorithm */

            /* Initializing b and p again */
            source_term(n,h,x,p);
            b[0] = b[n] = 2; v_special[0] = v_special[n] = 0.0;
            for (int i=0; i<n+1; i++) b[i] = (i+1.0)/((double) i);
            start = clock();

            special_tridiag_solver(n,b,p,v_special);

            finish = clock();
            time_special = ((finish-start)/((double)CLOCKS_PER_SEC));

            /* Calculating relative error */
            double max_eps = relative_error(n,v_general,u,eps);

            /* Writing to file */
            myfile << setw(10) << n << ",";
            myfile << setw(15) << setprecision(8) << time_general << ",";
            myfile << setw(15) << setprecision(8) << time_special << ",";
            myfile << setw(15) << setprecision(8) << max_eps << endl;

            /* Close file when all different n values have been added */
            if (n_counter == exponent)
            {
                myfile.close();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////
        ////                                  Task (e)                                  ////
        ////////////////////////////////////////////////////////////////////////////////////
        // task e, with ludcmp, only need time calculation here, so nice
        if (strcmp(argv[2], "e") == 0)
        {
            if (n_counter == 1) /* In order to not initialize file multiple time */
            {
                outfile = "../benchmarks/LU_decomposition_" + to_string(exponent)+ ".txt";
                myfile.open(outfile);
                myfile << setiosflags(ios::showpoint | ios::uppercase);
                myfile << "       n:        t_ludcmp:  " << endl;
            }

            /* Creating matrix for LU-decomp solution */
            double **A_matrix = (double **) matrix(n,n,sizeof(double));

            /* Setting values into matrix, could reduce to one for loop if setting end points manually */
            for (int i=0; i<n; i++)
            {
                A_matrix[i][i] = 2.0;
            }
            for (int i=0; i<n-1; i++)
            {
                A_matrix[i+1][i] = -1.0;
                A_matrix[i][i+1] = -1.0;
            }

            start = clock();
            LU_decomp_solver(n,A_matrix,p);
            finish = clock();

            time_ludcmp = ((finish-start)/((double)CLOCKS_PER_SEC));

            /* Writing to file */
            myfile << setw(10) << n << ",";
            myfile << setw(15) << setprecision(8) << time_ludcmp << endl;

            /* Close file when all different n values have been added */
            if (n_counter == exponent)
            {
                myfile.close();
            }

        }

        /* Freeing memory */
        delete []a; delete []b; delete[]c; delete[]p; delete[]v_general; delete[]v_special; delete[]u; delete[]eps; delete[]x;

    }
    return 0;
}
