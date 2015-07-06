#ifndef HFDP_WEATHERSTATION_SUBJECT_HPP
#define HFDP_WEATHERSTATION_SUBJECT_HPP
/*---------------------------------------------------------------------------*\
| \file     Subject.hpp
| \brief    Observer Design Pattern component interfaces
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <memory>

/*---------------------------------------------------------------------------*\
| \class    Observer
| \brief    Observer base class
\*---------------------------------------------------------------------------*/
class Observer
{
public:
    virtual        ~Observer() {};
    virtual void    update( float, float, float ) = 0;
};

typedef std::shared_ptr<Observer>   TObserverPtr;

/*---------------------------------------------------------------------------*\
| \class    Subject
| \brief    Subject base class
\*---------------------------------------------------------------------------*/
class Subject
{
public:
    virtual        ~Subject() {};

    virtual void    register_observer( TObserverPtr ) = 0;
    virtual void    remove_observer( TObserverPtr ) = 0;

    virtual void    notify_observers() = 0;

};

/*---------------------------------------------------------------------------*\
| \class    DisplayElement
| \brief    DisplayElement base class
\*---------------------------------------------------------------------------*/
class DisplayElement
{
public:
    virtual        ~DisplayElement() {};

    virtual void    display() = 0;
};


#endif//HFDP_WEATHERSTATION_SUBJECT_HPP
