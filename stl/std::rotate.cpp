#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    vector<int> myVector;
    mt19937 engine;
    uniform_int_distribution<> my_distribution(1,100);
    generate_n( std::back_inserter(myVector), 10, [&engine,&my_distribution](){
        return my_distribution(engine);
    });

    cout<<"A sequence of integers \n";
    for( const auto& element_in_vector : myVector) std::cout<<element_in_vector<<" ";
    cout<<"\n";

    // Input format for rotate
    // first, third arguments -> iterator for the range to be considered for rotation
    // second argument        -> element within the range that will become new first element
    //                           of the range
    rotate(begin(myVector), begin(myVector)+3, end(myVector));

    cout<<"After rotation \n";
    for( const auto& element_in_vector : myVector) std::cout<<element_in_vector<<" ";
    cout<<"\n";

    cout<<"Now a left rotation \n";
    rotate(begin(myVector), begin(myVector)+1, end(myVector));
    for( const auto& element_in_vector : myVector) std::cout<<element_in_vector<<" ";
    cout<<"\n";
}
