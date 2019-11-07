%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
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
%token                  PLUS
%token                  MULT
%token <int>            NUMBER
%type <int>             addition
%type <int>             multiplication

%%

programme:
    NUMBER NL {
        std::cout << "nombre : " << $1 << std::endl;
    } programme
    |addition NL{
      std::cout << "addition :" << $1 << std::endl;
    } programme
    |multiplication NL{
     std::cout << "multiplication :" << $1 << std::endl;
    } programme
    | END NL {
        YYACCEPT;
    }
addition:
  NUMBER PLUS NUMBER{
    $$ = $1 + $3;
  }

multiplication:
  NUMBER MULT NUMBER{
    $$ = $1 * $3;
  }
%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
