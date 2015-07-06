/*---------------------------------------------------------------------------*\
| \file     SeussObserverDemo.cpp
| \brief    Lab04 Observer Design Pattern demo
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "CatInTheHat.hpp"
#include "Characters.hpp"

#include <cstdlib>
#include <iostream>

int main()
{
    CatInTheHat the_cat;
    /*-----------------------------------------------------------------------*\
    |   Add initial set of Observers
    \*-----------------------------------------------------------------------*/
    TObserverPtr thing_one( std::make_shared<Thing>( "One" ) );
    TObserverPtr thing_two( std::make_shared<Thing>( "Two" ) );
    TObserverPtr fish( std::make_shared<Fish>() );
    TObserverPtr boy( std::make_shared<Child>( "Boy" ) );
    TObserverPtr girl( std::make_shared<Child>( "Girl" ) );

    the_cat.register_observer( thing_one );
    the_cat.register_observer( thing_two );
    the_cat.register_observer( fish );
    the_cat.register_observer( boy );
    the_cat.register_observer( girl );

    /*-----------------------------------------------------------------------*\
    |   After Event 1, Thing One detaches
    \*-----------------------------------------------------------------------*/
    the_cat.says( "Hello." );
    the_cat.remove_observer( thing_one );

    /*-----------------------------------------------------------------------*\
    |   Event 2
    \*-----------------------------------------------------------------------*/
    the_cat.says( "Let's play!" );

    /*-----------------------------------------------------------------------*\
    |   Event 3
    \*-----------------------------------------------------------------------*/
    the_cat.says( "Rock and roll." );

    /*-----------------------------------------------------------------------*\
    |   Cleanup ensues as Mom comes on the scene
    \*-----------------------------------------------------------------------*/
    the_cat.remove_observer( thing_two );
    the_cat.remove_observer( fish );
    the_cat.remove_observer( boy );
    the_cat.remove_observer( girl );

    the_cat.register_observer( TObserverPtr( std::make_shared<Mom>() ) );

    /*-----------------------------------------------------------------------*\
    |   Event 4
    \*-----------------------------------------------------------------------*/
    the_cat.says( "Good-bye." );
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
