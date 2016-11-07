#include<iostream>
#include<stdio.h>
#include<string.h>

enum PersistenceType
{
	File,Queue,Pathway
};
struct PersistenceAttribute
{
	PersistenceType type;
	char value[30];
};

class DistrWorkPackage
{
public:
	DistrWorkPackage(char *type)
	{
		sprintf(_desc, "DistrWorkPackage for: %s",type);
	}

	void setFile(char *f,char *v)
	{
		sprintf(_temp, "\n File(%s): %s", f, v);
		strcat(_desc,_temp);
	}	

	void setQueue(char *q,char *v)
	{
		sprintf(_temp, "\n Queue(%s): %s", q, v);
		strcat(_desc,_temp);
	}

	void setPathway(char *p,char *v)
	{
		sprintf(_temp, "\n Pathway(%s): %s", p, v);
		strcat(_desc,_temp);
	}

	const char *getState()
	{
		return _desc;
	}

private:
	char _desc[200],_temp[80];
};

class Builder
{
public:
	virtual void configureFile(char *) = 0;
	virtual void configureQueue(char *) = 0;
	virtual void configurePathway(char *) = 0;
	DistrWorkPackage *getResult()
	{
		return _result;
	}

protected: 
	DistrWorkPackage *_result;
};

class UnixBuilder: public Builder
{
public:
	UnixBuilder()
	{
		_result = new DistrWorkPackage("Unix");
	}

	void configureFile(char *name)
	{
		_result->setFile("flatFile",name);	
	}
	void configureQueue(char *queue)
	{
		_result->setQueue("FIFO",queue);
	}

	void configurePathway(char *type)
	{
		_result->setPathway("thread",type);
	}
};

class VmsBuilder: public Builder
{
public:
	VmsBuilder()
	{
		_result = new DistrWorkPackage("Vms");
	}

	void configureFile(char *name)
	{
		_result->setFile("ISAM",name);	
	}
	void configureQueue(char *queue)
	{
		_result->setQueue("Priority",queue);
	}

	void configurePathway(char *type)
	{
		_result->setPathway("LWP",type);
	}
};

class Reader
{
public:
	void setBuilder(Builder *B)
	{
		_builder = B;
	}

	void construct(PersistenceAttribute[],int);
private:
	Builder *_builder;
};
const int UNM_ENTRIES = 6;

PersistenceAttribute input[UNM_ENTRIES] =
{
	{File,"state.dat"},
	{File,"config.sys"},

	{Queue,"compute"},
	{Queue,"log"},

	{Pathway,"Pathway"},
	{Pathway,"errot processing"}
};

void Reader::construct(PersistenceAttribute list[],int num)
{
	for(int i=0;i<num;i++)
	{
		if( list[i].type==File)          _builder->configureFile(list[i].value);
		else if (list[i].type==Queue)    _builder->configureQueue(list[i].value);
		else if (list[i].type==Pathway)  _builder->configurePathway(list[i].value);
	}
}