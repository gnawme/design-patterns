#ifndef LAB03_DECORATOR_MODELS_HPP
#define LAB03_DECORATOR_MODELS_HPP
/*---------------------------------------------------------------------------*\
| \file     Models.hpp
| \brief    Decorator Pattern concrete components
| \note     Only one concrete component in class problem
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "CarBase.hpp"

#include <string>

/*---------------------------------------------------------------------------*\
| \class    BaseModel
| \brief    BaseModel for Cars in class problem
\*---------------------------------------------------------------------------*/
class BaseModel: public Car
{
public:
                BaseModel( std::string description )
                : Car( description )
                , m_cost( 12000.00 )
                {}

               ~BaseModel() {};

    std::string get_description()
                { 
                    return m_description; 
                }

    double      get_cost()
                {
                    return m_cost;
                }

private:
    double      m_cost;
};

#endif//LAB03_DECORATOR_MODELS_HPP