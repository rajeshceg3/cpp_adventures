#include <iostream>
#include <vector>
 
#define rowCount 3
#define columnCount 4
 
int main()
{
  std::vector<int> singleRow(columnCount, 5);
  std::vector<std::vector<int>> matrix(rowCount, singleRow); 
  
  for(auto i : matrix) 
    for(auto i : singleRow)
        std::cout<<i<<" ";
  return 0;
}