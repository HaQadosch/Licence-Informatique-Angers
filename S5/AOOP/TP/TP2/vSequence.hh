#pragma once
#include <array>
#include <vector>

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
    Sequence()=default;
    Sequence(Sequence &s);
    ~Sequence();
    /*setters & getters*/
    indiceSequence getTaille() const {return couleurs.size();}
	std::vector<couleur> getCouleurs() const {return couleurs;}
  private:
    /*variables*/
    std::vector<couleur> couleurs;
};
