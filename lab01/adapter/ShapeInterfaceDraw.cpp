/*---------------------------------------------------------------------------*\
| \file     ShapeInterfaceDraw.cpp
| \brief    Implementations for Adapted 3rd-party shapes
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "ShapeInterfaceDraw.hpp"
#include "AcmeShapeInterfaceDisplay.h"

/*---------------------------------------------------------------------------*\
| \fn       Polygon::Polygon
| \brief    Adapter interface for acme_shapes::Polygon
\*---------------------------------------------------------------------------*/
Polygon::Polygon()
    : m_polygon( new acme_shapes::Polygon )
{} 

/*---------------------------------------------------------------------------*\
| \fn       Polygon::draw
| \brief    Adapter interface for acme_shapes::Polygon
\*---------------------------------------------------------------------------*/
void Polygon::draw()
{
    m_polygon->display();
}

/*---------------------------------------------------------------------------*\
| \fn       Torus::Torus
| \brief    Adapter interface for acme_shapes::Torus
\*---------------------------------------------------------------------------*/
Torus::Torus()
    : m_torus( new acme_shapes::Torus )
{} 

/*---------------------------------------------------------------------------*\
| \fn       Torus::draw
| \brief    Adapter interface for acme_shapes::Torus
\*---------------------------------------------------------------------------*/
void Torus::draw()
{
    m_torus->display();
}

/*---------------------------------------------------------------------------*\
| \fn       Bezel::Bezel
| \brief    Adapter interface for acme_shapes::Bezel
\*---------------------------------------------------------------------------*/
Bezel::Bezel()
    : m_bezel( new acme_shapes::Bezel )
{} 

/*---------------------------------------------------------------------------*\
| \fn       Bezel::draw
| \brief    Adapter interface for acme_shapes::Bezel
\*---------------------------------------------------------------------------*/
void Bezel::draw()
{
    m_bezel->display();
}


