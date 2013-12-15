#include "calc_driver.hpp"
#include "calc_parser.hpp"

#define YY_NO_UNISTD_H
#include "calc_lexer.hpp"

calc_driver::calc_driver ()
  : trace_scanning (false), trace_parsing (false)
{
    variables["one"] = 1;
    variables["two"] = 2;
}

calc_driver::~calc_driver ()
{
}

bool calc_driver::parse (const std::string &f)
{
    file = f;

    yyscan_t scanner;
    calc_lex_init ( &scanner );
    scan_begin ( scanner );

    calc_::calc_parser parser ( scanner, *this);
    parser.set_debug_level (trace_parsing);
    int res = parser.parse ();

    scan_end( scanner );
    calc_lex_destroy ( scanner );

    return res == 0;
}

void calc_driver::error (const calc_::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void calc_driver::error (const std::string& m)
{
    std::cerr << m << std::endl;
}

void calc_driver::scan_begin( yyscan_t yyscanner )
{
    calc_set_debug( trace_scanning, yyscanner );
    if( file == "-" )
    {
        calc_set_in( stdin, yyscanner );
    }
    else
    {
        FILE* newIn  = fopen (file.c_str (), "r");
        if ( !newIn )
        {
            error ( std::string ("cannot open ") + file );
            exit (1);
        }
        else
        {
            calc_set_in( newIn, yyscanner );
        }   
    }
}

void calc_driver::scan_end( yyscan_t yyscanner )
{
    fclose ( calc_get_in(yyscanner) );
}
