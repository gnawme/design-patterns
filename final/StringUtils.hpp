#ifndef FINAL_STRING_UTILS_HPP
#define FINAL_STRING_UTILS_HPP
/*---------------------------------------------------------------------------*\
| \file     StringUtils.hpp
| \brief    String utilities
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <sstream>
#include <string>
#include <vector>

typedef std::vector<std::string>    TStringVec;

void        remove_invalid( TStringVec& valid, const TStringVec& invalid );
TStringVec  split( const std::string& s, char delim, TStringVec& elems );
TStringVec  split( const std::string& s, char delim );
std::string trim( std::string& trimit );
bool        verify( const TStringVec& input, const TStringVec& valid, TStringVec& invalid );
bool        verify( const std::string& input, const TStringVec& valid, TStringVec& invalid );

#endif//FINAL_STRING_UTILS_HPP
