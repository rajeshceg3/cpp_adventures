#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;
random_device rd;

struct RandomNumber{
    int operator()(){
    // get random numbers via a functor
    // c++11 way of doing this
    mt19937 eng(rd());
    uniform_int_distribution<> dist(1,100);
    return dist(eng);
    }
};


int main(){
    std::vector<int> vec(10);
    // generate n numbers from a number and save it in the container passed as input
    generate_n(begin(vec), 10, RandomNumber());
    move(begin(vec),end(vec), ostream_iterator<int> (cout," "));
}
