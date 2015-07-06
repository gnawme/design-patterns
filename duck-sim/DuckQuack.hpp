/*--------------------------------------------------------------------*\
| \file     DuckQuack.hpp
| \author   Norm Evangelista
| \brief    Defines quacking behaviors for Duck Simulator
\*--------------------------------------------------------------------*/
#include <string>

/*--------------------------------------------------------------------*\
| \class    DuckQuack
| \brief    DuckQuack abstract base class
\*--------------------------------------------------------------------*/
class DuckQuack
{
public:
    virtual std::string quack_ducky_quack() = 0;
};

/*--------------------------------------------------------------------*\
| \brief    DuckQuack derivatives
\*--------------------------------------------------------------------*/
class DuckQuackStandard: public DuckQuack
{
public:
    std::string quack_ducky_quack()
    {
        return std::string( "Quack, dude." );
    }
};

class DuckQuackRetro: public DuckQuack
{
public:
    std::string quack_ducky_quack()
    {
        return std::string( "Like, quack, man." );
    }
};

class DuckQuackClassic: public DuckQuack
{
public:
    std::string quack_ducky_quack()
    {
        return std::string( "To quack, perchance, to dream -- ay, there's the tub." );
    }
};