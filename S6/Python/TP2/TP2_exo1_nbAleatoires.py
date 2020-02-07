import numpy as np

#exercice 6#
np.random.seed(42)

numExo=1 #exercice 1#
ranarr=(np.random.rand(10)*100).round()

print("\n"+str(numExo)+": "+str(ranarr))

numExo+=1 #exercice 2#
ran100=np.random.randint(0,high=100,size=100)

print("\n"+str(numExo)+": "+str(ran100))

numExo+=1 #exercice 3#
rannor=np.random.normal(25)
print("\n"+str(numExo)+": "+str(rannor))

numExo+=1 #exercice 4#
ranuni=np.random.uniform(size=25)
print("\n"+str(numExo)+": "+str(ranuni))

numExo+=1 #exercice 5#
ran2D=(np.random.rand(10,10)*100).round()
print("\n"+str(numExo)+": "+str(ran2D))
