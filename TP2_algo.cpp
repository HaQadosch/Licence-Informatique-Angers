
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

struct elem{
	int val; // valeur de l'element
	elem * prec; // pointeur sur l'element qui le precede
	elem * suiv; // pointeur sur l'element qui suit 
};

struct liste{
	elem * tete; // point sur le debut de la liste
	elem * queue; // pointeur sur la fin de la liste
};
/* génére et retourne une liste vide */
liste creer_liste(){
	liste l;
	l.tete=NULL;
	l.queue=NULL;
	return l;
}
/* retourne vrai si la liste est vide, et faux si ne l'est pas */
bool test_liste_vide(liste l){
	return (l.tete==NULL);
}
/* A COMPLETER */ // ajoute le nombre pris en parametre à la liste 
void inser_elem_tete_liste(liste &l,int val){
	elem * e= new elem;
	e->val=val;	
	e->suiv=l.tete;
	e->prec=NULL;
	if(test_liste_vide(l)){
		l.queue=e;	
	} else l.tete->prec=e;
	l.tete=e;
}
/* affiche la liste , methode iterative*/
void aff_liste_it(liste l){
	if(test_liste_vide(l)){
		std::cout<<" ";	
	}
	else{
		for(elem * cur=l.tete; cur->suiv!=NULL; cur=cur->suiv){
			std::cout<<" "<<cur->val<<",";	
		}
	}
}


int main(){
	liste l=creer_liste();
	inser_elem_tete_liste(l,42);
	std::cout<<+
	aff_liste_it(l);
	return 0;
}
