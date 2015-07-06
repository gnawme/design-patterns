#ifndef HFDP_STARBUZZ_DRINKS_HPP
#define HFDP_STARBUZZ_DRINKS_HPP
/*---------------------------------------------------------------------------*\
| \file     Drinks.hpp
| \brief    Beverages based on Beverage class
\*---------------------------------------------------------------------------*/
#include "Beverage.hpp"

/*---------------------------------------------------------------------------*\
| \class    DarkRoast
\*---------------------------------------------------------------------------*/
class DarkRoast: public Beverage
{
public:
                DarkRoast()
                : Beverage( "Dark Roast" )
                , m_cost( 0.99 )
                {}

    double      get_cost() { return m_cost; }

private:
    double      m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    Decaf
\*---------------------------------------------------------------------------*/
class Decaf: public Beverage
{
public:
                Decaf()
                : Beverage( "Decaf" )
                , m_cost( 1.05 )
                {}

    double      get_cost() { return m_cost; }

private:
    double      m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    Espresso
\*---------------------------------------------------------------------------*/
class Espresso: public Beverage
{
public:
                Espresso()
                : Beverage( "Espresso" )
                , m_cost( 1.99 )
                {}

    double      get_cost() { return m_cost; }

private:
    double      m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    HouseBlend
\*---------------------------------------------------------------------------*/
class HouseBlend: public Beverage
{
public:
                HouseBlend()
                : Beverage( "House Blend" )
                , m_cost( 0.89 )
                {}

    double      get_cost() { return m_cost; }

private:
    double      m_cost;
};

#endif//HFDP_STARBUZZ_DRINKS_HPP