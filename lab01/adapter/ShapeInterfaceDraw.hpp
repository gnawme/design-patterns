#ifndef LAB01_ADAPTER_SHAPE_INTERFACE_DRAW_HPP
#define LAB01_ADAPTER_SHAPE_INTERFACE_DRAW_HPP
/*---------------------------------------------------------------------------*\
| \file     ShapeInterfaceDraw.hpp
| \brief    ShapeInterfaceDraw, including extensions
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <iostream>
#include <memory>

/*---------------------------------------------------------------------------*\
| \class    ShapeInterfaceDraw
| \brief    ABC for heavily used Shape class
\*---------------------------------------------------------------------------*/
class ShapeInterfaceDraw                      
{
public:
    virtual        ~ShapeInterfaceDraw() 
    { std::cerr << "Bye-bye, ShapeInterfaceDraw" << std::endl; }

    virtual void    draw() = 0;
};

/*---------------------------------------------------------------------------*\
| \class    Point
\*---------------------------------------------------------------------------*/
class Point: public ShapeInterfaceDraw
{
public:
    void    draw() { std::cout << "Draw point." << std::endl; };
};

/*---------------------------------------------------------------------------*\
| \class    Line
\*---------------------------------------------------------------------------*/
class Line: public ShapeInterfaceDraw
{
public:
    void    draw() { std::cout << "Draw line." << std::endl; };
};

/*---------------------------------------------------------------------------*\
| \class    Rect
\*---------------------------------------------------------------------------*/
class Rect: public ShapeInterfaceDraw
{
public:
    void    draw() { std::cout << "Draw rectangle." << std::endl; };
};

/*---------------------------------------------------------------------------*\
| \brief    Adapted Acme extensions
\*---------------------------------------------------------------------------*/
namespace acme_shapes
{
class Polygon;
class Torus;
class Bezel;
}

/*---------------------------------------------------------------------------*\
| \class    Polygon
| \brief    Adapted from acme_shapes::Polygon
\*---------------------------------------------------------------------------*/
class Polygon: public ShapeInterfaceDraw
{
public:
            Polygon();
    void    draw();

private:
    std::unique_ptr<acme_shapes::Polygon>   m_polygon;
};

/*---------------------------------------------------------------------------*\
| \class    Torus
| \brief    Adapted from acme_shapes::Torus
\*---------------------------------------------------------------------------*/
class Torus: public ShapeInterfaceDraw
{
public:
            Torus();
    void    draw();

private:
    std::unique_ptr<acme_shapes::Torus>     m_torus;
};

/*---------------------------------------------------------------------------*\
| \class    Bezel
| \brief    Adapted from acme_shapes::Bezel
\*---------------------------------------------------------------------------*/
class Bezel: public ShapeInterfaceDraw
{
public:
            Bezel();
    void    draw();

private:
    std::unique_ptr<acme_shapes::Bezel>     m_bezel;
};

#endif//LAB01_ADAPTER_SHAPE_INTERFACE_DRAW_HPP

