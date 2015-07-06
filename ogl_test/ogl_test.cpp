/*--------------------------------------------------------------------*\
| \author   Norm Evangelista
| \brief    Simple test to check if OpenGL dev is configured
\*--------------------------------------------------------------------*/
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <string>

/*--------------------------------------------------------------------*\
|
\*--------------------------------------------------------------------*/
void error_callback(
    int         error, 
    const char* description
)
{
    std::cerr
    << "GLFW error: "
    << description
    << std::endl;
}

/*--------------------------------------------------------------------*\
|
\*--------------------------------------------------------------------*/
int main()
{
    /*----------------------------------------------------------------*\
    |   Init GFLW, bail if bad
    \*----------------------------------------------------------------*/
    if ( !glfwInit() )
    {
        std::cerr << "Error initializing GLFW" << std::endl;
    }

    glfwSetErrorCallback( error_callback );

    /*----------------------------------------------------------------*\
    |   Window and context
    \*----------------------------------------------------------------*/
    GLFWwindow* win480p = glfwCreateWindow( 720, 480, "I Hate GLUT", NULL, NULL );
    if (!win480p)
    {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent( win480p );

    /*----------------------------------------------------------------*\
    |   Init GLEW, bail if bad
    \*----------------------------------------------------------------*/
    GLenum err = glewInit();
    if ( GLEW_OK != err )
    {
        std::string glewboo( reinterpret_cast<const char*>( glewGetErrorString( err ) ) );
        std::cerr
        << "Error initializing GLEW, "
        << glewboo
        << std::endl;
        
        return EXIT_FAILURE;

    }

    /*----------------------------------------------------------------*\
    |   GLM decl to test inclusion
    \*----------------------------------------------------------------*/
    glm::mat4 proj;

    /*----------------------------------------------------------------*\
    |   Get OpenGL properties
    \*----------------------------------------------------------------*/
    std::string renderer( reinterpret_cast<const char*>( glGetString( GL_RENDERER ) ) );
    std::string vendor( reinterpret_cast<const char*>( glGetString( GL_VENDOR ) ) );
    std::string version( reinterpret_cast<const char*>( glGetString( GL_VERSION ) ) );
    std::string glsl( reinterpret_cast<const char*>( glGetString( GL_SHADING_LANGUAGE_VERSION ) ) );

    GLint major, minor; 
    glGetIntegerv( GL_MAJOR_VERSION, &major ); 
    glGetIntegerv( GL_MINOR_VERSION, &minor );

    /*----------------------------------------------------------------*\
    |   Print OpenGL properties
    \*----------------------------------------------------------------*/
    std::cout
    << "OpenGL version "
    << version
    << "(" << major << "." << minor << ")" << std::endl
    << "Vendor:        " << vendor << std::endl
    << "Renderer:      " << renderer << std::endl
    << "GLSL:          " << glsl << std::endl;


    /*----------------------------------------------------------------*\
    |   Buh-bye
    \*----------------------------------------------------------------*/
    glfwDestroyWindow( win480p );
    glfwTerminate();
    return EXIT_SUCCESS;
}