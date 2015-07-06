#ifndef LAB05_BRIDGE_SHAPE_IMPL_HPP
#define LAB05_BRIDGE_SHAPE_IMPL_HPP
/*---------------------------------------------------------------------------*\
| \file     ShapeImpl.hpp
| \brief    Concrete Shape implementations (Abstraction implementations)
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Shape.hpp"

/*---------------------------------------------------------------------------*\
| \class    Rectangle
\*---------------------------------------------------------------------------*/
class Rectangle: public Shape
{
public:
            Rectangle( 
                TPlatformPtr    platform, 
                double          lrx, 
                double          lry, 
                double          urx, 
                double          ury );

    void    draw();

private:
    double  m_lrx;
    double  m_lry;
    double  m_urx;
    double  m_ury;

};

/*---------------------------------------------------------------------------*\
| \class    Circle
\*---------------------------------------------------------------------------*/
class Circle: public Shape
{
public:
            Circle( 
                TPlatformPtr    platform, 
                double          cx, 
                double          cy, 
                double          radius );

    void    draw();

private:
    double  m_cx;
    double  m_cy;
    double  m_radius;

};

#endif//LAB05_BRIDGE_SHAPE_IMPL_HPP
