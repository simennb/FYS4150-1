from pylab import *
import numpy as np
rc('font',**{'family':'serif'}) 

for n in [10,100,1000,1000,10000]:
    
    filename = '../benchmarks/task_b_N_%d.txt' %n
    data = np.loadtxt(filename,delimiter=',',skiprows=1)

    x = data[:,0]
    u = data[:,1]
    v_gen = data[:,2]
    v_spec = data[:,3]

    xlim([0.0,1.0])
    plot(x,u,'b',linewidth=2.0,label='Exact')
    plot(x,v_gen,'r--',linewidth=2.0,label='Numerical')#label='General')
    #plot(x,v_spec,label='Special')
    
    title(r'$N = $%d'%n,size=16)
    xlabel(r'x',size=16)
    ylabel(r'Solution',size=16)
    legend(fontsize=15)
    grid('on')
    savefig('../figures/task_b_N_%d.png'%n)

    show()
