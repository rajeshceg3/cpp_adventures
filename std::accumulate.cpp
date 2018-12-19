#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <numeric>
#include <iterator>
using namespace std;

int main(){
    srand(time(nullptr));
    std::vector<int> vec(10);
    // Generate a sequence of random numbers and store in vec
    generate_n(begin(vec), 10, [](){return rand()%20; });
    cout<<"Original sequence\n";
    move(begin(vec), end(vec), ostream_iterator<int> (cout," "));
    cout<<"\n";
    cout<<"Sum = "<<accumulate(begin(vec),end(vec),0)<<"\n";

    cout<<"Product of container elements "
          "using multiplies functor= "<<accumulate(begin(vec),end(vec),1,multiplies<>())<<"\n";

    cout<<"Accumulate with lambda = "<<accumulate(begin(vec),end(vec),0,[](auto x, auto y) -> decltype(auto)
    {
        return x+y+1;
    })<<"\n";
}
