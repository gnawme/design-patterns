#*-------------------------------------------------------------------------*\
#  Decorator Pattern options decorators
#*-------------------------------------------------------------------------*/
require_relative 'car_base.rb'

#*-------------------------------------------------------------------------*\
#  TwoDoor option
#*-------------------------------------------------------------------------*/
class TwoDoor < OptionsDecorator

   def initialize( car )
      super( "2 Door" )
      @car  = car
      @cost = 2000.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end

#*-------------------------------------------------------------------------*\
#  FourDoor option
#*-------------------------------------------------------------------------*/
class FourDoor < OptionsDecorator

   def initialize( car )
      super( "4 Door" )
      @car  = car
      @cost = 4000.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end

#*-------------------------------------------------------------------------*\
#  AC option
#*-------------------------------------------------------------------------*/
class AC < OptionsDecorator

   def initialize( car )
      super( "Automatic Climate Control" )
      @car  = car
      @cost = 1500.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end

#*-------------------------------------------------------------------------*\
#  PremiumSoundSystem option
#*-------------------------------------------------------------------------*/
class PremiumSoundSystem < OptionsDecorator

   def initialize( car )
      super( "Harman/Kardon Sound System" )
      @car  = car
      @cost = 1000.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end

#*-------------------------------------------------------------------------*\
#  Navigation option
#*-------------------------------------------------------------------------*/
class Navigation < OptionsDecorator

   def initialize( car )
      super( "Navigation System" )
      @car  = car
      @cost = 2000.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end

#*-------------------------------------------------------------------------*\
#  ManualTransmission option
#*-------------------------------------------------------------------------*/
class ManualTransmission < OptionsDecorator

   def initialize( car )
      super( "6-Speed Getrag Manual" )
      @car  = car
      @cost = 2500.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end

#*-------------------------------------------------------------------------*\
#  AutomaticTransmission option
#*-------------------------------------------------------------------------*/
class AutomaticTransmission < OptionsDecorator

   def initialize( car )
      super( "6-Speed Steptronic Automatic" )
      @car  = car
      @cost = 3000.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end

#*-------------------------------------------------------------------------*\
#  V8 option
#*-------------------------------------------------------------------------*/
class V8 < OptionsDecorator

   def initialize( car )
      super( "6.2L LT1 V8" )
      @car  = car
      @cost = 6000.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end

#*-------------------------------------------------------------------------*\
#  SuperCharger option
#*-------------------------------------------------------------------------*/
class SuperCharger < OptionsDecorator

   def initialize( car )
      super( "Sprintex Supercharger" )
      @car  = car
      @cost = 3000.00
   end

   def get_description
      printf "#{@car.get_description}\n\t#{@description}"
   end

   def get_cost
      @cost + @car.get_cost
   end
end
