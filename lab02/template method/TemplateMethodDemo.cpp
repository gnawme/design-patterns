/*---------------------------------------------------------------------------*\
| \file     TemplateMethodDemo.cpp
| \brief    Demonstrates implementations of Template Method Pattern lab
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "SixStepTemplateMethod.hpp"
#include "SixStepTemplateMethodNew.hpp"

#include <cstdlib>
#include <memory>
#include <vector>

using namespace template_method_common;
using namespace template_method_new_specs;

typedef std::unique_ptr<SixStepTemplateMethod>  TSixStepPtr;
typedef std::vector<TSixStepPtr>                TSixStepVec;

/*---------------------------------------------------------------------------*\
| \fn       main
| \brief    Instantiates and runs all template method concrete implementations
\*---------------------------------------------------------------------------*/
int main()
{
    TSixStepVec processes;
    /*-----------------------------------------------------------------------*\
    |   Stock methods
    \*-----------------------------------------------------------------------*/
    processes.push_back( TSixStepPtr( new SixStepTemplateMethodFast( "Fast method" ) ) );
    processes.push_back( TSixStepPtr( new SixStepTemplateMethodEconomical( "Economical method" ) ) );

    /*-----------------------------------------------------------------------*\
    |   Extended methods
    \*-----------------------------------------------------------------------*/
    processes.push_back( TSixStepPtr( new SixStepTemplateMethodCritical( "Critical method" ) ) );
    processes.push_back( TSixStepPtr( new SixStepTemplateMethodNPC( "NPC method" ) ) );

    /*-----------------------------------------------------------------------*\
    |   Iterate through all concrete implementations and run them
    \*-----------------------------------------------------------------------*/
    for ( auto& it : processes )
    {
        it->template_method();
    }

    return EXIT_SUCCESS;
}