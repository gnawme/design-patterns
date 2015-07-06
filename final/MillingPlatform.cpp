/*---------------------------------------------------------------------------*\
| \file     MillingPlatform.cpp
| \brief    Abstract Factory abstract and concrete products
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "MillingPlatform.hpp"
#include "AssemblyState.hpp"

#include <sstream>

/*---------------------------------------------------------------------------*\
| \fn       MillingPlatformHighCarbon::MillingPlatformHighCarbon
\*---------------------------------------------------------------------------*/
MillingPlatformHighCarbon::MillingPlatformHighCarbon(
    TInjectionPtr   injector )
    : m_injector( injector )
{}

/*---------------------------------------------------------------------------*\
| \fn       MillingPlatformHighCarbon::description
\*---------------------------------------------------------------------------*/
std::string MillingPlatformHighCarbon::description()
{
    AssemblyState state;

    std::stringstream ss;
    ss 
    << "\t\t\tusing HighCarbon tools "
    << "(drill, cut, and high speed grind) to mill "
    << m_injector->material()
    << " block into "
    << m_injector->num_cavities() 
    << " "
    << state.get_mold_shape()
    << " shapes with "
    << state.get_finish()
    << " finish."
    << std::endl;

    return std::string( ss.str() );
}

/*---------------------------------------------------------------------------*\
| \fn       MillingPlatformCarbide::MillingPlatformCarbide
\*---------------------------------------------------------------------------*/
MillingPlatformCarbide::MillingPlatformCarbide(
    TInjectionPtr   injector )
    : m_injector( injector )
{}

/*---------------------------------------------------------------------------*\
| \fn       MillingPlatformCarbide::description
\*---------------------------------------------------------------------------*/
std::string MillingPlatformCarbide::description()
{
    AssemblyState state;

    std::stringstream ss;
    ss 
    << "\t\t\tusing Carbide tools "
    << "(high speed drill, cross cut, and layer grind) to mill "
    << m_injector->material()
    << " block into "
    << m_injector->num_cavities() 
    << " "
    << state.get_mold_shape()
    << " shapes with "
    << state.get_finish()
    << " finish."
    << std::endl;

    return std::string( ss.str() );
}

/*---------------------------------------------------------------------------*\
| \fn       MillingPlatformDiamondTipped::MillingPlatformDiamondTipped
\*---------------------------------------------------------------------------*/
MillingPlatformDiamondTipped::MillingPlatformDiamondTipped(
    TInjectionPtr   injector )
    : m_injector( injector )
{}

/*---------------------------------------------------------------------------*\
| \fn       MillingPlatformDiamondTipped::description
\*---------------------------------------------------------------------------*/
std::string MillingPlatformDiamondTipped::description()
{
    AssemblyState state;

    std::stringstream ss;
    ss 
    << "\t\t\tusing DiamondTipped tools "
    << "(precision drill, oil cooled cut, and cartoid grind) to mill "
    << m_injector->material()
    << " block into "
    << m_injector->num_cavities() 
    << " "
    << state.get_mold_shape()
    << " shapes with "
    << state.get_finish()
    << " finish."
    << std::endl;

    return std::string( ss.str() );
}