/*---------------------------------------------------------------------------*\
| \file     SixStepTemplateMethod.cpp
| \brief    Six Step Template Method pattern implementation
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "SixStepTemplateMethod.hpp"

#include <cstdlib>
#include <iostream>
#include <random>

namespace template_method_common
{
/*---------------------------------------------------------------------------*\
|   SixStepTemplateMethod base class methods
\*---------------------------------------------------------------------------*/
SixStepTemplateMethod::SixStepTemplateMethod(
    const char* name = "" )
    : m_implementation_name( name )
{
    std::random_device                  rd;
    std::uniform_int_distribution<int>  uni( 0, 23 );

    auto random_hour = uni( rd );
    m_morning = ( random_hour < 12 );
}

//! \fn     SixStepTemplateMethod::setup
//! \brief  Base class setup method
//! \note   Not an overridden step
void SixStepTemplateMethod::setup()
{
    std::cout << std::endl << m_implementation_name << std::endl;
    std::cout << "setup" << std::endl;
}

//! \fn     SixStepTemplateMethod::schedule
//! \brief  Base class schedule method
//! \note   Not an overridden step
void SixStepTemplateMethod::schedule()
{
    std::cout << "schedule" << std::endl;
}

//! \fn     SixStepTemplateMethod::heat
//! \brief  Base class heat method
//! \note   Not an overridden step
void SixStepTemplateMethod::heat()
{
    std::cout
    << ( m_morning ? "high heat" : "low heat" )
    << std::endl;
}

//! \fn     SixStepTemplateMethod::optimize
//! \brief  Base class optimize method
//! \note   Default implementation of step that can be overridden
void SixStepTemplateMethod::optimize()
{
    std::cout << "standard optimization" << std::endl;
}

//! \fn     SixStepTemplateMethod::cleanup
//! \brief  Base class cleanup method
//! \note   Default implementation of step that can be overridden
void SixStepTemplateMethod::cleanup()
{
    std::cout << "standard cleanup" << std::endl;
}

//! \fn     SixStepTemplateMethod::putaway
//! \brief  Base class putaway method
//! \note   Not an overridden step
void SixStepTemplateMethod::putaway()
{
    std::cout << "putaway" << std::endl;
}

/*---------------------------------------------------------------------------*\
|   SixStepTemplateMethod template method
\*---------------------------------------------------------------------------*/
void SixStepTemplateMethod::template_method()
{
    setup();
    schedule();
    heat();
    optimize();
    cleanup();
    putaway();
}

/*---------------------------------------------------------------------------*\
|   SixStepTemplateMethodFast overrides
\*---------------------------------------------------------------------------*/
//! \fn     SixStepTemplateMethodFast::SixStepTemplateMethodFast
//! \brief  Disciple of the SixStepTemplateMethod
SixStepTemplateMethodFast::SixStepTemplateMethodFast(
    const char* name )
    : SixStepTemplateMethod( name )
{}

//! \fn     SixStepTemplateMethodFast::optimize
//! \brief  Overrides the optimize step
void SixStepTemplateMethodFast::optimize()
{
    std::cout << "fast optimize" << std::endl;
}

//! \fn     SixStepTemplateMethodFast::cleanup
//! \brief  Overrides the default cleanup step for illustration
void SixStepTemplateMethodFast::cleanup()
{
    std::cout << "standard cleanup" << std::endl;
}

/*---------------------------------------------------------------------------*\
|   SixStepTemplateMethodEconomical overrides
\*---------------------------------------------------------------------------*/
//! \fn     SixStepTemplateMethodEconomical::SixStepTemplateMethodEconomical
//! \brief  Disciple of the SixStepTemplateMethod
SixStepTemplateMethodEconomical::SixStepTemplateMethodEconomical(
    const char* name )
    : SixStepTemplateMethod( name )
{}

//! \fn     SixStepTemplateMethodEconomical::optimize
//! \brief  Overrides the optimize step
void SixStepTemplateMethodEconomical::optimize()
{
    std::cout << "economical optimize" << std::endl;
}

//! \fn     SixStemTemplateMethodEconomical::cleanup
//! \brief  Overrides the cleanup step for illustration
//! \note   Does NOT override the default step
void SixStepTemplateMethodEconomical::cleanup()
{
    std::cout << "standard cleanup" << std::endl;
}

}//namespace template_method_common