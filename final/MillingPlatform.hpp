#ifndef FINAL_MILLING_PLATFORM_HPP
#define FINAL_MILLING_PLATFORM_HPP
/*---------------------------------------------------------------------------*\
| \file     MillingPlatformAP.hpp
| \brief    Abstract Factory abstract and concrete products
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "InjectionLineComponents.hpp"

#include <iostream>
#include <string>

/*---------------------------------------------------------------------------*\
| \class    MillingPlatformAP
| \brief    Abstract Product base class
\*---------------------------------------------------------------------------*/
class MillingPlatformAP
{
public:
    virtual            ~MillingPlatformAP()
                        {
                            std::cout 
                            << "~MillingPlatformAP "
                            << std::endl;
                        }


    virtual std::string description() = 0;
};

/*---------------------------------------------------------------------------*\
| \class    MillingPlatformHighCarbon
| \brief    Concrete Product
\*---------------------------------------------------------------------------*/
class MillingPlatformHighCarbon: public MillingPlatformAP
{
public:
                    MillingPlatformHighCarbon( TInjectionPtr );
                   ~MillingPlatformHighCarbon()
                    {
                        std::cout 
                        << "~MillingPlatformHighCarbon ";
                    }


    std::string     description();

private:
    TInjectionPtr   m_injector;
};

/*---------------------------------------------------------------------------*\
| \class    MillingPlatformCarbide
| \brief    Concrete Product
\*---------------------------------------------------------------------------*/
class MillingPlatformCarbide: public MillingPlatformAP
{
public:
                    MillingPlatformCarbide( TInjectionPtr );
                   ~MillingPlatformCarbide()
                    {
                        std::cout 
                        << "~MillingPlatformCarbide ";
                    }

    std::string     description();

private:
    TInjectionPtr   m_injector;
};

/*---------------------------------------------------------------------------*\
| \class    MillingPlatformDiamondTipped
| \brief    Concrete Product
\*---------------------------------------------------------------------------*/
class MillingPlatformDiamondTipped: public MillingPlatformAP
{
public:
                    MillingPlatformDiamondTipped( TInjectionPtr );
                   ~MillingPlatformDiamondTipped()
                    {
                        std::cout 
                        << "~MillingPlatformDiamondTipped ";
                    }

    std::string     description();

private:
    TInjectionPtr   m_injector;
};

#endif//FINAL_MILLING_PLATFORM_HPP
