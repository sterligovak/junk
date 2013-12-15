#ifndef CALC_DRIVER_HPP
#define CALC_DRIVER_HPP

#include <string>
#include <map>

#include "calc_parser.hpp"

// Tell Flex the lexer's prototype ...
# define YY_DECL \
  calc_::calc_parser::token_type \
  calc_lex ( calc_::calc_parser::semantic_type* yylval, \
         calc_::calc_parser::location_type* yylloc, \
         yyscan_t yyscanner, \
         calc_driver& driver) \
/**/

YY_DECL;

// Conducting the whole scanning and parsing of Calc++.
class calc_driver
{
public:
    calc_driver();
    virtual ~calc_driver();

    void scan_begin( yyscan_t yyscanner );
    void scan_end( yyscan_t yyscanner );

    bool parse(const std::string& f);

    // Error handling.
    void error( const calc_::location& l, const std::string& m );
    void error( const std::string& m );

public:
    bool trace_scanning;
    bool trace_parsing;

    std::string file;

    std::map<std::string, int> variables;
};

#endif // ! CALC_DRIVER_HPP

