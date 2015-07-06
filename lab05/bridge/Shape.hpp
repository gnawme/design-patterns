#ifndef LAB05_BRIDGE_SHAPE_HPP
#define LAB05_BRIDGE_SHAPE_HPP
/*---------------------------------------------------------------------------*\
| \file     Shape.hpp
| \brief    Shape abstract base class
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "PlatformDecl.hpp"

/*---------------------------------------------------------------------------*\
| \class    Shape
| \brief    Shape abstract base class, base of the Abstraction hierarchy
| \note     Composes Platform* for derived classes
\*---------------------------------------------------------------------------*/
class Shape
{
public:
                    Shape( TPlatformPtr platform )
                    : m_platform( platform )
                    {}

    virtual        ~Shape() {};

    virtual void    draw() = 0;

protected:
    TPlatformPtr    m_platform;
};


#endif//LAB05_BRIDGE_SHAPE_HPP
