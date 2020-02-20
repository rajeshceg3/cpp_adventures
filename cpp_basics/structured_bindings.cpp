#include <iostream>
#include <string>

std::pair<std::string, int> pair_generator()
{
    return {"Year is: ", 2050};
}

int main(void)
{
    auto [msg, year] = pair_generator();
    std::cout<<msg<<year <<"\n";
}
