#ifndef LAB03_FACTORY_CRYPTO_TYPE_FACTORY_HPP
#define LAB03_FACTORY_CRYPTO_TYPE_FACTORY_HPP
/*---------------------------------------------------------------------------*\
| \file     CryptoTypeFactory.hpp
| \brief    Video encryption types and associated factory
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <memory>
#include <string>

/*---------------------------------------------------------------------------*\
| \enum     CryptoTypes
| \brief    Encryption protocols used in this lab
\*---------------------------------------------------------------------------*/
enum CryptoTypes
{
    PVP,
    ID1,
    RSA,
    RDX
};

/*---------------------------------------------------------------------------*\
| \class    CryptoType
| \brief    Crypto type ABC
\*---------------------------------------------------------------------------*/
class CryptoType
{
public:
                    CryptoType() {};
    virtual        ~CryptoType() {};

    virtual std::string encrypt_video() = 0;
};

/*---------------------------------------------------------------------------*\
| \class    CryptoTypePVP
\*---------------------------------------------------------------------------*/
class CryptoTypePVP: public CryptoType
{
public:
                CryptoTypePVP()
                : m_identifier( "PVP" )
                {}

    std::string encrypt_video() { return m_identifier; }

private:
    std::string m_identifier;
};

/*---------------------------------------------------------------------------*\
| \class    CryptoTypeID1
\*---------------------------------------------------------------------------*/
class CryptoTypeID1: public CryptoType
{
public:
                CryptoTypeID1()
                : m_identifier( "ID1" )
                {}

    std::string encrypt_video() { return m_identifier; }

private:
    std::string m_identifier;
};

/*---------------------------------------------------------------------------*\
| \class    CryptoTypeRSA
\*---------------------------------------------------------------------------*/
class CryptoTypeRSA: public CryptoType
{
public:
                CryptoTypeRSA()
                : m_identifier( "RSA" )
                {}

    std::string encrypt_video() { return m_identifier; }

private:
    std::string m_identifier;
};

/*---------------------------------------------------------------------------*\
| \class    CryptoTypeRDX
\*---------------------------------------------------------------------------*/
class CryptoTypeRDX: public CryptoType
{
public:
                CryptoTypeRDX()
                : m_identifier( "RDX" )
                {}

    std::string encrypt_video() { return m_identifier; }

private:
    std::string m_identifier;
};

/*---------------------------------------------------------------------------*\
| \note     Convenience typedef for CryptoType*
\*---------------------------------------------------------------------------*/
typedef std::shared_ptr<CryptoType>     TCryptoTypePtr;

/*---------------------------------------------------------------------------*\
| \fn       CryptoTypeFactory
| \brief    CryptoType factory; static per classical implementation
\*---------------------------------------------------------------------------*/
class CryptoTypeFactory
{
public:
    static TCryptoTypePtr get_crypto_protocol
    (   CryptoTypes crypto_type )
    {
        switch( crypto_type )
        {
        case PVP:
            return std::make_shared<CryptoTypePVP>();
        case ID1:
            return std::make_shared<CryptoTypeID1>();
        case RSA:
            return std::make_shared<CryptoTypeRSA>();
        case RDX:
            return std::make_shared<CryptoTypeRDX>();
        default:
            return nullptr;
        }
    }
};

#endif//LAB03_FACTORY_CRYPTO_TYPE_FACTORY_HPP
