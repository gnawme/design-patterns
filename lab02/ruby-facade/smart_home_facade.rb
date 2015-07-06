#*----------------------------------------------------------------------------*\
#  Facade implementation for Smart Home components
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/
require_relative 'acme_smart_home_components'

#*----------------------------------------------------------------------------*\
#  SmartHomeFacade hides the complexity of the Acme Smart Home components
#  behind a simplified interface
#*----------------------------------------------------------------------------*/
class SmartHomeFacade
   include AcmeSmartHomeComponents

   #*-------------------------------------------------------------------------*\
   #  Constructor with private instances of Acme components
   #*-------------------------------------------------------------------------*/
   def initialize
      @alarm  = Alarm.new
      @ac     = AC.new
      @tv     = TV.new
      @lights = Lights.new
   end

   #*-------------------------------------------------------------------------*\
   #  Implements client arriving functionality
   #*-------------------------------------------------------------------------*/
   def client_arriving
      puts "\nA good traveler has no fixed plans, and is not intent on arriving."

      @alarm.off
      @ac.on
      @tv.on
      @lights.on
   end

   #*-------------------------------------------------------------------------*\
   #  Implements client leaving functionality
   #*-------------------------------------------------------------------------*/
   def client_leaving
      puts "\nElvis has left the building."

      @alarm.on
      @ac.off
      @tv.off
      @lights.off
   end

   #*-------------------------------------------------------------------------*\
   #  Runs demo with client leaving and returning
   #*-------------------------------------------------------------------------*/
   def demo
      client_leaving
      client_arriving
   end
end
