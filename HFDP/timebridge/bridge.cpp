/*---------------------------------------------------------------------------*\
| \file     bridge.cpp
| \brief    Simple Bridge Pattern example
\*---------------------------------------------------------------------------*/
#include <array>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

class TimeImp
{
public:
                    TimeImp( int hr, int min )
                        : m_hr( hr )
                        , m_min( min )
                    {}

    virtual        ~TimeImp() {};

    virtual void    tell()
    {
        std::cout
                << "time is "
                << std::setw( 2 )
                << std::setfill( '0' )
                << m_hr
                << m_min
                << std::endl;
    }

protected:
    int m_hr;
    int m_min;
};

class CivilianTimeImp: public TimeImp
{
public:
            CivilianTimeImp( int hr, int min, int pm )
                : TimeImp( hr, min )
                , m_ampm( pm ? "PM" : "AM" )
            {}

    /* virtual */
    void    tell()
    {
        std::cout
                << "time is "
                << m_hr
                << ":"
                << m_min
                << m_ampm
                << std::endl;
    }
private:
    std::string m_ampm;
};

class ZuluTimeImp: public TimeImp
{
public:
            ZuluTimeImp( int hr, int min, int zone )
                : TimeImp( hr, min )
            {
                switch( zone )
                {
                case 5:
                    m_timezone = " EST";
                case 6:
                    m_timezone = " CST";
                }
            }

    /* virtual */
    void    tell()
    {
        std::cout
                << "time is "
                << std::setw( 2 )
                << std::setfill( '0' )
                << m_hr
                << m_min
                << m_timezone
                << std::endl;
    }
private:
    std::string m_timezone;
};

class Time
{
public:
                    Time() {};

                    Time( int hr, int min )
                        : m_impl( new TimeImp( hr, min ) )
                    {}

    virtual        ~Time() {};

    virtual void    tell()
    {
        m_impl->tell();
    }

private:
    std::unique_ptr<TimeImp>    m_impl;

};

class CivilianTime: public Time
{
public:
            CivilianTime( int hr, int min, int pm )
                : m_impl( new CivilianTimeImp( hr, min, pm ) )
            {}

    void    tell()
    {
        m_impl->tell();
    }

private:
    std::unique_ptr<TimeImp>    m_impl;

};

class ZuluTime: public Time
{
public:
            ZuluTime( int hr, int min, int zone )
                : m_impl( new ZuluTimeImp( hr, min, zone ) )
            {}

    void    tell()
    {
        m_impl->tell();
    }

private:
    std::unique_ptr<TimeImp>    m_impl;

};

/*---------------------------------------------------------------------------*\
| \fn       main
| \brief    Simple Bridge Pattern example
\*---------------------------------------------------------------------------*/
int main()
{
    typedef std::unique_ptr<Time>   TTimePtr;

    std::array<TTimePtr, 3> times;

    times[0] = TTimePtr( new Time( 14, 30 ) );
    times[1] = TTimePtr( new CivilianTime( 2, 30, 1 ) );
    times[2] = TTimePtr( new ZuluTime( 14, 30, 6 ) );

    for ( auto& it : times )
    {
        it->tell();
    }

    return EXIT_SUCCESS;
}
