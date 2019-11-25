#include "Pieces.hh"
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
