#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

struct elem{
	int val;
	elem * prec;
	elem * suiv;
};

struct liste{
	elem * tete;
	elem * queue;
};

liste creer_liste(){
	liste l;
	l.tete=NULL;
	l.queue=NULL;
	return l;
}

bool test_liste_vide(liste l){
	return (l.tete==NULL);
}

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
