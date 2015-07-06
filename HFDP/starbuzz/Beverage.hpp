#ifndef HFDP_STARBUZZ_BEVERAGE_HPP
#define HFDP_STARBUZZ_BEVERAGE_HPP
/*---------------------------------------------------------------------------*\
| \file     Beverage.hpp
| \brief    C++ implementation of HFDP Decorator example
\*---------------------------------------------------------------------------*/
#include <string>

/*---------------------------------------------------------------------------*\
| \class    Beverage
| \brief    Beverage base class
\*---------------------------------------------------------------------------*/
class Beverage
{
public:
                        Beverage( std::string description = "Unknown beverage" )
                        : m_description( description )
                        {}

    virtual            ~Beverage() {};

    virtual std::string get_description()
                        {
                            return m_description;
                        }

    virtual double      get_cost() = 0;

protected:
    std::string         m_description;
};

/*---------------------------------------------------------------------------*\
| \class    CondimentDecorator
| \brief    CondimentDecorator base class
\*---------------------------------------------------------------------------*/
class CondimentDecorator: public Beverage
{
public:
                        CondimentDecorator( std::string description )
                        : m_description( description )
                        {}

    virtual            ~CondimentDecorator() {};

    virtual std::string get_description() = 0;
    virtual double      get_cost() = 0;

protected:
    std::string         m_description;
};

#endif//HFDP_STARBUZZ_BEVERAGE_HPP
