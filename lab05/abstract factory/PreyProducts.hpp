#ifndef LAB05_ABSTRACT_FACTORY_PREY_PRODUCTS_HPP
#define LAB05_ABSTRACT_FACTORY_PREY_PRODUCTS_HPP
/*---------------------------------------------------------------------------*\
| \file     PreyProducts.hpp
| \brief    Prey (Product B concrete products)
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Prey.hpp"
#include "AnimalFwd.hpp"

/*---------------------------------------------------------------------------*\
| \class    Bison
| \brief    Prey product for North America
\*---------------------------------------------------------------------------*/
class Bison: public Prey
{
public:
                Bison();

    void        evade( TPredatorPtr );
    void        graze();
    void        mate( TPreyPtr );

    std::string name();

private:
    std::string m_name;
};


/*---------------------------------------------------------------------------*\
| \class    Wildebeest
| \brief    Prey product for Africa
\*---------------------------------------------------------------------------*/
class Wildebeest: public Prey
{
public:
                Wildebeest();

    void        evade( TPredatorPtr );
    void        graze();
    void        mate( TPreyPtr );

    std::string name();

private:
    std::string m_name;
};


#endif//LAB05_ABSTRACT_FACTORY_PREY_PRODUCTS_HPP