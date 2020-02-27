// Barebones hello world example for implementing
// our own templated algorithms

// This algorithm calculates lcm for a sequence of numbers

#include <iostream>
#include <numeric>
#include <vector>
int gcd(const int  a, const int  b)
{
   return b == 0 ? a : gcd(b, a % b);
}

template<class InputIt>
int lcm_reduce(InputIt first, InputIt last)
{
	return std::accumulate(first,last,1,[](auto a, auto b){
		   int h = gcd(a, b);
		   return h ? (a * (b / h)) : 0;
	});
}

int main(){
   std::vector<int> numbers = {4,8,12,16,20,24};
	 std::cout<<lcm_reduce(begin(numbers),end(numbers));
	 return 0;
}
