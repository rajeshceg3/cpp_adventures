#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int arr[5] = { 1,2,3,4,5};
    std::vector<int> vec(arr, arr+5);
    std::cout<< "Size of vector: "<<vec.size()<< std::endl;
    std::cout<< "Modify values inside range based for loop and print" << std::endl;
    for ( auto i: vec){
        i++;
        std::cout<< i <<" ";
    }
    std::cout<<std::endl;
     std::cout<< "Printing vector outside the scope of for loop" << std::endl;
     for ( auto i: vec){
        std::cout<< i <<" ";
     }
}
