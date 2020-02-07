import matplotlib.pyplot as plt
import numpy as np

numExo=1 #exercice 1#
tab1=[1,4,8,9]
tab2=[12,25,34,78]
plt.scatter(tab1,tab2)
plt.title("exo numero "+str(numExo))
plt.show()

numExo+=1 #exercice 2#
val=np.random.randint(0,1000,1000)
plt.scatter(range(0,1000),val)
plt.title("exo numero "+str(numExo))
plt.show()

numExo+=1 #exercice 3#
plt.plot(tab1,tab2)
plt.title("exo numero "+str(numExo))
plt.show()

numExo+=1 #exercice 4#

plt.plot(range(0,100),np.random.randn(100))
plt.title("exo numero "+str(numExo))
plt.show()

#exercice 5 a 8#
fig=plt.figure()
ax=fig.add_axes([0.1, 0.1, 0.8, 0.8])
x=np.linspace(0,2,num=100)
ax.plot(x, x,label="lineaire")
ax.plot(x, x**2,label="quadratique")
ax.plot(x, x**3,label="cubique")
ax.legend()
ax.set_xlabel("abscisse")
ax.set_ylabel("ordonnee")
plt.title("Comparaison des fonctions lineaire,quadratique et cubique")

plt.show()


#exercice 9#
fig, axes = plt.subplots(nrows=1, ncols=3, figsize=(20,7))
x=np.linspace(0,2,num=100)
axes[0].plot(x, x,label="lineaire",color="blue")
axes[1].plot(x, x**2,label="quadratique",color="orange")
axes[2].plot(x, x**3,label="cubique",color="green")
for ax in axes:
	ax.legend()
	ax.set_xlabel("abscisse")
	ax.set_ylabel("ordonnee")
axes[0].set_title("lineaire")
axes[1].set_title("quadratique ")
axes[2].set_title("cubique")
plt.tight_layout()
plt.show()

numExo=11#exercice 11#
arrhist=np.random.randint(0,11,100)
plt.hist(arrhist)
plt.title("exo numero "+str(numExo))
plt.show()
