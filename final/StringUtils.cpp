/*---------------------------------------------------------------------------*\
| \file     StringUtils.hpp
| \brief    String utilities
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "StringUtils.hpp"

#include <algorithm>
#include <array>

/*---------------------------------------------------------------------------*\
| \fn       remove_invalid
| \brief    Removes invalid strings from a vector
| \return   Trimmed string
\*---------------------------------------------------------------------------*/
void remove_invalid( 
    TStringVec&         valid, 
    const TStringVec&   invalid 
)
{
    for ( auto& bad : invalid )
    {
        valid.erase( std::remove( valid.begin(), valid.end(), bad ), valid.end() );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       split
| \brief    Splits a string at the given delimiter
| \return   Trimmed string
\*---------------------------------------------------------------------------*/
TStringVec split
(   const std::string&  s, 
    char                delim, 
    TStringVec&         elems ) 
{
    std::stringstream ss(s);
    std::string item;
    while ( std::getline( ss, item, delim ) ) 
    {
        elems.push_back(item);
    }

    return elems;
}

/*---------------------------------------------------------------------------*\
| \fn       split
| \brief    Splits a string at the given delimiter
| \return   Vector of strings extracted
\*---------------------------------------------------------------------------*/
TStringVec split(
    const std::string&  s, 
    char                delim ) 
{
    TStringVec elems;
    split( s, delim, elems );
    return elems;
}

/*---------------------------------------------------------------------------*\
| \fn       trim
| \brief    Trims leading and trailing whitespace from a string
| \return   Trimmed string
\*---------------------------------------------------------------------------*/
std::string trim(
    std::string&    trimit )
{
    const std::string whitespace( " \t \r" );

    auto begin = trimit.find_first_not_of( whitespace );
    if ( begin == std::string::npos )
        return ""; // no content

    auto last  = trimit.find_last_not_of( whitespace );
    auto range = last - begin + 1;

    return trimit.substr( begin, range );
}

/*---------------------------------------------------------------------------*\
| \fn       verify
| \brief    Verifies a vector of strings against a valid set
| \return   true if no invalid strings found 
\*---------------------------------------------------------------------------*/
bool verify(
    const TStringVec&   input,
    const TStringVec&   valid,
    TStringVec&         invalid )
{
    invalid.clear();
    bool all_good = true;
    for ( auto checkme : input )
    {
        auto result = std::find( valid.begin(), valid.end(), checkme );

        if ( result == valid.end() )
        {
            invalid.push_back( checkme );
        }
        all_good = all_good && ( result != valid.end() );
    }

    return all_good;
}

bool verify(
    const std::string&  input,
    const TStringVec&   valid,
    TStringVec&         invalid )
{
    TStringVec check;
    check.push_back( input );
    return verify( check, valid, invalid );
}


