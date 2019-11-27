//#include "Pieces.hh"
#include "Biblio.hh"
#include <iostream>
#include <string>
#include <sstream>

int main(int argc,char * argv[]){
 	//en fonction du num d'exercice, on change l'execution
 	if(argc!=2){
		std::cout<<"utilisation:"<<std::endl;
		std::cout<<"./exe [numero de la partie du TP à tester]"<<std::endl;
	}else{
		switch(std::stoi(argv[1])){

			case(1): { // Partie 1 du TP
			break;}

			case(2):{ // partie 2 du TP
				Document *d = new Periodique("titre","auteur",120,30);
				std::cout<< (*d) <<std::endl;
				delete(*d);

				Bibliotheque b;
				b.ajout(Periodique("t","a",100,5));
				// !!! ne pas "montrer" (get&set) les pointeurs sinon on peut les delete
				// b.contenu().push_back(nullptr);
				for(std::size_t i=0;i<b.taille();i++){
					std::cout << b.acces(i) << std::endl;
				}

        	break;}

      		case(3):{ // partie 3 du TP
        	break;}

      		case(4):{ // partie 4 du TP
			break;}


      		default:{ // cas erreur
        		std::cout<<"entrez le numero d'un exercice existant"<<std::endl;
        	break;}
		}//fin switch-case
	}//fin else
	return 0;
}
