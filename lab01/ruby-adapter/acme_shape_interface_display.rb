#*----------------------------------------------------------------------------*\
#   Acme ShapeInterfaceDisplay Library
#
#   The Acme Software is provided by Acme on an "AS IS" basis.  ACME
#   MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
#   THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
#   FOR A PARTICULAR PURPOSE, REGARDING THE ACME SOFTWARE OR ITS USE AND
#   OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
#
#   (c) 2001 Acme Widgets, Inc. All Rights Reserved
#*----------------------------------------------------------------------------*/
module AcmeShapes

   # Base class, just for documentation
   class ShapeInterfaceDisplay
      def display
      end
   end

   class Polygon < ShapeInterfaceDisplay
      def display
         puts "Display polygon."
      end
   end

   class Torus < ShapeInterfaceDisplay
      def display
         puts "Display torus."
      end
   end

   class Bezel < ShapeInterfaceDisplay
      def display
         puts "Display bezel."
      end
   end
end
