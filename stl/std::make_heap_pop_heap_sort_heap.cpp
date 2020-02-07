#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>
using namespace std;

int main(){
    srand(time(nullptr));
    std::vector<int> vec(10);

    generate_n(begin(vec), 10, [](){
        return rand()%100;
    });
    cout<<"Original sequence\n";
    move(begin(vec), end(vec), ostream_iterator<int> (cout," "));
    make_heap(begin(vec),end(vec));

    // print container to console
    cout<<"\nHeapified sequence - std::make_heap\n";
    move(begin(vec), end(vec), ostream_iterator<int> (cout," "));

    pop_heap(begin(vec),end(vec));
    cout<<"\nAfter pop heap operation std::pop_heap\n";
    move(begin(vec), end(vec), ostream_iterator<int> (cout," "));

    sort_heap(begin(vec), end(vec));
    cout<<"\nSorted sequence using std::heap_sort \n";
    move(begin(vec), end(vec), ostream_iterator<int> (cout," "));
}
