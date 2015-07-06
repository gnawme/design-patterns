#ifndef HFDP_BRIDGESWITCH_APPPLIANCE_HPP
#define HFDP_BRIDGESWITCH_APPPLIANCE_HPP

#include <memory>
class Appliance;
typedef std::shared_ptr<Appliance>  TAppliancePtr;

class Appliance
{
public:
    virtual        ~Appliance() {};

    virtual void    run() = 0;
};

#endif//HFDP_BRIDGESWITCH_APPPLIANCE_HPP
