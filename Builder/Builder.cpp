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
	reader.construct(input, UNM_ENTRIES);
	std::cout<< unixbuilder.getResult()->getState()<<std::endl;

	reader.setBuilder(&vmsbuilder);
	reader.construct(input,UNM_ENTRIES);
	std::cout << vmsbuilder.getResult()->getState()<<std::endl;

	std::cin >> exit;
	return 0;
}
	
