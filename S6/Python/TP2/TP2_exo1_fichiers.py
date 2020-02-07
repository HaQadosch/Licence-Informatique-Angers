
#matrice a sauvegarder
import numpy as np
matrice=(np.random.rand(10,10)*100).round()

#ecriture dans le fichier
fichier = open("matrice1.csv", "a")
for l in range (1,10):
		for c in range(1,10):
			fichier.write(matrice[l][c])

fichier.close()
