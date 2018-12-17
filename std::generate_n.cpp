#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
using namespace std;

int getNewNumber(){
    return rand();
}

int main(){
    srand(time(nullptr));
    std::vector<int> vec(10);
    // generate n numbers from a number and save it in the container passed as input
    generate_n(begin(vec), 10, getNewNumber);
    copy(begin(vec), end(vec), ostream_iterator<int> (cout," "));
}

