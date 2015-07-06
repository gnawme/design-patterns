#ifndef LAB05_ABSTRACT_FACTORY_CONTINENT_HPP
#define LAB05_ABSTRACT_FACTORY_CONTINENT_HPP
/*---------------------------------------------------------------------------*\
| \file     Continent.hpp
| \brief    Continent abstract base class (AbstractFactory)
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AnimalFwd.hpp"

#include <string>

/*---------------------------------------------------------------------------*\
| \class    Continent
\*---------------------------------------------------------------------------*/
class Continent
{
public:
    virtual TPredatorPtr    create_predator() = 0;
    virtual TPreyPtr        create_prey() = 0;
    virtual std::string     name() = 0;
};


#endif//LAB05_ABSTRACT_FACTORY_CONTINENT_HPP
