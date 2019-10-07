#include "sequence.hh"
#include <iostream>

void sc_initialiservide(sequence &s) {
    s.taille=0;
}

void sc_ajouter(sequence &s,couleur coul){
    s.contenu[s.taille++]=coul;
}

void sc_copier( sequence &vers, sequence de){
    vers=de; // methode de feignasse, les vrais vont faire une boucle for pour copier que les cases remplies
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
        std::cout<<" ";
    }
    std::cout << std::endl;
}

void sc_vider(sequence &s){
    for(;s.taille>0;s.taille--){
       //s.contenu[s.taille];
    }
}

bool sc_comparer(sequence s1, sequence s2){
    if(s1.taille==s2.taille){
        for(indicesequence i=0;i<s1.taille;i++){
            if(s1.contenu[i]!=s2.contenu[i]) return 0;
        }
        return 1;
    }
    return 0;
}
