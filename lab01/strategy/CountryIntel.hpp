#ifndef LAB01_STRATEGY_COUNTRY_INTEL_HPP
#define LAB01_STRATEGY_COUNTRY_INTEL_HPP

#include <iostream>
#include <memory>
#include <string>

class CountryIntel;

typedef std::unique_ptr<CountryIntel>   TCountryPtr;

/*---------------------------------------------------------------------------*\
| \enum     CountryCode
\*---------------------------------------------------------------------------*/
enum CountryCode
{
    USA,
    Canada,
    Quebec,
    Germany
};

/*---------------------------------------------------------------------------*\
| \class    CountryHelper
| \brief    Instantiates the correct CountryIntel for a given CountryCode
\*---------------------------------------------------------------------------*/
class CountryHelper
{
public:
    static CountryIntel*    get_country_intel( const CountryCode );
};

/*---------------------------------------------------------------------------*\
| \class    CountryIntel
| \brief    CountryIntel ABC
\*---------------------------------------------------------------------------*/
class CountryIntel
{
public:
    virtual                ~CountryIntel() 
    { std::cerr << "Ta-ta, CountryIntel" << std::endl; };

    virtual double          compute_tax( double ) = 0;

    virtual std::wstring    get_country_date_format() = 0;
    virtual std::string     get_country_locale() = 0;
    virtual std::wstring    get_country_string() = 0;
};

/*---------------------------------------------------------------------------*\
| \class    CountryIntelCAN
| \brief    CountryIntel for CAN
\*---------------------------------------------------------------------------*/
class CountryIntelCAN: public CountryIntel
{
public:
                    CountryIntelCAN( CountryCode );

    double          compute_tax( double );

    std::wstring    get_country_date_format();
    std::string     get_country_locale();
    std::wstring    get_country_string();

private:
    bool            m_is_election_year;
    bool            m_is_quebec;
    double          m_tax_rate;
    std::wstring    m_date_format;
    std::string     m_locale;
    std::wstring    m_country_string;
};

/*---------------------------------------------------------------------------*\
| \class    CountryIntelDEU
| \brief    CountryIntel for USA
\*---------------------------------------------------------------------------*/
class CountryIntelDEU: public CountryIntel
{
public:
                    CountryIntelDEU();

    double          compute_tax( double );

    std::wstring    get_country_date_format();
    std::string     get_country_locale();
    std::wstring    get_country_string();

private:
    bool            luxurious( double );

    double          m_tax_rate;
    std::wstring    m_date_format;
    std::string     m_locale;
    std::wstring    m_country_string;
};

/*---------------------------------------------------------------------------*\
| \class    CountryIntelUSA
| \brief    CountryIntel for USA
\*---------------------------------------------------------------------------*/
class CountryIntelUSA: public CountryIntel
{
public:
                    CountryIntelUSA();

    double          compute_tax( double );

    std::wstring    get_country_date_format();
    std::string     get_country_locale();
    std::wstring    get_country_string();

private:
    double          tax_by_state();

    double          m_tax_rate;
    std::wstring    m_date_format;
    std::string     m_locale;
    std::wstring    m_country_string;
};

#endif//#ifndef LAB01_STRATEGY_COUNTRY_INTEL_HPP


