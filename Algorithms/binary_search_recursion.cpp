#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

int doBinarySearch(const vector<int>& inputVector,int first, int last, int value){
    cout<<"Searching for "<<value<<" in the range "<<first<<" "<<last<<"\n";
    if ( first > last) return -1;
    int middle = (first + last) / 2;
    int currenthit = inputVector[middle];
    if ( currenthit == value){
        cout<<"Element found at "<<middle <<"\n";
        return middle;
    }
    else if ( currenthit > value) return doBinarySearch(inputVector,first, middle-1, value );
    else return doBinarySearch(inputVector,middle+1, last, value );
}

int main(){
srand(time(nullptr));
vector<int> myVector;
generate_n(back_inserter(myVector), 25, [](){
    return rand()%50;
});
sort(begin(myVector), end(myVector));
for(const auto& single_element: myVector) cout<<single_element<<" ";
cout<<"\n";
int last = myVector.size() -1;
// Search for the element 25 in the vector
int resultPosition = doBinarySearch(myVector,0,last, 25);
cout<<"Postion where element is found "<<resultPosition<<"\n";
return 0;
}
