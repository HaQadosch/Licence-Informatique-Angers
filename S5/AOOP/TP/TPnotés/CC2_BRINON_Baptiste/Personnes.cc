#include "Personnes.hh"

unsigned int Etudiant::id(0);

Etudiant::Etudiant(std::string const & n,Formation const & f):
	Personne(n),form(f){	
	id++;
	id=id;
}

void Enseignant::ajoutEnseignement(Enseignement e){
	enseigne.push_back(e);
}

void Personnel::ajoutFormation(Formation f){
	listeForm.push_back(f);
}
