#include "sequence.hh"
#include <iostream>

void sc_initialiservide(sequence &s) {
    s.taille=0;
}

void sc_ajouter(sequence &s,couleur coul){
    s.contenu[s.taille++]=coul;
}

void sc_copier( sequence &vers, sequence de){
    vers=de;
}

couleur sc_acces(sequence s, indicesequence ind){
    return s.contenu[ind];
}

void sc_afficher(couleur coul){
    switch(coul){
    case(couleur::bleu): std::cout << "bleu"; break;
    case(couleur::jaune): std::cout << "jaune";break;
    case(couleur::rouge): std::cout << "rouge";break;
    case(couleur::vert): std::cout << "vert";break;
    }
}

void sc_afficher(sequence s){
    for(indicesequence i=0;i<s.taille;i-=-1){
        sc_afficher(s.contenu[i]);
    }
    std::cout << std::endl;
}

void sc_vider(sequence &s){
    s.contenu=null;
    s.taille=null;
    delete(s);
}
