#include <iostream>
#include <string>
#include "Cat.h"

Cat::Cat() : Animal(){
  name = "no name";
}
Cat::Cat(std::string n, std::string c) : Animal(c){
  name = n;
}
Cat::~Cat(){
  std::cout << "Cat deconstr\n";
}
Cat::Cat(const Cat& c){
  std::cout << "Cat cpy const\n";
  name = c.name;
}
std::string Cat::getName(){
  return name;
}
std::string Cat::makeSound(){
  return "meow";
}
