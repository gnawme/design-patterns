#ifndef LAB05_BRIDGE_PLATFORM_HPP
#define LAB05_BRIDGE_PLATFORM_HPP
/*---------------------------------------------------------------------------*\
| \file     Platform.hpp
| \brief    Platform abstract base class
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*\
| \class    Platform
| \brief    Platform abstract class, base of the Implementation hierarchy
\*---------------------------------------------------------------------------*/
class Platform
{
public:
    virtual        ~Platform() {};

    virtual void    draw_line( double, double, double, double ) = 0;
    virtual void    draw_arc( double, double, double, double ) = 0;
};

#endif//LAB05_BRIDGE_PLATFORM_HPP
