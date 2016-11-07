//
//                         _oo0oo_
//                        o8888888o
//                        88" . "88
//                        (| -_- |)
//                        0\  =  /0
//                      ___/`---'\___
//                    .' \\|     |// '.
//                   / \\|||  :  |||// \
//                  / _||||| -:- |||||- \
//                 |   | \\\  -  /// |   |
//                 | \_|  ''\---/''  |_/ |
//                 \  .-\__  '-'  ___/-. /
//               ___'. .'  /--.--\  `. .'___
//            ."" '<  `.___\_<|>_/___.' >' "".
//           | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//           \  \ `_.   \_ __\ /__ _/   .-` /  /
//       =====`-.____`.___ \_____/___.-`___.-'=====
//                         `=---='
//
//
//       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                 佛祖保佑         永无BUG
//                
//
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
 
class Component
{
public:
	virtual void traverse() = 0;
};

class Primitive: public Component
{
	int value;
public:
	Primitive(int val)
	{
		value=val;
	}
	
	void traverse()
	{
		cout << value << " ";
	}
};

class Composite: public Component
{
	vector <Component *> children;
	int value;
public:
	Composite(int val)
	{
		value=val;
	}
	void add(Component *c)
	{
		children.push_back(c);
	}
	void traverse()
	{
		cout<< value << " ";
		for(int i=0;i<children.size();i++)
		{
			children[i] ->traverse();
		}
	}
};
class Row: public Composite
{
public:
	Row(int val):Composite(val){}
	void traverse()
	{
		cout << "Row ";
		Composite::traverse();
	}
};

class Column: public Composite
{
public:
	Column(int val):Composite(val){}
	void traverse()
	{
		cout << "Col ";
		Composite::traverse();

	}
};

int _tmain(int argc, _TCHAR* argv[])
{

  char exit;
  Row first(1);                 // Row1
  Column second(2);             //   |
  Column third(3);              //   +-- Col2
  Row fourth(4);                //   |     |
  Row fifth(5);                 //   |     +-- 7
  first.add(&second);           //   +-- Col3
  first.add(&third);            //   |     |
  third.add(&fourth);           //   |     +-- Row4
  third.add(&fifth);            //   |     |     |
  first.add(&Primitive(6));     //   |     |     +-- 9
  second.add(&Primitive(7));    //   |     +-- Row5
  third.add(&Primitive(8));     //   |     |     |
  fourth.add(&Primitive(9));    //   |     |     +-- 10
  fifth.add(&Primitive(10));    //   |     +-- 8
  first.traverse();             //   +-- 6
  cout << '\n';                 
  cin >> exit;
	return 0;
}

