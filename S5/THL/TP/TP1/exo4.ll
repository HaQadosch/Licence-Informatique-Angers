/* header */
/* header */
%{
#include "scanner.hh"
#define YY_NO_UNISTD_H
%}

%option c++
%option yyclass="Scanner"
%option noyywrap

entier [0-9]+
decimal (,[0-9]+)?
nombre {entier}{decimal}

Chaine (\"([^"]|\\\")*\")


 /* règles et traitement */
%%
 /* format: [expression_reguliere] { code } */

{Chaine}  {
  std::cout << "Chaine détectée :"<< YYText() << " de longueur "<< YYLeng()-2<< std::endl;
}

begin|end {
  std::cout << "keywords :"<< YYText() << std::endl;
}

{nombre}  {
  std::cout << "Nombre :"<< YYText() << std::endl;
}

[a-zA-Z0-9]+  {
    std::cout << "identificteur :"<< YYText() << std::endl;
}

[\*\_\+]|([\*][\*]) {
  std::cout << "opératateur :" << YYText() << std::endl;
}

.  { // cas par défaut/d'erreur
  std::cout << "ERREUR" << std::endl;
}

%%

/* affichage des résultats (avec ctrl+D dans le terminal) */
int main( int argc, char* argv[] )
{
    Scanner* lexer = new Scanner(std::cin, std::cout);
    while(lexer->yylex() != 0);

    // code ici l'affichage & autre

    return 0;
}
