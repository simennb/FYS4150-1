from numpy import arctan, log, linspace, sqrt
import matplotlib as plt

def f(x):
    return arctan(x)

def f2c(x, h):
    return (f(x + h) - f(x))/h

def f3c(x, h):
    return (f(x + h) - f(x - h))/(2*h)

fx = 1/3.

h1 = linspace(-100,50)

eps2c = log(abs((f2c(sqrt(2), h1) - fx)/fx))


plt.plot(h1, eps2c)
plt.show()
