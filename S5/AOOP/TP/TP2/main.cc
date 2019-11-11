#include <iostream>
#include <stdlib.h>
#include <vector>
#include "TaillePosition.hh"
#include "vSequence.hh"
#include "vectrois.hh"

/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

int main(int argc,char * argv[]){
    //en fonction du num d'exercice, on change l'execution
    if(argc!=2){
        std::cout<<"utilisation:"<<std::endl;
        std::cout<<"./nomprog [numero de la partie du TP à tester]"<<std::endl;
    }else{
        switch(std::stoi(argv[1])){

            case(1): { // Partie 1 du TP
                Position pos1(22,05);
                Position pos2(pos1);
                if(pos2.comparaison(pos1)){
                    std::cout<<"nice, sucess, ça marche!"<<std::endl;
                }
            break;}

            case(2):// partie 2 du TP, même execution que le 4
			case(4):{  //partie 4 du TP
                Sequence a;
      	        a.ajouter(couleur::rouge);
      	        a.ajouter(couleur::bleu);
      	        a.ajouter(couleur::rouge);
      	        a.ajouter(couleur::vert);
                Sequence b(a); // voir question 3
      	        a.afficher(a.acces(0)); std::cout << "\n";
      	        for (indiceSequence i=0; i<a.getTaille(); ++i)
      		        a.afficher(a.acces(i));
      	        std::cout << "\n";
      	        a.vider();
      	        std::cout << "A: "; a.afficher(std::cout); // voir question 4
      	        std::cout << "B: "; b.afficher(std::cout);
      	        std::cout << a.comparer(b) << "\n";
      	        a.copier(b); // voir question 5
      			std::cout << a.comparer(b) << "\n";
        	break;}

      		case(3):{ // partie 3 du TP
        		std::vector<int> v1; // Construction à vide
        		for (int i(0); i<10; i++)
            		v1.push_back(i);
        		std::vector<int> v2(v1); // Construction par recopie
        		// Parcours par indice
        		for (std::vector<int>::size_type i(0); i<v1.size(); ++i)
        		std::cout << v1[i];
        		// Parcours par itérateur
        		for (std::vector<int>::const_iterator i(v1.begin()); i!=v1.end(); ++i)
        			std::cout << *i;
        		// Parcours et modification par itérateur
        		for (std::vector<int>::iterator i(v1.begin()); i!=v1.end(); ++i)
        		*i = *i +1;
        		// Parcours et modification par itérateur
		        for (auto i(v1.begin()); i!=v1.end(); ++i)
		        	*i = *i +1;
		        // Parcours par boucle for d'intervalle (valeur)
		        for (auto i : v1)
		        	std::cout << i;
		        // Parcours par boucle for d'intervalle (référence)
		        for (auto & i : v1)
		        	i *= 2;
		        // Utilisation de l'opérateur d'affectation.
		        v2 = v1;

				//tests persos
				std::cout<<std::endl;
				std::vector<int> vTrois=Saisie_val(); // saisie du contenu du vecteur
				std::cout<<"avez-vous bien saisi ";
				//affichage du vecteur
				for (auto i(vTrois.begin());i!=vTrois.end(); i++) std::cout <<*i<<" ";
				std::cout<<"?"<<std::endl<<"laissez-moi deviner. Son plus grand nombre est "<<vMax(vTrois)<<std::endl;
		    break;}

      		default:{ // cas erreur
        		std::cout<<"entrez le numero d'un exercice existant"<<std::endl;
        	break;}
    	}//fin switch-case
	}//fin else
  	return 0;
}
