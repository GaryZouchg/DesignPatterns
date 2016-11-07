// AbstractFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

class Shape{
public:
	Shape()
	{
		id_ = total_++;
	}
	virtual void draw()=0;
protected:
	int id_;
	static int total_;
};

int Shape::total_ = 0;

class Circle:public Shape
{
public:
	void draw()
	{
		std::cout<< "Circle "<<id_<<" draw"<<std::endl; 
	}
};
class Ellipse:public Shape
{
public:
	void draw()
	{
		std::cout<< "Ellipse "<<id_<<" draw"<<std::endl; 
	}
};

class Square:public Shape
{
public:
	void draw()
	{
		std::cout<< "Square "<<id_<<" draw"<<std::endl; 
	}
};

class Rectangle:public Shape
{
public:
	void draw()
	{
		std::cout<< "Rectangle "<<id_<<" draw"<<std::endl; 
	}
};


class Factory
{
public:
	virtual Shape* createCurvedInstance()
	{
		return new Circle;
	}
	virtual Shape* createStraightInstance()
	{
		return new Square;
	}
};


class SimpleShapeFactory:public Factory
{
	Shape* createCurvedInstance()
	{
		return new Circle;
	}
	Shape* createStraightInstance()
	{
		return new Square;
	}

};

class RobustShapeFactory:public Factory
{
	Shape* createCurvedInstance()
	{
		return new Ellipse;
	}
	Shape* createStraightInstance()
	{
		return new Rectangle;
	}	

};

int _tmain(int argc, _TCHAR* argv[])
{
	char exit;

	Factory * factory1 = new SimpleShapeFactory;
	Factory * factory2 = new RobustShapeFactory;

	Shape *shapes[4];

	shapes[0]= factory1->createCurvedInstance();

	shapes[1]= factory1->createStraightInstance();

	shapes[2]= factory2->createCurvedInstance();

	shapes[3]= factory2->createStraightInstance();

	for(int i=0;i<4;++i)
	{
		shapes[i]->draw();
	}


	std::cin>>exit;
	return 0;
}

