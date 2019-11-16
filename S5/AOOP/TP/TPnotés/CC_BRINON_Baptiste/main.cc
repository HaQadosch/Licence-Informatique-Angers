#include <iostream>
#include <stdlib.h>
#include "Horaire.hh"
#include "Message.hh"

int main(int argc,char * argv[]){
	Horaire testH(10,10,10);
	std::cout<<testH.toString()<<std::endl; // test affichage
	//test messages
	Message testM("victor");
	testM.ajoutDestinataire("pers1");
	testM.ajoutDestinataire("pers2");
	std::cout<<testM.getExpediteur()<<" à envoyer le message numero "<<std::to_string(testM.getId())<<" à "<<testM.getDestinataire(1)<<std::endl;
	//saut de la question 4
	//question 5 presque terminée, mais pas le temps de l'implémenter dans le main.



}
