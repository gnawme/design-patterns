#ifndef HFDP_STARBUZZ_CONDIMENTS_HPP
#define HFDP_STARBUZZ_CONDIMENTS_HPP
/*---------------------------------------------------------------------------*\
| \file     Condiments.hpp
| \brief    Condiment decorators based on Beverage class
\*---------------------------------------------------------------------------*/
#include "Beverage.hpp"

#include <memory>
#include <sstream>

typedef std::shared_ptr<Beverage>   TBeveragePtr;

/*---------------------------------------------------------------------------*\
| \class    Mocha
\*---------------------------------------------------------------------------*/
class Mocha: public CondimentDecorator
{
public:
                    Mocha( TBeveragePtr beverage )
                    : CondimentDecorator( "Mocha" )
                    , m_beverage( beverage )
                    , m_cost( 0.20 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_beverage->get_description()
                        << ", "
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_beverage->get_cost(); }

private:
    TBeveragePtr    m_beverage;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    Soy
\*---------------------------------------------------------------------------*/
class Soy: public CondimentDecorator
{
public:
                    Soy( TBeveragePtr beverage )
                    : CondimentDecorator( "Soy" )
                    , m_beverage( beverage )
                    , m_cost( 0.15 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_beverage->get_description()
                        << ", "
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_beverage->get_cost(); }

private:
    TBeveragePtr    m_beverage;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    SteamedMilk
\*---------------------------------------------------------------------------*/
class SteamedMilk: public CondimentDecorator
{
public:
                    SteamedMilk( TBeveragePtr beverage )
                    : CondimentDecorator( "Steamed Milk" )
                    , m_beverage( beverage )
                    , m_cost( 0.10 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_beverage->get_description()
                        << ", "
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_beverage->get_cost(); }

private:
    TBeveragePtr    m_beverage;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    Whip
\*---------------------------------------------------------------------------*/
class Whip: public CondimentDecorator
{
public:
                    Whip( TBeveragePtr beverage )
                    : CondimentDecorator( "Whip" )
                    , m_beverage( beverage )
                    , m_cost( 0.10 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_beverage->get_description()
                        << ", "
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_beverage->get_cost(); }

private:
    TBeveragePtr    m_beverage;
    double          m_cost;
};

#endif//HFDP_STARBUZZ_CONDIMENTS_HPP
