#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){
    vector<int> vec;
    
    // this iterator is created for comparison, end case for 
    // getting out of for loop
    istream_iterator<int> eos;
    
    // this istream_iterator wraps around cin
    istream_iterator<int> cin_it(cin);
    
    // get an iterator from back_inserter, this iterator can be 
    // used alogn with our cin iterator
    back_insert_iterator<vector<int>> back_it = back_inserter(vec);
    // Line 11 is an ideal candidate for always auto philosophy
    // no need to type all that iterator jazz for tellign the type to compiler
    // using auto, compiler will deduce it for you 
    // auto back_it = back_inserter(vec);

    for ( ;cin_it != eos; ++cin_it){
        // Voila, magic, push the input received from console direclty 
        // inside vector with iterator magic
         *back_it = *cin_it;
    }

    ostream_iterator<int>cout_it( cout, " ");
    for( auto&i : vec){
        *cout_it = i;
    }
    cout<< endl;

}
