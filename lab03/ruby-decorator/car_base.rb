#*----------------------------------------------------------------------------*\
#  Decorator Pattern base Car and OptionsDecorator classes
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/

#*----------------------------------------------------------------------------*\
#  Car base class
#*----------------------------------------------------------------------------*/
class Car

   def initialize( description = "Undefined model" )
      @description = description
   end

   def get_description
      @description
   end

   def get_cost
      # To be implemented by subclasses
   end

end

#*----------------------------------------------------------------------------*\
#  Base model car
#  @note The only concrete component given in the homework
#*----------------------------------------------------------------------------*/
class BaseModel < Car

   def initialize( description )
      super( description )
      @cost = 12000.00
   end

   def get_description
      super
   end

   def get_cost
      @cost
   end
end

#*----------------------------------------------------------------------------*\
#  OptionsDecorator
#*----------------------------------------------------------------------------*/
class OptionsDecorator < Car

   def initialize( description )
      @description = description
   end

   #*-------------------------------------------------------------------------*\
   #  Subclasses must implement the following methods
   #*-------------------------------------------------------------------------*/
   def get_description
      @description
   end

   def get_cost

   end
end
