// Example to demonstrate unique_ptr usage
#include <iostream>
#include <memory>

class Widget {
  uint32_t value_;
  public :
    Widget(uint32_t value) : value_(value) { 
      std::cout << "Building Widget " << value_ << "\n"; 
    }

    ~Widget() { 
      std::cout << "Destroying Widget " << value_ << "\n"; 
    }
  
};

int main() 
{
  Widget* w = new Widget(1);
  std::unique_ptr<Widget> uw = std::make_unique<Widget>(2);
}
