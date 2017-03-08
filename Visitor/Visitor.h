#include <iostream>
#include <vector>
using namespace std;

class Visitor
{
public:
    virtual void visit(class Primitive *, class Component*) = 0;
    virtual void visit(class Composite *,class Component*) = 0;
};

class Component
{
    int value;
public:
    Component(int val)
    {
        value = val;
    }
    virtual void traverse()
    {
        cout << value << " ";
    }
    // Having add() here sacrifices safety, but it supports transparency
    // virtual void add( Component* ) { }
    virtual void accept(Visitor &, Component*) = 0;
};

class Primitive: public Component
{
  public:
    Primitive(int val): Component(val){cout<<"primitive constructor"<<endl ;}
    void accept(Visitor &v, Component *c)
    {
        v.visit(this, c);
    }
};

class Composite: public Component
{
    vector < Component * > children;
  public:
    Composite(int val): Component(val){ cout<<"composit constructor"<<endl ; }
    void add(Component *ele)
    {
        children.push_back(ele);
    }	
    void accept(Visitor &v, Component *c)
    {
        v.visit(this, c);
    }
    void traverse()
    {
        Component::traverse();
        for (int i = 0; i < children.size(); i++)
          children[i]->traverse();   //函数自身调用
    }
};    
    
class AddVisitor: public Visitor
{
public:
    void AddVistitor(){"AddVistor Constructor";}
    void visit(Primitive *, Component*)
    {
    /* does not make sense */
    }
    void visit(Composite *node, Component *c)
    {
        node->add(c);
    }
};