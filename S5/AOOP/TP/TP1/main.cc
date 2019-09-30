#include "sequence.hh"
#include <iostream>
/** @author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */


int main(int argc,char * argv[]){
  //en fonction du num d'exercice, on change l'execution
  if(argc!=2){// en cas d'utilisation incorrecte
      std::cout<<"utilisation:"<<std::endl;
      std::cout<<"./nomprog [numero de la partie du TP à tester]"<<std::endl;
  }else{ // execution normale
    switch(std::stoi(argv[1])){
  
      case(1||3):{ // cas de la partie 1 et 3
        sequence a, b;
        sc_initialiservide(a); // 3
        sc_initialiservide(b);
        sc_ajouter(a, couleur::rouge); // 4
        sc_ajouter(a, couleur::bleu);
        sc_ajouter(a, couleur::rouge);
        sc_ajouter(a, couleur::vert);
        sc_copier(b, a); // Copie a dans b // 5
        sc_afficher(sc_acces(a, 0)); std::cout << "\n"; // 6 et 7
        for (indicesequence i=0; i<a.taille; ++i)
        sc_afficher(sc_acces(a,i));
        sc_vider(a); // 8
        std::cout << "\n";
        std::cout << "A: "; sc_afficher(a); // 9
        std::cout << "B: "; sc_afficher(b);
        std::cout << sc_comparer(a,b) << "\n"; // 10
        sc_copier(a,b);
        std::cout << sc_comparer(a,b) << "\n";
        break;}

      case(2):{ // cas de la partie 2

        // test voyelles
        std::string s("Vous savez, moi je ne crois pas qu’il y ait de bonne ou de mauvaise situation. Moi, si je devais résumer ma vie aujourd’hui avec vous, je dirais que c’est d’abord des rencontres. Des gens qui m’ont tendu la main, peut-être à un moment où je ne pouvais pas, où j’étais seul chez moi. Et c’est assez curieux de se dire que les hasards, les rencontres forgent une destinée… Parce que quand on a le goût de la chose, quand on a le goût de la chose bien faite, le beau geste, parfois on ne trouve pas l’interlocuteur en face je dirais, le miroir qui vous aide à avancer. Alors ça n’est pas mon cas, comme je disais là, puisque moi au contraire, j’ai pu : et je dis merci à la vie, je lui dis merci, je chante la vie, je danse la vie… je ne suis qu’amour ! Et finalement, quand beaucoup de gens aujourd’hui me disent « Mais comment fais-tu pour avoir cette humanité ? », et bien je leur réponds très simplement, je leur dis que c’est ce goût de l’amour ce goût donc qui m’a poussé aujourd’hui à entreprendre une construction mécanique, mais demain qui sait ? Peut-être simplement à me mettre au service de la communauté, à faire le don, le don de soi");
        std::cout <<"la phrase testée contient " << nb_voyelles(s) <<" voyelles \n" <<std::endl;

        //test palindrome
        std::string test_pal("engagelejeuquejelegagne");
        std::cout << test_pal;
        if(est_Palindrome(test_pal)) std::cout << " est un palindrome \n"<< std::endl;
        else std::cout << " n'est pas un palindrome \n" << s << std::endl;

        //test chiffrer & déchiffrer
        chiffrer(s);
        std::cout << " vous avez reçu un message codé : " << s << " \n"<< std::endl;;
        dechiffrer(s);
        std::cout << " décodage en cours... \n"<< std::endl <<" le message était : " << s << std::endl;

        // test extract_number
        s=("2019");
        int annee=extract_number(s);
        std::cout << "\n l'année d'aujourd'hui est " << annee << std::endl;

        break;}

      default:{ // cas erreur
        std::cout<<"entrez le numero d'un exercice existant"<<std::endl;
        break;}
    }//fin else
    return 0;
}
