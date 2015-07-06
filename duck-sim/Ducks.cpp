/*--------------------------------------------------------------------*\
| \file     Ducks.cpp
| \author   Norm Evangelista
| \brief    Duck Simulator for VPG Design Patterns pre-work
\*--------------------------------------------------------------------*/
#include "DuckSim.hpp"

#include "DuckFly.hpp"
#include "DuckQuack.hpp"

#include <cstdlib>

int main( void )
{
    /*----------------------------------------------------------------*\
    |   Define our duck products
    \*----------------------------------------------------------------*/
    DuckSim mallard( "I'm a mallard", new DuckFlyNormal, new DuckQuackStandard );

    DuckSim luckyDucky( "I'm a lucky duck", new DuckFlyHigh, new DuckQuackClassic );

    DuckSim decoy( "I'm a duck decoy", new DuckFlyNull, new DuckQuackRetro );

    DuckSim rubberDucky( "I'm a rubber ducky!", new DuckFlyNormal, new DuckQuackStandard );

    /*----------------------------------------------------------------*\
    |   Display their characteristics
    \*----------------------------------------------------------------*/
    mallard.display();
    luckyDucky.display();
    decoy.display();
    rubberDucky.display();

    return EXIT_SUCCESS;
}