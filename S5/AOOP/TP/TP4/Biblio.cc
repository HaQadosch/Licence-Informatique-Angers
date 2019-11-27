#include "Biblio.hh"

Bibliotheque::~Bibliotheque(){
	for(auto i: contenu)
		delete i;
}

boid Bibliotheque::ajout(Document const & d){
	contenu.pushback(d.clone());
}
