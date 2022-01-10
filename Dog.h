#include <iostream>
#include <string>
#include "Animal.h"

class Dog : public Animal{
 private:
  std::string name;

 public:
  Dog();
  Dog(std::string n, std::string c);
  virtual ~Dog();
  Dog(const Dog& d);
  virtual std::string getName();
  virtual std::string makeSound();
};
