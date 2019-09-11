#include <iostream>
#include<string>
int nb_voyelles(std::string s){
    int nb(0);
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

bool est_Palindrome(std::string s){
    for(int i=0;i<=(s.size()/2);i++){
        if((s.at(i))!=(s.at(s.size()-(i+1)))) return false;
    }
    return true;
}

void chiffrer( std::string &s){
    for(int i=0;i<s.size();i++){
        s.at(i)=(s.at(i)+3);
        
        if(s.at(i)>'z'){
            if(s.at(i)>'Z') 
            }
            else (s.at(i)=s.at(i)-26);
        } 
    }
}
void dechiffrer( std::string &s){
    for(int i=0;i<s.size();i++){
         s.at(i)=(s.at(i)+3);

    }
}
int main()
{
    std::string s("Vous savez, moi je ne crois pas qu’il y ait de bonne ou de mauvaise situation. Moi, si je devais résumer ma vie aujourd’hui avec vous, je dirais que c’est d’abord des rencontres. Des gens qui m’ont tendu la main, peut-être à un moment où je ne pouvais pas, où j’étais seul chez moi. Et c’est assez curieux de se dire que les hasards, les rencontres forgent une destinée… Parce que quand on a le goût de la chose, quand on a le goût de la chose bien faite, le beau geste, parfois on ne trouve pas l’interlocuteur en face je dirais, le miroir qui vous aide à avancer. Alors ça n’est pas mon cas, comme je disais là, puisque moi au contraire, j’ai pu : et je dis merci à la vie, je lui dis merci, je chante la vie, je danse la vie… je ne suis qu’amour ! Et finalement, quand beaucoup de gens aujourd’hui me disent « Mais comment fais-tu pour avoir cette humanité ? », et bien je leur réponds très simplement, je leur dis que c’est ce goût de l’amour ce goût donc qui m’a poussé aujourd’hui à entreprendre une construction mécanique, mais demain qui sait ? Peut-être simplement à me mettre au service de la communauté, à faire le don, le don de soi");
    std::cout << nb_voyelles(s) << std::endl;
    s="ahahahahazwyx";
    chiffrer(s);
    std::cout << est_Palindrome(s)<< "\n" << s << std::endl;

    return 0;
}
