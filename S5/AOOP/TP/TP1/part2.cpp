#include <iostream>
#include<string>
/** @author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

/***********************************************************FONCTIONS***************************************************/

/**
 * @brief nb_voyelles compte le nombre de voyelles d'une chaine
 * @param s chaine testée
 * @return nombre de voyelle de la chaine
 */
int nb_voyelles(std::string s){
    int nb(0); // initialisation du compteur à 0

    //parcours de la chaine, incrémentation du compteur à chaque voyelle rencontrée
    for(int i=0;i<s.size();i++){
        switch(s.at(i)){
            case('a'): nb-=-1;break;
            case('e'): nb-=-1;break;
            case('i'): nb-=-1;break;
            case('o'): nb-=-1;break;
            case('u'): nb-=-1;break;
            case('y'): nb-=-1;break;
            default: break;
        }
    }
    return nb;
}

/**
 * @brief est_Palindrome verifie si la chaine est un palindrome
 * @param s chaine testée
 * @return bool indiquant s'il s'agit ou non d'un palindrome
 */
bool est_Palindrome(std::string s){
    for(int i=0;i<=(s.size()/2);i++){ // on parcours les deux moitiés de la chaine testée
        if((s.at(i))!=(s.at(s.size()-(i+1)))) return false; // retourne faux si les lettres sont différentes
    }
    return true; // si aucune lettre n'est différente de son symétrique, alors retourne vrai
}

/**
 * @brief chiffrer permet de chiffrer une chaine selon le chiffrement césar
 * @param s chaine qui sera chiffrée
 */
void chiffrer( std::string &s){
    for(int i=0;i<s.size();i++){ // parcours de la chaine
         // décallage de 3 vers la droite quand il s'agit de lettre
        if((s.at(i)>='A'&& s.at(i)<='Z') || (s.at(i)>='a' && s.at(i)<='z') ){ // verification de s'il s'agit d'une lettre
            if((s.at(i)>='x' && s.at(i)<='z') || (s.at(i)>='X' && s.at(i)<='Z') ) s.at(i)=s.at(i)-26;  // s'il s'agit d'une des 3 dernieres lettres, retour au début de l'alphabet
            s.at(i)=(s.at(i)+3); // decallage de 3 vers la droite
        }
    }
}

/**
 * @brief extract_number permet de transformer une chaine contente un nombre, en nombre
 * @param s chaine dont le nombre sera extrait
 * @return le nombre contenu dans la chaine
 */
unsigned int extract_number(std::string s){
    int num_lettre=s.size()-1;
    if((s.at(num_lettre)>='0'&& s.at(num_lettre)<='9')){ // test si c'est un chiffre
        int res(s.at(num_lettre)-'0'); // creation de l'entier associé
        if(num_lettre>0){
           return(10*extract_number(s.substr(0,num_lettre))+res); // on traite le chiffre précédant, en multipliant celui-ci par 10
        }
        return res; // sinon, on retourne l'entier résultant
   }
}

/**
 * @brief dechiffrer permet de déchiffrer une chaine chiffrée par le chiffrement de césar
 * @param s chaine qui sera déchiffrée
 */
void dechiffrer( std::string &s){
    for(int i=0;i<s.size();i++){ // parcours de la chaine
         // décallage de 3 vers la gauche quand il s'agit de lettre
        if((s.at(i)>='A'&& s.at(i)<='Z') || (s.at(i)>='a'&& s.at(i)<='z') ){ // verification de s'il s'agit d'une lettre
            if((s.at(i)>='a' && s.at(i)<='c') || (s.at(i)>='A' && s.at(i)<='C') ) s.at(i)=s.at(i)+26;  // s'il s'agit d'une des 3 dernieres lettres, retour au début de l'alphabet
            s.at(i)=(s.at(i)-3); // decallage de 3 vers la droite
        }
    }
}

/***********************************************************MAIN***************************************************/

int main()
{

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
    return 0;
}

