#*----------------------------------------------------------------------------*\
#  Ruby version of Template Method Pattern lab demo
#  @author Norm Evangelista
#*----------------------------------------------------------------------------*/
require_relative "six_step_template_method.rb"
require_relative "six_step_template_method_new.rb"

#*----------------------------------------------------------------------------*\
#  Instantiate stock templates
#*----------------------------------------------------------------------------*/
include TemplateMethodCommon

processes = []

processes << SixStepTemplateMethodFast.new
processes << SixStepTemplateMethodEconomical.new

#*----------------------------------------------------------------------------*\
#  Instantiate new templates
#*----------------------------------------------------------------------------*/
include TemplateMethodNewSpecs

processes << SixStepTemplateMethodCritical.new
processes << SixStepTemplateMethodNPC.new

#*----------------------------------------------------------------------------*\
#  Iterate through and demo
#*----------------------------------------------------------------------------*/
processes.each do |process|
   process.template_method
end
