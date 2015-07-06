/*---------------------------------------------------------------------------*\
|
\*---------------------------------------------------------------------------*/
#include "DrawingAPIImp.hpp"
#include "CircleShape.hpp"

#include <array>
#include <cstdlib>

typedef std::unique_ptr<Shape>  TShapePtr;

int main()
{
    std::array<TShapePtr, 2>    shapes =
    {
        TShapePtr( new CircleShape( 1, 2, 3, std::make_shared<DrawingAPIOne>() ) ),
        TShapePtr( new CircleShape( 5, 7, 11, std::make_shared<DrawingAPITwo>() ) )
    };

    for ( auto& it : shapes )
    {
        it->resize( 2.5 );
        it->draw();
    }

    return EXIT_SUCCESS;
}