#*----------------------------------------------------------------------------*\
#  Main for Lab 3 Decorator homework (Ruby version)
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/
require_relative 'options.rb'

#*----------------------------------------------------------------------------*\
#  Prints out the configuration of the current car
#*----------------------------------------------------------------------------*/
def print_car_configuration( car )

   puts
   puts
   printf( "%s\n\t$%0.2f", car.get_description, car.get_cost )

end

#*----------------------------------------------------------------------------*\
#
#*----------------------------------------------------------------------------*/
purchases = []

#*----------------------------------------------------------------------------*\
#  2 Door Runabout
#*----------------------------------------------------------------------------*/
mine = BaseModel.new( "Runabout: MINI Hardtop 2 Door" )
mine = TwoDoor.new( mine )
purchases << mine

#*----------------------------------------------------------------------------*\
#  4 Door SUV with AC and automatic transmission
#*----------------------------------------------------------------------------*/
yours = BaseModel.new( "SUV: MINI Countryman" )
yours = FourDoor.new( yours )
yours = AC.new( yours )
yours = AutomaticTransmission.new( yours )
purchases << yours

#*----------------------------------------------------------------------------*\
#  4 Door Status with AC, premium sound system, navigation, AT
#*----------------------------------------------------------------------------*/
hers = BaseModel.new( "Status: MINI Paceman ALL4" )
hers = FourDoor.new( hers )
hers = AC.new( hers )
hers = PremiumSoundSystem.new( hers )
hers = Navigation.new( hers )
hers = AutomaticTransmission.new( hers )
purchases << hers

#*----------------------------------------------------------------------------*\
#  2 Door Performance with AC, premium sound system, navigation,
#  MT, V8, and supercharger
#*----------------------------------------------------------------------------*/
boss = BaseModel.new( "Performance: MINI John Cooper Works" )
boss = TwoDoor.new( boss )
boss = AC.new( boss )
boss = PremiumSoundSystem.new( boss )
boss = Navigation.new( boss )
boss = ManualTransmission.new( boss )
boss = V8.new( boss )
boss = SuperCharger.new( boss )
purchases << boss

#*----------------------------------------------------------------------------*\
#  Iterate through purchases and print them out
#*----------------------------------------------------------------------------*/
purchases.each do |purchase|
   print_car_configuration( purchase )
end

