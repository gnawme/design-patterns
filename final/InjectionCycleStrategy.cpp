/*---------------------------------------------------------------------------*\
| \file     InjectionCycleStrategy.cpp
| \brief    Injection cycle strategy classes
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "InjectionCycleStrategy.hpp"

namespace
{
/*---------------------------------------------------------------------------*\
| \fn       run_injection_cycle()
| \brief    Common function for injection cycle simulation
\*---------------------------------------------------------------------------*/
void run_injection_cycle(
    int             heat_temp,
    int             pressure,
    int             cool_temp,
    std::string&    ejection_technique )
{
    std::cout
    << "\t\t\tClose - "
    << "heat to "
    << heat_temp
    << " - inject at "
    << pressure
    << " PSI - cool to "
    << cool_temp
    << " - separate - "
    << ejection_technique
    << " eject."
    << std::endl;
}
}

/*---------------------------------------------------------------------------*\
| \fn       InjectionCycleStrategyABS::run_process()
| \brief    Simulates the injection cycle for ABS plastic
\*---------------------------------------------------------------------------*/
void InjectionCycleStrategyABS::run_process()
{
    run_injection_cycle( m_heat_temp, m_pressure, m_cool_temp, m_eject_technique );
}

/*---------------------------------------------------------------------------*\
| \fn       InjectionCycleStrategyPoly::run_process()
| \brief    Simulates the injection cycle for Poly plastic
\*---------------------------------------------------------------------------*/
void InjectionCycleStrategyPoly::run_process()
{
    run_injection_cycle( m_heat_temp, m_pressure, m_cool_temp, m_eject_technique );
}

/*---------------------------------------------------------------------------*\
| \fn       InjectionCycleStrategyPET::run_process()
| \brief    Simulates the injection cycle for PET plastic
\*---------------------------------------------------------------------------*/
void InjectionCycleStrategyPET::run_process()
{
    run_injection_cycle( m_heat_temp, m_pressure, m_cool_temp, m_eject_technique );
}

/*---------------------------------------------------------------------------*\
| \fn       InjectionCycleStrategyStyrene::run_process()
| \brief    Simulates the injection cycle for Styrene plastic
\*---------------------------------------------------------------------------*/
void InjectionCycleStrategyStyrene::run_process()
{
    run_injection_cycle( m_heat_temp, m_pressure, m_cool_temp, m_eject_technique );
}

/*---------------------------------------------------------------------------*\
| \fn       InjectionCycleStrategyNylon66::run_process()
| \brief    Simulates the injection cycle for Nylon66 plastic
\*---------------------------------------------------------------------------*/
void InjectionCycleStrategyNylon66::run_process()
{
    run_injection_cycle( m_heat_temp, m_pressure, m_cool_temp, m_eject_technique );
}

