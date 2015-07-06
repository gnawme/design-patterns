#ifndef LAB04_CHAIN_OF_RESPONSIBILITY_HANDLER_HPP
#define LAB04_CHAIN_OF_RESPONSIBILITY_HANDLER_HPP
/*---------------------------------------------------------------------------*\
| \file     Handler.hpp
| \brief    Handler abstract base class for Chain of Responsibility
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <memory>

class Handler;
typedef std::shared_ptr<Handler>    THandlerPtr;

/*---------------------------------------------------------------------------*\
| \class    Handler
| \brief    Handler base class
| \note     Provide default implementation for set_superior
\*---------------------------------------------------------------------------*/
class Handler
{
public:
    virtual        ~Handler() {};

    virtual void    handle_request( unsigned int ) = 0;
    virtual void    set_superior( THandlerPtr superior )
                    {
                        m_superior = superior;
                    }

protected:
    THandlerPtr     m_superior;
};

#endif//LAB04_CHAIN_OF_RESPONSIBILITY_HANDLER_HPP