#pragma once
#include <array>

enum class couleur{
    rouge,
    bleu,
    jaune,
    vert
};

using indicesequence = unsigned int;

class sequence{
  public:
    /*fonctions*/
    void sc_initialiservide(sequence &s);
    void sc_ajouter(sequence &s,couleur coul);
    void sc_copier( sequence &vers, sequence de);
    couleur sc_acces(sequence s, indicesequence ind);
    void sc_afficher(couleur coul);
    void sc_afficher(sequence s);
    void sc_vider(sequence &s);
    bool sc_comparer(sequence s1, sequence s2);

    /*constructeurs*/
    void sequence();

    /*setters & getters*/
    coordonnee get_var() const {return this._var;}
    void set_var(type var){this._var=var};

  private:
    /*variables*/
    couleur * couleurs;
    indicesequence taille;
};
