// Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Builder.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char exit;
	UnixBuilder unixbuilder;
	VmsBuilder  vmsbuilder;
	Reader      reader;

	reader.setBuilder(&unixbuilder);
	reader.construct(input2, UNM_ENTRIES);
	std::cout<< unixbuilder.getResult()->getState()<<std::endl;
    //unixbuilder.getResult()返回 DistrWorkPackage
    //通过Reader的对象来创建 DistrWorkPackage 对象
	
    reader.setBuilder(&vmsbuilder);//通过不同的builder创建不同的对象
	reader.construct(input,UNM_ENTRIES);
	std::cout << vmsbuilder.getResult()->getState()<<std::endl;
    
	std::cin >> exit;
	return 0;
}
	
