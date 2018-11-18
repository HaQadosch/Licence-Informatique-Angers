#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

const int TailleMax=1000000;
const int Taille=10;
using tab=std::array<int,TailleMax>;

/* fonction permettant l'initialisation d'un tableau T de taille Taille
 * Le remplis de nombre aleatoires */
void initTab (tab &T){

  int cur;//current, marqueur utilisé pour le parcours

  srand(time(NULL)); // initialise le générateur de rand

  //parcours du tableau
  for (cur=0; cur<Taille;cur++){
    T[cur]=rand()%100; // attribue un entier aleatoire à chaque case
  }

}

/* fonction permettant l'affichage du tableau */
void AffPetitTab(tab T){

  int cur; // current, marqueur utilisé pour le parcours

  std::cout<<" | "; // affichage de la barre de delimitation gauche

  // parcours du tableau et affichage de chaque case
  for (cur=0; cur<Taille;cur++){
    std::cout<<T[cur]<<" | ";
  }

  std::cout<<"\n"; // saut de ligne à la fin de l'affichage
}

/* trie le tableau en utilisant la méthode d'insertion */
void tri_insertion (tab &T){
  int cur,value,sec;

  //parcours du tableau
  for (cur=1;cur<Taille;cur++){
    value=T[cur]; // sauvegarde de la premiere valeur non-triée du tableau
    sec=cur-1; // sauvegarde de la derniere valeur du tableau trié

    // parcours du tableau trié tant que la valeur testée est supérieur à celle à insérer
    while(sec >= 0 && T[sec]>value){
      T[sec+1] = T[sec]; // decallage de l'element à droite
      sec--; // on deplace le curseur d'un cran à gauche
    }//fin while

    T[sec+1]=value; // on place la valeur à insérer juste aprés l'element qui lui est inférieur
  }//fin for
}// fin fct

int main(){

  int exo_test; // numero de l'exercice à tester

  // demande de l'exercice à tester
  std::cout<<"quel exercice voulez-vous testez?"<<"\n"
  <<"1: tri_insertion"<<"\n"
  <<"2: tri_rapide"<<"\n"
  <<"3: Comparaison des performances du tri insertion, tri rapide, et tri bulle"<<"\n"
  <<"valeur saisie :";
  std::cin>>exo_test; // saisie du numero d'exercice à tester

  //si l'exo testé est le 3, generation d'un tableau particulier
  if(exo_test==3){

  } else if(exo_test!=1 && exo_test!=2){ // Si la valeur n'est pas entre 1 et 3

    std::cout<<" veuillez saisir une valeur valide, entre 1 et 3 inclus"<<"\n";

  } else { // si l'exo testé est le 1 ou le 2

    /* création et initialisation du tableau */
    tab T;
    initTab(T);

    std::cout<<" tableau généré avant le tri"<<"\n";
    AffPetitTab(T); //affichage du tableau avant tri
    
    if(exo_test==1) tri_insertion(T);// tri du tableau vie tri_insertion
    if(exo_test==2)//tri_rapide(T); // tri du tableau via tri_rapide

    std::cout<<" même tableau aprés le tri"<<"\n";
    AffPetitTab(T); // affichage du tableau aprés tri

  }
}
