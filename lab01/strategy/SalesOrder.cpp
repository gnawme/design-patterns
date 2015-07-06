/*---------------------------------------------------------------------------*\
| \file     SalesOrder.cpp
| \brief    SalesOrder class and ancillary data for Strategy Pattern example
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "SalesOrder.hpp"

#include <clocale>
#include <cwchar>
#include <iomanip>
#include <iostream>
#include <sstream>

/*---------------------------------------------------------------------------*\
| \fn       SalesOrder::SalesOrder
| \brief    SalesOrder constructor
\*---------------------------------------------------------------------------*/
SalesOrder::SalesOrder(
    int         quantity,
    double      unit_price,
    CountryCode country_code )
    : m_quantity( quantity )
    , m_unit_price( unit_price )
    , m_country_intel( CountryHelper::get_country_intel( country_code ) )
{}

SalesOrder::~SalesOrder()
{
    std::cerr << "Ciao-ciao, SalesOrder" << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       SalesOrder::process
| \brief    Processes a sales order and outputs a formatted summary
\*---------------------------------------------------------------------------*/
void SalesOrder::process()
{
    std::wcout << std::endl << create_order_summary() << std::endl;
}

/*---------------------------------------------------------------------------*\
| \private
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
| \fn       SalesOrder::get_time
| \brief    Creates a formatted date/time string
| \return   Formatted date/time string
\*---------------------------------------------------------------------------*/
std::wstring SalesOrder::get_time()
{
    std::time_t tyme = std::time( nullptr );
    std::wstring format = m_country_intel->get_country_date_format();

    const int bufsize = 64;
    wchar_t buf[bufsize] = {L'0'};
    std::wcsftime( buf, bufsize, format.c_str(), std::localtime( &tyme ) );

    return std::wstring( buf );
}

/*---------------------------------------------------------------------------*\
| \fn       SalesOrder::create_order_summary
| \brief    Creates a formatted sales order summmary
| \return   Formatted summary string
\*---------------------------------------------------------------------------*/
std::wstring SalesOrder::create_order_summary()
{
    /*-----------------------------------------------------------------------*\
    |   Compute quantities
    \*-----------------------------------------------------------------------*/
    double sale = m_quantity * m_unit_price;
    double tax  = m_country_intel->compute_tax( sale );

    std::wstringstream ss;
    /*-----------------------------------------------------------------------*\
    |   Imbue the stream with the locale
    \*-----------------------------------------------------------------------*/
    std::string locale = m_country_intel->get_country_locale();
    std::locale::global( std::locale( locale ) );
    std::lconv* lc = std::localeconv();
    
    ss.imbue( std::locale( locale ) );

    /*-----------------------------------------------------------------------*\
    |   Construct the summary
    |   NOTE: Inputs to std::put_money are in cents
    \*-----------------------------------------------------------------------*/
    ss
    << lc->int_curr_symbol 
    << " "
    << lc->currency_symbol
    << std::put_money( 100.0 * ( sale + tax ) ) 
    << " ("
    << lc->currency_symbol 
    << std::put_money( 100.0 * tax )
    << " tax)"
    << L" for " << m_country_intel->get_country_string()
    << L" on " << get_time();

    /*-----------------------------------------------------------------------*\
    |   Reset the locale and return the summary string
    \*-----------------------------------------------------------------------*/
    std::locale::classic();
    return ss.str();
}

