#ifndef LAB04_OBSERVER_CAT_IN_THE_HAT_HPP
#define LAB04_OBSERVER_CAT_IN_THE_HAT_HPP
/*---------------------------------------------------------------------------*\
| \file     CatInTheHat.hpp
| \brief    Concrete Subject for Lab04 Observer Design Pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Subject.hpp"

#include <vector>

typedef std::vector<TObserverPtr>   TObserverVec;

class CatInTheHat: public Subject
{
public:
            CatInTheHat();
           ~CatInTheHat();

    void    notify_observers();
    void    register_observer( TObserverPtr );
    void    remove_observer( TObserverPtr );

    void    says( const char* );

private:
    TObserverVec    m_observers;
};

#endif//LAB04_OBSERVER_CAT_IN_THE_HAT_HPP

