#include <iostream>
using std::cout;

struct Animal {
  virtual void getName(){ cout<<"An Animal\n"; }
};

struct Racoon : Animal {
  virtual void getName() override { cout<<"A Racoon\n"; }
};

struct Horse : Animal {
  virtual void getName() override { cout<<"A Horse\n"; }
};

void fn_interface(Animal* animal)
{
	animal->getName;
}

int main() {

  Animal* animal = new Animal();
  Racoon* racoon = new Racoon();
  Horse* horse = new Horse();
  
  fn_interface(animal);
  fn_interface(racoon);
  fn_interface(horse);

  return 0;
}
