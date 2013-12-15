%skeleton "lalr1.cc"
%require "2.4"
%defines
%define parser_class_name "calc_parser"
%name-prefix "calc_"

%code requires
{
#include <string>

class calc_driver;
typedef void* yyscan_t;
}

// The parsing context.
%parse-param { yyscan_t yyscanner }
%parse-param { calc_driver& driver }
%lex-param { yyscan_t yyscanner }
%lex-param { calc_driver& driver }

%locations

%initial-action
{
    // Initialize the initial location.
    @$.begin.filename = @$.end.filename = &driver.file;
};

%debug
%error-verbose

// Symbols.
%union
{
    std::string *sval;
};

%code {
#include "calc_driver.hpp"
}

%token END 0 "end of file"

%token CLASS "class"
%token '{'
%token '}'
%token '('
%token ')'
%token ';'
%token ','
%token '.'

%token <sval> IDENTIFIER "identifier"

%type <sval> function_declaration
%type <sval> function_header


%printer    { debug_stream () << *$$; } <sval>
%destructor { delete $$; } <sval>

%%

%start unit;

unit: declarations 
    ;

declarations: /* empty */
    | declarations declaration
    ;

declaration: CLASS IDENTIFIER '{' class_body '}' { std::cout << "class: " << *$2 << std::endl; }
    ;

class_body: class_elements
    ;

class_elements: /*empty*/
    | class_elements class_element;

class_element: function_declaration { std::cout << "function: " << *$1 << std::endl; }
    | var_declaration
    | error ';'
    ;

function_declaration: function_header ';' { $$ = $1; }  
    | function_header function_body { $$ = $1; }
    ;

function_header : IDENTIFIER IDENTIFIER '(' argument_list ')' { $$ = $2; }
    ;

argument_list: /* empty */
    | non_empty_argument_list
    ;

non_empty_argument_list : argument
    | non_empty_argument_list ',' argument
    ;

argument : IDENTIFIER IDENTIFIER
    ;

function_body : '{' statements '}'
    ;

statements : /* empty */
    | statements statement
    ;

statement: var_declaration ';'
    | function_call ';'
    | error ';'
    ;

var_declaration: IDENTIFIER IDENTIFIER
    ;

function_call: IDENTIFIER '.' IDENTIFIER '(' call_argument_list ')'
    ;

call_argument_list : /**/
    | non_empty_argument_list
    ;

non_empty_argument_list : non_empty_argument_list ',' call_argument
    ;

call_argument: IDENTIFIER
    ;
   
%%

void calc_::calc_parser::error (const calc_::calc_parser::location_type& l,
                          const std::string& m)
{
    driver.error (l, m);
}
