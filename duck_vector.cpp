#include <iostream>
#include <vector>
using namespace std;

struct Duck{
    int age_of_duck;
    Duck();
    Duck( const Duck& AnotherDuck);
    Duck& operator=(const Duck& AnotherDuck);
    Duck( Duck&& MovableDuck);
    Duck& operator=( Duck&& MovableDuck);
};


Duck::Duck(){
    cout<<"Default constructor \n";
}

Duck::Duck( const Duck& AnotherDuck){
    cout<<"Copy constructor \n";
}

Duck& Duck::operator=(const Duck& AnotherDuck){
    cout<<"Copy Assignment \n";
}

Duck::Duck( Duck&& MovableDuck){
    cout<<"Move constructor \n";
}

Duck& Duck::operator=( Duck&& MovableDuck){
    cout<<"Move Assignment \n";
}

int main(){
    vector<Duck> DuckVector {10};

}
