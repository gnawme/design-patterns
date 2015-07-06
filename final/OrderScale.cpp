/*---------------------------------------------------------------------------*\
| \file     OrderScale.cpp
| \brief    Strategies for constructing injector based on order size
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "OrderScale.hpp"

#include "AssemblyLines.hpp"

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleSmall::OrderScaleSmall
\*---------------------------------------------------------------------------*/
OrderScaleSmall::OrderScaleSmall()
    : m_order_scale( ORDER_SMALL )
    , m_conveyor_belt( "Linear" )
    , m_output_bin( "CardboardBox" )
{
    AssemblyState state;
    state.set_conveyor_belt( m_conveyor_belt );
    state.set_output_bin( m_output_bin );
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleSmall::get_injection_machine
| \brief    Decorates an injection assembly line appropriate for order size
\*---------------------------------------------------------------------------*/
TInjectionPtr OrderScaleSmall::get_injection_machine()
{
    TInjectionPtr injector = 
        InjectionMachineFactory::get_injection_molding_machine( m_order_scale );

    m_bin_subject = 
        std::make_shared<OutputBinSubject>( "CardboardBox package bin" );
    m_bin_subject->register_observer( injector );

    injector = std::make_shared<ConveyorBeltLinear>( injector );
    m_bin_subject->register_observer( injector );
    injector = std::make_shared<PackagerCardboardBox>( injector );
    m_bin_subject->register_observer( injector );

    AssemblyState state;
    StufferType stuffer = state.get_stuffer_type( state.get_stuffer() );
    injector = StufferFactory::get_stuffer( injector, stuffer );
    m_bin_subject->register_observer( injector );

    return injector;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleSmall::get_bin_publisher
\*---------------------------------------------------------------------------*/
TSubjectPtr OrderScaleSmall::get_bin_publisher()
{
    return m_bin_subject;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleMedium::OrderScaleMedium
\*---------------------------------------------------------------------------*/
OrderScaleMedium::OrderScaleMedium()
    : m_order_scale( ORDER_MEDIUM )
    , m_conveyor_belt( "Y-Split" )
    , m_output_bin( "CardboardBox" )
{
    AssemblyState state;
    state.set_conveyor_belt( m_conveyor_belt );
    state.set_output_bin( m_output_bin );
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleMedium::get_injection_machine
| \brief    Decorates an injection assembly line appropriate for order size
\*---------------------------------------------------------------------------*/
TInjectionPtr OrderScaleMedium::get_injection_machine()
{
    TInjectionPtr injector = 
        InjectionMachineFactory::get_injection_molding_machine( m_order_scale );

    m_bin_subject = 
        std::make_shared<OutputBinSubject>( "CardboardBox package bin" );
    m_bin_subject->register_observer( injector );

    injector = std::make_shared<ConveyorBeltYSplit>( injector );
    m_bin_subject->register_observer( injector );
    injector = std::make_shared<PackagerCardboardBox>( injector );
    m_bin_subject->register_observer( injector );

    AssemblyState state;
    StufferType stuffer = state.get_stuffer_type( state.get_stuffer() );
    injector = StufferFactory::get_stuffer( injector, stuffer );
    m_bin_subject->register_observer( injector );

    return injector;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleMedium::get_bin_publisher
\*---------------------------------------------------------------------------*/
TSubjectPtr OrderScaleMedium::get_bin_publisher()
{
    return m_bin_subject;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleFast::OrderScaleFast
\*---------------------------------------------------------------------------*/
OrderScaleFast::OrderScaleFast()
    : m_order_scale( ORDER_FAST )
    , m_conveyor_belt( "V-Level" )
    , m_output_bin( "PalletBox" )
{
    AssemblyState state;
    state.set_conveyor_belt( m_conveyor_belt );
    state.set_output_bin( m_output_bin );
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleFast::get_injection_machine
| \brief    Decorates an injection assembly line appropriate for order size
\*---------------------------------------------------------------------------*/
TInjectionPtr OrderScaleFast::get_injection_machine()
{
    TInjectionPtr injector = 
        InjectionMachineFactory::get_injection_molding_machine( m_order_scale );

    m_bin_subject = 
        std::make_shared<OutputBinSubject>( "PalletBox package bin" );
    m_bin_subject->register_observer( injector );

    injector = std::make_shared<ConveyorBeltVLevel>( injector );
    m_bin_subject->register_observer( injector );
    injector = std::make_shared<PackagerPalletBox>( injector );
    m_bin_subject->register_observer( injector );

    AssemblyState state;
    StufferType stuffer = state.get_stuffer_type( state.get_stuffer() );
    injector = StufferFactory::get_stuffer( injector, stuffer );
    m_bin_subject->register_observer( injector );

    return injector;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleFast::get_bin_publisher
\*---------------------------------------------------------------------------*/
TSubjectPtr OrderScaleFast::get_bin_publisher()
{
    return m_bin_subject;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleLarge::OrderScaleLarge
\*---------------------------------------------------------------------------*/
OrderScaleLarge::OrderScaleLarge()
    : m_order_scale( ORDER_LARGE )
    , m_conveyor_belt( "Linear" )
    , m_output_bin( "PalletBox" )
{
    AssemblyState state;
    state.set_conveyor_belt( m_conveyor_belt );
    state.set_output_bin( m_output_bin );
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleLarge::get_injection_machine
| \brief    Decorates an injection assembly line appropriate for order size
\*---------------------------------------------------------------------------*/
TInjectionPtr OrderScaleLarge::get_injection_machine()
{
    TInjectionPtr injector = 
        InjectionMachineFactory::get_injection_molding_machine( m_order_scale );

    m_bin_subject = 
        std::make_shared<OutputBinSubject>( "PalletBox package bin" );
    m_bin_subject->register_observer( injector );

    injector = std::make_shared<ConveyorBeltLinear>( injector );
    m_bin_subject->register_observer( injector );
    injector = std::make_shared<PackagerPalletBox>( injector );
    m_bin_subject->register_observer( injector );

    AssemblyState state;
    StufferType stuffer = state.get_stuffer_type( state.get_stuffer() );
    injector = StufferFactory::get_stuffer( injector, stuffer );
    m_bin_subject->register_observer( injector );

    return injector;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleLarge::get_bin_publisher
\*---------------------------------------------------------------------------*/
TSubjectPtr OrderScaleLarge::get_bin_publisher()
{
    return m_bin_subject;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleJumbo::OrderScaleJumbo
\*---------------------------------------------------------------------------*/
OrderScaleJumbo::OrderScaleJumbo()
    : m_order_scale( ORDER_JUMBO )
    , m_conveyor_belt( "Y-split" )
    , m_output_bin( "Crate" )
{
    AssemblyState state;
    state.set_conveyor_belt( m_conveyor_belt );
    state.set_output_bin( m_output_bin );
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleJumbo::get_injection_machine
| \brief    Decorates an injection assembly line appropriate for order size
\*---------------------------------------------------------------------------*/
TInjectionPtr OrderScaleJumbo::get_injection_machine()
{
    TInjectionPtr injector = 
        InjectionMachineFactory::get_injection_molding_machine( m_order_scale );

    m_bin_subject = 
        std::make_shared<OutputBinSubject>( "Crate package bin" );
    m_bin_subject->register_observer( injector );

    injector = std::make_shared<ConveyorBeltYSplit>( injector );
    m_bin_subject->register_observer( injector );
    injector = std::make_shared<PackagerCrate>( injector );
    m_bin_subject->register_observer( injector );

    AssemblyState state;
    StufferType stuffer = state.get_stuffer_type( state.get_stuffer() );
    injector = StufferFactory::get_stuffer( injector, stuffer );
    m_bin_subject->register_observer( injector );

    return injector;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleJumbo::get_bin_publisher
\*---------------------------------------------------------------------------*/
TSubjectPtr OrderScaleJumbo::get_bin_publisher()
{
    return m_bin_subject;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleHuge::OrderScaleHuge
\*---------------------------------------------------------------------------*/
OrderScaleHuge::OrderScaleHuge()
    : m_order_scale( ORDER_HUGE )
    , m_conveyor_belt( "V-Level" )
    , m_output_bin( "Crate" )
{
    AssemblyState state;
    state.set_conveyor_belt( m_conveyor_belt );
    state.set_output_bin( m_output_bin );
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleHuge::get_injection_machine
| \brief    Decorates an injection assembly line appropriate for order size
\*---------------------------------------------------------------------------*/
TInjectionPtr OrderScaleHuge::get_injection_machine()
{
    TInjectionPtr injector = 
        InjectionMachineFactory::get_injection_molding_machine( m_order_scale );

    m_bin_subject = 
        std::make_shared<OutputBinSubject>( "Crate package bin" );
    m_bin_subject->register_observer( injector );

    injector = std::make_shared<ConveyorBeltVLevel>( injector );
    m_bin_subject->register_observer( injector );
    injector = std::make_shared<PackagerCrate>( injector );
    m_bin_subject->register_observer( injector );

    AssemblyState state;
    StufferType stuffer = state.get_stuffer_type( state.get_stuffer() );
    injector = StufferFactory::get_stuffer( injector, stuffer );
    m_bin_subject->register_observer( injector );

    return injector;
}

/*---------------------------------------------------------------------------*\
| \fn       OrderScaleHuge::get_bin_publisher
\*---------------------------------------------------------------------------*/
TSubjectPtr OrderScaleHuge::get_bin_publisher()
{
    return m_bin_subject;
}

