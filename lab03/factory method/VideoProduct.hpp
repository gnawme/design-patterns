#ifndef LAB03_FACTORY_VIDEO_PRODUCT_HPP
#define LAB03_FACTORY_VIDEO_PRODUCT_HPP
/*---------------------------------------------------------------------------*\
| \file     VideoProduct.hpp
| \brief    Concrete Product for Factory Method design pattern lab
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "DisplayTypeFactory.hpp"
#include "CryptoTypeFactory.hpp"

#include <string>

/*---------------------------------------------------------------------------*\
| \class    VideoProduct
| \brief    Aggregates display type, crypto protocol, display resolution,
|           and frame rate into a single video product
\*---------------------------------------------------------------------------*/
class VideoProduct
{
public:
                    VideoProduct( 
                        DisplayTypes, 
                        CryptoTypes, 
                        DisplayResolutions, 
                        int 
                    );
                     
    void            send_video();

private:
    TDisplayTypePtr m_display_type;
    TCryptoTypePtr  m_crypto_type;
    TDisplayResArr  m_display_res;
    int             m_frame_rate;
};


#endif//LAB03_FACTORY_VIDEO_PRODUCT_HPP
