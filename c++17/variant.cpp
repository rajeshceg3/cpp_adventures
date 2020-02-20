#include <iostream>
#include <variant>

int main()
{
    std::variant<int, double> vrt = 50;
    std::cout << std::get<int>(vrt) << "\n";

    vrt = 50.5;
    std::cout << std::get<double>(vrt) << "\n";
	
	return 0;
}
