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
	(*mai1).value=0;
	(*mai1).suivant=NULL;
	rou.taille=1;
	rou.debut=mai1;
}

int main(){
	
	roulette rou;
	initialise_roulette(rou);
	std::cout<<rou.debut->value<<' '<<rou.taille;
	return 0;
}
