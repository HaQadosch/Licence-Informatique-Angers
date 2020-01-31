numExo=1 #exercice 1#
liste1=list(range(1,100))

print("\n"+str(numExo)+": "+str(liste1))

numExo+=1 #exercice 2#
liste2=[]
for i in range (100,200):
	liste2.append(i)

print("\n"+str(numExo)+": "+str(liste2))

numExo+=1 #exercice 3#
liste1+=liste2

print("\n"+str(numExo)+": "+str(liste1))

numExo+=1 #exercice 4#
liste1.reverse()

print("\n"+str(numExo)+": "+str(liste1))

numExo+=1 #exercice 5#
#en modifiant :
liste1.sort()
print("\n"+str(numExo)+" (modified): "+str(liste2))
liste1.reverse()

#sans la modifier:
print ("\n"+str(numExo)+ "(not modified): "+ str(list(reversed(liste1))))

numExo+=1 #exercice 6#
liste3=list(range(0,101,2))

print("\n"+str(numExo)+": "+str(liste3))

numExo+=1 #exercice 7#
for i in liste3 :
	if i%10==0:
		liste3.remove(i)

print("\n"+str(numExo)+": "+str(liste3))

numExo+=1 #exercice 8#
print("\n"+str(numExo)+": la liste 3 est de longueur "+str(len(liste3)))

numExo+=1 #exercice 9#
print("\n"+str(numExo)+": "+str([i for i in liste3 if i%8==0]))

numExo+=1 #exercice 10#
print("\n"+str(numExo)+": "+str(liste3[:20]))

numExo+=1 #exercice 11#
print("\n"+str(numExo)+": "+str(liste3[20:]))

numExo+=1 #exercice 12#
print("\n"+str(numExo)+": "+str(liste3[-10:]))

numExo+=1 #exercice 13#
liste4=[i for i in range(1,100) if i%3==0]

print("\n"+str(numExo)+": "+str(liste4))

numExo+=1 #exercice 14#
liste5=[0,1]
for taille in range(20) :
	liste5.append(liste5[len(liste5)-1]+liste5[len(liste5)-2])

print("\n"+str(numExo)+": "+str(liste5))

numExo+=1 #exercice 15#
def MaFonctionCallBack(callback, liste):
	result=[]
	for element in liste :
		result.append(callback(element))
	return result

def CarrePair(x):
	return ((x*x)%2==0)

print("\n"+str(numExo)+": "+str(MaFonctionCallBack(CarrePair,liste4)))

numExo+=1 #exercice 16#
def MaFonctionCallbackIsBack(callback, liste):
	result=[]
	for element in liste :
		if(callback(element)): result.append(element)
	return result

def EstPair(x) :
	return(x%2==0)

print("\n"+str(numExo)+": "+str(MaFonctionCallbackIsBack(EstPair,liste4)))

numExo+=1 #exercice 17#
def MaFonctionCallbackIsBackTwice(callback,liste):
	if len(liste)==0 : return None #cas d'erreur
	elif len(liste)==1 : return liste[0]
	else : return callback(liste[0],MaFonctionCallbackIsBackTwice(callback,liste[1:]))

def Somme(x,y): return x+y

print("\n"+str(numExo)+": "+str(MaFonctionCallbackIsBackTwice(Somme,liste4)))

numExo+=1 #exercice 18#
def Moyenne(liste):
	total=0
	for elem in liste:
		total=total+elem
	return (total/len(liste))

def MinMaxMoy(listeInt):
	return [min(listeInt),max(listeInt),Moyenne(listeInt)]

fic=open("minMaxMoy.txt","w")
fic.write(str(MinMaxMoy([10,18,14,20,12,16])))
fic.close()

print("\n"+str(numExo)+": voir le fichier minMaxMoy.txt")

numExo+=1 #exercice 19#
liste6=[1,2,3]
liste6bis=liste6[:]
liste6.append(44) #test pour verifier si 44 est ajouté à la liste6bis

print("\n"+str(numExo)+": "+ str(liste6bis))
