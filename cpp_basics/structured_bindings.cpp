#include <iostream>
#include <string>

std::pair<std::string, int> pair_generator()
{
    return {"Year is: ", 2050};
}

struct Sample
{
    string s_msg;
    int s_year;
};

Sample struct_generator()
{
    return {"Year is: ", 2050};
}

int main()
{
    auto [msg, year] = pair_generator();
    auto a_pair = pair_generator();
    auto [s_msg, s_year] = struct_generator();
    
    std::cout<< msg << year <<"\n";
    std::cout<< std::get <0>(a_pair) << std::get<1>(a_pair) <<"\n";
    std::cout << s_msg << s_year << '\n';
}
