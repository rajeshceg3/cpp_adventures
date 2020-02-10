#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Naive Approach
int fib_naive(int n)
{
  int result;
  if( n <= 1) result = n;
  else result = fib_naive(n-1) + fib_naive(n-2);
  return result;								
}

// Memoization Approach
int fib_memo(int n, vector<int>& memo)
{	
  if ( std::find( begin(memo), end(memo), n ) != end( memo ) ) return memo[n];
  int result;
  if ( n <= 1) result = n;
  else result = fib_memo(n-1, memo) + fib_memo(n-2,memo);
  memo[n] = result;
  return result;
} 

// Bottom up Memoization approach

int fib_dp( int n)
{
    vector<int> bottom_up(n+1, 0);
    bottom_up[1] = 1;
    bottom_up[2] = 1;
    for ( int index = 3; index <= n; index++ ) 
    bottom_up[index] = bottom_up[index -1] + bottom_up[index-2];
    return bottom_up[n];
}



int main() {
  int input = 50;
  vector<int> memo(input,0);
  std::cout<<fib_naive(input)<<"\n";
  std::cout<<fib_memo( input, memo )<<"\n";
  std::cout<<fib_dp(input);
}
