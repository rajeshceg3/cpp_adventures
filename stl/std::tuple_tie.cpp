#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int main(){
    tuple<int, double, string> mytuple(42, 37.5, "hell yeah");
    int x =	get<0> (mytuple);
    double y =	get<1> (mytuple);
    string str = get<2> (mytuple);
    cout<<x<<" "<<y<<" "<<str<<"\n";

    // make_tuple helper function template
    // this uses std::forward internally
    auto maketuple_demo = make_tuple(24, 24.5, "maketuple_tuple");
    cout<<get<0>(maketuple_demo)<<" "<<get<1>(maketuple_demo)<<" "<<get<2>(maketuple_demo)<<"\n";

    // std::tie functionality
    int another_x;
    double another_y;
    string another_string;
    tie(another_x, another_y, another_string) = make_tuple(88,88.7,"tie demo");
    cout<<another_x<<" "<<another_y<<" "<<another_string<<"\n";
    
    //c++17 structured bindings
    auto [struct_x, struct_y, struct_str] = make_tuple( 99, 0.56, "structured bindings demo");
    cout<<struct_x<<" "<<struct_y<<" "<<struct_str<<"\n";

}
