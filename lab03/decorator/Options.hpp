#ifndef LAB03_DECORATOR_OPTIONS_HPP
#define LAB03_DECORATOR_OPTIONS_HPP
/*---------------------------------------------------------------------------*\
| \file     Options.hpp
| \brief    Decorator Pattern options decorators
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "CarBase.hpp"

#include <memory>
#include <sstream>

/*---------------------------------------------------------------------------*\
| \note     All decorators HAVE-A Car (decorated object) by composition
\*---------------------------------------------------------------------------*/
typedef std::shared_ptr<Car>    TCarPtr;

/*---------------------------------------------------------------------------*\
| \class    TwoDoor
\*---------------------------------------------------------------------------*/
class TwoDoor: public OptionsDecorator
{
public:
                    TwoDoor( TCarPtr car )
                    : OptionsDecorator( "2 Door" )
                    , m_car( car )
                    , m_cost( 2000.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    FourDoor
\*---------------------------------------------------------------------------*/
class FourDoor: public OptionsDecorator
{
public:
                    FourDoor( TCarPtr car )
                    : OptionsDecorator( "4 Door" )
                    , m_car( car )
                    , m_cost( 4000.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    AC
\*---------------------------------------------------------------------------*/
class AC: public OptionsDecorator
{
public:
                    AC( TCarPtr car )
                    : OptionsDecorator( "Automatic Climate Control" )
                    , m_car( car )
                    , m_cost( 1500.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    PremiumSoundSytem
\*---------------------------------------------------------------------------*/
class PremiumSoundSytem: public OptionsDecorator
{
public:
                    PremiumSoundSytem( TCarPtr car )
                    : OptionsDecorator( "Harman/Kardon Sound System" )
                    , m_car( car )
                    , m_cost( 1000.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    Navigation
\*---------------------------------------------------------------------------*/
class Navigation: public OptionsDecorator
{
public:
                    Navigation( TCarPtr car )
                    : OptionsDecorator( "Navigation System" )
                    , m_car( car )
                    , m_cost( 2000.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    ManualTransmission
\*---------------------------------------------------------------------------*/
class ManualTransmission: public OptionsDecorator
{
public:
                    ManualTransmission( TCarPtr car )
                    : OptionsDecorator( "6-Speed Getrag Manual" )
                    , m_car( car )
                    , m_cost( 2500.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    AutomaticTransmission
\*---------------------------------------------------------------------------*/
class AutomaticTransmission: public OptionsDecorator
{
public:
                    AutomaticTransmission( TCarPtr car )
                    : OptionsDecorator( "6-Speed Steptronic Automatic" )
                    , m_car( car )
                    , m_cost( 3000.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    V8
\*---------------------------------------------------------------------------*/
class V8: public OptionsDecorator
{
public:
                    V8( TCarPtr car )
                    : OptionsDecorator( "6.2L LT1 V8" )
                    , m_car( car )
                    , m_cost( 6000.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

/*---------------------------------------------------------------------------*\
| \class    SuperCharger
\*---------------------------------------------------------------------------*/
class SuperCharger: public OptionsDecorator
{
public:
                    SuperCharger( TCarPtr car )
                    : OptionsDecorator( "Sprintex Supercharger" )
                    , m_car( car )
                    , m_cost( 3000.00 )
                    {}

    std::string     get_description()
                    {
                        std::stringstream ss;
                        ss 
                        << m_car->get_description()
                        << std::endl << "\t"
                        << m_description;
                        
                        return std::string( ss.str() );
                    }

    double          get_cost() { return m_cost + m_car->get_cost(); }

private:
    TCarPtr         m_car;
    double          m_cost;
};

#endif//LAB03_DECORATOR_OPTIONS_HPP
