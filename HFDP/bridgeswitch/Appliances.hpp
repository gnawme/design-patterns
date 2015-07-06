#ifndef HFDP_BRIDGESWITCH_APPPLIANCES_HPP
#define HFDP_BRIDGESWITCH_APPPLIANCES_HPP

#include "Appliance.hpp"

#include <iostream>
#include <string>

class TV: public Appliance
{
public:
                TV( std::string model )
                : m_model( model )
                {}

    void        run()
                {
                    std::cout
                    << m_model
                    << " is on and looking gorgeous"
                    << std::endl;
                }

private:
    std::string m_model;
};

class Vacuum: public Appliance
{
public:
                Vacuum( std::string model )
                : m_model( model )
                {}

    void        run()
                {
                    std::cout
                    << m_model
                    << " is on and not losing suction"
                    << std::endl;
                }

private:
    std::string m_model;
};


#endif//HFDP_BRIDGESWITCH_APPPLIANCES_HPP
