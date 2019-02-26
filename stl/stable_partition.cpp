#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// function template to print the contents of vector
template <typename T> void printvec(const vector<T> &vec) {
  for (const auto &i : vec)
    cout << i << " ";
  cout << "\n";
}

int main() {
  srand(time(0));
  vector<int> vec;
  printvec(vec);
  
  // store 10 random elements in vec, max value is 99
  generate_n(back_inserter(vec), 10, []() { return rand() % 100; });
  printvec(vec);
  
  // std::stable_parititon to move all even elements to front
  // Relative ordering of elements is preserved with stable_partition
  // predicate can specify any condition for a match
  auto partition_it = stable_partition(
      begin(vec), end(vec), [](auto element) { return (element % 2) == 0; });
  printvec(vec);
  
  // partition returns an iterator to an element past the parition
  // which serves a partition point
  cout << "Paritition point = " << *partition_it;
}
