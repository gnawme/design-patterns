/*--------------------------------------------------------------------*\
| \file     DuckSim.cpp
| \author   Norm Evangelista
| \brief    Duck Simulator implementation
\*--------------------------------------------------------------------*/
#include "DuckSim.hpp"
#include "DuckFly.hpp"
#include "DuckQuack.hpp"

#include <iostream>

/*--------------------------------------------------------------------*\
| \fn       DuckSim::DuckSim
| \brief    DuckSim constructor
\*--------------------------------------------------------------------*/
DuckSim::DuckSim(
    const char* whoAmI,
    DuckFly*    flyBehavior,
    DuckQuack*  quackBehavior )
    : whoAmI( whoAmI )
    , flyBehavior( flyBehavior )
    , quackBehavior( quackBehavior )
    {}

/*--------------------------------------------------------------------*\
| \fn       DuckSim::display
| \brief    Tells the world, loud and proud
\*--------------------------------------------------------------------*/
void DuckSim::display()
{
    std::cout
    << std::endl
    << "Duck type            : " << whoAmI 
    << std::endl
    << "Flight behavior      : " << flyBehavior->fly_ducky_fly() 
    << std::endl
    << "Quack characteristics: " << quackBehavior->quack_ducky_quack()
    << std::endl;
}