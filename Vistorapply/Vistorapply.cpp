// Vistorapply.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Visitor.h"
#include <string>
#include "Methods.h"


int _tmain(int argc, _TCHAR* argv[])
{
    typedef boost::variant< int,double,bool,std::string >  VRT;
    std::vector< VRT > vec_VRT;

    VRT tmp= 100;

    vec_VRT.push_back( tmp );
    vec_VRT.push_back( "string" );
    vec_VRT.push_back( 1.0001 );

    IMethods * f = new Methods;

    for(auto iter= vec_VRT.begin(); iter != vec_VRT.end(); iter++)
    {
        f->DataPrint( 45 );
    }
    




    char quit;
    std::cin>>quit; 
	return 0;
}

