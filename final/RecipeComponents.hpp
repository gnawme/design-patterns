#ifndef FINAL_RECIPE_COMPONENTS_HPP
#define FINAL_RECIPE_COMPONENTS_HPP
/*---------------------------------------------------------------------------*\
| \file     RecipeComponents.hpp
| \brief    Declares objects participating in Mix Recipe Decorator
| \author   Norm Evangelista
\*---------------------------------------------------------------------------*/
#include <memory>
#include <sstream>
#include <string>

/*---------------------------------------------------------------------------*\
| \class    RecipeComponent
| \brief    Component base class
\*---------------------------------------------------------------------------*/
class RecipeComponent
{
public:
    virtual            ~RecipeComponent() 
                        { 
                            std::cout 
                            << "~RecipeComponent " 
                            << std::endl; 
                        };

    virtual std::string description() = 0;
    virtual int         volume() = 0;
};

typedef std::shared_ptr<RecipeComponent>    TRecipePtr;

/*---------------------------------------------------------------------------*\
| \note     Concrete RecipeComponents
\*---------------------------------------------------------------------------*/
//!
class RecipeMold: public RecipeComponent
{
public:
                    RecipeMold( 
                        std::string&    plastic,
                        int             volume )
                    : m_description( plastic )
                    , m_volume( volume )
                    {}

                   ~RecipeMold()
                    { 
                        std::cout 
                        << "~RecipeMold ";
                    };


    std::string     description()
                    {
                        std::stringstream ss; 
                        ss 
                        << m_description
                        << "("
                        << m_volume
                        << ") ";

                        return std::string( ss.str() );
                    };

    int             volume()
                    {
                        return m_volume;
                    };

private:
    std::string     m_description;
    int             m_volume;
};

/*---------------------------------------------------------------------------*\
| \class    RecipeDecorator
| \brief    Decorator 
\*---------------------------------------------------------------------------*/
class RecipeDecorator: public RecipeComponent
{
public:
    virtual            ~RecipeDecorator() 
                        { 
                            std::cout 
                            << "~RecipeDecorator "
                            << std::endl; 
                        };

    virtual std::string description() = 0;
};

/*---------------------------------------------------------------------------*\
| \note     Concrete RecipeDecorators
\*---------------------------------------------------------------------------*/
class RecipeAdditive: public RecipeDecorator
{
public:
                    RecipeAdditive( 
                        TRecipePtr      comp,
                        std::string&    description,
                        int             volume )
                    : m_recipe_comp( comp )
                    , m_description( description )
                    , m_volume( volume )
                    {}

                   ~RecipeAdditive()
                    { 
                        std::cout 
                        << "~RecipeAdditive ";
                    };

    std::string     description()
                    { 
                        std::stringstream ss; 
                        ss 
                        << m_recipe_comp->description()
                        << m_description
                        << "("
                        << m_volume
                        << ") ";

                        return std::string( ss.str() );
                    };

    int             volume()
                    {
                        return m_recipe_comp->volume() + m_volume;
                    }

private:
    TRecipePtr      m_recipe_comp;
    std::string     m_description;
    int             m_volume;
};


#endif//FINAL_RECIPE_COMPONENTS_HPP
