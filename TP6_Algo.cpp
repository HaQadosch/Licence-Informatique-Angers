#include <iostream>
#include <cstdlib>
#include <time.h>

struct maillon{
   int value; // valeur stockée dans le maillon
   maillon * suivant; // maillon suivant 
};

struct roulette{
  int taille; // nombre de maillons composant la roulette
  maillon * debut; // pointeur vers le premier maillon
};

//initialise la roulette avec un maillon 0
void initialise_roulette(roulette &rou){
	// creation d'un maillon de valeur 0
	maillon * mai1=new maillon;
	(*mai1).value=0;
	(*mai1).suivant=NULL;
	//mise à jour de la taille de la roulette
	rou.taille=1;
	//ajout du maillon à la roulette
	rou.debut=mai1;
}

// ajoute un element de valeur num à la roulette rou
void ajout_numero(roulette &rou, int num){
	//creation d'un maillon de valeur num
	maillon * mai=new maillon;
	(*mai).value=num;
	// le maillon suivant du nouveau maillon correspond à son futur précédant
	(*mai).suivant=rou.debut;
	// on le fait pointer sur le dernier élément de la liste
	for(int i=1;i<rou.taille;i++){
		(*mai).suivant=(*mai).suivant->suivant;	
	}
	// le maillon suivant le dernier est le nouveau maillon
	(*mai).suivant->suivant=mai;
	// le nouveau maillon est le nouveau dernier maillon et pointe donc sur le premier maillon
	(*mai).suivant=rou.debut;

	//mise à jour de la taille de la roulette
	rou.taille++;

}

roulette creer_roulette(int taille){
	roulette rou;
	initialise_roulette(rou);
	for(int i=1;i<taille;i++){
		ajout_numero(rou,i);	
	}
	return rou;
}

void tourner_roulette(roulette &rou){
	rou.debut=rou.debut->suivant;
}

void lancer_roulette(roulette &rou){
	//initialisation du random
	srand(time(NULL));
	// choix d'un nombre aléatoire, de 1 à la taille du tableau 
	int nb_tour=rand()%rou.taille +1;
	
	for( int i=0; i<nb_tour ;i++){
		rou.debut=rou.debut->suivant;	
	}
}

// creation d'une fonction d'affichage, pour tester l'exo
void affiche_roulette( roulette rou){
	maillon * cur=new maillon;
	(*cur).value=0;
	(*cur).suivant=rou.debut;
	for(int i=0;i<rou.taille;i++){
		std::cout<<(*cur).suivant->value<<" | ";
		(*cur).suivant=(*cur).suivant->suivant;
	}
	std::cout<<std::endl;

}

int main(){
	
	roulette rou=creer_roulette(5);
	affiche_roulette(rou);
	tourner_roulette(rou);
	affiche_roulette(rou);
	lancer_roulette(rou);
	affiche_roulette(rou);
	return 0;
}
