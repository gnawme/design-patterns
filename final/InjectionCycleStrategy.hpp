#ifndef FINAL_INJECTION_CYCLE_STRATEGY_HPP
#define FINAL_INJECTION_CYCLE_STRATEGY_HPP
/*---------------------------------------------------------------------------*\
| \file     InjectionCycleStrategy.hpp
| \brief    Injection cycle strategy classes
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <iostream>
#include <memory>
#include <string>

/*---------------------------------------------------------------------------*\
| \class    InjectionCycleStrategy
| \brief    Base class for injection cycle strategies
\*---------------------------------------------------------------------------*/
class InjectionCycleStrategy
{
public:
    virtual        ~InjectionCycleStrategy()
                    { 
                        std::cout 
                        << "~InjectionCycleStrategy " 
                        << std::endl; 
                    };

    virtual void    run_process() = 0;
};

typedef std::shared_ptr<InjectionCycleStrategy> TInjectionCyclePtr;

/*---------------------------------------------------------------------------*\
| \class    InjectionCycleStrategyABS
| \brief    InjectionCycleStrategy for ABS plastic
\*---------------------------------------------------------------------------*/
class InjectionCycleStrategyABS: public InjectionCycleStrategy
{
public:
                InjectionCycleStrategyABS()
                : m_heat_temp( 440 )
                , m_cool_temp( 360 )
                , m_pressure( 125 )
                , m_eject_technique( "progressive" )
                {}

               ~InjectionCycleStrategyABS()
                { 
                    std::cout 
                    << "~InjectionCycleStrategyABS ";
                };
                
    void        run_process();

private:
    int         m_heat_temp;
    int         m_cool_temp;
    int         m_pressure;
    std::string m_eject_technique;
};

/*---------------------------------------------------------------------------*\
| \class    InjectionCycleStrategyPoly
| \brief    InjectionCycleStrategy for Polypropylene/Polyethylene
\*---------------------------------------------------------------------------*/
class InjectionCycleStrategyPoly: public InjectionCycleStrategy
{
public:
                InjectionCycleStrategyPoly()
                : m_heat_temp( 350 )
                , m_cool_temp( 290 )
                , m_pressure( 90 )
                , m_eject_technique( "smooth" )
                {}

               ~InjectionCycleStrategyPoly()
                { 
                    std::cout 
                    << "~InjectionCycleStrategyPoly ";
                };
                
    void        run_process();

private:
    int         m_heat_temp;
    int         m_cool_temp;
    int         m_pressure;
    std::string m_eject_technique;
};

/*---------------------------------------------------------------------------*\
| \class    InjectionCycleStrategyPET
| \brief    InjectionCycleStrategy for PET
\*---------------------------------------------------------------------------*/
class InjectionCycleStrategyPET: public InjectionCycleStrategy
{
public:
                InjectionCycleStrategyPET()
                : m_heat_temp( 404 )
                , m_cool_temp( 340 )
                , m_pressure( 110 )
                , m_eject_technique( "smooth" )
                {}

               ~InjectionCycleStrategyPET()
                { 
                    std::cout 
                    << "~InjectionCycleStrategyPET ";
                };
                
    void        run_process();

private:
    int         m_heat_temp;
    int         m_cool_temp;
    int         m_pressure;
    std::string m_eject_technique;
};

/*---------------------------------------------------------------------------*\
| \class    InjectionCycleStrategyStyrene
| \brief    InjectionCycleStrategy for Styrene plastic
\*---------------------------------------------------------------------------*/
class InjectionCycleStrategyStyrene: public InjectionCycleStrategy
{
public:
                InjectionCycleStrategyStyrene()
                : m_heat_temp( 480 )
                , m_cool_temp( 390 )
                , m_pressure( 150 )
                , m_eject_technique( "shock" )
                {}

               ~InjectionCycleStrategyStyrene()
                { 
                    std::cout 
                    << "~InjectionCycleStrategyStyrene ";
                };
                
    void        run_process();

private:
    int         m_heat_temp;
    int         m_cool_temp;
    int         m_pressure;
    std::string m_eject_technique;
};

/*---------------------------------------------------------------------------*\
| \class    InjectionCycleStrategyNylon66
| \brief    InjectionCycleStrategy for Nylon66 plastic
\*---------------------------------------------------------------------------*/
class InjectionCycleStrategyNylon66: public InjectionCycleStrategy
{
public:
                InjectionCycleStrategyNylon66()
                : m_heat_temp( 480 )
                , m_cool_temp( 390 )
                , m_pressure( 150 )
                , m_eject_technique( "shock" )
                {}

               ~InjectionCycleStrategyNylon66()
                { 
                    std::cout 
                    << "~InjectionCycleStrategyNylon66 ";
                };
                
    void        run_process();

private:
    int         m_heat_temp;
    int         m_cool_temp;
    int         m_pressure;
    std::string m_eject_technique;
};

#endif//FINAL_INJECTION_CYCLE_STRATEGY_HPP
