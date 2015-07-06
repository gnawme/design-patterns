/*---------------------------------------------------------------------------*\
| \file     AdapterDemo.cpp
| \brief    Various demos of the Adapter implementation
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "ShapeInterfaceDraw.hpp"
#include "AcmeShapeInterfaceDisplay.h"

#include <memory>
#include <vector>

/*---------------------------------------------------------------------------*\
|   Convenience typedefs
\*---------------------------------------------------------------------------*/
typedef std::unique_ptr<ShapeInterfaceDraw> TShapePtr;
typedef std::vector<TShapePtr>              TShapeVec;

namespace adapter_legacy
{
/*---------------------------------------------------------------------------*\
| \fn       demo
| \brief    Loads all base ShapeInterfaceDraw objects and draws them
\*---------------------------------------------------------------------------*/
void demo()
{
    TShapeVec shapes;
    shapes.push_back( TShapePtr( new Point ) );
    shapes.push_back( TShapePtr( new Line ) );
    shapes.push_back( TShapePtr( new Rect ) );

    for ( auto& it : shapes )                                         
    {
        it->draw();
    }

    std::cout << std::endl;
}
}

namespace adapter_problem
{
/*---------------------------------------------------------------------------*\
| \fn       demo
| \brief    Loads all base ShapeInterfaceDraw objects and draws them
\*---------------------------------------------------------------------------*/
void demo()
{
    TShapeVec shapes;
    shapes.push_back( TShapePtr( new Point ) );
    shapes.push_back( TShapePtr( new Line ) );
    shapes.push_back( TShapePtr( new Rect ) );
    shapes.push_back( TShapePtr( new Polygon ) );
    shapes.push_back( TShapePtr( new Torus ) );
    shapes.push_back( TShapePtr( new Bezel ) );

    for ( auto& it : shapes )                                         
    {
        it->draw();
    }

    std::cout << std::endl;
}
}


/*---------------------------------------------------------------------------*\
| \fn       main
| \brief    Demos legacy and Adapter Pattern extended interfaces
\*---------------------------------------------------------------------------*/
int main()
{
    adapter_legacy::demo();

    adapter_problem::demo();

    return EXIT_SUCCESS;
}

