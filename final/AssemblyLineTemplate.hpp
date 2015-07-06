#ifndef FINAL_ASSEMBLY_LINE_TEMPLATE_HPP
#define FINAL_ASSEMBLY_LINE_TEMPLATE_HPP
/*---------------------------------------------------------------------------*\
| \file     AssemblyLineTemplate.hpp
| \brief    Injection molding assembly line simulation
| \note     Uses the Template Method pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "OrderProcessing.hpp"
#include "InjectionLineComponents.hpp"
#include "MoldMetal.hpp"
#include "OrderScale.hpp"
#include "RecipeComponents.hpp"

#include <memory>
#include <vector>

/*---------------------------------------------------------------------------*\
| \class    AssemblyLineTemplate
\*---------------------------------------------------------------------------*/
class AssemblyLineTemplate
{
public:
                    AssemblyLineTemplate( const TOrderMap& );
    virtual        ~AssemblyLineTemplate();

    // The Template Method
    void            process_order();

    void            setup_injection_line();
    void            pull_mold();
    void            insert_tags();
    void            load_additive_bins();
    virtual void    load_additive_hook() {};
    virtual void    run_injection_cycle();
    virtual void    clean_mold();
    void            ship();

protected:
    TOrderMap           m_order;
    TInjectionPtr       m_injector;
    TOrderScalePtr      m_order_scale_strategy;
    TRecipePtr          m_recipe;
    TMoldMetalPtr       m_mold_metal;
    TMillPlatformPtr    m_milling_platform;
};

typedef std::shared_ptr<AssemblyLineTemplate>   TAssemblyLinePtr;

#endif//FINAL_ASSEMBLY_LINE_TEMPLATE_HPP
