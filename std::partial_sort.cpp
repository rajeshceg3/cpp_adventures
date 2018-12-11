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
    /*
    This for loop is replaced with a single line statement
    making use of std::move algorithm
    for(; cin_it != eos; ++cin_it){
        back_inserter(collection) = *cin_it;
    }*/
    move(cin_it,eos,back_inserter(collection));

    auto midpoint = (collection.size())/2;
    // partial sort the first half alone using partial_sort
    // note the alternative syntax for iterators used here
    // rather than collection.begin()
    partial_sort( begin(collection), begin(collection) + midpoint, end(collection) );

    /*
    for( const auto&i: collection){
        *cout_it = i;
    }*/

    // use std::copy to send partial sorted container to console
    // std::move can also be used
    cout<<"Partial sorted output"<< endl;
    copy(begin(collection),end(collection),cout_it);
}

