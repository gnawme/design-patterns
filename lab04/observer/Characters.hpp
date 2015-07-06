#ifndef LAB04_OBSERVER_CHARACTERS_HPP
#define LAB04_OBSERVER_CHARACTERS_HPP
/*---------------------------------------------------------------------------*\
| \file     Characters.hpp
| \brief    Concrete Observers for Lab04 Observer Design Pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Observer.hpp"

#include <string>

/*---------------------------------------------------------------------------*\
| \class    Thing
| \brief    Thing One and Thing Two
\*---------------------------------------------------------------------------*/
class Thing: public Observer
{
public:
                Thing( const std::string& );
               ~Thing();

    void        make_mischief();
    void        update();

private:
    std::string m_name;
};

/*---------------------------------------------------------------------------*\
| \class    Fish
| \brief    The Fish
\*---------------------------------------------------------------------------*/
class Fish: public Observer
{
public:
                Fish();
               ~Fish();

    void        complains();
    void        update();
};

/*---------------------------------------------------------------------------*\
| \class    Child
| \brief    Dick or Sally
\*---------------------------------------------------------------------------*/
class Child: public Observer
{
public:
                Child( const std::string& );
               ~Child();

    void        has_fun();
    void        update();

private:
    std::string m_name;
};

/*---------------------------------------------------------------------------*\
| \class    Mom
| \brief    The Mom
\*---------------------------------------------------------------------------*/
class Mom: public Observer
{
public:
                Mom();
               ~Mom();

    void        returns();
    void        update();
};



#endif//LAB04_OBSERVER_CHARACTERS_HPP