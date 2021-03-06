#include <iostream>
#include "Rect.h"

  
Rect::Rect() : Shape(){
  width = 1;
  height = 1;
}
Rect::Rect(int w, int h) : Shape(){
  width = w;
  height = h;
}
Rect::Rect(int w, int h, int xx, int y) : Shape(x,y){
  width = w;
  height = h;
  //x = xx;
  //this->y = y;
}
Rect::~Rect(){
  std::cout << "Rect destruct\n";
}
Rect::Rect(const Rect& r) : Shape(r){
  std::cout << "Rect cpy const\n";
  width = r.width;
  height = r.height;
}

double Rect::area(){
  return width*height;
}
void Rect::print(){
  std::cout << "Rect with width of "<<width<< " and height of "<< height << " at " << x << ", "<<y<<"\n";
}

