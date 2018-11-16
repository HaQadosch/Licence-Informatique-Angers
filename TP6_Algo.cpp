#include <iostream>
#include <cstdlib>

struct maillon{
   int value;
   maillon * suivant;
};

struct roulette{
  int taille;
  maillon * debut; 
};

void initialise_roulette(roulette &rou){
	maillon * mai1=new maillon;
	(*mai1).value=2;
	(*mai1).suivant=NULL;
	rou.taille=1;
	rou.debut=mai1;
}

void ajout_numero(roulette &rou, int num){
	maillon * mai=new maillon;
	(*mai).value=num;
	(*mai).suivant=rou.debut;
	for(int i=1;i<rou.taille;i++){
		(*mai).suivant=(*mai).suivant->suivant;	
	}

	/*while((*mai).suivant->suivant!=NULL){
		(*mai).suivant=(*mai).suivant->suivant;
		std::cout<<"valeur dans boucle :"<<(*mai).suivant->value;
	}
	*/
	(*mai).suivant->suivant=mai;
	(*mai).suivant=NULL;
	
	rou.taille++;

}


// creation d'une fonction d'affichage, pour tester l'exo
void affiche_roulette( roulette rou){
	maillon * cur=new maillon;
	(*cur).value=0;
	(*cur).suivant=rou.debut;
	for(int i=0;i<rou.taille;i++){
		std::cout<<(*cur).suivant->value;
		(*cur).suivant=(*cur).suivant->suivant;
	}

}
int main(){
	
	roulette rou;
	initialise_roulette(rou);
	ajout_numero(rou,3);
	ajout_numero(rou,4);
	ajout_numero(rou,5);
	affiche_roulette(rou);
	return 0;
}
