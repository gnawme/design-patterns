#*----------------------------------------------------------------------------*\
#  Concrete Product for Factory Method design pattern lab
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/
require_relative 'display_type_factory'
require_relative 'crypto_type_factory'

#*----------------------------------------------------------------------------*\
#  VideoProduct
#  @note Aggregates display type, display resolution, crypto protocol, framerate
#*----------------------------------------------------------------------------*/
class VideoProduct
   def initialize(args)
      display_type = args[:display_type]
      crypto_type  = args[:crypto_type]
      display_res  = args[:display_res]
      framerate    = args[:framerate]

      @display_type = DisplayTypeFactory::get_display_type(display_type)
      @crypto_type  = CryptoTypeFactory::get_crypto_type(crypto_type)
      @display_res  = DisplayResolutionFactory::get_resolution_type(display_res)
      @framerate    = framerate
   end

   def send_video
      puts "Sending #{@display_type.display_name}[#{@display_res[0]}, #{@display_res[1]}] via #{@crypto_type.encrypt_video} at #{@framerate} fps."
   end
end
