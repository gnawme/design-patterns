#ifndef LAB03_FACTORY_DISPLAY_TYPE_FACTORY_HPP
#define LAB03_FACTORY_DISPLAY_TYPE_FACTORY_HPP
/*---------------------------------------------------------------------------*\
| \file     DisplayTypeFactory.hpp
| \brief    Display types and associated factory
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <array>
#include <string>
#include <memory>

/*---------------------------------------------------------------------------*\
| \enum     DisplayTypes
| \brief    Display interfaces used in this lab
\*---------------------------------------------------------------------------*/
enum DisplayTypes
{
    DisplayPort,
    HDMI,
    MIPI,
    WiDi,
    HEVC
};

/*---------------------------------------------------------------------------*\
| \enum     DisplayResolutions
| \brief    Display resolutions used in this lab
\*---------------------------------------------------------------------------*/
enum DisplayResolutions
{
    VGA,
    FullHD,
    UHD
};

/*---------------------------------------------------------------------------*\
| \class    DisplayType
| \brief    Display type ABC
\*---------------------------------------------------------------------------*/
class DisplayType
{
public:
                    DisplayType() {};
    virtual        ~DisplayType() {};

    virtual std::string display_name() = 0;
};

/*---------------------------------------------------------------------------*\
| \class    DisplayTypeDisplayPort
\*---------------------------------------------------------------------------*/
class DisplayTypeDisplayPort: public DisplayType
{
public:
                DisplayTypeDisplayPort()
                : m_display_name( "DisplayPort" )
                {}

    std::string display_name() { return m_display_name; }

private:
    std::string m_display_name;
};

/*---------------------------------------------------------------------------*\
| \class    DisplayTypeHDMI
\*---------------------------------------------------------------------------*/
class DisplayTypeHDMI: public DisplayType
{
public:
                DisplayTypeHDMI()
                : m_display_name( "HDMI" )
                {}

    std::string display_name() { return m_display_name; }

private:
    std::string m_display_name;
};

/*---------------------------------------------------------------------------*\
| \class    DisplayTypeMIPI
\*---------------------------------------------------------------------------*/
class DisplayTypeMIPI: public DisplayType
{
public:
                DisplayTypeMIPI()
                : m_display_name( "MIPI" )
                {}

    std::string display_name() { return m_display_name; }

private:
    std::string m_display_name;
};

/*---------------------------------------------------------------------------*\
| \class    DisplayTypeWiDi
\*---------------------------------------------------------------------------*/
class DisplayTypeWiDi: public DisplayType
{
public:
                DisplayTypeWiDi()
                : m_display_name( "WiDi" )
                {}

    std::string display_name() { return m_display_name; }

private:
    std::string m_display_name;
};

/*---------------------------------------------------------------------------*\
| \class    DisplayTypeHEVC
\*---------------------------------------------------------------------------*/
class DisplayTypeHEVC: public DisplayType
{
public:
                DisplayTypeHEVC()
                : m_display_name( "HEVC" )
                {}

    std::string display_name() { return m_display_name; }

private:
    std::string m_display_name;
};

/*---------------------------------------------------------------------------*\
| \note     Convenience typedefs for DisplayType* and display resolutions
\*---------------------------------------------------------------------------*/
typedef std::shared_ptr<DisplayType>    TDisplayTypePtr;
typedef std::array<int, 2>              TDisplayResArr;

/*---------------------------------------------------------------------------*\
| \class    DisplayTypeFactory
| \brief    DisplayType factory; static per classical implementation
\*---------------------------------------------------------------------------*/
class DisplayTypeFactory
{
public:
    static TDisplayTypePtr get_display_type
    (   DisplayTypes    display_type )
    {
        switch( display_type )
        {
        case DisplayPort:
            return std::make_shared<DisplayTypeDisplayPort>();
        case HDMI:
            return std::make_shared<DisplayTypeHDMI>();
        case MIPI:
            return std::make_shared<DisplayTypeMIPI>();
        case WiDi:
            return std::make_shared<DisplayTypeWiDi>();
        case HEVC:
            return std::make_shared<DisplayTypeHEVC>();
        default:
            return nullptr;
        }

        return nullptr;
    }
};

/*---------------------------------------------------------------------------*\
| \class    DisplayResFactory
| \brief    Display resolutions factory; static per classical implementation
\*---------------------------------------------------------------------------*/
class DisplayResFactory
{
public:
    static TDisplayResArr get_display_resolution
    (   DisplayResolutions  display_res )
    {
        switch( display_res )
        {
        case VGA:
        default:
        {
            TDisplayResArr vga = {640, 480};
            return vga;
        }
            break;
        case FullHD:
        {
            TDisplayResArr full_hd = {1920, 1080};
            return full_hd;
        }
            break;
        case UHD:
        {
            TDisplayResArr uhd = {3840, 2160};
            return uhd;
        }
            break;
        }
    }
};

enum DisplayFrequencies
{
    f48p,
    f50p,
    f60p,
    f72p,
    f120p
};

#endif//LAB03_FACTORY_DISPLAY_TYPE_FACTORY_HPP
