#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;

int main(){
    std::vector<int> vec(10);
    // generate a sequence
    iota(begin(vec),end(vec),2);
    cout<<"\nSequence generated\n";
    move(begin(vec),end(vec), ostream_iterator<int> (cout," "));
    partial_sum(begin(vec),end(vec),begin(vec));
    cout<<"\nSequence generated after partial_sum \n";
    move(begin(vec),end(vec), ostream_iterator<int> (cout," "));
}
