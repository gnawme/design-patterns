#ifndef FINAL_INJECTION_LINE_COMPONENTS_HPP
#define FINAL_INJECTION_LINE_COMPONENTS_HPP
/*---------------------------------------------------------------------------*\
| \file     InjectionLineComponents.hpp
| \brief    Declares objects participating in Injection Line Decorator
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include "AssemblyState.hpp"
#include "OutputBinObserver.hpp"

#include <iostream>
#include <memory>
#include <sstream>

/*---------------------------------------------------------------------------*\
| \class    InjectionLineComponent
| \brief    Component base class
\*---------------------------------------------------------------------------*/
class InjectionLineComponent: public OutputBinObserver
{
public:
    virtual            ~InjectionLineComponent() 
                        { 
                            std::cout 
                            << "~InjectionLineComponent " 
                            << std::endl; 
                        };

    virtual std::string description() = 0;
    virtual std::string material() = 0;
    virtual int         num_cavities() = 0;

    virtual void        update( std::string& ) {};
};

typedef std::shared_ptr<InjectionLineComponent>  TInjectionPtr;

/*---------------------------------------------------------------------------*\
| \class    InjectionLineDecorator
| \brief    Decorator
\*---------------------------------------------------------------------------*/
class InjectionLineDecorator: public InjectionLineComponent
{
public:
    virtual            ~InjectionLineDecorator() 
                        { 
                            std::cout 
                            << "~InjectionLineDecorator " 
                            << std::endl; 
                        };
};

/*---------------------------------------------------------------------------*\
| \note     Concrete InjectionLineComponents
\*---------------------------------------------------------------------------*/
//!
class InjectionMolderIJM_110: public InjectionLineComponent
{
public:
                    InjectionMolderIJM_110()
                    : m_component( "IJM_110" )
                    , m_material( "Aluminum" )
                    , m_num_cavities( 1 )
                    {
                        AssemblyState state;
                        state.set_mold_metal( m_material );
                    }

                   ~InjectionMolderIJM_110()
                    {
                        std::cout 
                        << "~InjectionMolderIJM_110 ";
                    }

    std::string     description()
                    {
                        std::stringstream ss; 
                        ss 
                        << "\t"
                        << m_component
                        << " - "
                        << m_material
                        << "("
                        << m_num_cavities
                        << ") - ";

                        return std::string( ss.str() );
                    };

    std::string     material() 
                    {
                        return m_material;
                    };

    int             num_cavities()
                    {
                        return m_num_cavities;
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tIJM pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    std::string     m_component;
    std::string     m_material;
    int             m_num_cavities;
};

//!
class InjectionMolderIJM_120: public InjectionLineComponent
{
public:
                    InjectionMolderIJM_120()
                    : m_component( "IJM_120" )
                    , m_material( "Aluminum" )
                    , m_num_cavities( 2 )
                    {
                        AssemblyState state;
                        state.set_mold_metal( m_material );
                    }

                   ~InjectionMolderIJM_120()
                    {
                        std::cout 
                        << "~InjectionMolderIJM_120 ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << "\t"
                        << m_component
                        << " - "
                        << m_material
                        << "("
                        << m_num_cavities
                        << ") - ";

                        return std::string( ss.str() );
                    };

    std::string     material() 
                    {
                        return m_material;
                    };

    int             num_cavities()
                    {
                        return m_num_cavities;
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tIJM pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    std::string     m_component;
    std::string     m_material;
    int             m_num_cavities;
};

//!
class InjectionMolderIJM_140: public InjectionLineComponent
{
public:
                    InjectionMolderIJM_140()
                    : m_component( "IJM_140" )
                    , m_material( "Aluminum" )
                    , m_num_cavities( 4 )
                    {
                        AssemblyState state;
                        state.set_mold_metal( m_material );
                    }

                   ~InjectionMolderIJM_140()
                    {
                        std::cout 
                        << "~InjectionMolderIJM_140 ";
                    }

    std::string     description()
                    {
                        std::stringstream ss; 
                        ss 
                        << "\t"
                        << m_component
                        << " - "
                        << m_material
                        << "("
                        << m_num_cavities
                        << ") - ";

                        return std::string( ss.str() );
                    };

    std::string     material() 
                    {
                        return m_material;
                    };

    int             num_cavities()
                    {
                        return m_num_cavities;
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tIJM pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    std::string     m_component;
    std::string     m_material;
    int             m_num_cavities;
};

//!
class InjectionMolderIJM_210: public InjectionLineComponent
{
public:
                    InjectionMolderIJM_210()
                    : m_component( "IJM_210" )
                    , m_material( "Steel" )
                    , m_num_cavities( 1 )
                    {
                        AssemblyState state;
                        state.set_mold_metal( m_material );
                    }

                   ~InjectionMolderIJM_210()
                    {
                        std::cout 
                        << "~InjectionMolderIJM_210 ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << "\t"
                        << m_component
                        << " - "
                        << m_material
                        << "("
                        << m_num_cavities
                        << ") - ";

                        return std::string( ss.str() );
                    };

    std::string     material() 
                    {
                        return m_material;
                    };

    int             num_cavities()
                    {
                        return m_num_cavities;
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tIJM pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    std::string     m_component;
    std::string     m_material;
    int             m_num_cavities;
};

//!
class InjectionMolderIJM_220: public InjectionLineComponent
{
public:
                    InjectionMolderIJM_220()
                    : m_component( "IJM_220" )
                    , m_material( "Steel" )
                    , m_num_cavities( 2 )
                    {
                        AssemblyState state;
                        state.set_mold_metal( m_material );
                    }

                   ~InjectionMolderIJM_220()
                    {
                        std::cout 
                        << "~InjectionMolderIJM_220 ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << "\t"
                        << m_component
                        << " - "
                        << m_material
                        << "("
                        << m_num_cavities
                        << ") - ";

                        return std::string( ss.str() );
                    };

    std::string     material() 
                    {
                        return m_material;
                    };

    int             num_cavities()
                    {
                        return m_num_cavities;
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tIJM pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    std::string     m_component;
    std::string     m_material;
    int             m_num_cavities;
};

//!
class InjectionMolderIJM_240: public InjectionLineComponent
{
public:
                    InjectionMolderIJM_240()
                    : m_component( "IJM_240" )
                    , m_material( "Steel" )
                    , m_num_cavities( 4 )
                    {
                        AssemblyState state;
                        state.set_mold_metal( m_material );
                    }

                   ~InjectionMolderIJM_240()
                    {
                        std::cout 
                        << "~InjectionMolderIJM_240 ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << "\t"
                        << m_component
                        << " - "
                        << m_material
                        << "("
                        << m_num_cavities
                        << ") - ";

                        return std::string( ss.str() );
                    };

    std::string     material() 
                    {
                        return m_material;
                    };

    int             num_cavities()
                    {
                        return m_num_cavities;
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tIJM pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    std::string     m_component;
    std::string     m_material;
    int             m_num_cavities;
};

/*---------------------------------------------------------------------------*\
| \class    InjectionMachineFactory
| \brief    Instantiates an InjectionMolder based on order scale
\*---------------------------------------------------------------------------*/
class InjectionMachineFactory
{
public:
    static TInjectionPtr get_injection_molding_machine( OrderScale order_scale );
};

/*---------------------------------------------------------------------------*\
| \note     Concrete InjectionLineDecorators
\*---------------------------------------------------------------------------*/
//!
class ConveyorBeltLinear: public InjectionLineComponent
{
public:
                    ConveyorBeltLinear( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "Linear conveyer belt" )
                    {}

                   ~ConveyorBeltLinear()
                    {
                        std::cout 
                        << "~ConveyorBeltLinear ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << m_component
                        << " - ";

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tConveyor belt pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

//!
class ConveyorBeltYSplit: public InjectionLineComponent
{
public:
                    ConveyorBeltYSplit( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "Y-Split conveyer belt" )
                    {}

                   ~ConveyorBeltYSplit()
                    {
                        std::cout 
                        << "~ConveyorBeltYSplit ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << m_component
                        << " - ";

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tConveyor belt pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

class ConveyorBeltVLevel: public InjectionLineComponent
{
public:
                    ConveyorBeltVLevel( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "V-Level conveyer belt" )
                    {}

                   ~ConveyorBeltVLevel()
                    {
                        std::cout 
                        << "~ConveyorBeltVLevel ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << m_component
                        << " - ";

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tConveyor belt pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

//!
class PackagerCardboardBox: public InjectionLineComponent
{
public:
                    PackagerCardboardBox( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "CardboardBox" )
                    {}

                   ~PackagerCardboardBox()
                    {
                        std::cout 
                        << "~PackagerCardboardBox ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << m_component 
                        << std::endl; 

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tPackager pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

//!
class PackagerPalletBox: public InjectionLineComponent
{
public:
                    PackagerPalletBox( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "PalletBox" )
                    {}

                   ~PackagerPalletBox()
                    {
                        std::cout 
                        << "~PackagerPalletBox ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << m_component 
                        << std::endl; 

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tPackager pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

//!
class PackagerZipLock: public InjectionLineComponent
{
public:
                    PackagerZipLock( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "ZipLock" )
                    {}

                   ~PackagerZipLock()
                    {
                        std::cout 
                        << "~PackagerZipLock ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << m_component 
                        << std::endl; 

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tPackager pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

class PackagerCrate: public InjectionLineComponent
{
public:
                    PackagerCrate( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "Crate" )
                    {}

                   ~PackagerCrate()
                    {
                        std::cout 
                        << "~PackagerCrate ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << m_component 
                        << std::endl; 

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tPackager pausing while "
                        << subject
                        << " is swapped."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

//!
class StufferAir: public InjectionLineComponent
{
public:
                    StufferAir( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "Stuffer" )
                    {}

                   ~StufferAir()
                    {
                        std::cout 
                        << "~StufferAir ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << " ";

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tStuffer filling "
                        << subject
                        << " with air stuffing."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

//!
class StufferPopcorn: public InjectionLineComponent
{
public:
                    StufferPopcorn( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "Stuffer" )
                    {}

                   ~StufferPopcorn()
                    {
                        std::cout 
                        << "~StufferPopcorn ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << " ";

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tStuffer filling "
                        << subject
                        << " with styrene popcorn stuffing."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

//!
class StufferBubbleWrap: public InjectionLineComponent
{
public:
                    StufferBubbleWrap( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "Stuffer" )
                    {}

                   ~StufferBubbleWrap()
                    {
                        std::cout 
                        << "~StufferBubbleWrap ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << " ";

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tStuffer filling "
                        << subject
                        << " with bubble wrap stuffing."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

//!
class StufferFoam: public InjectionLineComponent
{
public:
                    StufferFoam( TInjectionPtr comp )
                    : m_injection_comp( comp )
                    , m_component( "Stuffer" )
                    {}

                   ~StufferFoam()
                    {
                        std::cout 
                        << "~StufferFoam ";
                    }

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_injection_comp->description()
                        << " ";

                        return std::string( ss.str() );
                    };

    std::string     material()
                    {
                        return m_injection_comp->material();
                    }

    int             num_cavities()
                    {
                        return m_injection_comp->num_cavities();
                    }

    void            update( std::string& subject )
                    {
                        std::cout
                        << "\t\t\t\tStuffer filling "
                        << subject
                        << " with expanding foam stuffing."
                        << std::endl;
                    }

private:
    TInjectionPtr   m_injection_comp;
    std::string     m_component;
};

#endif//FINAL_INJECTION_LINE_COMPONENTS_HPP
