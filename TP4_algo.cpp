#include <iostream>
#include <cstdlib>
#include <array>

const int TMAX=200;
using tab=std::array<char,TMAX>;

struct pile{
	tab pile; 
	int sommet;
};

void initpile(pile &p){
	p.sommet=-1;
}

void empiler(pile &p,char c){
	if(p.sommet<TMAX-1){
		p.sommet++;
		p.pile[p.sommet]=c;	
	}
}

char depiler(pile &p){
	char c;
	if(p.sommet>=0){
		c=p.pile[p.sommet];
		p.sommet--;
		return c;	
	}
}

int pilevide(pile &p){
	return(p.sommet==-1);
}



int main(){
}
