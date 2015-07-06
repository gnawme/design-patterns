/*---------------------------------------------------------------------------*\
| \file     Personnel.cpp
| \brief    Concrete Handler implementations for Chain of Responsibility
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "Personnel.hpp"

#include <iostream>
#include <iomanip>

/*---------------------------------------------------------------------------*\
| \fn       Captain::Captain
\*---------------------------------------------------------------------------*/
Captain::Captain()
    : m_paygrade( 20 )
{}

/*---------------------------------------------------------------------------*\
| \fn       Captain::handle_request
\*---------------------------------------------------------------------------*/
void Captain::handle_request
(   unsigned int    request )
{
    if ( request < m_paygrade )
    {
        std::cout
        << "Request "
        << request
        << ": "
        << "Captain Pierce -- I've got this one."
        << std::endl;
    }
    else
    {
        m_superior->handle_request( request );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       Colonel::Colonel
\*---------------------------------------------------------------------------*/
Colonel::Colonel()
    : m_paygrade( 50 )
{}

/*---------------------------------------------------------------------------*\
| \fn       Colonel::handle_request
\*---------------------------------------------------------------------------*/
void Colonel::handle_request
(   unsigned int    request )
{
    if ( request < m_paygrade )
    {
        std::cout
        << "Request "
        << request
        << ": "
        << "Colonel Pierce -- I've got this one."
        << std::endl;
    }
    else
    {
        m_superior->handle_request( request );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       CommanderInChief::CommanderInChief
\*---------------------------------------------------------------------------*/
CommanderInChief::CommanderInChief()
    : m_paygrade( 20 )
{}

/*---------------------------------------------------------------------------*\
| \fn       CommanderInChief::handle_request
\*---------------------------------------------------------------------------*/
void CommanderInChief::handle_request
(   unsigned int    request )
{
    std::cout
    << "Request "
    << request
    << ": "
    << "Commander-in-Chief Truman -- The buck stops here."
    << std::endl;
}

/*---------------------------------------------------------------------------*\
| \fn       General::General
\*---------------------------------------------------------------------------*/
General::General()
    : m_paygrade( 60 )
{}

/*---------------------------------------------------------------------------*\
| \fn       General::handle_request
\*---------------------------------------------------------------------------*/
void General::handle_request
(   unsigned int    request )
{
    if ( request < m_paygrade )
    {
        std::cout
        << "Request "
        << request
        << ": "
        << "General Rothaker -- I've got this one."
        << std::endl;
    }
    else
    {
        Handler::m_superior->handle_request( request );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       Lieutenant::Lieutenant
\*---------------------------------------------------------------------------*/
Lieutenant::Lieutenant()
    : m_paygrade( 10 )
{}

/*---------------------------------------------------------------------------*\
| \fn       Lieutenant::handle_request
\*---------------------------------------------------------------------------*/
void Lieutenant::handle_request
(   unsigned int    request )
{
    if ( request < m_paygrade )
    {
        std::cout
        << "Request "
        << std::setw( 2 )
        << request
        << ": "
        << "Lieutenant Yamato -- I've got this one."
        << std::endl;
    }
    else
    {
        Handler::m_superior->handle_request( request );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       LieutenantColonel::LieutenantColonel
\*---------------------------------------------------------------------------*/
LieutenantColonel::LieutenantColonel()
    : m_paygrade( 40 )
{}

/*---------------------------------------------------------------------------*\
| \fn       LieutenantColonel::handle_request
\*---------------------------------------------------------------------------*/
void LieutenantColonel::handle_request
(   unsigned int    request )
{
    if ( request < m_paygrade )
    {
        std::cout
        << "Request "
        << request
        << ": "
        << "Lieutenant Colonel Blake -- I've got this one."
        << std::endl;
    }
    else
    {
        Handler::m_superior->handle_request( request );
    }
}

/*---------------------------------------------------------------------------*\
| \fn       Major::Major
\*---------------------------------------------------------------------------*/
Major::Major()
    : m_paygrade( 30 )
{}

/*---------------------------------------------------------------------------*\
| \fn       Major::handle_request
\*---------------------------------------------------------------------------*/
void Major::handle_request
(   unsigned int    request )
{
    if ( request < m_paygrade )
    {
        std::cout
        << "Request "
        << request
        << ": "
        << "Major Houlihan -- I've got this one."
        << std::endl;
    }
    else
    {
        Handler::m_superior->handle_request( request );
    }
}
