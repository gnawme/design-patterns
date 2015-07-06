#ifndef LAB04_CHAIN_OF_RESPONSIBILITY_PERSONNEL_HPP
#define LAB04_CHAIN_OF_RESPONSIBILITY_PERSONNEL_HPP
/*---------------------------------------------------------------------------*\
| \file     Personnel.hpp
| \brief    Concrete Handlers for Chain of Responsibility design pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Handler.hpp"

/*---------------------------------------------------------------------------*\
| \class    Captain
\*---------------------------------------------------------------------------*/
class Captain: public Handler
{
public:
                    Captain();
                   ~Captain() {};

    void            handle_request( unsigned int );

private:
    unsigned int    m_paygrade;
};

/*---------------------------------------------------------------------------*\
| \class    Colonel
\*---------------------------------------------------------------------------*/
class Colonel: public Handler
{
public:
                    Colonel();
                   ~Colonel() {};

    void            handle_request( unsigned int );

private:
    unsigned int    m_paygrade;
};

/*---------------------------------------------------------------------------*\
| \class    CommanderInChief
\*---------------------------------------------------------------------------*/
class CommanderInChief: public Handler
{
public:
                    CommanderInChief();
                   ~CommanderInChief() {};

    void            handle_request( unsigned int );

private:
    unsigned int    m_paygrade;
};

/*---------------------------------------------------------------------------*\
| \class    General
\*---------------------------------------------------------------------------*/
class General: public Handler
{
public:
                    General();
                   ~General() {};

    void            handle_request( unsigned int );

private:
    unsigned int    m_paygrade;
};

/*---------------------------------------------------------------------------*\
| \class    Lieutenant
\*---------------------------------------------------------------------------*/
class Lieutenant: public Handler
{
public:
                    Lieutenant();
                   ~Lieutenant() {};

    void            handle_request( unsigned int );

private:
    unsigned int    m_paygrade;
};

/*---------------------------------------------------------------------------*\
| \class    LieutenantColonel
\*---------------------------------------------------------------------------*/
class LieutenantColonel: public Handler
{
public:
                    LieutenantColonel();
                   ~LieutenantColonel() {};

    void            handle_request( unsigned int );

private:
    unsigned int    m_paygrade;
};

/*---------------------------------------------------------------------------*\
| \class    Major
\*---------------------------------------------------------------------------*/
class Major: public Handler
{
public:
                    Major();
                   ~Major() {};

    void            handle_request( unsigned int );

private:
    unsigned int    m_paygrade;
};

#endif//LAB04_CHAIN_OF_RESPONSIBILITY_PERSONNEL_HPP
