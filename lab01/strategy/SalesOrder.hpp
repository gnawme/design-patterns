#ifndef LAB01_STRATEGY_SALES_ORDER_HPP
#define LAB01_STRATEGY_SALES_ORDER_HPP
/*---------------------------------------------------------------------------*\
| \file     SalesOrder.hpp
| \brief    SalesOrder class for Strategy Pattern example
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <string>

#include "CountryIntel.hpp"

/*---------------------------------------------------------------------------*\
| \class    SalesOrder
\*---------------------------------------------------------------------------*/
class SalesOrder
{
public:
                    SalesOrder( int, double, CountryCode );
                   ~SalesOrder();
    void            process();

private:
                    SalesOrder();
    std::wstring    create_order_summary();
    std::wstring    get_time();


    int             m_quantity;
    double          m_unit_price;
    TCountryPtr     m_country_intel;
};

#endif//LAB01_STRATEGY_SALES_ORDER_HPP