#ifndef FINAL_ORDER_PROCESSING_HPP
#define FINAL_ORDER_PROCESSING_HPP
/*---------------------------------------------------------------------------*\
| \file     OrderProcessing.hpp
| \brief    API to read order file and process orders
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <iosfwd>
#include <map>
#include <string>

typedef std::map<std::string, std::string>  TOrderMap;
typedef std::pair<std::string, std::string> TOrderPair;

/*---------------------------------------------------------------------------*\
|   Functions in API
\*---------------------------------------------------------------------------*/
bool        check_key( TOrderMap& order, std::string key );
bool        check_key( TOrderMap& order, std::string key, std::string msg );
void        configure_assembly( TOrderMap& order );
void        echo_order( TOrderMap& order );
TOrderMap   get_complete_order( std::ifstream&  orderfile );
void        process( TOrderMap& order );


#endif//FINAL_ORDER_PROCESSING_HPP
