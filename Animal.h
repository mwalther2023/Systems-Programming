#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal{
 protected:
  std::string color;
 public:
  Animal();
  Animal(std::string c);
  Animal(const Animal& a);
  virtual ~Animal();
  virtual std::string getColor();
  virtual std::string makeSound() = 0;
};

#endif
