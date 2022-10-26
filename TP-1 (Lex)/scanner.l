%option noyywrap prefix="scanner"
%{

#include <stdlib.h> /* for atof() */
#include "./scanner.h"

struct Token *t;

%}

NUMERO -?([0-9]+\.?[0-9]*)|(\.?[0-9]+);
OPERADORES [\-\%\+\*\/]
ENTER \n

%%
[ \t]+ ;
{NUMERO} return Number;
{OPERADORES} return *scannertext;
{ENTER} {return PopResult;}
. {return LexError;}
%%

bool GetNextToken(struct Token *t) {
      TokenType type = scannerlex();
      if (type == 0) return false;
      t -> type = type;
      switch (type) {
            case Number:
                  t -> data.val = atof(scannertext);
                  return true;
            case LexError:
                  t -> data.lexeme = scannertext;
                  return true;
            default:
                  return true;
      }
}