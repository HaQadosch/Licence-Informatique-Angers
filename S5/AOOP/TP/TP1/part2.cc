#include "part2.hh"
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////nb_voyelles
/// \brief nb_voyelles compte le nombre de voyelles d'une chaine
/// \param s chaine testée
/// \return nombre de voyelle de la chaine
int nb_voyelles(std::string s){
    int nb(0); ///< initialisation du compteur à 0

    /// parcours de la chaine, incrémentation du compteur à chaque voyelle rencontrée
    for(unsigned int i=0;i<s.size();i++){
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



///////////////////////////////////////////////////////////////////////////////////////////////////////////////est_Palindrome
/// \brief est_Palindrome verifie si la chaine est un palindrome
/// \param s chaine testée
/// \return bool indiquant s'il s'agit ou non d'un palindrome
bool est_Palindrome(std::string s){
    for(unsigned int i=0;i<=(s.size()/2);i++){ // on parcours les deux moitiés de la chaine testée
        if((s.at(i))!=(s.at(s.size()-(i+1)))) return false; // retourne faux si les lettres sont différentes
    }
    return true; // si aucune lettre n'est différente de son symétrique, alors retourne vrai
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////chiffrer
/// \brief chiffrer permet de chiffrer une chaine selon le chiffrement césar
/// \param s chaine qui sera chiffrée
void chiffrer( std::string &s){
    for(unsigned int i=0;i<s.size();i++){ // parcours de la chaine
         // décallage de 3 vers la droite quand il s'agit de lettre
        if((s.at(i)>='A'&& s.at(i)<='Z') || (s.at(i)>='a' && s.at(i)<='z') ){ // verification de s'il s'agit d'une lettre
            if((s.at(i)>='x' && s.at(i)<='z') || (s.at(i)>='X' && s.at(i)<='Z') ) s.at(i)=s.at(i)-26;  // s'il s'agit d'une des 3 dernieres lettres, retour au début de l'alphabet
            s.at(i)=(s.at(i)+3); // decallage de 3 vers la droite
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////extract_number
/// \brief extract_number permet de transformer une chaine contente un nombre, en nombre
/// \param s chaine dont le nombre sera extrait
/// \return le nombre contenu dans la chaine
unsigned int extract_number(std::string s){
    unsigned int num_lettre=s.size()-1;
    if((s.at(num_lettre)>='0'&& s.at(num_lettre)<='9')){ // test si c'est un chiffre
        unsigned int res(s.at(num_lettre)-'0'); // creation de l'entier associé
        if(num_lettre>0){
           return(10*extract_number(s.substr(0,num_lettre))+res); // on traite le chiffre précédant, en multipliant celui-ci par 10
        }
        return res; // sinon, on retourne l'entier résultant
   }
   return -1;// cas d'erreur
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////dechiffrer
/// \brief dechiffrer permet de déchiffrer une chaine chiffrée par le chiffrement de césar
/// \param s chaine qui sera déchiffrée
void dechiffrer( std::string &s){
    for(unsigned int i=0;i<s.size();i++){ // parcours de la chaine
         // décallage de 3 vers la gauche quand il s'agit de lettre
        if((s.at(i)>='A'&& s.at(i)<='Z') || (s.at(i)>='a'&& s.at(i)<='z') ){ // verification de s'il s'agit d'une lettre
            if((s.at(i)>='a' && s.at(i)<='c') || (s.at(i)>='A' && s.at(i)<='C') ) s.at(i)=s.at(i)+26;  // s'il s'agit d'une des 3 dernieres lettres, retour au début de l'alphabet
            s.at(i)=(s.at(i)-3); // decallage de 3 vers la droite
        }
    }
}
