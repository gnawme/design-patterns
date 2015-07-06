/*---------------------------------------------------------------------------*\
| \file     DrawingAPI.hpp
| \brief    Abstract base class for DrawingAPI
\*---------------------------------------------------------------------------*/
#ifndef HFDP_BRIDGESHAPE_DRAWING_API_HPP
#define HFDP_BRIDGESHAPE_DRAWING_API_HPP

/*---------------------------------------------------------------------------*\
| \class    DrawingAPI
\*---------------------------------------------------------------------------*/
class DrawingAPI
{
public:
    virtual        ~DrawingAPI() {};
    virtual void    draw_circle( double, double, double ) = 0;
};


#endif//HFDP_BRIDGESHAPE_DRAWING_API_HPP
