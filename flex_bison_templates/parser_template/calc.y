/* Mini Calculator */
%{
#include <string>
#include <iostream>
%}

%name-prefix "calc_"

%define api.pure
%parse-param {yyscan_t scanner}
%lex-param   {yyscan_t scanner}
%locations

%union{
int int_val;
std::string	*op_val;
}

%{
#define YY_NO_UNISTD_H
#include "calc_lexer.hpp"

int calc_lex( YYSTYPE *yyval, YYLTYPE * llocp, void* scanner );
void calc_error ( YYLTYPE *locp, yyscan_t scanner, char const *msg);
%}

%start input 

%token LEXER_ERROR
%token COLON
%token LBRACE
%token RBRACE
%token LCURL
%token RCURL

%token <op_val> ID

%token INT
%token VOID

%token <int_val> INTEGER_LITERAL
%left PLUS
%left MULT
%left DIV

%type <int_val>	exp
%type <op_val> function_name;

%%
input:   /* empty */
		| input line
		;

line:	declaration
		;

declaration:	type function_name LBRACE argument_list RBRACE LCURL statements RCURL { std::cout << "function: " << *$2 << std::endl; }
		;

type:	VOID | INT
		;
		
function_name: ID { $$ = $1; }
		;
		
argument_list: /* empty */
		;
	
statements: /* empty */
		| statements exp COLON
		;

exp:	INTEGER_LITERAL	{ $$ = $1; }
		| exp PLUS exp	{ $$ = $1 + $3; }
		| exp MULT exp	{ $$ = $1 * $3; }
		| exp DIV exp	{ $$ = $1 / $3; }
		| LBRACE exp RBRACE { $$ = $2; }
		;
%%

void calc_error ( YYLTYPE *locp, yyscan_t scanner, char const *msg)
{
	std::cerr << "ERROR: " << msg << " : \"" << calc_get_text( scanner ) << "\""
				" at " << 
				locp->first_line << ":" << locp->first_column << "-" <<
				locp->last_line << ":" << locp->last_column <<
				std::endl;
}
