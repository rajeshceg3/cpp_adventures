#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int arr[5] = { 1,2,3,4,5};
    std::vector<int> vec(arr, arr+5);
    for ( auto i: vec){
        std::cout<< i <<"   ";
    }
    std::cin.get();
}
