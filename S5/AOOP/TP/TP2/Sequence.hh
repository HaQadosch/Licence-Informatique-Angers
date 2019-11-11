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
    void afficher(std::ostream & out);
    void vider();
    bool comparer(Sequence & s);
    void copier(Sequence & s);
    /*constructeurs & destructeur*/
    Sequence():couleurs(nullptr),taille(0){};
    Sequence(Sequence &s);
    ~Sequence();
    /*setters & getters*/
    indiceSequence getTaille() const {return taille;}
  private:
    /*variables*/
    couleur * couleurs;
    indiceSequence taille;
};
