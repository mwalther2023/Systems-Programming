#include <iostream>
#include "Shape.h"

Shape::Shape(){
  std::cout << "Shape deft const\n";
  x = 0;
  y = 0;
}
Shape::Shape(int dx, int dy){
  std::cout << "Shape 2 parm const\n";
  x = dx;
  y = dy;
}
Shape::~Shape(){
  std::cout << "Shape destr\n";
}
Shape::Shape(const Shape& s){
  std::cout << "Shape copy const\n";
  x = s.x;
  y = s.y;
}
void Shape::trans(int dx, int dy){
  x += dx;
  y += dy;
}

double Shape::area(){
  return -1;
}
