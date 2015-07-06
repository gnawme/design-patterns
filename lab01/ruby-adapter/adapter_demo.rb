#*----------------------------------------------------------------------------*\
#  Demos of the Adapter implementation
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/
require_relative 'shape_interface_draw'
require_relative 'shape_interface_draw_acme'

#*----------------------------------------------------------------------------*\
#  Loads all base ShapeInterfaceDraw objects and draws them
#*----------------------------------------------------------------------------*/
def adapter_legacy
   include ShapeInterface

   shapes = []
   shapes << Point.new
   shapes << Line.new
   shapes << Rect.new

   shapes.each do |shape|
      shape.draw
   end
   puts ""
end

#*----------------------------------------------------------------------------*\
#  Loads all base ShapeInterfaceDraw objects and Adapted Acme shapes and draws them
#*----------------------------------------------------------------------------*/
def adapter_problem
   include ShapeInterface

   shapes = []
   shapes << Point.new
   shapes << Line.new
   shapes << Rect.new

   shapes << Polygon.new
   shapes << Torus.new
   shapes << Bezel.new

   shapes.each do |shape|
      shape.draw
   end
   puts ""
end

#*----------------------------------------------------------------------------*\
#  Call examples
#*----------------------------------------------------------------------------*/
adapter_legacy
adapter_problem
