#include <stdlib.h>
#include <vector>
#include <iostream>
#include "vectrois.hh"

// saisie au clavier de valeurs qui seront retournées sous forme de vecteur
std::vector<int> Saisie_val(){
	std::vector<int> result; // creation du vecteur à retourner
	int max; // la quantité de nombres que contiendra le vecteur
	std::cout<<"entrez la quantité de nombres que vous voulez entrer"<<std::endl;
	std::cin>>max;
	std::cout<<"veuillez à présent entrer les nombres les uns aprés les autres"<<std::endl;
	//saisie des nombres dans le vecteur
	for(int i(0),temp;i<max;i++){
		std::cin>>temp;
		result.push_back(temp);
	}
	return result;
}

//retourne le plus grand nombre contenu dans le vecteur
int vMax(std::vector<int> v){
	int max(0); // initialise le plus grand nombre à 0
	//parcours du vecteur en gardant que le plus grand nombre
	for (auto i(v.begin());i!=v.end(); i++){
		if(max<*i) max=*i;
	}
	return max;
}
