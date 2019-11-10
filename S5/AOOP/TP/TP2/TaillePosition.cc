#include "TaillePosition.hh"
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */


/***********************************************************Taille***************************************************/
/*constructeurs*/
Taille::Taille(coordonnee largeur, coordonnee hauteur){
  largeur=largeur;
  hauteur=hauteur;
}
/***********************************************************Position***************************************************/
/* constructeurs */
Position::Position(Position const & pos){
  x=pos.x;
  y=pos.y;
}

Position::Position(coordonnee x,coordonnee y){
  x=x;
  y=y;
}

/**
 * \brief Comparaison compare si la Position est identique à test
 * \param test Position testée
 * \return true si les deux Positions sont identiques
 * \return false si les deux Positions ne le sont pas
 */
bool Position::comparaison(Position test) const {
  if((test.getX()!=x) || (test.getY()!=y)) return false;
  return true;
}
