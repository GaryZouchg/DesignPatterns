#pragma once



#include<iostream>
#include<vector>
#include "Methods.h"
#include "boost\variant.hpp"

class PrintVisitor : public boost::static_visitor<>
{
     typedef boost::variant< int,double,bool,std::string >  VRT;
private:
    IMethods * fptr;

public:
    PrintVisitor( )
    {
        fptr = new Methods();
    }

    template<typename T> void operator()( T & v1)
    {
        fptr->DataPrint( v1 );
    }


};


class Visitor
{
    typedef boost::variant< int,double,bool,std::string >  VRT;
public:
    Visitor()
    {
        fptr = new Methods();
    }

    template<typename T> void visit( T& arg  )
    {
        fptr->DataPrint( arg );
        return;
    }
private:
    IMethods * fptr;
};