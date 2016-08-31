/* Fancy program */

#include <stdio.h>      /* printf */
#include <math.h>       /* mathfunctions */
#include <iostream>     /* output */
#include <fstream>      /* output to file */
#include <iomanip>      /* pretty, pretty */

using namespace std;

int singleprec()
{
  float hstop, dfdx2, dfdx3, x, h;
  float fpluss, fnorm, fmin;
  x = sqrt(2);
  hstop = 1e-20;
  ofstream myfile;
  myfile.open("/home/eirik/Documents/Git/FYS4150/warmup/data/ex2cpp.txt");
  for (h = 1; h > hstop; h /= 10)
    { fpluss = atan(x + h);
      fnorm = atan(x);
      fmin = atan(x - h);
      dfdx2 = (fpluss - fnorm)/h;
      dfdx3 = (fpluss - fmin)/(2.0*h);
      cout << "dfdx2 = "<< setw(10) << dfdx2;
      cout << ", dfdx3 = "<< setw(10) << dfdx3;
      cout << ", h = "<< setw(10) << h << endl;
      myfile << "dfdx2 = "<< setw(10) << dfdx2 << ", ";
      myfile << ", dfdx3 = "<< setw(10) << dfdx3;
      myfile << ", h = "<< setw(10) << h << endl;
    }
  return 0;
}

int doubleprec()
{
  double hstop, dfdx2, dfdx3, x, h;
  double fpluss, fnorm, fmin;
  x = sqrt(2);
  hstop = 1e-20;
  ofstream myfile;
  myfile.open("/home/eirik/Documents/Git/FYS4150/warmup/data/ex2cpp.txt", std::ios_base::app);
  myfile << "\n";
  for (h = 1; h > hstop; h /= 10)
    { fpluss = atan(x + h);
      fnorm = atan(x);
      fmin = atan(x - h);
      dfdx2 = (fpluss - fnorm)/h;
      dfdx3 = (fpluss - fmin)/(2.0*h);
      cout << "dfdx2 = "<< setw(10) << dfdx2;
      cout << ", dfdx3 = "<< setw(10) << dfdx3;
      cout << ", h = "<< setw(10) << h << endl;
      myfile << "dfdx2 = "<< setw(10) << dfdx2 << ", ";
      myfile << ", dfdx3 = "<< setw(10) << dfdx3;
      myfile << ", h = "<< setw(10) << h << endl;
    }
  myfile.close();
  return 0;
}


  int main(int argn, char** argv)
  {
    remove("/home/eirik/Documents/Git/FYS4150/warmup/data/ex2cpp.txt");
    singleprec();
    cout << "\n";
    doubleprec();
    return 0;
  }
  
