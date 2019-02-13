#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm> // stable_sort, for_each

using namespace std;

class Shape // TODO fix a fatal bug!
{
protected:
  Shape(string name) : name_(name) {}
public:
  virtual ~Shape(){}
  const string& getName() const { return name_; }
  virtual float getAreaSize() const = 0;
private:
  string name_;
};

class Circle : public Shape
{
public:
  Circle(string name, unsigned radius) : Shape(name), radius_(radius) {};
  virtual float getAreaSize() const override { return radius_ * radius_* 3.14; } // TODO
private:
  unsigned radius_;
};

// TODO Rectangle, Triangle, Square
class Rectangle : public Shape
{
public:
  Rectangle (string name, unsigned teihen, unsigned takasa) : Shape(name), teihen_(teihen), takasa_(takasa) {};
  virtual float getAreaSize() const override { return teihen_ * takasa_; } // TODO
private:
  unsigned teihen_;
  unsigned takasa_;
};


class Triangle : public Shape
{
public:
  Triangle(string name, unsigned teihen, unsigned takasa) : Shape(name), teihen_(teihen), takasa_(takasa) {};
  virtual float getAreaSize() const override { return teihen_ * takasa_ / 2; } // TODO
private:
  unsigned teihen_;
  unsigned takasa_;
};

class Square : public Shape
{
public:
  Square(string name, unsigned ippen) : Shape(name), ippen_(ippen) {};
  virtual float getAreaSize() const override { return ippen_ * ippen_; } // TODO
private:
  unsigned ippen_;
};

int main()
{
  vector<unique_ptr<Shape> > vec;
  vec.push_back(unique_ptr<Shape>(new Circle("c1", 2)));
  vec.push_back(unique_ptr<Shape>(new Circle("c2", 4)));

  // TODO push back other shapes
  vec.push_back(unique_ptr<Shape>(new Rectangle("r1", 2, 3)));
  vec.push_back(unique_ptr<Shape>(new Triangle("t1", 2, 3)));
  vec.push_back(unique_ptr<Shape>(new Square("s1", 4)));


  for (auto& sp: vec){
    auto s = sp.get();
    cout << s->getName() << ": " << s->getAreaSize() << endl;
  }

  // TODO stable_sort と ラムダ式 を使用して、面積の大きい順に並び替える（1文で）
  // stable_sort(vec.begin(), vec.end(), ????);
  	stable_sort(vec.begin(), vec.end(), [](const unique_ptr<Shape>& x, const unique_ptr<Shape>& y) { return x->getAreaSize() > y->getAreaSize();});

  for (auto& sp: vec){
    auto s = sp.get();
    cout << s->getName() << ": " << s->getAreaSize() << endl;
  }

  return 0;
}
