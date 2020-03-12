#include <iostream>
#include <optional>
#include <string>	

std::optional<std::string> generate1(bool flag)
{
  if (flag)
    return "True value passed";
  return {};
}

auto generate2(bool flag)
{
  return flag ? std::optional<std::string>{"True value paased"} : std::nullopt;
}

int main()
{
  std::cout << "generate1(false) returned "<< generate1(false).value_or("empty") << '\n';			
  if (auto str = generate2(true)) 
    std::cout << "generate2(true) returned " << *str <<"\n";  
}
