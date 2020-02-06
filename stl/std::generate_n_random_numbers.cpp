#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <ctime>
using namespace std;

int main(){
    mt19937 eng;
    uniform_int_distribution <> dist(1,100);
    std::vector<int> vec(10);
    generate_n(begin(vec),
               10,
               [&dist,&eng](){
        return dist(eng);
    });
    // print container to console
    move(begin(vec), end(vec), ostream_iterator<int> (cout," "));
}
