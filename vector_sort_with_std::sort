#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int arr[5] = { 5,2,4,1,3};
    std::vector<int> vec(arr, arr+5);
    std::cout<< "Size of vector: "<<vec.size()<< std::endl;
    std::cout<< "Before sorting" << std::endl;

    for ( auto i: vec){
        std::cout<< i <<"   ";
    }

    std::cout<<std::endl;
    std::sort( vec.begin(),vec.end());
    std::cout<<"After sorting" << std::endl;

    for ( auto i: vec){
        std::cout<< i <<"   ";
    }
        std::cin.get();
}
