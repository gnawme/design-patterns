/*---------------------------------------------------------------------------*\
| \file     ChainOfCommandDemo.cpp
| \brief    Demo for Chain of Responsibility design pattern lab
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Personnel.hpp"

#include <array>
#include <cstdlib>

/*---------------------------------------------------------------------------*\
| \fn       main
\*---------------------------------------------------------------------------*/
int main()
{
    /*-----------------------------------------------------------------------*\
    |   Instantiate components of chain
    \*-----------------------------------------------------------------------*/
    THandlerPtr lieutenant( std::make_shared<Lieutenant>() );
    THandlerPtr captain( std::make_shared<Captain>() );
    THandlerPtr major( std::make_shared<Major>() );
    THandlerPtr lite_colonel( std::make_shared<LieutenantColonel>() );
    THandlerPtr colonel( std::make_shared<Colonel>() );
    THandlerPtr general( std::make_shared<General>() );
    THandlerPtr pres( std::make_shared<CommanderInChief>() );

    /*-----------------------------------------------------------------------*\
    |   Construct the chain
    \*-----------------------------------------------------------------------*/
    lieutenant->set_superior( captain );
    captain->set_superior( major );
    major->set_superior( lite_colonel );
    lite_colonel->set_superior( colonel );
    colonel->set_superior( general );
    general->set_superior( pres );

    /*-----------------------------------------------------------------------*\
    |   Construct the request list and iterate through it
    \*-----------------------------------------------------------------------*/
    std::array<unsigned int, 5> requests = {1, 15, 25, 55, 99};

    for ( auto it : requests )
    {
        lieutenant->handle_request( it );
    }

    return EXIT_SUCCESS;
}