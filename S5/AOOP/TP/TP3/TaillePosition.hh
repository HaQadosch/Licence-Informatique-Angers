
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

typedef int coordonnee;

class position{
  public:
    /*fonctions*/
    bool comparaison(position test) const;

    /*constructeurs*/
    position(position const & pos); // par recopie
    position(coordonnee x, coordonnee y);//avec paramètre
    position();//vide

    /*setters & getters*/
    coordonnee getX() const {return x;}
    coordonnee getY() const {return y;}
    void setX(coordonnee x){x=x;}
    void setY(coordonnee y){y=y;}

  private:
    /*variables*/
    coordonnee x,y;

};

class taille{
  public:
    /*fonctions*/

    /*constructeurs*/
    taille(coordonnee largeur, coordonnee hauteur); // avec paramètre
    taille(); // vide

    /*setters & getters*/
    coordonnee getLargeur() const {return largeur;}
    coordonnee getHauteur() const {return hauteur;}
    void setLargeur(coordonnee largeur){largeur=largeur;}
    void setHauteur(coordonnee hauteur){hauteur=hauteur;}

  private:
    /*variables*/
    coordonnee  largeur,hauteur;
};
