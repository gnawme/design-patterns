#ifndef FINAL_OUTPUT_BIN_OBSERVER_HPP
#define FINAL_OUTPUT_BIN_OBSERVER_HPP
/*---------------------------------------------------------------------------*\
| \file     OutputBinObserver.hpp
| \brief    Subject and Observer classes for OutputBin
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*---------------------------------------------------------------------------*\
| \class    OutputBinObserver
\*---------------------------------------------------------------------------*/
class OutputBinObserver
{
public:
    virtual        ~OutputBinObserver()
                    {
                        std::cout 
                        << "~OutputBinObserver " 
                        << std::endl; 
                    }

    virtual void    update( std::string& ) = 0;
};

typedef std::shared_ptr<OutputBinObserver>  TObserverPtr;
typedef std::vector<TObserverPtr>           TObserverVec;

/*---------------------------------------------------------------------------*\
| \class    OutputBinSubject
\*---------------------------------------------------------------------------*/
class OutputBinSubject
{
public:
                    OutputBinSubject( const char* description )
                    : m_description( description )
                    {}

    virtual        ~OutputBinSubject()
                    {
                        std::cout 
                        << "~OutputBinSubject " 
                        << std::endl; 
                    }

    virtual void    notify_observers();
    virtual void    register_observer( TObserverPtr );
    virtual void    remove_observer( TObserverPtr );

    virtual void    issue_alert( const char* );

protected:
    std::string     m_description;
    TObserverVec    m_observers;
};

typedef std::shared_ptr<OutputBinSubject>   TSubjectPtr;

#endif//FINAL_OUTPUT_BIN_OBSERVER_HPP
