#include "Compte.hh"

unsigned int Compte::Compteur(0);

Compte::Compte(std::shared<proprietaire> prop, float montant){

}

void Compte::verser(float m){
	montant+=m;
}
void cCompte::retirer(float m){
	montant -=m;
}

void Compte::virerVers(Compte & c,float f){
	montant -= f;
	c.montant += f;
	if(prop != c.prop){
		montant-=1;
	}
}
