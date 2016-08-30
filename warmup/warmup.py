from numpy import arctan, log, linspace, sqrt
import matplotlib.pyplot as plt
import os

def f(x):
    return arctan(x)

def f2c(x, h):
    if isinstance(h, int):
        h = float(h)
    return (f(x + h) - f(x))/h

def f3c(x, h):
    return (f(x + h) - f(x - h))/(2.0*h)

fx = 1/3.

h1_exp = linspace(-20,1)
h1 = 10**h1_exp

eps2c = f2c(sqrt(2), h1)
eps3c = f3c(sqrt(2), h1)

currdir = os.getcwd() + "/"
with open(currdir+"data/ex2.txt", 'w') as outfile:
    outfile.write("step-length, eps2c, eps3c\n")
    for i in range(len(h1)):
        string_h = str(h1[i]) + ", "
        string_2c = str(eps2c[i]) + ", "
        string_3c = str(eps3c[i]) + '\n'
        string = string_h + string_2c + string_3c
        outfile.write(string)


e2c = log(abs((eps2c - fx)/(fx)))
e3c = log(abs((eps3c - fx)/(fx)))

plt.plot(h1, e2c, label = 'Two-point')
plt.plot(h1, e3c, '-r', label = 'Three-point')
plt.xlabel('logaritmic h')
plt.ylabel('I AM ERROR')
plt.legend()
plt.xscale('log')
plt.show()

