#ifndef LAB02_SMART_HOME_FACADE_HPP
#define LAB02_SMART_HOME_FACADE_HPP
/*---------------------------------------------------------------------------*\
| \file     SmartHomeFacade.hpp
| \brief    Facade for smart home components
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <memory>

/*---------------------------------------------------------------------------*\
|   Forward references for Acme Home components
\*---------------------------------------------------------------------------*/
namespace acme_home
{
class Alarm;
class AC;
class TV;
class Lights;
}

/*---------------------------------------------------------------------------*\
| \class    SmartHomeFacade
| \brief    Facade Pattern implementation hides complexity of components
\*---------------------------------------------------------------------------*/
class SmartHomeFacade
{
public:
            SmartHomeFacade();
           ~SmartHomeFacade() {};

    void    client_arriving();
    void    client_leaving();
    void    demo();

private:
    /*-----------------------------------------------------------------------*\
    |   Pointers to Acme Home components
    \*-----------------------------------------------------------------------*/
    std::unique_ptr<acme_home::Alarm>   m_alarm;
    std::unique_ptr<acme_home::AC>      m_ac;
    std::unique_ptr<acme_home::TV>      m_tv;
    std::unique_ptr<acme_home::Lights>  m_lights;
};

#endif//#ifndef LAB02_SMART_HOME_FACADE_HPP

