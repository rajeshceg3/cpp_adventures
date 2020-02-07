#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// Overload new  to track heap allocations
void* operator new(size_t n)
{
  cout << "Allocating " << n << " bytes" << endl;
  return malloc(n);
}

int main() {

  size_t string_size = sizeof(string);
  cout << "Size of string = " << string_size << endl;

  // Increase string size every iteration
  for (size_t i = 0; i < string_size; i++) 
  {
    string s(i, 'X');
    std::cout << i << ": " << s << std::endl;
  }

  return 0;
}
