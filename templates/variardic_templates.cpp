#include <iostream>

template <class T>
T sum(T elem)
{
  return elem;
}

template <class T, class... Ts>
T sum(T x, Ts... args) 
{
  return x + sum(args...);
}

int main() 
{
  std::cout << sum(5,6,7,40);
}
