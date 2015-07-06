/*---------------------------------------------------------------------------*\
| \file     OutputBinObserver.cpp
| \brief    Subject and Observer classes for OutputBin
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "OutputBinObserver.hpp"

/*---------------------------------------------------------------------------*\
| \fn       OutputBinSubject::notify_observers
| \brief    Iterates through the Observers and calls their update function
\*---------------------------------------------------------------------------*/
void OutputBinSubject::notify_observers()
{
    for ( auto& observer : m_observers )
    {
        observer->update( m_description );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       OutputBinSubject::register_observer
| \brief    Adds an Observer to the list
\*---------------------------------------------------------------------------*/
void OutputBinSubject::register_observer
(   TObserverPtr    observer )
{
    m_observers.push_back( observer );
}

/*---------------------------------------------------------------------------*\
| \fn       OutputBinSubject::remove_observer
| \brief    Removes an Observer from the list
| \note     Can't use remove-erase idiom on container of pointers
\*---------------------------------------------------------------------------*/
void OutputBinSubject::remove_observer
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
| \fn       OutputBinSubject::issue_alert
| \brief    Issues an alert, and notifies all observers
\*---------------------------------------------------------------------------*/
void OutputBinSubject::issue_alert(
    const char* alert )
{
    std::cout
    << "\t\t\t"
    << m_description
    << " "
    << alert
    << std::endl;

    notify_observers();
}
