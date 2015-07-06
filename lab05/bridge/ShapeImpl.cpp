/*---------------------------------------------------------------------------*\
| \file     ShapeImpl.cpp
| \brief    Concrete Shape implementations, concrete Abstraction implementations
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "ShapeImpl.hpp"
#include "Platform.hpp"

#include <iostream>

/*---------------------------------------------------------------------------*\
| \note     Omnibus drawing functions 
| \brief    Exploits common Platform drawing interfaces
\*---------------------------------------------------------------------------*/
namespace
{
/*---------------------------------------------------------------------------*\
| \fn       draw_circle
| \brief    Draws a circle using the Platform interface
\*---------------------------------------------------------------------------*/
void draw_circle(
    TPlatformPtr    platform,
    double          cx,
    double          cy,
    double          radius )
{
    std::cout << std::endl << "\tDrawing a circle" << std::endl;

    double arc_x1 = cx;
    double arc_y1 = cy + radius;
    double arc_x2 = cx + radius;
    double arc_y2 = cy;

    platform->draw_arc( cx,         cy+radius,  cx+radius,  cy );
    platform->draw_arc( cx+radius,  cy,         cx,         cy-radius );
    platform->draw_arc( cx,         cy-radius,  cx-radius,  cy );
    platform->draw_arc( cx-radius,  cy,         cx,         cy+radius );
}

/*---------------------------------------------------------------------------*\
| \fn       draw_rectangle
| \brief    Draws a rectangle using the Platform interface
\*---------------------------------------------------------------------------*/
void draw_rectangle(
    TPlatformPtr    platform,
    double          lrx,
    double          lry,
    double          urx,
    double          ury )
{
    std::cout << std::endl << "\tDrawing a rectangle" << std::endl;

    platform->draw_line( lrx, lry, urx, lry );
    platform->draw_line( urx, lry, urx, ury );
    platform->draw_line( urx, ury, lrx, ury );
    platform->draw_line( lrx, ury, lrx, lry );
}

}

/*---------------------------------------------------------------------------*\
| \fn       Rectangle::Rectangle
\*---------------------------------------------------------------------------*/
Rectangle::Rectangle(
    TPlatformPtr    platform,
    double          lrx,
    double          lry,
    double          urx,
    double          ury )
    : Shape( platform )
    , m_lrx( lrx )
    , m_lry( lry )
    , m_urx( urx )
    , m_ury( ury )
    {}

/*---------------------------------------------------------------------------*\
| \fn       Rectangle::draw
| \brief    Draws a rectangle using the current Platform implementation
| \note     Implemented in terms of the Platform interface, not its implementation
\*---------------------------------------------------------------------------*/
void Rectangle::draw()
{
    draw_rectangle( m_platform, m_lrx, m_lry, m_urx, m_ury );
}

/*---------------------------------------------------------------------------*\
| \fn       Circle::Circle
\*---------------------------------------------------------------------------*/
Circle::Circle(
    TPlatformPtr    platform,
    double          cx,
    double          cy,
    double          radius )
    : Shape( platform )
    , m_cx( cx )
    , m_cy( cy )
    , m_radius( radius )
    {}

/*---------------------------------------------------------------------------*\
| \fn       Circle::draw
| \brief    Draws a circle using the current Platform implementation
| \note     Implemented in terms of the Platform interface, not its implementation
\*---------------------------------------------------------------------------*/
void Circle::draw()
{
    draw_circle( m_platform, m_cx, m_cy, m_radius );
}

