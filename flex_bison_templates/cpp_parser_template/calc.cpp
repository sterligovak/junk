#include <iostream>
#include <conio.h>

#include "calc_driver.hpp"

int main(int argc, char *argv[])
{
    calc_driver driver;
    for (++argv; argv[0]; ++argv)
    {
        if ( *argv == std::string ("-p") )
        {
            driver.trace_parsing = true;
        }
        else if ( *argv == std::string ("-s") )
        {
            driver.trace_scanning = true;
        }
        else if ( !driver.parse (*argv) )
        {
            std::cout << "parse stopped with error" << std::endl;
        }
    }

    _getch();
}
