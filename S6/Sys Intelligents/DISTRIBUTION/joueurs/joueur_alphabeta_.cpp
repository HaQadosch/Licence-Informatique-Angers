#include "joueur_alphabeta_.h"


Joueur_AlphaBeta_::Joueur_AlphaBeta_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_AlphaBeta_::nom_abbrege() const
{
    return 'A';
}

int Joueur_AlphaBeta_::eval_E(int etatTemp,int bestE,int bestA,Jeu jeu){
	//condition de défaite
	if(etatTemp==0){
		return -1;
	}
	int v=-1000;
	for(int suiv=etatTemp,i=0;i<jeu.nb_coups();i++){// A RETRAVAILLER
		suiv=jeu[i];
		v=max(v,eval_A(suiv,bestE,bestA,jeu));
		if(v>bestA){return v;}
		bestE=max(v,bestA);
	}
	return v;
}

int Joueur_AlphaBeta_::eval_A(int etatTemp,int bestE,int bestA,Jeu jeu){
	//condition de victoire
	if(etatTemp==0){
		return 1;
	}
	int v=+1000;
	for(int suiv=etatTemp, i=0;i<jeu.nb_coups();i++){ // A RETRAVAILLER s est l'etat du prochain coup
		suiv=jeu[i];
		v=min(v,eval_A(suiv,bestE,bestA,jeu));
		if(v>bestA){return v;}
		bestA=min(v,bestE);
	}
	return v;
}

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
	int etatTemp = jeu.etat();
	coup=eval_E(etatTemp,-1000,+1000,jeu);
}
