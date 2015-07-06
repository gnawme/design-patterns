/*---------------------------------------------------------------------------*\
| \file     CatInTheHat.cpp
| \brief    Concrete Subject implementation for Lab04 Observer Design Pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "CatInTheHat.hpp"

#include "Observer.hpp"

#include <algorithm>
#include <iostream>

/*---------------------------------------------------------------------------*\
| \fn       CatInTheHat::CatInTheHat
\*---------------------------------------------------------------------------*/
CatInTheHat::CatInTheHat()
{}

/*---------------------------------------------------------------------------*\
| \fn       CatInTheHat::~CatInTheHat
\*---------------------------------------------------------------------------*/
CatInTheHat::~CatInTheHat()
{
    std::cout
    << "\tThe Cat in the Hat is squashed flat."
    << std::endl;
}


/*---------------------------------------------------------------------------*\
| \fn       CatInTheHat::notify_observers
| \brief    Iterates through the Observers and calls their update function
\*---------------------------------------------------------------------------*/
void CatInTheHat::notify_observers()
{
    for ( auto& it : m_observers )
    {
        it->update();
    }
}

/*---------------------------------------------------------------------------*\
| \fn       CatInTheHat::register_observer
| \brief    Adds an Observer to the list
\*---------------------------------------------------------------------------*/
void CatInTheHat::register_observer
(   TObserverPtr    observer )
{
    m_observers.push_back( observer );
}

/*---------------------------------------------------------------------------*\
| \fn       CatInTheHat::remove_observer
| \brief    Removes an Observer from the list
\*---------------------------------------------------------------------------*/
void CatInTheHat::remove_observer
(   TObserverPtr    observer )
{
    TObserverVec::iterator obs = 
        std::find( m_observers.begin(), m_observers.end(), observer );

    if ( obs != m_observers.end() )
    {
        m_observers.erase( obs );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       CatInTheHat::says
| \brief    Echoes Cat in the Hat's latest utterance, and notifies observers
\*---------------------------------------------------------------------------*/
void CatInTheHat::says
(   const char* says )
{
    std::cout
    << std::endl
    << "The Cat in the Hat says \""
    << says
    << "\""
    << std::endl;

    notify_observers();
}



