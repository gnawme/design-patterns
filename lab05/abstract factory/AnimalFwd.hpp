#ifndef LAB05_ABSTRACT_FACTORY_ANIMAL_FWD_HPP
#define LAB05_ABSTRACT_FACTORY_ANIMAL_FWD_HPP
/*---------------------------------------------------------------------------*\
| \file     AnimalFwd.hpp
| \brief    Centralized Predator and Prey forward declarations
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <memory>

/*---------------------------------------------------------------------------*\
|   Forward declarations
\*---------------------------------------------------------------------------*/
class Predator;
typedef std::shared_ptr<Predator>   TPredatorPtr;

class Prey;
typedef std::shared_ptr<Prey>       TPreyPtr;

#endif//LAB05_ABSTRACT_FACTORY_ANIMAL_FWD_HPP
