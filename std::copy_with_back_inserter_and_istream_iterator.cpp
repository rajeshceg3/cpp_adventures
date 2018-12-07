#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vec;
    istream_iterator<int> eos;
    cout<< "Enter data to be stored in vector " <<endl;
    istream_iterator<int> cin_it(cin);
    back_insert_iterator<vector<int>> back_it = back_inserter(vec);

    /*
    for ( ;cin_it != eos; ++cin_it){
         *back_it = *cin_it;
    }
    */

    copy(cin_it, eos, back_it);


    ostream_iterator<int>cout_it( cout, " ");
    /*
    for( auto&i : vec){
        *cout_it = i;
    }
    */
    copy( vec.begin(), vec.end(), cout_it);
    cout<< endl;

}
