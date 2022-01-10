
#include <iostream>
#include <string>
#include "Animal.h"

Animal::Animal(){
  std::cout << "Animal no parm const\n";
  color = "blue";
}
Animal::Animal(std::string c){
  std::cout << "Animal 1 parm const\n";
  color = c;
}
Animal::~Animal(){
  std::cout << "Animal deconst\n";
}
Animal::Animal(const Animal& a){
  color = a.color;
}
std::string Animal::getColor(){
  return color;
}


