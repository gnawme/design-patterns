#ifndef LAB05_BRIDGE_PLATFORM_IMPL_HPP
#define LAB05_BRIDGE_PLATFORM_IMPL_HPP
/*---------------------------------------------------------------------------*\
| \file     PlatformImpl.hpp
| \brief    Concrete Platform implementations
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Platform.hpp"
#include "PlatformDecl.hpp"

#include <iostream>

/*---------------------------------------------------------------------------*\
| \struct   RasterThing
| \brief    Raster drawing library
\*---------------------------------------------------------------------------*/
struct RasterThing
{
    //! \fn     draw_line
    void draw_line( double x1, double y1, double x2, double y2 )
    {
        std::cout 
        << "\tDraw raster line: "
        << "[" 
        << x1 << ","
        << y1 << "] "
        << "[" 
        << x2 << "," 
        << y2 << "]"
        << std::endl;
    }

    //! \fn     draw_arc
    void draw_arc( double x1, double y1, double x2, double y2 )
    {
        std::cout 
        << "\tDraw raster arc: "
        << "[" 
        << x1 << ","
        << y1 << "] "
        << "[" 
        << x2 << "," 
        << y2 << "]"
        << std::endl;
    }
};

/*---------------------------------------------------------------------------*\
| \class    PlatformRaster
| \brief    Raster concrete Platform implementation
\*---------------------------------------------------------------------------*/
class PlatformRaster: public Platform
{
public:
            PlatformRaster();

    void    draw_line( double, double, double, double );
    void    draw_arc( double, double, double, double );

private:
    std::unique_ptr<RasterThing>    m_raster;
};

/*---------------------------------------------------------------------------*\
| \struct   VectorThing
| \brief    Vector drawing library
\*---------------------------------------------------------------------------*/
struct VectorThing
{
    //! \fn     drawLine
    void drawLine( double x1, double y1, double x2, double y2 )
    {
        std::cout 
        << "\tDraw vector line: "
        << "[" 
        << x1 << ","
        << y1 << "] "
        << "[" 
        << x2 << "," 
        << y2 << "]"
        << std::endl;
    }

    //! \fn     drawArc
    void drawArc( double x1, double y1, double x2, double y2 )
    {
        std::cout 
        << "\tDraw vector arc: "
        << "[" 
        << x1 << ","
        << y1 << "] "
        << "[" 
        << x2 << "," 
        << y2 << "]"
        << std::endl;
    }
};

/*---------------------------------------------------------------------------*\
| \class    PlatformVector
| \brief    Vector concrete Platform implementation
\*---------------------------------------------------------------------------*/
class PlatformVector: public Platform
{
public:
            PlatformVector();

    void    draw_line( double, double, double, double );
    void    draw_arc( double, double, double, double );

private:
    std::unique_ptr<VectorThing>    m_vector;
};

/*---------------------------------------------------------------------------*\
| \struct   PlotterThing
| \brief    Plotter drawing library
\*---------------------------------------------------------------------------*/
struct PlotterThing
{
    //! \fn     draw_a_line
    void draw_a_line( double x1, double y1, double x2, double y2 )
    {
        std::cout 
        << "\tDraw plotter line: "
        << "[" 
        << x1 << ","
        << y1 << "] "
        << "[" 
        << x2 << "," 
        << y2 << "]"
        << std::endl;
    }

    //! \fn     draw_an_arc
    void draw_an_arc( double x1, double y1, double x2, double y2 )
    {
        std::cout 
        << "\tDraw plotter arc: "
        << "[" 
        << x1 << ","
        << y1 << "] "
        << "[" 
        << x2 << "," 
        << y2 << "]"
        << std::endl;
    }
};

/*---------------------------------------------------------------------------*\
| \class    PlatformPlotter
| \brief    Plotter concrete Platform implementation
\*---------------------------------------------------------------------------*/
class PlatformPlotter: public Platform
{
public:
            PlatformPlotter();

    void    draw_line( double, double, double, double );
    void    draw_arc( double, double, double, double );

private:
    std::unique_ptr<PlotterThing>    m_plotter;
};

/*---------------------------------------------------------------------------*\
| \enum     WhichPlatform
| \brief    Platform types supported
\*---------------------------------------------------------------------------*/
enum WhichPlatform
{
    e_Raster,
    e_Vector,
    e_Plotter
};

/*---------------------------------------------------------------------------*\
| \class    PlatformFactory
| \brief    Simple Platform Factory
\*---------------------------------------------------------------------------*/
class PlatformFactory
{
public:
    static TPlatformPtr get_platform( WhichPlatform platform )
    {
        switch( platform )
        {
        case e_Raster:
            return TPlatformPtr( new PlatformRaster );
        case e_Vector:
            return TPlatformPtr( new PlatformVector );
        case e_Plotter:
            return TPlatformPtr( new PlatformPlotter );
        default:
            return nullptr;
        }
    }
};

#endif//LAB05_BRIDGE_PLATFORM_IMPL_HPP
