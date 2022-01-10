#include <iostream>
#include "Shape.h"

class Rect : public Shape {

 private:
  int width;
  int height;
 public:

  Rect();
  Rect(int w, int h);
  Rect(int w, int h, int x, int y);
  Rect(const Rect& r);
  ~Rect();
  double area();
  void print();
};
