// Vistorapply.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Visitor.h"
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
    typedef boost::variant< int,double,bool,std::string >  VRT;
    std::vector< VRT > vec_VRT;

    VRT tmpi= 100;
    std::string tempstr="string";

    vec_VRT.push_back( tmpi );
    vec_VRT.push_back( 1.0001 );
    vec_VRT.push_back( true );
    vec_VRT.push_back( tempstr );


    for(auto iter= vec_VRT.begin(); iter != vec_VRT.end(); iter++)
    {
        PrintVisitor printVisitor;
        boost::apply_visitor( printVisitor,*iter );
    }
    

    for( auto iter= vec_VRT.begin(); iter != vec_VRT.end(); iter++ )
    {
        Visitor visitor;
        //visitor.visit( *iter );
    }



    char quit;
    std::cin>>quit; 
	return 0;
}

