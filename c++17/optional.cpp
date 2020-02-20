#include <iostream>
#include <optional>

class SimpleClass
{
    int value;
	public:
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
        std::cout << "First try: " << opt->value << "\n";

    opt = SimpleClass(42);

    if (opt) 
        std::cout << "Second try: " << opt->value << "\n";
    
	  return 0;
}
