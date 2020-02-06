#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template <class T>
T square(T x){
    return x*x;
}

int main(){
    ostream_iterator<int> cout_it(cout, " ");
    *cout_it = square(5);
    *cout_it = square(12.3);
}

