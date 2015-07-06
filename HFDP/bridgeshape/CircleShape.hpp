/*---------------------------------------------------------------------------*\
| \file     CircleShape.hpp
| \brief    Concrete Shape implementation
\*---------------------------------------------------------------------------*/
#ifndef HFDP_BRIDGESHAPE_CIRCLE_SHAPE_HPP
#define HFDP_BRIDGESHAPE_CIRCLE_SHAPE_HPP

#include "Shape.hpp"

/*---------------------------------------------------------------------------*\
| \class    CircleShape
\*---------------------------------------------------------------------------*/
class CircleShape: public Shape
{
public:
            CircleShape( double xc, double yc, double radius, TDrawingAPIPtr api );

    void    draw();
    void    resize( double );

private:
    double  m_xc;
    double  m_yc;
    double  m_radius;
};


#endif//HFDP_BRIDGESHAPE_CIRCLE_SHAPE_HPP
