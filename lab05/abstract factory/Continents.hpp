#ifndef LAB05_ABSTRACT_FACTORY_CONTINENTS_HPP
#define LAB05_ABSTRACT_FACTORY_CONTINENTS_HPP
/*---------------------------------------------------------------------------*\
| \file     Continents.hpp
| \brief    Continent ConcreteFactory classes
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Continent.hpp"

/*---------------------------------------------------------------------------*\
| \enum     Continents
| \brief    Continents enumerators
\*---------------------------------------------------------------------------*/
enum Continents
{
    e_Africa,
    e_NorthAmerica
};

/*---------------------------------------------------------------------------*\
| \class    NorthAmerica
\*---------------------------------------------------------------------------*/
class NorthAmerica: public Continent
{
public:
                    NorthAmerica();

    TPredatorPtr    create_predator();
    TPreyPtr        create_prey();

    std::string     name();

private:
    std::string     m_continent;
};

/*---------------------------------------------------------------------------*\
| \class    Africa
\*---------------------------------------------------------------------------*/
class Africa: public Continent
{
public:
                    Africa();

    TPredatorPtr    create_predator();
    TPreyPtr        create_prey();

    std::string     name();

private:
    std::string     m_continent;
};

typedef std::shared_ptr<Continent>  TContinentPtr;

#endif//LAB05_ABSTRACT_FACTORY_CONTINENTS_HPP