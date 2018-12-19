#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <iterator>
using namespace std;

int main(){
    srand(time(nullptr));
    std::vector<int> vec_a(10);
    std::vector<int> vec_b(10);
    std::vector<int> vec_result(20);

    generate_n(begin(vec_a), 10, [&vec_a](){return rand()%20;});
    sort(begin(vec_a), end(vec_a), greater<int>());
    cout<<"Sorted Vec_a\n";
    move(begin(vec_a), end(vec_a), ostream_iterator<int> (cout," "));

    generate_n(begin(vec_b), 10, [&vec_b](){return rand()%20;});
    sort(begin(vec_b), end(vec_b), greater<int>());
    cout<<"\nSorted Vec_b\n";
    move(begin(vec_b), end(vec_b), ostream_iterator<int> (cout," "));

    auto it = copy(begin(vec_a), end(vec_a), begin(vec_result));
    copy(begin(vec_b), end(vec_b), it);

    cout<<"\nCombined sequence\n";
    move(begin(vec_result), end(vec_result), ostream_iterator<int> (cout," "));
    inplace_merge(begin(vec_result), it, end(vec_result),greater<int>() );
    cout<<"\nInplace merged sequence\n";
    move(begin(vec_result), end(vec_result), ostream_iterator<int> (cout," "));
    cout<<"\n";
}
