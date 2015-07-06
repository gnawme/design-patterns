/*---------------------------------------------------------------------------*\
| \file     SmartHomeFacade.cpp
| \brief    Implementation of Facade for smart home components
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "SmartHomeFacade.hpp"

#include "AcmeSmartHomeComponents.h"

using namespace acme_home;

/*---------------------------------------------------------------------------*\
| \fn       SmartHomeFacade::SmartHomeFacade
\*---------------------------------------------------------------------------*/
SmartHomeFacade::SmartHomeFacade()
    : m_alarm( new Alarm )
    , m_ac( new AC )
    , m_tv( new TV )
    , m_lights( new Lights )
{}

/*---------------------------------------------------------------------------*\
| \fn       SmartHomeFacade::client_arriving
| \brief    Implements client arriving functionality
\*---------------------------------------------------------------------------*/
void SmartHomeFacade::client_arriving()
{
    std::cout 
    << std::endl 
    << "A good traveler has no fixed plans, and is not intent on arriving." 
    << std::endl;

    m_alarm->off();
    m_ac->on();
    m_tv->on();
    m_lights->on();
}

/*---------------------------------------------------------------------------*\
| \fn       SmartHomeFacade::client_leaving
| \brief    Implements client leaving functionality
\*---------------------------------------------------------------------------*/
void SmartHomeFacade::client_leaving()
{
    std::cout 
    << std::endl 
    << "Elvis has left the building." 
    << std::endl;

    m_alarm->on();
    m_ac->off();
    m_tv->off();
    m_lights->off();
}

/*---------------------------------------------------------------------------*\
| \fn       SmartHomeFacade::demo
| \brief    Implements the client demo
\*---------------------------------------------------------------------------*/
void SmartHomeFacade::demo()
{
    client_leaving();
    client_arriving();
}