#include <iostream>
#include <cstdlib>
#include <time.h>
#include <array>

//DEFINITION DES STRUCTURES

struct noeud;
struct noeud{
	noeud * abG;
	noeud * abD;
	int val;
};

using ABR = noeud*;

// initialisation de l'arbre en lui attribuant les valeurs prisent en paramètre
void init_abr(ABR &abr, ABR abG, ABR abD, int val){
	abr->abG=abG;
	abr->abD=abD;
	abr->val=val;

}
// ajout un entier en bout de branche
void AjoutFeuille(ABR &abr, int i){
	//creation de l'arbre ajouté
	ABR current=new noeud;
	init_abr(current,NULL,NULL,i);
	// insére à droite si la valeur est supérieur à l'arbre actuel
	if(i> abr->val){
		if(abr->abD==NULL) abr->abD=current;
		else AjoutFeuille(abr->abD,i);
	}
	// insére à gauche si la valeur est égale ou inférieur à l'arbre actuel
	else if(i<=current->val){
		if(abr->abG==NULL) abr->abG=current;
		else AjoutFeuille(abr->abG,i);			
	}
	// cas d'erreur 
	else std::cout<<" ERREUR dans l'ajout feuille";
	
}

//affiche l'arbre pris en paramètre
void affiche_abr(ABR arbre){
	// parcours infixe, donc affichage aprés parcours gauche et avant parcours droit
	if(arbre!=NULL){
		if(arbre->abG!=NULL) affiche_abr(arbre->abG);
		std::cout<<"|"<<arbre->val;
		if(arbre->abD!=NULL) affiche_abr(arbre->abD);
	}
}

ABR cherche_int(ABR &abr, int i){

	if(i==abr->val){
		return abr;
	}
	// cherche à droite si la valeur est supérieur à l'arbre actuel
	if(i> abr->val){
		if(abr->abD!=NULL) cherche_int(abr->abD,i);
	}
	// cherche à gauche si la valeur est inférieur à l'arbre actuel
	if(i<abr->val){
		if(abr->abG!=NULL) cherche_int(abr->abG,i);
	}
	// cas d'erreur et cas NULL
	else std::cout<<" ERREUR dans l'ajout feuille";
	return NULL;
} 

ABR max(ABR abr){
	if(abr->abD!=NULL) return max(abr->abD);
	return abr;
}

void supp_int(ABR &abr, int supp){
	ABR arbre=cherche_int(abr,supp);
	if(arbre==NULL);
	else{
			
			
			
	}
}

int main(){
	// creation de l'arbre
	ABR test=new noeud;
	init_abr(test,NULL,NULL,5);
	AjoutFeuille(test,6);
	AjoutFeuille(test,4);
	AjoutFeuille(test,1);
	AjoutFeuille(test,8);
	AjoutFeuille(test,6);
	AjoutFeuille(test,9);
	// affichage
	affiche_abr(test);
	std::cout<<"|"<<std::endl;
	return 0;
}
