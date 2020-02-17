#include "joueur_alphabeta_.h"


Joueur_AlphaBeta_::Joueur_AlphaBeta_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_AlphaBeta_::nom_abbrege() const
{
    return 'A';
}

int Joueur_AlphaBeta_::alphaBeta(Jeu jeu, int &alpha, int &beta, bool est_Existentiel){
	//cas d'arret, feuille
	int v;
	if(jeu.fini()){
		if(est_Existentiel) // si arret durant le tour du joueur existentiel, défaite
			return -1;
		else return 1; // sinon, vitoire
	}
	else if(est_Existentiel){ // si joueur existentiel
		v=-1000;
		for(int i=0;jeu.coup_licite(i);i++){
			jeu.joue(i);
			v=std::max(v,alphaBeta(jeu,alpha,beta,false));
			if(beta<=v){return v;}
			alpha=std::max(alpha,v);
		}
	}
	else {
		v=1000;
		for(int i=0;jeu.coup_licite(i);i++){
			jeu.joue(i);
			v=std::min(v,alphaBeta(jeu,alpha,beta,true));
			if(alpha>=v){return v;}
			beta=std::min(beta,v);
		}
	}
	return v;
}

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
	int alpha=-1000;
	int beta=+1000;
	int v=-1000;
	Jeu backup=jeu;
	for(int i=0;jeu.coup_licite(i);i++){
		// faut rebosser le jeu qu'on transmet
		backup=jeu;
		std::cout<<"i="<<i;
		backup.joue(i);
		v=std::max(v,alphaBeta(backup,alpha,beta,false));
		if(beta<=v){coup=i;return;}
	}
}
