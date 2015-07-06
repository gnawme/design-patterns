#ifndef FINAL_ASSEMBLY_STATE_HPP
#define FINAL_ASSEMBLY_STATE_HPP
/*---------------------------------------------------------------------------*\
| \file     AssemblyState.hpp
| \brief    Maintains assembly line state using the Monostate Pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "StringUtils.hpp"

typedef std::map<std::string, int>  TMoldVolMap;

const std::array<std::string, 4> c_valid_shapes = 
    { "duck", "car", "hero", "dino" };

const std::array<std::string, 6> c_valid_tags = 
    { "ModelNumber", "Country", "Date", 
      "IncCounter", "PartNumber", "RecycleCode" };

const std::array<std::string, 4> c_valid_packagers =
    { "Bulk", "ShrinkWrap", "HardPack", "ZipLock" };

const std::array<std::string, 3> c_valid_additives =
    { "UVInhibiter", "AntiBacterial", "MicroFibers" };

const std::array<std::string, 4> c_valid_stuffers =
    { "Air", "Popcorn", "BubbleWrap", "Foam" };

const std::array<std::string, 4> c_valid_locations =
    { "inventory", "sisterCompany", "purchase", "mill" };

struct Additive
{
                Additive( std::string& additive, int volume )
                : m_additive( additive )
                , m_volume( volume )
                {}

    std::string m_additive;
    int         m_volume;
};

typedef std::vector<Additive>       TAdditVec;

enum OrderScale
{
    ORDER_SMALL,
    ORDER_MEDIUM,
    ORDER_FAST,
    ORDER_LARGE,
    ORDER_JUMBO,
    ORDER_HUGE
};

enum PlasticType
{
    e_ABS,
    e_Polypropylene,
    e_Polyethylene,
    e_PET,
    e_Styrene,
    e_Nylon66
};

typedef std::map<std::string, PlasticType>  TPlasticMap;

enum StufferType
{
    e_Air,
    e_Popcorn,
    e_BubbleWrap,
    e_Foam
};

typedef std::map<std::string, StufferType>  TStufferMap;

enum MoldShape
{
    e_Duck,
    e_Car,
    e_Hero
};

typedef std::map<std::string, MoldShape>    TMoldMap;

enum LocationType
{
    e_Inventory,
    e_SisterCompany,
    e_Purchase,
    e_Mill
};

typedef std::map<std::string, LocationType> TLocMap;

typedef std::map<std::string, int>          TTagMap;

/*---------------------------------------------------------------------------*\
| \class    AssemblyState
| \brief    Monostate for managing injection assembly state
\*---------------------------------------------------------------------------*/
class AssemblyState
{
public:
    /*-----------------------------------------------------------------------*\
    | \fn       set_defaults
    | \brief    Sets/resets monostate defaults
    \*-----------------------------------------------------------------------*/
    void                set_defaults()
                        {
                            m_plastic_type              = "ABS";
                            m_order_size                = 100;
                            m_order_scale               = ORDER_SMALL;
                            m_packager                  = "Bulk";
                            m_injection_molding_machine = "IJM_110";
                            m_mold_metal                = "Aluminum";
                            m_num_cavities              = "1 cavity";
                            m_conveyor_belt             = "Linear";
                            m_output_bin                = "CardboardBox";
                            m_mold_shape                = "duck";
                            m_invalid_tags.clear();
                            m_tags.clear();
                            m_mold_location             = "inventory";
                            m_additives.clear();
                            m_color                     = "black";
                        };

    /*-----------------------------------------------------------------------*\
    | \note     Accessors
    \*-----------------------------------------------------------------------*/
    std::string         get_plastic_type() const
                        {
                            return m_plastic_type;
                        }

    void                set_plastic_type( std::string& type )
                        {
                            m_plastic_type = type;
                        }

    PlasticType         get_plastic_enum() const
                        {
                            return m_plastic_enum[m_plastic_type];
                        }

    int                 get_order_size() const
                        {
                            return m_order_size;
                        }

    void                set_order_size( int size )
                        {
                            if ( size > 200000 )
                            {
                                std::cout
                                << "\t<>Size too large |"
                                << size
                                << "| defaulting to HugeOrder of 200000."
                                << std::endl;

                                size = 200000;
                            }
                            m_order_size = size;
                            set_order_scale();
                        }

    OrderScale          get_order_scale() const
                        {
                            return m_order_scale;
                        }

    OrderScale          get_order_scale( int order_size )
                        {
                            switch( m_order_size )
                            {
                            case 10000:
                                return ORDER_SMALL;
                            case 20000:
                                return ORDER_MEDIUM;
                            case 40000:
                                return ORDER_FAST;
                            case 50000:
                                return ORDER_LARGE;
                            case 100000:
                                return ORDER_JUMBO;
                            case 200000:
                                return ORDER_HUGE;
                            default:
                                return ORDER_SMALL;
                            }

                            return ORDER_SMALL;
                        }

    void                set_order_scale()
                        {
                            m_order_scale = get_order_scale( m_order_size );
                        }

    int                 get_run_size() const
                        {
                            return m_run_size;
                        }

    void                set_run_size( int size )
                        {
                            m_run_size = size;
                        }

    std::string         get_packager() const
                        {
                            return m_packager;
                        }

    void                set_packager( std::string& packager )
                        {
                            TStringVec nogood;
                            TStringVec valid( 
                                c_valid_packagers.begin(), 
                                c_valid_packagers.end() );

                            bool good = verify( 
                                packager, valid, nogood );

                            if ( good == false )
                            {
                                std::cout
                                << "\t<>Unknown packager |"
                                << packager
                                << "| defaulting to Bulk packager."
                                << std::endl;
                                m_packager = "Bulk";
                            }
                            else
                            {
                                m_packager = packager;
                            }
                        }


    std::string         get_injection_molding_machine() const
                        {
                            return m_injection_molding_machine;
                        }

    void                set_injection_molding_machine( std::string& machine )
                        {
                            m_injection_molding_machine = machine;
                        }

    std::string         get_mold_metal() const
                        {
                            return m_mold_metal;
                        }

    void                set_mold_metal( std::string& metal )
                        {
                            m_mold_metal = metal;
                        }

    std::string         get_num_cavities() const
                        {
                            return m_num_cavities;
                        }

    void                set_num_cavities( std::string& cavities )
                        {
                            m_num_cavities = cavities;
                        }

    std::string         get_conveyor_belt() const
                        {
                            return m_conveyor_belt;
                        }

    void                set_conveyor_belt( std::string& belt )
                        {
                            m_conveyor_belt = belt;
                        }

    std::string         get_output_bin() const
                        {
                            return m_output_bin;
                        }

    void                set_output_bin( std::string& bin )
                        {
                            m_output_bin = bin;
                        }

    std::string         get_mold_shape() const
                        {
                            return m_mold_shape;
                        }

    void                set_mold_shape( std::string& shape )
                        {
                            TStringVec nogood;
                            TStringVec valid( 
                                c_valid_shapes.begin(), 
                                c_valid_shapes.end() );

                            bool good = verify( 
                                shape, valid, nogood );

                            if ( good == false )
                            {
                                std::cout
                                << "\t\t<>Unknown shape |"
                                << shape
                                << "| defaulting to duck."
                                << std::endl;

                                m_mold_shape = "duck";
                            }
                            else
                            {
                                m_mold_shape = shape;
                            }
                        }

    MoldShape           get_mold_enum() const
                        {
                            return m_mold_enum[m_mold_shape];
                        }

    int                 get_mold_volume() const
                        {
                            return m_mold_vol_map[m_mold_shape];
                        }

    std::string         get_mold_location() const
                        {
                            return m_mold_location;
                        }

    void                set_mold_location( std::string& location )
                        {
                            m_mold_location = location;
                        }

    LocationType        get_mold_location_type( std::string& mold_loc ) const
                        {
                            return m_mold_location_map[mold_loc];
                        }

    void                set_tags( std::string& tags )
                        {
                            m_tags.clear();
                            m_tags = split( tags, ' ' );

                            if ( verify_tags() == false )
                            {
                                remove_invalid( m_tags, m_invalid_tags );
                            }
                        }

    TStringVec          get_tags() const
                        {
                            return m_tags;
                        }

    int                 get_tag_size( std::string& tag ) const
                        {
                            return m_tag_map[tag];
                        }

    TStringVec          get_invalid_tags() const
                        {
                            return m_invalid_tags;
                        }

    bool                verify_tags()
                        {
                            TStringVec valid( 
                                c_valid_tags.begin(), c_valid_tags.end() );

                            return verify( m_tags, valid, m_invalid_tags );
                        }

    std::string         get_color() const
                        {
                            return m_color;
                        }

    void                set_color( std::string& color )
                        {
                            m_color = color;
                        }

    TAdditVec           get_additives() const
                        {
                            return TAdditVec( m_additives );
                        }

    void                set_additive( std::string& name, int volume )
                        {
                            Additive additive( name, volume );
                            m_additives.push_back( additive );
                        }

    std::string         get_finish() const
                        {
                            return m_finish;
                        }

    void                set_finish( std::string& finish )
                        {
                            m_finish = finish;
                        }

    std::string         get_stuffer() const
                        {
                            return m_stuffer;
                        }

    void                set_stuffer( std::string& stuffer )
                        {
                            m_stuffer = stuffer;
                        }

    StufferType         get_stuffer_type( std::string& stuffer )
                        {
                            return m_stuffer_map[stuffer];
                        }

    std::string         get_address() const
                        {
                            return m_address;
                        }

    void                set_address( std::string& address )
                        {
                            m_address = address;
                        }

private:
    static std::string  m_plastic_type;
    static TPlasticMap  m_plastic_enum;
    static int          m_order_size;
    static OrderScale   m_order_scale;
    static int          m_run_size;
    static std::string  m_packager;
    static std::string  m_injection_molding_machine;
    static std::string  m_mold_metal;
    static std::string  m_num_cavities;
    static std::string  m_conveyor_belt;
    static std::string  m_output_bin;
    static std::string  m_mold_shape;
    static TMoldMap     m_mold_enum;
    static TMoldVolMap  m_mold_vol_map;
    static TStringVec   m_invalid_tags;
    static TStringVec   m_tags;
    static TTagMap      m_tag_map;
    static std::string  m_mold_location;
    static TLocMap      m_mold_location_map;
    static std::string  m_color;
    static TAdditVec    m_additives;
    static std::string  m_finish;
    static std::string  m_stuffer;
    static TStufferMap  m_stuffer_map;
    static std::string  m_address;
};

#endif//FINAL_ASSEMBLY_STATE_HPP
