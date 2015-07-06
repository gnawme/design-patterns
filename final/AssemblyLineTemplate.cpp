/*---------------------------------------------------------------------------*\
| \file     AssemblyLineTemplate.cpp
| \brief    Injection molding assembly line simulation
| \note     Uses the Template Method pattern to define a default process
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AssemblyLineTemplate.hpp"

#include "AssemblyState.hpp"
#include "MillingPlatform.hpp"

#include <iostream>
#include <sstream>

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::AssemblyLineTemplate
| \brief    Constructor
\*---------------------------------------------------------------------------*/
AssemblyLineTemplate::AssemblyLineTemplate(
    const TOrderMap& order )
    : m_order( order )
{}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::~AssemblyLineTemplate
| \brief    Virtual destructor
\*---------------------------------------------------------------------------*/
AssemblyLineTemplate::~AssemblyLineTemplate()
{
    std::cout << "~AssemblyLineTemplate " << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::process_order
| \brief    AssemblyLineTemplate template method
\*---------------------------------------------------------------------------*/
void AssemblyLineTemplate::process_order()
{
    setup_injection_line();

    std::cout << "\tProcess order." << std::endl;
    pull_mold();
    insert_tags();
    load_additive_bins();
    run_injection_cycle();
    clean_mold();
    ship();
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::setup_injection_line
| \brief    Step 1
\*---------------------------------------------------------------------------*/
void AssemblyLineTemplate::setup_injection_line()
{
    AssemblyState state;

    OrderScale order_scale = state.get_order_scale();
    m_injector = 
        InjectionMachineFactory::get_injection_molding_machine( order_scale );

    /*-----------------------------------------------------------------------*\
    |   Sort of a Strategy, sort of a Bridge based on order scale
    \*-----------------------------------------------------------------------*/
    switch( order_scale )
    {
    case ORDER_SMALL:
        m_order_scale_strategy = std::make_shared<OrderScaleSmall>();
        m_injector = m_order_scale_strategy->get_injection_machine();
        break;
    case ORDER_MEDIUM:
        m_order_scale_strategy = std::make_shared<OrderScaleMedium>();
        m_injector = m_order_scale_strategy->get_injection_machine();
        break;
    case ORDER_FAST:
        m_order_scale_strategy = std::make_shared<OrderScaleFast>();
        m_injector = m_order_scale_strategy->get_injection_machine();
        break;
    case ORDER_LARGE:
        m_order_scale_strategy = std::make_shared<OrderScaleLarge>();
        m_injector = m_order_scale_strategy->get_injection_machine();
        break;
    case ORDER_JUMBO:
        m_order_scale_strategy = std::make_shared<OrderScaleJumbo>();
        m_injector = m_order_scale_strategy->get_injection_machine();
        break;
    case ORDER_HUGE:
        m_order_scale_strategy = std::make_shared<OrderScaleHuge>();
        m_injector = m_order_scale_strategy->get_injection_machine();
        break;
    }

    /*-----------------------------------------------------------------------*\
    |   Run size is order size divided by the number of mold cavities
    \*-----------------------------------------------------------------------*/
    int order_size = state.get_order_size();
    int run_size = order_size / m_injector->num_cavities();
    state.set_run_size( run_size );

    std::string packager = state.get_packager();
    std::string stuffer  = state.get_stuffer();

    std::cout
    << "\tSetup injection line for "
    << run_size
    << " run with "
    << packager
    << " packager and "
    << stuffer 
    << " stuffing:"
    << std::endl;

    std::cout
    << m_injector->description()
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::pull_mold
| \brief    Step 2
\*---------------------------------------------------------------------------*/
void AssemblyLineTemplate::pull_mold()
{
    bool mold_location = check_key( m_order, "moldLoc" );
    bool mold_shape    = check_key( m_order, "mold" );
    bool incomplete    = ( mold_location == false ) || ( mold_shape == false );

    AssemblyState state;
    if ( mold_shape == false )
    {
        state.set_mold_shape( std::string( "duck" ) );
    }

    if ( mold_location == false )
    {
        state.set_mold_location( std::string( "inventory" ) );
    }

    if ( incomplete )
    {
        std::cout 
        << "\t\t<>Can't find place |"
        << m_order["moldLoc"]
        << "| to get |"
        << m_order["mold"]
        << "| mold from, defaulting to duck from inventory."
        << std::endl;
    }
    else
    {
        state.set_mold_shape( m_order["mold"] );
        state.set_mold_location( m_order["moldLoc"] );

        switch( state.get_mold_location_type( m_order["moldLoc"] ) )
        {
        case e_Inventory:
        {
            std::cout
            << "\t\tPull "
            << state.get_mold_shape()
            << " mold from "
            << state.get_mold_location()
            << "."
            << std::endl;
        }
            break;

        case e_SisterCompany:
        {
            std::cout
            << "\t\tBorrow "
            << state.get_mold_shape()
            << " mold from sister company."
            << std::endl;
        }
            break;

        case e_Purchase:
        {
            std::cout
            << "\t\tAcquire "
            << state.get_mold_shape()
            << " mold via purchase."
            << std::endl;
        }
            break;

        case e_Mill:
        {
            state.set_finish( m_order["finish"] );
            std::cout
            << "\t\tCreate "
            << state.get_mold_shape()
            << " mold from "
            << state.get_mold_location()
            << " with "
            << m_injector->num_cavities()
            << " cavities:"
            << std::endl;

            if ( m_injector->material() == "Aluminum" )
            {
                m_mold_metal = std::make_shared<MoldMetalAluminum>( m_injector );
            }
            else if ( m_injector->material() == "Steel" )
            {
                m_mold_metal = std::make_shared<MoldMetalSteel>( m_injector );
            }

            m_milling_platform = m_mold_metal->get_milling_platform();
            std::cout << m_milling_platform->description();
        }
            break;
        }
    }
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::insert_tags
| \brief    Step 3
\*---------------------------------------------------------------------------*/
void AssemblyLineTemplate::insert_tags()
{
    AssemblyState state;
    bool has_tags = check_key( m_order, "tags" );
    /*-----------------------------------------------------------------------*\
    |   Pull any tags from order
    \*-----------------------------------------------------------------------*/
    if ( has_tags )
    {
        state.set_tags( m_order[ "tags" ] );
    }

    /*-----------------------------------------------------------------------*\
    |   Accumulate tags and tag size, total space for tags is 20mm
    \*-----------------------------------------------------------------------*/
    int taglen = 0;
    TStringVec tags = state.get_tags();
    std::stringstream ss;
    for ( auto tag : tags )
    {
        ss << tag << " ";
        taglen += state.get_tag_size( tag );
    }

    std::cout
    << "\t\tInsert tags ["
    << ss.str()
    << "] of width "
    << taglen
    << "/20 mm."
    << std::endl;

    /*-----------------------------------------------------------------------*\
    |   Flag bad tags
    \*-----------------------------------------------------------------------*/
    TStringVec badtags = state.get_invalid_tags();
    if ( !badtags.empty() )
    {
        for ( auto bad : badtags )
        {
            std::cout
            << "\t\tIgnoring unknown tag "
            << bad
            << std::endl;
        }
    }
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::load_additive_bins
| \brief    Step 4
| \note     Has virtual hook
\*---------------------------------------------------------------------------*/
void AssemblyLineTemplate::load_additive_bins()
{
    std::cout 
    << "\t\tLoad plastic, color, and additive bins." 
    << std::endl;

    /*-----------------------------------------------------------------------*\
    |   Get color specified
    \*-----------------------------------------------------------------------*/
    AssemblyState state;
    bool has_color = check_key( m_order, "color" );
    if ( has_color )
    {
        state.set_color( m_order[ "color" ] );
    }
    else
    {
        std::cout
        << "\t\t\t<>No color specified, defaulting to black."
        << std::endl;
    }

    /*-----------------------------------------------------------------------*\
    |   Get additives
    \*-----------------------------------------------------------------------*/
    for ( auto additive : c_valid_additives )
    {
        bool has_additive = check_key( m_order, additive );
        if ( has_additive )
        {
            int volume = std::stoi( m_order[additive] );
            state.set_additive( additive, volume );
        }  
    }

    load_additive_hook();

    /*-----------------------------------------------------------------------*\
    |   Output aggregated description and volume
    \*-----------------------------------------------------------------------*/
    int volume = m_injector->num_cavities() * m_recipe->volume();
    std::cout
    << "\t\t\tRecipe: "
    << m_recipe->description()
    << " Total = "
    << volume
    << "."
    << std::endl;

}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::run_injection_cycle
| \brief    Step 5
| \note     Virtual, no default implementation
\*---------------------------------------------------------------------------*/
void AssemblyLineTemplate::run_injection_cycle()
{}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::clean_mold
| \brief    Step 6
| \note     Virtual, no default implementation
\*---------------------------------------------------------------------------*/
void AssemblyLineTemplate::clean_mold()
{}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineTemplate::ship
| \brief    Step 7
\*---------------------------------------------------------------------------*/
void AssemblyLineTemplate::ship()
{
    AssemblyState state;
    state.set_address( m_order["address"] );

    std::cout 
    << "\t\tShip to \""
    << state.get_address()
    << "\""
    << std::endl;
}

