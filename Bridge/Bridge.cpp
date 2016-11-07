// Bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bridge.h"

int _tmain(int argc, _TCHAR* argv[])
{
  Time *times[3]; char exit;
  times[0] = new Time(14, 30);
  times[1] = new CivilianTime(2, 30, 1);
  times[2] = new ZuluTime(14, 30, 6);
  for (int i = 0; i < 3; i++)
    times[i]->tell();

  std::cin>>exit;
  return 0;
}

