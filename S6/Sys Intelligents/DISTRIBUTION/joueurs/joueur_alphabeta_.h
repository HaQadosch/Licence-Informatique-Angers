#pragma once
#include "joueur.h"


class Joueur_AlphaBeta_ : public Joueur
{
public:
  Joueur_AlphaBeta_(std::string nom, bool joueur);
  char nom_abbrege() const override;

  void recherche_coup(Jeu, int & coup) override;

  //methodes ajoutées
  int maxi(int a, int b){ return ((a>b)? a:b); }
  int mini(int a, int b){ return ((a<b)? a:b); }
  int alphaBeta(Jeu jeu, int &alpha, int &beta, bool est_Existentiel);
 // int eval_E(int etatTemp,int &bestE,int &bestA,Jeu jeu);
 // int eval_A(int etatTemp,int &bestE,int &bestA,Jeu jeu);
};
