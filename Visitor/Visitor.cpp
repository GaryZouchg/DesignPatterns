// Visitor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <memory>
#include <iostream>
#include <tuple>

/// original visitor pattern
class Wheel;
class Engine;
class Body;
class Car;

class CarElementVisitor
{
public:
  virtual void visit(const std::shared_ptr<Wheel>& wheel) const = 0;
  virtual void visit(const std::shared_ptr<Engine>& engine) const = 0;
  virtual void visit(const std::shared_ptr<Body>& body) const = 0;
  virtual void visit(const std::shared_ptr<Car>& car) const = 0;
};

class CarElement
{
public:
  virtual void accept(const std::shared_ptr<CarElementVisitor>& visitor) = 0;
};

class Wheel : public CarElement,
              public std::enable_shared_from_this<Wheel>
{
public:
  virtual void accept(const std::shared_ptr<CarElementVisitor>& visitor)
  {
    visitor->visit(shared_from_this());
  }
};

class Engine : public CarElement,
               public std::enable_shared_from_this<Engine>
{
public:
  virtual void accept(const std::shared_ptr<CarElementVisitor>& visitor)
  {
    visitor->visit(shared_from_this());
  }
};

class Body : public CarElement,
             public std::enable_shared_from_this<Body>
{
public:
  virtual void accept(const std::shared_ptr<CarElementVisitor>& visitor)
  {
    visitor->visit(shared_from_this());
  }
};

class Car : public CarElement,
            public std::enable_shared_from_this<Car>
{
  typedef std::tuple<std::shared_ptr<Wheel>, std::shared_ptr<Engine>, std::shared_ptr<Body> > Elements;

  template <std::size_t> class int_ {};

  template <typename Tuple, std::size_t pos>
  void visit(const std::shared_ptr<CarElementVisitor>& visitor, const Tuple& t, int_<pos>)
  {
    visitor->visit(std::get<std::tuple_size<Tuple>::value - pos>(t));
    visit(visitor, t, int_<pos - 1>());
  }

  template <typename Tuple>
  void visit(const std::shared_ptr<CarElementVisitor>& visitor, const Tuple& t, int_<1>)
  {
    visitor->visit(std::get<std::tuple_size<Tuple>::value - 1>(t));
  }

  template <typename Args>
  void visit(const std::shared_ptr<CarElementVisitor>& visitor, const std::tuple<Args >& t)
  {
    visit(visitor, t, int_<sizeof...(Args)>());
  }

public:
  Car()
  {
    elements_ = std::make_tuple(std::make_shared<Wheel>(), std::make_shared<Engine>(), std::make_shared<Body>());
  }

  virtual void accept(const std::shared_ptr<CarElementVisitor>& visitor)
  {
    visit(visitor, elements_);
    visitor->visit(shared_from_this());
  }

private:

  Elements elements_;
};

class PrintVisitor : public CarElementVisitor
{
public:
  virtual void visit(const std::shared_ptr<Wheel>& wheel) const
  {
    std::cout << "void PrintVisitor::visit(std::shared_ptr<Wheel> wheel) const" << std::endl;
  }

  virtual void visit(const std::shared_ptr<Engine>& engine) const
  {
    std::cout << "void PrintVisitor::visit(std::shared_ptr<Engine> engine) const" << std::endl;
  }

  virtual void visit(const std::shared_ptr<Body>& body) const
  {
    std::cout << "void PrintVisitor::visit(std::shared_ptr<Body> body) const" << std::endl;
  }

  virtual void visit(const std::shared_ptr<Car>& car) const
  {
    std::cout << "void PrintVisitor::visit(std::shared_ptr<Car> car) const" << std::endl;
  }
};

class OtherVisitor : public CarElementVisitor
{
public:
  virtual void visit(const std::shared_ptr<Wheel>& wheel) const
  {
    std::cout << "void OtherVisitor::visit(std::shared_ptr<Wheel> wheel) const" << std::endl;
  }

  virtual void visit(const std::shared_ptr<Engine>& engine) const
  {
    std::cout << "void OtherVisitor::visit(std::shared_ptr<Engine> engine) const" << std::endl;
  }

  virtual void visit(const std::shared_ptr<Body>& body) const
  {
    std::cout << "void OtherVisitor::visit(std::shared_ptr<Body> body) const" << std::endl;
  }

  virtual void visit(const std::shared_ptr<Car>& car) const
  {
    std::cout << "void OtherVisitor::visit(std::shared_ptr<Car> car) const" << std::endl;
  }
};



int _tmain(int argc, _TCHAR* argv[])
{
	
	std::shared_ptr<CarElement> car(std::make_shared<Car>());
	car->accept(std::make_shared<PrintVisitor>());
	car->accept(std::make_shared<OtherVisitor>());
	
	return 0;
}

