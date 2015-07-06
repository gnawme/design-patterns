/*
 * finalDesign.h
 *
 *  Created on:
 *      Author:
 *
 *  Project: Intro to Design Patterns Pilot class.
 */

#ifndef DP4_SRC_DESIGN_FINAL_H_
#define DP4_SRC_DESIGN_FINAL_H_

namespace final_design_file
{

const bool on = true;	// Useful macro to turn dtor instrumentation on/off.
inline void DTOR(std::std::string& x) 
{
    if(on) 
    { 
        std::cout << x << std::endl; 
    }
}

namespace legacy_classes  	// Can't change these.
{

class CleanABS
{
public:
    ~CleanABS()
    {
        DTOR( "~CleanABS " );
    }
    void clean()
    {
        std::cout << "\tClean ABS mold: soak in alcohol, rinse with water, dry." << std::endl;
    }
};

class CleanPolys
{
public:
    ~CleanPolys()
    {
        DTOR( "~CleanPolys " );
    }
    void prepForReuse()
    {
        std::cout << "\tClean Poly mold: rinse with acetone, dry." << std::endl;
    }
};

class PETCleanup
{
public:
    ~PETCleanup()
    {
        DTOR( "~PETCleanup " );
    }
    void carbonize()   // Use only on stainless steel.
    {
        std::cout << "\tClean PET steel mold: heat to 895 C." << std::endl;
    }
    void purify()  	// Use only on aluminum.
    {
        std::cout << "\tClean PET aluminum mold: rinse with soap and water, dry." << std::endl;
    }
};

}

namespace adapter  			// DP 2.
{

// Seam point - add another interface.

}

namespace strategy  		// DP 1.
{

// Seam point - add another algorithm.

}

namespace observer  		// DP 7.
{

// Seam point - add another listener.

}

namespace abstract_factory  // DP 10.
{

// Seam point - add another type1 member.
// Seam point - add another type2 member.
// Seam point - add another type3 member.
// ...

// Seam point - add another family.

}
// ----- Alternatively (may make it hard to match the dtor instrumentation) -----
namespace abstract_factory_solti  	// DP 10 - more like GoF.
{

class AbstractA {};
class AbstractB {};
class AbstractC {};
// ...

class AbstractFactory {};
class InjectionLine {};

// 10,000
class ConcreteA_1 : public AbstractA {};
class ConcreteB_1 : public AbstractB {};
class ConcreteC_1 : public AbstractC {};
class AF_1 : public AbstractFactory {};
class IL_1 : public InjectionLine {};

// 20,000
class ConcreteA_2 : public AbstractA {};
class ConcreteB_2 : public AbstractB {};
class ConcreteC_2 : public AbstractC {};
class AF_2 : public AbstractFactory {};
class IL_2 : public InjectionLine {};

// 50,000
class ConcreteA_3 : public AbstractA {};
class ConcreteB_3 : public AbstractB {};
class ConcreteC_3 : public AbstractC {};
class AF_3 : public AbstractFactory {};
class IL_3 : public InjectionLine {};

// Seam line - add another family.

}

namespace bridge  			// DP 9.
{

// Seam Point - add another implementation.

// Seam Point - add another abstraction.

}

namespace chain_of_resp  	// DP 8.
{

// Seam points - add another responder.

}

namespace decorator  		// DP 6.
{

// Seam point - add another option.

}

namespace factory_method  	// DP 5.
{

// Seam point - add another class.

}

namespace template_method  	// DP 4.
{

// Seam point - add another step.

}

void process( std::map<std::string, std::string>& order )
{

}

std::pair<std::string, std::string> parse( std::string line )
{
    char key[83];
    char val[83] = {0};

    sscanf( line.c_str(), "%s", key );

    char* equalSign = strchr( line.c_str(), '=' );
    std::string value = "";
    if( equalSign )  	// tags = sam i am
    {
        char*	nextToken = equalSign += 2;
        while( nextToken )
        {
            sscanf( nextToken, "%s", val );
            value += val;
            nextToken = strchr( nextToken+1, ' ' );
            value += " ";
        }
        value.erase( value.length()-1, 1 );
    }

    return make_pair( key, value );
}

std::map<std::string, std::string> getCompleteOrder( FILE* orderFilePtr )
{
    std::map<std::string, std::string> order;
    char line[80+3];
    std::pair<std::string, std::string>	keyValue;

    while( fgets( line, 80, orderFilePtr ) )
    {
        std::cout << line;
        if( strstr( line, "endOfOrder" ) )
        {
            return( order );
        }
        else
        {
            keyValue = parse( line );
            std::string key = keyValue.first;
            if( strchr( key.c_str(), ':' ) )	// Skip left justified order number.
                continue;
            std::string value = keyValue.second;
            order[key] = value;
        }
    }

    return order;
}

void demo( const std::string& orderFile )
{
    std::cout << "<<< final design >>>" << std::endl;

    FILE* orderFilePtr = fopen( orderFile.c_str(), "r" );

    for( ;; )  	// Get and process each order.
    {
        std::map<std::string, std::string> order = getCompleteOrder( orderFilePtr );
        if( order.size() == 0 )
            break;
        process( order );
    }
}

}

#endif//DP4_SRC_DESIGN_FINAL_H_
