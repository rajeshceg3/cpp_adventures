// C++17 fold expressions, use -std=c++17 compilation flag
#include <iostream>
#include <vector>
#include <iterator>

template<class Container, class... Ts>
void push_back(Container& c, Ts&&... args)
{
   (c.push_back(args), ...);
}

int main()
{
   std::vector<int> vec;
   push_back(vec, 1, 2, 3, 4);
   std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));
}
