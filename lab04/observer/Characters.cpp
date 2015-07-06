/*---------------------------------------------------------------------------*\
| \file     Characters.cpp
| \brief    Concrete Observers implementations for Lab04 Observer Design Pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Characters.hpp"

#include <iostream>

/*---------------------------------------------------------------------------*\
| \fn       Thing::Thing
\*---------------------------------------------------------------------------*/
Thing::Thing
(   const std::string&  name )
    : m_name( name )
{}

/*---------------------------------------------------------------------------*\
| \fn       Thing::~Thing
\*---------------------------------------------------------------------------*/
Thing::~Thing()
{
    std::cout 
    << "\tThing " 
    << m_name 
    << " leaves." 
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       Thing::make_mischief
\*---------------------------------------------------------------------------*/
void Thing::make_mischief()
{
    std::cout 
    << "\tThing " 
    << m_name 
    << " makes mischief." 
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       Thing::update
| \brief    Allows pinging by Subject
\*---------------------------------------------------------------------------*/
void Thing::update()
{
    make_mischief();
}

/*---------------------------------------------------------------------------*\
| \fn       Fish::Fish
\*---------------------------------------------------------------------------*/
Fish::Fish()
{}

/*---------------------------------------------------------------------------*\
| \fn       Fish::~Fish
\*---------------------------------------------------------------------------*/
Fish::~Fish()
{
    std::cout 
    << "\tFish " 
    << " swims into its castle." 
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       Fish::complains
\*---------------------------------------------------------------------------*/
void Fish::complains()
{
    std::cout 
    << "\tFish complains." 
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       Fish::update
| \brief    Allows pinging by Subject
\*---------------------------------------------------------------------------*/
void Fish::update()
{
    complains();
}

/*---------------------------------------------------------------------------*\
| \fn       Child::Child
\*---------------------------------------------------------------------------*/
Child::Child
(   const std::string&  gender )
    : m_name( gender == "Boy" ? "Dick" : "Sally" )
{}

/*---------------------------------------------------------------------------*\
| \fn       Child::~Child
\*---------------------------------------------------------------------------*/
Child::~Child()
{
    std::cout 
    << "\t" 
    << m_name 
    << " goes to bed." 
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       Child::has_fun
\*---------------------------------------------------------------------------*/
void Child::has_fun()
{
    std::cout 
    << "\t" 
    << m_name 
    << " has fun." 
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       Child::update
| \brief    Allows pinging by Subject
\*---------------------------------------------------------------------------*/
void Child::update()
{
    has_fun();
}

/*---------------------------------------------------------------------------*\
| \fn       Mom::Mom
\*---------------------------------------------------------------------------*/
Mom::Mom()
{}

/*---------------------------------------------------------------------------*\
| \fn       Mom::~Mom
\*---------------------------------------------------------------------------*/
Mom::~Mom()
{
    std::cout 
    << "\tMom goes to living room." 
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       Mom::returns
\*---------------------------------------------------------------------------*/
void Mom::returns()
{
    std::cout 
    << "\tMom returns." 
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       Mom::update
| \brief    Allows pinging by Subject
\*---------------------------------------------------------------------------*/
void Mom::update()
{
    returns();
}

