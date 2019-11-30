#include "ClassePolymorphisme.hh"


std::string Classe1::quiSuisJe() const override{
	return nom;
}

std::string Classe1::quiSuisJe() const override{
	return prenom;
}

void Polym::Polym(Polym const & c){
	for(auto cc:c.done) // parcours des membres du vecteur de c
		done.push_back(cc->clone()); // ajout de ceux-ci 1 par 1 dans le nouveau
}

//redéfinition du destructeur
void Polym::~Polym(){
	for (auto c : done)//parcours du vecteur de pointeur
		delete c; // destruction de chaque pointeur du vecteur
}

void Polym::afficheSiTop(int truc)const{
	for (auto c : _prod) { // parcours du vecteur
		auto cc = dynamic_cast <Classe2 const*>(c); /*
		dynamic_cast permet d'identifier les sous-classe d'un pointeur de superClasse (donc ici, distinguer Classe1 de Classe2)
		retourne nullptr si la conversion n'est pas possible (donc si l'element actuel n'est pas celui demandé)
		*/
		if (cc != nullptr) // verification que la conversion est une réussite (donc que l'element actuelle est bien classe2
			cc->JeSuisTop(truc);
	}
}

void Polym::ajouterClasse(Generale const & c){
	//appel du constructeur spécifique pour retourner la sous-classé précisément
	done.push_back(c.clone());
}

//comportement par défaut
void Generale::sortie(std::ostream & os) const{
	os<<var1<<var2;;
}
//redefinition & ajout
void Classe1::sortie(std::ostream & os) const{
	Generale::sortie(os);
	os<<nom;
}
void Classe2::sortie(std::ostream & os) const{
	Generale::sortie(os);
	os<<prenom;
}

//modification de l'operateur, qui à un comportement différent en fonction de la classe
std::ostream & operator <<(std::ostream & os, Polym const & c) {
	for (auto p : c.done) //parcours du vecteur
		p->sortie(os);
		return os;
}
//pour éviter une erreur si on l'appelle avec Generale, on la redéfinie aussi dessus.
std::ostream & operator <<(std::ostream & os, Generale const & c) {
	c.sortie(os);
	return os;
}
