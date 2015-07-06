#*----------------------------------------------------------------------------*\
#  Template Method Pattern new subclasses of SixStepTemplateMethod
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/
require_relative "six_step_template_method.rb"

#*----------------------------------------------------------------------------*\
#  New implementations based on SixStepTemplateMethod
#*----------------------------------------------------------------------------*/
module TemplateMethodNewSpecs

include TemplateMethodCommon

#*----------------------------------------------------------------------------*\
#  Critical variation of SixStepTemplateMethod
#  @note Only overrides SixStepTemplateMethod hook methods
#*----------------------------------------------------------------------------*/
class SixStepTemplateMethodCritical < SixStepTemplateMethod

   #*-------------------------------------------------------------------------*\
   #  Constructor
   #*-------------------------------------------------------------------------*/
   def initialize
      super( "Critical method" )
   end

   #*-------------------------------------------------------------------------*\
   #  Overrides optimize step
   #*-------------------------------------------------------------------------*/
   def optimize
      puts "critical optimization"
   end

   #*-------------------------------------------------------------------------*\
   #  Overrides cleanup step
   #*-------------------------------------------------------------------------*/
   def cleanup
      puts "meticulous cleanup"
   end

end

#*----------------------------------------------------------------------------*\
#  NPC variation of SixStepTemplateMethod
#  @note Only overrides SixStepTemplateMethod hook methods
#*----------------------------------------------------------------------------*/
class SixStepTemplateMethodNPC < SixStepTemplateMethod

   #*-------------------------------------------------------------------------*\
   #  Constructor
   #*-------------------------------------------------------------------------*/
   def initialize
      super( "NPC method" )
   end

   #*-------------------------------------------------------------------------*\
   #  Overrides optimize step
   #*-------------------------------------------------------------------------*/
   def optimize
      puts "NPC optimization"
   end

   #*-------------------------------------------------------------------------*\
   #  Overrides cleanup step
   #*-------------------------------------------------------------------------*/
   def cleanup
      puts "meticulous cleanup"
   end

end

end

