/*---------------------------------------------------------------------------*\
|
\*---------------------------------------------------------------------------*/
#include "Condiments.hpp"
#include "Drinks.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>

/*---------------------------------------------------------------------------*\
| \fn       print_menu_item
| \brief    Prints out the menu item
\*---------------------------------------------------------------------------*/
void print_menu_item( TBeveragePtr item )
{
    std::cout
    << item->get_description()
    << ", $"
    << std::fixed
    << std::setprecision(2)
    << item->get_cost()
    << std::endl;
    
}

/*---------------------------------------------------------------------------*\
| \fn       main
| \brief    The main thang
\*---------------------------------------------------------------------------*/
int main()
{
    TBeveragePtr espresso = std::make_shared<Espresso>();
    print_menu_item( espresso );

    TBeveragePtr dark = std::make_shared<DarkRoast>();
    dark = std::make_shared<Mocha>( dark );
    dark = std::make_shared<Mocha>( dark );
    dark = std::make_shared<Whip>( dark );
    print_menu_item( dark );

    TBeveragePtr house = std::make_shared<HouseBlend>();
    house = std::make_shared<Soy>( house );
    house = std::make_shared<Mocha>( house );
    house = std::make_shared<Whip>( house );
    print_menu_item( house );

    return EXIT_SUCCESS;
}