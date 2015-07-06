#*----------------------------------------------------------------------------*\
#  Runs Lab 3 Factory Method Pattern problem
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/
require_relative 'video_product'

#*----------------------------------------------------------------------------*\
#  Test 4 of 5 display types, and 3 of 4 crypto formats
#*----------------------------------------------------------------------------*/
displays = [
   DisplayTypes::DisplayPort,
   DisplayTypes::HDMI,
   DisplayTypes::MIPI,
   DisplayTypes::WiDi
]

cryptos  = [
   CryptoTypes::PVP,
   CryptoTypes::ID1,
   CryptoTypes::RSA
]

#*----------------------------------------------------------------------------*\
#  Test at a single frame rate and display resolution
#*----------------------------------------------------------------------------*/
framerate  = 60
resolution = DisplayResolutions::FullHD

displays.each do |display|
   puts
   cryptos.each do |crypto|

      video = VideoProduct.new(
         :display_type => display,
         :crypto_type  => crypto,
         :display_res  => resolution,
         :framerate    => framerate
      )

      video.send_video
   end
end

