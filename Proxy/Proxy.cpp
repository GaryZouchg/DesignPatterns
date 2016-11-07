// Proxy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Proxy.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char exit;
	ProxySubject obj(string("the quick brown fox jumped over the dog"));
	obj->execute();
	obj.execute();

	cin >> exit;
	return 0;
}

