/*---------------------------------------------------------------------------*\
| \file     PlatformImpl.cpp
| \brief    Platform abstract base class
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "PlatformImpl.hpp"

/*---------------------------------------------------------------------------*\
| \fn       PlatformRaster::PlatformRaster
\*---------------------------------------------------------------------------*/
PlatformRaster::PlatformRaster()
    : m_raster( new RasterThing )
{}

/*---------------------------------------------------------------------------*\
| \fn       PlatformRaster::draw_line
| \brief    Implements draw_line (Platform abstraction) 
\*---------------------------------------------------------------------------*/
void    PlatformRaster::draw_line( 
    double  lrx, 
    double  lry, 
    double  urx, 
    double  ury )
{
    m_raster->draw_line( lrx, lry, urx, ury );
}

/*---------------------------------------------------------------------------*\
| \fn       PlatformRaster::draw_arc
| \brief    Implements draw_arc (Platform abstraction) 
\*---------------------------------------------------------------------------*/
void    PlatformRaster::draw_arc( 
    double  x1, 
    double  y1, 
    double  x2, 
    double  y2 )
{
    m_raster->draw_arc( x1, y1, x2, y2 );
}

/*---------------------------------------------------------------------------*\
| \fn       PlatformVector::PlatformVector
\*---------------------------------------------------------------------------*/
PlatformVector::PlatformVector()
    : m_vector( new VectorThing )
{}

/*---------------------------------------------------------------------------*\
| \fn       PlatformVector::draw_line
| \brief    Implements draw_line (Platform abstraction) 
\*---------------------------------------------------------------------------*/
void    PlatformVector::draw_line( 
    double  lrx, 
    double  lry, 
    double  urx, 
    double  ury )
{
    m_vector->drawLine( lrx, lry, urx, ury );
}

/*---------------------------------------------------------------------------*\
| \fn       PlatformVector::draw_arc
| \brief    Implements draw_arc (Platform abstraction) 
\*---------------------------------------------------------------------------*/
void    PlatformVector::draw_arc( 
    double  x1, 
    double  y1, 
    double  x2, 
    double  y2 )
{
    m_vector->drawArc( x1, y1, x2, y2 );
}

/*---------------------------------------------------------------------------*\
| \fn       PlatformPlotter::PlatformPlotter
\*---------------------------------------------------------------------------*/
PlatformPlotter::PlatformPlotter()
    : m_plotter( new PlotterThing )
{}

/*---------------------------------------------------------------------------*\
| \fn       PlatformPlotter::draw_line
| \brief    Implements draw_line (Platform abstraction) 
\*---------------------------------------------------------------------------*/
void    PlatformPlotter::draw_line( 
    double  lrx, 
    double  lry, 
    double  urx, 
    double  ury )
{
    m_plotter->draw_a_line( lrx, lry, urx, ury );
}

/*---------------------------------------------------------------------------*\
| \fn       PlatformPlotter::draw_arc
| \brief    Implements draw_arc (Platform abstraction) 
\*---------------------------------------------------------------------------*/
void    PlatformPlotter::draw_arc( 
    double  x1, 
    double  y1, 
    double  x2, 
    double  y2 )
{
    m_plotter->draw_an_arc( x1, y1, x2, y2 );
}