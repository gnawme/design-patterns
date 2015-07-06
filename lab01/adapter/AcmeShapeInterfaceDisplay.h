#ifndef LABO1_ACME_SHAPE_INTERFACE_DISPLAY_H
#define LABO1_ACME_SHAPE_INTERFACE_DISPLAY_H
/*---------------------------------------------------------------------------*\
|   Acme ShapeInterfaceDisplay Library
|
|   The Acme Software is provided by Acme on an "AS IS" basis.  ACME
|   MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
|   THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
|   FOR A PARTICULAR PURPOSE, REGARDING THE ACME SOFTWARE OR ITS USE AND
|   OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
|
|   (c) 2001 Acme Widgets, Inc. All Rights Reserved
\*---------------------------------------------------------------------------*/


namespace acme_shapes
{
#include <iostream>

// \class ShapeInterfaceDisplay
class ShapeInterfaceDisplay 
{
public:
    virtual void    display() = 0;
    virtual        ~ShapeInterfaceDisplay() 
    { std::cerr << "Adios, ShapeInterfaceDisplay" << std::endl; }
};

// \class Polygon
class Polygon : public ShapeInterfaceDisplay
{
public:
    void display()
    {
        std::cout << "Display polygon." << std::endl;
    }
};

// \class Torus
class Torus : public ShapeInterfaceDisplay
{
public:
    void display()
    {
        std::cout << "Display torus." << std::endl;
    }
};

// \class Bezel
class Bezel : public ShapeInterfaceDisplay
{
public:
    void display()
    {
        std::cout << "Display bezel." << std::endl;
    }
};

}//namespace acme_shapes

#endif//LABO1_ACME_SHAPE_INTERFACE_DISPLAY_H