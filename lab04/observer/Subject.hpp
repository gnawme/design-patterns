#ifndef LAB04_OBSERVER_SUBJECT_HPP
#define LAB04_OBSERVER_SUBJECT_HPP
/*---------------------------------------------------------------------------*\
| \file     Subject.hpp
| \brief    Subject abstract base class
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <memory>

/*---------------------------------------------------------------------------*\
|  Convenience typedef
\*---------------------------------------------------------------------------*/
class Observer;
typedef std::shared_ptr<Observer>   TObserverPtr;

/*---------------------------------------------------------------------------*\
| \class    Subject
\*---------------------------------------------------------------------------*/
class Subject
{
public:
    virtual        ~Subject() {};

    virtual void    notify_observers() = 0;
    virtual void    register_observer( TObserverPtr ) = 0;
    virtual void    remove_observer( TObserverPtr ) = 0;
};

#endif//LAB04_OBSERVER_SUBJECT_HPP
