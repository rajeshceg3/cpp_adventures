#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

int main(){
    std::vector<int> vec(1000);
    srand(time(nullptr));
    generate(begin(vec), end(vec),[](){ return rand()%30;});
    cout<<"Generated sequence\n";
    move(begin(vec), end(vec), ostream_iterator<int> (cout,"  "));
    auto start = chrono::high_resolution_clock::now();
    cout<<"\nEven count = "<<count_if( begin(vec), end(vec), [](int a){ return a%2 == 0; })<<"\n";
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;
    cout<<"Time taken = "<<duration.count();
}
