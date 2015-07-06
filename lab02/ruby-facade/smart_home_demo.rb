#*----------------------------------------------------------------------------*\
#  Demo for SmartHome Facade pattern implementation
#*----------------------------------------------------------------------------*/
require_relative 'smart_home_facade'

client1 = SmartHomeFacade.new
client2 = SmartHomeFacade.new
client3 = SmartHomeFacade.new

client1.demo
client2.demo
client3.demo


