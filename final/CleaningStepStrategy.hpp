#ifndef FINAL_CLEANING_STEP_STRATEGY_HPP
#define FINAL_CLEANING_STEP_STRATEGY_HPP
/*---------------------------------------------------------------------------*\
| \file     CleaningStepStrategy.hpp
| \brief    Cleaning step strategy classes
| \note     Wraps legacy classes in legacy_classes namespace
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AssemblyState.hpp"
#include "LegacyClasses.hpp"

#include <iostream>
#include <memory>
#include <string>

using namespace legacy_classes;

/*---------------------------------------------------------------------------*\
| \class    CleaningStepStrategy
| \brief    Base class for cleaning step strategies
\*---------------------------------------------------------------------------*/
class CleaningStepStrategy
{
public:
    virtual        ~CleaningStepStrategy()
                    { 
                        std::cout 
                        << "~CleaningStepStrategy " 
                        << std::endl; 
                    };

    virtual void    run_cleaning_steps() = 0;
};

typedef std::shared_ptr<CleaningStepStrategy> TCleaningStepPtr;

/*---------------------------------------------------------------------------*\
| \class    CleaningStepABS
| \brief    Cleaning step for ABS
\*---------------------------------------------------------------------------*/
class CleaningStepABS: public CleaningStepStrategy
{
public:
                CleaningStepABS()
                : m_cleaner( new CleanABS )
                {}

               ~CleaningStepABS()
                { 
                    std::cout 
                    << "~CleaningStepABS ";
                }

    void        run_cleaning_steps()
                {
                    std::cout << "\t";
                    m_cleaner->clean();
                }

private:
    std::unique_ptr<CleanABS>   m_cleaner;
};

/*---------------------------------------------------------------------------*\
| \class    CleaningStepPoly
| \brief    Cleaning step for Poly
\*---------------------------------------------------------------------------*/
class CleaningStepPoly: public CleaningStepStrategy
{
public:
                CleaningStepPoly()
                : m_cleaner( new CleanPolys )
                {}

               ~CleaningStepPoly()
                { 
                    std::cout 
                    << "~CleaningStepPoly ";
                }

    void        run_cleaning_steps()
                {
                    std::cout << "\t";
                    m_cleaner->prepForReuse();
                }

private:
    std::unique_ptr<CleanPolys> m_cleaner;
};

/*---------------------------------------------------------------------------*\
| \class    CleaningStepPET
| \brief    Cleaning step for PET
\*---------------------------------------------------------------------------*/
class CleaningStepPET: public CleaningStepStrategy
{
public:
                CleaningStepPET()
                : m_cleaner( new PETCleanup )
                {}

               ~CleaningStepPET()
                { 
                    std::cout 
                    << "~CleaningStepPET ";
                }

    void        run_cleaning_steps()
                {
                    AssemblyState state;
                    std::string mold_metal = state.get_mold_metal();

                    std::cout << "\t";
                    if ( mold_metal == "Aluminum" )
                    {
                        m_cleaner->purify();
                    }
                    else if ( mold_metal == "Steel" )
                    {
                        m_cleaner->carbonize();
                    }
                }

private:
    std::unique_ptr<PETCleanup> m_cleaner;
};

/*---------------------------------------------------------------------------*\
| \class    CleaningStepSynthetic
| \brief    Cleaning step for Synthetic
\*---------------------------------------------------------------------------*/
class CleaningStepSynthetic: public CleaningStepStrategy
{
public:
                CleaningStepSynthetic()
                {}

               ~CleaningStepSynthetic()
                { 
                    std::cout 
                    << "~CleaningStepSynthetic ";
                }

    void        run_cleaning_steps()
                {
                    std::cout 
                    << "\t\tClean synthetic mold: ozone wash."
                    << std::endl;
                }

};

#endif//FINAL_CLEANING_STEP_STRATEGY_HPP
