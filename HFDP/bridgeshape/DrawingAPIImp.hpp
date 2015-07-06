/*---------------------------------------------------------------------------*\
| \file     DrawingAPIImp.hpp
| \brief    Concrete DrawingAPI implementations
\*---------------------------------------------------------------------------*/
#ifndef HFDP_BRIDGESHAPE_DRAWING_API_IMP_HPP
#define HFDP_BRIDGESHAPE_DRAWING_API_IMP_HPP

#include "DrawingAPI.hpp"

#include <iomanip>
#include <iostream>

/*---------------------------------------------------------------------------*\
| \class    DrawingAPIOne
\*---------------------------------------------------------------------------*/
class DrawingAPIOne: public DrawingAPI
{
public:
    void    draw_circle( double xc, double yc, double radius )
            {
                std::cout
                << "API One at "
                << std::setw( 2 )
                << std::fixed
                << std::setprecision( 2 )
                << xc << ", "
                << yc << ", radius "
                << radius 
                << std::endl;
            }
};

/*---------------------------------------------------------------------------*\
| \class    DrawingAPITwo
\*---------------------------------------------------------------------------*/
class DrawingAPITwo: public DrawingAPI
{
public:
    void    draw_circle( double xc, double yc, double radius )
            {
                std::cout
                << "API Two at "
                << std::setw( 2 )
                << std::fixed
                << std::setprecision( 2 )
                << xc << ", "
                << yc << ", radius "
                << radius 
                << std::endl;
            }
};


#endif//HFDP_BRIDGESHAPE_DRAWING_API_IMP_HPP
