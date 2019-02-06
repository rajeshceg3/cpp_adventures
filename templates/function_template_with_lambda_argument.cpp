#include <iostream>
#include <functional>
using namespace std;
// The lambda from call site will be implicitly converted to 
// a function pointer given in declaration
// Not the presence of + at call site, what is it ? homework for you

template <typename R, typename A>
void foo ( R(*fptr)(A) ){

}

int main(){
foo( +[](int x){ return x;});
}
