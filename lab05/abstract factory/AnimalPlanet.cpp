/*---------------------------------------------------------------------------*\
| \file     AnimalPlanet.cpp
| \brief    Lab 5 Abstract Factory Client class
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Continents.hpp"
#include "Predator.hpp"
#include "Prey.hpp"

#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

namespace
{
/*---------------------------------------------------------------------------*\
| \class    AnimalPlanet
\*---------------------------------------------------------------------------*/
class AnimalPlanet
{
public:
    //! \fn     AnimalPlanet::AnimalPlanet
    //! \brief  Constructs predator and prey for a given continent
            AnimalPlanet( TContinentPtr continent )
            : m_continent( continent ) 
            , m_predator( m_continent->create_predator() )
            , m_prey( m_continent->create_prey() )
            {}

    //! \fn     AnimalPlanet::run_food_chain
    //! \brief  Runs predator and prey simulation
    void    run_food_chain()
            {
                std::string chain( "Food chain of " + m_continent->name() );
                std::string unders( chain.length(), '=' );
                std::cout 
                << std::endl
                << "\t"
                << chain
                << std::endl
                << "\t"
                << unders
                << std::endl;

                m_prey->evade( m_predator );
                m_prey->graze();
                m_prey->mate( m_prey );

                m_predator->eat( m_prey );
                m_predator->hunt();
                m_predator->mate( m_predator );
            }

private:
    TContinentPtr   m_continent;
    TPredatorPtr    m_predator;
    TPreyPtr        m_prey;
};

}

/*---------------------------------------------------------------------------*\
| \fn       main
\*---------------------------------------------------------------------------*/
int main()
{
    std::array<TContinentPtr, 2> continents = 
    {
        TContinentPtr( std::make_shared<NorthAmerica>() ), 
        TContinentPtr( std::make_shared<Africa>() )
    };

    for ( auto continent : continents )
    {
        std::unique_ptr<AnimalPlanet> land( new AnimalPlanet( continent ) );

        land->run_food_chain();
    }

    return EXIT_SUCCESS;
}


