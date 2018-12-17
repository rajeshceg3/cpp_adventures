#include <iostream>
#include <functional>
using namespace std;

int main(){

    // Generic lambdas, lambdas that take auto as a parameter are supported from c++14 onwards
    function <void(double)> f = [](auto i)
    {
        cout<<i<<endl;
    };

    // invoke the lambda with int
    f(5);
    // invoke the lambda with double
    f(5.65);
    // invoke the lambda with bool
    f(true);
    }

