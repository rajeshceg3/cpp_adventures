#include <iostream>
#include <vector>
#include <algorithm>
#include <forward_list>

using namespace std;

int main(){
    vector<int> vec{1,2,3,4,5};
    cout<< "vector content" << endl;
    for_each( vec.begin(),vec.end(),[]( int y) -> void
    {
        cout<< y <<" ";
    });
    cout<<endl;
    vector<int>:: iterator it = vec.begin();
    // std::advance doesn't return anything
    // it moves the iterator we passed to new location
    advance(it,3);
    cout<<"After advance by 3 "<< *it <<endl;

    // We can pass negative numbers to move backwards
    // Only thing is iterator should either be bidirectional
    // or a random access iterator
    advance(it, -2);
    cout<<"After advance by -2 again "<< *it <<endl;


    forward_list<int> flist{6,7,8,9,10};
    cout<< "forward_list contents" << endl;
    for_each(flist.begin(),flist.end(),[](int x) -> void
    {
        cout<< x << " ";
    });

    cout<< endl;
    auto flist_it = flist.begin();
    // advance(flist_it, -3); This is bad, will cause crash
    // advance doesn't give warning when we try to move
    // backwards on a forward_iterator

    // prev, next
    auto next_it = next(flist_it, 2);
    cout<<"next by 2 positions "<< *next_it <<endl;
    // prev works the same as next, returns an iterator
    // after moving by n positions in backward direction
    // ie if backward or random iterator is supported for the
    // container, else it will lead to crash
}
