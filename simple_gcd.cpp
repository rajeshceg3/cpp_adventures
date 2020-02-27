#include <iostream>

int gcd(const int  a, const int  b)
{
   return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int a = 12;
	int b = 8;
	std::cout<<gcd(12,8)<<"\n";
	return 0;
}
