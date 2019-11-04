#ifndef SCANNER_H
#define SCANNER_H

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif


class Scanner : public yyFlexLexer {
public:
    /*variables*/
    unsigned int nbMots;
    unsigned int nbPonc;
    unsigned int nbNum;

    /*constructeur & destructeur*/
    Scanner(std::istream & in, std::ostream & out) : yyFlexLexer(in, out) {
      nbMots=0;
      nbPonc=0;
      nbNum=0;
    }

    ~Scanner() {
    }

    /*méthodes*/
    //affiche le nombre de mots, de ponctuation et de nombres
    void afficher(){
      std::cout << "il y a " << nbMots << "mots" << std::endl;
      std::cout << "il y a " << nbNum << "nombres" << std::endl;
      std::cout << "il y a " << nbPonc << "caractères de ponctuations" << std::endl;
    }
    virtual
    int yylex();
};


#endif
