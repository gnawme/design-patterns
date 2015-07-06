#ifndef FINAL_LEGACY_CLASSES_HPP
#define FINAL_LEGACY_CLASSES_HPP

#include <iostream>

namespace legacy_classes    // Can't touch these.
{

class CleanABS
{
public:
   ~CleanABS()
    {
        std::cout << "~CleanABS " << std::endl;
    }

    //! \fn     clean
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
        std::cout << "~CleanPolys " << std::endl;
    }

    //! \fn     clean
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
        std::cout << "~PETCleanup " << std::endl;
    }

    //! \fn     clean
    void carbonize()    // Use only on stainless steel.
    {
        std::cout << "\tClean PET steel mold: heat to 895 C." << std::endl;
    }

    //! \fn     clean
    void purify()       // Use only on aluminum.
    {
        std::cout << "\tClean PET aluminum mold: rinse with soap and water, dry." << std::endl;
    }
};

}//namespace legacy_classes

#endif//FINAL_LEGACY_CLASSES_HPP