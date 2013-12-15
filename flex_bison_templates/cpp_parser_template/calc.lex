%{
#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <string>

#include "calc_driver.hpp"
#include "calc_parser.hpp"

#undef yywrap
#define yywrap() 1

#define yyterminate() return token::END
%}

%option prefix="calc_"
%option header-file="calc_lexer.hpp"
%option noyywrap
%option nounput
%option batch
%option debug
%option nounistd
%option never-interactive

%option reentrant

id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t]

%{
#define YY_USER_ACTION yylloc->columns(yyleng);
%}

%%

%{
    yylloc->step ();
%}


{blank}+   yylloc->step();
[\n]+      yylloc->lines(yyleng); yylloc->step();

%{
typedef calc_::calc_parser::token token;
%}

[{}();,.]   return calc_::calc_parser::token_type (yytext[0]);
"class"     return token::CLASS;

{id}        { yylval->sval = new std::string(yytext); return token::IDENTIFIER; }
.          driver.error (*yylloc, "invalid character");

%%

