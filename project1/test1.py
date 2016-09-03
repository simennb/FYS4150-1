import numpy as np
import matplotlib.pyplot as plt
import sys

def hermione(filename, variable1, variable2):
    """
    Function that automatically reads a file and
    makes a plot
    """

    filename = "%s.txt" %filename

    x = []
    y = []
    
    f = open(filename, "r")
    f.readline() #skips first line
    for line in f:
        data = line.split(',')
        data[-1] = ''.join(data[-1].split())
        data[-2] = ''.join(data[-2].split())
        x.append(float(data[int(variable1)]))
        y.append(float(data[int(variable2)]))

    return x, y

def harry_plotter(x, y):
    plt.plot(x, y, label = '%s' %sys.argv[6])
    plt.xlabel('%s' %sys.argv[4])
    plt.ylabel('%s' %sys.argv[5])
    plt.legend()
    plt.show()


if __name__ == '__main__':
    x, y = hermione(sys.argv[1], sys.argv[2], sys.argv[3])
    harry_plotter(x, y)
