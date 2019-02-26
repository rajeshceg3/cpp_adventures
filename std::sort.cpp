#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <ctime>
using namespace std;

int main(){
    vector<int> collection;
    srand(time(nullptr));

    // fill vector with 10 random numbers
    generate_n(back_inserter(collection), 10, [](){
    return rand();
    });    

    cout << "10 random numbers"<< endl;
    ostream_iterator<int> cout_it(cout, ": ");

    for( const auto&i: collection){
        *cout_it = i;
    }

    sort(collection.begin(),collection.end());
    cout <<endl<< "After std::sort"<<endl;

    copy(begin(collection),end(collection),ostream_iterator<int> (cout, ": "));
    // Alternatively, you can use std::move to make use of move semantics for underlying objects
    //move(begin(collection),end(collection),ostream_iterator<int> (cout, ": "));
}
