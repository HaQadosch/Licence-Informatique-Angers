#include "vSequence.hh"
#include <vector>
#include <iostream>
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

//retourne la couleur au numero indiqué
couleur Sequence::acces(indiceSequence const ind){
  return couleurs[ind];
}

//ajoute la couleur en paramètre à la fin de la liste
void Sequence::ajouter(couleur coul){
	couleurs.push_back(coul);
}

//destructeur
Sequence::~Sequence(){
  couleurs.clear();
}

//copie de la séquence en paramètre dans la séquence
void Sequence::copier(Sequence & s){
    couleurs=s.getCouleurs();
}

//constructeur par recopie
Sequence::Sequence(Sequence &s){
  copier(s);
}

//affiche la couleur prise en paramètre
void Sequence::afficher(couleur coul){
  switch(coul){
    case(couleur::rouge):{
      std::cout<<"rouge ";
    break;}
    case(couleur::jaune):{
      std::cout<<"jaune ";
    break;}
    case(couleur::vert):{
      std::cout<<"vert ";
    break;}
    case(couleur::bleu):{
      std::cout<<"bleu ";
    break;}
  }
}

//affiche la séquence sur le flux pris en paramètre
void Sequence::afficher(std::ostream & out){
  for(auto i : couleurs){ // parcours de la séquence
    switch(i){ // affiche la couleur actuelle
      case(couleur::rouge):{
        out<<"rouge ";
      break;}
      case(couleur::jaune):{
        out<<"jaune ";
      break;}
      case(couleur::vert):{
        out<<"vert ";
      break;}
      case(couleur::bleu):{
        out<<"bleu ";
      break;}
    }
  }
  out<<std::endl;
}

//vide la liste de couleurs de la séquence
void Sequence::vider(){
  couleurs.clear();
}
// retourne true si les séquences sont identiques, false sinon
bool Sequence::comparer(Sequence & s){
  if(this->getTaille()!=s.getTaille()) return false; // pas besoin d'aller plus loin si elles sont de taille différentes
  if(couleurs!=s.getCouleurs()) return false;
  return true; // si elles ne sont pas différentes, elles sont identiques
}
