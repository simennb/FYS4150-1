import numpy as np
import matplotlib.pyplot as plt
import sys


class Rowling:
    def hermione(self, filename, variable1 = 0, variable2 = 1):
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

    def harry_plotter(self, x, y, xlab = 'x', ylab='y'
                      , plotlab = 'This is your graf',
                      d=1):
        plt.plot(x, y, label = '%s' %plotlab)
        plt.xlabel('%s' %xlab)
        plt.ylabel('%s' %ylab)
        plt.legend(loc=d)
        plt.show()


if __name__ == '__main__':
    a = Rowling()
    x, y = a.hermione("ex2", 0, 1)
    a.harry_plotter(x, y)
