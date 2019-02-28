#include <iostream>
#include <algorithm>
#include <variant>
#include <string>
#include <vector>
using namespace std;

struct FunctorOverload{
    void operator()( const int& FunnyInteger){
        cout<<FunnyInteger<<" ";
}
    void operator()( const double& FunnyDouble){
        cout<<FunnyDouble<<" ";
}
    void operator()( const string& FunnyString){
        cout<<FunnyString<<" ";
}

};

int main(){
    using my_variant = std::variant<int, double, string>;
    vector<my_variant> FunnyVector;
    FunnyVector.emplace_back(42);
    FunnyVector.emplace_back(87.5);
    FunnyVector.emplace_back("Ha ha");
    FunctorOverload fo_object;
    for(const auto & funny_element : FunnyVector) visit( fo_object,funny_element);
}
