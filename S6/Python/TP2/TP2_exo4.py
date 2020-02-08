import pandas as pd
import numpy as np

numExo=1 #exercice 1#
uns= np.ones((3,4))
y= ["A","B","C","D"]
x= ["i1","i2","i3"]
dfabcd= pd.DataFrame(data =uns, columns =y, index=x)

print("\n"+str(numExo)+": \n"+str(dfabcd))

numExo+=1 #exercice 2#
uns= np.ones((100,4))
y= ["p1","p2","p3","p4"]
#remplissage de x
x=["i1"]
for i in range(1,100):
	x.append("i"+str(i+1))

dfpi= pd.DataFrame(data =uns, columns =y, index=x)

print("\n"+str(numExo)+": \n"+str(dfpi))

numExo+=1 #exercice 3#
for i in range (0,100):
	dfpi["p2"][i]=(i+1)**2
	dfpi["p3"][i]=(i+1)**3
	dfpi["p4"][i]=(i+1)**4

print("\n"+str(numExo)+": \n"+str(dfpi))

numExo+=1 #exercice 4#

print("\n"+str(numExo)+": "+str(dfpi.shape))

numExo+=1 #exercice 5#

print("\n"+str(numExo)+": \n"+str(dfpi[:10]))

numExo+=1 #exercice 6#

print("\n"+str(numExo)+": \n"+str(dfpi[-10:]))

numExo+=1 #exercice 7#

print("\n"+str(numExo)+": "+str(dfpi.columns.values))

numExo+=1 #exercice 8#

print("\n"+str(numExo)+": "+str(dfpi.dtypes))

numExo+=2 #exercice 9 et 10#

print("\n"+str(dfpi.info()))

numExo+=1 #exercice 11#

print("\n"+str(numExo)+": \n"+str(dfpi["p4"]))
print("\n"+str(dfpi.p4))

numExo+=1 #exercice 12#

print("\n"+str(numExo)+": \n"+str(dfpi[["p1","p4"]]))

numExo+=1 #exercice 13#

print("\n"+str(numExo)+": \n"+str(dfpi["p4"].value_counts(bins=10)))


numExo+=1 #exercice 14#
def moyenne(x):
	return(x.mean())
print("\n"+str(numExo)+": \n"+str(dfpi.apply(moyenne,axis=1)))
print("\n"+str(dfpi.apply(moyenne,axis=0)))
