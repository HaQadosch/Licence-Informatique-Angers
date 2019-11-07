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
%token <char>           OP
%token <int>            NUMBER
%type <int>             operation

%%

programme:
    NUMBER NL {
        std::cout << "nombre : " << $1 << std::endl;
    } programme
    |operation NL{
      std::cout << "operation : " << $1 << std::endl;
    } programme
    | END NL {
        YYACCEPT;
    }
operation:
  NUMBER OP NUMBER{

    switch($2){
      case("+") : $$ = $1 + $3; break;
      case("-") : $$ = $1 + $3; break;
      case("*") : $$ = $1 + $3; break;
      case("/") : $$ = $1 + $3; break;
      default : break;
    }

  }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
