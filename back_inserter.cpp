#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){
    vector<int> vec;
    istream_iterator<int> eos;
    istream_iterator<int> cin_it(cin);
    back_insert_iterator<vector<int>> back_it = back_inserter(vec);

    for ( ;cin_it != eos; ++cin_it){
         *back_it = *cin_it;
    }

    ostream_iterator<int>cout_it( cout, " ");
    for( auto&i : vec){
        *cout_it = i;
    }
    cout<< endl;

}
