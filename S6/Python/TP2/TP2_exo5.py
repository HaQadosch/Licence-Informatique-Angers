import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

numExo=1 #exercice 1#
DFwhitewine=pd.read_csv("whitewinePD.csv", sep = ";",index_col=0)
DFredwine=pd.read_csv("redwinePD.csv", sep = ";",index_col=0)

print("\n"+str(numExo)+": \n"+str(DFwhitewine))
print("\n"+str(DFredwine))

numExo+=1 #exercice 2#
DFwines=pd.concat([DFwhitewine,DFredwine])
DFwines=DFwines.sort_values(by="alcohol",ascending = False)
print("\n"+str(numExo)+": \n"+str(DFwines.head()))

numExo+=1 #exercice 3#
print("\n"+str(numExo)+": \n"+str(DFwines.loc[DFwines["quality"]>7,:]))

numExo+=1 #exercice 4#
ratioBlanc=(DFwhitewine["quality"]>7).value_counts(normalize=True)
ratioRouge=(DFredwine["quality"]>7).value_counts(normalize=True)
print("\n"+str(numExo)+": ratio blanc:\n"+str(ratioBlanc) +"\n ratio rouge: \n"+str(ratioRouge))


numExo+=1 #exercice 5#
df=pd.concat([DFwhitewine.loc[(DFwhitewine["alcohol"]<9)],DFredwine.loc[(DFredwine["alcohol"]<10)]])
df=df.loc[(df["quality"]>7)]

print("\n"+str(numExo)+": \n"+str(df[["alcohol","quality"]]))

numExo+=1 #exercice 6#
DFwines["quality"].value_counts().plot.pie()
plt.show()

numExo+=1 #exercice 7#
DFwines.plot.scatter(x="quality",y="alcohol")
plt.show()

numExo+=1 #exercice 8#
DFwines.plot.scatter(x="quality",y="alcohol",c="volatile acidity")
plt.show()

numExo+=1 #exercice 9#
DFwines.boxplot(column="alcohol",by="quality")
plt.show()

numExo+=1 #exercice 10#
DFwines.hist(column="alcohol")
plt.show()

numExo+=1 #exercice 11#
DFwines.hist(column="alcohol",by="quality")
plt.show()

numExo+=1 #exercice 12#
res=pd.crosstab(pd.cut(DFwines["alcohol"],10),DFwines["quality"])
print("\n"+str(numExo)+": \n"+str(res))
