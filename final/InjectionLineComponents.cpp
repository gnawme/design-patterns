/*---------------------------------------------------------------------------*\
| \file     InjectionLineComponents.cpp
| \brief    Injection Line Decorator implementation
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "InjectionLineComponents.hpp"

#include "OrderProcessing.hpp"
#include "AssemblyState.hpp"

/*---------------------------------------------------------------------------*\
| \fn       InjectionMachineFactory::get_injection_molding_machine
| \brief    Static InjectionMachine factory
\*---------------------------------------------------------------------------*/
TInjectionPtr InjectionMachineFactory::get_injection_molding_machine(
    OrderScale  order_scale )
{
    /*-----------------------------------------------------------------------*\
    |   Return injection molding machine based on order scale
    \*-----------------------------------------------------------------------*/
    switch( order_scale )
    {
    case ORDER_SMALL:
        return std::make_shared<InjectionMolderIJM_110>();
    case ORDER_MEDIUM:
        return std::make_shared<InjectionMolderIJM_120>();
    case ORDER_FAST:
        return std::make_shared<InjectionMolderIJM_140>();
    case ORDER_LARGE:
        return std::make_shared<InjectionMolderIJM_210>();
    case ORDER_JUMBO:
        return std::make_shared<InjectionMolderIJM_220>();
    case ORDER_HUGE:
        return std::make_shared<InjectionMolderIJM_240>();
    }

    return nullptr;
}
