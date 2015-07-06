#ifndef HFDP_BRIDGESWITCH_SWITCH_HPP
#define HFDP_BRIDGESWITCH_SWITCH_HPP

#include "Appliance.hpp"
#include <memory>


class Switch
{
public:
                    Switch( TAppliancePtr appliance )
                    : m_appliance( appliance )
                    {}

    virtual        ~Switch() {};

    virtual void    turn_on() = 0;

protected:
    TAppliancePtr   m_appliance;
};

#endif//HFDP_BRIDGESWITCH_SWITCH_HPP