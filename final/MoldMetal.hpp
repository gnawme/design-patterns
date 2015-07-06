#ifndef FINAL_MOLD_METAL_HPP
#define FINAL_MOLD_METAL_HPP
/*---------------------------------------------------------------------------*\
| \file     MoldMetalAF.hpp
| \brief    Abstract Factory for mold metals and their products
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "InjectionLineComponents.hpp"

#include <iostream>
#include <memory>

class MillingPlatformAP;
typedef std::shared_ptr<MillingPlatformAP>  TMillPlatformPtr;

/*---------------------------------------------------------------------------*\
| \class    MoldMetalAF
| \brief    Base AbstractFactory
\*---------------------------------------------------------------------------*/
class MoldMetalAF
{
public:
    virtual                    ~MoldMetalAF()
                                {
                                    std::cout 
                                    << "~MoldMetalAF "
                                    << std::endl;
                                }


    virtual TMillPlatformPtr    get_milling_platform() = 0;  
};

typedef std::shared_ptr<MoldMetalAF>    TMoldMetalPtr;

/*---------------------------------------------------------------------------*\
| \class    MoldMetalAluminum
| \brief    ConcreteFactory for aluminum
\*---------------------------------------------------------------------------*/
class MoldMetalAluminum: public MoldMetalAF
{
public:
                        MoldMetalAluminum( TInjectionPtr );
                       ~MoldMetalAluminum()
                        {
                            std::cout 
                            << "~MoldMetalAluminum ";
                        }


    TMillPlatformPtr    get_milling_platform();

private:
    TInjectionPtr       m_injector;
};

/*---------------------------------------------------------------------------*\
| \class    MoldMetalSteel
| \brief    ConcreteFactory for stainless steel
\*---------------------------------------------------------------------------*/
class MoldMetalSteel: public MoldMetalAF
{
public:
                        MoldMetalSteel( TInjectionPtr );
                       ~MoldMetalSteel()
                        {
                            std::cout 
                            << "~MoldMetalSteel ";
                        }


    TMillPlatformPtr    get_milling_platform();  

private:
    TInjectionPtr       m_injector;
};

#endif//FINAL_MOLD_METAL_HPP
