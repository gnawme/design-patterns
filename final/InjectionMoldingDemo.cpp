/*---------------------------------------------------------------------------*\
| \file     InjectionMoldingDemo.cpp
| \brief    Main for Design Patterns final
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "OrderProcessing.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "AssemblyState.hpp"

/*---------------------------------------------------------------------------*\
| \fn       Main
\*---------------------------------------------------------------------------*/
int main(
    int     argc,
    char**  argv )
{
    if ( argc == 1 )
    /*-----------------------------------------------------------------------*\
    |   Usage note
    \*-----------------------------------------------------------------------*/
    {
        std::cerr 
        << "Usage: final_exam <input-file>" 
        << std::endl;
        return EXIT_FAILURE;
    }

    while ( *++argv )
    /*-----------------------------------------------------------------------*\
    |   Inhale argument vector
    \*-----------------------------------------------------------------------*/
    {
        char* filename = *argv;
        std::ifstream orderfile( filename, std::ios::in );
        std::cout << "Hello DP4." << std::endl << std::endl;
        std::cout << "<<< final design >>>" << std::endl;

        while ( orderfile )
        {
            TOrderMap one_order = get_complete_order( orderfile );

            if ( one_order.empty() )
                break;

            process( one_order );
        }

        orderfile.close();
    }

    std::cout << "Aloha DP4." << std::endl;

    return EXIT_SUCCESS;
}
