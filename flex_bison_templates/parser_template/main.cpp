/* main.cc */

#include <conio.h>
#include <iostream>

#include <boost/exception/all.hpp>
#include <boost/program_options.hpp>
#include <boost/foreach.hpp>

#include "calc_parser.hpp"

#define YY_NO_UNISTD_H
#include "calc_lexer.hpp"

int calc_parse( yyscan_t scanner );

namespace po = boost::program_options;

static po::variables_map ParseCommandLine( int argc, char **argv );

int main(int argc, char **argv)
{
    try
    {
        po::variables_map vm = ParseCommandLine( argc, argv );

        std::vector<std::string> inputFiles = vm["input-files"].as<std::vector<std::string> >();
        
        BOOST_FOREACH( std::string filename, inputFiles )
        {
            if ( freopen( filename.c_str(), "r", stdin) == NULL )
            {
                std::cerr << argv[0] << ": File " << argv[1] << " cannot be opened.\n";
                exit( 1 );
            }

            yyscan_t scanner;
            calc_lex_init( &scanner );
            calc_parse( scanner );
            calc_lex_destroy ( scanner );

            fclose( stdin );
        }

        _getch();
    }
    catch( ... )
    {
        return 1;
    }

    return 0;
}

struct HelpMessageDisplayed : std::exception, boost::exception
{
    virtual ~HelpMessageDisplayed() throw() {};
};

static po::variables_map ParseCommandLine( int argc, char **argv )
{
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "Print help message")
        ("input-files", po::value<std::vector<std::string> >()->composing(), "input file" )
    ;
    po::positional_options_description p;
    p.add("input-files", -1);

    po::variables_map vm;
    po::store( po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm );
    po::notify(vm);

    if ( vm.count( "help" ) )
    {
        std::cout << desc << "\n";
        throw HelpMessageDisplayed();
    }

    return vm;
}

