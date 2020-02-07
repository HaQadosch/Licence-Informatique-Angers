import csv
#matrice a sauvegarder
import numpy as np
matrice=(np.random.rand(10,10)*100).round()

#ecriture dans le fichier
with open("matrice1.csv","w") as csvfile:
	file=csv.writer(csvfile,delimiter=";")
	for row in matrice:
		file.writerow(row)
csvfile.close()

#lecture du fichier
with open("matrice1.csv","r") as csvfile:
	file=csv.reader(csvfile,delimiter=";")
	for row in file:
		print(row)
csvfile.close()
