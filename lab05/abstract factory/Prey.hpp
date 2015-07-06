#ifndef LAB05_ABSTRACT_FACTORY_PREY_HPP
#define LAB05_ABSTRACT_FACTORY_PREY_HPP
/*---------------------------------------------------------------------------*\
| \file     Prey.hpp
| \brief    Prey abstract base class (AbstractProductB)
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AnimalFwd.hpp"

#include <string>

/*---------------------------------------------------------------------------*\
| \class    Prey
\*---------------------------------------------------------------------------*/
class Prey
{
public:
    virtual            ~Prey() {};

    virtual void        evade( TPredatorPtr ) = 0;
    virtual void        graze() = 0;
    virtual void        mate( TPreyPtr ) = 0;

    virtual std::string name() = 0;
};

#endif//LAB05_ABSTRACT_FACTORY_PREY_HPP
