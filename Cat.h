#include <iostream>
#include <string>
#include "Animal.h"

class Cat : public Animal{
 private:
  std::string name;
 public:
  Cat();
  Cat(std::string n, std::string c);
  virtual ~Cat();
  Cat(const Cat& c);
  virtual std::string getName();
  virtual std::string makeSound();
};
