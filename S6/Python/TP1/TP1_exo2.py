numExo=1 #exercice 1#
import numpy as np

numExo+=1 #exercice 2#
arVide=np.empty(10)

print("\n"+str(numExo)+": "+str(arVide))

numExo+=1 #exercice 3#
arZeros=np.zeros(10)

print("\n"+str(numExo)+": "+str(arZeros))

numExo+=1 #exercice 4#
arOnes=np.ones(10)

print("\n"+str(numExo)+": "+str(arOnes))

numExo+=1 #exercice 5#
#premiere version
arFives=np.ones(10)*5
print("\n"+str(numExo)+": "+str(arFives))

#deuxieme version
arFivesBis=np.array([5]*10)
print(str(numExo)+" bis: "+str(arFivesBis))

numExo+=1 #exercice 6#
liste=[i for i in range(1,10)]
arStr=np.array(str(liste))

print("\n"+str(numExo)+": "+str(arStr)+" est de type"+str(type(arStr)))
