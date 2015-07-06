/*---------------------------------------------------------------------------*\
| \file     DisplayFactoryDemo.cpp
| \brief    Runs Lab 3 Factory Method Pattern problem
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "VideoProduct.hpp"

#include <array>
#include <cstdlib>
#include <iostream>

typedef std::unique_ptr<VideoProduct>   TVideoProductPtr;

/*---------------------------------------------------------------------------*\
| \fn       main
| \brief    Tests the sample space given in the lab homework
\*---------------------------------------------------------------------------*/
int main()
{

    /*-----------------------------------------------------------------------*\
    |   Test 4 of 5 display types, and 3 of 4 crypto formats
    \*-----------------------------------------------------------------------*/
	std::array<DisplayTypes, 4> displays = {DisplayPort, HDMI, MIPI, WiDi};
	std::array<CryptoTypes, 3> cryptos   = {PVP, ID1, RSA};

    /*-----------------------------------------------------------------------*\
    |   Test at a single frame rate and display resolution
    \*-----------------------------------------------------------------------*/
	int framerate = 60;
	DisplayResolutions res = FullHD;

    for ( auto dit : displays )
    {
        std::cout << std::endl;

        for ( auto cit : cryptos )
        {
            TVideoProductPtr video = 
                TVideoProductPtr( new VideoProduct( dit, cit, res, framerate ) );

            video->send_video();
        }
    }
     
    return EXIT_SUCCESS;
}