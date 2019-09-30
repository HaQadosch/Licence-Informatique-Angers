#include "TaillePosition.hh"
/** @author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */


/***********************************************************TAILLE***************************************************/
/*constructeurs*/
Taille::Taille(coordonnee largeur, coordonnee hauteur){
  largeur=largeur;
  hauteur=hauteur;
}
/***********************************************************POSITION***************************************************/
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
 * @brief Comparaison compare si la position est identique à test
 * @param test position testée
 * @return true si les deux positions sont identiques
 * @return false si les deux positions ne le sont pas
 */
bool Position::Comparaison(Position test) const {
  if((test.getX()!=x) || (test.getY()!=y)) return false;
  return true;
}
