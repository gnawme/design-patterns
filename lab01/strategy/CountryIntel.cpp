/*---------------------------------------------------------------------------*\
| \file     CountryIntel.cpp
| \brief    Implementation of CountryIntel classes
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "CountryIntel.hpp"

#include <string>

/*---------------------------------------------------------------------------*\
| \fn       CountryHelper::get_country_intel
| \brief    Instantiates a CountryIntel object given a country code
\*---------------------------------------------------------------------------*/
CountryIntel* CountryHelper::get_country_intel
( const CountryCode   country_code )
{
    switch( country_code )
    {
    case USA:
        return new CountryIntelUSA();
        break;
    case Canada:
        return new CountryIntelCAN( Canada );
        break;
    case Quebec:
        return new CountryIntelCAN( Quebec );
        break;
    case Germany:
        return new CountryIntelDEU();
        break;
    default:
        return new CountryIntelUSA();
    };

    return nullptr;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelCAN::CountryIntelCAN
| \brief    CAN specific implementation
\*---------------------------------------------------------------------------*/
CountryIntelCAN::CountryIntelCAN(
    CountryCode country )
    : m_is_election_year( true )
    , m_is_quebec( country == Quebec )
    , m_tax_rate( 0.065 )
    , m_date_format( L"%m%d%y (%c)" )
    , m_locale( "en-CA" )
    , m_country_string( L"CAN" )
{
    if ( m_is_election_year )
    /*-----------------------------------------------------------------------*\
    |   Set election-year tax rate
    \*-----------------------------------------------------------------------*/
    {
        m_tax_rate = 0.075;
    }

    if ( m_is_quebec )
    /*-----------------------------------------------------------------------*\
    |   Set Quebec-specific values
    \*-----------------------------------------------------------------------*/
    {
        m_locale = "fr-CA";
        m_country_string = L"CAN (QC)";
    }
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelCAN::compute_tax
| \brief    CAN specific tax computation
\*---------------------------------------------------------------------------*/
double CountryIntelCAN::compute_tax(
    double  sale_price )
{
    return m_tax_rate * sale_price;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelCAN::get_country_date_format
| \brief    Gets date format specified by assignment
| \return   Date format string
\*---------------------------------------------------------------------------*/
std::wstring CountryIntelCAN::get_country_date_format()
{
    return m_date_format;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelCAN::get_country_locale
| \brief    Gets NLS locale
| \return   NLS locale name
\*---------------------------------------------------------------------------*/
std::string CountryIntelCAN::get_country_locale()
{
    return m_locale;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelCAN::get_country_string
| \brief    Gets NLS country abbreviation
| \return   NLS country abbreviation
\*---------------------------------------------------------------------------*/
std::wstring CountryIntelCAN::get_country_string()
{
    return m_country_string;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelDEU::CountryIntelDEU
| \brief    DEU specific implementation
\*---------------------------------------------------------------------------*/
CountryIntelDEU::CountryIntelDEU()
    : m_tax_rate( 0.077 )
    , m_date_format( L"%d%m%Y (%c)" )
    , m_locale( "de-DE" )
    , m_country_string( L"DEU" )
{}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelDEU::compute_tax
| \brief    DEU specific tax computation
\*---------------------------------------------------------------------------*/
double CountryIntelDEU::compute_tax(
    double  sale_price )
{
    bool check = luxurious( sale_price );
    return m_tax_rate * sale_price;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelDEU::get_country_date_format
| \brief    Gets date format specified by assignment
| \return   Date format string
\*---------------------------------------------------------------------------*/
std::wstring CountryIntelDEU::get_country_date_format()
{
    return m_date_format;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelDEU::get_country_locale
| \brief    Gets NLS locale
| \return   NLS locale name
\*---------------------------------------------------------------------------*/
std::string CountryIntelDEU::get_country_locale()
{
    return m_locale;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelDEU::get_country_string
| \brief    Gets NLS country abbreviation
| \return   NLS country abbreviation
\*---------------------------------------------------------------------------*/
std::wstring CountryIntelDEU::get_country_string()
{
    return m_country_string;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelDEU::luxurious
| \brief    Determines whether luxury tax rate should apply
| \return   true if sale amount exceeds threshold
\*---------------------------------------------------------------------------*/
bool CountryIntelDEU::luxurious(
    double  sale_price )
{
    const double threshold = 10000.00;
    if ( sale_price >= threshold )
    {
        m_tax_rate = 0.088;
        return true;
    }

    return false;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelUSA::CountryIntelUSA
| \brief    USA specific implementation
\*---------------------------------------------------------------------------*/
CountryIntelUSA::CountryIntelUSA()
    : m_tax_rate( 0.060 )
    , m_date_format( L"%m%d%y (%c)" )
    , m_locale( "en-US" )
    , m_country_string( L"USA" )
{}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelUSA::compute_tax
| \brief    USA specific tax computation
\*---------------------------------------------------------------------------*/
double CountryIntelUSA::compute_tax(
    double  sale_price )
{
    return tax_by_state() * sale_price;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelUSA::get_country_date_format
| \brief    Gets date format specified by assignment
| \return   Date format string
\*---------------------------------------------------------------------------*/
std::wstring CountryIntelUSA::get_country_date_format()
{
    return m_date_format;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelUSA::get_country_locale
| \brief    Gets NLS locale
| \return   NLS locale name
\*---------------------------------------------------------------------------*/
std::string CountryIntelUSA::get_country_locale()
{
    return m_locale;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelUSA::get_country_string
| \brief    Gets NLS country abbreviation
| \return   NLS country abbreviation
\*---------------------------------------------------------------------------*/
std::wstring CountryIntelUSA::get_country_string()
{
    return m_country_string;
}

/*---------------------------------------------------------------------------*\
| \fn       CountryIntelUSA::tax_by_state
| \brief    Pretend we have a tax lookup by state
\*---------------------------------------------------------------------------*/
double CountryIntelUSA::tax_by_state()
{
    return m_tax_rate;
}


