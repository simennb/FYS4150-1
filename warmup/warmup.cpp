/* Fancy program */

#include <stdio.h>      /* printf */
#include <math.h>       /* mathfunctions */
#include <iostream>     /* output */
#include <fstream>      /* output to file */

using namespace std;

int singleprec()
{
  float hstop, dfdx2, dfdx3, x, h;
  float fpluss, fnorm, fmin;
  x = sqrt(2);
  hstop = 1e-20;
  for (h = 1; h > hstop; h /= 10)
    { fpluss = atan(x + h);
      fnorm = atan(x);
      fmin = atan(x - h);
      dfdx2 = (fpluss - fnorm)/h;
      dfdx3 = (fpluss - fmin)/(2.0*h);
      cout << "dfdx2 = "<< dfdx2 << ", ";
      cout << "dfdx3 = "<< dfdx3 << ", ";
      cout << "h = "<< h << "\n";
    }
  return 0;
}

int doubleprec()
{
  double hstop, dfdx2, dfdx3, x, h;
  double fpluss, fnorm, fmin;
  x = sqrt(2);
  hstop = 1e-20;
  myfile.open("/home/eirik/Documents/Git/FYS4150/warmup/data/ex2cpp.txt");
  for (h = 1; h > hstop; h /= 10)
    { fpluss = atan(x + h);
      fnorm = atan(x);
      fmin = atan(x - h);
      dfdx2 = (fpluss - fnorm)/h;
      dfdx3 = (fpluss - fmin)/(2.0*h);
      cout << "dfdx2 = "<< dfdx2 << ", ";
      cout << "dfdx3 = "<< dfdx3 << ", ";
      cout << "h = "<< h << "\n";
      myfile << "dfdx2 = "<< dfdx2 << ", ";
      myfile << "dfdx3 = "<< dfdx3 << ", ";
      myfile << "h = "<< h << "\n";
    }
  return 0;
}


  int main(int argn, char** argv)
  {
    ofstream myfile;
    singleprec();
    cout << "\n";
    doubleprec();
    myfile.close();
    return 0;
  }
  
