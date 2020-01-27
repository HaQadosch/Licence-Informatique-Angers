#include "joueur_alphabeta_.h"


Joueur_AlphaBeta_::Joueur_AlphaBeta_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_AlphaBeta_::nom_abbrege() const
{
    return 'A';
}

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
	int etatTemp = jeu.etat();
	//int coup = -2;
	int tour=1;
	int max(int a, int b){ return ((a>b)? a:b); }

	int eval_E(int etatTemp,int bestE,int bestA){
		if(etatTemp==0){
			return (tour%2)? 1:-1;
		}
		int v=-1000;
		for(int s : jeu.nb_coups()-1){
			v=max(v,eval_A(s,bestE,bestA))
			if(v>bestA){return v;}
			bestE=maximum(v,bestA);
		}
	}
}
