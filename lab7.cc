#include <iostream>
#include <string>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Duck.h"
int main(){

  
  //Animal* a = new Animal();
  //Animal a2("white");

  Dog d("Fido","brown");
  std::cout << d.getName() << " | " << d.makeSound() << " | " << d.getColor() << "\n";

  Cat c("Snowball","white");
  std::cout << c.getName() << " | " << c.makeSound() << " | " << c.getColor() << "\n";

  Duck m("green");
  std::cout << m.makeSound() << " | " << m.getColor() << "\n";
  Animal* a = new Dog("Jake","black");
  //Animal* a = new Cat("Jake","black");
  std::cout <<((Dog*) a)->getName() << " | " << a->makeSound() << " | " << a->getColor() << "\n";\

  Dog n(d);
  std::cout << n.getName() << " | " << n.makeSound() << " | " << n.getColor() << "\n";
  delete a;
}
