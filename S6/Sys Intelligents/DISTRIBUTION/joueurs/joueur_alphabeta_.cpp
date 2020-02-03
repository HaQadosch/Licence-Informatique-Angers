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
//		std::cout<<"OH!"<<std::endl;
		return -1;
	}
	int v=-1000;
	for(int etatSuiv=etatTemp,i=0;i<jeu.nb_coups()-1;i++){// A RETRAVAILLER
//		std::cout<<"check e2"<<std::endl;
		etatSuiv=jeu[i]; // ou jeu.etat()
		jeu.joue(i);
//		std::cout<<"check e2.3"<<std::endl;
		v=max(v,eval_A(etatSuiv,bestE,bestA,jeu));
//		std::cout<<"check e3"<<std::endl;
		if(v>bestA){return v;}
//		std::cout<<"check e48"<<std::endl;
		bestE=max(v,bestA);
	}
	return v;
}

int Joueur_AlphaBeta_::eval_A(int etatTemp,int bestE,int bestA,Jeu jeu){
	//condition de victoire
	if(etatTemp==0){
	//	std::cout<<"OH!"<<std::endl;
		return 1;
	}
//	std::cout<<"check a1"<<std::endl;
	int v=+1000;
	for(int etatSuiv=etatTemp, i=0;i<jeu.nb_coups()-1;i++){ // A RETRAVAILLER s est l'etat du prochain coup
		//std::cout<<"check a2"<<std::endl;
		etatSuiv=jeu[i];
		jeu.joue(i);
		//std::cout<<"check a2.3"<<std::endl;
		v=min(v,eval_E(etatSuiv,bestE,bestA,jeu));
		//std::cout<<"check a3"<<std::endl;
		if(v>bestA){return v;}
		//std::cout<<"check a48"<<std::endl;
		bestA=min(v,bestE);
	}
	return v;
}

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
	int etatTemp = jeu.etat();
	coup=eval_E(etatTemp,-1000,+1000,jeu);
}
