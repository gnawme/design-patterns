/*
 * adapter.h
 *
 * Desc: Adapt interfaces so classes can work together polymorphically.
 *
 *  Created on: Mar 8, 2014
 *      Author: aldgoff
 *
 *  URLs:
 *      http://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Adapter
 *      http://www.dofactory.com/net/adapter-design-pattern
 *      http://www.netobjectives.com/resources/books/design-patterns-explained/review-questions#Chapter7
 *      http://sourcemaking.com/design_patterns/adapter
 */

#ifndef ADAPTER_H_
#define ADAPTER_H_

/* Consider the case where an installed and heavily used class hierarchy
 * for simple shapes needs to be extended by incorporating a commercial
 * class hierarchy containing more complex shapes.
 * The problem is that the two class hierarchies use different API's.
 * The original one uses the function "draw()" the other the function "display()".
 * This breaks the polymorphism that kept the client code simple.
 * This cause 4 maintenance headaches:
 *   1) Client code will become more complicated.
 *   2) Changes will be required in existing client code.
 *   3) Likely become littered with if statements of the sort "what type are you"?
 *   4) Need for error detection.
 * Solve this problem by writing new classes that 'adapt' the new interface
 * to the old.
 */

class ShapeInterfaceDraw                      // Interface class (home grown?).
{
public:
    virtual void draw()=0;
    virtual ~ShapeInterfaceDraw() {}
};
class Point : public ShapeInterfaceDraw
{
public:
    void draw()
    {
        cout << "Draw point.\n";
    }
};
class Line : public ShapeInterfaceDraw
{
public:
    void draw()
    {
        cout << "Draw line.\n";
    }
};
class Rect : public ShapeInterfaceDraw
{
public:
    void draw()
    {
        cout << "Draw rectangle.\n";
    }
};

namespace commercial
{

class ShapeInterfaceDisplay                  // Another interface class (commercial?).
{
public:
    virtual void display()=0;
    virtual ~ShapeInterfaceDisplay() {}
};
class Polygon : public ShapeInterfaceDisplay
{
public:
    void display()
    {
        cout << "Display polygon.\n";
    }
};
class Torus : public ShapeInterfaceDisplay
{
public:
    void display()
    {
        cout << "Display torus.\n";
    }
};
class Bezel : public ShapeInterfaceDisplay
{
public:
    void display()
    {
        cout << "Display bezel.\n";
    }
};

}

namespace adapter_legacy
{

void demo()
{
    vector<ShapeInterfaceDraw*> shapes;
    shapes.push_back( new Point );
    shapes.push_back( new Line );
    shapes.push_back( new Rect );

    for( size_t i=0; i<shapes.size(); i++ )    // Polymorphic client code.
    {
        shapes[i]->draw();
    }

    cout << endl;
}

}

namespace adapter_problem
{

struct Shapes
{
    ShapeInterfaceDraw*    draw;
    commercial::ShapeInterfaceDisplay*    display;
    Shapes(
        ShapeInterfaceDraw* draw=0,
        commercial::ShapeInterfaceDisplay* display=0 )
        : draw( draw ), display( display ) {}
};

void demo()
{
    vector<Shapes*>    shapes;                    // Changes to existing code.
    shapes.push_back( new Shapes( new Point ) );
    shapes.push_back( new Shapes( new Line ) );
    shapes.push_back( new Shapes( new Rect ) );
    shapes.push_back( new Shapes( 0, new commercial::Polygon ) );
    shapes.push_back( new Shapes( 0, new commercial::Torus ) );
    shapes.push_back( new Shapes( 0, new commercial::Bezel ) );

    for( size_t i=0; i<shapes.size(); i++ )    // Client code more complicated
    {
        if( shapes[i]->draw )                  // because API's differ
            shapes[i]->draw->draw();        // requiring if-else statements,
        else if( shapes[i]->display )          // changes to existing client code,
            shapes[i]->display->display();
        else
        {
            throw "unknown shape object.";    // and worse; error detection.
        }
    }

    cout << endl;
}

}

#endif /* ADAPTER_H_ */
