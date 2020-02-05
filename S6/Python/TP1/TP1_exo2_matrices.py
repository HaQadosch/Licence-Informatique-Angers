import numpy as np

numExo=1 #exercice 1#
ident=np.identity(9)

print("\n"+str(numExo)+": \n"+str(ident))

numExo+=1 #exercice 2#
uns=np.ones((10,10))

print("\n"+str(numExo)+": \n"+str(uns))

numExo+=1 #exercice 3#
print("\n"+str(numExo)+": "+str(np.size(uns)))

numExo+=1 #exercice 4#
print("\n"+str(numExo)+": "+str(np.shape(uns)))


numExo+=1 #exercice 5#

numExo+=1 #exercice 6#
arr=np.arange(0,9)
arr2D=np.reshape(arr,(3,3))

print("\n"+str(numExo)+": \n"+str(arr2D))

numExo+=1 #exercice 7#
A=np.reshape(np.arange(0.01,1.001,0.01),(10,10))

print("\n"+str(numExo)+": \n"+str(A))

numExo+=1 #exercice 8#
B=A[6:,:4]

print("\n"+str(numExo)+": \n"+str(B))

numExo+=1 #exercice 9#
unsTB=np.ones(np.shape(B)) #size creee un array

print("\n"+str(numExo)+": \n"+str(unsTB))

numExo+=1 #exercice 10#
C=A[2:4,[0,2,4,6]]

print("\n"+str(numExo)+": \n"+str(C))

numExo+=1 #exercice 11#
prodCB=C.dot(B)

print("\n"+str(numExo)+": \n"+str(prodCB))

numExo+=1 #exercice 12#
val=A[A==0.55]

print("\n"+str(numExo)+": "+str(val))

numExo+=1 #exercice 13#
col4=A[:,3]

print("\n"+str(numExo)+": "+str(col4))

numExo+=1 #exercice 14#
l4=A[3,:]

print("\n"+str(numExo)+": "+str(l4))

numExo+=1 #exercice 15#
sup05=A[A[:,4]>0.5]

print("\n"+str(numExo)+": \n"+str(sup05))

numExo+=1 #exercice 16#

print("\n"+str(numExo)+": "+str(A.mean()))

numExo+=1 #exercice 17#

print("\n"+str(numExo)+": "+str(np.mean(A,1)))

numExo+=1 #exercice 18#

print("\n"+str(numExo)+": "+str(np.mean(A,0)))

numExo+=1 #exercice 19#
prodScal=A[:,0]*A[0,:]

print("\n"+str(numExo)+": "+str(prodScal))

numExo+=1 #exercice 20#
A[3:7,3:7]=A[3:7,3:7]*np.zeros((4,4))

print("\n"+str(numExo)+": \n"+str(A))

numExo+=1 #exercice 21#
indices=np.where(A==0)

print("\n"+str(numExo)+": "+str(indices))
