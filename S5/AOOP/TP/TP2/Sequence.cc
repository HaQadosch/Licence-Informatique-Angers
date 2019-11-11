#include "Sequence.hh"
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
  // creation d'un nouveau tableau de couleur + grand
  couleur * nouv=new couleur[taille+1];
  //copie de l'ancien tableau dans le nouveau
  for(indiceSequence ind(0);ind<taille;ind++){
    nouv[ind]=couleurs[ind];
  }
  // ajout de la nouvelle valeur dans le nouveau tableau, puis suppression de l'ancien
  nouv[taille]=coul;
  taille++;
  delete [] couleurs;
  couleurs=nouv; // lien du nouveau tableau à la séquence
}

//destructeur
Sequence::~Sequence(){
  delete [] couleurs;
}

//copie de la séquence en paramètre dans la séquence
void Sequence::copier(Sequence & s){
    taille=0;
    //parcours de la séquence à copier
    for(indiceSequence ind=0; ind<s.getTaille();ind++){
      ajouter(s.acces(ind)); //ajout de chacune des couleurs à la séquence
    }
}

//constructeur par recopie
Sequence::Sequence(Sequence &s):
couleurs(nullptr),taille(0){
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
  for(indiceSequence ind=0; ind<taille;ind++){ // parcours de la séquence
    switch(couleurs[ind]){ // affiche la couleur actuelle
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
  //destruction de la liste
  delete [] couleurs;
  //réinitialisation
  taille=0;
  couleurs=nullptr;
}
// retourne true si les séquences sont identiques, false sinon
bool Sequence::comparer(Sequence & s){
  if(taille!=s.getTaille()) return false; // pas besoin d'aller plus loin si elles sont de taille différentes
  for(indiceSequence ind(0);ind<taille;ind++){
        if(s.acces(ind)!=couleurs[ind]) return false;
  }
  return true; // si elles ne sont pas différentes, elles sont identiques
}
