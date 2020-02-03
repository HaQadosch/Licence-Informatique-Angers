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

print("\n"+str(numExo)+": "+str(arStr))

numExo+=1 #exercice 7#
tab1=np.arange(1,10.1,0.5)

print("\n"+str(numExo)+": "+str(tab1))

numExo+=1 #exercice 8#
tab2=np.linspace(1,10,num=20)

print("\n"+str(numExo)+": "+str(tab2))

numExo+=1 #exercice 9#
tab3=np.arange(10,30)

print("\n"+str(numExo)+": "+str(tab3))

numExo+=1 #exercice 10#
somme=tab3.sum()

print("\n"+str(numExo)+": "+str(somme))

numExo+=1 #exercice 11#
sommecum=np.cumsum(tab3)

print("\n"+str(numExo)+": "+str(sommecum))

numExo+=1 #exercice 12#
moy=tab3.mean()

print("\n"+str(numExo)+": "+str(moy))

numExo+=1 #exercice 13#
prod=tab2*tab3

print("\n"+str(numExo)+": "+str(prod))

numExo+=1 #exercice 14#
tab3sup20=(tab3[tab3>20])

print("\n"+str(numExo)+": "+str(tab3sup20))

numExo+=1 #exercice 15#
selec=tab3[[1,5,10,15]]

print("\n"+str(numExo)+": "+str(selec))
