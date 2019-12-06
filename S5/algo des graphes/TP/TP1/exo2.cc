#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>

using Sommet=unsigned int;

struct Graphe{
	bool estOriente;
	std::vector<std::vector<Sommet>> matAdjac;
};

void ajoutArete(Graphe &g,std::string l){
	//lecture de la ligne
	int numligne(0);
	int numcolonne(0);
	unsigned int carac(2);//position du caractere
	std::string numero("");
	//parcours du premier nombre
	while(l[carac]!=' '){
		numero=numero+l[carac];
		carac++;
	}
	numligne=stoi(numero);//conversion de celui-ci en nombre
	//accés au 2nd nombre
	while(l[carac]==' ') carac++;
	//parcours du 2nd nombre
	while(l[carac]!=' '){
		numero.clear();
		numero=numero+l[carac];
		carac++;
	}
	numcolonne=stoi(numero);//conversion de celui-ci en nombre
	//accés au 2nd nombre
	while(l[carac]==' ') carac++;
	//parcours du 2nd nombre
	while(carac<l.size()){
		numero.clear();
		numero=numero+l[carac];
		carac++;
	}
	g.matAdjac[numligne][numcolonne]=stoi(numero);//conversion de celui-ci en nombre
}

Graphe Charger(std::string nomFic){
	std::ifstream fichier(nomFic);
	std::string ligne;
	Graphe nouv;
	//parcours du fichier et chargement
	while(std::getline(fichier,ligne)){
		if(ligne[1]!='c'){ // lecture que s'il ne s'agit pas d'un commentaire
			switch(ligne[0]){
				//cas ou il s'agit d'un indicateur d'orientation
				case('o'):{
					if(ligne=="o go") nouv.estOriente=true;
					else nouv.estOriente=false;
				break;}
				//cas ou il s'agit d'un indicateur de nb sommets
				case('v'):{
					ligne.substr(2);
					Sommet max=std::stoi(ligne.substr(2));
					std::vector<std::vector<Sommet>> mat(max,std::vector<Sommet>(max));
					nouv.matAdjac=mat;
				break;}
				//cas ou il s'agit d'un arc/arete
				case('e'):{
					ajoutArete(nouv,ligne);
				break;}
			}
		}
	}
	return nouv;
}

void afficheGraphe(Graphe g){
	for(unsigned int i=0;i<g.matAdjac.size();i++){
		for(unsigned int j=0;j<g.matAdjac.size();j++){
			std::cout<<g.matAdjac[i][j];
		}
		std::cout<<std::endl;
	}
}

int main(){
	Graphe test=Charger("truc.txt");
	if(test.estOriente) std::cout<<"réussite"<<std::endl;
	afficheGraphe(test);
	return 0;
}
