#include "Appliances.hpp"
#include "RemoteControl.hpp"

#include <cstdlib>

int main()
{
    TAppliancePtr   televisor( new TV( "Samsung JS9500" ) );
    TAppliancePtr   vacuum( new Vacuum( "Dyson Cinetic" ) );

    RemoteControl tv_remote  = RemoteControl( televisor );
    RemoteControl vac_remote = RemoteControl( vacuum );

    tv_remote.turn_on();
    vac_remote.turn_on();

    return EXIT_SUCCESS;
}