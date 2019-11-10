#pragma once
#include <array>

enum class couleur{
    rouge,
    bleu,
    jaune,
    vert
};

using indiceSequence = unsigned int;

class Sequence{
  public:
    /*fonctions*/
    void ajouter(couleur const coul);
    couleur acces(indiceSequence const ind);
    void afficher(couleur coul);
  //  void afficher(couleur coul,std::ostream out);
/*    void vider(Sequence &s);
    bool comparer(Sequence s1, Sequence s2);
*/
    /*constructeurs & destructeur*/
    Sequence():couleurs(nullptr),taille(0){};
    Sequence(Sequence &s);
    ~Sequence();
    /*setters & getters*/
    indiceSequence getTaille() const {return taille;}
  //  void setCouleur();
  private:
    /*variables*/
    couleur * couleurs;
    indiceSequence taille;
};
