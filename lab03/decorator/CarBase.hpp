#ifndef LAB03_DECORATOR_CAR_BASE_HPP
#define LAB03_DECORATOR_CAR_BASE_HPP
/*---------------------------------------------------------------------------*\
| \file     CarBase.hpp
| \brief    Decorator Pattern base Car and OptionsDecorator classes
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <string>

/*---------------------------------------------------------------------------*\
| \class    Car
| \brief    Car base class
\*---------------------------------------------------------------------------*/
class Car
{
public:
                        Car( std::string description = "Undefined model" )
                        : m_description( description )
                        {}

    virtual            ~Car() {};

    virtual std::string get_description()
                        { 
                            return m_description; 
                        }

    virtual double      get_cost() = 0;

protected:
    std::string         m_description;
};

/*---------------------------------------------------------------------------*\
| \class    OptionsDecorator
| \brief    Options Decorator base class
\*---------------------------------------------------------------------------*/
class OptionsDecorator: public Car
{
public:
                        OptionsDecorator( std::string description )
                        : m_description( description )
                        {}

    /*-----------------------------------------------------------------------*\
    | \note Concrete OptionsDecorators must implement
    \*-----------------------------------------------------------------------*/
    virtual std::string get_description() = 0;
    virtual double      get_cost() = 0;

protected:
    std::string         m_description;
};


#endif//LAB03_DECORATOR_CAR_BASE_HPP
