#include <iostream>

using namespace std;

class Subject
{
  public:
    virtual void execute() = 0;
};

class RealSubject: public Subject
{
    string str;
  public:
    RealSubject(string s)
    {
        str = s;
    }
     /*virtual*/void execute()
    {
		cout << str.c_str() << '\n';
    }
};

class ProxySubject: public Subject
{
    string first, second, third;
    RealSubject *ptr;
  public:
    ProxySubject(string s)
    {
        int num = s.find_first_of(' ');
        first = s.substr(0, num);
        s = s.substr(num + 1);

        num = s.find_first_of(' ');
        second = s.substr(0, num);
        s = s.substr(num + 1);
        num = s.find_first_of(' ');
        third = s.substr(0, num);
        s = s.substr(num + 1);
        ptr = new RealSubject(s);
    }
    ~ProxySubject()
    {
        delete ptr;
    }
    RealSubject *operator->()
    {
        cout << first.c_str() << ' ' << second.c_str() << ' ';
        return ptr;
    }
     /*virtual*/void execute()
    {
        cout << first.c_str() << ' ' << third.c_str() << ' ';
        ptr->execute();
    }
};
