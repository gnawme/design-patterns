/*---------------------------------------------------------------------------*\
| \file     DecoratorDemo.cpp
| \brief    Main for Lab 3 Decorator Pattern homework
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Models.hpp"
#include "Options.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

typedef std::vector<TCarPtr>    TCarVec;

/*---------------------------------------------------------------------------*\
| \fn       print_car_configuration
| \brief    Prints out the configuration of the current car
\*---------------------------------------------------------------------------*/
void print_car_configuration( TCarPtr item )
{
    std::cout
    << std::endl
    << item->get_description()
    << std::endl
    << "\t$"
    << std::fixed
    << std::setprecision(2)
    << item->get_cost()
    << std::endl; 
}

/*---------------------------------------------------------------------------*\
| \fn       main
| \brief    Main assembly site for cars and options
\*---------------------------------------------------------------------------*/
int main()
{
    TCarVec purchases;
    /*-----------------------------------------------------------------------*\
    |   2 Door Runabout
    \*-----------------------------------------------------------------------*/
    TCarPtr mine = std::make_shared<BaseModel>( "Runabout: MINI Hardtop 2 Door" );
    mine = std::make_shared<TwoDoor>( mine );

    purchases.push_back( mine );

    /*-----------------------------------------------------------------------*\
    |   4 Door SUV with AC and automatic transmission
    \*-----------------------------------------------------------------------*/
    TCarPtr yours = std::make_shared<BaseModel>( "SUV: MINI Countryman" );
    yours = std::make_shared<FourDoor>( yours );
    yours = std::make_shared<AC>( yours );
    yours = std::make_shared<AutomaticTransmission>( yours );

    purchases.push_back( yours );

    /*-----------------------------------------------------------------------*\
    |   4 Door Status with AC, premium sound system, navigation, AT 
    \*-----------------------------------------------------------------------*/
    TCarPtr hers = std::make_shared<BaseModel>( "Status: MINI Paceman ALL4" );
    hers = std::make_shared<FourDoor>( hers );
    hers = std::make_shared<AC>( hers );
    hers = std::make_shared<PremiumSoundSytem>( hers );
    hers = std::make_shared<Navigation>( hers );
    hers = std::make_shared<AutomaticTransmission>( hers );

    purchases.push_back( hers );

    /*-----------------------------------------------------------------------*\
    |   2 Door Performance with AC, premium sound system, navigation,
    |   MT, V8, and supercharger
    \*-----------------------------------------------------------------------*/
    TCarPtr boss = std::make_shared<BaseModel>( "Performance: MINI John Cooper Works" );
    boss = std::make_shared<TwoDoor>( boss );
    boss = std::make_shared<AC>( boss );
    boss = std::make_shared<PremiumSoundSytem>( boss );
    boss = std::make_shared<Navigation>( boss );
    boss = std::make_shared<ManualTransmission>( boss );
    boss = std::make_shared<V8>( boss );
    boss = std::make_shared<SuperCharger>( boss );

    purchases.push_back( boss );

    /*-----------------------------------------------------------------------*\
    |   Iterate through purchases and print them out
    \*-----------------------------------------------------------------------*/
    for ( auto& it : purchases )
    {
        print_car_configuration( it );
    }

    return EXIT_SUCCESS;
}