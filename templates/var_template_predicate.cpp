#include <iostream>
template <class Predicate, class T>
T find_min_or_max(Predicate comp, T const a, T const b) 
{ 
  return comp(a, b) ? a : b; 
}

template <class Predicate, class T, class... Ts>
T find_min_or_max(Predicate comp, T a, Ts... args)
{
   return find_min_or_max(comp, a, find_min_or_max(comp, args...));
}

int main()
{
    std::cout<<"Min value : "<<find_min_or_max(std::less<>(),2,3,4,5,6)<<"\n";
    std::cout<<"Max value : "<<find_min_or_max(std::greater<>(),2,3,4,5,6);
}
