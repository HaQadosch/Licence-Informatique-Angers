#include "ClasseBases.hh"

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
