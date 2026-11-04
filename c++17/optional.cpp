#include <iostream>
#include <optional>

class SimpleClass
{
    int value;
	public:
    int getValue() const { return value; }

    SimpleClass(int v) :
    value(v)
    {
        std::cout << "Object Constructed";
    }
};

int main()
{
    std::optional<SimpleClass> opt;
    std::cout << "Class is not yet Constructed\n";

    if (opt) 
        std::cout << "First try: " << opt->getValue() << "\n";

    opt = SimpleClass(42);

    if (opt) 
        std::cout << "Second try: " << opt->getValue() << "\n";
    
	  return 0;
}
