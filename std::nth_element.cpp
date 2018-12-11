#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    vector<int> collection;
    cout<< "Enter numbers as you wish followed by terminating character"<<endl;
    istream_iterator<int> cin_it(cin);
    istream_iterator<int> eos;
    ostream_iterator<int> cout_it(cout, ": ");

    move(cin_it,eos,back_inserter(collection));
    auto nthpoint = (collection.size())/2;
    // std::nth_element
    nth_element( begin(collection), begin(collection) + nthpoint, end(collection) );

    cout<<"Nth element is "<< collection[collection.size()/2]<<endl;
    copy(begin(collection),end(collection),cout_it);
}

