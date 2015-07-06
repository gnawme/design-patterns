/*---------------------------------------------------------------------------*\
| \file     AssemblyState.cpp
| \brief    Maintains assembly line state using the Monostate Pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AssemblyState.hpp"

/*---------------------------------------------------------------------------*\
|   Initialize mold/volume map
\*---------------------------------------------------------------------------*/
TMoldVolMap load_mold_vol_map()
{
    TMoldVolMap m;
    m["duck"]   = 35;
    m["car"]    = 40;
    m["hero"]   = 50;
    m["dino"]   = 30;

    return m;
}

/*---------------------------------------------------------------------------*\
|   Initialize plastic map
\*---------------------------------------------------------------------------*/
TPlasticMap load_plastic_map()
{
    TPlasticMap m;
    m["ABS"]            = e_ABS;
    m["Polypropylene"]  = e_Polypropylene;
    m["Polyethelene"]   = e_Polyethylene;
    m["Polyethylene"]   = e_Polyethylene;
    m["PET"]            = e_PET;
    m["Styrene"]        = e_Styrene;
    m["Nylon66"]        = e_Nylon66;

    return m;
}

/*---------------------------------------------------------------------------*\
|   Initialize stuffer map
\*---------------------------------------------------------------------------*/
TStufferMap load_stuffer_map()
{
    TStufferMap m;
    m["Air"]        = e_Air;
    m["Popcorn"]    = e_Popcorn;
    m["BubbleWrap"] = e_BubbleWrap;
    m["Foam"]       = e_Foam;

    return m;
}

/*---------------------------------------------------------------------------*\
|   Initialize mold map
\*---------------------------------------------------------------------------*/
TMoldMap load_mold_map()
{
    TMoldMap m;
    m["duck"]   = e_Duck;
    m["car"]    = e_Car;
    m["hero"]   = e_Hero;

    return m;
}

/*---------------------------------------------------------------------------*\
|   Initialize tag map
\*---------------------------------------------------------------------------*/
TTagMap load_tag_map()
{
    TTagMap m;
    m["ModelNumber"]    = 2;
    m["Country"]        = 2;
    m["Date"]           = 2;
    m["IncCounter"]     = 4;
    m["PartNumber"]     = 2;
    m["RecycleCode"]    = 6;

    return m;
}

/*---------------------------------------------------------------------------*\
|   Initialize mold location map
\*---------------------------------------------------------------------------*/
TLocMap load_mold_loc_map()
{
    TLocMap m;
    m["inventory"]      = e_Inventory;
    m["sisterCompany"]  = e_SisterCompany;
    m["purchase"]       = e_Purchase;
    m["mill"]           = e_Mill;

    return m;
}

/*---------------------------------------------------------------------------*\
|   Initialize static private member data to defaults
\*---------------------------------------------------------------------------*/
std::string AssemblyState::m_plastic_type               = "ABS";
TPlasticMap AssemblyState::m_plastic_enum               = load_plastic_map();
int         AssemblyState::m_order_size                 = 100;
OrderScale  AssemblyState::m_order_scale                = ORDER_SMALL;
int         AssemblyState::m_run_size                   = 100;
std::string AssemblyState::m_packager                   = "Bulk";
std::string AssemblyState::m_injection_molding_machine  = "IJM_110";
std::string AssemblyState::m_mold_metal                 = "Aluminum";
std::string AssemblyState::m_num_cavities               = "1 cavity";
std::string AssemblyState::m_conveyor_belt              = "Linear";
std::string AssemblyState::m_mold_shape                 = "duck";
TMoldMap    AssemblyState::m_mold_enum                  = load_mold_map();
std::string AssemblyState::m_output_bin                 = "CardboardBox";
TMoldVolMap AssemblyState::m_mold_vol_map               = load_mold_vol_map();
TStringVec  AssemblyState::m_invalid_tags;
TStringVec  AssemblyState::m_tags;
TTagMap     AssemblyState::m_tag_map                    = load_tag_map();
std::string AssemblyState::m_mold_location              = "inventory";
TLocMap     AssemblyState::m_mold_location_map          = load_mold_loc_map();
std::string AssemblyState::m_color                      = "black";
TAdditVec   AssemblyState::m_additives;
std::string AssemblyState::m_finish                     = "smooth"; 
std::string AssemblyState::m_stuffer                    = "Air"; 
TStufferMap AssemblyState::m_stuffer_map                = load_stuffer_map();
std::string AssemblyState::m_address                    = ""; 
