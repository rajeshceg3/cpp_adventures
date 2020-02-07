#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Simple wrapper around a string object
struct StringWrapper {
  string s;
  StringWrapper(string s1) : s(s1) {}
  // Keep track of copies with cout statements
  StringWrapper(const StringWrapper &s2) {
    cout << "Copying the string!" << endl;
    s = s2.s;
  }
};

// copy elision
StringWrapper rvo() 
{
  StringWrapper ms("Hey there!");
  return ms;
}

// No copy elision
StringWrapper no_rvo(int condition) 
{
  StringWrapper ms_1("Hello");
  StringWrapper ms_2("World");

  if (condition) 
    return ms_1;
  else 
    return ms_2;
}

int main() {
  // Generate a random choice
  srand(time(NULL));
  int condition = rand() % 2;

  // RVO version
  cout << "Getting a string with RVO" << endl;
  StringWrapper s1 = rvo();

  // Without RVO
  cout << "Getting a string without RVO" << endl;
  StringWrapper s2 = no_rvo(condition);

  // Print the values
  cout << "String 1: " << s1.s << endl;
  cout << "String 2: " << s2.s << endl;

  return 0;
}
