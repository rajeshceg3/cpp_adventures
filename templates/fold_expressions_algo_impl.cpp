#include <iostream>
#include <vector>
#include <algorithm>

// Usage of fold-expressions with variardic templates
// to represent a series of operations in one-shot

template<class Container, class T>
bool contains(const Container& c, const T& val)
{
   return std::find(begin(c), end(c), val) != end(c);
}

template<class Container, class... T>
bool contains_all(const Container& c, T&&... val)
{
   return (... && contains(c, val));
}

int main()
{
   std::vector<int> v{ 1,2,3,4,5,6 };
   std::cout<<std::boolalpha<<contains(v, 3)<<"\n";
   std::cout<<contains_all(v, 1, 3, 6)<<"\n";
   std::cout<<contains_all(v, 1, 3, 7);
}
