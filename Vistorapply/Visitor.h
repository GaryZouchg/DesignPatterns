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
    VRT  vrt;

public:
    PrintVisitor( VRT v ):vrt( v )
    {
        fptr = new Methods();
    }

    template<typename T> void operator()( T & v1)
    {
        fptr->DataPrint( v1 );
    }


};

