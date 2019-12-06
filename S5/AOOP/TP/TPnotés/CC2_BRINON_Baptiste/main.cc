#include<iostream>
#include<string>
#include "Enseignement.hh"
#include "Personnes.hh"
#include "Universite.hh"
int main(){
	//test Enseignement
	Formation L3info1(Niveau::L3,"informatique");
	Enseignement cpp(L3info1,TypeEns::TP,"C++");
	Formation L3info2(Niveau::L3,"informatique");
	std::cout<<"1.1 -> "<<(L3info1==L3info2)<<std::endl;
	std::cout<<"2.L3 informatique -> "<<L3info1.tostring()<<std::endl;
	std::cout<<"3.L3 informatique : TP C++-> "<<cpp.tostring()<<std::endl;

	//test Personnes
	Etudiant billy("Billy",L3info1);
	std::cout<<"4.n°1 Billy L3 informatique-> "<<"n°"<<billy.getId()<<" "<<billy.getNom()<<" "<<billy.getForm().tostring()<<std::endl;

	Enseignant prof("LeC",Grade::Professeur);
	prof.ajoutEnseignement(cpp);
	bool test=(prof.getGrade()==Grade::Professeur);
	std::cout<<"5.grade";
	if(test) std::cout<<" OK";
	else std::cout<<" FAIL";
	std::cout<<std::endl;

	std::cout<<"6.L3 informatique : TP C++ -> "<<prof.getEnseignement(0).tostring()<<std::endl;
	// Cependant on ne teste pas le dépassement, ce qui est un problème :
		std::cout<<"6,5. cas d'erreur ? -> "<<prof.getEnseignement(1).tostring()<<std::endl;
/* PAS LE TEMPS POUR Q4 et Q5 */

	//test Universite

	return 0;
}
