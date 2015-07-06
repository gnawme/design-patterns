#ifndef LAB05_BRIDGE_PLATFORM_DECL_HPP
#define LAB05_BRIDGE_PLATFORM_DECL_HPP
/*---------------------------------------------------------------------------*\
| \file     PlatformDecl.hpp
| \brief    Centralizes Platform shared pointer declaration
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <memory>

class Platform;
typedef std::shared_ptr<Platform>   TPlatformPtr;

#endif//LAB05_BRIDGE_PLATFORM_DECL_HPP
