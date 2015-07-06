#ifndef LAB05_ABSTRACT_FACTORY_PREDATOR_HPP
#define LAB05_ABSTRACT_FACTORY_PREDATOR_HPP
/*---------------------------------------------------------------------------*\
| \file     Predator.hpp
| \brief    Predator abstract base class (AbstractProductA)
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AnimalFwd.hpp"

#include <string>

/*---------------------------------------------------------------------------*\
| \class    Predator
\*---------------------------------------------------------------------------*/
class Predator
{
public:
    virtual            ~Predator() {};

    virtual void        eat( TPreyPtr ) = 0;
    virtual void        hunt() = 0;
    virtual void        mate( TPredatorPtr ) = 0;

    virtual std::string name() = 0;
};


#endif//LAB05_ABSTRACT_FACTORY_PREDATOR_HPP
