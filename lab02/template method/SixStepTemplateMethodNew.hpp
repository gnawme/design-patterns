#ifndef LAB02_SIX_STEP_TEMPLATE_METHOD_NEW_HPP
#define LAB02_SIX_STEP_TEMPLATE_METHOD_NEW_HPP
/*---------------------------------------------------------------------------*\
| \file     SixStepTemplateMethodNew.hpp
| \brief    Six Step Template Method pattern extensions
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "SixStepTemplateMethod.hpp"

#include <iostream>

namespace template_method_new_specs
{
using namespace template_method_common;

/*---------------------------------------------------------------------------*\
| \class    SixStepTemplateMethodCritical
| \brief    "Critical" concrete implementation of SixStepTemplate
\*---------------------------------------------------------------------------*/
class SixStepTemplateMethodCritical: public SixStepTemplateMethod
{
public:
            SixStepTemplateMethodCritical( const char* name )
            : SixStepTemplateMethod( name )
            {}

    //! \fn     optimize
    //! /brief  Implements the optimize step
    void    optimize()
            { std::cout << "critical optimization" << std::endl; }

    //! \fn     cleanup
    //! /brief  Implements the cleanup step
    void    cleanup()
            { std::cout << "meticulous cleanup" << std::endl; }
};

/*---------------------------------------------------------------------------*\
| \class    SixStepTemplateMethodNPC
| \brief    "NPC" concrete implementation of SixStepTemplate
\*---------------------------------------------------------------------------*/
class SixStepTemplateMethodNPC: public SixStepTemplateMethod
{
public:
            SixStepTemplateMethodNPC( const char* name )
            : SixStepTemplateMethod( name )
            {}

    //! \fn     optimize
    //! /brief  Implements the optimize step
    void    optimize()
            { std::cout << "NPC optimized" << std::endl; }

    //! \fn     cleanup
    //! /brief  Implements the cleanup step
    void    cleanup()
            { std::cout << "meticulous cleanup" << std::endl; }
};

}//namespace template_method_new_specs

#endif//LAB02_SIX_STEP_TEMPLATE_METHOD_NEW_HPP