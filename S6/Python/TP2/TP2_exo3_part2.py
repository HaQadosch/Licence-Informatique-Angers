import numpy as np
from numpy import genfromtxt
import matplotlib.pyplot as plt

whiteWine=genfromtxt('whitewineNP.csv',delimiter=';')
redWine=genfromtxt('redwineNP.csv',delimiter=';')

#traitement redwine
redQual=redWine[:,11]
redDeg=redWine[:,10]
#moy=np.empty(9)
#for i in range(3,9):
#	moy[i]=np.mean(redDeg[i])
plt.scatter(redQual,redDeg)
#plt.scatter(redQual,moy,color="red")
plt.xlabel("qualite")
plt.ylabel("degre d'alcool")
plt.title("degre d'alcool en fonction de sa qualite")
plt.show()
