#include <iostream>
using namespace std;

int main()
{
  
  int arr[5] = {13,7,56,34,9};
  int len = 5;
  for ( int outerIndex = 0; outerIndex < len; outerIndex++ )
  {
    for(int innerIndex = outerIndex+1; innerIndex < len; innerIndex++)
    {
      if ( arr[outerIndex] > arr[innerIndex])
      {
        std::swap(arr[outerIndex], arr[innerIndex]);
      }							
    }
    
  }
  for (const auto&elem : arr) cout<<elem<<" ";
}
