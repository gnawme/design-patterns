/*---------------------------------------------------------------------------*\
| \file     AssemblyLines.cpp
| \brief    Injection molding assembly lines specialized for materials
| \note     Overrides methods of AssemblyLineTemplate
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AssemblyLines.hpp"

#include "RecipeComponents.hpp"

#include <iostream>

namespace
{
/*---------------------------------------------------------------------------*\
| \fn       color_volume
| \brief    Calculates the volume of color used
| \note     Color volume used is 10% of shape volume
\*---------------------------------------------------------------------------*/
int color_volume(
    int shape_volume )
{
    return static_cast<int>( 0.10 * shape_volume );
}

/*---------------------------------------------------------------------------*\
| \fn       decorate_mold
| \brief    Decorates the mold with order color and additives
\*---------------------------------------------------------------------------*/
TRecipePtr decorate_mold(
    TRecipePtr  recipe )
{
    AssemblyState state;
    /*-----------------------------------------------------------------------*\
    |   Decorate with order color
    \*-----------------------------------------------------------------------*/
    std::string color( state.get_color() );
    int volume = color_volume( state.get_mold_volume() );
    recipe     = std::make_shared<RecipeAdditive>( recipe, color, volume );

    /*-----------------------------------------------------------------------*\
    |   Decorate with additives
    \*-----------------------------------------------------------------------*/
    TAdditVec additives = state.get_additives();
    if ( !additives.empty() )
    {
        for ( auto addit : additives )
        {
            recipe = 
                std::make_shared<RecipeAdditive>( 
                    recipe, 
                    addit.m_additive, 
                    addit.m_volume );
        }
    }

    return recipe;
}

/*---------------------------------------------------------------------------*\
| \fn       initiate_cycle
| \brief    Initiates the injection cycle simulation
\*---------------------------------------------------------------------------*/
void initiate_cycle(
    std::string&    plastic )
{
    AssemblyState state;
    std::cout 
    << "\t\tCycle IJM for "
    << plastic
    << " "
    << state.get_run_size()
    << " times."
    << std::endl;
}

}//namespace

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineABS::load_additive_hook
| \brief    Overrides Step 4 hook of the AssemblyLineTemplate
\*---------------------------------------------------------------------------*/
void AssemblyLineABS::load_additive_hook()
{
    AssemblyState state;
    /*-----------------------------------------------------------------------*\
    |   Create component to be decorated based on order plastic
    \*-----------------------------------------------------------------------*/
    m_recipe = std::make_shared<RecipeMold>( m_plastic, state.get_mold_volume() );

    /*-----------------------------------------------------------------------*\
    |   Decorate with order color and additives
    \*-----------------------------------------------------------------------*/
    m_recipe = decorate_mold( m_recipe );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineABS::run_injection_cycle
| \brief    Step 5
\*---------------------------------------------------------------------------*/
void AssemblyLineABS::run_injection_cycle()
{
    initiate_cycle( m_plastic );

    m_injection_cycle->run_process();
    m_order_scale_strategy->get_bin_publisher()->issue_alert( "full..." );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineABS::clean_mold
| \brief    Step 6
\*---------------------------------------------------------------------------*/
void AssemblyLineABS::clean_mold()
{
    m_cleaning_step->run_cleaning_steps();
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePolypropylene::load_additive_hook
| \brief    Overrides Step 4 hook of the AssemblyLineTemplate
\*---------------------------------------------------------------------------*/
void AssemblyLinePolypropylene::load_additive_hook()
{
    AssemblyState state;
    /*-----------------------------------------------------------------------*\
    |   Create component to be decorated based on order plastic
    \*-----------------------------------------------------------------------*/
    m_recipe = std::make_shared<RecipeMold>( m_plastic, state.get_mold_volume() );

    /*-----------------------------------------------------------------------*\
    |   Decorate with order color and additives
    \*-----------------------------------------------------------------------*/
    m_recipe = decorate_mold( m_recipe );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePolypropylene::run_injection_cycle
| \brief    Step 5
\*---------------------------------------------------------------------------*/
void AssemblyLinePolypropylene::run_injection_cycle()
{
    initiate_cycle( m_plastic );

    m_injection_cycle->run_process();
    m_order_scale_strategy->get_bin_publisher()->issue_alert( "full..." );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePolypropylene::clean_mold
| \brief    Step 6
\*---------------------------------------------------------------------------*/
void AssemblyLinePolypropylene::clean_mold()
{
    m_cleaning_step->run_cleaning_steps();
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePolyethylene::load_additive_hook
| \brief    Overrides Step 4 hook of the AssemblyLineTemplate
\*---------------------------------------------------------------------------*/
void AssemblyLinePolyethylene::load_additive_hook()
{
    AssemblyState state;
    /*-----------------------------------------------------------------------*\
    |   Create component to be decorated based on order plastic
    \*-----------------------------------------------------------------------*/
    m_recipe = std::make_shared<RecipeMold>( m_plastic, state.get_mold_volume() );

    /*-----------------------------------------------------------------------*\
    |   Decorate with order color and additives
    \*-----------------------------------------------------------------------*/
    m_recipe = decorate_mold( m_recipe );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePolyethylene::run_injection_cycle
| \brief    Step 5
\*---------------------------------------------------------------------------*/
void AssemblyLinePolyethylene::run_injection_cycle()
{
    initiate_cycle( m_plastic );

    m_injection_cycle->run_process();
    m_order_scale_strategy->get_bin_publisher()->issue_alert( "full..." );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePolyethylene::clean_mold
| \brief    Step 6
\*---------------------------------------------------------------------------*/
void AssemblyLinePolyethylene::clean_mold()
{
    m_cleaning_step->run_cleaning_steps();
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePET::load_additive_hook
| \brief    Overrides Step 4 hook of the AssemblyLineTemplate
\*---------------------------------------------------------------------------*/
void AssemblyLinePET::load_additive_hook()
{
    AssemblyState state;
    /*-----------------------------------------------------------------------*\
    |   Create component to be decorated based on order plastic
    \*-----------------------------------------------------------------------*/
    m_recipe = std::make_shared<RecipeMold>( m_plastic, state.get_mold_volume() );

    /*-----------------------------------------------------------------------*\
    |   Decorate with order color and additives
    \*-----------------------------------------------------------------------*/
    m_recipe = decorate_mold( m_recipe );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePET::run_injection_cycle
| \brief    Step 5
\*---------------------------------------------------------------------------*/
void AssemblyLinePET::run_injection_cycle()
{
    initiate_cycle( m_plastic );

    m_injection_cycle->run_process();
    m_order_scale_strategy->get_bin_publisher()->issue_alert( "full..." );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLinePET::clean_mold
| \brief    Step 6
\*---------------------------------------------------------------------------*/
void AssemblyLinePET::clean_mold()
{
    m_cleaning_step->run_cleaning_steps();
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineStyrene::load_additive_hook
| \brief    Overrides Step 4 hook of the AssemblyLineTemplate
\*---------------------------------------------------------------------------*/
void AssemblyLineStyrene::load_additive_hook()
{
    AssemblyState state;
    /*-----------------------------------------------------------------------*\
    |   Create component to be decorated based on order plastic
    \*-----------------------------------------------------------------------*/
    m_recipe = std::make_shared<RecipeMold>( m_plastic, state.get_mold_volume() );

    /*-----------------------------------------------------------------------*\
    |   Decorate with order color and additives
    \*-----------------------------------------------------------------------*/
    m_recipe = decorate_mold( m_recipe );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineStyrene::run_injection_cycle
| \brief    Step 5
\*---------------------------------------------------------------------------*/
void AssemblyLineStyrene::run_injection_cycle()
{
    initiate_cycle( std::string( "Synthetics" ) );

    m_injection_cycle->run_process();
    m_order_scale_strategy->get_bin_publisher()->issue_alert( "full..." );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineStyrene::clean_mold
| \brief    Step 6
\*---------------------------------------------------------------------------*/
void AssemblyLineStyrene::clean_mold()
{
    m_cleaning_step->run_cleaning_steps();
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineNylon66::load_additive_hook
| \brief    Overrides Step 4 hook of the AssemblyLineTemplate
\*---------------------------------------------------------------------------*/
void AssemblyLineNylon66::load_additive_hook()
{
    AssemblyState state;
    /*-----------------------------------------------------------------------*\
    |   Create component to be decorated based on order plastic
    \*-----------------------------------------------------------------------*/
    m_recipe = std::make_shared<RecipeMold>( m_plastic, state.get_mold_volume() );

    /*-----------------------------------------------------------------------*\
    |   Decorate with order color and additives
    \*-----------------------------------------------------------------------*/
    m_recipe = decorate_mold( m_recipe );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineNylon66::run_injection_cycle
| \brief    Step 5
\*---------------------------------------------------------------------------*/
void AssemblyLineNylon66::run_injection_cycle()
{
    initiate_cycle( std::string( "Synthetics" ) );

    m_injection_cycle->run_process();
    m_order_scale_strategy->get_bin_publisher()->issue_alert( "full..." );
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineNylon66::clean_mold
| \brief    Step 6
\*---------------------------------------------------------------------------*/
void AssemblyLineNylon66::clean_mold()
{
    m_cleaning_step->run_cleaning_steps();
}

/*---------------------------------------------------------------------------*\
| \fn       AssemblyLineFactory::get_assembly_line
| \brief    Instantiates an AssemblyLine given a plastic type
\*---------------------------------------------------------------------------*/
TAssemblyLinePtr AssemblyLineFactory::get_assembly_line( 
    const TOrderMap&    order,
    const PlasticType   plastic )
{
    switch( plastic )
    {
    case e_ABS:
        return std::make_shared<AssemblyLineABS>( order );
    case e_Polypropylene:
        return std::make_shared<AssemblyLinePolypropylene>( order );
    case e_Polyethylene:
        return std::make_shared<AssemblyLinePolyethylene>( order );
    case e_PET:
        return std::make_shared<AssemblyLinePET>( order );
    case e_Styrene:
        return std::make_shared<AssemblyLineStyrene>( order );
    case e_Nylon66:
        return std::make_shared<AssemblyLineNylon66>( order );
    }
    
    return nullptr;
}

/*---------------------------------------------------------------------------*\
| \fn       StufferFactory::get_stuffer
| \brief    Instantiates an Stuffer given a stuffer type
\*---------------------------------------------------------------------------*/
TInjectionPtr StufferFactory::get_stuffer(
        const TInjectionPtr&    comp,
        const StufferType       stuffer )
{
    switch( stuffer )
    {
    case e_Air:
        return std::make_shared<StufferAir>( comp );
    case e_Popcorn:
         return std::make_shared<StufferPopcorn>( comp );
    case e_BubbleWrap:
        return std::make_shared<StufferBubbleWrap>( comp );
    case e_Foam:
        return std::make_shared<StufferFoam>( comp );
    }
    return nullptr;
}
