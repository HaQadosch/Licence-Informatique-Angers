#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

const int TailleT=10;
using namespace std;
using tab=array<int,TailleT>;

/* fonction permettant l'initialisation d'un tableau T de taille TailleT
 * Le remplis de nombre aleatoires */

void initTab ( tab &T){
        int cur;
        srand(time(NULL)); // initialise le générateur de rand

        /* parcours le tableau et génére un entier aleatoire à chaque case */
        for (cur=0; cur<TailleT;cur++){
                T[cur]=rand()%1000;
        }
}

/* fonction permettant l'affichage du tableau */
void AffPetitTab(tab T){
    int cur;

    // parcours du tableau et affichage de chaque case
    for (cur=0; cur<TailleT;cur++){
            std::cout <<"tab"<<cur<<": "<<T[cur]<<"\n";
    }
}


void tri_insertion (tab &T){
    int cur,actual;
    for (cur=1;cur<TailleT,cur++){
        value=T[cur];
        sec=cur-1;
        while(sec >= 0 && T[sec]>value){
            T[sec+1] = t[sec];
            sec--;
        }
        T[sec+1]=x;
    }
}

int main(){

        /* initialisation du tableau */
        tab T;
        initTab(T);

        /* affichage du tableau */
        AffPetitTab(T);

}

