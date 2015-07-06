/*---------------------------------------------------------------------------*\
| \file     BridgeDemo.cpp
| \brief    Lab 5 Bridge Pattern lab demo
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "PlatformImpl.hpp"
#include "ShapeImpl.hpp"

#include <array>
#include <cstdlib>

/*---------------------------------------------------------------------------*\
| \fn       main
\*---------------------------------------------------------------------------*/
int main()
{

    std::array<WhichPlatform, 3> platforms = {e_Raster, e_Vector, e_Plotter};

    for ( auto it : platforms )
    /*-----------------------------------------------------------------------*\
    |   Iterate through each Platform type and draw a Shape in each
    \*-----------------------------------------------------------------------*/
    {
        TPlatformPtr platform = PlatformFactory::get_platform( it );

        Rectangle rect = Rectangle( platform, 1.0, 1.0, 2.0, 3.0 );
        Circle circle  = Circle( platform, 4.0, 4.0, 1.0 );

        rect.draw();
        circle.draw();
    }

    return EXIT_SUCCESS;
}