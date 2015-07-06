/*---------------------------------------------------------------------------*\
| \file     StrategyDemo.cpp
| \brief    Loads and runs Strategy Pattern demo
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "SalesOrder.hpp"

#include <memory>
#include <vector>

typedef std::unique_ptr<SalesOrder> TSalesOrderPtr;
typedef std::vector<TSalesOrderPtr> TSalesOrderVec;

/*---------------------------------------------------------------------------*\
| \fn       main
| \brief    Strategy Pattern demo main
\*---------------------------------------------------------------------------*/
int main()
{
    TSalesOrderVec sales;
    
    sales.push_back( TSalesOrderPtr( new SalesOrder( 5, 10.0, USA ) ) );
    sales.push_back( TSalesOrderPtr( new SalesOrder( 1, 20.0, Canada ) ) );
    sales.push_back( TSalesOrderPtr( new SalesOrder( 3, 15.0, Quebec ) ) );
    sales.push_back( TSalesOrderPtr( new SalesOrder( 2, 99.99, Germany ) ) );

    for ( auto& it : sales )                                         
    {
        it->process();
    }

    return EXIT_SUCCESS;
}
