/*---------------------------------------------------------------------------*\
| \file     SmartHomeFacadeDemo.cpp
| \brief    Demonstrates Facade Pattern implementation
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "SmartHomeFacade.hpp"
#include "AcmeSmartHomeComponents.h"

/*---------------------------------------------------------------------------*\
| \fn       client1
| \brief    Facade Pattern client
\*---------------------------------------------------------------------------*/
void client1()
{
    SmartHomeFacade home1;
    home1.client_leaving();
    home1.client_arriving();
}

/*---------------------------------------------------------------------------*\
| \fn       client2
| \brief    Facade Pattern client
\*---------------------------------------------------------------------------*/
void client2()
{
    SmartHomeFacade home2;
    home2.client_leaving();
    home2.client_arriving();
}

/*---------------------------------------------------------------------------*\
| \fn       client1
| \brief    Facade Pattern client
\*---------------------------------------------------------------------------*/
void client3()
{
    SmartHomeFacade home3;
    home3.client_leaving();
    home3.client_arriving();
}

/*---------------------------------------------------------------------------*\
| \fn       main
| \brief    Demonstrates Facade Pattern implementation
\*---------------------------------------------------------------------------*/
int main()
{
    client1();
    client2();
    client3();

    return EXIT_SUCCESS;
}
