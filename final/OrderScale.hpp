#ifndef FINAL_ORDER_SCALE_HPP
#define FINAL_ORDER_SCALE_HPP
/*---------------------------------------------------------------------------*\
| \file     OrderScale.hpp
| \brief    Strategies for constructing injector based on order size
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AssemblyState.hpp"
#include "InjectionLineComponents.hpp"
#include "OutputBinObserver.hpp"

#include <iostream>
#include <memory>
#include <string>

/*---------------------------------------------------------------------------*\
| \class    OrderScaleStrategy
| \brief    Base Strategy
\*---------------------------------------------------------------------------*/
class OrderScaleStrategy
{
public:
    virtual                    ~OrderScaleStrategy()
                                {
                                    std::cout 
                                    << "~OrderScaleStrategy "
                                    << std::endl;
                                }


    virtual TInjectionPtr       get_injection_machine() = 0;
    virtual TSubjectPtr         get_bin_publisher() = 0;

};

typedef std::shared_ptr<OrderScaleStrategy>   TOrderScalePtr;

/*---------------------------------------------------------------------------*\
| \class    OrderScaleSmall
| \brief    Concrete Strategy for small orders
\*---------------------------------------------------------------------------*/
class OrderScaleSmall: public OrderScaleStrategy
{
public:
                    OrderScaleSmall();
                   ~OrderScaleSmall()
                    {
                        std::cout 
                        << "~OrderScaleSmall ";
                    }

    TInjectionPtr   get_injection_machine();
    TSubjectPtr     get_bin_publisher();

private:
    OrderScale      m_order_scale;
    std::string     m_conveyor_belt;
    std::string     m_output_bin;
    TSubjectPtr     m_bin_subject;
};

/*---------------------------------------------------------------------------*\
| \class    OrderScaleMedium
| \brief    Concrete Strategy for medium orders
\*---------------------------------------------------------------------------*/
class OrderScaleMedium: public OrderScaleStrategy
{
public:
                    OrderScaleMedium();
                   ~OrderScaleMedium()
                    {
                        std::cout 
                        << "~OrderScaleMedium ";
                    }

    TInjectionPtr   get_injection_machine();  
    TSubjectPtr     get_bin_publisher();

private:
    OrderScale      m_order_scale;
    std::string     m_conveyor_belt;
    std::string     m_output_bin;
    TSubjectPtr     m_bin_subject;
};

/*---------------------------------------------------------------------------*\
| \class    OrderScaleFast
| \brief    Concrete Strategy for fast orders
\*---------------------------------------------------------------------------*/
class OrderScaleFast: public OrderScaleStrategy
{
public:
                    OrderScaleFast();
                   ~OrderScaleFast()
                    {
                        std::cout 
                        << "~OrderScaleFast ";
                    }

    TInjectionPtr   get_injection_machine();  
    TSubjectPtr     get_bin_publisher();

private:
    OrderScale      m_order_scale;
    std::string     m_conveyor_belt;
    std::string     m_output_bin;
    TSubjectPtr     m_bin_subject;
};

/*---------------------------------------------------------------------------*\
| \class    OrderScaleLarge
| \brief    Concrete Strategy for large orders
\*---------------------------------------------------------------------------*/
class OrderScaleLarge: public OrderScaleStrategy
{
public:
                    OrderScaleLarge();
                   ~OrderScaleLarge()
                    {
                        std::cout 
                        << "~OrderScaleLarge ";
                    }

    TInjectionPtr   get_injection_machine();  
    TSubjectPtr     get_bin_publisher();

private:
    OrderScale      m_order_scale;
    std::string     m_conveyor_belt;
    std::string     m_output_bin;
    TSubjectPtr     m_bin_subject;
};

/*---------------------------------------------------------------------------*\
| \class    OrderScaleJumbo
| \brief    Concrete Strategy for jumbo orders
\*---------------------------------------------------------------------------*/
class OrderScaleJumbo: public OrderScaleStrategy
{
public:
                    OrderScaleJumbo();
                   ~OrderScaleJumbo()
                    {
                        std::cout 
                        << "~OrderScaleJumbo ";
                    }

    TInjectionPtr   get_injection_machine();  
    TSubjectPtr     get_bin_publisher();

private:
    OrderScale      m_order_scale;
    std::string     m_conveyor_belt;
    std::string     m_output_bin;
    TSubjectPtr     m_bin_subject;
};

/*---------------------------------------------------------------------------*\
| \class    OrderScaleHuge
| \brief    Concrete Strategy for huge orders
\*---------------------------------------------------------------------------*/
class OrderScaleHuge: public OrderScaleStrategy
{
public:
                    OrderScaleHuge();
                   ~OrderScaleHuge()
                    {
                        std::cout 
                        << "~OrderScaleHuge ";
                    }

    TInjectionPtr   get_injection_machine();  
    TSubjectPtr     get_bin_publisher();

private:
    OrderScale      m_order_scale;
    std::string     m_conveyor_belt;
    std::string     m_output_bin;
    TSubjectPtr     m_bin_subject;
};

#endif//FINAL_ORDER_SCALE_HPP
