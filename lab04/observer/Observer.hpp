#ifndef LAB04_OBSERVER_OBSERVER_HPP
#define LAB04_OBSERVER_OBSERVER_HPP
/*---------------------------------------------------------------------------*\
| \file     Observer.hpp
| \brief    Observer abstract base class
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*\
| \class    Observer
\*---------------------------------------------------------------------------*/
class Observer
{
public:
    virtual        ~Observer() {};

    virtual void    update() = 0;
};


#endif//LAB04_OBSERVER_OBSERVER_HPP