#include <iostream>
#include <cstdlib>
#include <array>
#include <math.h> 

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
	} else return(' ');
}

bool pilevide(pile &p){
	return(p.sommet==-1);
}

void initTP(pile &p){
	empiler(p,'2');
	empiler(p,'5');
	empiler(p,'+');
	empiler(p,'4');
	empiler(p,'5');
	empiler(p,'3');
	empiler(p,'+');
	empiler(p,'2');
	empiler(p,'^');
	empiler(p,'x');
	empiler(p,'R');
	empiler(p,'*');
}

float add(float a, float b){
	return(a+b);
}

float mult(float a, float b){
	return (a*b);
}

float racine(float x){
	return(sqrt(x));
}

float puiss(float a, float n){
	for (int i=0; i<n;i++){
		a=a*a;	
	}
	return a;
}

float calcul(float res,pile &p){
	char a;
	if(!pilevide(p)){
		std::cout<<res<<std::endl;
		a=depiler(p);
		if(a=='+'){
			res=add(res,calcul(res,p));
		}else if(a=='*'){
			res=mult(res,calcul(res,p));
		}else if(a=='R'){
			res=racine(calcul(res,p));
		}else if(a=='^'){
			res=puiss(res,calcul(res,p));
		}else res=(a-'0');
	}
	return (res);
}

int main(){
	pile p;
	initpile(p);
	initTP(p);
	float res=0.0;
	res=calcul(res,p);
	std::cout<<res<<std::endl;
}
