/*---------------------------------------------------------------------------*\
| \file     OrderProcessing.cpp
| \brief    API to read order file and process orders
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "OrderProcessing.hpp"

#include "AssemblyLines.hpp"
#include "AssemblyState.hpp"
#include "StringUtils.hpp"

#include <fstream>
#include <iostream>

/*---------------------------------------------------------------------------*\
| \fn       check_key
| \brief    Check if specific keys are present in order
\*---------------------------------------------------------------------------*/
bool check_key(
    TOrderMap&  order,
    std::string key )
{
    return ( order.count( key ) == 1 );
}

bool check_key(
    TOrderMap&  order,
    std::string key,
    std::string message )
{
    if ( check_key( order, key ) == false )
    {
        std::cout
        << message
        << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}

/*---------------------------------------------------------------------------*\
| \fn       configure_assembly
| \brief    Configures the assembly state from the order
\*---------------------------------------------------------------------------*/
void configure_assembly(
    TOrderMap&  order )
{
    AssemblyState state;
    state.set_defaults();

    /*-----------------------------------------------------------------------*\
    |   Check if specific items are present in order, and notify of defaults
    \*-----------------------------------------------------------------------*/
    bool present = check_key( order, 
        "plastic", 
        "\t<>Unknown plastic || defaulting to ABS." );

    if ( present )
    {
        state.set_plastic_type( order["plastic"] );
    }

    present = check_key( order, 
        "size", 
        "\t<>No size specified, defaulting to 100." );

    if ( present )
    {
        state.set_order_size( std::stoi( order["size"] ) );
    }

    present = check_key( order, 
        "packager", 
        "\t<>Unknown packager || defaulting to Bulk packager." );

    if ( present )
    {
        state.set_packager( order["packager"] );
    }

    present = check_key( order, 
        "stuffer", 
        "\t<>Unknown stuffer || defaulting to Air stuffer." );

    if ( present )
    {
        state.set_stuffer( order["stuffer"] );
    }

    PlasticType plastic = state.get_plastic_enum();
    TAssemblyLinePtr injection_line( 
        AssemblyLineFactory::get_assembly_line( order, plastic ) );

    injection_line->process_order();
}

/*---------------------------------------------------------------------------*\
| \fn       echo_order
| \brief    Echoes order to stdout
\*---------------------------------------------------------------------------*/
void echo_order(
    TOrderMap&  order )
{
    std::cout
    << std::endl
    << order["orderNum"]
    << ":"
    << std::endl;

    auto maxlen = 0;

    for ( const auto info : order )
    {
        maxlen = std::max<size_t>( maxlen, info.first.length() );
    }

    for ( TOrderMap::iterator info = order.begin(); info != order.end(); ++info )
    {
        auto numblanks = maxlen - info->first.length() + 1;

        std::string blanks( numblanks, ' ' );
        std::cout
        << "\t"
        << info->first
        << blanks
        << " = "
        << info->second
        << std::endl;
    }

    std::cout << "\tendOfOrder" << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       get_complete_order
| \brief    Processes a complete order from input
| \return   TOrderMap containing the order info
\*---------------------------------------------------------------------------*/
TOrderMap get_complete_order(
    std::ifstream&  orderfile )
{
    TOrderMap   orders;

    std::string line;
    while ( orderfile )
    {
        for ( std::string line; std::getline( orderfile, line ); )
        {
            // Skip order tag
            if ( line.find( ':' ) != std::string::npos )
                continue;

            // Relevant lines contain a '='
            std::string::size_type idx = line.find( '=' );
            if ( idx != std::string::npos )
            {
                std::cout << line << std::endl;
                std::string key = trim( line.substr( 0, idx ) );
                std::string val = trim( line.substr( idx+1, line.length() ) );
                orders[key]     = val;
            }

            // End marker
            if ( line.find( "endOfOrder" ) != std::string::npos )
            {
                std::cout << line << std::endl;
                return TOrderMap( orders );
            }
        }
    }

    return TOrderMap( orders );
}

/*---------------------------------------------------------------------------*\
| \fn       process
| \brief    Processes one order
\*---------------------------------------------------------------------------*/
void process(
    TOrderMap&  order )
{
    //echo_order( order );
    configure_assembly( order );
}
