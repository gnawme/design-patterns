/*---------------------------------------------------------------------------*\
| \file     Subject.cpp
| \brief    Observer Design Pattern component implementations
\*---------------------------------------------------------------------------*/
#include "WeatherData.hpp"

#include <algorithm>

/*---------------------------------------------------------------------------*\
| \fn       WeatherData::WeatherData
\*---------------------------------------------------------------------------*/
WeatherData::WeatherData()
    : m_temperature( 0.0 )
    , m_humidity( 0.0 )
    , m_pressure( 0.0 )
{}

/*---------------------------------------------------------------------------*\
| \fn       WeatherData::notify_observers
\*---------------------------------------------------------------------------*/
void WeatherData::notify_observers()
{
    for ( auto& it : m_observers )
    {
        it->update( m_temperature, m_humidity, m_pressure );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       WeatherData::register_observer
\*---------------------------------------------------------------------------*/
void WeatherData::register_observer
(   TObserverPtr    observer )
{
    m_observers.push_back( observer );
}

/*---------------------------------------------------------------------------*\
| \fn       WeatherData::remove_observer
\*---------------------------------------------------------------------------*/
void WeatherData::remove_observer
(   TObserverPtr    observer )
{
    /*-----------------------------------------------------------------------*\
    |   User remove-erase idiom
    \*-----------------------------------------------------------------------*/
    m_observers.erase( 
        std::remove( m_observers.begin(),  m_observers.end(), observer ), 
        m_observers.end() );
}


