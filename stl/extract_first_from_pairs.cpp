#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    std::map<int, std::string> numbers_with_names = { {1, "one"}, {2, "two"}, {3, "three"} };
    std::vector<int> numbers;

    // use transform to extract first alone from a set of pairs
    // Attribution : article from fluentcpp
    std::transform(begin(numbers_with_names), end(numbers_with_names),
                   std::back_inserter(numbers),
                   [](auto const& pair){ return pair.first; });
    for(const auto& single_number: numbers ) cout<<single_number<<" ";
    cout<<"\n";
/*
Alternate solution for pre c++14, ie without a generic lambda
Write a templated functor, remember, a lambda is nothing but a functor
struct get_first
{
    template<typename T, typename U>
    T const& operator()(std::pair<T, U> const& pair)
    {
        return pair.first;
    }
};
*/
}
