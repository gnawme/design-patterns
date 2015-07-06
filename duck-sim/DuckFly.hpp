/*--------------------------------------------------------------------*\
| \author   Norm Evangelista
| \brief    Defines flying behaviors for Duck Simulator
\*--------------------------------------------------------------------*/
#include <string>

/*--------------------------------------------------------------------*\
| \class    DuckFly
| \brief    DuckFly abstract base class
\*--------------------------------------------------------------------*/
class DuckFly
{
public:
    virtual std::string fly_ducky_fly() = 0;
};

/*--------------------------------------------------------------------*\
| \brief    DuckFly derivatives
\*--------------------------------------------------------------------*/
class DuckFlyNull: public DuckFly
{
public:
    std::string fly_ducky_fly()
    {
        return std::string( "Dude, I'm only paid to float." );
    }
};

class DuckFlyNormal: public DuckFly
{
public:
    std::string fly_ducky_fly()
    {
        return std::string( "I'm flying! I'm flying!" );
    }
};

class DuckFlyHigh: public DuckFly
{
public:
    std::string fly_ducky_fly()
    {
        return std::string( "Wir fliegen fliegen fliegen uber die Autobahn." );
    }
};
