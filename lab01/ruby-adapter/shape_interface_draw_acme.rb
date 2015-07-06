#*----------------------------------------------------------------------------*\
#  Adapts Acme ShapeInterfaceDisplay to be compatible with ShapeInterfaceDisplay
#  @author Norm Evangelista
#  @note Makes use of Ruby monkey-patching to adapt Acme classes
#*----------------------------------------------------------------------------*/
require_relative 'acme_shape_interface_display'
include AcmeShapes

#*----------------------------------------------------------------------------*\
#  ShapeInterfaceDisplay Adapter for AcmeShapes::Polygon
#*----------------------------------------------------------------------------*/
class Polygon
   def draw
      self.display
   end
end

#*----------------------------------------------------------------------------*\
#  ShapeInterfaceDisplay Adapter for AcmeShapes::Torus
#*----------------------------------------------------------------------------*/
class Torus
   def draw
      self.display
   end
end

#*----------------------------------------------------------------------------*\
#  ShapeInterfaceDisplay Adapter for AcmeShapes::Bezel
#*----------------------------------------------------------------------------*/
class Bezel
   def draw
      self.display
   end
end
