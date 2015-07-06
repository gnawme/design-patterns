/*---------------------------------------------------------------------------*\
| \file     MoldMetal.cpp
| \brief    Abstract Factory for mold metals and their products
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "MoldMetal.hpp"

#include "AssemblyState.hpp"
#include "MillingPlatform.hpp"

/*---------------------------------------------------------------------------*\
| \fn       MoldMetalAluminum::MoldMetalAluminum
\*---------------------------------------------------------------------------*/
MoldMetalAluminum::MoldMetalAluminum(
    TInjectionPtr   injector )
    : m_injector( injector )
{}

/*---------------------------------------------------------------------------*\
| \fn       MoldMetalAluminum::get_milling_platform
| \brief    Instantiates milling platform specific to this mold metal
\*---------------------------------------------------------------------------*/
TMillPlatformPtr MoldMetalAluminum::get_milling_platform()
{
    return std::make_shared<MillingPlatformHighCarbon>( m_injector );
}

/*---------------------------------------------------------------------------*\
| \fn       MoldMetalSteel::MoldMetalSteel
\*---------------------------------------------------------------------------*/
MoldMetalSteel::MoldMetalSteel(
    TInjectionPtr   injector )
    : m_injector( injector )
{}

/*---------------------------------------------------------------------------*\
| \fn       MoldMetalSteel::get_milling_platform
| \brief    Instantiates milling platform specific to this mold metal
\*---------------------------------------------------------------------------*/
TMillPlatformPtr MoldMetalSteel::get_milling_platform()
{
    AssemblyState state;
    if ( state.get_finish() == "satin" )
    {
        return std::make_shared<MillingPlatformDiamondTipped>( m_injector );
    }
    else
    {
        return std::make_shared<MillingPlatformCarbide>( m_injector );
    }

}
