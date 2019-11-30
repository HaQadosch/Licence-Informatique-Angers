#include "ClasseBases.hh"

type sharedVar(0); //les attributs de classes sont définies hors des blocs.
// il peut aussi être const.

//methode de classe.
bool Classe::comparaison(Classe const & c1, Classe const & c2)const{
	return c1.var>c2.var;
} // on l'appellera dans le main avec " bool test=Classe::comparaison(c1,c2);"
/* !!! si on défini une des 3 méthodes:
		- constructeur par recopie
		- destructeur
		- operator =
	alors on doit définir les 3 autres !!! ( sauf si on garde leur comportement par défaut)
	Cependant on essaye d'appliquer la règle des 0 sauf cas extreme
*/

void Classe::Classe (Classe const & c){ //constructeur par recopie
	var=c.var;
	if(c.ptr) //on évite le cas du nullptr
		ptr=new TypePtr(*c.ptr); // on créer un nouveau pointeur pour éviter qu'il pointe sur du bullshit si on supprime son créateur
}

void Classe::Classe (Classe const & c):
	var(c.var){// constructeur par recopie en liste d'initialisation
	if(c.ptr) //on évite le cas du nullptr
		ptr=new TypePtr(*c.ptr); // on créer un nouveau pointeur pour éviter qu'il pointe sur du bullshit si on supprime son créateur
}

Classe & Classe::operator=(Classe const & c){
	if(this!=c){ // copie que si different
		this.var=c.var;
		delete ptr;
		if(c.ptr){ // verifie si besoin de copier ou non, puis copie
			ptr=new TypePtr(*c.ptr);
		} else {
			ptr=nullptr;
		}
	}
	return *this;
}

std::ostream & operator <<(std::ostream & os, Classe const & c){
	os<< " la var est" << getVar(); // attention, utiliser les accesseurs, on est hors de la classe.
	return os;
}
