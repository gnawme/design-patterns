#ifndef LAB05_ABSTRACT_FACTORY_PREDATOR_PRODUCTS_HPP
#define LAB05_ABSTRACT_FACTORY_PREDATOR_PRODUCTS_HPP
/*---------------------------------------------------------------------------*\
| \file     PredatorProducts.hpp
| \brief    Predators (Product A concrete products)
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Predator.hpp"
#include "AnimalFwd.hpp"

/*---------------------------------------------------------------------------*\
| \class    Lion
| \brief    Predator product for Africa
\*---------------------------------------------------------------------------*/
class Lion: public Predator
{
public:
                Lion();

    void        eat( TPreyPtr );
    void        hunt();
    void        mate( TPredatorPtr );

    std::string name();

private:
    std::string m_name;
};

/*---------------------------------------------------------------------------*\
| \class    Wolf
| \brief    Predator product for North America
\*---------------------------------------------------------------------------*/
class Wolf: public Predator
{
public:
                Wolf();

    void        eat( TPreyPtr );
    void        hunt();
    void        mate( TPredatorPtr );

    std::string name();

private:
    std::string m_name;
};

#endif//LAB05_ABSTRACT_FACTORY_PREDATOR_PRODUCTS_HPP
