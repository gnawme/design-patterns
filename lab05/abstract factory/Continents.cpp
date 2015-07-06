/*---------------------------------------------------------------------------*\
| \file     Continents.cpp
| \brief    Continent ConcreteFactory classes
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Continents.hpp"

#include "PredatorProducts.hpp"
#include "PreyProducts.hpp"

/*---------------------------------------------------------------------------*\
| \fn       NorthAmerica::NorthAmerica
\*---------------------------------------------------------------------------*/
NorthAmerica::NorthAmerica()
    : m_continent( "North America" )
{}

/*---------------------------------------------------------------------------*\
| \fn       NorthAmerica::create_predator
\*---------------------------------------------------------------------------*/
TPredatorPtr NorthAmerica::create_predator()
{
    return std::make_shared<Wolf>();
}

/*---------------------------------------------------------------------------*\
| \fn       NorthAmerica::create_prey
\*---------------------------------------------------------------------------*/
TPreyPtr NorthAmerica::create_prey()
{
    return std::make_shared<Bison>();
}

/*---------------------------------------------------------------------------*\
| \fn       NorthAmerica::name
\*---------------------------------------------------------------------------*/
std::string NorthAmerica::name()
{
    return std::string( m_continent );
}

/*---------------------------------------------------------------------------*\
| \fn       Africa::Africa
\*---------------------------------------------------------------------------*/
Africa::Africa()
    : m_continent( "Africa" )
{}

/*---------------------------------------------------------------------------*\
| \fn       Africa::create_predator
\*---------------------------------------------------------------------------*/
TPredatorPtr Africa::create_predator()
{
    return std::make_shared<Lion>();
}

/*---------------------------------------------------------------------------*\
| \fn       Africa::create_prey
\*---------------------------------------------------------------------------*/
TPreyPtr Africa::create_prey()
{
    return std::make_shared<Wildebeest>();
}

/*---------------------------------------------------------------------------*\
| \fn       Africa::name
\*---------------------------------------------------------------------------*/
std::string Africa::name()
{
    return std::string( m_continent );
}

