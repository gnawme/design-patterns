#*----------------------------------------------------------------------------*\
#  Ruby version of Template Method Pattern lab
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/

module TemplateMethodCommon

#*----------------------------------------------------------------------------*\
#  Base Template Method class
#  @note Contains hook methods (default implementations) for steps to be overridden
#*----------------------------------------------------------------------------*/
class SixStepTemplateMethod

   #*-------------------------------------------------------------------------*\
   #  Constructor, generates random hour value to set @morning
   #*-------------------------------------------------------------------------*/
   def initialize( name = "" )
      @implementation_name = name

      hour     = Random.rand(0..23)
      @morning = (hour < 12)
   end

   #*-------------------------------------------------------------------------*\
   #  Default setup, not overridden
   #*-------------------------------------------------------------------------*/
   def setup
      puts "\n#{@implementation_name}"
      puts "setup"
   end

   #*-------------------------------------------------------------------------*\
   #  Default schedule, not overridden
   #*-------------------------------------------------------------------------*/
   def schedule
      puts "schedule"
   end

   #*-------------------------------------------------------------------------*\
   #  Default heat, not overridden
   #*-------------------------------------------------------------------------*/
   def heat
      if @morning
         puts "high heat"
      else
         puts "low heat"
      end
   end

   #*-------------------------------------------------------------------------*\
   #  Hook method for optimize, overridden by subclasses
   #*-------------------------------------------------------------------------*/
   def optimize
      puts "standard optimization"
   end

   #*-------------------------------------------------------------------------*\
   #  Hook method for cleanup, overridden by subclasses
   #*-------------------------------------------------------------------------*/
   def cleanup
      puts "standard cleanup"
   end

   #*-------------------------------------------------------------------------*\
   #  Default putaway, not overridden
   #*-------------------------------------------------------------------------*/
   def putaway
      puts "putaway"
   end

   #*-------------------------------------------------------------------------*\
   #  The heart of the Template Method: the template method
   #*-------------------------------------------------------------------------*/
   def template_method

      setup
      schedule
      heat
      optimize # Step to be overridden
      cleanup  # Step to be overridden
      putaway

   end

end

#*----------------------------------------------------------------------------*\
#  Fast variation of SixStepTemplateMethod
#  @note Only overrides SixStepTemplateMethod hook methods
#*----------------------------------------------------------------------------*/
class SixStepTemplateMethodFast < SixStepTemplateMethod

   #*-------------------------------------------------------------------------*\
   #  Constructor
   #*-------------------------------------------------------------------------*/
   def initialize
      super( "Fast method" )
   end

   #*-------------------------------------------------------------------------*\
   #  Overrides optimize step
   #*-------------------------------------------------------------------------*/
   def optimize
      puts "fast optimize"
   end

   #*-------------------------------------------------------------------------*\
   #  Overrides cleanup step
   #  @note Not really necessary, since it's identical to the base hook method
   #*-------------------------------------------------------------------------*/
   def cleanup
      puts "standard cleanup"
   end

end

#*----------------------------------------------------------------------------*\
#  Economical variation of SixStepTemplateMethod
#  @note Only overrides SixStepTemplateMethod hook methods
#*----------------------------------------------------------------------------*/
class SixStepTemplateMethodEconomical < SixStepTemplateMethod

   #*-------------------------------------------------------------------------*\
   #  Constructor
   #*-------------------------------------------------------------------------*/
   def initialize
      super( "Economical method" )
   end

   #*-------------------------------------------------------------------------*\
   #  Overrides optimize step
   #*-------------------------------------------------------------------------*/
   def optimize
      puts "economical optimize"
   end

   #*-------------------------------------------------------------------------*\
   #  Overrides cleanup step
   #  @note Not really necessary, since it's identical to the base hook method
   #*-------------------------------------------------------------------------*/
   def cleanup
      puts "standard cleanup"
   end

end

end #module TemplateMethodCommon
