import numpy as np
import matplotlib.pyplot as plt

#exercice 1#
np.random.seed(42)

numExo=2#exercice 2#
truc=np.random.randn(500)

print("\n"+str(numExo)+": \n"+str(truc))


numExo+=1#exercice 3#
sig=15
mu=100
fx=(truc*sig+mu)

print("\n"+str(numExo)+": \n"+str(fx))

numExo+=1#exercice 4-7#
_,bins=plt.hist(fx,bins=50)
plt.xlabel("Quotient intellectuel")
plt.ylabel("Probabilite de densite")
plt.title("exo numero "+str(numExo))
plt.grid()
plt.show()

numExo=8#exercice 8#
def y(x):
	return(1/(sig*np.sqrt(2*np.pi)))*np.exp((-(1/2)*((x-mu)/sig))**2)

numExo+=1#exercice 9
plt.plot(bins,y(bins),"g--")
plt.title("Histogramme de la repartition du QI: mu=100, sigma=15")
plt.show()
