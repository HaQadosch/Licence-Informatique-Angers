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
void Sequence::ajouter(couleur const coul){
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

//constructeur par recopie
Sequence::Sequence(Sequence &s){
  for(indiceSequence i=0; i<s.getTaille();i++){
    ajouter(s.acces(i));
  }
}

void Sequence::afficher(couleur coul){
  switch(coul){
    case(couleur::rouge):{
      std::cout<<" rouge";
    break;}
    case(couleur::jaune):{
      std::cout<<" jaune";
    break;}
    case(couleur::vert):{
      std::cout<<" vert";
    break;}
    case(couleur::bleu):{
      std::cout<<" bleu";
    break;}
  }
}
