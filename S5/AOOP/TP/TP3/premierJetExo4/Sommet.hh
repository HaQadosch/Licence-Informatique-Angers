#include <string>
#include <list>

using identifiant = unsigned int;
 struct arcSortant{
    identifiant extremite;
    std::string etiquette;
 };

class Sommet{
  public:
    /*methods*/
    void ajouterArc(identifiant etc, std::string const & etiq);
    void supprimerArc(identifiant ext);
    /*constructeurs*/
    Sommet(std::string const & et);

    /*setters & getters*/
    identifiant id() const {return id;}
    std::string const &etiquette() const {return etiquette;}

  private:
    /*variables*/
    identifiant id;
    std::string etiquette;
    std::list<arcSortant> arcs;
    static identifiant compteur;
}
