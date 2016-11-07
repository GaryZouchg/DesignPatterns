// Adapter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Adapter.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char exit;
	Rectangle *r = new RectangleAdapter(120, 200, 60, 40);
	r->draw();

	std::cin>>exit;
	return 0;
}

