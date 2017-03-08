﻿// Visitor2.cpp : Defines the entry point for the console application.

#include "stdafx.h"

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

int _tmain(int argc, _TCHAR* argv[])
{
  Component *nodes[3];
  // The type of Composite* is "lost" when the object is assigned to a Component*
  // 把 Composite* 的类型赋值给 Component* 后, Composite*的类型信息就丢失了
  nodes[0] = new Composite(1);
  nodes[1] = new Composite(2);
  nodes[2] = new Composite(3);

  // If add() were in class Component, this would work   nodes[0]->add( nodes[1] );
  // If it is NOT in Component, and only in Composite,  you get the error -
  //    no member function `Component::add(Component *)' defined
  // 如果类Component中 存在虚函数add() nodes[0]->add( nodes[1] )  ;    
  // 如果没有会报错; 成员函数Component::add(Component *) 未定义

  // Instead of sacrificing safety, we use a Visitor to support add()
  AddVisitor addVisitor;
  nodes[0]->accept(addVisitor, nodes[1]);   

  nodes[0]->accept(addVisitor, nodes[2]);
  nodes[0]->accept(addVisitor, new Primitive(4));
  //composite::accept(Visitor &v, Component *c){v.vist(this,c);}
  //visit(Composite *node, Component *c) {node->add(c);}
  //把  Composite(2)  中的值 存入node[0]   
  nodes[1]->accept(addVisitor, new Primitive(5));
  nodes[1]->accept(addVisitor, new Primitive(6));
  nodes[2]->accept(addVisitor, new Primitive(7));

  for (int i = 0; i < 3; i++)
  {
    nodes[i]->traverse();
    cout << endl;
  }

  char exit;
  std::cin>>exit;
  return 0;
}

