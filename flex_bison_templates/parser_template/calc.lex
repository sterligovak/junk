/* Mini Calculator */

%{
#include <string>

#include "calc_parser.hpp"
void calc_error ( YYLTYPE *locp, yyscan_t scanner, char const *msg);
%}

%option prefix="calc_"
%option nounistd
%option never-interactive
%option noyywrap
%option reentrant
%option yylineno

%option bison-bridge
%option bison-locations

%option header-file="calc_lexer.hpp"

%{
#define YY_USER_ACTION \
	do {\
		yylloc->first_line = yylloc->last_line = yylineno; \
		yylloc->first_column = yycolumn;\
		yylloc->last_column = yycolumn + yyleng - 1; \
		yycolumn += yyleng;\
	} while(0);\
/**/
%}

int_const	[[:digit:]]+
id			[[:alpha:]][[:alnum:]]+

%%

{int_const}	{yylval->int_val = atoi(yytext); return INTEGER_LITERAL;}
"+"			return PLUS;
"*"			return MULT;

"/"			return DIV;
";"			return COLON;

"("			return LBRACE;
")"			return RBRACE;

"{"			return LCURL;
"}"			return RCURL;

"int"		return INT;
"void"		return VOID;
{id}		yylval->op_val = new std::string(yytext); return ID;

[[:space:]]*	{}
.			return LEXER_ERROR;
