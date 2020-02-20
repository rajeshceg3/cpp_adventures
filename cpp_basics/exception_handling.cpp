#include <iostream>
#include <exception>

void validate(int i)
{
    if (i == 77) 
        throw 77;
}

int main()
{
    try 
	  {
        validate(100);
        std::cout << "1st Call Success";

        validate(77);
        std::cout << "2nd Call Success\n";
    }
    catch(...) 
	  {
        std::cout << "Exception Caught\n";
    }
	return 0;
}
