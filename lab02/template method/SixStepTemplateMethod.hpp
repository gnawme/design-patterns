#ifndef LAB02_SIX_STEP_TEMPLATE_METHOD_HPP
#define LAB02_SIX_STEP_TEMPLATE_METHOD_HPP
/*---------------------------------------------------------------------------*\
| \file     SixStepTemplateMethod.hpp
| \brief    Six Step Template Method pattern
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/

namespace template_method_common
{
/*---------------------------------------------------------------------------*\
| \class    SixStepTemplateMethod
| \brief    Six step process where optimize and cleanup steps can vary
\*---------------------------------------------------------------------------*/
class SixStepTemplateMethod
{
public:
                    SixStepTemplateMethod( const char* );
    virtual        ~SixStepTemplateMethod() {};

    void            setup();
    void            schedule();
    void            heat();
    virtual void    optimize();
    virtual void    cleanup();
    void            putaway();
    
    void            template_method();

private:
    const char*     m_implementation_name;
    bool            m_morning;
};

/*---------------------------------------------------------------------------*\
| \class    SixStepTemplateMethodFast
| \brief    "Fast" concrete implementation of SixStepTemplate
\*---------------------------------------------------------------------------*/
class SixStepTemplateMethodFast: public SixStepTemplateMethod
{
public:
            SixStepTemplateMethodFast( const char* );
    void    optimize();
    void    cleanup();
};

/*---------------------------------------------------------------------------*\
| \class    SixStepTemplateMethodEconomical
| \brief    "Economical" concrete implementation of SixStepTemplate
\*---------------------------------------------------------------------------*/
class SixStepTemplateMethodEconomical: public SixStepTemplateMethod
{
public:
            SixStepTemplateMethodEconomical( const char* );
    void    optimize();
    void    cleanup();
};

}//namespace template_method_common

#endif//LAB02_SIX_STEP_TEMPLATE_METHOD_HPP
