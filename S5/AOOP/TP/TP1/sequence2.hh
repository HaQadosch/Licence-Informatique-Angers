#pragma once
#include <array>

enum class couleur{
    rouge,
    bleu,
    jaune,
    vert
};

using indicesequence = std::size_t;

struct sequence{
    couleur * couleurs;
    indicesequence taille;
};

void sc_initialiservide(sequence &s);
void sc_ajouter(sequence &s,couleur coul);
void sc_copier( sequence &vers, sequence de);
couleur sc_acces(sequence s, indicesequence ind);
void sc_afficher(couleur coul);
void sc_afficher(sequence s);
void sc_vider(sequence &s);
bool sc_comparer(sequence s1, sequence s2);

