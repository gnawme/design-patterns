#ifndef HFDP_WEATHERSTATION_WEATHER_DATA_HPP
#define HFDP_WEATHERSTATION_WEATHER_DATA_HPP
/*---------------------------------------------------------------------------*\
| \file     WeatherData
| \brief    Concrete Subject implementation
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Subject.hpp"

#include <vector>

typedef std::vector<TObserverPtr>   TObserverVec;

class WeatherData: public Subject
{
public:
                    WeatherData();

    void            notify_observers();
    void            register_observer( TObserverPtr );
    void            remove_observer( TObserverPtr );

    float           get_temperature();
    float           get_humidity();
    float           get_pressure();

private:
    TObserverVec    m_observers;
    float           m_temperature;
    float           m_humidity;
    float           m_pressure;
};

#endif//HFDP_WEATHERSTATION_WEATHER_DATA_HPP
