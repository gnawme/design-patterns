#ifndef LAB02_ACME_SMART_HOME_COMPONENTS_H
#define LAB02_ACME_SMART_HOME_COMPONENTS_H
/*---------------------------------------------------------------------------*\
|   Acme Smart Home Components Library
|
|   The Acme Software is provided by Acme on an "AS IS" basis.  ACME
|   MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
|   THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
|   FOR A PARTICULAR PURPOSE, REGARDING THE ACME SOFTWARE OR ITS USE AND
|   OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
|
|   (c) 2001 Acme Widgets, Inc. All Rights Reserved
\*---------------------------------------------------------------------------*/
#include <iostream>

namespace acme_home
{
class Alarm
{
public:
    void on()
    {
        std::cout << "  Alarm on." << std::endl;
    }
    void off()
    {
        std::cout << "  Alarm off." << std::endl;
    }
};

class AC
{
public:
    void on()
    {
        std::cout << "  AC on." << std::endl;
    }
    void off()
    {
        std::cout << "  AC off." << std::endl;
    }
};

class TV
{
public:
    void on()
    {
        std::cout << "  TV on." << std::endl;
    }
    void off()
    {
        std::cout << "  TV off." << std::endl;
    }
};

class Lights
{
public:
    void on()
    {
        std::cout << "  Lights on." << std::endl;
    }
    void off()
    {
        std::cout << "  Lights off." << std::endl;
    }
};


}//namespace acme_home


#endif//LAB02_ACME_SMART_HOME_COMPONENTS_H