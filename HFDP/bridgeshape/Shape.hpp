/*---------------------------------------------------------------------------*\
| \file     Shape.hpp
| \brief    Abstract base class for Shape
\*---------------------------------------------------------------------------*/
#ifndef HFDP_BRIDGESHAPE_SHAPE_HPP
#define HFDP_BRIDGESHAPE_SHAPE_HPP

#include "DrawingAPI.hpp"
#include <memory>

typedef std::shared_ptr<DrawingAPI> TDrawingAPIPtr;


/*---------------------------------------------------------------------------*\
| \class    Shape
\*---------------------------------------------------------------------------*/
class Shape
{
public:
                    Shape( TDrawingAPIPtr drawing_api )
                    : m_drawing_api( drawing_api )
                    {}

    virtual        ~Shape() {};

    virtual void    draw() = 0;
    virtual void    resize( double ) = 0;

protected:
    TDrawingAPIPtr  m_drawing_api;
};

#endif//HFDP_BRIDGESHAPE_SHAPE_HPP
