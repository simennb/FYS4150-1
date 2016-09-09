import numpy as np
import matplotlib.pyplot as plt
import sys


class Rowling:
    def hermione(self, filename, variable1 = 0, variable2 = 1):
        """
        Function that automatically reads a file and
        makes a plot.
        The name? Because Hermione reads.
        """

        filename = "%s.txt" %filename

        x = []
        y = []
    
        f = open(filename, "r")
        f.readline() #skips first line
        for line in f:
            data = line.split(',')
            for j in range(1, len(data)):
                data[j] = ''.join(data[j].split())
            x.append(float(data[int(variable1)]))
            y.append(float(data[int(variable2)]))
        return x, y

    def harry_plotter(self, x, y, xlab = 'x', ylab='y'
                      , plotlab = 'This is your graf',
                      d=1):
        """
        The name? Because it's funny.
        """
        plt.plot(x, y, label = '%s' %plotlab)
        plt.xlabel('%s' %xlab)
        plt.ylabel('%s' %ylab)
        plt.legend(loc=d)
        plt.show()


if __name__ == '__main__':
    a = Rowling()
    x, y = a.hermione("ex2", 0, 1)
    a.harry_plotter(x, y)
