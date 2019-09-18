#include "sequence2.hh"
#include <iostream>

void sc_initialiservide(sequence &s) {
    s.taille=0;
    s.couleurs=nullptr;
}

void sc_ajouter(sequence &s,couleur coul){
    //creation du nouveau tableau
    couleur * nouv(new couleur[s.taille+1]);

    //copie de l'ancien tableau dans le nouveau
    for(indicesequence i=0;i<s.taille;i++){
        nouv[i]=s.couleurs[i];
    }
    //suppression de l'ancien tableau
    delete[] s.couleurs;

    //ajout de la couleur dans le nouveau tableau
    nouv[s.taille]=coul;
    s.taille++; // mise à jour de la taille

    //nouveau tableau associé a la sequence
    s.couleurs=nouv;
}

void sc_copier( sequence &vers, sequence de){

    if(de.taille!=vers.taille){//si les tailles sont identiques, réutilisation de l'ancien tableau

        //suppression de l'ancien tableau
        if(vers.taille!=0)delete[] vers.couleurs;

        //creation du nouveau tableau
        if(de.taille!=0)vers.couleurs=(new couleur[de.taille]);
    }
    //copie du tableau
    for(vers.taille=0;vers.taille<de.taille;vers.taille++){
        vers.couleurs[vers.taille]=de.couleurs[vers.taille];
    }

    // cas de tableau vide
    if(vers.taille==0) vers.couleurs=nullptr;

}

couleur sc_acces(sequence s, indicesequence ind){
    return s.couleurs[ind];
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
        sc_afficher(s.couleurs[i]);
        std::cout<<" ";
    }
    std::cout << std::endl;
}

void sc_vider(sequence &s){
    delete[] s.couleurs;
    s.taille=0;
}

bool sc_comparer(sequence s1, sequence s2){
    if(s1.taille==s2.taille){
        for(indicesequence i(0);i<s1.taille;i++){
            if(s1.couleurs[i]!=s2.couleurs[i]) return false;
        }
        return true;
    }
    return false;
}
