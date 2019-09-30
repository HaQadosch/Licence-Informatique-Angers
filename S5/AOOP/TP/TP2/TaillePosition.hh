
/** @author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

typedef int coordonnee;

class Position{
  public:
    /*fonctions*/
    bool Comparaison(Position test) const;

    /*constructeurs*/
    Position(Position const & pos); // par recopie
    Position(coordonnee x, coordonnee y);//avec paramètre
    Position();//vide

    /*setters & getters*/
    coordonnee getX() const {return x;}
    coordonnee getY() const {return y;}
    void setX(coordonnee x){x=x;}
    void setY(coordonnee y){y=y;}

  private:
    /*variables*/
    coordonnee x,y;

};

class Taille{
  public:
    /*fonctions*/

    /*constructeurs*/
    Taille(coordonnee largeur, coordonnee hauteur); // avec paramètre
    Taille(); // vide

    /*setters & getters*/
    coordonnee getLargeur() const {return largeur;}
    coordonnee getHauteur() const {return hauteur;}
    void setLargeur(coordonnee largeur){largeur=largeur;}
    void setHauteur(coordonnee hauteur){hauteur=hauteur;}

  private:
    /*variables*/
    coordonnee  largeur,hauteur;
};
