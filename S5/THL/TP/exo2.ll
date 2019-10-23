/*header */
%{
#include "scanner.hh"
#define YY_NO_UNISTD_H
%}
%option c++
%option yyclass="Scanner"
%option noyywrap

%%
[a-zA-Z]+|([a-zA-Z]+[-\'][a-zA-Z]+) { //'
  nbMots++;
}

[0-9]+([,][0-9]+)? {
  nbNum++;
}

[,?:.;!] {
  nbPonc++;
}

%%

int main( int argc, char* argv[] )
{
    Scanner* lexer = new Scanner(std::cin, std::cout);
    while(lexer->yylex() != 0);

    //affichage du résultat
    lexer->afficher();

    return 0;
}
