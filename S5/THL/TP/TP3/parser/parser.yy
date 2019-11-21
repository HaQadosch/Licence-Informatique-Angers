%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>

    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token <double>      	NUMBER

%type <ExpressionPtr>	operation
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    instruction NL programme
    | END NL {
        YYACCEPT;
    }

instruction:
    expression  {
    }
    | affectation {
    }

expression:
    operation {
        //Modifier cette partie pour prendre en compte la structure avec expressions
		Contexte C;
		std::cout << "#-> " << $1->calculer(C) << std::endl;
    }

affectation:
    '=' { std::cout << "Affectation à réaliser" << std::endl;
    }

operation:
    NUMBER {
        $$ = std::make_shared<Constante>($1);
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ =std::make_shared<ExpressionBinaire>($1,$3, OperateurBinaire::plus); // 2 + x
    }
    | operation '-' operation {
        $$ =std::make_shared<ExpressionBinaire>($1,$3, OperateurBinaire::moins);
    }
    | operation '*' operation {
        $$ =std::make_shared<ExpressionBinaire>($1,$3, OperateurBinaire::multiplie);
    }
    | operation '/' operation {
        $$ =std::make_shared<ExpressionBinaire>($1,$3, OperateurBinaire::divise);
    }
    | '-' operation %prec NEG {
        $$ =std::make_shared<ExpressionUnaire>($2, OperateurUnaire::neg);
    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
