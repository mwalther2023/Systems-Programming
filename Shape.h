#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape{
   protected:
  // private:
  int x;
  int y;

 public:
  Shape();
  Shape(int dx, int dy);
  Shape(const Shape& s);
  virtual ~Shape();
  virtual void trans(int dx, int dy);
  virtual double area();
};
#endif
