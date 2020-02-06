#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
using namespace std;

int main(){
    vector<int> collection;
    srand(time(nullptr));
    int no_of_elements;
    cout<< "Enter desired no of items in collection"<<endl;
    cin>> no_of_elements;
    collection.resize(no_of_elements);

    transform( collection.begin(), collection.end(),
               collection.begin(),
               [](auto i){
        return i+rand();
    } );
    ostream_iterator<int> cout_it(cout, ": ");


    auto nthpoint = (collection.size())/2;
    // std::nth_element
    nth_element( begin(collection), begin(collection) + nthpoint, end(collection) );

    cout<<"Nth element is "<< collection[collection.size()/2]<<endl;
    copy(begin(collection),end(collection),cout_it);
}

