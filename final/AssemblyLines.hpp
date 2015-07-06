#ifndef FINAL_ASSEMBLY_LINES_HPP
#define FINAL_ASSEMBLY_LINES_HPP
/*---------------------------------------------------------------------------*\
| \file     AssemblyLines.hpp
| \brief    Injection molding assembly lines specialized for materials
| \note     Overrides methods of AssemblyLineTemplate
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AssemblyLineTemplate.hpp"

#include "AssemblyState.hpp"
#include "CleaningStepStrategy.hpp"
#include "InjectionCycleStrategy.hpp"
#include "InjectionLineComponents.hpp"

#include <iostream>

/*---------------------------------------------------------------------------*\
| \class    AssemblyLineABS
| \brief    Specializes assembly process for ABS
\*---------------------------------------------------------------------------*/
class AssemblyLineABS: public AssemblyLineTemplate
{
public:
                AssemblyLineABS( const TOrderMap& order )
                : AssemblyLineTemplate( order )
                , m_plastic( "ABS" )
                , m_injection_cycle( std::make_shared<InjectionCycleStrategyABS>() )
                , m_cleaning_step( std::make_shared<CleaningStepABS>() )
                {}

               ~AssemblyLineABS()
                {
                    std::cout 
                    << "~AssemblyLineABS ";
                }

    void        load_additive_hook();
    void        run_injection_cycle();
    void        clean_mold();

private:
    std::string         m_plastic;
    TInjectionCyclePtr  m_injection_cycle;
    TCleaningStepPtr    m_cleaning_step;
};

/*---------------------------------------------------------------------------*\
| \class    AssemblyLinePolypropylene
| \brief    Specializes assembly process for Polypropylene
\*---------------------------------------------------------------------------*/
class AssemblyLinePolypropylene: public AssemblyLineTemplate
{
public:
                AssemblyLinePolypropylene( const TOrderMap& order )
                : AssemblyLineTemplate( order )
                , m_plastic( "Polypropylene" )
                , m_injection_cycle( std::make_shared<InjectionCycleStrategyPoly>() )
                , m_cleaning_step( std::make_shared<CleaningStepPoly>() )
                {}

               ~AssemblyLinePolypropylene()
                {
                    std::cout 
                    << "~AssemblyLinePolypropylene ";
                }

    void        load_additive_hook();
    void        run_injection_cycle();
    void        clean_mold();

private:
    std::string         m_plastic;
    TInjectionCyclePtr  m_injection_cycle;
    TCleaningStepPtr    m_cleaning_step;
};

/*---------------------------------------------------------------------------*\
| \class    AssemblyLinePolyethylene
| \brief    Specializes assembly process for Polyethylene
\*---------------------------------------------------------------------------*/
class AssemblyLinePolyethylene: public AssemblyLineTemplate
{
public:
                AssemblyLinePolyethylene( const TOrderMap& order )
                : AssemblyLineTemplate( order )
                , m_plastic( "Polyethylene" )
                , m_injection_cycle( std::make_shared<InjectionCycleStrategyPoly>() )
                , m_cleaning_step( std::make_shared<CleaningStepPoly>() )
                {}

               ~AssemblyLinePolyethylene()
                {
                    std::cout 
                    << "~AssemblyLinePolyethylene ";
                }

    void        load_additive_hook();
    void        run_injection_cycle();
    void        clean_mold();

private:
    std::string         m_plastic;
    TInjectionCyclePtr  m_injection_cycle;
    TCleaningStepPtr    m_cleaning_step;
};

/*---------------------------------------------------------------------------*\
| \class    AssemblyLinePET
| \brief    Specializes assembly process for PET
\*---------------------------------------------------------------------------*/
class AssemblyLinePET: public AssemblyLineTemplate
{
public:
                AssemblyLinePET( const TOrderMap& order )
                : AssemblyLineTemplate( order )
                , m_plastic( "PET" )
                , m_injection_cycle( std::make_shared<InjectionCycleStrategyPET>() )
                , m_cleaning_step( std::make_shared<CleaningStepPET>() )
                {
                }

               ~AssemblyLinePET()
                {
                    std::cout 
                    << "~AssemblyLinePET ";
                }

    void        load_additive_hook();
    void        run_injection_cycle();
    void        clean_mold();

private:
    std::string         m_plastic;
    TInjectionCyclePtr  m_injection_cycle;
    TCleaningStepPtr    m_cleaning_step;
};

/*---------------------------------------------------------------------------*\
| \class    AssemblyLineStyrene
| \brief    Specializes assembly process for Styrene
\*---------------------------------------------------------------------------*/
class AssemblyLineStyrene: public AssemblyLineTemplate
{
public:
                AssemblyLineStyrene( const TOrderMap& order )
                : AssemblyLineTemplate( order )
                , m_plastic( "Styrene" )
                , m_injection_cycle( std::make_shared<InjectionCycleStrategyStyrene>() )
                , m_cleaning_step( std::make_shared<CleaningStepSynthetic>() )
                {}

               ~AssemblyLineStyrene()
                {
                    std::cout 
                    << "~AssemblyLineStyrene ";
                }

    void        load_additive_hook();
    void        run_injection_cycle();
    void        clean_mold();

private:
    std::string         m_plastic;
    TInjectionCyclePtr  m_injection_cycle;
    TCleaningStepPtr    m_cleaning_step;
};

/*---------------------------------------------------------------------------*\
| \class    AssemblyLineNylon66
| \brief    Specializes assembly process for Nylon66
\*---------------------------------------------------------------------------*/
class AssemblyLineNylon66: public AssemblyLineTemplate
{
public:
                AssemblyLineNylon66( const TOrderMap& order )
                : AssemblyLineTemplate( order )
                , m_plastic( "Nylon66" )
                , m_injection_cycle( std::make_shared<InjectionCycleStrategyNylon66>() )
                , m_cleaning_step( std::make_shared<CleaningStepSynthetic>() )
                {}

               ~AssemblyLineNylon66()
                {
                    std::cout 
                    << "~AssemblyLineNylon66 ";
                }

    void        load_additive_hook();
    void        run_injection_cycle();
    void        clean_mold();

private:
    std::string         m_plastic;
    TInjectionCyclePtr  m_injection_cycle;
    TCleaningStepPtr    m_cleaning_step;
};

/*---------------------------------------------------------------------------*\
| \class    AssemblyLineFactory
| \brief    Instantiates an AssemblyLine
\*---------------------------------------------------------------------------*/
class AssemblyLineFactory
{
public:
    static TAssemblyLinePtr get_assembly_line(
        const TOrderMap&    order,
        const PlasticType   plastic );
};

/*---------------------------------------------------------------------------*\
| \class    StufferFactory
| \brief    Instantiates a Stuffer
\*---------------------------------------------------------------------------*/
class StufferFactory
{
public:
    static TInjectionPtr get_stuffer(
        const TInjectionPtr&    comp,
        const StufferType       stuffer );
};

#endif//FINAL_ASSEMBLY_LINES_HPP
