#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int start, int end)
{
	int partitionIndex = start;
	int pivot = arr[end];
	for( int index = start; index < end; index++)
	{
		if( arr[index] < pivot)
		{
			std::swap(arr[index],arr[partitionIndex]);
			partitionIndex++;
		}		
	}
	std::swap(arr[partitionIndex], arr[end]);
	return partitionIndex;
}

void quicksort(vector<int>& arr,int start, int end )
{
  if(start < end)
  {
	int point = partition(arr,start,end);
	quicksort(arr,start,point-1);
	quicksort(arr,point+1,end);	  
  }
}


int main()
{
	vector<int> arr = {10, 7, 8, 9, 1, 5};
	int index = arr.size() -1;
	quicksort(arr,0,index);
	for(const auto& slice: arr) cout<<slice<<" ";
}
