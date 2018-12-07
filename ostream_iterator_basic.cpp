#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){
    vector<int> vec;
    istream_iterator<int> eos;
    istream_iterator<int> cin_it(cin);

    for ( ;cin_it != eos; ++cin_it){
        vec.emplace_back(*cin_it);
    }

    ostream_iterator<int>cout_it( cout, " ");
    for( auto&i : vec){
        *cout_it = i;
    }
    cout<< endl;

}
