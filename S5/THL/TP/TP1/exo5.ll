/* header */
%{
#include "scanner.hh"
#define YY_NO_UNISTD_H
%}

%option c++
%option yyclass="Scanner"
%option noyywrap

 /* règles et traitement */
%%
 /* format: [expression_reguliere] { code } */
 
.  { // cas par défaut/d'erreur
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
