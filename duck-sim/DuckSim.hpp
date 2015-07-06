/*--------------------------------------------------------------------*\
| \file     DuckSim.hpp
| \author   Norm Evangelista
| \brief    Duck Simulator
\*--------------------------------------------------------------------*/
#include <memory>
#include <string>

class DuckFly;
class DuckQuack;

/*--------------------------------------------------------------------*\
| \class    DuckSim
| \brief    Duck simulator for type, flying, and quacking 
\*--------------------------------------------------------------------*/
class DuckSim
{
public:
            DuckSim( const char*, DuckFly*, DuckQuack* );
   
   void     display();

private:
            DuckSim();

    std::string                 whoAmI;
    std::unique_ptr<DuckFly>    flyBehavior;
    std::unique_ptr<DuckQuack>  quackBehavior;

};