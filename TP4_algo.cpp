#include <iostream>
#include <cstdlib>
#include <array>

const int TMAX=200;
char pile [TMAX]; 
int sommet;

void initpile(){
	sommet=-1;
}

void empiler(char c){
	if(sommet<TMAX-1){
		sommet++;
		pile[sommet]=c;	
	}
}

void depiler(char *c){
	if(sommet>=0){
		*c=pile[sommet];
		sommet--;	
	}
}

int pilevide(){
	return(sommet==-1);
}


int main(){
}
