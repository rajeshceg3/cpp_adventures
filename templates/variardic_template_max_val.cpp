#include <iostream>

template<class T>
T maximum(T a, T b)
{
	return a > b ? a : b;
}

template <class T, class... Ts>
T maximum(T a, Ts ...args)
{
	return maximum(a,maximum(args...));
}

int main()
{
	std::cout<<"Max value is "<<maximum(5,12,6,13,6,2);
	return 0;
}
