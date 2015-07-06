/*---------------------------------------------------------------------------*\
| \file     CircleShape.cpp
| \brief    Concrete Shape implementation
\*---------------------------------------------------------------------------*/
#include "CircleShape.hpp"

/*---------------------------------------------------------------------------*\
| \fn       CircleShape::CircleShape
\*---------------------------------------------------------------------------*/
CircleShape::CircleShape
(   double          xc,
    double          yc,
    double          radius,
    TDrawingAPIPtr  api )
    : m_xc( xc )
    , m_yc( yc )
    , m_radius( radius )
    , Shape( api )
    {}

/*---------------------------------------------------------------------------*\
| \fn       CircleShape::draw
\*---------------------------------------------------------------------------*/
void CircleShape::draw()
{
    m_drawing_api->draw_circle( m_xc, m_yc, m_radius );
}

/*---------------------------------------------------------------------------*\
| \fn       CircleShape::resize
\*---------------------------------------------------------------------------*/
void CircleShape::resize(
    double  pct )
{
    m_radius *= pct;
}

