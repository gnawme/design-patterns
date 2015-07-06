#*----------------------------------------------------------------------------*\
#  Acme Smart Home Components Library
#
#  The Acme Software is provided by Acme on an "AS IS" basis.  ACME
#  MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
#  THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
#  FOR A PARTICULAR PURPOSE, REGARDING THE ACME SOFTWARE OR ITS USE AND
#  OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
#
#  (c) 2001 Acme Widgets, Inc. All Rights Reserved
#*----------------------------------------------------------------------------*/
module AcmeSmartHomeComponents
   class Alarm
      def on
         puts "Alarm on."
      end

      def off
         puts "Alarm off."
      end
   end

   class AC
      def on
         puts "AC on."
      end

      def off
         puts "AC off."
      end
   end

   class TV
      def on
         puts "TV on."
      end

      def off
         puts "TV off."
      end
   end

   class Lights
      def on
         puts "Lights on."
      end

      def off
         puts "Lights off."
      end
   end
end
