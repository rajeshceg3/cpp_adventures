#include <iostream>
#include <memory>

class Widget {
  public :
    Widget(int value) : value_(value) { 
      std::cout << "Building Widget " << value_ << "\n"; 
    }

    ~Widget() { 
      std::cout << "Destroying Widget " << value_ << "\n"; 
    }
  
  private :
    int value_;
};

int main() 
{
  Widget* w = new Widget(1);
  std::unique_ptr<Widget> uw = std::make_unique<Widget>(2);
}
