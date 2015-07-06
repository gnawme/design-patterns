#*----------------------------------------------------------------------------*\
#  Display types and associated factory
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/

#*----------------------------------------------------------------------------*\
#  Ruby-style enum for display types
#*----------------------------------------------------------------------------*/
class DisplayTypes
   DisplayPort = 1
   HDMI        = 2
   MIPI        = 3
   WiDi        = 4
   HEVC        = 5
end

#*----------------------------------------------------------------------------*\
#  DisplayTypeDisplayPort
#*----------------------------------------------------------------------------*/
class DisplayTypeDisplayPort
   def display_name
      "DisplayPort"
   end
end

#*----------------------------------------------------------------------------*\
#  DisplayTypeHDMI
#*----------------------------------------------------------------------------*/
class DisplayTypeHDMI
   def display_name
      "HDMI"
   end
end

#*----------------------------------------------------------------------------*\
#  DisplayTypeMIPI
#*----------------------------------------------------------------------------*/
class DisplayTypeMIPI
   def display_name
      "MIPI"
   end
end

#*----------------------------------------------------------------------------*\
#  DisplayTypeWiDi
#*----------------------------------------------------------------------------*/
class DisplayTypeWiDi
   def display_name
      "WiDi"
   end
end

#*----------------------------------------------------------------------------*\
#  DisplayTypeHEVC
#*----------------------------------------------------------------------------*/
class DisplayTypeHEVC
   def display_name
      "HEVC"
   end
end

#*----------------------------------------------------------------------------*\
#  DisplayTypeFactory
#*----------------------------------------------------------------------------*/
class DisplayTypeFactory
   class << self
      def get_display_type(display_type)

         case display_type
         when DisplayTypes::DisplayPort
            DisplayTypeDisplayPort.new
         when DisplayTypes::HDMI
            DisplayTypeHDMI.new
         when DisplayTypes::MIPI
            DisplayTypeMIPI.new
         when DisplayTypes::WiDi
            DisplayTypeWiDi.new
         when DisplayTypes::HEVC
            DisplayTypeHEVC.new
         else
            nil
         end
      end
   end
end

#*----------------------------------------------------------------------------*\
#  Ruby-style enum for display resolutions
#*----------------------------------------------------------------------------*/
class DisplayResolutions
   VGA    = 1
   FullHD = 2
   UHD    = 3
end

#*----------------------------------------------------------------------------*\
#  DisplayResolutionFactory
#*----------------------------------------------------------------------------*/
class DisplayResolutionFactory
   class << self
      def get_resolution_type(resolution_type)
         case resolution_type
         when DisplayResolutions::VGA
            [640, 480]
         when DisplayResolutions::FullHD
            [1920, 1080]
         when
            [3840, 2160]
         end
      end
   end

end
