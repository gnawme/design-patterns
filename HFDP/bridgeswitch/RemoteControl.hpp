#ifndef HFDP_BRIDGESWITCH_REMOTE_CONTROL_HPP
#define HFDP_BRIDGESWITCH_REMOTE_CONTROL_HPP

#include "Switch.hpp"

class RemoteControl: public Switch
{
public:
                RemoteControl( TAppliancePtr appliance )
                : Switch( appliance )
                {}
    
    void        turn_on()
    {
        m_appliance->run();
    }
};

#endif//HFDP_BRIDGESWITCH_REMOTE_CONTROL_HPP
