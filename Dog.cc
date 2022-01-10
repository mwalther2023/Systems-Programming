#include <iostream>
#include <string>
#include "Dog.h"

Dog::Dog() : Animal(){
  name = "no name";
}
Dog::Dog(std::string n, std::string c) : Animal(c){
  name = n;
}
Dog::~Dog(){
  std::cout << "Dog destruct\n";
}
Dog::Dog(const Dog& d) : Animal (d){
  std::cout << "Dog cpy const\n";
  name = d.name;
}
std::string Dog::getName(){
  return name;
}
std::string Dog::makeSound(){
  return "woof";
}
