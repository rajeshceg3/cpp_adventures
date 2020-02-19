#include <iostream>

int main()
{
    auto num_bytes_int = sizeof(int);
    auto min_int = std::numeric_limits<int>().min();
    auto max_int = std::numeric_limits<int>().max();

    auto num_bytes_unsigned = sizeof(unsigned int);
    auto min_unsigned = std::numeric_limits<unsigned int>().min();
    auto max_unsigned = std::numeric_limits<unsigned int>().max();

    std::cout << "num bytes (signed int): " << num_bytes_int << "\n";
    std::cout << "min value (signed int): " << min_int << "\n";
    std::cout << "max value (signed int): " << max_int << "\n";

    std::cout << "\n";

    std::cout << "num bytes (unsigned int): " << num_bytes_unsigned << "\n";
    std::cout << "min value (unsigned int): " << min_unsigned << "\n";
    std::cout << "max value (unsigned int): " << max_unsigned << "\n";
}
