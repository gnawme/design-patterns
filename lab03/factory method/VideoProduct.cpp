/*---------------------------------------------------------------------------*\
| \file     VideoProduct.cpp
| \brief    Concrete Product implementation for Factory Method design pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "VideoProduct.hpp"

#include <iostream>

/*---------------------------------------------------------------------------*\
| \fn       VideoProduct::VideoProduct
\*---------------------------------------------------------------------------*/
VideoProduct::VideoProduct
(   DisplayTypes        display_type,
    CryptoTypes         crypto_type,
    DisplayResolutions  display_res,
    int                 frame_rate )
    : m_display_type( DisplayTypeFactory::get_display_type( display_type ) )
    , m_crypto_type( CryptoTypeFactory::get_crypto_protocol( crypto_type ) )
    , m_display_res( DisplayResFactory::get_display_resolution( display_res ) )
    , m_frame_rate( frame_rate )
{}

/*---------------------------------------------------------------------------*\
| \fn       VideoProduct::send_video
\*---------------------------------------------------------------------------*/
void VideoProduct::send_video()
{
    std::cout
    << "Sending "
    << m_display_type->display_name()
    << "[" << m_display_res[0] << ", " << m_display_res[1] << "] "
    << "via "
    << m_crypto_type->encrypt_video()
    << " at "
    << m_frame_rate
    << " fps."
    << std::endl;
}



