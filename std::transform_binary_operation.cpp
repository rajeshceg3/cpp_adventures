#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

int main(){
    vector<int> collection = {1,2,3,4,5,6,7,8,9};
    vector<int> collection2 = {10,20,30,40,50,60,70,80,90};
    vector<int> result_collection;
    // Allocate memory for the vector which will store result
    result_collection.resize(collection.size());

    // Lambda which is used to print the elements of a container to console
    // A note here about trailing, return type of a lambda
    // This function doesn't return anything, but if we want to return something
    // from a lambda, and one and only statement inside lambda is a return
    // statement, then it's type is automatically deduced
    // If not, trailing return type needs to be specified like this
    auto print = [](const int& j) -> void
    {
             cout<<j<<" ";
    };

    cout<<" Both Collections Before transform application "<< endl;

    // std::for_each ignores the return value of unary predicate, it is used to
    // perform side effects, it belongs to non modifying category
    // original container value is not changed as result of for_each
    for_each( collection.begin(), collection.end(),print);
    cout<<endl;
    for_each( collection2.begin(), collection2.end(),print);
    cout<<endl;

    // std::transform -> modifying stl algorithm
    // Type 1 - takes a range, applies a unary predicate to it, gets results via
    // return value of unary predicate, provides results in the same container
    // in place or via a new container as specified
    transform(collection.begin(), collection.end(),
              collection2.begin(),
              // Note that, back_inserter(result_collection) can also be used
              // to collect the result in transform operation
              result_collection.begin(),[](const int& i, const int &j) -> int
    {
        return i*j;
    });

    cout<<"After binary transform ie multiply application "<< endl;
    for_each( result_collection.begin(), result_collection.end(),print);
}
