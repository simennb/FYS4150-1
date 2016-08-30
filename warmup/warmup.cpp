/* Fancy program */

#include <stdio.h>      /* printf */
#include <math.h>       /* atan */

float f(float a)
{
  float r;
  r = atan(a);
  return r;
}

float f2c(float x, float h)
{
  float r;
  r = (f(x + h) - f(x))/h;
  return r;
}

float f3c(float x, float h)
{
  float r;
  r = (f(x+h) - f(x - h))/(2.0*h);
  return r;
}
