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

// créé une roulette de taille taille
roulette creer_roulette(int taille){
	// creation de la roulette
	roulette rou;
	initialise_roulette(rou);
	// remplissage de la roulette:
	for(int i=1;i<taille;i++){ // parcours de la roulette
		ajout_numero(rou,i); // à chaque emplacement on ajout un element 
	}
	return rou;
}

// tourne la roulette d'un cran
void tourner_roulette(roulette &rou){
	// le pointeur de début devient l'élément suivant celui du début
	rou.debut=rou.debut->suivant;
}

// fait tourner la roulette d'un nombre aléatoire de crans
void lancer_roulette(roulette &rou){
	//initialisation du random
	srand(time(NULL));
	// choix d'un nombre aléatoire, variant de 1 à la taille du tableau 
	int nb_tour=rand()%rou.taille +1;
	
	// pour chaque tour ...
	for( int i=0; i<nb_tour ;i++){
		tourner_roulette(rou); // ... on fait tourner la roulette d'un cran	
	}
}

// creation d'une fonction d'affichage, pour tester l'exo
void affiche_roulette( roulette rou){
	// creation d'un maillon de parcours
	maillon * cur=new maillon;
	(*cur).value=0;
	(*cur).suivant=rou.debut;// on fait pointer ce maillon sur le début
	
	// on parcours la roulette avec le maillon
	for(int i=0;i<rou.taille;i++){
		std::cout<<(*cur).suivant->value<<" | "; // on affiche la valeur du maillon sur lequel il pointe
		(*cur).suivant=(*cur).suivant->suivant; // il pointe sur le maillon suivant
	}
	std::cout<<std::endl; // saute de ligne pour confort d'affichage

}

int main(){
	// test creation de roulette
	roulette rou=creer_roulette(5);
	affiche_roulette(rou);
	// test tourner la roulette d'un cran
	tourner_roulette(rou);
	affiche_roulette(rou);
	// test tourner la roulette d'un nombre aléatoire de crans
	lancer_roulette(rou);
	affiche_roulette(rou);
	return 0;
}
