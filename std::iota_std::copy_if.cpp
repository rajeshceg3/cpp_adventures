#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    std::vector<int> vec;
    std::vector<int> even_vec;
    vec.resize(10);
    // iota - generate a series of numbers
    iota( begin(vec), end(vec), 1);
    // copy with a unary predicate
    copy_if( begin(vec), end(vec), back_inserter(even_vec), [](int x){
        return x%2 == 0;
    } );
    // printing vector contents to output
    copy(begin(even_vec), end(even_vec), ostream_iterator <int> (cout," "));
}
